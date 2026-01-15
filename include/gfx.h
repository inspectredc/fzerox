#ifndef GFX_H
#define GFX_H

#include "libultra/ultra64.h"
#include "macros.h"

typedef union {
    u64 buffer[SCREEN_HEIGHT * SCREEN_WIDTH / 4];
    u16 data[SCREEN_HEIGHT * SCREEN_WIDTH];
    u16 array[SCREEN_HEIGHT][SCREEN_WIDTH];
} FrameBuffer; // size = 0x25800

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

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
    ((u16*)((vtx)->v.ob))[0] = ((x) & 0xFFFF);     \
    ((u16*)((vtx)->v.ob))[1] = ((y) & 0xFFFF);     \
    ((u16*)((vtx)->v.ob))[2] = ((z) & 0xFFFF);     \
    (vtx)->v.flag = 0;                             \
    ((u16*)((vtx)->v.tc))[0] = ((s) & 0xFFFF);     \
    ((u16*)((vtx)->v.tc))[1] = ((t) & 0xFFFF);     \
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
