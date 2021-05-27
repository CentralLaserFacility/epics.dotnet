#line 1 "XPS_trajectoryScan.st"
program XPS_trajectoryScan("P=13BMC:,R=traj1,IPADDR=164.54.160.34,PORT=5001,"
                           "USERNAME=Administrator,PASSWORD=Administrator,"
                           "M1=m1,M2=m2,M3=m3,M4=m4,M5=m5,M6=m6,M7=m7,M8=m8,"
                           "GROUP=g1,"
                           "P1=p1,P2=p2,P3=p3,P4=p4,P5=p5,P6=p6,P7=p7,P8=p8")

/*  
 *  This sequencer program works with trajectoryScan.db.  It implements
 *  coordinated trajectory motion with the Newport XPS-C8 motor controller.
 *  It can be used with the Newport General Purpose Diffractometer or with any
 *  other set of motors connected to that controller.
 *  
 *  Original author: Jon Kelly, based on Mark Rivers' version for the MM4000.
 *  Current author:  Mark Rivers
 *
 * Modifications:
*/

%% #include <string.h>
%% #include <stdio.h>
%% #include <math.h>
%% #include <stdarg.h>
%% #define epicsExportSharedSymbols
%% #include <shareLib.h>
%% #include "XPS_C8_drivers.h"
%% #include "XPS_C8_errors.h"
%% #include "Socket.h"
%% #include "xps_ftp.h"

#line 1 "C:\\epics\\include\\seq_release.h"


#line 31 "XPS_trajectoryScan.st"



/* This program must be compiled with the recursive option */
option +r;

/* Maximum # of trajectory elements.  The number of points XPS can accept
 * is almost unlimited because the data is stored in a file but the channel 
 * access limit with a double data type is 2000 on R3.13 clients.
 */


/* Maximum # of output pulses.  At the moment the pulses are defined by a
 * timer which is synchronised with the trajectory points so the max number
 * of pulses equals the max number of elements.
 */


/* Note that MAX_ELEMENTS, and MAX_PULSES must be defined before
 * including the trajectoryScan.h */
#line 1 "C:\\epics\\motor\\motorApp\\NewportSrc\\trajectoryScan.h"
/* trajectoryScan.h
 * 
 * This file is included in MM4005_trajectoryScan.st and XPS_trajectoryScan.st to
 * ensure consistency and minimize duplication of code.
 */


/* State codes for Build, Read and Execute. Careful, these must match the
 * corresponding MBBI records, but there is no way to check this */









/* Status codes for Build, Execute and Read */






/* Time modes */



/* Move modes */




/* The maximum number of axes per controller.  If this is changed from 8
 * then many assign statements in this file must be changed */


/* Define PVs */
int     debugLevel;  assign debugLevel   to "{P}{R}DebugLevel.VAL"; 
monitor debugLevel;
int     numAxes;     assign numAxes      to "{P}{R}NumAxes.VAL"; 
monitor numAxes;
int     nelements;   assign nelements    to "{P}{R}Nelements.VAL"; 
monitor nelements;
int     npulses;     assign npulses      to "{P}{R}Npulses.VAL"; 
monitor npulses;
int     startPulses; assign startPulses  to "{P}{R}StartPulses.VAL"; 
monitor startPulses;
int     endPulses;   assign endPulses    to "{P}{R}EndPulses.VAL"; 
monitor endPulses;
int     nactual;     assign nactual      to "{P}{R}Nactual.VAL"; 
int     moveMode;    assign moveMode     to "{P}{R}MoveMode.VAL";    
monitor moveMode;
double  time_PV;        assign time_PV         to "{P}{R}Time.VAL";      
monitor time_PV;
double  timeScale;   assign timeScale    to "{P}{R}TimeScale.VAL"; 
monitor timeScale;
int     timeMode;    assign timeMode     to "{P}{R}TimeMode.VAL";    
monitor timeMode;
double  accel;       assign accel        to "{P}{R}Accel.VAL";     
monitor accel;
int     build;       assign build        to "{P}{R}Build.VAL";     
monitor build;
int     buildState;  assign buildState   to "{P}{R}BuildState.VAL"; 
int     buildStatus; assign buildStatus  to "{P}{R}BuildStatus.VAL"; 
string  buildMessage;assign buildMessage to "{P}{R}BuildMessage.VAL";
int     simMode;     assign simMode      to "{P}{R}SimMode.VAL";   
monitor simMode;
int     execute;     assign execute      to "{P}{R}Execute.VAL";   
monitor execute;
int     execState;   assign execState    to "{P}{R}ExecState.VAL";  
monitor execState; 
int     execStatus;  assign execStatus   to "{P}{R}ExecStatus.VAL";   
string  execMessage; assign execMessage  to "{P}{R}ExecMessage.VAL";
int     abort;       assign abort        to "{P}{R}Abort.VAL";   
monitor abort;
int     readback;    assign readback     to "{P}{R}Readback.VAL";   
monitor readback;
int     readState;   assign readState    to "{P}{R}ReadState.VAL";   
int     readStatus;  assign readStatus   to "{P}{R}ReadStatus.VAL";   
string  readMessage; assign readMessage  to "{P}{R}ReadMessage.VAL";
double  timeTrajectory[2000];
assign  timeTrajectory to  "{P}{R}TimeTraj.VAL"; 
monitor timeTrajectory;
string  trajectoryFile; assign trajectoryFile to "{P}{R}TrajectoryFile.VAL";
monitor trajectoryFile;

int     moveAxis[8]; 
assign  moveAxis     to
        {"{P}{R}M1Move.VAL",
         "{P}{R}M2Move.VAL",
         "{P}{R}M3Move.VAL",
         "{P}{R}M4Move.VAL",
         "{P}{R}M5Move.VAL",
         "{P}{R}M6Move.VAL",
         "{P}{R}M7Move.VAL",
         "{P}{R}M8Move.VAL"};
monitor moveAxis;

double  motorTrajectory[8][2000]; 
assign  motorTrajectory to
        {"{P}{R}M1Traj.VAL",
         "{P}{R}M2Traj.VAL",
         "{P}{R}M3Traj.VAL",
         "{P}{R}M4Traj.VAL",
         "{P}{R}M5Traj.VAL",
         "{P}{R}M6Traj.VAL",
         "{P}{R}M7Traj.VAL",
         "{P}{R}M8Traj.VAL"};
monitor motorTrajectory;

double  motorReadbacks[8][2000]; 
assign  motorReadbacks to
        {"{P}{R}M1Actual.VAL",
         "{P}{R}M2Actual.VAL",
         "{P}{R}M3Actual.VAL",
         "{P}{R}M4Actual.VAL",
         "{P}{R}M5Actual.VAL",
         "{P}{R}M6Actual.VAL",
         "{P}{R}M7Actual.VAL",
         "{P}{R}M8Actual.VAL"};

double  motorError[8][2000]; 
assign  motorError  to
        {"{P}{R}M1Error.VAL",
         "{P}{R}M2Error.VAL",
         "{P}{R}M3Error.VAL",
         "{P}{R}M4Error.VAL",
         "{P}{R}M5Error.VAL",
         "{P}{R}M6Error.VAL",
         "{P}{R}M7Error.VAL",
         "{P}{R}M8Error.VAL"};

double  motorCurrent[8]; 
assign  motorCurrent to
        {"{P}{R}M1Current.VAL",
         "{P}{R}M2Current.VAL",
         "{P}{R}M3Current.VAL",
         "{P}{R}M4Current.VAL",
         "{P}{R}M5Current.VAL",
         "{P}{R}M6Current.VAL",
         "{P}{R}M7Current.VAL",
         "{P}{R}M8Current.VAL"};

double  motorMDVS[8]; 
assign  motorMDVS   to
        {"{P}{R}M1MDVS.VAL",
         "{P}{R}M2MDVS.VAL",
         "{P}{R}M3MDVS.VAL",
         "{P}{R}M4MDVS.VAL",
         "{P}{R}M5MDVS.VAL",
         "{P}{R}M6MDVS.VAL",
         "{P}{R}M7MDVS.VAL",
         "{P}{R}M8MDVS.VAL"};
monitor motorMDVS;

double  motorMDVA[8]; 
assign  motorMDVA   to
        {"{P}{R}M1MDVA.VAL",
         "{P}{R}M2MDVA.VAL",
         "{P}{R}M3MDVA.VAL",
         "{P}{R}M4MDVA.VAL",
         "{P}{R}M5MDVA.VAL",
         "{P}{R}M6MDVA.VAL",
         "{P}{R}M7MDVA.VAL",
         "{P}{R}M8MDVA.VAL"};

int     motorMDVE[8]; 
assign  motorMDVE   to
        {"{P}{R}M1MDVE.VAL",
         "{P}{R}M2MDVE.VAL",
         "{P}{R}M3MDVE.VAL",
         "{P}{R}M4MDVE.VAL",
         "{P}{R}M5MDVE.VAL",
         "{P}{R}M6MDVE.VAL",
         "{P}{R}M7MDVE.VAL",
         "{P}{R}M8MDVE.VAL"};

double  motorMVA[8]; 
assign  motorMVA    to
        {"{P}{R}M1MVA.VAL",
         "{P}{R}M2MVA.VAL",
         "{P}{R}M3MVA.VAL",
         "{P}{R}M4MVA.VAL",
         "{P}{R}M5MVA.VAL",
         "{P}{R}M6MVA.VAL",
         "{P}{R}M7MVA.VAL",
         "{P}{R}M8MVA.VAL"};

int     motorMVE[8]; 
assign  motorMVE    to
        {"{P}{R}M1MVE.VAL",
         "{P}{R}M2MVE.VAL",
         "{P}{R}M3MVE.VAL",
         "{P}{R}M4MVE.VAL",
         "{P}{R}M5MVE.VAL",
         "{P}{R}M6MVE.VAL",
         "{P}{R}M7MVE.VAL",
         "{P}{R}M8MVE.VAL"};

double  motorMAA[8]; 
assign  motorMAA    to
        {"{P}{R}M1MAA.VAL",
         "{P}{R}M2MAA.VAL",
         "{P}{R}M3MAA.VAL",
         "{P}{R}M4MAA.VAL",
         "{P}{R}M5MAA.VAL",
         "{P}{R}M6MAA.VAL",
         "{P}{R}M7MAA.VAL",
         "{P}{R}M8MAA.VAL"};

int     motorMAE[8]; 
assign  motorMAE    to
        {"{P}{R}M1MAE.VAL",
         "{P}{R}M2MAE.VAL",
         "{P}{R}M3MAE.VAL",
         "{P}{R}M4MAE.VAL",
         "{P}{R}M5MAE.VAL",
         "{P}{R}M6MAE.VAL",
         "{P}{R}M7MAE.VAL",
         "{P}{R}M8MAE.VAL"};

/* We don't assign the EPICS motors here because there may be fewer than 
 * MAX_AXES actually in use. */
double  epicsMotorPos[8]; 
assign  epicsMotorPos to {"","","","","","","",""};
monitor epicsMotorPos;

double  epicsMotorDir[8]; 
assign  epicsMotorDir to {"","","","","","","",""};
monitor epicsMotorDir;

double  epicsMotorOff[8]; 
assign  epicsMotorOff to {"","","","","","","",""};
monitor epicsMotorOff;

double  epicsMotorDone[8]; 
assign  epicsMotorDone to {"","","","","","","",""};
monitor epicsMotorDone;


evflag buildMon;        sync build      buildMon;
evflag executeMon;      sync execute    executeMon;
evflag execStateMon;    sync execState  execStateMon;
evflag abortMon;        sync abort      abortMon;
evflag readbackMon;     sync readback   readbackMon;
evflag nelementsMon;    sync nelements  nelementsMon;
evflag motorMDVSMon;    sync motorMDVS  motorMDVSMon;

#line 52 "XPS_trajectoryScan.st"

/* Buffer sizes */


/* Polling interval for waiting for motors to reach their targets */


/* Socket timeouts */




/* Used within the exec state as a timeout within the while loops which wait for
 * the ss xpsTrajectoryRun to catch up.  The delays are 0.1 second, so 100 loops
 * is 10 seconds. */


/* The maximum size of the item names in gathering, e.g. "GROUP2.POSITIONER1.CurrentPosition" */

/* Number of items per axis */

/* Total length of gathering configuration string */



/* Constants used for FTP to the XPS */


int status;
int i;
int j;
int k;
int anyMoving;
int ncomplete;
int nextra;
int npoints;
int dir;
int pollSocket;
int driveSocket;
int abortSocket;
int positionSocket;
int xpsStatus;
int count;
double dtime;
double posActual;
double posTheory;
double expectedTime;
double initialPos[8];
double trajVel;
double preDistance[8];
double postDistance[8];
double motorLowLimit[8];
double motorHighLimit[8];
double motorMinPos[8];
double motorMaxPos[8];
double pulseTime;
double pulsePeriod;
char groupName[100];
char xpsAddress[100];
char *axisName[8];
char macroBuf[100];
char motorName[100];
char userName[100];
char password[100];
int  xpsPort;

/* Define PVs */

/* All PVs which will be accessed in local C functions need to have their index
 * extracted with pvIndex() */
int motorCurrentIndex[8];
int epicsMotorDoneIndex[8];

/* Note, this should be time_t, but SNL doesn't understand that.  This is
 * the defininition in vxWorks. */
unsigned long startTime;  

/* Define escaped C functions at end of file */
%% static int getMotorPositions(SS_ID ssId, struct UserVar *pVar, double *pos);
%% static int getMotorMoving(SS_ID ssId, struct UserVar *pVar);
%% static int waitMotors(SS_ID ssId, struct UserVar *pVar);
%% static int getEpicsMotorMoving(SS_ID ssId, struct UserVar *pVar);
%% static int waitEpicsMotors(SS_ID ssId, struct UserVar *pVar);

%% static int getSocket(SS_ID ssId, struct UserVar *pVar, double timeout);
%% static void trajectoryExecute(SS_ID ssId, struct UserVar *pVar);
%% static void buildAndVerify(SS_ID ssId, struct UserVar *pVar);
%% static int currentElement(SS_ID ssId, struct UserVar *pVar);
%% static int getGroupStatus(SS_ID ssId, struct UserVar *pVar);
%% static void readGathering(SS_ID ssId, struct UserVar *pVar);
%% static int trajectoryAbort(SS_ID ssId, struct UserVar *pVar);
%% static void printMessage(const char *pformat, ...);


ss xpsTrajectoryScan {

    /* Initialize things when first starting */
    state init {
        when() {
            /* Get the values from the macro parameteters */ 
            strcpy(groupName, macValueGet("GROUP"));
            strcpy(xpsAddress, macValueGet("IPADDR"));
            strcpy(userName, macValueGet("USERNAME"));
            strcpy(password, macValueGet("PASSWORD"));
            xpsPort = atoi(macValueGet("PORT"));
            if (debugLevel > 0) {
                printf("XPS_trajectoryScan: ss xpsTrajectoryScan: state init:"
                       " xpsAddress=%s groupName=%s\n",
                       xpsAddress, groupName);
            }
            for (i=0; i<numAxes; i++) {
                axisName[i] = malloc(100);
                sprintf(macroBuf, "P%d", i+1);
                sprintf(axisName[i], "%s.%s", groupName, macValueGet(macroBuf));
                sprintf(macroBuf, "M%d", i+1);
                sprintf(motorName, "%s%s.VAL", macValueGet("P"), macValueGet(macroBuf));
                pvAssign(epicsMotorPos[i], motorName);
                sprintf(motorName, "%s%s.DIR", macValueGet("P"), macValueGet(macroBuf));
                pvAssign(epicsMotorDir[i], motorName);
                sprintf(motorName, "%s%s.OFF", macValueGet("P"), macValueGet(macroBuf));
                pvAssign(epicsMotorOff[i], motorName);
                sprintf(motorName, "%s%s.DMOV", macValueGet("P"), macValueGet(macroBuf));
                pvAssign(epicsMotorDone[i], motorName);
            }
            xpsStatus = 0;
            ncomplete = 1;
        
            /* Set the arrays to zero */
            for (i=0; i<2000; i++) {
                for (j=0; j<8; j++) {
                    motorTrajectory[j][i] = 0.0;
                }
            }

            /* Force numAxes to be <= MAX_AXES */
            if (numAxes > 8) numAxes = 8;
            
            /* Get sockets for communicating with XPS */
            %%pVar->pollSocket = getSocket(ssId, pVar, 1.0);
            %%pVar->driveSocket = getSocket(ssId, pVar, 100000.);
            %%pVar->abortSocket = getSocket(ssId, pVar, 10.);
        
            for (j=0; j<numAxes; j++) {
                motorCurrentIndex[j]   =  pvIndex(motorCurrent[j]);
                epicsMotorDoneIndex[j] =  pvIndex(epicsMotorDone[j]);
            }

            /* Clear all event flags */
            efClear(buildMon);
            efClear(executeMon);
            efClear(abortMon);
            efClear(readbackMon);
            efClear(nelementsMon);
        } state monitor_inputs
    }


    /* Monitor inputs which control what to do (Build, Execute, Read) */
    state monitor_inputs {
        entry {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state monitor_inputs:"
                       " entry\n");
            }
        }
        when(efTestAndClear(buildMon) && (build==1)) {
        } state build

        when(efTestAndClear(executeMon) && (execute==1) 
                && (buildStatus == 1)){
        } state execute

        when(efTestAndClear(readbackMon) && (readback==1)
                && (execStatus == 1)) {
        } state readback

        when(efTestAndClear(nelementsMon) && (nelements>=1)) {
            /* If nelements changes, then change endPulses to this value,
             * since this is what the user normally wants.  endPulses can be
             * changed again after changing nelements if this is desired. */
            if (moveMode == 0)
                endPulses = nelements;
            else
                endPulses = nelements-1;
            pvPut(endPulses);
        } state monitor_inputs

    }


    /* Build and verify trajectory */
    state build {
        entry {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state build:"
                       " entry\n");
            }
        }
        when() {
            /* Set busy flag while building */
            buildState = 1;
            pvPut(buildState);
            buildStatus=0;
            pvPut(buildStatus);
            
            if (moveMode == 0)
                npoints = nelements;
            else
                npoints = nelements-1;
            /* If total time mode, calc time per element and write,
               else use the array timeTraj  */
            if (timeMode == 0) {
                dtime = time_PV/npoints;
                for (i=0; i<nelements; i++) timeTrajectory[i] = dtime;
                pvPut(timeTrajectory);
            }
        
            /* Compute expected time for trajectory & check element period */
            expectedTime=0;
            for (i=0; i<npoints; i++) {
                expectedTime += timeTrajectory[i];
            }
        
            %%buildAndVerify(ssId, pVar);
         
            /* Export values to PVs */
            for (j=0; j<numAxes; j++) {       
                pvPut(motorMVA[j]);
                pvPut(motorMAA[j]);
            } 
            /* Clear busy flag, post status */
            buildState = 0;
            pvPut(buildState);
            pvPut(buildStatus);
            pvPut(buildMessage);
            /* Clear build command, post.  This is a "busy" record, don't want
             * to do this until build is complete. */
            build=0;
            pvPut(build);
            /* Set exec status to UNDEFINED */
            execStatus = 0;
            pvPut(execStatus);
            strcpy(execMessage, " ");
 
        } state monitor_inputs
    }


    state execute {
        entry {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state execute:"
                       " entry\n");
            }
            %%waitMotors(ssId, pVar);
        
            /* Get the initial positions of the motors */
            for (j=0; j<numAxes; j++) initialPos[j] = epicsMotorPos[j];
            /* Move to start position if required.
             * Subtract distance of initial acceleration element */
            if (moveMode == 1) {
                for (j=0; j<numAxes; j++) {
                    if (moveAxis[j]) {
                        epicsMotorPos[j] = motorTrajectory[j][0] - preDistance[j];
                        pvPut(epicsMotorPos[j]);
                    }
                }
            } else {
                /* Backup by distance of initial acceleration element */
                for (j=0; j<numAxes; j++) {
                    if (moveAxis[j]) {
                        epicsMotorPos[j] = epicsMotorPos[j] - preDistance[j];
                        pvPut(epicsMotorPos[j]);
                    }
                }
            }
            %%waitEpicsMotors(ssId, pVar);
        
           /* Define pulse output for trajectory */
            if (npulses > 0) {
                /* Check validity, modify values if necessary */
                if (startPulses < 1) startPulses = 1;
                if (startPulses > nelements) startPulses = nelements;
                pvPut(startPulses);
                if (endPulses < startPulses) endPulses = startPulses;
                if (endPulses > nelements) endPulses = nelements;
                pvPut(endPulses);

                /* The XPS can only output pulses at a fixed period, not a fixed
                 * distance along the trajectory.  
                 * The trajectory elements where pulses start and stop are
                 * defined with the PVs startPulses and endPulses.
                 * Compute the time between pulses as the total time over which pulses 
                 * should be output divided by the number of pulses to be output. */
                pulseTime=0;
                for (i=startPulses; i<=endPulses; i++) {
                    pulseTime += timeTrajectory[i-1];
                }
                pulsePeriod = pulseTime/npulses;
            } else {
                pulsePeriod = 0.;
            }

            /* Check that the trajectory won't exceed the software limits */
            for (j=0; j<numAxes; j++) {
                if (moveAxis[j]) {
                    status = PositionerUserTravelLimitsGet(pollSocket,
                                                           axisName[j],
                                                           &motorLowLimit[j], 
                                                           &motorHighLimit[j]);
                    /* Note that epicsMotorPos is in user coordinates, motorMinPos and motorLow/HighLimit
                     * are in XPS (dial) coordinates, need to do conversion */
                    if (epicsMotorDir[j] == 0) dir=1; else dir=-1;
                    if (((epicsMotorPos[j]*dir + epicsMotorOff[j]) + motorMinPos[j]) < motorLowLimit[j]) {
                        execStatus = 2;
                        pvPut(execStatus);
                        sprintf(execMessage, "Low soft limit violation on motor %d", j);
                        pvPut(execMessage);
                        printMessage("Low soft limit violation on motor %d, epicsMotorPos=%f, motorMinPos=%f, motorLowLimit=%f\n", 
                                j, epicsMotorPos[j], motorMinPos[j], motorLowLimit[j]);
                    }
                    if (((epicsMotorPos[j]*dir + epicsMotorOff[j]) + motorMaxPos[j]) > motorHighLimit[j]) {
                        execStatus = 2;
                        pvPut(execStatus);
                        sprintf(execMessage, "High soft limit violation on motor %d", j);
                        printMessage("High soft limit violation on motor %d, epicsMotorPos=%f, motorMaxPos=%f, motorHighLimit=%f\n", 
                                j, epicsMotorPos[j], motorMaxPos[j], motorHighLimit[j]);
                        pvPut(execMessage);
                    }
                }
            }
        }
 

        when (execStatus == 2) {
            /* Clear execute command, post.  This is a "busy" record, don't
             * want to do this until execution is complete. */
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state execute:"
                       " execStatus = STATUS_FAILURE\n");
            }
            execute=0;
            pvPut(execute);
        } state monitor_inputs


        when (execStatus != 2) {
            %%pVar->xpsStatus = getGroupStatus(ssId, pVar);
            /* Setting execState here will cause the xpsTrajectoryRun SS to wake up */
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state execute:"
                       " setting execState = EXECUTE_STATE_MOVE_START\n");
            }
            execState = 1;
            pvPut(execState);
            count = 0;
            while (execState != 2 && 
                   count < 100 ) {
                epicsThreadSleep(0.1);
                count++;
            }
            if (count == 100) {
                strcpy(execMessage, "Exec Timeout!");
                pvPut(execMessage);
                execStatus = 3;
                pvPut(execStatus);
            }        
            count = 0;
            /* Wait until ss xpsTrajectoryRun has started the traj scan */
            while (xpsStatus != 45 && 
                   count < 100 && 
                   execStatus != 2 ) {
                epicsThreadSleep(0.1);
                count++;
                %%pVar->xpsStatus = getGroupStatus(ssId, pVar);
            }
            if (count == 100) {
                strcpy(execMessage, "Exec Timeout!");
                pvPut(execMessage);
                execStatus = 3;
                pvPut(execStatus);
            }
            readStatus=0;
            pvPut(readStatus);
        } state wait_execute
    }


    /* Wait for trajectory to complete */
    state wait_execute {
        entry {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state wait_execute:"
                       " entry\n");
            }
        }
        when (execStatus == 3) {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state wait_execute:"
                       " execStatus = STATUS_ABORT\n");
            }
            /* The trajectory_abort state set has detected an abort. It has
             * already posted the status and message.  Don't execute flyback
             * return to top */
            execState = 0;
            pvPut(execState);
            /* Clear execute command, post.  This is a "busy" record, don't
             * want to do this until execution is complete. */
            execute=0;
            pvPut(execute);
        } state monitor_inputs

        when (delay(0.1) && execState==2) {
            /* Get the current motor positions, post them */
            %%getMotorPositions(ssId, pVar, pVar->motorCurrent);
            for (j=0; j<numAxes; j++) pvPut(motorCurrent[j]);

            %%pVar->xpsStatus = getGroupStatus(ssId, pVar);
            if (xpsStatus == 45) {
                %%pVar->ncomplete = currentElement(ssId, pVar);
                sprintf(execMessage, "Executing element %d/%d", 
                        ncomplete, nelements);
                pvPut(execMessage);
            }
            else if (xpsStatus == 12) {
                /* 12 = ready from move */
                execState = 3;
                execStatus = 1;
                strcpy(execMessage, " ");
            }
            else if (xpsStatus < 10) {
                /* The xps group status reflects an error. */
                execState = 3;
                execStatus = 2;
                sprintf(execMessage,"XPS Status Error=%d", xpsStatus);
            }
            /* See if the elapsed time is more than expected, time out */
            if (difftime(time(0), startTime) > (expectedTime+10)) {
                execState = 3;
                execStatus = 4;
                strcpy(execMessage, "Timeout");
            }
        } state wait_execute

        when (execState==3) {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state wait_execute:"
                       " execStatus = EXECUTE_STATE_FLYBACK\n");
            }
            pvPut(execState);
            pvPut(execStatus);
            pvPut(execMessage);

            /* Only do the following if the trajectory executed OK */
            if (execStatus == 1) { 
                /* Make sure the motors have stopped */
                %%waitMotors(ssId, pVar);
                %%waitEpicsMotors(ssId, pVar);        
            
                /* Get the current motor positions, post them */
                %%getMotorPositions(ssId, pVar, pVar->motorCurrent);
                for (j=0; j<numAxes; j++) pvPut(motorCurrent[j]);
                for (j=0; j<numAxes; j++) {
                    epicsMotorPos[j] = motorCurrent[j];
                    pvPut(epicsMotorPos[j]);
                }
                %%waitEpicsMotors(ssId, pVar);
            }
            
            execState = 0;
            pvPut(execState);
            /* Clear execute command, post.  This is a "busy" record, don't
             * want to do this until execution is complete. */
            execute=0;
            pvPut(execute);
        } state monitor_inputs
    }


    /* Read back actual positions */
    state readback {
        entry {
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryScan: state readback:"
                       " entry\n");
            }
        }
        when() {
            /* Set busy flag */
            readState = 1;
            pvPut(readState);
            readStatus=0;
            pvPut(readStatus);
            /* Erase the readback and error arrays */
            for (j=0; j<numAxes; j++) {
                for (i=0; i<2000; i++) {
                    motorReadbacks[j][i] = 0.;
                    motorError[j][i] = 0.;
                }
            }
            
            %%readGathering(ssId, pVar);
           
            /* readGathering has set the actual number of positions read back */
            pvPut(nactual);
 
            /* Post the readback and error arrays */
            for (j=0; j<numAxes; j++) {
                pvPut(motorReadbacks[j]);
                pvPut(motorError[j]);
            }
            /* Clear busy flag */
            readState = 0;
            pvPut(readState);
            /* For now we are not handling read errors */
            readStatus = 1;  
            pvPut(readStatus);
            strcpy(readMessage, " ");
            pvPut(readMessage);
            /* Clear readback command, post.  This is a "busy" record, don't
             * want to do this until readback is complete. */
            readback=0;
            pvPut(readback);
        } state monitor_inputs
    }
}



/* This state set simply monitors the abort input.  It is a separate state set
 * so that it is always active, no matter what the state of the trajectoryScan
 * state set. */
ss xpsTrajectoryAbort {
    state monitorAbort {
        when ((efTestAndClear(abortMon)) && (abort==1) &&
              (execState==2)) {

            execStatus = 3;
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryAbort: state monitorAbort:"
                       " setting execStatus = STATUS_ABORT\n");
            }
            pvPut(execStatus);
            strcpy(execMessage, "Motion aborted");
            pvPut(execMessage);
        
            %%trajectoryAbort(ssId, pVar);
        
            /* Clear abort command, post.  This is a "busy" record, don't
             * want to do this until abort command has been sent. */
            abort=0;
            pvPut(abort);
        } state monitorAbort
    }
}

/* This state was required because the trajectory execute call does not return
 * until the end of the trajectory. So to poll during the scan we call the 
 * scan from a separate state set. */
ss xpsTrajectoryRun {
    state asyncExecute {
        when (efTestAndClear(execStateMon) && (execState == 1)) {
            /*%%pVar->xpsStatus = getGroupStatus(ssId, pVar);*/
            if (debugLevel > 0) {
                printMessage("XPS_trajectoryScan: ss xpsTrajectoryRun: state asyncExecute:"
                       " setting execState = EXECUTE_STATE_EXECUTING\n");
            }
            execState = 2;
            pvPut(execState);

            /* If ready to move */
            if (xpsStatus > 9 && xpsStatus < 20) {
                /* Get start time of execute */        
                startTime = time(0);
                /* Call the C function from here so that the main state set can poll */
                %%trajectoryExecute(ssId, pVar);
            } else {
                execStatus = 2;
                pvPut(execStatus);
            }
        } state asyncExecute
    }
}

/* This state set polls every second to keep the motor current position medm 
 * screen up to date when a scan is not running */
ss xpsTrajectoryPosition {
    state positionUpdate {
        when (delay (1) && (execState == 0)) {
            %%getMotorPositions(ssId, pVar, pVar->motorCurrent);
            for (j=0; j<numAxes; j++) pvPut(motorCurrent[j]);
        } state positionUpdate
    }
}


/*  C functions  */
%{

/* getMotorPositions returns the positions of each motor.
 * It reads the positions from the controller, and then converts to 
 * EPICS motor user coordinates */
static int getMotorPositions(SS_ID ssId, struct UserVar *pVar, double *pos)
{
    int status;
    int j;
    int dir;

    /* Read the current positions of all the axes */
    
    status = GroupPositionCurrentGet(pVar->positionSocket,
                                     pVar->groupName,pVar->numAxes,pos);
    if (status != 0)
        printMessage("Error performing GroupPositionCurrentGet%i\n", status);
    /* Convert from XPS units (which are EPICS motor dial units) to user units */
    for (j=0; j<pVar->numAxes; j++) {
        if (pVar->epicsMotorDir[j] == 0) dir=1; else dir=-1;
        pos[j] = pos[j]*dir + pVar->epicsMotorOff[j];
    }
  
    return(status);
}


/* Returns 0 when no motors are moving */
static int getMotorMoving(SS_ID ssId, struct UserVar *pVar)
{
    int status;
    int moving=0;
    int groupStatus;

    /* Read the current status of the group */

    status = GroupStatusGet(pVar->pollSocket,pVar->groupName,&groupStatus);
    if (status != 0)
        printMessage("Error performing GroupStatusGet %i\n",status);
    
    if (groupStatus > 42)
        moving = 1;

    return(moving);
}

/* getEpicsMotorMoving returns the EPICS moving status of each motor, packed into 
 * a single int.  Bit 0 = motor 1, bit 1 = motor 2, etc. 0=not moving, 1=moving.
 * If the entire int is 0 then no motors are moving */
static int getEpicsMotorMoving(SS_ID ssId, struct UserVar *pVar)
{
    int j;
    int result=0, mask=0x01;

    for (j=0; j<pVar->numAxes; j++) {
		seq_pvGet(ssId, pVar->epicsMotorDoneIndex[j], 0);
        if (pVar->epicsMotorDone[j] == 0) result |= mask;
        mask = mask << 1;
    }
    return(result);
}

/* waitMotors waits for all motors to stop moving.  It reads and posts the
 * motor positions during each loop. */
static int waitMotors(SS_ID ssId, struct UserVar *pVar)
{
    int j;

    /* Logic is that we always want to post position motor positions 
     * after the end of move is detected. */
    while(getMotorMoving(ssId, pVar)) {
        /* Get the current motor positions, post them */
        getMotorPositions(ssId, pVar, pVar->motorCurrent);
        for (j=0; j<pVar->numAxes; j++) {
			seq_pvPut(ssId, pVar->motorCurrentIndex[j], 0);
		}
        epicsThreadSleep(0.1);
    }
    getMotorPositions(ssId, pVar, pVar->motorCurrent);
    for (j=0; j<pVar->numAxes; j++) {
		seq_pvPut(ssId, pVar->motorCurrentIndex[j], 0);
	}
    return(0);
}

/* waitEpicsMotors waits for all motors to stop moving using the EPICS motor
 * records..  It reads and posts the motor positions during each loop. */
static int waitEpicsMotors(SS_ID ssId, struct UserVar *pVar)
{
    int j;

    /* Logic is that we always want to post position motor positions 
     * after the end of move is detected. */
    while(getEpicsMotorMoving(ssId, pVar)) {
        /* Get the current motor positions, post them */
        for (j=0; j<pVar->numAxes; j++) {
            pVar->motorCurrent[j] = pVar->epicsMotorPos[j];
			seq_pvPut(ssId, pVar->motorCurrentIndex[j], 0);
        }
        epicsThreadSleep(0.1);
    }
    for (j=0; j<pVar->numAxes; j++) {
        pVar->motorCurrent[j] = pVar->epicsMotorPos[j];
		seq_pvPut(ssId, pVar->motorCurrentIndex[j], 0);
    }
    return(0);
}

/* Function to ask the XPS for a socket this requires Socket.h */
static int getSocket(SS_ID ssId, struct UserVar *pVar, double timeout)
{
    int sock = 0;
    
    sock = TCP_ConnectToServer(pVar->xpsAddress, pVar->xpsPort, timeout);
    if (sock < 0) 
            printMessage("Error TCP_ConnectToServer, status=%d\n",sock);
    return (sock);
}


/* Function to setup the gathering, events and start the trajectory */
static void trajectoryExecute(SS_ID ssId, struct UserVar *pVar)
{
    int status;
    int j;
    char buffer[60 * 2 * 8];
    int eventId;
    
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " entry\n");
    }
    /* Configure Gathering */
    /* Reset gathering.  
     * This must be done because GatheringOneData just appends to in-memory list */    
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling GatheringReset(%d)\n", pVar->pollSocket);
    }
    status = GatheringReset(pVar->pollSocket);
    if (status != 0) {
        printMessage("Error performing GatheringReset, status=%d\n",status);
        return;
    }

    /* Write list of gathering parameters.
     * Note that there must be NUM_GATHERING_ITEMS per axis in this list. */
    strcpy(buffer, "");
    for (j=0; j<pVar->numAxes; j++) {
        strcat (buffer, pVar->axisName[j]);
        strcat (buffer, ".SetpointPosition;");
        strcat (buffer, pVar->axisName[j]);
        strcat (buffer, ".CurrentPosition;");
    }
    
    /* Define what is to be saved in the GatheringExternal.dat.  
     * 3 pieces of information per axis. */
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling GatheringConfigurationSet(%d, %d, %s)\n",
               pVar->pollSocket, pVar->numAxes*2, buffer);
    }
    status = GatheringConfigurationSet(pVar->pollSocket, 
                                       pVar->numAxes*2, buffer);
    if (status != 0)
            printMessage("Error performing GatheringConfigurationSet, status=%d, buffer=%p\n",
                   status, buffer);

    /* Define trajectory output pulses. 
     * startPulses and endPulses are defined as 1=first real element, need to add
     * 1 to each to skip the acceleration element.  
     * The XPS is told the element to stop outputting pulses, and it seems to stop
     * outputting at the start of that element.  So we need to have that element be
     * the decceleration endPulses is the element, which means adding another +1. */

    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling MultipleAxesPVTPulseOutputSet(%d, %s, %d, %d, %f)\n",
                                           pVar->pollSocket, pVar->groupName,
                                           pVar->startPulses+1, 
                                           pVar->endPulses+1, 
                                           pVar->pulsePeriod);
    }
    status = MultipleAxesPVTPulseOutputSet(pVar->pollSocket, pVar->groupName,
                                           pVar->startPulses+1, 
                                           pVar->endPulses+1, 
                                           pVar->pulsePeriod);

    /* Define trigger */
    sprintf(buffer, "Always;%s.PVT.TrajectoryPulse", pVar->groupName);
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling EventExtendedConfigurationTriggerSet(%d, %d, %s, %s, %s, %s, %s)\n",
                                                  pVar->pollSocket, 2, buffer, 
                                                  "", "", "", "");
    }
    status = EventExtendedConfigurationTriggerSet(pVar->pollSocket, 2, buffer, 
                                                  "", "", "", "");
    if (status != 0) {
        printMessage("Error performing EventExtendedConfigurationTriggerSet, status=%d, buffer=%s\n", 
               status, buffer);
        return;
    }

    /* Define action */
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling EventExtendedConfigurationActionSet(%d, %d, %s, %s, %s, %s, %s)\n",
                                                 pVar->pollSocket, 1, 
                                                 "GatheringOneData", 
                                                 "", "", "", "");
    }
    status = EventExtendedConfigurationActionSet(pVar->pollSocket, 1, 
                                                 "GatheringOneData", 
                                                 "", "", "", "");
    if (status != 0) {
        printMessage("Error performing EventExtendedConfigurationActionSet, status=%d\n",
               status);
        return;
    }

    /* Start gathering */
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling EventExtendedStart(%d, %p)\n",
                                            pVar->pollSocket, &eventId);
    }
    status= EventExtendedStart(pVar->pollSocket, &eventId);
    if (status != 0) {
        printMessage("Error performing EventExtendedStart, status=%d\n",status);
        return;
    }

    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling MultipleAxesPVTExecution(%d, %s, %s, %d)\n",
                                      pVar->driveSocket, pVar->groupName,
                                      pVar->trajectoryFile, 1);
    }
    status = MultipleAxesPVTExecution(pVar->driveSocket, pVar->groupName,
                                      pVar->trajectoryFile, 1);
    /* status -27 means the trajectory was aborted */
    if ((status != 0) && (status != -27))
        printMessage("Error performing MultipleAxesPVTExecution, status=%d\n", status);
    
    /* Remove the event */
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling EventExtendedRemove(%d, %d)\n", pVar->pollSocket, eventId);
    }
    status = EventExtendedRemove(pVar->pollSocket, eventId);
    if (status != 0) {
        printMessage("Error performing ExtendedEventRemove, status=%d\n",status);
        return;
    }
        
    /* Stop the gathering */    
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: trajectoryExecute:"
               " calling GatheringStop(%d)\n", pVar->pollSocket);
    }
    status = GatheringStop(pVar->pollSocket);
    
    /* status -30 means gathering not started i.e. aborted before the end of
       1 trajectory element */
    if ((status != 0) && (status != -30))
        printMessage("Error performing GatheringStop, status=%d\n", status);
    
    return;
}


/* Function to build, install and verify trajectory */ 
static void buildAndVerify(SS_ID ssId, struct UserVar *pVar)
{
    FILE *trajFile;
    int i, j, status;
    int npoints;
    double trajVel;
    double D0, D1, T0, T1;
    SOCKET ftpSocket;
    char fileName[100];
    double distance;
    double maxVelocity[8], maxAcceleration[8];
    double minJerkTime[8], maxJerkTime[8];
    double preTimeMax, postTimeMax;
    double preVelocity[8], postVelocity[8];
    double time;
    int dir[8];
    
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: buildAndVerify:"
               " entry\n");
    }
    /* We create trajectories with an extra element at the beginning and at the end.
     * The distance and time of the first element is defined so that the motors will
     * accelerate from 0 to the velocity of the first "real" element at their 
     * maximum allowed acceleration.
     * Similarly, the distance and time of last element is defined so that the 
     * motors will decelerate from the velocity of the last "real" element to 0 
     * at the maximum allowed acceleration.

    /* Compute the velocity of each motor during the first real trajectory element, 
     * and the time required to reach this velocity. */
    preTimeMax = 0.;
    postTimeMax = 0.;
    /* Zero values since axes may not be used */
    for (j=0; j<pVar->numAxes; j++) {
        preVelocity[j] = 0.;
        postVelocity[j] = 0.;
    }
    for (j=0; j<pVar->numAxes; j++) {
        if (!pVar->moveAxis[j]) continue;
        status = PositionerSGammaParametersGet(pVar->pollSocket, pVar->axisName[j], 
                                               &maxVelocity[j], &maxAcceleration[j],
                                               &minJerkTime[j], &maxJerkTime[j]);
        if (status != 0) {
            printMessage("Error calling positionerSGammaParametersSet, status=%d\n", 
                   status);
        }
        /* The calculation using maxAcceleration read from controller below
         * is "correct" but subject to roundoff errors when sending ASCII commands
         * to XPS.  Reduce acceleration 10% to account for this. */
        maxAcceleration[j] = 0.9 * maxAcceleration[j];
        /* Note: the preDistance and postDistance numbers computed here are
         * in user coordinates, not XPS coordinates, because they are used for 
         * EPICS moves at the start and end of the scan */
        if (pVar->moveMode == 0) {
            distance = pVar->motorTrajectory[j][0];
        } else {
            distance = pVar->motorTrajectory[j][1] - pVar->motorTrajectory[j][0];
        }
        preVelocity[j] = distance/pVar->timeTrajectory[0];
        time = fabs(preVelocity[j]) / maxAcceleration[j];
        if (time > preTimeMax) preTimeMax = time;
        if (pVar->moveMode == 0) {
            distance = pVar->motorTrajectory[j][pVar->nelements-1];
        } else {
            distance = pVar->motorTrajectory[j][pVar->nelements-1] - 
                       pVar->motorTrajectory[j][pVar->nelements-2];
        }
        postVelocity[j] = distance/pVar->timeTrajectory[pVar->nelements-1];
        time = fabs(postVelocity[j]) / maxAcceleration[j];
        if (time > postTimeMax) postTimeMax = time;
    }

    /* Compute the distance that each motor moves during its acceleration phase.
     * Only move it this far. */
    for (j=0; j<pVar->numAxes; j++) {
        pVar->preDistance[j] =  0.5 * preVelocity[j] *  preTimeMax; 
        pVar->postDistance[j] = 0.5 * postVelocity[j] * postTimeMax;
    }

    /* Create the trajectory file */
    trajFile =  fopen (pVar->trajectoryFile, "w");

    /* Compute the sign relationship of user coordinates to XPS coordinates for
     * each axis */
    for (j=0; j<pVar->numAxes; j++) {
        if (pVar->epicsMotorDir[j] == 0) dir[j]=1; else dir[j]=-1;
    }
    /* Create the initial acceleration element */
    fprintf(trajFile,"%f", preTimeMax);
    for (j=0; j<pVar->numAxes; j++) 
        fprintf(trajFile,", %f, %f", pVar->preDistance[j]*dir[j], preVelocity[j]*dir[j]);
    fprintf(trajFile,"\n");
 
    /* The number of points in the file is nelements for MOVE_MODE_RELATIVE and
     * nelements-1 for other modes */
    if (pVar->moveMode == 0) 
        npoints = pVar->nelements;
    else 
        npoints = pVar->nelements-1;
    for (i=0; i<npoints; i++) {
        T0 = pVar->timeTrajectory[i];
        if (i < npoints-1)
            T1 = pVar->timeTrajectory[i+1];
        else
            T1 = T0;
        for (j=0; j<pVar->numAxes; j++) {
            if (pVar->moveMode == 0) {
                D0 = pVar->motorTrajectory[j][i] * dir[j];
                if (i < npoints-1) 
                    D1 = pVar->motorTrajectory[j][i+1] * dir[j];
                else
                    D1 = D0;
            } else {
                D0 = pVar->motorTrajectory[j][i+1] *dir[j] - 
                           pVar->motorTrajectory[j][i] * dir[j];
                if (i < npoints-1) 
                    D1 = pVar->motorTrajectory[j][i+2] * dir[j] - 
                           pVar->motorTrajectory[j][i+1] * dir[j];
                else
                    D1 = D0;
            }
                
            /* Average either side of the point? */
            trajVel = ((D0 + D1) / (T0 + T1));
            if (!(pVar->moveAxis[j])) {
                D0 = 0.0;    /* Axis turned off*/
                trajVel = 0.0;
            }
        
            if (j == 0) fprintf(trajFile,"%f", pVar->timeTrajectory[i]);
            fprintf(trajFile,", %f, %f",D0,trajVel);
            if (j == (pVar->numAxes-1)) fprintf(trajFile,"\n");
        }    
    }

    /* Create the final acceleration element. Final velocity must be 0. */
    fprintf(trajFile,"%f", postTimeMax);
    for (j=0; j<pVar->numAxes; j++) 
        fprintf(trajFile,", %f, %f", pVar->postDistance[j]*dir[j], 0.);
    fprintf(trajFile,"\n");
    fclose (trajFile);
    
    /* FTP the trajectory file from the local directory to the XPS */
    status = ftpConnect(pVar->xpsAddress, pVar->userName, pVar->password, &ftpSocket);
    if (status != 0) {
        printMessage("Error calling ftpConnect, status=%d\n", status);
        return;
    }
    status = ftpChangeDir(ftpSocket, "/Admin/public/Trajectories");
    if (status != 0) {
        printMessage("Error calling ftpChangeDir, status=%d\n", status);
        return;
    }
    status = ftpStoreFile(ftpSocket, pVar->trajectoryFile);
    if (status != 0) {
        printMessage("Error calling ftpStoreFile, status=%d\n", status);
        return;
    }
    status = ftpDisconnect(ftpSocket);
    if (status != 0) {
        printMessage("Error calling ftpDisconnect, status=%d\n", status);
        return;
    }
       
    /* Verify trajectory */
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: buildAndVerify:"
               " calling MultipleAxesPVTVerification(%d, %s, %s)\n", 
               pVar->pollSocket, pVar->groupName, pVar->trajectoryFile);
    }
    status = MultipleAxesPVTVerification(pVar->pollSocket, pVar->groupName,
                                         pVar->trajectoryFile);
     
    pVar->buildStatus = 2;
    if (status == 0) {
        strcpy(pVar->buildMessage, " ");
        pVar->buildStatus = 1;
    }        
    else if (status == -69)
        strcpy(pVar->buildMessage, "Acceleration Too High");
    else if (status == -68)
        strcpy(pVar->buildMessage, "Velocity Too High");
    else if (status == -70)
        strcpy(pVar->buildMessage, "Final Velocity Non Zero");         
    else if (status == -75)
        strcpy(pVar->buildMessage, "Negative or Null Delta Time");         
    else
        sprintf(pVar->buildMessage, "Unknown trajectory verify error=%d", status);  
     
    /* Read dynamic parameters*/
     
    if (status == 0){
        pVar->buildStatus = 1;
    }    
    if (1) {  /* We may need to test for status here */
        for (j=0; j<pVar->numAxes; j++) {
            status = MultipleAxesPVTVerificationResultGet(pVar->pollSocket,
                         pVar->axisName[j], fileName, &pVar->motorMinPos[j], &pVar->motorMaxPos[j], 
                         &pVar->motorMVA[j], &pVar->motorMAA[j]);
            if (status != 0) {
                printMessage("Error performing MultipleAxesPVTVerificationResultGet for axis %s, status=%d\n",
                       pVar->axisName[j], status); 
            }
        }
    } else {
        for (j=0; j<pVar->numAxes; j++) {
            pVar->motorMVA[j] = 0;
            pVar->motorMAA[j] = 0;     
        }
    }
           
    return; 
}


/* Function returns the current trajectory element*/ 
static int currentElement(SS_ID ssId, struct UserVar *pVar)
{
    int status;
    int number;
    char fileName[100];
    
    status = MultipleAxesPVTParametersGet(pVar->pollSocket,
                 pVar->groupName, fileName, &number);
    if (status != 0)
        printMessage("Error performing MultipleAxesPVTParametersGet, status=%d\n", 
               status);
    return (number);
}

static int getGroupStatus(SS_ID ssId, struct UserVar *pVar)
{
    int status;
    int groupStatus;

    /* Read the current status of the group */

    status = GroupStatusGet(pVar->pollSocket,pVar->groupName,&groupStatus);
    if (status != 0)
        printMessage("Error performing GroupStatusGet, status=%d\n", status);
    return(groupStatus);
}


/* Function to read the gathering data that was collected
 * by the XPS as the trajectory was performed and read back the
 * actual motor positions and calculate the position errors */ 
static void readGathering(SS_ID ssId, struct UserVar *pVar)
{
    char *buffer, *bptr, *tptr;
    int currentSamples, maxSamples;
    double setpointPosition, actualPosition;
    int status;
    int dir;
    int i, j;
    int nitems;
    int numRead, numInBuffer, numChars;

    
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: readGathering:"
               " entry\n");
    }
    /* Read the number of lines of gathering */
    status = GatheringCurrentNumberGet(pVar->pollSocket, &currentSamples, &maxSamples);
    if (status != 0) {
        printMessage("Error calling GatherCurrentNumberGet, status=%d\n", status);
        return;
    }
    if (currentSamples != pVar->npulses) {
        printMessage("readGathering: error, npulses=%d, currentSamples=%d\n", 
            pVar->npulses, currentSamples);
        return;
    }
    buffer = (char *)calloc(65536, sizeof(char));
    numInBuffer = 0;
    for (numRead=0; numRead<currentSamples;) {
        /* Read the next buffer */
        /* Try to read all the remaining points */
        status = -1;
        numInBuffer = currentSamples - numRead;
        while (status && (numInBuffer > 0)) {
            status = GatheringDataMultipleLinesGet(pVar->pollSocket, numRead, numInBuffer, buffer);
            if (pVar->debugLevel > 0) {
                printMessage("readGathering: GatheringDataMultipleLinesGet, status=%d, numInBuffer=%d\n", status, numInBuffer);
            }
            if (status) numInBuffer /= 2;
        }
        if (numInBuffer == 0) {
            printMessage("Error reading gathering data, numInBuffer = 0\n");
            goto done;
        }
        bptr = buffer;
        for (i=0; i<numInBuffer; i++) {
            /* Find the next \n and replace with null */
            tptr = strstr(bptr, "\n");
            if (tptr) *tptr = 0;
            for (j=0; j<pVar->numAxes; j++) {
                nitems = sscanf(bptr, "%lf;%lf%n", 
                                &setpointPosition, &actualPosition, &numChars);
                bptr += numChars+1;
                if (nitems != 2) {
                    printMessage("Error reading Gathering.dat file, nitems=%d, should be %d\n",
                           nitems, 2);
                    goto done;
                }
                pVar->motorError[j][numRead] = actualPosition - setpointPosition;
                /* Convert from XPS units to EPICS motor user units */
                if (pVar->epicsMotorDir[j] == 0) dir=1; else dir=-1;
                pVar->motorReadbacks[j][numRead] = actualPosition * dir + pVar->epicsMotorOff[j];
            }
            numRead++;
            pVar->nactual = numRead;
            bptr = tptr + 1;
        }
    }
    
    done:
    free(buffer);
    if (pVar->debugLevel > 0) {
        printMessage("XPS_trajectoryScan: readGathering:"
               " exit\n");
    }

    return;
}

/* Function aborts the trajectory/motion */ 
static int trajectoryAbort(SS_ID ssId, struct UserVar *pVar)
{
    int status;
    
    status = GroupMoveAbort(pVar->abortSocket,pVar->groupName);
    if (status != 0)
        printMessage("Error performing GroupMoveAbort, status=%d\n", status);
       
    return (0);
}

static void printMessage(const char *pformat, ...)
{
    va_list pvar;
    FILE     *fp = stdout;
    epicsTimeStamp now;
    char nowText[40];

    epicsTimeGetCurrent(&now);
    nowText[0] = 0;
    epicsTimeToStrftime(nowText,sizeof(nowText),
         "%Y/%m/%d %H:%M:%S.%03f",&now);
    fprintf(fp,"%s ",nowText);
    va_start(pvar, pformat);
    vfprintf(fp,pformat,pvar);
    va_end(pvar);
    fflush(fp);
}

}%
