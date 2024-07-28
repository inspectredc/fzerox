#include "global.h"
#include "audio.h"
#include "fzxthread.h"

extern s32 D_800DCD04;
extern s32 D_800DCD08;
extern s32 D_800DCD0C;

void func_80067AE0(void) {
    s32 temp_t7;

    temp_t7 = D_800DCD08;
    D_800DCD08 = D_800DCD04;
    D_800DCD04 = D_800DCD0C;
    D_800DCD0C = temp_t7;
}

void func_80076B80(s32, void*);
extern void* D_800DCCF0;
extern void* D_800DCCF4;
extern s32 D_800DCCFC;
extern s32 D_800DCD00;
extern u8 D_8024DCE0[];
extern u8 D_802A6AC0[];
extern Gfx* gMasterDisp;

void func_80067B14(void) {

    D_800DCD00 ^= 1;
    D_800DCCFC ^= 1;
    D_800DCCF4 = (D_800DCCFC << 6) + D_802A6AC0;
    D_800DCCF0 = (D_800DCCFC * 0x2C6F0) + D_8024DCE0;
    func_80076B80(1, D_800DCCF0);
    gMasterDisp = D_800DCCF0;
}

Gfx* func_80076C08(Gfx*);

void func_80067BA8(void) {
    gMasterDisp = func_80076C08(gMasterDisp);
}

void func_80067BD0(void) {
    gDPFullSync(gMasterDisp++);
    gSPEndDisplayList(gMasterDisp++);
}

extern OSMesgQueue D_800DCAE0;
extern s32 D_800DCE44;
extern OSTask* D_800DCCC0;

void func_80067C0C(OSTask* task) {

    task->t.type = 1;
    task->t.flags = 4;
    task->t.ucode_boot = (u64*) rspbootTextStart;
    task->t.ucode_boot_size = (uintptr_t) rspbootTextEnd - (uintptr_t) rspbootTextStart;

    switch (D_800DCE44 & 0xC000) {
        case 0x0:
            task->t.ucode = (u64*) gspF3DEX_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DEX_fifoDataStart;
            break;
        case 0x4000:
            task->t.ucode = (u64*) gspF3DLX_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DLX_Rej_fifoDataStart;
            break;
        case 0x8000:
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
    task->t.data_ptr = D_800DCCF0;
    task->t.data_size = (size_t) (gMasterDisp - (Gfx*)D_800DCCF0) * sizeof(Gfx);
    task->t.yield_data_ptr = (u64*) gOSYieldData;
    task->t.yield_data_size = OS_YIELD_DATA_SIZE;
    D_800DCCC0 = task;
    osSendMesg(&D_800DCAE0, (OSMesg)0x15, 1);
}


extern OSMesgQueue D_800DCAB0;
extern OSMesgQueue D_800DCAC8;
extern FrameBuffer* D_800DCCD0[];
extern void* D_800DCD10;

void func_800690FC(void);
void func_i2_800FD344(void);
Gfx* func_80069698(Gfx*);

void func_80067D64(void) {
    MQ_WAIT_FOR_MESG(&D_800DCAB0, &D_800DCD10);
    func_800B9E28();
    func_80067B14();
    func_800690FC();
    func_80067BA8();
    gMasterDisp = func_80069698(gMasterDisp);
    func_80067BD0();
    MQ_WAIT_FOR_MESG(&D_800DCAC8, &D_800DCD10);

    while (osDpGetStatus() & 0x170) {}

    func_80077C9C();
    func_i2_800FD344();
    osViSwapBuffer(D_800DCCD0[D_800DCD00]);

    while (osViGetCurrentFramebuffer() != D_800DCCD0[D_800DCD00]) {}

    func_80067C0C(D_800DCCF4);
}

void func_80067E98(void) {
    s32 var_s1 = 0x186A0;

    MQ_WAIT_FOR_MESG(&D_800DCAB0, &D_800DCD10);
    func_80067B14();
    func_800690FC();
    func_80067AE0();
    func_80067BA8();
    gMasterDisp = func_80069698(gMasterDisp);
    func_80067BD0();
    func_800B9E28();
    MQ_WAIT_FOR_MESG(&D_800DCAC8, &D_800DCD10);
    func_i2_800FD344();
    osViSwapBuffer(D_800DCCD0[D_800DCD08]);
    func_80077C9C();

    while (
        (osViGetCurrentFramebuffer() == D_800DCCD0[D_800DCD04] || osViGetNextFramebuffer() == D_800DCCD0[D_800DCD04]) &&
        var_s1 != 0) {
        var_s1 -= 1;
    }

    func_80067C0C(D_800DCCF4);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1AE0/func_80068008.s")
