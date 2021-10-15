/** @file dfanoutRecord.h
 * @brief Declarations for the @ref dfanoutRecord "dfanout" record type.
 *
 * This header was generated from dfanoutRecord.dbd
 */

#ifndef INC_dfanoutRecord_H
#define INC_dfanoutRecord_H

#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"

#ifndef dfanoutSELM_NUM_CHOICES
/** @brief Enumerated type from menu dfanoutSELM */
typedef enum {
    dfanoutSELM_All                 /**< @brief State string "All" */,
    dfanoutSELM_Specified           /**< @brief State string "Specified" */,
    dfanoutSELM_Mask                /**< @brief State string "Mask" */
} dfanoutSELM;
/** @brief Number of states defined for menu dfanoutSELM */
#define dfanoutSELM_NUM_CHOICES 3
#endif

/** @brief Declaration of dfanout record type. */
typedef struct dfanoutRecord {
    char                name[61];   /**< @brief Record Name */
    char                desc[41];   /**< @brief Descriptor */
    char                asg[29];    /**< @brief Access Security Group */
    epicsEnum16         scan;       /**< @brief Scan Mechanism */
    epicsEnum16         pini;       /**< @brief Process at iocInit */
    epicsInt16          phas;       /**< @brief Scan Phase */
    char                evnt[40];   /**< @brief Event Name */
    epicsInt16          tse;        /**< @brief Time Stamp Event */
    DBLINK              tsel;       /**< @brief Time Stamp Link */
    epicsEnum16         dtyp;       /**< @brief Device Type */
    epicsInt16          disv;       /**< @brief Disable Value */
    epicsInt16          disa;       /**< @brief Disable */
    DBLINK              sdis;       /**< @brief Scanning Disable */
    epicsMutexId        mlok;       /**< @brief Monitor lock */
    ELLLIST             mlis;       /**< @brief Monitor List */
    ELLLIST             bklnk;      /**< @brief Backwards link tracking */
    epicsUInt8          disp;       /**< @brief Disable putField */
    epicsUInt8          proc;       /**< @brief Force Processing */
    epicsEnum16         stat;       /**< @brief Alarm Status */
    epicsEnum16         sevr;       /**< @brief Alarm Severity */
    epicsEnum16         nsta;       /**< @brief New Alarm Status */
    epicsEnum16         nsev;       /**< @brief New Alarm Severity */
    epicsEnum16         acks;       /**< @brief Alarm Ack Severity */
    epicsEnum16         ackt;       /**< @brief Alarm Ack Transient */
    epicsEnum16         diss;       /**< @brief Disable Alarm Sevrty */
    epicsUInt8          lcnt;       /**< @brief Lock Count */
    epicsUInt8          pact;       /**< @brief Record active */
    epicsUInt8          putf;       /**< @brief dbPutField process */
    epicsUInt8          rpro;       /**< @brief Reprocess  */
    struct asgMember    *asp;       /**< @brief Access Security Pvt */
    struct processNotify *ppn;      /**< @brief pprocessNotify */
    struct processNotifyRecord *ppnr; /**< @brief pprocessNotifyRecord */
    struct scan_element *spvt;      /**< @brief Scan Private */
    struct typed_rset   *rset;      /**< @brief Address of RSET */
    struct dset         *dset;      /**< @brief DSET address */
    void                *dpvt;      /**< @brief Device Private */
    struct dbRecordType *rdes;      /**< @brief Address of dbRecordType */
    struct lockRecord   *lset;      /**< @brief Lock Set */
    epicsEnum16         prio;       /**< @brief Scheduling Priority */
    epicsUInt8          tpro;       /**< @brief Trace Processing */
    char                bkpt;       /**< @brief Break Point */
    epicsUInt8          udf;        /**< @brief Undefined */
    epicsEnum16         udfs;       /**< @brief Undefined Alarm Sevrty */
    epicsTimeStamp      time;       /**< @brief Time */
    DBLINK              flnk;       /**< @brief Forward Process Link */
    epicsFloat64        val;        /**< @brief Desired Output */
    epicsEnum16         selm;       /**< @brief Select Mechanism */
    epicsUInt16         seln;       /**< @brief Link Selection */
    DBLINK              sell;       /**< @brief Link Selection Loc */
    DBLINK              outa;       /**< @brief Output Spec A */
    DBLINK              outb;       /**< @brief Output Spec B */
    DBLINK              outc;       /**< @brief Output Spec C */
    DBLINK              outd;       /**< @brief Output Spec D */
    DBLINK              oute;       /**< @brief Output Spec E */
    DBLINK              outf;       /**< @brief Output Spec F */
    DBLINK              outg;       /**< @brief Output Spec G */
    DBLINK              outh;       /**< @brief Output Spec H */
    DBLINK              dol;        /**< @brief Desired Output Loc */
    epicsEnum16         omsl;       /**< @brief Output Mode Select */
    char                egu[16];    /**< @brief Engineering Units */
    epicsInt16          prec;       /**< @brief Display Precision */
    epicsFloat64        hopr;       /**< @brief High Operating Range */
    epicsFloat64        lopr;       /**< @brief Low Operating Range */
    epicsFloat64        hihi;       /**< @brief Hihi Alarm Limit */
    epicsFloat64        lolo;       /**< @brief Lolo Alarm Limit */
    epicsFloat64        high;       /**< @brief High Alarm Limit */
    epicsFloat64        low;        /**< @brief Low Alarm Limit */
    epicsEnum16         hhsv;       /**< @brief Hihi Severity */
    epicsEnum16         llsv;       /**< @brief Lolo Severity */
    epicsEnum16         hsv;        /**< @brief High Severity */
    epicsEnum16         lsv;        /**< @brief Low Severity */
    epicsFloat64        hyst;       /**< @brief Alarm Deadband */
    epicsFloat64        adel;       /**< @brief Archive Deadband */
    epicsFloat64        mdel;       /**< @brief Monitor Deadband */
    epicsFloat64        lalm;       /**< @brief Last Value Alarmed */
    epicsFloat64        alst;       /**< @brief Last Value Archived */
    epicsFloat64        mlst;       /**< @brief Last Val Monitored */
} dfanoutRecord;

typedef enum {
	dfanoutRecordNAME = 0,
	dfanoutRecordDESC = 1,
	dfanoutRecordASG = 2,
	dfanoutRecordSCAN = 3,
	dfanoutRecordPINI = 4,
	dfanoutRecordPHAS = 5,
	dfanoutRecordEVNT = 6,
	dfanoutRecordTSE = 7,
	dfanoutRecordTSEL = 8,
	dfanoutRecordDTYP = 9,
	dfanoutRecordDISV = 10,
	dfanoutRecordDISA = 11,
	dfanoutRecordSDIS = 12,
	dfanoutRecordMLOK = 13,
	dfanoutRecordMLIS = 14,
	dfanoutRecordBKLNK = 15,
	dfanoutRecordDISP = 16,
	dfanoutRecordPROC = 17,
	dfanoutRecordSTAT = 18,
	dfanoutRecordSEVR = 19,
	dfanoutRecordNSTA = 20,
	dfanoutRecordNSEV = 21,
	dfanoutRecordACKS = 22,
	dfanoutRecordACKT = 23,
	dfanoutRecordDISS = 24,
	dfanoutRecordLCNT = 25,
	dfanoutRecordPACT = 26,
	dfanoutRecordPUTF = 27,
	dfanoutRecordRPRO = 28,
	dfanoutRecordASP = 29,
	dfanoutRecordPPN = 30,
	dfanoutRecordPPNR = 31,
	dfanoutRecordSPVT = 32,
	dfanoutRecordRSET = 33,
	dfanoutRecordDSET = 34,
	dfanoutRecordDPVT = 35,
	dfanoutRecordRDES = 36,
	dfanoutRecordLSET = 37,
	dfanoutRecordPRIO = 38,
	dfanoutRecordTPRO = 39,
	dfanoutRecordBKPT = 40,
	dfanoutRecordUDF = 41,
	dfanoutRecordUDFS = 42,
	dfanoutRecordTIME = 43,
	dfanoutRecordFLNK = 44,
	dfanoutRecordVAL = 45,
	dfanoutRecordSELM = 46,
	dfanoutRecordSELN = 47,
	dfanoutRecordSELL = 48,
	dfanoutRecordOUTA = 49,
	dfanoutRecordOUTB = 50,
	dfanoutRecordOUTC = 51,
	dfanoutRecordOUTD = 52,
	dfanoutRecordOUTE = 53,
	dfanoutRecordOUTF = 54,
	dfanoutRecordOUTG = 55,
	dfanoutRecordOUTH = 56,
	dfanoutRecordDOL = 57,
	dfanoutRecordOMSL = 58,
	dfanoutRecordEGU = 59,
	dfanoutRecordPREC = 60,
	dfanoutRecordHOPR = 61,
	dfanoutRecordLOPR = 62,
	dfanoutRecordHIHI = 63,
	dfanoutRecordLOLO = 64,
	dfanoutRecordHIGH = 65,
	dfanoutRecordLOW = 66,
	dfanoutRecordHHSV = 67,
	dfanoutRecordLLSV = 68,
	dfanoutRecordHSV = 69,
	dfanoutRecordLSV = 70,
	dfanoutRecordHYST = 71,
	dfanoutRecordADEL = 72,
	dfanoutRecordMDEL = 73,
	dfanoutRecordLALM = 74,
	dfanoutRecordALST = 75,
	dfanoutRecordMLST = 76
} dfanoutFieldIndex;

#ifdef GEN_SIZE_OFFSET

#include <epicsExport.h>
#include <cantProceed.h>
#ifdef __cplusplus
extern "C" {
#endif
static int dfanoutRecordSizeOffset(dbRecordType *prt)
{
    dfanoutRecord *prec = 0;

    if (prt->no_fields != 77) {
        cantProceed("IOC build or installation error:\n"
            "    The dfanoutRecord defined in the DBD file has %d fields,\n"
            "    but the record support code was built with 77.\n",
            prt->no_fields);
    }
    prt->papFldDes[dfanoutRecordNAME]->size = sizeof(prec->name);
    prt->papFldDes[dfanoutRecordNAME]->offset = (unsigned short)((char *)&prec->name - (char *)prec);
    prt->papFldDes[dfanoutRecordDESC]->size = sizeof(prec->desc);
    prt->papFldDes[dfanoutRecordDESC]->offset = (unsigned short)((char *)&prec->desc - (char *)prec);
    prt->papFldDes[dfanoutRecordASG]->size = sizeof(prec->asg);
    prt->papFldDes[dfanoutRecordASG]->offset = (unsigned short)((char *)&prec->asg - (char *)prec);
    prt->papFldDes[dfanoutRecordSCAN]->size = sizeof(prec->scan);
    prt->papFldDes[dfanoutRecordSCAN]->offset = (unsigned short)((char *)&prec->scan - (char *)prec);
    prt->papFldDes[dfanoutRecordPINI]->size = sizeof(prec->pini);
    prt->papFldDes[dfanoutRecordPINI]->offset = (unsigned short)((char *)&prec->pini - (char *)prec);
    prt->papFldDes[dfanoutRecordPHAS]->size = sizeof(prec->phas);
    prt->papFldDes[dfanoutRecordPHAS]->offset = (unsigned short)((char *)&prec->phas - (char *)prec);
    prt->papFldDes[dfanoutRecordEVNT]->size = sizeof(prec->evnt);
    prt->papFldDes[dfanoutRecordEVNT]->offset = (unsigned short)((char *)&prec->evnt - (char *)prec);
    prt->papFldDes[dfanoutRecordTSE]->size = sizeof(prec->tse);
    prt->papFldDes[dfanoutRecordTSE]->offset = (unsigned short)((char *)&prec->tse - (char *)prec);
    prt->papFldDes[dfanoutRecordTSEL]->size = sizeof(prec->tsel);
    prt->papFldDes[dfanoutRecordTSEL]->offset = (unsigned short)((char *)&prec->tsel - (char *)prec);
    prt->papFldDes[dfanoutRecordDTYP]->size = sizeof(prec->dtyp);
    prt->papFldDes[dfanoutRecordDTYP]->offset = (unsigned short)((char *)&prec->dtyp - (char *)prec);
    prt->papFldDes[dfanoutRecordDISV]->size = sizeof(prec->disv);
    prt->papFldDes[dfanoutRecordDISV]->offset = (unsigned short)((char *)&prec->disv - (char *)prec);
    prt->papFldDes[dfanoutRecordDISA]->size = sizeof(prec->disa);
    prt->papFldDes[dfanoutRecordDISA]->offset = (unsigned short)((char *)&prec->disa - (char *)prec);
    prt->papFldDes[dfanoutRecordSDIS]->size = sizeof(prec->sdis);
    prt->papFldDes[dfanoutRecordSDIS]->offset = (unsigned short)((char *)&prec->sdis - (char *)prec);
    prt->papFldDes[dfanoutRecordMLOK]->size = sizeof(prec->mlok);
    prt->papFldDes[dfanoutRecordMLOK]->offset = (unsigned short)((char *)&prec->mlok - (char *)prec);
    prt->papFldDes[dfanoutRecordMLIS]->size = sizeof(prec->mlis);
    prt->papFldDes[dfanoutRecordMLIS]->offset = (unsigned short)((char *)&prec->mlis - (char *)prec);
    prt->papFldDes[dfanoutRecordBKLNK]->size = sizeof(prec->bklnk);
    prt->papFldDes[dfanoutRecordBKLNK]->offset = (unsigned short)((char *)&prec->bklnk - (char *)prec);
    prt->papFldDes[dfanoutRecordDISP]->size = sizeof(prec->disp);
    prt->papFldDes[dfanoutRecordDISP]->offset = (unsigned short)((char *)&prec->disp - (char *)prec);
    prt->papFldDes[dfanoutRecordPROC]->size = sizeof(prec->proc);
    prt->papFldDes[dfanoutRecordPROC]->offset = (unsigned short)((char *)&prec->proc - (char *)prec);
    prt->papFldDes[dfanoutRecordSTAT]->size = sizeof(prec->stat);
    prt->papFldDes[dfanoutRecordSTAT]->offset = (unsigned short)((char *)&prec->stat - (char *)prec);
    prt->papFldDes[dfanoutRecordSEVR]->size = sizeof(prec->sevr);
    prt->papFldDes[dfanoutRecordSEVR]->offset = (unsigned short)((char *)&prec->sevr - (char *)prec);
    prt->papFldDes[dfanoutRecordNSTA]->size = sizeof(prec->nsta);
    prt->papFldDes[dfanoutRecordNSTA]->offset = (unsigned short)((char *)&prec->nsta - (char *)prec);
    prt->papFldDes[dfanoutRecordNSEV]->size = sizeof(prec->nsev);
    prt->papFldDes[dfanoutRecordNSEV]->offset = (unsigned short)((char *)&prec->nsev - (char *)prec);
    prt->papFldDes[dfanoutRecordACKS]->size = sizeof(prec->acks);
    prt->papFldDes[dfanoutRecordACKS]->offset = (unsigned short)((char *)&prec->acks - (char *)prec);
    prt->papFldDes[dfanoutRecordACKT]->size = sizeof(prec->ackt);
    prt->papFldDes[dfanoutRecordACKT]->offset = (unsigned short)((char *)&prec->ackt - (char *)prec);
    prt->papFldDes[dfanoutRecordDISS]->size = sizeof(prec->diss);
    prt->papFldDes[dfanoutRecordDISS]->offset = (unsigned short)((char *)&prec->diss - (char *)prec);
    prt->papFldDes[dfanoutRecordLCNT]->size = sizeof(prec->lcnt);
    prt->papFldDes[dfanoutRecordLCNT]->offset = (unsigned short)((char *)&prec->lcnt - (char *)prec);
    prt->papFldDes[dfanoutRecordPACT]->size = sizeof(prec->pact);
    prt->papFldDes[dfanoutRecordPACT]->offset = (unsigned short)((char *)&prec->pact - (char *)prec);
    prt->papFldDes[dfanoutRecordPUTF]->size = sizeof(prec->putf);
    prt->papFldDes[dfanoutRecordPUTF]->offset = (unsigned short)((char *)&prec->putf - (char *)prec);
    prt->papFldDes[dfanoutRecordRPRO]->size = sizeof(prec->rpro);
    prt->papFldDes[dfanoutRecordRPRO]->offset = (unsigned short)((char *)&prec->rpro - (char *)prec);
    prt->papFldDes[dfanoutRecordASP]->size = sizeof(prec->asp);
    prt->papFldDes[dfanoutRecordASP]->offset = (unsigned short)((char *)&prec->asp - (char *)prec);
    prt->papFldDes[dfanoutRecordPPN]->size = sizeof(prec->ppn);
    prt->papFldDes[dfanoutRecordPPN]->offset = (unsigned short)((char *)&prec->ppn - (char *)prec);
    prt->papFldDes[dfanoutRecordPPNR]->size = sizeof(prec->ppnr);
    prt->papFldDes[dfanoutRecordPPNR]->offset = (unsigned short)((char *)&prec->ppnr - (char *)prec);
    prt->papFldDes[dfanoutRecordSPVT]->size = sizeof(prec->spvt);
    prt->papFldDes[dfanoutRecordSPVT]->offset = (unsigned short)((char *)&prec->spvt - (char *)prec);
    prt->papFldDes[dfanoutRecordRSET]->size = sizeof(prec->rset);
    prt->papFldDes[dfanoutRecordRSET]->offset = (unsigned short)((char *)&prec->rset - (char *)prec);
    prt->papFldDes[dfanoutRecordDSET]->size = sizeof(prec->dset);
    prt->papFldDes[dfanoutRecordDSET]->offset = (unsigned short)((char *)&prec->dset - (char *)prec);
    prt->papFldDes[dfanoutRecordDPVT]->size = sizeof(prec->dpvt);
    prt->papFldDes[dfanoutRecordDPVT]->offset = (unsigned short)((char *)&prec->dpvt - (char *)prec);
    prt->papFldDes[dfanoutRecordRDES]->size = sizeof(prec->rdes);
    prt->papFldDes[dfanoutRecordRDES]->offset = (unsigned short)((char *)&prec->rdes - (char *)prec);
    prt->papFldDes[dfanoutRecordLSET]->size = sizeof(prec->lset);
    prt->papFldDes[dfanoutRecordLSET]->offset = (unsigned short)((char *)&prec->lset - (char *)prec);
    prt->papFldDes[dfanoutRecordPRIO]->size = sizeof(prec->prio);
    prt->papFldDes[dfanoutRecordPRIO]->offset = (unsigned short)((char *)&prec->prio - (char *)prec);
    prt->papFldDes[dfanoutRecordTPRO]->size = sizeof(prec->tpro);
    prt->papFldDes[dfanoutRecordTPRO]->offset = (unsigned short)((char *)&prec->tpro - (char *)prec);
    prt->papFldDes[dfanoutRecordBKPT]->size = sizeof(prec->bkpt);
    prt->papFldDes[dfanoutRecordBKPT]->offset = (unsigned short)((char *)&prec->bkpt - (char *)prec);
    prt->papFldDes[dfanoutRecordUDF]->size = sizeof(prec->udf);
    prt->papFldDes[dfanoutRecordUDF]->offset = (unsigned short)((char *)&prec->udf - (char *)prec);
    prt->papFldDes[dfanoutRecordUDFS]->size = sizeof(prec->udfs);
    prt->papFldDes[dfanoutRecordUDFS]->offset = (unsigned short)((char *)&prec->udfs - (char *)prec);
    prt->papFldDes[dfanoutRecordTIME]->size = sizeof(prec->time);
    prt->papFldDes[dfanoutRecordTIME]->offset = (unsigned short)((char *)&prec->time - (char *)prec);
    prt->papFldDes[dfanoutRecordFLNK]->size = sizeof(prec->flnk);
    prt->papFldDes[dfanoutRecordFLNK]->offset = (unsigned short)((char *)&prec->flnk - (char *)prec);
    prt->papFldDes[dfanoutRecordVAL]->size = sizeof(prec->val);
    prt->papFldDes[dfanoutRecordVAL]->offset = (unsigned short)((char *)&prec->val - (char *)prec);
    prt->papFldDes[dfanoutRecordSELM]->size = sizeof(prec->selm);
    prt->papFldDes[dfanoutRecordSELM]->offset = (unsigned short)((char *)&prec->selm - (char *)prec);
    prt->papFldDes[dfanoutRecordSELN]->size = sizeof(prec->seln);
    prt->papFldDes[dfanoutRecordSELN]->offset = (unsigned short)((char *)&prec->seln - (char *)prec);
    prt->papFldDes[dfanoutRecordSELL]->size = sizeof(prec->sell);
    prt->papFldDes[dfanoutRecordSELL]->offset = (unsigned short)((char *)&prec->sell - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTA]->size = sizeof(prec->outa);
    prt->papFldDes[dfanoutRecordOUTA]->offset = (unsigned short)((char *)&prec->outa - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTB]->size = sizeof(prec->outb);
    prt->papFldDes[dfanoutRecordOUTB]->offset = (unsigned short)((char *)&prec->outb - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTC]->size = sizeof(prec->outc);
    prt->papFldDes[dfanoutRecordOUTC]->offset = (unsigned short)((char *)&prec->outc - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTD]->size = sizeof(prec->outd);
    prt->papFldDes[dfanoutRecordOUTD]->offset = (unsigned short)((char *)&prec->outd - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTE]->size = sizeof(prec->oute);
    prt->papFldDes[dfanoutRecordOUTE]->offset = (unsigned short)((char *)&prec->oute - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTF]->size = sizeof(prec->outf);
    prt->papFldDes[dfanoutRecordOUTF]->offset = (unsigned short)((char *)&prec->outf - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTG]->size = sizeof(prec->outg);
    prt->papFldDes[dfanoutRecordOUTG]->offset = (unsigned short)((char *)&prec->outg - (char *)prec);
    prt->papFldDes[dfanoutRecordOUTH]->size = sizeof(prec->outh);
    prt->papFldDes[dfanoutRecordOUTH]->offset = (unsigned short)((char *)&prec->outh - (char *)prec);
    prt->papFldDes[dfanoutRecordDOL]->size = sizeof(prec->dol);
    prt->papFldDes[dfanoutRecordDOL]->offset = (unsigned short)((char *)&prec->dol - (char *)prec);
    prt->papFldDes[dfanoutRecordOMSL]->size = sizeof(prec->omsl);
    prt->papFldDes[dfanoutRecordOMSL]->offset = (unsigned short)((char *)&prec->omsl - (char *)prec);
    prt->papFldDes[dfanoutRecordEGU]->size = sizeof(prec->egu);
    prt->papFldDes[dfanoutRecordEGU]->offset = (unsigned short)((char *)&prec->egu - (char *)prec);
    prt->papFldDes[dfanoutRecordPREC]->size = sizeof(prec->prec);
    prt->papFldDes[dfanoutRecordPREC]->offset = (unsigned short)((char *)&prec->prec - (char *)prec);
    prt->papFldDes[dfanoutRecordHOPR]->size = sizeof(prec->hopr);
    prt->papFldDes[dfanoutRecordHOPR]->offset = (unsigned short)((char *)&prec->hopr - (char *)prec);
    prt->papFldDes[dfanoutRecordLOPR]->size = sizeof(prec->lopr);
    prt->papFldDes[dfanoutRecordLOPR]->offset = (unsigned short)((char *)&prec->lopr - (char *)prec);
    prt->papFldDes[dfanoutRecordHIHI]->size = sizeof(prec->hihi);
    prt->papFldDes[dfanoutRecordHIHI]->offset = (unsigned short)((char *)&prec->hihi - (char *)prec);
    prt->papFldDes[dfanoutRecordLOLO]->size = sizeof(prec->lolo);
    prt->papFldDes[dfanoutRecordLOLO]->offset = (unsigned short)((char *)&prec->lolo - (char *)prec);
    prt->papFldDes[dfanoutRecordHIGH]->size = sizeof(prec->high);
    prt->papFldDes[dfanoutRecordHIGH]->offset = (unsigned short)((char *)&prec->high - (char *)prec);
    prt->papFldDes[dfanoutRecordLOW]->size = sizeof(prec->low);
    prt->papFldDes[dfanoutRecordLOW]->offset = (unsigned short)((char *)&prec->low - (char *)prec);
    prt->papFldDes[dfanoutRecordHHSV]->size = sizeof(prec->hhsv);
    prt->papFldDes[dfanoutRecordHHSV]->offset = (unsigned short)((char *)&prec->hhsv - (char *)prec);
    prt->papFldDes[dfanoutRecordLLSV]->size = sizeof(prec->llsv);
    prt->papFldDes[dfanoutRecordLLSV]->offset = (unsigned short)((char *)&prec->llsv - (char *)prec);
    prt->papFldDes[dfanoutRecordHSV]->size = sizeof(prec->hsv);
    prt->papFldDes[dfanoutRecordHSV]->offset = (unsigned short)((char *)&prec->hsv - (char *)prec);
    prt->papFldDes[dfanoutRecordLSV]->size = sizeof(prec->lsv);
    prt->papFldDes[dfanoutRecordLSV]->offset = (unsigned short)((char *)&prec->lsv - (char *)prec);
    prt->papFldDes[dfanoutRecordHYST]->size = sizeof(prec->hyst);
    prt->papFldDes[dfanoutRecordHYST]->offset = (unsigned short)((char *)&prec->hyst - (char *)prec);
    prt->papFldDes[dfanoutRecordADEL]->size = sizeof(prec->adel);
    prt->papFldDes[dfanoutRecordADEL]->offset = (unsigned short)((char *)&prec->adel - (char *)prec);
    prt->papFldDes[dfanoutRecordMDEL]->size = sizeof(prec->mdel);
    prt->papFldDes[dfanoutRecordMDEL]->offset = (unsigned short)((char *)&prec->mdel - (char *)prec);
    prt->papFldDes[dfanoutRecordLALM]->size = sizeof(prec->lalm);
    prt->papFldDes[dfanoutRecordLALM]->offset = (unsigned short)((char *)&prec->lalm - (char *)prec);
    prt->papFldDes[dfanoutRecordALST]->size = sizeof(prec->alst);
    prt->papFldDes[dfanoutRecordALST]->offset = (unsigned short)((char *)&prec->alst - (char *)prec);
    prt->papFldDes[dfanoutRecordMLST]->size = sizeof(prec->mlst);
    prt->papFldDes[dfanoutRecordMLST]->offset = (unsigned short)((char *)&prec->mlst - (char *)prec);
    prt->rec_size = sizeof(*prec);
    return 0;
}
epicsExportRegistrar(dfanoutRecordSizeOffset);

#ifdef __cplusplus
}
#endif
#endif /* GEN_SIZE_OFFSET */

#endif /* INC_dfanoutRecord_H */
