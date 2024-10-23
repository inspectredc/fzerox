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

// TODO: Figure out where this is supposed to come from
#define F3DEX_GBI_PL
#ifdef F3DEX_GBI_PL
# define G_LIGHTING_POSITIONAL  0x00400000
#endif
#undef F3DEX_GBI_PL

#endif // GFX_H
