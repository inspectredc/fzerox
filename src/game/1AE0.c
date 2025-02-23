#include "global.h"
#include "audio.h"
#include "fzx_game.h"
#include "fzx_thread.h"

GfxPool* D_800DCCF0;
OSTask* sGfxTask;
Gfx* gMasterDisp;
s32 D_800DCCFC;
s32 D_800DCD00;
s32 D_800DCD04;
s32 D_800DCD08;
s32 D_800DCD0C;
OSMesg D_800DCD10;
u32 D_800DCD14;
u32 D_800DCD18;
u32 D_800DCD1C;
u32 D_800DCD20;
u32 D_800DCD24;
u32 D_800DCD28;
u32 D_800DCD2C;
u32 D_800DCD30;
u32 D_800DCD34;
u32 D_800DCD38;
u32 D_800DCD3C;
u32 D_800DCD40;
u32 D_800DCD44;
u32 D_800DCD48;
u32 D_800DCD4C;
u32 D_800DCD50;
u32 D_800DCD54;
u32 D_800DCD58;
u32 D_800DCD5C;
u32 D_800DCD60;
u32 D_800DCD64;
u32 D_800DCD68;
UNUSED u32 D_800DCD6C;
UNUSED u32 D_800DCD70;
u32 D_800DCD74;
u32 D_800DCD78;
u32 D_800DCD7C;
u32 D_800DCD80;
u32 D_800DCD84;
u32 D_800DCD88;
u32 D_800DCD8C;
u32 D_800DCD90;
u32 D_800DCD94;
u32 D_800DCD98;
u32 D_800DCD9C;
u32 D_800DCDA0;
u32 D_800DCDA4;
u32 D_800DCDA8;
u32 D_800DCDAC;
u32 D_800DCDB0;
u32 D_800DCDB4;
u32 D_800DCDB8;
UNUSED u32 D_800DCDBC;
UNUSED u32 D_800DCDC0;
u32 D_800DCDC4;
u32 D_800DCDC8;
u32 D_800DCDCC;
u32 D_800DCDD0;
u32 D_800DCDD4;
u32 D_800DCDD8;
s32 D_800DCDDC;
s32 D_800DCDE0;
s32 D_800DCDE4;
s32 D_800DCDE8;
u32 D_800DCDEC;
u32 D_800DCDF0;
u32 D_800DCDF4;
u32 D_800DCDF8;
u32 D_800DCDFC;
u32 D_800DCE00;
u32 D_800DCE04;
u32 D_800DCE08;
u32 D_800DCE0C;
u32 D_800DCE10;
u32 D_800DCE14;
u32 D_800DCE18;
u32 D_800DCE1C;
u32 D_800DCE20;

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
    D_800DCCF0 = &D_8024DCE0[D_800DCCFC];
    Segment_SetPhysicalAddress(1, D_800DCCF0);
    gMasterDisp = D_800DCCF0->gfxBuffer;
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
    task->t.data_ptr = (u64*) D_800DCCF0->gfxBuffer;
    task->t.data_size = (size_t) (gMasterDisp - D_800DCCF0->gfxBuffer) * sizeof(Gfx);
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
    D_800DCD14 = osVirtualToPhysical(SEGMENT_VRAM_START(main));
    D_800DCD18 = osVirtualToPhysical(SEGMENT_VRAM_END(main));
    D_800DCD1C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i2));
    D_800DCD20 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i2));
    D_800DCD24 = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i3));
    D_800DCD28 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i3));
    D_800DCD2C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i4));
    D_800DCD30 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i4));
    D_800DCD34 = osVirtualToPhysical(SEGMENT_VRAM_START(course_select));
    D_800DCD38 = osVirtualToPhysical(SEGMENT_VRAM_END(course_select));
    D_800DCD3C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i6));
    D_800DCD40 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i6));
    D_800DCD44 = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i7));
    D_800DCD48 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i7));
    D_800DCD4C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i8));
    D_800DCD50 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i8));
    D_800DCD54 = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i9));
    D_800DCD58 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i9));
    D_800DCD5C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i10));
    D_800DCD60 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i10));
    D_800DCD74 = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer1));
    D_800DCD78 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer1));
    D_800DCD7C = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer2));
    D_800DCD80 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer2));
    D_800DCD84 = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer3));
    D_800DCD88 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer3));
    D_800DCD8C = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer_unused));
    D_800DCD90 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer_unused));
    D_800DCE04 = osVirtualToPhysical(SEGMENT_VRAM_START(buffers));
    D_800DCE08 = osVirtualToPhysical(SEGMENT_VRAM_END(buffers));
    D_800DCE0C = osVirtualToPhysical(SEGMENT_VRAM_START(unk_gfx_segment));
    D_800DCE10 = osVirtualToPhysical(SEGMENT_VRAM_END(unk_gfx_segment));
    D_800DCE14 = osVirtualToPhysical(SEGMENT_VRAM_START(unk_context));
    D_800DCE18 = osVirtualToPhysical(SEGMENT_VRAM_END(unk_context));
    D_800DCE1C = osVirtualToPhysical(SEGMENT_VRAM_START(audio_context));
    D_800DCE20 = osVirtualToPhysical(SEGMENT_VRAM_END(audio_context) + 0x10);
    D_800DCD94 = osVirtualToPhysical(SEGMENT_VRAM_START(gfxpool));
    D_800DCD98 = osVirtualToPhysical(SEGMENT_VRAM_END(gfxpool));
    D_800DCD9C = osVirtualToPhysical(SEGMENT_VRAM_START(unk_bss_segment));
    D_800DCDA0 = osVirtualToPhysical(SEGMENT_VRAM_END(unk_bss_segment));

    D_800DCDA4 = D_800DCE08;
    D_800DCDA8 = D_800DCDA4 + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0);

    D_800DCDAC = D_800DCDA8;
    D_800DCDB0 = D_800DCDAC + (size_t) SEGMENT_VRAM_SIZE(segment_17B1E0);

    D_800DCDB4 = D_800DCDB0;
    D_800DCDB8 = D_800DCDB4 + (size_t) SEGMENT_VRAM_SIZE(segment_17B960);

    D_800DCDC4 = D_800DCDB8;
    D_800DCDC8 = D_800DCDC4 + (size_t) SEGMENT_VRAM_SIZE(segment_1B8550);

    D_800DCDCC = D_800DCD28;
    D_800DCDD0 = D_800DCDCC + (size_t) SEGMENT_VRAM_SIZE(segment_1E23F0);

    D_800DCDD4 = D_800DCDB8;
    D_800DCDD8 = D_800DCDD4 + (size_t) SEGMENT_DATA_SIZE_CONST(segment_22B0A0);

    D_800DCDFC = D_800DCDB0;
    D_800DCE00 = D_800DCDFC + 0x1F820;

    D_800DCDEC = D_800DCE00;
    D_800DCDF0 = D_800DCDEC + (size_t) SEGMENT_VRAM_SIZE(course_edit_textures);

    D_800DCDF4 = D_800DCE00;
    D_800DCDF8 = D_800DCDF4 + (size_t) SEGMENT_VRAM_SIZE(create_machine_textures);

    D_800DCD64 = osVirtualToPhysical(SEGMENT_VRAM_START(leo));
    D_800DCD68 = osVirtualToPhysical(SEGMENT_VRAM_END(leo));

    // Setup memory
    Segment_SetAddress(0, 0);
    Segment_SetAddress(2, D_800DCD9C);
    Segment_SetAddress(8, D_800DCDA4);
    Segment_SetAddress(3, D_800DCDAC);
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

    osInvalDCache(osPhysicalToVirtual(D_800DCDA4), SEGMENT_DATA_SIZE_CONST(segment_16C8A0));
    Dma_LoadAssets(SEGMENT_ROM_START(segment_16C8A0),
                   (uintptr_t) osPhysicalToVirtual(D_800DCDA4) + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
                   SEGMENT_ROM_SIZE(segment_16C8A0));

    mio0Decode((uintptr_t) osPhysicalToVirtual(D_800DCDA4) + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
               osPhysicalToVirtual(D_800DCDA4));
    Dma_LoadAssets(SEGMENT_ROM_START(segment_17B1E0), osPhysicalToVirtual(D_800DCDAC),
                   SEGMENT_ROM_SIZE(segment_17B1E0));
    Dma_LoadAssets(SEGMENT_ROM_START(segment_17B960), osPhysicalToVirtual(D_800DCDB4),
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
