#include "global.h"
#include "PR/leo.h"

s32 func_800BBD00(void);
void func_800BBD60(s32);

void func_800751C0(void) {
    s32 sp1C = func_800BBD00();

    func_800BBD60(1);
    osWritebackDCacheAll();
    func_800BBD60(sp1C);
}

#ifdef IMPORT_BSS
static u8 D_800E332C[4];

void func_800751FC(char* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E332C[i] = *arg0++;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_800751FC.s")
#endif

void func_80075228(void) {
}

extern OSThread* D_800CD2D4;

void func_80075230(OSThread* arg0) {
    D_800CD2D4 = arg0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_8007523C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_800752EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_800753EC.s")

s32 func_80075534(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_80075534.s")

s32 func_80075690(LEODiskID);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_80075690.s")

s32 func_80075738(LEODiskID);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_80075738.s")

void func_800751C0(void);
void func_80075228(void);
s32 func_800753EC(void);
void func_8007FC68(s32);
void func_8007FCB8(void);
s32 func_i1_80414E30(u8*);
extern s32 D_800CD2D0;
extern u8 D_800E32E0;
extern s32 D_800E3324;

s32 func_80075800(void) {

    D_800E3324 = func_i1_80414E30(&D_800E32E0);

    switch (D_800E3324) {
        case 0:
            if (D_800CD2D0 == 0) {
                if (func_800753EC() == 0) {
                    return 0;
                }
                return 1;
            }
            return 0;
        case 47:
            if (func_800753EC() == 0) {
                func_80075228();
                return 0;
            }
            break;
        case 8:
            return 2;
        case 42:
            return 1;
        case 34:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
    }
    return 1;
}

s32 func_800758F8(void) {

    D_800E3324 = func_i1_80414E30(&D_800E32E0);

    switch (D_800E3324) {
        case 8:
            return 1;
        case 34:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
        case 0:
        case 42:
        case 47:
            if (D_800E32E0 & 1) {
                return 1;
            } else {
                return 0;
            }
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_800759AC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_80075D10.s")

extern LEODiskID D_800CD2B0;
#ifdef IMPORT_BSS
extern s32 D_800DCCCC;

s32 func_800760F8(void) {
    static s32 D_800E3370;

    if (D_800DCCCC == 0) {
        return 0;
    }
    D_800E3370 = func_80075800();

    while (D_800E3370 == 2) {
        D_800E3370 = func_80075800();
    }
    if (D_800E3370 == 0) {
        if (func_80075738(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_800760F8.s")
#endif

#ifdef IMPORT_BSS
extern s32 D_800DCCCC;
s32 func_800761D4(void) {
    static s32 D_800E3374;

    if (D_800DCCCC == 0) {
        return 0;
    }
    D_800E3374 = func_80075800();

    while (D_800E3374 == 2) {
        D_800E3374 = func_80075800();
    }
    if (D_800E3374 == 0) {
        if (func_80075690(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F1C0/func_800761D4.s")
#endif

void func_800762B0(LEODiskID arg0) {
    D_800CD2B0 = arg0;
}

extern OSMesgQueue D_800E3308;
extern void* D_800E3320;

void func_80076310(void) {
    osCreateMesgQueue(&D_800E3308, &D_800E3320, 1);
}

s32 func_i1_80414BA0(s32, s32, void*, s32);

extern s32 D_800E3330;

s32 func_80076340(void) {

    osCreateMesgQueue(&D_800E3308, &D_800E3320, 1);
    D_800E3324 = func_i1_80414BA0(0x95, 0x96, &D_800E3330, 0x10);

    if (D_800E3324 == 0x29) {
        return -1;
    }
    return 0;
}

extern OSMesg D_800E3328;
extern OSMesgQueue D_800DCAE0;

void func_i1_8040BD70(void);

void func_800763A8(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        do {
            osRecvMesg(&D_800DCAE0, &D_800E3328, 1);
        } while (D_800E3328 != (OSMesg) 0x1A);

        func_i1_8040BD70();
        D_800E3324 = func_80075534();

        if (D_800E3324 != 0x2B) {
            return;
        }
    }
    func_800751C0();
    func_8007FCB8();
    func_8007FC68(D_800E3324);
    func_800751C0();
    while (true) {}
}

void func_8007647C(void) {
}
