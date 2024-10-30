#ifndef SYS_H
#define SYS_H

#include "PR/xstdio.h"
#include "PR/controller.h"
#include "libultra/ultra64.h"
#include "libc/stdarg.h"
#include "libc/stdbool.h"
#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/string.h"
#include "gfx.h"
#include "buffers.h"
#include "other_types.h"
#include "segment_symbols.h"

// ROUGH APPROXIMATIONS OF SIZES, NOT CORRECT!!

typedef struct GfxPool {
    Gfx gfxBuffer[1];
    s8 pad_00008[0x10000];
    Vtx unk_10008[1];
    s8 pad_10018[0xFFF0];
    Mtx unk_20008[4];
    Mtx unk_20108[4];
    Mtx unk_20208[4];
    s8 pad_20308[0x1680];
    Mtx unk_21988[1];
    s8 pad_219C8[0xC0];
    s8 unk_21A88[4][24];
    s8 pad_21AE8[0x60];
    Vtx unk_21B48[2048];
    Vtx unk_29B48[28];
    Vtx unk_29D08[4];
    s8 pad_29D48[0x500];
    Vtx unk_2A248[256];
    Mtx unk_2B248[1];
    Mtx unk_2B288[1];
    Mtx unk_2B2C8[64];
    Vp unk_2C2C8[1];
    Vp unk_2C2D8[1];
    s8 pad_2C2E8[0x20];
    Vp unk_2C308[4];
    s8 pad_2C348[0x20];
    Mtx unk_2C368[1];
    s8 pad_2C3A8[0x140];
    Vtx unk_2C4E8[4];
    u16 unk_2C528[1][16];
    s8 pad_2C548[0xA0];
    Mtx unk_2C5E8[1];
    Mtx unk_2C628[1];
    Mtx unk_2C668[1];
    s8 pad_2C6A8[0x48];
} GfxPool; // size = 0x2C6F0

typedef struct {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ char stack[0x800];
    /* 0x9B0 */ OSMesgQueue mesgQueue;
    /* 0x9C8 */ OSMesg msg;
    /* 0x9CC */ FrameBuffer* fb;
    /* 0x9D0 */ u16 width;
    /* 0x9D2 */ u16 height;
} FaultMgr; // size = 0x9D8, 0x8 aligned

#endif // SYS_H
