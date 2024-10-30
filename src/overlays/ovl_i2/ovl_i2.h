#ifndef OVL_I2_H
#define OVL_I2_H

#include "PR/ultratypes.h"
#include "other_types.h"

typedef struct unk_8010D778_unk_18 {
    s8 unk_00;
    u8 unk_01;
} unk_8010D778_unk_18; // size = 0x2

typedef struct unk_8010D778_unk_18_2 {
    s8 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} unk_8010D778_unk_18_2; // size = 0x1C

typedef struct unk_8010D778_unk_18_3 {
    s8 unk_00;
    s8 unk_01;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
} unk_8010D778_unk_18_3; // size = 0x14

typedef struct unk_8010D778_unk_1C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} unk_8010D778_unk_1C; // size = 0x14

typedef struct unk_8010D778 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    s16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    TexturePtr unk_14;
    void* unk_18;
    unk_8010D778_unk_1C unk_1C;
} unk_8010D778; // size = 0x30

extern u8 D_i2_8010D7F0[];

#endif // OVL_I2_H
