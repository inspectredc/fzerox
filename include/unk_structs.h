#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "fzxmath.h"

typedef struct unk_8006FC8C {
    f32 unk_00;
    s8 unk_04[0x4];
    f32 unk_08;
    Vec3f unk_0C;
    f32 unk_18;
    f32 unk_1C;
    s32 unk_20;
    s8 unk_24[0xC];
    s32 unk_30;
    struct unk_8006FC8C* unk_34;
    struct unk_8006FC8C* unk_38;
    s8 unk_3C[0x2C];
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    s8 unk_74[0x30];
} unk_8006FC8C; // size = 0xA4

typedef struct unk_800F8510 {
    s32 unk_00;
    s8 unk_04[0x4];
    s32 unk_08;
    f32 unk_0C;
    unk_8006FC8C* unk_10;
    s8 unk_14[0xC];
    s32 unk_20;
    s8 unk_24[0x10];
    u8 unk_34[4][20];
    s8 unk_84[0x40];
    u8 unk_C4[20];
    s8 unk_D8[0x4];
    u8 unk_DC[20];
} unk_800F8510; // size = 0xF0

typedef struct unk_8010B7D0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s8 unk_12[0x2];
} unk_8010B7D0; // size = 0x14

typedef struct unk_8010B7B0 {
    s8 unk_000[0x20];
    unk_8010B7D0 unk_020[1]; // unknown length
    s8 unk_034[0x4EC];
    s16 unk_520[64];
    s8 unk_5A0[64];
    s8 unk_5E0[64];
    s8 unk_620[64];
    s8 unk_660[64];
    s8 unk_6A0[64];
    s8 unk_6E0[64];
    s8 unk_720[64];
    s8 unk_760[64];
    s8 unk_7A0[64];
} unk_8010B7B0; // size = 0x7E0

typedef struct unk_802D3E38 {
    s8 unk_00[0x4];
    f32 unk_04;
    f32 unk_08;
    Vec3f unk_0C;
    Vec3f unk_18;
    s8 unk_24[0x4];
} unk_802D3E38; // size = 0x28

typedef struct unk_8006FF90_arg_1 {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
} unk_8006FF90_arg_1; // size = 0x18

typedef struct unk_8006FF90_arg_2 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
} unk_8006FF90_arg_2; // size = 0x10

typedef struct unk_802D1B60_unk_00 {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} unk_802D1B60_unk_00; // size = 0x1C

typedef struct unk_802D1B60 {
    unk_802D1B60_unk_00* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} unk_802D1B60;

typedef struct unk_800E3A28 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s8 unk_14;
    s8 unk_15;
    s8 unk_16[0x2];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s8 unk_24[0x4];
} unk_800E3A28; // size = 0x28

typedef Gfx* (*unk_800E51B8_unk_1C_func)(Gfx*, s16, s16);

typedef struct unk_800E51B8 {
    s32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    unk_800E51B8_unk_1C_func unk_1C;
} unk_800E51B8; // size = 0x20

#endif // UNK_STRUCTS_H
