#ifndef GFX_H
#define GFX_H

#include "libultra/ultra64.h"
#include "macros.h"

typedef union {
    u16 data[SCREEN_HEIGHT * SCREEN_WIDTH];
    u16 array[SCREEN_HEIGHT][SCREEN_WIDTH];
} FrameBuffer; // size = 0x25800

#endif // GFX_H
