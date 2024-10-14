#ifndef OVL_I3_H
#define OVL_I3_H

#include "unk_structs.h"

typedef struct unk_80140874 {
    void* unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
} unk_80140874; // size = 0x14

typedef struct unk_80140920 {
    void* unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D[0x1];
    u16 unk_0E;
} unk_80140920; // size = 0x10

typedef struct unk_80142180 {
    unk_80140874* unk_00;
    unk_80140920* unk_04;
} unk_80142180;

typedef struct unk_80141860 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} unk_80141860; // size = 0x20 (possibly unk_struct_20)

typedef struct unk_80141FF0 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    unk_80141860 unk_1C;
    unk_80141860 unk_3C;
    f32 unk_5C;
} unk_80141FF0;

typedef struct unk_80140E58 {
    s16 unk_00;
    f32 unk_04;
} unk_80140E58; // size = 0x8

typedef struct unk_801421A0 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s8 unk_06[0x2];
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    TexturePtr unk_14;
    u16* unk_18;
} unk_801421A0; // size = 0x1C

typedef struct unk_80142248 {
    s16 unk_00;
    s16 unk_02;
    u16 unk_04[16];
} unk_80142248; // size = 0x24

typedef struct unk_80142320 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s8 unk_04[4];
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14[4][2];
} unk_80142320; // size = 0x34

typedef struct unk_801437C0 {
    s8 unk_00;
    s8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
} unk_801437C0; // size = 0xA

Gfx* func_i3_8011B264(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
Gfx* func_i3_8012F554(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

Gfx* func_i3_80130824(Gfx*, s32, s32);
Gfx* func_i3_801312DC(Gfx*, s32, s32);
Gfx* func_i3_80131DF4(Gfx*);
Gfx* func_i3_80132EEC(Gfx*);
Gfx* func_i3_80135B20(Gfx*, s32, s32);
void func_i3_80139FF4(void);
bool func_i3_8013A004(void);
Gfx* func_i3_8013A360(Gfx*, s32);
void func_i3_8013C15C(void);
Gfx* func_i3_8013D2BC(Gfx*);

#endif // OVL_I3_H
