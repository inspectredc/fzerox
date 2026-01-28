#include "global.h"
#include "fzx_camera.h"

extern const CameraLocalAnchorData kDefaultLocalAnchorData;

f32 D_i7_8014AFA0[] = { 0.0f, 0.0f, 0.0f, -25.0f, -25.0f, -25.0f };

f32 D_i7_8014AFB8[] = { 0.0f, 0.0f, 0.0f, 300.0f, 300.0f, 300.0f };

f32 D_i7_8014AFD0[] = { 0.0f, 0.0f, 0.0f, -285.0f, -285.0f, -285.0f };

s32 D_i7_8014AFE8[] = { 160, 130, 190 };

f32 D_i7_8014AFF4[] = { 0.0f, 0.0f, -27.0f, -27.0f, -27.0f, -27.0f };

f32 D_i7_8014B00C[] = { 20.0f, 20.0f, 20.0f, 196.0f, 196.0f, 196.0f };

f32 D_i7_8014B024[] = { 199.0f, 199.0f, 154.0f, 154.0f, 154.0f, 154.0f };

s32 D_i7_8014B03C[] = { 160, 160, 160 };

CubicBSpline3fData D_i7_8014B048[] = {
    { 6, D_i7_8014AFA0, D_i7_8014AFB8, D_i7_8014AFD0, D_i7_8014AFE8 },
    { 6, D_i7_8014AFF4, D_i7_8014B00C, D_i7_8014B024, D_i7_8014B03C },
};

CameraScript gEndingPodiumPosition1Script[] = {
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 480, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014B048 },
    { CAMERA_SCRIPT_BREAK, NULL, 0 },
};

f32 D_i7_8014B0A0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014B0B8[] = { 0.0f, 0.0f, 0.0f, 80.0f, 80.0f, 80.0f };

f32 D_i7_8014B0D0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014B0E8[] = { 125, 100, 75 };

f32 D_i7_8014B0F4[] = { 0.0f, 125.0f, 113.0f, -36.0f, -36.0f, -36.0f };

f32 D_i7_8014B10C[] = { 42.0f, 35.0f, 59.0f, 86.0f, 86.0f, 86.0f };

f32 D_i7_8014B124[] = { -139.0f, -63.0f, 74.0f, 138.0f, 138.0f, 138.0f };

s32 D_i7_8014B13C[] = { 125, 120, 75 };

f32 D_i7_8014B148[] = { 60.0f, 74.0f, 74.0f, 74.0f };

s32 D_i7_8014B158[] = { 300 };

CubicBSpline331Data D_i7_8014B15C = {
    {
        { 6, D_i7_8014B0A0, D_i7_8014B0B8, D_i7_8014B0D0, D_i7_8014B0E8 },
        { 6, D_i7_8014B0F4, D_i7_8014B10C, D_i7_8014B124, D_i7_8014B13C },
    },
    { 4, D_i7_8014B148, D_i7_8014B158 },
};

CameraScript gEndingPodiumPosition2Script[] = {
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 300, Camera_ScriptUpdateLocalAnchorBasisAtEyeFov, &D_i7_8014B15C },
    { CAMERA_SCRIPT_BREAK, NULL, 0 },
};

f32 D_i7_8014B1C0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014B1D8[] = { 0.0f, 0.0f, 0.0f, 60.0f, 60.0f, 60.0f };

f32 D_i7_8014B1F0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014B208[] = { 170, 150, 130 };

f32 D_i7_8014B214[] = { 325.0f, 325.0f, 33.0f, 48.0f, 48.0f, 48.0f };

f32 D_i7_8014B22C[] = { 60.0f, 60.0f, 26.0f, 87.0f, 87.0f, 87.0f };

f32 D_i7_8014B244[] = { 162.0f, 162.0f, 140.0f, 140.0f, 140.0f, 140.0f };

s32 D_i7_8014B25C[] = { 170, 150, 130 };

f32 D_i7_8014B268[] = { -1.0f, -1.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014B27C[] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };

f32 D_i7_8014B290[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014B2A4[] = { 130, 170 };

f32 D_i7_8014B2AC[] = { 75.0f, 75.0f, 60.0f, 60.0f, 91.4f };

s32 D_i7_8014B2C0[] = { 130, 170 };

CubicBSpline3331Data D_i7_8014B2C8 = {
    {
        { 6, D_i7_8014B1C0, D_i7_8014B1D8, D_i7_8014B1F0, D_i7_8014B208 },
        { 6, D_i7_8014B214, D_i7_8014B22C, D_i7_8014B244, D_i7_8014B25C },
        { 5, D_i7_8014B268, D_i7_8014B27C, D_i7_8014B290, D_i7_8014B2A4 },
    },
    { 5, D_i7_8014B2AC, D_i7_8014B2C0 },
};

CameraScript gEndingPodiumPosition3Script[] = {
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 300, Camera_ScriptUpdateLocalAnchorBasisAtEyeUpFov, &D_i7_8014B2C8 },
    { CAMERA_SCRIPT_BREAK, NULL, 0 },
};
