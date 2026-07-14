#ifndef FZX_CACHE_H
#define FZX_CACHE_H

#include "libultra/ultra64.h"

#define TEX_CACHE_MIO0_FLAG 0x10
#define TEX_CACHE_MIO0(x) ((x) | TEX_CACHE_MIO0_FLAG)

typedef enum TextureCacheFormat {
    TEX_CACHE_FMT_RGBA16 = 1,
    TEX_CACHE_FMT_RGBA16_TILED,
    TEX_CACHE_FMT_IA8,
    TEX_CACHE_FMT_I4,
    TEX_CACHE_FMT_I4_TILED,
} TextureCacheFormat;

#define INDEXED_DRAW_USE_TLUT 1
#define INDEXED_DRAW_TINT_PRIM_COLOR 2
#define INDEXED_DRAW_SMALL_BLOCKS 4

#endif // FZX_CACHE_H
