#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "fzxmath.h"

typedef struct unk_8006FC8C {
    s8 unk_00[0xC];
    Vec3f unk_0C;
    f32 unk_18;
    f32 unk_1C;
    s8 unk_20[0x14];
    struct unk_8006FC8C* unk_34;
} unk_8006FC8C;

typedef struct unk_800F8510 {
    s8 unk_00[0x8];
    s32 unk_08;
    s8 unk_0C[0x4];
    unk_8006FC8C* unk_10;
} unk_800F8510;

typedef struct unk_8010B7B0 {
    s8 unk_000[0x520];
    s16 unk_520[1];
} unk_8010B7B0;

typedef struct unk_struct_24 {
    f32 unk_00[9];
} unk_struct_24; // size = 0x24

#endif // UNK_STRUCTS_H
