#include "macros.h"
#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PR/piint.h"
#include "PR/rdb.h"

#if IS_VERSION_I_PATCH
OSPiHandle D_800FA020 ALIGNED(0x8);
OSPiHandle D_800FA098 ALIGNED(0x8);
#endif

static OSThread piThread ALIGNED(0x8);
static STACK(piThreadStack, OS_PIM_STACKSIZE) ALIGNED(0x10);

#ifndef _FINALROM
static OSThread ramromThread ALIGNED(0x8);
static STACK(ramromThreadStack, 0x400) ALIGNED(0x10);
static OSMesgQueue getRamromQ ALIGNED(0x8);
static OSMesg getRamromBuf[1];
static OSMesgQueue freeRamromQ ALIGNED(0x8);
static OSMesg freeRamromBuf[1];
static void ramromMain(void*);
#endif

static OSMesgQueue piEventQueue ALIGNED(0x8);
static OSMesg piEventBuf[1];

OSDevMgr __osPiDevMgr = { 0 };
OSPiHandle* __osPiTable = NULL;
#if BUILD_VERSION >= VERSION_J
OSPiHandle __Dom1SpeedParam ALIGNED(0x8);
OSPiHandle __Dom2SpeedParam ALIGNED(0x8);
OSPiHandle* __osCurrentHandle[2] ALIGNED(0x8) = { &__Dom1SpeedParam, &__Dom2SpeedParam };
#elif IS_VERSION_I_PATCH
OSPiHandle* __osCurrentHandle[2] ALIGNED(0x8) = { &D_800FA020, &D_800FA098 };
void func_800C104C(void);
#else
extern OSPiHandle CartRomHandle;
extern OSPiHandle LeoDiskHandle;
OSPiHandle* __osCurrentHandle[2] ALIGNED(0x8) = { &CartRomHandle, &LeoDiskHandle };
#endif

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

#ifdef _DEBUG
    if ((pri < OS_PRIORITY_IDLE) || (pri > OS_PRIORITY_MAX)) {
        __osError(ERR_OSCREATEPIMANAGER, 1, pri);
        return;
    }
#endif

    if (__osPiDevMgr.active) {
        return;
    }
#if IS_VERSION_I_PATCH
    func_800C104C();
#endif
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&piEventQueue, (OSMesg*) piEventBuf, 1);

    if (!__osPiAccessQueueEnabled) {
        __osPiCreateAccessQueue();
    }

    osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg) 0x22222222);
    oldPri = -1;
    myPri = osGetThreadPri(NULL);

    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();
    __osPiDevMgr.active = 1;
    __osPiDevMgr.thread = &piThread;
    __osPiDevMgr.cmdQueue = cmdQ;
    __osPiDevMgr.evtQueue = &piEventQueue;
    __osPiDevMgr.acsQueue = &__osPiAccessQueue;
    __osPiDevMgr.dma = __osPiRawStartDma;
    __osPiDevMgr.edma = __osEPiRawStartDma;
    osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, STACK_START(piThreadStack), pri);
    osStartThread(&piThread);

#ifndef _FINALROM
    osCreateThread(&ramromThread, 0, ramromMain, NULL, STACK_START(ramromThreadStack), (OSPri) pri - 1);
    osStartThread(&ramromThread);
#endif
    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

#if IS_VERSION_I_PATCH
void func_800C104C(void) {
    D_800FA020.latency = IO_READ(PI_BSD_DOM1_LAT_REG);
    D_800FA020.pulse = IO_READ(PI_BSD_DOM1_PWD_REG);
    D_800FA020.pageSize = IO_READ(PI_BSD_DOM1_PGS_REG);
    D_800FA020.relDuration = IO_READ(PI_BSD_DOM1_RLS_REG);
    D_800FA020.domain = 0;

    D_800FA098.latency = IO_READ(PI_BSD_DOM2_LAT_REG);
    D_800FA098.pulse = IO_READ(PI_BSD_DOM2_PWD_REG);
    D_800FA098.pageSize = IO_READ(PI_BSD_DOM2_PGS_REG);
    D_800FA098.relDuration = IO_READ(PI_BSD_DOM2_RLS_REG);
    D_800FA098.domain = 1;
}
#endif

#ifndef _FINALROM
static void ramromMain(void* arg) {
    u32 sent;
    u8 tmp[3];

    osCreateMesgQueue(&getRamromQ, getRamromBuf, 1);
    osCreateMesgQueue(&freeRamromQ, freeRamromBuf, 1);
    osSetEventMesg(OS_EVENT_RDB_REQ_RAMROM, &getRamromQ, NULL);
    osSetEventMesg(OS_EVENT_RDB_FREE_RAMROM, &freeRamromQ, NULL);

    while (TRUE) {
        osRecvMesg(&getRamromQ, NULL, OS_MESG_BLOCK);

        __osPiGetAccess();

        sent = 0;

        while (sent < 1) {
            sent += __osRdbSend(tmp, 1, RDB_TYPE_GtoH_RAMROM);
        }

        osRecvMesg(&freeRamromQ, NULL, OS_MESG_BLOCK);

        __osPiRelAccess();
    }
}
#endif
