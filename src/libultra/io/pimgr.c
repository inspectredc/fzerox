#include "macros.h"
#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PR/piint.h"
#include "PR/rdb.h"

// This appears to be a custom version of pimgr used for f-zero x

OSPiHandle D_800FA020;
OSPiHandle D_800FA098;

static OSThread piThread ALIGNED(8);
static char piThreadStack[OS_PIM_STACKSIZE] ALIGNED(16);

static OSMesgQueue piEventQueue ALIGNED(8);
static OSMesg piEventBuf[1];

OSDevMgr __osPiDevMgr = { 0 };
OSPiHandle* __osPiTable = NULL;

OSPiHandle* __osCurrentHandle[2] ALIGNED(8) = { &D_800FA020, &D_800FA098 };

void func_800C104C(void);

void osCreatePiManager(OSPri pri, OSMesgQueue* cmdQ, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osPiDevMgr.active) {
        return;
    }
    func_800C104C();
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
    osCreateThread(&piThread, 0, __osDevMgrMain, &__osPiDevMgr, &piThreadStack[OS_PIM_STACKSIZE], pri);
    osStartThread(&piThread);

    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

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
