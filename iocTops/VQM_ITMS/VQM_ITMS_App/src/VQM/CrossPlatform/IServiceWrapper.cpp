#include <asynOctetSyncIO.h>
#include <asynOctet.h>

#include <epicsGuard.h>
#include <aitConvert.h>

#include <sstream>

#define epicsExportSharedSymbols
#include "IServiceWrapper.h"
#include "../../Exception.h"

#include "../../VQM/Include/SAnalyzedData.h"

#ifdef _DEBUG
// Infinite timeout, convenient for debugging.
const double TimeOut = -1;
#else
const double TimeOut = 5;
#endif

std::string ToString(double value)
{
	std::ostringstream o;
	o << value;
	return o.str ();
}

void FromString(std::string const& String, int& value)
{
	value = atoi(String.c_str());
}

void FromHexString(std::string const& String, int& value)
{
	char* EndPtr;
	value = strtoul(String.c_str(), &EndPtr, 16);
}

void FromString(std::string const& String, double& value)
{
	value = atof(String.c_str());
}

IServiceWrapper::~IServiceWrapper()
{
	for(std::map<asynUser*, GaugeState*>::iterator Iter = m_GaugeStates.begin(); Iter != m_GaugeStates.end(); Iter++)
		delete Iter->second;
}

SVQM_800_Error IServiceWrapper::ConnectToDevice(asynUser* IOUser, bool isMaster)
{
	if (m_GaugeStates[IOUser] == NULL)
		m_GaugeStates[IOUser] = new GaugeState;
	epicsGuard < epicsMutex > guard (m_GaugeStates[IOUser]->m_Mutex);
	ThrowException(IOUser, pasynOctetSyncIO->flush(IOUser), __FUNCTION__, "flush");
	ThrowException(IOUser, pasynOctetSyncIO->setOutputEos(IOUser, "\r", 1), __FUNCTION__, "setOutputEos");
	ThrowException(IOUser, pasynOctetSyncIO->setInputEos(IOUser, "\r", 1), __FUNCTION__, "setInputEos");
	write(IOUser, "INST MSP");
	std::string ErrResponse;
	writeRead(IOUser, "SYST:ERR:ALL?", ErrResponse);
	std::string ReportResponse;
	writeRead(IOUser, "TEST:REPORT?", ReportResponse);
	epicsTime Time = epicsTime::getCurrent();
	char Date[11], TimeOfDay[9]; 
    Time.strftime ( Date, sizeof(Date), "%Y,%m,%d");
    Time.strftime ( TimeOfDay, sizeof(TimeOfDay), "%H,%M,%S");

	write(IOUser, "SYST:DATE " + std::string(Date));
	write(IOUser, "SYST:TIME " + std::string(TimeOfDay));
	write(IOUser, "STAT:OPER:CONT:NTR 32767");
	GetGaugeState(m_GaugeStates[IOUser]->m_GaugeState, IOUser);
	SetGaugeState(EnumGaugeState_OFF, IOUser);
	write(IOUser, "INST FIL");
	write(IOUser, "SOUR:MODE ADJ");
	writeRead(IOUser, "SYST:ERR:ALL?", ErrResponse);
	GetLogicalInstrumentMinMaxVoltage(FILAMENTBIAS, IOUser);
	GetLogicalInstrumentMinMaxVoltage(REPELLERBIAS, IOUser);
	GetLogicalInstrumentMinMaxVoltage(ENTRYPLATE, IOUser);
	GetLogicalInstrumentMinMaxVoltage(PRESSUREPLATE, IOUser);
	GetLogicalInstrumentMinMaxVoltage(CUPS, IOUser);
	GetLogicalInstrumentMinMaxVoltage(TRANSITION, IOUser);
	GetLogicalInstrumentMinMaxVoltage(EXITPLATE, IOUser);
	GetLogicalInstrumentMinMaxVoltage(EMSHIELD, IOUser);
	GetLogicalInstrumentMinMaxVoltage(EMBIAS, IOUser);
	GetLogicalInstrumentMinMaxVoltage(RFAMP, IOUser);
	std::string AMUResponse;
	writeRead(IOUser, "CONF:AMU?", AMUResponse);
	// +9.28392E-01,+1.47596E+02
	size_t CommaPos = FindMarkerPos(AMUResponse, 0, ",");
	std::string lowerRange = AMUResponse.substr(0, CommaPos-1);
	FromString(lowerRange, m_GaugeStates[IOUser]->m_lowerRange);
	std::string upperRange = AMUResponse.substr(CommaPos+1);
	FromString(upperRange, m_GaugeStates[IOUser]->m_upperRange);
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::DataAnalysisSetAvgMode(EnumAvgMode mode, asynUser* IOUser)
{
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::DataAnalysisSetNumAvgs(int numAverages, asynUser* IOUser)
{
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetFilamentEmissionCurrent(double& value, asynUser* IOUser) const
{
	value = getGaugeState(IOUser).m_EmissionCurrent;
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::SetFilamentEmissionCurrentSetpoint(double& value, asynUser* IOUser)
{
	epicsGuard < epicsMutex > guard (m_GaugeStates[IOUser]->m_Mutex);
	write(IOUser, "INST FIL");
	write(IOUser, "SOUR CURR " + ToString(value));
	return SVQM_800_Error();
}


std::string IServiceWrapper::EnumToText(EnumLogicalInstruments logicalInstrumentEnum) const
{
	switch(logicalInstrumentEnum)
	{
		case FILAMENT : // duplicate?
		case FILAMENTBIAS : return "INST FIL"; break;
		case REPELLERBIAS : return "INST REP"; break;
		case ENTRYPLATE : return "INST ENTR"; break;
		case PRESSUREPLATE : return "INST PPL"; break;
		case CUPS : return "INST CUPS"; break;
		case TRANSITION : return "INST TPL"; break;
		case EXITPLATE : return "INST EXIT"; break;
		case EMSHIELD : return "INST EMSH"; break;
		case EMBIAS : return "INST EMUL"; break;
		case RFAMP : return "INST DDS"; break;
		default : _ASSERT(false);
	}
	return "";
}

SVQM_800_Error IServiceWrapper::GetLogicalInstrumentMinMaxVoltage(EnumLogicalInstruments logicalInstrumentEnum, asynUser* IOUser)
{
	GaugeState& GaugeState = getGaugeState(IOUser);
	epicsGuard < epicsMutex > guard (GaugeState.m_Mutex);
	double Min, Max;
	write(IOUser, EnumToText(logicalInstrumentEnum));
	std::string MaxResponse, MinResponse;
	writeRead(IOUser, "SOUR:VOLT? MAX", MaxResponse);
	FromString(MaxResponse, Max);
	writeRead(IOUser, "SOUR:VOLT? MIN", MinResponse);
	FromString(MinResponse, Min);
	GaugeState.m_InstrumentVoltages[logicalInstrumentEnum].m_Min = Min;
	GaugeState.m_InstrumentVoltages[logicalInstrumentEnum].m_Max = Max;
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetLogicalInstrumentCurrentVoltage(double& value, EnumLogicalInstruments logicalInstrumentEnum, asynUser* IOUser) const
{
	GaugeState const& GaugeState = getGaugeState(IOUser);
	std::map<EnumLogicalInstruments, InstrumentVoltage>::const_iterator Iter = GaugeState.m_InstrumentVoltages.find(logicalInstrumentEnum);
	if (Iter == GaugeState.m_InstrumentVoltages.end())
		return SVQM_800_Error(NO_ANALYZED_DATA, L"Instrument not found", L"GetLogicalInstrumentCurrentVoltage");
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::SetLogicalInstrumentVoltageSetpoint(EnumLogicalInstruments logicalInstrumentEnum, double& value, asynUser* IOUser)
{
	GaugeState& GaugeState = getGaugeState(IOUser);
	epicsGuard < epicsMutex > guard (GaugeState.m_Mutex);
	write(IOUser, EnumToText(logicalInstrumentEnum));
	write(IOUser, "SOUR:VOLT");
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetMassCalibrationFactor(float& value, asynUser* IOUser) const
{
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetElectrometerGain(double& value, asynUser* IOUser) const
{
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetScanRange(double& lowerRange, double& upperRange, asynUser* IOUser)
{
	GaugeState const& GaugeState = getGaugeState(IOUser);
	lowerRange = GaugeState.m_lowerRange;
	upperRange = GaugeState.m_upperRange;
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::SetScanRange(double& lowerRange, double& upperRange, asynUser* IOUser)
{
	GaugeState& GaugeState = getGaugeState(IOUser);
	epicsGuard < epicsMutex > guard (GaugeState.m_Mutex);
	write(IOUser, "CONF:AMU " + ToString(lowerRange) + "," + ToString(upperRange));
	return SVQM_800_Error();
}

//	asynStatus GetScanData(int& lastScanNumber, SAnalyzedData& analyzedData, IHeaderData** headerDataPtr,
//                                            SAverageData& averageData, const SDeviceConnectionInfo& connectInfo, bool& isValidData, EnumGaugeState& controllerState) = 0;
SVQM_800_Error IServiceWrapper::SetGaugeState(EnumGaugeState gaugeState, asynUser* IOUser)
{
	GaugeState& GaugeState = getGaugeState(IOUser);
	epicsGuard < epicsMutex > guard (GaugeState.m_Mutex);
	write(IOUser, "INST MSP");
	switch (gaugeState)
	{
	case EnumGaugeState_OFF :
		write (IOUser, "OUTP OFF");
		break;
	case EnumGaugeState_STANDBY :
		write (IOUser, "SOUR:MODE STANDBY");
		write (IOUser, "OUTP ON");
		break;
	case EnumGaugeState_ON :
		write (IOUser, "OUTP ON");
		break;
	case EnumGaugeState_SCAN :
		write (IOUser, "OUTP ON");
		write (IOUser, "FORM:ALL 1,0");
		write (IOUser, "INIT:CONT ON");
		break;
	default: _ASSERT(false);
	}
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetGaugeState(EnumGaugeState& gaugeState, asynUser* IOUser) const
{
	GaugeState const& GaugeState = getGaugeState(IOUser);
	epicsGuard < epicsMutex > guard (GaugeState.m_Mutex);
	write(IOUser, "INST MSP");
	std::string OUTPResponse, INITResponse;
	int OUTPValue = 0, INITValue;
	writeRead(IOUser, "OUTP?", OUTPResponse);
	FromString(OUTPResponse, OUTPValue);
	writeRead(IOUser, "INIT:CONT?", INITResponse);
	FromString(INITResponse, INITValue);
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetTSETingsValues(GaugeState& GaugeState, std::string const&  TSETingsValues)
{
	// enum EnumLogicalInstruments { FILAMENT = 0, FILAMENTBIAS, REPELLERBIAS, ENTRYPLATE, PRESSUREPLATE, CUPS, TRANSITION, EXITPLATE, EMSHIELD, EMBIAS, RFAMP };

	//								  RepellerBias  Emission    FilamentBias   No idea     EntryPlate   PressurePlate Cups        Transition   ExitPlate     RFAmp       EMShield     EMBias      no idea      no idea
	// (MEASurement=TSETtings (VALues -5.29913E+01,+7.50000E-05,+3.09385E+01,+2.83090E+00,+1.30018E+02,+7.50945E+01,+2.69785E+01,-6.85262E+02,+1.21151E+02,+4.50000E-01,+1.23000E+02,-8.58475E+02,+1.90069E-08,+9.99999E-10))
	size_t FirstCommaPos = 0, SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos, ",");
	std::string RepellerBias = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(RepellerBias, GaugeState.m_InstrumentVoltages[REPELLERBIAS].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string EmissionCurrent = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(EmissionCurrent, GaugeState.m_EmissionCurrent);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string FilamentBias = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(FilamentBias, GaugeState.m_InstrumentVoltages[FILAMENTBIAS].m_Current);

	// No idea (+2.83090E+00)
	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string EntryPlate = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(EntryPlate, GaugeState.m_InstrumentVoltages[ENTRYPLATE].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string PressurePlate = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(PressurePlate, GaugeState.m_InstrumentVoltages[PRESSUREPLATE].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string Cups = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(Cups, GaugeState.m_InstrumentVoltages[CUPS].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string Transition = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(Transition, GaugeState.m_InstrumentVoltages[TRANSITION].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string ExitPlate = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(Transition, GaugeState.m_InstrumentVoltages[EXITPLATE].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string RFAmp = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(RFAmp, GaugeState.m_InstrumentVoltages[RFAMP].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string EMShield = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(EMShield, GaugeState.m_InstrumentVoltages[EMSHIELD].m_Current);

	FirstCommaPos = SecondCommaPos; SecondCommaPos = FindMarkerPos(TSETingsValues, FirstCommaPos+1, ",");
	std::string EMBias = TSETingsValues.substr(FirstCommaPos, SecondCommaPos-FirstCommaPos-1);
	FromString(EMBias, GaugeState.m_InstrumentVoltages[EMBIAS].m_Current);
	return SVQM_800_Error();
}

SVQM_800_Error IServiceWrapper::GetScanData(int& lastScanNumber, SAnalyzedData& analyzedData, IHeaderData** headerDataPtr,
                               SAverageData& averageData, asynUser* IOUser, bool& isValidData, EnumGaugeState& controllerState)
{
	GaugeState& GaugeState = getGaugeState(IOUser);
	epicsGuard < epicsMutex > guard (GaugeState.m_Mutex);
	std::vector<aitUint16> NoisePacket, DataPacket;
	std::string FirstHeader;
	write(IOUser, "fetc?");
	ThrowException(IOUser, pasynOctetSyncIO->setInputEos(IOUser, "", 0), __FUNCTION__, "setInputEos");
	readTill(IOUser, FirstHeader, "CURVe", 0);
	readTill(IOUser, FirstHeader, "VALues #3", 6);

	size_t IDPos = FindMarkerPos(FirstHeader, 0, "(DIF (VERSion 1999.0) IDENtify", "(ID \"");
	size_t QuotePos = FindMarkerPos(FirstHeader, IDPos, "\"");
	GaugeState.m_HeaderData.m_MID = mbstowcs(FirstHeader.substr(IDPos, QuotePos-IDPos));

	size_t DESignPos = FindMarkerPos(FirstHeader, QuotePos, "DESign \"");

	// (DIF (VERSion 1999.0) IDENtify (DATE 2016,07,25 TIME 13,55,09.737 UUT (ID "835A0405"  DESign "0A,03.001.01301"))
	size_t CommaPos = FindMarkerPos(FirstHeader, DESignPos, ",");
	QuotePos = FindMarkerPos(FirstHeader, CommaPos, "\"");
	GaugeState.m_HeaderData.m_HardwareRevision = mbstowcs(FirstHeader.substr(DESignPos, CommaPos-DESignPos-1));
	GaugeState.m_HeaderData.m_FirmwareRevision = mbstowcs(FirstHeader.substr(CommaPos, QuotePos-CommaPos-1));

	// enum EnumLogicalInstruments { FILAMENT = 0, FILAMENTBIAS, REPELLERBIAS, ENTRYPLATE, PRESSUREPLATE, CUPS, TRANSITION, EXITPLATE, EMSHIELD, EMBIAS, RFAMP };
	//								  RepellerBias  Emission    FilamentBias   No idea     EntryPlate   PressurePlate Cups        Transition   ExitPlate     RFAmp       EMShield     no idea     no idea      no idea
	// (MEASurement=TSETtings (VALues -5.29913E+01,+7.50000E-05,+3.09385E+01,+2.83090E+00,+1.30018E+02,+7.50945E+01,+2.69785E+01,-6.85262E+02,+1.21151E+02,+4.50000E-01,+1.23000E+02,-8.58475E+02,+1.90069E-08,+9.99999E-10))
	size_t VALuesPos = FindMarkerPos(FirstHeader, QuotePos, "DATA (MEASurement=TSETtings (VALues ");
	size_t CloseBracketPos = FindMarkerPos(FirstHeader, VALuesPos, "))");
	std::string TSETingsValues = FirstHeader.substr(VALuesPos, CloseBracketPos-VALuesPos-2);
	SVQM_800_Error Error = GetTSETingsValues(GaugeState, TSETingsValues);

	size_t DIMNoisePos = FindMarkerPos(FirstHeader, CloseBracketPos, "DIMension=NOISe", "NSAMples #H");
	size_t SpacePos = FindMarkerPos(FirstHeader, DIMNoisePos, " ");
	std::string NoiseSamplesStr = FirstHeader.substr(DIMNoisePos, SpacePos-DIMNoisePos-1);
	int NoiseSamples;
	FromHexString(NoiseSamplesStr, NoiseSamples);

	size_t  NoiseValuesPos = FindMarkerPos(FirstHeader, DIMNoisePos, "VALues #3");
	std::string NoiseVALuesStr = FirstHeader.substr(NoiseValuesPos);
	int NoiseValues;
	FromString(NoiseVALuesStr, NoiseValues);
	_ASSERT(NoiseValues==NoiseSamples*sizeof(aitUint16));

	NoisePacket.resize(NoiseSamples);
	read(IOUser, NoisePacket);

	std::string SecondHeader;
	readTill(IOUser, SecondHeader, "DIMension=COUNt (TYPE EXPLicit UNITs \"COUNt\") DATA (", 0);
	readTill(IOUser, SecondHeader, "VALues #5", 6);

	// DIMension=COUNt (TYPE EXPLicit UNITs "COUNt") 
	//		DATA (TSOurce "IMMediate" OTCounter #H00000000 BOCounter #H00001d26 CVALue +6.13000E+05 BAMu +9.28392E-01 EAMu +1.22370E+02 BSEGment #H01 ESEGment #H12 NSAMples #H00001c41 BLINe +0.00000E+00 RMSNoise +0.00000E+00
	//			CURVe (DATE 2016,08,01 TIME 15,38,19.539 VALues #514466 

	size_t DIMDataPos = FindMarkerPos(SecondHeader, 0, "DIMension=COUNt", "NSAMples #H");
	SpacePos = FindMarkerPos(SecondHeader, DIMDataPos, " ");
	std::string DataSamplesStr = SecondHeader.substr(DIMDataPos, SpacePos-DIMDataPos-1);
	int DataSamples;
	FromHexString(DataSamplesStr, DataSamples);

	size_t  DataValuesPos = FindMarkerPos(SecondHeader, DIMDataPos, "VALues #5");
	std::string DataVALuesStr = SecondHeader.substr(DataValuesPos);
	int DataValues;
	FromString(DataVALuesStr, DataValues);
	_ASSERT(DataValues==DataSamples*sizeof(aitUint16));

	DataPacket.resize(DataSamples);
	read(IOUser, DataPacket);

	analyzedData.DenoisedRawData().resize(DataSamples);
	for(size_t Sample = 0; Sample < analyzedData.DenoisedRawData().size(); Sample++)
	{
		aitUint16 HostOrder = DataPacket[Sample];
//		aitFromNetOrder16(&HostOrder, &(DataPacket[Sample]));
		analyzedData.DenoisedRawData()[Sample] = HostOrder;
	}

	std::string DiscardedTerminator;
	readTill(IOUser, DiscardedTerminator, " )))", 0);
	_ASSERT(DiscardedTerminator==" )))");

#ifdef _DEBUG
//	CheckExtraData(IOUser);
#endif
	analyzedData.PeakArea().resize(size_t(GaugeState.m_upperRange - GaugeState.m_lowerRange));
	pasynOctetSyncIO->setInputEos(IOUser, "\r", 1);
	*headerDataPtr = &GaugeState.m_HeaderData;

	return Error;
}

size_t IServiceWrapper::FindMarkerPos(std::string const& HeaderData, size_t Offset, const char* FirstMarker)
{
	size_t FirstMarkerPos = HeaderData.find(FirstMarker, Offset);
	if (FirstMarkerPos != std::string::npos)
		FirstMarkerPos += strlen(FirstMarker);
	return FirstMarkerPos;
}

size_t IServiceWrapper::FindMarkerPos(std::string const& HeaderData, size_t Offset, const char* FirstMarker, const char* SecondMarker)
{
	size_t FirstMarkerPos = FindMarkerPos(HeaderData, Offset, FirstMarker);
	size_t SecondMarkerPos = std::string::npos;
	if (FirstMarkerPos != std::string::npos)
	{
		FirstMarkerPos += strlen(FirstMarker);
		SecondMarkerPos = HeaderData.find(SecondMarker, FirstMarkerPos);
		if (SecondMarkerPos != std::string::npos)
			SecondMarkerPos += strlen(SecondMarker);
	}
	return SecondMarkerPos;
}

void IServiceWrapper::write(asynUser* IOUser, std::string const& WritePacket) const
{
	epicsGuard < epicsMutex > guard (getGaugeState(IOUser).m_Mutex);
	size_t nBytesOut;
	// NB, *don't* pass pasynUser to this function - it has the wrong type and will cause an access violation.
	ThrowException(IOUser, pasynOctetSyncIO->write(IOUser, WritePacket.c_str(), WritePacket.size(), TimeOut, &nBytesOut), __FUNCTION__, "write");
}

void IServiceWrapper::read(asynUser* IOUser, std::string& ReadPacket) const
{
	int eomReason = ASYN_EOM_CNT;
	char Buf[1024];
	size_t nBytesIn;
	while (eomReason == ASYN_EOM_CNT)
	{
		ThrowException(IOUser, pasynOctetSyncIO->read(IOUser, Buf, sizeof(Buf), TimeOut, &nBytesIn, &eomReason), __FUNCTION__, "read");
		for(size_t Byte = 0; Byte < nBytesIn; Byte++)
			ReadPacket.push_back(Buf[Byte]);
	}
}

void IServiceWrapper::writeRead(asynUser* IOUser, std::string const& WritePacket, std::string& ReadPacket) const
{
	epicsGuard < epicsMutex > guard (getGaugeState(IOUser).m_Mutex);
	// NB, *don't* pass pasynUser to this function - it has the wrong type and will cause an access violation.
	write(IOUser, WritePacket);
	read(IOUser, ReadPacket);
}

void IServiceWrapper::readTill(asynUser* IOUser, std::string& ReadPacket, std::string const& Termination, int AdditionalChars) const
{
	epicsGuard < epicsMutex > guard (getGaugeState(IOUser).m_Mutex);
	size_t nBytesIn;
	int eomReason = ASYN_EOM_CNT;
	char Buf;
	// NB, *don't* pass pasynUser to this function - it has the wrong type and will cause an access violation.
	while ((ReadPacket.size() < Termination.size()) ||
		   (ReadPacket.substr(ReadPacket.size()-Termination.size(), Termination.size()) != Termination))
	{
		ThrowException(IOUser, pasynOctetSyncIO->read(IOUser, &Buf, sizeof(Buf), TimeOut, &nBytesIn, &eomReason), __FUNCTION__, "read");
		ReadPacket += Buf;
	}
	for(int Additional = 0; Additional < AdditionalChars; Additional++)
	{
		ThrowException(IOUser, pasynOctetSyncIO->read(IOUser, &Buf, sizeof(Buf), TimeOut, &nBytesIn, &eomReason), __FUNCTION__, "read");
		ReadPacket += Buf;
	}
}

void IServiceWrapper::read(asynUser* IOUser, std::vector<aitUint16>& ReadPacket) const
{
	epicsGuard < epicsMutex > guard (getGaugeState(IOUser).m_Mutex);
	size_t nBytesIn;
	int eomReason = ASYN_EOM_CNT;
	// NB, *don't* pass pasynUser to this function - it has the wrong type and will cause an access violation.
	ThrowException(IOUser, pasynOctetSyncIO->read(IOUser, reinterpret_cast<char*>(&(ReadPacket[0])), ReadPacket.size()*sizeof(aitUint16), TimeOut, &nBytesIn, &eomReason), __FUNCTION__, "read");
	_ASSERT(eomReason == ASYN_EOM_CNT);
}

int IServiceWrapper::CheckExtraData(asynUser* IOUser)
{
	size_t ExtraData = 0;
	size_t nBytesIn;
	int eomReason = ASYN_EOM_CNT;
	char Buf;
	do
	{
		asynStatus Status = pasynOctetSyncIO->read(IOUser, &Buf, sizeof(Buf), 0.01, &nBytesIn, &eomReason);
		ExtraData += nBytesIn;
	}
	while (eomReason == ASYN_EOM_CNT);
	_ASSERT(ExtraData == 0);
	return ExtraData;
}

IServiceWrapper::CException::CException(asynUser* AsynUser, asynStatus Status, const char* functionName, std::string const& what) :
	std::runtime_error(what) 
{
	std::string message = "%s:%s ERROR: " + what + "%s\n";
	asynPrint(AsynUser, ASYN_TRACE_ERROR, message.c_str(), __FILE__, functionName, AsynUser->errorMessage);
	m_Status = Status;
}

void IServiceWrapper::ThrowException(asynUser* pasynUser, asynStatus Status, const char* Function, std::string const& what) const
{
	if (Status == asynSuccess)
		return;
	throw CException(pasynUser, Status, Function, what);
}

