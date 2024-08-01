#ifndef UNK_LEO_H
#define UNK_LEO_H

#include "libultra/ultra64.h"
#include "PR/leo.h"

typedef struct unk_leo_804285D0 {
    u16 unk_00;
    u16 unk_02;
    s8 unk_04[2];
    s8 unk_06[4];
    u16 unk_0A;
    s32 unk_0C;
    u8 unk_10[20];
    u8 unk_24[5];
    s8 unk_29;
    u8 unk_2A;
    s8 unk_2B[0x1];
    s32 unk_2C;
} unk_leo_804285D0; // size = 0x30

typedef struct unk_leo_80419EA0 {
    u8 unk_00[10];
    s8 unk_0A[4];
    s8 unk_0E[0x16];
    s32 unk_24;
    u16 unk_28;
    s8 unk_2C[0x12];
    u16 unk_3C[0xB3A];
    unk_leo_804285D0 unk_16B0[1];
} unk_leo_80419EA0;

#endif // UNK_LEO_H
