#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "other_types.h"
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
    // s8 unk_3C[0x10];
    // struct unk_802D3978* unk_4C;
    // struct unk_802D3978* unk_50;
    // s8 unk_54[0x10];
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
    s16 unk_14[6];
    s32 unk_20[5];
    u8 unk_34[4][20];
    s8 unk_84[0x14];
    f32 unk_98[5];
    s8 unk_AC[5][4];
    f32 unk_C0;
    u8 unk_C4[20];
    s32 unk_D8;
    u8 unk_DC[20];
} unk_800F8510;

typedef struct unk_8010B7D0 {
    Vec3f unk_00;
    s16 unk_0C;
    s16 unk_0E;
    s32 unk_10;
} unk_8010B7D0;

typedef struct unk_8010B7B0 {
    s8 unk_000[0x20];
    unk_8010B7D0 unk_020[64];
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

typedef struct unk_802A9FC0 {
    s8 unk_00[0x14];
    Vec3f unk_14;
    s8 unk_20[0x40];
} unk_802A9FC0; // size = 0x60

typedef struct unk_802D08E0 {
    Vec3f unk_00;
    Mtx3F unk_0C;
    f32 unk_30;
    unk_802A9FC0* unk_34;
} unk_802D08E0; // size = 0x38

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

typedef Gfx* (*unk_800E51B8_unk_1C_func)(Gfx*, s32, s32);

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
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
    s32 unk_E0;
    s16 unk_E4;
    s16 unk_E6;
    f32 unk_E8;
    f32 unk_EC;
    f32 unk_F0;
    f32 unk_F4;
    f32 unk_F8;
    f32 unk_FC;
    f32 unk_100;
    f32 unk_104;
    f32 unk_108;
    f32 unk_10C;
    f32 unk_110;
    f32 unk_114;
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
    f32 unk_9C;
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
    f32 unk_1AC;
    f32 unk_1B0;
    f32 unk_1B4;
    f32 unk_1B8;
    f32 unk_1BC;
    s8 unk_1C0[0x4];
    f32 unk_1C4;
    s8 unk_1C8[0x8];
    f32 unk_1D0;
    f32 unk_1D4;
    f32 unk_1D8;
    s8 unk_1DC[0x4];
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
    f32 unk_1EC;
    s8 unk_1F0[0x8];
    f32 unk_1F8;
    s8 unk_1FC[0x10];
    s32 unk_20C;
    s8 unk_210[0xC];
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
    s16 unk_2A8;
    s8 unk_2AA[0x2];
    s32 unk_2AC;
    s16 unk_2B0;
    s8 unk_2B2[0x2];
    s32 unk_2B4;
    struct unk_802C4920* unk_2B8;
    struct unk_802C4920* unk_2BC;
    f32 unk_2C0;
    f32 unk_2C4;
    s8 unk_2C8;
    s8 unk_2C9[0x3];
    s16 unk_2CC;
    s8 unk_2CE[0x2];
    s8 unk_2D0[0x10];
    f32 unk_2E0;
    f32 unk_2E4;
    f32 unk_2E8;
    s8 unk_2EC[0x44];
    f32 unk_330;
    f32 unk_334;
    f32 unk_338;
    f32 unk_33C;
    s32 unk_340;
    s8 unk_344;
    s8 unk_345;
    s8 unk_346;
    s8 unk_347;
    s8 unk_348;
    s8 unk_349;
    s8 unk_34A;
    s8 unk_34B;
    s8 unk_34C;
    s8 unk_34D;
    s16 unk_34E;
    s16 unk_350;
    s16 unk_352;
    f32 unk_354;
    s32 unk_358;
    s32 unk_35C;
    f32 unk_360;
    f32 unk_364;
    u32 unk_368;
    s32 unk_36C;
    s32 unk_370;
    s32 unk_374;
    s32 unk_378;
    s32 unk_37C;
    s32 unk_380;
    s32 unk_384;
    f32 unk_388;
    f32 unk_38C;
    s32 unk_390;
    s32 unk_394;
    s32 unk_398;
    s32 unk_39C;
    s32 unk_3A0;
    s32 unk_3A4;
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
} unk_800DCE98; // size = 0x94

typedef struct unk_36ED0 {
    s32 unk_00;
    s8 unk_04[0x8];
    f32 unk_0C;
    s8 unk_10[0x4];
    Vec3f unk_14;
    s16 unk_20[3];
    s16 unk_26[3];
    s16 unk_2C[3];
    s16 unk_32[3];
    s16 unk_38[3];
    s16 unk_3E[3];
    s16 unk_44[3];
    s16 unk_4A[3];
    s16 unk_50;
    s16 unk_52;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5A;
    s16 unk_5C;
    s16 unk_5E;
} unk_36ED0; // size = 0x60

typedef struct unk_802D2D70 {
    unk_8006FF90_arg_1* unk_00;
    s32 index;
} unk_802D2D70;

typedef struct unk_802D3978 {
    s32 unk_00;
    Vec3f unk_04;
    s8 unk_10[0x4];
} unk_802D3978; // size = 0x14

typedef struct unk_800E5FF8 {
    u32 unk_0000;
    s32 unk_0004;
    s32 unk_0008[1]; // unknown length
    s8 unk_000C[0x3F5C];
    s16 unk_3F68;
    u8 unk_3F6A[20];
} unk_800E5FF8; // size = 0x3F80

typedef struct unk_80077D50 {
    s16 unk_00;
    void* unk_04; // segmented address
    u16 width;
    u16 height;
    size_t compressedSize;
} unk_80077D50;

typedef struct unk_800E33E0 {
    void* unk_00; // segmented address
    TexturePtr unk_04;
} unk_800E33E0; // size = 0x8

typedef struct unk_800E4068 {
    unk_80077D50* unk_00;
    TexturePtr unk_04;
} unk_800E4068; // size = 0x8

typedef struct unk_800792D8 {
    unk_80077D50* unk_00;
    s32 unk_04;
} unk_800792D8;

typedef struct unk_800E3F28 {
    unk_800792D8* unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    TexturePtr unk_0C;
    TexturePtr unk_10;
} unk_800E3F28; // size = 0x14


typedef struct unk_800DCE48 {
    s32 unk_00;
    s8 unk_04[0xC];
    s32 unk_10;
} unk_800DCE48;

typedef struct unk_800F5DF0 {
    s32 unk_00;
    unk_800E5FF8* unk_04;
    s8* unk_08;
    s32 unk_0C;
    s16 unk_10;
    s16 unk_12;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s8 unk_20[0xC];
    f32 unk_2C;
    unk_802C4920* unk_30;
} unk_800F5DF0; // size 0x34

typedef struct unk_8012F450 {
    s32 unk_00;
    u8 unk_04;
    u8 unk_05;
    s8 unk_06[0x2];
    f32 unk_08;
} unk_8012F450;
typedef struct unk_80141EA8 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    unk_8012F450 unk_0C;
    s8 unk_18[0x30];
} unk_80141EA8; // size = 0x48

typedef struct unk_800E4268 {
    s32 unk_00;
    f32 unk_04;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s8 unk_0E[0x2];
} unk_800E4268; // size = 0x10

#endif // UNK_STRUCTS_H
