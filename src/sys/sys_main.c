#include "global.h"
#include "audio.h"
#include "fzx_thread.h"
#include "PR/viint.h"
#include "PR/leo.h"

char sBootThreadStack[0x200];
char sIdleThreadStack[0x200];
char sMainThreadStack[0x400];
char sGameThreadStack[0x1000];
char sAudioThreadStack[0x800];
#ifndef EXPANSION_KIT
char sResetThreadStack[0x1200];
#else
char sSys6ThreadStack[0x1000];
char sResetThreadStack[0x200];
#endif
UNUSED char sUnusedThreadStack[0xE00];
OSThread sIdleThread;
OSThread sMainThread;
OSThread sAudioThread;
OSThread sGameThread;
OSThread sResetThread;
OSThread sSys6Thread;
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
#ifdef EXPANSION_KIT
OSMesgQueue D_8079A2E8;
OSMesg D_8079A300[1];
#endif
OSIoMesg gDmaIOMsg;
OSTask* gCurGfxTask;
OSTask* gCurAudioOSTask;
bool gResetStarted;
s32 gLeoDriveConnectionState;
FrameBuffer* gFrameBuffers[3];
OSPiHandle* gCartRomHandle;
OSPiHandle* gDriveRomHandle;

#ifdef EXPANSION_KIT
#include ASSET_SOURCE_EK(boot_logo/boot_logo.c)
#endif

void Idle_ThreadEntry(void*);
void Reset_ThreadEntry(void*);

void bootproc(void) {
    osInitialize();
    osCreateMesgQueue(&gResetMesgQueue, sResetMsgBuf, ARRAY_COUNT(sResetMsgBuf));
    osSetEventMesg(OS_EVENT_PRENMI, &gResetMesgQueue, (void*) 0x1B);
#ifdef EXPANSION_KIT
    {
        u64* ptr;
        u32 i;
        ptr = (u64*) sIdleThreadStack;

        for (i = 0; i < sizeof(sIdleThreadStack) / sizeof(u64); i++) {
            ptr[i] = 0x8877665544332211;
        }

        ptr = (u64*) sMainThreadStack;

        for (i = 0; i < sizeof(sMainThreadStack) / sizeof(u64); i++) {
            ptr[i] = 0x8877665544332211;
        }

        ptr = (u64*) sGameThreadStack;

        for (i = 0; i < sizeof(sGameThreadStack) / sizeof(u64); i++) {
            ptr[i] = 0x8877665544332211;
        }

        ptr = (u64*) sSys6ThreadStack;

        for (i = 0; i < sizeof(sSys6ThreadStack) / sizeof(u64); i++) {
            ptr[i] = 0x8877665544332211;
        }

        ptr = (u64*) sAudioThreadStack;

        for (i = 0; i < sizeof(sAudioThreadStack) / sizeof(u64); i++) {
            ptr[i] = 0x8877665544332211;
        }
    }
#endif
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
s8 sAudioThreadStartEnabled = true;
UNUSED s8 D_800CCFD4 = 1;

void func_80069F5C(FrameBuffer*);

void Main_ThreadEntry(void* arg0) {
    OSMesg msg;
    s32 var_a0;
    u64* var_v1;
#ifdef EXPANSION_KIT
    s32 i;
#endif

    // Init message queues
    osCreateMesgQueue(&gDmaMesgQueue, sDmaMsgBuf, ARRAY_COUNT(sDmaMsgBuf));
    osCreateMesgQueue(&gAudioTaskMesgQueue, sAudioTaskMsgBuf, ARRAY_COUNT(sAudioTaskMsgBuf));
    osCreateMesgQueue(&D_800DCAB0, D_800DCC34, ARRAY_COUNT(D_800DCC34));
    osCreateMesgQueue(&D_800DCAC8, D_800DCC38, ARRAY_COUNT(D_800DCC38));
    osCreateMesgQueue(&gMainThreadMesgQueue, sMainThreadMsgBuf, ARRAY_COUNT(sMainThreadMsgBuf));
    osCreateMesgQueue(&gSerialEventQueue, sSerialEventBuf, ARRAY_COUNT(sSerialEventBuf));
    osCreateMesgQueue(&D_800DCB10, D_800DCC84, ARRAY_COUNT(D_800DCC84));
#ifdef EXPANSION_KIT
    osCreateMesgQueue(&D_8079A2E8, D_8079A300, ARRAY_COUNT(D_8079A300));
#endif
    osSetEventMesg(OS_EVENT_SI, &gSerialEventQueue, (OSMesg) EVENT_MESG_SI);
    osSetEventMesg(OS_EVENT_SP, &gMainThreadMesgQueue, (OSMesg) EVENT_MESG_SP);
    osSetEventMesg(OS_EVENT_DP, &gMainThreadMesgQueue, (OSMesg) EVENT_MESG_DP);
    osViSetEvent(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_VI, 1);
    gResetStarted = false;

#ifndef EXPANSION_KIT
    gLeoDriveConnectionState = LeoDD_CheckPresence();
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
        if (gLeoDriveConnectionState != 0) {
            LeoFault_LoadFonts();
        }
#ifdef VERSION_JP
        func_800751FC("EFZJ");
#else
        func_800751FC("EFZE");
#endif
        if (gLeoDriveConnectionState != 0) {
            SLLeoCreateManager();
        }
    }
#else
    DiskDrive_InitRomSegmentPairs();

    switch (osResetType) {
        case OS_TV_PAL:
        case OS_TV_NTSC:
            gRamDDCompatible = true;
            break;
        case OS_TV_MPAL:
            gRamDDCompatible = true;
            break;
    }

    if (gRamDDCompatible) {
        gLeoDriveConnectionState = LeoDriveExist();
        gDriveRomHandle = osDriveRomInit();
        if (gLeoDriveConnectionState != 0) {
            LeoFault_LoadFontSet();
        }
        func_80704DB0("01", leoBootID.gameName);

        for (i = 0; i < 3; i++) {
            var_v1 = &gFrameBuffers[i]->buffer[19199];

            while (var_v1 >= gFrameBuffers[i]->buffer) {
                *var_v1-- = 0x0001000100010001;
            }
        }

        osViSwapBuffer(gFrameBuffers[0]);

        while (osViGetCurrentFramebuffer() != gFrameBuffers[0]) {}

        osViBlack(false);

        DiskMount_Init();
    }
#endif

    osCreateThread(&sResetThread, THREAD_ID_RESET, Reset_ThreadEntry, NULL,
                   sResetThreadStack + sizeof(sResetThreadStack), 100);
    osStartThread(&sResetThread);

#ifndef EXPANSION_KIT
    if (gRamDDCompatible && (gLeoDriveConnectionState != 0)) {
        SLLeoResetClear();
    }
    if (gRamDDCompatible && (gLeoDriveConnectionState != 0) && (func_800761D4() == 2)) {
        func_8007515C();
    }
#endif

    osViSwapBuffer(gFrameBuffers[1]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[1]) {}

#ifndef EXPANSION_KIT
    func_80069F5C(gFrameBuffers[0]);
#else
    func_806F33D0(gFrameBuffers[0]);
    func_806F33D0(gFrameBuffers[1]);
    func_806F33D0(gFrameBuffers[2]);
#endif
    osViSwapBuffer(gFrameBuffers[0]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[0]) {}

    osViBlack(false);

#ifndef EXPANSION_KIT
    if (gRamDDCompatible && (gLeoDriveConnectionState != 0)) {
        LeoFault_LoadFonts();
#ifdef VERSION_JP
        func_8007647C();
#endif
    }
#else
    if (gRamDDCompatible) {
        osCreateThread(&sSys6Thread, THREAD_ID_6, func_80767958, 0, sSys6ThreadStack + sizeof(sSys6ThreadStack), 30);
        if (gLeoDriveConnectionState == 1) {
            osStartThread(&sSys6Thread);
            gLeoDriveConnectionState = 2;
        }
    }
#endif

    func_80075230(&sGameThread);

#ifdef EXPANSION_KIT
    AudioLoad_SetDmaHandler(func_80768C08);
    AudioLoad_SetLeoHandler(func_80768AF0);
#endif

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
#ifdef EXPANSION_KIT
            osSendMesg(&D_8079A2E8, (OSMesg) 1, OS_MESG_NOBLOCK);
#endif
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
#ifndef EXPANSION_KIT
    gDriveRomHandle = osDriveRomInit();
#endif
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
    if (gRamDDCompatible && (gLeoDriveConnectionState != 0)) {
        LeoReset();
    }
    Controller_Reset();

    while (true) {}
}

#ifdef EXPANSION_KIT
void func_806F33D0(FrameBuffer* fb) {
    u64* var_s0 = &fb->array[SCREEN_HEIGHT - 1][SCREEN_WIDTH - 4];
    u64* var;
    s32 i;
    s32 j;

    // Very FAKE Throughout
    while (var_s0 >= fb->buffer) {
        *(--var_s0 + 1) = 0x1000100010001;
    }
    osWritebackDCache(fb, sizeof(FrameBuffer));

    var_s0 = &fb->array[100][92];

    for (i = 0; i < 39; i++) {
        for (j = 0; j < 34; j++) {
            var = &D_80769DF0[i * 136 + j * 4];
            var_s0[j] = *var;
        }
        var_s0 += 80;
    }
}
#endif
