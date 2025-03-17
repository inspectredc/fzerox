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
u32 gMainVramStart;
u32 gMainVramEnd;
u32 gOvl2VramStart;
u32 gOvl2VramEnd;
u32 gOvl3VramStart;
u32 gOvl3VramEnd;
u32 gOvl4VramStart;
u32 gOvl4VramEnd;
u32 gOvlCourseSelectVramStart;
u32 gOvlCourseSelectVramEnd;
u32 gOvl6VramStart;
u32 gOvl6VramEnd;
u32 gOvl7VramStart;
u32 gOvl7VramEnd;
u32 gOvl8VramStart;
u32 gOvl8VramEnd;
u32 gOvl9VramStart;
u32 gOvl9VramEnd;
u32 gOvl10VramStart;
u32 gOvl10VramEnd;
u32 gLeoVramStart;
u32 gLeoVramEnd;
UNUSED u32 D_800DCD6C;
UNUSED u32 D_800DCD70;
u32 gFramebuffer1VramStart;
u32 gFramebuffer1VramEnd;
u32 gFramebuffer2VramStart;
u32 gFramebuffer2VramEnd;
u32 gFramebuffer3VramStart;
u32 gFramebuffer3VramEnd;
u32 gFramebufferUnusedVramStart;
u32 gFramebufferUnusedVramEnd;
u32 gGfxPoolVramStart;
u32 gGfxPoolVramEnd;
u32 gUnkBssVramStart;
u32 gUnkBssVramEnd;
u32 gSegment16C8A0VramStart;
u32 gSegment16C8A0VramEnd;
u32 gSegment17B1E0VramStart;
u32 gSegment17B1E0VramEnd;
u32 gSegment17B960VramStart;
u32 gSegment17B960VramEnd;
UNUSED u32 D_800DCDBC;
UNUSED u32 D_800DCDC0;
u32 gSegment1B8550VramStart;
u32 gSegment1B8550VramEnd;
u32 gSegment1E23F0VramStart;
u32 gSegment1E23F0VramEnd;
u32 gSegment22B0A0VramStart;
u32 gSegment22B0A0VramEnd;
s32 gSegment235130VramStart;
s32 gSegment235130VramEnd;
s32 gSegment2738A0VramStart;
s32 gSegment2738A0VramEnd;
u32 gCourseEditTexturesVramStart;
u32 gCourseEditTexturesVramEnd;
u32 gCreateMachineTexturesVramStart;
u32 gCreateMachineTexturesVramEnd;
u32 D_800DCDFC;
u32 D_800DCE00;
u32 gBuffersVramStart;
u32 gBuffersVramEnd;
u32 gUnkGfxVramStart;
u32 gUnkGfxVramEnd;
u32 gUnkContextVramStart;
u32 gUnkContextVramEnd;
u32 gAudioContextVramStart;
u32 gAudioContextVramEnd;

void func_80067AE0(void) {
    s32 temp_t7;

    temp_t7 = D_800DCD08;
    D_800DCD08 = D_800DCD04;
    D_800DCD04 = D_800DCD0C;
    D_800DCD0C = temp_t7;
}

void Segment_SetPhysicalAddress(s32, void*);

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
            task->t.ucode = (u64*) gspF3DEX_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DEX_fifoDataStart;
            break;
        case GFXMODE_F3DLX:
            task->t.ucode = (u64*) gspF3DLX_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DLX_Rej_fifoDataStart;
            break;
        case GFXMODE_F3DFLX:
            task->t.ucode = (u64*) gspF3DFLX_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DFLX_Rej_fifoDataStart;
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
extern FrameBuffer* D_800DCCD0[];

void func_800690FC(void);
void func_i2_800FD344(void);

void func_80067D64(void) {
    MQ_WAIT_FOR_MESG(&D_800DCAB0, &D_800DCD10);
    func_800B9E28();
    Gfx_InitBuffer();
    func_800690FC();
    Gfx_LoadSegments();
    gMasterDisp = func_80069698(gMasterDisp);
    Gfx_FullSync();
    MQ_WAIT_FOR_MESG(&D_800DCAC8, &D_800DCD10);

    while (osDpGetStatus() &
           (DPC_STATUS_DMA_BUSY | DPC_STATUS_CMD_BUSY | DPC_STATUS_PIPE_BUSY | DPC_STATUS_TMEM_BUSY)) {}

    func_80077C9C();
    func_i2_800FD344();
    osViSwapBuffer(D_800DCCD0[D_800DCD00]);

    while (osViGetCurrentFramebuffer() != D_800DCCD0[D_800DCD00]) {}

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
    func_800B9E28();
    MQ_WAIT_FOR_MESG(&D_800DCAC8, &D_800DCD10);
    func_i2_800FD344();
    osViSwapBuffer(D_800DCCD0[D_800DCD08]);
    func_80077C9C();

    while (
        (osViGetCurrentFramebuffer() == D_800DCCD0[D_800DCD04] || osViGetNextFramebuffer() == D_800DCCD0[D_800DCD04]) &&
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
    func_800BB46C();
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
    gOvl7VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i7));
    gOvl7VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i7));
    gOvl8VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i8));
    gOvl8VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i8));
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
    gUnkContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_context));
    gUnkContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_context));
    gAudioContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(audio_context));
    gAudioContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(audio_context) + 0x10);
    gGfxPoolVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(gfxpool));
    gGfxPoolVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(gfxpool));
    gUnkBssVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_bss_segment));
    gUnkBssVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_bss_segment));

    gSegment16C8A0VramStart = gBuffersVramEnd;
    gSegment16C8A0VramEnd = gSegment16C8A0VramStart + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0);

    gSegment17B1E0VramStart = gSegment16C8A0VramEnd;
    gSegment17B1E0VramEnd = gSegment17B1E0VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_17B1E0);

    gSegment17B960VramStart = gSegment17B1E0VramEnd;
    gSegment17B960VramEnd = gSegment17B960VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_17B960);

    gSegment1B8550VramStart = gSegment17B960VramEnd;
    gSegment1B8550VramEnd = gSegment1B8550VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_1B8550);

    gSegment1E23F0VramStart = gOvl3VramEnd;
    gSegment1E23F0VramEnd = gSegment1E23F0VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_1E23F0);

    gSegment22B0A0VramStart = gSegment17B960VramEnd;
    gSegment22B0A0VramEnd = gSegment22B0A0VramStart + (size_t) SEGMENT_DATA_SIZE_CONST(segment_22B0A0);

    D_800DCDFC = gSegment17B1E0VramEnd;
    D_800DCE00 = D_800DCDFC + 0x1F820;

    gCourseEditTexturesVramStart = D_800DCE00;
    gCourseEditTexturesVramEnd = gCourseEditTexturesVramStart + (size_t) SEGMENT_VRAM_SIZE(course_edit_textures);

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
    func_80076804();
    func_80076848();

    // clang-format off
    osInvalICache(SEGMENT_TEXT_START(ovl_i2), SEGMENT_TEXT_SIZE(ovl_i2)); \
    osInvalDCache(SEGMENT_DATA_START(ovl_i2), SEGMENT_DATA_END(ovl_i2) - SEGMENT_DATA_START(ovl_i2));
    // clang-format on
    Dma_LoadOverlay(SEGMENT_ROM_START(ovl_i2), SEGMENT_VRAM_START(ovl_i2), SEGMENT_ROM_SIZE(ovl_i2),
                    SEGMENT_BSS_START(ovl_i2), SEGMENT_BSS_SIZE(ovl_i2));

    // clang-format off
    osInvalICache(SEGMENT_TEXT_START(ovl_i10), SEGMENT_TEXT_SIZE(ovl_i10)); \
    osInvalDCache(SEGMENT_DATA_START(ovl_i10), SEGMENT_DATA_SIZE(ovl_i10));
    // clang-format on
    Dma_LoadOverlay(SEGMENT_ROM_START(ovl_i10), SEGMENT_VRAM_START(ovl_i10), SEGMENT_ROM_SIZE(ovl_i10),
                    SEGMENT_BSS_START(ovl_i10), SEGMENT_BSS_SIZE(ovl_i10));

    osInvalDCache(osPhysicalToVirtual(gSegment16C8A0VramStart), SEGMENT_DATA_SIZE_CONST(segment_16C8A0));
    Dma_LoadAssets(SEGMENT_ROM_START(segment_16C8A0),
                   (uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                       (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
                   SEGMENT_ROM_SIZE(segment_16C8A0));

    mio0Decode((uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                   (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
               osPhysicalToVirtual(gSegment16C8A0VramStart));
    Dma_LoadAssets(SEGMENT_ROM_START(segment_17B1E0), osPhysicalToVirtual(gSegment17B1E0VramStart),
                   SEGMENT_ROM_SIZE(segment_17B1E0));
    Dma_LoadAssets(SEGMENT_ROM_START(segment_17B960), osPhysicalToVirtual(gSegment17B960VramStart),
                   SEGMENT_ROM_SIZE(segment_17B960));

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
    func_8006C378(&D_80225800.unk_000, 0, 1.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f);

    Math_Rand1Init(osGetTime(), osGetTime() + osGetTime());
    Controller_Init();
    func_i10_80115DF0();
    if (gSettingSoundMode == 0) {
        Audio_SetSoundMode(SOUNDMODE_SURROUND);
    } else {
        Audio_SetSoundMode(SOUNDMODE_MONO);
    }

    while (true) {
        if (OS_CYCLES_TO_NSEC(osGetTime() - startTime) * 6e-8 > 230.0) {
            break;
        }
    }

    Math_Rand2Init(osGetTime() + osGetTime(), osGetTime());
    osSetTime(0);
    osViSwapBuffer(D_800DCCD0[0]);
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
