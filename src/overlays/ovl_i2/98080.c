#include "global.h"

typedef struct unk_8010D778 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    s16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
} unk_8010D778;

extern unk_8010D778 D_i2_8010D778;
extern s16 D_8010D770;
extern s16 D_i2_8010D774;
extern s16 D_i2_8010D7A8;
extern s16 D_i2_8010D7AA;

void func_i2_800FC730(void) {
    D_i2_8010D778.unk_04 = 0;
    D_i2_8010D778.unk_00 = 0;
    D_i2_8010D778.unk_08 = 0;
    D_i2_8010D778.unk_0C = 0;
    D_i2_8010D778.unk_0E = 0;
    D_i2_8010D778.unk_12 = 0;
    D_i2_8010D778.unk_14 = 0;
    D_i2_8010D778.unk_18 = 0;
    D_i2_8010D7A8 = 0;
    D_i2_8010D7AA = 0;
    D_8010D770 = 0;
    D_i2_8010D774 = 0;
}

s32 func_i2_800FCB84(s32, s32);
void func_i2_800FCD38(s32, s32);
s32 func_i2_800FCD4C(s32, s32);
extern s32 D_800CD000;
extern s16 D_800CD044;
extern s32 D_800DCE44;
extern s32 D_i2_80106DA4;

void func_i2_800FC77C(void) {
    D_i2_80106DA4 = 2;

    if (D_800CD044 == 0x1F) {
        func_i2_800FCB84(0, 10);
        return;
    }

    switch (D_800DCE44) {
        case 0x8000:
            func_i2_800FCB84(0, 7);
            break;
        case 0x11:
            func_i2_800FCD38(5, 120);
            func_i2_800FCB84(0, 5);
            break;
        case 0xD:
            func_i2_800FCB84(0, 10);
            break;
        case 0x800A:
            func_i2_800FCD38(5, 40);
            func_i2_800FCB84(0, 5);
            break;
        case 0x8008:
            if (D_800CD000 == 1) {
                func_i2_800FCB84(0, 10);
                break;
            }
            func_i2_800FCB84(0, 5);
            break;
        case 0x8007:
            if (D_800CD044 == 0x15) {
                func_i2_800FCB84(0, 10);
                break;
            }
            func_i2_800FCB84(0, 1);
            break;
        case 0x8013:
        case 0x8014:
            if (D_800CD044 == 0x15) {
                func_i2_800FCB84(0, 10);
                break;
            }
            func_i2_800FCD4C(0, 1);
            break;
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0xE:
        case 0x15:
            func_i2_800FCB84(0, 5);
            break;
        case 0x4009:
        case 0x4012:
            func_i2_800FCB84(0, 6);
            break;
        case 0x6:
            if (D_800CD044 != 0x15) {
                func_i2_800FCD4C(0, 1);
                break;
            }
            func_i2_800FCB84(0, 10);
            break;
        default:
            func_i2_800FCD4C(0, 1);
            break;
    }
}

extern unk_800DCE48 D_800DCE48;

void func_i2_800FC9BC(void) {
    D_i2_80106DA4 = 1;

    if (D_800CD044 == 0x21) {
        func_i2_800FCB84(1, 10);
        return;
    }

    switch (D_800DCE48.unk_00) {
        case 0x8000:
            func_i2_800FCB84(1, 1);
            break;
        case 0x11:
            func_i2_800FCB84(1, 5);
            break;
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0xE:
        case 0x15:
        case 0x8008:
            func_i2_800FCB84(1, 5);
            break;
        case 0xD:
            func_i2_800FCB84(1, 10);
            break;
        case 0x8013:
        case 0x8014:
            if (D_800CD044 == 0x17) {
                func_i2_800FCD38(9, 2);
                func_i2_800FCB84(1, 9);
                break;
            }
            func_i2_800FCD4C(1, 1);
            break;
        case 0x8007:
            if (D_800CD044 == 0x17) {
                func_i2_800FCD38(9, 3);
                func_i2_800FCB84(1, 9);
                break;
            }
            func_i2_800FCB84(1, 7);
            break;
        case 0x6:
            if (D_800CD044 != 0x17) {
                func_i2_800FCD4C(1, 1);
                break;
            }
            func_i2_800FCB84(1, 9);
            break;
        case 0x800C:
            func_i2_800FCD38(5, 60);
            func_i2_800FCB84(1, 5);
            break;
        default:
            func_i2_800FCD4C(1, 1);
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FCB84.s")

void func_i2_800FCD38(s32 arg0, s32 arg1) {
    D_i2_8010D7AA = arg0;
    D_i2_8010D7A8 = arg1;
}

extern s32 D_i2_8010AB60[];

s32 func_i2_800FCD4C(s32 arg0, s32 arg1) {
    s32 temp;
    u32 temp2;
    s32 var_v0;

    if (arg0 == 0) {
        temp = (func_8006A918() % 8);
        if (arg1 != 0) {
            if (temp < 2) {
                temp2 = func_8006A918();
                var_v0 = func_i2_800FCB84(arg0, D_i2_8010AB60[temp2 % 7]);
            } else {
                var_v0 = func_i2_800FCB84(arg0, 10);
            }
        } else {
            temp2 = func_8006A918();
            var_v0 = func_i2_800FCB84(arg0, D_i2_8010AB60[temp2 % 7]);
        }
    } else {
        temp2 = func_8006A918();
        var_v0 = func_i2_800FCB84(arg0, D_i2_8010AB60[temp2 % 7]);
    }
    return var_v0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FCE3C.s")

void func_i2_800FD4AC(unk_8010D778*);
void func_i2_800FDBDC(unk_8010D778*);
void func_i2_800FE13C(unk_8010D778*);
void func_i2_800FEED8(unk_8010D778*);
void func_i2_800FF7A8(unk_8010D778*, s32, s32);
void func_i2_800FF9C8(unk_8010D778*);
void func_i2_800FFC68(unk_8010D778*);
void func_i2_80100220(unk_8010D778*);

void func_i2_800FCF48(unk_8010D778* arg0) {
    s16 temp_t2;
    s32 temp_at;
    s32 temp_t6;
    u32 temp_t9;

    arg0->unk_00 = arg0->unk_04;
    arg0->unk_04 = 0;
    arg0->unk_0C = 0;
    arg0->unk_12 = 2;

    switch (arg0->unk_00 - 1) {
        case 9:

            arg0->unk_12 &= ~0x2;
            arg0->unk_12 |= 8;
            break;
        case 0:
            if (arg0->unk_10 != 0) {
                arg0->unk_08 = 3;
            } else {
                arg0->unk_08 = 1;
            }
            func_i2_800FD4AC(arg0);
            break;
        case 1:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FDBDC(arg0);
            break;
        case 2:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FE13C(arg0);
            break;
        case 3:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FEED8(arg0);
            break;
        case 4:
        case 5:
            if (arg0->unk_10 != 0) {
                arg0->unk_08 = 3;
                func_i2_800FF7A8(arg0, 255, 20);
            } else {
                arg0->unk_08 = 1;
                func_i2_800FF7A8(arg0, 0, 20);
            }
            break;
        case 8:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FF9C8(arg0);
            break;
        case 6:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_800FFC68(arg0);
            break;
        case 7:
            if (arg0->unk_10 == 0) {
                arg0->unk_12 |= 4;
            }
            arg0->unk_08 = 1;
            func_i2_80100220(arg0);
            break;
    }

    if (arg0->unk_10 == 0) {
        if (arg0->unk_12 & 4) {
            D_i2_8010D774 = 1;
            return;
        }
        D_i2_8010D774 = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FD184.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FD344.s")

void func_i2_800FD978(unk_8010D778* arg0, s32 arg1, s8 arg2);

void func_i2_800FD4AC(unk_8010D778* arg0) {
    s32 i;
    u8* ptr = arg0->unk_18;
    s32 temp;
    s32 temp2;

    for (i = 0; i < 0x818; i++) {
        *ptr++ = 0;
    }

    for (i = 0; i < 5; i++) {
        temp = func_8006A918() % 74;
        temp2 = func_8006A918() % 56;
        func_i2_800FD978(arg0, (temp2 * 74) + temp, 1);
    }
}

bool func_i2_800FD638(unk_8010D778* arg0);

void func_i2_800FD58C(unk_8010D778* arg0) {

    switch (arg0->unk_08) {
        case 1:
            if (func_i2_800FD638(arg0) != 0) {
                arg0->unk_08 = 2;
                arg0->unk_0C = 0;
            }
            break;
        case 2:
            arg0->unk_0C += 1;
            if (arg0->unk_0C >= 3) {
                arg0->unk_08 = 4;
            }
            break;
        case 3:
            if (func_i2_800FD638(arg0) != 0) {
                arg0->unk_08 = 4;
            }
            break;
        case 4:
            arg0->unk_12 |= 8;
            break;
        case 0:
        default:
            break;
    }
}

extern s16 D_i2_80106DA8[];
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FD638.s")

s8 func_i2_800FD938(unk_8010D778* arg0, s32 arg1);

s32 func_i2_800FD840(unk_8010D778* arg0, s32 arg1, bool* arg2) {
    s32 var_a1;
    s32 i;
    s32 var_s3 = 0;
    s16* var_s1 = D_i2_80106DA8;

    for (i = 0; i < 8; i++) {
        var_a1 = (*var_s1 % 2072) + arg1;
        if (var_a1 < 0) {
            var_a1 += 0x818;
        }
        if (func_i2_800FD938(arg0, var_a1) == 0) {
            var_s3++;
            arg2[i] = true;
        } else {
            arg2[i] = false;
        }
        var_s1++;
    }
    return var_s3;
}

s8 func_i2_800FD938(unk_8010D778* arg0, s32 arg1) {
    s8* temp_v0 = arg0->unk_18 + (arg1 >> 1);
    s8 ret;

    if (arg1 & 1) {
        ret = (*temp_v0 & 0xF);
    } else {
        ret = (*temp_v0 >> 4);
    }
    return ret;
}

void func_i2_800FD978(unk_8010D778* arg0, s32 arg1, s8 arg2) {
    s8* temp_v0 = arg0->unk_18 + (arg1 >> 1);

    if (arg1 & 1) {
        *temp_v0 = (*temp_v0 & 0xF0) | arg2;
    } else {
        *temp_v0 = (*temp_v0 & 0xF) | (arg2 << 4);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FD9C8.s")

void func_i2_800FDBDC(unk_8010D778* arg0) {
    s32 i;
    u8* var_v1;

    arg0->unk_1C = 0x40;
    arg0->unk_12 |= 1;

    for (i = 0, var_v1 = arg0->unk_18; i < 0x40; i++) {
        *var_v1++ = 0;
        *var_v1++ = -1;
    }
}

bool func_i2_800FDC98(unk_8010D778*);

void func_i2_800FDC30(unk_8010D778* arg0) {
    switch (arg0->unk_08) {
        case 0:
            break;
        case 1:
            if (func_i2_800FDC98(arg0)) {
                arg0->unk_08 = 2;
            }
            break;
        case 2:
            arg0->unk_12 |= 8;
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FDC98.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FDE84.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FE13C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FE4E4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FE6F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FEB2C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FEED8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FF284.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FF494.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FF7A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FF7D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FF91C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FF9C8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFA34.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFBF4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFC68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFCAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFD4C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_800FFEEC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_80100220.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_80100248.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_801002E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/func_i2_8010034C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/98080/D_i2_8010AB60.s")
