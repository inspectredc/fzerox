#ifndef FZX_CACHE_H
#define FZX_CACHE_H

#include "libultra/ultra64.h"
#include "macros.h"

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

#define CACHE_TEX_INFO_WH_PAD(type, texture, width, height, compressedSize) \
        { { type, texture, width, height, compressedSize }, { 0 } }

#ifndef EXPANSION_KIT
    #define CACHE_TEX_INFO_WH(type, texture, width, height, compressedSize) \
        CACHE_TEX_INFO_WH_PAD(type, texture, width, height, compressedSize)
#else
    #define CACHE_TEX_INFO_WH(type, texture, width, height, compressedSize) \
        { { type, texture, width, height, compressedSize } }
#endif

#define CACHE_TEX_INFO_PAD(type, texture, compressedSize) \
    CACHE_TEX_INFO_WH_PAD(type, texture, TEX_WIDTH(texture), TEX_HEIGHT(texture), compressedSize)

#define CACHE_TEX_INFO(type, texture, compressedSize) \
    CACHE_TEX_INFO_WH(type, texture, TEX_WIDTH(texture), TEX_HEIGHT(texture), compressedSize)

#define CACHE_TEX_INFO_COMP_PAD(type, texture) \
    CACHE_TEX_INFO_PAD(TEX_CACHE_MIO0(type), texture, TEX_COMPRESSED_SIZE(texture))

#define CACHE_TEX_INFO_COMP(type, texture) \
    CACHE_TEX_INFO(TEX_CACHE_MIO0(type), texture, TEX_COMPRESSED_SIZE(texture))

typedef enum TextureCacheDrawMode {
    TEXTURE_CACHE_DRAW,
    TEXTURE_CACHE_DRAW_TINTED,
    TEXTURE_CACHE_DRAW_MIRROR,
    TEXTURE_CACHE_DRAW_SCALED,
    TEXTURE_CACHE_DRAW_SCALED_TINTED,
    TEXTURE_CACHE_DRAW_SCALED_MIRROR,
} TextureCacheDrawMode;

#endif // FZX_CACHE_H
