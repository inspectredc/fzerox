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
