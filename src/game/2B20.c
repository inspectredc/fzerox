#include "global.h"
#include "audio.h"

void func_80076848(void);
void func_8007D9D0(void);
void func_8007F500(void);
void func_80085510(void);
void func_8008DA68(void);
void func_8008DB98(void);
void func_800A4B54(void);
void func_800A4BAC(void);
void func_i2_800FC730(void);
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
    func_i2_800FC730();
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
                } else {
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

#ifdef IMPORT_DATA
void func_8007E0CC(s32);
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
void func_80068DCC(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/2B20/func_80068DCC.s")
#endif

void func_8007DABC(void*);

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

void func_80069820(void);

extern s32 (*D_800CD0A4[])(void);
extern void (*D_800CD04C[])(void);
extern OSMesgQueue D_800DCA80;
extern s8 D_800DCE5C;
extern s16 D_800CD168;

// Ovl 9 Segments
extern u8 D_F2AC0[];
extern u8 D_1459A0[];
extern u8 D_i9_80168A70[];
extern u8 D_i9_80168CD0[];
extern u8 D_i9_80168CE0[];
extern u8 D_i9_80115DF0[];

void func_800690FC(void) {
    s32 sp24;

    if (D_800DCE44 != D_800DCE48) {
        if (D_800CD044 == 0) {
            if (D_800DCE44 == -1) {
                D_800CD044 = 3;
            } else {
                D_800CD044 = 1;
            }
        }
    } else {
        func_80068BC0();
    }

    D_800CD048 = 0;
    switch (D_800CD044) {
        case 1:
        case 11:
        case 21:
        case 31:
            func_i2_800FC77C();
            if (D_800CD168 != 0) {
                func_80069820();
                D_800CD168 = 0;
            }
            D_800CD0A4[D_800DCE44 & 0x1F]();
            func_i2_800FCE3C();
            if (D_800CD16C != 0) {
                osContStartReadData(&D_800DCA80);
                D_800CD168 = 1;
            }
            D_800CD044++;
            return;
        case 2:
        case 12:
        case 22:
        case 32:
            if (D_800CD168 != 0) {
                func_80069820();
                D_800CD168 = 0;
            }
            D_800CD0A4[D_800DCE44 & 0x1F]();
            if (func_i2_800FCE3C() != 0) {
                if (D_800DCE44 == 1) {
                    func_i3_80134598();
                }
                D_800CD044++;
            }
            if (D_800CD16C != 0) {
                osContStartReadData(&D_800DCA80);
                D_800CD168 = 1;
                return;
            }
            return;
        case 3:
        case 13:
        case 23:
        case 33:
            func_80069700();
            switch (D_800DCE44) {
                case 0x4009:
                case 0x4012:
                    if ((D_800CD000 == 1) && (D_800F8514 < 0x18)) {
                        func_i2_801012CC(D_800F8514);
                    }
                    break;
                case 0x8008:
                    func_i4_8011A7B8();
                    break;
            }
            D_800DCE44 = D_800DCE48;
            if (D_800CD010 == 2) {
                D_800CD010 = 0;
            }
            D_800DCE5C = 0;
            func_800766F0();

            switch (D_800DCE44) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 13:
                case 14:
                case 16:
                case 21:
                    if (D_800CD010 == 0) {
                        func_8007E08C();
                    }
                    break;
            }
            sp24 = 0;
            switch (D_800DCE44) {
                case 0x1:
                case 0x2:
                case 0x3:
                case 0x4:
                case 0x5:
                case 0xD:
                case 0x15:
                case 0x4009:
                case 0x4012:
                case 0x8008:
                    sp24 = 1;
                    break;
                case 0xE:
                    sp24 = 2;
                    break;
                case 0x6:
                    sp24 = 3;
                    break;
            }
            if (sp24 != 0) {
                // clang-format off
                osInvalICache(D_i9_80115DF0, D_i9_80168A70 - D_i9_80115DF0);\
                osInvalDCache(D_i9_80168A70, D_i9_80168CD0 - D_i9_80168A70);
                // clang-format on
                func_80076658(D_F2AC0, D_i9_80115DF0, D_1459A0 - D_F2AC0, D_i9_80168CD0, D_i9_80168CE0 - D_i9_80168CD0);
                switch (sp24) {
                    case 1:
                        func_8008D7E8();
                        break;
                    case 2:
                        func_i2_80100520(D_800F8514);
                        func_8008D8E8();
                        break;
                    case 3:
                        func_8008D824();
                        break;
                }
            }
            func_80077318();
            func_80079EC8();
            D_800CD04C[D_800DCE44 & 0x1F]();
            func_80068DCC();
            func_80077C9C();
            func_i2_800FC9BC();
            D_800CD044 = 0;
            break;
        case 5:
            func_i2_800FC77C();
            func_i2_800FCE3C();
            D_800CD044 = 6;
            break;
        case 6:
            if (func_i2_800FCE3C() != 0) {
                func_i2_800FC9BC();
                if (D_800DCE44 != 6) {
                    func_8007E08C();
                }
                func_80068DCC();
                func_80079F1C();
                func_i2_80103A70();
                D_800CD044 = 0;
            }
            break;
        case 0:
        default:
            break;
    }

    if (D_800CD168 != 0) {
        func_80069820();
        D_800CD168 = 0;
    }
    D_800DCE48 = D_800CD0A4[D_800DCE44 & 0x1F]();
    func_80068F04();
    switch (D_800CD044) {
        case 6:
            break;
        case 0:
            func_i2_800FCE3C();
            break;
    }
    if (D_800CD16C != 0) {
        osContStartReadData(&D_800DCA80);
        D_800CD168 = 1;
    }
}

extern s32 (*D_800CD0FC[])(void);
extern s16 D_80106DA0;

void func_80069698(s32 arg0) {

    if ((D_800CD044 != 3) && (D_80106DA0 != 0)) {
        arg0 = D_800CD0FC[D_800DCE44 & 0x1F]();
    }
    func_i2_800FD184(arg0);
}

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
