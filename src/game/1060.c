#include "global.h"
#include "fzx_thread.h"
#include "audio.h"
#include "PR/viint.h"

char sBootThreadStack[0x200];
char sIdleThreadStack[0x200];
char sMainThreadStack[0x400];
char sGameThreadStack[0x1000];
char sAudioThreadStack[0x800];
char sResetThreadStack[0x1200];
UNUSED char sUnusedThreadStack[0xE00];
OSThread sIdleThread;
OSThread sMainThread;
OSThread sAudioThread;
OSThread sGameThread;
OSThread sResetThread;
UNUSED OSThread sUnusedThread;
OSMesgQueue sPiMgrCmdQueue;
OSMesgQueue gDmaMesgQueue;
OSMesgQueue gSerialEventQueue;
OSMesgQueue gAudioTaskMesgQueue;
OSMesgQueue D_800DCAB0;
OSMesgQueue D_800DCAC8;
OSMesgQueue gMainThreadMesgQueue;
OSMesgQueue gResetMesgQueue;
OSMesgQueue D_800DCB10;
OSMesg sPiMgrCmdBuf[64];
OSMesg sDmaMsgBuf[1];
OSMesg sSerialEventBuf[1];
OSMesg sAudioTaskMsgBuf[1];
OSMesg D_800DCC34[1];
OSMesg D_800DCC38[1];
OSMesg sMainThreadMsgBuf[16];
OSMesg sResetMsgBuf[1];
OSMesg D_800DCC84[1];
/*  */ UNUSED s8 D_800DCC88[0x20];
OSIoMesg D_800DCCA8;
OSTask* gCurGfxTask;
OSTask* gCurAudioOSTask;
bool gResetStarted;
bool gLeoDDConnected;
FrameBuffer* gFrameBuffers[3];
OSPiHandle* gCartRomHandle;
OSPiHandle* gDriveRomHandle;

void Idle_ThreadEntry(void*);
void Reset_ThreadEntry(void*);

void bootproc(void) {
    osInitialize();
    osCreateMesgQueue(&gResetMesgQueue, sResetMsgBuf, ARRAY_COUNT(sResetMsgBuf));
    osSetEventMesg(OS_EVENT_PRENMI, &gResetMesgQueue, (void*) 0x1B);
    osCreateThread(&sIdleThread, THREAD_ID_IDLE, Idle_ThreadEntry, NULL, sIdleThreadStack + sizeof(sIdleThreadStack),
                   100);
    osStartThread(&sIdleThread);
}

s32 sSpTaskState = SP_TASK_INACTIVE;
bool sSpTaskActive = false;

void Sched_SpTaskYield(void) {
    osSpTaskYield();
    sSpTaskState = SP_TASK_YIELDING;
    sSpTaskActive = true;
}

void Sched_SpTaskStartAudio(void) {
    osSpTaskStart(gCurAudioOSTask);
    sSpTaskState = SP_TASK_AUDIO;
    sSpTaskActive = true;
}

void Sched_SpTaskClearStartGfx(void) {
    osDpSetStatus(DPC_CLR_TMEM_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_CMD_CTR | DPC_CLR_CLOCK_CTR);
    osSpTaskStart(gCurGfxTask);
    sSpTaskState = SP_TASK_GFX;
    sSpTaskActive = true;
}

void Sched_SpTaskResumeGfx(void) {
    osSpTaskStart(gCurGfxTask);
    sSpTaskState = SP_TASK_GFX;
    sSpTaskActive = true;
}

bool sGfxTaskYielded = false;
bool sGfxTaskQueued = false;
s32 D_800CCFB0 = 1;
s32 D_800CCFB4 = 0;
s32 D_800CCFB8 = 1;
s32 D_800CCFBC = 1;
bool gRamDDCompatible = false;
bool sAudioThreadCreated = false;
s8 sMainThreadStartEnabled = true;
s8 sGameThreadStartEnabled = true;
s8 sAudioThreadStartEnabled = 1;
UNUSED s8 D_800CCFD4 = 1;

void func_80069F5C(FrameBuffer*);

void Main_ThreadEntry(void* arg0) {
    OSMesg msg;
    s32 var_a0;
    u64* var_v1;

    // Init message queues
    osCreateMesgQueue(&gDmaMesgQueue, sDmaMsgBuf, ARRAY_COUNT(sDmaMsgBuf));
    osCreateMesgQueue(&gAudioTaskMesgQueue, sAudioTaskMsgBuf, ARRAY_COUNT(sAudioTaskMsgBuf));
    osCreateMesgQueue(&D_800DCAB0, D_800DCC34, ARRAY_COUNT(D_800DCC34));
    osCreateMesgQueue(&D_800DCAC8, D_800DCC38, ARRAY_COUNT(D_800DCC38));
    osCreateMesgQueue(&gMainThreadMesgQueue, sMainThreadMsgBuf, ARRAY_COUNT(sMainThreadMsgBuf));
    osCreateMesgQueue(&gSerialEventQueue, sSerialEventBuf, ARRAY_COUNT(sSerialEventBuf));
    osCreateMesgQueue(&D_800DCB10, D_800DCC84, ARRAY_COUNT(D_800DCC84));
    osSetEventMesg(OS_EVENT_SI, &gSerialEventQueue, (OSMesg) EVENT_MESG_SI);
    osSetEventMesg(OS_EVENT_SP, &gMainThreadMesgQueue, (OSMesg) EVENT_MESG_SP);
    osSetEventMesg(OS_EVENT_DP, &gMainThreadMesgQueue, (OSMesg) EVENT_MESG_DP);
    osViSetEvent(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_VI, 1);
    gResetStarted = false;
    gLeoDDConnected = LeoDD_CheckPresence();
    var_v1 = (u64*) gFrameBuffers[0];

    // clang-format off
    for (var_a0 = 0; var_a0 < (SCREEN_WIDTH * SCREEN_HEIGHT) / 4; var_a0++) { \
        var_v1[var_a0] = 1;
    }
    // clang-format on

    func_80069F5C(gFrameBuffers[1]);
    func_80069F5C(gFrameBuffers[2]);
    osViSwapBuffer(gFrameBuffers[0]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[0]) {}

    osViBlack(false);

    if (osAppNMIBuffer[15] != 0x20DE1529) {
        // More than 8MB Ram available, n64dd compatible
        if (osGetMemSize() >= 0x800000) {
            gRamDDCompatible = true;
        } else {
            gRamDDCompatible = false;
        }
        osAppNMIBuffer[14] = gRamDDCompatible;
    } else {
        gRamDDCompatible = osAppNMIBuffer[14];
    }

    if (gRamDDCompatible) {
        Dma_ClearRomCopy(SEGMENT_ROM_START(leo), SEGMENT_VRAM_START(leo), SEGMENT_ROM_SIZE(leo));
        bzero(SEGMENT_BSS_START(leo), SEGMENT_BSS_SIZE(leo));
        if (gLeoDDConnected) {
            LeoDD_LoadFonts();
        }
#ifdef VERSION_JP
        func_800751FC("EFZJ");
#else
        func_800751FC("EFZE");
#endif
        if (gLeoDDConnected) {
            func_80076340();
        }
    }

    osCreateThread(&sResetThread, THREAD_ID_RESET, Reset_ThreadEntry, NULL,
                   sResetThreadStack + sizeof(sResetThreadStack), 100);
    osStartThread(&sResetThread);

    if (gRamDDCompatible && gLeoDDConnected) {
        func_800763A8();
    }
    if (gRamDDCompatible && gLeoDDConnected && (func_800761D4() == 2)) {
        func_8007515C();
    }
    osViSwapBuffer(gFrameBuffers[1]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[1]) {}

    func_80069F5C(gFrameBuffers[0]);
    osViSwapBuffer(gFrameBuffers[0]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[0]) {}

    osViBlack(false);

    if (gRamDDCompatible && gLeoDDConnected) {
        LeoDD_LoadFonts();
#ifdef VERSION_JP
        func_8007647C();
#endif
    }
    func_80075230(&sGameThread);

    osCreateThread(&sAudioThread, THREAD_ID_AUDIO, Audio_ThreadEntry, NULL,
                   sAudioThreadStack + sizeof(sAudioThreadStack), 20);
    if (sAudioThreadStartEnabled) {
        osStartThread(&sAudioThread);
    }
    sAudioThreadCreated = true;
    osCreateThread(&sGameThread, THREAD_ID_GAME, Game_ThreadEntry, NULL, sGameThreadStack + sizeof(sGameThreadStack),
                   10);
    if (sGameThreadStartEnabled) {
        osStartThread(&sGameThread);
    }

    while (true) {
        osRecvMesg(&gMainThreadMesgQueue, &msg, OS_MESG_BLOCK);
        if (msg == (OSMesg) EVENT_MESG_SP) {
            switch (sSpTaskState) {
                case SP_TASK_YIELDING:
                    if (osSpTaskYielded(gCurGfxTask)) {
                        sGfxTaskYielded = true;
                    }
                    Sched_SpTaskStartAudio();
                    break;
                case SP_TASK_AUDIO:
                    if (sGfxTaskYielded) {
                        sGfxTaskYielded = false;
                        Sched_SpTaskResumeGfx();
                    } else if (sGfxTaskQueued) {
                        sGfxTaskQueued = false;
                        Sched_SpTaskClearStartGfx();
                    } else {
                        sSpTaskState = SP_TASK_INACTIVE;
                        sSpTaskActive = false;
                    }
                    break;
                case SP_TASK_GFX:
                    sSpTaskState = SP_TASK_INACTIVE;
                    sSpTaskActive = false;
                    break;
            }
        } else if (msg == (OSMesg) EVENT_MESG_VI) {
            osSendMesg(&gAudioTaskMesgQueue, (OSMesg) EVENT_MESG_NEXT_AUDIO_TASK, OS_MESG_NOBLOCK);
            if ((++D_800CCFB0 - D_800CCFB4) >= D_800CCFB8) {
                D_800CCFB4 = D_800CCFB0;
                D_800CCFB8 = D_800CCFBC;
                osSendMesg(&D_800DCAB0, (OSMesg) 0x29, OS_MESG_NOBLOCK);
            }
        } else if (msg == (OSMesg) EVENT_MESG_AUDIO_TASK_SET) {
            osWritebackDCacheAll();
            if (sSpTaskActive) {
                if (sSpTaskState != SP_TASK_YIELDING) {
                    Sched_SpTaskYield();
                }
            } else {
                Sched_SpTaskStartAudio();
            }
        } else if ((msg == (OSMesg) EVENT_MESG_GFX_TASK_SET) && !gResetStarted) {
            osWritebackDCacheAll();
            if (sSpTaskActive) {
                sGfxTaskQueued = true;
            } else {
                Sched_SpTaskClearStartGfx();
            }
        } else if (msg == (OSMesg) EVENT_MESG_DP) {
            osSendMesg(&D_800DCAC8, (OSMesg) 0x2A, OS_MESG_NOBLOCK);
        }
    }
}

extern FrameBuffer gFrameBuffer1;
extern FrameBuffer gFrameBuffer2;
extern FrameBuffer gFrameBuffer3;

void Idle_ThreadEntry(void* arg0) {
    gFrameBuffers[0] = &gFrameBuffer1;
    gFrameBuffers[1] = &gFrameBuffer2;
    gFrameBuffers[2] = &gFrameBuffer3;
    osCreateViManager(OS_PRIORITY_VIMGR);
    if (osTvType == OS_TV_TYPE_NTSC) {
        osViSetMode(&osViModeNtscLan1);
    } else {
        osViSetMode(&osViModeMpalLan1);
    }
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osViSetSpecialFeatures(OS_VI_GAMMA_DITHER_OFF);
    osViSetSpecialFeatures(OS_VI_DIVOT_OFF);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
    osViBlack(true);
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPiMgrCmdQueue, sPiMgrCmdBuf, ARRAY_COUNT(sPiMgrCmdBuf));
    gCartRomHandle = osCartRomInit();
    gDriveRomHandle = osDriveRomInit();
    Fault_Init();
    Fault_SetFrameBuffer(&gFrameBuffer1, SCREEN_WIDTH, 16);
    osCreateThread(&sMainThread, THREAD_ID_MAIN, Main_ThreadEntry, NULL, sMainThreadStack + sizeof(sMainThreadStack),
                   99);
    if (sMainThreadStartEnabled) {
        osStartThread(&sMainThread);
    }
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (true) {}
}

void LeoReset(void);

void Reset_ThreadEntry(void* arg0) {
    OSMesg resetMsg;

    MQ_WAIT_FOR_MESG(&gResetMesgQueue, &resetMsg);
    if (!gResetStarted && sAudioThreadCreated) {
        Audio_PreNMI();
    }
    gResetStarted = true;
    osViBlack(true);
    osViSetYScale(1.0f);
    if (gRamDDCompatible && gLeoDDConnected) {
        LeoReset();
    }
    func_80069700();

    while (true) {}
}
