#include "global.h"
#include "records.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_camera.h"
#include "fzx_course.h"
#include "fzx_bordered_box.h"
#include "src/overlays/ovl_i2/transition.h"
#include "assets/segment_16C8A0.h"
#include "assets/segment_17B960.h"
#include "assets/segment_2B9EA0.h"

s32 sRecordsState;
s32 sUnlockedCourseCount;
s16 sRecordsMenuIndexValid[4];
BorderedBoxWidget* sRecordsMenuBox;
BorderedBoxWidget* sRecordsClearConfirmBox;
s16 sRecordsHighlightedMenuIndex;
s16 sRecordsToCourseSelectMenuIndex;
s16 sRecordsYesNoIndex;
s16 sRecordsClearType;
s16 sGhostMarkerState;
s16 sGhostMarkerTopAlpha;
s16 sGhostMarkerBottomAlpha;
s16 sRecordsStopStateUpdate;
GhostMarkerRenderInfo* sGhostMarkerRenderInfo;
GhostMarkerRenderInfo sGhostMarkerRenderInfos[2];

s32 sRecordsCourseIndex = 0;

RecordsMenuInfo sRecordsMenuInfo[] = {
    { RECORDS_MENU_CHANGE_COURSE,
      { aMenuChangeCourseTex, TEX_WIDTH(aMenuChangeCourseTex), TEX_HEIGHT(aMenuChangeCourseTex) } },
    { RECORDS_MENU_QUIT, { aMenuQuitTex, TEX_WIDTH(aMenuQuitTex), TEX_HEIGHT(aMenuQuitTex) } },
    { RECORDS_MENU_CLEAR_RECORD,
      { aMenuClearRecordTex, TEX_WIDTH(aMenuClearRecordTex), TEX_HEIGHT(aMenuClearRecordTex) } },
    { RECORDS_MENU_CLEAR_GHOST, { aMenuClearGhostTex, TEX_WIDTH(aMenuClearGhostTex), TEX_HEIGHT(aMenuClearGhostTex) } },
};

TextureInfo sRecordsClearTextureInfos[] = {
    { aMenuEraseCourseSavedData1Tex, TEX_WIDTH(aMenuEraseCourseSavedData1Tex),
      TEX_HEIGHT(aMenuEraseCourseSavedData1Tex) },
    { aMenuEraseCourseSavedData2Tex, TEX_WIDTH(aMenuEraseCourseSavedData2Tex),
      TEX_HEIGHT(aMenuEraseCourseSavedData2Tex) },
};

TextureInfo sRecordsYesNoTextureInfos[] = {
    { aMenuNoTex, TEX_WIDTH(aMenuNoTex), TEX_HEIGHT(aMenuNoTex) },
    { aMenuYesTex, TEX_WIDTH(aMenuYesTex), TEX_HEIGHT(aMenuYesTex) },
};

extern s16 D_800CCFE8;
extern s8 gGamePaused;
extern s32 D_i2_80106F10;
extern s32 gDifficulty;

void Records_Init(void) {
    D_800CCFE8 = D_i2_80106F10 = 3;
    gGamePaused = false;
    gDifficulty = MASTER;
    gRacers[0].character = CAPTAIN_FALCON;
    Course_Init();
    func_i3_80116C4C();
    Racer_Init();
    Camera_Init();
    func_8007F4E0(COURSE_CONTEXT()->courseData.venue, COURSE_CONTEXT()->courseData.skybox);
    Background_Init();
    Course_LandminesViewInteractDataInit();
    Course_JumpsViewInteractDataInit();
    Course_DecorationsViewInteractDataInit();
    Course_EffectsViewInteractDataInit(false);
    Records_InitData();
}

extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;
extern s32 gCourseIndex;

void Records_InitData(void) {
    s32 i;
    RecordsMenuInfo* recordsOption;

    sRecordsCourseIndex = gCourseIndex;
    if ((gUnlockableLevel == 0) && !gSettingEverythingUnlocked) {
        sUnlockedCourseCount = 18;
    } else {
        sUnlockedCourseCount = 24;
    }

    for (i = 0; i < 4; i++) {
        switch (sRecordsMenuInfo[i].menuOption) {
            case RECORDS_MENU_CLEAR_RECORD:
                if (Records_CourseHasNoRecords(sRecordsCourseIndex)) {
                    sRecordsMenuIndexValid[i] = false;
                } else {
                    sRecordsMenuIndexValid[i] = true;
                }
                break;
            case RECORDS_MENU_CLEAR_GHOST:
                if (Records_CourseHasGhost(sRecordsCourseIndex)) {
                    sRecordsMenuIndexValid[i] = true;
                    sGhostMarkerState = 1;
                    sGhostMarkerTopAlpha = sGhostMarkerBottomAlpha = 255;
                } else {
                    sRecordsMenuIndexValid[i] = false;
                    sGhostMarkerState = 0;
                }
                break;
            case RECORDS_MENU_CHANGE_COURSE:
                sRecordsToCourseSelectMenuIndex = i;
                sRecordsMenuIndexValid[i] = true;
                break;
            default:
                sRecordsMenuIndexValid[i] = true;
                break;
        }
    }
    sRecordsState = RECORDS_STATE_VIEW_RECORDS;
    sRecordsStopStateUpdate = false;
    func_80078104(aMenuTextTLUT, TEX_SIZE(aMenuTextTLUT, sizeof(u16)), 0, 0, false);

    recordsOption = sRecordsMenuInfo;
    for (i = 0; i < 4; i++, recordsOption++) {
        func_80078104(recordsOption->textureInfo.texture,
                      recordsOption->textureInfo.width * recordsOption->textureInfo.height * sizeof(u8), 0, 1, false);
    }
    func_80078104(aMenuEraseCourseSavedData1Tex, TEX_SIZE(aMenuEraseCourseSavedData1Tex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuEraseCourseSavedData2Tex, TEX_SIZE(aMenuEraseCourseSavedData2Tex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), 0, 1, false);
    func_80078104(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), 0, 1, false);
    func_80078104(aHasGhostMarkerTex, TEX_SIZE_4B(aHasGhostMarkerTex), 0, 0, false);
    RecordsEntry_Init();
    BorderedBox_CleanWidget(&sRecordsMenuBox);
    BorderedBox_CleanWidget(&sRecordsClearConfirmBox);
    BorderedBox_ClearAll();
}

bool Records_CourseHasNoRecords(s32 courseIndex) {
    s32 i;
    bool hasNoRecords = true;

    for (i = 0; i < 5; i++) {
        if (gCourseInfos[courseIndex].timeRecord[i] != MAX_TIMER) {
            hasNoRecords = false;
            break;
        }
    }

    return hasNoRecords;
}

bool Records_CourseHasGhost(s32 courseIndex) {
    s32 pad;
    bool hasGhost = false;
    s32 pad2[2];
    GhostInfo ghostInfo;

    Save_LoadGhostInfo(&ghostInfo);

    if (ghostInfo.encodedCourseIndex == gCourseInfos[courseIndex].encodedCourseIndex) {
        hasGhost = true;
    }
    return hasGhost;
}

extern s16 gMenuChangeMode;
extern s32 gLastRecordsCourseIndex;
extern s32 D_800DCCFC;

s32 Records_Update(void) {
    s32 updateState;
    s32 gameMode;
    bool reloadRecords;

    Controller_SetGlobalInputs(&gSharedController);
    sGhostMarkerRenderInfo = &sGhostMarkerRenderInfos[D_800DCCFC];
    Racer_Update();
    Camera_Update();
    Background_Update();
    Course_Update();
    func_80074844();
    if (sGhostMarkerState != GHOST_MARKER_NONE) {
        Records_UpdateGhostMarker();
    }
    RecordsEntry_Update();
    BorderedBox_Update();
    gameMode = GAMEMODE_RECORDS;
    reloadRecords = false;
    if (!sRecordsStopStateUpdate) {
        switch (sRecordsState) {
            case RECORDS_STATE_VIEW_RECORDS:
                updateState = Records_ViewRecordsUpdate();
                gameMode = GAMEMODE_RECORDS;
                if (updateState == 1) {
                    reloadRecords = true;
                } else if (updateState == 2) {
                    gameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                }
                if (updateState != 0) {
                    sRecordsStopStateUpdate = true;
                }
                break;
            case RECORDS_STATE_RECORDS_MENU:
                updateState = Records_MenuUpdate();
                gameMode = GAMEMODE_RECORDS;
                if (updateState == 1) {
                    gameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                } else if (updateState == 2) {
                    gameMode = GAMEMODE_FLX_MAIN_MENU;
                }
                if (updateState != 0) {
                    sRecordsStopStateUpdate = true;
                }
                break;
            case RECORDS_STATE_CONFIRM_CLEAR:
                Records_ClearConfirmUpdate();
                gameMode = GAMEMODE_RECORDS;
                break;
        }
    }
    if (reloadRecords) {
        gLastRecordsCourseIndex = gCourseIndex;
        gMenuChangeMode = MENU_CHANGE_CHANGE_RECORD_COURSE;
    } else if ((gameMode == GAMEMODE_RECORDS) && !sRecordsStopStateUpdate &&
               (gRacers[0].stateFlags & RACER_STATE_FALLING_OFF_TRACK)) {
        gMenuChangeMode = MENU_CHANGE_RETRY;
    }
    return gameMode;
}

extern s32 gTransitionState;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

s32 Records_ViewRecordsUpdate(void) {
    s32 sp2C;
    s32 lastCourseIndex;

    if (gTransitionState != TRANSITION_INACTIVE) {
        return 0;
    }
    if (BorderedBox_GetInfo(sRecordsMenuBox, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }
    RecordsEntry_SetDrawArrows(true);

    lastCourseIndex = gCourseIndex;
    if (gInputPressed & BTN_RIGHT) {
        gCourseIndex++;
        if (gCourseIndex >= sUnlockedCourseCount) {
            gCourseIndex = COURSE_MUTE_CITY;
        }
        Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_LEFT);
    } else if (gInputPressed & BTN_LEFT) {
        gCourseIndex--;
        if (gCourseIndex < 0) {
            gCourseIndex = sUnlockedCourseCount - 1;
        }
        Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_RIGHT);
    }

    if (lastCourseIndex != gCourseIndex) {
        sp2C = 1;
        Audio_TriggerSystemSE(NA_SE_30);
    } else {
        sp2C = 0;
    }
    if (sp2C == 0) {
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            sRecordsMenuBox = BorderedBox_Init(0, 108, 50, 104, 100, GPACK_RGBA5551(0, 255, 0, 1), Records_MenuDraw);
            if (sRecordsMenuBox != NULL) {
                sRecordsState = RECORDS_STATE_RECORDS_MENU;
                sRecordsHighlightedMenuIndex = 0;
                Audio_TriggerSystemSE(NA_SE_33);
                RecordsEntry_SetDrawArrows(false);
            }
        } else if (gInputButtonPressed & BTN_B) {
            sp2C = 2;
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
    return sp2C;
}

s32 Records_MenuUpdate(void) {
    s32 clearBoxTop;
    bool successfulSelection;
    s32 sp2C;
    s32 lastMenuIndex;

    if (!BorderedBox_GetInfo(sRecordsMenuBox, IS_BORDERED_BOX_OPENED)) {
        return 0;
    }
    sp2C = 0;
    lastMenuIndex = sRecordsHighlightedMenuIndex;
    // clang-format off
    if (gInputPressed & BTN_UP) {
        if (--sRecordsHighlightedMenuIndex < 0) { sRecordsHighlightedMenuIndex = 3; }

        while (!sRecordsMenuIndexValid[sRecordsHighlightedMenuIndex]) {
            if (--sRecordsHighlightedMenuIndex < 0) { sRecordsHighlightedMenuIndex = 3; }
        }
    } else if (gInputPressed & BTN_DOWN) {
        if (++sRecordsHighlightedMenuIndex > 3) { sRecordsHighlightedMenuIndex = 0; }

        while (!sRecordsMenuIndexValid[sRecordsHighlightedMenuIndex]) {
            if (++sRecordsHighlightedMenuIndex > 3) { sRecordsHighlightedMenuIndex = 0; }
        }
    }
    // clang-format on
    if (lastMenuIndex != sRecordsHighlightedMenuIndex) {
        Audio_TriggerSystemSE(NA_SE_30);
    }
    if (gInputButtonPressed & (BTN_A | BTN_START)) {
        successfulSelection = false;

        switch (sRecordsMenuInfo[sRecordsHighlightedMenuIndex].menuOption) {
            case RECORDS_MENU_CHANGE_COURSE:
                successfulSelection = true;
                sp2C = 1;
                break;
            case RECORDS_MENU_QUIT:
                successfulSelection = true;
                sp2C = 2;
                break;
            case RECORDS_MENU_CLEAR_RECORD:
            case RECORDS_MENU_CLEAR_GHOST:
                if (sRecordsMenuInfo[sRecordsHighlightedMenuIndex].menuOption == RECORDS_MENU_CLEAR_RECORD) {
                    sRecordsClearType = RECORDS_CLEAR_RECORDS;
                    clearBoxTop = 120;
                } else { // RECORDS_MENU_CLEAR_GHOST
                    sRecordsClearType = RECORDS_CLEAR_GHOST;
                    clearBoxTop = 142;
                }

                sRecordsClearConfirmBox = BorderedBox_Init(1, 120, clearBoxTop, 148, 80, GPACK_RGBA5551(255, 0, 0, 1),
                                                           Records_DrawClearConfirm);

                successfulSelection = false;
                if (sRecordsClearConfirmBox != NULL) {
                    sRecordsYesNoIndex = 0;
                    successfulSelection = true;
                    sRecordsState = RECORDS_STATE_CONFIRM_CLEAR;
                }
                break;
        }

        if (successfulSelection) {
            Audio_TriggerSystemSE(NA_SE_33);
        }
    } else if (gInputButtonPressed & BTN_B) {
        sRecordsState = RECORDS_STATE_VIEW_RECORDS;
        BorderedBox_StartClose(sRecordsMenuBox);
        Audio_TriggerSystemSE(NA_SE_16);
    }
    return sp2C;
}

void Records_ClearConfirmUpdate(void) {
    s32 lastYesNoIndex;
    bool selectionMade;

    if (BorderedBox_GetInfo(sRecordsClearConfirmBox, IS_BORDERED_BOX_OPENED)) {
        lastYesNoIndex = sRecordsYesNoIndex;
        if (gInputPressed & BTN_LEFT) {
            sRecordsYesNoIndex--;
            if (sRecordsYesNoIndex < RECORDS_CLEAR_NO) {
                sRecordsYesNoIndex = RECORDS_CLEAR_YES;
            }
        } else if (gInputPressed & BTN_RIGHT) {
            sRecordsYesNoIndex++;
            if (sRecordsYesNoIndex > RECORDS_CLEAR_YES) {
                sRecordsYesNoIndex = RECORDS_CLEAR_NO;
            }
        }
        if (lastYesNoIndex != sRecordsYesNoIndex) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        selectionMade = false;
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            selectionMade = true;
            if (sRecordsYesNoIndex == RECORDS_CLEAR_NO) {
                Audio_TriggerSystemSE(NA_SE_16);
            } else {
                if (sRecordsClearType == RECORDS_CLEAR_RECORDS) {
                    func_i2_801017B8(gCourseIndex);
                } else if (sRecordsClearType == RECORDS_CLEAR_GHOST) {
                    Save_InitGhost(gCourseIndex);
                    sGhostMarkerState = GHOST_MARKER_FADE_OUT;
                }
                sRecordsMenuIndexValid[sRecordsHighlightedMenuIndex] = false;
                sRecordsHighlightedMenuIndex = sRecordsToCourseSelectMenuIndex;
                Audio_TriggerSystemSE(NA_SE_5);
            }
        } else if (gInputButtonPressed & BTN_B) {
            selectionMade = true;
            Audio_TriggerSystemSE(NA_SE_16);
        }
        if (selectionMade) {
            sRecordsState = RECORDS_STATE_RECORDS_MENU;
            BorderedBox_StartClose(sRecordsClearConfirmBox);
        }
    }
}

extern FrameBuffer* gFrameBuffers[];
extern s32 D_800DCD04;
extern Vtx* gEffectsVtxPtr;
extern Vtx* gEffectsVtxEndPtr;
extern Vtx* gCourseVtxPtr;
extern GfxPool* gGfxPool;

Gfx* Records_Draw(Gfx* gfx) {

    if (D_i2_80106F10 != 0) {
        D_i2_80106F10--;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPPipelineMode(gfx++, G_PM_NPRIMITIVE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    gSPDisplayList(gfx++, D_303A810);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));

    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gEffectsVtxPtr = gGfxPool->effectsVtxBuffer;
    gEffectsVtxEndPtr = &gGfxPool->effectsVtxBuffer[0x7FF];
    gfx = Background_Draw(gfx, 0, SCISSOR_BOX_FULL_SCREEN);
    gfx = Course_Draw(gfx, 0);
    gfx = Course_GadgetsDraw(gfx, 0);
    gfx = RecordsEntry_DrawRecords(gfx, sRecordsCourseIndex);
    if (sGhostMarkerState != GHOST_MARKER_NONE) {
        gfx = Records_DrawGhostMarker(gfx);
    }
    return BorderedBox_Draw(gfx);
}

void Records_UpdateGhostMarker(void) {
    Vtx* vtx;

    switch (sGhostMarkerState) {
        case GHOST_MARKER_SHOWN:
            break;
        case GHOST_MARKER_FADE_OUT:
            if (sGhostMarkerBottomAlpha > 0) {
                sGhostMarkerBottomAlpha -= 10;
                if (sGhostMarkerBottomAlpha < 0) {
                    sGhostMarkerBottomAlpha = 0;
                }
            }
            if (sGhostMarkerBottomAlpha == 0) {
                sGhostMarkerTopAlpha -= 10;
                if (sGhostMarkerTopAlpha < 0) {
                    sGhostMarkerTopAlpha = 0;
                }
            }
            if ((sGhostMarkerBottomAlpha == 0) && (sGhostMarkerTopAlpha == 0)) {
                sGhostMarkerState = GHOST_MARKER_NONE;
                return;
            }
            break;
    }

    Matrix_SetOrtho(&sGhostMarkerRenderInfo->mtx, NULL, 1.0f, 0.0f, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, 0.0f, -100.0f,
                    100.0f);

    vtx = sGhostMarkerRenderInfo->vtx;

    SET_VTX(vtx, 236, 60, 0, -16, -16, 255, 255, 255, sGhostMarkerTopAlpha);
    vtx++;
    SET_VTX(vtx, 236 + TEX_WIDTH(aHasGhostMarkerTex) - 1, 60, 0, 0x400, 0, 255, 255, 255, sGhostMarkerTopAlpha);
    vtx++;
    SET_VTX(vtx, 236, 60 + TEX_HEIGHT(aHasGhostMarkerTex) - 1, 0, 0, 0x200, 255, 255, 255, sGhostMarkerBottomAlpha);
    vtx++;
    SET_VTX(vtx, 236 + TEX_WIDTH(aHasGhostMarkerTex) - 1, 60 + TEX_HEIGHT(aHasGhostMarkerTex) - 1, 0, 0x400, 0x200, 255,
            255, 255, sGhostMarkerBottomAlpha);
    vtx++;
}

extern Mtx D_2000000[];

Gfx* Records_DrawGhostMarker(Gfx* gfx) {

    gfx = func_8006A00C(gfx, SCISSOR_BOX_FULL_SCREEN);
    gSPDisplayList(gfx++, D_8014810);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    gSPMatrix(gfx++, &sGhostMarkerRenderInfo->mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gfx++, sGhostMarkerRenderInfo->vtx, 4, 0);

    gDPLoadTextureBlock_4b(gfx++, func_800783AC(aHasGhostMarkerTex), G_IM_FMT_I, TEX_WIDTH(aHasGhostMarkerTex),
                           TEX_HEIGHT(aHasGhostMarkerTex), 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);

    return gfx;
}

Gfx* Records_MenuDraw(Gfx* gfx, s32 left, s32 top) {
    s32 boxCenteringOffset;
    s32 i;
    TextureInfo* textureInfo;
    TexturePtr tlut;
    RecordsMenuInfo* recordsOption;

    gSPDisplayList(gfx++, D_8014940);

    recordsOption = sRecordsMenuInfo;
    for (i = 0; i < 4; i++, recordsOption++) {
        textureInfo = &recordsOption->textureInfo;
        gDPPipeSync(gfx++);

        if (i != sRecordsHighlightedMenuIndex) {
            if (sRecordsMenuIndexValid[i]) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8007DB28(gfx, 0);
        }

        if (i == 0) {
            tlut = func_800783AC(aMenuTextTLUT);
        } else {
            tlut = NULL;
        }

        boxCenteringOffset = ((104 - textureInfo->width) / 2) - 20;
        gfx = func_8007E410(gfx, func_800783AC(textureInfo->texture), tlut, G_IM_FMT_CI, 1,
                            left + boxCenteringOffset + 20, top + 10 + i * 20, textureInfo->width, textureInfo->height,
                            3);
    }

    return gfx;
}

Gfx* Records_DrawClearConfirm(Gfx* gfx, s32 left, s32 top) {
    TextureInfo* textureInfo;
    s32 boxCenteringOffset;
    s32 pad;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    textureInfo = &sRecordsClearTextureInfos[sRecordsClearType];

#ifdef VERSION_JP
    gfx = func_8007E410(gfx, func_800783AC(textureInfo->texture), func_800783AC(aMenuTextTLUT), G_IM_FMT_CI, 1,
                        left + 12, top + 10, textureInfo->width, textureInfo->height, 3);
#else
    boxCenteringOffset = (124 - textureInfo->width) / 2;

    gfx = func_8007E410(gfx, func_800783AC(textureInfo->texture), func_800783AC(aMenuTextTLUT), G_IM_FMT_CI, 1,
                        left + boxCenteringOffset + 12, top + 10, textureInfo->width, textureInfo->height, 3);
#endif

    gDPPipeSync(gfx++);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_8007E410(gfx, func_800783AC(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, left + 24, top + 50, 16, 16, 0);
    gfx = func_8007E410(gfx, func_800783AC(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, left + 99, top + 50, 16, 16, 0);

    textureInfo = &sRecordsYesNoTextureInfos[sRecordsYesNoIndex];
    boxCenteringOffset = (59 - textureInfo->width) / 2;
    return func_8007E410(gfx, func_800783AC(textureInfo->texture), NULL, G_IM_FMT_CI, 1, left + boxCenteringOffset + 42,
                         top + 50, textureInfo->width, textureInfo->height, 0);
}
