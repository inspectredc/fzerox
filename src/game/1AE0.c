#include "global.h"

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

void func_80076B80(s32, void*, s32*);
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
    func_80076B80(1, D_800DCCF0, &D_800DCD00);
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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1AE0/func_80067C0C.s")

extern OSMesgQueue D_800DCAB0;
extern OSMesgQueue D_800DCAC8;
extern void* D_800DCCD0[];
extern void* D_800DCD10;
void func_800B9E28(void);
void func_800690FC(void);
void func_80077C9C(void);
void func_800FD344(void);
void func_80067C0C(void*);
Gfx* func_80069698(Gfx*);

void func_80067D64(void) {
    osRecvMesg(&D_800DCAB0, &D_800DCD10, 1);
    func_800B9E28();
    func_80067B14();
    func_800690FC();
    func_80067BA8();
    gMasterDisp = func_80069698(gMasterDisp);
    func_80067BD0();
    osRecvMesg(&D_800DCAC8, &D_800DCD10, 1);

    while (osDpGetStatus() & 0x170) {}
    
    func_80077C9C();
    func_800FD344();
    osViSwapBuffer(D_800DCCD0[D_800DCD00]);

    while (osViGetCurrentFramebuffer() != D_800DCCD0[D_800DCD00]) {}
    
    func_80067C0C(D_800DCCF4);
}

void func_80067E98(void) {
    s32 var_s1 = 0x186A0;

    osRecvMesg(&D_800DCAB0, &D_800DCD10, 1);
    func_80067B14();
    func_800690FC();
    func_80067AE0();
    func_80067BA8();
    gMasterDisp = func_80069698(gMasterDisp);
    func_80067BD0();
    func_800B9E28();
    osRecvMesg(&D_800DCAC8, &D_800DCD10, 1);
    func_800FD344();
    osViSwapBuffer(D_800DCCD0[D_800DCD08]);
    func_80077C9C();

    while ((osViGetCurrentFramebuffer() == D_800DCCD0[D_800DCD04] || osViGetNextFramebuffer() == D_800DCCD0[D_800DCD04]) && var_s1 != 0) {
        var_s1 -= 1;
    }

    func_80067C0C(D_800DCCF4);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1AE0/func_80068008.s")
