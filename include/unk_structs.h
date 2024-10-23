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

typedef struct Racer_unk_C {
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
} Racer_unk_C; // size >= 0x50

typedef struct Racer {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    s16 unk_0A;
    Racer_unk_C unk_0C;
    Vec3f unk_5C;
    Vec3f unk_68;
    Vec3f unk_74;
    Vec3f unk_80;
    s8 unk_8C[0xC];
    f32 unk_98;
    f32 unk_9C;
    f32 unk_A0;
    f32 unk_A4;
    Vec3f unk_A8;
    Vec3f unk_B4;
    Mtx3F unk_C0;
    f32 unk_E4;
    Mtx3F unk_E8;
    Vec3f unk_10C;
    Vec3f unk_118;
    s8 unk_124[0x40];
    // very weird field
    union {
        s32 unk_164;
        struct {
            s8 unk_164_pad[3];
            s8 unk_167;
        };
    };
    Vec3f unk_168;
    f32 unk_174;
    f32 unk_178;
    f32 unk_17C;
    Vec3f unk_180;
    Vec3f unk_18C;
    f32 unk_198;
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
    f32 unk_1DC;
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
    f32 unk_1EC;
    f32 unk_1F0;
    f32 unk_1F4;
    f32 unk_1F8;
    s8 unk_1FC[0x4];
    f32 unk_200;
    s32 unk_204;
    s32 unk_208;
    s32 unk_20C;
    s32 unk_210;
    s32 unk_214;
    s32 unk_218;
    s32 unk_21C;
    s32 unk_220;
    f32 unk_224;
    f32 unk_228;
    f32 unk_22C;
    f32 unk_230;
    f32 unk_234;
    f32 unk_238;
    f32 unk_23C;
    f32 unk_240;
    f32 unk_244;
    f32 unk_248;
    Mtx3F unk_24C;
    f32 unk_270;
    f32 unk_274;
    s16 unk_278;
    s16 unk_27A;
    s32 unk_27C;
    s8 unk_280[0x4];
    s16 unk_284;
    s16 unk_286;
    s32 unk_288;
    struct Racer* unk_28C;
    s32 unk_290[3];
    s32 unk_29C;
    s32 unk_2A0;
    s32 unk_2A4;
    s16 unk_2A8;
    s16 unk_2AA;
    s32 unk_2AC;
    s16 unk_2B0;
    s8 unk_2B2;
    s8 unk_2B3;
    s32 unk_2B4;
    struct Racer* unk_2B8;
    struct Racer* unk_2BC;
    f32 unk_2C0;
    f32 unk_2C4;
    s8 character;
    s8 unk_2C9;
    s8 unk_2CA;
    s8 unk_2CB;
    s16 unk_2CC;
    s16 unk_2CE;
    s16 unk_2D0;
    s16 unk_2D2;
    s16 unk_2D4;
    s16 unk_2D6;
    s16 unk_2D8;
    s16 unk_2DA;
    s16 unk_2DC;
    s16 unk_2DE;
    f32 unk_2E0;
    f32 unk_2E4;
    f32 unk_2E8;
    f32 unk_2EC;
    f32 unk_2F0;
    f32 unk_2F4;
    f32 unk_2F8;
    f32 unk_2FC;
    f32 unk_300;
    s8 unk_304[0x18];
    f32 unk_31C;
    f32 unk_320;
    f32 unk_324;
    f32 unk_328;
    f32 unk_32C;
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
} Racer; // size = 0x3A8

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
    Racer* unk_18;
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

typedef struct Controller {
    OSPfs pfs;
    s8 unk_68[0x3];
    u8 unk_6B;
    s8 stickX;
    s8 stickY;
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
} Controller; // size = 0x94

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
    s8 unk_000C[0x3F58];
    s32 unk_3F64;
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
    Racer* unk_30;
} unk_800F5DF0; // size 0x34

typedef struct unk_8012F450 {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 hours;
    /* 0x05 */ u8 minutes;
    /* 0x08 */ f32 minuteFraction;
} unk_8012F450; // size = 0xC

typedef struct unk_800E4268 {
    s32 unk_00;
    f32 unk_04;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s8 unk_0E[0x2];
} unk_800E4268; // size = 0x10

typedef struct unk_80141C88 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u16 unk_10;
    s8 unk_12[0x2];
    char unk_14[1];
    s8 unk_15[0x8];
    u8 unk_1D[20];
    s8 unk_31[0xF];
} unk_80141C88; // size = 0x40

/* 
    spacing marker
 */

typedef struct unk_struct_110 {
    s16 unk_00;
    s8 unk_02[0x10A];
    s32 unk_10C; // added to allow struct copy match
} unk_struct_110; // size = 0x110

typedef struct unk_struct_80 {
    s16 unk_00;
    s8 unk_02[0x7E];
} unk_struct_80; // size = 0x80

// possibly just unk_struct_40
typedef struct unk_struct_40_2 {
    s16 unk_00;
    s8 unk_02[0x3A];
    s32 unk_3C;
} unk_struct_40_2; // size = 0x40

typedef struct unk_struct_10 {
    u8 unk_00[14];
    s16 unk_0E;
} unk_struct_10;

typedef struct unk_struct_10_2 {
    s16 unk_00;
    u8 unk_02[14];
} unk_struct_10_2;

typedef struct unk_struct_19E0 {
    unk_struct_10 unk_00;
    unk_struct_10_2 unk_10;
    unk_struct_110 unk_20[24];
    unk_struct_40_2 unk_19A0;
} unk_struct_19E0; // size = 0x19E0

typedef struct unk_struct_40 {
    s16 unk_00;
    s8 unk_02[0x3E];
} unk_struct_40; // size = 0x40

typedef struct unk_struct_3F80 {
    s16 unk_00;
    s8 unk_02[0x3F7E];
} unk_struct_3F80; // size = 0x3F80

typedef struct unk_struct_60 {
    s16 unk_00;
    s8 unk_02[0x5E];
} unk_struct_60; // size = 0x60

typedef struct unk_801247C0 {
    unk_struct_19E0 unk_00[2];
    unk_struct_40 unk_33C0;
    unk_struct_3F80 unk_3400;
    unk_struct_80 unk_7380[24];
    unk_struct_60 unk_7F80;
    s8 unk_7FE0[0x20];
} unk_801247C0; // size = 0x8000

#endif // UNK_STRUCTS_H
