#include "global.h"
#include "course_edit.h"
#include "fzx_camera.h"
#include "fzx_course.h"
#include "fzx_expansion_kit.h"
#include "src/overlays/ovl_i3/hud.h"
#include "src/overlays/ovl_i3/minimap.h"
#include ASSET_HEADER(setup_gfx.h)
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

extern MenuDropItem gRoadTypeMenuItems;
extern MenuDropItem gHRoadTypeMenuItems;
extern MenuDropItem gPipeTypeMenuItems;
extern MenuDropItem gCylinderTypeMenuItems;
extern MenuDropItem gHalfPipeTypeMenuItems;
extern MenuDropItem gTunnelTypeMenuItems;
extern MenuDropItem gTRoadTypeMenuItems;

s32 sCourseEditDrawState = 0;
s32 D_xk2_800F7034 = 0;
s32 D_xk2_800F7038 = 16;
s32 gCourseEditInfoControlPoint = -1;
s32 D_xk2_800F7040 = 0;
s32 gCourseEditDrawDetailedCourse = 0;
s32 D_xk2_800F7048 = 0;
s32 D_xk2_800F704C = -1;
s32 D_xk2_800F7050 = 0;
s32 D_xk2_800F7054 = 0;
s32 gCourseEditCourseSplitIndex = 0;
s32 gCourseEditHighlightedIconIndex = -1;
s32 gCourseEditMiniMachineCharacter = 0;
s32 gCourseEditMiniMachineColorPalette = 0;
s32 D_xk2_800F7068 = -1;
s32 D_xk2_800F706C = -1;
s8 sCourseEditTrackShapeLineColors[][4] = {
    { 64, 64, 64, 1 },     // TRACK_SHAPE_ROAD
    { 192, 64, 64, 1 },    // TRACK_SHAPE_WALLED_ROAD
    { 100, 150, 255, 10 }, // TRACK_SHAPE_PIPE
    { 64, 192, 64, 10 },   // TRACK_SHAPE_CYLINDER
    { 255, 255, 100, 10 }, // TRACK_SHAPE_HALF_PIPE
    { 192, 64, 64, 10 },   // TRACK_SHAPE_TUNNEL
    { 64, 192, 64, 1 },    // TRACK_SHAPE_AIR
    { 100, 150, 255, 1 },  // TRACK_SHAPE_BORDERLESS_ROAD
};

u8 sCourseEditTrackShapeEncStrs[][8] = {
    //  どうろ
    { 0x20, 0x8F, 0xB3, 0xDB, 0x00, 0x00, 0x00, 0x00 },
    //  Hどうろ
    { 0x20, 0x48, 0x8F, 0xB3, 0xDB, 0x00, 0x00, 0x00 },
    //  パイプ
    { 0x20, 0x95, 0xB2, 0x97, 0x00, 0x00, 0x00, 0x00 },
    // シリンダー
    { 0xBC, 0xD8, 0xDD, 0x8B, 0xB0, 0x00, 0x00, 0x00 },
    // ハーフパイプ
    { 0xCA, 0xB0, 0xCC, 0x95, 0xB2, 0x97, 0x00, 0x00 },
    //  トンネル
    { 0x20, 0xC4, 0xDD, 0xC8, 0xD9, 0x00, 0x00, 0x00 },
    //  スペース
    { 0x20, 0xBD, 0x98, 0xB0, 0xBD, 0x00, 0x00, 0x00 },
    //  Tどうろ
    { 0x20, 0x54, 0x8F, 0xB3, 0xDB, 0x00, 0x00, 0x00 },
};

u8 sCourseEditTrackShapeBoxColors[][3] = {
    140, 200, 255, // TRACK_SHAPE_ROAD
    80,  200, 140, // TRACK_SHAPE_WALLED_ROAD
    200, 180, 255, // TRACK_SHAPE_PIPE
    90,  180, 180, // TRACK_SHAPE_CYLINDER
    120, 255, 200, // TRACK_SHAPE_HALF_PIPE
    255, 255, 150, // TRACK_SHAPE_TUNNEL
    200, 200, 200, // TRACK_SHAPE_AIR
    255, 200, 255, // TRACK_SHAPE_BORDERLESS_ROAD
};

s32 sCourseEditRoadMenuItemIndexMap[] = {
    -1, // ROAD_START_LINE
    -1, // ROAD_1
    0,  // ROAD_2
    1,  // ROAD_3
    2,  // ROAD_4
    3,  // ROAD_5
    4,  // ROAD_6
    1,  // ROAD_7 ?
    2,  // ROAD_8 ?
    3,  // ROAD_9 ?
};

MenuDropItem* sCourseEditTrackShapeMenuItems[] = {
    &gRoadTypeMenuItems,     // TRACK_SHAPE_ROAD
    &gHRoadTypeMenuItems,    // TRACK_SHAPE_WALLED_ROAD
    &gPipeTypeMenuItems,     // TRACK_SHAPE_PIPE
    &gCylinderTypeMenuItems, // TRACK_SHAPE_CYLINDER
    &gHalfPipeTypeMenuItems, // TRACK_SHAPE_HALF_PIPE
    &gTunnelTypeMenuItems,   // TRACK_SHAPE_TUNNEL
    NULL,                    // TRACK_SHAPE_AIR
    &gTRoadTypeMenuItems,    // TRACK_SHAPE_BORDERLESS_ROAD
};

extern unk_807B3C20 D_802CB6D0;

void func_xk2_800DF5C0(void) {
    s32 i;

    if (gControllers[1].buttonPressed & BTN_START) {
        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {}
    }
}

extern bool gInCourseEditTestRun;
extern Mtx gCourseEditCourseLookAtMtx;

Gfx* CourseEdit_DrawUpdateState(Gfx* gfx) {

    switch (sCourseEditDrawState) {
        case 0:
            sCourseEditDrawState = 1;
            Matrix_SetLockedLookAt(&gCourseEditCourseLookAtMtx, NULL, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
                                   0.0f, 0.0f, 0.0f, 0.0f);
            break;
        case 1:
            func_xk2_800DF5C0();
            func_xk1_800260E4();
            if (!gInCourseEditTestRun) {
                gSPMatrix(gfx++, K0_TO_PHYS(&gCourseEditCourseLookAtMtx), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            }
            gfx = CourseEdit_DrawMain(gfx);
            break;
    }
    return gfx;
}

void CourseEdit_DrawTooltipIntroHelper(Gfx** gfxP);

extern unk_80225800 D_2000000;
extern char* gCourseEditMessageStrs[];
extern s32 D_80119880;
extern u16* gCourseEditIconTextures[];
extern u8 D_80794E14;
extern s32 gCourseEditDetailedCourseEnabled;
extern unk_800D6CA0 D_800D6CA0;

extern s32 gCourseEditCursorXPos;
extern s32 gCourseEditCursorYPos;
extern s32 D_xk2_800F7404;
extern s32 gCourseEditCameraOnlyMode;

extern u8 gCourseEditErrors[];

Gfx* CourseEdit_DrawMain(Gfx* gfx) {

    gSPDisplayList(gfx++, D_30004A8);
    gSPDisplayList(gfx++, D_9014AA0);

    if (gInCourseEditTestRun) {
        gSPMatrix(gfx++, &D_2000000.unk_000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(gfx++);
        gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gfx = Background_Draw(gfx, 0, SCISSOR_BOX_FULL_SCREEN);
        gfx = Course_Draw(gfx, 0);
        gfx = Course_GadgetsDraw(gfx, 0);
        gSPLoadUcodeL(gfx++, gspF3DFLX2_Rej_fifo);
        CourseEdit_DrawSetup(&gfx);
        gfx = Racer_Draw(gfx, 0);
        gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
        gSPMatrix(gfx++, &D_2000000.unk_000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        CourseEdit_DrawSetup(&gfx);
        gfx = Minimap_DrawCourseMinimap(gfx, 0, 0);
        gfx = Hud_DrawPlayerSpeed(gfx, 0, 0);
        return Hud_DrawReverse(gfx, 0, 0);
    }
    if (CourseEdit_CheckInvalidJoins()) {
        gCourseEditErrors[COURSE_EDIT_ERROR_INVALID_PART_PLACEMENT] = true;
        gCourseEditDetailedCourseEnabled = 0;
        gCourseEditIconTextures[1] = aCourseEditGoldLineModeIconTex;
        gCourseEditDrawDetailedCourse = 0;
    }
    gfx = CourseEdit_DrawCourseBackground(gfx);
    gSPDisplayList(gfx++, D_9014B68);
    gSPDisplayList(gfx++, aExecuteCourseEditAxisDL);
    gSPMatrix(gfx++, &D_2000000.unk_000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((D_802CB6D0.controlPointCount >= 4) && (gCourseEditDrawDetailedCourse == 1) &&
        (D_800D6CA0.unreasonableControlPoint == -1)) {
        gSPDisplayList(gfx++, D_9014BA0);
        if (D_xk2_800F7404 == 0) {
            gfx = Course_DrawEditCourse(gfx);
        }
    }
    gSPMatrix(gfx++, &D_2000000.unk_000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((D_802CB6D0.controlPointCount >= 4) && (D_800D6CA0.unreasonableControlPoint == -1) && (D_xk2_800F7404 == 0) &&
        !gCourseEditErrors[COURSE_EDIT_ERROR_TOO_MUCH_TO_DISPLAY]) {
        gfx = Course_GadgetsDraw(gfx, 0);
    }
    if (D_xk2_800F7404 != 0) {
        D_xk2_800F7404 = 0;
    } else {
        gfx = CourseEdit_DrawL3DEX(gfx);
        gfx = CourseEdit_DrawControlPoints(gfx);
        gfx = CourseEdit_DrawStartMarker(gfx);
        gfx = CourseEdit_DrawMiniMachine(gfx);
    }
    gfx = CourseEdit_DrawSelectionBox(gfx);
    CourseEdit_DrawControlPointHighlight(&gfx);
    CourseEdit_UpdateMouseClick();
    gSPDisplayList(gfx++, aCourseEditMouseClickDL);
    CourseEdit_DrawOverlapMouseClick(&gfx);
    CourseEdit_DrawUnreasonablePointMouseClick(&gfx);
    CourseEdit_DrawInvalidPartPlacementMouseClick(&gfx);
    CourseEdit_DrawTooNarrowForJointMouseClick(&gfx);
    CourseEdit_DrawTooLowMouseClick(&gfx);
    CourseEdit_DrawMidPointOOBMouseClick(&gfx);
    CourseEdit_DrawIcons(&gfx);
    gfx = CourseEdit_DrawCourseTitle(gfx);
    gfx = CourseEdit_DrawGeneralInfo(gfx);
    gfx = CourseEdit_DrawControlPointCountVenueId(gfx);
    gfx = CourseEdit_DrawInfoWindows(gfx);
    gfx = func_xk2_800EDF90(gfx);
    CourseEdit_DrawPressBToReturnToPreviousState(&gfx);
    if (gCourseEditCameraOnlyMode) {
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 30, 70, 255);
        gSPTextureRectangle(gfx++, 0 << 2, 0 << 2, SCREEN_WIDTH << 2, 56 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    } else {
        gfx = CourseEdit_DrawMenu(gfx);
    }
    gfx = CourseEdit_DrawBGMTooltip(gfx);
    CourseEdit_DrawCameraOnlyInstructions(&gfx);
    if (D_80794E14 == 0) {
        gfx = CourseEdit_DrawFileSelectRegisterMenu(gfx);
    }

    if ((D_800D6CA0.state == 0x11) || (D_800D6CA0.state == 0x23) || (D_800D6CA0.state == 0xFF)) {
        EKFileMenu_DrawYesNoOption(&gfx);
    }
    if (D_800D6CA0.state == 0xFF) {
        func_xk2_800EECD4(&gfx, 0, 72, gCourseEditMessageStrs[30], 30);
    }
    if (!gCourseEditCameraOnlyMode) {
        gfx = CourseEdit_DrawCursor(gfx);
    }
    CourseEdit_DrawCopyToDifferentDisk(&gfx);
    func_xk2_800EE67C(&gfx);
    if (!gCourseEditCameraOnlyMode) {
        CourseEdit_DrawIconTooltip(&gfx);
        CourseEdit_DrawMenuWidgetTooltip(&gfx);
    }
    CourseEdit_DrawTooltipIntroHelper(&gfx);
    if (D_800D6CA0.state == COURSE_EDIT_OPTIONS_MENU) {
        CourseEditOptionsMenu_Draw(&gfx);
    }
    if (D_800D6CA0.state == COURSE_EDIT_NAME_ENTRY) {
        gfx = ExpansionKit_NameEntryDraw(gfx, &gCourseEditCursorXPos, &gCourseEditCursorYPos);
        if (D_80119880 == 9) {
            s32 x = 24;
            s32 y = 56;
            s32 width = 256;
            gSPDisplayList(gfx++, D_3000510);
            gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
            gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + width + 2) << 2, y << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
            gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 16) << 2, (x + width + 2) << 2, (y + 16 + 2) << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, x << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x + width) << 2, y << 2, (x + width + 2) << 2, (y + 16) << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
            gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPDisplayList(gfx++, D_3000540);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_xk1_800264C0(gfx, 24, 56, 16);
        }
    }
    CourseEdit_DrawClearCourseWarning(&gfx);
    CourseEdit_DrawClearEntryWarning(&gfx);
    return gfx;
}

extern unk_80128C94* D_80128C94;

void func_xk2_800DFFF8(void) {
    CourseSegment* segment;
    Vtx* vtx;
    s32 i;
    Vec3f tangent;
    Vec3f side;

    if (D_802CB6D0.controlPointCount < 2) {
        return;
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        segment = &D_802CB6D0.segments[i];
        Course_SplineGetTangent(segment, 0.0f, &tangent);
        Math_NormalizeXYZ(&tangent.x, &tangent.y, &tangent.z);

        side.x = (segment->up.y * tangent.z) - (tangent.y * segment->up.z);
        side.y = (segment->up.z * tangent.x) - (tangent.z * segment->up.x);
        side.z = (segment->up.x * tangent.y) - (tangent.x * segment->up.y);
        vtx = &D_80128C94->unk_0180[i * 6];
        vtx->v.ob[0] = segment->pos.x;
        vtx->v.ob[1] = segment->pos.y;
        vtx->v.ob[2] = segment->pos.z;
        vtx++;
        vtx->v.ob[0] = segment->pos.x;
        vtx->v.ob[1] = 0;
        vtx->v.ob[2] = segment->pos.z;
        vtx++;
        vtx->v.ob[0] = segment->pos.x + (300.0f * tangent.x);
        vtx->v.ob[1] = segment->pos.y + (300.0f * tangent.y);
        vtx->v.ob[2] = segment->pos.z + (300.0f * tangent.z);
        vtx++;
        vtx->v.ob[0] = segment->pos.x + (300.0f * segment->up.x);
        vtx->v.ob[1] = segment->pos.y + (300.0f * segment->up.y);
        vtx->v.ob[2] = segment->pos.z + (300.0f * segment->up.z);
        vtx++;
        vtx->v.ob[0] = segment->pos.x + (segment->radiusLeft * side.x);
        vtx->v.ob[1] = segment->pos.y + (segment->radiusLeft * side.y);
        vtx->v.ob[2] = segment->pos.z + (segment->radiusLeft * side.z);
        vtx++;
        vtx->v.ob[0] = segment->pos.x - (segment->radiusRight * side.x);
        vtx->v.ob[1] = segment->pos.y - (segment->radiusRight * side.y);
        vtx->v.ob[2] = segment->pos.z - (segment->radiusRight * side.z);
    }
}

extern s32 gCourseEditMenuCursorXPos;
extern s32 gCourseEditMenuCursorYPos;

Gfx* CourseEdit_DrawCursor(Gfx* gfx) {
    s32 left;
    s32 top;

    if (D_800D6CA0.moveMode == 1) {
        return gfx;
    }
    // clang-format off
    if (D_800D6CA0.state == 1) {
        left = gCourseEditMenuCursorXPos; \
        top = gCourseEditMenuCursorYPos;
    } else {
        left = gCourseEditCursorXPos; \
        top = gCourseEditCursorYPos;
    }
    // clang-format on
    if (D_800D6CA0.state == 0x20) {
        return gfx;
    }
    if (D_800D6CA0.state == COURSE_EDIT_OPTIONS_MENU) {
        return gfx;
    }
    if (D_800D6CA0.state == 3) {
        return gfx;
    }
    if (D_800D6CA0.state == 0x10) {
        return gfx;
    }
    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, aCourseEditCursorTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern u32 gGameFrameCount;
extern s32 D_800DCCFC;
extern unk_80128690 D_80128690[];

Gfx* CourseEdit_DrawControlPoints(Gfx* gfx) {
    s32 i;
    s32 closestControlPoint;
    s32 screenPosX;
    s32 screenPosY;
    f32 pulseScale;
    Vec3f pos;
    s32 blueBrightness;

    if (gInCourseEditTestRun) {
        return gfx;
    }
    closestControlPoint = CourseEdit_GetClosestControlPoint(150.0f);
    gSPDisplayList(gfx++, aCourseEditControlPointDL);

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        gDPPipeSync(gfx++);
        if (D_80128690[i].isSelected) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == D_800D6CA0.overlappingControlPoint) && (D_800DCCFC != 0)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == D_800D6CA0.unreasonableControlPoint) && (D_800DCCFC != 0)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == closestControlPoint) && (D_800D6CA0.moveMode != 1)) {
            if (D_800DCCFC != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        } else if (i == 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 255, 128);
        } else {
            blueBrightness = Math_Round(D_802CB6D0.segments[i].pos.y);
            if (blueBrightness < 0) {
                blueBrightness = 0;
            }
            blueBrightness = (blueBrightness * 255) / 5000;
            gDPSetPrimColor(gfx++, 0, 0, blueBrightness, blueBrightness, 255, 255);
        }
        pos = D_802CB6D0.segments[i].pos;

        if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) != 0) {
            continue;
        }

        if (D_80128690[i].isSelected) {
            pulseScale = ((gGameFrameCount % 10) * 0.2f) + 1.0f;
        } else {
            pulseScale = 1.0f;
        }

        gSPTextureRectangle(
            gfx++, Math_Round(screenPosX - (4.0f * pulseScale)) << 2, Math_Round(screenPosY - (4.0f * pulseScale)) << 2,
            Math_Round(screenPosX + (4.0f * pulseScale)) << 2, Math_Round(screenPosY + (4.0f * pulseScale)) << 2, 0, 0,
            0, Math_Round((1 << 10) / pulseScale), Math_Round((1 << 10) / pulseScale));
    }
    return gfx;
}

s32 CourseEdit_GetSplitControlPoint(s32 split) {
    CourseSegment* segment;
    s32 i;
    s32 startSplit;
    s32 endSplit;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        segment = &D_802CB6D0.segments[i];
        startSplit = D_80128690[segment->segmentIndex].startSplit;
        endSplit = D_80128690[segment->segmentIndex].endSplit;
        if (startSplit > endSplit) {
            startSplit = 0;
        }
        if ((split >= startSplit) && (split < endSplit)) {
            break;
        }
    }
    return i;
}

extern unk_80128C94 D_6000000;

extern s32 D_800DCD04;
extern s32 gCreateOption;

extern CourseSplitInfo gCourseEditCourseSplitInfos[];

Gfx* CourseEdit_DrawCourseLines(Gfx* gfx) {
    s32 i;
    s32 shapeIndex;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);
    gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_NOOP2);

    if ((D_800D6CA0.unreasonableControlPoint != -1) || (D_802CB6D0.controlPointCount < 4)) {
        return CourseEdit_DrawControlPointDirectLines(gfx);
    }
    if (gCourseEditDrawDetailedCourse != 0) {
        return gfx;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }

    for (i = 0; i < gCourseEditCourseSplitIndex; i++) {
        if ((CourseEdit_GetSplitControlPoint(i) == D_800D6CA0.selectedControlPoint) && (D_800DCD04 == 0) &&
            (gCreateOption != CREATE_OPTION_POINT)) {
            continue;
        }
        gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
        gDPPipeSync(gfx++);
        shapeIndex = TRACK_SHAPE_INDEX(gCourseEditCourseSplitInfos[i].trackSegmentInfo & TRACK_SHAPE_MASK);

        gDPSetPrimColor(gfx++, 0, 0, sCourseEditTrackShapeLineColors[shapeIndex][0],
                        sCourseEditTrackShapeLineColors[shapeIndex][1], sCourseEditTrackShapeLineColors[shapeIndex][2],
                        255);
        gSPLineW3D(gfx++, 0, 1, sCourseEditTrackShapeLineColors[shapeIndex][3], 0);
    }
    return gfx;
}

Gfx* CourseEdit_DrawSelectedSegmentLine(Gfx* gfx) {
    CourseSegment* segment;
    s32 end;
    s32 start;
    s32 i;

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }

    if (gCreateOption == CREATE_OPTION_POINT) {
        return gfx;
    }

    if (D_800D6CA0.unreasonableControlPoint != -1) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_NOOP2);
        if (D_800D6CA0.selectedControlPoint != -1) {
            start = D_800D6CA0.selectedControlPoint;
        } else {
            start = 0;
        }
        end = D_802CB6D0.segments[start].next->segmentIndex;
        if (end < start) {
            for (i = 0; i < end; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }

            for (i = start; i < D_802CB6D0.controlPointCount; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        } else {
            for (i = start; i < end; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        }
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - D_xk2_800F7034);
    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);

    if (D_800D6CA0.selectedControlPoint != -1) {
        segment = &D_802CB6D0.segments[D_800D6CA0.selectedControlPoint];
    } else {
        segment = &D_802CB6D0.segments[0];
    }

    start = D_80128690[segment->segmentIndex].startSplit;
    end = D_80128690[segment->segmentIndex].endSplit;

    if (end < start) {
        for (i = 0; i < end; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }

        for (i = start; i < gCourseEditCourseSplitIndex; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    } else {
        for (i = start; i < end; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    }

    return gfx;
}

Gfx* CourseEdit_DrawSegmentLine(Gfx* gfx, s32 controlPoint) {
    s32 startSplit;
    s32 endSplit;
    s32 i;

    startSplit = D_80128690[controlPoint].startSplit;
    endSplit = D_80128690[controlPoint].endSplit;

    if (endSplit < startSplit) {
        if (startSplit < 0x10000) {
            for (i = 0; i < endSplit; i++) {
                gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }

            for (i = startSplit; i < gCourseEditCourseSplitIndex; i++) {
                gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        }
    } else {
        for (i = startSplit; i < endSplit; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    }
    return gfx;
}

extern s32 gPartsStyleOption;

Gfx* CourseEdit_DrawTrapLine(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_TRAP) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.landmine[i] == LANDMINE_NONE) {
            continue;
        }
        gfx = CourseEdit_DrawSegmentLine(gfx, i);
    }
    return gfx;
}

Gfx* CourseEdit_DrawDashLine(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_DASH) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.dash[i] == DASH_NONE) {
            continue;
        }
        gfx = CourseEdit_DrawSegmentLine(gfx, i);
    }
    return gfx;
}

Gfx* CourseEdit_DrawJumpLine(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_JUMP) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.jump[i] == JUMP_NONE) {
            continue;
        }
        gfx = CourseEdit_DrawSegmentLine(gfx, i);
    }
    return gfx;
}

Gfx* CourseEdit_DrawGateLine(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_GATE) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.gate[i] == GATE_NONE) {
            continue;
        }
        gfx = CourseEdit_DrawSegmentLine(gfx, i);
    }
    return gfx;
}

Gfx* CourseEdit_DrawSignLine(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_SIGN) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.sign[i] == SIGN_NONE) {
            continue;
        }
        gfx = CourseEdit_DrawSegmentLine(gfx, i);
    }
    return gfx;
}

Gfx* CourseEdit_DrawPartsLines(Gfx* gfx) {

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }
    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }
    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return gfx;
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, D_xk2_800F7034);

    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);

    gfx = CourseEdit_DrawTrapLine(gfx);
    gfx = CourseEdit_DrawDashLine(gfx);
    gfx = CourseEdit_DrawJumpLine(gfx);
    gfx = CourseEdit_DrawGateLine(gfx);
    gfx = CourseEdit_DrawSignLine(gfx);
    return gfx;
}

void CourseEdit_DrawControlPointAxis(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;

    gfx = *gfxP;

    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 6, 0);
        gSPDisplayList(gfx++, D_70207A0);
    }

    *gfxP = gfx;
}

extern FrameBuffer* gFrameBuffers[];

void CourseEdit_DrawSetup(Gfx** gfxP) {
    Gfx* gfx;

    gfx = *gfxP;
    gfx = Segment_SetTableAddresses(gfx);
    gSPDisplayList(gfx++, D_3000338);
    gSPSetGeometryMode(gfx++, G_CLIPPING);
    gSPClipRatio(gfx++, FRUSTRATIO_2);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    gDPSetDepthImage(gfx++, K0_TO_PHYS(0x803DBC00));
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gfx = CourseEdit_DrawCamera(gfx);
    if (!gInCourseEditTestRun) {
        gSPMatrix(gfx++, K0_TO_PHYS(&gCourseEditCourseLookAtMtx), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    }
    *gfxP = gfx;
}

Gfx* CourseEdit_DrawL3DEX(Gfx* gfx) {

    if (gInCourseEditTestRun) {
        return gfx;
    }

    gSPLoadUcodeL(gfx++, gspL3DEX2_fifo);
    CourseEdit_DrawSetup(&gfx);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gfx = CourseEdit_DrawCourseLines(gfx);
    gfx = CourseEdit_DrawPartsLines(gfx);
    gfx = CourseEdit_DrawSelectedSegmentLine(gfx);
    CourseEdit_DrawControlPointAxis(&gfx);
    gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
    CourseEdit_DrawSetup(&gfx);

    // TODO: move to more appropriate place
    PRINTF("(%d - %d)\n");
    PRINTF("LINE vtxi0 %d, vtxi1 %d\n");
    return gfx;
}

extern s32 gExpansionKitEncStrEncType;
extern CourseSegment* gCourseEditInfoSegment;
extern s32 gCourseEditCameraOnlyMode;
extern s32 D_xk2_80128CA0;

void CourseEdit_DrawControlPointInfo(Gfx** gfxP) {
    u8 strBuf[0x40];
    s32 var_a1;
    s32 left;
    s32 top;
    s32 trackTypeMenuIndex;
    s32 shape;
    Gfx* gfx;
    MenuDropItem* menuItem;

    top = 60;
    left = 232;
    if (gCourseEditCameraOnlyMode) {
        return;
    }
    gfx = *gfxP;
    if (gCourseEditInfoControlPoint == -1) {
        return;
    }
    if (gCourseEditCursorXPos > 224) {
        left = 24;
    }
    D_xk2_80128CA0 = 0x40;
    gCourseEditInfoSegment = &D_802CB6D0.segments[gCourseEditInfoControlPoint];
    CourseEdit_DrawControlPointInfoBackground(&gfx, left, top, 64, 116);
    left += 4;
    top += 4;
    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 56) << 2, (top + 50) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    var_a1 = (gCourseEditInfoSegment->segmentIndex + 1) / 10;
    if (var_a1) {
        gDPLoadTextureBlock(gfx++, aCourseEditNumberSheetTex + var_a1 * 0x90, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (left + 3) << 2, top << 2, (left + 15) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
    }
    var_a1 = (gCourseEditInfoSegment->segmentIndex + 1) % 10;

    gDPLoadTextureBlock(gfx++, aCourseEditNumberSheetTex + var_a1 * 0x90, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + 15) << 2, top << 2, (left + 0x1B) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gDPLoadTextureBlock(gfx++, aCourseEditNumberTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + 0x1B) << 2, top << 2, (left + 0x33) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    left += 4;
    top += 16;

    shape = gCourseEditInfoSegment->trackSegmentInfo & TRACK_SHAPE_MASK;
    switch (shape) {
        case TRACK_SHAPE_ROAD:
            trackTypeMenuIndex =
                sCourseEditRoadMenuItemIndexMap[gCourseEditInfoSegment->trackSegmentInfo & TRACK_TYPE_MASK];
            break;
        case TRACK_SHAPE_AIR:
            trackTypeMenuIndex = 0;
            break;
        default:
            trackTypeMenuIndex = gCourseEditInfoSegment->trackSegmentInfo & TRACK_TYPE_MASK;
            CourseEdit_NumToPaddedInfoEncStr(strBuf, trackTypeMenuIndex + 1, 2);
            break;
    }

    CourseEdit_NumToPaddedInfoEncStr(strBuf, trackTypeMenuIndex + 1, 2);
    if (trackTypeMenuIndex != -1) {
        var_a1 = TRACK_SHAPE_INDEX((u32) (gCourseEditInfoSegment->trackSegmentInfo & TRACK_SHAPE_MASK));
        if (var_a1 == TRACK_SHAPE_INDEX(TRACK_SHAPE_AIR)) {
            var_a1 = 0;
        }
        menuItem = sCourseEditTrackShapeMenuItems[var_a1];
        menuItem += trackTypeMenuIndex;

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        gDPLoadTextureBlock(gfx++, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            48, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        gDPLoadTextureBlock(gfx++, menuItem->subContentsRGBATex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (left + 0x13) << 2, (top + 2) << 2, (left + 0x2D) << 2, ((top + 2) + 12) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        gDPLoadTextureBlock_4b(gfx++, menuItem->contentsTex, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    } else {
        gDPPipeSync(gfx++);

        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        gDPLoadTextureBlock(gfx++, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            48, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        gDPLoadTextureBlock(gfx++, aCourseEditSRoadTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (left + 0x13) << 2, (top + 2) << 2, (left + 0x2D) << 2, ((top + 2) + 12) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        gDPLoadTextureBlock_4b(gfx++, aCourseEditSTex, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    top += 20;
    shape = TRACK_SHAPE_INDEX((u32) (gCourseEditInfoSegment->trackSegmentInfo & TRACK_SHAPE_MASK));

    gSPDisplayList(gfx++, D_3000510);
    if (gCourseEditInfoSegment->segmentIndex != 0) {
        gDPSetPrimColor(gfx++, 0, 0, sCourseEditTrackShapeBoxColors[shape][0], sCourseEditTrackShapeBoxColors[shape][1],
                        sCourseEditTrackShapeBoxColors[shape][2], 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 120, 130, 255, 255);
    }

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 10) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    top++;
    {
        s32 trackShapeEncType[8] = {
            1, // TRACK_SHAPE_ROAD
            1, // TRACK_SHAPE_WALLED_ROAD
            0, // TRACK_SHAPE_PIPE
            0, // TRACK_SHAPE_CYLINDER
            0, // TRACK_SHAPE_HALF_PIPE
            0, // TRACK_SHAPE_TUNNEL
            0, // TRACK_SHAPE_AIR
            1, // TRACK_SHAPE_BORDERLESS_ROAD
        };

        gExpansionKitEncStrEncType = trackShapeEncType[shape];
        if (gCourseEditInfoSegment->segmentIndex != 0) {
            gfx = ExpansionKit_DrawEncStr(gfx, left, top, sCourseEditTrackShapeEncStrs[shape]);
        } else {
            // グリッド
            u8 gridEncStr[5] = { 0x83, 0xD8, 0xAF, 0x8F, 0x00 };

            gExpansionKitEncStrEncType = 0;
            gfx = ExpansionKit_DrawEncStr(gfx, left, top, gridEncStr);
        }

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        top += 14;

        CourseEdit_DrawInfoEncStr(&gfx, left, top, "X");
        CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(gCourseEditInfoSegment->pos.x / 10.0f), 7);
        CourseEdit_DrawInfoEncStr(&gfx, left, top, strBuf);
        top += 8;
        CourseEdit_DrawInfoEncStr(&gfx, left, top, "Y");
        CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(gCourseEditInfoSegment->pos.y / 10.0f), 7);
        CourseEdit_DrawInfoEncStr(&gfx, left, top, strBuf);
        top += 8;
        CourseEdit_DrawInfoEncStr(&gfx, left, top, "Z");
        CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(gCourseEditInfoSegment->pos.z / 10.0f), 7);
        CourseEdit_DrawInfoEncStr(&gfx, left, top, strBuf);

        top += 9;

        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        gSPTextureRectangle(gfx++, (left - 4) << 2, top << 2, (left + 52) << 2, (top + 2) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        top += 3;

        gExpansionKitEncStrEncType = 0;
        // バンク
        gfx = ExpansionKit_DrawEncStr(gfx, left, top, "%c%c%c", 0x90, 0xDD, 0xB8);
        CourseEdit_NumToPaddedInfoEncStr(strBuf,
                                         COURSE_CONTEXT()->courseData.bankAngle[gCourseEditInfoControlPoint] % 360, 7);
        CourseEdit_DrawInfoEncStr(&gfx, left, top, strBuf);
        // °
        gfx = ExpansionKit_DrawEncStr(gfx, left + 0x28, top + 1, "%c", 0xDF);

        top += 9;
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        gSPTextureRectangle(gfx++, (left - 4) << 2, top << 2, (left + 52) << 2, (top + 2) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        top += 3;
        gExpansionKitEncStrEncType = 1;
        // みちはば
        gfx = ExpansionKit_DrawEncStr(gfx, left, top, "%c%c%c%c", 0xD0, 0xC1, 0xCA, 0x90);
        CourseEdit_NumToPaddedInfoEncStr(
            strBuf, Math_Round((gCourseEditInfoSegment->radiusLeft + gCourseEditInfoSegment->radiusRight) / 10.0f), 3);
        CourseEdit_DrawInfoEncStr(&gfx, left + 32, top, strBuf);
        top += 8;
        CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(gCourseEditInfoSegment->radiusLeft / 10.0f), 3);
        CourseEdit_DrawInfoEncStr(&gfx, left, top, strBuf);
        CourseEdit_DrawInfoEncStr(&gfx, left + 18, top, "-");
        CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(gCourseEditInfoSegment->radiusRight / 10.0f), 7);
        CourseEdit_DrawInfoEncStr(&gfx, left, top, strBuf);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);

        gfx = ExpansionKit_DrawEncStr(gfx, left - 2, top, "L");
        gfx = ExpansionKit_DrawEncStr(gfx, left + 44, top, "R");
    }

    *gfxP = gfx;
}

extern CourseInfo* gCurrentCourseInfo;

void CourseEdit_DrawCourseLength(Gfx** gfxP) {
    u8 strBuf[0x40];
    Gfx* gfx;

    gfx = *gfxP;
    gSPDisplayList(gfx++, D_8014940);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(gCurrentCourseInfo->length * 0.1f), 6);
    CourseEdit_DrawInfoEncStr(&gfx, 248, 186, strBuf);
    CourseEdit_DrawInfoEncStr(&gfx, 287, 186, "M");
    *gfxP = gfx;
}

void CourseEdit_DrawMoveXYZInfo(Gfx** gfxP, CourseSegment* segment) {
    s32 screenPosX;
    s32 screenPosY;
    s32 left;
    u8 strBuf[0x40];
    Gfx* gfx;

    if (CourseEdit_GetScreenPosition(segment->pos, &screenPosX, &screenPosY) != 0) {
        return;
    }
    gfx = *gfxP;
    // clang-format off
    screenPosX -= 15; \
    screenPosY -= 34;
    // clang format on
    left = screenPosX;
    if (left <= 0) {
        left = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, (left - 1) << 2, (screenPosY - 1) << 2, (screenPosX + 31 + 1) << 2, screenPosY << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (screenPosX - 1) << 2, (screenPosY - 1) << 2, screenPosX << 2, (screenPosY + 24 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (screenPosX + 31) << 2, (screenPosY - 1) << 2, (screenPosX + 31 + 1) << 2, (screenPosY + 24 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (screenPosY + 24) << 2, (screenPosX + 31 + 1) << 2, (screenPosY + 24 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);

    gSPTextureRectangle(gfx++, left << 2, screenPosY << 2, (screenPosX + 31) << 2, (screenPosY + 24) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 150, 255, 150, 160);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(segment->pos.x / 10.0f), 5);
    CourseEdit_DrawLoadedInfoEncStr(&gfx, screenPosX, screenPosY, strBuf);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 150, 255, 160);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(segment->pos.y / 10.0f), 5);
    CourseEdit_DrawLoadedInfoEncStr(&gfx, screenPosX, screenPosY + 8, strBuf);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 150, 255, 255, 160);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(segment->pos.z / 10.0f), 5);
    CourseEdit_DrawLoadedInfoEncStr(&gfx, screenPosX, screenPosY + 16, strBuf);
    *gfxP = gfx;
}

void CourseEdit_DrawCenterWidthInfo(Gfx** gfxP, CourseSegment* segment) {
    s32 screenPosX;
    s32 screenPosY;
    s32 left;
    s32 width = 42;
    s32 height = 16;
    u8 strBuf[0x40];
    Gfx* gfx;

    if (CourseEdit_GetScreenPosition(segment->pos, &screenPosX, &screenPosY) != 0) {
        return;
    }
    gfx = *gfxP;
    // clang-format off
    screenPosX -= 21; \
    screenPosY -= 24;
    // clang-format on
    left = screenPosX;
    if (left <= 0) {
        left = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, (left - 1) << 2, (screenPosY - 1) << 2, (screenPosX + width + 1) << 2, screenPosY << 2,
                        0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (screenPosX - 1) << 2, (screenPosY - 1) << 2, screenPosX << 2,
                        (screenPosY + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (screenPosX + width) << 2, (screenPosY - 1) << 2, (screenPosX + width + 1) << 2,
                        (screenPosY + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (screenPosY + height) << 2, (screenPosX + width + 1) << 2,
                        (screenPosY + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);

    gSPTextureRectangle(gfx++, left << 2, screenPosY << 2, (screenPosX + width) << 2, (screenPosY + height) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = ExpansionKit_DrawEncStr(gfx, screenPosX, screenPosY, "L");
    gfx = ExpansionKit_DrawEncStr(gfx, screenPosX + 36, screenPosY, "R");
    CourseEdit_LoadInfoFontSheet(&gfx);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(segment->radiusLeft / 10.0f), 3);
    CourseEdit_DrawLoadedInfoEncStr(&gfx, screenPosX, screenPosY + 8, strBuf);
    CourseEdit_DrawLoadedInfoEncStr(&gfx, screenPosX + 18, screenPosY + 8, "-");
    CourseEdit_NumToPaddedInfoEncStr(strBuf, Math_Round(segment->radiusRight / 10.0f), 3);
    CourseEdit_DrawLoadedInfoEncStr(&gfx, screenPosX + 24, screenPosY + 8, strBuf);
    *gfxP = gfx;
}

void CourseEdit_DrawBankAngleInfo(Gfx** gfxP, CourseSegment* segment) {
    s32 screenPosX;
    s32 screenPosY;
    s32 left;
    s32 width = 24;
    s32 height = 8;
    u8 strBuf[0x40];
    Gfx* gfx;

    if (CourseEdit_GetScreenPosition(segment->pos, &screenPosX, &screenPosY) != 0) {
        return;
    }

    gfx = *gfxP;
    // clang-format off
    screenPosX -= 12; \
    screenPosY -= 16;
    // clang-format on
    left = screenPosX;
    if (left <= 0) {
        left = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, (left - 1) << 2, (screenPosY - 1) << 2, (screenPosX + width + 1) << 2, screenPosY << 2,
                        0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (screenPosX - 1) << 2, (screenPosY - 1) << 2, screenPosX << 2,
                        (screenPosY + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (screenPosX + width) << 2, (screenPosY - 1) << 2, (screenPosX + width + 1) << 2,
                        (screenPosY + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (screenPosY + height) << 2, (screenPosX + width + 1) << 2,
                        (screenPosY + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);

    gSPTextureRectangle(gfx++, left << 2, screenPosY << 2, (screenPosX + width) << 2, (screenPosY + height) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    CourseEdit_NumToPaddedInfoEncStr(&strBuf, COURSE_CONTEXT()->courseData.bankAngle[segment->segmentIndex] % 360, 3);
    CourseEdit_DrawInfoEncStr(&gfx, screenPosX, screenPosY, &strBuf);
    // °
    gfx = ExpansionKit_DrawEncStr(gfx, screenPosX + 16, screenPosY, "%c", 0xDF);

    *gfxP = gfx;
}

extern s32 gCourseEditOptions[];
extern s32 gMoveOption;

void CourseEdit_DrawMoveInfo(Gfx** gfxP) {
    s32 pad[0x12];
    Gfx* gfx;
    Gfx* gfx2;
    s32 i;

    if ((gCourseEditOptions[COURSE_EDIT_OPTION_CONTROL_POINT_MOVE_POS] == 0) || gInCourseEditTestRun ||
        (gCreateOption != CREATE_OPTION_POINT)) {
        return;
    }
    gfx = *gfxP;
    gfx2 = D_80128C94->unk_110C8;
    CourseEdit_LoadInfoFontSheet(&gfx2);

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (!D_80128690[i].isSelected) {
            continue;
        }
        switch (gMoveOption) {
            case MOVE_OPTION_MOVE_XZ:
            case MOVE_OPTION_MOVE_Y:
                CourseEdit_DrawMoveXYZInfo(&gfx2, &D_802CB6D0.segments[i]);
                break;
            case MOVE_OPTION_WIDTH:
            case MOVE_OPTION_CENTER:
                CourseEdit_DrawCenterWidthInfo(&gfx2, &D_802CB6D0.segments[i]);
                break;
            case MOVE_OPTION_BANK:
                CourseEdit_DrawBankAngleInfo(&gfx2, &D_802CB6D0.segments[i]);
                break;
        }
    }
    gSPEndDisplayList(gfx2++);

    if (gfx2 - D_80128C94->unk_110C8 > ARRAY_COUNT(D_80128C94->unk_110C8)) {
        PRINTF("GFX SIZE OVER ERROR(POINT INFO) %d\n");
        *(s8*) NULL = *(s8*) NULL;
    }
    gSPDisplayList(gfx++, D_6000000.unk_110C8);

    *gfxP = gfx;
}

Gfx* CourseEdit_DrawInfoWindows(Gfx* gfx) {

    D_xk2_80128CA0 = 0;
    gSPDisplayList(gfx++, D_8014940);
    CourseEdit_DrawControlPointInfo(&gfx);
    if ((gCreateOption != CREATE_OPTION_COURSE) && (gCreateOption != CREATE_OPTION_POINT)) {
        return gfx;
    }

    CourseEdit_DrawMoveInfo(&gfx);
    return gfx;
}

Gfx* CourseEdit_DrawDashCount(Gfx* gfx) {
    s32 dashCount;
    s32 i;
    u8 strBuf[0x40];
    // ダッシュ
    u8 dashEncStr[5] = { 0x8B, 0xAF, 0xBC, 0xAD, 0x00 };

    dashCount = 0;

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_DASH) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.dash[i] != DASH_NONE) {
            dashCount++;
        }
    }
    gSPDisplayList(gfx++, D_3000540);

    if (dashCount >= 32) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, 232, 186, dashEncStr);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, dashCount, 2);
    CourseEdit_DrawInfoEncStr(&gfx, 264, 186, strBuf);
    gfx = ExpansionKit_DrawEncStr(gfx, 276, 186, "/");
    CourseEdit_NumToPaddedInfoEncStr(strBuf, 32, 2);
    CourseEdit_DrawInfoEncStr(&gfx, 283, 186, strBuf);

    return gfx;
}

extern CourseFeaturesInfo gCourseFeaturesInfo;

Gfx* CourseEdit_DrawJumpCount(Gfx* gfx) {
    u8 strBuf[0x40];
    // ジャンプ
    u8 jumpEncStr[5] = { 0x87, 0xAC, 0xDD, 0x97, 0x00 };

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_JUMP) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_3000540);

    if (gCourseFeaturesInfo.jumpCount >= 8) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, 232, 186, jumpEncStr);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, gCourseFeaturesInfo.jumpCount, 1);
    CourseEdit_DrawInfoEncStr(&gfx, 270, 186, strBuf);
    gfx = ExpansionKit_DrawEncStr(gfx, 276, 186, "/");
    CourseEdit_NumToPaddedInfoEncStr(strBuf, 8, 1);
    CourseEdit_DrawInfoEncStr(&gfx, 290, 186, strBuf);

    return gfx;
}

Gfx* CourseEdit_DrawLandmineCount(Gfx* gfx) {
    u8 strBuf[0x40];
    // トラップ
    u8 trapEncStr[5] = { 0xC4, 0xD7, 0xAF, 0x97, 0x00 };

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_TRAP) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_3000540);

    if ((gCourseFeaturesInfo.landmineCount / 6) >= 8) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, 232, 186, trapEncStr);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, gCourseFeaturesInfo.landmineCount / 6, 1);
    CourseEdit_DrawInfoEncStr(&gfx, 270, 186, strBuf);
    gfx = ExpansionKit_DrawEncStr(gfx, 276, 186, "/");
    CourseEdit_NumToPaddedInfoEncStr(strBuf, 8, 1);
    CourseEdit_DrawInfoEncStr(&gfx, 290, 186, strBuf);

    return gfx;
}

Gfx* CourseEdit_DrawDecorationalFeatureCount(Gfx* gfx) {
    s32 decorationalFeatureCount;
    s32 i;
    u8 strBuf[0x40];
    // オブジェ
    u8 objectEncStr[5] = { 0xB5, 0x92, 0x87, 0xAA, 0x00 };

    decorationalFeatureCount = 0;

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_GATE && gPartsStyleOption != TRACK_PART_STYLE_BUILDING &&
        gPartsStyleOption != TRACK_PART_STYLE_SIGN) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.gate[i] != GATE_NONE) {
            decorationalFeatureCount++;
        }
        if (COURSE_CONTEXT()->courseData.building[i] != BUILDING_NONE) {
            decorationalFeatureCount++;
        }
        if (COURSE_CONTEXT()->courseData.sign[i] != SIGN_NONE) {
            decorationalFeatureCount++;
        }
    }
    gSPDisplayList(gfx++, D_3000540);

    if (decorationalFeatureCount >= 16) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, 232, 186, objectEncStr);
    CourseEdit_NumToPaddedInfoEncStr(strBuf, decorationalFeatureCount, 2);
    CourseEdit_DrawInfoEncStr(&gfx, 264, 186, strBuf);
    gfx = ExpansionKit_DrawEncStr(gfx, 276, 186, "/");
    CourseEdit_NumToPaddedInfoEncStr(strBuf, 16, 2);
    CourseEdit_DrawInfoEncStr(&gfx, 284, 186, strBuf);

    return gfx;
}

extern s32 gVenueOption;
extern MenuWidget gVenueWidget;

Gfx* CourseEdit_DrawControlPointCountVenueId(Gfx* gfx) {
    s32 venueIndex;
    u8 strBuf[0x40];
    // ポイント
    u8 pointEncStr[5] = { 0x99, 0xB2, 0xDD, 0xC4, 0x00 };

    if (gVenueWidget.highlightedIndex != -1) {
        venueIndex = gVenueWidget.highlightedIndex;
    } else {
        venueIndex = gVenueOption;
    }

    gSPDisplayList(gfx++, D_3000540);

    if (!gCourseEditCameraOnlyMode) {
        if ((gCreateOption == CREATE_OPTION_COURSE) || (gCreateOption == CREATE_OPTION_POINT)) {
            if (D_802CB6D0.controlPointCount >= 64) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
            gExpansionKitEncStrEncType = 0;
            gfx = ExpansionKit_DrawEncStr(gfx, 232, 194, pointEncStr);
            CourseEdit_NumToPaddedInfoEncStr(strBuf, D_802CB6D0.controlPointCount, 2);
            CourseEdit_DrawInfoEncStr(&gfx, 0x108, 194, strBuf);
            gfx = ExpansionKit_DrawEncStr(gfx, 0x114, 194, "/");
            CourseEdit_NumToPaddedInfoEncStr(strBuf, 64, 2);
            CourseEdit_DrawInfoEncStr(&gfx, 0x11B, 194, strBuf);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = ExpansionKit_DrawEncStr(gfx, 232, 194, "BG %d", venueIndex + 1);
        }
    }

    // TODO: move to more appropriate place
    PRINTF("CRS DEVIDE OVER ERROR crs_vertexes = %d\n");
    PRINTF("CRS REAL LENGTH ERROR\n");
    PRINTF("TENSION %d\n");
    PRINTF("MAKE_LINE_VERTEX_ERROR0\n");
    PRINTF("MAKE_LINE_VERTEX_ERROR2\n");
    PRINTF("EDIT_MODE_COURSE 20\n");
    PRINTF("INIT GADGET\n");

    return gfx;
}

UNUSED u8* sBGMNameTexturesUnused[] = {
    aCourseEditMuteCity1Tex, aCourseEditSilenceTex,      aCourseEditSandOceanTex,    aCourseEditPortTownTex,
    aCourseEditBigBlueTex,   aCourseEditDevilsForestTex, aCourseEditRedCanyonTex,    aCourseEditSectorTex,
    aCourseEditWhiteLandTex, aCourseEditRainbowRoadTex,  aCourseEditRegenerationTex, aCourseEditRollerCoasterTex,
    aCourseEditBigFootTex,   aCourseEditJaponTex,
};

u8* sBGMNameTextures[] = {
    aCourseEditMuteCity1Tex, aCourseEditSilenceTex,      aCourseEditSandOceanTex,    aCourseEditPortTownTex,
    aCourseEditBigBlueTex,   aCourseEditDevilsForestTex, aCourseEditRedCanyonTex,    aCourseEditSectorTex,
    aCourseEditWhiteLandTex, aCourseEditRainbowRoadTex,  aCourseEditRegenerationTex, aCourseEditRollerCoasterTex,
    aCourseEditBigFootTex,   aCourseEditJaponTex,
};

extern MenuWidget gBGMWidget;

Gfx* CourseEdit_DrawBGMTooltip(Gfx* gfx) {
    s32 highlightedIndex;
    s32 top;

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    if (gBGMWidget.highlightedIndex != -1) {
        if (gBGMWidget.highlightedIndex != -1) {}
        highlightedIndex = gBGMWidget.highlightedIndex;
        top = (highlightedIndex * 16) - func_xk1_800290B4() + 40;
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);

        gSPTextureRectangle(gfx++, 119 << 2, (top - 1) << 2, 185 << 2, (top + 8 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        gSPDisplayList(gfx++, D_8014940);

        gDPSetRenderMode(gfx++, CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                         CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_NOOP2);

        gDPSetAlphaCompare(gfx++, G_AC_NONE);

        gDPLoadTextureBlock_4b(gfx++, sBGMNameTextures[highlightedIndex], G_IM_FMT_I, 64, 8, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, 120 << 2, top << 2, 184 << 2, (top + 8) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    return gfx;
}

Gfx* CourseEdit_DrawGeneralInfo(Gfx* gfx) {

    if (gCourseEditCameraOnlyMode) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);
    gSPDisplayList(gfx++, D_3000540);
    gfx = CourseEdit_DrawDashCount(gfx);
    gfx = CourseEdit_DrawLandmineCount(gfx);
    gfx = CourseEdit_DrawJumpCount(gfx);
    gfx = CourseEdit_DrawDecorationalFeatureCount(gfx);
    if ((gCreateOption != CREATE_OPTION_COURSE) && (gCreateOption != CREATE_OPTION_POINT)) {
        return gfx;
    }
    CourseEdit_DrawCourseLength(&gfx);
    return gfx;
}

extern s32 D_xk1_80030608;

void func_xk2_800E5570(void) {

    if (D_800D6CA0.state != 0) {
        return;
    }
    D_xk2_800F7050 = D_800D6CA0.newSegment.pos.x;
    D_xk2_800F7054 = D_800D6CA0.newSegment.pos.z;
    if (D_xk2_800F7050 < -32000) {
        D_xk2_800F7050 = -32000;
    }
    if (D_xk2_800F7050 > 32000) {
        D_xk2_800F7050 = 32000;
    }

    if (D_xk2_800F7054 < -32000) {
        D_xk2_800F7054 = -32000;
    }
    if (D_xk2_800F7054 > 32000) {
        D_xk2_800F7054 = 32000;
    }
    if (D_xk2_800F7050 < 0) {
        D_xk2_800F7050 = (Math_Round(D_xk2_800F7050) - (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    } else {
        D_xk2_800F7050 = (Math_Round(D_xk2_800F7050) + (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    }
    if (D_xk2_800F7054 < 0) {
        D_xk2_800F7054 = (Math_Round(D_xk2_800F7054) - (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    } else {
        D_xk2_800F7054 = (Math_Round(D_xk2_800F7054) + (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    }

    D_xk2_800F7050 *= D_xk1_80030608 * 20;
    D_xk2_800F7054 *= D_xk1_80030608 * 20;
    if (D_xk2_800F7050 < -15000) {
        D_xk2_800F7050 = -15000;
    }
    if (D_xk2_800F7050 > 15000) {
        D_xk2_800F7050 = 15000;
    }

    if (D_xk2_800F7054 < -15000) {
        D_xk2_800F7054 = -15000;
    }
    if (D_xk2_800F7054 > 15000) {
        D_xk2_800F7054 = 15000;
    }
}

extern s32 gCourseEditCameraPitch;
extern Gfx D_xk2_80136EF8[];

Gfx* CourseEdit_DrawCourseBackground(Gfx* gfx) {

    if (gInCourseEditTestRun) {
        return gfx;
    }
    func_xk2_800E5570();
    gSPDisplayList(gfx++, aCourseEditBackgroundPlaneDL);
    if (gCourseEditCameraPitch < 0) {
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gDPSetCombineMode(gfx++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    }
    gSPDisplayList(gfx++, D_xk2_80136EF8);
    return gfx;
}

void func_xk2_800E5920(void) {
    s32 i;

    for (i = 0; i < gCourseEditCourseSplitIndex; i++) {
        D_80128C94->unk_1980[i].v.ob[0] = gCourseEditCourseSplitInfos[i].pos.x;
        D_80128C94->unk_1980[i].v.ob[1] = gCourseEditCourseSplitInfos[i].pos.y;
        D_80128C94->unk_1980[i].v.ob[2] = gCourseEditCourseSplitInfos[i].pos.z;
    }
    D_80128C94->unk_1980[i].v.ob[0] = gCourseEditCourseSplitInfos[0].pos.x;
    D_80128C94->unk_1980[i].v.ob[1] = gCourseEditCourseSplitInfos[0].pos.y;
    D_80128C94->unk_1980[i].v.ob[2] = gCourseEditCourseSplitInfos[0].pos.z;

    if (gCourseEditCourseSplitIndex > 896) {
        gCourseEditCourseSplitIndex--;
    }
}

extern s32 gSegmentChunkCount;

void func_xk2_800E5A38(s32 arg0) {

    gCourseEditErrors[COURSE_EDIT_ERROR_TOO_MUCH_TO_DISPLAY] = false;
    gCourseEditErrors[COURSE_EDIT_ERROR_TOO_LONG] = false;
    gCourseEditErrors[COURSE_EDIT_ERROR_TOO_SHORT] = false;
    if (D_xk2_800F7040 != 2) {
        gCourseEditErrors[COURSE_EDIT_ERROR_ROADS_OVERLAP] = false;
    }
    if (gSegmentChunkCount >= 0x2FF) {
        gCourseEditErrors[COURSE_EDIT_ERROR_TOO_MUCH_TO_DISPLAY] = true;
    }
    if (gCurrentCourseInfo->length > 250000.0f) {
        gCourseEditErrors[COURSE_EDIT_ERROR_TOO_LONG] = true;
    }
    if ((D_802CB6D0.controlPointCount >= 4) && (gCurrentCourseInfo->length < 3000.0f)) {
        gCourseEditErrors[COURSE_EDIT_ERROR_TOO_SHORT] = true;
    }
    if (D_800D6CA0.state != 0x10) {
        if (D_xk2_800F7040 == 3) {
            D_800D6CA0.overlappingControlPoint = -1;
            D_xk2_800F706C = -1;
            if (arg0 & 0x10000) {
                gCourseEditErrors[COURSE_EDIT_ERROR_ROADS_OVERLAP] = true;
                D_xk2_800F706C = arg0 & 0xFFFF;
                D_800D6CA0.overlappingControlPoint = func_xk2_800E9134(D_xk2_800F706C);
            }
        } else {
            D_xk2_800F7068 = -1;
            if (arg0 & 0x10000) {
                gCourseEditErrors[COURSE_EDIT_ERROR_ROADS_OVERLAP] = true;
                D_xk2_800F7068 = arg0 & 0xFFFF;
            }
        }
    }
}

extern s32 D_xk2_800F6820;

s32 D_xk2_800F71F0 = 0;

void func_xk2_800E5B6C(void) {
    s32 temp_v0;

    if (!gInCourseEditTestRun) {
        gCurrentCourseInfo->courseSegments = D_802CB6D0.segments;
        gCurrentCourseInfo->segmentCount = D_802CB6D0.controlPointCount;
    }
    if (gCurrentCourseInfo->segmentCount < 4) {
        D_xk2_800F7068 = -1;
        D_xk2_800F706C = -1;
        gSegmentChunkCount = 0;
        func_xk2_800E5D90(gCurrentCourseInfo);
        func_xk2_800E5A38(0);
    } else if (D_xk2_800F7040 != 0) {
        if (D_xk2_800F6820 != 0) {
            if (D_800D6CA0.moveMode == 1) {
                func_800A4D0C(0);
            } else if (D_xk2_800F7040 == 3) {
                func_800A4D0C(2);
            } else {
                func_800A4D0C(1);
            }
        } else {
            func_800A4D0C(0);
        }
        gCourseEditErrors[COURSE_EDIT_ERROR_UNREASONABLE_POINTS] = false;
        D_800D6CA0.unreasonableControlPoint = func_i2_800B39B4(gCurrentCourseInfo);

        if (D_800D6CA0.unreasonableControlPoint == -1) {
            D_800D6CA0.unreasonableControlPoint = func_i2_800BE8BC(gCurrentCourseInfo);
        }
        if (D_800D6CA0.unreasonableControlPoint != -1) {
            D_xk2_800F7068 = -1;
            D_xk2_800F706C = -1;
            gSegmentChunkCount = 0;
            gCourseEditErrors[COURSE_EDIT_ERROR_UNREASONABLE_POINTS] = true;
            func_xk2_800E5D90(gCurrentCourseInfo);
            func_xk2_800E5A38(0);
        } else {
            func_80074CE4(gCurrentCourseInfo);
            func_8009F334(gCurrentCourseInfo);
            Course_SegmentLengthsInit(gCurrentCourseInfo);
            if (Course_SegmentJoinsInit(gCurrentCourseInfo) != 0) {
                gCourseEditErrors[COURSE_EDIT_ERROR_TOO_NARROW_FOR_JOINT] = true;
            }
            if ((D_xk2_800F7040 == 3) || (D_xk2_800F7040 == 2)) {
                D_xk2_800F71F0 = temp_v0 = func_xk2_800F2750();
                func_xk2_800E5A38(temp_v0);
            }
            func_xk2_800E6270(gCurrentCourseInfo);
            func_xk2_800E5920();
        }
    }
}

void func_xk2_800E5D90(CourseInfo* courseInfo) {
    CourseSegment* segment;
    f32 distance;
    f32 length;
    s32 j;
    s32 var_s1;
    s32 var_s3;
    s32 i;
    s32 scale;
    Vec3f pos;
    Vec3f nextPos;
    Vec3f dirVec;

    length = 0.0f;
    segment = D_802CB6D0.segments;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        pos = segment->pos;
        nextPos = segment->next->pos;

        distance = sqrtf(SQ(nextPos.x - pos.x) + SQ(nextPos.y - pos.y) + SQ(nextPos.z - pos.z));
        length += distance;
        segment = segment->next;
    }

    gCurrentCourseInfo->length = length;
    if (length > 281200.0f) {
        scale = (s32) (length / 703.0f);
    } else {
        scale = 400;
    }

    var_s1 = 0;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        segment = &D_802CB6D0.segments[i];

        pos = segment->pos;
        nextPos = segment->next->pos;
        distance = sqrtf(SQ(nextPos.x - pos.x) + SQ(nextPos.y - pos.y) + SQ(nextPos.z - pos.z));
        var_s3 = distance / scale;

        if (var_s3 == 0) {
            var_s3 = 1;
        }
        distance /= var_s3;
        dirVec.x = nextPos.x - pos.x;
        dirVec.y = nextPos.y - pos.y;
        dirVec.z = nextPos.z - pos.z;
        Math_VectorSetScale(&dirVec, distance);
        D_80128690[i].startSplit = var_s1;

        for (j = 0; j < var_s3; j++, var_s1++) {
            gCourseEditCourseSplitInfos[var_s1].pos.x = (j * dirVec.x) + pos.x;
            gCourseEditCourseSplitInfos[var_s1].pos.y = (j * dirVec.y) + pos.y;
            gCourseEditCourseSplitInfos[var_s1].pos.z = (j * dirVec.z) + pos.z;
            gCourseEditCourseSplitInfos[var_s1].trackSegmentInfo = segment->trackSegmentInfo;
        }

        D_80128690[i].endSplit = var_s1;
        if (var_s1 > 832) {
            break;
        }
    }
    D_80128690[0].startSplit = var_s1;
    gCourseEditCourseSplitIndex = var_s1;
}

extern Mtx3F D_80033840[];
extern SegmentChunk gSegmentChunks[];

void func_xk2_800E6270(CourseInfo* courseInfo) {
    s32 i;
    s32 chunkIndex;
    CourseSplitInfo* splitInfo;
    CourseSegment* segment;
    CourseSegment* startSegment;
    f32 distance;
    f32 lengthFromStart;
    s32 numSplits;
    s32 pad;
    Vec3f dirVec;
    Vec3f pos;
    s32 pad2[2];
    Mtx3F basis;

    gCourseEditCourseSplitIndex = 0;
    segment = courseInfo->courseSegments;
    splitInfo = gCourseEditCourseSplitInfos;
    courseInfo->segmentCount = D_802CB6D0.controlPointCount;
    startSegment = segment;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_80128690[i].startSplit = 0x10000;
    }

    while (true) {
        if (1) {}
        if (segment->startChunk == NULL) {
            break;
        }
        chunkIndex = segment->startChunk - gSegmentChunks;
        D_80128690[segment->segmentIndex].startSplit = gCourseEditCourseSplitIndex;
        splitInfo->pos = segment->pos;
        splitInfo->trackSegmentInfo = segment->trackSegmentInfo;
        splitInfo->segmentTValue = 0.0f;
        Course_SplineGetBasis(segment, 0.0f, &basis, 0.0f);
        splitInfo->basis = basis;
        splitInfo++;

        gCourseEditCourseSplitIndex++;
        if (gCourseEditCourseSplitIndex >= 896) {
            gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] =
                gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex - 1];
            break;
        }

        if (gSegmentChunks[chunkIndex].segmentTValue == 0.0f) {
            chunkIndex++;
        }
        if (segment->segmentIndex != gSegmentChunks[chunkIndex].segmentIndex) {
            chunkIndex = (chunkIndex + 1) % gSegmentChunkCount;
        }
        if ((segment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) {

            distance = Math_VectorGetDistance(segment->pos, segment->next->pos);
            numSplits = (s32) (distance / 400.0f);
            if (numSplits < 2) {
                numSplits = 2;
            }
            dirVec.x = segment->next->pos.x - segment->pos.x;
            dirVec.y = segment->next->pos.y - segment->pos.y;
            dirVec.z = segment->next->pos.z - segment->pos.z;

            Math_VectorSetScale(&dirVec, (s32) (distance / numSplits));
            for (i = 1; i < numSplits; i++) {
                splitInfo->trackSegmentInfo = segment->trackSegmentInfo;
                splitInfo->pos.x = segment->pos.x + (dirVec.x * i);
                splitInfo->pos.y = segment->pos.y + (dirVec.y * i);
                splitInfo->pos.z = segment->pos.z + (dirVec.z * i);
                splitInfo++;
                gCourseEditCourseSplitIndex++;
                if (gCourseEditCourseSplitIndex >= 896) {
                    gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] =
                        gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex - 1];
                    D_80128690[segment->segmentIndex].endSplit = gCourseEditCourseSplitIndex;
                    break;
                }
            }
        } else {
            while (true) {
                if (segment->segmentIndex != gSegmentChunks[chunkIndex].segmentIndex) {
                    break;
                }

                if (gSegmentChunks[chunkIndex].segmentTValue == 1.0f) {
                    break;
                }

                if ((gCourseEditCourseSplitIndex == (D_80128690[segment->segmentIndex].startSplit + 1)) &&
                    (gSegmentChunks[chunkIndex].segmentTValue > 0.5f)) {
                    splitInfo->trackSegmentInfo = segment->trackSegmentInfo;
                    splitInfo->segmentTValue = 0.5f;
                    Course_SplineGetPosition(segment, 0.5f, &splitInfo->pos);
                    Course_SplineGetBasis(segment, 0.5f, &basis,
                                          Course_SplineGetLengthInfo(segment, 0.5f, &lengthFromStart));
                    splitInfo->basis = basis;
                } else {
                    splitInfo->trackSegmentInfo = segment->trackSegmentInfo;
                    splitInfo->segmentTValue = gSegmentChunks[chunkIndex].segmentTValue;
                    splitInfo->pos.x = gSegmentChunks[chunkIndex].pos.x;
                    splitInfo->pos.y = gSegmentChunks[chunkIndex].pos.y;
                    splitInfo->pos.z = gSegmentChunks[chunkIndex].pos.z;
                    splitInfo->basis = D_80033840[chunkIndex];
                }
                splitInfo++;
                chunkIndex++;
                gCourseEditCourseSplitIndex++;

                if (gSegmentChunkCount < chunkIndex) {
                    gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] =
                        gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex - 1];
                    D_80128690[segment->segmentIndex].endSplit = gCourseEditCourseSplitIndex;
                    break;
                }

                if (gCourseEditCourseSplitIndex >= 896) {
                    gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] =
                        gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex - 1];
                    D_80128690[segment->segmentIndex].endSplit = gCourseEditCourseSplitIndex;
                    break;
                }
            }
            if (gCourseEditCourseSplitIndex == (D_80128690[segment->segmentIndex].startSplit + 1)) {
                Course_SplineGetPosition(segment, 0.5f, &pos);
                splitInfo->pos = pos;
                splitInfo->trackSegmentInfo = segment->trackSegmentInfo;
                splitInfo->segmentTValue = 0.5f;
                Course_SplineGetBasis(segment, 0.5f, &basis,
                                      Course_SplineGetLengthInfo(segment, 0.5f, &lengthFromStart));
                splitInfo->basis = basis;
                splitInfo++;
                gCourseEditCourseSplitIndex++;
                if (gCourseEditCourseSplitIndex >= 896) {
                    gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] =
                        gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex - 1];
                    D_80128690[segment->segmentIndex].endSplit = gCourseEditCourseSplitIndex;
                    break;
                }
            }
        }

        D_80128690[segment->segmentIndex].endSplit = gCourseEditCourseSplitIndex;
        gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] = gCourseEditCourseSplitInfos[0];

        segment = segment->next;
        if (startSegment == segment) {
            break;
        }
        if (gCourseEditCourseSplitIndex >= 896) {
            gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex] =
                gCourseEditCourseSplitInfos[gCourseEditCourseSplitIndex - 1];
            break;
        }
    }
    gCourseEditCourseSplitIndex++;
}

bool CourseEdit_CheckInvalidJoins(void) {
    s32 prevShape;
    s32 nextShape;
    s32 shape;
    s32 prevJoinable;
    s32 nextJoinable;
    s32 i;
    s32 invalidJoin;
    CourseSegment* segment;

    invalidJoin = false;
    if (D_800D6CA0.state == COURSE_EDIT_NAME_ENTRY) {
        return false;
    }
    segment = D_802CB6D0.segments;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++, segment = segment->next) {
        prevShape = segment->prev->trackSegmentInfo & TRACK_SHAPE_MASK;
        nextShape = segment->next->trackSegmentInfo & TRACK_SHAPE_MASK;
        shape = segment->trackSegmentInfo & TRACK_SHAPE_MASK;
        prevJoinable = segment->prev->trackSegmentInfo & TRACK_FLAG_JOINABLE;
        nextJoinable = segment->next->trackSegmentInfo & TRACK_FLAG_JOINABLE;

        switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
            case TRACK_SHAPE_ROAD:
            case TRACK_SHAPE_AIR:
                break;
            case TRACK_SHAPE_WALLED_ROAD:
            case TRACK_SHAPE_PIPE:
            case TRACK_SHAPE_CYLINDER:
            case TRACK_SHAPE_HALF_PIPE:
            case TRACK_SHAPE_TUNNEL:
            case TRACK_SHAPE_BORDERLESS_ROAD:
                if (((shape != prevShape) && !prevJoinable) || ((shape != nextShape) && !nextJoinable)) {
                    invalidJoin = true;
                    if ((shape != prevShape) && !prevJoinable) {
                        CourseEdit_SetSegmentJoinError(segment->segmentIndex, 1);
                    }
                }
                break;
            default:
                invalidJoin = true;
                break;
        }
    }
    return invalidJoin;
}

extern s32 gCourseEditNewSegmentBankAngle;

void CourseEdit_AddNewSegment(s32 selectedControlPoint, CourseSegment newSegment) {
    s32 pad[2];
    CourseSegment* segment;
    s32 i;

    if (selectedControlPoint != -1) {
        if (D_802CB6D0.controlPointCount >= 2) {
            newSegment.trackSegmentInfo = D_802CB6D0.segments[selectedControlPoint].trackSegmentInfo;
            if (!(newSegment.trackSegmentInfo & TRACK_TYPE_MASK) && !(newSegment.trackSegmentInfo & TRACK_SHAPE_MASK)) {
                newSegment.trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2);
            }
        }

        for (i = D_802CB6D0.controlPointCount; i > selectedControlPoint; i--) {
            D_802CB6D0.segments[i] = D_802CB6D0.segments[i - 1];
            D_802CB6D0.segments[i].segmentIndex = i;

            COURSE_CONTEXT()->courseData.bankAngle[i] = COURSE_CONTEXT()->courseData.bankAngle[i - 1];
            D_80128690[i] = D_80128690[i - 1];

            COURSE_CONTEXT()->courseData.pit[i] = COURSE_CONTEXT()->courseData.pit[i - 1];
            COURSE_CONTEXT()->courseData.dash[i] = COURSE_CONTEXT()->courseData.dash[i - 1];
            COURSE_CONTEXT()->courseData.dirt[i] = COURSE_CONTEXT()->courseData.dirt[i - 1];
            COURSE_CONTEXT()->courseData.ice[i] = COURSE_CONTEXT()->courseData.ice[i - 1];
            COURSE_CONTEXT()->courseData.jump[i] = COURSE_CONTEXT()->courseData.jump[i - 1];
            COURSE_CONTEXT()->courseData.landmine[i] = COURSE_CONTEXT()->courseData.landmine[i - 1];
            COURSE_CONTEXT()->courseData.gate[i] = COURSE_CONTEXT()->courseData.gate[i - 1];
            COURSE_CONTEXT()->courseData.building[i] = COURSE_CONTEXT()->courseData.building[i - 1];
            COURSE_CONTEXT()->courseData.sign[i] = COURSE_CONTEXT()->courseData.sign[i - 1];
        }
    }

    segment = &D_802CB6D0.segments[selectedControlPoint + 1];
    segment->segmentIndex = selectedControlPoint + 1;
    segment->pos.x = Math_Round(newSegment.pos.x);
    segment->pos.y = Math_Round(newSegment.pos.y);
    segment->pos.z = Math_Round(newSegment.pos.z);
    segment->up.x = 0.0f;
    segment->up.y = 1.0f;
    segment->up.z = 0.0f;
    segment->radiusLeft = newSegment.radiusLeft;
    segment->radiusRight = newSegment.radiusRight;
    segment->trackSegmentInfo = newSegment.trackSegmentInfo;
    COURSE_CONTEXT()->courseData.bankAngle[selectedControlPoint + 1] = gCourseEditNewSegmentBankAngle;
    COURSE_CONTEXT()->courseData.pit[selectedControlPoint + 1] = PIT_NONE;
    COURSE_CONTEXT()->courseData.dash[selectedControlPoint + 1] = DASH_NONE;
    COURSE_CONTEXT()->courseData.dirt[selectedControlPoint + 1] = DIRT_NONE;
    COURSE_CONTEXT()->courseData.ice[selectedControlPoint + 1] = ICE_NONE;
    COURSE_CONTEXT()->courseData.jump[selectedControlPoint + 1] = JUMP_NONE;
    COURSE_CONTEXT()->courseData.landmine[selectedControlPoint + 1] = LANDMINE_NONE;
    COURSE_CONTEXT()->courseData.gate[selectedControlPoint + 1] = GATE_NONE;
    COURSE_CONTEXT()->courseData.building[selectedControlPoint + 1] = BUILDING_NONE;
    COURSE_CONTEXT()->courseData.sign[selectedControlPoint + 1] = SIGN_NONE;
    D_800D6CA0.selectedControlPoint = selectedControlPoint + 1;

    D_802CB6D0.controlPointCount++;
    gCourseEditMiniMachineCharacter = Math_Rand2() % 30;
    gCourseEditMiniMachineColorPalette = Math_Rand2() % 4;
    func_xk2_800E6F9C();
}

void func_xk2_800E6F9C(void) {
    CourseSegment* segment;
    s32 i;

    segment = D_802CB6D0.segments;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        segment->segmentIndex = i;
        segment->next = segment + 1;
        segment->prev = segment - 1;
        segment++;
    }
    if (D_802CB6D0.controlPointCount != 0) {
        D_802CB6D0.segments[0].prev = &D_802CB6D0.segments[D_802CB6D0.controlPointCount - 1];
        D_802CB6D0.segments[D_802CB6D0.controlPointCount - 1].next = &D_802CB6D0.segments[0];
    } else {
        D_802CB6D0.segments[0].segmentIndex = 0;
        D_802CB6D0.segments[0].prev = D_802CB6D0.segments;
        D_802CB6D0.segments[0].next = D_802CB6D0.segments;
    }
}

extern Vtx D_xk2_80128DF8[];

void func_xk2_800E7028(s32 arg0) {
    s32 i;
    s32 j;
    Vtx* vtx;
    Gfx* gfx;
    s32 temp_lo;
    s32 x;
    s32 z;
    s32 s;
    s32 t;

    temp_lo = 8000 / arg0;

    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            vtx = &D_xk2_80128DF8[((i * 30) + j) * 4];
            x = (j - 15) * 1000;
            z = (i - 15) * 1000;
            s = ((j * 8000) / arg0) % 256;
            t = ((i * 8000) / arg0) % 256;

            vtx->v.ob[0] = x;
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = z;
            vtx->v.tc[0] = s << 6;
            vtx->v.tc[1] = t << 6;
            vtx++;
            vtx->v.ob[0] = x + 1000;
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = z;
            vtx->v.tc[0] = (s + temp_lo) << 6;
            vtx->v.tc[1] = t << 6;
            vtx++;
            vtx->v.ob[0] = x;
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = z + 1000;
            vtx->v.tc[0] = s << 6;
            vtx->v.tc[1] = (t + temp_lo) << 6;
            vtx++;
            vtx->v.ob[0] = x + 1000;
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = z + 1000;
            vtx->v.tc[0] = (s + temp_lo) << 6;
            vtx->v.tc[1] = (t + temp_lo) << 6;
            vtx++;
        }
    }
    gfx = D_xk2_80136EF8;
    for (i = 0; i < 900; i++) {
        vtx = &D_xk2_80128DF8[i * 4];
        gSPVertex(gfx++, vtx, 4, 0);
        gSP2Triangles(gfx++, 2, 1, 0, 0, 1, 2, 3, 0);
    }

    gSPEndDisplayList(gfx++);
}

void func_xk2_800E72BC(void) {
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;
    s32 i;

    var_fv0 = 65536.0f;
    var_fv1 = -65536.0f;
    var_fa0 = 65536.0f;
    var_fa1 = -65536.0f;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (var_fv0 > D_802CB6D0.segments[i].pos.x) {
            var_fv0 = D_802CB6D0.segments[i].pos.x;
        }
        if (var_fv1 < D_802CB6D0.segments[i].pos.x) {
            var_fv1 = D_802CB6D0.segments[i].pos.x;
        }

        if (var_fa0 > D_802CB6D0.segments[i].pos.z) {
            var_fa0 = D_802CB6D0.segments[i].pos.z;
        }
        if (var_fa1 < D_802CB6D0.segments[i].pos.z) {
            var_fa1 = D_802CB6D0.segments[i].pos.z;
        }
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_802CB6D0.segments[i].pos.x -= (var_fv0 + var_fv1) / 2;
        D_802CB6D0.segments[i].pos.z -= (var_fa0 + var_fa1) / 2;
    }
    D_xk2_800F7040 = 3;
}

Gfx* CourseEdit_DrawControlPointDirectLines(Gfx* gfx) {
    s32 i;

    if (D_802CB6D0.controlPointCount < 2) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if ((i == D_800D6CA0.selectedControlPoint) && (D_800DCD04 != 0)) {
            continue;
        }
        gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
        gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
        gSPLine3D(gfx++, 0, 1, 0);
    }
    return gfx;
}

extern s32 gCourseEditSelectionBoxStartX;
extern s32 gCourseEditSelectionBoxStartY;
extern s32 gCourseEditSelectionBoxEndX;
extern s32 gCourseEditSelectionBoxEndY;

Gfx* CourseEdit_DrawSelectionBox(Gfx* gfx) {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;

    if (gCourseEditCameraOnlyMode) {
        return gfx;
    }
    if (D_800D6CA0.state != COURSE_EDIT_SELECTION_BOX) {
        return gfx;
    }
    if (gCreateOption != CREATE_OPTION_POINT) {
        return gfx;
    }
    if (!(gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z)) {
        return gfx;
    }
    if (gCourseEditCursorYPos < 0x38) {
        return gfx;
    }
    if (gCourseEditSelectionBoxStartX < gCourseEditSelectionBoxEndX) {
        left = gCourseEditSelectionBoxStartX;
        right = gCourseEditSelectionBoxEndX;
    } else {
        left = gCourseEditSelectionBoxEndX;
        right = gCourseEditSelectionBoxStartX;
    }
    if (gCourseEditSelectionBoxStartY < gCourseEditSelectionBoxEndY) {
        top = gCourseEditSelectionBoxStartY;
        bottom = gCourseEditSelectionBoxEndY;
    } else {
        top = gCourseEditSelectionBoxEndY;
        bottom = gCourseEditSelectionBoxStartY;
    }

    gSPDisplayList(gfx++, D_3000510);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gSPTextureRectangle(gfx++, left << 2, top << 2, right << 2, (top + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, left << 2, bottom << 2, (right + 1) << 2, (bottom + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 1) << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, right << 2, top << 2, (right + 1) << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

void func_xk2_800E77F0(void) {
    D_800D6CA0.moveMode = 0;
    D_800D6CA0.unk_04 = 0;
    D_800D6CA0.state = 0;
    D_800D6CA0.newSegment.trackSegmentInfo = TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000;
    D_800D6CA0.unreasonableControlPoint = -1;
    D_800D6CA0.overlappingControlPoint = -1;
    D_800D6CA0.unk_24 = 0;
    D_800D6CA0.selectedControlPoint = -1;
    D_800D6CA0.unk_10 = -1;
    D_800D6CA0.courseYaw = 0;
    D_800D6CA0.newSegment.radiusLeft = 260.0f;
    D_800D6CA0.newSegment.radiusRight = 260.0f;
    D_800D6CA0.newSegment.up.x = 0.0f;
    D_800D6CA0.newSegment.up.y = 1.0f;
    D_800D6CA0.newSegment.up.z = 0.0f;
}

void func_xk2_800E7854(void) {

    D_xk2_800F7034 += D_xk2_800F7038;

    // clang-format off
    if (D_xk2_800F7034 >= 255) {
        D_xk2_800F7034 = 255; \
        D_xk2_800F7038 = -0x10;
    }
    if (D_xk2_800F7034 <= 0) {
        D_xk2_800F7034 = 0; \
        D_xk2_800F7038 = 0x10;
    }
    // clang-format on
    func_xk2_800DFFF8();
    func_xk2_800E5B6C();
    func_xk2_800E7BA8();
    func_xk2_800E7990();
    func_xk2_800E7A78();
    Course_UpdateSignRotation();
    func_80703234();
    if ((D_802CB6D0.controlPointCount >= 4) && (D_800D6CA0.unreasonableControlPoint == -1)) {
        Course_FeaturesInit(0);
        if (D_xk2_800F7040 != 0) {
            Course_EffectsInit(0);
        }
        Course_LandminesViewInteractDataInit();
        Course_JumpsViewInteractDataInit();
        if (D_800D6CA0.moveMode == 1) {
            Course_EffectsViewInteractDataInit(true);
        } else if (D_xk2_800F7040 != 0) {
            Course_EffectsViewInteractDataInit(false);
        }
        Course_DecorationsViewInteractDataInit();
    }
    func_xk2_800F1938();
}

extern Vec3f gCourseEditTooLowSegmentPos;

void func_xk2_800E7990(void) {
    CourseSegment* segment;
    s32 i;

    gCourseEditErrors[COURSE_EDIT_ERROR_TOO_LOW] = false;
    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    gCourseEditTooLowSegmentPos.y = 0.0f;
    segment = D_802CB6D0.segments;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        Course_SplineGetPosition(segment, 0.5f, &gCourseEditTooLowSegmentPos);
        if (gCourseEditTooLowSegmentPos.y < -375.0f) {
            gCourseEditErrors[COURSE_EDIT_ERROR_TOO_LOW] = true;
            return;
        }

        segment = segment->next;
    }
}

extern Vec3f D_xk2_80119828;

void func_xk2_800E7A78(void) {
    CourseSegment* var_s0;
    s32 i;

    gCourseEditErrors[COURSE_EDIT_ERROR_EXTENDS_OOB] = false;
    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    D_xk2_80119828.x = 0.0f;
    D_xk2_80119828.z = 0.0f;
    var_s0 = D_802CB6D0.segments;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        Course_SplineGetPosition(var_s0, 0.5f, &D_xk2_80119828);
        if ((D_xk2_80119828.x < -15000.0f) || (D_xk2_80119828.x > 15000.0f) || (D_xk2_80119828.z < -15000.0f) ||
            (D_xk2_80119828.z > 15000.0f)) {
            gCourseEditErrors[COURSE_EDIT_ERROR_EXTENDS_OOB] = true;
            return;
        }

        var_s0 = var_s0->next;
    }
}

void func_xk2_800E7BA8(void) {
    CourseSegment* var_s0;
    s32 i;
    f32 sp114;
    CourseSegment* temp_s1;
    CourseSegment* temp_s2;
    Vec3f sp100;
    Vec3f spF4;
    Vec3f spE8;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_ft4;
    Mtx3F spB8;
    Mtx3F sp94;
    Mtx3F sp70;
    f32 temp_fv0;
    f32 temp_fs0;
    f32 var_fs1;

    var_fs1 = 200.0f;
    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    var_s0 = D_802CB6D0.segments[0].prev;
    temp_fs0 = Course_SplineGetLengthInfo(var_s0, 0.0f, &sp114);
    Course_SplineGetPosition(var_s0, 0.0f, &spF4);
    Course_SplineGetBasis(var_s0, 0.0f, &sp94, temp_fs0);
    var_s0 = var_s0->next;
    temp_fs0 = Course_SplineGetLengthInfo(var_s0, 0.0f, &sp114);
    Course_SplineGetPosition(var_s0, 0.0f, &sp100);
    Course_SplineGetBasis(var_s0, 0.0f, &spB8, temp_fs0);

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_s0 = &D_802CB6D0.segments[i];

        temp_s1 = var_s0->next;
        temp_s2 = var_s0->prev;
        temp_fs0 = Course_SplineGetLengthInfo(temp_s1, 0.0f, &sp114);
        Course_SplineGetPosition(temp_s1, 0.0f, &spE8);
        Course_SplineGetBasis(temp_s1, 0.0f, &sp70, temp_fs0);

        temp_fv1 = ((temp_s2->radiusLeft * sp94.z.x) + spF4.x) - (sp100.x + (var_s0->radiusLeft * spB8.z.x));
        temp_fa1 = ((temp_s2->radiusLeft * sp94.z.y) + spF4.y) - (sp100.y + (var_s0->radiusLeft * spB8.z.y));
        temp_ft4 = ((temp_s2->radiusLeft * sp94.z.z) + spF4.z) - (sp100.z + (var_s0->radiusLeft * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }

        temp_fv1 = (spF4.x - (temp_s2->radiusRight * sp94.z.x)) - (sp100.x - (var_s0->radiusRight * spB8.z.x));
        temp_fa1 = (spF4.y - (temp_s2->radiusRight * sp94.z.y)) - (sp100.y - (var_s0->radiusRight * spB8.z.y));
        temp_ft4 = (spF4.z - (temp_s2->radiusRight * sp94.z.z)) - (sp100.z - (var_s0->radiusRight * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }

        temp_fv1 = ((temp_s1->radiusLeft * sp70.z.x) + spE8.x) - (sp100.x + (var_s0->radiusLeft * spB8.z.x));
        temp_fa1 = ((temp_s1->radiusLeft * sp70.z.y) + spE8.y) - (sp100.y + (var_s0->radiusLeft * spB8.z.y));
        temp_ft4 = ((temp_s1->radiusLeft * sp70.z.z) + spE8.z) - (sp100.z + (var_s0->radiusLeft * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }

        temp_fv1 = (spE8.x - (temp_s1->radiusRight * sp70.z.x)) - (sp100.x - (var_s0->radiusRight * spB8.z.x));
        temp_fa1 = (spE8.y - (temp_s1->radiusRight * sp70.z.y)) - (sp100.y - (var_s0->radiusRight * spB8.z.y));
        temp_ft4 = (spE8.z - (temp_s1->radiusRight * sp70.z.z)) - (sp100.z - (var_s0->radiusRight * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }
        spF4 = sp100;
        sp94 = spB8;
        sp100 = spE8;
        spB8 = sp70;
    }
    if (var_fs1 < 150.0f) {
        gCourseEditErrors[COURSE_EDIT_ERROR_POINTS_TOO_CLOSE] = true;
    }
}

extern MenuWidget gCreateWidget;
extern MenuWidget gCourseEditWidget;
extern s32* gCourseEditMenuOptions[];

Gfx* CourseEdit_DrawMenu(Gfx* gfx) {
    static bool sCourseEditCursorOnOption = false;
    s32 i;
    MenuDropItem* menuItem;
    s32 temp_t2_2;
    s32 left;
    s32 var_t0;

    gSPDisplayList(gfx++, D_9014908);

    for (i = 0; i < 5; i++) {
        if (gCourseEditWidget.menuItems[i].widget == NULL) {
            continue;
        }

        var_t0 = *gCourseEditMenuOptions[i];
        if (var_t0 == -1) {
            continue;
        }
        // FAKE
        menuItem = &gCourseEditWidget.menuItems[i].widget->menuItems[(0, var_t0)];

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        gDPLoadTextureBlock(gfx++, menuItem->backgroundSelectedTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, ((i * 48) + 24) << 2, 36 << 2, ((i * 48) + 72) << 2, 52 << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        if (menuItem->subContentsRGBATex != NULL) {
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, menuItem->subContentsRGBATex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, ((i * 48) + 0x2B) << 2, 38 << 2, ((i * 48) + 0x45) << 2, 50 << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
        }

        if (menuItem->contentsTex != NULL) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, menuItem->contentsTex, G_IM_FMT_I, menuItem->contentsWidth,
                                   menuItem->contentsHeight, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, ((i * 48) + 24) << 2, 36 << 2, ((i * 48) + menuItem->contentsWidth + 0x18) << 2,
                                (menuItem->contentsHeight + 0x34) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }

        if (menuItem->subContentsI4Tex != NULL) {
            temp_t2_2 = 16;
            // FAKE
            left = ((i * 48) + 0x34);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, menuItem->subContentsI4Tex, G_IM_FMT_I, temp_t2_2, temp_t2_2, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, ((i * 48) + 0x34) << 2, 36 << 2, ((i * 48) + 0x44) << 2, 52 << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
        }
    }
    {
        Gfx* menuGfx;
        menuGfx = D_80128C94->unk_F9A0;
        EKWidget_DrawWidgets(&menuGfx, &gCourseEditWidget, gCourseEditMenuCursorXPos, gCourseEditMenuCursorYPos);
        gSPEndDisplayList(menuGfx++);
    }

    gSPDisplayList(gfx++, D_6000000.unk_F9A0);

    {
        MenuWidget* widget;
        s32 top;
        widget = func_xk1_80026914(&gCourseEditWidget);
        if (D_802CB6D0.controlPointCount < 4) {
            if (widget == &gCreateWidget) {

                left = widget->left;
                top = widget->top + widget->itemYOffset;

                gSPDisplayList(gfx++, D_3000510);
                gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 128);

                gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 80) << 2, 0, 0, 0, 1 << 10,
                                    1 << 10);

                gSPDisplayList(gfx++, D_3000540);
                func_xk2_800EECD4(&gfx, left + 48, top + 16, gCourseEditMessageStrs[24], 24);
            }
        }
    }
    gfx = CourseEdit_DrawFileRegisterMenu(gfx);

    gDPPipeSync(gfx++);

    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    if ((gCourseEditCursorXPos >= 264) && (gCourseEditCursorXPos < 296) && (gCourseEditCursorYPos >= 20) &&
        (gCourseEditCursorYPos < 36)) {

        gDPLoadTextureBlock(gfx++, aExpansionKitMenuExitHighlightTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, aExpansionKitMenuExitTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    }

    gSPTextureRectangle(gfx++, 264 << 2, 20 << 2, 296 << 2, 36 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    if ((gCourseEditCursorXPos >= 264) && (gCourseEditCursorXPos < 296) && (gCourseEditCursorYPos >= 36) &&
        (gCourseEditCursorYPos < 52)) {
        if (!sCourseEditCursorOnOption) {
            Audio_TriggerSystemSE(NA_SE_35);
        }
        sCourseEditCursorOnOption = true;
    } else {
        if (sCourseEditCursorOnOption) {
            Audio_TriggerSystemSE(NA_SE_35);
        }
        sCourseEditCursorOnOption = false;
    }

    if (sCourseEditCursorOnOption) {
        gDPLoadTextureBlock(gfx++, aExpansionKitMenuOptionHighlightTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, aExpansionKitMenuOptionTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    }

    gSPTextureRectangle(gfx++, 264 << 2, 36 << 2, 296 << 2, 52 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    if (D_xk2_800F7048 != 0) {
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 128);

        gSPTextureRectangle(gfx++, 24 << 2, 20 << 2, 296 << 2, 36 << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gfx++, 24 << 2, 36 << 2, 296 << 2, 52 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    return gfx;
}

extern u8 D_80030060[];

Gfx* CourseEdit_DrawCourseTitle(Gfx* gfx) {

    if (gCourseEditCameraOnlyMode) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, 231 << 2, 177 << 2, 297 << 2, 203 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);
    gSPTextureRectangle(gfx++, 232 << 2, 178 << 2, 296 << 2, 202 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);

    if (D_80030060[0] == '\0') {
        gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 0);
        return ExpansionKit_DrawEncStr(gfx, 232, 178, "No Title");
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 0);
    return ExpansionKit_DrawEncStr(gfx, 232, 178, "%s", D_80030060);
}

s32 func_xk2_800E9134(s32 chunkIndex) {
    s32 i;
    s32 startChunkIndex;
    s32 endChunkIndex;
    s32 var_v1;
    CourseSegment* var_a0;

    var_v1 = -1;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_a0 = &D_802CB6D0.segments[i];

        startChunkIndex = var_a0->startChunk - gSegmentChunks;
        endChunkIndex = var_a0->endChunk - gSegmentChunks;
        if (startChunkIndex < endChunkIndex) {
            if ((chunkIndex >= startChunkIndex) && (chunkIndex < endChunkIndex)) {
                var_v1 = i;
                break;
            }
        } else if (((chunkIndex >= 0) && (chunkIndex < endChunkIndex)) || (chunkIndex >= startChunkIndex)) {
            var_v1 = i;
            break;
        }
    }
    return var_v1;
}

f32 sMouseClickTopOffset = 0.0f;

void CourseEdit_UpdateMouseClick(void) {
    static f32 sMouseClickSpeed = 0.0f;
    static bool sMouseClickMovingDown = true;
    sMouseClickTopOffset += sMouseClickSpeed;
    if (sMouseClickMovingDown) {
        sMouseClickSpeed += 1.0f;
        if (sMouseClickTopOffset >= 6.0f) {
            sMouseClickSpeed = -2.0f;
            sMouseClickMovingDown = false;
        }
    } else if (sMouseClickTopOffset <= 0.0f) {
        sMouseClickTopOffset = 0.0f;
        sMouseClickSpeed = 0.0f;
        sMouseClickMovingDown = true;
    }
}

void CourseEdit_DrawMouseClick(Gfx** gfxP, s32 left, s32 top) {
    Gfx* gfx;

    left = left - 8;
    top = ((s32) (sMouseClickTopOffset + 0.5f) + top) - 28;
    if ((left >= 0) && (left < SCREEN_WIDTH) && (top >= 40) && (top < SCREEN_HEIGHT)) {
        gfx = *gfxP;

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        *gfxP = gfx;
    }
}

void CourseEdit_DrawOverlapMouseClick(Gfx** gfxP) {
    Gfx* gfx;
    s32 screenPosX;
    s32 screenPosY;
    Vec3f pos;

    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return;
    }
    gfx = *gfxP;
    if (D_xk2_800F7068 != -1) {
        pos = gSegmentChunks[D_xk2_800F7068].pos;
        if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) == 0) {
            CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
        }
    }

    if (D_800D6CA0.overlappingControlPoint != -1) {
        pos = D_802CB6D0.segments[D_800D6CA0.overlappingControlPoint].pos;
        if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) == 0) {
            CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
        }
    }
    *gfxP = gfx;
}

void CourseEdit_DrawUnreasonablePointMouseClick(Gfx** gfxP) {
    Gfx* gfx;
    s32 screenPosX;
    s32 screenPosY;
    Vec3f pos;

    if (D_800D6CA0.unreasonableControlPoint == -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        D_800D6CA0.unreasonableControlPoint = -1;
        return;
    }
    gfx = *gfxP;
    pos = D_802CB6D0.segments[D_800D6CA0.unreasonableControlPoint].pos;
    if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) == 0) {
        CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
    }
    *gfxP = gfx;
}

void CourseEdit_DrawInvalidPartPlacementMouseClick(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 screenPosX;
    s32 screenPosY;
    Vec3f pos;

    gfx = *gfxP;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (CourseEdit_GetSegmentJoinErrors(i) & 1) {
            pos = D_802CB6D0.segments[i].pos;
            if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) == 0) {
                CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
            }
        }
    }
    *gfxP = gfx;
}

void CourseEdit_DrawTooNarrowForJointMouseClick(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 screenPosX;
    s32 screenPosY;
    Vec3f pos;

    gfx = *gfxP;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (CourseEdit_GetSegmentJoinErrors(i) & 2) {
            pos = D_802CB6D0.segments[i].pos;
            if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) == 0) {
                CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
            }
        }
    }
    *gfxP = gfx;
}

extern Vec3f gCourseEditTooLowSegmentPos;

void CourseEdit_DrawTooLowMouseClick(Gfx** gfxP) {
    Gfx* gfx;
    s32 screenPosX;
    s32 screenPosY;

    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        gCourseEditTooLowSegmentPos.y = 0.0f;
        return;
    }
    if (gCourseEditTooLowSegmentPos.y >= -375.0f) {
        return;
    }
    gfx = *gfxP;
    if (CourseEdit_GetScreenPosition(gCourseEditTooLowSegmentPos, &screenPosX, &screenPosY) == 0) {
        CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
    }
    *gfxP = gfx;
}

void CourseEdit_DrawMidPointOOBMouseClick(Gfx** gfxP) {
    CourseSegment* segment;
    s32 screenPosX;
    s32 screenPosY;
    Vec3f pos;
    s32 i;
    Gfx* gfx;

    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }

    gfx = *gfxP;
    segment = D_802CB6D0.segments;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        Course_SplineGetPosition(segment, 0.5f, &pos);
        if (((pos.x < -15000.0f) || (pos.x > 15000.0f) || (pos.z < -15000.0f) || (pos.z > 15000.0f)) &&
            (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) == 0)) {
            CourseEdit_DrawMouseClick(&gfx, screenPosX, screenPosY);
        }
        segment = segment->next;
    }
    *gfxP = gfx;
}

#define COURSE_EDIT_ICONS_X_POS 232
#define COURSE_EDIT_ICONS_Y_POS 204
#define COURSE_EDIT_ICON_WIDTH 16
#define COURSE_EDIT_ICON_HEIGHT 16
#define COURSE_EDIT_NUM_ICONS 4

s32 CourseEdit_UpdateHighlightedIconIndex(void) {
    s32 highlightedIconXPos;

    if ((gCreateOption == CREATE_OPTION_POINT) && (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z)) {
        gCourseEditHighlightedIconIndex = -1;
        return -1;
    }
    if (D_800D6CA0.state != 0) {
        return -1;
    }
    if (D_800D6CA0.moveMode == 1) {
        gCourseEditHighlightedIconIndex = -1;
        return -1;
    }
    if (gCourseEditHighlightedIconIndex == -1) {
        if ((gCourseEditCursorXPos < COURSE_EDIT_ICONS_X_POS) ||
            (gCourseEditCursorXPos >= COURSE_EDIT_ICONS_X_POS + COURSE_EDIT_NUM_ICONS * COURSE_EDIT_ICON_WIDTH)) {
            return gCourseEditHighlightedIconIndex;
        }
        if ((gCourseEditCursorYPos < COURSE_EDIT_ICONS_Y_POS) ||
            (gCourseEditCursorYPos >= COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT)) {
            return gCourseEditHighlightedIconIndex;
        }
        gCourseEditHighlightedIconIndex = (gCourseEditCursorXPos - COURSE_EDIT_ICONS_X_POS) / COURSE_EDIT_ICON_WIDTH;
        Audio_TriggerSystemSE(NA_SE_35);
    } else {
        highlightedIconXPos =
            (gCourseEditHighlightedIconIndex * COURSE_EDIT_ICON_WIDTH) + (COURSE_EDIT_ICONS_X_POS - 2);
        if ((gCourseEditCursorXPos >= highlightedIconXPos) &&
            (gCourseEditCursorXPos < (highlightedIconXPos + 2 + COURSE_EDIT_ICON_WIDTH + 2)) &&
            (gCourseEditCursorYPos >= COURSE_EDIT_ICONS_Y_POS - 2) &&
            (gCourseEditCursorYPos < COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT + 2)) {
            return gCourseEditHighlightedIconIndex;
        }
        if ((gCourseEditCursorXPos < COURSE_EDIT_ICONS_X_POS) ||
            (gCourseEditCursorXPos >= COURSE_EDIT_ICONS_X_POS + COURSE_EDIT_NUM_ICONS * COURSE_EDIT_ICON_WIDTH)) {
            gCourseEditHighlightedIconIndex = -1;
            return -1;
        }
        if ((gCourseEditCursorYPos < COURSE_EDIT_ICONS_Y_POS) ||
            (gCourseEditCursorYPos >= COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT)) {
            gCourseEditHighlightedIconIndex = -1;
            return -1;
        }
        Audio_TriggerSystemSE(NA_SE_35);
        gCourseEditHighlightedIconIndex = (gCourseEditCursorXPos - COURSE_EDIT_ICONS_X_POS) / COURSE_EDIT_ICON_WIDTH;
    }
    return gCourseEditHighlightedIconIndex;
}

void CourseEdit_DrawIcons(Gfx** gfxP) {
    Gfx* gfx;
    s32 highlightLeft;
    s32 i;
    s32 left;
    s32 highlightedIconIndex;

    gfx = *gfxP;
    if (gCourseEditCameraOnlyMode) {
        return;
    }

    gSPDisplayList(gfx++, D_8014940);

    left = COURSE_EDIT_ICONS_X_POS;
    for (i = 0; i < 4; i++, left += COURSE_EDIT_ICON_WIDTH) {
        gDPLoadTextureBlock(gfx++, gCourseEditIconTextures[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, COURSE_EDIT_ICON_WIDTH,
                            COURSE_EDIT_ICON_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, COURSE_EDIT_ICONS_Y_POS << 2, (left + COURSE_EDIT_ICON_WIDTH) << 2,
                            (COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    highlightedIconIndex = gCourseEditHighlightedIconIndex;
    if ((highlightedIconIndex >= COURSE_EDIT_ICON_TEST_DRIVE) && (highlightedIconIndex <= COURSE_EDIT_ICON_TOOLTIPS)) {
        highlightLeft = (highlightedIconIndex * COURSE_EDIT_ICON_WIDTH) + COURSE_EDIT_ICONS_X_POS;
        gDPLoadTextureBlock(gfx++, gCourseEditIconTextures[highlightedIconIndex], G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            COURSE_EDIT_ICON_WIDTH, COURSE_EDIT_ICON_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, (highlightLeft - 2) << 2, (COURSE_EDIT_ICONS_Y_POS - 2) << 2,
                            (highlightLeft + COURSE_EDIT_ICON_WIDTH + 2) << 2,
                            (COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT + 2) << 2, 0, 0, 0, (1 << 10) * 4 / 5,
                            (1 << 10) * 4 / 5);
    }
    *gfxP = gfx;
}

void CourseEdit_DrawControlPointInfoBackground(Gfx** gfxP, s32 left, s32 top, s32 width, s32 height) {
    Gfx* gfx;
    s32 pad[4];

    gfx = *gfxP;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureTile(gfx++, aCourseEditInfoBackgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 24, 8, 16, 8, 16, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + 4) << 2, (top + 4) << 2, (left + width - 4) << 2, (top + height - 4) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

Gfx* CourseEdit_DrawStartMarker(Gfx* gfx) {
    s32 screenPosX;
    s32 screenPosY;
    s32 pad[2];
    Vec3f pos;
    s32 pad2[11];

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }
    if (gInCourseEditTestRun) {
        return gfx;
    }
    pos = D_802CB6D0.segments[1].pos;

    if (CourseEdit_GetScreenPosition(pos, &screenPosX, &screenPosY) != 0) {
        return gfx;
    }
    screenPosX -= 12;
    screenPosY -= 12;
    gSPDisplayList(gfx++, aCourseEditStartMarkerDL);

    gSPTextureRectangle(gfx++, screenPosX << 2, screenPosY << 2, (screenPosX + 24) << 2, (screenPosY + 12) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);

    return gfx;
}

extern s32 gCourseEditCourseRegisterIndex;

Gfx* CourseEdit_DrawFileSelectRegisterMenu(Gfx* gfx) {

    if (D_800D6CA0.state != 3) {
        return gfx;
    }
    if (D_80119880 == 5) {
        gSPDisplayList(gfx++, D_8014940);
        EKFileMenu_DrawFileMenuBorder(&gfx, 208, 72, 10, 3);
        if (1) {}
        gDPPipeSync(gfx++);
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);

        gExpansionKitEncStrEncType = 0;
        // コース
        gfx = ExpansionKit_DrawEncStr(gfx, 216, 80, "  %c%c%c%d", 0xBA, 0xB0, 0xBD, gCourseEditCourseRegisterIndex + 1);
    }
    gfx = EKFileMenu_DrawFileMenu(gfx, 8);

    return gfx;
}

Lights2 D_xk2_800F7208 = gdSPDefLights2(64, 64, 64, 255, 255, 255, 0, 0, 120, 255, 255, 255, 0, 0, 120);

Gfx* CourseEdit_DrawMiniMachine(Gfx* gfx) {
    static s32 sMiniMachineControlPoint = 0;
    static f32 sMiniMachineSegmentTValue = 0.0f;
    CourseSegment* segment;
    f32 lengthProportionAlongSegment;
    f32 lengthFromStart;
    f32 var_fs0;
    f32 temp_fv1;
    Vec3f pos;
    Vec3f spBC;
    Mtx3F basis;
    s32 pad;

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }
    if (D_800D6CA0.unreasonableControlPoint != -1) {
        return gfx;
    }
    if (gInCourseEditTestRun) {
        return gfx;
    }

    if (sMiniMachineControlPoint >= D_802CB6D0.controlPointCount) {
        sMiniMachineControlPoint = 0;
        sMiniMachineSegmentTValue = 0.0f;
    }
    segment = &D_802CB6D0.segments[sMiniMachineControlPoint];

    lengthProportionAlongSegment = Course_SplineGetLengthInfo(segment, sMiniMachineSegmentTValue, &lengthFromStart);
    Course_SplineGetPosition(segment, sMiniMachineSegmentTValue, &pos);
    Course_SplineGetBasis(segment, sMiniMachineSegmentTValue, &basis, lengthProportionAlongSegment);
    Matrix_SetLockedLookAt(&D_80128C94->unk_0100, NULL, 1.0f, 1.0f, 1.0f, basis.x.x, basis.x.y, basis.x.z, basis.y.x,
                           basis.y.y, basis.y.z, pos.x, pos.y, pos.z);
    Course_SplineGetTangent(segment, sMiniMachineSegmentTValue, &spBC);
    var_fs0 = 250.0f;

    while (true) {
        temp_fv1 = var_fs0 / Course_SplineGetTangent(segment, sMiniMachineSegmentTValue, &spBC);
        if (temp_fv1 < 1.0f) {
            break;
        }
        var_fs0 /= temp_fv1 + 1;
    }
    sMiniMachineSegmentTValue += temp_fv1;
    if (sMiniMachineSegmentTValue >= 1.0f) {
        sMiniMachineControlPoint++;
        sMiniMachineSegmentTValue -= 1.0f;
    }

    gSPLoadUcodeL(gfx++, gspF3DLX2_Rej_fifo);
    CourseEdit_DrawSetup(&gfx);
    gSPMatrix(gfx++, &D_6000000.unk_0100, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_3000400);

    gSPSetLights2(gfx++, D_xk2_800F7208);

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);

    gfx = func_8009CCBC(gfx, gCourseEditMiniMachineCharacter, gCourseEditMiniMachineColorPalette);
    gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
    CourseEdit_DrawSetup(&gfx);
    return gfx;
}

void CourseEdit_DrawClearCourseWarning(Gfx** gfxP) {
    s32 pad[3];
    Gfx* gfx;

    if (D_800D6CA0.state != 0x11) {
        return;
    }
    gfx = *gfxP;
    func_xk2_800EECD4(&gfx, 0, 0x48, gCourseEditMessageStrs[18], 18);
    *gfxP = gfx;
}

void CourseEdit_DrawClearEntryWarning(Gfx** gfxP) {
    s32 pad[3];
    Gfx* gfx;

    if (D_800D6CA0.state != 0x23) {
        return;
    }
    gfx = *gfxP;
    func_xk2_800EECD4(&gfx, 0, 0x48, gCourseEditMessageStrs[23], 23);
    *gfxP = gfx;
}
