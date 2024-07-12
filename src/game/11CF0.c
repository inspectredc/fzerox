#include "global.h"

extern u8 D_2B9EA0[];

void func_80077CF0(s32 arg0, s32 arg1, void* arg2) {
    osInvalDCache(arg2, arg1);
    func_800765CC(D_2B9EA0 + (arg0 & 0xFFFFFF), arg2, arg1);
}

extern s32 D_800E3A20;

void func_80077D44(void) {
    D_800E3A20 = 0;
}

typedef struct unk_800E33E0 {
    s32 unk_00;
    s32 unk_04;
} unk_800E33E0; // size = 0x8
extern unk_800E33E0 D_800E33E0[];

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/11CF0/func_80077D50.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/11CF0/func_80078104.s")

extern s32 D_800E3A20;

s32 func_800783AC(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800E3A20; i++) {
        if (arg0 == D_800E33E0[i].unk_00) {
            return D_800E33E0[i].unk_04;
        }
    }
    return 0;
}

typedef struct unk_800783F4_arg_1 {
    s16 unk_00;
    s8 unk_02[0x2];
    s32 unk_04;
    u16 unk_08;
    u16 unk_0A;
    s8 unk_0C[0x4];
} unk_800783F4_arg_1;
void* func_8007B14C(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, s32 arg6, s32 arg7, s32 arg8,
                    s32 arg9, s32 argA, s32 argB);

void func_800783F4(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4) {

    switch (arg1->unk_00) {
        case 3:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 3, 1, 2, 0, 0, 0);
            break;
        case 4:
        case 20:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 4, 0, 3, 0, 0, 0);
            break;
        case 5:
        case 21:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 4, 0, 3, 1, 0, 0);
            break;
        case 2:
        case 18:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 0, 1, 0, 0);
            break;
        case 1:
        default:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 0, 0, 0, 0);
            break;
    }
}

void func_8007857C(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4) {

    switch (arg1->unk_00) {
        case 3:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 3, 1, 2, 0, 0, 0);
            break;
        case 4:
        case 20:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 4, 0, 3, 0, 0, 0);
            break;
        case 5:
        case 21:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 4, 0, 3, 1, 0, 0);
            break;
        case 2:
        case 18:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 1, 1, 0, 0);
            break;
        case 1:
        default:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 1, 0, 0, 0);
            break;
    }
}

void func_8007870C(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 3, 1, 2, 0, 0, 0);
            break;
        case 4:
        case 20:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 4, 0, 3, 0, 0, 0);
            break;
        case 5:
        case 21:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 4, 0, 3, 1, 0, 0);
            break;
        case 2:
        case 18:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 0, 1, arg5, arg6);
            break;
        case 1:
        default:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 0, 0, arg5, arg6);
            break;
    }
}

void* func_8007CDB0(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, f32 arg6, f32 arg7, s32 arg8,
                    s32 arg9, s32 argA, s32 argB, s32 argC);

void func_800788A4(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 3, 1, 2, 0, 0, 0);
            break;
        case 4:
        case 20:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 4, 0, 3, 0, 0);
            break;
        case 5:
        case 21:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 4, 0, 3, 0, 0);
            break;
        case 2:
        case 18:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 0, 1, 0, 0);
            break;
        case 1:
        default:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 0, 2, 0, 0, 0);
            break;
    }
}

void func_80078A4C(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 3, 1, 2, 0, 0, 0);
            break;
        case 4:
        case 20:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 4, 0, 3, 0, 0);
            break;
        case 5:
        case 21:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 4, 0, 3, 0, 0);
            break;
        case 2:
        case 18:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 0, 2, 0, 1, 0, 0);
            break;
        case 1:
        default:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 0, 2, 0, 0, 1);
            break;
    }
}

void func_80078BF8(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            func_8007B14C(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, 3, 1, 2, 0, 0, 0);
            break;
        case 4:
        case 20:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 4, 0, 3, 0, 0);
            break;
        case 5:
        case 21:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 4, 0, 3, 0, 0);
            break;
        case 2:
        case 18:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 0, 2, 1, 1, 0);
            break;
        case 1:
        default:
            func_8007CDB0(arg0, arg4, arg2, arg3, arg1->unk_08, arg1->unk_0A, arg5, arg6, 0, 2, 1, 0, 0);
            break;
    }
}

// BAD RETURN: (TODO: This should still return the outputs of the functions in the switch cases)
void* func_80078DB4(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, s32 arg6, s32 arg7,
                    f32 arg8, f32 arg9) {
    switch (arg5) {
        case 0:
            func_800783F4(arg0, arg1, arg2, arg3, arg4);
            break;
        case 1:
            func_8007857C(arg0, arg1, arg2, arg3, arg4);
            break;
        case 2:
            func_8007870C(arg0, arg1, arg2, arg3, arg4, arg6, arg7);
            break;
        case 3:
            func_800788A4(arg0, arg1, arg2, arg3, arg4, arg8, arg9);
            break;
        case 5:
            func_80078A4C(arg0, arg1, arg2, arg3, arg4, arg8, arg9);
            break;
        case 4:
            func_80078BF8(arg0, arg1, arg2, arg3, arg4, arg8, arg9);
            break;
        default:
            break;
    }
}

void* func_80078EA0(void* arg0, unk_800783F4_arg_1* arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8) {
    s32 temp_v0;

    while (arg1->unk_04 != 0) {
        // FAKE
        if (arg0) {}

        temp_v0 = func_800783AC(arg1->unk_04);
        if (temp_v0 != 0) {
            arg0 = func_80078DB4(arg0, arg1, arg2, arg3, temp_v0, arg4, arg5, arg6, arg7, arg8);
        }
        arg1++;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/11CF0/func_80078F80.s")

extern unk_800E33E0 D_800E4068[];

void func_80079080(void) {
    s32 i;

    D_800E4068[0].unk_00 = 0;

    for (i = 1; i < 17; i++) {}
}

void func_800790A4(s32 arg0, s32 arg1) {
    unk_800E33E0* var_v0;

    var_v0 = D_800E4068;
    while (var_v0->unk_00 != 0) {
        var_v0++;
    }
    var_v0->unk_00 = arg0;
    var_v0->unk_04 = arg1;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/11CF0/func_800790D4.s")

typedef struct unk_800E3F28 {
    void* unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s32 unk_0C;
    s32 unk_10;
} unk_800E3F28; // size = 0x14

extern unk_800E3F28 D_800E3F28[];

void func_800792A8(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800E3F28[i].unk_08 = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/11CF0/func_800792D8.s")

typedef struct unk_800793E8_arg_2 {
    s32 unk_00;
    s32 unk_04;
} unk_800793E8_arg_2;

// TODO: FAKE
void func_800793E8(s32 arg0, s32 arg1, unk_800793E8_arg_2* arg2) {
    unk_800E3F28* sp1C;
    s32 temp_a3;

    D_800E3F28[arg0].unk_04 = arg1;
    D_800E3F28[arg0].unk_00 = arg2;
    D_800E3F28[arg0].unk_06 = (*(unk_800793E8_arg_2*) (arg2 + arg1)).unk_04;
    temp_a3 = arg2[D_800E3F28[arg0].unk_04].unk_00;

    if (D_800E3F28[arg0].unk_0A != 0) {
        func_800790A4(temp_a3, D_800E3F28[arg0].unk_0C);
        D_800E3F28[arg0].unk_0A = 0;
    } else {
        func_800790A4(temp_a3, D_800E3F28[arg0].unk_10);
        D_800E3F28[arg0].unk_0A = 1;
    }
}

extern unk_800E3A28 D_800E3A28[];

void func_80079480(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        D_800E3A28[i].unk_00 = 0;
    }
}

void func_800794B0(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 i = 0;
    unk_800E3A28* var_s0 = D_800E3A28;

    while (true) {
        i++;
        // clang-format off
        if (var_s0->unk_00 == 0) {   \
            var_s0->unk_00 = arg0;   \
            var_s0->unk_04 = 0;      \
            var_s0->unk_08 = 0;      \
            var_s0->unk_0C = arg1;   \
            var_s0->unk_10 = arg2;   \
            var_s0->unk_14 = arg3;   \
            var_s0->unk_15 = 1;      \
            var_s0->unk_1C = 0;      \
            var_s0->unk_20 = 0;      \
            break;
        } else if (i > 0x20) {
            return;
        }
        // clang-format on
        var_s0++;
    }

    switch (arg0) {
        case 0xA:
            func_i4_8011B06C(var_s0);
            break;
        case 0xE:
            func_i4_8011B0C8();
            break;
        case 0xF:
            func_i4_8011B0D0(var_s0);
            break;
        case 0x10:
            func_i4_8011B134();
            break;
        case 0x11:
            func_i4_8011B13C(var_s0);
            break;
        case 0x12:
            func_i4_8011B1E4();
            break;
        case 0x13:
            func_i4_8011B1EC();
            break;
        case 0x14:
            func_i4_8011B214(var_s0);
            break;
        case 0x1F:
            func_i4_80116E64();
            break;
        case 0x20:
            func_i4_80116E8C(var_s0);
            break;
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            func_i4_80116F48(var_s0);
            break;
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            func_i4_80117008(var_s0);
            break;
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            func_i4_80117038(var_s0);
            break;
        case 0x2C:
            func_i4_8011706C();
            break;
        case 0x2D:
            func_i4_80117094(var_s0);
            break;
        case 0x35:
            func_i4_80117400(var_s0);
            break;
        case 0x33:
            func_i4_8011764C();
            break;
        case 0x34:
            func_i4_801176BC();
            break;
        case 0x36:
            func_i4_8011770C(var_s0);
            break;
        case 0x37:
            func_i4_8011774C();
            break;
        case 0x2E:
            func_i4_80117854(var_s0);
            break;
        case 0x39:
            func_i4_8011788C(var_s0);
            break;
        case 0x2F:
            func_i4_80117774(var_s0);
            break;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
            func_i4_80117808();
            break;
        case 0x50:
            func_i6_801167EC(var_s0);
            break;
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
            func_i6_80116894(var_s0);
            break;
        case 0x59:
            func_i6_801168EC(var_s0);
            break;
        case 0x5A:
            func_i6_80116934();
            break;
        case 0x5C:
            func_i6_80116990();
            break;
        case 0x5F:
            func_i6_801169EC();
            break;
        case 0x5D:
            func_i6_80116A48(var_s0);
            break;
        case 0x5E:
            func_i6_80116A80(var_s0);
            break;
        case 0x78:
            func_i5_80117684(var_s0);
            break;
        case 0x79:
            func_i5_80117758();
            break;
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
            func_i5_801177EC(var_s0);
            break;
        case 0x83:
            func_i5_801178D8(var_s0);
            break;
        case 0x80:
            func_i5_80117934(var_s0);
            break;
        case 0x81:
            func_i5_8011796C(var_s0);
            break;
        case 0x84:
            func_i5_801179A8(var_s0);
            break;
        case 0x85:
            func_i5_80117A2C(var_s0);
            break;
        default:
            break;
    }
}

Gfx* func_800797CC(Gfx* gfx, unk_800E3A28* arg1) {

    if (arg1->unk_15 == 0) {
        return gfx;
    }

    switch (arg1->unk_00) {
        case 0:
            break;
        case 0x5:
            gfx = func_8007ABA4(func_8007AE70(func_8007AB88(gfx)));
            break;
        case 0xA:
            gfx = func_i4_8011B380(gfx);
            break;
        case 0xE:
            gfx = func_i4_8011B3DC(gfx);
            break;
        case 0xC:
            gfx = func_8007AF40(gfx, 118, 164, 203, 217, 255, 255, 255, 48);
            break;
        case 0xD:
            gfx = func_8007AE8C(gfx, 12, 8, 307, 231, 0, 0, 0, 0);
            break;
        case 0xF:
            gfx = func_i4_8011B3E8(gfx);
            break;
        case 0x10:
            gfx = func_i4_8011B438(gfx);
            break;
        case 0x11:
            gfx = func_i4_8011B444(gfx);
            break;
        case 0x12:
            gfx = func_i4_8011B668(gfx);
            break;
        case 0x13:
            gfx = func_i4_8011B674(gfx);
            break;
        case 0x14:
            gfx = func_i4_8011B6C4(gfx);
            break;
        case 0x1E:
            gfx = func_i4_801178C4(gfx);
            break;
        case 0x3B:
            gfx = func_8007AC48(gfx, 0x18, 0x18, 0x18);
            break;
        case 0x1F:
            gfx = func_i4_80117B74(gfx);
            break;
        case 0x20:
            gfx = func_i4_80117BE0(gfx, arg1);
            break;
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            gfx = func_i4_80117D10(gfx);
            break;
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            gfx = func_i4_801180EC(gfx);
            break;
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            gfx = func_i4_801181C0(gfx);
            break;
        case 0x2C:
            gfx = func_i4_8011821C(gfx);
            break;
        case 0x2D:
            gfx = func_i4_80118414(gfx);
            break;
        case 0x2E:
            gfx = func_i4_80118734(gfx);
            break;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
            gfx = func_i4_80117E98(gfx);
            break;
        case 0x35:
            gfx = func_i4_80118918(gfx);
            break;
        case 0x32:
            gfx = func_i4_801187C0(gfx);
            break;
        case 0x33:
            gfx = func_i4_80118EC8(gfx);
            break;
        case 0x34:
            gfx = func_i4_80119170(gfx);
            break;
        case 0x3A:
            gfx = func_i4_801193B8(gfx);
            break;
        case 0x36:
            gfx = func_i4_801194F8(gfx);
            break;
        case 0x37:
            gfx = func_i4_80119574(gfx);
            break;
        case 0x38:
            gfx = func_i4_801197A0(gfx);
            break;
        case 0x39:
            gfx = func_i4_80119B50(gfx);
            break;
        case 0x2F:
            gfx = func_i4_80119834(gfx);
            break;
        case 0x30:
            gfx = func_i4_80119A64(gfx);
            break;
        case 0x50:
            gfx = func_i6_80116C78(gfx);
            break;
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
            gfx = func_i6_80116AA8(gfx);
            break;
        case 0x59:
            gfx = func_i6_80117400(gfx);
            break;
        case 0x5A:
            gfx = func_i6_801174DC(gfx);
            break;
        case 0x5C:
            gfx = func_i6_80117760(gfx);
            break;
        case 0x5F:
            gfx = func_i6_80117A18(gfx);
            break;
        case 0x5D:
            gfx = func_i6_80117C50(gfx);
            break;
        case 0x64:
        case 0x8C:
            gfx = func_8007AC48(gfx, 0, 0, 0);
            break;
        case 0x78:
            gfx = func_i5_80117A98(gfx);
            break;
        case 0x79:
            gfx = func_i5_80117BE0(gfx, arg1);
            break;
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
            gfx = func_i5_80117C48(gfx);
            break;
        case 0x83:
            gfx = func_i5_80117FB4(gfx);
            break;
        case 0x80:
            gfx = func_i5_80118100(gfx);
            break;
        case 0x81:
            gfx = func_i5_80118168(gfx);
            break;
        case 0x82:
            gfx = func_i5_801182DC(gfx);
            break;
        case 0x84:
            gfx = func_i5_80118674(gfx);
            break;
        case 0x85:
            gfx = func_i5_80118790(gfx);
            break;
    }
    return gfx;
}

Gfx* func_80079BC8(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 32; i++) {
        switch (D_800E3A28[i].unk_00) {
            case 0:
                break;
            case 0xA:
                func_i4_8011B2E0(&D_800E3A28[i]);
                break;
            case 0x14:
                func_i4_8011B874(&D_800E3A28[i]);
                break;
            case 0x5D:
                func_i6_80117D3C(&D_800E3A28[i]);
                break;
            case 0x5E:
                func_i6_80117DE0(&D_800E3A28[i]);
                break;
            case 0x20:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_80119BB8(&D_800E3A28[i]);
                break;
            case 0x3C:
            case 0x3D:
            case 0x3E:
            case 0x3F:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_80119BC0(&D_800E3A28[i]);
                break;
            case 0x21:
            case 0x22:
            case 0x23:
            case 0x24:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_80119C80(&D_800E3A28[i]);
                break;
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
                func_i4_80119D0C(&D_800E3A28[i]);
                break;
            case 0x2C:
                func_i4_80119D84(&D_800E3A28[i]);
                break;
            case 0x2D:
                func_i4_80119D8C(&D_800E3A28[i]);
                break;
            case 0x35:
                func_i4_8011A08C(&D_800E3A28[i]);
                break;
            case 0x36:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_8011A73C(&D_800E3A28[i]);
                break;
            case 0x2E:
                func_i4_8011A6A0(&D_800E3A28[i]);
                break;
            case 0x39:
                func_i4_8011A6EC(&D_800E3A28[i]);
                break;
            case 0x79:
                func_i5_80118928(&D_800E3A28[i]);
                break;
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
                func_i5_801189C4(&D_800E3A28[i]);
                break;
            case 0x80:
                func_i5_80118D44(&D_800E3A28[i]);
                break;
            case 0x81:
                func_i5_80118D94(&D_800E3A28[i]);
                break;
            case 0x84:
                func_i5_80118F24(&D_800E3A28[i]);
                break;
            case 0x85:
                func_i5_80118F84(&D_800E3A28[i]);
                break;
        }
    }

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 32; i++) {
            if (j == D_800E3A28[i].unk_14) {
                gfx = func_800797CC(gfx, &D_800E3A28[i]);
            }
        }
    }

    return gfx;
}

// Todo: figure out a way to stop pointer comparison (use index comparison instead)
unk_800E3A28* func_80079E88(s32 arg0) {
    unk_800E3A28* var_v1;

    var_v1 = D_800E3A28;

    while (true) {
        if (arg0 == var_v1->unk_00) {
            break;
        }
        var_v1++;
        if ((u32) D_800E3F28 < (u32) var_v1) {
            return NULL;
        }
    }
    return var_v1;
}

extern s32 D_800DCE44;

void func_80079EC8(void) {
    func_80077D44();
    func_80079480();
    func_800792A8();
    func_80079080();
    if (D_800DCE44 != 16) {
        func_8007E2B4();
    }
}

void func_80079F1C(void) {
    func_80079480();
    func_800792A8();
    func_80079080();
    func_8007E2B4();
}

typedef struct unk_80079F54_arg_0 {
    s8 unk_00[0xC];
    s32 unk_0C;
    s32 unk_10;
} unk_80079F54_arg_0;

void func_80079F54(unk_80079F54_arg_0* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_0C;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= arg2;
            if (++var_v0 > 8) {
                var_v0 = 8;
            }
        } else {
            var_v0 /= arg2;
            if (--var_v0 < -8) {
                var_v0 = -8;
            }
        }
    }
    arg0->unk_0C += var_v0;
}

void func_80079FFC(unk_80079F54_arg_0* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_10;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (++var_v0 > 16) {
                var_v0 = 16;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -16) {
                var_v0 = -16;
            }
        }
    }
    arg0->unk_10 += var_v0;
}

void func_8007A06C(unk_80079F54_arg_0* arg0, s32 arg1, s32 arg2) {
    func_80079F54(arg0, arg1, 4);
    func_80079FFC(arg0, arg2);
}

void func_8007A0A0(unk_80079F54_arg_0* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_0C;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (arg2 < ++var_v0) {
                var_v0 = arg2;
            }
            if (var_v0 < 8) {
                var_v0 = 8;
            }
            arg0->unk_0C += var_v0;

            if (arg1 < arg0->unk_0C) {
                arg0->unk_0C = arg1;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -arg2) {
                var_v0 = -arg2;
            }
            if (var_v0 > -8) {
                var_v0 = -8;
            }
            arg0->unk_0C += var_v0;

            if (arg0->unk_0C < arg1) {
                arg0->unk_0C = arg1;
            }
        }
    }
}

void func_8007A154(unk_80079F54_arg_0* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_10;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (++var_v0 > 0xC0) {
                var_v0 = 0xC0;
            }
            if (var_v0 < 8) {
                var_v0 = 8;
            }
            arg0->unk_10 += var_v0;

            if (arg1 < arg0->unk_10) {
                arg0->unk_10 = arg1;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -0xC0) {
                var_v0 = -0xC0;
            }
            if (var_v0 >= -7) {
                var_v0 = -8;
            }
            arg0->unk_10 += var_v0;

            if (arg0->unk_10 < arg1) {
                arg0->unk_10 = arg1;
            }
        }
    }
}

void func_8007A208(unk_80079F54_arg_0* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_10;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (++var_v0 > 0x10) {
                var_v0 = 0x10;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -0x10) {
                var_v0 = -0x10;
            }
        }
    }
    arg0->unk_10 += var_v0;
}

void func_8007A278(unk_80079F54_arg_0* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_0C;
    if (var_v0 != 0) {
        var_v0 = 0xC8 / var_v0;
        if (var_v0 > 0) {
            if (var_v0 > 0x18) {
                var_v0 = 0x18;
            }
            if (var_v0 < 0x10) {
                var_v0 = 0x10;
            }
            arg0->unk_0C += var_v0;

            if (arg1 < arg0->unk_0C) {
                arg0->unk_0C = arg1;
            }
        } else {
            if (var_v0 < -0x18) {
                var_v0 = -0x18;
            }
            if (var_v0 > -0x10) {
                var_v0 = -0x10;
            }
            arg0->unk_0C += var_v0;

            if (arg0->unk_0C < arg1) {
                arg0->unk_0C = arg1;
            }
        }
    }
}

void func_8007A334(unk_80079F54_arg_0* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 temp = arg0->unk_0C;
    s32 var_v1;

    var_v1 = arg1 - arg0->unk_0C;
    if (arg1 == arg0->unk_0C) {
        arg0->unk_0C += arg2;
        return;
    }
    if (var_v1 != 0) {
        if (var_v1 > 0) {
            var_v1 /= 8;
            if (++var_v1 > 0x10) {
                var_v1 = 0x10;
            }
        } else {
            var_v1 /= 8;
            if (--var_v1 < -0x10) {
                var_v1 = -0x10;
            }
        }
    }
    arg0->unk_0C -= var_v1;
}

void func_8007A3B8(unk_80079F54_arg_0* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 temp = arg0->unk_10;
    s32 var_v1;

    var_v1 = arg1 - arg0->unk_10;
    if (arg1 == arg0->unk_10) {
        arg0->unk_10 += arg2;
        return;
    }
    if (var_v1 != 0) {
        if (var_v1 > 0) {
            var_v1 /= 8;
            if (++var_v1 > 0x10) {
                var_v1 = 0x10;
            }
        } else {
            var_v1 /= 8;
            if (--var_v1 < -0x10) {
                var_v1 = -0x10;
            }
        }
    }
    arg0->unk_10 -= var_v1;
}
