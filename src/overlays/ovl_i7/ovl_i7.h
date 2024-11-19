#ifndef OVL_I7_H
#define OVL_I7_H

#include "unk_structs.h"

typedef struct unk_8014B480 {
    Mtx unk_00[3];
    Mtx unk_C0[3];
    Vtx unk_180[3][13];
    Mtx unk_3F0[3];
} unk_8014B480; // size = 0x4B0

typedef struct unk_8014BE28 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    f32 unk_08;
    f32 unk_0C;
} unk_8014BE28; // size = 0x10

typedef struct unk_8014BEC8 {
    s16 unk_00;
    u16 unk_02;
    s16 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} unk_8014BEC8; // size = 0x20

typedef struct unk_8014BF98 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s8 unk_14[0x4];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    s8 unk_24;
    s8 unk_25;
    f32 unk_28;
    s8 unk_2C;
    s16 unk_2E;
    s16 unk_30;
    s32 unk_34;
    s8 unk_38[0x4];
    s32 unk_3C;
} unk_8014BF98; // size = 0x40

typedef struct unk_8014BF94 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s8 unk_14[0x4];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    s8 unk_24[0x4];
    s32 unk_28;
    s32 unk_2C;
    s8 unk_30[0x4];
} unk_8014BF94; // size = 0x34

extern u16 D_i7_8014ADA8[];
extern u16 D_i7_8014AE30[];
extern u16 D_i7_8014AEB8[];

extern unk_8014B480* D_i7_8014BDF0;
extern s16 D_i7_8014BDF4;
extern u16 D_i7_8014BDF6;
extern void* D_i7_8014BDF8;
extern void* D_i7_8014BDFC;
extern s16 D_i7_8014BE00;
extern s16 D_i7_8014BE02;
extern s16 D_i7_8014BE04;
extern s32 D_i7_8014BE08;
extern s16 D_i7_8014BE0C;
extern f32 D_i7_8014BE10;
extern s16 D_i7_8014BE14;
extern s16 D_i7_8014BE16;
extern s16 D_i7_8014BE18;
extern s16 D_i7_8014BE1A;
extern s16 D_i7_8014BE1C;
extern s16 D_i7_8014BE1E;
extern s16 D_i7_8014BE20;
extern unk_8014BE28 D_i7_8014BE28[];
extern unk_8014BEC8 D_i7_8014BEC8[];
extern u16 D_i7_8014BF28;
extern s16 D_i7_8014BF92;
extern s32 D_i7_8014C248;

#endif // OVL_I7_H
