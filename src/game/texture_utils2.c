#include "global.h"
#include ASSET_HEADER(course_track_gfx.h)

Gfx* func_8007E410(Gfx* gfx, TexturePtr texture, TexturePtr palette, s32 format, s32 unkTmemFlag, s32 left, s32 top,
                   s32 width, s32 height, u16 unkDrawFlag) {
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
    if (unkDrawFlag & 4) {
        blockHeight = 2;
    }
    numBlocks = height / blockHeight;

    usedPrimitives = false;
    if (unkDrawFlag & 1) {
        gSPDisplayList(gfx++, D_8014940);
        usedPrimitives = true;
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    }
    if (unkDrawFlag & 2) {
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

void func_8007ECCC(u16* pixel, s32 textureSize) {
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

void func_8070EA38(u16* pixel, s32 arg1, s32 arg2) {
    s32 i;
    u16 var_v0;
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_t0;
    u32 red, green, blue;

    var_v0 = GPACK_RGBA5551(0, 0, 0, 1);
    for (i = 0; i < arg1; i++, pixel++) {
        temp_a0 = *pixel;
        temp_a2 = *(pixel + 1);
        temp_t0 = *(pixel + arg2);

        red = (((var_v0 & 0xF800) >> 11)) + (((temp_a0 & 0xF800) >> 11)) + (((temp_a2 & 0xF800) >> 11)) +
              (((temp_t0 & 0xF800) >> 11));
        green = (((var_v0 & 0x7C0) >> 6)) + (((temp_a0 & 0x7C0) >> 6)) + (((temp_a2 & 0x7C0) >> 6)) +
                (((temp_t0 & 0x7C0) >> 6));
        blue = (((var_v0 & 0x3E) >> 1)) + (((temp_a0 & 0x3E) >> 1)) + (((temp_a2 & 0x3E) >> 1)) +
               (((temp_t0 & 0x3E) >> 1));

        // clang-format off
        red /= 4; green /= 4; blue /= 4;
        // clang-format on

        var_v0 = temp_a0;

        *pixel = (red << 11) | (green << 6) | (blue << 1) | 1;
    }
}
#endif

s32 func_8007EF68(u16* palette, s32 paletteSize, u16 pixelColor) {
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

s32 func_8007EFBC(u16* pixel, u16* paletteStart, s32 pixelCount) {
    s32 i;
    s32 paletteIndex;
    u8* pixelOut = (u8*) pixel;
    s32 paletteSize = 0;
    u16* palette = paletteStart;

    //! @bug only call to this function passes in textureSize over pixelCount
    for (i = 0; i < pixelCount; i++, pixel++) {
        paletteIndex = func_8007EF68(paletteStart, paletteSize, *pixel);
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

Gfx* func_8007F090(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    u32 red;
    u32 green;
    u32 blue;
    s32 temp_v0 = gGameFrameCount & 0x10;
    s32 temp_t0 = gGameFrameCount & 0xF;
    f32 temp_fv0 = temp_t0 / 15.0f;

    if (!temp_v0) {
        red = (arg1 - 255) * temp_fv0 + 255.0f;
        green = (arg2 - 255) * temp_fv0 + 255.0f;
        blue = (arg3 - 255) * temp_fv0 + 255.0f;
    } else {
        red = arg1 + (255 - arg1) * temp_fv0;
        green = arg2 + (255 - arg2) * temp_fv0;
        blue = arg3 + (255 - arg3) * temp_fv0;
    }

    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);

    return gfx;
}
