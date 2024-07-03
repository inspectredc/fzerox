#include "global.h"
#include "PR/leo.h"

extern s32 D_800CD510;
extern s32 D_800E4260;
extern s32 D_800E4264;

void func_8007F4E0(s32 arg0, s32 arg1) {
    D_800CD510 = 1;
    D_800E4264 = arg0;
    D_800E4260 = arg1;
}

#ifdef IMPORT_BSS
static s8 D_800E42C8[4];
extern s16 D_800E42CC;

void func_8007F500(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E42C8[i] = 0;
    }

    D_800E42CC = 0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/194E0/func_8007F500.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/194E0/func_8007F520.s")

void func_80076310(void);
void func_8007F520(void);
s32 func_80403F4C(s32, OSMesg*, s32);
void func_8040428C(void);
s32 func_804043B8(s32);
s32 func_804046F0(void);
void func_80404AEC(char*, char*);
void func_804067BC(s32, s32);
void func_800762B0(LEODiskID);
extern OSMesgQueue D_800E42D0;
extern OSMesg D_800E42E8;
extern s32 D_80428610;
extern LEODiskID D_80428618;
extern LEODiskID leoBootID;

void func_8007F5EC(void) {

    func_80076310();
    osCreateMesgQueue(&D_800E42D0, &D_800E42E8, 0x10);
    func_80404AEC("01", "EFZE");
    if (func_80403F4C(0x101, &D_800E42E8, 0x10) < 0) {
        switch (D_80428610) {
            case 0x29:
                return;
            case 0x2A:
            case 0xF9:
            default:
                goto label;
                break;
        }
    }

label:
    if (D_80428610 == 0xF9) {
        func_8007F520();
    }
    func_8040428C();
    func_800762B0(D_80428618);
    leoBootID = D_80428618;

    switch (func_804046F0()) {
        case 1:
            break;
        case 0:
            if (func_804043B8(1) < 0) {}
            break;
        case -1:
            switch (D_80428610) {
                case 42:
                    break;
                case 23:
                    func_804043B8(1);
                    break;
            }
            break;
    }
    func_804067BC(0, 0);
}
