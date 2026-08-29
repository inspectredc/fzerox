#include "global.h"
#include "leo/mfs.h"
#include "course_edit.h"
#include "fzx_expansion_kit.h"
#include ASSET_HEADER(setup_gfx.h)
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

u16 sCourseEditHelpTex[228 * 180] = { 0 };

s32 sCourseEditOptionsMenuState = 0;
s32 sCourseEditOptionsIndex = 0;
s32 sCourseEditOptionsMenuHelpIndex = 0;

s32 sCourseEditOptionsPositions[][2] = {
    { 187, 68 }, { 187, 84 }, { 187, 112 }, { 187, 128 }, { 187, 144 }, { 0, 0 },
};

s32 sCourseEditOptionsTexOffsetHeight[][2] = {
    { 2, 17 }, { 19, 30 }, { 49, 17 }, { 66, 16 }, { 82, 17 }, { 99, 16 },
};

extern s32 gCourseEditOptions[6];
extern unk_800D6CA0 D_800D6CA0;

void CourseEditOptionsMenu_Update(void) {
    s32 prevIndex;
    bool optionsIndexUnchanged;
    Controller* controller;
    s32 prevHelpIndex;
    s32 prevIndex2;
    s32 pad;

    optionsIndexUnchanged = true;
    if (D_800D6CA0.state != COURSE_EDIT_OPTIONS_MENU) {
        return;
    }
    controller = &gControllers[gPlayerControlPorts[0]];
    switch (sCourseEditOptionsMenuState) {
        case COURSE_EDIT_OPTIONS_MAIN_MENU:
            prevIndex = sCourseEditOptionsIndex;
            EKController_UpdateVerticalOptionSlow(&sCourseEditOptionsIndex, 5, 1);

            if (prevIndex != sCourseEditOptionsIndex) {
                Audio_TriggerSystemSE(NA_SE_35);
                optionsIndexUnchanged = false;
            }
            if ((sCourseEditOptionsIndex < COURSE_EDIT_OPTION_CURSOR_SPEED) && optionsIndexUnchanged) {
                prevIndex = gCourseEditOptions[sCourseEditOptionsIndex];

                EKController_UpdateHorizontalOption(&gCourseEditOptions[sCourseEditOptionsIndex], 1, 1);

                if (prevIndex != gCourseEditOptions[sCourseEditOptionsIndex]) {
                    Audio_TriggerSystemSE(NA_SE_30);
                }
                if ((sCourseEditOptionsIndex == COURSE_EDIT_OPTION_CONTROL_POINT_INFO) && (prevIndex == 1) && (gCourseEditOptions[COURSE_EDIT_OPTION_CONTROL_POINT_INFO] == 0)) {
                    sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_SHOW_POINT_SELECT_HELP;
                }
                if ((sCourseEditOptionsIndex == COURSE_EDIT_OPTION_BGM) && (prevIndex == 0) && (gCourseEditOptions[COURSE_EDIT_OPTION_BGM] == 1)) {
                    Audio_EditorBgmRestart();
                }
                if ((sCourseEditOptionsIndex == COURSE_EDIT_OPTION_BGM) && (prevIndex == 1) && (gCourseEditOptions[COURSE_EDIT_OPTION_BGM] == 0)) {
                    Audio_EditorBgmStop();
                }
            }
            break;
        case COURSE_EDIT_OPTIONS_HELP_MENU:
            prevHelpIndex = sCourseEditOptionsMenuHelpIndex;
            EKController_UpdateVerticalOptionSlow(&sCourseEditOptionsMenuHelpIndex, 1, 1);
            if (prevHelpIndex != sCourseEditOptionsMenuHelpIndex) {
                Audio_TriggerSystemSE(NA_SE_35);
            }
            break;
        case COURSE_EDIT_OPTIONS_CURSOR_SPEED_MENU:
            prevIndex = gCourseEditOptions[COURSE_EDIT_OPTION_CURSOR_SPEED];
            EKController_UpdateHorizontalOption(&gCourseEditOptions[COURSE_EDIT_OPTION_CURSOR_SPEED], 8, 0);
            if (prevIndex != gCourseEditOptions[COURSE_EDIT_OPTION_CURSOR_SPEED]) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        case COURSE_EDIT_OPTIONS_SHOW_POINT_SELECT_HELP:
            prevIndex2 = sCourseEditOptionsIndex;
            EKController_UpdateVerticalOptionSlow(&sCourseEditOptionsIndex, 5, 1);
            if (prevIndex2 != sCourseEditOptionsIndex) {
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_MAIN_MENU;
            }
            prevIndex2 = gCourseEditOptions[sCourseEditOptionsIndex];
            EKController_UpdateHorizontalOption(&gCourseEditOptions[sCourseEditOptionsIndex], 1, 1);
            if (prevIndex2 != gCourseEditOptions[sCourseEditOptionsIndex]) {
                Audio_TriggerSystemSE(NA_SE_30);
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_MAIN_MENU;
            }
            break;
    }
    if (controller->buttonPressed & BTN_A) {
        switch (sCourseEditOptionsMenuState) {
            case COURSE_EDIT_OPTIONS_MAIN_MENU:
                if (sCourseEditOptionsIndex == COURSE_EDIT_OPTION_CURSOR_SPEED) {
                    Audio_TriggerSystemSE(NA_SE_36);
                    sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_CURSOR_SPEED_MENU;
                }
                if (sCourseEditOptionsIndex == COURSE_EDIT_OPTION_HELP) {
                    Audio_TriggerSystemSE(NA_SE_36);
                    sCourseEditOptionsMenuHelpIndex = 0;
                    sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_HELP_MENU;
                }
                break;
            case COURSE_EDIT_OPTIONS_HELP_MENU:
                Audio_TriggerSystemSE(NA_SE_36);
                {
                    u8* helpTextures[2] = { aExpansionKitEditControlHelpTex, aExpansionKitCameraControlHelpTex };

                    mio0Decode(Segment_SegmentedToVirtual(helpTextures[sCourseEditOptionsMenuHelpIndex]), sCourseEditHelpTex);
                }
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_SHOW_HELP_SCREEN;
                break;
            case COURSE_EDIT_OPTIONS_SHOW_POINT_SELECT_HELP:
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_MAIN_MENU;
                break;
            case COURSE_EDIT_OPTIONS_CURSOR_SPEED_MENU:
                Audio_TriggerSystemSE(NA_SE_36);
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_MAIN_MENU;
                break;
        }
    }
    if (controller->buttonPressed & BTN_B) {
        switch (sCourseEditOptionsMenuState) {
            case COURSE_EDIT_OPTIONS_MAIN_MENU:
                Audio_TriggerSystemSE(NA_SE_37);
                func_807683B8(MFS_ENTRY_WORKING_DIR, "OPTION", "OPT", gCourseEditOptions, sizeof(gCourseEditOptions), 0, 0xFF, true);
                D_800D6CA0.state = 0x38;
                break;
            case COURSE_EDIT_OPTIONS_HELP_MENU:
            case COURSE_EDIT_OPTIONS_CURSOR_SPEED_MENU:
                Audio_TriggerSystemSE(NA_SE_37);
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_MAIN_MENU;
                break;
            case COURSE_EDIT_OPTIONS_SHOW_HELP_SCREEN:
                Audio_TriggerSystemSE(NA_SE_37);
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_HELP_MENU;
                break;
            case COURSE_EDIT_OPTIONS_SHOW_POINT_SELECT_HELP:
                sCourseEditOptionsMenuState = COURSE_EDIT_OPTIONS_MAIN_MENU;
                break;
        }
    }
}

void CourseEditOptionsMenu_DrawPointSelectHelp(Gfx** gfxP) {
    s32 top;
    Gfx* gfx;
    s32 width;
    s32 left;
    s32 i;

    gfx = *gfxP;
    if (sCourseEditOptionsMenuState != COURSE_EDIT_OPTIONS_SHOW_POINT_SELECT_HELP) {
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

extern unk_80128C94* D_80128C94;
extern unk_80128C94 D_6000000;

void CourseEditOptionsMenu_DrawHelpScreen(Gfx** gfxP) {
    Gfx* gfx2;
    Gfx* gfx;
    s32 i;
    s32 left;
    s32 top;

    gfx = *gfxP;
    if (sCourseEditOptionsMenuState != COURSE_EDIT_OPTIONS_SHOW_HELP_SCREEN) {
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

    gfx2 = D_80128C94->unk_110C8;

    for (i = 0; i < 180; i++) {
        gDPLoadTextureBlock(gfx2++, K0_TO_PHYS(sCourseEditHelpTex + i * 228), G_IM_FMT_RGBA, G_IM_SIZ_16b, 228, 1, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx2++, left << 2, top << 2, (left + 228) << 2, (top + 1) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
        top++;
    }
    gSPEndDisplayList(gfx2++);

    gSPDisplayList(gfx++, D_6000000.unk_110C8);

    *gfxP = gfx;
}

void CourseEditOptionsMenu_DrawHelpMenu(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 top;
    s32 i;

    gfx = *gfxP;
    if (sCourseEditOptionsMenuState != COURSE_EDIT_OPTIONS_HELP_MENU) {
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

    gDPLoadTextureBlock_4b(gfx++, aExpansionKitHelpMenuTex + (((sCourseEditOptionsMenuHelpIndex * 0x10 + 4) * 112) / 2), G_IM_FMT_I, 112,
                           16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, 104 << 2, ((sCourseEditOptionsMenuHelpIndex * 0x10) + 138) << 2, 216 << 2,
                        ((sCourseEditOptionsMenuHelpIndex * 0x10) + 138 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

void CourseEditOptionsMenu_DrawCursorSpeedMenu(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 top;
    Gfx* fake_var;

    gfx = *gfxP;
    if (sCourseEditOptionsMenuState != COURSE_EDIT_OPTIONS_CURSOR_SPEED_MENU) {
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

    left = (gCourseEditOptions[COURSE_EDIT_OPTION_CURSOR_SPEED] * 0xC) + 0x68;
    top += 23;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

    gDPLoadTextureBlock_4b(gfx++, aCourseEditCursorSpeedMarkerTex, G_IM_FMT_I, 16, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    // FAKE
    fake_var = gfx;

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    left = (gCourseEditOptions[COURSE_EDIT_OPTION_CURSOR_SPEED] * 0xC) + 0x6B;
    top = 153;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 10) << 2, (top + 6) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

void CourseEditOptionsMenu_Draw(Gfx** gfxP) {
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

    if (sCourseEditOptionsMenuState != COURSE_EDIT_OPTIONS_SHOW_HELP_SCREEN) {
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

    gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionsMenuTex + (144 * sCourseEditOptionsTexOffsetHeight[5][0]) / 2, G_IM_FMT_I, 144,
                           sCourseEditOptionsTexOffsetHeight[5][1], 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, (sCourseEditOptionsTexOffsetHeight[5][0] + 62) << 2, (left + 144) << 2,
                        (sCourseEditOptionsTexOffsetHeight[5][0] + sCourseEditOptionsTexOffsetHeight[5][1] + 62) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gDPPipeSync(gfx++);

    if (sCourseEditOptionsMenuState == COURSE_EDIT_OPTIONS_MAIN_MENU) {
        gfx = func_i3_80059EC0(gfx, 3);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 210, 0, 255);
    }

    gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionsMenuTex + (144 * sCourseEditOptionsTexOffsetHeight[sCourseEditOptionsIndex][0]) / 2,
                           G_IM_FMT_I, 144, sCourseEditOptionsTexOffsetHeight[sCourseEditOptionsIndex][1], 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, (sCourseEditOptionsTexOffsetHeight[sCourseEditOptionsIndex][0] + 62) << 2, (left + 144) << 2,
                        (sCourseEditOptionsTexOffsetHeight[sCourseEditOptionsIndex][0] + sCourseEditOptionsTexOffsetHeight[sCourseEditOptionsIndex][1] + 62) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);

    for (i = 0; i < 4; i++) {
        gDPPipeSync(gfx++);
        if (gCourseEditOptions[i] != 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 40, 75, 255);

            gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionOnTex, G_IM_FMT_I, 48, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

            gDPLoadTextureBlock_4b(gfx++, aExpansionKitOptionOffTex, G_IM_FMT_I, 48, 12, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }

        if (i == sCourseEditOptionsIndex) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 210, 0, 255);
        }
        left = sCourseEditOptionsPositions[i][0];
        top = sCourseEditOptionsPositions[i][1];

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    CourseEditOptionsMenu_DrawHelpMenu(&gfx);
    CourseEditOptionsMenu_DrawHelpScreen(&gfx);
    CourseEditOptionsMenu_DrawPointSelectHelp(&gfx);
    CourseEditOptionsMenu_DrawCursorSpeedMenu(&gfx);
    *gfxP = gfx;
}
