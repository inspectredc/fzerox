#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_camera.h"
#include "fzx_course.h"
#include "fzx_save.h"
#include "src/overlays/ending/ending.h"
#include ASSET_HEADER(course_track_gfx.h)
#define ENDING_CHARACTER_FIREWORKS (1 << 0)
#define ENDING_SHOW_PODIUM_SEQUENCE (1 << 1)
#define ENDING_DRAW_CONGRATULATIONS (1 << 2)
#define ENDING_SIDE_VIEW_FIREWORKS (1 << 3)
#define ENDING_FOLLOW_WITH_CREDITS (1 << 4)
#define ENDING_SHOW_END_SCREEN (1 << 5)
#define ENDING_NOT_ON_PODIUM (1 << 6)

Camera gCameras[4];
CameraSettings sCameraSettings[4];
CameraScriptManager sCameraScriptMgrs[4];
SplineControlPointTimers sSplineControlPointTimers[4];
s32 sNumCameras;
s32 sEndingCameraMessage;
s16 sCameraEndingFocusRacer;
s16 sCameraInfoInitialized;
s16 D_800E5E8C;
Vec3f sFinishedSuccessFollowRacerEye[4];

const CameraAtEyeData kDefaultAtEyeData = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f },
};

const CameraOrbitData D_800D4CF8 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f },
      { { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
      0.0f,
      0.0f,
      1.0f,
      0.0f,
      0.0f,
      1.0f,
      0.0f,
      0.0f,
      1.0f },
};

UNUSED const CameraFollowSmoothData D_800D4DA4 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      120.0f,
      120.0f,
      1.0f,
      35.0f,
      35.0f,
      1.0f,
      0.0f,
      0.0f,
      1.0f,
      0.0f,
      300.0f,
      0 },
};

const CameraLocalAnchorData kDefaultLocalAnchorData = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f },
      { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      1.0f,
      1.0f },
};

const CameraOrbitData D_800D4F58 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f },
      { { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
      400.0f,
      400.0f,
      1.0f,
      40.0f,
      40.0f,
      1.0f,
      50.0f,
      50.0f,
      1.0f },
};

const CameraOrbitData D_800D5004 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f },
      { { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
      1500.0f,
      1500.0f,
      1.0f,
      35.0f,
      35.0f,
      1.0f,
      50.0f,
      50.0f,
      1.0f },
};

const CameraOrbitData D_800D50B0 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f },
      { { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
      10500.0f,
      10500.0f,
      1.0f,
      20.0f,
      20.0f,
      1.0f,
      0.0f,
      0.0f,
      1.0f },
};

const CameraAtEyeData D_800D515C = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 4000.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      0.0f,
      30.0f,
      30.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f },
};

UNUSED const CameraAtEyeData D_800D51D4 = {
    { { 0.0f, 50.0f, 0.0f },
      { 0.0f, 150.0f, 500.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      0.0f,
      75.0f,
      75.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f },
};

const CameraOrbitData D_800D524C = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      75.0f,
      75.0f,
      1.0f,
      0.0f,
      77.0f,
      0.0f,
      77.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f },
      { { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f } },
      1000.0f,
      1000.0f,
      1.0f,
      35.0f,
      35.0f,
      1.0f,
      180.0f,
      180.0f,
      1.0f },
};

const CameraRaceSettingInfo kRegularCameraRaceSettings[] = {
    { 80.0f, 400.0f, 50.0f },  // CAMERA_RACE_SETTING_OVERHEAD
    { 75.0f, 90.0f, 25.0f },   // CAMERA_RACE_SETTING_CLOSE_BEHIND
    { 75.0f, 120.0f, 35.0f },  // CAMERA_RACE_SETTING_REGULAR
    { 100.0f, 120.0f, 50.0f }, // CAMERA_RACE_SETTING_WIDE
};

const CameraRaceSettingInfo kWidescreenCameraRaceSettings[] = {
    { 100.0f, 400.0f, 50.0f }, // CAMERA_RACE_SETTING_OVERHEAD
    { 90.0f, 100.0f, 25.0f },  // CAMERA_RACE_SETTING_CLOSE_BEHIND
    { 100.0f, 120.0f, 35.0f }, // CAMERA_RACE_SETTING_REGULAR
    { 110.0f, 125.0f, 40.0f }, // CAMERA_RACE_SETTING_WIDE
};

const CameraFollowSmoothData D_800D5358 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 400.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      80.0f,
      80.0f,
      0.2f,
      0.0f,
      77.0f,
      0.0f,
      77.0f,
      0.1f,
      0.2f },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      400.0f,
      400.0f,
      0.2f,
      50.0f,
      50.0f,
      0.2f,
      0.0f,
      0.0f,
      1.0f,
      0.0f,
      300.0f,
      0 },
};

const CameraFollowSmoothData D_800D544C = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 400.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      100.0f,
      100.0f,
      0.2f,
      0.0f,
      -15.0f,
      0.0f,
      -15.0f,
      0.1f,
      0.2f },
    { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      400.0f,
      400.0f,
      0.2f,
      50.0f,
      50.0f,
      0.2f,
      0.0f,
      0.0f,
      1.0f,
      0.0f,
      300.0f,
      0 },
};

s32 sMultiplayerFocusCameraId = -1;
bool sAllowCameraLookBack = true;
#ifndef EXPANSION_KIT
f32 D_800CD8A8 = 5.0f;
f32 D_800CD8AC = 5.0f;
#endif

EyeFromRacerInfo sEyeFromRacerInfo0 = {
    2000.0f,
    0.0f,
    25.0f,
};

EyeFromRacerInfo sEyeFromRacerInfo4 = {
    4000.0f,
    -0.9f,
    50.0f,
};

LerpLocalAtEyeInfo sLerpLocalAtEyeInfo1 = {
    { -7.0f, 0.0f, 63.0f }, { -7.0f, 0.0f, 63.0f }, { 26.0f, 20.0f, -65.0f }, { 26.0f, 20.0f, -65.0f }, 0.0f, 0.0f
};

LerpLocalAtEyeInfo sLerpLocalAtEyeInfo2 = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { -50.0f, 40.0f, 40.0f }, { -50.0f, 40.0f, -40.0f }, 0.0f, 1.0f
};

LerpLocalAtEyeInfo sLerpLocalAtEyeInfo3 = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { -40.0f, 30.0f, 104.0f }, { 40.0f, 30.0f, 104.0f }, 0.0f, 1.0f
};

FinishedSuccessScript gFinishedSuccessScript[] = {
    { FINISHED_SUCCESS_FIXED_FOLLOW_RACER, 88, 60.0f, &sEyeFromRacerInfo0 },
    { FINISHED_SUCCESS_LERP_LOCAL_AT_EYE, 23, 60.0f, &sLerpLocalAtEyeInfo1 },
    { FINISHED_SUCCESS_LERP_LOCAL_AT_EYE, 23, 60.0f, &sLerpLocalAtEyeInfo2 },
    { FINISHED_SUCCESS_LERP_LOCAL_AT_EYE, 23, 80.0f, &sLerpLocalAtEyeInfo3 },
    { FINISHED_SUCCESS_FIXED_FOLLOW_RACER, 284, 60.0f, &sEyeFromRacerInfo4 },
};

const s32 kSingleCameraScissorBoxTypes[] = { SCISSOR_BOX_FULL_SCREEN };

const s32 kTwoCameraScissorBoxTypes[] = { SCISSOR_BOX_TOP_HALF, SCISSOR_BOX_BOTTOM_HALF };

const s32 kThreeCameraScissorBoxTypes[] = { SCISSOR_BOX_TOP_LEFT_QUARTER, SCISSOR_BOX_BOTTOM_LEFT_QUARTER,
                                            SCISSOR_BOX_TOP_RIGHT_QUARTER };

const s32 kFourCameraScissorBoxTypes[] = { SCISSOR_BOX_TOP_LEFT_QUARTER, SCISSOR_BOX_BOTTOM_LEFT_QUARTER,
                                           SCISSOR_BOX_TOP_RIGHT_QUARTER, SCISSOR_BOX_BOTTOM_RIGHT_QUARTER };

const s32* sCameraScissorBoxTypes[] = {
    NULL,
    kSingleCameraScissorBoxTypes,
    kTwoCameraScissorBoxTypes,
    kThreeCameraScissorBoxTypes,
    kFourCameraScissorBoxTypes,
};

ScissorBox gScissorBoxFullScreen = { 12, 8, 308, 232 };
ScissorBox gScissorBoxTopHalf = { 12, 8, 307, 119 };
ScissorBox gScissorBoxBottomHalf = { 12, 120, 307, 231 };
ScissorBox gScissorBoxLeftHalf = { 12, 8, 159, 231 };
ScissorBox gScissorBoxRightHalf = { 160, 8, 307, 231 };
ScissorBox gScissorBoxTopLeftQuarter = { 12, 8, 159, 119 };
ScissorBox gScissorBoxTopRightQuarter = { 160, 8, 307, 119 };
ScissorBox gScissorBoxBottomLeftQuarter = { 12, 120, 159, 231 };
ScissorBox gScissorBoxBottomRightQuarter = { 160, 120, 307, 231 };
ScissorBox gScissorBoxTopCenterQuarter = { 86, 8, 233, 119 };
ScissorBox gScissorBoxBottomCenterQuarter = { 86, 120, 233, 231 };
ScissorBox gScissorBoxLeftCenterQuarter = { 12, 64, 159, 175 };
ScissorBox gScissorBoxRightCenterQuarter = { 160, 64, 307, 175 };

f32 D_800CDA90 = 550.0f / 21.6f;
f32 D_800CDA94 = 1000.0f / 21.6f;
f32 D_800CDA98 = 120.0f;
s32 sMaxCameraLookBackRotate = 8;

void Camera_SettingsSetAtEye(CameraSettings* cameraSettings, CameraTypeAtEye* atEye) {
    cameraSettings->type = CAMERA_TYPE_AT_EYE;
    cameraSettings->atEye = *atEye;
}

void Camera_SettingsSetAtEyeWithParameters(CameraSettings* cameraSettings, CameraAtEyeData* atEyeData) {
    cameraSettings->type = CAMERA_TYPE_AT_EYE;
    cameraSettings->parameters = atEyeData->parameters;
    cameraSettings->atEye = atEyeData->data;
}

void Camera_SettingsSetFollowSmooth(CameraSettings* cameraSettings, CameraTypeFollowSmooth* followSmooth) {
    cameraSettings->type = CAMERA_TYPE_FOLLOW_SMOOTH;
    cameraSettings->followSmooth = *followSmooth;
}

void Camera_SettingsSetFollowSmoothWithParameters(CameraSettings* cameraSettings,
                                                  CameraFollowSmoothData* followSmoothData) {
    cameraSettings->type = CAMERA_TYPE_FOLLOW_SMOOTH;
    cameraSettings->parameters = followSmoothData->parameters;
    cameraSettings->followSmooth = followSmoothData->data;
}

void Camera_SettingsSetOrbit(CameraSettings* cameraSettings, s32 type, CameraTypeOrbit* orbit) {
    cameraSettings->type = type;
    cameraSettings->orbit = *orbit;
}

void Camera_SettingsSetOrbitWithParameters(CameraSettings* cameraSettings, s32 type, CameraOrbitData* orbitData) {
    cameraSettings->type = type;
    cameraSettings->parameters = orbitData->parameters;
    cameraSettings->orbit = orbitData->data;
}

void Camera_SettingsSetLocalAnchor(CameraSettings* cameraSettings, CameraTypeLocalAnchor* localAnchor) {
    cameraSettings->type = CAMERA_TYPE_LOCAL_ANCHOR;
    cameraSettings->localAnchor = *localAnchor;
}

void Camera_SettingsSetLocalAnchorWithParameters(CameraSettings* cameraSettings,
                                                 CameraLocalAnchorData* localAnchorData) {
    cameraSettings->type = CAMERA_TYPE_LOCAL_ANCHOR;
    cameraSettings->parameters = localAnchorData->parameters;
    cameraSettings->localAnchor = localAnchorData->data;
}

void Camera_SettingsUpdateCommon(CameraSettings* cameraSettings) {
    CameraParameters* params = &cameraSettings->parameters;

    params->up.x += (params->targetUp.x - params->up.x) * params->upLerpFactor;
    params->up.y += (params->targetUp.y - params->up.y) * params->upLerpFactor;
    params->up.z += (params->targetUp.z - params->up.z) * params->upLerpFactor;
    params->fov += (params->targetFov - params->fov) * params->fovLerpFactor;
    params->frustrumCenterX +=
        (params->targetFrustrumCenterX - params->frustrumCenterX) * params->frustrumCenterXLerpFactor;
    params->frustrumCenterY +=
        (params->targetFrustrumCenterY - params->frustrumCenterY) * params->frustrumCenterYLerpFactor;
}

void Camera_SettingsUpdateAtEye(CameraSettings* cameraSettings) {
    CameraTypeAtEye* atEye = &cameraSettings->atEye;
    CameraParameters* params = &cameraSettings->parameters;

    params->at.x += (atEye->targetAt.x - params->at.x) * atEye->atLerpFactor;
    params->at.y += (atEye->targetAt.y - params->at.y) * atEye->atLerpFactor;
    params->at.z += (atEye->targetAt.z - params->at.z) * atEye->atLerpFactor;
    params->eye.x += (atEye->targetEye.x - params->eye.x) * atEye->eyeLerpFactor;
    params->eye.y += (atEye->targetEye.y - params->eye.y) * atEye->eyeLerpFactor;
    params->eye.z += (atEye->targetEye.z - params->eye.z) * atEye->eyeLerpFactor;
}

void Camera_SettingsUpdateOrbit(CameraSettings* cameraSettings) {
    s32 angle;
    f32 sp40;
    f32 sp3C;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 xOffset;
    f32 yOffset;
    f32 zOffset;
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;

    orbit->distance += (orbit->targetDistance - orbit->distance) * orbit->distanceLerpFactor;
    orbit->pitch += (orbit->targetPitch - orbit->pitch) * orbit->pitchLerpFactor;
    orbit->yaw += (orbit->targetYaw - orbit->yaw) * orbit->yawLerpFactor;

    angle = Math_Round(DEG_TO_FZXANG2(orbit->pitch));

    sp3C = orbit->distance * SIN(angle);
    sp40 = orbit->distance * COS(angle);

    angle = Math_Round(DEG_TO_FZXANG2(orbit->yaw));
    temp_fv0 = SIN(angle) * sp40;
    temp_fv1 = COS(angle) * sp40;

    xOffset = (orbit->basis.x.x * temp_fv1) + (orbit->basis.z.x * temp_fv0) + (orbit->basis.y.x * sp3C);
    yOffset = (orbit->basis.x.y * temp_fv1) + (orbit->basis.z.y * temp_fv0) + (orbit->basis.y.y * sp3C);
    zOffset = (orbit->basis.x.z * temp_fv1) + (orbit->basis.z.z * temp_fv0) + (orbit->basis.y.z * sp3C);

    switch (cameraSettings->type) {
        case CAMERA_TYPE_ORBIT_AT:
            params->at = orbit->anchorPos;
            params->eye.x = orbit->anchorPos.x + xOffset;
            params->eye.y = orbit->anchorPos.y + yOffset;
            params->eye.z = orbit->anchorPos.z + zOffset;
            break;
        case CAMERA_TYPE_ORBIT_EYE:
            params->eye = orbit->anchorPos;
            params->at.x = orbit->anchorPos.x + xOffset;
            params->at.y = orbit->anchorPos.y + yOffset;
            params->at.z = orbit->anchorPos.z + zOffset;
            break;
    }
}

extern s32 gNumPlayers;
extern s8 gGamePaused;

void Camera_SettingsUpdateFollowSmooth(CameraSettings* cameraSettings, Camera* camera) {
    s32 angle;
    f32 var_fv1;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    Racer* racer = &gRacers[camera->id];
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_fv0;
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;

    followSmooth->distance +=
        (followSmooth->targetDistance - followSmooth->distance) * followSmooth->distanceLerpFactor;
    followSmooth->pitch += (followSmooth->targetPitch - followSmooth->pitch) * followSmooth->pitchLerpFactor;
    followSmooth->yaw += (followSmooth->targetYaw - followSmooth->yaw) * followSmooth->yawLerpFactor;

    camera->focusPos.x = racer->focusPos.x;
    camera->focusPos.y = racer->focusPos.y;
    camera->focusPos.z = racer->focusPos.z;

    var_fv1 = (racer->focusVelocity.x * racer->gravityUp.x) + (racer->focusVelocity.y * racer->gravityUp.y) +
              (racer->focusVelocity.z * racer->gravityUp.z);
    sp98.x = (followSmooth->anchorPoint.x - camera->focusPos.x) + (var_fv1 * racer->gravityUp.x);
    sp98.y = (followSmooth->anchorPoint.y - camera->focusPos.y) + (var_fv1 * racer->gravityUp.y);
    sp98.z = (followSmooth->anchorPoint.z - camera->focusPos.z) + (var_fv1 * racer->gravityUp.z);
    var_fv1 = sqrtf(SQ(sp98.x) + SQ(sp98.y) + SQ(sp98.z));

    if (var_fv1 < 0.01f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp98.x *= var_fv1;
    sp98.y *= var_fv1;
    sp98.z *= var_fv1;
    if (!gGamePaused) {
        temp_fv0 = followSmooth->distance;
        followSmooth->anchorPoint.x = camera->focusPos.x + (temp_fv0 * sp98.x);
        followSmooth->anchorPoint.y = camera->focusPos.y + (temp_fv0 * sp98.y);
        followSmooth->anchorPoint.z = camera->focusPos.z + (temp_fv0 * sp98.z);
    }

    temp_fv0 = (racer->focusVelocity.x * camera->basis.y.x) + (racer->focusVelocity.y * camera->basis.y.y) +
               (racer->focusVelocity.z * camera->basis.y.z);
    if (followSmooth->targetYaw >= 50.0f) {
        var_fv1 = 0.0f;
    } else {
        var_fv1 = (50.0f - followSmooth->targetYaw) * 0.02f;
    }

    params->at.x = camera->focusPos.x + (var_fv1 * (racer->focusVelocity.x - (temp_fv0 * camera->basis.y.x)));
    params->at.y = camera->focusPos.y + (var_fv1 * (racer->focusVelocity.y - (temp_fv0 * camera->basis.y.y)));
    params->at.z = camera->focusPos.z + (var_fv1 * (racer->focusVelocity.z - (temp_fv0 * camera->basis.y.z)));
    sp8C.x = racer->gravityUp.x - camera->racerBasis.y.x;
    sp8C.y = racer->gravityUp.y - camera->racerBasis.y.y;
    sp8C.z = racer->gravityUp.z - camera->racerBasis.y.z;

    var_fv1 = sqrtf(SQ(sp8C.x) + SQ(sp8C.y) + SQ(sp8C.z)) * 0.2f;

    followSmooth->basis.y.x = camera->racerBasis.y.x += var_fv1 * sp8C.x;
    followSmooth->basis.y.y = camera->racerBasis.y.y += var_fv1 * sp8C.y;
    followSmooth->basis.y.z = camera->racerBasis.y.z += var_fv1 * sp8C.z;

    sp7C.x = (followSmooth->basis.y.y * sp98.z) - (followSmooth->basis.y.z * sp98.y);
    sp7C.y = (followSmooth->basis.y.z * sp98.x) - (followSmooth->basis.y.x * sp98.z);
    sp7C.z = (followSmooth->basis.y.x * sp98.y) - (followSmooth->basis.y.y * sp98.x);
    var_fv1 = sqrtf(SQ(sp7C.x) + SQ(sp7C.y) + SQ(sp7C.z));
    if (var_fv1 < 0.1f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp7C.x *= var_fv1;
    sp7C.y *= var_fv1;
    sp7C.z *= var_fv1;

    sp70.x = (sp98.y * sp7C.z) - (sp98.z * sp7C.y);
    sp70.y = (sp98.z * sp7C.x) - (sp98.x * sp7C.z);
    sp70.z = (sp98.x * sp7C.y) - (sp98.y * sp7C.x);

    var_fv1 = 1.0f / sqrtf(SQ(sp70.x) + SQ(sp70.y) + SQ(sp70.z));

    sp70.x *= var_fv1;
    sp70.y *= var_fv1;
    sp70.z *= var_fv1;
    angle = Math_Round(DEG_TO_FZXANG2(followSmooth->pitch));

    var_fv1 = followSmooth->distance * SIN(angle) *
              ((sp70.x * racer->trueBasis.y.x) + (sp70.y * racer->trueBasis.y.y) + (sp70.z * racer->trueBasis.y.z));
    spA4 = followSmooth->distance * COS(angle);

    angle = Math_Round(DEG_TO_FZXANG2(followSmooth->targetYaw));
    temp_fv0 = COS(angle) * spA4;
    spA4 = SIN(angle) * spA4;
    params->eye.x = camera->focusPos.x + (spA4 * sp7C.x) + (temp_fv0 * sp98.x) + (var_fv1 * sp70.x);
    params->eye.y = camera->focusPos.y + (spA4 * sp7C.y) + (temp_fv0 * sp98.y) + (var_fv1 * sp70.y);
    params->eye.z = camera->focusPos.z + (spA4 * sp7C.z) + (temp_fv0 * sp98.z) + (var_fv1 * sp70.z);
    followSmooth->basis.x.x = params->at.x - params->eye.x;
    followSmooth->basis.x.y = params->at.y - params->eye.y;
    followSmooth->basis.x.z = params->at.z - params->eye.z;
    Math_OrthonormalizeAroundForward(&followSmooth->basis);
    if (!gGamePaused) {
        params->targetUp.x = params->up.x = followSmooth->basis.y.x;
        params->targetUp.y = params->up.y = followSmooth->basis.y.y;
        params->targetUp.z = params->up.z = followSmooth->basis.y.z;
    }
    params->frustrumCenterX = 0.0f;
    params->targetFrustrumCenterX = 0.0f;
    if (gNumPlayers == 2) {
        params->frustrumCenterY = -15.0f;
        params->targetFrustrumCenterY = -15.0f;
    } else {
        params->frustrumCenterY = 77.0f;
        params->targetFrustrumCenterY = 77.0f;
    }
}

void Camera_SettingsUpdateLocalAnchor(CameraSettings* cameraSettings) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;

    localAnchor->localAtCoordinates.x +=
        (localAnchor->targetLocalAt.x - localAnchor->localAtCoordinates.x) * localAnchor->localAtLerpFactor;
    localAnchor->localAtCoordinates.y +=
        (localAnchor->targetLocalAt.y - localAnchor->localAtCoordinates.y) * localAnchor->localAtLerpFactor;
    localAnchor->localAtCoordinates.z +=
        (localAnchor->targetLocalAt.z - localAnchor->localAtCoordinates.z) * localAnchor->localAtLerpFactor;

    localAnchor->localEyeCoordinates.x +=
        (localAnchor->targetLocalEye.x - localAnchor->localEyeCoordinates.x) * localAnchor->localEyeLerpFactor;
    localAnchor->localEyeCoordinates.y +=
        (localAnchor->targetLocalEye.y - localAnchor->localEyeCoordinates.y) * localAnchor->localEyeLerpFactor;
    localAnchor->localEyeCoordinates.z +=
        (localAnchor->targetLocalEye.z - localAnchor->localEyeCoordinates.z) * localAnchor->localEyeLerpFactor;

    params->at.x = localAnchor->anchorPoint.x + (localAnchor->basis.z.x * localAnchor->localAtCoordinates.x) +
                   (localAnchor->basis.y.x * localAnchor->localAtCoordinates.y) +
                   (localAnchor->basis.x.x * localAnchor->localAtCoordinates.z);
    params->at.y = localAnchor->anchorPoint.y + (localAnchor->basis.z.y * localAnchor->localAtCoordinates.x) +
                   (localAnchor->basis.y.y * localAnchor->localAtCoordinates.y) +
                   (localAnchor->basis.x.y * localAnchor->localAtCoordinates.z);
    params->at.z = localAnchor->anchorPoint.z + (localAnchor->basis.z.z * localAnchor->localAtCoordinates.x) +
                   (localAnchor->basis.y.z * localAnchor->localAtCoordinates.y) +
                   (localAnchor->basis.x.z * localAnchor->localAtCoordinates.z);

    params->eye.x = localAnchor->anchorPoint.x + (localAnchor->basis.z.x * localAnchor->localEyeCoordinates.x) +
                    (localAnchor->basis.y.x * localAnchor->localEyeCoordinates.y) +
                    (localAnchor->basis.x.x * localAnchor->localEyeCoordinates.z);
    params->eye.y = localAnchor->anchorPoint.y + (localAnchor->basis.z.y * localAnchor->localEyeCoordinates.x) +
                    (localAnchor->basis.y.y * localAnchor->localEyeCoordinates.y) +
                    (localAnchor->basis.x.y * localAnchor->localEyeCoordinates.z);
    params->eye.z = localAnchor->anchorPoint.z + (localAnchor->basis.z.z * localAnchor->localEyeCoordinates.x) +
                    (localAnchor->basis.y.z * localAnchor->localEyeCoordinates.y) +
                    (localAnchor->basis.x.z * localAnchor->localEyeCoordinates.z);
}

void Camera_SettingsUpdate(CameraSettings* cameraSettings, Camera* camera) {

    switch (cameraSettings->type) {
        case CAMERA_TYPE_AT_EYE:
            Camera_SettingsUpdateAtEye(cameraSettings);
            break;
        case CAMERA_TYPE_FOLLOW_SMOOTH:
            Camera_SettingsUpdateFollowSmooth(cameraSettings, camera);
            break;
        case CAMERA_TYPE_ORBIT_AT:
        case CAMERA_TYPE_ORBIT_EYE:
            Camera_SettingsUpdateOrbit(cameraSettings);
            break;
        case CAMERA_TYPE_LOCAL_ANCHOR:
            Camera_SettingsUpdateLocalAnchor(cameraSettings);
            break;
    }
    Camera_SettingsUpdateCommon(cameraSettings);
}

void Camera_ScriptUpdateAtEyeTargets(CameraSettings* cameraSettings, Vec3f* at, Vec3f* eye, Vec3f* up, f32* fov) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeAtEye* atEye = &cameraSettings->atEye;

    if (at != NULL) {
        atEye->targetAt.x = at->x;
        atEye->targetAt.y = at->y;
        atEye->targetAt.z = at->z;
    }
    if (eye != NULL) {
        atEye->targetEye.x = eye->x;
        atEye->targetEye.y = eye->y;
        atEye->targetEye.z = eye->z;
    }
    if (up != NULL) {
        params->targetUp.x = up->x;
        params->targetUp.y = up->y;
        params->targetUp.z = up->z;
    }
    if (fov != NULL) {
        params->targetFov = *fov;
    }
}

void Camera_ScriptUpdateOrbitTargets(CameraSettings* cameraSettings, Vec3f* anchorPos, Vec3f* distanceYawPitch,
                                     Vec3f* up, f32* fov) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;

    if (anchorPos != NULL) {
        orbit->anchorPos.x = anchorPos->x;
        orbit->anchorPos.y = anchorPos->y;
        orbit->anchorPos.z = anchorPos->z;
    }
    if (distanceYawPitch != NULL) {
        orbit->targetDistance = distanceYawPitch->v[0];
        orbit->targetYaw = distanceYawPitch->v[1];
        orbit->targetPitch = distanceYawPitch->v[2];
    }
    if (up != NULL) {
        params->targetUp.x = up->x;
        params->targetUp.y = up->y;
        params->targetUp.z = up->z;
    }
    if (fov != NULL) {
        params->targetFov = *fov;
    }
}

void Camera_ScriptUpdateLocalAnchorTargets(CameraSettings* cameraSettings, Vec3f* anchorPoint, Mtx3F* basis,
                                           Vec3f* localAt, Vec3f* localEye, Vec3f* up, f32* fov) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;

    if (anchorPoint != NULL) {
        localAnchor->anchorPoint.x = anchorPoint->x;
        localAnchor->anchorPoint.y = anchorPoint->y;
        localAnchor->anchorPoint.z = anchorPoint->z;
    }
    if (basis != NULL) {
        localAnchor->basis.x.x += basis->x.x * 0.2f;
        localAnchor->basis.x.y += basis->x.y * 0.2f;
        localAnchor->basis.x.z += basis->x.z * 0.2f;
        localAnchor->basis.y.x += basis->y.x * 0.2f;
        localAnchor->basis.y.y += basis->y.y * 0.2f;
        localAnchor->basis.y.z += basis->y.z * 0.2f;
        localAnchor->basis.z.x += basis->z.x * 0.2f;
        localAnchor->basis.z.y += basis->z.y * 0.2f;
        localAnchor->basis.z.z += basis->z.z * 0.2f;
        Math_OrthonormalizeAroundForward(&localAnchor->basis);
    }
    if (localAt != NULL) {
        localAnchor->targetLocalAt.x = localAt->x;
        localAnchor->targetLocalAt.y = localAt->y;
        localAnchor->targetLocalAt.z = localAt->z;
    }
    if (localEye != NULL) {
        localAnchor->targetLocalEye.x = localEye->x;
        localAnchor->targetLocalEye.y = localEye->y;
        localAnchor->targetLocalEye.z = localEye->z;
    }
    if (up != NULL) {
        params->targetUp.x = up->x;
        params->targetUp.y = up->y;
        params->targetUp.z = up->z;
    }
    if (fov != NULL) {
        params->targetFov = *fov;
    }
}

void Camera_ScriptUpdateFollowSmoothTargets(CameraSettings* cameraSettings, Vec3f* center, Vec3f* distanceYawPitch,
                                            Vec3f* up, f32* fov) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;

    if (center != NULL) {
        followSmooth->centerPos.x = center->x;
        followSmooth->centerPos.y = center->y;
        followSmooth->centerPos.z = center->z;
    }
    if (distanceYawPitch != NULL) {
        followSmooth->targetDistance = distanceYawPitch->v[0];
        followSmooth->targetYaw = distanceYawPitch->v[1];
        followSmooth->targetPitch = distanceYawPitch->v[2];
    }
    if (up != NULL) {
        params->targetUp.x = up->x;
        params->targetUp.y = up->y;
        params->targetUp.z = up->z;
    }
    if (fov != NULL) {
        params->targetFov = *fov;
    }
}

f32 Camera_AdvanceDistanceAlongSegment(CourseSegment** segment, f32 t, f32 distance) {
    f32 forwardMagnitude;
    s32 i;
    s32 steps;
    s32 pad[4];
    Vec3f tangent;
    Mtx3F basis;

    steps = (s32) distance / 20;
    forwardMagnitude = Course_SplineGetBasis(*segment, t, &basis, 0.0f);

    for (i = 0; i < steps; i++) {
        t += 20.0f / forwardMagnitude;
        if (t >= 1.0f) {
            *segment = (*segment)->next;
            t -= 1.0f;
            t *= forwardMagnitude / Course_SplineGetTangent(*segment, 0.0f, &tangent);
        }
    }

    t += (distance - (steps * 20.0f)) / forwardMagnitude;
    if (t >= 1.0f) {
        *segment = (*segment)->next;
        t -= 1.0f;
        t *= forwardMagnitude / Course_SplineGetTangent(*segment, 0.0f, &tangent);
    }
    return t;
}

Mtx3F* Camera_GetSegmentBasis(Mtx3F* basis, CourseSegment* segment, f32 t) {
    s32 pad;
    f32 lengthFromStart;
    Mtx3F segmentBasis;

    Course_SplineGetBasis(segment, t, &segmentBasis, Course_SplineGetLengthInfo(segment, t, &lengthFromStart));
    *basis = segmentBasis;

    return basis;
}

void Camera_RaceSettingChanged(Camera* camera, CameraParameters* params, CameraTypeFollowSmooth* followSmooth,
                               s32 numPlayers) {
    CameraRaceSettingInfo* raceSettingInfo;

    if (numPlayers == 2) {
        raceSettingInfo = &kWidescreenCameraRaceSettings[camera->raceSetting];
    } else {
        raceSettingInfo = &kRegularCameraRaceSettings[camera->raceSetting];
    }
    followSmooth->targetDistance = raceSettingInfo->distance;
    followSmooth->targetPitch = raceSettingInfo->pitch;
    params->targetFov = camera->targetFov = raceSettingInfo->fov;

    camera->fovFlags = CAMERA_FOV_FLAG_2;

    switch (camera->raceSetting) {
        case CAMERA_RACE_SETTING_CLOSE_BEHIND:
        case CAMERA_RACE_SETTING_REGULAR:
            camera->fovFlags |= CAMERA_FOV_FLAG_1;
            break;
        default:
            break;
    }
}

void Camera_UpdateFromSettings(Camera* camera, CameraSettings* cameraSettings) {

    camera->eye = cameraSettings->parameters.eye;
    camera->at = cameraSettings->parameters.at;

    camera->basis.y.x = cameraSettings->parameters.up.x;
    camera->basis.y.y = cameraSettings->parameters.up.y;
    camera->basis.y.z = cameraSettings->parameters.up.z;
    camera->fov = cameraSettings->parameters.fov;
    camera->frustrumCenterX = cameraSettings->parameters.frustrumCenterX;
    camera->frustrumCenterY = cameraSettings->parameters.frustrumCenterY;
}

void func_8071315C(Camera* camera) {
    f32 x;
    f32 z;
    f32 normalizingFactor;

    camera->basis.x.x = camera->at.x - camera->eye.x;
    camera->basis.x.y = camera->at.y - camera->eye.y;
    camera->basis.x.z = camera->at.z - camera->eye.z;

    Math_OrthonormalizeAroundForward(&camera->basis);
    x = camera->basis.x.x;
    z = camera->basis.x.z;
    normalizingFactor = sqrtf(SQ(x) + SQ(z));
    if (normalizingFactor != 0.0f) {
        camera->xzNormalizedX = camera->basis.x.x / normalizingFactor;
        camera->xzNormalizedZ = camera->basis.x.z / normalizingFactor;
    }
}

void Camera_CalculateProjectionViewMtx(MtxF* projectionViewMtx, MtxF* projectionMtx, MtxF* viewMtx) {
    projectionViewMtx->m[0][0] =
        (projectionMtx->m[0][0] * viewMtx->m[0][0]) + (projectionMtx->m[2][0] * viewMtx->m[0][2]);
    projectionViewMtx->m[0][1] =
        (projectionMtx->m[1][1] * viewMtx->m[0][1]) + (projectionMtx->m[2][1] * viewMtx->m[0][2]);
    projectionViewMtx->m[0][2] = projectionMtx->m[2][2] * viewMtx->m[0][2];
    projectionViewMtx->m[0][3] = -viewMtx->m[0][2];
    projectionViewMtx->m[1][0] =
        (projectionMtx->m[0][0] * viewMtx->m[1][0]) + (projectionMtx->m[2][0] * viewMtx->m[1][2]);
    projectionViewMtx->m[1][1] =
        (projectionMtx->m[1][1] * viewMtx->m[1][1]) + (projectionMtx->m[2][1] * viewMtx->m[1][2]);
    projectionViewMtx->m[1][2] = projectionMtx->m[2][2] * viewMtx->m[1][2];
    projectionViewMtx->m[1][3] = -viewMtx->m[1][2];
    projectionViewMtx->m[2][0] =
        (projectionMtx->m[0][0] * viewMtx->m[2][0]) + (projectionMtx->m[2][0] * viewMtx->m[2][2]);
    projectionViewMtx->m[2][1] =
        (projectionMtx->m[1][1] * viewMtx->m[2][1]) + (projectionMtx->m[2][1] * viewMtx->m[2][2]);
    projectionViewMtx->m[2][2] = projectionMtx->m[2][2] * viewMtx->m[2][2];
    projectionViewMtx->m[2][3] = -viewMtx->m[2][2];
    projectionViewMtx->m[3][0] =
        (projectionMtx->m[0][0] * viewMtx->m[3][0]) + (projectionMtx->m[2][0] * viewMtx->m[3][2]);
    projectionViewMtx->m[3][1] =
        (projectionMtx->m[1][1] * viewMtx->m[3][1]) + (projectionMtx->m[2][1] * viewMtx->m[3][2]);
    projectionViewMtx->m[3][2] = (projectionMtx->m[2][2] * viewMtx->m[3][2]) + projectionMtx->m[3][2];
    projectionViewMtx->m[3][3] = -viewMtx->m[3][2];
}

void Camera_MatrixToMtx(MtxF* mtxF, Mtx* mtx2) {
    s32 pad[3];
    s64 longValue;
    f32 temp_fv0;
    s32 i;
    s32 j;
    Mtx* mtx = mtx2;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            temp_fv0 = mtxF->m[i][j] * 65536.0f;
            if (temp_fv0 < 0.0f) {
                longValue = temp_fv0 - 0.5f;
            } else {
                longValue = temp_fv0 + 0.5f;
            }

            mtx->u.i[i][j] = longValue >> 0x10;
            mtx->u.f[i][j] = longValue & 0xFFFF;
        }
    }
}

extern s32 D_800CCFB0;

void Camera_UpdateProjectionViewMtx(GfxPool* gfxPool, Camera* camera) {
    Vec3f at;
    Vec3f eye;
    f32 var_fv0;
    f32 var_fv1;

    Matrix_SetFrustrum(&gfxPool->unk_20008[camera->id], &camera->projectionMtx, camera->fov, camera->near, camera->far,
                       camera->fovScaleX, camera->frustrumCenterX, camera->fovScaleY, camera->frustrumCenterY,
                       &camera->perspectiveScale);

#ifndef EXPANSION_KIT
    if (D_800E5E8C != 0) {
        var_fv0 = D_800CD8AC;
        var_fv1 = D_800CD8A8;
        if (D_800CCFB0 & 1) {
            var_fv0 = 0.0f - var_fv0;
            var_fv1 = 0.0f - var_fv1;
        }
        eye.x = camera->eye.x + (camera->basis.z.x * var_fv0);
        eye.y = camera->eye.y + (camera->basis.z.y * var_fv0);
        eye.z = camera->eye.z + (camera->basis.z.z * var_fv0);
        at.x = camera->at.x + (camera->basis.z.x * var_fv1);
        at.y = camera->at.y + (camera->basis.z.y * var_fv1);
        at.z = camera->at.z + (camera->basis.z.z * var_fv1);
    } else {
        eye = camera->eye;
        at = camera->at;
    }

    Matrix_SetLookAt(&gfxPool->unk_20108[camera->id], &camera->viewMtx, eye.x, eye.y, eye.z, at.x, at.y, at.z,
                     camera->basis.y.x, camera->basis.y.y, camera->basis.y.z);

    Camera_CalculateProjectionViewMtx(&camera->projectionViewMtx, &camera->projectionMtx, &camera->viewMtx);
#else
    eye = camera->eye;
    at = camera->at;

    Matrix_SetLookAt(&gfxPool->unk_20108[camera->id], &camera->viewMtx, eye.x, eye.y, eye.z, at.x, at.y, at.z,
                     camera->basis.y.x, camera->basis.y.y, camera->basis.y.z);
    Camera_CalculateProjectionViewMtx(&camera->projectionViewMtx, &camera->projectionMtx, &camera->viewMtx);
    if (gNumPlayers != 2) {
        f32 var_fv0;
        f32 fov;

        var_fv0 = ABS(camera->projectionViewMtx.m[3][1]);

        if (var_fv0 > 30000.0f) {
            var_fv0 -= 30000.0f;
            var_fv0 /= SHT_MAX - 30000.0f;
            if (var_fv0 >= 1.0f) {
                var_fv0 = 1.0f;
            }
            fov = camera->fov + ((85.0f - camera->fov) * var_fv0);

            Matrix_SetFrustrum(&gfxPool->unk_20008[camera->id], &camera->projectionMtx, fov, camera->near, camera->far,
                               camera->fovScaleX, camera->frustrumCenterX, camera->fovScaleY, camera->frustrumCenterY,
                               &camera->perspectiveScale);
            Camera_CalculateProjectionViewMtx(&camera->projectionViewMtx, &camera->projectionMtx, &camera->viewMtx);
        }
    }
#endif

    Camera_MatrixToMtx(&camera->projectionViewMtx, &gfxPool->unk_20208[camera->id]);
}

extern s32 gNearestRacer;

void Camera_UpdateEnemyEnginePan(Camera* camera) {
    Racer* racer;
    f32 var_fv1;
    f32 var_fa0;
    f32 x;
    f32 y;
    f32 z;

    racer = &gRacers[gNearestRacer];
    x = racer->segmentPositionInfo.pos.x - camera->eye.x;
    y = racer->segmentPositionInfo.pos.y - camera->eye.y;
    z = racer->segmentPositionInfo.pos.z - camera->eye.z;

    var_fv1 = sqrtf(SQ(x) + SQ(y) + SQ(z));

    if (var_fv1 != 0.0f) {
        var_fa0 = -((camera->basis.z.x * x) + (y * camera->basis.z.y) + (z * camera->basis.z.z)) / var_fv1;
        var_fv1 *= var_fa0;
    }
    if ((var_fv1 >= -1000.0f) && (var_fv1 <= 1000.0f)) {
        Audio_SetEnemyEnginePan(((var_fv1 + 1000.0f) / 2000.0f) * 127.0f);
    }
}

void Camera_NormalizeXYZ(f32* x, f32* y, f32* z) {
    f32 normalizeScale;

    normalizeScale = 1.0f / (SQ(*x) + SQ(*y) + SQ(*z));
    *x *= normalizeScale;
    *y *= normalizeScale;
    *z *= normalizeScale;
}

void Camera_SetAxisRotation(MtxF* mtxF, f32 angle, f32 x, f32 y, f32 z) {
    s32 pad[2];
    f32 temp_fa0;
    f32 temp_ft1;
    f32 cos;
    f32 sp18;
    f32 temp_fv0;
    f32 sin;
    s32 binAngle;

    Camera_NormalizeXYZ(&x, &y, &z);
    binAngle = Math_Round(DEG_TO_FZXANG2(angle));
    sin = SIN(binAngle);
    cos = COS(binAngle);
    temp_fv0 = 1.0f - cos;
    temp_ft1 = x * y * temp_fv0;
    temp_fa0 = y * z * temp_fv0;
    sp18 = z * x * temp_fv0;
    mtxF->m[0][0] = ((1.0f - SQ(x)) * cos) + SQ(x);
    mtxF->m[2][1] = temp_fa0 - (x * sin);
    mtxF->m[1][2] = (x * sin) + temp_fa0;
    mtxF->m[1][1] = ((1.0f - SQ(y)) * cos) + SQ(y);
    mtxF->m[2][0] = (y * sin) + sp18;
    mtxF->m[0][2] = sp18 - (y * sin);
    mtxF->m[2][2] = ((1.0f - SQ(z)) * cos) + SQ(z);
    mtxF->m[1][0] = temp_ft1 - (z * sin);
    mtxF->m[0][1] = (z * sin) + temp_ft1;
    mtxF->m[3][3] = 1.0f;
    mtxF->m[0][3] = mtxF->m[1][3] = mtxF->m[2][3] = mtxF->m[3][0] = mtxF->m[3][1] = mtxF->m[3][2] = 0.0f;
}

void func_80713AC0(unk_800832EC_arg_2* arg0) {
    u32 i;

    for (i = 0; i < arg0->unk_04; i++) {
        arg0->unk_08[i] = 0;
    }
}

u8* func_80713B00(u32 arg0, unk_800832EC_arg_2* arg1) {
    s32 var_v0;
    u32 temp_a2;
    u32 temp_v0;
    s32 var_a0;
    u32 var_a3;

    if ((arg0 % arg1->unk_00) != 0) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    temp_a2 = var_v0 + (arg0 / arg1->unk_00);
    if (arg1->unk_04 < temp_a2) {
        return NULL;
    }

    temp_v0 = (arg1->unk_04 - temp_a2) + 1;

    for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
        for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
            if (arg1->unk_08[var_a0 + var_a3] != 0) {
                break;
            }
        }
        if (var_a3 >= temp_a2) {
            for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
                arg1->unk_08[var_a0 + var_a3] = temp_a2 - var_a3;
            }
            return &arg1->unk_0C[arg1->unk_00 * var_a0];
        }
    }
    return NULL;
}

void func_80713C9C(u8* arg0, unk_800832EC_arg_2* arg1) {
    s32 temp_v1;
    u32 i;
    u32 temp_lo;

    if (arg0 != NULL) {
        temp_lo = (size_t) (arg0 - arg1->unk_0C) / arg1->unk_00;
        temp_v1 = arg1->unk_08[temp_lo];

        for (i = 0; i < temp_v1; i++) {
            arg1->unk_08[temp_lo + i] = 0;
        }
    }
}

u8* func_80713D78(u8* arg0, u32 arg1, unk_800832EC_arg_2* arg2) {
    u8* temp_v0;
    u32 var_a2;
    s32 var_v1;

    temp_v0 = func_80713B00(arg1, arg2);
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg0 == NULL) {
        return temp_v0;
    }
    var_v1 = arg2->unk_08[(size_t) (arg0 - arg2->unk_0C) / arg2->unk_00];
    var_a2 = arg2->unk_00 * var_v1;
    if (arg1 < var_a2) {
        var_a2 = arg1;
    }

    bcopy(arg0, temp_v0, var_a2);
    func_80713C9C(arg0, arg2);
    return temp_v0;
}

extern s32 gGameMode;
extern GfxPool D_1000000;
extern Camera gCameras[];

Gfx* Camera_Draw(Gfx* gfx, s32 scissorBoxType, s32 cameraIndex) {
    Camera* camera = &gCameras[cameraIndex];

    switch (camera->vpTransitionState) {
        case CAMERA_VP_TRANSITION_ACTIVE:
            gSPViewport(gfx++, &D_1000000.unk_2C2C8[cameraIndex]);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, camera->currentScissorLeft, camera->currentScissorTop,
                          camera->currentScissorRight, camera->currentScissorBottom);
            break;
        default:
            gfx = func_8006A00C(gfx, scissorBoxType);
            if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS)) {
                gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            }
            break;
    }

    return gfx;
}

void Camera_SettingsFollowSmoothSetDistancePitchYaw(s32 cameraIndex, f32 distance, f32 pitch, f32 yaw) {

    sCameraSettings[cameraIndex].followSmooth.distance = sCameraSettings[cameraIndex].followSmooth.targetDistance =
        distance;
    sCameraSettings[cameraIndex].followSmooth.pitch = sCameraSettings[cameraIndex].followSmooth.targetPitch = pitch;
    sCameraSettings[cameraIndex].followSmooth.yaw = sCameraSettings[cameraIndex].followSmooth.targetYaw = yaw;
}

void Camera_ScriptSetSettings(CameraScriptManager* scriptMgr, CameraSettings* cameraSettings) {
    scriptMgr->settings = cameraSettings;
}

void Camera_ScriptSetControlPointTimers(CameraScriptManager* scriptMgr, SplineControlPointTimers* timers) {
    scriptMgr->controlPointTimers = timers;
}

void Camera_ScriptSetRacerInfo(CameraScriptManager* scriptMgr, Vec3f* focusPos, Mtx3F* basis, Racer* racer) {
    scriptMgr->focusPos = focusPos;
    scriptMgr->racerBasis = basis;
    scriptMgr->racer = racer;
}

void Camera_ScriptSetEyeInfo(CameraScriptManager* scriptMgr, Vec3f* eyeAnchorPoint, Mtx3F* eyeBasis) {
    scriptMgr->eyeAnchorPoint = eyeAnchorPoint;
    scriptMgr->eyeBasis = eyeBasis;
}

void Camera_ScriptSetScript(CameraScriptManager* scriptMgr, CameraScript* script) {
    scriptMgr->script = script;
    scriptMgr->timer = 0;
}

void Camera_ScriptSetControlPointTimerCount(CameraScriptManager* scriptMgr, s32 timersCount) {
    Camera_ScriptInitControlPointTimers(scriptMgr->controlPointTimers, timersCount);
}

void Camera_ScriptSetFrustrumCenterY(CameraScriptManager* scriptMgr, f32* frustrumCenterY) {
    scriptMgr->settings->parameters.targetFrustrumCenterY = *frustrumCenterY;
}

bool Camera_ScriptUpdate(CameraScriptManager* scriptMgr) {
    bool completedScript;
    CameraScript* script;

    while (true) {
        completedScript = false;
        script = scriptMgr->script;
        if (script == NULL) {
            return true;
        }

        if (script->updateFunc != NULL) {
            ((void (*)(CameraScriptManager*, void*)) script->updateFunc)(scriptMgr, script->updateData);
        }
        switch (script->time) {
            case CAMERA_SCRIPT_NEXT:
                scriptMgr->script++;
                continue;
            case CAMERA_SCRIPT_CLEAR:
                scriptMgr->timer = 0;
                script = NULL;
                completedScript = true;
                break;
            case CAMERA_SCRIPT_BREAK:
                scriptMgr->timer++;
                completedScript = true;
                break;
            default:
                if (++scriptMgr->timer >= script->time) {
                    script++;
                    scriptMgr->timer = 0;
                }
                break;
        }
        break;
    }

    scriptMgr->script = script;
    return completedScript;
}

void Camera_ScriptSetAtEyeData(CameraScriptManager* scriptMgr, CameraAtEyeData* atEyeData) {
    Camera_SettingsSetAtEyeWithParameters(scriptMgr->settings, atEyeData);
}

void Camera_ScriptSetOrbitAtData(CameraScriptManager* scriptMgr, CameraOrbitData* orbitData) {
    Camera_SettingsSetOrbitWithParameters(scriptMgr->settings, CAMERA_TYPE_ORBIT_AT, orbitData);
}

void Camera_ScriptSetOrbitEyeData(CameraScriptManager* scriptMgr, CameraOrbitData* orbitData) {
    Camera_SettingsSetOrbitWithParameters(scriptMgr->settings, CAMERA_TYPE_ORBIT_EYE, orbitData);
}

void Camera_ScriptSetFollowSmoothData(CameraScriptManager* scriptMgr, CameraFollowSmoothData* followSmoothData) {
    Camera_SettingsSetFollowSmoothWithParameters(scriptMgr->settings, followSmoothData);
}

void Camera_ScriptSetLocalAnchorData(CameraScriptManager* scriptMgr, CameraLocalAnchorData* localAnchorData) {
    Camera_SettingsSetLocalAnchorWithParameters(scriptMgr->settings, localAnchorData);
}

void Camera_ScriptUpdateAtEyeFocusAtEye(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[2];
    Vec3f at;

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData[0].x + scriptMgr->focusPos->x;
    at.y = interpData[0].y + scriptMgr->focusPos->y;
    at.z = interpData[0].z + scriptMgr->focusPos->z;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &interpData[1], NULL, NULL);
}

void Camera_ScriptUpdateAtEyeFocusAtEyeUp(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[3];
    Vec3f at;

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData[0].x + scriptMgr->focusPos->x;
    at.y = interpData[0].y + scriptMgr->focusPos->y;
    at.z = interpData[0].z + scriptMgr->focusPos->z;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &interpData[1], &interpData[2], NULL);
}

void Camera_ScriptUpdateAtEyeFocusAtEyeFov(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData) {
    InterpolateOut331Data interpData;
    Vec3f at;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData.vecData[0].x + scriptMgr->focusPos->x;
    at.y = interpData.vecData[0].y + scriptMgr->focusPos->y;
    at.z = interpData.vecData[0].z + scriptMgr->focusPos->z;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &interpData.vecData[1], NULL, &interpData.floatData);
}

void Camera_ScriptUpdateAtEyeFocusAtEyeUpFov(CameraScriptManager* scriptMgr, CubicBSpline3331Data* splineData) {
    InterpolateOut3331Data interpData;
    Vec3f at;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData.vecData[0].x + scriptMgr->focusPos->x;
    at.y = interpData.vecData[0].y + scriptMgr->focusPos->y;
    at.z = interpData.vecData[0].z + scriptMgr->focusPos->z;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &interpData.vecData[1], &interpData.vecData[2],
                                    &interpData.floatData);
}

void Camera_ScriptUpdateAtEyeFocusAnchorAtEye(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[2];
    Vec3f at;
    Vec3f eye;

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData[0].x + scriptMgr->focusPos->x;
    at.y = interpData[0].y + scriptMgr->focusPos->y;
    at.z = interpData[0].z + scriptMgr->focusPos->z;

    eye.x = scriptMgr->eyeAnchorPoint->x + scriptMgr->eyeBasis->x.x * interpData[1].z +
            scriptMgr->eyeBasis->y.x * interpData[1].y + scriptMgr->eyeBasis->z.x * interpData[1].x;
    eye.y = scriptMgr->eyeAnchorPoint->y + scriptMgr->eyeBasis->x.y * interpData[1].z +
            scriptMgr->eyeBasis->y.y * interpData[1].y + scriptMgr->eyeBasis->z.y * interpData[1].x;
    eye.z = scriptMgr->eyeAnchorPoint->z + scriptMgr->eyeBasis->x.z * interpData[1].z +
            scriptMgr->eyeBasis->y.z * interpData[1].y + scriptMgr->eyeBasis->z.z * interpData[1].x;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &eye, NULL, NULL);
}

void Camera_ScriptUpdateAtEyeFocusAnchorAtEyeUp(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[3];
    Vec3f at;
    Vec3f eye;

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData[0].x + scriptMgr->focusPos->x;
    at.y = interpData[0].y + scriptMgr->focusPos->y;
    at.z = interpData[0].z + scriptMgr->focusPos->z;

    eye.x = scriptMgr->eyeAnchorPoint->x + scriptMgr->eyeBasis->x.x * interpData[1].z +
            scriptMgr->eyeBasis->y.x * interpData[1].y + scriptMgr->eyeBasis->z.x * interpData[1].x;
    eye.y = scriptMgr->eyeAnchorPoint->y + scriptMgr->eyeBasis->x.y * interpData[1].z +
            scriptMgr->eyeBasis->y.y * interpData[1].y + scriptMgr->eyeBasis->z.y * interpData[1].x;
    eye.z = scriptMgr->eyeAnchorPoint->z + scriptMgr->eyeBasis->x.z * interpData[1].z +
            scriptMgr->eyeBasis->y.z * interpData[1].y + scriptMgr->eyeBasis->z.z * interpData[1].x;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &eye, &interpData[2], NULL);
}

void Camera_ScriptUpdateAtEyeFocusAnchorAtEyeFov(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData) {
    InterpolateOut331Data interpData;
    Vec3f at;
    Vec3f eye;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData.vecData[0].x + scriptMgr->focusPos->x;
    at.y = interpData.vecData[0].y + scriptMgr->focusPos->y;
    at.z = interpData.vecData[0].z + scriptMgr->focusPos->z;

    eye.x = scriptMgr->eyeAnchorPoint->x + scriptMgr->eyeBasis->x.x * interpData.vecData[1].z +
            scriptMgr->eyeBasis->y.x * interpData.vecData[1].y + scriptMgr->eyeBasis->z.x * interpData.vecData[1].x;
    eye.y = scriptMgr->eyeAnchorPoint->y + scriptMgr->eyeBasis->x.y * interpData.vecData[1].z +
            scriptMgr->eyeBasis->y.y * interpData.vecData[1].y + scriptMgr->eyeBasis->z.y * interpData.vecData[1].x;
    eye.z = scriptMgr->eyeAnchorPoint->z + scriptMgr->eyeBasis->x.z * interpData.vecData[1].z +
            scriptMgr->eyeBasis->y.z * interpData.vecData[1].y + scriptMgr->eyeBasis->z.z * interpData.vecData[1].x;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &eye, NULL, &interpData.floatData);
}

void Camera_ScriptUpdateAtEyeFocusAnchorAtEyeUpFov(CameraScriptManager* scriptMgr, CubicBSpline3331Data* splineData) {
    InterpolateOut3331Data interpData;
    Vec3f at;
    Vec3f eye;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    at.x = interpData.vecData[0].x + scriptMgr->focusPos->x;
    at.y = interpData.vecData[0].y + scriptMgr->focusPos->y;
    at.z = interpData.vecData[0].z + scriptMgr->focusPos->z;

    eye.x = scriptMgr->eyeAnchorPoint->x + scriptMgr->eyeBasis->x.x * interpData.vecData[1].z +
            scriptMgr->eyeBasis->y.x * interpData.vecData[1].y + scriptMgr->eyeBasis->z.x * interpData.vecData[1].x;
    eye.y = scriptMgr->eyeAnchorPoint->y + scriptMgr->eyeBasis->x.y * interpData.vecData[1].z +
            scriptMgr->eyeBasis->y.y * interpData.vecData[1].y + scriptMgr->eyeBasis->z.y * interpData.vecData[1].x;
    eye.z = scriptMgr->eyeAnchorPoint->z + scriptMgr->eyeBasis->x.z * interpData.vecData[1].z +
            scriptMgr->eyeBasis->y.z * interpData.vecData[1].y + scriptMgr->eyeBasis->z.z * interpData.vecData[1].x;
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &at, &eye, &interpData.vecData[2], &interpData.floatData);
}

void Camera_ScriptUpdateAtEyeAtEye(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[2];

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &interpData[0], &interpData[1], NULL, NULL);
}

void Camera_ScriptUpdateAtEyeAtEyeUp(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[3];

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &interpData[0], &interpData[1], &interpData[2], NULL);
}

void Camera_ScriptUpdateAtEyeAtEyeFov(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData) {
    InterpolateOut331Data interpData;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &interpData.vecData[0], &interpData.vecData[1], NULL,
                                    &interpData.floatData);
}

void Camera_ScriptUpdateAtEyeAtEyeUpFov(CameraScriptManager* scriptMgr, CubicBSpline3331Data* splineData) {
    InterpolateOut3331Data interpData;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateAtEyeTargets(scriptMgr->settings, &interpData.vecData[0], &interpData.vecData[1],
                                    &interpData.vecData[2], &interpData.floatData);
}

void Camera_ScriptUpdateOrbitAnchorDistanceYawPitch(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[2];

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData[0], &interpData[1], NULL, NULL);
}

void Camera_ScriptUpdateOrbitAnchorDistanceYawPitchUp(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[3];

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData[0], &interpData[1], &interpData[2], NULL);
}

void Camera_ScriptUpdateOrbitAnchorDistanceYawPitchFov(CameraScriptManager* scriptMgr,
                                                       CubicBSpline331Data* splineData) {
    InterpolateOut331Data interpData;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData.vecData[0], &interpData.vecData[1], NULL,
                                    &interpData.floatData);
}

void Camera_ScriptUpdateOrbitAnchorDistanceYawPitchUpFov(CameraScriptManager* scriptMgr,
                                                         CubicBSpline3331Data* splineData) {
    InterpolateOut3331Data interpData;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData.vecData[0], &interpData.vecData[1],
                                    &interpData.vecData[2], &interpData.floatData);
}

void Camera_ScriptUpdateOrbitDistanceYawPitchAnchor(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[2];

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData[1], &interpData[0], NULL, NULL);
}

void Camera_ScriptUpdateOrbitDistanceYawPitchAnchorUp(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    Vec3f interpData[3];

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData[1], &interpData[0], &interpData[2], NULL);
}

void Camera_ScriptUpdateOrbitDistanceYawPitchAnchorFov(CameraScriptManager* scriptMgr,
                                                       CubicBSpline331Data* splineData) {
    InterpolateOut331Data interpData;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData.vecData[1], &interpData.vecData[0], NULL,
                                    &interpData.floatData);
}

void Camera_ScriptUpdateOrbitDistanceYawPitchAnchorFovUp(CameraScriptManager* scriptMgr,
                                                         CubicBSpline3331Data* splineData) {
    InterpolateOut3331Data interpData;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &interpData.vecData[1], &interpData.vecData[0],
                                    &interpData.vecData[2], &interpData.floatData);
}

void Camera_ScriptUpdateOrbitAngledAnchorDistanceYawPitch(CameraScriptManager* scriptMgr,
                                                          CubicBSpline3fData* splineData) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    Vec3f interpData[2];
    Vec3f anchorPos;
    s32 pad;

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * interpData[0].x;
    anchorPos.x = COS(sp64) * temp_fv0 + scriptMgr->focusPos->x;
    anchorPos.y = interpData[0].x * SIN(temp_v0) + scriptMgr->focusPos->y;
    anchorPos.z = scriptMgr->focusPos->z - SIN(sp64) * temp_fv0;
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &anchorPos, &interpData[1], NULL, NULL);
}

void Camera_ScriptUpdateOrbitAngledAnchorDistanceYawPitchUp(CameraScriptManager* scriptMgr,
                                                            CubicBSpline3fData* splineData) {
    s32 sp6C;
    s32 temp_v0;
    f32 sp64;
    f32 sp60;
    f32 temp_fv0;
    Vec3f interpData[3];
    Vec3f anchorPos;
    s32 pad;

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    //! @bug uninitialised angles
    sp6C = Math_Round(DEG_TO_FZXANG2(sp64));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp60));
    temp_fv0 = COS(temp_v0) * interpData[0].x;
    anchorPos.x = COS(sp6C) * temp_fv0 + scriptMgr->focusPos->x;
    anchorPos.y = interpData[0].x * SIN(temp_v0) + scriptMgr->focusPos->y;
    anchorPos.z = scriptMgr->focusPos->z - SIN(sp6C) * temp_fv0;
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &anchorPos, &interpData[1], &interpData[2], NULL);
}

void Camera_ScriptUpdateOrbitAngledAnchorDistanceYawPitchFov(CameraScriptManager* scriptMgr,
                                                             CubicBSpline331Data* splineData) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    InterpolateOut331Data interpData;
    Vec3f anchorPos;
    s32 pad;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * interpData.vecData[0].x;
    anchorPos.x = COS(sp64) * temp_fv0 + scriptMgr->focusPos->x;
    anchorPos.y = interpData.vecData[0].x * SIN(temp_v0) + scriptMgr->focusPos->y;
    anchorPos.z = scriptMgr->focusPos->z - SIN(sp64) * temp_fv0;
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &anchorPos, &interpData.vecData[1], NULL,
                                    &interpData.floatData);
}

void Camera_ScriptUpdateOrbitAngledAnchorDistanceYawPitchUpFov(CameraScriptManager* scriptMgr,
                                                               CubicBSpline3331Data* splineData) {
    s32 sp74;
    s32 temp_v0;
    f32 sp6C;
    f32 sp68;
    f32 temp_fv0;
    InterpolateOut3331Data interpData;
    Vec3f anchorPos;
    s32 pad;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    //! @bug uninitialised angles
    sp74 = Math_Round(DEG_TO_FZXANG2(sp6C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp68));
    temp_fv0 = COS(temp_v0) * interpData.vecData[0].x;
    anchorPos.x = COS(sp74) * temp_fv0 + scriptMgr->focusPos->x;
    anchorPos.y = interpData.vecData[0].x * SIN(temp_v0) + scriptMgr->focusPos->y;
    anchorPos.z = scriptMgr->focusPos->z - SIN(sp74) * temp_fv0;
    Camera_ScriptUpdateOrbitTargets(scriptMgr->settings, &anchorPos, &interpData.vecData[1], &interpData.vecData[2],
                                    &interpData.floatData);
}

void Camera_ScriptUpdateLocalAnchorBasisAtEye(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData) {
    s32 pad;
    Vec3f interpData[2];
    Vec3f anchorPoint;
    Mtx3F basis;

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData->vecData);
    anchorPoint.x = scriptMgr->focusPos->x;
    anchorPoint.y = scriptMgr->focusPos->y;
    anchorPoint.z = scriptMgr->focusPos->z;
    basis = *scriptMgr->racerBasis;
    Camera_ScriptUpdateLocalAnchorTargets(scriptMgr->settings, &anchorPoint, &basis, &interpData[0], &interpData[1],
                                          NULL, NULL);
}

void Camera_ScriptUpdateLocalAnchorBasisAtEyeUp(CameraScriptManager* scriptMgr, CubicBSpline3fData* splineData) {
    s32 pad;
    Vec3f interpData[3];
    Vec3f anchorPoint;
    Mtx3F basis;

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    anchorPoint.x = scriptMgr->focusPos->x;
    anchorPoint.y = scriptMgr->focusPos->y;
    anchorPoint.z = scriptMgr->focusPos->z;
    basis = *scriptMgr->racerBasis;
    Camera_ScriptUpdateLocalAnchorTargets(scriptMgr->settings, &anchorPoint, &basis, &interpData[0], &interpData[1],
                                          &interpData[2], NULL);
}

void Camera_ScriptUpdateLocalAnchorBasisAtEyeFov(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData) {
    s32 pad;
    InterpolateOut331Data interpData;
    Vec3f anchorPoint;
    Mtx3F basis;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    anchorPoint.x = scriptMgr->focusPos->x;
    anchorPoint.y = scriptMgr->focusPos->y;
    anchorPoint.z = scriptMgr->focusPos->z;
    basis = *scriptMgr->racerBasis;
    Camera_ScriptUpdateLocalAnchorTargets(scriptMgr->settings, &anchorPoint, &basis, &interpData.vecData[0],
                                          &interpData.vecData[1], NULL, &interpData.floatData);
}

void Camera_ScriptUpdateLocalAnchorBasisAtEyeUpFov(CameraScriptManager* scriptMgr, CubicBSpline3331Data* splineData) {
    s32 pad;
    InterpolateOut3331Data interpData;
    Vec3f anchorPoint;
    Mtx3F basis;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    anchorPoint.x = scriptMgr->focusPos->x;
    anchorPoint.y = scriptMgr->focusPos->y;
    anchorPoint.z = scriptMgr->focusPos->z;
    basis = *scriptMgr->racerBasis;
    Camera_ScriptUpdateLocalAnchorTargets(scriptMgr->settings, &anchorPoint, &basis, &interpData.vecData[0],
                                          &interpData.vecData[1], &interpData.vecData[2], &interpData.floatData);
}

void Camera_ScriptUpdateFollowSmoothCenterDistanceYawPitch(CameraScriptManager* scriptMgr,
                                                           CubicBSpline3fData* splineData) {
    s32 pad[4];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    Vec3f interpData[2];
    Vec3f center;

    Camera_UpdateInterpolateBSpline33f(interpData, scriptMgr->controlPointTimers, splineData);
    racer = scriptMgr->racer;
    followSmooth = &scriptMgr->settings->followSmooth;
    followSmooth->racerBasis = *scriptMgr->racerBasis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    center.x = interpData[0].x + scriptMgr->focusPos->x;
    center.y = interpData[0].y + scriptMgr->focusPos->y;
    center.z = interpData[0].z + scriptMgr->focusPos->z;

    Camera_ScriptUpdateFollowSmoothTargets(scriptMgr->settings, &center, &interpData[1], NULL, NULL);
}

void Camera_ScriptUpdateFollowSmoothCenterDistanceYawPitchUp(CameraScriptManager* scriptMgr,
                                                             CubicBSpline3fData* splineData) {
    s32 pad[4];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    Vec3f interpData[3];
    Vec3f center;

    Camera_UpdateInterpolateBSpline333f(interpData, scriptMgr->controlPointTimers, splineData);
    racer = scriptMgr->racer;
    followSmooth = &scriptMgr->settings->followSmooth;
    followSmooth->racerBasis = *scriptMgr->racerBasis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    center.x = interpData[0].x + scriptMgr->focusPos->x;
    center.y = interpData[0].y + scriptMgr->focusPos->y;
    center.z = interpData[0].z + scriptMgr->focusPos->z;

    Camera_ScriptUpdateFollowSmoothTargets(scriptMgr->settings, &center, &interpData[1], &interpData[2], NULL);
}

void Camera_ScriptUpdateFollowSmoothCenterDistanceYawPitchFov(CameraScriptManager* scriptMgr,
                                                              CubicBSpline331Data* splineData) {
    s32 pad[6];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    InterpolateOut331Data interpData;
    Vec3f center;

    Camera_UpdateInterpolateBSpline331f(&interpData, scriptMgr->controlPointTimers, splineData);
    racer = scriptMgr->racer;
    followSmooth = &scriptMgr->settings->followSmooth;
    followSmooth->racerBasis = *scriptMgr->racerBasis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    center.x = interpData.vecData[0].x + scriptMgr->focusPos->x;
    center.y = interpData.vecData[0].y + scriptMgr->focusPos->y;
    center.z = interpData.vecData[0].z + scriptMgr->focusPos->z;

    Camera_ScriptUpdateFollowSmoothTargets(scriptMgr->settings, &center, &interpData.vecData[1], NULL,
                                           &interpData.floatData);
}

void Camera_ScriptUpdateFollowSmoothCenterDistanceYawPitchUpFov(CameraScriptManager* scriptMgr,
                                                                CubicBSpline3331Data* splineData) {
    s32 pad[4];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    InterpolateOut3331Data interpData;
    Vec3f center;

    Camera_UpdateInterpolateBSpline3331f(&interpData, scriptMgr->controlPointTimers, splineData);
    racer = scriptMgr->racer;
    followSmooth = &scriptMgr->settings->followSmooth;
    followSmooth->racerBasis = *scriptMgr->racerBasis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    center.x = interpData.vecData[0].x + scriptMgr->focusPos->x;
    center.y = interpData.vecData[0].y + scriptMgr->focusPos->y;
    center.z = interpData.vecData[0].z + scriptMgr->focusPos->z;

    Camera_ScriptUpdateFollowSmoothTargets(scriptMgr->settings, &center, &interpData.vecData[1], &interpData.vecData[2],
                                           &interpData.floatData);
}

void Camera_ScriptInitControlPointTimers(SplineControlPointTimers* timers, s32 timersCount) {
    s32 i;

    for (i = 0; i < timersCount; i++) {
        timers->controlPointTimer[i].timer = timers->controlPointTimer[i].controlPoint = 0;
    }
}

f32 Camera_InterpolateBSpline(f32 t, s32 startPoint, f32* pointData, s32 totalPointCount) {
    f32 oneMinusT;
    f32 oneMinusTSquare;
    f32 oneMinusTCube;
    f32 tSquare;
    f32 tCube;
    f32 b3;
    f32 b2;
    f32 b1;
    f32 b0;

    if (startPoint == 0) {
        oneMinusT = 1.0f - t;
        tSquare = SQ(t);
        tCube = CB(t);
        b0 = CB(oneMinusT);
        b1 = (((tCube * 21.0f) / 12.0f) - (tSquare * 9.0f / 2.0f)) + (t * 3.0f);
        b2 = ((-tCube * 11.0f) / 12.0f) + (tSquare * 3.0f / 2.0f);
        b3 = tCube / 6.0f;
    } else if (startPoint == 1) {
        oneMinusT = 1.0f - t;
        tSquare = SQ(t);
        tCube = CB(t);
        b0 = CB(oneMinusT) / 4.0f;
        b1 = (((tCube * 7.0f) / 12.0f) - (tSquare * 5.0f / 4.0f)) + (t / 4.0f) + 7.0f / 12.0f;
        b2 = (-tCube / 2.0f) + (tSquare / 2.0f) + (t / 2.0f) + 1.0f / 6.0f;
        b3 = tCube / 6.0f;
    } else if ((totalPointCount < 7) || (startPoint < (totalPointCount - 5))) {
        oneMinusT = 1.0f - t;
        tSquare = SQ(t);
        tCube = CB(t);
        b0 = CB(oneMinusT) / 6.0f;
        b1 = ((tCube / 2.0f) - tSquare) + 2.0f / 3.0f;
        b2 = (-tCube / 2.0f) + (tSquare / 2.0f) + (t / 2.0f) + 1.0f / 6.0f;
        b3 = tCube / 6.0f;
    } else if (startPoint == totalPointCount - 5) {
        oneMinusT = 1.0f - t;
        oneMinusTSquare = SQ(oneMinusT);
        oneMinusTCube = CB(oneMinusT);
        b0 = oneMinusTCube / 6.0f;
        b1 = (-oneMinusTCube / 2.0f) + (oneMinusTSquare / 2.0f) + (oneMinusT / 2.0f) + 1.0f / 6.0f;
        b2 = (((oneMinusTCube * 7.0f) / 12.0f) - (oneMinusTSquare * 5.0f / 4.0f)) + (oneMinusT / 4.0f) + 7.0f / 12.0f;
        b3 = CB(t) / 4.0f;
    } else if (startPoint == totalPointCount - 4) {
        oneMinusT = 1.0f - t;
        oneMinusTSquare = SQ(oneMinusT);
        oneMinusTCube = CB(oneMinusT);
        b0 = oneMinusTCube / 6.0f;
        b1 = ((-oneMinusTCube * 11.0f) / 12.0f) + (oneMinusTSquare * 3.0f / 2.0f);
        b2 = (((oneMinusTCube * 21.0f) / 12.0f) - (oneMinusTSquare * 9.0f / 2.0f)) + (oneMinusT * 3.0f);
        b3 = CB(t);
    }

    return b0 * pointData[startPoint] + b1 * pointData[startPoint + 1] + b2 * pointData[startPoint + 2] +
           b3 * pointData[startPoint + 3];
}

void Camera_UpdateInterpolateBSpline1f(f32* interpolatedData, SplineControlPointTimer* controlPointTimer,
                                       CubicBSpline1fData* splineData) {

    while (splineData->times[controlPointTimer->controlPoint] == 0) {
        controlPointTimer->controlPoint++;
    }

    *interpolatedData = Camera_InterpolateBSpline(
        (f32) controlPointTimer->timer / (f32) splineData->times[controlPointTimer->controlPoint],
        controlPointTimer->controlPoint, splineData->controlPoints, splineData->controlPointCount);

    controlPointTimer->timer++;

    if (controlPointTimer->timer >= splineData->times[controlPointTimer->controlPoint]) {
        controlPointTimer->timer = 0;
        controlPointTimer->controlPoint++;
        if (controlPointTimer->controlPoint >= (splineData->controlPointCount - 3)) {
            controlPointTimer->controlPoint = -1;
        }
    }
}

void Camera_UpdateInterpolateBSpline3f(Vec3f* interpolatedVecData, SplineControlPointTimer* controlPointTimer,
                                       CubicBSpline3fData* splineData) {
    s32 i;

    while (splineData->times[controlPointTimer->controlPoint] == 0) {
        controlPointTimer->controlPoint++;
    }

    for (i = 0; i < 3; i++) {
        interpolatedVecData->v[i] = Camera_InterpolateBSpline(
            (f32) controlPointTimer->timer / (f32) splineData->times[controlPointTimer->controlPoint],
            controlPointTimer->controlPoint, splineData->controlPoints[i], splineData->controlPointCount);
    }

    controlPointTimer->timer++;

    if (controlPointTimer->timer >= splineData->times[controlPointTimer->controlPoint]) {
        controlPointTimer->timer = 0;
        controlPointTimer->controlPoint++;
        if (controlPointTimer->controlPoint >= (splineData->controlPointCount - 3)) {
            controlPointTimer->controlPoint = -1;
        }
    }
}

void Camera_UpdateInterpolateBSpline33f(Vec3f* interpolatedData, SplineControlPointTimers* timers,
                                        CubicBSpline3fData* splineData) {
    Camera_UpdateInterpolateBSpline3f(&interpolatedData[0], &timers->controlPointTimer[0], &splineData[0]);
    Camera_UpdateInterpolateBSpline3f(&interpolatedData[1], &timers->controlPointTimer[1], &splineData[1]);
}

void Camera_UpdateInterpolateBSpline333f(Vec3f* interpolatedData, SplineControlPointTimers* timers,
                                         CubicBSpline3fData* splineData) {
    Camera_UpdateInterpolateBSpline3f(&interpolatedData[0], &timers->controlPointTimer[0], &splineData[0]);
    Camera_UpdateInterpolateBSpline3f(&interpolatedData[1], &timers->controlPointTimer[1], &splineData[1]);
    Camera_UpdateInterpolateBSpline3f(&interpolatedData[2], &timers->controlPointTimer[2], &splineData[2]);
}

void Camera_UpdateInterpolateBSpline331f(InterpolateOut331Data* interpolatedData, SplineControlPointTimers* timers,
                                         CubicBSpline331Data* splineData) {
    Camera_UpdateInterpolateBSpline3f(&interpolatedData->vecData[0], &timers->controlPointTimer[0],
                                      &splineData->vecData[0]);
    Camera_UpdateInterpolateBSpline3f(&interpolatedData->vecData[1], &timers->controlPointTimer[1],
                                      &splineData->vecData[1]);
    Camera_UpdateInterpolateBSpline1f(&interpolatedData->floatData, &timers->controlPointTimer[2],
                                      &splineData->floatData);
}

void Camera_UpdateInterpolateBSpline3331f(InterpolateOut3331Data* interpolatedData, SplineControlPointTimers* timers,
                                          CubicBSpline3331Data* splineData) {
    Camera_UpdateInterpolateBSpline3f(&interpolatedData->vecData[0], &timers->controlPointTimer[0],
                                      &splineData->vecData[0]);
    Camera_UpdateInterpolateBSpline3f(&interpolatedData->vecData[1], &timers->controlPointTimer[1],
                                      &splineData->vecData[1]);
    Camera_UpdateInterpolateBSpline3f(&interpolatedData->vecData[2], &timers->controlPointTimer[2],
                                      &splineData->vecData[2]);
    Camera_UpdateInterpolateBSpline1f(&interpolatedData->floatData, &timers->controlPointTimer[3],
                                      &splineData->floatData);
}

void Camera_StartInit(void) {
    CameraScriptManager* var_s1;
    s32 i;
    Racer* racer;
    Camera* camera;
    SplineControlPointTimers* var_s4;
    CameraSettings* cameraSettings;

    for (i = 0, camera = gCameras, var_s1 = sCameraScriptMgrs, cameraSettings = sCameraSettings,
        var_s4 = sSplineControlPointTimers;
         i < 4; i++) {
        camera->id = (s16) i;
        camera->raceSetting = CAMERA_RACE_SETTING_REGULAR;
        camera->vpTransitionState = CAMERA_VP_TRANSITION_INACTIVE;
        Camera_ScriptSetSettings(var_s1, cameraSettings);
        Camera_ScriptSetControlPointTimers(var_s1, var_s4);
        racer = &gRacers[camera->id];
        Camera_ScriptSetRacerInfo(var_s1, &racer->focusPos, &racer->trueBasis, racer);

        var_s1++;
        cameraSettings++;
        var_s4++;
        camera++;
    }
#ifndef EXPANSION_KIT
    sCameraInfoInitialized = false;
#else
    sCameraInfoInitialized = true;
#endif
}

extern s8 gTitleDemoState;

void Camera_Init(void) {
    s32 i;
    Camera* camera;
    Racer* racer;

    sEndingCameraMessage = 0;
#ifndef EXPANSION_KIT
    D_800E5E8C = 0;
#endif

    for (i = 0, camera = gCameras; i < 4; i++, camera++) {
        racer = &gRacers[camera->id];
        Camera_ScriptSetRacerInfo(&sCameraScriptMgrs[i], &racer->focusPos, &racer->trueBasis, racer);
    }
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_TITLE;
            Camera_InitMode(gCameras, sCameraSettings, sCameraScriptMgrs);
            break;
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_FLX_MACHINE_SELECT:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_MACHINE_SELECT_CREATE;
            Camera_InitMode(gCameras, sCameraSettings, sCameraScriptMgrs);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
#ifndef EXPANSION_KIT
            D_800E5E8C = sCameraInfoInitialized;
#endif
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_MACHINE_SETTINGS;
            Camera_InitMode(gCameras, sCameraSettings, sCameraScriptMgrs);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_COURSE_SELECT;
            Camera_InitMode(gCameras, sCameraSettings, sCameraScriptMgrs);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_DEATH_RACE:
#ifndef EXPANSION_KIT
            D_800E5E8C = sCameraInfoInitialized;
#endif
            /* fallthrough */
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
            sMultiplayerFocusCameraId = -1;
            sNumCameras = gNumPlayers;
            for (i = 0; i < sNumCameras; i++) {
                if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                    gCameras[i].mode = CAMERA_MODE_TITLE_DEMO;
                } else {
                    gCameras[i].mode = CAMERA_MODE_RACE_INTRO;
                }

                gCameras[i].focusPos = gRacers[i].segmentPositionInfo.pos;

                gCameras[i].racerBasis = gRacers[i].trueBasis;

                Camera_InitMode(&gCameras[i], &sCameraSettings[i], &sCameraScriptMgrs[i]);
            }

            break;
        case GAMEMODE_TIME_ATTACK:
#ifndef EXPANSION_KIT
            D_800E5E8C = sCameraInfoInitialized;
#endif
            sMultiplayerFocusCameraId = -1;
#ifndef EXPANSION_KIT
            sNumCameras = 2;
#endif
            if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
#ifdef EXPANSION_KIT
                sNumCameras = 1;
#endif
                gCameras[0].mode = CAMERA_MODE_TITLE_DEMO;
#ifndef EXPANSION_KIT
                if (1) {
                    gCameras[0].mode = CAMERA_MODE_RACE_INTRO;
                }
#endif
            } else {
#ifdef EXPANSION_KIT
                sNumCameras = 2;
#endif
                gCameras[0].mode = CAMERA_MODE_RACE_INTRO;
            }
            gCameras[0].focusPos = gRacers[0].segmentPositionInfo.pos;
            gCameras[0].racerBasis = gRacers[0].trueBasis;
            gCameras[1].mode = CAMERA_MODE_RECORDS_ENTRY;
            for (i = 0; i < sNumCameras; i++) {
                Camera_InitMode(&gCameras[i], &sCameraSettings[i], &sCameraScriptMgrs[i]);
            }
            break;
#ifdef EXPANSION_KIT
        case GAMEMODE_COURSE_EDIT:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_RACE;
            gCameras[0].focusPos = gRacers[0].segmentPositionInfo.pos;
            gCameras[0].racerBasis = gRacers[0].trueBasis;

            for (i = 0; i < sNumCameras; i++) {
                Camera_InitMode(&gCameras[i], &sCameraSettings[i], &sCameraScriptMgrs[i]);
            }
            break;
#endif
        case GAMEMODE_RECORDS:
            sNumCameras = 2;
            gCameras[0].mode = CAMERA_MODE_RECORDS_RACE;
            gCameras[0].focusPos = gRacers[0].segmentPositionInfo.pos;
            gCameras[0].racerBasis = gRacers[0].trueBasis;
            gCameras[1].mode = CAMERA_MODE_RECORDS_ENTRY;
            for (i = 0; i < sNumCameras; i++) {
                Camera_InitMode(&gCameras[i], &sCameraSettings[i], &sCameraScriptMgrs[i]);
            }
            break;
        case GAMEMODE_GP_END_CS:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_ENDING;
            Camera_InitMode(gCameras, sCameraSettings, sCameraScriptMgrs);
            break;
    }
}

extern s16 gPlayer1OverallPosition;

void Camera_InitMode(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    s32 pad;
    s32 raceSetting;
    bool initViewport;
    f32 angle;
    s32 pad2;
    CameraRaceSettingInfo* raceSettingInfo;
    Vec3f eye;
    Racer* racer;

    camera->lookBackRotate = 0;
    camera->state = 0;
    camera->timer = 0;
    initViewport = false;

    switch (camera->mode) {
        case CAMERA_MODE_MACHINE_SELECT_CREATE:
        case CAMERA_MODE_RECORDS_ENTRY:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(cameraSettings, CAMERA_TYPE_ORBIT_AT, &D_800D4F58);
            break;
        case CAMERA_MODE_MACHINE_SETTINGS:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(cameraSettings, CAMERA_TYPE_ORBIT_AT, &D_800D5004);
            if (gNumPlayers >= 2) {
                cameraSettings->orbit.yaw = cameraSettings->orbit.targetYaw = 30.0f;
            }
            break;
        case CAMERA_MODE_COURSE_SELECT:
            camera->near = 16.0f;
            camera->far = 16384.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(cameraSettings, CAMERA_TYPE_ORBIT_AT, &D_800D50B0);
            break;
        case CAMERA_MODE_RACE_INTRO:
            Camera_SettingsSetOrbitWithParameters(cameraSettings, CAMERA_TYPE_ORBIT_AT, &D_800D524C);
            if (gNumPlayers == 2) {
                camera->near = 16.0f;
                camera->far = 8192.0f;
                cameraSettings->parameters.frustrumCenterY = cameraSettings->parameters.targetFrustrumCenterY = -15.0f;
                cameraSettings->parameters.fov = cameraSettings->parameters.targetFov = 100.0f;
            } else {
                camera->near = 16.0f;
                camera->far = 8192.0f;
            }
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            initViewport = true;
            break;
        case CAMERA_MODE_RACE:
        case CAMERA_MODE_TITLE_DEMO:
            if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                raceSetting = CAMERA_RACE_SETTING_REGULAR;
            } else {
                raceSetting = camera->raceSetting;
            }
            if (gNumPlayers == 2) {
                camera->near = 16.0f;
                camera->far = 8192.0f;
                camera->fovScaleX = SCREEN_WIDTH;
                camera->fovScaleY = SCREEN_HEIGHT;

                Camera_SettingsSetFollowSmoothWithParameters(cameraSettings, &D_800D544C);

                raceSettingInfo = &kWidescreenCameraRaceSettings[raceSetting];
            } else {
                camera->near = 16.0f;
                camera->far = 8192.0f;
                camera->fovScaleX = SCREEN_WIDTH;
                camera->fovScaleY = SCREEN_HEIGHT;

                Camera_SettingsSetFollowSmoothWithParameters(cameraSettings, &D_800D5358);

                raceSettingInfo = &kRegularCameraRaceSettings[raceSetting];
            }
            cameraSettings->followSmooth.targetDistance = cameraSettings->followSmooth.distance =
                raceSettingInfo->distance;
            cameraSettings->followSmooth.targetPitch = cameraSettings->followSmooth.pitch = raceSettingInfo->pitch;
            cameraSettings->parameters.targetFov = cameraSettings->parameters.fov = raceSettingInfo->fov;

            Math_Round(DEG_TO_FZXANG2(cameraSettings->followSmooth.pitch));
            racer = &gRacers[camera->id];
            cameraSettings->followSmooth.anchorPoint.x =
                racer->focusPos.x - (raceSettingInfo->distance * racer->trueBasis.x.x);
            cameraSettings->followSmooth.anchorPoint.y =
                racer->focusPos.y - (raceSettingInfo->distance * racer->trueBasis.x.y);
            cameraSettings->followSmooth.anchorPoint.z =
                racer->focusPos.z - (raceSettingInfo->distance * racer->trueBasis.x.z);
            camera->targetFov = cameraSettings->parameters.targetFov;
            camera->fovFlags = 0;
            if ((raceSetting == CAMERA_RACE_SETTING_CLOSE_BEHIND) || (raceSetting == CAMERA_RACE_SETTING_REGULAR)) {
                camera->fovFlags |= CAMERA_FOV_FLAG_1;
            }
            initViewport = true;
            break;
        case CAMERA_MODE_FALLING_OFF_TRACK:
            eye = cameraSettings->parameters.eye;
            Camera_SettingsSetAtEyeWithParameters(cameraSettings, &kDefaultAtEyeData);
            cameraSettings->parameters.fov = cameraSettings->parameters.targetFov = 80.0f;
            cameraSettings->atEye.targetEye = eye;
            if (gNumPlayers == 2) {
                cameraSettings->parameters.frustrumCenterY = cameraSettings->parameters.targetFrustrumCenterY = -50.0f;
            }
            break;
        case CAMERA_MODE_FINISHED_SUCCESS:
            Camera_SettingsSetAtEyeWithParameters(cameraSettings, &kDefaultAtEyeData);
            cameraSettings->parameters.targetFov = gFinishedSuccessScript[0].fov;
            if (gNumPlayers == 2) {
                cameraSettings->parameters.frustrumCenterY = cameraSettings->parameters.targetFrustrumCenterY = -30.0f;
            }

            racer = &gRacers[camera->id];
            Camera_SetupFinishedSuccessFollowRacer(
                &sFinishedSuccessFollowRacerEye[camera->id], racer->segmentPositionInfo.courseSegment,
                racer->segmentPositionInfo.segmentTValue, &gFinishedSuccessScript[0]);
            break;
        case CAMERA_MODE_FINISHED_SPECTATE:
            racer = &gRacers[camera->id];

            Camera_SettingsSetOrbitWithParameters(cameraSettings, CAMERA_TYPE_ORBIT_AT, &D_800D4CF8);
            if (gNumPlayers == 2) {
                cameraSettings->parameters.frustrumCenterY = cameraSettings->parameters.targetFrustrumCenterY = -30.0f;
            }
            cameraSettings->parameters.fov = cameraSettings->parameters.targetFov = 80.0f;
            cameraSettings->orbit.distance = cameraSettings->orbit.targetDistance = 125.0f;
            cameraSettings->orbit.pitch = cameraSettings->orbit.targetPitch = 35.0f;
            cameraSettings->orbit.yaw = cameraSettings->orbit.targetYaw = -50.0f;

            cameraSettings->orbit.basis = racer->trueBasis;

            cameraSettings->orbit.basis.y.x = racer->tiltUp.x;
            cameraSettings->orbit.basis.y.y = racer->tiltUp.y;
            cameraSettings->orbit.basis.y.z = racer->tiltUp.z;
            break;
        case CAMERA_MODE_FINISHED_LOSER:
            eye = cameraSettings->parameters.eye;
            Camera_SettingsSetAtEyeWithParameters(cameraSettings, &kDefaultAtEyeData);
            cameraSettings->parameters.fov = cameraSettings->parameters.targetFov = 80.0f;
            cameraSettings->atEye.targetEye = eye;
            break;
        case CAMERA_MODE_RECORDS_RACE:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetFollowSmoothWithParameters(cameraSettings, &D_800D5358);
            raceSettingInfo = &kRegularCameraRaceSettings[CAMERA_RACE_SETTING_CLOSE_BEHIND];
            cameraSettings->followSmooth.targetDistance = cameraSettings->followSmooth.distance =
                raceSettingInfo->distance;
            cameraSettings->followSmooth.targetPitch = cameraSettings->followSmooth.pitch = 15.0f;
            cameraSettings->parameters.targetFov = cameraSettings->parameters.fov = raceSettingInfo->fov;
            angle = 15.0f;
            Math_Round(DEG_TO_FZXANG2(angle));
            racer = &gRacers[0];
            cameraSettings->followSmooth.anchorPoint.x =
                racer->focusPos.x - (raceSettingInfo->distance * racer->trueBasis.x.x);
            cameraSettings->followSmooth.anchorPoint.y =
                racer->focusPos.y - (raceSettingInfo->distance * racer->trueBasis.x.y);
            cameraSettings->followSmooth.anchorPoint.z =
                racer->focusPos.z - (raceSettingInfo->distance * racer->trueBasis.x.z);
            camera->targetFov = cameraSettings->parameters.targetFov;
            camera->fovFlags = 0;
            initViewport = true;
            break;
        case CAMERA_MODE_13:
            camera->near = 512.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetAtEyeWithParameters(cameraSettings, &D_800D515C);
            break;
        case CAMERA_MODE_ENDING:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(cameraSettings, CAMERA_TYPE_ORBIT_EYE, &D_800D4CF8);
            cameraSettings->orbit.anchorPos.x = 196.0f;
            cameraSettings->orbit.anchorPos.y = 25.0f;
            cameraSettings->orbit.anchorPos.z = -3000.0f;
            cameraSettings->orbit.distance = cameraSettings->orbit.targetDistance = 258.0f;
            cameraSettings->orbit.pitch = cameraSettings->orbit.targetPitch = -7.0f;
            cameraSettings->orbit.yaw = cameraSettings->orbit.targetYaw = 269.0f;
            initViewport = true;
            if (gPlayer1OverallPosition < 4) {
                sCameraEndingFocusRacer = gPlayer1OverallPosition - 1;
            } else {
                sCameraEndingFocusRacer = 0;
            }
            break;
    }
    if (initViewport) {
        camera->vpTransitionState = CAMERA_VP_TRANSITION_INACTIVE;
        camera->transitionTimer = camera->transitionTime = 0;
        Camera_InitViewport(camera);
    }
}

extern s32 sNumCameras;

void Camera_InitViewport(Camera* camera) {
    s32* scissorBoxTypes = sCameraScissorBoxTypes[sNumCameras];
    s32 scissorBoxType = scissorBoxTypes[camera->id];
    Vp* vp;
    ScissorBox* scissorBox;

    switch (scissorBoxType) {
        case SCISSOR_BOX_FULL_SCREEN:
            vp = Segment_SegmentedToVirtual(&aVpFullScreen);
            scissorBox = &gScissorBoxFullScreen;
            break;
        case SCISSOR_BOX_TOP_HALF:
            vp = Segment_SegmentedToVirtual(&aVpTopHalf);
            scissorBox = &gScissorBoxTopHalf;
            break;
        case SCISSOR_BOX_BOTTOM_HALF:
            vp = Segment_SegmentedToVirtual(&aVpBottomHalf);
            scissorBox = &gScissorBoxBottomHalf;
            break;
        case SCISSOR_BOX_LEFT_HALF:
            vp = Segment_SegmentedToVirtual(&aVpLeftHalf);
            scissorBox = &gScissorBoxLeftHalf;
            break;
        case SCISSOR_BOX_RIGHT_HALF:
            vp = Segment_SegmentedToVirtual(&aVpRightHalf);
            scissorBox = &gScissorBoxRightHalf;
            break;
        case SCISSOR_BOX_TOP_LEFT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpTopLeftQuarter);
            scissorBox = &gScissorBoxTopLeftQuarter;
            break;
        case SCISSOR_BOX_TOP_RIGHT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpTopRightQuarter);
            scissorBox = &gScissorBoxTopRightQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_LEFT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpBottomLeftQuarter);
            scissorBox = &gScissorBoxBottomLeftQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_RIGHT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpBottomRightQuarter);
            scissorBox = &gScissorBoxBottomRightQuarter;
            break;
        case SCISSOR_BOX_TOP_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpTopCenterQuarter);
            scissorBox = &gScissorBoxTopCenterQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpBottomCenterQuarter);
            scissorBox = &gScissorBoxBottomCenterQuarter;
            break;
        case SCISSOR_BOX_LEFT_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpLeftCenterQuarter);
            scissorBox = &gScissorBoxLeftCenterQuarter;
            break;
        case SCISSOR_BOX_RIGHT_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpRightCenterQuarter);
            scissorBox = &gScissorBoxRightCenterQuarter;
            break;
    }

    camera->currentVpScaleX = camera->startVpScaleX = camera->endVpScaleX = vp->vp.vscale[0] * 0.25f;
    camera->currentVpScaleY = camera->startVpScaleY = camera->endVpScaleY = vp->vp.vscale[1] * 0.25f;

    camera->currentVpTransX = vp->vp.vtrans[0] * 0.25f;
    camera->currentVpTransY = vp->vp.vtrans[1] * 0.25f;

    camera->startVpTransX = camera->endVpTransX = camera->currentVpTransX - camera->currentVpScaleX;
    camera->startVpTransY = camera->endVpTransY = camera->currentVpTransY - camera->currentVpScaleY;

    camera->currentScissorLeft = camera->startScissorLeft = camera->endScissorLeft = scissorBox->left;
    camera->currentScissorTop = camera->startScissorTop = camera->endScissorTop = scissorBox->top;
    camera->currentScissorRight = camera->startScissorRight = camera->endScissorRight = scissorBox->right;
    camera->currentScissorBottom = camera->startScissorBottom = camera->endScissorBottom = scissorBox->bottom;
}

void Camera_Update(void) {
    s32 i;

    for (i = 0; i < sNumCameras; i++) {
        Camera_UpdateMode(&gCameras[i], &sCameraSettings[i], &sCameraScriptMgrs[i]);
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P)) {
        Camera_UpdateViewportTransition();
    }
}

extern GfxPool* gGfxPool;

void Camera_UpdateMode(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    f32 diff;
    bool cameraReadyForRace;
    u32 startMode;
    u32 mode;

    do {
        startMode = mode = camera->mode;
        switch (mode) {
            case CAMERA_MODE_TITLE:
            case CAMERA_MODE_MACHINE_SELECT_CREATE:
            case CAMERA_MODE_MACHINE_SETTINGS:
            case CAMERA_MODE_16:
#ifndef EXPANSION_KIT
            default:
#endif
                break;
            case CAMERA_MODE_COURSE_SELECT:
                Camera_UpdateCourseSelect(camera, cameraSettings);
                break;
            case CAMERA_MODE_RACE_INTRO:
                if (!gGamePaused) {
                    Camera_UpdateRaceIntro(camera, cameraSettings);
                }
                break;
            case CAMERA_MODE_SETUP_RACE:

                cameraReadyForRace = true;

                diff = cameraSettings->parameters.targetFov - cameraSettings->parameters.fov;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                diff = cameraSettings->parameters.targetFrustrumCenterY - cameraSettings->parameters.frustrumCenterY;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                diff = cameraSettings->followSmooth.targetDistance - cameraSettings->followSmooth.distance;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                diff = cameraSettings->followSmooth.targetPitch - cameraSettings->followSmooth.pitch;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                if (cameraReadyForRace) {
                    camera->mode = CAMERA_MODE_RACE;
                    cameraSettings->parameters.fovLerpFactor = 0.2f;
                    cameraSettings->parameters.upLerpFactor = 1.0f;
                    cameraSettings->parameters.frustrumCenterXLerpFactor = 0.1f;
                    cameraSettings->parameters.frustrumCenterYLerpFactor = 0.2f;
                    cameraSettings->followSmooth.distanceLerpFactor = 0.2f;
                    cameraSettings->followSmooth.pitchLerpFactor = 0.2f;
                }
                break;
            case CAMERA_MODE_RACE:
                Camera_UpdateRace(camera, cameraSettings, scriptMgr);
                break;
            case CAMERA_MODE_TITLE_DEMO:
                Camera_UpdateTitleDemo(camera, cameraSettings, scriptMgr);
                break;
            case CAMERA_MODE_FALLING_OFF_TRACK:
                if (!gGamePaused) {
                    Camera_UpdateFallingOffTrack(camera, cameraSettings);
                }
                break;
            case CAMERA_MODE_FINISHED_SUCCESS:
                if (!gGamePaused) {
                    Camera_UpdateFinishedSuccess(camera, cameraSettings, scriptMgr);
                }
                break;
            case CAMERA_MODE_FINISHED_SPECTATE:
                if (!gGamePaused) {
                    Camera_UpdateFinishedSpectate(camera, cameraSettings, scriptMgr);
                }
                break;
            case CAMERA_MODE_FINISHED_LOSER:
                if (!gGamePaused) {
                    Camera_UpdateFinishedLoser(camera, cameraSettings, scriptMgr);
                }
                break;
#ifdef EXPANSION_KIT
            case CAMERA_MODE_RECORDS_RACE:
                Camera_UpdateRecordsRace(camera, cameraSettings, scriptMgr);
                break;
#endif
            case CAMERA_MODE_ENDING:
                Camera_UpdateEnding(camera, cameraSettings, scriptMgr);
                break;
        }
        mode = camera->mode;
    } while (startMode != mode);

    Camera_SettingsUpdate(cameraSettings, camera);
    Camera_SettingsUpdateRaceIntroStart(camera, cameraSettings);
    Camera_UpdateFromSettings(camera, cameraSettings);
    func_8071315C(camera);
    Camera_UpdateProjectionViewMtx(gGfxPool, camera);
    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_TIME_ATTACK) ||
        (gGameMode == GAMEMODE_DEATH_RACE)) {
        Camera_UpdateEnemyEnginePan(camera);
    }
}

void Camera_SettingsUpdateRaceIntroStart(Camera* camera, CameraSettings* cameraSettings) {
    CameraRaceSettingInfo* raceSettingInfo;
    s32 angle;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    Mtx3F basis;
    f32 temp_fv0;
    f32 temp_fv1;
    CameraParameters* params = &cameraSettings->parameters;
    Racer* racer;

    if (camera->mode == CAMERA_MODE_RACE_INTRO) {
        if (gNumPlayers == 2) {
            raceSettingInfo = &kWidescreenCameraRaceSettings[CAMERA_RACE_SETTING_REGULAR];
        } else {
            raceSettingInfo = &kRegularCameraRaceSettings[CAMERA_RACE_SETTING_REGULAR];
        }

        racer = &gRacers[camera->id];

        basis.x.x = 0.0f - (raceSettingInfo->distance * racer->trueBasis.x.x);
        basis.x.y = 0.0f - (raceSettingInfo->distance * racer->trueBasis.x.y);
        basis.x.z = 0.0f - (raceSettingInfo->distance * racer->trueBasis.x.z);
        temp_fv1 = 1.0f / sqrtf(SQ(basis.x.x) + SQ(basis.x.y) + SQ(basis.x.z));
        basis.x.x *= temp_fv1;
        basis.x.y *= temp_fv1;
        basis.x.z *= temp_fv1;

        basis.z.x = (racer->trueBasis.y.y * basis.x.z) - (racer->trueBasis.y.z * basis.x.y);
        basis.z.y = (racer->trueBasis.y.z * basis.x.x) - (racer->trueBasis.y.x * basis.x.z);
        basis.z.z = (racer->trueBasis.y.x * basis.x.y) - (racer->trueBasis.y.y * basis.x.x);
        temp_fv1 = 1.0f / sqrtf(SQ(basis.z.x) + SQ(basis.z.y) + SQ(basis.z.z));
        basis.z.x *= temp_fv1;
        basis.z.y *= temp_fv1;
        basis.z.z *= temp_fv1;

        basis.y.x = (basis.x.y * basis.z.z) - (basis.x.z * basis.z.y);
        basis.y.y = (basis.x.z * basis.z.x) - (basis.x.x * basis.z.z);
        basis.y.z = (basis.x.x * basis.z.y) - (basis.x.y * basis.z.x);
        temp_fv1 = 1.0f / sqrtf(SQ(basis.y.x) + SQ(basis.y.y) + SQ(basis.y.z));
        basis.y.x *= temp_fv1;
        basis.y.y *= temp_fv1;
        basis.y.z *= temp_fv1;

        angle = Math_Round(DEG_TO_FZXANG2(raceSettingInfo->pitch));

        temp_fv0 = (SIN(angle) * raceSettingInfo->distance) *
                   ((basis.y.x * racer->trueBasis.y.x) + (basis.y.y * racer->trueBasis.y.y) +
                    (basis.y.z * racer->trueBasis.y.z));
        temp_fv1 = COS(angle) * raceSettingInfo->distance;

        temp1 = (racer->focusPos.x + (temp_fv1 * basis.x.x) + (temp_fv0 * basis.y.x));
        temp2 = (racer->focusPos.y + (temp_fv1 * basis.x.y) + (temp_fv0 * basis.y.y));
        temp3 = (racer->focusPos.z + (temp_fv1 * basis.x.z) + (temp_fv0 * basis.y.z));

        temp_fv0 = (f32) (camera->timer - 1) / 300.0f;

        temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);

        params->eye.x = ((1.0f - temp_fv0) * params->eye.x) + (temp_fv0 * temp1);
        params->eye.y = ((1.0f - temp_fv0) * params->eye.y) + (temp_fv0 * temp2);
        params->eye.z = ((1.0f - temp_fv0) * params->eye.z) + (temp_fv0 * temp3);

        basis.x.x = params->at.x - params->eye.x;
        basis.x.y = params->at.y - params->eye.y;
        basis.x.z = params->at.z - params->eye.z;
        basis.y.x = racer->trueBasis.y.x;
        basis.y.y = racer->trueBasis.y.y;
        basis.y.z = racer->trueBasis.y.z;
        Math_OrthonormalizeAroundForward(&basis);
        params->up.x = params->targetUp.x = basis.y.x;
        params->up.y = params->targetUp.y = basis.y.y;
        params->up.z = params->targetUp.z = basis.y.z;
    }
}

extern bool D_80141D6C;
extern bool D_80141D70;
extern s32 D_i2_80106F10;
extern s32 sNumCameras;
extern s16 D_800E5FBC;

void Camera_UpdateViewportTransition(void) {
    Racer* racer;
    f32 temp_fv0;
    s32 i;
    Camera* camera;
    Vp* vp;

    if (sMultiplayerFocusCameraId == -1) {
        if ((D_800E5FBC != 0) && D_80141D6C) {
            D_i2_80106F10 = 30;

            for (i = 0, camera = gCameras; i < sNumCameras; i++, camera++) {
                racer = &gRacers[i];
                if (racer->position == 1) {
                    sMultiplayerFocusCameraId = i;
                }
                camera->vpTransitionState = CAMERA_VP_TRANSITION_ACTIVE;
                camera->transitionTimer = 0;
                camera->transitionTime = 30;
            }

            switch (gGameMode) {
                case GAMEMODE_VS_2P:
                    if (sMultiplayerFocusCameraId == 0) {
                        gCameras[0].endScissorTop = 8.0f;
                        gCameras[0].endScissorBottom = 231.0f;
                        gCameras[0].endVpScaleY = 120.0f;
                        gCameras[0].endVpTransY = 0.0f;
                        gCameras[1].endScissorTop = 231.0f;
                        gCameras[1].endScissorBottom = 231.0f;
                        gCameras[1].endVpScaleY = 0.0f;
                        gCameras[1].endVpTransY = 240.0f;
                    } else {
                        gCameras[0].endScissorTop = 8.0f;
                        gCameras[0].endScissorBottom = 8.0f;
                        gCameras[0].endVpScaleY = 0.0f;
                        gCameras[0].endVpTransY = 0.0f;
                        gCameras[1].endScissorTop = 8.0f;
                        gCameras[1].endScissorBottom = 231.0f;
                        gCameras[1].endVpScaleY = 120.0f;
                        gCameras[1].endVpTransY = 0.0f;
                    }
                    break;
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                    switch (sMultiplayerFocusCameraId) {
                        case 0:
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorRight = 307.0f;
                            gCameras[0].endScissorBottom = 231.0f;
                            gCameras[0].endVpScaleX = 160.0f;
                            gCameras[0].endVpScaleY = 120.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 231.0f;
                            gCameras[1].endScissorRight = 307.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[1].endVpScaleX = 160.0f;
                            gCameras[1].endVpScaleY = 0.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 240.0f;
                            gCameras[2].endScissorLeft = 307.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorBottom = 231.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[2].endVpScaleX = 0.0f;
                            gCameras[2].endVpScaleY = 120.0f;
                            gCameras[2].endVpTransX = 320.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endScissorLeft = 307.0f;
                            gCameras[3].endScissorTop = 231.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[3].endVpScaleX = 0.0f;
                            gCameras[3].endVpScaleY = 0.0f;
                            gCameras[3].endVpTransX = 320.0f;
                            gCameras[3].endVpTransY = 240.0f;
                            break;
                        case 1:
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorRight = 307.0f;
                            gCameras[0].endScissorBottom = 8.0f;
                            gCameras[0].endVpScaleX = 160.0f;
                            gCameras[0].endVpScaleY = 0.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 8.0f;
                            gCameras[1].endScissorRight = 307.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[1].endVpScaleX = 160.0f;
                            gCameras[1].endVpScaleY = 120.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 0.0f;
                            gCameras[2].endScissorLeft = 307.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[2].endScissorBottom = 8.0f;
                            gCameras[2].endVpScaleX = 0.0f;
                            gCameras[2].endVpScaleY = 0.0f;
                            gCameras[2].endVpTransX = 320.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endScissorLeft = 307.0f;
                            gCameras[3].endScissorTop = 8.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[3].endVpScaleX = 0.0f;
                            gCameras[3].endVpScaleY = 120.0f;
                            gCameras[3].endVpTransX = 320.0f;
                            gCameras[3].endVpTransY = 0.0f;
                            break;
                        case 2:
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorRight = 12.0f;
                            gCameras[0].endScissorBottom = 231.0f;
                            gCameras[0].endVpScaleX = 0.0f;
                            gCameras[0].endVpScaleY = 120.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 231.0f;
                            gCameras[1].endScissorRight = 12.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[1].endVpScaleX = 0.0f;
                            gCameras[1].endVpScaleY = 0.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 240.0f;
                            gCameras[2].endScissorLeft = 12.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[2].endScissorBottom = 231.0f;
                            gCameras[2].endVpScaleX = 160.0f;
                            gCameras[2].endVpScaleY = 120.0f;
                            gCameras[2].endVpTransX = 0.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endScissorLeft = 12.0f;
                            gCameras[3].endScissorTop = 231.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[3].endVpScaleX = 160.0f;
                            gCameras[3].endVpScaleY = 0.0f;
                            gCameras[3].endVpTransX = 0.0f;
                            gCameras[3].endVpTransY = 240.0f;
                            break;
                        case 3:
                            gCameras[0].endVpScaleX = 0.0f;
                            gCameras[0].endVpScaleY = 0.0f;
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorRight = 12.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorBottom = 8.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorRight = 12.0f;
                            gCameras[2].endScissorLeft = 12.0f;
                            gCameras[3].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 8.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorBottom = 8.0f;
                            gCameras[3].endScissorTop = 8.0f;
                            gCameras[1].endVpScaleY = 120.0f;
                            gCameras[3].endVpScaleY = 120.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[2].endVpScaleX = 160.0f;
                            gCameras[3].endVpScaleX = 160.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[1].endVpScaleX = 0.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 0.0f;
                            gCameras[2].endVpScaleY = 0.0f;
                            gCameras[2].endVpTransX = 0.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endVpTransX = 0.0f;
                            gCameras[3].endVpTransY = 0.0f;
                            break;
                    }
                    break;
            }
        }
    } else if ((gCameras[sMultiplayerFocusCameraId].transitionTimer == 30) && !D_80141D70) {
        D_80141D70 = true;
    }

    for (i = 0, camera = gCameras; i < sNumCameras; i++, camera++) {
        if (camera->vpTransitionState != CAMERA_VP_TRANSITION_ACTIVE) {
            continue;
        }
        if (camera->transitionTimer < camera->transitionTime) {
            camera->transitionTimer++;
        }

        temp_fv0 = (f32) camera->transitionTimer / camera->transitionTime;

        camera->currentScissorLeft =
            camera->startScissorLeft + ((camera->endScissorLeft - camera->startScissorLeft) * temp_fv0);
        camera->currentScissorTop =
            camera->startScissorTop + ((camera->endScissorTop - camera->startScissorTop) * temp_fv0);
        camera->currentScissorRight =
            camera->startScissorRight + ((camera->endScissorRight - camera->startScissorRight) * temp_fv0);
        camera->currentScissorBottom =
            camera->startScissorBottom + ((camera->endScissorBottom - camera->startScissorBottom) * temp_fv0);
        camera->currentVpScaleX = camera->startVpScaleX + ((camera->endVpScaleX - camera->startVpScaleX) * temp_fv0);
        camera->currentVpScaleY = camera->startVpScaleY + ((camera->endVpScaleY - camera->startVpScaleY) * temp_fv0);
        camera->currentVpTransX = camera->startVpTransX + ((camera->endVpTransX - camera->startVpTransX) * temp_fv0) +
                                  camera->currentVpScaleX;
        camera->currentVpTransY = camera->startVpTransY + ((camera->endVpTransY - camera->startVpTransY) * temp_fv0) +
                                  camera->currentVpScaleY;

        vp = &gGfxPool->unk_2C2C8[i];
        vp->vp.vscale[0] = camera->currentVpScaleX * 4.0f;
        vp->vp.vscale[1] = camera->currentVpScaleY * 4.0f;
        vp->vp.vscale[2] = 0x1FF;
        vp->vp.vscale[3] = 0;
        vp->vp.vtrans[0] = camera->currentVpTransX * 4.0f;
        vp->vp.vtrans[1] = camera->currentVpTransY * 4.0f;
        vp->vp.vtrans[2] = 0x1FF;
        vp->vp.vtrans[3] = 0;
    }
}

void Camera_UpdateRaceIntro(Camera* camera, CameraSettings* cameraSettings) {
    CameraRaceSettingInfo* raceSettingInfo;
    f32 temp_fv0;
    s32 index;
    CameraParameters* params = &cameraSettings->parameters;
    Racer* racer = &gRacers[camera->id];
    CameraTypeOrbit* orbit = &cameraSettings->orbit;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;
    s32 pad[5];

    orbit->anchorPos = racer->focusPos;
    orbit->basis = racer->trueBasis;

    temp_fv0 = (f32) camera->timer / 300.0f;
    temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);
    orbit->targetDistance = (-880.0f * temp_fv0) + 1000.0f;
    orbit->targetYaw = (-360.0f * temp_fv0) + 180.0f;

    if (camera->timer >= 300) {
        if (gNumPlayers == 2) {
            Camera_SettingsSetFollowSmooth(cameraSettings, &D_800D544C.data);
            raceSettingInfo = &kWidescreenCameraRaceSettings[CAMERA_RACE_SETTING_REGULAR];
        } else {
            Camera_SettingsSetFollowSmooth(cameraSettings, &D_800D5358.data);
            raceSettingInfo = &kRegularCameraRaceSettings[CAMERA_RACE_SETTING_REGULAR];
        }
        camera->mode = CAMERA_MODE_SETUP_RACE;

        followSmooth->centerPos.x = 0.0f;
        followSmooth->centerPos.y = 0.0f;
        followSmooth->centerPos.z = 0.0f;

        followSmooth->distance = raceSettingInfo->distance;
        followSmooth->pitch = raceSettingInfo->pitch;
        params->fov = raceSettingInfo->fov;

        if (gNumPlayers == 2) {
            raceSettingInfo = &kWidescreenCameraRaceSettings[camera->raceSetting];
        } else {
            raceSettingInfo = &kRegularCameraRaceSettings[camera->raceSetting];
        }
        followSmooth->targetDistance = raceSettingInfo->distance;
        followSmooth->targetPitch = raceSettingInfo->pitch;
        params->targetFov = raceSettingInfo->fov;

        racer = &gRacers[camera->id];
        followSmooth->anchorPoint.x = racer->focusPos.x - (raceSettingInfo->distance * racer->trueBasis.x.x);
        followSmooth->anchorPoint.y = racer->focusPos.y - (raceSettingInfo->distance * racer->trueBasis.x.y);
        followSmooth->anchorPoint.z = racer->focusPos.z - (raceSettingInfo->distance * racer->trueBasis.x.z);

        camera->focusPos = racer->focusPos;
        camera->racerBasis = racer->trueBasis;

        camera->targetFov = cameraSettings->parameters.targetFov;
        camera->fovFlags = 0;
        if ((camera->raceSetting == CAMERA_RACE_SETTING_CLOSE_BEHIND) ||
            (camera->raceSetting == CAMERA_RACE_SETTING_REGULAR)) {
            camera->fovFlags |= CAMERA_FOV_FLAG_1;
        }
        followSmooth->distanceLerpFactor = followSmooth->pitchLerpFactor = 0.1f;
        params->upLerpFactor = 0.1f;
        params->fovLerpFactor = 0.1f;
        params->frustrumCenterYLerpFactor = 0.1f;
    } else {
        camera->timer++;
    }
}

extern s16 D_800E5FBC;
extern s32 gCurrentGhostType;
extern s32 gFastestGhostTime;

void Camera_UpdateRace(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    f32 var_fa0;
    f32 var_fv1;
    s32 playerIndex;
    bool settingChanged;
    CameraParameters* params;
    s32 pad[4];
    Racer* racer;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;
    Controller* controller;

    playerIndex = camera->id;
    racer = &gRacers[playerIndex];
    if (!gGamePaused) {
        if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
            camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
            Camera_InitMode(camera, cameraSettings, scriptMgr);
            return;
        }
        if (racer->stateFlags & RACER_STATE_FINISHED) {
            if ((gNumPlayers >= 2) && (D_800E5FBC != 0)) {
                camera->mode = CAMERA_MODE_FINISHED_SPECTATE;
                Camera_InitMode(camera, cameraSettings, scriptMgr);
                return;
            }
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if ((gCurrentGhostType != GHOST_STAFF) && (gCurrentGhostType != GHOST_CELEBRITY) &&
                    (gCurrentGhostType != GHOST_CHAMP)) {
                    camera->mode = CAMERA_MODE_FINISHED_SUCCESS;
                } else if (racer->raceTime < gFastestGhostTime) {
                    camera->mode = CAMERA_MODE_FINISHED_SUCCESS;
                } else {
                    camera->mode = CAMERA_MODE_FINISHED_LOSER;
                }
            } else {
                camera->mode = CAMERA_MODE_FINISHED_SUCCESS;
            }
            Camera_InitMode(camera, cameraSettings, scriptMgr);
            return;
        }
    }

    controller = &gControllers[gPlayerControlPorts[playerIndex]];
    settingChanged = false;

    if (!(racer->stateFlags & RACER_STATE_RETIRED) && (controller->buttonPressed & BTN_CRIGHT)) {
        settingChanged = true;
        if (++camera->raceSetting == CAMERA_RACE_SETTING_MAX) {
            camera->raceSetting = CAMERA_RACE_SETTING_OVERHEAD;
        }
    }
    if (settingChanged) {
        Camera_RaceSettingChanged(camera, &cameraSettings->parameters, followSmooth, gNumPlayers);
    }
    params = &cameraSettings->parameters;
    if (sAllowCameraLookBack && !gGamePaused) {
        if ((controller->buttonCurrent & BTN_CUP) && !(racer->stateFlags & RACER_STATE_RETIRED)) {
            if (++camera->lookBackRotate > sMaxCameraLookBackRotate) {
                camera->lookBackRotate = sMaxCameraLookBackRotate;
            }
        } else {
            if (--camera->lookBackRotate < 0) {
                camera->lookBackRotate = 0;
            }
        }
        followSmooth->targetYaw = (camera->lookBackRotate * 180.0f) / sMaxCameraLookBackRotate;
    }
    if (camera->fovFlags & CAMERA_FOV_FLAG_1) {

        var_fv1 = sqrtf(SQ(racer->unk_5C.x) + SQ(racer->unk_5C.z)) - D_800CDA90;
        if (var_fv1 < 0.0f) {
            var_fa0 = camera->targetFov;
        } else {
            var_fv1 /= (D_800CDA94 - D_800CDA90);
            if (var_fv1 > 1.0f) {
                var_fv1 = 1.0f;
            }

            var_fa0 = camera->targetFov + ((120.0f - camera->targetFov) * var_fv1);
        }
        if (camera->fovFlags & CAMERA_FOV_FLAG_2) {
            params->targetFov = var_fa0;
        } else {
            params->targetFov = var_fa0;
            params->fov = var_fa0;
        }
    }
    var_fv1 = params->targetFov - params->fov;

    if (ABS(var_fv1) < 0.1f) {
        camera->fovFlags &= ~CAMERA_FOV_FLAG_2;
    }
}

void Camera_UpdateTitleDemo(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    s32 playerIndex = camera->id;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, scriptMgr);
    }
}

extern s8 D_i5_801190D0;

void Camera_UpdateCourseSelect(Camera* camera, CameraSettings* cameraSettings) {
    s32 i;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;

    if (D_i5_801190D0) {
        orbit->targetYaw += 1.0f;
        if (orbit->targetYaw >= 360.0f) {
            orbit->targetYaw -= 360.0f;
        }
        if (camera->state == CAMERA_COURSE_SELECT_ACCEPT_INPUTS) {
            for (i = 0; i < gNumPlayers; i++) {
                Controller* controller = &gControllers[gPlayerControlPorts[i]];

                if (controller->buttonCurrent & BTN_CUP) {
                    orbit->targetPitch += 0.1f;
                }
                if (controller->buttonCurrent & BTN_CDOWN) {
                    orbit->targetPitch -= 0.1f;
                }
            }
        } else {
            camera->state = CAMERA_COURSE_SELECT_ACCEPT_INPUTS;
            orbit->targetPitch = 20.0f;
        }

        if (orbit->targetPitch < -50.0f) {
            orbit->targetPitch = -50.0f;
        } else if (orbit->targetPitch > 90.0f) {
            orbit->targetPitch = 90.0f;
        }
    }
}

void Camera_UpdateFallingOffTrack(Camera* camera, CameraSettings* cameraSettings) {
    CameraTypeAtEye* atEye = &cameraSettings->atEye;

#ifndef EXPANSION_KIT
    atEye->targetAt = gRacers[camera->id].segmentPositionInfo.pos;
#else
    atEye->targetAt = gRacers[camera->id].focusPos;
#endif
}

void Camera_UpdateFinishedSuccess(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    s32 pad;
    Vec3f* eye = &sFinishedSuccessFollowRacerEye[camera->id];
    FinishedSuccessScript* finishedSuccessScript = &gFinishedSuccessScript[camera->state];
    CameraParameters* params = &cameraSettings->parameters;
    s16 lastType = finishedSuccessScript->type;
    Racer* racer = &gRacers[camera->id];
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;
    CameraTypeAtEye* atEye = &cameraSettings->atEye;
    LerpLocalAtEyeInfo* lerpLocalAtEyeInfo;

    if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, scriptMgr);
        return;
    }
    switch (finishedSuccessScript->type) {
        case FINISHED_SUCCESS_FIXED_FOLLOW_RACER:
            atEye->targetAt = racer->focusPos;
            atEye->targetEye.x = eye->x;
            atEye->targetEye.y = eye->y;
            atEye->targetEye.z = eye->z;
            break;
        case FINISHED_SUCCESS_LERP_LOCAL_AT_EYE:
            lerpLocalAtEyeInfo = (LerpLocalAtEyeInfo*) finishedSuccessScript->data;

            localAnchor->basis = racer->trueBasis;

            params->targetUp.x = localAnchor->basis.y.x;
            params->targetUp.y = localAnchor->basis.y.y;
            params->targetUp.z = localAnchor->basis.y.z;
            localAnchor->anchorPoint = racer->focusPos;

            localAnchor->targetLocalAt.x =
                lerpLocalAtEyeInfo->startAt.x +
                ((((lerpLocalAtEyeInfo->endAt.x - lerpLocalAtEyeInfo->startAt.x) * camera->timer) /
                  finishedSuccessScript->time) *
                 lerpLocalAtEyeInfo->atTranslationScale);
            localAnchor->targetLocalAt.y =
                lerpLocalAtEyeInfo->startAt.y +
                ((((lerpLocalAtEyeInfo->endAt.y - lerpLocalAtEyeInfo->startAt.y) * camera->timer) /
                  finishedSuccessScript->time) *
                 lerpLocalAtEyeInfo->atTranslationScale);
            localAnchor->targetLocalAt.z =
                lerpLocalAtEyeInfo->startAt.z +
                ((((lerpLocalAtEyeInfo->endAt.z - lerpLocalAtEyeInfo->startAt.z) * camera->timer) /
                  finishedSuccessScript->time) *
                 lerpLocalAtEyeInfo->atTranslationScale);

            localAnchor->targetLocalEye.x =
                lerpLocalAtEyeInfo->startEye.x +
                ((((lerpLocalAtEyeInfo->endEye.x - lerpLocalAtEyeInfo->startEye.x) * camera->timer) /
                  finishedSuccessScript->time) *
                 lerpLocalAtEyeInfo->eyeTranslationScale);
            localAnchor->targetLocalEye.y =
                lerpLocalAtEyeInfo->startEye.y +
                ((((lerpLocalAtEyeInfo->endEye.y - lerpLocalAtEyeInfo->startEye.y) * camera->timer) /
                  finishedSuccessScript->time) *
                 lerpLocalAtEyeInfo->eyeTranslationScale);
            localAnchor->targetLocalEye.z =
                lerpLocalAtEyeInfo->startEye.z +
                ((((lerpLocalAtEyeInfo->endEye.z - lerpLocalAtEyeInfo->startEye.z) * camera->timer) /
                  finishedSuccessScript->time) *
                 lerpLocalAtEyeInfo->eyeTranslationScale);
        default:
            break;
    }

    if (camera->timer >= finishedSuccessScript->time) {
        camera->timer = 0;
        if (++camera->state >= CAMERA_FINISHED_SUCCESS_STATE_COUNT) {
            camera->mode = CAMERA_MODE_FINISHED_SPECTATE;
            Camera_InitMode(camera, cameraSettings, scriptMgr);
            return;
        }
        finishedSuccessScript = &gFinishedSuccessScript[camera->state];
        params->targetFov = finishedSuccessScript->fov;

        switch (finishedSuccessScript->type) {
            case FINISHED_SUCCESS_FIXED_FOLLOW_RACER:
                if (lastType != finishedSuccessScript->type) {
                    Camera_SettingsSetAtEye(cameraSettings, &kDefaultAtEyeData.data);
                }
                params->targetUp.x = 0.0f;
                params->targetUp.y = 1.0f;
                params->targetUp.z = 0.0f;
                Camera_SetupFinishedSuccessFollowRacer(eye, racer->segmentPositionInfo.courseSegment,
                                                       racer->segmentPositionInfo.segmentTValue, finishedSuccessScript);
                atEye->targetAt = racer->focusPos;
                atEye->targetEye.x = eye->x;
                atEye->targetEye.y = eye->y;
                atEye->targetEye.z = eye->z;
                break;
            case FINISHED_SUCCESS_LERP_LOCAL_AT_EYE:
                if (lastType != finishedSuccessScript->type) {
                    Camera_SettingsSetLocalAnchor(cameraSettings, &kDefaultLocalAnchorData.data);
                }
                lerpLocalAtEyeInfo = (LerpLocalAtEyeInfo*) finishedSuccessScript->data;
                localAnchor->targetLocalAt = lerpLocalAtEyeInfo->startAt;
                localAnchor->targetLocalEye = lerpLocalAtEyeInfo->startEye;
                break;
            default:
                break;
        }
    } else {
        camera->timer++;
    }
}

void Camera_SetupFinishedSuccessFollowRacer(Vec3f* eyePos, CourseSegment* segment, f32 racerTValue,
                                            FinishedSuccessScript* finishedSuccessScript) {
    f32 abs;
    f32 t;
    f32 radiusRScale;
    f32 radiusLScale;
    f32 verticalOffset;
    f32 lateralOffset;
    Mtx3F segmentBasis;
    EyeFromRacerInfo* eyeFromRacerInfo = (EyeFromRacerInfo*) finishedSuccessScript->data;

    t = Camera_AdvanceDistanceAlongSegment(&segment, racerTValue, eyeFromRacerInfo->distanceAhead);

    Course_SplineGetPosition(segment, t, eyePos);
    Camera_GetSegmentBasis(&segmentBasis, segment, t);

    radiusLScale = segment->radiusLeft * (1.0f - t) + segment->next->radiusLeft * t;
    radiusRScale = segment->radiusRight * (1.0f - t) + segment->next->radiusRight * t;

    switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_CYLINDER:
            lateralOffset = eyeFromRacerInfo->lateralOffset * radiusRScale;
            verticalOffset = eyeFromRacerInfo->verticalOffset + radiusRScale;
            break;
        case TRACK_SHAPE_HALF_PIPE:
            lateralOffset = eyeFromRacerInfo->lateralOffset * radiusLScale;
            verticalOffset = eyeFromRacerInfo->verticalOffset;
            break;
        default:
            if (eyeFromRacerInfo->lateralOffset >= 0.0f) {
                lateralOffset = eyeFromRacerInfo->lateralOffset * radiusLScale;
            } else {
                lateralOffset = eyeFromRacerInfo->lateralOffset * radiusRScale;
            }
            verticalOffset = eyeFromRacerInfo->verticalOffset;
            break;
    }

    abs = ABS(lateralOffset);
    if (D_800CDA98 < abs) {
        abs = D_800CDA98;
        if (lateralOffset < 0) {
            lateralOffset = 0.0f - abs;
        } else {
            lateralOffset = abs;
        }
    }

    eyePos->x += (segmentBasis.y.x * verticalOffset) + (segmentBasis.z.x * lateralOffset);
    eyePos->y += (segmentBasis.y.y * verticalOffset) + (segmentBasis.z.y * lateralOffset);
    eyePos->z += (segmentBasis.y.z * verticalOffset) + (segmentBasis.z.z * lateralOffset);
}

void Camera_UpdateFinishedLoser(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    CameraTypeAtEye* atEye = &cameraSettings->atEye;

    if (camera->timer <= 60) {
        atEye->targetAt = gRacers[camera->id].segmentPositionInfo.pos;
        camera->timer++;
    }
}

void Camera_UpdateFinishedSpectate(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    s32 pad;
    f32 temp;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;
    Racer* racer = &gRacers[camera->id];
    CameraParameters* params = &cameraSettings->parameters;

    if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, scriptMgr);
        return;
    }
    orbit->basis.y.x += racer->tiltUp.x * 0.3f;
    orbit->basis.y.y += racer->tiltUp.y * 0.3f;
    orbit->basis.y.z += racer->tiltUp.z * 0.3f;

    Math_OrthonormalizeAroundUp(&orbit->basis);

    params->targetUp.x = orbit->basis.y.x;
    params->targetUp.y = orbit->basis.y.y;
    params->targetUp.z = orbit->basis.y.z;

    orbit->anchorPos = racer->focusPos;

    switch (camera->state) {
        case CAMERA_FINISHED_SPECTATE_STILL_ON_RACER:
            if (++camera->timer >= 180) {
                camera->state = CAMERA_FINISHED_SPECTATE_ROTATE_AROUND_RACER;
                camera->timer = 0;
                orbit->distanceLerpFactor = 0.005f;
            }
            break;
        case CAMERA_FINISHED_SPECTATE_ROTATE_AROUND_RACER:
            if (++camera->timer >= 300) {
                camera->timer = 0;
                orbit->targetDistance = (Math_Rand1() % 451) + 50.0f;
            }
            orbit->targetYaw += 0.4f;

            if (orbit->targetYaw >= 360.0f) {
                orbit->targetYaw -= 360.0f;
            }
            break;
        default:
            break;
    }

    if ((sMultiplayerFocusCameraId == camera->id) && (gNumPlayers == 2)) {

        if (camera->transitionTimer < camera->transitionTime) {
            temp = (f32) (camera->transitionTimer + 1) / camera->transitionTime;
            cameraSettings->parameters.targetFrustrumCenterY = -30.0f - (-30.0f * temp);
        } else {
            cameraSettings->parameters.targetFrustrumCenterY = 0.0f;
        }
    }
}

#ifdef EXPANSION_KIT
void Camera_UpdateRecordsRace(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    Racer* racer = &gRacers[camera->id];

    if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, scriptMgr);
    }
}
#endif

extern CameraScript gEndingPosition1FocusScript[];
extern CameraScript gEndingPosition3FocusScript[];
extern CameraScript gEndingPosition2FocusScript[];
extern CameraScript gEndingPodiumPosition1Script[];
extern CameraScript gEndingPodiumPosition2Script[];
extern CameraScript gEndingPodiumPosition3Script[];
extern u16 gEndingFlags;

void Camera_UpdateEnding(Camera* camera, CameraSettings* cameraSettings, CameraScriptManager* scriptMgr) {
    s32 continueProcessing = true;
    Racer* racer;
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;
    CameraScript* script;

    while (continueProcessing) {

        continueProcessing = false;
        switch (camera->state) {
            case CAMERA_ENDING_DRIVE_INTO_CAMERA:
                if (Camera_CheckEndingCameraMessage(ENDING_CAMERA_1)) {
                    if (gEndingFlags & ENDING_NOT_ON_PODIUM) {
                        continueProcessing = true;
                        camera->state = CAMERA_ENDING_FIXED_FOCUS_RACER;
                        Camera_SettingsSetLocalAnchor(cameraSettings, &kDefaultLocalAnchorData.data);
                        localAnchor = &cameraSettings->localAnchor;
                        localAnchor->targetLocalAt.x = localAnchor->targetLocalAt.y = localAnchor->targetLocalAt.z =
                            0.0f;
                        localAnchor->targetLocalEye.x = 0.0f;
                        localAnchor->targetLocalEye.y = 37.0f;
                        localAnchor->targetLocalEye.z = -132.0f;
                    } else {
                        camera->state = CAMERA_ENDING_FOLLOW_RACER;
                        camera->timer = 0;
                        if (sCameraEndingFocusRacer == 0) {
                            script = gEndingPosition1FocusScript;
                        } else if (sCameraEndingFocusRacer == 1) {
                            script = gEndingPosition2FocusScript;
                        } else {
                            script = gEndingPosition3FocusScript;
                        }
                        Camera_ScriptSetScript(scriptMgr, script);
                        racer = &gRacers[sCameraEndingFocusRacer];
                        Camera_ScriptSetRacerInfo(&sCameraScriptMgrs[camera->id], &racer->focusPos, &racer->trueBasis,
                                                  racer);
                    }
                }
                break;
            case CAMERA_ENDING_FOLLOW_RACER:
                if (Camera_ScriptUpdate(scriptMgr)) {
                    camera->state = CAMERA_ENDING_FIXED_FOCUS_RACER;
                    localAnchor = &cameraSettings->localAnchor;
                    localAnchor->targetLocalAt.x = 0.0f;
                    localAnchor->targetLocalAt.y = 0.0f;
                    localAnchor->targetLocalAt.z = 0.0f;
                    localAnchor->targetLocalEye.x = 0.0f;
                    localAnchor->targetLocalEye.y = 37.0f;
                    continueProcessing = true;
                    if (gEndingFlags & ENDING_SHOW_PODIUM_SEQUENCE) {
                        localAnchor->targetLocalEye.z = 132.0f;
                    } else {
                        localAnchor->targetLocalEye.z = -132.0f;
                    }
                }
                break;
            case CAMERA_ENDING_FIXED_FOCUS_RACER:
                racer = &gRacers[sCameraEndingFocusRacer];
                localAnchor = &cameraSettings->localAnchor;
                localAnchor->basis = racer->trueBasis;
                localAnchor->anchorPoint = racer->focusPos;
                if (Camera_CheckEndingCameraMessage(ENDING_CAMERA_PODIUM_P3)) {
                    camera->state = CAMERA_ENDING_PODIUM_P3;
                    camera->timer = 0;
                    racer = &gRacers[2];
                    Camera_ScriptSetRacerInfo(&sCameraScriptMgrs[camera->id], &racer->focusPos, &racer->trueBasis,
                                              racer);
                    Camera_ScriptSetScript(scriptMgr, gEndingPodiumPosition3Script);
                }
                break;
            case CAMERA_ENDING_PODIUM_P3:
                if (Camera_ScriptUpdate(scriptMgr) && Camera_CheckEndingCameraMessage(ENDING_CAMERA_PODIUM_P2)) {
                    camera->state = CAMERA_ENDING_PODIUM_P2;
                    camera->timer = 0;
                    racer = &gRacers[1];
                    Camera_ScriptSetRacerInfo(&sCameraScriptMgrs[camera->id], &racer->focusPos, &racer->trueBasis,
                                              racer);
                    Camera_ScriptSetScript(scriptMgr, gEndingPodiumPosition2Script);
                }
                break;
            case CAMERA_ENDING_PODIUM_P2:
                if (Camera_ScriptUpdate(scriptMgr) && Camera_CheckEndingCameraMessage(ENDING_CAMERA_PODIUM_P1)) {
                    camera->state = CAMERA_ENDING_PODIUM_P1;
                    camera->timer = 0;
                    racer = &gRacers[0];
                    Camera_ScriptSetRacerInfo(&sCameraScriptMgrs[camera->id], &racer->focusPos, &racer->trueBasis,
                                              racer);
                    Camera_ScriptSetScript(scriptMgr, gEndingPodiumPosition1Script);
                }
                break;
            case CAMERA_ENDING_PODIUM_P1:
                Camera_ScriptUpdate(scriptMgr);
                break;
        }
    }
}

void Camera_SendEndingCameraMessage(s32 msg) {
    sEndingCameraMessage = msg;
}

bool Camera_CheckEndingCameraMessage(s32 msg) {
    bool matchingMsg = false;

    if (msg == sEndingCameraMessage) {
        matchingMsg = true;
        sEndingCameraMessage = 0;
    }
    return matchingMsg;
}

#ifdef EXPANSION_KIT
Gfx* Camera_DrawCourseEditTestRun(Gfx* gfx) {

    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
    gSPMatrix(gfx++, &D_1000000.unk_20208[gCameras[0].id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    return Camera_Draw(gfx, SCISSOR_BOX_FULL_SCREEN, gCameras[0].id);
}
#endif
