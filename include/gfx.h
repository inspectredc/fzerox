#ifndef GFX_H
#define GFX_H

#include "libultra/ultra64.h"
#include "macros.h"

typedef union {
    u16 data[SCREEN_HEIGHT * SCREEN_WIDTH];
    u16 array[SCREEN_HEIGHT][SCREEN_WIDTH];
} FrameBuffer; // size = 0x25800

typedef struct ScissorBox {
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;
} ScissorBox;

/**
 * `x` vertex x
 * `y` vertex y
 * `z` vertex z
 * `s` texture s coordinate
 * `t` texture t coordinate
 * `crnx` red component of color vertex, or x component of normal vertex
 * `cgny` green component of color vertex, or y component of normal vertex
 * `cbnz` blue component of color vertex, or z component of normal vertex
 * `a` alpha
 */
#define VTX(x, y, z, s, t, crnx, cgny, cbnz, a) \
    { { { x, y, z }, 0, { s, t }, { crnx, cgny, cbnz, a } }, }

#define VTX_T(x, y, z, s, t, cr, cg, cb, a) \
    { { x, y, z }, 0, { s, t }, { cr, cg, cb, a }, }

#define SET_VTX(vtx, x, y, z, s, t, cr, cg, cb, a) \
    (vtx)->v.ob[0] = ((x) & 0xFFFF);               \
    (vtx)->v.ob[1] = ((y) & 0xFFFF);               \
    (vtx)->v.ob[2] = ((z) & 0xFFFF);               \
    (vtx)->v.flag = 0;                             \
    (vtx)->v.tc[0] = ((s) & 0xFFFF);               \
    (vtx)->v.tc[1] = ((t) & 0xFFFF);               \
    (vtx)->v.cn[0] = cr;                           \
    (vtx)->v.cn[1] = cg;                           \
    (vtx)->v.cn[2] = cb;                           \
    (vtx)->v.cn[3] = a;

// TODO: Figure out where this is supposed to come from
#define F3DEX_GBI_PL
#ifdef F3DEX_GBI_PL
# define G_LIGHTING_POSITIONAL  0x00400000
#endif
#undef F3DEX_GBI_PL

#endif // GFX_H
