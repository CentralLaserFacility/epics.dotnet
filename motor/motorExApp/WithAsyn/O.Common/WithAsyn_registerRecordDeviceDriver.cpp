/* THIS IS A GENERATED FILE. DO NOT EDIT! */
/* Generated from O.Common/WithAsyn.dbd */

#include <string.h>

#include "compilerDependencies.h"
#include "epicsStdlib.h"
#include "iocsh.h"
#include "iocshRegisterCommon.h"
#include "registryCommon.h"

extern "C" {

epicsShareExtern rset *pvar_rset_aaiRSET, *pvar_rset_aaoRSET,
    *pvar_rset_aiRSET, *pvar_rset_aoRSET, *pvar_rset_biRSET,
    *pvar_rset_boRSET, *pvar_rset_busyRSET, *pvar_rset_calcRSET,
    *pvar_rset_calcoutRSET, *pvar_rset_compressRSET,
    *pvar_rset_dfanoutRSET, *pvar_rset_eventRSET, *pvar_rset_fanoutRSET,
    *pvar_rset_histogramRSET, *pvar_rset_longinRSET,
    *pvar_rset_longoutRSET, *pvar_rset_lsiRSET, *pvar_rset_lsoRSET,
    *pvar_rset_mbbiRSET, *pvar_rset_mbbiDirectRSET, *pvar_rset_mbboRSET,
    *pvar_rset_mbboDirectRSET, *pvar_rset_motorRSET,
    *pvar_rset_permissiveRSET, *pvar_rset_printfRSET, *pvar_rset_selRSET,
    *pvar_rset_seqRSET, *pvar_rset_stateRSET, *pvar_rset_stringinRSET,
    *pvar_rset_stringoutRSET, *pvar_rset_subRSET, *pvar_rset_subArrayRSET,
    *pvar_rset_waveformRSET;

typedef int (*rso_func)(dbRecordType *pdbRecordType);
epicsShareExtern rso_func pvar_func_aaiRecordSizeOffset,
    pvar_func_aaoRecordSizeOffset, pvar_func_aiRecordSizeOffset,
    pvar_func_aoRecordSizeOffset, pvar_func_biRecordSizeOffset,
    pvar_func_boRecordSizeOffset, pvar_func_busyRecordSizeOffset,
    pvar_func_calcRecordSizeOffset, pvar_func_calcoutRecordSizeOffset,
    pvar_func_compressRecordSizeOffset, pvar_func_dfanoutRecordSizeOffset,
    pvar_func_eventRecordSizeOffset, pvar_func_fanoutRecordSizeOffset,
    pvar_func_histogramRecordSizeOffset, pvar_func_longinRecordSizeOffset,
    pvar_func_longoutRecordSizeOffset, pvar_func_lsiRecordSizeOffset,
    pvar_func_lsoRecordSizeOffset, pvar_func_mbbiRecordSizeOffset,
    pvar_func_mbbiDirectRecordSizeOffset, pvar_func_mbboRecordSizeOffset,
    pvar_func_mbboDirectRecordSizeOffset, pvar_func_motorRecordSizeOffset,
    pvar_func_permissiveRecordSizeOffset,
    pvar_func_printfRecordSizeOffset, pvar_func_selRecordSizeOffset,
    pvar_func_seqRecordSizeOffset, pvar_func_stateRecordSizeOffset,
    pvar_func_stringinRecordSizeOffset,
    pvar_func_stringoutRecordSizeOffset, pvar_func_subRecordSizeOffset,
    pvar_func_subArrayRecordSizeOffset, pvar_func_waveformRecordSizeOffset;

static const char * const recordTypeNames[] = {
    "aai", "aao", "ai", "ao", "bi", "bo", "busy", "calc", "calcout",
    "compress", "dfanout", "event", "fanout", "histogram", "longin",
    "longout", "lsi", "lso", "mbbi", "mbbiDirect", "mbbo", "mbboDirect",
    "motor", "permissive", "printf", "sel", "seq", "state", "stringin",
    "stringout", "sub", "subArray", "waveform"
};

static const recordTypeLocation rtl[] = {
    {pvar_rset_aaiRSET, pvar_func_aaiRecordSizeOffset},
    {pvar_rset_aaoRSET, pvar_func_aaoRecordSizeOffset},
    {pvar_rset_aiRSET, pvar_func_aiRecordSizeOffset},
    {pvar_rset_aoRSET, pvar_func_aoRecordSizeOffset},
    {pvar_rset_biRSET, pvar_func_biRecordSizeOffset},
    {pvar_rset_boRSET, pvar_func_boRecordSizeOffset},
    {pvar_rset_busyRSET, pvar_func_busyRecordSizeOffset},
    {pvar_rset_calcRSET, pvar_func_calcRecordSizeOffset},
    {pvar_rset_calcoutRSET, pvar_func_calcoutRecordSizeOffset},
    {pvar_rset_compressRSET, pvar_func_compressRecordSizeOffset},
    {pvar_rset_dfanoutRSET, pvar_func_dfanoutRecordSizeOffset},
    {pvar_rset_eventRSET, pvar_func_eventRecordSizeOffset},
    {pvar_rset_fanoutRSET, pvar_func_fanoutRecordSizeOffset},
    {pvar_rset_histogramRSET, pvar_func_histogramRecordSizeOffset},
    {pvar_rset_longinRSET, pvar_func_longinRecordSizeOffset},
    {pvar_rset_longoutRSET, pvar_func_longoutRecordSizeOffset},
    {pvar_rset_lsiRSET, pvar_func_lsiRecordSizeOffset},
    {pvar_rset_lsoRSET, pvar_func_lsoRecordSizeOffset},
    {pvar_rset_mbbiRSET, pvar_func_mbbiRecordSizeOffset},
    {pvar_rset_mbbiDirectRSET, pvar_func_mbbiDirectRecordSizeOffset},
    {pvar_rset_mbboRSET, pvar_func_mbboRecordSizeOffset},
    {pvar_rset_mbboDirectRSET, pvar_func_mbboDirectRecordSizeOffset},
    {pvar_rset_motorRSET, pvar_func_motorRecordSizeOffset},
    {pvar_rset_permissiveRSET, pvar_func_permissiveRecordSizeOffset},
    {pvar_rset_printfRSET, pvar_func_printfRecordSizeOffset},
    {pvar_rset_selRSET, pvar_func_selRecordSizeOffset},
    {pvar_rset_seqRSET, pvar_func_seqRecordSizeOffset},
    {pvar_rset_stateRSET, pvar_func_stateRecordSizeOffset},
    {pvar_rset_stringinRSET, pvar_func_stringinRecordSizeOffset},
    {pvar_rset_stringoutRSET, pvar_func_stringoutRecordSizeOffset},
    {pvar_rset_subRSET, pvar_func_subRecordSizeOffset},
    {pvar_rset_subArrayRSET, pvar_func_subArrayRecordSizeOffset},
    {pvar_rset_waveformRSET, pvar_func_waveformRecordSizeOffset}
};

epicsShareExtern dset *pvar_dset_devAaiSoft, *pvar_dset_devAaoSoft,
    *pvar_dset_devAiSoft, *pvar_dset_devAiSoftRaw,
    *pvar_dset_devAiSoftCallback, *pvar_dset_devTimestampAI,
    *pvar_dset_devAiGeneralTime, *pvar_dset_devAoSoft,
    *pvar_dset_devAoSoftRaw, *pvar_dset_devAoSoftCallback,
    *pvar_dset_devBiSoft, *pvar_dset_devBiSoftRaw,
    *pvar_dset_devBiSoftCallback, *pvar_dset_devBiDbState,
    *pvar_dset_devBoSoft, *pvar_dset_devBoSoftRaw,
    *pvar_dset_devBoSoftCallback, *pvar_dset_devBoGeneralTime,
    *pvar_dset_devBoDbState, *pvar_dset_devBusySoft,
    *pvar_dset_devBusySoftRaw, *pvar_dset_asynBusyInt32,
    *pvar_dset_devCalcoutSoft, *pvar_dset_devCalcoutSoftCallback,
    *pvar_dset_devEventSoft, *pvar_dset_devHistogramSoft,
    *pvar_dset_devLiSoft, *pvar_dset_devLiSoftCallback,
    *pvar_dset_devLiGeneralTime, *pvar_dset_devLoSoft,
    *pvar_dset_devLoSoftCallback, *pvar_dset_devLsiSoft,
    *pvar_dset_devLsiEnviron, *pvar_dset_devLsoSoft,
    *pvar_dset_devLsoSoftCallback, *pvar_dset_devLsoStdio,
    *pvar_dset_devMbbiSoft, *pvar_dset_devMbbiSoftRaw,
    *pvar_dset_devMbbiSoftCallback, *pvar_dset_devMbbiDirectSoft,
    *pvar_dset_devMbbiDirectSoftRaw, *pvar_dset_devMbbiDirectSoftCallback,
    *pvar_dset_devMbboSoft, *pvar_dset_devMbboSoftRaw,
    *pvar_dset_devMbboSoftCallback, *pvar_dset_devMbboDirectSoft,
    *pvar_dset_devMbboDirectSoftRaw, *pvar_dset_devMbboDirectSoftCallback,
    *pvar_dset_devMotorAsyn, *pvar_dset_devMCB4B, *pvar_dset_devIM483SM,
    *pvar_dset_devIM483PL, *pvar_dset_devMDrive, *pvar_dset_devPM304,
    *pvar_dset_devMicos, *pvar_dset_devMVP2001, *pvar_dset_devMM3000,
    *pvar_dset_devMM4000, *pvar_dset_devPM500, *pvar_dset_devESP300,
    *pvar_dset_devPIC844, *pvar_dset_devPIC630, *pvar_dset_devPIC848,
    *pvar_dset_devPIC662, *pvar_dset_devPIC862, *pvar_dset_devPIC663,
    *pvar_dset_devPIE710, *pvar_dset_devPIE516, *pvar_dset_devPIE517,
    *pvar_dset_devPIE816, *pvar_dset_devOMS, *pvar_dset_devOms58,
    *pvar_dset_devMAXv, *pvar_dset_devOmsPC68, *pvar_dset_devMotorSoft,
    *pvar_dset_devMotorSim, *pvar_dset_devSmartMotor, *pvar_dset_devSC800,
    *pvar_dset_devSoloist, *pvar_dset_devPrintfSoft,
    *pvar_dset_devPrintfSoftCallback, *pvar_dset_devPrintfStdio,
    *pvar_dset_devSiSoft, *pvar_dset_devSiSoftCallback,
    *pvar_dset_devTimestampSI, *pvar_dset_devSiGeneralTime,
    *pvar_dset_devSiEnviron, *pvar_dset_devSoSoft,
    *pvar_dset_devSoSoftCallback, *pvar_dset_devSoStdio,
    *pvar_dset_devSASoft, *pvar_dset_devWfSoft;

static const char * const deviceSupportNames[] = {
    "devAaiSoft", "devAaoSoft", "devAiSoft", "devAiSoftRaw",
    "devAiSoftCallback", "devTimestampAI", "devAiGeneralTime",
    "devAoSoft", "devAoSoftRaw", "devAoSoftCallback", "devBiSoft",
    "devBiSoftRaw", "devBiSoftCallback", "devBiDbState", "devBoSoft",
    "devBoSoftRaw", "devBoSoftCallback", "devBoGeneralTime",
    "devBoDbState", "devBusySoft", "devBusySoftRaw", "asynBusyInt32",
    "devCalcoutSoft", "devCalcoutSoftCallback", "devEventSoft",
    "devHistogramSoft", "devLiSoft", "devLiSoftCallback",
    "devLiGeneralTime", "devLoSoft", "devLoSoftCallback", "devLsiSoft",
    "devLsiEnviron", "devLsoSoft", "devLsoSoftCallback", "devLsoStdio",
    "devMbbiSoft", "devMbbiSoftRaw", "devMbbiSoftCallback",
    "devMbbiDirectSoft", "devMbbiDirectSoftRaw",
    "devMbbiDirectSoftCallback", "devMbboSoft", "devMbboSoftRaw",
    "devMbboSoftCallback", "devMbboDirectSoft", "devMbboDirectSoftRaw",
    "devMbboDirectSoftCallback", "devMotorAsyn", "devMCB4B", "devIM483SM",
    "devIM483PL", "devMDrive", "devPM304", "devMicos", "devMVP2001",
    "devMM3000", "devMM4000", "devPM500", "devESP300", "devPIC844",
    "devPIC630", "devPIC848", "devPIC662", "devPIC862", "devPIC663",
    "devPIE710", "devPIE516", "devPIE517", "devPIE816", "devOMS",
    "devOms58", "devMAXv", "devOmsPC68", "devMotorSoft", "devMotorSim",
    "devSmartMotor", "devSC800", "devSoloist", "devPrintfSoft",
    "devPrintfSoftCallback", "devPrintfStdio", "devSiSoft",
    "devSiSoftCallback", "devTimestampSI", "devSiGeneralTime",
    "devSiEnviron", "devSoSoft", "devSoSoftCallback", "devSoStdio",
    "devSASoft", "devWfSoft"
};

static const dset * const devsl[] = {
    pvar_dset_devAaiSoft, pvar_dset_devAaoSoft, pvar_dset_devAiSoft,
    pvar_dset_devAiSoftRaw, pvar_dset_devAiSoftCallback,
    pvar_dset_devTimestampAI, pvar_dset_devAiGeneralTime,
    pvar_dset_devAoSoft, pvar_dset_devAoSoftRaw,
    pvar_dset_devAoSoftCallback, pvar_dset_devBiSoft,
    pvar_dset_devBiSoftRaw, pvar_dset_devBiSoftCallback,
    pvar_dset_devBiDbState, pvar_dset_devBoSoft, pvar_dset_devBoSoftRaw,
    pvar_dset_devBoSoftCallback, pvar_dset_devBoGeneralTime,
    pvar_dset_devBoDbState, pvar_dset_devBusySoft,
    pvar_dset_devBusySoftRaw, pvar_dset_asynBusyInt32,
    pvar_dset_devCalcoutSoft, pvar_dset_devCalcoutSoftCallback,
    pvar_dset_devEventSoft, pvar_dset_devHistogramSoft,
    pvar_dset_devLiSoft, pvar_dset_devLiSoftCallback,
    pvar_dset_devLiGeneralTime, pvar_dset_devLoSoft,
    pvar_dset_devLoSoftCallback, pvar_dset_devLsiSoft,
    pvar_dset_devLsiEnviron, pvar_dset_devLsoSoft,
    pvar_dset_devLsoSoftCallback, pvar_dset_devLsoStdio,
    pvar_dset_devMbbiSoft, pvar_dset_devMbbiSoftRaw,
    pvar_dset_devMbbiSoftCallback, pvar_dset_devMbbiDirectSoft,
    pvar_dset_devMbbiDirectSoftRaw, pvar_dset_devMbbiDirectSoftCallback,
    pvar_dset_devMbboSoft, pvar_dset_devMbboSoftRaw,
    pvar_dset_devMbboSoftCallback, pvar_dset_devMbboDirectSoft,
    pvar_dset_devMbboDirectSoftRaw, pvar_dset_devMbboDirectSoftCallback,
    pvar_dset_devMotorAsyn, pvar_dset_devMCB4B, pvar_dset_devIM483SM,
    pvar_dset_devIM483PL, pvar_dset_devMDrive, pvar_dset_devPM304,
    pvar_dset_devMicos, pvar_dset_devMVP2001, pvar_dset_devMM3000,
    pvar_dset_devMM4000, pvar_dset_devPM500, pvar_dset_devESP300,
    pvar_dset_devPIC844, pvar_dset_devPIC630, pvar_dset_devPIC848,
    pvar_dset_devPIC662, pvar_dset_devPIC862, pvar_dset_devPIC663,
    pvar_dset_devPIE710, pvar_dset_devPIE516, pvar_dset_devPIE517,
    pvar_dset_devPIE816, pvar_dset_devOMS, pvar_dset_devOms58,
    pvar_dset_devMAXv, pvar_dset_devOmsPC68, pvar_dset_devMotorSoft,
    pvar_dset_devMotorSim, pvar_dset_devSmartMotor, pvar_dset_devSC800,
    pvar_dset_devSoloist, pvar_dset_devPrintfSoft,
    pvar_dset_devPrintfSoftCallback, pvar_dset_devPrintfStdio,
    pvar_dset_devSiSoft, pvar_dset_devSiSoftCallback,
    pvar_dset_devTimestampSI, pvar_dset_devSiGeneralTime,
    pvar_dset_devSiEnviron, pvar_dset_devSoSoft,
    pvar_dset_devSoSoftCallback, pvar_dset_devSoStdio,
    pvar_dset_devSASoft, pvar_dset_devWfSoft
};

epicsShareExtern drvet *pvar_drvet_drvESP300, *pvar_drvet_drvIM483PL,
    *pvar_drvet_drvIM483SM, *pvar_drvet_drvMAXv, *pvar_drvet_drvMCB4B,
    *pvar_drvet_drvMDrive, *pvar_drvet_drvMM3000, *pvar_drvet_drvMM4000,
    *pvar_drvet_drvMVP2001, *pvar_drvet_drvMicos, *pvar_drvet_drvOms,
    *pvar_drvet_drvOms58, *pvar_drvet_drvOmsPC68, *pvar_drvet_drvPIC630,
    *pvar_drvet_drvPIC662, *pvar_drvet_drvPIC663, *pvar_drvet_drvPIC844,
    *pvar_drvet_drvPIC848, *pvar_drvet_drvPIC862, *pvar_drvet_drvPIE516,
    *pvar_drvet_drvPIE517, *pvar_drvet_drvPIE710, *pvar_drvet_drvPIE816,
    *pvar_drvet_drvPM304, *pvar_drvet_drvPM500, *pvar_drvet_drvSC800,
    *pvar_drvet_drvSmartMotor, *pvar_drvet_drvSoloist,
    *pvar_drvet_motorA3200, *pvar_drvet_motorANC150,
    *pvar_drvet_motorEnsemble, *pvar_drvet_motorMM4000,
    *pvar_drvet_motorSim, *pvar_drvet_motorXPS;

static const char *driverSupportNames[] = {
    "drvESP300", "drvIM483PL", "drvIM483SM", "drvMAXv", "drvMCB4B",
    "drvMDrive", "drvMM3000", "drvMM4000", "drvMVP2001", "drvMicos",
    "drvOms", "drvOms58", "drvOmsPC68", "drvPIC630", "drvPIC662",
    "drvPIC663", "drvPIC844", "drvPIC848", "drvPIC862", "drvPIE516",
    "drvPIE517", "drvPIE710", "drvPIE816", "drvPM304", "drvPM500",
    "drvSC800", "drvSmartMotor", "drvSoloist", "motorA3200",
    "motorANC150", "motorEnsemble", "motorMM4000", "motorSim", "motorXPS"};

static struct drvet *drvsl[] = {
    pvar_drvet_drvESP300,
    pvar_drvet_drvIM483PL,
    pvar_drvet_drvIM483SM,
    pvar_drvet_drvMAXv,
    pvar_drvet_drvMCB4B,
    pvar_drvet_drvMDrive,
    pvar_drvet_drvMM3000,
    pvar_drvet_drvMM4000,
    pvar_drvet_drvMVP2001,
    pvar_drvet_drvMicos,
    pvar_drvet_drvOms,
    pvar_drvet_drvOms58,
    pvar_drvet_drvOmsPC68,
    pvar_drvet_drvPIC630,
    pvar_drvet_drvPIC662,
    pvar_drvet_drvPIC663,
    pvar_drvet_drvPIC844,
    pvar_drvet_drvPIC848,
    pvar_drvet_drvPIC862,
    pvar_drvet_drvPIE516,
    pvar_drvet_drvPIE517,
    pvar_drvet_drvPIE710,
    pvar_drvet_drvPIE816,
    pvar_drvet_drvPM304,
    pvar_drvet_drvPM500,
    pvar_drvet_drvSC800,
    pvar_drvet_drvSmartMotor,
    pvar_drvet_drvSoloist,
    pvar_drvet_motorA3200,
    pvar_drvet_motorANC150,
    pvar_drvet_motorEnsemble,
    pvar_drvet_motorMM4000,
    pvar_drvet_motorSim,
    pvar_drvet_motorXPS};

typedef void (*reg_func)(void);
epicsShareExtern reg_func pvar_func_ACRMotorRegister,
    pvar_func_AG_CONEXRegister, pvar_func_AG_UCRegister,
    pvar_func_ANC150Register, pvar_func_AcsRegister,
    pvar_func_AerotechRegister, pvar_func_HXPRegister,
    pvar_func_IMSmotorRegister, pvar_func_ImsMDrivePlusMotorRegister,
    pvar_func_MAX_trajectoryScanRegistrar, pvar_func_MCB4BRegister,
    pvar_func_MM4005_trajectoryScanRegistrar, pvar_func_MVP2001Register,
    pvar_func_MclennanRegister, pvar_func_NewportRegister,
    pvar_func_OmsMAXvRegister, pvar_func_OmsPC68Register,
    pvar_func_PIC630Register, pvar_func_PIC662motorRegister,
    pvar_func_PIC663motorRegister, pvar_func_PIC848motorRegister,
    pvar_func_PIC862motorRegister, pvar_func_PIE516motorRegister,
    pvar_func_PIE517motorRegister, pvar_func_PIE710motorRegister,
    pvar_func_PIE816motorRegister, pvar_func_PImotorRegister,
    pvar_func_SC800Register, pvar_func_SMC100Register,
    pvar_func_SMChydraRegister, pvar_func_SmartMotormotorRegister,
    pvar_func_XPSGatheringRegister, pvar_func_XPSInterposeRegister,
    pvar_func_XPSRegister, pvar_func_XPSRegister3,
    pvar_func_arrInitialize, pvar_func_asSub,
    pvar_func_asynMotorControllerRegister, pvar_func_concatStringRegister,
    pvar_func_dbndInitialize, pvar_func_drvAsynIPPortRegisterCommands,
    pvar_func_drvAsynIPServerPortRegisterCommands,
    pvar_func_drvAsynSerialPortRegisterCommands,
    pvar_func_drvXPSAsynAuxRegister, pvar_func_motorRegister,
    pvar_func_motorSimDriverRegister, pvar_func_motorSimRegister,
    pvar_func_motorUtilRegister, pvar_func_oms58Registrar,
    pvar_func_syncInitialize, pvar_func_tsInitialize;

epicsShareExtern int * const pvar_int_CASDEBUG;
epicsShareExtern int * const pvar_int_asCaDebug;
epicsShareExtern int * const pvar_int_atExitDebug;
epicsShareExtern double * const pvar_double_boHIGHlimit;
epicsShareExtern int * const pvar_int_boHIGHprecision;
epicsShareExtern double * const pvar_double_calcoutODLYlimit;
epicsShareExtern int * const pvar_int_calcoutODLYprecision;
epicsShareExtern int * const pvar_int_callbackParallelThreadsDefault;
epicsShareExtern int * const pvar_int_dbBptNotMonotonic;
epicsShareExtern int * const pvar_int_dbQuietMacroWarnings;
epicsShareExtern int * const pvar_int_dbRecordsAbcSorted;
epicsShareExtern int * const pvar_int_dbRecordsOnceOnly;
epicsShareExtern int * const pvar_int_dbTemplateMaxVars;
epicsShareExtern int * const pvar_int_dbThreadRealtimeLock;
epicsShareExtern int * const pvar_int_drvIM483PLdebug;
epicsShareExtern int * const pvar_int_drvIM483SMdebug;
epicsShareExtern int * const pvar_int_drvMDrivedebug;
epicsShareExtern int * const pvar_int_drvOmsPC68debug;
epicsShareExtern int * const pvar_int_drvPIC630debug;
epicsShareExtern int * const pvar_int_drvPIC662debug;
epicsShareExtern int * const pvar_int_drvPIC663debug;
epicsShareExtern int * const pvar_int_drvPIC844debug;
epicsShareExtern int * const pvar_int_drvPIC848debug;
epicsShareExtern int * const pvar_int_drvPIC862debug;
epicsShareExtern int * const pvar_int_drvPIE516debug;
epicsShareExtern int * const pvar_int_drvPIE517debug;
epicsShareExtern int * const pvar_int_drvPIE710debug;
epicsShareExtern int * const pvar_int_drvPIE816debug;
epicsShareExtern int * const pvar_int_drvSC800debug;
epicsShareExtern int * const pvar_int_drvSmartMotordebug;
epicsShareExtern int * const pvar_int_histogramSDELprecision;
epicsShareExtern double * const pvar_double_seqDLYlimit;
epicsShareExtern int * const pvar_int_seqDLYprecision;

static struct iocshVarDef vardefs[] = {
    {"CASDEBUG", iocshArgInt, pvar_int_CASDEBUG},
    {"asCaDebug", iocshArgInt, pvar_int_asCaDebug},
    {"atExitDebug", iocshArgInt, pvar_int_atExitDebug},
    {"boHIGHlimit", iocshArgDouble, pvar_double_boHIGHlimit},
    {"boHIGHprecision", iocshArgInt, pvar_int_boHIGHprecision},
    {"calcoutODLYlimit", iocshArgDouble, pvar_double_calcoutODLYlimit},
    {"calcoutODLYprecision", iocshArgInt, pvar_int_calcoutODLYprecision},
    {"callbackParallelThreadsDefault", iocshArgInt, pvar_int_callbackParallelThreadsDefault},
    {"dbBptNotMonotonic", iocshArgInt, pvar_int_dbBptNotMonotonic},
    {"dbQuietMacroWarnings", iocshArgInt, pvar_int_dbQuietMacroWarnings},
    {"dbRecordsAbcSorted", iocshArgInt, pvar_int_dbRecordsAbcSorted},
    {"dbRecordsOnceOnly", iocshArgInt, pvar_int_dbRecordsOnceOnly},
    {"dbTemplateMaxVars", iocshArgInt, pvar_int_dbTemplateMaxVars},
    {"dbThreadRealtimeLock", iocshArgInt, pvar_int_dbThreadRealtimeLock},
    {"drvIM483PLdebug", iocshArgInt, pvar_int_drvIM483PLdebug},
    {"drvIM483SMdebug", iocshArgInt, pvar_int_drvIM483SMdebug},
    {"drvMDrivedebug", iocshArgInt, pvar_int_drvMDrivedebug},
    {"drvOmsPC68debug", iocshArgInt, pvar_int_drvOmsPC68debug},
    {"drvPIC630debug", iocshArgInt, pvar_int_drvPIC630debug},
    {"drvPIC662debug", iocshArgInt, pvar_int_drvPIC662debug},
    {"drvPIC663debug", iocshArgInt, pvar_int_drvPIC663debug},
    {"drvPIC844debug", iocshArgInt, pvar_int_drvPIC844debug},
    {"drvPIC848debug", iocshArgInt, pvar_int_drvPIC848debug},
    {"drvPIC862debug", iocshArgInt, pvar_int_drvPIC862debug},
    {"drvPIE516debug", iocshArgInt, pvar_int_drvPIE516debug},
    {"drvPIE517debug", iocshArgInt, pvar_int_drvPIE517debug},
    {"drvPIE710debug", iocshArgInt, pvar_int_drvPIE710debug},
    {"drvPIE816debug", iocshArgInt, pvar_int_drvPIE816debug},
    {"drvSC800debug", iocshArgInt, pvar_int_drvSC800debug},
    {"drvSmartMotordebug", iocshArgInt, pvar_int_drvSmartMotordebug},
    {"histogramSDELprecision", iocshArgInt, pvar_int_histogramSDELprecision},
    {"seqDLYlimit", iocshArgDouble, pvar_double_seqDLYlimit},
    {"seqDLYprecision", iocshArgInt, pvar_int_seqDLYprecision},
    {NULL, iocshArgInt, NULL}
};

int WithAsyn_registerRecordDeviceDriver(DBBASE *pbase)
{
    static int executed = 0;
    const char *bldTop = "../../../";
    const char *envTop = getenv("TOP");

    if (envTop && strcmp(envTop, bldTop)) {
        printf("Warning: IOC is booting with TOP = \"%s\"\n"
               "          but was built with TOP = \"%s\"\n",
               envTop, bldTop);
    }

    if (!pbase) {
        printf("pdbbase is NULL; you must load a DBD file first.\n");
        return -1;
    }

    if (executed) {
        printf("Warning: Registration already done.\n");
    }
    executed = 1;

    registerRecordTypes(pbase, NELEMENTS(rtl), recordTypeNames, rtl);
    registerDevices(pbase, NELEMENTS(devsl), deviceSupportNames, devsl);
    registerDrivers(pbase, NELEMENTS(drvsl), driverSupportNames, drvsl);
    pvar_func_ACRMotorRegister();
    pvar_func_AG_CONEXRegister();
    pvar_func_AG_UCRegister();
    pvar_func_ANC150Register();
    pvar_func_AcsRegister();
    pvar_func_AerotechRegister();
    pvar_func_HXPRegister();
    pvar_func_IMSmotorRegister();
    pvar_func_ImsMDrivePlusMotorRegister();
    pvar_func_MAX_trajectoryScanRegistrar();
    pvar_func_MCB4BRegister();
    pvar_func_MM4005_trajectoryScanRegistrar();
    pvar_func_MVP2001Register();
    pvar_func_MclennanRegister();
    pvar_func_NewportRegister();
    pvar_func_OmsMAXvRegister();
    pvar_func_OmsPC68Register();
    pvar_func_PIC630Register();
    pvar_func_PIC662motorRegister();
    pvar_func_PIC663motorRegister();
    pvar_func_PIC848motorRegister();
    pvar_func_PIC862motorRegister();
    pvar_func_PIE516motorRegister();
    pvar_func_PIE517motorRegister();
    pvar_func_PIE710motorRegister();
    pvar_func_PIE816motorRegister();
    pvar_func_PImotorRegister();
    pvar_func_SC800Register();
    pvar_func_SMC100Register();
    pvar_func_SMChydraRegister();
    pvar_func_SmartMotormotorRegister();
    pvar_func_XPSGatheringRegister();
    pvar_func_XPSInterposeRegister();
    pvar_func_XPSRegister();
    pvar_func_XPSRegister3();
    pvar_func_arrInitialize();
    pvar_func_asSub();
    pvar_func_asynMotorControllerRegister();
    pvar_func_concatStringRegister();
    pvar_func_dbndInitialize();
    pvar_func_drvAsynIPPortRegisterCommands();
    pvar_func_drvAsynIPServerPortRegisterCommands();
    pvar_func_drvAsynSerialPortRegisterCommands();
    pvar_func_drvXPSAsynAuxRegister();
    pvar_func_motorRegister();
    pvar_func_motorSimDriverRegister();
    pvar_func_motorSimRegister();
    pvar_func_motorUtilRegister();
    pvar_func_oms58Registrar();
    pvar_func_syncInitialize();
    pvar_func_tsInitialize();
    iocshRegisterVariable(vardefs);
    return 0;
}

/* WithAsyn_registerRecordDeviceDriver */
static const iocshArg rrddArg0 = {"pdbbase", iocshArgPdbbase};
static const iocshArg *rrddArgs[] = {&rrddArg0};
static const iocshFuncDef rrddFuncDef =
    {"WithAsyn_registerRecordDeviceDriver", 1, rrddArgs};
static void rrddCallFunc(const iocshArgBuf *)
{
    WithAsyn_registerRecordDeviceDriver(*iocshPpdbbase);
}

} // extern "C"

/*
 * Register commands on application startup
 */
static int Registration() {
    iocshRegisterCommon();
    iocshRegister(&rrddFuncDef, rrddCallFunc);
    return 0;
}

static int done EPICS_UNUSED = Registration();
