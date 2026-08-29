#include "global.h"
#include "fzx_camera.h"
#include "fzx_course.h"

u8 D_xk2_80128D00[64];
f32 D_xk2_80128D40;
f32 D_xk2_80128D44;
s32 D_xk2_80128D48;
s32 D_xk2_80128D4C;
s32 D_xk2_80128D50;
s32 D_xk2_80128D54;
s32 D_xk2_80128D58;
s32 D_xk2_80128D5C;
f32 sCourseEditCameraForwardX;
f32 sCourseEditCameraForwardY;
f32 sCourseEditCameraForwardZ;
s32 D_xk2_80128D6C;

u8 D_xk2_80104CA0[12] = { 0 };

extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F12B0(void) {
    s32 i;

    D_800D6CA0.unk_1C = -1;

    for (i = 0; i < 12; i++) {
        if ((i != 10) && (i != 1) && (i != 3)) {
            D_xk2_80104CA0[i] = 0;
        }
    }

    for (i = 0; i < 64; i++) {
        D_xk2_80128D00[i] = 0;
    }
}

void func_xk2_800F1330(s32 arg0, s32 arg1) {
    if (&arg1) {}
    D_xk2_80128D00[arg0] |= arg1;
}

u8 func_xk2_800F1350(s32 arg0) {
    return D_xk2_80128D00[arg0];
}

UNUSED s32 D_xk2_80104CAC = 0;
s32 gCourseEditCameraPitch = 90;
s32 gCourseEditCameraZoom = 15000;
s32 gCourseEditCameraAtX = 0;
s32 gCourseEditCameraAtY = 0;
s32 gCourseEditCameraAtZ = 0;

void func_xk2_800F1360(void) {
    D_xk2_80128D48 = gCourseEditCameraPitch;
    D_xk2_80128D4C = D_800D6CA0.courseYaw;
    D_xk2_80128D50 = gCourseEditCameraZoom;
    D_xk2_80128D54 = gCourseEditCameraAtX;
    D_xk2_80128D58 = gCourseEditCameraAtY;
    D_xk2_80128D5C = gCourseEditCameraAtZ;
}

void func_xk2_800F13C4(void) {
    gCourseEditCameraPitch = D_xk2_80128D48;
    D_800D6CA0.courseYaw = D_xk2_80128D4C;
    gCourseEditCameraZoom = D_xk2_80128D50;
    gCourseEditCameraAtX = D_xk2_80128D54;
    gCourseEditCameraAtY = D_xk2_80128D58;
    gCourseEditCameraAtZ = D_xk2_80128D5C;
}

extern unk_80225800 D_2000000;
extern bool gInCourseEditTestRun;
extern unk_80128C94 D_6000000;
extern unk_80128C94* D_80128C94;

Gfx* func_xk2_800F1428(Gfx* gfx) {
    u16 perspectiveScale;
    s32 pad[11];
    Camera* camera = gCameras;
    Mtx mtx;
    MtxF mtxF;

    if (gInCourseEditTestRun) {
        return Camera_DrawCourseEditTestRun(gfx);
    }
    if (gInCourseEditTestRun) {
        Matrix_SetFrustrum(&D_80128C94->unk_0000, NULL, (gCameras[0].fov * SCREEN_WIDTH) / SCREEN_HEIGHT, 32.0f, 4096.0f, SCREEN_WIDTH,
                           0.0f, SCREEN_HEIGHT, 0.0f, &perspectiveScale);
    } else {
        Matrix_SetFrustrum(&D_80128C94->unk_0000, NULL, (gCameras[0].fov * SCREEN_WIDTH) / SCREEN_HEIGHT, 128.0f, 32768.0f, SCREEN_WIDTH,
                           0.0f, SCREEN_HEIGHT, 0.0f, &perspectiveScale);
        perspectiveScale = 16;
    }
    gSPPerspNormalize(gfx++, perspectiveScale);
    gSPMatrix(gfx++, &D_6000000.unk_0000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    Matrix_FromMtx(&D_80128C94->unk_0000, &gCameras[0].projectionMtx);
    sCourseEditCameraForwardY = SIN(DEG_TO_FZXANG(gCourseEditCameraPitch));
    sCourseEditCameraForwardZ = COS(DEG_TO_FZXANG(gCourseEditCameraPitch));
    sCourseEditCameraForwardX = SIN(DEG_TO_FZXANG(D_800D6CA0.courseYaw)) * sCourseEditCameraForwardZ;
    sCourseEditCameraForwardY = (-1.0f * sCourseEditCameraForwardY);
    sCourseEditCameraForwardZ = COS(DEG_TO_FZXANG(D_800D6CA0.courseYaw)) * (-1.0f * sCourseEditCameraForwardZ);
    gCameras[0].basis.x.x = sCourseEditCameraForwardX;
    gCameras[0].basis.x.y = sCourseEditCameraForwardY;
    gCameras[0].basis.x.z = sCourseEditCameraForwardZ;

    gCameras[0].eye.x = gCourseEditCameraAtX - (gCourseEditCameraZoom * sCourseEditCameraForwardX);
    gCameras[0].eye.y = gCourseEditCameraAtY - (gCourseEditCameraZoom * sCourseEditCameraForwardY);
    gCameras[0].eye.z = gCourseEditCameraAtZ - (gCourseEditCameraZoom * sCourseEditCameraForwardZ);

    D_xk2_80128D40 = SIN(DEG_TO_FZXANG(D_800D6CA0.courseYaw));
    D_xk2_80128D44 = COS(DEG_TO_FZXANG(D_800D6CA0.courseYaw));

    gCameras[0].basis.y.x = 0 - (sCourseEditCameraForwardY * D_xk2_80128D40);
    gCameras[0].basis.y.y = (sCourseEditCameraForwardX * D_xk2_80128D40) - (sCourseEditCameraForwardZ * D_xk2_80128D44);
    gCameras[0].basis.y.z = sCourseEditCameraForwardY * D_xk2_80128D44;

    gCameras[0].basis.z.x = (sCourseEditCameraForwardZ * gCameras[0].basis.y.y) - (sCourseEditCameraForwardY * gCameras[0].basis.y.z);
    gCameras[0].basis.z.y = (sCourseEditCameraForwardX * gCameras[0].basis.y.z) - (sCourseEditCameraForwardZ * gCameras[0].basis.y.x);
    gCameras[0].basis.z.z = (sCourseEditCameraForwardY * gCameras[0].basis.y.x) - (sCourseEditCameraForwardX * gCameras[0].basis.y.y);
    Matrix_SetLookAt(&D_80128C94->unk_0040, NULL, gCameras[0].eye.x, gCameras[0].eye.y, gCameras[0].eye.z,
                     gCourseEditCameraAtX, gCourseEditCameraAtY, gCourseEditCameraAtZ, gCameras[0].basis.y.x, gCameras[0].basis.y.y,
                     gCameras[0].basis.y.z);

    gSPMatrix(gfx++, &D_6000000.unk_0040, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_2000000.unk_000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    Matrix_FromMtx(&D_80128C94->unk_0040, &gCameras[0].viewMtx);
    Camera_CalculateProjectionViewMtx(&gCameras[0].projectionViewMtx, &gCameras[0].projectionMtx, &gCameras[0].viewMtx);
    Matrix_SetLockedLookAt(&mtx, NULL, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Matrix_FromMtx(&mtx, &mtxF);
    func_xk2_800F1FF0(&mtxF, &gCameras[0].projectionViewMtx, &gCameras[0].projectionViewMtx);
    return gfx;
}

extern s32 gCourseEditCursorXPos;
extern s32 gCourseEditCursorYPos;
extern unk_807B3C20 D_802CB6D0;

void func_xk2_800F1938(void) {
    CourseSegment* temp_v1;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f64 temp_fa0;
    f64 temp_fa1;
    f32 var_fa1;
    f32 radiusLeft;
    f32 radiusRight;
    f32 var_fv0;
    f64 var_fv1;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    f64 var_fv0_2;
    f64 temp_dfv0;
    f64 temp_dfv1;
    f32 pad;

    if (gCourseEditCursorYPos < 0x38) {
        return;
    }
    temp_dfv0 = gCameras[0].fov;
    temp_dfv1 = ((gCameras[0].fov * 320.0f) / 240.0f);
    temp_dfv1 = ((gCourseEditCursorXPos - 0xA0) / 320.0) * temp_dfv1;
    temp_dfv0 = ((gCourseEditCursorYPos - 0x78) / 240.0) * temp_dfv0;

    temp_dfv1 = (4096.0 * temp_dfv1) / 360.0;
    temp_dfv0 = (4096.0 * temp_dfv0) / 360.0;

    temp_fa0 = ((10000.0f * SIN((s32) temp_dfv1)) / COS((s32) temp_dfv1));
    temp_fa1 = ((10000.0f * SIN((s32) temp_dfv0)) / COS((s32) temp_dfv0));

    sp88 = gCameras[0].eye.x + (gCameras[0].basis.x.x * 10000.0f);
    sp8C = gCameras[0].eye.y + (gCameras[0].basis.x.y * 10000.0f);
    sp90 = gCameras[0].eye.z + (gCameras[0].basis.x.z * 10000.0f);

    sp88 = ((sp88 - (temp_fa1 * gCameras[0].basis.y.x)) - (temp_fa0 * gCameras[0].basis.z.x));
    sp8C = ((sp8C - (temp_fa1 * gCameras[0].basis.y.y)) - (temp_fa0 * gCameras[0].basis.z.y));
    sp90 = ((sp90 - (temp_fa1 * gCameras[0].basis.y.z)) - (temp_fa0 * gCameras[0].basis.z.z));

    if (gCameras[0].eye.y <= sp8C) {
        var_fa1 = sp8C - gCameras[0].eye.y;
        var_fv0 = var_fa1;
    } else {
        var_fa1 = sp8C - gCameras[0].eye.y;
        var_fv0 = -var_fa1;
    }
    if (var_fv0 < 10.0f) {
        return;
    }
    if (D_802CB6D0.controlPointCount != 0) {
        temp_v1 = &D_802CB6D0.segments[D_800D6CA0.unk_0C];
        if (gCourseEditCameraPitch < 0) {
            var_fv1 = (((temp_v1->pos.y + temp_v1->next->pos.y) * 0.3f) / 2);
        } else {
            var_fv1 = (((temp_v1->pos.y + temp_v1->next->pos.y) * 0.3f) / 2);
            if (gCameras[0].eye.y < var_fv1) {
                var_fv1 = (gCameras[0].eye.y - 256.0f);
                if (var_fv1 < 0.0) {
                    var_fv1 = 0.0;
                }
            }
        }
        radiusLeft = (temp_v1->radiusLeft + temp_v1->next->radiusLeft) / 2;
        radiusRight = (temp_v1->radiusRight + temp_v1->next->radiusRight) / 2;
        temp_a2 = COURSE_CONTEXT()->courseData.bankAngle[temp_v1->segmentIndex];
        temp_a3 = COURSE_CONTEXT()->courseData.bankAngle[temp_v1->next->segmentIndex];
        temp_a1 = temp_a3 - temp_a2;

        if (ABS(temp_a1) < 180) {
            D_xk2_80128D6C = (s32) (temp_a2 + temp_a3) / 2;
        } else {
            D_xk2_80128D6C = (s32) (temp_a3 + temp_a2 + 360) / 2;
            D_xk2_80128D6C %= 360;
        }
    } else {
        D_xk2_80128D6C = 0;
        var_fv1 = 0.0;
        radiusLeft = 260.0f;
        radiusRight = 260.0f;
    }
    if (gCameras[0].eye.y != 0.0f) {
        // FAKE
        var_fv0_2 = (var_fv1 - (1 * gCameras[0].eye.y)) / (pad = var_fa1);
    } else {
        var_fv0_2 = (var_fv1 - (1 * sp8C)) / (gCameras[0].eye.y - sp8C);
    }
    if ((var_fv0_2 > 100000.0) || (var_fv0_2 < -10000.0)) {
        return;
    }

    D_800D6CA0.unk_28.pos.x = ((sp88 - gCameras[0].eye.x) * var_fv0_2) + gCameras[0].eye.x;
    D_800D6CA0.unk_28.pos.y = var_fv1;
    D_800D6CA0.unk_28.pos.z = ((sp90 - gCameras[0].eye.z) * var_fv0_2) + gCameras[0].eye.z;
    D_800D6CA0.unk_28.pos.x /= 0.3f;
    D_800D6CA0.unk_28.pos.y /= 0.3f;
    D_800D6CA0.unk_28.pos.z /= 0.3f;
    D_800D6CA0.unk_28.pos.x = (Math_Round(D_800D6CA0.unk_28.pos.x) / 10) * 10;
    D_800D6CA0.unk_28.pos.y = (Math_Round(D_800D6CA0.unk_28.pos.y) / 10) * 10;
    D_800D6CA0.unk_28.pos.z = (Math_Round(D_800D6CA0.unk_28.pos.z) / 10) * 10;
    D_800D6CA0.unk_28.radiusLeft = radiusLeft;
    D_800D6CA0.unk_28.radiusRight = radiusRight;

    if ((D_802CB6D0.controlPointCount == 1) && (D_802CB6D0.segments[0].trackSegmentInfo == 0x18000000) &&
        (D_800D6CA0.unk_28.trackSegmentInfo == 0x18000000)) {
        D_800D6CA0.unk_28.trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2);
    } else if (D_802CB6D0.controlPointCount == 0) {
        D_800D6CA0.unk_28.trackSegmentInfo =
            (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_START_LINE);
    }
}
