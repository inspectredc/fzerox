#include "global.h"
#include "fzx_cache.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "segment_symbols.h"

TextureCacheEntry gTextureCache[200];
s32 gTextureCacheCount;
Object gObjects[32];
TexSwapSlot gTextureSwapSlots[16];
QueuedTextureLoad gQueuedTextureLoads[16];

void TextureCache_LoadAssetData(s32 segAddr, size_t size, u8* dest) {
    CLEAR_DATA_CACHE(dest, size);
#ifndef EXPANSION_KIT
    Dma_LoadAssets(SEGMENT_ROM_START(common_assets_compressed) + SEGMENT_OFFSET(segAddr), dest, size);
#else
    Dma_LoadAssets(gRomSegmentPairs[4][0] + SEGMENT_OFFSET(segAddr), dest, size);
#endif
}

void TextureCache_ResetCache(void) {
    gTextureCacheCount = 0;
}

extern uintptr_t gArenaStartPtrs[];

u8* TextureCache_LoadCacheTexInfoList_impl(CacheTexInfo* texInfo, bool forceReload, bool singleEntry) {
    bool alreadyCached;
    s32 i;
    s32 alignedWidth;
    s32 headerSize;
    size_t textureSize;
    u8* header;
    u8* firstTexture;
    u8* texture;
    bool foundFirst;
    TextureCacheEntry* cache = gTextureCache;

    firstTexture = gArenaStartPtrs[0];
    foundFirst = false;

    while (texInfo->segAddr != 0) {
        alreadyCached = false;
        if (!forceReload) {
            for (i = 0; i < gTextureCacheCount; i++) {
                // FAKE
                if (gTextureCache[i].segAddr == (0, texInfo->segAddr)) {
                    alreadyCached = true;
                    break;
                }
            }
        }
        if (!alreadyCached) {
            switch (texInfo->format) {
                case TEX_CACHE_FMT_I4:
                case TEX_CACHE_FMT_I4_TILED:
                    if (texInfo->width % 16) {
                        alignedWidth = ((texInfo->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = texInfo->width;
                    }
                    textureSize = texInfo->height * alignedWidth;
                    texture = Arena_Allocate(ALLOC_FRONT, textureSize);
                    TextureCache_LoadAssetData(texInfo->segAddr, textureSize, texture);
                    break;
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):

                    if (texInfo->width % 16) {
                        alignedWidth = ((texInfo->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = texInfo->width;
                    }
                    textureSize = texInfo->height * alignedWidth;
                    if (texInfo->compressedSize != 0) {
                        headerSize = ALIGN_2(texInfo->compressedSize) + 2;
                    } else {
                        headerSize = 0x400;
                    }
                    texture = Arena_Allocate(ALLOC_FRONT, textureSize);
                    header = Arena_Allocate(ALLOC_PEEK, headerSize);
                    CLEAR_DATA_CACHE(header, headerSize);
                    TextureCache_LoadAssetData(texInfo->segAddr, headerSize, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, texture);
                    } else {
                        bzero(texture, (texInfo->height * alignedWidth) / 2);
                    }
                    break;
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16):
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
                    if (texInfo->compressedSize != 0) {
                        i = ALIGN_2(texInfo->compressedSize) + 2;
                    } else {
                        i = 0x400;
                    }

                    texture = Arena_Allocate(ALLOC_FRONT, texInfo->height * texInfo->width * 2);
                    header = Arena_Allocate(ALLOC_PEEK, i);
                    CLEAR_DATA_CACHE(header, i);
                    TextureCache_LoadAssetData(texInfo->segAddr, i, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, texture);
                    } else {
                        bzero(texture, texInfo->height * texInfo->width * 2);
                    }
                    break;
                default:
                    i = texInfo->height * texInfo->width * 2;
                    texture = Arena_Allocate(ALLOC_FRONT, i);
                    TextureCache_LoadAssetData(texInfo->segAddr, i, texture);
                    break;
            }
            if (!foundFirst) {
                firstTexture = texture;
                foundFirst = true;
            }
            cache[gTextureCacheCount].segAddr = texInfo->segAddr;
            cache[gTextureCacheCount].texture = texture;
            gTextureCacheCount++;
        }

#ifdef EXPANSION_KIT
        if (singleEntry) {
            break;
        }
#endif

        texInfo++;
    }

    return firstTexture;
}

#ifdef EXPANSION_KIT
u8* TextureCache_LoadCacheTexInfoListEK(CacheTexInfo* texInfo, bool singleEntry) {
    s32 temp_s0;
    bool alreadyCached;
    s32 i;
    bool foundFirst;
    u8* header;
    u8* firstTexture;
    u8* texture;
    TextureCacheEntry* cache = gTextureCache;

    foundFirst = false;
    firstTexture = gArenaStartPtrs[0];

    while (texInfo->segAddr != NULL) {
        alreadyCached = false;
        if (!singleEntry) {
            for (i = 0; i < gTextureCacheCount; i++) {
                if (gTextureCache[i].segAddr == (0, texInfo->segAddr)) {
                    alreadyCached = true;
                    break;
                }
            }
        }
        if (!alreadyCached) {
            switch (texInfo->format) {
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16):
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
                    if (texInfo->compressedSize != 0) {
                        i = ((texInfo->compressedSize >> 1) * 2) + 2;
                    } else {
                        i = 0x400;
                    }
                    texture = Arena_Allocate(ALLOC_FRONT, texInfo->height * texInfo->width * 2);
                    header = Arena_Allocate(ALLOC_PEEK, i);
                    CLEAR_DATA_CACHE(header, i);
                    bcopy(texInfo->segAddr, header, i);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, texture);
                    } else {
                        bzero(texture, texInfo->height * texInfo->width * 2);
                    }
                    break;
                default:
                    i = texInfo->height * texInfo->width * 2;
                    texture = Arena_Allocate(ALLOC_FRONT, i);
                    TextureCache_LoadAssetData(texInfo->segAddr, i, texture);
                    break;
            }
            if (!foundFirst) {
                firstTexture = texture;
                foundFirst = true;
            }
            cache[gTextureCacheCount].segAddr = texInfo->segAddr;
            cache[gTextureCacheCount].texture = texture;
            gTextureCacheCount++;
        }
        texInfo++;
    }
    return firstTexture;
}
#endif

void* TextureCache_LoadAndCache(void* segAddr, s32 textureSize, bool forceReload, bool isCompressed, bool noCache) {
    s32 decodedSize;
    bool alreadyCached;
    u8* texture;
    u8* header;
    s32 combinedSize;
    TextureCacheEntry* cache = gTextureCache;

    alreadyCached = false;
    if (!forceReload && !noCache) {
        for (decodedSize = 0; decodedSize < gTextureCacheCount; decodedSize++) {
            if (gTextureCache[decodedSize].segAddr == segAddr) {
                alreadyCached = true;
                break;
            }
        }
    }
    if (!alreadyCached || noCache) {
        if (!isCompressed) {
            if (!noCache) {
                texture = Arena_Allocate(ALLOC_FRONT, textureSize);
            } else {
                texture = Arena_Allocate(ALLOC_PEEK, textureSize);
            }
            TextureCache_LoadAssetData(segAddr, textureSize, texture);
        } else {
            texture = Arena_Allocate(ALLOC_PEEK, 8);
            TextureCache_LoadAssetData(segAddr, 8, texture);
            decodedSize = func_800AA6BC(texture);

            if (!noCache) {
                texture = Arena_Allocate(ALLOC_FRONT, decodedSize);
                header = Arena_Allocate(ALLOC_PEEK, textureSize);
            } else {
                if (decodedSize % 16) {
                    decodedSize = ((decodedSize / 16) * 16) + 16;
                }
                if (textureSize % 16) {
                    textureSize = ((textureSize / 16) * 16) + 16;
                }

                combinedSize = textureSize + decodedSize;
                texture = Arena_Allocate(ALLOC_PEEK, combinedSize);
                CLEAR_DATA_CACHE(texture, combinedSize);
                header = texture + decodedSize;
            }

            CLEAR_DATA_CACHE(header, textureSize);
            TextureCache_LoadAssetData(segAddr, textureSize, header);
            if (*(s32*) header == (s32) 'MIO0') {
                mio0Decode(header, texture);
            } else {
                bzero(texture, decodedSize);
            }
        }
        if (!noCache) {
            cache[gTextureCacheCount].segAddr = segAddr;
            cache[gTextureCacheCount].texture = texture;
            gTextureCacheCount++;
        }
    } else {
        // FAKE
        return (cache + decodedSize)->texture;
    }
    return texture;
}

TexturePtr TextureCache_GetCached(void* segAddr) {
    s32 i;

    for (i = 0; i < gTextureCacheCount; i++) {
        if (segAddr == gTextureCache[i].segAddr) {
            return gTextureCache[i].texture;
        }
    }
    return NULL;
}

Gfx* TextureCache_Draw(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture) {

    switch (texInfo->format) {
        case TEX_CACHE_FMT_IA8:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_IA, G_IM_SIZ_8b,
                                     TEXTURE_RENDER_DECAL_IA8, false, false, false);
        case TEX_CACHE_FMT_I4:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_I, G_IM_SIZ_4b,
                                     TEXTURE_RENDER_MODULATE_I4, false, false, false);
        case TEX_CACHE_FMT_I4_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_I, G_IM_SIZ_4b,
                                     TEXTURE_RENDER_MODULATE_I4, true, false, false);
        case TEX_CACHE_FMT_RGBA16_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, true, false, false);
        case TEX_CACHE_FMT_RGBA16:
        default:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, false, false, false);
    }
}

Gfx* TextureCache_DrawTinted(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture) {

    switch (texInfo->format) {
        case TEX_CACHE_FMT_IA8:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_IA, G_IM_SIZ_8b,
                                     TEXTURE_RENDER_DECAL_IA8, false, false, false);
        case TEX_CACHE_FMT_I4:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_I, G_IM_SIZ_4b,
                                     TEXTURE_RENDER_MODULATE_I4, false, false, false);
        case TEX_CACHE_FMT_I4_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_I, G_IM_SIZ_4b,
                                     TEXTURE_RENDER_MODULATE_I4, true, false, 0);
        case TEX_CACHE_FMT_RGBA16_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_TINT_PRIM_COLOR, true, false, false);
        case TEX_CACHE_FMT_RGBA16:
        default:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_TINT_PRIM_COLOR, false, false, false);
    }
}

Gfx* TextureCache_DrawMirror(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture, bool mirrorS,
                             bool mirrorT) {

    switch (texInfo->format) {
        case TEX_CACHE_FMT_IA8:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_IA, G_IM_SIZ_8b,
                                     TEXTURE_RENDER_DECAL_IA8, false, false, false);
        case TEX_CACHE_FMT_I4:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_I, G_IM_SIZ_4b,
                                     TEXTURE_RENDER_MODULATE_I4, false, false, false);
        case TEX_CACHE_FMT_I4_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_I, G_IM_SIZ_4b,
                                     TEXTURE_RENDER_MODULATE_I4, true, false, false);
        case TEX_CACHE_FMT_RGBA16_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, true, mirrorS, mirrorT);
        case TEX_CACHE_FMT_RGBA16:
        default:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, false, mirrorS, mirrorT);
    }
}

Gfx* TextureCache_DrawScaled(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture, f32 scaleX,
                             f32 scaleY) {

    switch (texInfo->format) {
        case TEX_CACHE_FMT_IA8:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_IA, G_IM_SIZ_8b,
                                     TEXTURE_RENDER_DECAL_IA8, false, false, false);
        case TEX_CACHE_FMT_I4:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_I, G_IM_SIZ_4b, TEXTURE_RENDER_MODULATE_I4, false, false);
        case TEX_CACHE_FMT_I4_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_I, G_IM_SIZ_4b, TEXTURE_RENDER_MODULATE_I4, false, false);
        case TEX_CACHE_FMT_RGBA16_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, true, false, false);
        case TEX_CACHE_FMT_RGBA16:
        default:
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_RGBA, G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, false, false);
    }
}

Gfx* TextureCache_DrawScaledMirror(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture, f32 scaleX,
                                   f32 scaleY) {

    switch (texInfo->format) {
        case TEX_CACHE_FMT_IA8:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_IA, G_IM_SIZ_8b,
                                     TEXTURE_RENDER_DECAL_IA8, false, false, false);
        case TEX_CACHE_FMT_I4:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_I, G_IM_SIZ_4b, TEXTURE_RENDER_MODULATE_I4, false, false);
        case TEX_CACHE_FMT_I4_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_I, G_IM_SIZ_4b, TEXTURE_RENDER_MODULATE_I4, false, false);
        case TEX_CACHE_FMT_RGBA16_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_RGBA,
                                     G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, true, false, false);
        case TEX_CACHE_FMT_RGBA16:
        default:
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_RGBA, G_IM_SIZ_16b, TEXTURE_RENDER_DECAL_RGBA, false, true);
    }
}

Gfx* TextureCache_DrawScaledTinted(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture, f32 scaleX,
                                   f32 scaleY) {

    switch (texInfo->format) {
        case TEX_CACHE_FMT_IA8:
            return TextureUtils_Draw(gfx, texture, left, top, texInfo->width, texInfo->height, G_IM_FMT_IA, G_IM_SIZ_8b,
                                     TEXTURE_RENDER_DECAL_IA8, false, false, false);
        case TEX_CACHE_FMT_I4:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_I, G_IM_SIZ_4b, TEXTURE_RENDER_MODULATE_I4, false, false);
        case TEX_CACHE_FMT_I4_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_I4_TILED):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_I, G_IM_SIZ_4b, TEXTURE_RENDER_MODULATE_I4, false, false);
        case TEX_CACHE_FMT_RGBA16_TILED:
        case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_RGBA, G_IM_SIZ_16b, TEXTURE_RENDER_TINT_PRIM_COLOR, true, false);
        case TEX_CACHE_FMT_RGBA16:
        default:
            return TextureUtils_DrawScaled(gfx, texture, left, top, texInfo->width, texInfo->height, scaleX, scaleY,
                                           G_IM_FMT_RGBA, G_IM_SIZ_16b, TEXTURE_RENDER_TINT_PRIM_COLOR, false, false);
    }
}

// BAD RETURN
Gfx* TextureCache_DrawWithMode(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, TexturePtr texture, u32 mode,
                               bool mirrorS, bool mirrorT, f32 scaleX, f32 scaleY) {
    switch (mode) {
        case TEXTURE_CACHE_DRAW:
            return TextureCache_Draw(gfx, texInfo, left, top, texture);
        case TEXTURE_CACHE_DRAW_TINTED:
            return TextureCache_DrawTinted(gfx, texInfo, left, top, texture);
        case TEXTURE_CACHE_DRAW_MIRROR:
            return TextureCache_DrawMirror(gfx, texInfo, left, top, texture, mirrorS, mirrorT);
        case TEXTURE_CACHE_DRAW_SCALED:
            return TextureCache_DrawScaled(gfx, texInfo, left, top, texture, scaleX, scaleY);
        case TEXTURE_CACHE_DRAW_SCALED_MIRROR:
            return TextureCache_DrawScaledMirror(gfx, texInfo, left, top, texture, scaleX, scaleY);
        case TEXTURE_CACHE_DRAW_SCALED_TINTED:
            return TextureCache_DrawScaledTinted(gfx, texInfo, left, top, texture, scaleX, scaleY);
    }
}

Gfx* TextureCache_DrawList_impl(Gfx* gfx, CacheTexInfo* texInfo, s32 left, s32 top, u32 mode, bool mirrorS,
                                bool mirrorT, f32 scaleX, f32 scaleY, bool singleEntry) {
    TexturePtr texture;

    while (texInfo->segAddr != 0) {
        // FAKE
        if (gfx) {}

        texture = TextureCache_GetCached(texInfo->segAddr);
        if (texture != NULL) {
            gfx = TextureCache_DrawWithMode(gfx, texInfo, left, top, texture, mode, mirrorS, mirrorT, scaleX, scaleY);
        }
#ifdef EXPANSION_KIT
        if (singleEntry) {
            break;
        }
#endif
        texInfo++;
    }
    return gfx;
}

Gfx* TextureCache_DrawSwapSlot_impl(Gfx* gfx, TexSwapSlot* slot, s32 left, s32 top, u32 mode, bool mirrorS,
                                    bool mirrorT, f32 scaleX, f32 scaleY, bool singleEntry) {
    TexturePtr texture;
    CacheTexInfo* texInfo;
    s32 slotTextureId;

    texInfo = slot->entries[slot->entryIndex].CacheTexInfo;

    while (texInfo->segAddr != 0) {
#ifdef EXPANSION_KIT
        if (gfx) {}
#endif
        slotTextureId = slot->slotTextureId;
        switch (slotTextureId) {
            case 0:
                texture = slot->textureA;
                break;
            default:
                texture = slot->textureB;
                break;
        }

        if (texture != NULL) {
            gfx = TextureCache_DrawWithMode(gfx, texInfo, left, top, texture, mode, mirrorS, mirrorT, scaleX, scaleY);
        }
#ifdef EXPANSION_KIT
        if (singleEntry) {
            break;
        }
#endif
        texInfo++;
    }
    return gfx;
}

void TextureCache_ClearLoadQueue(void) {
    s32 i;

    gQueuedTextureLoads[0].CacheTexInfo = NULL;

    for (i = 1; i < 17; i++) {}
}

void TextureCache_QueueLoad(CacheTexInfo* CacheTexInfo, TexturePtr texture) {
    QueuedTextureLoad* load;

    load = gQueuedTextureLoads;
    while (load->CacheTexInfo != NULL) {
        load++;
    }
    load->CacheTexInfo = CacheTexInfo;
    load->texture = texture;
}

void TextureCache_ProcessLoadQueue(void) {
    s32 alignedWidth;
    u8* header;
    size_t size;
    CacheTexInfo* texInfo;
    QueuedTextureLoad* load;

    load = gQueuedTextureLoads;

    while (true) {
        texInfo = load->CacheTexInfo;
        if (texInfo != NULL) {
            switch (texInfo->format) {
                case TEX_CACHE_FMT_I4:
                case TEX_CACHE_FMT_I4_TILED:
                    if (texInfo->width % 16) {
                        alignedWidth = ((texInfo->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = texInfo->width;
                    }
                    TextureCache_LoadAssetData(texInfo->segAddr, texInfo->height * alignedWidth, load->texture);
                    break;
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16):
                case TEX_CACHE_MIO0(TEX_CACHE_FMT_RGBA16_TILED):
                    if (texInfo->compressedSize != 0) {
                        size = ALIGN_2(texInfo->compressedSize) + 2;
                    } else {
                        size = 0x400;
                    }
                    header = Arena_Allocate(ALLOC_PEEK, size);
                    CLEAR_DATA_CACHE(header, size);
                    TextureCache_LoadAssetData(texInfo->segAddr, size, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, load->texture);
                    } else {
                        bzero(load->texture, texInfo->height * texInfo->width * 2);
                    }
                    break;
                default:
                    size = texInfo->height * texInfo->width;
                    TextureCache_LoadAssetData(texInfo->segAddr, size * 2, load->texture);
                    break;
            }
            load->CacheTexInfo = NULL;
            load++;
        } else {
            break;
        }
    }
}

void TextureCache_ClearSwapSlots(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        gTextureSwapSlots[i].allocated = 0;
    }
}

s32 TextureCache_AllocSwapSlot(TextureSwapEntry* entries) {
    s32 i = 0;
    UNUSED s32 pad;

    while (gTextureSwapSlots[i].allocated != 0) {
        if (++i >= 16) {
            return -1;
        }
    }

    gTextureSwapSlots[i].entries = entries;
    gTextureSwapSlots[i].entryIndex = -1;
    gTextureSwapSlots[i].unk_06 = 0;
    gTextureSwapSlots[i].allocated = -0x8000;

    if (entries[0].CacheTexInfo != NULL) {
        gTextureSwapSlots[i].textureA = TextureCache_LoadCacheTexInfoList_impl(entries[0].CacheTexInfo, true, true);
    }

    gTextureSwapSlots[i].textureB = (entries[1].CacheTexInfo != NULL)
                                        ? TextureCache_LoadCacheTexInfoList_impl(entries[1].CacheTexInfo, true, true)
                                        : TextureCache_LoadCacheTexInfoList_impl(entries[0].CacheTexInfo, true, true);
    gTextureSwapSlots[i].slotTextureId = 0;
    return i;
}

void TextureCache_SetSwapSlotEntry(s32 slotIndex, s32 entryIndex, TextureSwapEntry* entries) {
    UNUSED s32 pad;
    s32 entryTexInfo;

    gTextureSwapSlots[slotIndex].entryIndex = entryIndex;
    gTextureSwapSlots[slotIndex].entries = entries;
    // FAKE
    gTextureSwapSlots[slotIndex].unk_06 = (entries + entryIndex)->unk_04;
    entryTexInfo = entries[gTextureSwapSlots[slotIndex].entryIndex].CacheTexInfo;

    if (gTextureSwapSlots[slotIndex].slotTextureId != 0) {
        TextureCache_QueueLoad(entryTexInfo, gTextureSwapSlots[slotIndex].textureA);
        gTextureSwapSlots[slotIndex].slotTextureId = 0;
    } else {
        TextureCache_QueueLoad(entryTexInfo, gTextureSwapSlots[slotIndex].textureB);
        gTextureSwapSlots[slotIndex].slotTextureId = 1;
    }
}

void Object_ClearAll(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        gObjects[i].cmdId = OBJECT_FREE;
    }
}

void Object_Init(s32 cmdId, s32 left, s32 top, s8 priority) {
    s32 i = 0;
    Object* object = gObjects;

    while (true) {
        if (object->cmdId == OBJECT_FREE) {
            break;
        }
        if (++i > ARRAY_COUNT(gObjects)) {
            return;
        }
        object++;
    }

    object->cmdId = cmdId;
    object->state = 0;
    object->state2 = 0;
    object->left = left;
    object->top = top;
    object->priority = priority;
    object->shouldDraw = true;
    object->counter = 0;
    object->counter2 = 0;

    switch (cmdId) {
        case OBJECT_TITLE_BACKGROUND:
            Title_BackgroundInit(object);
            break;
        case OBJECT_14:
            func_i4_8011B0C8();
            break;
        case OBJECT_TITLE_LOGO:
            Title_LogoInit(object);
            break;
        case OBJECT_16:
            func_i4_8011B134();
            break;
        case OBJECT_TITLE_PUSH_START:
            Title_StartInit(object);
            break;
        case OBJECT_18:
            func_i4_8011B1E4();
            break;
        case OBJECT_TITLE_COPYRIGHT:
            Title_CopyrightInit();
            break;
        case OBJECT_TITLE_DISK_DRIVE:
            Title_DiskDriveInit(object);
            break;
#ifdef EXPANSION_KIT
        case OBJECT_21:
            func_i4_800748F4();
            break;
#endif
        case OBJECT_MACHINE_SELECT_HEADER:
            MachineSelect_HeaderInit();
            break;
        case OBJECT_32:
            func_i4_80116E8C(object);
            break;
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
            MachineSettings_PortraitInit(object);
            break;
        case OBJECT_MACHINE_SELECT_PORTRAIT_0:
        case OBJECT_MACHINE_SELECT_PORTRAIT_1:
        case OBJECT_MACHINE_SELECT_PORTRAIT_2:
        case OBJECT_MACHINE_SELECT_PORTRAIT_3:
            MachineSelect_PortraitInit(object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
            MachineSelect_CursorNumInit(object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR:
            MachineSelect_CursorInit();
            break;
        case OBJECT_MACHINE_SELECT_MACHINE:
            MachineSelect_MachineInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_MACHINE:
            MachineSettings_MachineInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT:
            MachineSettings_EngineWeightInit();
            break;
        case OBJECT_MACHINE_SETTINGS_STATS:
            MachineSettings_StatsInit();
            break;
        case OBJECT_MACHINE_SETTINGS_NAME_CARD:
            MachineSettings_NameCardInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_SLIDER:
            MachineSettings_SliderInit();
            break;
        case OBJECT_MACHINE_SELECT_OK:
            MachineSelect_OkInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_OK:
            MachineSettings_OkInit(object);
            break;
        case OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS:
            MachineSelect_DifficultyCupsInit(object);
            break;
        case OBJECT_MACHINE_SELECT_STATS_0:
        case OBJECT_MACHINE_SELECT_STATS_1:
        case OBJECT_MACHINE_SELECT_STATS_2:
        case OBJECT_MACHINE_SELECT_STATS_3:
            MachineSelect_StatsInit();
            break;
        case OBJECT_MAIN_MENU_BACKGROUND:
            MainMenu_BackgroundInit(object);
            break;
        case OBJECT_MAIN_MENU_MODE_SIGN_0:
        case OBJECT_MAIN_MENU_MODE_SIGN_1:
        case OBJECT_MAIN_MENU_MODE_SIGN_2:
        case OBJECT_MAIN_MENU_MODE_SIGN_3:
        case OBJECT_MAIN_MENU_MODE_SIGN_4:
        case OBJECT_MAIN_MENU_MODE_SIGN_5:
        case OBJECT_MAIN_MENU_MODE_SIGN_6:
        case OBJECT_MAIN_MENU_MODE_SIGN_7:
            MainMenu_SignInit(object);
            break;
        case OBJECT_MAIN_MENU_HEADER:
            MainMenu_HeaderInit(object);
            break;
        case OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS:
            MainMenu_NumPlayersInit();
            break;
        case OBJECT_MAIN_MENU_SELECT_DIFFICULTY:
            MainMenu_DifficultyInit();
            break;
        case OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE:
            MainMenu_TimeAttackModeInit();
            break;
        case OBJECT_MAIN_MENU_OK:
            MainMenu_OkInit(object);
            break;
        case OBJECT_MAIN_MENU_UNLOCK_EVERYTHING:
            MainMenu_UnlockEverythingInit(object);
            break;
        case OBJECT_COURSE_SELECT_BACKGROUND:
            CourseSelect_BackgroundInit(object);
            break;
        case OBJECT_COURSE_SELECT_MODEL:
            CourseSelect_ModelInit();
            break;
        case OBJECT_COURSE_SELECT_CUP_0:
        case OBJECT_COURSE_SELECT_CUP_1:
        case OBJECT_COURSE_SELECT_CUP_2:
        case OBJECT_COURSE_SELECT_CUP_3:
        case OBJECT_COURSE_SELECT_CUP_4:
        case OBJECT_COURSE_SELECT_CUP_5:
#ifdef EXPANSION_KIT
        case OBJECT_COURSE_SELECT_CUP_6:
        case OBJECT_COURSE_SELECT_CUP_7:
#endif
            CourseSelect_CupInit(object);
            break;
        case OBJECT_COURSE_SELECT_HEADER:
            CourseSelect_HeaderInit(object);
            break;
        case OBJECT_COURSE_SELECT_OK:
            CourseSelect_OkInit(object);
            break;
        case OBJECT_COURSE_SELECT_ARROWS:
            CourseSelect_ArrowsInit(object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_MARKER:
            CourseSelect_GhostMarkerInit(object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_OPTION:
            CourseSelect_GhostOptionInit(object);
            break;
#ifdef EXPANSION_KIT
        case OBJECT_170:
            func_xk3_80133B4C(object);
            break;
        case OBJECT_171:
            func_xk3_80133B84();
            break;
        case OBJECT_172:
            func_xk3_80133BD4(object);
            break;
        case OBJECT_173:
            func_xk3_80133F40();
            break;
        case OBJECT_174:
            func_xk3_8012F5F0(object);
            break;
#endif
        default:
            break;
    }
}

Gfx* Object_Draw(Gfx* gfx, Object* object) {

    if (!object->shouldDraw) {
        return gfx;
    }

    switch (object->cmdId) {
        case OBJECT_FREE:
            break;
        case OBJECT_FRAMEBUFFER:
            gfx = TextureUtils_SetupFramebufferView(gfx);
            gfx = TextureUtils_LoadFramebufferTexture(gfx);
            gfx = TextureUtils_SetFramebuffer(gfx);
            break;
        case OBJECT_TITLE_BACKGROUND:
            gfx = Title_BackgroundDraw(gfx, object);
            break;
        case OBJECT_14:
            gfx = func_i4_8011B3DC(gfx, object);
            break;
        case OBJECT_12:
            gfx = TextureUtils_DrawTranslucentRectangle(gfx, 118, 164, 203, 217, 255, 255, 255, 48);
            break;
        case OBJECT_13:
            gfx = TextureUtils_DrawDitheredRectangle(gfx, 12, 8, 307, 231, 0, 0, 0, 0);
            break;
        case OBJECT_TITLE_LOGO:
            gfx = Title_LogoDraw(gfx, object);
            break;
        case OBJECT_16:
            gfx = func_i4_8011B438(gfx, object);
            break;
        case OBJECT_TITLE_PUSH_START:
            gfx = Title_StartDraw(gfx, object);
            break;
        case OBJECT_18:
            gfx = func_i4_8011B668(gfx, object);
            break;
        case OBJECT_TITLE_COPYRIGHT:
            gfx = Title_CopyrightDraw(gfx, object);
            break;
        case OBJECT_TITLE_DISK_DRIVE:
            gfx = Title_DiskDriveDraw(gfx, object);
            break;
#ifdef EXPANSION_KIT
        case OBJECT_21:
            gfx = func_i4_80074EE0(gfx, object);
            break;
#endif
        case OBJECT_MACHINE_SELECT_BACKGROUND:
            gfx = MachineSelect_BackgroundDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_BACKGROUND:
            gfx = TextureUtils_DrawBackgroundColor(gfx, 24, 24, 24);
            break;
        case OBJECT_MACHINE_SELECT_HEADER:
            gfx = MachineSelect_HeaderDraw(gfx, object);
            break;
        case OBJECT_32:
            gfx = func_i4_80117BE0(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
            gfx = MachineSettings_PortraitDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_PORTRAIT_0:
        case OBJECT_MACHINE_SELECT_PORTRAIT_1:
        case OBJECT_MACHINE_SELECT_PORTRAIT_2:
        case OBJECT_MACHINE_SELECT_PORTRAIT_3:
            gfx = MachineSelect_PortraitDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
            gfx = MachineSelect_CursorNumDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR:
            gfx = MachineSelect_CursorDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_MACHINE:
            gfx = MachineSelect_MachineDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_OK:
            gfx = MachineSelect_OkDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_STATS_0:
        case OBJECT_MACHINE_SELECT_STATS_1:
        case OBJECT_MACHINE_SELECT_STATS_2:
        case OBJECT_MACHINE_SELECT_STATS_3:
            gfx = MachineSelect_StatsDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_MACHINE:
            gfx = MachineSettings_MachineDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_NAME:
            gfx = MachineSettings_NameDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT:
            gfx = MachineSettings_EngineWeightDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_STATS:
            gfx = MachineSettings_StatsDraw(gfx, object);
            break;
        case OBJECT_58:
            gfx = func_i4_801193B8(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_NAME_CARD:
            gfx = MachineSettings_NameCardDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_SLIDER:
            gfx = MachineSettings_SliderDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_SPLITSCREEN_BARS:
            gfx = MachineSettings_SplitscreenDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_OK:
            gfx = MachineSettings_OkDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS:
            gfx = MachineSelect_DifficultyCupsDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_NAME:
            gfx = MachineSelect_NameDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_BACKGROUND:
            gfx = MainMenu_BackgroundDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_MODE_SIGN_0:
        case OBJECT_MAIN_MENU_MODE_SIGN_1:
        case OBJECT_MAIN_MENU_MODE_SIGN_2:
        case OBJECT_MAIN_MENU_MODE_SIGN_3:
        case OBJECT_MAIN_MENU_MODE_SIGN_4:
        case OBJECT_MAIN_MENU_MODE_SIGN_5:
        case OBJECT_MAIN_MENU_MODE_SIGN_6:
        case OBJECT_MAIN_MENU_MODE_SIGN_7:
            gfx = MainMenu_SignDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_HEADER:
            gfx = MainMenu_HeaderDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS:
            gfx = MainMenu_NumPlayersDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_DIFFICULTY:
            gfx = MainMenu_DifficultyDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE:
            gfx = MainMenu_TimeAttackModeDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_OK:
            gfx = MainMenu_OkDraw(gfx, object);
            break;
        case OBJECT_100:
        case OBJECT_140:
            gfx = TextureUtils_DrawBackgroundColor(gfx, 0, 0, 0);
            break;
        case OBJECT_COURSE_SELECT_BACKGROUND:
            gfx = CourseSelect_BackgroundDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_MODEL:
            gfx = CourseSelect_ModelDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_CUP_0:
        case OBJECT_COURSE_SELECT_CUP_1:
        case OBJECT_COURSE_SELECT_CUP_2:
        case OBJECT_COURSE_SELECT_CUP_3:
        case OBJECT_COURSE_SELECT_CUP_4:
        case OBJECT_COURSE_SELECT_CUP_5:
#ifdef EXPANSION_KIT
        case OBJECT_COURSE_SELECT_CUP_6:
        case OBJECT_COURSE_SELECT_CUP_7:
#endif
            gfx = CourseSelect_CupDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_HEADER:
            gfx = CourseSelect_HeaderDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_OK:
            gfx = CourseSelect_OkDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_ARROWS:
            gfx = CourseSelect_ArrowsDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_NAME:
            gfx = CourseSelect_NameDraw(gfx);
            break;
        case OBJECT_COURSE_SELECT_GHOST_MARKER:
            gfx = CourseSelect_GhostMarkerDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_OPTION:
            gfx = CourseSelect_GhostOptionDraw(gfx, object);
            break;
#ifdef EXPANSION_KIT
        case OBJECT_170:
            gfx = func_xk3_80133F6C(gfx, object);
            break;
        case OBJECT_171:
            gfx = func_xk3_801340DC(gfx, object);
            break;
        case OBJECT_172:
            gfx = func_xk3_80134408(gfx, object);
            break;
        case OBJECT_173:
            gfx = func_xk3_80134854(gfx, object);
            break;
        case OBJECT_174:
            gfx = func_xk3_8012F628(gfx, object);
            break;
#endif
    }
    return gfx;
}

Gfx* Object_UpdateAndDrawAll(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 32; i++) {
        switch (gObjects[i].cmdId) {
            case OBJECT_FREE:
                break;
            case OBJECT_TITLE_BACKGROUND:
                Title_BackgroundUpdate(&gObjects[i]);
                break;
            case OBJECT_TITLE_DISK_DRIVE:
                Title_DiskDriveUpdate(&gObjects[i]);
                break;
            case OBJECT_MAIN_MENU_OK:
                MainMenu_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_MAIN_MENU_UNLOCK_EVERYTHING:
                MainMenu_UnlockEverythingUpdate(&gObjects[i]);
                break;
            case OBJECT_32:
                gTextureSwapSlots[OBJECT_CACHE_INDEX(&gObjects[i])].entryIndex = 0;
                func_i4_80119BB8(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
                gTextureSwapSlots[OBJECT_CACHE_INDEX(&gObjects[i])].entryIndex = 0;
                MachineSettings_PortraitUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_PORTRAIT_0:
            case OBJECT_MACHINE_SELECT_PORTRAIT_1:
            case OBJECT_MACHINE_SELECT_PORTRAIT_2:
            case OBJECT_MACHINE_SELECT_PORTRAIT_3:
                gTextureSwapSlots[OBJECT_CACHE_INDEX(&gObjects[i])].entryIndex = 0;
                MachineSelect_PortraitUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
                MachineSelect_CursorNumUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CURSOR:
                MachineSelect_CursorUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_MACHINE:
                MachineSelect_MachineUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_MACHINE:
                MachineSettings_MachineUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_NAME_CARD:
                gTextureSwapSlots[OBJECT_CACHE_INDEX(&gObjects[i])].entryIndex = 0;
                MachineSettings_NameCardUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_OK:
                MachineSelect_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_OK:
                MachineSettings_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_MODEL:
                CourseSelect_ModelUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_CUP_0:
            case OBJECT_COURSE_SELECT_CUP_1:
            case OBJECT_COURSE_SELECT_CUP_2:
            case OBJECT_COURSE_SELECT_CUP_3:
            case OBJECT_COURSE_SELECT_CUP_4:
            case OBJECT_COURSE_SELECT_CUP_5:
#ifdef EXPANSION_KIT
            case OBJECT_COURSE_SELECT_CUP_6:
            case OBJECT_COURSE_SELECT_CUP_7:
#endif
                CourseSelect_CupUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_OK:
                CourseSelect_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_ARROWS:
                CourseSelect_ArrowsUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_GHOST_MARKER:
                CourseSelect_GhostMarkerUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_GHOST_OPTION:
                CourseSelect_GhostOptionUpdate(&gObjects[i]);
                break;
#ifdef EXPANSION_KIT
            case OBJECT_170:
                gTextureSwapSlots[OBJECT_CACHE_INDEX(&gObjects[i])].entryIndex = 0;
                func_xk3_80134A48(&gObjects[i]);
                break;
            case OBJECT_172:
                func_xk3_80134B04(&gObjects[i]);
                break;
            case OBJECT_174:
                gTextureSwapSlots[OBJECT_CACHE_INDEX(&gObjects[i])].entryIndex = 0;
                func_xk3_8012F6A8(&gObjects[i]);
                break;
#endif
        }
    }

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 32; i++) {
            if (j == gObjects[i].priority) {
                gfx = Object_Draw(gfx, &gObjects[i]);
            }
        }
    }

    return gfx;
}

Object* Object_Get(s32 cmdId) {
    Object* object;

    object = gObjects;

    while (true) {
        if (cmdId == object->cmdId) {
            break;
        }
        object++;
        //! @bug this allows for an iteration out of the bounds of the array
        if (object > &gObjects[ARRAY_COUNT(gObjects)]) {
            return NULL;
        }
    }
    return object;
}

extern s32 gGameMode;

void func_80079EC8(void) {
    TextureCache_ResetCache();
    Object_ClearAll();
    TextureCache_ClearSwapSlots();
    TextureCache_ClearLoadQueue();
    if (gGameMode != GAMEMODE_CREATE_MACHINE) {
        func_8007E2B4();
    }
}

void func_80079F1C(void) {
    Object_ClearAll();
    TextureCache_ClearSwapSlots();
    TextureCache_ClearLoadQueue();
    func_8007E2B4();
}

void Object_LerpPosXToTarget(Object* object, s32 target, s32 stepScale) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        if (step > 0) {
            step /= stepScale;
            if (++step > 8) {
                step = 8;
            }
        } else {
            step /= stepScale;
            if (--step < -8) {
                step = -8;
            }
        }
    }
    OBJECT_LEFT(object) += step;
}

void Object_LerpPosYToTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 4;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) += step;
}

void Object_LerpToPos(Object* object, s32 xTarget, s32 yTarget) {
    Object_LerpPosXToTarget(object, xTarget, 4);
    Object_LerpPosYToTarget(object, yTarget);
}

void Object_LerpPosXToClampedTargetMaxStep(Object* object, s32 target, s32 maxStep) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (maxStep < ++step) {
                step = maxStep;
            }
            if (step < 8) {
                step = 8;
            }
            OBJECT_LEFT(object) += step;

            if (target < OBJECT_LEFT(object)) {
                OBJECT_LEFT(object) = target;
            }
        } else {
            step /= 4;
            if (--step < -maxStep) {
                step = -maxStep;
            }
            if (step > -8) {
                step = -8;
            }
            OBJECT_LEFT(object) += step;

            if (OBJECT_LEFT(object) < target) {
                OBJECT_LEFT(object) = target;
            }
        }
    }
}

void Object_LerpPosYToClampedTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 192) {
                step = 192;
            }
            if (step < 8) {
                step = 8;
            }
            OBJECT_TOP(object) += step;

            if (target < OBJECT_TOP(object)) {
                OBJECT_TOP(object) = target;
            }
        } else {
            step /= 4;
            if (--step < -192) {
                step = -192;
            }
            if (step >= -7) {
                step = -8;
            }
            OBJECT_TOP(object) += step;

            if (OBJECT_TOP(object) < target) {
                OBJECT_TOP(object) = target;
            }
        }
    }
}

// Duplicate function
void Object_LerpPosYToTarget2(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 4;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) += step;
}

void Object_LerpPosXToClampedTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        step = 200 / step;
        if (step > 0) {
            if (step > 24) {
                step = 24;
            }
            if (step < 16) {
                step = 16;
            }
            OBJECT_LEFT(object) += step;

            if (target < OBJECT_LEFT(object)) {
                OBJECT_LEFT(object) = target;
            }
        } else {
            if (step < -24) {
                step = -24;
            }
            if (step > -16) {
                step = -16;
            }
            OBJECT_LEFT(object) += step;

            if (OBJECT_LEFT(object) < target) {
                OBJECT_LEFT(object) = target;
            }
        }
    }
}

void Object_LerpAwayFromPosX(Object* object, s32 origin, s32 initialStep) {
    UNUSED s32 temp = OBJECT_LEFT(object);
    s32 step;

    step = origin - OBJECT_LEFT(object);
    if (origin == OBJECT_LEFT(object)) {
        OBJECT_LEFT(object) += initialStep;
        return;
    }
    if (step != 0) {
        if (step > 0) {
            step /= 8;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 8;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_LEFT(object) -= step;
}

void Object_LerpAwayFromPosY(Object* object, s32 origin, s32 initialStep) {
    UNUSED s32 temp = OBJECT_TOP(object);
    s32 step;

    step = origin - OBJECT_TOP(object);
    if (origin == OBJECT_TOP(object)) {
        OBJECT_TOP(object) += initialStep;
        return;
    }
    if (step != 0) {
        if (step > 0) {
            step /= 8;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 8;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) -= step;
}
