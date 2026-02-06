#include "global.h"
#include "fzx_font.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_camera.h"
#include "fzx_course.h"
#include "menus.h"
#include "records_entry.h"
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER(machine_custom_gfx.h)
#include ASSET_HEADER(common_assets_compressed.h)

u16 sRecordsEntryFlags;
u16 sRecordsEntryIncreaseState;
s32 sRecordsEntryState;
s32 sRecordsEntryRecordLeftOffset;
s32 sRecordsEntryRecordsTransitionTimer;
s32 sRecordsEntryRecordLeft;
int sRecordsEntryRecordTop;
s32 sRecordsEntryRecordHeight;
s32 sRecordsEntryMaxSpeedLeft;
s32 sRecordsEntryMaxSpeedTop;
s32 sRecordsEntryMaxSpeedTopMachineOffset;
s16 sRecordsEntryBestTimeLeft;
s16 sRecordsEntryBestTimeTop;
s16 sRecordsEntryBestLapWordsLeftOffset;
s16 sRecordsEntryBestLapWordsTopOffset;
s16 sRecordsEntryNameEntryState;
s16 sPreviousRecordsEntryNameEntryState;
s16 sRecordsEntryNameEntryTransitionTimer;
s16 sKeyboardCursorX;
s16 sKeyboardCursorY;
s16 gRecordNameEnteredLength;
s16 sEnterKeyboardIndex;
KeyboardObject sKeyboardObjects[50];
s16 sSelectedCharacterTransitionTimer[3];
unk_80077D50* sSpinningKeyboardCharacterCompTexInfo;
u16 sSpinningKeyboardCharacterPerspectiveScale;

extern Mtx D_8024DC80;
extern Lights1 D_8024DCC0;

extern f32 D_800CE748;
extern f32 D_800CE74C;
extern f32 D_800CE750;

extern s32 gGameMode;

void RecordsEntry_Init(void) {

    sRecordsEntryFlags = 0;
    sRecordsEntryIncreaseState = false;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        sRecordsEntryState = RECORDS_ENTRY_WAIT_NAME_ENTRY;
        sRecordsEntryFlags |= RECORDS_ENTRY_DRAW_NAME_BOX | RECORDS_ENTRY_HIGHLIGHT_CURRENT;
        sRecordsEntryRecordLeft = 25;
        sRecordsEntryRecordTop = 64;
        sRecordsEntryRecordHeight = 35;
        sRecordsEntryMaxSpeedLeft = 220;
        sRecordsEntryMaxSpeedTop = 60;
        sRecordsEntryMaxSpeedTopMachineOffset = 33;
        sRecordsEntryBestTimeLeft = 220;
        sRecordsEntryBestTimeTop = 118;
        sRecordsEntryBestLapWordsLeftOffset = 0;
        sRecordsEntryBestLapWordsTopOffset = -12;
        sRecordsEntryRecordLeftOffset = SCREEN_WIDTH;
        sRecordsEntryRecordsTransitionTimer = 30;
    } else {
        sRecordsEntryState = RECORDS_ENTRY_RECORDS;
        sRecordsEntryFlags |= RECORDS_ENTRY_LOAD_ARROWS | RECORDS_ENTRY_DRAW_ENGINE_SETTINGS |
                              RECORDS_ENTRY_FILTER_BACKGROUND | RECORDS_ENTRY_DRAW_COURSE_WITH_ARROWS;
        sRecordsEntryRecordLeft = 25;
        sRecordsEntryRecordTop = 64;
        sRecordsEntryRecordHeight = 35;
        sRecordsEntryMaxSpeedLeft = 220;
        sRecordsEntryMaxSpeedTop = 97;
        sRecordsEntryMaxSpeedTopMachineOffset = 33;
        sRecordsEntryBestTimeLeft = 220;
        sRecordsEntryBestTimeTop = 170;
        sRecordsEntryBestLapWordsLeftOffset = 0;
        sRecordsEntryBestLapWordsTopOffset = -12;
        sRecordsEntryRecordLeftOffset = 0;
        sRecordsEntryRecordsTransitionTimer = 0;
    }
    Matrix_SetLockedLookAt(&D_8024DC80, NULL, 0.7f * D_800CE748, 0.7f * D_800CE74C, 0.7f * D_800CE750, 0.0f, 0.0f, 1.0f,
                           0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Lights_SetSource(&D_8024DCC0, 0, 0, 0, 255, 255, 255, 100, 50, 69);
    func_80078104(aBestTex, TEX_SIZE(aBestTex, sizeof(u16)), 0, 0, 0);

    if (sRecordsEntryFlags & RECORDS_ENTRY_DRAW_ENGINE_SETTINGS) {
        func_80078104(aRecordsAccelerationSpeedGraphTex, TEX_SIZE(aRecordsAccelerationSpeedGraphTex, sizeof(u16)), 0, 0,
                      0);
        func_80078104(aRecordsAccelerationSpeedSliderTex, TEX_SIZE(aRecordsAccelerationSpeedSliderTex, sizeof(u16)), 0,
                      0, 0);
    }
    if (sRecordsEntryFlags & RECORDS_ENTRY_LOAD_ARROWS) {
        RecordsEntry_SetDrawArrows(true);
        func_80078104(aYellowArrowTex, TEX_SIZE(aYellowArrowTex, sizeof(u16)), 0, 1, 0);
    }
}

void RecordsEntry_ToRecordsState(void) {
    sRecordsEntryIncreaseState = true;
}

extern GfxPool* gGfxPool;

bool RecordsEntry_Update(void) {
    Vp* vp;
    s32 i;
    bool isOnRecordsScreen;
    f32 temp_ft1;
    s32 temp_t6;
    s32 leftOffset;

    isOnRecordsScreen = false;
    switch (sRecordsEntryState) {
        case RECORDS_ENTRY_WAIT_NAME_ENTRY:
            if (sRecordsEntryIncreaseState) {
                sRecordsEntryIncreaseState = false;
                sRecordsEntryState = RECORDS_ENTRY_TRANSITION_RECORDS;
            }
            break;
        case RECORDS_ENTRY_TRANSITION_RECORDS:
            sRecordsEntryRecordLeftOffset = (sRecordsEntryRecordsTransitionTimer * (f32) SCREEN_WIDTH) / 30.0f;
            sRecordsEntryRecordsTransitionTimer--;

            if (sRecordsEntryRecordsTransitionTimer < 0) {
                sRecordsEntryRecordLeftOffset = 0;
                sRecordsEntryRecordsTransitionTimer = 0;
                sRecordsEntryState = RECORDS_ENTRY_RECORDS;
            }
            break;
        case RECORDS_ENTRY_RECORDS:
            isOnRecordsScreen = true;
            break;
    }

    vp = gGfxPool->recordsMachineVp;
    for (i = 0; i < 5; i++) {
        leftOffset = (i & 1) ? -sRecordsEntryRecordLeftOffset : sRecordsEntryRecordLeftOffset;

        vp->vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
        vp->vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
        vp->vp.vscale[2] = 0x1FF;
        vp->vp.vscale[3] = 0;
        vp->vp.vtrans[0] = (leftOffset + sRecordsEntryRecordLeft + 45) << 2;
        vp->vp.vtrans[1] = ((sRecordsEntryRecordTop + (sRecordsEntryRecordHeight * i)) - 4) << 2;
        vp->vp.vtrans[2] = 0x1FF;
        vp->vp.vtrans[3] = 0;
        vp++;
    }

    vp->vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
    vp->vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
    vp->vp.vscale[2] = 0x1FF;
    vp->vp.vscale[3] = 0;
    vp->vp.vtrans[0] = (sRecordsEntryRecordLeftOffset + sRecordsEntryMaxSpeedLeft + 36) << 2;
    vp->vp.vtrans[1] = (sRecordsEntryMaxSpeedTop + sRecordsEntryMaxSpeedTopMachineOffset) << 2;
    vp->vp.vtrans[2] = 0x1FF;
    vp->vp.vtrans[3] = 0;

    return isOnRecordsScreen;
}

extern FrameBuffer* gFrameBuffers[];
extern s32 D_800DCD04;
extern Mtx D_2028480;
extern Lights1 D_20284C0;
extern Camera gCameras[];
extern char* gTrackNames[];
extern u32 gGameFrameCount;
extern s16 gCurrentTimeAttackRecordPosition;
extern s16 gCurrentTimeAttackHasMaxSpeed;
extern s16 gBestTimedLap;
extern GfxPool D_1000000;
extern Gfx D_8076CE28[];

Gfx* RecordsEntry_DrawRecords(Gfx* gfx, s32 courseIndex) {
    CourseInfo* courseInfo;
    s32 recordPosition;
    s32 xl;
    s32 yl;
    bool highlightSection;
    bool highlightSpeedSection;
    s32 i;
    s32 leftOffset;
    s32 temp1;
    s32 temp2;
    f32 var_fv0;
    s8 recordPositionStr[0x10];
    char* trackName;

#ifndef EXPANSION_KIT
    gSPDisplayList(gfx++, D_303A810);
#else
    gSPDisplayList(gfx++, D_8076CE28);
#endif
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));

    if (sRecordsEntryFlags & RECORDS_ENTRY_FILTER_BACKGROUND) {
        gfx = func_8007A440(gfx, 12, 8, 308, 232, 0, 0, 0, 191);
    }
    if (sRecordsEntryFlags & RECORDS_ENTRY_DRAW_COURSE_WITH_ARROWS) {
        trackName = gTrackNames[courseIndex];
        i = Font_GetStringWidth(trackName, FONT_SET_3, 1);

        gfx = Menus_DrawBeveledBox(gfx, 153 - i / 2, 21, i / 2 + 167, 43, 0, 0, 200, 127);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        gfx = Font_DrawString(gfx, 162 - (Font_GetStringWidth(trackName, FONT_SET_3, 1) / 2), 42, trackName, 1,
                              FONT_SET_3, 0);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

        gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth(trackName, FONT_SET_3, 1) / 2), 40, trackName, 1,
                              FONT_SET_3, 0);

        if ((sRecordsEntryFlags & RECORDS_ENTRY_LOAD_ARROWS) && (sRecordsEntryFlags & RECORDS_ENTRY_DRAW_ARROWS)) {
            temp2 = (gGameFrameCount % 40);
            temp1 = (temp2 / 20);
            temp2 %= 20;

            var_fv0 = temp2 / 20.0f;

            if (temp1 != 0) {
                var_fv0 = 1.0 - var_fv0;
            }
            leftOffset = (s32) (10.0f * var_fv0);

            gfx = func_8007B14C(gfx, func_800783AC(aYellowArrowTex), (-(i / 2) - leftOffset) + 118, 16, 32, 32,
                                G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 0, 0);
            gfx = func_8007B14C(gfx, func_800783AC(aYellowArrowTex), (i / 2) + leftOffset + 170, 16, 32, 32,
                                G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 1, 0);
        }
    }

    if (sRecordsEntryFlags & RECORDS_ENTRY_DRAW_NAME_BOX) {
        courseInfo = &gCourseInfos[courseIndex];
        for (i = 0; i < 5; i++) {
            if (i & 1) {
                leftOffset = -sRecordsEntryRecordLeftOffset;
            } else {
                leftOffset = sRecordsEntryRecordLeftOffset;
            }
            if (courseInfo->timeRecord[i] != MAX_TIMER) {
                xl = Font_GetStringWidth(courseInfo->recordNames[i], FONT_SET_1, 1);
                if (xl > 0) {
                    gfx = Menus_DrawBeveledBox(gfx, (leftOffset + sRecordsEntryRecordLeft) + 74,
                                               (sRecordsEntryRecordTop + (sRecordsEntryRecordHeight * i)) + 3,
                                               (leftOffset + sRecordsEntryRecordLeft) + xl + 77,
                                               (sRecordsEntryRecordTop + (sRecordsEntryRecordHeight * i)) + 17, 0, 0, 0,
                                               128);
                }
            }
        }
    }

    recordPosition = 1;
    courseInfo = &gCourseInfos[courseIndex];
    for (i = 0; i < 5; i++) {

        if (i & 1) {
            leftOffset = -sRecordsEntryRecordLeftOffset;
        } else {
            leftOffset = sRecordsEntryRecordLeftOffset;
        }

        if (courseInfo->timeRecord[i] != MAX_TIMER) {
            if ((i != 0) && (courseInfo->timeRecord[i] != courseInfo->timeRecord[i - 1])) {
                recordPosition = i + 1;
            }
        } else {
            recordPosition = i + 1;
        }

        sprintf(recordPositionStr, "%d", recordPosition);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        gfx = Font_DrawString(gfx, leftOffset + sRecordsEntryRecordLeft + 2,
                              (sRecordsEntryRecordHeight * i) + sRecordsEntryRecordTop + 2, recordPositionStr, 1,
                              FONT_SET_3, 0);

        if (sRecordsEntryFlags & RECORDS_ENTRY_HIGHLIGHT_CURRENT) {
            if (gCurrentTimeAttackRecordPosition == i + 1) {
                highlightSection = true;
            } else {
                highlightSection = false;
            }
        } else {
            highlightSection = false;
        }

        gDPPipeSync(gfx++);

        if (highlightSection) {
            gfx = func_8007DB28(gfx, 0);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 250, 250, 255, 255);
        }
        gfx = Font_DrawString(gfx, leftOffset + sRecordsEntryRecordLeft,
                              (sRecordsEntryRecordHeight * i) + sRecordsEntryRecordTop, recordPositionStr, 1,
                              FONT_SET_3, 0);
    }
    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 5; i++) {
        if (i & 1) {
            leftOffset = -sRecordsEntryRecordLeftOffset;
        } else {
            leftOffset = sRecordsEntryRecordLeftOffset;
        }
        if (courseInfo->timeRecord[i] != MAX_TIMER) {

            if (sRecordsEntryFlags & RECORDS_ENTRY_HIGHLIGHT_CURRENT) {
                if (gCurrentTimeAttackRecordPosition == i + 1) {
                    highlightSection = true;
                } else {
                    highlightSection = false;
                }
            } else {
                highlightSection = false;
            }

            gDPPipeSync(gfx++);

            if (highlightSection) {
                gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
                gfx = func_8007F090(gfx, 255, 0, 0);
            } else {
                gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            }
            gfx =
                Hud_DrawTimerScisThousandths(gfx, courseInfo->timeRecord[i], leftOffset + sRecordsEntryRecordLeft + 75,
                                             (sRecordsEntryRecordTop + (sRecordsEntryRecordHeight * i)) - 14, 1.0f);
        }
    }

    if (courseInfo->bestTime != MAX_TIMER) {

        if (sRecordsEntryFlags & RECORDS_ENTRY_HIGHLIGHT_CURRENT) {
            if (gBestTimedLap != 0) {
                highlightSection = true;
            } else {
                highlightSection = false;
            }
        } else {
            highlightSection = false;
        }

        gDPPipeSync(gfx++);

        if (highlightSection) {
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
            gfx = func_8007F090(gfx, 255, 0, 0);
        } else {
            gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        }
        gfx = Hud_DrawTimerScisThousandths(gfx, courseInfo->bestTime,
                                           sRecordsEntryBestTimeLeft + sRecordsEntryRecordLeftOffset,
                                           sRecordsEntryBestTimeTop, 1.0f);
    }

    xl = sRecordsEntryBestTimeLeft + sRecordsEntryRecordLeftOffset + sRecordsEntryBestLapWordsLeftOffset;
    yl = sRecordsEntryBestTimeTop + sRecordsEntryBestLapWordsTopOffset;

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, func_800783AC(aBestTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, xl << 2, yl << 2, (xl + 16) << 2, (yl + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gDPLoadTextureBlock(gfx++, aLapTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (xl + 16) << 2, yl << 2, (xl + 32) << 2, (yl + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    for (i = 0; i < 5; i++) {
        if (i & 1) {
            leftOffset = -sRecordsEntryRecordLeftOffset;
        } else {
            leftOffset = sRecordsEntryRecordLeftOffset;
        }
        if (courseInfo->timeRecord[i] == MAX_TIMER) {
            gfx = Font_DrawString(gfx, leftOffset + sRecordsEntryRecordLeft + 75,
                                  (sRecordsEntryRecordTop + (sRecordsEntryRecordHeight * i)) - 2, "--------", 1,
                                  FONT_SET_4, 0);
        }
    }

    if (courseInfo->bestTime == MAX_TIMER) {
        gfx = Font_DrawString(gfx, sRecordsEntryBestTimeLeft + sRecordsEntryRecordLeftOffset,
                              sRecordsEntryBestTimeTop + 12, "--------", 1, FONT_SET_4, 0);
    }

    for (i = 0; i < 5; i++) {
        if (i & 1) {
            leftOffset = -sRecordsEntryRecordLeftOffset;
        } else {
            leftOffset = sRecordsEntryRecordLeftOffset;
        }
        if (courseInfo->timeRecord[i] != MAX_TIMER) {
            gfx = Font_DrawString(gfx, leftOffset + sRecordsEntryRecordLeft + 75,
                                  sRecordsEntryRecordTop + (sRecordsEntryRecordHeight * i) + 18,
                                  courseInfo->recordNames[i], 1, FONT_SET_1, 0);
        }
    }

    if (sRecordsEntryFlags & RECORDS_ENTRY_DRAW_ENGINE_SETTINGS) {
        for (i = 0; i < 5; i++) {
            if (courseInfo->timeRecord[i] != MAX_TIMER) {
                gfx = RecordsEntry_DrawRecordEngineSetting(gfx, 178, (i * 35) + 51, courseInfo->recordEngines[i]);
            }
        }
    }
    gSPDisplayList(gfx++, D_8014940);

    if (sRecordsEntryFlags & RECORDS_ENTRY_HIGHLIGHT_CURRENT) {
        if (gCurrentTimeAttackHasMaxSpeed) {
            highlightSpeedSection = true;
        } else {
            highlightSpeedSection = false;
        }
    } else {
        highlightSpeedSection = false;
    }

    gfx = RecordsEntry_DrawSpeed(gfx, sRecordsEntryRecordLeftOffset + sRecordsEntryMaxSpeedLeft,
                                 sRecordsEntryMaxSpeedTop, courseInfo->maxSpeed, highlightSpeedSection, true);
    gSPLoadUcodeL(gfx++, gspF3DFLX2_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
    gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gfx++, D_303A5F8);
    gSPNumLights(gfx++, NUMLIGHTS_1);
    gSPLight(gfx++, &D_20284C0.l[0], 1);
    gSPLight(gfx++, &D_20284C0.a, 2);
    gSPMatrix(gfx++, &D_2028480, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (i = 0; i < 5; i++) {
        if (courseInfo->timeRecord[i] != MAX_TIMER) {
            gfx = RecordsEntry_DrawRecordMachine(gfx, i, &courseInfo->recordMachineInfos[i]);
        }
    }

    if (courseInfo->maxSpeed != 0.0f) {
        gfx = RecordsEntry_DrawRecordMachine(gfx, 5, &courseInfo->maxSpeedMachine);
    }
    return gfx;
}

Gfx* RecordsEntry_DrawSpeed(Gfx* gfx, s32 left, s32 top, f32 speed, bool shouldHighlight, bool drawMaxSpeedTexture) {
    s32 i;
    s32 speedValue;
    s32 digitMask;
    bool startedDrawSpeed;
    s32 digit;
    s32 texLeft;

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(gfx++, left + 12, top, left + 35, top + 15);
    gSPDisplayList(gfx++, D_8014940);

    texLeft = left;
    speedValue = (speed * 21.6f) + 0.5f;
    if (drawMaxSpeedTexture) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aMaxSpeedTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, (texLeft + 4) << 2, (top - 17) << 2, (texLeft + 68) << 2, (top - 1) << 2, 0, 0,
                                0, 1 << 10, 1 << 10);
    }

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock(gfx++, aKmhTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    texLeft += 48;
    gSPScisTextureRectangle(gfx++, texLeft << 2, top << 2, (texLeft + 20) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

    gDPPipeSync(gfx++);

    if (shouldHighlight) {
        gfx = func_8007F090(gfx, 255, 0, 0);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    } else {
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }
    gDPLoadTextureBlock(gfx++, aSpeedDigitsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    digitMask = 1000;
    startedDrawSpeed = false;

    for (i = 0; i < 4; i++) {
        digit = speedValue / digitMask;
        speedValue %= digitMask;
        digitMask /= 10;
        if ((digit != 0) || (startedDrawSpeed) || (i == 3)) {
            if (1) {}
            startedDrawSpeed = true;
            gSPScisTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + ((i + 1) * 12)) << 2,
                                    (top + 16) << 2, 0, 0, (digit * 16) << 5, 1 << 10, 1 << 10);
        }
    }
    return gfx;
}

Gfx* RecordsEntry_DrawRecordMachine(Gfx* gfx, s32 recordsIndex, MachineInfo* machineInfo) {
    gSPViewport(gfx++, &D_1000000.recordsMachineVp[recordsIndex]);

    return func_8009CBE8(gfx, recordsIndex + 1, machineInfo->bodyR, machineInfo->bodyG, machineInfo->bodyB);
}

Gfx* RecordsEntry_DrawRecordEngineSetting(Gfx* gfx, s32 left, s32 top, f32 engineValue) {
    u32 sliderOffset;

    gDPLoadTextureBlock(gfx++, func_800783AC(aRecordsAccelerationSpeedGraphTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 32) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    sliderOffset = engineValue * 29.5f;

    gDPLoadTextureBlock(gfx++, func_800783AC(aRecordsAccelerationSpeedSliderTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + sliderOffset - 2) << 2, (top + 9) << 2, (left + sliderOffset + 6) << 2,
                        (top + 17) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

void RecordsEntry_SetDrawArrows(bool drawArrows) {
    if (drawArrows) {
        sRecordsEntryFlags |= RECORDS_ENTRY_DRAW_ARROWS;
    } else {
        sRecordsEntryFlags &= ~RECORDS_ENTRY_DRAW_ARROWS;
    }
}

extern RaceStats gCupRaceStats[][6];
extern s16 gRacersKOd;
extern s16 gCurrentTimeAttackRecordPosition;
extern s16 gCurrentTimeAttackHasMaxSpeed;

void RecordsEntry_UpdateRaceStats(s32 courseIndex) {
    Racer* racer;
    RaceStats* raceStats;
    s32 i;
    s32 index = courseIndex % 6;

    for (i = 0, racer = gRacers; i < 1; i++, racer++) {
        raceStats = &gCupRaceStats[i][index];
        raceStats->raceTime = racer->raceTime;
        raceStats->maxSpeed = racer->maxSpeed;
        raceStats->position = racer->position;
        raceStats->unk_0A = 0;
        if (gCurrentTimeAttackRecordPosition != 0) {
            raceStats->unk_0A |= (gCurrentTimeAttackRecordPosition & 0xF);
        }
        if (gCurrentTimeAttackHasMaxSpeed) {
            raceStats->unk_0A |= ((gCurrentTimeAttackHasMaxSpeed & 0xF) << 4);
        }
        raceStats->racersKOd = gRacersKOd;
    }
}

extern s32 gCourseIndex;

void RecordsEntry_ClearCurrentRecordName(void) {
    CourseInfo* courseInfo;
    s32 i;

    if (gCurrentTimeAttackRecordPosition != 0) {
        courseInfo = &gCourseInfos[gCourseIndex];
        for (i = 0; i < 4; i++) {
            courseInfo->recordNames[gCurrentTimeAttackRecordPosition - 1][i] = '\0';
        }
    }
}

extern s8 gRecordNameEntered[];

void RecordsEntry_InitNameEntry(void) {
    s32 i;

    sRecordsEntryNameEntryState = NAME_ENTRY_START;
    sRecordsEntryNameEntryTransitionTimer = 0;
    sKeyboardCursorX = sKeyboardCursorY = 0;
    gRecordNameEnteredLength = 0;

    for (i = 0; i < 4; i++) {
        gRecordNameEntered[i] = 0;
    }

    sEnterKeyboardIndex = RecordsEntry_GetCharacterKeyboardIndex('<');
    if (gRecordNameEnteredLength >= 3) {
        sKeyboardCursorX = (sEnterKeyboardIndex % KEYBOARD_COLUMN_COUNT);
        sKeyboardCursorY = (sEnterKeyboardIndex / KEYBOARD_COLUMN_COUNT);
    }
}

void RecordsEntry_UpdateNameEntry(void) {
    Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[0]]);
    switch (sRecordsEntryNameEntryState) {
        case NAME_ENTRY_START:
            RecordsEntry_UpdateNameEntryStart();
            break;
        case NAME_ENTRY_TRANSITION_IN:
            RecordsEntry_UpdateNameEntryTransition(false);
            break;
        case NAME_ENTRY_TRANSITION_OUT:
            RecordsEntry_UpdateNameEntryTransition(true);
            break;
        case NAME_ENTRY_KEYBOARD:
            RecordsEntry_UpdateNameEntryKeyboard();
            break;
    }
}

signed char sNameKeyboardCharacters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ'!.,0123456789       >-<";

void RecordsEntry_InitKeyboardObjects(bool keyboardObjectsInPosition) {
    KeyboardObject* keyboardObject;
    s32 i;

    for (i = 0, keyboardObject = sKeyboardObjects; i < KEYBOARD_TOTAL_COUNT; i++, keyboardObject++) {
        keyboardObject->keyboardCharacter[0] = sNameKeyboardCharacters[i];
        keyboardObject->keyboardCharacter[1] = '\0';
        keyboardObject->randLeftTarget = Math_Rand1() % SCREEN_WIDTH;
        keyboardObject->randTopTarget = Math_Rand1() % SCREEN_HEIGHT;

        if (!keyboardObjectsInPosition) {
            keyboardObject->left = keyboardObject->randLeftTarget;
            keyboardObject->top = keyboardObject->randTopTarget;
        } else {
            keyboardObject->left = ((i % KEYBOARD_COLUMN_COUNT) * 20) + 62;
            keyboardObject->top = ((i / KEYBOARD_COLUMN_COUNT) * 20) + 100;
        }
    }
}

void RecordsEntry_UpdateNameEntryStart(void) {
    sRecordsEntryNameEntryState = NAME_ENTRY_TRANSITION_IN;
    sRecordsEntryNameEntryTransitionTimer = 0;
    RecordsEntry_InitKeyboardObjects(false);
}

extern bool gShowNameEntryMenu;

void RecordsEntry_UpdateNameEntryTransition(bool transitionKeysAway) {
    KeyboardObject* keyboardObject;
    s32 i;
    s16 leftStart;
    s16 topStart;
    s16 leftEnd;
    s16 topEnd;

    for (i = 0, keyboardObject = sKeyboardObjects; i < KEYBOARD_TOTAL_COUNT; i++, keyboardObject++) {
        if (!transitionKeysAway) {
            leftStart = keyboardObject->randLeftTarget;
            topStart = keyboardObject->randTopTarget;
            topEnd = ((i / KEYBOARD_COLUMN_COUNT) * 20) + 100;
            leftEnd = ((i % KEYBOARD_COLUMN_COUNT) * 20) + 62;
            leftEnd += ((16 - Font_GetStringWidth(keyboardObject->keyboardCharacter, FONT_SET_1, 1)) / 2);
        } else {
            topStart = ((i / KEYBOARD_COLUMN_COUNT) * 20) + 100;
            leftStart = ((i % KEYBOARD_COLUMN_COUNT) * 20) + 62;
            leftStart += ((16 - Font_GetStringWidth(keyboardObject->keyboardCharacter, FONT_SET_1, 1)) / 2);
            leftEnd = keyboardObject->randLeftTarget;
            topEnd = keyboardObject->randTopTarget;
        }
        keyboardObject->left =
            (s16) (leftStart + ((s32) ((leftEnd - leftStart) * sRecordsEntryNameEntryTransitionTimer) / 60));
        keyboardObject->top =
            (s16) (topStart + ((s32) ((topEnd - topStart) * sRecordsEntryNameEntryTransitionTimer) / 60));
    }
    sRecordsEntryNameEntryTransitionTimer++;
    if (sRecordsEntryNameEntryTransitionTimer > 60) {
        if (!transitionKeysAway) {
            sRecordsEntryNameEntryState = NAME_ENTRY_KEYBOARD;
            sRecordsEntryNameEntryTransitionTimer = 0;
            for (i = 0, keyboardObject = sKeyboardObjects; i < 3; i++, keyboardObject++) {
                keyboardObject->keyboardCharacter[0] = '\0';
            }
        } else {
            gShowNameEntryMenu = false;
            RecordsEntry_ToRecordsState();
        }
    }
}

extern unk_80077D50* sFont1CompTexInfos[];
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

void RecordsEntry_UpdateNameEntryKeyboard(void) {
    KeyboardObject* keyboardObject;
    Vp* vp;
    s32 i;
    s32 keyboardIndex;
    s32 previousKeyboardIndex;
    bool nameLengthIncreased;
    s32 x;
    s32 y;
    s32 t;
    s32 s;
    CourseInfo* courseInfo;
    s32 keyboardCursorX;
    s32 keyboardCursorY;
    Vtx* vtx;
    unk_80077D50* spinningCharacterCompTexInfo;
    f32 xPositions[4];
    f32 yPositions[4];
    f32 textureSCoordinates[4];
    f32 textureTCoordinates[4];
    f32 spB8;
    f32 temp_fv0;
    MtxF mtxF;

    courseInfo = &gCourseInfos[gCourseIndex];
    previousKeyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;

    if (gRecordNameEnteredLength < 3) {
        if (gInputPressed & BTN_LEFT) {
            do {
                if (--sKeyboardCursorX < 0) {
                    sKeyboardCursorX = KEYBOARD_COLUMN_COUNT - 1;
                }
                keyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;
            } while (sNameKeyboardCharacters[keyboardIndex] == ' ');
        }
        if (gInputPressed & BTN_RIGHT) {
            do {
                if (++sKeyboardCursorX > KEYBOARD_COLUMN_COUNT - 1) {
                    sKeyboardCursorX = 0;
                }
                keyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;
            } while (sNameKeyboardCharacters[keyboardIndex] == ' ');
        }
        if (gInputPressed & BTN_UP) {
            do {
                if (--sKeyboardCursorY < 0) {
                    sKeyboardCursorY = KEYBOARD_ROW_COUNT - 1;
                }
                keyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;
            } while (sNameKeyboardCharacters[keyboardIndex] == ' ');
        }
        if (gInputPressed & BTN_DOWN) {
            do {
                if (++sKeyboardCursorY > KEYBOARD_ROW_COUNT - 1) {
                    sKeyboardCursorY = 0;
                }
                keyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;
            } while (sNameKeyboardCharacters[keyboardIndex] == ' ');
        }
    }

    keyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;
    if (previousKeyboardIndex != keyboardIndex) {
        Audio_TriggerSystemSE(NA_SE_30);
    }
    if (gInputButtonPressed & BTN_A) {
        nameLengthIncreased = false;
        switch (sNameKeyboardCharacters[keyboardIndex]) {
            case '<':
                RecordsEntry_SaveRecordName(courseInfo);
                break;
            case '>':
                nameLengthIncreased = true;
                gRecordNameEntered[gRecordNameEnteredLength] = ' ';
                break;
            default:
                nameLengthIncreased = true;
                gRecordNameEntered[gRecordNameEnteredLength] = sNameKeyboardCharacters[keyboardIndex];
                break;
        }

        if (nameLengthIncreased) {
            keyboardObject = &sKeyboardObjects[gRecordNameEnteredLength];
            keyboardObject->keyboardCharacter[0] = gRecordNameEntered[gRecordNameEnteredLength];
            keyboardObject->keyboardCharacter[1] = '\0';
            keyboardObject->randLeftTarget = ((s16) (keyboardIndex % KEYBOARD_COLUMN_COUNT) * 20) + 62;
            keyboardObject->randTopTarget = ((s16) (keyboardIndex / KEYBOARD_COLUMN_COUNT) * 20) + 100;
            sSelectedCharacterTransitionTimer[gRecordNameEnteredLength] = 0;
            gRecordNameEnteredLength++;
            if (gRecordNameEnteredLength >= 3) {
                sKeyboardCursorX = sEnterKeyboardIndex % KEYBOARD_COLUMN_COUNT;
                sKeyboardCursorY = sEnterKeyboardIndex / KEYBOARD_COLUMN_COUNT;
            }
        }
        Audio_TriggerSystemSE(NA_SE_33);
    } else if (gInputButtonPressed & BTN_START) {
        if (sNameKeyboardCharacters[keyboardIndex] == '<') {
            RecordsEntry_SaveRecordName(courseInfo);
        } else {
            sKeyboardCursorX = sEnterKeyboardIndex % KEYBOARD_COLUMN_COUNT;
            sKeyboardCursorY = sEnterKeyboardIndex / KEYBOARD_COLUMN_COUNT;
        }
        Audio_TriggerSystemSE(NA_SE_33);
    } else if (gInputButtonPressed & BTN_B) {
        gRecordNameEnteredLength--;
        if (gRecordNameEnteredLength < 0) {
            gRecordNameEnteredLength = 0;
        }
        keyboardIndex = RecordsEntry_GetCharacterKeyboardIndex(gRecordNameEntered[gRecordNameEnteredLength]);

        sKeyboardCursorX = keyboardIndex % KEYBOARD_COLUMN_COUNT;
        sKeyboardCursorY = keyboardIndex / KEYBOARD_COLUMN_COUNT;
        gRecordNameEntered[gRecordNameEnteredLength] = 0;
        Audio_TriggerSystemSE(NA_SE_16);
    }
    if (sRecordsEntryNameEntryState == NAME_ENTRY_KEYBOARD) {
        keyboardCursorX = ((s16) (keyboardIndex % KEYBOARD_COLUMN_COUNT) * 20) + 62;
        keyboardCursorY = ((s16) (keyboardIndex / KEYBOARD_COLUMN_COUNT) * 20) + 100;

        for (i = 0, keyboardObject = sKeyboardObjects; i < 3; i++, keyboardObject++) {
            if (keyboardObject->keyboardCharacter[0] != '\0') {
                keyboardObject->left = ((sSelectedCharacterTransitionTimer[i] *
                                         ((s16) (((i * 20) + 132)) - keyboardObject->randLeftTarget)) /
                                        15) +
                                       keyboardObject->randLeftTarget;
                keyboardObject->top =
                    ((sSelectedCharacterTransitionTimer[i] * (210 - keyboardObject->randTopTarget)) / 15) +
                    keyboardObject->randTopTarget;
                sSelectedCharacterTransitionTimer[i]++;
                if (sSelectedCharacterTransitionTimer[i] >= 15) {
                    sSelectedCharacterTransitionTimer[i] = 0;
                    keyboardObject->keyboardCharacter[0] = '\0';
                }
            }
        }
        spinningCharacterCompTexInfo =
            sFont1CompTexInfos[Font_GetCharIndex(&sNameKeyboardCharacters[keyboardIndex], FONT_SET_UPPERCASE_ONLY)];
        sSpinningKeyboardCharacterCompTexInfo = spinningCharacterCompTexInfo;

        xPositions[0] = xPositions[2] = 0.0f - (spinningCharacterCompTexInfo->width * 0.5f);
        xPositions[1] = xPositions[3] = xPositions[0] + spinningCharacterCompTexInfo->width;

        yPositions[0] = yPositions[1] = spinningCharacterCompTexInfo->height * 0.5f;
        yPositions[2] = yPositions[3] = yPositions[0] - spinningCharacterCompTexInfo->height;

        vtx = gGfxPool->spinningKeyboardCharacterVtx;
        for (i = 0; i < 4; i++) {
            x = Math_Round(xPositions[i]);
            y = Math_Round(yPositions[i]);
            if (i & 1) {
                textureSCoordinates[i] = spinningCharacterCompTexInfo->width;
            } else {
                textureSCoordinates[i] = 0.0f;
            }

            if (i >= 2) {
                textureTCoordinates[i] = spinningCharacterCompTexInfo->height;
            } else {
                textureTCoordinates[i] = 0.0f;
            }
            s = textureSCoordinates[i] * 32.0f;
            t = textureTCoordinates[i] * 32.0f;
            SET_VTX(vtx, x, y, 0, s, t, 0, 0, 0, 0);
            vtx++;
        }
        temp_fv0 = (s16) keyboardCursorY - spinningCharacterCompTexInfo->height * 0.5f;
        spB8 = (s16) keyboardCursorX + 8.0f;
        vp = &gGfxPool->unk_2C2C8[1];
        vp->vp.vscale[0] = SCREEN_WIDTH * 4;
        vp->vp.vscale[1] = SCREEN_HEIGHT * 4;
        vp->vp.vscale[2] = 0x1FF;
        vp->vp.vscale[3] = 0;
        vp->vp.vtrans[0] = spB8 * 4.0f;
        vp->vp.vtrans[1] = temp_fv0 * 4.0f;
        vp->vp.vtrans[2] = 0x1FF;
        vp->vp.vtrans[3] = 0;

        t = gGameFrameCount % 128;
        i = ((t << 12) / 127) % 4096;

        t = gGameFrameCount % 32;
        temp_fv0 = t / 31.0f;

        if ((gGameFrameCount / 64) % 2) {
            temp_fv0 = 1.0f - temp_fv0;
        }
        spB8 = (100.0f * temp_fv0) + 400.0f;
        if (spB8 > 500.0f) {
            spB8 = 500.0f;
        }

        Matrix_SetFrustrum(&gGfxPool->unk_2B2C8[1], &mtxF, 60.0f, 16.0f, 8129.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT,
                           0.0f, &sSpinningKeyboardCharacterPerspectiveScale);
        Matrix_SetLookAt(&gGfxPool->unk_2B2C8[2], &mtxF, 0.0f, 0.0f, spB8, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        Matrix_SetTransRot(&gGfxPool->unk_2B2C8[3], &mtxF, spB8, 0, i, i, 0.0f, 0.0f, 0.0f);
    }
}

s32 RecordsEntry_GetCharacterKeyboardIndex(s8 character) {
    s32 i;
    s8 keyboardCharacter;
    s32 characterKeyboardIndex = 0;

    if (character == ' ') {
        keyboardCharacter = '>';
    } else {
        keyboardCharacter = character;
    }

    for (i = 0; i < KEYBOARD_TOTAL_COUNT; i++) {
        if (sNameKeyboardCharacters[i] == keyboardCharacter) {
            characterKeyboardIndex = i;
            break;
        }
    }

    return characterKeyboardIndex;
}

void RecordsEntry_SaveRecordName(CourseInfo* courseInfo) {
    s32 i;
    s32 nameEntryCharacter;

    sRecordsEntryNameEntryState = NAME_ENTRY_TRANSITION_OUT;
    sRecordsEntryNameEntryTransitionTimer = 0;
    RecordsEntry_InitKeyboardObjects(true);

    for (i = 0; i < 4; i++) {
        if (i < gRecordNameEnteredLength) {
            nameEntryCharacter = gRecordNameEntered[i];
        } else {
            nameEntryCharacter = '\0';
        }

        courseInfo->recordNames[gCurrentTimeAttackRecordPosition - 1][i] = nameEntryCharacter;
    }
#ifdef EXPANSION_KIT
    if (gCourseIndex < COURSE_EDIT_1) {
#endif
        Save_SaveCourseRecordProfiles(gCourseIndex);
#ifdef EXPANSION_KIT
    }
#endif
}

signed char sNameEntryStr[] = "NAME ENTRY";

Gfx* RecordsEntry_DrawNameEntry(Gfx* gfx) {
    s32 i;
    s32 alpha;
    s32 temp;
    s32 temp2;
    s32 keyboardIndex;
    s16 state;
    s32 nameEntryWidth;
    s32 nameEntryLeft;
    s32 keyboardCharacterLeft;
    s32 pad;
    s8 keyboardCharacterStr[2];
    KeyboardObject* keyboardObject;

    if (sRecordsEntryNameEntryState == NAME_ENTRY_START) {
        return gfx;
    }
    state = sRecordsEntryNameEntryState;
    if ((sPreviousRecordsEntryNameEntryState == NAME_ENTRY_TRANSITION_IN) &&
        (sRecordsEntryNameEntryState == NAME_ENTRY_KEYBOARD)) {
        state = NAME_ENTRY_TRANSITION_IN;
    }
    switch (state) {
        case NAME_ENTRY_KEYBOARD:
            keyboardIndex = (sKeyboardCursorY * KEYBOARD_COLUMN_COUNT) + sKeyboardCursorX;
            gfx = Menus_DrawBeveledBox(gfx, 52, 54, 268, 220, 0, 0, 0, 128);
            nameEntryWidth = Font_GetStringWidth(sNameEntryStr, FONT_SET_3, 1);
            nameEntryLeft = (SCREEN_WIDTH - nameEntryWidth) / 2;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gfx = Font_DrawString(gfx, nameEntryLeft + 2, 81, sNameEntryStr, 1, FONT_SET_3, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
            gfx = Font_DrawString(gfx, nameEntryLeft, 79, sNameEntryStr, 1, FONT_SET_3, 0);

            // Draw Keyboard
            keyboardCharacterStr[1] = '\0';
            for (i = 0; i < KEYBOARD_TOTAL_COUNT; i++) {
                keyboardCharacterStr[0] = sNameKeyboardCharacters[i];
                temp = (16 - Font_GetStringWidth(keyboardCharacterStr, FONT_SET_1, 1)) / 2;
                keyboardCharacterLeft = ((i % KEYBOARD_COLUMN_COUNT) * 20) + temp + 62;
                if (keyboardIndex != i) {
                    gfx = Font_DrawString(gfx, keyboardCharacterLeft, ((i / KEYBOARD_COLUMN_COUNT) * 20) + 100,
                                          keyboardCharacterStr, 1, FONT_SET_1, 0);
                }
            }

            // Draw Record Name
            for (i = 0; i < 3; i++) {
                gDPPipeSync(gfx++);
                if (gRecordNameEnteredLength != i) {
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                } else {
                    gfx = func_8007F090(gfx, 255, 0, 0);
                }
                keyboardCharacterLeft = (i * 20) + 132;
                gfx = Font_DrawString(gfx, keyboardCharacterLeft, 214, "_", 1, FONT_SET_1, 1);
                if (sKeyboardObjects[i].keyboardCharacter[0] == '\0') {
                    keyboardCharacterStr[0] = gRecordNameEntered[i];
                    keyboardCharacterLeft += (16 - Font_GetStringWidth(keyboardCharacterStr, FONT_SET_1, 1)) / 2;
                    gfx = Font_DrawString(gfx, keyboardCharacterLeft, 210, keyboardCharacterStr, 1, FONT_SET_1, 0);
                }
            }

            // Draw Transitioning Entered Characters
            for (i = 0, keyboardObject = sKeyboardObjects; i < 3; i++, keyboardObject++) {
                if (keyboardObject->keyboardCharacter[0] == '\0') {
                    continue;
                }

                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 128);
                gfx = Font_DrawString(gfx, keyboardObject->left, keyboardObject->top, keyboardObject->keyboardCharacter,
                                      1, FONT_SET_1, 1);
            }

            // Draw Cursor Character
            gSPDisplayList(gfx++, D_80148C0);
            gSPViewport(gfx++, &D_1000000.unk_2C2C8[1]);
            gSPPerspNormalize(gfx++, sSpinningKeyboardCharacterPerspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_2B2C8[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gSPMatrix(gfx++, &D_1000000.unk_2B2C8[2], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            gSPMatrix(gfx++, &D_1000000.unk_2B2C8[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(gfx++, D_1000000.spinningKeyboardCharacterVtx, 4, 0);

            gDPLoadTextureBlock(gfx++, func_800783AC(sSpinningKeyboardCharacterCompTexInfo->unk_04), G_IM_FMT_RGBA,
                                G_IM_SIZ_16b, sSpinningKeyboardCharacterCompTexInfo->width,
                                sSpinningKeyboardCharacterCompTexInfo->height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
            break;
        case NAME_ENTRY_TRANSITION_IN:
            alpha = ((sRecordsEntryNameEntryTransitionTimer * 255) - 255) / 60;
            if (alpha < 0) {
                alpha = 0;
            } else if (alpha > 255) {
                alpha = 255;
            }
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);

            for (i = 0, keyboardObject = sKeyboardObjects; i < KEYBOARD_TOTAL_COUNT; i++, keyboardObject++) {
                gfx = Font_DrawString(gfx, keyboardObject->left, keyboardObject->top, keyboardObject->keyboardCharacter,
                                      1, FONT_SET_1, 1);
            }
            break;
        case NAME_ENTRY_TRANSITION_OUT:
            alpha = ((1.0f - ((sRecordsEntryNameEntryTransitionTimer - 1) / 60.0f)) * 255.0f);
            if (alpha < 0) {
                alpha = 0;
            } else if (alpha > 255) {
                alpha = 255;
            }

            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);

            for (i = 0, keyboardObject = sKeyboardObjects; i < KEYBOARD_TOTAL_COUNT; i++, keyboardObject++) {
                gfx = Font_DrawString(gfx, keyboardObject->left, keyboardObject->top, keyboardObject->keyboardCharacter,
                                      1, FONT_SET_1, 1);
            }
            break;
    }
    sPreviousRecordsEntryNameEntryState = sRecordsEntryNameEntryState;
    return gfx;
}
