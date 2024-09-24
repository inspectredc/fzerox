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
    task->t.data_size = (size_t) (gMasterDisp - (Gfx*) D_800DCCF0) * sizeof(Gfx);
    task->t.yield_data_ptr = (u64*) gOSYieldData;
    task->t.yield_data_size = OS_YIELD_DATA_SIZE;
    D_800DCCC0 = task;
    osSendMesg(&D_800DCAE0, (OSMesg) 0x15, 1);
}

extern OSMesgQueue D_800DCAB0;
extern OSMesgQueue D_800DCAC8;
extern FrameBuffer* D_800DCCD0[];
extern void* D_800DCD10;

void func_800690FC(void);
void func_i2_800FD344(void);

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

u32 D_800CCFE0 = 0;
s16 D_800CCFE4 = 2;
s16 D_800CCFE8 = 2;

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1AE0/func_80068008.s")
/*
extern OSMesgQueue D_800DCAB0;
extern u32 D_800DCD14;
extern u32 D_800DCD18;
extern u32 D_800DCD1C;
extern u32 D_800DCD20;
extern u32 D_800DCD24;
extern u32 D_800DCD28;
extern u32 D_800DCD2C;
extern u32 D_800DCD30;
extern u32 D_800DCD34;
extern u32 D_800DCD38;
extern u32 D_800DCD3C;
extern u32 D_800DCD40;
extern u32 D_800DCD44;
extern u32 D_800DCD48;
extern u32 D_800DCD4C;
extern u32 D_800DCD50;
extern u32 D_800DCD54;
extern u32 D_800DCD58;
extern u32 D_800DCD5C;
extern u32 D_800DCD60;
extern u32 D_800DCD64;
extern u32 D_800DCD68;
extern u32 D_800DCD74;
extern u32 D_800DCD78;
extern u32 D_800DCD7C;
extern u32 D_800DCD80;
extern u32 D_800DCD84;
extern u32 D_800DCD88;
extern u32 D_800DCD8C;
extern u32 D_800DCD90;
extern u32 D_800DCE04;
extern u32 D_800DCE08;
extern u32 D_800DCE0C;
extern u32 D_800DCE10;
extern u32 D_800DCE14;
extern u32 D_800DCE18;
extern u32 D_800DCE1C;
extern u32 D_800DCE20;
extern u32 D_800DCD94;
extern u32 D_800DCD98;
extern u32 D_800DCD9C;
extern u32 D_800DCDA0;

extern u32 D_800DCDA4;
extern u32 D_800DCDA8;
extern u32 D_800DCDAC;
extern u32 D_800DCDB0;
extern u32 D_800DCDB4;
extern u32 D_800DCDB8;
extern u32 D_800DCDC4;
extern u32 D_800DCDC8;
extern u32 D_800DCDCC;
extern u32 D_800DCDD0;
extern u32 D_800DCDD4;
extern u32 D_800DCDD8;
extern u32 D_800DCDEC;
extern u32 D_800DCDF0;
extern u32 D_800DCDF4;
extern u32 D_800DCDF8;
extern u32 D_800DCDFC;
extern u32 D_800DCE00;

extern void* D_800DCCF4;
extern s32 D_800DCCFC;
extern s32 D_800CCFE0;
extern s16 D_800CCFE4;
extern s16 D_800CCFE8;
extern s32 D_800DCD00;
extern FrameBuffer* D_800DCCD0[];

extern s32 D_800CCFC0;
extern s16 D_80111840;
extern s32 D_800DCD04;
extern s32 D_800DCD08;
extern s32 D_800DCD0C;

extern Mtx D_80225800[];

DECLARE_SEGMENT(seg1);
DECLARE_SEGMENT(seg2);
DECLARE_SEGMENT(seg3);
DECLARE_SEGMENT(seg4);
DECLARE_SEGMENT(seg5);
DECLARE_SEGMENT(seg6);
DECLARE_SEGMENT(seg7);
DECLARE_SEGMENT(seg8);
DECLARE_SEGMENT(seg9);
DECLARE_SEGMENT(seg10);
DECLARE_SEGMENT(seg11);
DECLARE_SEGMENT(seg12);
DECLARE_SEGMENT(seg13);
DECLARE_SEGMENT(seg14);
DECLARE_SEGMENT(seg15);
DECLARE_SEGMENT(seg16);
DECLARE_SEGMENT(seg17);
DECLARE_SEGMENT(seg18);
DECLARE_SEGMENT(seg19);
DECLARE_SEGMENT(seg20);
DECLARE_SEGMENT(seg21);
DECLARE_SEGMENT(seg22);
DECLARE_SEGMENT(seg23);
DECLARE_SEGMENT(seg24);
DECLARE_SEGMENT(seg25);
DECLARE_SEGMENT(seg26);
DECLARE_SEGMENT(seg27);
DECLARE_SEGMENT(seg28);
DECLARE_SEGMENT(seg29);
DECLARE_SEGMENT(seg30);
DECLARE_SEGMENT(seg31);
DECLARE_SEGMENT(seg32);
DECLARE_SEGMENT(seg33);
DECLARE_SEGMENT(seg34);
DECLARE_SEGMENT(seg35);
DECLARE_SEGMENT(seg36);
DECLARE_SEGMENT(seg37);
DECLARE_SEGMENT(seg38);
DECLARE_SEGMENT(seg39);
DECLARE_SEGMENT(seg40);

DECLARE_SEGMENT(leo);
DECLARE_SEGMENT(ovl_i2);
DECLARE_SEGMENT(ovl_i10);

DECLARE_MIO0_SEGMENT(mio0_segment_1);
DECLARE_SEGMENT(_17B1E0);
DECLARE_SEGMENT(_17B960);
DECLARE_SEGMENT(unk4);
DECLARE_SEGMENT(unk5);
DECLARE_MIO0_SEGMENT(unk6);
DECLARE_SEGMENT(unk7);
DECLARE_SEGMENT(unk8);
DECLARE_MIO0_SEGMENT(unk9);

void noop_pad() {}

void func_80068008(void* arg0) {
    s32 startTime;
    OSMesg sp80;

    startTime = osGetTime();
    func_800BB46C();
    osRecvMesg(&D_800DCAB0, &sp80, OS_MESG_BLOCK);
    D_800DCD14 = osVirtualToPhysical(SEGMENT_VRAM_START(seg1));
    D_800DCD18 = osVirtualToPhysical(SEGMENT_VRAM_START(seg2));
    D_800DCD1C = osVirtualToPhysical(SEGMENT_VRAM_START(seg3));
    D_800DCD20 = osVirtualToPhysical(SEGMENT_VRAM_START(seg4));
    D_800DCD24 = osVirtualToPhysical(SEGMENT_VRAM_START(seg5));
    D_800DCD28 = osVirtualToPhysical(SEGMENT_VRAM_START(seg6));
    D_800DCD2C = osVirtualToPhysical(SEGMENT_VRAM_START(seg7));
    D_800DCD30 = osVirtualToPhysical(SEGMENT_VRAM_START(seg8));
    D_800DCD34 = osVirtualToPhysical(SEGMENT_VRAM_START(seg9));
    D_800DCD38 = osVirtualToPhysical(SEGMENT_VRAM_START(seg10));
    D_800DCD3C = osVirtualToPhysical(SEGMENT_VRAM_START(seg11));
    D_800DCD40 = osVirtualToPhysical(SEGMENT_VRAM_START(seg12));
    D_800DCD44 = osVirtualToPhysical(SEGMENT_VRAM_START(seg13));
    D_800DCD48 = osVirtualToPhysical(SEGMENT_VRAM_START(seg14));
    D_800DCD4C = osVirtualToPhysical(SEGMENT_VRAM_START(seg15));
    D_800DCD50 = osVirtualToPhysical(SEGMENT_VRAM_START(seg16));
    D_800DCD54 = osVirtualToPhysical(SEGMENT_VRAM_START(seg17));
    D_800DCD58 = osVirtualToPhysical(SEGMENT_VRAM_START(seg18));
    D_800DCD5C = osVirtualToPhysical(SEGMENT_VRAM_START(seg19));
    D_800DCD60 = osVirtualToPhysical(SEGMENT_VRAM_START(seg20));
    D_800DCD74 = osVirtualToPhysical(SEGMENT_VRAM_START(seg21));
    D_800DCD78 = osVirtualToPhysical(SEGMENT_VRAM_START(seg22));
    D_800DCD7C = osVirtualToPhysical(SEGMENT_VRAM_START(seg23));
    D_800DCD80 = osVirtualToPhysical(SEGMENT_VRAM_START(seg24));
    D_800DCD84 = osVirtualToPhysical(SEGMENT_VRAM_START(seg25));
    D_800DCD88 = osVirtualToPhysical(SEGMENT_VRAM_START(seg26));
    D_800DCD8C = osVirtualToPhysical(SEGMENT_VRAM_START(seg27));
    D_800DCD90 = osVirtualToPhysical(SEGMENT_VRAM_START(seg28));
    D_800DCE04 = osVirtualToPhysical(SEGMENT_VRAM_START(seg29));
    D_800DCE08 = osVirtualToPhysical(SEGMENT_VRAM_START(mio0_segment_1));
    D_800DCE0C = osVirtualToPhysical(SEGMENT_VRAM_START(seg31));
    D_800DCE10 = osVirtualToPhysical(SEGMENT_VRAM_START(seg32));
    D_800DCE14 = osVirtualToPhysical(SEGMENT_VRAM_START(seg33));
    D_800DCE18 = osVirtualToPhysical(SEGMENT_VRAM_START(seg34));
    D_800DCE1C = osVirtualToPhysical(SEGMENT_VRAM_START(seg35));
    D_800DCE20 = osVirtualToPhysical(SEGMENT_VRAM_START(seg36));
    D_800DCD94 = osVirtualToPhysical(SEGMENT_VRAM_START(seg37));
    D_800DCD98 = osVirtualToPhysical(SEGMENT_VRAM_START(seg38));
    D_800DCD9C = osVirtualToPhysical(SEGMENT_VRAM_START(seg39));
    D_800DCDA0 = osVirtualToPhysical(SEGMENT_VRAM_START(seg40));

    // Start and End Pairs
    D_800DCDA4 = D_800DCE08;
    D_800DCDA8 = D_800DCDA4 + SEGMENT_DECOMPRESSED_SIZE(mio0_segment_1);

    D_800DCDAC = D_800DCDA8;
    D_800DCDB0 = D_800DCDAC + SEGMENT_VRAM_SIZE(_17B1E0);

    D_800DCDB4 = D_800DCDB0;
    D_800DCDB8 = D_800DCDB4 + SEGMENT_VRAM_SIZE(_17B960);

    D_800DCDC4 = D_800DCDB8;
    D_800DCDC8 = D_800DCDC4 + SEGMENT_VRAM_SIZE(unk4);

    D_800DCDCC = D_800DCD28;
    D_800DCDD0 = D_800DCDCC + SEGMENT_VRAM_SIZE(unk5);

    D_800DCDD4 = D_800DCDC4;
    D_800DCDD8 = D_800DCDD4 + SEGMENT_DECOMPRESSED_SIZE(unk6);

    D_800DCDFC = D_800DCDB0;
    D_800DCE00 = D_800DCDFC + 0x1F820;

    D_800DCDEC = D_800DCE00;
    D_800DCDF0 = D_800DCDEC + SEGMENT_VRAM_SIZE(unk7);

    D_800DCDF4 = D_800DCE00;
    D_800DCDF8 = D_800DCDF4 + SEGMENT_VRAM_SIZE(unk8);

    D_800DCD64 = osVirtualToPhysical(SEGMENT_VRAM_START(leo));
    D_800DCD68 = osVirtualToPhysical(SEGMENT_VRAM_END(leo));

    func_80076BA0(0, 0);
    func_80076BA0(2, D_800DCD9C);
    func_80076BA0(8, D_800DCDA4);
    func_80076BA0(3, D_800DCDAC);
    func_80076804();
    func_80076848();

    osInvalICache(SEGMENT_TEXT_START(ovl_i2), SEGMENT_TEXT_SIZE(ovl_i2));\
    osInvalDCache(SEGMENT_DATA_START(ovl_i2), SEGMENT_DATA_SIZE(ovl_i2));
    func_80076658(SEGMENT_ROM_START(ovl_i2), SEGMENT_VRAM_START(ovl_i2), SEGMENT_ROM_SIZE(ovl_i2),
SEGMENT_BSS_START(ovl_i2), SEGMENT_BSS_SIZE(ovl_i2));

    osInvalICache(SEGMENT_TEXT_START(ovl_i10), SEGMENT_TEXT_SIZE(ovl_i10));\
    osInvalDCache(SEGMENT_DATA_START(ovl_i10), SEGMENT_DATA_SIZE(ovl_i10));
    func_80076658(SEGMENT_ROM_START(ovl_i10), SEGMENT_VRAM_START(ovl_i10), SEGMENT_ROM_SIZE(ovl_i10),
SEGMENT_BSS_START(ovl_i10), SEGMENT_BSS_SIZE(ovl_i10));

    // two separate decompressed size references??
    osInvalDCache(osPhysicalToVirtual(D_800DCDA4), SEGMENT_DECOMPRESSED_SIZE(unk9));
    func_800765CC(SEGMENT_ROM_START(mio0_segment_1), (uintptr_t)osPhysicalToVirtual(D_800DCDA4) +
SEGMENT_DECOMPRESSED_SIZE(mio0_segment_1), SEGMENT_ROM_SIZE(mio0_segment_1));
    // mio decode
    mio0Decode((uintptr_t)osPhysicalToVirtual(D_800DCDA4) + SEGMENT_DECOMPRESSED_SIZE(mio0_segment_1),
osPhysicalToVirtual(D_800DCDA4)); func_800765CC(SEGMENT_ROM_START(_17B1E0), osPhysicalToVirtual(D_800DCDAC),
SEGMENT_ROM_SIZE(_17B1E0)); func_800765CC(SEGMENT_ROM_START(_17B960), osPhysicalToVirtual(D_800DCDB4),
SEGMENT_ROM_SIZE(_17B960)); D_800DCCFC = 0; D_800DCD00 = 1; D_800DCD08 = 2; D_800DCD04 = 0; D_800DCD0C = 1;
    func_8006A6E4();
    if (D_800CCFC0 != 0) {
        func_800742D0();
    }
    func_800742FC();
    func_8006C378(D_80225800, 0, 1.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f);

    func_8006A8F0(osGetTime(), osGetTime() + osGetTime());
    func_80069D44();
    func_80115DF0();
    if (D_80111840 == 0) {
        func_800BA28C(2);
    } else {
        func_800BA28C(3);
    }


    while (true) {
        if (OS_CYCLES_TO_NSEC(osGetTime() - startTime) * 6e-8 > 230.0) {
            break;
        }
    }

    func_8006A904(osGetTime() + osGetTime(), osGetTime());
    osSetTime(0);
    osViSwapBuffer(D_800DCCD0[0]);
    func_80067B14();
    func_80067AE0();

    gMoveWd(gMasterDisp++, 6, 0, 0);
    gDPFullSync(gMasterDisp++);
    gSPEndDisplayList(gMasterDisp++);

    func_80067C0C(D_800DCCF4);
    func_80068B20();
    D_800CCFE0 = 0;

    while(true) {
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

        switch (D_800CCFE4) {
            case 2:
                func_80067D64();
                break;
            case 3:
                func_80067E98();
                break;
        }
        D_800CCFE0++;
    }
}
*/
