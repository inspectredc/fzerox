#include "global.h"
#include "fzx_cache.h"
#include ASSET_HEADER(course_track_gfx.h)

Gfx* TextureUtils_DrawIndexedBlocks(Gfx* gfx, TexturePtr texture, TexturePtr palette, s32 format, s32 unkTmemFlag,
                                    s32 left, s32 top, s32 width, s32 height, u16 drawFlags) {
    bool usedPrimitives;
    u8* texPtr;
    s32 numBlocks;
    s32 blockHeight;
    s32 pixelSize;
    s32 tmem;
    s32 row;
    s32 remainingHeight;
    s32 blockWidth = width;

    tmem = 0x1000;
    if (unkTmemFlag == 1) {
        tmem = 0x800;
        pixelSize = 1;
    } else {
        //! @bug pixelSize uninitialised
    }
    blockHeight = (s32) (tmem / pixelSize) / blockWidth;
    if (drawFlags & INDEXED_DRAW_SMALL_BLOCKS) {
        blockHeight = 2;
    }
    numBlocks = height / blockHeight;

    usedPrimitives = false;
    if (drawFlags & INDEXED_DRAW_USE_TLUT) {
        gSPDisplayList(gfx++, D_8014940);
        usedPrimitives = true;
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    }
    if (drawFlags & INDEXED_DRAW_TINT_PRIM_COLOR) {
        if (!usedPrimitives) {
            gDPPipeSync(gfx++);
            usedPrimitives = true;
        }
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    }
    if (palette != NULL) {
        if (!usedPrimitives) {
            gDPPipeSync(gfx++);
        }

        gDPLoadTLUT_pal256(gfx++, palette);
    }

    for (row = 0, texPtr = texture; row < numBlocks; row++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, texPtr, G_IM_FMT_CI, G_IM_SIZ_8b, blockWidth, blockHeight, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, (top + (blockHeight * row)) << 2, (left + blockWidth) << 2,
                                (top + (blockHeight * (row + 1))) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

        texPtr += blockWidth * blockHeight * pixelSize;
    }
    remainingHeight = height % blockHeight;
    if (remainingHeight > 0) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, texPtr, format, G_IM_SIZ_8b, blockWidth, remainingHeight, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, (top + (blockHeight * row)) << 2, (left + blockWidth) << 2,
                                ((top + (blockHeight * row) + (remainingHeight))) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                                1 << 10);
    }
    return gfx;
}

void Graphics_ConvertToInverseGreyscale(u16* pixel, s32 textureSize) {
    s32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (textureSize / (s32) sizeof(u16)); i++, pixel++) {
        red = ((*pixel & 0xF800) >> 11) * 77;
        green = ((*pixel & 0x7C0) >> 6) * 150;
        blue = ((*pixel & 0x3E) >> 1) * 29;
        alpha = *pixel & 0x1;

        colorBlend = (0x1F00 - (red + green + blue)) >> 8;

        *pixel = (colorBlend << 1) + (colorBlend << 6) + (colorBlend << 11) + alpha;
    }
}

#ifdef EXPANSION_KIT

void TextureUtils_Blur(u16* pixel, s32 count, s32 width) {
    s32 i;
    u16 prevPixel;
    u16 currentPixel;
    u16 nextPixel;
    u16 belowPixel;
    u32 red, green, blue;

    prevPixel = GPACK_RGBA5551(0, 0, 0, 1);
    for (i = 0; i < count; i++, pixel++) {
        currentPixel = *pixel;
        nextPixel = *(pixel + 1);
        belowPixel = *(pixel + width);

        red = (((prevPixel & 0xF800) >> 11)) + (((currentPixel & 0xF800) >> 11)) + (((nextPixel & 0xF800) >> 11)) +
              (((belowPixel & 0xF800) >> 11));
        green = (((prevPixel & 0x7C0) >> 6)) + (((currentPixel & 0x7C0) >> 6)) + (((nextPixel & 0x7C0) >> 6)) +
                (((belowPixel & 0x7C0) >> 6));
        blue = (((prevPixel & 0x3E) >> 1)) + (((currentPixel & 0x3E) >> 1)) + (((nextPixel & 0x3E) >> 1)) +
               (((belowPixel & 0x3E) >> 1));

        // clang-format off
        red /= 4; green /= 4; blue /= 4;
        // clang-format on

        prevPixel = currentPixel;

        *pixel = (red << 11) | (green << 6) | (blue << 1) | 1;
    }
}
#endif

s32 TextureUtils_FindPaletteColor(u16* palette, s32 paletteSize, u16 pixelColor) {
    s32 i;
    s32 index;

    if (paletteSize == 0) {
        return -1;
    }
    index = -1;

    for (i = 0; i < paletteSize; i++, palette++) {
        if (*palette == pixelColor) {
            index = i;
            break;
        }
    }

    return index;
}

s32 TextureUtils_GeneratePalette(u16* pixel, u16* paletteStart, s32 pixelCount) {
    s32 i;
    s32 paletteIndex;
    u8* pixelOut = (u8*) pixel;
    s32 paletteSize = 0;
    u16* palette = paletteStart;

    //! @bug only call to this function passes in textureSize over pixelCount
    for (i = 0; i < pixelCount; i++, pixel++) {
        paletteIndex = TextureUtils_FindPaletteColor(paletteStart, paletteSize, *pixel);
        if (paletteIndex == -1) {
            if (paletteSize >= 0x100) {
                return -1;
            }
            *pixelOut = paletteSize;
            *palette = *pixel;
            pixelOut++;
            palette++;
            paletteSize++;
        } else {
            *pixelOut = paletteIndex;
            pixelOut++;
        }
    }

    return paletteSize;
}

extern u32 gGameFrameCount;

Gfx* TextureUtils_SetPulsingColor(Gfx* gfx, s32 red, s32 green, s32 blue) {
    u32 pulseRed;
    u32 pulseGreen;
    u32 pulseBlue;
    s32 fadingToWhite = gGameFrameCount & 0x10;
    s32 phase = gGameFrameCount & 0xF;
    f32 phaseScale = phase / 15.0f;

    if (!fadingToWhite) {
        pulseRed = (red - 255) * phaseScale + 255.0f;
        pulseGreen = (green - 255) * phaseScale + 255.0f;
        pulseBlue = (blue - 255) * phaseScale + 255.0f;
    } else {
        pulseRed = red + (255 - red) * phaseScale;
        pulseGreen = green + (255 - green) * phaseScale;
        pulseBlue = blue + (255 - blue) * phaseScale;
    }

    gDPSetPrimColor(gfx++, 0, 0, pulseRed, pulseGreen, pulseBlue, 255);

    return gfx;
}
