#include "global.h"

extern Gfx D_8014940[];

Gfx* func_8007E410(Gfx* gfx, TexturePtr texture, TexturePtr tlutTexture, s32 format, s32 unkTmemFlag, s32 arg5,
                   s32 arg6, s32 width, s32 height, u16 unkDrawFlag) {
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
    if (tlutTexture != NULL) {
        if (!usedPrimitives) {
            gDPPipeSync(gfx++);
        }

        gDPLoadTLUT_pal256(gfx++, tlutTexture);
    }

    for (row = 0, texPtr = texture; row < numBlocks; row++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, texPtr, G_IM_FMT_CI, G_IM_SIZ_8b, blockWidth, blockHeight, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, arg5 << 2, (arg6 + (blockHeight * row)) << 2, (arg5 + blockWidth) << 2,
                                (arg6 + (blockHeight * (row + 1))) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

        texPtr += blockWidth * blockHeight * pixelSize;
    }
    remainingHeight = height % blockHeight;
    if (remainingHeight > 0) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, texPtr, format, G_IM_SIZ_8b, blockWidth, remainingHeight, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, arg5 << 2, (arg6 + (blockHeight * row)) << 2, (arg5 + blockWidth) << 2,
                                ((arg6 + (blockHeight * row) + (remainingHeight))) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                                1 << 10);
    }
    return gfx;
}

void func_8007ECCC(u16* arg0, s32 arg1) {
    s32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (arg1 / 2); i++, arg0++) {
        red = ((*arg0 & 0xF800) >> 11) * 77;
        green = ((*arg0 & 0x7C0) >> 6) * 150;
        blue = ((*arg0 & 0x3E) >> 1) * 29;
        alpha = *arg0 & 0x1;

        colorBlend = (0x1F00 - red - green - blue) >> 8;

        *arg0 = (colorBlend << 1) + (colorBlend << 6) + (colorBlend << 11) + alpha;
    }
}

s32 func_8007EF68(u16* arg0, s32 arg1, u16 arg2) {
    s32 i;
    s32 index;

    if (arg1 == 0) {
        return -1;
    }
    index = -1;

    for (i = 0; i < arg1; i++, arg0++) {
        if (*arg0 == arg2) {
            index = i;
            break;
        }
    }

    return index;
}

s32 func_8007EFBC(u16* arg0, u16* arg1, s32 arg2) {
    s32 i;
    s32 temp_v0;
    u8* var_s0 = (u8*) arg0;
    s32 var_s2 = 0;
    u16* var_s3 = arg1;

    for (i = 0; i < arg2; i++, arg0++) {
        temp_v0 = func_8007EF68(arg1, var_s2, *arg0);
        if (temp_v0 == -1) {
            if (var_s2 >= 0x100) {
                return -1;
            }
            *var_s0 = var_s2;
            *var_s3 = *arg0;
            var_s0++;
            var_s3++;
            var_s2++;
        } else {
            *var_s0 = temp_v0;
            var_s0++;
        }
    }

    return var_s2;
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
