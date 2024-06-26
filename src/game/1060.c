#include "global.h"
#include "libultra/ultra64.h"

extern s32 D_800D8430;
extern OSThread D_800DC030;
extern OSMesgQueue D_800DCAF8;
extern void* D_800DCC80;

void func_800678B8(void*);

void func_80067060(void) {
    osInitialize();
    osCreateMesgQueue(&D_800DCAF8, &D_800DCC80, 1);
    osSetEventMesg(0xEU, &D_800DCAF8, (void* )0x1B);
    osCreateThread(&D_800DC030, 1, func_800678B8, NULL, &D_800D8430, 0x64);
    osStartThread(&D_800DC030);
}

extern s32 D_800CCFA0;
extern s32 D_800CCFA4;

void func_800670E8(void) {
    osSpTaskYield();
    D_800CCFA0 = 1;
    D_800CCFA4 = 1;
}

extern void* D_800DCCC4;

void func_80067118(void) {
    osSpTaskLoad(D_800DCCC4);
    osSpTaskStartGo(D_800DCCC4);
    D_800CCFA0 = 2;
    D_800CCFA4 = 1;
}

extern OSTask* D_800DCCC0;

void func_8006715C(void) {
    osDpSetStatus(0x3C0);
    osSpTaskLoad(D_800DCCC0);
    osSpTaskStartGo(D_800DCCC0);
    D_800CCFA0 = 3;
    D_800CCFA4 = 1;
}

void func_800671A8(void) {
    osSpTaskLoad(D_800DCCC0);
    osSpTaskStartGo(D_800DCCC0);
    D_800CCFA0 = 3;
    D_800CCFA4 = 1;
}

extern void* D_800DCCD0[];

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/1060/func_800671EC.s")

extern s8 D_800CCFC8;
extern OSViMode D_800D1DA0;
extern OSViMode D_800D2660;
extern s32 D_800D8830;
extern OSThread D_800DC1E0;
extern OSMesgQueue D_800DCA50;
extern void* D_800DCB28;
extern OSPiHandle* D_800DCCDC;
extern OSPiHandle* D_800DCCE0;
extern s32 D_801D9800;
extern s32 D_80200000;
extern s32 D_803DA800;

extern void func_800671EC(void*);
extern void func_80080974(void*, s32, s32);
extern void func_8008099C(void);

void func_800678B8(void* arg0) {
    D_800DCCD0[0] = &D_801D9800;
    D_800DCCD0[1] = &D_80200000;
    D_800DCCD0[2] = &D_803DA800;
    osCreateViManager(0xFE);
    if (osTvType == 1) {
        osViSetMode(&D_800D1DA0);
    } else {
        osViSetMode(&D_800D2660);
    }
    osViSetSpecialFeatures(2);
    osViSetSpecialFeatures(8);
    osViSetSpecialFeatures(0x20);
    osViSetSpecialFeatures(0x80);
    osViBlack(1);
    osCreatePiManager(0x96, &D_800DCA50, &D_800DCB28, 0x40);
    D_800DCCDC = osCartRomInit();
    D_800DCCE0 = osDriveRomInit();
    func_8008099C();
    func_80080974(&D_801D9800, 0x140, 0x10);
    osCreateThread(&D_800DC1E0, 3, func_800671EC, NULL, &D_800D8830, 0x63);
    if (D_800CCFC8 != 0) {
        osStartThread(&D_800DC1E0);
    }
    osSetThreadPri(NULL, 0);

    while (true) {}
}

void func_80069700(void);
void func_800BA248(void);
void func_8040BCB0(void);
extern s32 D_800CCFC0;
extern s32 D_800CCFC4;
extern s32 D_800DCCC8;
extern s32 D_800DCCCC;

void func_80067A10(s32 arg0) {
    void* sp1C;

    osRecvMesg(&D_800DCAF8, &sp1C, 1);
    if ((D_800DCCC8 == 0) && (D_800CCFC4 != 0)) {
        func_800BA248();
    }
    D_800DCCC8 = 1;
    osViBlack(1);
    osViSetYScale(1.0f);
    if ((D_800CCFC0 != 0) && (D_800DCCCC != 0)) {
        func_8040BCB0();
    }
    func_80069700();

    while (true) {}
}
