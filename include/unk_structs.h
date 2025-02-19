#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "other_types.h"
#include "fzx_math.h"

// Course Segment
typedef struct unk_8006FC8C {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ f32 radiusLeft;
    /* 0x1C */ f32 radiusRight;
    /* 0x20 */ s32 trackSegmentInfo;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 segmentIndex;
    /* 0x34 */ struct unk_8006FC8C* next;
    /* 0x38 */ struct unk_8006FC8C* prev;
    /* 0x3C */ struct unk_36ED0* unk_3C;
    /* 0x40 */ struct unk_36ED0* unk_40;
    /* 0x44 */ struct unk_802D3D38* unk_44;
    /* 0x48 */ struct unk_802D3D38* unk_48;
    /* 0x4C */ struct unk_802D3978* unk_4C;
    /* 0x50 */ struct unk_802D3978* unk_50;
    /* 0x54 */ struct unk_802D3E38* unk_54;
    /* 0x58 */ struct unk_802D3E38* unk_58;
    /* 0x5C */ s8 unk_5C[0x8];
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ Vec3f unk_74;
    /* 0x80 */ Vec3f unk_80;
    /* 0x8C */ Vec3f unk_8C;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ f32 unk_9C;
    /* 0xA0 */ f32 unk_A0;
} unk_8006FC8C; // size = 0xA4

// Todo fill in array as individual documented u8 variables
typedef struct CarInfo {
    u8 unk_00[20];
} CarInfo;

typedef struct CourseRecordInfo {
    s32 encodedCourseIndex;
    s32 unk_04;
    s32 unk_08;
    f32 unk_0C;
    unk_8006FC8C* unk_10;
    s16 unk_14[6];
    s32 timeRecord[5];
    CarInfo carInfo[5];
    f32 engine[5];
    u8 name[5][4];
    f32 maxSpeed;
    CarInfo maxSpeedCar;
    s32 bestTime;
    CarInfo bestTimeCar;
} CourseRecordInfo; // size = 0xF0

typedef struct unk_802D3E38 {
    s32 unk_00;
    f32 unk_04;
    f32 unk_08;
    Vec3f unk_0C;
    Vec3f unk_18;
    s8 unk_24[0x4];
} unk_802D3E38; // size = 0x28

typedef struct unk_802D3D38 {
    Vec3f unk_00;
    Mtx3F unk_0C;
    Vec3f unk_30;
    s8 unk_3C[0x4];
} unk_802D3D38; // size = 0x40

typedef struct unk_8006FF90_arg_1 {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
} unk_8006FF90_arg_1; // size = 0x18

typedef struct unk_802D1B60_unk_00 {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    Vec3f unk_10;
} unk_802D1B60_unk_00; // size = 0x1C

typedef struct unk_802D1B60 {
    unk_802D1B60_unk_00* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} unk_802D1B60;

typedef struct unk_802D08E0 {
    Vec3f unk_00;
    Mtx3F unk_0C;
    f32 unk_30;
    struct unk_36ED0* unk_34;
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
    f32* unk_04[3];
    s32* unk_10;
} unk_struct_14; // size = 0x14

typedef struct unk_80085154_arg_2 {
    s32 unk_00;
    f32* unk_04;
    s32* unk_08;
} unk_80085154_arg_2; // size = 0xC

typedef struct unk_80085434_arg_2 {
    unk_struct_14 unk_00[2];
    unk_80085154_arg_2 unk_28;
} unk_80085434_arg_2; // size = 0x34

typedef struct unk_80085494_arg_2 {
    unk_struct_14 unk_00[3];
    unk_80085154_arg_2 unk_3C;
} unk_80085494_arg_2; // size = 0x48

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
    f32 unk_94;
    s32 unk_98;
} unk_struct_9C; // size = 0x9C

typedef struct unk_struct_58 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18[16];
} unk_struct_58; // size = 0x58

typedef struct unk_redo_1 {
    unk_struct_58 unk_00;
    unk_struct_20 unk_58;
} unk_redo_1; // size = 0x78

typedef struct unk_redo_2 {
    unk_struct_58 unk_00;
    unk_struct_54 unk_58;
} unk_redo_2; // size = 0xAC

typedef struct unk_redo_3 {
    unk_struct_58 unk_00;
    unk_struct_68 unk_58;
} unk_redo_3; // size = 0xC0

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
    s32 id;
    s32 unk_04;
    u16 unk_08;
    s16 unk_0A;
    Racer_unk_C unk_0C;
    Vec3f unk_5C;
    Vec3f unk_68;
    Vec3f unk_74;
    Vec3f unk_80;
    Vec3f unk_8C;
    f32 unk_98;
    f32 maxSpeed;
    f32 unk_A0;
    f32 unk_A4;
    Vec3f unk_A8;
    Vec3f unk_B4;
    Mtx3F unk_C0;
    f32 unk_E4;
    Mtx3F unk_E8;
    Vec3f unk_10C;
    Vec3f unk_118;
    MtxF unk_124;
    s8 unk_164;
    s8 unk_165;
    s8 unk_166;
    s8 unk_167;
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
    f32 unk_1C0;
    f32 unk_1C4;
    f32 unk_1C8;
    f32 unk_1CC;
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
    f32 unk_1FC;
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
    s32 unk_280;
    s16 unk_284;
    s16 unk_286;
    s32 unk_288;
    struct Racer* unk_28C;
    s32 lapTimes[3];
    s32 unk_29C;
    s32 raceTime;
    s32 unk_2A4;
    s16 lap;
    s16 unk_2AA;
    s32 position;
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
    u8 unk_2CA;
    u8 unk_2CB;
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
    f32 unk_304;
    f32 unk_308;
    f32 unk_30C;
    s8 unk_310[0xC];
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
    f32* unk_08;
} unk_800CD970; // size 0xC

typedef struct Controller {
    OSPfs pfs;
    s8 unk_68[0x3];
    u8 errno;
    s8 stickX;
    s8 stickY;
    u8 stickCurrent;
    u8 stickPressed;
    u8 stickReleased;
    u8 stickPrev;
    s16 unk_72;
    s16 unk_74;
    s16 unk_76;
    s16 unk_78;
    u16 buttonCurrent;
    u16 buttonPressed;
    u16 buttonReleased;
    u16 buttonPrev;
    u16 unk_82;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8C;
    s32 unk_90;
} Controller; // size = 0x94

typedef struct unk_36ED0 {
    s32 trackSegmentInfo;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    s32 unk_10;
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

typedef struct unk_802D2D78 {
    s32 unk_00;
    Vtx* unk_04;
    Vtx* unk_08;
    s8 unk_0C[0x4];
} unk_802D2D78; // size = 0x10

typedef struct unk_802D3978 {
    s32 unk_00;
    Vec3f unk_04;
    s8 unk_10[0x4];
} unk_802D3978; // size = 0x14

typedef struct Ghost {
    /* 0x0000 */ s32 encodedCourseIndex;
    /* 0x0004 */ s32 raceTime;
    /* 0x0008 */ s32 lapTimes[3];
    /* 0x0014 */ s32 replayEnd;
    /* 0x0018 */ s32 replaySize;
    /* 0x001C */ s8 replayData[16200];
    /* 0x3F64 */ s32 replayChecksum;
    /* 0x3F68 */ s16 ghostType;
    /* 0x3F6A */ CarInfo carInfo;
} Ghost; // size = 0x3F80

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
    s32 gameMode;
    s8 unk_04[0xC];
    s32 unk_10;
} unk_800DCE48; // size = 0x14

typedef struct unk_800F5DF0 {
    s32 unk_00;
    Ghost* ghost;
    s8* unk_08;
    s32 unk_0C;
    s16 unk_10;
    s16 unk_12;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    Vec3f unk_20;
    f32 unk_2C;
    Racer* unk_30;
} unk_800F5DF0; // size 0x34

typedef struct unk_8012F450 {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 hours;
    /* 0x05 */ u8 minutes;
    /* 0x08 */ f32 minuteFraction;
} unk_8012F450; // size = 0xC

typedef struct RaceStats {
    s32 raceTime;
    f32 maxSpeed;
    s16 position;
    s16 unk_0A;
    s16 racersKOd;
    s8 unk_0E[0x2];
} RaceStats; // size = 0x10

typedef struct unk_80141C88_unk_1D {
    CarInfo unk_00;
    s8 unk_14[12];
} unk_80141C88_unk_1D;

typedef struct GhostInfo {
    s32 courseIndex;
    s32 encodedCourseIndex;
    s32 raceTime;
    s32 replayChecksum;
    u16 ghostType;
    u16 unk_12;
    char trackName[9];
    unk_80141C88_unk_1D unk_1D;
} GhostInfo; // size = 0x40

typedef struct unk_80111870 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    u32 unk_1C;
    Racer* unk_20;
} unk_80111870; // size = 0x24

typedef struct unk_80112FB8 {
    f32 unk_00;
    s32 unk_04;
    Racer* unk_08;
} unk_80112FB8; // size = 0xC

typedef struct unk_801122A8 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3f unk_24;
    Vec3f unk_30;
    u32 unk_3C;
    Racer* unk_40;
} unk_801122A8; // size = 0x44

typedef struct unk_80113140 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3i unk_24;
    Vec3f unk_30;
    Vec3f unk_3C;
    s16 unk_48;
    s16 unk_4A;
    s16 unk_4C;
    s16 unk_4E;
    u32 unk_50;
    Racer* unk_54;
} unk_80113140; // size = 0x58

typedef struct unk_800CF1B0 {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[4];
    u8 unk_08[4];
    u8 unk_0C[4];
    u8 unk_10;
    s8 unk_11[3];
    s16 unk_14;
} unk_800CF1B0; // size = 0x16

typedef struct unk_80225800 {
    Mtx unk_000;
    Vtx unk_040[4 * 6];
    Vtx unk_1C0[48 * 5];
} unk_80225800; // size = 0x10C0

#endif // UNK_STRUCTS_H
