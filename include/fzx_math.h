#ifndef FZX_MATH_H
#define FZX_MATH_H

#include "libultra/ultra64.h"

#define M_PI    3.14159265358979323846f
#define M_DTOR	(M_PI / 180.0f)
#define M_RTOD	(180.0f / M_PI)

#define LCG_MULTIPLIER 1103515245
#define LCG_INCREMENT_1 12345
#define LCG_INCREMENT_2 67890

#define SIN(x) (gSinTable[(x) & 0xFFF])
#define COS(x) (gSinTable[((x) + 0x400) & 0xFFF])
#define TAN(x) (SIN(x) / COS(x))

// TODO: figure out calculation from D_PI and M_PI which gives correct rodata values
#define D_TWO_PI 6.283185958862305
#define M_TWO_PI 6.283186f

#define RAD_TO_FZXANG(x) (((x) * 0x1000) / D_TWO_PI)

#define DEG_TO_FZXANG(x) (((x) * 0x1000) / 360)
#define DEG_TO_FZXANG2(x) ((x) * (0x1000 / 360.0f))

typedef union {
    struct {
        /* 0x0 */ f32 x;
        /* 0x4 */ f32 y;
        /* 0x8 */ f32 z;
    };
    /* 0x0 */ f32 v[3];
} Vec3f; // size = 0xC

typedef union {
    struct {
        /* 0x0 */ s16 x;
        /* 0x2 */ s16 y;
        /* 0x4 */ s16 z;
    };
    /* 0x0 */ s16 v[3];
} Vec3s; // size = 0x6

typedef union {
    struct {
        /* 0x0 */ s32 x;
        /* 0x4 */ s32 y;
        /* 0x8 */ s32 z;
    };
    /* 0x0 */ s32 v[3];
} Vec3i; // size = 0xC

// Needed for stack to complement macros
typedef struct Vec3fFlip {
    /* 0x0 */ f32 z;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 x;
} Vec3fFlip;

typedef float Mtx3F_t[3][3];
typedef union {
    struct {
        Vec3f x,y,z;
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

extern f32 gSinTable[];

#endif // FZX_MATH_H
