/********************************************
 *  p6kController.cpp
 * 
 *  P6K Asyn motor based on the 
 *  asynMotorController class.
 * 
 *  Matt Pearson
 *  26 March 2014
 * 
 ********************************************/

 /*
 MIT License
 Copyright (c) 2019 win32ports
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#pragma once

#ifndef __UNISTD_H_17CD2BD1_839A_4E25_97C7_DE9544B8B59C__
#define __UNISTD_H_17CD2BD1_839A_4E25_97C7_DE9544B8B59C__

#ifndef _WIN32

#pragma message("this unistd.h implementation is for Windows only!")

#else /* _WIN32 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _INC_IO
#include <io.h> /* _access() */
#endif /* _INC_IO */

#ifndef _INC_DIRECT
#include <direct.h> /* _chdir() */
#endif /* _INC_DIRECT */

#ifndef _INC_PROCESS
#include <process.h> /* _execl() */
#endif /* _INC_PROCESS */

#include <sys/stat.h> /* */

#ifndef access
#define access _access
#endif /* access */

#ifndef R_OK
#define R_OK 04
#endif /* R_OK */

#ifndef W_OK
#define W_OK 02
#endif /* W_OK */

#ifndef X_OK
#define X_OK R_OK
#endif /* X_OK */

#ifndef F_OK
#define F_OK 00
#endif /* F_OK */

#ifndef chdir
#define chdir _chdir
#endif /* chdir */

#ifndef close
#define close _close
#endif /* close */

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif /* STDIN_FILENO */

#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif /* STDOUT_FILENO */

#ifndef STDERR_FILENO
#define STDERR_FILENO 2
#endif /* STDERR_FILENO */

#ifndef dup
#define dup _dup
#endif /* dup */

#ifndef dup2
#define dup2 _dup2
#endif /* dup2 */

#ifndef execl
#define execl _execl
#endif /* execl */

#ifndef execle
#define execle _execle
#endif /* execle */

#ifndef execlp
#define execlp _execlp
#endif /* execlp */

#ifndef execp
#define execp _execp
#endif /* execp */

#ifndef execpe
#define execpe _execpe
#endif /* execpe */

#ifndef execpp
#define execpp _execpp
#endif /* execpp */

#ifndef rmdir
#define rmdir _rmdir
#endif /* rmdir */

#ifndef unlink
#define unlink _unlink
#endif /* unlink */

    /* permission bits below must be defined in sys/stat.h, but MSVC lacks them */

#ifndef S_IRWXU
#define S_IRWXU 0700
#endif /* S_IRWXU */

#ifndef S_IRUSR
#define S_IRUSR 0400
#endif /* S_IRUSR */

#ifndef S_IWUSR
#define S_IWUSR 0200
#endif /* S_IWUSR */

#ifndef S_IXUSR
#define S_IXUSR 0100
#endif /* S_IXUSR */

#ifndef S_IRWXG
#define S_IRWXG 070
#endif /* S_IRWXG */

#ifndef S_IRGRP
#define S_IRGRP 040
#endif /* S_IRGRP */

#ifndef S_IWGRP
#define S_IWGRP 020
#endif /* S_IWGRP */

#ifndef S_IXGRP
#define S_IXGRP 010
#endif /* S_IXGRP */

#ifndef S_IRWXO
#define S_IRWXO 07
#endif /* S_IRWXO */

#ifndef S_IROTH
#define S_IROTH 04
#endif /* S_IROTH */

#ifndef S_IWOTH
#define S_IWOTH 02
#endif /* S_IWOTH */

#ifndef S_IXOTH
#define S_IXOTH 01
#endif /* S_IXOTH */

#ifndef S_ISUID
#define S_ISUID 04000
#endif /* S_ISUID */

#ifndef S_ISGID
#define S_ISGID 02000
#endif /* S_ISGID */

#ifndef S_ISVTX
#define S_ISVTX 01000
#endif /* S_ISVTX */

#ifndef S_IRWXUGO
#define S_IRWXUGO 0777
#endif /* S_IRWXUGO */

#ifndef S_IALLUGO
#define S_IALLUGO 0777
#endif /* S_IALLUGO */	

#ifndef S_IRUGO
#define S_IRUGO 0444
#endif /* S_IRUGO */

#ifndef S_IWUGO
#define S_IWUGO 0222
#endif /* S_IWUGO */

#ifndef S_IXUGO
#define S_IXUGO 0111
#endif /* S_IXUGO */

#ifndef _S_IFMT
#define _S_IFMT 0xF000
#endif /* _S_IFMT */

#ifndef _S_IFIFO
#define _S_IFIFO 0x1000
#endif /* _S_IFIFO */

#ifndef _S_IFCHR
#define _S_IFCHR 0x2000
#endif /* _S_IFCHR */

#ifndef _S_IFDIR
#define _S_IFDIR 0x4000
#endif /* _S_IFDIR */

#ifndef _S_IFBLK
#define _S_IFBLK 0x6000
#endif /* _S_IFBLK */

#ifndef _S_IFREG
#define _S_IFREG 0x8000
#endif /* _S_IFREG */

#ifndef _S_IFLNK
#define _S_IFLNK 0xA000
#endif /* _S_IFLNK */

#ifndef _S_IFSOCK
#define _S_IFSOCK 0xC000
#endif /* _S_IFSOCK */

#ifndef S_IFMT
#define S_IFMT _S_IFMT
#endif /* S_IFMT */

#ifndef S_IFIFO
#define S_IFIFO _S_IFIFO
#endif /* S_IFIFO */

#ifndef S_IFCHR
#define S_IFCHR _S_IFCHR
#endif /* S_IFCHR */

#ifndef S_IFDIR
#define S_IFDIR _S_IFDIR
#endif /* S_IFDIR */

#ifndef S_IFBLK
#define S_IFBLK _S_IFBLK
#endif /* S_IFBLK */

#ifndef S_IFREG
#define S_IFREG _S_IFREG
#endif /* S_IFREG */

#ifndef S_IFLNK
#define S_IFLNK _S_IFLNK
#endif /* S_IFLNK */

#ifndef S_IFSOCK
#define S_IFSOCK _S_IFSOCK
#endif /* S_IFSOCK */

#ifndef S_ISTYPE
#define S_ISTYPE(mode, mask) (((mode) & S_IFMT) == (mask))
#endif /* S_ISTYPE */

#ifndef S_ISFIFO
#define S_ISFIFO(mode) S_ISTYPE(mode, S_IFIFO)
#endif /* S_ISFIFO */

#ifndef S_ISCHR
#define S_ISCHR(mode) S_ISTYPE(mode, S_IFCHR)
#endif /* S_ISCHR */

#ifndef S_ISDIR
#define S_ISDIR(mode) S_ISTYPE(mode, S_IFDIR)
#endif /* S_ISDIR */

#ifndef S_ISBLK
#define S_ISBLK(mode) S_ISTYPE(mode, S_IFBLK)
#endif /* S_ISBLK */

#ifndef S_ISREG
#define S_ISREG(mode) S_ISTYPE(mode, S_IFREG)
#endif /* S_ISREG */

#ifndef S_ISLNK
#define S_ISLNK(mode) S_ISTYPE(mode, S_IFLNK)
#endif /* S_ISLNK */

#ifndef S_ISSOCK
#define S_ISSOCK(mode) S_ISTYPE(mode, S_IFSOCK)
#endif /* S_ISSOCK */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WIN32 */

#endif /* __UNISTD_H_17CD2BD1_839A_4E25_97C7_DE9544B8B59C__ */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <osiUnistd.h>

#include <iostream>
using std::cout;
using std::endl;
using std::dec;

#include <epicsTime.h>
#include <epicsThread.h>
#include <epicsExport.h>
#include <epicsString.h>
#include <iocsh.h>
#include <drvSup.h>
#include <registryFunction.h>

#include "asynOctetSyncIO.h"

#include "parker6kController.h"

static const char *driverName = "parker6k";

const epicsUInt32 p6kController::P6K_MAXBUF_ = P6K_MAXBUF;
const epicsUInt32 p6kController::P6K_MAXAXES_ = 8;
const epicsFloat64 p6kController::P6K_TIMEOUT_ = 5.0;
const epicsUInt32 p6kController::P6K_ERROR_PRINT_TIME_ = 600; //seconds (this should be set larger when we finish debugging)
const epicsUInt32 p6kController::P6K_FORCED_FAST_POLLS_ = 10;
const epicsUInt32 p6kController::P6K_OK_ = 0;
const epicsUInt32 p6kController::P6K_ERROR_ = 1;
const epicsUInt32 p6kController::P6K_MAX_DIGITS_ = 4;

const char * p6kController::P6K_ASYN_IEOS_ = ">";
const char * p6kController::P6K_ASYN_IEOS_PROG_ = "-";
const char * p6kController::P6K_ASYN_OEOS_ = "\n";

const char p6kController::P6K_ON_         = '1';
const char p6kController::P6K_OFF_        = '0';
const char p6kController::P6K_NOCHANGE_   = 'X';
const char p6kController::P6K_UNDERSCORE_ = '_';

//TSS Status Bits (position in char array, not TSS bit position) 
const epicsUInt32 p6kController::P6K_TSS_SYSTEMREADY_ = 0;
const epicsUInt32 p6kController::P6K_TSS_PROGRUNNING_ = 2;
const epicsUInt32 p6kController::P6K_TSS_IMMEDIATE_   = 3;
const epicsUInt32 p6kController::P6K_TSS_CMDERROR_    = 12;
const epicsUInt32 p6kController::P6K_TSS_MEMERROR_    = 26;

//TLIM Bits (position in char array of first axis)
const epicsUInt32 p6kController::P6K_TLIM_BIT1_ = 0;
const epicsUInt32 p6kController::P6K_TLIM_BIT2_ = 1;
const epicsUInt32 p6kController::P6K_TLIM_BIT3_ = 2;
const epicsUInt32 p6kController::P6K_TLIM_SIZE_ = 4;

const epicsUInt32 p6kController::P6K_UINT32_SIZE_ = 32;

//C function prototypes, for the functions that can be called on IOC shell.
extern "C" {
  asynStatus p6kCreateController(const char *portName, const char *lowLevelPortName, int lowLevelPortAddress, 
				 int numAxes, int movingPollPeriod, int idlePollPeriod);
  
  asynStatus p6kCreateAxis(const char *p6kName, int axis);

  asynStatus p6kCreateAxes(const char *p6kName, int numAxes);
  
  asynStatus p6kUpload(const char *p6kName, const char *filename);
}

/**
 * p6kController constructor.
 * @param portName The Asyn port name to use (that the motor record connects to).
 * @param lowLevelPortName The name of the low level port that has already been 
 *        created, to enable comms to the controller.
 * @param lowLevelPortAddress The asyn address for the low level port
 * @param numAxes The number of axes on the controller (1 based)
 * @param movingPollPeriod The time (in milliseconds) between polling when axes are moving
 * @param idlePollPeriod The time (in milliseconds) between polling when axes are idle
 */
p6kController::p6kController(const char *portName, const char *lowLevelPortName, int lowLevelPortAddress, 
			     int numAxes, double movingPollPeriod, double idlePollPeriod)
  : asynMotorController(portName, numAxes+1, NUM_MOTOR_DRIVER_PARAMS,
			0, // No additional interfaces
			0, // No addition interrupt interfaces
			ASYN_CANBLOCK | ASYN_MULTIDEVICE, 
			1, // autoconnect
			0, 0),  // Default priority and stack size
    movingPollPeriod_(movingPollPeriod), idlePollPeriod_(idlePollPeriod)
{
  static const char *functionName = "p6kController::p6kController";

  printf("%s: Constructor.\n", functionName);

  //Initialize non static data members
  lowLevelPortUser_ = NULL;
  movesDeferred_ = 0;
  nowTimeSecs_ = 0.0;
  lastTimeSecs_ = 0.0;
  printNextError_ = false;
  printErrors_ = true;

  pAxes_ = (p6kAxis **)(asynMotorController::pAxes_);

  //Create controller-specific parameters
  printf("%s: Create controller parameters.\n", functionName);
  createParam(P6K_C_FirstParamString,       asynParamInt32, &P6K_C_FirstParam_);
  createParam(P6K_C_GlobalStatusString,     asynParamInt32, &P6K_C_GlobalStatus_);
  createParam(P6K_C_CommsErrorString,       asynParamInt32, &P6K_C_CommsError_);
  createParam(P6K_C_CommandString,          asynParamOctet, &P6K_C_Command_);
  createParam(P6K_C_ResponseString,         asynParamOctet, &P6K_C_Response_);
  createParam(P6K_C_ErrorString,            asynParamOctet, &P6K_C_Error_);
  createParam(P6K_C_ConfigString,           asynParamInt32, &P6K_C_Config_);
  createParam(P6K_C_LogString,              asynParamInt32, &P6K_C_Log_);
  createParam(P6K_C_TSS_SystemReadyString,  asynParamInt32, &P6K_C_TSS_SystemReady_);
  createParam(P6K_C_TSS_ProgRunningString,  asynParamInt32, &P6K_C_TSS_ProgRunning_);
  createParam(P6K_C_TSS_ImmediateString,    asynParamInt32, &P6K_C_TSS_Immediate_);
  createParam(P6K_C_TSS_CmdErrorString,     asynParamInt32, &P6K_C_TSS_CmdError_);
  createParam(P6K_C_TSS_MemErrorString,     asynParamInt32, &P6K_C_TSS_MemError_);
  createParam(P6K_C_TLIM_EnableString,      asynParamInt32, &P6K_C_TLIM_Enable_);
  createParam(P6K_C_TLIM_BitsString,        asynParamInt32, &P6K_C_TLIM_Bits_);
  createParam(P6K_C_INOUT_EnableString,     asynParamInt32, &P6K_C_INOUT_Enable_);
  createParam(P6K_C_TOUT_BitsString,        asynParamInt32, &P6K_C_TOUT_Bits_);
  createParam(P6K_C_TIN_BitsString,        asynParamInt32, &P6K_C_TIN_Bits_);
  createParam(P6K_C_OUT_BitString,          asynParamInt32, &P6K_C_OUT_Bit_);
  createParam(P6K_C_OUT_ValString,          asynParamInt32, &P6K_C_OUT_Val_);
  createParam(P6K_C_OUT_AllString,          asynParamInt32, &P6K_C_OUT_All_);
  createParam(P6K_C_LastParamString,        asynParamInt32, &P6K_C_LastParam_);

  //Create axis specific parameters
  //createParam adds the parameters to all param lists automatically (using maxAddr).
  printf("%s: Create axis parameters.\n", functionName);
  createParam(P6K_A_DRESString,             asynParamInt32, &P6K_A_DRES_);
  createParam(P6K_A_ERESString,             asynParamInt32, &P6K_A_ERES_);
  createParam(P6K_A_DRIVEString,            asynParamInt32, &P6K_A_DRIVE_);
  createParam(P6K_A_AXSDEFString,           asynParamInt32, &P6K_A_AXSDEF_);
  createParam(P6K_A_MaxDigitsString,        asynParamInt32, &P6K_A_MaxDigits_);
  createParam(P6K_A_LimitDriveEnableString, asynParamInt32, &P6K_A_LimitDriveEnable_);
  createParam(P6K_A_SendPositionOnlyString, asynParamInt32, &P6K_A_SendPositionOnly_);
  createParam(P6K_A_LSEnableString,         asynParamInt32, &P6K_A_LS_Enable_);
  createParam(P6K_A_LSString,               asynParamInt32, &P6K_A_LS_);
  createParam(P6K_A_LHString,               asynParamInt32, &P6K_A_LH_);
  createParam(P6K_A_CommandString,          asynParamOctet, &P6K_A_Command_);
  createParam(P6K_A_ResponseString,         asynParamOctet, &P6K_A_Response_);
  createParam(P6K_A_ErrorString,            asynParamOctet, &P6K_A_Error_);
  createParam(P6K_A_MoveErrorString,        asynParamOctet, &P6K_A_MoveError_);
  createParam(P6K_A_DelayTimeString,        asynParamFloat64, &P6K_A_DelayTime_);
  createParam(P6K_A_TAS_DriveFaultString,   asynParamInt32, &P6K_A_TAS_DriveFault_);
  createParam(P6K_A_TAS_TimeoutString,      asynParamInt32, &P6K_A_TAS_Timeout_);
  createParam(P6K_A_TAS_PosErrString,       asynParamInt32, &P6K_A_TAS_PosErr_);
  createParam(P6K_A_AutoDriveEnableString,  asynParamInt32, &P6K_A_AutoDriveEnable_);
  createParam(P6K_A_AutoDriveEnableDelayString,  asynParamInt32, &P6K_A_AutoDriveEnableDelay_);
  createParam(P6K_A_DriveRetryString,       asynParamInt32, &P6K_A_DriveRetry_);
  createParam(P6K_A_ExternalEncoderUseString, asynParamInt32, &P6K_A_ExternalEncoderUse_);
  createParam(P6K_A_ExternalEncoderString, asynParamInt32, &P6K_A_ExternalEncoder_);
  createParam(P6K_A_ModbusEncoderString, asynParamInt32, &P6K_A_ModbusEncoder_);
  createParam(P6K_A_ModbusEncoderAddrString, asynParamInt32, &P6K_A_ModbusEncoderAddr_);
  createParam(P6K_A_ModbusEncoderOffsetString, asynParamInt32, &P6K_A_ModbusEncoderOffset_);
  createParam(P6K_A_ModbusEncoderCheckString, asynParamInt32, &P6K_A_ModbusEncoderCheck_);
  createParam(P6K_A_DriveVoltageString,     asynParamFloat64, &P6K_A_DriveVoltage_);
  createParam(P6K_A_VoltageOffsetString,    asynParamFloat64, &P6K_A_VoltageOffset_);
  createParam(P6K_A_HoldVoltageString,    asynParamFloat64, &P6K_A_HoldVoltage_);
  createParam(P6K_A_TargetDirectionString,    asynParamInt32, &P6K_A_TargetDirection_);

  //Create dummy axis for asyn address 0. This is used for controller parameters.
  printf("%s: Create pAxisZero for controller parameters.\n", functionName);
  pAxisZero = new p6kAxis(this, 0);
  
  //Connect our Asyn user to the low level port that is a parameter to this constructor
  //NOTE:
  // The P6K will send back a command with a \r\r\n> \n>
  // The low level port EOS will remove the first >. 
  // We will need to deal with the rest in p6kController::lowLevelWriteRead
  // Error responses are handled differently, and unfortunately rely on a asyn timeout.
  printf("%s: Connect to low level Asyn port.\n", functionName);
  if (lowLevelPortConnect(lowLevelPortName, lowLevelPortAddress, &lowLevelPortUser_, 
			  P6K_ASYN_IEOS_, P6K_ASYN_OEOS_) != asynSuccess) {
    printf("%s: Failed to connect to low level asynOctetSyncIO port %s\n", functionName, lowLevelPortName);
    setIntegerParam(P6K_C_CommsError_, P6K_ERROR_);
  } else {
    setIntegerParam(P6K_C_CommsError_, P6K_OK_);
  }

  char command[P6K_MAXBUF_] = {0};
  char response[P6K_MAXBUF_] = {0};

  //Disable command echo
  epicsSnprintf(command, P6K_MAXBUF_, "%s0", P6K_CMD_ECHO);
  if (lowLevelWriteRead(command, response) != asynSuccess) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
	      "%s: Setting %s failed.\n", functionName, P6K_CMD_ECHO);
    setStringParam(P6K_C_Error_, "Startup failed. Not starting poller.");
  } else {

    memset(command, 0, sizeof(command));
    //Enable continuous command execution mode
    epicsSnprintf(command, P6K_MAXBUF_, "%s1", P6K_CMD_COMEXC);
    if (lowLevelWriteRead(command, response) != asynSuccess) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s: Continuous command execution mode (%s) failed.\n", functionName, P6K_CMD_COMEXC);
    }

    startPoller();

    bool paramStatus = true;
    paramStatus = ((setIntegerParam(P6K_C_GlobalStatus_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setStringParam(P6K_C_Command_, " ") == asynSuccess) && paramStatus);
    paramStatus = ((setStringParam(P6K_C_Response_, " ") == asynSuccess) && paramStatus);
    paramStatus = ((setStringParam(P6K_C_Error_, " ") == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_Config_, 1) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TSS_SystemReady_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TSS_ProgRunning_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TSS_Immediate_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TSS_CmdError_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TSS_MemError_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TLIM_Bits_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TOUT_Bits_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_TIN_Bits_, 0) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_OUT_Bit_, 1) == asynSuccess) && paramStatus);
    paramStatus = ((setIntegerParam(P6K_C_OUT_All_, 0) == asynSuccess) && paramStatus);
    callParamCallbacks();

    if (!paramStatus) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s Unable To Set Driver Parameters In Constructor.\n", 
		functionName);
    }

  }
 
}


p6kController::~p6kController(void) 
{
  //Destructor. Should never get here.
  delete pAxisZero;
}


/**
 * Connect to the underlying low level Asyn port that is used for comms.
 * This uses the asynOctetSyncIO interface, and also sets the input and output terminators.
 * @param port The port to connect to
 * @param addr The address of the port to connect to
 * @param ppasynUser A pointer to the pasynUser structure used by the controller
 * @param inputEos The input EOS character
 * @param outputEos The output EOS character
 * @return asynStatus  
 */
asynStatus p6kController::lowLevelPortConnect(const char *port, int addr, 
					      asynUser **ppasynUser, const char *inputEos, 
					      const char *outputEos)
{
  asynStatus status = asynSuccess;
 
  static const char *functionName = "p6kController::lowLevelPortConnect";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  status = pasynOctetSyncIO->connect( port, addr, ppasynUser, NULL);
  if (status) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
	      "p6kController::motorAxisAsynConnect: unable to connect to port %s\n", 
	      port);
    return status;
  }

  status = pasynOctetSyncIO->setInputEos(*ppasynUser, inputEos, strlen(inputEos) );
  if (status) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
	      "p6kController: unable to set input EOS on %s: %s\n", 
	      port, (*ppasynUser)->errorMessage);
    pasynOctetSyncIO->disconnect(*ppasynUser);
    //Set my low level pasynUser pointer to NULL
    *ppasynUser = NULL;
    return status;
  }
  
  status = pasynOctetSyncIO->setOutputEos(*ppasynUser, outputEos, strlen(outputEos));
  if (status) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
	      "p6kController: unable to set output EOS on %s: %s\n", 
	      port, (*ppasynUser)->errorMessage);
    pasynOctetSyncIO->disconnect(*ppasynUser);
    //Set my low level pasynUser pointer to NULL
    *ppasynUser = NULL;
    return status;
  }
  
  return status;
}

/**
 * Utilty function to print the connected status of the low level asyn port.
 * @return asynStatus
 */
asynStatus p6kController::printConnectedStatus()
{
  asynStatus status = asynSuccess;
  int32_t asynManagerConnected = 0;
  static const char *functionName = "p6kController::printConnectedStatus";
  
  if (lowLevelPortUser_) {
    status = pasynManager->isConnected(lowLevelPortUser_, &asynManagerConnected);
      if (status!=asynSuccess) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
		"p6kController: Error calling pasynManager::isConnected.\n");
      return status;
      } else {
	asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s isConnected: %d\n", 
		  functionName, asynManagerConnected);
    }
  }
  return status;
}

/**
 * Wrapper for asynOctetSyncIO write/read functions.
 * @param command - String command to send.
 * @response response - String response back.
 */
asynStatus p6kController::lowLevelWriteRead(const char *command, char *response)
{
  bool stat = true;
  int32_t eomReason = 0;
  size_t nwrite = 0;
  size_t nread = 0;
  char temp[P6K_MAXBUF_] = {0};
  static const char *functionName = "p6kController::lowLevelWriteRead";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);
  
  if (!lowLevelPortUser_) {
    setIntegerParam(P6K_C_CommsError_, P6K_ERROR_);
    return asynError;
  }
  
  asynPrint(lowLevelPortUser_, ASYN_TRACEIO_DRIVER, "%s: command: %s\n", functionName, command);
  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s: command: %s\n", functionName, command);   

  int32_t log = 0;
  getIntegerParam(P6K_C_Log_, &log);
  if (log != 0) {
    printf("%s > %s\n", this->portName, command);
  }

  memset(response, 0, strlen(response));

  // Check if we are defining a program using DEF. If so, change the 
  // input EOS character from > to -. If we sending an END then change it back.
  if (strncmp(command, "DEF", 3) == 0) {
    pasynOctetSyncIO->setInputEos(lowLevelPortUser_, P6K_ASYN_IEOS_PROG_, strlen(P6K_ASYN_IEOS_PROG_) );
  } else if (strncmp(command, "END", 3) == 0) {
    pasynOctetSyncIO->setInputEos(lowLevelPortUser_, P6K_ASYN_IEOS_, strlen(P6K_ASYN_IEOS_) );
  }
  
  stat = (pasynOctetSyncIO->writeRead(lowLevelPortUser_ ,
				       command, strlen(command),
				       temp, P6K_MAXBUF_,
				       P6K_TIMEOUT_,
				       &nwrite, &nread, &eomReason ) == asynSuccess) && stat;
  
  if (!stat) {
    if (printErrors_) {
      asynPrint(lowLevelPortUser_, ASYN_TRACE_ERROR, 
		"%s: Error from pasynOctetSyncIO->writeRead. command: %s\n", 
		functionName, command);
    }
    setIntegerParam(P6K_C_CommsError_, P6K_ERROR_);
  } else {
    setIntegerParam(P6K_C_CommsError_, P6K_OK_);
  }

  //Search for an error response
  if (errorResponse(temp, response) == asynSuccess) {
    asynPrint(lowLevelPortUser_, ASYN_TRACE_ERROR, 
	      "%s: ERROR: Command %s returned an error: %s\n", functionName, command, response);
    stat = false;
  }

  //The P6K will send back a command with a \r\r\n> \n>
  //The low level port asyn EOS will remove the first >
  //(or we removed the error char in the errorResponse function)
  //We deal with the rest in this function.
  stat = (trimResponse(temp, response) == asynSuccess) && stat;

  asynPrint(lowLevelPortUser_, ASYN_TRACEIO_DRIVER, "%s: response: %s\n", functionName, response); 
  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s: response: %s\n", functionName, response); 

  if (log != 0) {
    printf("%s < %s\n", this->portName, response);
  }

  if (!stat) {
    return asynError;
  }

  return asynSuccess;
}

/**
 * The P6K will send back an error string with a ? prompt afterwards it.
 * We search for this before dealing with a successful command. An error
 * response would have caused an Asyn timeout, because there was no standard
 * IEOS character and by defaut we search for the character that terminates a
 * successful command.
 * @param input - input buffer. This will be modified.
 * @param output - output buffer. No bigger than P6K_MAXBUF_.
 */
asynStatus p6kController::errorResponse(char *input, char *output)
{
  static const char *trailer = "?";
  static const char *header = "*";
  
  static const char *functionName = "p6kController::errorResponse";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  if (input == NULL) {
    return asynError;
  }

  char *pTrailer = strstr(input, trailer);

  if (pTrailer != NULL) {
    *pTrailer = '\0';
    //Remove leading '*' character. Make sure it's there first.
    //For error strings there may be some leading chars before the '*'
    char *pHeader = strstr(input, header);
    if (pHeader != NULL) {
      pHeader++;
      if (output != NULL) {
	strncpy(output, pHeader, P6K_MAXBUF_-1);
      }
      return asynSuccess;
    }
  } 

  //asynError is used to indicate we have not found an error
  return asynError;
}

/**
 * Remove a \r\r\n from an input buffer.
 * Also remove leading '*' character. 
 * @param input - input buffer. This will be modified.
 * @param output - output buffer. No bigger than P6K_MAXBUF_.
 */
asynStatus p6kController::trimResponse(char *input, char *output)
{
  asynStatus status = asynSuccess;
  static const char *trailer = "\r\r\n";
  static const char *smallTrailer = "\r\n";
  static const char *header = "*";
  static const char *functionName = "p6kController::trimResponse";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  if (input == NULL) {
    return asynError;
  }

  char *pTrailer = strstr(input, trailer);
  if (pTrailer != NULL) {
    *pTrailer = '\0';
  } else {
    //Try the smallTrailer instead
    pTrailer = strstr(input, smallTrailer);
    if (pTrailer != NULL) {
      *pTrailer = '\0';
    } else {
      if (printErrors_) {
	asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		  "%s Could not find correct trailer.\n", functionName);
      }
      status = asynError;
    }
  }

  //Remove leading '*' character. Make sure it's there first.
  //Occasionally there may be some leading chars before the '*', eg a space.
  char *pHeader = strstr(input, header);
  if (pHeader != NULL) {
    pHeader++;
    if (output != NULL) {
      strncpy(output, pHeader, P6K_MAXBUF_-1);
    }
  }

  return status;
}


/**
 * asynReport function. Currently this just calls the base class. 
 */
void p6kController::report(FILE *fp, int level)
{
  int32_t axis = 0;
  p6kAxis *pAxis = NULL;

  fprintf(fp, "p6k motor driver %s, numAxes=%d, moving poll period=%f, idle poll period=%f\n", 
          this->portName, numAxes_, movingPollPeriod_, idlePollPeriod_);

  if (level > 0) {
    for (axis=0; axis<numAxes_; axis++) {
      pAxis = getAxis(axis);
      if (!pAxis) continue;
      fprintf(fp, "  axis %d\n", 
              pAxis->axisNo_);
    }
  }

  // Call the base class method
  asynMotorController::report(fp, level);
}

/**
 * Deal with controller specific epicsFloat64 params.
 * @param pasynUser
 * @param value
 * @return asynStatus
 */
asynStatus p6kController::writeFloat64(asynUser *pasynUser, epicsFloat64 value)
{
  int function = pasynUser->reason;
  bool status = true;
  p6kAxis *pAxis = NULL;
	
  static const char *functionName = "p6kController::writeFloat64";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  pAxis = this->getAxis(pasynUser);
  if (!pAxis) {
    return asynError;
  }

  /* Set the parameter and readback in the parameter library. */
  status = (pAxis->setDoubleParam(function, value) == asynSuccess) && status;

  if (function == P6K_A_DelayTime_) {
    if (value < 0.0) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s: ERROR: forcing done moving delay time to be >=0. Axis %d\n", 
		functionName, pAxis->axisNo_);
      value = 0.0;
    }
  }

  //Call base class method. This will handle callCallbacks even if the function was handled here.
  status = (asynMotorController::writeFloat64(pasynUser, value) == asynSuccess) && status;

  if (!status) {
    setIntegerParam(pAxis->axisNo_, this->motorStatusCommsError_, P6K_ERROR_);
    return asynError;
  } else {
    setIntegerParam(pAxis->axisNo_, this->motorStatusCommsError_, P6K_OK_);
  }

  return asynSuccess;

}

/**
 * Deal with controller specific epicsInt32 params.
 * @param pasynUser
 * @param value
 * @return asynStatus
 */
asynStatus p6kController::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
  int function = pasynUser->reason;
  bool status = true;
  p6kAxis *pAxis = NULL;
  static const char *functionName = "p6kController::writeInt32";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  pAxis = this->getAxis(pasynUser);
  if (!pAxis) {
    return asynError;
  } 

  if (function == P6K_A_AutoDriveEnableDelay_) {
    if (value < 0) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s: ERROR: forcing drive enable to be >=0. Axis %d\n", 
		functionName, pAxis->axisNo_);
      value = 0;
    }
  } else if (function == P6K_A_LS_Enable_) {
    if (value !=0 ) {
      status = (pAxis->disableSoftwareLimits(false) == asynSuccess) && status;
    } else {
      status = (pAxis->disableSoftwareLimits(true) == asynSuccess) && status;
    }
  } else if (function == P6K_C_OUT_Bit_) {
    if ((value < 1) || (value > 8)) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s: ERROR: forcing OUT bit to be 1. Axis %d\n", 
		functionName, pAxis->axisNo_);
      status = false;
    }
  } else if (function == P6K_C_OUT_Val_) {
    if (value != 0) value = 1;
    int32_t bit = 0;
    getIntegerParam(P6K_C_OUT_Bit_, &bit);
    status = (setDigitalOutput(bit, value) == asynSuccess) && status;
  } else if (function == P6K_C_OUT_All_) {
    if (value != 0) value = 1;
    status = (setDigitalOutputs(value) == asynSuccess) && status;
  }

  status = (pAxis->setIntegerParam(function, value) == asynSuccess) && status;

  //Call base class method. This will handle callCallbacks even if the function was handled here.
  status = (asynMotorController::writeInt32(pasynUser, value) == asynSuccess) && status;
  
  if (!status) {
    setIntegerParam(pAxis->axisNo_, this->motorStatusCommsError_, P6K_ERROR_);
    return asynError;
  } else {
    setIntegerParam(pAxis->axisNo_, this->motorStatusCommsError_, P6K_OK_);
  }

  return asynSuccess;

}

/**
 * Set a digital output. Leave the rest unchanged.
 * @param bit (1 to 8)
 * @param enable (0=off, 1=on)
 * @return asynStatus
 */
asynStatus p6kController::setDigitalOutput(epicsInt32 bit, epicsInt32 enable)
{
  char out_cmd[P6K_MAXBUF_] = {0};
  char command[P6K_MAXBUF_] = {0};
  char response[P6K_MAXBUF_] = {0};  
  bool stat = true;

  const char *functionName = "parker6kController::setDigitalOutput";
  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s.\n", functionName);

  for (uint32_t axis=1; axis<P6K_MAXAXES_; ++axis) {
    if (axis == static_cast<uint32_t>(bit)) {
      if (enable == 1) {
	out_cmd[axis-1] = P6K_ON_;
      } else {
	out_cmd[axis-1] = P6K_OFF_;
      }
    } else {
      	out_cmd[axis-1] = P6K_NOCHANGE_;
    }
  }

  epicsSnprintf(command, P6K_MAXBUF_, "%s%s", P6K_CMD_OUT, out_cmd);
  stat = (lowLevelWriteRead(command, response) == asynSuccess) && stat;
  if (!stat) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
	      "%s: ERROR: failed to set bit %d %s\n", 
	      functionName, bit, (enable ? "on" : "off"));
    return asynError;
  }

  return asynSuccess;
}


/**
 * Set all digital outputs on or off.
 * @param enable (0=all off, 1=all on)
 * @return asynStatus
 */
asynStatus p6kController::setDigitalOutputs(epicsInt32 enable)
{
  char command[P6K_MAXBUF_] = {0};
  char response[P6K_MAXBUF_] = {0};  
  bool stat = true;

  const char *functionName = "parker6kController::setDigitalOutputs";
  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s.\n", functionName);

  if (enable == 1) {
    epicsSnprintf(command, P6K_MAXBUF_, "%s%s", P6K_CMD_OUT, "11111111");
  } else {
    epicsSnprintf(command, P6K_MAXBUF_, "%s%s", P6K_CMD_OUT, "00000000");
  }

  stat = (lowLevelWriteRead(command, response) == asynSuccess) && stat;
  if (!stat) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
	      "%s: ERROR: failed to set all bits %s\n", 
	      functionName, (enable ? "on" : "off")); 
    return asynError;
  }

  return asynSuccess;
}

/**
 * This is a generic function that sends a command to the controller 
 * and expects back a string of format 0000_0000_0000_ etc. Or any number
 * of digits with underscore separating each block (eg. 000_000_ etc.) 
 * The underscores are ignored and the bits are placed into a uint32_t. 
 * This can be used to read the state of the digital inputs, outputs and limits.
 * @param command Pointer to char array command to send
 * @param size Number of characters in char array command (not including EOL)
 * @param bits Pointer to uint32_t that will be modified to contain the bits.
 * @return asynStatus
 */
asynStatus p6kController::getDigital(const char *command, size_t size, uint32_t *bits)
{
  char response[P6K_MAXBUF_] = {0};  
  bool stat = true;
  uint32_t offset = 0;

  *bits = 0;

  const char *functionName = "parker6kController::getDigital";
  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s.\n", functionName);

  stat = (lowLevelWriteRead(command, response) == asynSuccess) && stat;
  if (!stat) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
	      "%s: ERROR: failed to send %s\n", 
	      functionName, command);
    return asynError;
  } else {
    for (uint32_t bit=size; bit<P6K_MAXBUF_; ++bit) {
      if (bit >= P6K_UINT32_SIZE_) {
	break;
      }
      if (response[bit] == P6K_UNDERSCORE_) {
	++offset;
      } else {
	*bits |= ((response[bit] == P6K_ON_) << (bit-offset-size));
      }
    }
  }

  return asynSuccess;
}


/**
 * Deal with controller specific asynOctet params.
 * @param pasynUser
 * @param value
 * @param nChars
 * @param nActual
 * @return asynStatus
 */
asynStatus p6kController::writeOctet(asynUser *pasynUser, const char *value, 
                                    size_t nChars, size_t *nActual)
{
    int function = pasynUser->reason;
    asynStatus status = asynSuccess;
    p6kAxis *pAxis = NULL;
    char command[P6K_MAXBUF_] = {0};
    char response[P6K_MAXBUF_] = {0};
    char error[P6K_MAXBUF_] = {0};
    const char *functionName = "parker6kController::writeOctet";

    asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s.\n", functionName);

    pAxis = this->getAxis(pasynUser);
    if (!pAxis) {
      return asynError;
    } 
    
    if (function == P6K_C_Command_) {
      //Send command to controller
      epicsSnprintf(command, P6K_MAXBUF_, "%s", value);
      if (lowLevelWriteRead(command, response) != asynSuccess) {
	epicsSnprintf(error, P6K_MAXBUF_, "Command %s failed", command);
	asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		  "%s: %s.\n", functionName, error);
	setStringParam(P6K_C_Error_, error);
	setStringParam(P6K_C_Response_, " ");
      } else {
	setStringParam(P6K_C_Response_, response);
	setStringParam(P6K_C_Error_, " ");
      }
    } else if (function == P6K_A_Command_) {
      //Send axis specific command to controller. 
      //This adds on the axis number to the command
      //epicsSnprintf(command, P6K_MAXBUF_, "%d%s", pAxis->axisNo_, value);
      //if (lowLevelWriteRead(command, response) != asynSuccess) {
      //asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
      //	  "%s: Command %s failed for axis %d.\n", functionName, command, pAxis->axisNo_);
      //} else {
      //	setStringParam(P6K_A_Response_, response);
      //}
    } else {
      status = asynMotorController::writeOctet(pasynUser, value, nChars, nActual);
    }

    if (status != asynSuccess) {
      callParamCallbacks();
      return asynError;
    }
    
    /* Set the parameter in the parameter library. */
    status = (asynStatus)setStringParam(function, (char *)value);
    /* Do callbacks so higher layers see any changes */
    status = (asynStatus)callParamCallbacks();

    if (status!=asynSuccess) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
              "%s Error Setting Parameter. asynUser->reason: %d\n", 
              functionName, function);
    }

    *nActual = nChars;
    return status;
}


/** Returns a pointer to an p6kAxis object.
  * Returns NULL if the axis number encoded in pasynUser is invalid.
  * \param[in] pasynUser asynUser structure that encodes the axis index number. */
p6kAxis* p6kController::getAxis(asynUser *pasynUser)
{
  int32_t axisNo = 0;
    
  getAddress(pasynUser, &axisNo);
  return getAxis(axisNo);
}



/** Returns a pointer to an p6kAxis object.
  * Returns NULL if the axis number is invalid.
  * \param[in] axisNo Axis index number. */
p6kAxis* p6kController::getAxis(int axisNo)
{
  if ((axisNo < 0) || (axisNo >= numAxes_)) return NULL;
  return pAxes_[axisNo];
}

/**
 * Wrapper for asynMotorController::startPoller.
 * @return asynStatus
 */
asynStatus p6kController::startPoller(void)
{
  asynStatus status = asynError;
  static const char *functionName = "p6kController::startPoller";

  printf("%s: Starting poller.\n", functionName);

  status = asynMotorController::startPoller(movingPollPeriod_, idlePollPeriod_, P6K_FORCED_FAST_POLLS_);

  return status;
}


/** 
 * Polls the controller, rather than individual axis.
 * @return asynStatus
 */
asynStatus p6kController::poll()
{
  char command[P6K_MAXBUF] = {0};
  char response[P6K_MAXBUF] = {0};
  bool stat = true;
  int32_t nvals = 0;
  uint32_t bits = 0;
  char stringVal[P6K_MAXBUF] = {0};
  static const char *functionName = "p6kController::poll";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  if (!lowLevelPortUser_) {
    return asynError;
  }

  /* Get the time and decide if we want to print errors.*/
  epicsTimeGetCurrent(&nowTime_);
  nowTimeSecs_ = nowTime_.secPastEpoch;
  if ((nowTimeSecs_ - lastTimeSecs_) < P6K_ERROR_PRINT_TIME_) {
    printErrors_ = false;
  } else {
    printErrors_ = true;
    lastTimeSecs_ = nowTimeSecs_;
  }

  if (printNextError_) {
    printErrors_ = true;
  }

  //Set any controller specific parameters. 
  //Some of these may be used by the axis poll to set axis bits.

  //Transfer limit and home status and pack into uint32_t param.
  int32_t tlim = 0;
  getIntegerParam(P6K_C_TLIM_Enable_, &tlim);
  setIntegerParam(P6K_C_TLIM_Bits_, 0);
  if (tlim == 1) {
    bits = 0;
    stat = (getDigital(P6K_CMD_TLIM, (sizeof(P6K_CMD_TLIM)-1), &bits) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TLIM_Bits_, bits) == asynSuccess) && stat;
  }

  //Transfer input and output signals and pack into uint32_t param.
  int32_t inout = 0;
  getIntegerParam(P6K_C_INOUT_Enable_, &inout);
  setIntegerParam(P6K_C_TOUT_Bits_, 0);
  setIntegerParam(P6K_C_TIN_Bits_, 0);
  if (inout == 1) {
    bits = 0;
    stat = (getDigital(P6K_CMD_TOUT, (sizeof(P6K_CMD_TOUT)-1), &bits) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TOUT_Bits_, bits) == asynSuccess) && stat;

    bits = 0;
    stat = (getDigital(P6K_CMD_TIN, (sizeof(P6K_CMD_TIN)-1), &bits) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TIN_Bits_, bits) == asynSuccess) && stat;
  }
  
  //Transfer system status
  epicsSnprintf(command, P6K_MAXBUF, "%s", P6K_CMD_TSS);
  stat = (lowLevelWriteRead(command, response) == asynSuccess) && stat;
  if (stat) {
    nvals = sscanf(response, P6K_CMD_TSS"%s", stringVal);
    if (nvals <= 0) {
      stat = false;
      if (printErrors_) {
	asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		  "%s: ERROR: Problem reading TSS on controller %s\n", 
		  functionName, this->portName);
      }
    }
  }
  memset(command, 0, sizeof(command));
   
  if (stat) {
    stat = (setIntegerParam(P6K_C_TSS_SystemReady_, (stringVal[P6K_TSS_SYSTEMREADY_] == P6K_ON_)) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TSS_ProgRunning_, (stringVal[P6K_TSS_PROGRUNNING_] == P6K_ON_)) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TSS_Immediate_,   (stringVal[P6K_TSS_IMMEDIATE_]   == P6K_ON_)) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TSS_CmdError_,    (stringVal[P6K_TSS_CMDERROR_]    == P6K_ON_)) == asynSuccess) && stat;
    stat = (setIntegerParam(P6K_C_TSS_MemError_,    (stringVal[P6K_TSS_MEMERROR_]    == P6K_ON_)) == asynSuccess) && stat;
  }
  
  callParamCallbacks();

  if (!stat) {
    if (printErrors_) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s: ERROR: Problem reading status on controller %s\n", 
		functionName, this->portName);
    }
    setIntegerParam(P6K_C_CommsError_, P6K_ERROR_);
    setStringParam(P6K_C_Error_, "Problem reading controller status");
    printNextError_ = false;
    return asynError;
  } else {
    if (!printErrors_) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s: Problem cleared on controller %s\n", 
		functionName, this->portName);
    }
    setIntegerParam(P6K_C_CommsError_, P6K_OK_);
    setStringParam(P6K_C_Error_, " ");
    printNextError_ = true;
    return asynSuccess;
  }
}


/**
 * Write a configuration file to the controller. This function reads a ASCII file
 * that should only contain P6K commands terminated by a newline. 
 * Any commands with comments or whitespace are rejected. 
 * I kept this simple to leave open the possibility of
 * porting to other platforms.
 * 
 * If any command fails then the function prints an error and sets an error parameter.
 *
 * This function should be called after the driver controller instantiation, but before
 * the axis objects are instantiated. Calling this function to setup the controller
 * is optional. The driver can be used without it if the user has another means of 
 * pre-configuring the controller.
 * 
 * @param filename (and full path)
 * @return asynStatus
 */
asynStatus p6kController::upload(const char *filename) 
{
  asynStatus status = asynSuccess;
  FILE *fptr = NULL;
  char line[P6K_MAXBUF_] = {0};
  char response[P6K_MAXBUF_] = {0};
  const char *whitespace = "# \n\t";
  uint32_t count = 0;
  const char *functionName = "p6kController::upload";

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);  

  printf("%s: Uploading file: %s\n", functionName, filename);  

  if (access(filename, R_OK) != 0) {
    perror(functionName);
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
              "%s ERROR: File could not be read.\n", functionName);
    setStringParam(P6K_C_Error_, "ERROR: Upload file could not be read.");
    status = asynError;
  }

  if (status == asynSuccess) {
    if ((fptr = fopen(filename, "r")) == NULL) {
      perror(functionName);
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s ERROR: File could not be read.\n", functionName);
      status = asynError;
    }

    while (fgets(line, P6K_MAXBUF_-1, fptr)) {
      //Remove newline
      line[strlen(line)-1]='\0';
      //reject if any whitespace (but allow in IF statements)
      if ((strpbrk(line, whitespace) == NULL) || (strncmp(line, "IF", 2) == 0)) {
        printf("%s: %s\n", functionName, line);
        epicsThreadSleep(0.05);
        if (lowLevelWriteRead(line, response) != asynSuccess) {
          asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
              "%s: Command %s failed.\n", functionName, line);
          status = asynError;
          break;
        }
        ++count;
      } else {
        // TZ: No need for print statements. TODO: Remove this else
        //asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
        //    "%s: Skipping %s due to whitespace.\n", functionName, line);
        // TZ: We just want to skip, not quit if we find a white space
        // status = asynError;
        //break;
        }
      memset(line, 0, sizeof(line));
    }
    
  }

  if (fclose(fptr)) {
    perror(functionName);
  }

  if (count==0) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
              "%s ERROR: Empty file.\n", functionName);
    status = asynError;
  }

  if (status != asynSuccess) {
    setIntegerParam(P6K_C_Config_, 0);
    callParamCallbacks();
  }

  epicsThreadSleep(5);

  return status;
}


/**
 * Implement co-ordinated moves.
 * @param deferMoves Flag to indicate we are setting or executing deferred moves.
 *                   0=turn off (execute), 1=turn on (defer moves)
 * @return asynStatus 
 */
asynStatus p6kController::setDeferredMoves(bool deferMoves)
{
  asynStatus status = asynSuccess;
  bool stat = true;
  char command[P6K_MAXBUF_] = {0};
  char response[P6K_MAXBUF_] = {0};
  uint32_t move[P6K_MAXAXES_+1] = {0};
  p6kAxis *pAxis = NULL;
  static const char *functionName = "p6kController::setDeferredMoves";

  cout << functionName << endl;

  asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW, "%s\n", functionName);

  //If we are not ending deferred moves then return
  if (deferMoves || !movesDeferred_) {
    movesDeferred_ = true;
    return asynSuccess;
  }

  //Set the distance to move for each axis
  for (int32_t axis=0; axis<numAxes_; ++axis) {
    pAxis = getAxis(axis);
    if (pAxis != NULL) {
      if (pAxis->deferredMove_) {
	epicsSnprintf(command, P6K_MAXBUF, "%dD%d", pAxis->axisNo_, pAxis->deferredPosition_);
	stat = (lowLevelWriteRead(command, response) == asynSuccess) && stat;
	if (static_cast<uint32_t>(axis) <= P6K_MAXAXES_) {
	  move[axis] = 1;
	}
	memset(command, 0, sizeof(command));
      }
    }
  }

  //If any commands failed, don't execute, cancel deferred move and return
  if (!stat) {
    asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
	      "%s ERROR Sending Deferred Move Positions.\n", functionName);
    status = asynError;
  } else {
  
    //Execute the deferred move
    epicsSnprintf(command, P6K_MAXBUF, "GO%d%d%d%d%d%d%d%d", 
	     move[1],move[2],move[3],move[4],move[5],move[6],move[7],move[8]);
    if (lowLevelWriteRead(command, response) != asynSuccess) {
      asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
		"%s ERROR Sending Deferred Move Command.\n", functionName);
      setStringParam(P6K_C_Error_, "ERROR: Deferred Move Failed");
      status = asynError;
    } else {
      setStringParam(P6K_C_Error_, " ");
      status = asynSuccess;
    }
    
  }

  //Clear deferred move flag for the axes involved.
  for (int32_t axis=0; axis<numAxes_; axis++) {
    pAxis = getAxis(axis);
    if (pAxis!=NULL) {
      if (pAxis->deferredMove_) {
	pAxis->deferredMove_ = 0;
      }
    }
  }

  movesDeferred_ = false;
     
  return status;
}





/*************************************************************************************/
/** The following functions have C linkage, and can be called directly or from iocsh */

extern "C" {

/**
 * C wrapper for the p6kController constructor.
 * See p6kController::p6kController.
 *
 */
asynStatus p6kCreateController(const char *portName, const char *lowLevelPortName, 
			       int lowLevelPortAddress, int numAxes, 
			       int movingPollPeriod, int idlePollPeriod)
{

    p6kController *pp6kController
      = new p6kController(portName, lowLevelPortName, lowLevelPortAddress, 
			  numAxes, movingPollPeriod/1000., idlePollPeriod/1000.);
    if (pp6kController) {
      pp6kController = NULL;
    }

    return asynSuccess;
}

/**
 * C wrapper for the p6kAxis constructor.
 * See p6kAxis::p6kAxis.
 *
 */
asynStatus p6kCreateAxis(const char *p6kName,   //specify which controller by port name
			 int axis)               //axis number (start from 1).
{
  p6kController *pC;
  p6kAxis *pAxis;

  static const char *functionName = "p6kCreateAxis";

  pC = (p6kController*) findAsynPortDriver(p6kName);
  if (!pC) {
    printf("%s::%s: ERROR Port %s Not Found.\n",
           driverName, functionName, p6kName);
    return asynError;
  }

  if (axis == 0) {
    printf("%s::%s: ERROR Axis Number 0 Not Allowed. "
	   "This Asyn Address Is Reserved For Controller Specific Parameters.\n",
	   driverName, functionName);
    return asynError;
  }
  
  pC->lock();
  pAxis = new p6kAxis(pC, axis);
  if (pAxis) {
    pAxis = NULL;
  }
  pC->unlock();
  return asynSuccess;
}

/**
 * C wrapper for the p6kAxis constructor.
 * This function also connects the Axis object to the modbus port so we can
 * read an encoder position from modbus. 
 * See p6kAxis::p6kAxis.
 *
 */
asynStatus p6kCreateModbusEncAxis(const char *p6kName,    //specify which controller by port name
                                  int axis,               //axis number (start from 1)
                                  const char *modbusPort, //modbus asyn port
                                  int modbusAddr,         //modbus address offset (in 16-bit words)
                                  int modbusOffset)       //modbus encoder offset
                                  
{
  p6kController *pC;
  p6kAxis *pAxis;
  asynStatus status = asynSuccess;

  static const char *functionName = "p6kCreateAxis";

  pC = (p6kController*) findAsynPortDriver(p6kName);
  if (!pC) {
    printf("%s::%s: ERROR Port %s Not Found.\n",
           driverName, functionName, p6kName);
    return asynError;
  }

  if (axis == 0) {
    printf("%s::%s: ERROR Axis Number 0 Not Allowed. "
	   "This Asyn Address Is Reserved For Controller Specific Parameters.\n",
	   driverName, functionName);
    return asynError;
  }
  
  pC->lock();
  pAxis = new p6kAxis(pC, axis);

  if (pAxis->modbusPortConnect(modbusPort, modbusAddr, modbusOffset) != asynSuccess) {
    printf("%s::%s: ERROR Failed to connect to modbus port %s, addr %d\n.",
	   driverName, functionName, modbusPort, modbusAddr);
    status = asynError;
  }

  if (pAxis) {
    pAxis = NULL;
  }
  pC->unlock();
  return status;
}

/**
 * C Wrapper function for p6kAxis constructor.
 * See p6kAxis::p6kAxis.
 * This function allows creation of multiple p6kAxis objects with axis numbers 1 to numAxes.
 * @param p6kName Asyn port name for the controller (const char *)
 * @param numAxes The number of axes to create, starting at 1.
 *
 */
asynStatus p6kCreateAxes(const char *p6kName,        
			  int numAxes)                   
{
  p6kController *pC;
  p6kAxis *pAxis;

  static const char *functionName = "p6kCreateAxis";

  pC = (p6kController*) findAsynPortDriver(p6kName);
  if (!pC) {
    printf("%s:%s: Error port %s not found\n",
           driverName, functionName, p6kName);
    return asynError;
  }
  
  pC->lock();
  for (int axis=1; axis<=numAxes; axis++) {
    pAxis = new p6kAxis(pC, axis);
    if (pAxis) {
      pAxis = NULL;
    }
  }
  pC->unlock();
  return asynSuccess;
}

/**
 * Wrapper for p6kController::upload.
 * @param p6kName Controller port name
 * @param filename The full filename and path to the config file.
 */
asynStatus p6kUpload(const char *p6kName, const char *filename)
{
  asynStatus status = asynError; 
  p6kController *pC;
  static const char *functionName = "p6kUpload";
  pC = (p6kController*) findAsynPortDriver(p6kName);
  if (!pC) {
    printf("%s:%s: Error port %s not found\n",
           driverName, functionName, p6kName);
    return status;
  }

  pC->lock();
  status = pC->upload(filename);
  pC->unlock();
  
  return status;
}



/* Code for iocsh registration */

/* p6kCreateController */
static const iocshArg p6kCreateControllerArg0 = {"Controller port name", iocshArgString};
static const iocshArg p6kCreateControllerArg1 = {"Low level port name", iocshArgString};
static const iocshArg p6kCreateControllerArg2 = {"Low level port address", iocshArgInt};
static const iocshArg p6kCreateControllerArg3 = {"Number of axes", iocshArgInt};
static const iocshArg p6kCreateControllerArg4 = {"Moving poll rate (ms)", iocshArgInt};
static const iocshArg p6kCreateControllerArg5 = {"Idle poll rate (ms)", iocshArgInt};
static const iocshArg * const p6kCreateControllerArgs[] = {&p6kCreateControllerArg0,
							    &p6kCreateControllerArg1,
							    &p6kCreateControllerArg2,
							    &p6kCreateControllerArg3,
							    &p6kCreateControllerArg4,
							    &p6kCreateControllerArg5};
static const iocshFuncDef configp6kCreateController = {"p6kCreateController", 6, p6kCreateControllerArgs};
static void configp6kCreateControllerCallFunc(const iocshArgBuf *args)
{
  p6kCreateController(args[0].sval, args[1].sval, args[2].ival, args[3].ival, args[4].ival, args[5].ival);
}


/* p6kCreateAxis */
static const iocshArg p6kCreateAxisArg0 = {"Controller port name", iocshArgString};
static const iocshArg p6kCreateAxisArg1 = {"Axis number", iocshArgInt};
static const iocshArg * const p6kCreateAxisArgs[] = {&p6kCreateAxisArg0,
                                                     &p6kCreateAxisArg1};
static const iocshFuncDef configp6kAxis = {"p6kCreateAxis", 2, p6kCreateAxisArgs};

static void configp6kAxisCallFunc(const iocshArgBuf *args)
{
  p6kCreateAxis(args[0].sval, args[1].ival);
}

/* p6kCreateModbusEncAxis */
static const iocshArg p6kCreateModbusEncAxisArg0 = {"Controller port name", iocshArgString};
static const iocshArg p6kCreateModbusEncAxisArg1 = {"Axis number", iocshArgInt};
static const iocshArg p6kCreateModbusEncAxisArg2 = {"Modbus Port Name", iocshArgString};
static const iocshArg p6kCreateModbusEncAxisArg3 = {"Modbus Port Address", iocshArgInt};
static const iocshArg p6kCreateModbusEncAxisArg4 = {"Modbus Enc Offset", iocshArgInt};
static const iocshArg * const p6kCreateModbusEncAxisArgs[] = {&p6kCreateModbusEncAxisArg0,
                                                              &p6kCreateModbusEncAxisArg1,
                                                              &p6kCreateModbusEncAxisArg2,
                                                              &p6kCreateModbusEncAxisArg3,
                                                              &p6kCreateModbusEncAxisArg4};
static const iocshFuncDef configp6kModbusEncAxis = {"p6kCreateModbusEncAxis", 5, p6kCreateModbusEncAxisArgs};

static void configp6kModbusEncAxisCallFunc(const iocshArgBuf *args)
{
  p6kCreateModbusEncAxis(args[0].sval, args[1].ival, args[2].sval, args[3].ival, args[4].ival);
}

/* p6kCreateAxes */
static const iocshArg p6kCreateAxesArg0 = {"Controller port name", iocshArgString};
static const iocshArg p6kCreateAxesArg1 = {"Num Axes", iocshArgInt};
static const iocshArg * const p6kCreateAxesArgs[] = {&p6kCreateAxesArg0,
                                                     &p6kCreateAxesArg1};
static const iocshFuncDef configp6kAxes = {"p6kCreateAxes", 2, p6kCreateAxesArgs};

static void configp6kAxesCallFunc(const iocshArgBuf *args)
{
  p6kCreateAxes(args[0].sval, args[1].ival);
}

/* p6kUpload */
static const iocshArg p6kUploadArg0 = {"Controller port name", iocshArgString};
static const iocshArg p6kUploadArg1 = {"Filename", iocshArgString};
static const iocshArg * const p6kUploadArgs[] = {&p6kUploadArg0,
						 &p6kUploadArg1};
static const iocshFuncDef configp6kUpload = {"p6kUpload", 2, p6kUploadArgs};
static void configp6kUploadCallFunc(const iocshArgBuf *args)
{
  p6kUpload(args[0].sval, args[1].sval);
}


static void p6kControllerRegister(void)
{
  iocshRegister(&configp6kCreateController,   configp6kCreateControllerCallFunc);
  iocshRegister(&configp6kAxis,               configp6kAxisCallFunc);
  iocshRegister(&configp6kModbusEncAxis,      configp6kModbusEncAxisCallFunc);
  iocshRegister(&configp6kAxes,               configp6kAxesCallFunc);
  iocshRegister(&configp6kUpload,             configp6kUploadCallFunc);
}
epicsExportRegistrar(p6kControllerRegister);


} // extern "C"
