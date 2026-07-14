#include "global.h"
#include ASSET_HEADER(setup_gfx.h)

Gfx* TextureUtils_DrawRectangleClipped(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue,
                                       s32 alpha) {

    red &= 0xFF;
    green &= 0xFF;
    blue &= 0xFF;
    alpha &= 0xFF;
    if ((left >= SCREEN_WIDTH) || (top >= SCREEN_HEIGHT)) {
        return gfx;
    }

    if (left < 0) {
        left = 0;
    }
    if (top < 0) {
        top = 0;
    }
    if ((right < 0) || (bottom < 0)) {
        return gfx;
    }

    if (right > SCREEN_WIDTH) {
        right = SCREEN_WIDTH;
    }
    if (bottom > SCREEN_HEIGHT) {
        bottom = SCREEN_HEIGHT;
    }

    gSPDisplayList(gfx++, D_3000088);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gDPFillRectangle(gfx++, left, top, right, bottom);
    gDPPipeSync(gfx++);
    return gfx;
}

void TextureUtils_ConvertToGreyscale(u16* pixel, s32 size) {
    u32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (size / (s32) sizeof(u16)); i++, pixel++) {
        red = ((*pixel & 0xF800) >> 11) * 77;
        green = ((*pixel & 0x7C0) >> 6) * 150;
        blue = ((*pixel & 0x3E) >> 1) * 29;
        alpha = *pixel & 0x1;

        colorBlend = (red + green + blue) >> 8;

        *pixel = (colorBlend << 1) + (colorBlend << 6) + (colorBlend << 11) + alpha;
    }
}

void TextureUtils_ConvertToTintedGreyscale(u16* pixel, size_t size, s32 redScale, s32 greenScale, s32 blueScale) {
    u32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (size / sizeof(u16)); i++, pixel++) {
        red = ((*pixel & 0xF800) >> 11) * 77;
        green = ((*pixel & 0x7C0) >> 6) * 150;
        blue = ((*pixel & 0x3E) >> 1) * 29;
        alpha = *pixel & 0x1;

        colorBlend = (red + green + blue) >> 8;

        *pixel = (((redScale * colorBlend) >> 8) << 11) + (((greenScale * colorBlend) >> 8) << 6) +
                 (((blueScale * colorBlend) >> 8) << 1) + alpha;
    }
}

Gfx* TextureUtils_SetupFramebufferView(Gfx* gfx) {
    gSPDisplayList(gfx++, D_30001A8);
    return gfx;
}

extern s16 D_800CCFE4;
extern FrameBuffer* gFrameBuffers[];
extern s32 D_800DCCFC;
extern s32 D_800DCD04;

Gfx* TextureUtils_SetFramebuffer(Gfx* gfx) {

    gDPPipeSync(gfx++);

    if (D_800CCFE4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCCFC]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    }
    return gfx;
}

Gfx* TextureUtils_DrawBackgroundColor(Gfx* gfx, u16 red, u16 green, u16 blue) {

    if ((red < 0) || (red > 255) || (green < 0) || (green > 255) || (blue < 0) || (blue > 255)) {
        return gfx;
    }

    red >>= 3;
    green >>= 3;
    blue >>= 3;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetFillColor(gfx++, PACK_5551(red, green, blue, 1) << 16 | PACK_5551(red, green, blue, 1));
    gDPFillRectangle(gfx++, 12, 8, 307, 231);
    return gfx;
}

Gfx* TextureUtils_DrawColorRectangle(Gfx* gfx, u16 red, u16 green, u16 blue, s32 left, s32 top, s32 right, s32 bottom) {

    if ((red < 0) || (red > 255) || (green < 0) || (green > 255) || (blue < 0) || (blue > 255)) {
        return gfx;
    }

    red >>= 3;
    green >>= 3;
    blue >>= 3;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetFillColor(gfx++, PACK_5551(red, green, blue, 1) << 16 | PACK_5551(red, green, blue, 1));
    gDPFillRectangle(gfx++, left, top, right, bottom);
    return gfx;
}

extern Gfx D_8076CAF8[];

Gfx* TextureUtils_LoadFramebufferTexture(Gfx* gfx) {
#ifndef EXPANSION_KIT
    gSPDisplayList(gfx++, D_3000170);
#else
    gSPDisplayList(gfx++, D_8076CAF8);
#endif
    return gfx;
}

Gfx* TextureUtils_DrawDitheredRectangle(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green,
                                        s32 blue, s32 alpha) {
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPDisplayList(gfx++, D_3000000);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

Gfx* TextureUtils_DrawTranslucentRectangle(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green,
                                           s32 blue, s32 alpha) {
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPDisplayList(gfx++, D_3000028);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* TextureUtils_DrawSpinningTextureRectangle(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom) {
    gSPDisplayList(gfx++, D_3000270);
    gSPTextureRectangle(gfx++, (left + 1) << 2, (top + 1) << 2, (right - 1) << 2, (bottom - 1) << 2, G_TX_RENDERTILE, 0,
                        (gGameFrameCount % 32) << 5, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* TextureUtils_DrawShadeBlendRectangle(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom) {
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++,
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c1(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA),
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c2(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

Gfx* TextureUtils_Draw(Gfx* gfx, TexturePtr texture, s32 left, s32 top, s32 width, u32 height, s32 format, s32 size,
                       s32 renderType, bool tileLoad, bool mirrorS, bool mirrorT) {
    s32 i;
    s32 numBlocks;
    s32 blockHeight;
    s32 blockWidth = width;
    s32 pad[1];
    s32 sp48;
    s32 var;
    s32 siz;
    s32 spE4;
    s32 s;
    s32 blockSize;
    s32 dsdx;
    s32 dtdy;
    s32 lineBytes;
    s32 incr;
    s32 shift;
    s32 byteSiz;
    s32 sTemp = 1;

    if (blockWidth & 3) {
        return gfx;
    }

    switch (size) {
        case G_IM_SIZ_4b:
            siz = G_IM_SIZ_4b_LOAD_BLOCK;
            incr = G_IM_SIZ_4b_INCR;
            shift = G_IM_SIZ_4b_SHIFT;
            byteSiz = G_IM_SIZ_4b_BYTES;
            blockSize = 0x1000;
            break;
        case G_IM_SIZ_8b:
            siz = G_IM_SIZ_8b_LOAD_BLOCK;
            lineBytes = G_IM_SIZ_8b_LINE_BYTES;
            incr = G_IM_SIZ_8b_INCR;
            shift = G_IM_SIZ_8b_SHIFT;
            byteSiz = G_IM_SIZ_8b_BYTES;
            blockSize = 0x800;
            break;
        case G_IM_SIZ_16b:
            siz = G_IM_SIZ_16b_LOAD_BLOCK;
            lineBytes = G_IM_SIZ_16b_LINE_BYTES;
            incr = G_IM_SIZ_16b_INCR;
            shift = G_IM_SIZ_16b_SHIFT;
            byteSiz = G_IM_SIZ_16b_BYTES;
            blockSize = 0x400;
            break;
        case G_IM_SIZ_32b:
            siz = G_IM_SIZ_32b_LOAD_BLOCK;
            lineBytes = G_IM_SIZ_32b_LINE_BYTES;
            incr = G_IM_SIZ_32b_INCR;
            shift = G_IM_SIZ_32b_SHIFT;
            byteSiz = G_IM_SIZ_32b_BYTES;
            blockSize = 0x200;
            break;
        default:
            return gfx;
    }

    blockHeight = blockSize / blockWidth;
    while (height < blockHeight / 2) {
        blockHeight /= 2;
    }

    if ((blockHeight % 4) && (size == G_IM_SIZ_4b)) {
        blockHeight /= 4;
        blockHeight *= 4;
    }
    numBlocks = height / blockHeight;

    if (mirrorS != 0) {
        dsdx = -0x400;
        s = (blockWidth - sTemp) << 5;
    } else {
        dsdx = 0x400;
        s = 0;
    }

    switch (renderType) {
        case 1:
            gSPDisplayList(gfx++, D_3000088);
            break;
        case 2:
            gSPDisplayList(gfx++, D_3000100);
            break;
        case 3:
            gSPDisplayList(gfx++, D_3000138);
            break;
        case 0:
        default:
            gSPDisplayList(gfx++, D_3000050);
            break;
    }

    if (!tileLoad) {
        gDPSetTextureImage(gfx++, format, siz, blockWidth, texture);

        gDPSetTile(gfx++, format, siz, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

        if (size == G_IM_SIZ_4b) {
            gDPSetTile(gfx++, format, size, ((blockWidth >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                       G_TX_NOLOD);
        } else {
            gDPSetTile(gfx++, format, size, ((blockWidth * lineBytes) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                       G_TX_NOLOD);
        }
    } else if (size == G_IM_SIZ_4b) {
        gDPSetTextureImage(gfx++, format, 1, blockWidth >> 1, texture);

        gDPSetTile(gfx++, format, 1, ((blockWidth >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

        gDPSetTile(gfx++, format, 0, ((blockWidth * size) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTextureImage(gfx++, format, size, blockWidth, texture);

        gDPSetTile(gfx++, format, size, ((blockWidth * size) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

        gDPSetTile(gfx++, format, size, ((blockWidth * size) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
    }

    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                   (blockHeight - 1) << G_TEXTURE_IMAGE_FRAC);

    if (mirrorT != 0) {
        sp48 = height % blockHeight;
        for (i = 0; i < numBlocks; i++) {
            gDPLoadSync(gfx++);
            if (!tileLoad) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT(blockWidth, byteSiz));
                }

                gSPScisTextureRectangle(gfx++, left << 2,
                                        (s32) (top + ((numBlocks - i - 1) * blockHeight) + (height % blockHeight)) << 2,
                                        (left + blockWidth) << 2,
                                        (s32) (top + ((numBlocks - i) * blockHeight) + (height % blockHeight)) << 2,
                                        G_TX_RENDERTILE, s, (blockHeight - 1) << 5, dsdx, (64 - 1) * (1 << 10));
            } else {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);

                //! @bug s and t are swapped around from expected
                gSPScisTextureRectangle(
                    gfx++, left << 2, (s32) (top + ((numBlocks - i - 1) * blockHeight) + (height % blockHeight)) << 2,
                    (left + blockWidth) << 2,
                    (s32) (top + ((numBlocks - i) * blockHeight) + (height % blockHeight)) << 2, G_TX_RENDERTILE, s,
                    (((i + 1) * blockHeight) - 1) << 5, dsdx, (64 - 1) * (1 << 10));
            }
        }

        if (height % blockHeight) {
            gDPLoadSync(gfx++);
            if (!tileLoad) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT(blockWidth, byteSiz));
                }

                gSPScisTextureRectangle(gfx++, left << 2, top << 2, (left + blockWidth) << 2,
                                        (top + (height % blockHeight)) << 2, G_TX_RENDERTILE, s,
                                        ((height % blockHeight) - 1) << 5, dsdx, (64 - 1) * (1 << 10));
            } else {
                //! @bug, condition blocks switched around from what size would expect
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                gSPScisTextureRectangle(gfx++, left << 2, top << 2, (left + blockWidth) << 2,
                                        (top + (height % blockHeight)) << 2, G_TX_RENDERTILE, s, (height - 1) << 5,
                                        dsdx, (64 - 1) * (1 << 10));
            }
        }
    } else {
        for (i = 0; i < numBlocks; i++) {
            // FAKE?
            var = i + 1;
            gDPLoadSync(gfx++);
            if (!tileLoad) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight / 4,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT(blockWidth, byteSiz));
                }

                gSPScisTextureRectangle(gfx++, left << 2, (top + (i * blockHeight)) << 2, (left + blockWidth) << 2,
                                        (top + (var * blockHeight)) << 2, G_TX_RENDERTILE, s, 0, dsdx, 1 << 10);
            } else {
                //! @bug, condition blocks switched around from what size would expect
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                gSPScisTextureRectangle(gfx++, left << 2, (top + (i * blockHeight)) << 2, (left + blockWidth) << 2,
                                        (top + (var * blockHeight)) << 2, G_TX_RENDERTILE, s, (i * blockHeight) << 5,
                                        dsdx, 1 << 10);
            }
        }

        if (height % blockHeight) {
            gDPLoadSync(gfx++);
            if (!tileLoad) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight / 4,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                                 ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT(blockWidth, byteSiz));
                }

                gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + ((numBlocks * blockHeight))) << 2,
                                        (left + blockWidth) << 2,
                                        (s32) (top + (numBlocks * blockHeight) + (height % blockHeight)) << 2,
                                        G_TX_RENDERTILE, s, 0, dsdx, 1 << 10);
            } else {
                //! @bug, condition blocks switched around from what size would expect
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (numBlocks * blockHeight)) << 2,
                                        (left + blockWidth) << 2,
                                        (s32) (top + (numBlocks * blockHeight) + (height % blockHeight)) << 2,
                                        G_TX_RENDERTILE, s, (numBlocks * blockHeight) << 5, dsdx, 1 << 10);
            }
        }
    }

    return gfx;
}

Gfx* TextureUtils_DrawScaled(Gfx* gfx, TexturePtr texture, s32 left, s32 top, s32 width, u32 height, f32 scaleX,
                             f32 scaleY, s32 format, s32 size, s32 renderType, bool singleRowBlocks, bool mirrorS) {
    s32 i;
    s32 numBlocks;
    s32 blockHeight;
    s32 blockWidth = width;
    s32 pad[5];
    s32 s;
    s32 blockSize;
    s32 dsdx;
    s32 dtdy;
    s32 siz;
    s32 lineBytes;
    s32 incr;
    s32 shift;
    s32 byteSiz;
    f32 temp;
    s32 sTemp = 1;

    if (blockWidth & 3) {
        return gfx;
    }
    if ((scaleX == 0.0) || (scaleY == 0.0)) {
        return gfx;
    }

    switch (size) {
        case G_IM_SIZ_4b:
            siz = G_IM_SIZ_4b_LOAD_BLOCK;
            incr = G_IM_SIZ_4b_INCR;
            shift = G_IM_SIZ_4b_SHIFT;
            byteSiz = G_IM_SIZ_4b_BYTES;
            blockSize = 0x1000;
            break;
        case G_IM_SIZ_8b:
            siz = G_IM_SIZ_8b_LOAD_BLOCK;
            lineBytes = G_IM_SIZ_8b_LINE_BYTES;
            incr = G_IM_SIZ_8b_INCR;
            shift = G_IM_SIZ_8b_SHIFT;
            byteSiz = G_IM_SIZ_8b_BYTES;
            blockSize = 0x800;
            break;
        case G_IM_SIZ_16b:
            siz = G_IM_SIZ_16b_LOAD_BLOCK;
            lineBytes = G_IM_SIZ_16b_LINE_BYTES;
            incr = G_IM_SIZ_16b_INCR;
            shift = G_IM_SIZ_16b_SHIFT;
            byteSiz = G_IM_SIZ_16b_BYTES;
            blockSize = 0x400;
            break;
        case G_IM_SIZ_32b:
            siz = G_IM_SIZ_32b_LOAD_BLOCK;
            lineBytes = G_IM_SIZ_32b_LINE_BYTES;
            incr = G_IM_SIZ_32b_INCR;
            shift = G_IM_SIZ_32b_SHIFT;
            byteSiz = G_IM_SIZ_32b_BYTES;
            blockSize = 0x200;
            break;
        default:
            return gfx;
    }

    if (!singleRowBlocks) {
        blockHeight = blockSize / blockWidth;
        while (height < blockHeight / 2) {
            blockHeight /= 2;
        }
    } else {
        blockHeight = 1;
    }

    numBlocks = height / blockHeight;

    if (mirrorS != 0) {
        dsdx = -0x400;
        dtdy = 0x400;
        s = (blockWidth - sTemp) << 5;
    } else {
        dsdx = 0x400;
        dtdy = 0x400;
        s = 0;
    }

    switch (renderType) {
        case 1:
            gSPDisplayList(gfx++, D_3000088);
            break;
        case 2:
            gSPDisplayList(gfx++, D_3000100);
            break;
        case 3:
            gSPDisplayList(gfx++, D_3000138);
            break;
        case 0:
        default:
            gSPDisplayList(gfx++, D_3000050);
            break;
    }

    dsdx /= scaleX;
    dtdy /= scaleY;

    gDPSetTextureImage(gfx++, format, siz, blockWidth, texture);

    gDPSetTile(gfx++, format, siz, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

    if (size == G_IM_SIZ_4b) {
        gDPSetTile(gfx++, format, size, ((blockWidth >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTile(gfx++, format, size, ((blockWidth * lineBytes) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
    }

    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                   (blockHeight - 1) << G_TEXTURE_IMAGE_FRAC);

    temp = blockHeight * scaleY;

    for (i = 0; i < numBlocks; i++) {
        gDPLoadSync(gfx++);
        if (size == G_IM_SIZ_4b) {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight, ((blockWidth * blockHeight + incr) >> shift) - 1,
                         CALC_DXT_4b(blockWidth));
        } else {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight, ((blockWidth * blockHeight + incr) >> shift) - 1,
                         CALC_DXT(blockWidth, byteSiz));
        }

        gSPScisTextureRectangle(
            gfx++, left << 2, (top + (s32) (i * temp)) << 2, (left + (s32) (blockWidth * scaleX)) << 2,
            (top + (s32) ((i + 1) * (blockHeight * scaleY))) << 2, G_TX_RENDERTILE, s, 0, dsdx, dtdy);
    }

    if (height % blockHeight) {
        gDPLoadSync(gfx++);
        if (size == G_IM_SIZ_4b) {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                         ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT_4b(blockWidth));
        } else {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                         ((blockWidth * blockHeight + incr) >> shift) - 1, CALC_DXT(blockWidth, byteSiz));
        }

        gSPScisTextureRectangle(gfx++, left << 2, (top + (s32) (numBlocks * temp)) << 2,
                                (left + (s32) (blockWidth * scaleX)) << 2, (top + (s32) (height * scaleY)) << 2,
                                G_TX_RENDERTILE, s, 0, dsdx, dtdy);
    }

    return gfx;
}
