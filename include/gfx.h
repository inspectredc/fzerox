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

#endif // GFX_H
