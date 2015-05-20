/*************************************************************************\
* Copyright (c) 2009 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* Revision-Id: anj@aps.anl.gov-20101005192737-disfz3vs0f3fiixd */

/* String names for alarms */

#ifndef INC_alarmString_H
#define INC_alarmString_H


#define epicsExportSharedSymbols
#include <alarm.h>

/* Name strings */

/* ALARM SEVERITIES - must match menuAlarmSevr.dbd and alarm.h */

const char * epicsAlarmSeverityStrings[ALARM_NSEV] = {
    "NO_ALARM",
    "MINOR",
    "MAJOR",
    "INVALID"
};


/* ALARM STATUS - must match menuAlarmStat.dbd and alarm.h */

const char * epicsAlarmConditionStrings[ALARM_NSTATUS] = {
    "NO_ALARM",
    "READ",
    "WRITE",
    "HIHI",
    "HIGH",
    "LOLO",
    "LOW",
    "STATE",
    "COS",
    "COMM",
    "TIMEOUT",
    "HWLIMIT",
    "CALC",
    "SCAN",
    "LINK",
    "SOFT",
    "BAD_SUB",
    "UDF",
    "DISABLE",
    "SIMM",
    "READ_ACCESS",
    "WRITE_ACCESS"
};

#endif
