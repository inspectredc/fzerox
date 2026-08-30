#include "global.h"
#include "fzx_camera.h"
#include "fzx_expansion_kit.h"
#include ASSET_HEADER_EK(course_edit_textures.h)

Vec3f sCourseEditControlPointHighlightPos;
UNUSED s32 D_xk2_8013A750[2];
Mtx sCourseEditControlPointOrthoMtx;
Mtx sCourseEditControlPointLookAtMtx;

bool sCourseEditControlPointIsHighlighted = false;
s32 sCourseEditHighlightedControlPoint = -1;

void CourseEdit_ClearControlPointHighlight(void) {
    sCourseEditControlPointIsHighlighted = false;
}

void CourseEdit_InitControlPointHighlight(void) {
    Matrix_SetOrtho(&sCourseEditControlPointOrthoMtx, NULL, 1.0f, -(SCREEN_WIDTH / 2), (SCREEN_WIDTH / 2), -(SCREEN_HEIGHT / 2), (SCREEN_HEIGHT / 2), 16.0f, 256.0f);
    Matrix_SetLookAt(&sCourseEditControlPointLookAtMtx, NULL, 0.0f, 0.0f, 128.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

bool CourseEdit_IsControlPointHighlighted(void) {
    return sCourseEditControlPointIsHighlighted;
}

extern GfxPool* gGfxPool;

void CourseEdit_UpdateControlPointHighlightVtxs(void) {
    static s32 sControlPointHighlightAngle = 0;
    s32 angle;
    Vtx* vtx;
    MtxF mtxF;
    s32 pad[8];
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv1;
    f32 temp_ft2;
    f32 temp_ft2_2;
    f32 sp38;

    sControlPointHighlightAngle = (sControlPointHighlightAngle + 8) % 360;
    angle = DEG_TO_FZXANG(sControlPointHighlightAngle);

    Matrix_SetAxisRotation(NULL, &mtxF, 1.0f, angle, gCameras[0].basis.x.x, gCameras[0].basis.x.y, gCameras[0].basis.x.z,
                           0.0f, 0.0f, 0.0f);

    vtx = gGfxPool->unk_365E8;
    temp_fv1 = COS(angle) * 24.0f;
    temp_ft4 = SIN(angle) * -24.0f;
    temp_ft2_2 = 0.0f;
    temp_ft5 = SIN(angle) * 24.0f;
    sp38 = COS(angle) * 24.0f;
    temp_ft2 = 0.0f;

    // clang-format off
    vtx->v.ob[0] = temp_ft5; \
    vtx->v.ob[1] = sp38;     \
    vtx->v.ob[2] = temp_ft2; \
    vtx->v.tc[0] = 0;        \
    vtx->v.tc[1] = 0;
    vtx++;

    vtx->v.ob[0] = temp_fv1;   \
    vtx->v.ob[1] = temp_ft4;   \
    vtx->v.ob[2] = temp_ft2_2; \
    vtx->v.tc[0] = 0x800;      \
    vtx->v.tc[1] = 0;
    vtx++;

    vtx->v.ob[0] = 0.0f - temp_ft5; \
    vtx->v.ob[1] = 0.0f - sp38;     \
    vtx->v.ob[2] = 0.0f - temp_ft2; \
    vtx->v.tc[0] = 0x800;           \
    vtx->v.tc[1] = 0x800;
    vtx++;

    vtx->v.ob[0] = 0.0f - temp_fv1;   \
    vtx->v.ob[1] = 0.0f - temp_ft4;   \
    vtx->v.ob[2] = 0.0f - temp_ft2_2; \
    vtx->v.tc[0] = 0;                 \
    vtx->v.tc[1] = 0x800;
    vtx++;
    // clang-format on
}

extern s32 gCourseEditAlignPointsEnabled;
extern s32 gCourseEditCameraZoom;
extern s32 gCourseEditCameraAtX;
extern s32 gCourseEditCameraAtY;
extern s32 gCourseEditCameraAtZ;
extern unk_807B3C20 D_802CB6D0;
extern unk_800D6CA0 D_800D6CA0;
extern s32 gCourseEditCursorXPos;
extern s32 gCourseEditCursorYPos;
extern s32 D_xk2_800F7040;

void CourseEdit_UpdateControlPointHighlight(void) {
    static s32 sZPressActivationTimer = 0;
    static s32 sZPressActivated = 0;

    if (sCourseEditControlPointIsHighlighted) {
        CourseEdit_UpdateControlPointHighlightVtxs();
    }
    if (sZPressActivationTimer != 0) {
        sZPressActivationTimer--;
    }

    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        sCourseEditControlPointIsHighlighted = false;
    }
    if (D_800D6CA0.unk_00 == 1) {
        sCourseEditControlPointIsHighlighted = false;
    }
    if (!sZPressActivated || (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z)) {
        sZPressActivated = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z;
        return;
    }
    if (gCourseEditCursorYPos < 0x38) {
        sZPressActivated = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z;
        return;
    }
    if (sZPressActivationTimer != 0) {
        sCourseEditHighlightedControlPoint = func_xk2_800EFDE4(4000.0f);
        if (sCourseEditHighlightedControlPoint == -1) {
            return;
        }
        sCourseEditControlPointIsHighlighted = true;
        gCourseEditCursorXPos = SCREEN_WIDTH / 2;
        gCourseEditCursorYPos = SCREEN_HEIGHT / 2;
        if (gCourseEditAlignPointsEnabled != 0) {
            func_xk2_800DE4F8();
        }
        D_xk2_800F7040 = 3;
        if (D_800D6CA0.unk_00 == 1) {
            D_800D6CA0.unk_00 = 0;
        }
        func_xk2_800DC3F8();
        sCourseEditControlPointHighlightPos = D_802CB6D0.segments[sCourseEditHighlightedControlPoint].pos;
        gCourseEditCameraAtX = D_802CB6D0.segments[sCourseEditHighlightedControlPoint].pos.x * 0.3f;
        gCourseEditCameraAtY = D_802CB6D0.segments[sCourseEditHighlightedControlPoint].pos.y * 0.3f;
        gCourseEditCameraAtZ = D_802CB6D0.segments[sCourseEditHighlightedControlPoint].pos.z * 0.3f;
        gCameras[0].eye.x = gCourseEditCameraAtX;
        gCameras[0].eye.y = gCourseEditCameraAtY + gCourseEditCameraZoom;
        gCameras[0].eye.z = gCourseEditCameraAtZ;
    } else {
        sZPressActivationTimer = 8;
    }
    sZPressActivated = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z;
}

extern GfxPool D_1000000;

void CourseEdit_DrawControlPointHighlight(Gfx** gfxP) {
    Gfx* gfx;

    if (!sCourseEditControlPointIsHighlighted || (D_800D6CA0.state != 0)) {
        return;
    }
    gfx = *gfxP;

    gSPMatrix(gfx++, &sCourseEditControlPointOrthoMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &sCourseEditControlPointLookAtMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_9014D18);
    gSPVertex(gfx++, D_1000000.unk_365E8, 4, 0);
    gSP2Triangles(gfx++, 0, 3, 1, 0, 1, 3, 2, 0);
    *gfxP = gfx;
}
