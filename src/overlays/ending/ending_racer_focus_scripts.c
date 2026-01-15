#include "global.h"
#include "fzx_camera.h"

f32 D_i7_8014A050[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A060[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A070[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A080[] = { 360 };

f32 D_i7_8014A084[] = { 53.0f, -36.0f, -75.0f, -75.0f, -75.0f };

f32 D_i7_8014A098[] = { 20.0f, 61.0f, 9.0f, 9.0f, 9.0f };

f32 D_i7_8014A0AC[] = { -700.0f, 87.0f, 92.0f, 92.0f, 92.0f };

s32 D_i7_8014A0C0[] = { 180, 180 };

CubicBSpline3fData D_i7_8014A0C8[] = {
    { 4, D_i7_8014A050, D_i7_8014A060, D_i7_8014A070, D_i7_8014A080 },
    { 5, D_i7_8014A084, D_i7_8014A098, D_i7_8014A0AC, D_i7_8014A0C0 },
};

f32 D_i7_8014A0F0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A108[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A120[] = { 0.0f, 0.0f, 61.0f, 61.0f, 61.0f, 61.0f };

s32 D_i7_8014A138[] = { 180, 180, 180 };

f32 D_i7_8014A144[] = { 375.0f, 375.0f, 375.0f, -49.0f, -223.0f, -223.0f, -223.0f, -223.0f };

f32 D_i7_8014A164[] = { 140.0f, 140.0f, 140.0f, 57.0f, 11.0f, 11.0f, 11.0f, 11.0f };

f32 D_i7_8014A184[] = { 56.0f, 56.0f, 56.0f, -53.0f, -1.0f, -1.0f, -1.0f, -1.0f };

s32 D_i7_8014A1A4[] = { 60, 60, 60, 180, 180 };

f32 D_i7_8014A1B8[] = { 60.0f, 60.0f, 60.0f, 60.0f };

s32 D_i7_8014A1C8[] = { 540 };

CubicBSpline331Data D_i7_8014A1CC = {
    {
        { 6, D_i7_8014A0F0, D_i7_8014A108, D_i7_8014A120, D_i7_8014A138 },
        { 8, D_i7_8014A144, D_i7_8014A164, D_i7_8014A184, D_i7_8014A1A4 },
    },
    { 4, D_i7_8014A1B8, D_i7_8014A1C8 },
};

f32 D_i7_8014A200[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A210[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A220[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A230[] = { 120 };

f32 D_i7_8014A234[] = { -60.0f, -56.0f, -56.0f, -56.0f };

f32 D_i7_8014A244[] = { 17.0f, 14.0f, 14.0f, 14.0f };

f32 D_i7_8014A254[] = { 229.0f, -85.0f, -85.0f, -85.0f };

s32 D_i7_8014A264[] = { 120 };

f32 D_i7_8014A268[] = { 60.0f, 79.0f, 79.0f, 79.0f };

s32 D_i7_8014A278[] = { 120 };

CubicBSpline331Data D_i7_8014A27C = {
    {
        { 4, D_i7_8014A200, D_i7_8014A210, D_i7_8014A220, D_i7_8014A230 },
        { 4, D_i7_8014A234, D_i7_8014A244, D_i7_8014A254, D_i7_8014A264 },
    },
    { 4, D_i7_8014A268, D_i7_8014A278 },
};

f32 D_i7_8014A2B0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A2C0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A2D0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A2E0[] = { 120 };

f32 D_i7_8014A2E4[] = { 149.0f, -45.0f, -45.0f, -45.0f };

f32 D_i7_8014A2F4[] = { 9.0f, 12.0f, 12.0f, 12.0f };

f32 D_i7_8014A304[] = { 42.0f, 98.0f, 98.0f, 98.0f };

s32 D_i7_8014A314[] = { 120 };

CubicBSpline3fData D_i7_8014A318[] = {
    { 4, D_i7_8014A2B0, D_i7_8014A2C0, D_i7_8014A2D0, D_i7_8014A2E0 },
    { 4, D_i7_8014A2E4, D_i7_8014A2F4, D_i7_8014A304, D_i7_8014A314 },
};

f32 D_i7_8014A340[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A350[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A360[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A370[] = { 300 };

f32 D_i7_8014A374[] = { 43.0f, 43.0f, 43.0f, 43.0f, 43.0f };

f32 D_i7_8014A388[] = { 8.0f, 10.0f, 10.0f, 10.0f, 10.0f };

f32 D_i7_8014A39C[] = { 110.0f, -94.0f, -94.0f, -94.0f, -94.0f };

s32 D_i7_8014A3B0[] = { 120, 180 };

f32 D_i7_8014A3B8[] = { 60.0f, 74.0f, 74.0f, 74.0f };

s32 D_i7_8014A3C8[] = { 300 };

CubicBSpline331Data D_i7_8014A3CC = {
    {
        { 4, D_i7_8014A340, D_i7_8014A350, D_i7_8014A360, D_i7_8014A370 },
        { 5, D_i7_8014A374, D_i7_8014A388, D_i7_8014A39C, D_i7_8014A3B0 },
    },
    { 4, D_i7_8014A3B8, D_i7_8014A3C8 },
};

f32 D_i7_8014A400[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A414[] = { 29.0f, 29.0f, 29.0f, 29.0f, 29.0f };

f32 D_i7_8014A428[] = { -220.0f, 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A43C[] = { 240, 180 };

f32 D_i7_8014A444[] = { 4.0f, 4.0f, 4.0f, -18.0f, -18.0f, -18.0f, -18.0f };

f32 D_i7_8014A460[] = { 6.0f, -18.0f, -18.0f, 7.0f, 7.0f, 7.0f, 7.0f };

f32 D_i7_8014A47C[] = { -110.0f, -34.0f, 38.0f, 108.0f, 108.0f, 108.0f, 108.0f };

s32 D_i7_8014A498[] = { 120, 60, 60, 180 };

CubicBSpline3fData D_i7_8014A4A8[] = {
    { 5, D_i7_8014A400, D_i7_8014A414, D_i7_8014A428, D_i7_8014A43C },
    { 7, D_i7_8014A444, D_i7_8014A460, D_i7_8014A47C, D_i7_8014A498 },
};

extern const CameraLocalAnchorData kDefaultLocalAnchorData;

CameraScript gEndingPosition1FocusScript[] = {
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 360, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014A0C8 },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 540, Camera_ScriptUpdateLocalAnchorBasisAtEye, &D_i7_8014A1CC },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 120, Camera_ScriptUpdateLocalAnchorBasisAtEye, &D_i7_8014A27C },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 120, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014A318 },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 300, Camera_ScriptUpdateLocalAnchorBasisAtEye, &D_i7_8014A3CC },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 420, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014A4A8 },
    { CAMERA_SCRIPT_BREAK, NULL, 0 },
    { CAMERA_SCRIPT_NEXT, NULL, 0 },
};

f32 D_i7_8014A5C0[] = { 0.0f, 0.0f, 0.0f, -125.0f, -125.0f, -125.0f, -125.0f, -125.0f };

f32 D_i7_8014A5E0[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A600[] = { 0.0f, 0.0f, 0.0f, 141.0f, 141.0f, 141.0f, 141.0f, 141.0f };

s32 D_i7_8014A620[] = { 300, 150, 150, 150, 150 };

f32 D_i7_8014A634[] = { 98.0f, 98.0f, 98.0f, 62.0f, 62.0f, 62.0f, 62.0f, 62.0f };

f32 D_i7_8014A654[] = { 20.0f, 20.0f, 20.0f, 38.0f, 38.0f, 38.0f, 38.0f, 38.0f };

f32 D_i7_8014A674[] = { -74.0f, -74.0f, -74.0f, -63.0f, -63.0f, -63.0f, -63.0f, -63.0f };

s32 D_i7_8014A694[] = { 300, 150, 150, 150, 150 };

f32 D_i7_8014A6A8[] = { 70.0f, 70.0f, 70.0f, 70.0f };

s32 D_i7_8014A6B8[] = { 900 };

CubicBSpline331Data D_i7_8014A6BC = {
    {
        { 8, D_i7_8014A5C0, D_i7_8014A5E0, D_i7_8014A600, D_i7_8014A620 },
        { 8, D_i7_8014A634, D_i7_8014A654, D_i7_8014A674, D_i7_8014A694 },
    },
    { 4, D_i7_8014A6A8, D_i7_8014A6B8 },
};

f32 D_i7_8014A6F0[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A700[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A710[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A720[] = { 960 };

f32 D_i7_8014A724[] = { -1.0f, -1.0f, -1.0f, -38.0f, -38.0f, -38.0f, -38.0f, -38.0f };

f32 D_i7_8014A744[] = { 450.0f, 450.0f, 450.0f, 53.0f, 53.0f, 53.0f, 53.0f, 53.0f };

f32 D_i7_8014A764[] = { 79.0f, 79.0f, 79.0f, 79.0f, 79.0f, 79.0f, 79.0f, 79.0f };

s32 D_i7_8014A784[] = { 300, 150, 150, 150, 210 };

f32 D_i7_8014A798[] = { 70.0f, 60.0f, 60.0f, 60.0f };

s32 D_i7_8014A7A8[] = { 960 };

CubicBSpline331Data D_i7_8014A7AC = {
    {
        { 4, D_i7_8014A6F0, D_i7_8014A700, D_i7_8014A710, D_i7_8014A720 },
        { 8, D_i7_8014A724, D_i7_8014A744, D_i7_8014A764, D_i7_8014A784 },
    },
    { 4, D_i7_8014A798, D_i7_8014A7A8 },
};

CameraScript gEndingPosition3FocusScript[] = {
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 900, Camera_ScriptUpdateLocalAnchorBasisAtEyeFov, &D_i7_8014A6BC },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 960, Camera_ScriptUpdateLocalAnchorBasisAtEyeFov, &D_i7_8014A7AC },
    { CAMERA_SCRIPT_BREAK, NULL, 0 },
    { CAMERA_SCRIPT_NEXT, NULL, 0 },
};

f32 D_i7_8014A840[] = { 146.0f, 146.0f, 146.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A858[] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A870[] = { 194.0f, 194.0f, 194.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014A888[] = { 300, 150, 150 };

f32 D_i7_8014A894[] = { -72.0f, -72.0f, -72.0f, -79.0f, 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014A8B4[] = { 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f };

f32 D_i7_8014A8D4[] = { -82.0f, -82.0f, -82.0f, 27.0f, 113.0f, 113.0f, 113.0f, 113.0f };

s32 D_i7_8014A8F4[] = { 250, 125, 75, 75, 75 };

CubicBSpline3fData D_i7_8014A908[] = {
    { 6, D_i7_8014A840, D_i7_8014A858, D_i7_8014A870, D_i7_8014A888 },
    { 8, D_i7_8014A894, D_i7_8014A8B4, D_i7_8014A8D4, D_i7_8014A8F4 },
};

f32 D_i7_8014A930[] = { 0.0f, 0.0f, 0.0f, -29.0f, -29.0f, -29.0f };

f32 D_i7_8014A948[] = { 0.0f, 0.0f, 0.0f, 22.0f, 22.0f, 22.0f };

f32 D_i7_8014A960[] = { 0.0f, 0.0f, 0.0f, 2.0f, 2.0f, 2.0f };

s32 D_i7_8014A978[] = { 300, 150, 150 };

f32 D_i7_8014A984[] = { 0.0f, 0.0f, 86.0f, 86.0f, 86.0f, 86.0f };

f32 D_i7_8014A99C[] = { 30.0f, 45.0f, 41.0f, 41.0f, 41.0f, 41.0f };

f32 D_i7_8014A9B4[] = { 113.0f, 27.0f, 13.0f, 13.0f, 13.0f, 13.0f };

s32 D_i7_8014A9CC[] = { 300, 150, 150 };

CubicBSpline3fData D_i7_8014A9D8[] = {
    { 6, D_i7_8014A930, D_i7_8014A948, D_i7_8014A960, D_i7_8014A978 },
    { 6, D_i7_8014A984, D_i7_8014A99C, D_i7_8014A9B4, D_i7_8014A9CC },
};

f32 D_i7_8014AA00[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AA10[] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AA20[] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014AA30[] = { 300 };

f32 D_i7_8014AA34[] = { -10.0f, -10.0f, -10.0f, -10.0f, -10.0f, -10.0f };

f32 D_i7_8014AA4C[] = { 222.0f, 222.0f, 222.0f, 222.0f, 222.0f, 222.0f };

f32 D_i7_8014AA64[] = { -498.0f, -498.0f, -498.0f, 563.0f, 563.0f, 563.0f };

s32 D_i7_8014AA7C[] = { 100, 100, 100 };

f32 D_i7_8014AA88[] = { 90.0f, 60.0f, 60.0f, 60.0f };

s32 D_i7_8014AA98[] = { 300 };

CubicBSpline331Data D_i7_8014AA9C = {
    {
        { 4, D_i7_8014AA00, D_i7_8014AA10, D_i7_8014AA20, D_i7_8014AA30 },
        { 6, D_i7_8014AA34, D_i7_8014AA4C, D_i7_8014AA64, D_i7_8014AA7C },
    },
    { 4, D_i7_8014AA88, D_i7_8014AA98 },
};

f32 D_i7_8014AAD0[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AAE0[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AAF0[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

s32 D_i7_8014AB00[] = { 360 };

f32 D_i7_8014AB04[] = { -10.0f, 0.0f, 0.0f, 0.0f };

f32 D_i7_8014AB14[] = { 222.0f, 37.0f, 37.0f, 37.0f };

f32 D_i7_8014AB24[] = { 563.0f, 132.0f, 132.0f, 132.0f };

s32 D_i7_8014AB34[] = { 360 };

CubicBSpline3fData D_i7_8014AB38[] = {
    { 4, D_i7_8014AAD0, D_i7_8014AAE0, D_i7_8014AAF0, D_i7_8014AB00 },
    { 4, D_i7_8014AB04, D_i7_8014AB14, D_i7_8014AB24, D_i7_8014AB34 },
};

CameraScript gEndingPosition2FocusScript[] = {
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 600, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014A908 },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 600, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014A9D8 },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 300, Camera_ScriptUpdateLocalAnchorBasisAtEye, &D_i7_8014AA9C },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetLocalAnchorData, &kDefaultLocalAnchorData },
    { CAMERA_SCRIPT_NEXT, Camera_ScriptSetControlPointTimerCount, 4 },
    { 360, Camera_ScriptUpdateLocalAnchorBasisAtEye, D_i7_8014AB38 },
    { CAMERA_SCRIPT_BREAK, NULL, 0 },
};
