#ifndef FZX_MATH_H
#define FZX_MATH_H

#include "libultra/ultra64.h"

typedef union {
    struct {
        /* 0x0 */ f32 x;
        /* 0x4 */ f32 y;
        /* 0x8 */ f32 z;
    };
    /* 0x0 */ f32 v[3];
} Vec3f; // size = 0xC

// Needed for stack to complement macros
typedef struct Vec3fFlip {
    /* 0x0 */ f32 z;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 x;
} Vec3fFlip;

typedef float Mtx3F_t[3][3];
typedef union {
    Mtx3F_t mf;
    struct {
        Vec3f x,y,z;
    };
    struct {
        float xx, yx, zx,
              xy, yy, zy,
              xz, yz, zz;
    };
} Mtx3F; // size = 0x24

typedef float MtxF_t[4][4];

typedef union {
    MtxF_t m;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF; // size = 0x40

#endif // FZX_MATH_H
