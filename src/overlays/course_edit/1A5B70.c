#include "global.h"
#include "leo/mfs.h"
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

u16 D_xk2_80105540[228 * 180] = { 0 };

s32 D_xk2_801195E0 = 0;
s32 D_xk2_801195E4 = 0;
s32 D_xk2_801195E8 = 0;

s32 D_xk2_801195EC[][2] = {
    { 187, 68 }, { 187, 84 }, { 187, 112 }, { 187, 128 }, { 187, 144 }, { 0, 0 },
};

s32 D_xk2_8011961C[][2] = {
    { 2, 17 }, { 19, 30 }, { 49, 17 }, { 66, 16 }, { 82, 17 }, { 99, 16 },
};

extern s32 D_800D11C8[6];
extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F40B0(void) {
    s32 sp54;
    bool sp50;
    Controller* sp4C;
    s32 sp48;
    s32 sp44;
    s32 pad;

    sp50 = true;
    if (D_800D6CA0.unk_08 != 4) {
        return;
    }
    sp4C = &gControllers[gPlayerControlPorts[0]];
    switch (D_xk2_801195E0) {
        case 0:
            sp54 = D_xk2_801195E4;
            func_xk1_8002DBD4(&D_xk2_801195E4, 5, 1);

            if (sp54 != D_xk2_801195E4) {
                Audio_TriggerSystemSE(NA_SE_35);
                sp50 = false;
            }
            if ((D_xk2_801195E4 < 4) && sp50) {
                sp54 = D_800D11C8[D_xk2_801195E4];

                func_xk1_8002DAE0(&D_800D11C8[D_xk2_801195E4], 1, 1);

                if (sp54 != D_800D11C8[D_xk2_801195E4]) {
                    Audio_TriggerSystemSE(NA_SE_30);
                }
                if ((D_xk2_801195E4 == 0) && (sp54 == 1) && (D_800D11C8[0] == 0)) {
                    D_xk2_801195E0 = 3;
                }
                if ((D_xk2_801195E4 == 2) && (sp54 == 0) && (D_800D11C8[2] == 1)) {
                    Audio_EditorBgmRestart();
                }
                if ((D_xk2_801195E4 == 2) && (sp54 == 1) && (D_800D11C8[2] == 0)) {
                    Audio_EditorBgmStop();
                }
            }
            break;
        case 1:
            sp48 = D_xk2_801195E8;
            func_xk1_8002DBD4(&D_xk2_801195E8, 1, 1);
            if (sp48 != D_xk2_801195E8) {
                Audio_TriggerSystemSE(NA_SE_35);
            }
            break;
        case 4:
            sp54 = D_800D11C8[4];
            func_xk1_8002DAE0(&D_800D11C8[4], 8, 0);
            if (sp54 != D_800D11C8[4]) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        case 3:
            sp44 = D_xk2_801195E4;
            func_xk1_8002DBD4(&D_xk2_801195E4, 5, 1);
            if (sp44 != D_xk2_801195E4) {
                D_xk2_801195E0 = 0;
            }
            sp44 = D_800D11C8[D_xk2_801195E4];
            func_xk1_8002DAE0(&D_800D11C8[D_xk2_801195E4], 1, 1);
            if (sp44 != D_800D11C8[D_xk2_801195E4]) {
                Audio_TriggerSystemSE(NA_SE_30);
                D_xk2_801195E0 = 0;
            }
            break;
    }
    if (sp4C->buttonPressed & BTN_A) {
        switch (D_xk2_801195E0) {
            case 0:
                if (D_xk2_801195E4 == 4) {
                    Audio_TriggerSystemSE(NA_SE_36);
                    D_xk2_801195E0 = 4;
                }
                if (D_xk2_801195E4 == 5) {
                    Audio_TriggerSystemSE(NA_SE_36);
                    D_xk2_801195E8 = 0;
                    D_xk2_801195E0 = 1;
                }
                break;
            case 1:
                Audio_TriggerSystemSE(NA_SE_36);
                {
                    u8* sp38[2] = { aExpansionKitEditControlHelpTex, aExpansionKitCameraControlHelpTex };

                    mio0Decode(Segment_SegmentedToVirtual(sp38[D_xk2_801195E8]), D_xk2_80105540);
                }
                D_xk2_801195E0 = 2;
                break;
            case 3:
                D_xk2_801195E0 = 0;
                break;
            case 4:
                Audio_TriggerSystemSE(NA_SE_36);
                D_xk2_801195E0 = 0;
                break;
        }
    }
    if (sp4C->buttonPressed & BTN_B) {
        switch (D_xk2_801195E0) {
            case 0:
                Audio_TriggerSystemSE(NA_SE_37);
                func_807683B8(MFS_ENTRY_WORKING_DIR, "OPTION", "OPT", D_800D11C8, sizeof(D_800D11C8), 0, 0xFF, true);
                D_800D6CA0.unk_08 = 0x38;
                break;
            case 1:
            case 4:
                Audio_TriggerSystemSE(NA_SE_37);
                D_xk2_801195E0 = 0;
                break;
            case 2:
                Audio_TriggerSystemSE(NA_SE_37);
                D_xk2_801195E0 = 1;
                break;
            case 3:
                D_xk2_801195E0 = 0;
                break;
        }
    }
}

extern Gfx D_8014940[];
extern Gfx D_80149A0[];

void func_xk2_800F4580(Gfx** gfxP) {
    s32 top;
    Gfx* gfx;
    s32 width;
    s32 left;
    s32 i;

    gfx = *gfxP;
    if (D_xk2_801195E0 != 3) {
        return;
    }

    left = 80;
    top = 120;

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 0, 0, 1) << 16 | GPACK_RGBA5551(255, 0, 0, 1));
    gDPFillRectangle(gfx++, (left - 2), (top - 2), (left + 160 + 2), (top + 56 + 2));

    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(gfx++, left, top, (left + 160), (top + 56));
    gSPDisplayList(gfx++, D_8014940);

    for (i = 0; i < 56; i++) {

        gDPLoadTextureBlock_4b(gfx++, aExpansionKitPointSelectHelpTex + ((i * 160) / 2), G_IM_FMT_I, 160, 1, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 160) << 2, (top + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        top++;
    }
    *gfxP = gfx;
}

extern Gfx D_3000510[];
extern unk_80128C94* D_80128C94;
extern unk_80128C94 D_6000000;

extern u16 D_xk2_80105540[];
extern s32 D_xk2_801195E0;

void func_xk2_800F47FC(Gfx** gfxP) {
    Gfx* var_v0;
    Gfx* gfx;
    s32 i;
    s32 left;
    s32 top;

    gfx = *gfxP;
    if (D_xk2_801195E0 != 2) {
        return;
    }
    left = 46;
    top = 30;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 245, 70, 0, 255);
    gSPTextureRectangle(gfx++, (left - 4) << 2, (top - 4) << 2, (left + 228 + 4) << 2, (top + 180 + 4) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 48, 77, 83, 255);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + 228 + 2) << 2, (top + 180 + 2) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_8014940);

    var_v0 = D_80128C94->unk_110C8;

    for (i = 0; i < 180; i++) {
        gDPLoadTextureBlock(var_v0++, K0_TO_PHYS(D_xk2_80105540 + i * 228), G_IM_FMT_RGBA, G_IM_SIZ_16b, 228, 1, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(var_v0++, left << 2, top << 2, (left + 228) << 2, (top + 1) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
        top++;
    }
    gSPEndDisplayList(var_v0++);

    gSPDisplayList(gfx++, D_6000000.unk_110C8);

    *gfxP = gfx;
}

void func_xk2_800F4AF8(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 top;
    s32 i;

    gfx = *gfxP;
    if (D_xk2_801195E0 != 1) {
        return;
    }
    left = 96;
    top = 134;

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(240, 70, 0, 1) << 16 | GPACK_RGBA5551(240, 70, 0, 1));
    gDPFillRectangle(gfx++, (left - 2), (top - 2), (left + 128 + 2), (top + 42 + 2));

    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(gfx++, left, top, (left + 128), (top + 42));
    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    left = 104;

    for (i = 0; i < 42; i++) {
        gDPLoadTextureBlock_4b(gfx++, aExpansionKitHelpMenuTex + ((i * 112) / 2), G_IM_FMT_I, 112, 1, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 112) << 2, (top + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        top++;
    }

    gDPPipeSync(gfx++);
    gfx = func_i3_80059EC0(gfx, 3);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

    gDPLoadTextureBlock_4b(gfx++, aExpansionKitHelpMenuTex + (((D_xk2_801195E8 * 0x10 + 4) * 112) / 2), G_IM_FMT_I, 112,
                           16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, 104 << 2, ((D_xk2_801195E8 * 0x10) + 138) << 2, 216 << 2,
                        ((D_xk2_801195E8 * 0x10) + 138 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

extern s32 D_xk2_801195E0;

void func_xk2_800F4EB8(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 top;
    Gfx* fake_var;

    gfx = *gfxP;
    if (D_xk2_801195E0 != 4) {
        return;
    }

    left = 96;
    top = 134;

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(240, 70, 0, 1) << 16 | GPACK_RGBA5551(240, 70, 0, 1));
    gDPFillRectangle(gfx++, (left - 2), (top - 2), (left + 128 + 2), (top + 42 + 2));
    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(gfx++, left, top, (left + 128), (top + 42));
    gSPDisplayList(gfx++, D_8014940);

    left = 104;
    top = 138;

    gDPLoadTextureBlock_4b(gfx++, aCourseEditCursorSpeedSliderTex, G_IM_FMT_I, 112, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 112) << 2, (top + 24) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    left = (D_800D11C8[4] * 0xC) + 0x68;
    top += 23;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

    gDPLoadTextureBlock_4b(gfx++, aCourseEditCursorSpeedMarkerTex, G_IM_FMT_I, 16, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    // FAKE
    fake_var = gfx;

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    left = (D_800D11C8[4] * 0xC) + 0x6B;
    top = 153;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 10) << 2, (top + 6) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

extern Gfx D_3000540[];

void func_xk2_800F5250(Gfx** gfxP) {
    s32 i;
    s32 left;
    s32 top;
    Gfx* gfx;

    gfx = *gfxP;

    left = 72;
    top = 58;

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 200, 1) << 16 | GPACK_RGBA5551(0, 255, 200, 1));
    gDPFillRectangle(gfx++, left - 2, top - 2, left + 176 + 2, top + 124 + 2);
    gDPPipeSync(gfx++);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(50, 80, 140, 1) << 16 | GPACK_RGBA5551(50, 80, 140, 1));
    gDPFillRectangle(gfx++, left, top, left + 176, top + 124);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    left = 85;
    top = 56;

    if (D_xk2_801195E0 != 2) {
        for (i = 0; i < 19; i++) {
            gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionsMenuTex + (i * (144 * 6)) / 2, G_IM_FMT_I, 144, 6, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, left << 2, (top + 6) << 2, (left + 144) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
            top += 6;
        }
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 145, 140, 255, 255);

    gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionsMenuTex + (144 * D_xk2_8011961C[5][0]) / 2, G_IM_FMT_I, 144,
                           D_xk2_8011961C[5][1], 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, (D_xk2_8011961C[5][0] + 62) << 2, (left + 144) << 2,
                        (D_xk2_8011961C[5][0] + D_xk2_8011961C[5][1] + 62) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gDPPipeSync(gfx++);

    if (D_xk2_801195E0 == 0) {
        gfx = func_i3_80059EC0(gfx, 3);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 210, 0, 255);
    }

    gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionsMenuTex + (144 * D_xk2_8011961C[D_xk2_801195E4][0]) / 2,
                           G_IM_FMT_I, 144, D_xk2_8011961C[D_xk2_801195E4][1], 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, (D_xk2_8011961C[D_xk2_801195E4][0] + 62) << 2, (left + 144) << 2,
                        (D_xk2_8011961C[D_xk2_801195E4][0] + D_xk2_8011961C[D_xk2_801195E4][1] + 62) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);

    for (i = 0; i < 4; i++) {
        gDPPipeSync(gfx++);
        if (D_800D11C8[i] != 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 40, 75, 255);

            gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionOnTex, G_IM_FMT_I, 48, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

            gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionOffTex, G_IM_FMT_I, 48, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }

        if (i == D_xk2_801195E4) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 210, 0, 255);
        }
        left = D_xk2_801195EC[i][0];
        top = D_xk2_801195EC[i][1];

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    func_xk2_800F4AF8(&gfx);
    func_xk2_800F47FC(&gfx);
    func_xk2_800F4580(&gfx);
    func_xk2_800F4EB8(&gfx);
    *gfxP = gfx;
}
