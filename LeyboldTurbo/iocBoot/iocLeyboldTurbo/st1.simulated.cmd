#!../../bin/_TARGETARCH_/LeyboldTurbo

## Register all support components
dbLoadDatabase ("../dbd/LeyboldTurbo.dbd")
LeyboldTurbo_registerRecordDeviceDriver pdbbase

epicsEnvSet ASYNPORT LEYBOLDTURBO
epicsEnvSet IOPORT PUMP

# Configure asyn communication port, first
LeyboldTurboPortDriverConfigure($(ASYNPORT), 1, $(NOOFPZD))
drvAsynIPPortConfigure($(IOPORT):1, $(IPPORT1), 0, 0)
LeyboldTurboAddIOPort($(IOPORT):1)

## Load record instances
dbLoadRecords("Db/$(DB=LeyboldTurbo).db", "P=$(ASYNPORT):1:,PORT=$(ASYNPORT),ADDR=0")
asynSetTraceIOMask($(ASYNPORT),0,0x2)

iocInit

## Start any sequence programs
#seq sncxxx,"user=pheestHost"
