#include "global.h"
#include "libultra/ultra64.h"

void func_80076848(void);
void func_8007D9D0(void);
void func_8007F500(void);
void func_80085510(void);
void func_8008DA68(void);
void func_8008DB98(void);
void func_800A4B54(void);
void func_800A4BAC(void);
void func_800FC730(void);
extern s16 D_800CD16C;
extern s32 D_800DCE44;
extern s32 D_800DCE48;
extern s32 D_800DCE60;

void func_80068B20(void) {
    D_800DCE44 = -1;
    D_800DCE48 = 0x8000;
    if (D_800DCE60 != 0x20DE1529) {
        D_800DCE60 = 0x20DE1529;
        func_8008DB98();
        func_800A4BAC();
    } else {
        func_8008DA68();
        func_800A4B54();
    }
    func_80085510();
    func_800FC730();
    func_8007F500();
    func_80076848();
    func_8007D9D0();
    D_800CD16C = 1;
}

extern s16 D_800CD044;
extern s16 D_800CD048;
extern f32 D_800E5EF0;
extern s32 D_800F8514;

void func_80068BC0(void) {
    if (D_800CD044 == 0) {
        switch (D_800CD048) {
            case 1:
                D_800CD044 = 5;
                break;
            case 2:
                D_800CD044 = 1;
                D_800DCE48 = 0x8007;
                break;
            case 3:
                D_800CD044 = 1;
                D_800DCE48 = 0x800A;
                break;
            case 7:
                D_800CD044 = 1;
                D_800DCE48 = 0x8008;
                break;
            case 4:
                D_800CD044 = 1;
                if (D_800F8514 % 6 == 5) {
                    D_800DCE48 = 0x11;
                } else {
                    D_800DCE48 = 0x800F;
                    D_800F8514++;
                }
                D_800E5EF0 = 0.5f;
                break;
            case 5:
                D_800CD044 = 1;
                D_800DCE48 = 0x800F;
                break;
            case 6:
                D_800CD044 = 0xB;
                D_800DCE48 = 0x800F;
                break;
            case 8:
                D_800CD044 = 0x15;
                D_800DCE48 = 6;
                break;
            case 9:
                D_800CD044 = 0x15;
                D_800DCE48 = 0x8013;
                break;
            case 10:
            case 14:
                D_800CD044 = 0x15;
                D_800DCE48 = 0x8007;
                break;
            case 11:
                D_800CD044 = 0x1F;
                D_800DCE48 = 0x800A;
                break;
            case 12:
                D_800CD044 = 0x1F;
                D_800DCE48 = 0x8007;
                break;
            case 13:
                D_800CD044 = 0x15;
                D_800DCE48 = 0x8014;
                break;
            case 15:
                D_800CD044 = 0xB;
                if (D_800DCE44 == 1) {
                    D_800DCE48 = 0x4012;
                } else{
                    D_800DCE48 = 0x4009;
                }
                break;
            case 16:
                D_800CD044 = 0xB;
                D_800DCE48 = D_800DCE44;
                break;
        }
    } 
}

#ifdef REQUIRES_DATA
void func_8007E08C(void);
void func_8007E0CC(s32);
void func_800BAFA4(u8);
extern s8 D_800CD010;
extern s32 D_800DCE44;

void func_80068DCC(void) {
    static u16 D_800CD154 = 0;
    s32 var_v1;

    var_v1 = D_800CD154;
    switch (D_800DCE44) {
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0xE:
        case 0x15:
            if (D_800CD010 == 0) {
                D_800CD154 = 0;
            }
            return;
        case 0x8000:
            var_v1 = 0xD;
            break;
        case 0x11:
            var_v1 = 0x15;
            break;
        case 0x800B:
        case 0x800C:
            var_v1 = 0x16;
            break;
        case 0x8013:
        case 0x8014:
            var_v1 = 0xF;
            break;
        case 0x4009:
        case 0x4012:
        case 0x8007:
        case 0x8008:
        case 0x800A:
        case 0x800F:
            var_v1 = 0xE;
            break;
        case 0xD:
        case 0x10:
            D_800CD154 = 0;
            return;
        default:
            break;
    }
    if (D_800CD154 != var_v1) {
        func_8007E0CC(D_800CD154);
        func_8007E08C();
        func_800BAFA4(var_v1);
    }
    D_800CD154 = var_v1;
}

#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_80068DCC.s")
#endif

void func_8007DABC(void*);


typedef struct unk_800DCE98 {
    OSPfs pfs;
    s8 unk_68[0x3];
    u8 unk_6B;
    s8 unk_6C;
    s8 unk_6D;
    u8 unk_6E;
    u8 unk_6F;
    u8 unk_70;
    u8 unk_71;
    s16 unk_72;
    s16 unk_74;
    s16 unk_76;
    s16 unk_78;
    u16 unk_7A;
    u16 unk_7C;
    u16 unk_7E;
    u16 unk_80;
    u16 unk_82;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8C;
    s32 unk_90;
} unk_800DCE98;

extern unk_800DCE98 D_800DCE98[];
extern unk_800DCE98 D_800DD180;


extern s32 D_800DD228;
extern u16 D_800E416E;
extern s32 D_800F8514;

extern s32 D_800CD000;
extern s32 D_800CD008;
extern s8 D_800CD010;
extern s8 D_800CD014;
extern s8 D_800CD018;
extern u16 D_800CD020;
extern s32 D_800CD024[3];
extern s32 D_800CD030[3];
extern s8 D_800CD03C[8];
extern s32 D_800DCE44;
extern s32 D_800DCE48;

void func_80068F04(void) {

    if (D_800DCE44 != D_800DCE48) {
        D_800CD010 = 0;
        D_800CD020 = 0;
        return;
    }
    func_8007DABC(&D_800DD180);
    switch (D_800DCE44) {
        case 0x8000:
            if (D_800DD228 != 0) {
                D_800CD020++;
            }
            if ((D_800CD010 != 0) && (D_800DD228 != 0)) {

                D_800DCE48 = D_800CD024[D_800CD014];
                D_800CD000 = D_800CD030[D_800CD014];
                D_800F8514 = D_800CD03C[D_800CD018];
                D_800CD014++;
                D_800CD018++;
                if (D_800CD014 >= 3) {
                    D_800CD014 = 0;
                }
                if (D_800CD018 >= 5) {
                    D_800CD018 = 0;
                }
                D_800CD020 = 0;
                D_800CD010 = 1;
                D_800CD008 = 3;
            }
            break;
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0xE:
        case 0x15:
            if (D_800CD010 != 0) {
                D_800CD020++;
                switch (D_800CD010) {
                    case 1:
                        if (D_800E416E & 0x9000) {
                    case 3:
                            D_800DCE48 = 0x8000;
                            D_800CD020 = 0;
                            D_800CD010 = 2;
                        }
                        break;
                    case 2:
                        break;
                }
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_800690FC.s")

void func_800FD184(s32);
extern s32 (*D_800CD0FC[])(void);
extern s16 D_80106DA0;

void func_80069698(s32 arg0) {

    if ((D_800CD044 != 3) && (D_80106DA0 != 0)) {
        arg0 = D_800CD0FC[D_800DCE44 & 0x1F]();
    }
    func_800FD184(arg0);
}

void func_80069820(void);
extern s16 D_800CD168;

void func_80069700(void) {
    s32 i;

    if (D_800CD168 != 0) {
        func_80069820();
        D_800CD168 = 0;
    }
    
    for (i = 0; i < 4; i++) {
        if (__osMotorAccess(&D_800DCE98[i].pfs, 0) == 0) {
            D_800DCE98[i].unk_74 = 1;
        } else {
            D_800DCE98[i].unk_74 = 0;
        }
        D_800DCE98[i].unk_76 = 0;
        D_800DCE98[i].unk_72 = D_800DCE98[i].unk_76;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_80069790.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_80069820.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_80069D44.s")

extern u16 D_800DCE70;
extern u16 D_800DCE74;
extern u16 D_800DCE78;
extern u16 D_800DCE7C;

extern s32 D_800DCF2C;
extern s32 D_800DCFC0;
extern s32 D_800DD054;

void* func_80069ED0(void) {
    if ((D_800DCE70 & 0x1F07) == 2) {
        return &D_800DCE98;
    }
    if ((D_800DCE74 & 0x1F07) == 2) {
        return &D_800DCF2C;
    }
    if ((D_800DCE78 & 0x1F07) == 2) {
        return &D_800DCFC0;
    }
    if ((D_800DCE7C & 0x1F07) == 2) {
        return &D_800DD054;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_80069F5C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006A00C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006A3AC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006A6E4.s")

extern s32 D_800CD170;
extern u32 D_800CD174;
extern s32 D_800CD178;
extern u32 D_800CD17C;

void func_8006A8F0(s32 arg0, s32 arg1) {
    D_800CD170 = arg0;
    D_800CD174 = arg1;
}


void func_8006A904(s32 arg0, s32 arg1) {
    D_800CD178 = arg0;
    D_800CD17C = arg1;
}

s32 func_8006A918(void) {

    D_800CD170 = D_800CD170 * 0x41C64E6D + 0x3039;
    if (D_800CD174 & 1) {
        D_800CD174 ^= 0x11020;
    }

    D_800CD174 >>= 1;

    return D_800CD170 ^ D_800CD174;
}

s32 func_8006A978(void) {

    D_800CD178 = D_800CD178 * 0x41C64E6D + 0x10932;
    if (D_800CD17C & 1) {
        D_800CD17C ^= 0x11020;
    }

    D_800CD17C >>= 1;

    return D_800CD178 + D_800CD17C;
}

s32 func_8006A9E0(f32 arg0) {
    if (arg0 < 0.0f) {
        return arg0 - 0.5f;
    }
    return arg0 + 0.5f;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006AA38.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006AC10.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006ADE4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006AFC8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006AFE4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006B000.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006B010.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006B07C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006B18C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006B33C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006B908.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006BB80.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006BBE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006BC84.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006BFCC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006C278.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006C378.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006C520.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006CB0C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006CC98.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006D03C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_8006D2E0.s")
