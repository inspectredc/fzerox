#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "fzxmath.h"

typedef struct unk_8006FC8C {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    f32 unk_1C;
    s32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
    struct unk_8006FC8C* unk_34;
    struct unk_8006FC8C* unk_38;
    s8 unk_3C[0x28];
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    Vec3f unk_74;
    Vec3f unk_80;
    Vec3f unk_8C;
    f32 unk_98;
    f32 unk_9C;
    f32 unk_A0;
} unk_8006FC8C; // size = 0xA4

typedef struct unk_800F8510 {
    s32 unk_00;
    s32 unk_04;
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

// # Mostly for 1B0E0, structs may end up varying
typedef struct unk_struct_8 {
    s32 unk_00;
    s32 unk_04;
} unk_struct_8; // size = 0x8

typedef struct unk_struct_20_2 {
    unk_struct_8 unk_00[4];
} unk_struct_20_2; // size = 0x20

typedef struct unk_struct_14 {
    s32 unk_00;
    f32* unk_04[1];
    s32* unk_08;
    s8 unk_0C[0x4];
    s32* unk_10;
} unk_struct_14; // size = 0x14

typedef struct unk_struct_20 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    f32 unk_1C;
} unk_struct_20; // size = 0x20

typedef struct unk_struct_54 {
    unk_struct_20 unk_00;
    f32 unk_20;
    Vec3f unk_24;
    Vec3f unk_30;
    Vec3f unk_3C;
    Vec3f unk_48;
} unk_struct_54; // size = 0x54

typedef struct unk_struct_68 {
    unk_struct_54 unk_00;
    Vec3f unk_54;
    f32 unk_60;
    f32 unk_64;
} unk_struct_68; // size = 0x68

typedef struct unk_struct_9C {
    unk_struct_68 unk_00;
    f32 unk_68[10];
    f32 unk_90;
    s8 unk_94[0x4];
    s32 unk_98;
} unk_struct_9C; // size = 0x9C

typedef struct unk_struct_58 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18[16];
} unk_struct_58; // size = 0x58

typedef struct unk_8008112C_arg_1 {
    unk_struct_58 unk_00;
    unk_struct_9C unk_58;
} unk_8008112C_arg_1; // size = 0xF4

typedef struct unk_struct_F8 {
    s32 unk_00;
    unk_8008112C_arg_1 unk_04;
} unk_struct_F8; // size = 0xF8

typedef struct unk_struct_1DC {
    s32 unk_00;
    u32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    f32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    Vec3f unk_20;
    Mtx3F unk_2C;
    Vec3f unk_50;
    Mtx3F unk_5C;
    f32 unk_80;
    f32 unk_84;
    Vec3f unk_88;
    Vec3f unk_94;
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    s8 unk_C0[0x20];
    s32 unk_E0;
    s16 unk_E4;
    s16 unk_E6;
    s8 unk_E8[0x30];
    u16 unk_118;
    s8 unk_11A[0x2];
    MtxF unk_11C;
    MtxF unk_15C;
    MtxF unk_19C;
} unk_struct_1DC; // size = 0x1DC

typedef struct unk_802C4920_unk_C {
    unk_8006FC8C* unk_00;
    f32 unk_04;
    f32 unk_08;
    Vec3f unk_0C;
    f32 unk_18;
    Vec3f unk_1C;
    Vec3f unk_28;
    Vec3f unk_34;
    f32 unk_40;
    Vec3f unk_44;
} unk_802C4920_unk_C; // size >= 0x50

typedef struct unk_802C4920 {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    s16 unk_0A;
    unk_802C4920_unk_C unk_0C;
    f32 unk_5C;
    s8 unk_60[0x4];
    f32 unk_64;
    s8 unk_68[0xC];
    Vec3f unk_74;
    s8 unk_80[0x18];
    f32 unk_98;
    s8 unk_9C[0x4];
    f32 unk_A0;
    s8 unk_A4[0x4];
    Vec3f unk_A8;
    Vec3f unk_B4;
    Mtx3F unk_C0;
    f32 unk_E4;
    s8 unk_E8[0x30];
    Vec3f unk_118;
    s8 unk_124[0x40];
    s32 unk_164;
    Vec3f unk_168;
    s8 unk_174[0xC];
    Vec3f unk_180;
    s8 unk_18C[0x10];
    Vec3f unk_19C;
    f32 unk_1A8;
    s8 unk_1AC[0x70];
    s32 unk_21C;
    s8 unk_220[0x8];
    f32 unk_228;
    f32 unk_22C;
    f32 unk_230;
    f32 unk_234;
    f32 unk_238;
    f32 unk_23C;
    s8 unk_240[0x4];
    f32 unk_244;
    f32 unk_248;
    Mtx3F unk_24C;
    f32 unk_270;
    f32 unk_274;
    s8 unk_278[0x10];
    s32 unk_288;
    struct unk_802C4920* unk_28C;
    s32 unk_290[4];
    s32 unk_2A0;
    s32 unk_2A4;
    s8 unk_2A8[0x4];
    s32 unk_2AC;
    s8 unk_2B0[0x4];
    s32 unk_2B4;
    s8 unk_2B8[0x10];
    s8 unk_2C8;
    s8 unk_2C9[0x3];
    s16 unk_2CC;
    s8 unk_2CE[0x2];
    s8 unk_2D0[0x10];
    f32 unk_2E0;
    f32 unk_2E4;
    f32 unk_2E8;
    s8 unk_2EC[0x50];
    f32 unk_33C;
    s8 unk_340[0x68];
} unk_802C4920; // size = 0x3A8

typedef struct unk_struct_C {
    s32 unk_00;
    void* unk_04;
    void* unk_08;
} unk_struct_C; // size = 0xC

typedef struct unk_800E5D70 {
    unk_struct_F8* unk_00;
    unk_struct_C* unk_04;
    s32 unk_08;
    unk_struct_20_2* unk_0C;
    Vec3f* unk_10;
    Mtx3F* unk_14;
    unk_802C4920* unk_18;
    Vec3f* unk_1C;
    Mtx3F* unk_20;
} unk_800E5D70; // size = 0x24

typedef struct unk_80085434_arg_0 {
    Vec3f unk_00[2];
    f32 unk_18;
} unk_80085434_arg_0; // size = 0x1C

typedef struct unk_80085494_arg_0 {
    Vec3f unk_00[3];
    f32 unk_24;
} unk_80085494_arg_0; // size = 0x28

typedef struct unk_800CD8B0 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3f unk_24;
    f32 unk_30;
    f32 unk_34;
} unk_800CD8B0; // size 0x38

typedef struct unk_800CD970 {
    s16 unk_00;
    s16 unk_02;
    f32 unk_04;
    unk_800CD8B0* unk_08;
} unk_800CD970; // size 0xC

#endif // UNK_STRUCTS_H
