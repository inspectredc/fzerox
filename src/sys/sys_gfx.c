#include "global.h"
#include "audio.h"
#include "fzx_game.h"
#include "fzx_thread.h"

GfxPool* gGfxPool;
OSTask* sGfxTask;
Gfx* gMasterDisp;
s32 D_800DCCFC;
s32 D_800DCD00;
s32 D_800DCD04;
s32 D_800DCD08;
s32 D_800DCD0C;
OSMesg D_800DCD10;
uintptr_t gMainVramStart;
uintptr_t gMainVramEnd;
uintptr_t gOvl2VramStart;
uintptr_t gOvl2VramEnd;
uintptr_t gOvl3VramStart;
uintptr_t gOvl3VramEnd;
uintptr_t gOvl4VramStart;
uintptr_t gOvl4VramEnd;
uintptr_t gOvlCourseSelectVramStart;
uintptr_t gOvlCourseSelectVramEnd;
uintptr_t gOvl6VramStart;
uintptr_t gOvl6VramEnd;
uintptr_t gOvl7VramStart;
uintptr_t gOvl7VramEnd;
uintptr_t gOvl8VramStart;
uintptr_t gOvl8VramEnd;
uintptr_t gOvl9VramStart;
uintptr_t gOvl9VramEnd;
uintptr_t gOvl10VramStart;
uintptr_t gOvl10VramEnd;
uintptr_t gLeoVramStart;
uintptr_t gLeoVramEnd;
UNUSED uintptr_t D_800DCD6C;
UNUSED uintptr_t D_800DCD70;
uintptr_t gFramebuffer1VramStart;
uintptr_t gFramebuffer1VramEnd;
uintptr_t gFramebuffer2VramStart;
uintptr_t gFramebuffer2VramEnd;
uintptr_t gFramebuffer3VramStart;
uintptr_t gFramebuffer3VramEnd;
uintptr_t gFramebufferUnusedVramStart;
uintptr_t gFramebufferUnusedVramEnd;
uintptr_t gGfxPoolVramStart;
uintptr_t gGfxPoolVramEnd;
uintptr_t gUnkBssVramStart;
uintptr_t gUnkBssVramEnd;
uintptr_t gSegment16C8A0VramStart;
uintptr_t gSegment16C8A0VramEnd;
uintptr_t gSegment17B1E0VramStart;
uintptr_t gSegment17B1E0VramEnd;
uintptr_t gSegment17B960VramStart;
uintptr_t gSegment17B960VramEnd;
UNUSED uintptr_t D_800DCDBC;
UNUSED uintptr_t D_800DCDC0;
uintptr_t gSegment1B8550VramStart;
uintptr_t gSegment1B8550VramEnd;
uintptr_t gSegment1E23F0VramStart;
uintptr_t gSegment1E23F0VramEnd;
uintptr_t gSegment22B0A0VramStart;
uintptr_t gSegment22B0A0VramEnd;
uintptr_t gSegment235130VramStart;
uintptr_t gSegment235130VramEnd;
uintptr_t gSegment2738A0VramStart;
uintptr_t gSegment2738A0VramEnd;
uintptr_t gCourseEditTexturesVramStart;
uintptr_t gCourseEditTexturesVramEnd;
uintptr_t gCreateMachineTexturesVramStart;
uintptr_t gCreateMachineTexturesVramEnd;
uintptr_t D_800DCDFC;
uintptr_t D_800DCE00;
uintptr_t gBuffersVramStart;
uintptr_t gBuffersVramEnd;
uintptr_t gUnkGfxVramStart;
uintptr_t gUnkGfxVramEnd;
uintptr_t gUnkContextVramStart;
uintptr_t gUnkContextVramEnd;
uintptr_t gAudioContextVramStart;
uintptr_t gAudioContextVramEnd;

void func_80067AE0(void) {
    s32 temp_t7;

    temp_t7 = D_800DCD08;
    D_800DCD08 = D_800DCD04;
    D_800DCD04 = D_800DCD0C;
    D_800DCD0C = temp_t7;
}

extern GfxPool D_8024DCE0[2];
extern OSTask D_802A6AC0[];

void Gfx_InitBuffer(void) {

    D_800DCD00 ^= 1;
    D_800DCCFC ^= 1;
    sGfxTask = &D_802A6AC0[D_800DCCFC];
    gGfxPool = &D_8024DCE0[D_800DCCFC];
    Segment_SetPhysicalAddress(1, gGfxPool);
    gMasterDisp = gGfxPool->gfxBuffer;
}

void Gfx_LoadSegments(void) {
    gMasterDisp = Segment_SetTableAddresses(gMasterDisp);
}

void Gfx_FullSync(void) {
    gDPFullSync(gMasterDisp++);
    gSPEndDisplayList(gMasterDisp++);
}

extern OSMesgQueue gMainThreadMesgQueue;
extern s32 gGameMode;
extern OSTask* gCurGfxTask;

void Gfx_SetTask(OSTask* task) {

    task->t.type = M_GFXTASK;
    task->t.flags = OS_TASK_LOADABLE;
    task->t.ucode_boot = (u64*) rspbootTextStart;
    task->t.ucode_boot_size = (uintptr_t) rspbootTextEnd - (uintptr_t) rspbootTextStart;

    switch (gGameMode & GAMEMODE_F3D_MASK) {
        case GFXMODE_F3DEX:
            task->t.ucode = (u64*) gspF3DEX2_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DEX2_fifoDataStart;
            break;
        case GFXMODE_F3DLX:
            task->t.ucode = (u64*) gspF3DLX2_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DLX2_Rej_fifoDataStart;
            break;
        case GFXMODE_F3DFLX:
            task->t.ucode = (u64*) gspF3DFLX2_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DFLX2_Rej_fifoDataStart;
            break;
    }

    task->t.ucode_size = SP_UCODE_SIZE;
    task->t.ucode_data_size = SP_UCODE_DATA_SIZE;
    task->t.dram_stack = (u64*) gDramStack;
    task->t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    task->t.output_buff = (u64*) gTaskOutputBuffer;
    task->t.output_buff_size = (u64*) (gTaskOutputBuffer + ARRAY_COUNT(gTaskOutputBuffer));
    task->t.data_ptr = (u64*) gGfxPool->gfxBuffer;
    task->t.data_size = (size_t) (gMasterDisp - gGfxPool->gfxBuffer) * sizeof(Gfx);
    task->t.yield_data_ptr = (u64*) gOSYieldData;
    task->t.yield_data_size = OS_YIELD_DATA_SIZE;
    gCurGfxTask = task;
    osSendMesg(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_GFX_TASK_SET, OS_MESG_BLOCK);
}

extern OSMesgQueue D_800DCAB0;
extern OSMesgQueue D_800DCAC8;
extern FrameBuffer* gFrameBuffers[];

void func_80067D64(void) {
    MQ_WAIT_FOR_MESG(&D_800DCAB0, &D_800DCD10);
    Audio_Update();
    Gfx_InitBuffer();
    func_800690FC();
    Gfx_LoadSegments();
    gMasterDisp = func_80069698(gMasterDisp);
    Gfx_FullSync();
    MQ_WAIT_FOR_MESG(&D_800DCAC8, &D_800DCD10);

    while (osDpGetStatus() &
           (DPC_STATUS_DMA_BUSY | DPC_STATUS_CMD_BUSY | DPC_STATUS_PIPE_BUSY | DPC_STATUS_TMEM_BUSY)) {}

    Segment_LoadAssets();
    Transition_SetBackgroundBuffer();
    osViSwapBuffer(gFrameBuffers[D_800DCD00]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[D_800DCD00]) {}

    Gfx_SetTask(sGfxTask);
}

void func_80067E98(void) {
    s32 retries = 100000;

    MQ_WAIT_FOR_MESG(&D_800DCAB0, &D_800DCD10);
    Gfx_InitBuffer();
    func_800690FC();
    func_80067AE0();
    Gfx_LoadSegments();
    gMasterDisp = func_80069698(gMasterDisp);
    Gfx_FullSync();
    Audio_Update();
    MQ_WAIT_FOR_MESG(&D_800DCAC8, &D_800DCD10);
    Transition_SetBackgroundBuffer();
    osViSwapBuffer(gFrameBuffers[D_800DCD08]);
    Segment_LoadAssets();

    while ((osViGetCurrentFramebuffer() == gFrameBuffers[D_800DCD04] ||
            osViGetNextFramebuffer() == gFrameBuffers[D_800DCD04]) &&
           retries != 0) {
        retries--;
    }

    Gfx_SetTask(sGfxTask);
}

u32 gGameFrameCount = 0;
s16 D_800CCFE4 = 2;
s16 D_800CCFE8 = 2;

extern bool gRamDDCompatible;
extern s16 gSettingSoundMode;

extern unk_80225800 D_80225800;

void Game_ThreadEntry(void* entry) {
    s32 startTime;
    OSMesg msgBuf[1];

    startTime = osGetTime();
    Audio_GuitarSeqStart();
    osRecvMesg(&D_800DCAB0, msgBuf, OS_MESG_BLOCK);

    // Segment Start and End Pairs
    gMainVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(main));
    gMainVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(main));
    gOvl2VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i2));
    gOvl2VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i2));
    gOvl3VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i3));
    gOvl3VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i3));
    gOvl4VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i4));
    gOvl4VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i4));
    gOvlCourseSelectVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(course_select));
    gOvlCourseSelectVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(course_select));
    gOvl6VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i6));
    gOvl6VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i6));
    gOvl7VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ending));
    gOvl7VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ending));
    gOvl8VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(records));
    gOvl8VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(records));
    gOvl9VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i9));
    gOvl9VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i9));
    gOvl10VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i10));
    gOvl10VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i10));
    gFramebuffer1VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer1));
    gFramebuffer1VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer1));
    gFramebuffer2VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer2));
    gFramebuffer2VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer2));
    gFramebuffer3VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer3));
    gFramebuffer3VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer3));
    gFramebufferUnusedVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer_unused));
    gFramebufferUnusedVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer_unused));
    gBuffersVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(buffers));
    gBuffersVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(buffers));
    gUnkGfxVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_gfx_segment));
    gUnkGfxVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_gfx_segment));
    gUnkContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(game_context));
    gUnkContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(game_context));
    gAudioContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(audio_context));
    gAudioContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(audio_context) + 0x10);
    gGfxPoolVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(gfxpool));
    gGfxPoolVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(gfxpool));
    gUnkBssVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_bss_segment));
    gUnkBssVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_bss_segment));

    gSegment16C8A0VramStart = gBuffersVramEnd;
    gSegment16C8A0VramEnd = gSegment16C8A0VramStart + (size_t) SEGMENT_DATA_SIZE_CONST(course_track_gfx);

    gSegment17B1E0VramStart = gSegment16C8A0VramEnd;
    gSegment17B1E0VramEnd = gSegment17B1E0VramStart + (size_t) SEGMENT_VRAM_SIZE(setup_gfx);

    gSegment17B960VramStart = gSegment17B1E0VramEnd;
    gSegment17B960VramEnd = gSegment17B960VramStart + (size_t) SEGMENT_VRAM_SIZE(machine_custom_gfx);

    gSegment1B8550VramStart = gSegment17B960VramEnd;
    gSegment1B8550VramEnd = gSegment1B8550VramStart + (size_t) SEGMENT_VRAM_SIZE(hud_gfx);

    gSegment1E23F0VramStart = gOvl3VramEnd;
    gSegment1E23F0VramEnd = gSegment1E23F0VramStart + (size_t) SEGMENT_VRAM_SIZE(machine_global_gfx);

    gSegment22B0A0VramStart = gSegment17B960VramEnd;
    gSegment22B0A0VramEnd = gSegment22B0A0VramStart + (size_t) SEGMENT_DATA_SIZE_CONST(machine_models);

    D_800DCDFC = gSegment17B1E0VramEnd;
    D_800DCE00 = D_800DCDFC + 0x1F820;

    gCourseEditTexturesVramStart = D_800DCE00;
    gCourseEditTexturesVramEnd = gCourseEditTexturesVramStart + (size_t) SEGMENT_VRAM_SIZE(course_edit_textures_beta);

    gCreateMachineTexturesVramStart = D_800DCE00;
    gCreateMachineTexturesVramEnd =
        gCreateMachineTexturesVramStart + (size_t) SEGMENT_VRAM_SIZE(create_machine_textures);

    gLeoVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(leo));
    gLeoVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(leo));

    // Setup memory
    Segment_SetAddress(0, 0);
    Segment_SetAddress(2, gUnkBssVramStart);
    Segment_SetAddress(8, gSegment16C8A0VramStart);
    Segment_SetAddress(3, gSegment17B1E0VramStart);
    Arena_DefaultStartInit();
    Arena_EndInit();

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i2), SEGMENT_TEXT_SIZE(ovl_i2), SEGMENT_DATA_START(ovl_i2),
                        SEGMENT_DATA_END(ovl_i2) - SEGMENT_DATA_START(ovl_i2));
    Dma_LoadOverlay(SEGMENT_ROM_START(ovl_i2), SEGMENT_VRAM_START(ovl_i2), SEGMENT_ROM_SIZE(ovl_i2),
                    SEGMENT_BSS_START(ovl_i2), SEGMENT_BSS_SIZE(ovl_i2));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i10), SEGMENT_TEXT_SIZE(ovl_i10), SEGMENT_DATA_START(ovl_i10),
                        SEGMENT_DATA_SIZE(ovl_i10));
    Dma_LoadOverlay(SEGMENT_ROM_START(ovl_i10), SEGMENT_VRAM_START(ovl_i10), SEGMENT_ROM_SIZE(ovl_i10),
                    SEGMENT_BSS_START(ovl_i10), SEGMENT_BSS_SIZE(ovl_i10));

    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment16C8A0VramStart), SEGMENT_DATA_SIZE_CONST(course_track_gfx));
    Dma_LoadAssets(SEGMENT_ROM_START(course_track_gfx),
                   (uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                       (size_t) SEGMENT_DATA_SIZE_CONST(course_track_gfx),
                   SEGMENT_ROM_SIZE(course_track_gfx));

    mio0Decode((uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                   (size_t) SEGMENT_DATA_SIZE_CONST(course_track_gfx),
               osPhysicalToVirtual(gSegment16C8A0VramStart));
    Dma_LoadAssets(SEGMENT_ROM_START(setup_gfx), osPhysicalToVirtual(gSegment17B1E0VramStart),
                   SEGMENT_ROM_SIZE(setup_gfx));
    Dma_LoadAssets(SEGMENT_ROM_START(machine_custom_gfx), osPhysicalToVirtual(gSegment17B960VramStart),
                   SEGMENT_ROM_SIZE(machine_custom_gfx));

    // FrameBuffer Indexes
    D_800DCCFC = 0;
    D_800DCD00 = 1;
    D_800DCD08 = 2;
    D_800DCD04 = 0;
    D_800DCD0C = 1;

    // General Initialisation
    Math_SinTableInit();
    if (gRamDDCompatible) {
        func_800742D0();
    }
    func_800742FC();
    Matrix_SetTransRot(&D_80225800.unk_000, 0, 1.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f);

    Math_Rand1Init(osGetTime(), osGetTime() + osGetTime());
    Controller_Init();
    func_i10_80115DF0();
    if (gSettingSoundMode == 0) {
        Audio_SetOutMode(SOUNDMODE_SURROUND);
    } else {
        Audio_SetOutMode(SOUNDMODE_MONO);
    }

    while (true) {
        if (OS_CYCLES_TO_NSEC(osGetTime() - startTime) * 6e-8 > 230.0) {
            break;
        }
    }

    Math_Rand2Init(osGetTime() + osGetTime(), osGetTime());
    osSetTime(0);
    osViSwapBuffer(gFrameBuffers[0]);
    Gfx_InitBuffer();
    func_80067AE0();

    gMoveWd(gMasterDisp++, 6, 0, 0);
    gDPFullSync(gMasterDisp++);
    gSPEndDisplayList(gMasterDisp++);

    Gfx_SetTask(sGfxTask);
    Game_Init();
    gGameFrameCount = 0;

    while (true) {
        if (D_800CCFE4 != D_800CCFE8) {
            D_800CCFE4 = D_800CCFE8;
            D_800DCD04 = D_800DCCFC;
            D_800DCD08 = D_800DCD04 - 1;
            if (D_800DCD08 == -1) {
                D_800DCD08 = 2;
            }
            D_800DCD0C = D_800DCD04 + 1;
            if (D_800DCD0C == 3) {
                D_800DCD0C = 0;
            }
        }

        // Game main loops
        switch (D_800CCFE4) {
            case 2:
                func_80067D64();
                break;
            case 3:
                func_80067E98();
                break;
        }
        gGameFrameCount++;
    }
}
