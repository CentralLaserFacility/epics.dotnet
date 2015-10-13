//////////////////////////////////////////////////////////////////////////////////////////////////////
//																									//
//	Module:																							//
//		LeyboldSimDriver.h																			//
//																									//
//	Description:																					//
//		Declares the CLeyboldSimDriver class.														//
//		This uses AsynPortDriver and asynOctetSyncIO to provide a simulated connection with			//
//		the CLeyboldTurboPortDriver class instance.													//
//																									//
//		The class communicates by means of the Universal Serial Interface (USS)						//
//		protocol (http://www.automation.siemens.com/WW/forum/guests/PostShow.aspx?PostID=104133).	//
//																									//
//	Author:  Peter Heesterman (Tessella plc). Date: 05 Jan 2015.									//
//	Written for CCFE (Culham Centre for Fusion Energy).												//
//																									//
//	LeyboldTurbo is distributed subject to a Software License Agreement								//
//	found in file LICENSE that is included with this distribution.									//
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LEYBOLD_SIM_DRIVER_H
#define LEYBOLD_SIM_DRIVER_H

#include <USSPacket.h>

#include <LeyboldBase.h>

#include <epicsMutex.h>
#include <epicsEvent.h>

#include <map>
#include <vector>
#include <string>

class CLeyboldSimPortDriver : public CLeyboldBase {
public:
    CLeyboldSimPortDriver(const char *AsynPortName, int NumPumps, int NoOfPZD);
    ~CLeyboldSimPortDriver();
	void addIOPort(const char* IOPortName);
	void exit();
    virtual asynStatus readInt32(asynUser *pasynUser, epicsInt32 *value);
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus readOctet(asynUser *pasynUser, char *value, size_t maxChars,
                                        size_t *nActual, int *eomReason);
	static CLeyboldSimPortDriver* Instance() {
		return m_Instance;
	}
                 
protected:
    template<size_t NoOfPZD> bool read(asynUser *pasynUser, asynUser *IOUser, USSPacket<NoOfPZD>& USSReadPacket);
    template<size_t NoOfPZD> bool process(asynUser *pasynUser, asynUser *IOUser, USSPacket<NoOfPZD> const& USSReadPacket, USSPacket<NoOfPZD>& USSWritePacket, size_t TableIndex);
    void process(USSPacket<NoOfPZD6>& USSWritePacket, int TableIndex);
	static void octetConnectionCallback(void *userPvt, asynUser *pasynUser,
                      char *data,size_t numchars, int eomReason);
	static void ListenerThread(void* parm);

private:
	void setDefaultValues(size_t TableIndex);
    static epicsMutex m_Mutex;
	epicsEvent m_ExitEvent;

	static int UsedParams();
	volatile bool m_Exiting;		// Signals the listening thread to exit.
	std::vector<std::pair<RunStates, unsigned> > m_WasRunning;	// For each simulated pump, was it in the Running state, on the previous iteration?
	std::vector<asynUser*> m_asynUsers;
	static CLeyboldSimPortDriver* m_Instance;
};

#endif // LEYBOLD_SIM_DRIVER_H
