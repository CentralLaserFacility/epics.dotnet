#line 1 "xpsSlave.st"
program xpsSlave("name=xpsSlave,P=xxx:,R=xps:slave,IP=192.168.1.11,M=GROUP1.POSITIONER,S=GROUP2")

/* Turn on run-time debug messages */
option +d;
/* Make the generated code reentrant */
option +r;
/* Suppress SNC warnings */
/*option -w;*/

#line 1 "C:\\epics\\motor\\motorApp\\NewportSrc\\seqPVmacros.h"
/*================================================================
 *
 * seqPVmacros.h -- PV-related macros for EPICS State Notation
 *     Language (SNL) code development
 *
 * 2004-May-19	[jemian] merged all DEBUG_PRINTn macros into one macro
 * 2003-Oct-01	[jemian] changed errlogPrintf to printf (can't use in interrupts)
 * 2003-Mar-20	[jemian] changed pvSet to PVPUT (and pvSetStr to PVPUTSTR)
 * 2003-Mar-19	[jemian] changed printf to errlogPrintf
 * 2002-Sep-24	[tischler] added pvSetStr and DEBUG_PRINT (a la Jemian)
 * 2002-Jun-04	[lazmo] renamed to seqPVmacros.h
 * 2002-Mar-08	[lazmo] added pvSet()
 * 2002-Feb-21	[lazmo] fixed comments
 * 2001-Nov-24	[lazmo] added PVA & PVAA
 * 2001-Oct-18  [lazmo] original
 *
 * Author:
 *   M. Laznovsky -- lazmo_at_slac.stanford.edu
 *
 *================================================================
 */

/*----------------------------------------------------------------
 * PV() -- declare a variable and the EPICS PV it's assigned to, with
 * optional monitor & event flag.  One line takes the place of
 * the usual:
 *
 *    int blah;
 *    assign blah ...
 *    monitor blah;
 *    evflag blahFLag;
 *    sync blah ...
 *
 * Format:
 *
 *    PV( varType, varName, pvName, other )
 *
 * Where:
 *
 *    varType   is int, short, float, etc.
 *    varName   is the variable name, e.g. foo
 *    pvName    is the associated PV, e.g. "XYZ:ETC:FOO"
 *    other     is one of the following:
 *                  NoMon
 *                  Monitor
 *                  EvFlag
 *
 * Examples:
 *
 *    PV (int,   gui_goo,   "{STN}:GUI:GOO",   NoMon);     <-- no monitor
 *    PV (float, gui_fudge, "{STN}:GUI:FUDGE", Monitor);   <-- w/monitor
 *    PV (short, gui_run,   "{STN}:GUI:RUN",   EvFlag);    <-- w/monitor & event flag
 *
 *----------------------------------------------------------------
 */






/*----------------------------------------------------------------
 * PVA(), for single waveform rec or array of PVs
 *
 *   "varName" becomes array of <varType>; 3rd arg is number of elements
 *
 * examples:
 *
 *   single waveform record:
 *
 *     PVA (short, plot_x0,  32, "{STN}:DATA:PLOT:X0", NoMon);
 *  
 *   array of PVs:
 *
 *     #define PVA_zap {	\
 *         "{STN}:GUI:ZAP1",	\
 *         "{STN}:GUI:ZAP2",	\
 *         "{STN}:GUI:ZAP3"	\
 *       }
 *     PVA (int, zap, 3, PVA_zap, EvFlag);
 *
 *----------------------------------------------------------------
 */






/*----------------------------------------------------------------
 * PVAA(), for arrays of waveform records
 *
 *   "varName" becomes double-dimensioned array of <varType>
 *   3rd arg is number of waveform records
 *   4th arg is number of elements per record
 *   Need to define another macro first for "_PV_"
 *
 * example:
 *
 *	#define PVAA_plotx {		\
 *	    "{STN}:DATA:PLOT:X1",	\
 *	    "{STN}:DATA:PLOT:X2",	\
 *	    "{STN}:DATA:PLOT:X3"	\
 *	  }
 *	PVAA (short, plotx, 3, 500, PVAA_plotx, NoMon);
 *
 *----------------------------------------------------------------
 */






/*----------------------------------------------------------------
 * macros for last arg of PV* ("_OTHER_")
 *----------------------------------------------------------------
 */

/*
 * no monitor
 */


/*
 * monitor
 */


/* 
 * monitor & event flag; flag var will be named "<var>_EvFlag"
 */





/*================================================================*/
/*================================================================*/

/*----------------------------------------------------------------
 * PVPUT() -- variable assign and pvPut() in one
 *
 * Format:
 *
 *    PVPUT( varName, expr )
 *
 * Where:
 *
 *    varName   is the variable name, e.g. foo
 *    expr      is any C expression
 *
 * Examples:
 *
 *    PVPUT (foo, 3);
 *      expands to:
 *        foo = 3;
 *        pvPut(foo);
 *
 *    PVPUT (bar, xyz + 2);
 *      expands to:
 *        bar = xyz + 2;
 *        pvPut(bar);
 *
 *----------------------------------------------------------------
 */







/*----------------------------------------------------------------
 * PVPUTSTR() -- string assign and pvPut() in one
 *
 * Format:
 *
 *    PVPUTSTR( strName, string expr )
 *
 * Where:
 *
 *    strName      is the variable name, e.g. foo
 *    string expr  is any C expression that points to a string
 *
 * Example:
 *
 *    PVPUTSTR (foo, "error message");
 *      expands to:
 *        strcpy(foo,"error message");
 *        pvPut(foo);
 *
 *----------------------------------------------------------------
 */







/*================================================================*/
/*================================================================*/

/*----------------------------------------------------------------
 * DEBUG_PRINT() -- print a debug string for a particular debug level
 *
 * Format:
 *
 *    DEBUG_PRINT( debug_level, string format, v1, v2, v3, v4 )
 *
 * Where:
 *
 *    debug_level      is the debugging level, ie 3
 *    string format    is an sprintf format specifier
 *    v1, v2, v3, v4   are optional arguments for the sprintf format
 *
 * Example:
 *
 *    DEBUG_PRINT (1, "ERROR, how did I get here?", 0, 0, 0, 0 );
 *
 *----------------------------------------------------------------
 */



#line 228 "C:\\epics\\motor\\motorApp\\NewportSrc\\seqPVmacros.h"











#line 240 "C:\\epics\\motor\\motorApp\\NewportSrc\\seqPVmacros.h"

/*================================================================*/
/*================================================================*/
/*================================================================*/

/* end */
#line 11 "xpsSlave.st"
%%#define epicsExportSharedSymbols
%%#include <shareLib.h>
%%#include "XPS_C8_drivers.h"




char* SNLtaskName;
char* ip;
char* master;
char* slave;
%%int xps_socket;
int val;
char* masterRdbk;
double ratioRdbk;

/* PV definitions */

int debug_flag; assign debug_flag to "{P}{R}:debug.VAL" ; monitor debug_flag;
/* the ok PV is an indicator that slave mode has been configured. it should only be false after a power-cycle before initializing */
int ok_pv; assign ok_pv to "{P}{R}:ok.VAL" ;
int on_pv; assign on_pv to "{P}{R}:on.VAL" ; monitor on_pv; evflag on_pv_mon; sync on_pv on_pv_mon;
int init_pv; assign init_pv to "{P}{R}:init.VAL" ; monitor init_pv; evflag init_pv_mon; sync init_pv init_pv_mon;
double ratio_pv; assign ratio_pv to "{P}{R}:ratio.VAL" ; monitor ratio_pv;
double ratioRdbk_pv; assign ratioRdbk_pv to "{P}{R}:ratioRdbk.VAL" ;

ss slave_main
{
  state init
  {
    when ()
    {
      /* get macros */
      ip = macValueGet("IP");
      master = macValueGet("M");
      slave = macValueGet("S");
      SNLtaskName = macValueGet("name");
      
      /* Connect to the XPS controller (save the xps_socket ID) */
      %%xps_socket = TCP_ConnectToServer(pVar->ip, 5001, 100.0);
      
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 52, SNLtaskName, 2); printf("init -> update",0,0,0,0); printf("\n"); };
      
      efClear(init_pv_mon);
      efClear(on_pv_mon);
    
    } state update
  }

  state update
  {
    when ()
    {
      /* Check if slave mode is on and set the on_pv appropriately */
      %%pVar->val = SingleAxisSlaveParametersGet(xps_socket, pVar->slave, pVar->masterRdbk, &pVar->ratioRdbk);
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 66, SNLtaskName, 2); printf("update(): val = %i, masterRdbk = %s, ratioRdbk = %f",val,masterRdbk,ratioRdbk,0); printf("\n"); };
      
      /* Set the ok indictor to 1 if slave parameters exist */
      if (val == 0)
      {
        { ok_pv = ( 1 ); pvPut(ok_pv); };
      }
      else
      {
        { ok_pv = ( 0 ); pvPut(ok_pv); };
      }
      
      /* what is the initial value if the first poll fails? */
      /* display the ratio */
      { ratioRdbk_pv = ( ratioRdbk ); pvPut(ratioRdbk_pv); };
    
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 82, SNLtaskName, 2); printf("update -> idle",0,0,0,0); printf("\n"); };
    
    } state idle
  
  }
  
  state modeChange
  {
    when ()
    {
      if (on_pv == 1)
      {
        %%pVar->val = SingleAxisSlaveModeEnable(xps_socket, pVar->slave);
        if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 95, SNLtaskName, 2); printf("on_pv == 1",0,0,0,0); printf("\n"); };
      }
      else
      {
        %%pVar->val = SingleAxisSlaveModeDisable(xps_socket, pVar->slave);
        if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 100, SNLtaskName, 2); printf("on_pv != 1",0,0,0,0); printf("\n"); };
      }
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 102, SNLtaskName, 2); printf("modeChange -> idle",0,0,0,0); printf("\n"); };
   } state idle
    
  }
  
  /* Should reinit wait until a move is done before changing the gear ratio? */
  state reinit
  {
    when ()
    {
      %%pVar->val = SingleAxisSlaveParametersSet(xps_socket, pVar->slave, pVar->master, pVar->ratio_pv);
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 113, SNLtaskName, 2); printf("reinit(): val = %i",val,0,0,0); printf("\n"); };

      /* reset the init PV */
      { init_pv = ( 0 ); pvPut(init_pv); };
      efClear(init_pv_mon);
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 118, SNLtaskName, 2); printf("reinit -> update",0,0,0,0); printf("\n"); };
    
    } state update
  }
  
  state idle
  {
    when ( efTestAndClear(on_pv_mon) && ok_pv == 1 )
    {
      /* A mode toggle has been requested */
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 128, SNLtaskName, 2); printf("idle -> modeChange",0,0,0,0); printf("\n"); };
    } state modeChange
    
    when ( efTest(init_pv_mon) )
    {
      /* A reinit has been requested */
      if (debug_flag >= 2) { printf("<%s,%d,%s,%d> ", "xpsSlave.st", 134, SNLtaskName, 2); printf("idle -> reinit",0,0,0,0); printf("\n"); };
    } state reinit
  
  }
}
