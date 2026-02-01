#include "global.h"
#include "leo/mfs.h"
#include "fzx_game.h"
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER(setup_gfx.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)

s32 D_xk1_8003A5D0;
unk_8003A5D8 D_xk1_8003A5D8[102];
u16 D_xk1_8003B430[900];
s32 D_xk1_8003BB38;
s32 (*D_xk1_8003BB3C)(u8*, u8*);
s32 D_xk1_8003BB40;
s32 D_xk1_8003BB44;

s32 D_xk1_80032BD0 = 4;
s32 D_xk1_80032BD4 = 0;
s32 D_xk1_80032BD8 = 0;
s32 D_xk1_80032BDC = 0;
UNUSED s32 D_xk1_80032BE0 = 8;
s32 D_xk1_80032BE4 = 24;
s32 D_xk1_80032BE8 = 52;
s32 D_xk1_80032BEC = 0;
s32* D_xk1_80032BF0 = NULL;
s32* D_xk1_80032BF4 = NULL;
s32 D_xk1_80032BF8 = 0;

void func_xk1_8002AED0(void) {
    s32 i;

    // TODO: Move to appropriate place
    PRINTF("CURSOR POINTER IS NOT INITIALIZED !!\n");
    PRINTF("FILELISTc\n");
    PRINTF("FILE LISTS %d\n");

    for (i = 0; i < 102; i++) {
        D_xk1_8003A5D8[i].extension[3] = '\0';
    }
}

void func_xk1_8002AF10(s32 arg0) {
    D_xk1_80032BD0 = arg0;
}

void func_xk1_8002AF1C(Gfx** gfxP, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_a0;
    s32 var_a1;
    s32 i;
    s32 j;
    Gfx* gfx;

    gfx = *gfxP;
    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, aExpansionKitFileMenuBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 24, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    for (i = 0; i < arg4; i++) {
        for (j = 0; j < arg3; j++) {
            var_a0 = 8;
            var_a1 = 8;
            if (j == 0) {
                var_a0 = 0;
            }
            if (j == arg3 - 1) {
                var_a0 = 0x10;
            }
            if (i == 0) {
                var_a1 = 0;
            }
            if (i == arg4 - 1) {
                var_a1 = 0x10;
            }
            gSPTextureRectangle(gfx++, (arg1 + (j * 8)) << 2, (arg2 + (i * 8)) << 2, (arg1 + ((j + 1) * 8)) << 2,
                                (arg2 + ((i + 1) * 8) << 2), 0, var_a0 << 5, var_a1 << 5, 1 << 10, 1 << 10);
        }
    }
    *gfxP = gfx;
}

void func_xk1_8002B150(s32 arg0, s32 arg1, s32* arg2, s32* arg3) {
    D_xk1_80032BDC = 0;
    D_xk1_80032BE4 = arg0;
    D_xk1_80032BE8 = arg1;
    D_xk1_80032BF0 = arg2;
    D_xk1_80032BF4 = arg3;
}

extern u32 gGameFrameCount;
extern s32 gGameMode;
extern s32 D_80119880;

Gfx* func_xk1_8002B17C(Gfx* gfx, s32 arg1) {
    s32 temp_s4;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_t1;
    s32 sp11C;
    s32 sp4C;
    s32 i;

    if (D_xk1_80032BF0 == NULL) {
        return gfx;
    }
    if (D_xk1_80032BD4 == NULL) {
        return gfx;
    }

    sp11C = D_xk1_80032BDC;
    gSPDisplayList(gfx++, D_8014940);

    var_t1 = D_xk1_8003A5D0;
    if (D_xk1_8003A5D0 > 13) {
        var_t1 = 13;
    }
    func_xk1_8002AF1C(&gfx, D_xk1_80032BE4 - 8, D_xk1_80032BE8 - 8, arg1 + 2, var_t1 + 2);

    gDPPipeSync(gfx++);

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_xk1_80032BE4 - 10, D_xk1_80032BE8, (arg1 * 8) + D_xk1_80032BE4 + 2,
                  D_xk1_80032BE8 + 0x68);

    for (i = 0; i < D_xk1_8003A5D0; i++) {

        temp_s4 = ((i * 8) + D_xk1_80032BE8) - D_xk1_80032BEC;
        if (temp_s4 < (D_xk1_80032BE8 - 8)) {
            continue;
        }
        if (temp_s4 > (D_xk1_80032BE8 + 0x70)) {
            continue;
        }

        gSPDisplayList(gfx++, D_3000510);
        if (i == sp11C) {
            gDPSetPrimColor(gfx++, 0, 0, 190, 175, 255, 255);
        } else {
            if (D_xk1_8003A5D8[i].unk_22 != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 0);
            }
        }
        gSPTextureRectangle(gfx++, (D_xk1_80032BE4 - 2) << 2, temp_s4 << 2, ((arg1 * 8) + D_xk1_80032BE4 + 2) << 2,
                            (temp_s4 + 8) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);

        if (gGameMode == GAMEMODE_COURSE_EDIT) {
            if (i == sp11C) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
            } else {
                if (D_xk1_8003A5D8[i].unk_22 != 0) {
                    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                } else {
                    if (D_80119880 == 6) {
                        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0,
                                          TEXEL0);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    } else if (func_xk2_800EC234(&D_xk1_8003A5D8[i]) != 0) {
                        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0,
                                          TEXEL0);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
                    } else {
                        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0,
                                          TEXEL0);
                        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    }
                }
            }
        } else if (i == sp11C) {
            gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            if (func_xk3_801363F8(&D_xk1_8003A5D8[i]) != 0) {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        }

        gfx = func_xk1_8002924C(gfx, D_xk1_80032BE4, temp_s4, D_xk1_8003A5D8[i].name);
        if ((D_xk1_8003A5D8[i].extension[3] == 'E') && ((gGameFrameCount % 16) < 8)) {
            gSPDisplayList(gfx++, D_7020808);
            gSPTextureRectangle(gfx++, (D_xk1_80032BE4 + 0x1C) << 2, temp_s4 << 2, (D_xk1_80032BE4 + 0x24) << 2,
                                (temp_s4 + 8) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, aExpansionKitScrollArrowIndicatorTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);

    if (D_xk1_80032BEC != 0) {
        if (((gGameFrameCount % D_xk1_80032BD0) < (D_xk1_80032BD0 / 2))) {
            temp_v0 = D_xk1_80032BE4 + 0x18;
            temp_v1 = D_xk1_80032BE8 - 0x10;
            gSPTextureRectangle(gfx++, temp_v0 << 2, temp_v1 << 2, (temp_v0 + 16) << 2, (temp_v1 + 8) << 2, 0, 0,
                                16 << 5, 0x800, -0x800);
        }
    }

    if ((D_xk1_8003A5D0 >= 0xE) && (D_xk1_80032BEC < ((D_xk1_8003A5D0 * 8) - 0x68))) {
        if ((gGameFrameCount % D_xk1_80032BD0) < (D_xk1_80032BD0 / 2)) {
            temp_v0 = D_xk1_80032BE4 + 0x18;
            temp_v1 = D_xk1_80032BE8 + 0x70;
            gSPTextureRectangle(gfx++, temp_v0 << 2, temp_v1 << 2, (temp_v0 + 16) << 2, (temp_v1 + 8) << 2, 0, 0, 0,
                                0x800, 0x800);
        }
    }

    return gfx;
}

void func_xk1_8002BB50(void) {

    if (D_xk1_80032BDC >= ((D_xk1_80032BEC / 8) + 13)) {
        D_xk1_80032BEC += 8;
        return;
    }
    if (D_xk1_80032BDC < (D_xk1_80032BEC / 8)) {
        D_xk1_80032BEC -= 8;
    }
}

void func_xk1_8002BBA4(void) {
    s32 sp1C;

    sp1C = D_xk1_80032BDC;
    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z) {
        if (gGameMode == GAMEMODE_COURSE_EDIT) {
            func_xk1_8002DCC8(&D_xk1_80032BDC, D_xk1_8003A5D0 - 1, 0);
        } else {
            func_xk1_8002DDC4(&D_xk1_80032BDC, D_xk1_8003A5D0 - 1, 0);
        }
    } else {
        func_xk1_8002DBD4(&D_xk1_80032BDC, D_xk1_8003A5D0 - 1, 0);
    }

    if (sp1C != D_xk1_80032BDC) {
        Audio_TriggerSystemSE(NA_SE_35);
    }

    if (D_xk1_80032BDC >= ((D_xk1_80032BEC / 8) + 13)) {
        D_xk1_80032BEC += 8;
        return;
    }
    if (D_xk1_80032BDC < (D_xk1_80032BEC / 8)) {
        D_xk1_80032BEC -= 8;
    }
}

char* func_xk1_8002BCC4(void) {
    s32 var_v1;

    D_xk1_80032BD4 = 0;
    D_xk1_80032BD8 = 1;

    var_v1 = D_xk1_80032BDC;
    if (var_v1 > D_xk1_8003A5D0 - 1) {
        var_v1 = D_xk1_8003A5D0 - 1;
    }
    return D_xk1_8003A5D8[var_v1].name;
}

s32 func_xk1_8002BD14(void) {
    s32 var_v1;

    D_xk1_80032BD4 = 0;
    D_xk1_80032BD8 = 1;
    var_v1 = D_xk1_80032BDC;
    return var_v1;
}

void func_xk1_8002BD34(void) {
    Audio_TriggerSystemSE(NA_SE_37);
    D_xk1_80032BD4 = 0;
}

void func_xk1_8002BD58(void) {
    D_xk1_80032BD4 = 0;
}

extern MfsRamArea gMfsRamArea;

s32 func_xk1_8002BD64(u8 arg0, char* extension) {
    s32 i;
    s32 var_s0 = 0;
    s32 pad[3];
    s32 var_s6;
    u16* var_s1;
    unk_8003A5D8* temp_s0;

    var_s1 = D_xk1_8003B430;
    D_xk1_80032BF8 = 0;
    D_xk1_8003A5D8[0].attr = 0;
    D_xk1_8003A5D8[0].unk_22 = 1;
    D_xk1_8003A5D0 = arg0;

    if (Mfs_GetFilesPreparation(MFS_ENTRY_WORKING_DIR)) {
        return D_xk1_8003A5D0;
    }

    var_s6 = 0;
    while (true) {

        if ((*var_s1 = Mfs_GetNextFileInPreparedDir()) == MFS_ENTRY_DOES_NOT_EXIST) {
            break;
        }
        if ((extension == NULL) || (mfsStrnCmp(gMfsRamArea.directoryEntry[*var_s1].extension, extension, 3) == 0)) {
            temp_s0 = &D_xk1_8003A5D8[D_xk1_8003A5D0];
            temp_s0->unk_22 = 0;
            mfsStrCpy(temp_s0->name, gMfsRamArea.directoryEntry[*var_s1].name);
            mfsStrCpy(temp_s0->extension, gMfsRamArea.directoryEntry[*var_s1].extension);
            temp_s0->attr = gMfsRamArea.directoryEntry[*var_s1].attr;
            var_s6++;

            if (++D_xk1_8003A5D0 == 0x66) {
                break;
            }
        }

        var_s1++;
    }

    var_s0++;
    D_xk1_80032BEC = 0;
    D_xk1_80032BD4 = var_s0;
    func_xk1_8002CEF8(&D_xk1_8003A5D8[arg0], D_xk1_8003A5D0 - arg0, sizeof(unk_8003A5D8), func_xk1_8002CA98);
    D_xk1_80032BF8 = var_s0;

    if (var_s6 > 100) {
        for (i = 0; i < var_s6 - 100; i++) {
            temp_s0 = &D_xk1_8003A5D8[D_xk1_8003A5D0 - (i + 1)];
            Mfs_DeleteFileInDir(MFS_ENTRY_WORKING_DIR, temp_s0->name, temp_s0->extension, true);
            D_xk1_8003A5D0--;
        }
    }

    return D_xk1_8003A5D0;
}

s32 func_xk1_8002BFA4(void) {
    return D_xk1_8003A5D0;
}

// FAKE! -- requires some very specific permutation of temps for matching
void func_xk1_8002BFB0(Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    s32 x = 136;
    s32 y = 120;
    int new_var = 1 << 10;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + 50) << 2, y << 2, 0, 0, 0, new_var, 1 << 10);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 32) << 2, (x + 50) << 2, (y + 34) << 2, 0, 0, 0, 1 << 10, new_var);
    gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, 136 << 2, (y + 32) << 2, 0, 0, 0, new_var, new_var);
    gSPTextureRectangle(gfx++, (x + 48) << 2, y << 2, (x + 50) << 2, (y + 32) << 2, 0, 0, 0, new_var, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 48) << 2, (y + 32) << 2, 0, 0, 0, new_var, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPLoadTextureBlock_4b(gfx++, aExpansionKitYesNoTex, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 32) << 2, x << 2, 0, 0, 16 << 5, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, x << 2, x << 2, (x + 32) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPLoadTextureBlock(gfx++, aExpansionKitABButtonTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gfx++, (x + 32) << 2, y << 2, (x + 48) << 2, (y + 16) << 2, 0, 0, 16 << 5, new_var, 1 << 10);
    gSPTextureRectangle(gfx++, (x + 32) << 2, (y + 16) << 2, (x + 48) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    *gfxP = gfx;
}

Gfx* func_xk1_8002C420(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 var_a3;

    if (D_xk1_80032BD4 == 0) {
        return gfx;
    }
    if ((D_80119880 != 7) && (D_80119880 != 8)) {
        var_a3 = 0xB0;
    } else {
        var_a3 = 0x100;
    }
    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);

    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, (arg2 - 2) << 2, (arg1 + var_a3 + 2) << 2, arg2 << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, (arg2 + 16) << 2, (arg1 + var_a3 + 2) << 2, (arg2 + 16 + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, arg2 << 2, arg1 << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (arg1 + var_a3) << 2, arg2 << 2, (arg1 + var_a3 + 2) << 2, (arg2 + 16) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + var_a3) << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    if ((D_80119880 == 7) || (D_80119880 == 8)) {
        gfx = func_xk1_800264C0(gfx, arg1, arg2, 0xF);
    } else {
        gfx = func_xk1_800264C0(gfx, arg1, arg2, 0);
    }

    return gfx;
}

extern u8* D_xk1_800331F0[];

void func_xk1_8002C720(Gfx** gfxP, s32 arg1, s32 arg2, char* arg3, s32 arg4) {
    Gfx* gfx;
    s32 temp_a0;
    s32 temp_t4;
    u8 sp1B4[0x100];
    u8 spB4[0x100];

    gfx = *gfxP;
    if (D_xk1_80032BD8 == 0) {
        return;
    }
    func_xk1_80026830(arg3, sp1B4);
    mfsStrCpy(spB4, D_xk1_800331F0[arg4 + 1]);
    temp_a0 = mfsStrLen(sp1B4) + mfsStrLen(spB4);
    temp_t4 = temp_a0 * 8;
    arg1 = (((34 - temp_a0) / 2) * 8) + 24;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, (arg2 - 2) << 2, (arg1 + temp_t4 + 2) << 2, arg2 << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, (arg2 + 16) << 2, (arg1 + temp_t4 + 2) << 2, (arg2 + 16 + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (arg1 - 2) << 2, arg2 << 2, arg1 << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (arg1 + temp_t4) << 2, arg2 << 2, (arg1 + temp_t4 + 2) << 2, (arg2 + 16) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + temp_t4) << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 255);
    gfx = func_xk1_800262F4(gfx, arg1, arg2, sp1B4);
    arg1 += mfsStrLen(sp1B4) * 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk1_800264C0(gfx, arg1, arg2, arg4 + 1);

    *gfxP = gfx;
}

s32 func_xk1_8002CA80(void) {
    return D_xk1_80032BD8;
}

void func_xk1_8002CA8C(void) {
    D_xk1_80032BD8 = 0;
}

s32 func_xk1_8002CA98(u8* arg0, u8* arg1) {
    s32 i;

    for (i = 0; i < 8; i++, arg0++, arg1++) {
        if (*arg0 != *arg1) {
            return *arg0 - *arg1;
        }
    }

    return 0;
}

void func_xk1_8002CB30(s8* arg0, s8* arg1) {
    s32 temp_v0;
    s32 var_a0;
    s32 var_s1;
    s8* var_s0;
    s8* var_s1_2;
    s8* var_s2;
    s8* var_s5;
    s8* var_v1;

    var_s1 = arg1 - arg0;
    do {
        var_s0 = (((var_s1 / D_xk1_8003BB38) >> 1) * D_xk1_8003BB38) + arg0;
        var_s2 = var_s0;
        if (var_s1 >= D_xk1_8003BB44) {
            if (D_xk1_8003BB3C(arg0, var_s0) > 0) {
                var_s1_2 = arg0;
            } else {
                var_s1_2 = var_s0;
            }
            var_s5 = arg1 - D_xk1_8003BB38;
            if (D_xk1_8003BB3C(var_s1_2, var_s5) > 0) {
                if (var_s1_2 == arg0) {
                    var_s1_2 = var_s0;
                } else {
                    var_s1_2 = arg0;
                }
                if (D_xk1_8003BB3C(var_s1_2, var_s5) < 0) {
                    var_s1_2 = var_s5;
                }
            }
            if (var_s1_2 != var_s0) {
                var_a0 = D_xk1_8003BB38;
                do {
                    temp_v0 = *var_s0;
                    *var_s0 = *var_s1_2;
                    *var_s1_2 = temp_v0;
                    var_a0--;
                    var_s0++;
                    var_s1_2++;
                } while (var_a0 != 0);
            }
        }
        var_s0 = arg0;
        var_s1_2 = arg1 - D_xk1_8003BB38;

        while (true) {
            while ((var_s0 < var_s2) && (D_xk1_8003BB3C(var_s0, var_s2) <= 0)) {
                var_s0 += D_xk1_8003BB38;
            }
            while (var_s2 < var_s1_2) {
                if (D_xk1_8003BB3C(var_s2, var_s1_2) <= 0) {
                    var_s1_2 -= D_xk1_8003BB38;
                } else {
                    var_s5 = var_s0 + D_xk1_8003BB38;
                    if (var_s0 == var_s2) {
                        var_v1 = var_s1_2;
                        var_s2 = var_s1_2;
                    } else {
                        var_v1 = var_s1_2;
                        var_s1_2 -= D_xk1_8003BB38;
                    }
                    goto block_x;
                }
            }
            if (var_s0 == var_s2) {
                break;
            }
            var_v1 = var_s2;
            var_s2 = var_s0;
            var_s5 = var_s0;
            var_s1_2 -= D_xk1_8003BB38;
        block_x:

            var_a0 = D_xk1_8003BB38;
            do {
                temp_v0 = *var_s0;
                *var_s0 = *var_v1;
                *var_v1 = temp_v0;
                var_a0--;
                var_s0++;
                var_v1++;
            } while (var_a0 != 0);
            var_s0 = var_s5;
        }

        var_s0 = var_s2 + D_xk1_8003BB38;
        if ((var_s1 = (var_s2 - arg0)) <= arg1 - var_s0) {
            if ((var_s2 - arg0) >= D_xk1_8003BB40) {
                func_xk1_8002CB30(arg0, var_s2);
            }
            arg0 = var_s0;
            var_s1 = arg1 - var_s0;
        } else {
            if (arg1 - var_s0 >= D_xk1_8003BB40) {
                func_xk1_8002CB30(var_s0, arg1);
            }
            arg1 = var_s2;
        }
    } while (var_s1 >= D_xk1_8003BB40);
}

void func_xk1_8002CEF8(s8* arg0, s32 arg1, s32 arg2, s32 (*arg3)(u8*, u8*)) {
    s32 temp_v1;
    s8* temp_s7;
    s8* var_s0;
    s8* var_s1;
    s8* var_s2;
    s8* var_s4;
    s8* var_v0;
    s32 i;

    if (arg1 < 2) {
        return;
    }
    D_xk1_8003BB38 = arg2;
    D_xk1_8003BB3C = arg3;
    D_xk1_8003BB40 = D_xk1_8003BB38 * 4;
    D_xk1_8003BB44 = D_xk1_8003BB38 * 6;
    temp_s7 = arg0 + (arg1 * D_xk1_8003BB38);
    if (arg1 >= 4) {
        func_xk1_8002CB30(arg0, temp_s7);
        var_s2 = arg0 + D_xk1_8003BB40;
    } else {
        var_s2 = temp_s7;
    }
    var_s1 = arg0 + D_xk1_8003BB38;
    var_s0 = arg0;
    while (var_s1 < var_s2) {
        if (D_xk1_8003BB3C(var_s0, var_s1) > 0) {
            var_s0 = var_s1;
        }
        var_s1 += D_xk1_8003BB38;
    }

    var_s2 = arg0;
    var_s2 += D_xk1_8003BB38;

    if (var_s0 != arg0) {
        for (var_v0 = arg0; var_v0 < var_s2; var_v0++, var_s0++) {
            temp_v1 = *var_s0;
            *var_s0 = *var_v0;
            *var_v0 = temp_v1;
        }
    }
    var_s4 = arg0 + D_xk1_8003BB38;
    while (var_s4 < temp_s7) {
        var_s2 = var_s4 - D_xk1_8003BB38;
        while (D_xk1_8003BB3C(var_s2, var_s4) > 0) {
            var_s2 -= D_xk1_8003BB38;
        }

        var_s2 += D_xk1_8003BB38;
        if (var_s2 != var_s4) {
            var_s1 = (var_s4 + D_xk1_8003BB38) - 1;
            while (var_s1 >= var_s4) {
                var_v0 = var_s1;
                temp_v1 = *var_s1;
                var_s0 = var_s1 - D_xk1_8003BB38;
                var_s1--;
                while (var_s0 >= var_s2) {
                    *var_v0 = *var_s0;
                    var_v0 = var_s0;
                    var_s0 -= D_xk1_8003BB38;
                }
                *var_v0 = temp_v1;
            }
        }
        var_s4 += D_xk1_8003BB38;
    }
}

void func_xk1_8002D16C(void) {
    s32 i;
    s32 j;
    s32 k;
    char sp48[][6] = { "JACK", "QUEEN", "KING", "JOKER", "DD1-", "DD2-" };
    unk_8003A5D8* var_s0;

    D_xk1_80032BD4 = 1;
    k = 0;
    for (i = 0, var_s0 = D_xk1_8003A5D8; i < 6; i++) {
        for (j = 0; j < 6; j++, k++, var_s0++) {
            var_s0->attr = 0;
            var_s0->unk_22 = 0;
            var_s0->extension[3] = '\0';
            sprintf(var_s0->name, "%s%d", sp48[i], j + 1);
        }
    }
    D_xk1_8003A5D0 = k;
}

s32 func_xk1_8002D26C(void) {
    return D_xk1_80032BEC;
}

void func_xk1_8002D278(s32 arg0) {
    D_xk1_80032BEC = arg0;
}

void func_xk1_8002D284(s32 arg0) {
    D_xk1_8003A5D0 = arg0;
}

void func_xk1_8002D290(void) {
    D_xk1_80032BD4 = 1;
}

s32 func_xk1_8002D2A0(void) {
    if ((D_xk1_8003A5D0 > 13) && (D_xk1_80032BEC < ((D_xk1_8003A5D0 - 13) * 8))) {
        return 1;
    }
    return 0;
}

void func_xk1_8002D2E4(s32 arg0) {
    D_xk1_80032BDC = arg0;
}

s32 D_xk1_80032C20 = 0;

void func_xk1_8002D2F0(void) {
    s32 sp1C = D_xk1_80032C20;

    func_xk1_8002DBD4(&D_xk1_80032C20, 1, 1);
    if (sp1C != D_xk1_80032C20) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
}

void func_xk1_8002D340(Gfx** gfxP) {
    s32 x = 136;
    s32 y = 120;
    s32 width = 48;
    s32 spD0;
    Gfx* gfx;

    gfx = *gfxP;
    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        spD0 = 3;
    } else {
        spD0 = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + width + 2) << 2, y << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 32) << 2, (x + width + 2) << 2, (y + 32 + 2) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, x << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (x + width) << 2, y << 2, (x + width + 2) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    // FAKE
    x += 0;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);
    gSPTextureRectangle(gfx++, x << 2, ((D_xk1_80032C20 * 16) + 120) << 2, (x + width) << 2,
                        (((D_xk1_80032C20 + 1) * 16) + 120) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    x += 8;
    gSPDisplayList(gfx++, D_3000540);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPLoadTextureBlock_4b(gfx++, aExpansionKitYesNoTex, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (D_xk1_80032C20 == 0) {
        gfx = func_i3_80059EC0(gfx, spD0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }

    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 32) << 2, (y + 16) << 2, 0, 0, 16 << 5, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);

    if (D_xk1_80032C20 != 0) {
        gfx = func_i3_80059EC0(gfx, spD0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gSPTextureRectangle(gfx++, x << 2, (y + 16) << 2, (x + 32) << 2, (y + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}
