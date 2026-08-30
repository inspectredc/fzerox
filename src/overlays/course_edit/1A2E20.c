#include "global.h"
#include "fzx_camera.h"
#include "fzx_course.h"

f32 D_xk2_80128D40;
f32 D_xk2_80128D44;
s32 sCourseEditCameraPitchBackup;
s32 sCourseEditCourseYawBackup;
s32 sCourseEditCameraZoomBackup;
s32 sCourseEditCameraAtXBackup;
s32 sCourseEditCameraAtYBackup;
s32 sCourseEditCameraAtZBackup;
f32 sCourseEditCameraForwardX;
f32 sCourseEditCameraForwardY;
f32 sCourseEditCameraForwardZ;
s32 gCourseEditNewSegmentBankAngle;

s32 gCourseEditCameraPitch = 90;
s32 gCourseEditCameraZoom = 15000;
s32 gCourseEditCameraAtX = 0;
s32 gCourseEditCameraAtY = 0;
s32 gCourseEditCameraAtZ = 0;

extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F1360(void) {
    sCourseEditCameraPitchBackup = gCourseEditCameraPitch;
    sCourseEditCourseYawBackup = D_800D6CA0.courseYaw;
    sCourseEditCameraZoomBackup = gCourseEditCameraZoom;
    sCourseEditCameraAtXBackup = gCourseEditCameraAtX;
    sCourseEditCameraAtYBackup = gCourseEditCameraAtY;
    sCourseEditCameraAtZBackup = gCourseEditCameraAtZ;
}

void func_xk2_800F13C4(void) {
    gCourseEditCameraPitch = sCourseEditCameraPitchBackup;
    D_800D6CA0.courseYaw = sCourseEditCourseYawBackup;
    gCourseEditCameraZoom = sCourseEditCameraZoomBackup;
    gCourseEditCameraAtX = sCourseEditCameraAtXBackup;
    gCourseEditCameraAtY = sCourseEditCameraAtYBackup;
    gCourseEditCameraAtZ = sCourseEditCameraAtZBackup;
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

// Calculates new segment information
void func_xk2_800F1938(void) {
    CourseSegment* selectedSegment;
    Vec3f rayEnd;
    f64 xCursorOffset;
    f64 yCursorOffset;
    s32 pad;
    f32 radiusLeft;
    f32 radiusRight;
    f32 rayYDistance;
    f64 yPos;
    s32 bankAngleDiff;
    s32 prevBankAngle;
    s32 nextBankAngle;
    f64 rayIntersectionDistance;
    f64 temp_dfv0;
    f64 temp_dfv1;
    s32 pad2;

    if (gCourseEditCursorYPos < 0x38) {
        return;
    }
    temp_dfv0 = gCameras[0].fov;
    temp_dfv1 = (gCameras[0].fov * SCREEN_WIDTH) / SCREEN_HEIGHT;
    temp_dfv1 = ((gCourseEditCursorXPos - (SCREEN_WIDTH / 2)) / SCREEN_WIDTH_D) * temp_dfv1;
    temp_dfv0 = ((gCourseEditCursorYPos - (SCREEN_HEIGHT / 2)) / SCREEN_HEIGHT_D) * temp_dfv0;

    temp_dfv1 = DEG_TO_FZXANG4(temp_dfv1);
    temp_dfv0 = DEG_TO_FZXANG4(temp_dfv0);

    xCursorOffset = ((10000.0f * SIN((s32) temp_dfv1)) / COS((s32) temp_dfv1));
    yCursorOffset = ((10000.0f * SIN((s32) temp_dfv0)) / COS((s32) temp_dfv0));

    rayEnd.x = gCameras[0].eye.x + (gCameras[0].basis.x.x * 10000.0f);
    rayEnd.y = gCameras[0].eye.y + (gCameras[0].basis.x.y * 10000.0f);
    rayEnd.z = gCameras[0].eye.z + (gCameras[0].basis.x.z * 10000.0f);

    rayEnd.x = (rayEnd.x - (yCursorOffset * gCameras[0].basis.y.x)) - (xCursorOffset * gCameras[0].basis.z.x);
    rayEnd.y = (rayEnd.y - (yCursorOffset * gCameras[0].basis.y.y)) - (xCursorOffset * gCameras[0].basis.z.y);
    rayEnd.z = (rayEnd.z - (yCursorOffset * gCameras[0].basis.y.z)) - (xCursorOffset * gCameras[0].basis.z.z);

    rayYDistance = ABS(rayEnd.y - gCameras[0].eye.y);
    if (rayYDistance < 10.0f) {
        return;
    }
    if (D_802CB6D0.controlPointCount != 0) {
        selectedSegment = &D_802CB6D0.segments[D_800D6CA0.selectedControlPoint];
        if (gCourseEditCameraPitch < 0) {
            yPos = ((selectedSegment->pos.y + selectedSegment->next->pos.y) * 0.3f) / 2;
        } else {
            yPos = ((selectedSegment->pos.y + selectedSegment->next->pos.y) * 0.3f) / 2;
            if (gCameras[0].eye.y < yPos) {
                yPos = gCameras[0].eye.y - 256.0f;
                if (yPos < 0.0) {
                    yPos = 0.0;
                }
            }
        }
        radiusLeft = (selectedSegment->radiusLeft + selectedSegment->next->radiusLeft) / 2;
        radiusRight = (selectedSegment->radiusRight + selectedSegment->next->radiusRight) / 2;
        prevBankAngle = COURSE_CONTEXT()->courseData.bankAngle[selectedSegment->segmentIndex];
        nextBankAngle = COURSE_CONTEXT()->courseData.bankAngle[selectedSegment->next->segmentIndex];
        bankAngleDiff = nextBankAngle - prevBankAngle;

        if (ABS(bankAngleDiff) < 180) {
            gCourseEditNewSegmentBankAngle = (s32) (prevBankAngle + nextBankAngle) / 2;
        } else {
            gCourseEditNewSegmentBankAngle = (s32) (nextBankAngle + prevBankAngle + 360) / 2;
            gCourseEditNewSegmentBankAngle %= 360;
        }
    } else {
        gCourseEditNewSegmentBankAngle = 0;
        yPos = 0.0;
        radiusLeft = 260.0f;
        radiusRight = 260.0f;
    }
    if (gCameras[0].eye.y != 0.0f) {
        rayIntersectionDistance = (yPos - (1 * gCameras[0].eye.y)) / (rayEnd.y - gCameras[0].eye.y);
    } else {
        rayIntersectionDistance = (yPos - (1 * rayEnd.y)) / (gCameras[0].eye.y - rayEnd.y);
    }
    if ((rayIntersectionDistance > 100000.0) || (rayIntersectionDistance < -10000.0)) {
        return;
    }

    D_800D6CA0.newSegment.pos.x = ((rayEnd.x - gCameras[0].eye.x) * rayIntersectionDistance) + gCameras[0].eye.x;
    D_800D6CA0.newSegment.pos.y = yPos;
    D_800D6CA0.newSegment.pos.z = ((rayEnd.z - gCameras[0].eye.z) * rayIntersectionDistance) + gCameras[0].eye.z;
    D_800D6CA0.newSegment.pos.x /= 0.3f;
    D_800D6CA0.newSegment.pos.y /= 0.3f;
    D_800D6CA0.newSegment.pos.z /= 0.3f;
    D_800D6CA0.newSegment.pos.x = (Math_Round(D_800D6CA0.newSegment.pos.x) / 10) * 10;
    D_800D6CA0.newSegment.pos.y = (Math_Round(D_800D6CA0.newSegment.pos.y) / 10) * 10;
    D_800D6CA0.newSegment.pos.z = (Math_Round(D_800D6CA0.newSegment.pos.z) / 10) * 10;
    D_800D6CA0.newSegment.radiusLeft = radiusLeft;
    D_800D6CA0.newSegment.radiusRight = radiusRight;

    if ((D_802CB6D0.controlPointCount == 1) && (D_802CB6D0.segments[0].trackSegmentInfo == (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000)) &&
        (D_800D6CA0.newSegment.trackSegmentInfo == (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000))) {
        D_800D6CA0.newSegment.trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2);
    } else if (D_802CB6D0.controlPointCount == 0) {
        D_800D6CA0.newSegment.trackSegmentInfo =
            (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_START_LINE);
    }
}
