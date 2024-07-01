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
    s8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0A;
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

// BAD RETURN
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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/11CF0/func_80078EA0.s")

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
            func_8011B06C(var_s0);
            break;
        case 0xE:
            func_8011B0C8();
            break;
        case 0xF:
            func_8011B0D0(var_s0);
            break;
        case 0x10:
            func_8011B134();
            break;
        case 0x11:
            func_8011B13C(var_s0);
            break;
        case 0x12:
            func_8011B1E4();
            break;
        case 0x13:
            func_8011B1EC();
            break;
        case 0x14:
            func_8011B214(var_s0);
            break;
        case 0x1F:
            func_80116E64();
            break;
        case 0x20:
            func_80116E8C(var_s0);
            break;
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            func_80116F48(var_s0);
            break;
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            func_80117008(var_s0);
            break;
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            func_80117038(var_s0);
            break;
        case 0x2C:
            func_8011706C();
            break;
        case 0x2D:
            func_80117094(var_s0);
            break;
        case 0x35:
            func_80117400(var_s0);
            break;
        case 0x33:
            func_8011764C();
            break;
        case 0x34:
            func_801176BC();
            break;
        case 0x36:
            func_8011770C(var_s0);
            break;
        case 0x37:
            func_8011774C();
            break;
        case 0x2E:
            func_80117854(var_s0);
            break;
        case 0x39:
            func_8011788C(var_s0);
            break;
        case 0x2F:
            func_80117774(var_s0);
            break;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
            func_80117808();
            break;
        case 0x50:
            func_801167EC(var_s0);
            break;
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
            func_80116894(var_s0);
            break;
        case 0x59:
            func_801168EC(var_s0);
            break;
        case 0x5A:
            func_80116934();
            break;
        case 0x5C:
            func_80116990();
            break;
        case 0x5F:
            func_801169EC();
            break;
        case 0x5D:
            func_80116A48(var_s0);
            break;
        case 0x5E:
            func_80116A80(var_s0);
            break;
        case 0x78:
            func_80117684(var_s0);
            break;
        case 0x79:
            func_80117758();
            break;
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
            func_801177EC(var_s0);
            break;
        case 0x83:
            func_801178D8(var_s0);
            break;
        case 0x80:
            func_80117934(var_s0);
            break;
        case 0x81:
            func_8011796C(var_s0);
            break;
        case 0x84:
            func_801179A8(var_s0);
            break;
        case 0x85:
            func_80117A2C(var_s0);
            break;
        default:
            break;
    }
}

unk_800E3A28* func_8007AB88(unk_800E3A28*);
unk_800E3A28* func_8007ABA4(unk_800E3A28*);
unk_800E3A28* func_8007AC48(unk_800E3A28*, s32, s32, s32);
unk_800E3A28* func_8007AE70(unk_800E3A28*);
unk_800E3A28* func_8007AE8C(unk_800E3A28*, s32, s32, s32, s32, s32, s32, s32, s32);
unk_800E3A28* func_8007AF40(unk_800E3A28*, s32, s32, s32, s32, s32, s32, s32, s32);

unk_800E3A28* func_800797CC(unk_800E3A28* arg0, unk_800E3A28* arg1) {

    if (arg1->unk_15 == 0) {
        return arg0;
    }

    switch (arg1->unk_00) {
        case 0:
            break;
        case 0x5:
            arg0 = func_8007ABA4(func_8007AE70(func_8007AB88(arg0)));
            break;
        case 0xA:
            arg0 = func_8011B380(arg0);
            break;
        case 0xE:
            arg0 = func_8011B3DC(arg0);
            break;
        case 0xC:
            arg0 = func_8007AF40(arg0, 0x76, 0xA4, 0xCB, 0xD9, 0xFF, 0xFF, 0xFF, 0x30);
            break;
        case 0xD:
            arg0 = func_8007AE8C(arg0, 0xC, 8, 0x133, 0xE7, 0, 0, 0, 0);
            break;
        case 0xF:
            arg0 = func_8011B3E8(arg0);
            break;
        case 0x10:
            arg0 = func_8011B438(arg0);
            break;
        case 0x11:
            arg0 = func_8011B444(arg0);
            break;
        case 0x12:
            arg0 = func_8011B668(arg0);
            break;
        case 0x13:
            arg0 = func_8011B674(arg0);
            break;
        case 0x14:
            arg0 = func_8011B6C4(arg0);
            break;
        case 0x1E:
            arg0 = func_801178C4(arg0);
            break;
        case 0x3B:
            arg0 = func_8007AC48(arg0, 0x18, 0x18, 0x18);
            break;
        case 0x1F:
            arg0 = func_80117B74(arg0);
            break;
        case 0x20:
            arg0 = func_80117BE0(arg0);
            break;
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            arg0 = func_80117D10(arg0);
            break;
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            arg0 = func_801180EC(arg0);
            break;
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            arg0 = func_801181C0(arg0);
            break;
        case 0x2C:
            arg0 = func_8011821C(arg0);
            break;
        case 0x2D:
            arg0 = func_80118414(arg0);
            break;
        case 0x2E:
            arg0 = func_80118734(arg0);
            break;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
            arg0 = func_80117E98(arg0);
            break;
        case 0x35:
            arg0 = func_80118918(arg0);
            break;
        case 0x32:
            arg0 = func_801187C0(arg0);
            break;
        case 0x33:
            arg0 = func_80118EC8(arg0);
            break;
        case 0x34:
            arg0 = func_80119170(arg0);
            break;
        case 0x3A:
            arg0 = func_801193B8(arg0);
            break;
        case 0x36:
            arg0 = func_801194F8(arg0);
            break;
        case 0x37:
            arg0 = func_80119574(arg0);
            break;
        case 0x38:
            arg0 = func_801197A0(arg0);
            break;
        case 0x39:
            arg0 = func_80119B50(arg0);
            break;
        case 0x2F:
            arg0 = func_80119834(arg0);
            break;
        case 0x30:
            arg0 = func_80119A64(arg0);
            break;
        case 0x50:
            arg0 = func_80116C78(arg0);
            break;
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
            arg0 = func_80116AA8(arg0);
            break;
        case 0x59:
            arg0 = func_80117400(arg0);
            break;
        case 0x5A:
            arg0 = func_801174DC(arg0);
            break;
        case 0x5C:
            arg0 = func_80117760(arg0);
            break;
        case 0x5F:
            arg0 = func_80117A18(arg0);
            break;
        case 0x5D:
            arg0 = func_80117C50(arg0);
            break;
        case 0x64:
        case 0x8C:
            arg0 = func_8007AC48(arg0, 0, 0, 0);
            break;
        case 0x78:
            arg0 = func_80117A98(arg0);
            break;
        case 0x79:
            arg0 = func_80117BE0(arg0);
            break;
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
            arg0 = func_80117C48(arg0);
            break;
        case 0x83:
            arg0 = func_80117FB4(arg0);
            break;
        case 0x80:
            arg0 = func_80118100(arg0);
            break;
        case 0x81:
            arg0 = func_80118168(arg0);
            break;
        case 0x82:
            arg0 = func_801182DC(arg0);
            break;
        case 0x84:
            arg0 = func_80118674(arg0);
            break;
        case 0x85:
            arg0 = func_80118790(arg0);
            break;
    }
    return arg0;
}

unk_800E3A28* func_80079BC8(unk_800E3A28* arg0) {
    s32 i;
    s32 j;

    for (i = 0; i < 32; i++) {
        switch (D_800E3A28[i].unk_00) {
            case 0:
                break;
            case 0xA:
                func_8011B2E0(&D_800E3A28[i]);
                break;
            case 0x14:
                func_8011B874(&D_800E3A28[i]);
                break;
            case 0x5D:
                func_80117D3C(&D_800E3A28[i]);
                break;
            case 0x5E:
                func_80117DE0(&D_800E3A28[i]);
                break;
            case 0x20:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_80119BB8(&D_800E3A28[i]);
                break;
            case 0x3C:
            case 0x3D:
            case 0x3E:
            case 0x3F:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_80119BC0(&D_800E3A28[i]);
                break;
            case 0x21:
            case 0x22:
            case 0x23:
            case 0x24:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_80119C80(&D_800E3A28[i]);
                break;
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
                func_80119D0C(&D_800E3A28[i]);
                break;
            case 0x2C:
                func_80119D84(&D_800E3A28[i]);
                break;
            case 0x2D:
                func_80119D8C(&D_800E3A28[i]);
                break;
            case 0x35:
                func_8011A08C(&D_800E3A28[i]);
                break;
            case 0x36:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_8011A73C(&D_800E3A28[i]);
                break;
            case 0x2E:
                func_8011A6A0(&D_800E3A28[i]);
                break;
            case 0x39:
                func_8011A6EC(&D_800E3A28[i]);
                break;
            case 0x79:
                func_80118928(&D_800E3A28[i]);
                break;
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
                func_801189C4(&D_800E3A28[i]);
                break;
            case 0x80:
                func_80118D44(&D_800E3A28[i]);
                break;
            case 0x81:
                func_80118D94(&D_800E3A28[i]);
                break;
            case 0x84:
                func_80118F24(&D_800E3A28[i]);
                break;
            case 0x85:
                func_80118F84(&D_800E3A28[i]);
                break;
        }
    }

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 32; i++) {
            if (j == D_800E3A28[i].unk_14) {
                arg0 = func_800797CC(arg0, &D_800E3A28[i]);
            }
        }
    }

    return arg0;
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
