#include <asynParamType.h>

struct ParameterDefn
{
	const char* ParamName;
	asynParamType ParamType;
	int DefaultValue;
};

static const char* STARTSTOP = "STARTSTOP"; 
static const char* RESET = "RESET";
static const char* FAULT = "FAULT";
static const char* WARNINGTEMPERATURE = "WARNINGTEMPERATURE";
static const char* WARNINGHIGHLOAD = "WARNINGHIGHLOAD";
static const char* STATORFREQUENCY = "STATORFREQUENCY";
static const char* CONVERTERTEMPERATURE = "CONVERTERTEMPERATURE";
static const char* MOTORCURRENT = "MOTORCURRENT";
static const char* PUMPTEMPERATURE = "PUMPTEMPERATURE";
static const char* CIRCUITVOLTAGE = "CIRCUITVOLTAGE";

ParameterDefn ParameterDefns[] =
{
	{STARTSTOP, asynParamInt32, 1},
	{RESET, asynParamInt32, 0},
	{FAULT, asynParamInt32, 0},
	{WARNINGTEMPERATURE, asynParamInt32, 0},
	{WARNINGHIGHLOAD, asynParamInt32, 0},
	{STATORFREQUENCY, asynParamInt32, 0},
	{CONVERTERTEMPERATURE, asynParamInt32, 0},
	{MOTORCURRENT, asynParamFloat64, 0},
	{PUMPTEMPERATURE, asynParamInt32, 0},
	{CIRCUITVOLTAGE, asynParamFloat64, 0}
};

static const int NUM_PARAMS = sizeof(ParameterDefns) / sizeof(ParameterDefn);
