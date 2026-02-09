#include "global.h"
#include "leo/mfs.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include "fzx_expansion_kit.h"
#include ASSET_HEADER_EK(course_edit_textures.h)

Controller* D_80119720;
UNUSED s32 D_xk2_80119724;
u16 D_xk2_80119728;
u16 D_xk2_8011972A;
u16 D_xk2_8011972C;
u16 D_xk2_8011972E;
f32 D_xk2_80119730;
f32 D_xk2_80119734;
f32 D_xk2_80119738;
s32 D_xk2_8011973C;
s32 D_xk2_80119740;
f32 D_xk2_80119744;
CourseSegment D_xk2_80119748;
CourseSegment* D_xk2_801197EC;
UNUSED s32 D_xk2_801197F0[4];
s32 D_xk2_80119800;
UNUSED s32 D_xk2_80119808[4];
/* new file? */
Vec3f D_xk2_80119818;
UNUSED s32 D_xk2_8011981C;
Vec3f D_xk2_80119828;
UNUSED s32 D_xk2_8011982C;
Mtx D_xk2_80119838;
UNUSED s32 D_xk2_80119878[2];
/* new file? */
s32 D_80119880;
s32 D_xk2_80119884;
UNUSED s32 D_xk2_80119888[2];
/* new file? */
s32 D_80119890;
UNUSED s32 D_xk2_80119898[32];
s32 D_xk2_80119918;
CourseSegment D_xk2_80119920[64];
unk_8011C220 D_8011C220[898];
unk_80128690 D_80128690[64];
unk_80128690 D_xk2_80128990[64];

s32 D_xk2_800F6820 = 1;
s32 gCourseEditCursorXPos = 160;
s32 gCourseEditCursorYPos = 120;
UNUSED s32 D_xk2_800F682C = 160;
UNUSED s32 D_xk2_800F6830 = 120;
f32 D_xk2_800F6834 = 0.05f;
s32 D_xk2_800F6838 = 0;
s32 D_xk2_800F683C = 0;
s32 D_xk2_800F6840 = 0;
s32 D_xk2_800F6844 = 0;
s32 D_xk2_800F6848 = 0;
s32 D_xk2_800F684C = 0;

s32 D_xk2_800F6850[] = { 0, 1, 2, 4 };

s32 D_xk2_800F6860[] = { 0, 6, 2, 4, 1 };

s32 D_xk2_800F6874[] = { 0, 6, 2, 4, 1 };

s32 D_xk2_800F6888[] = { 0, 6, 2, 4, 1 };

s32 D_xk2_800F689C[] = { -1, 3, 1, -1, 2, -1, 0 };

s32 D_xk2_800F68B8[] = { -1, 0, 1, -1, 2, -1, -1 };

s32 D_xk2_800F68D4[] = { -1, 3, 1, -1, 2, -1, 0 };

s32 D_xk2_800F68F0[] = { -1, 3, 1, -1, 2, -1, 0 };

void func_xk2_800D6D90(s32 arg0, s32 arg1, f32* arg2, f32* arg3) {
    s32 var_v0;
    s32 var_v1;
    f32 temp_fv1;
    s32 temp_ft3;

    temp_fv1 = sqrtf(SQ((f32) arg0) + SQ((f32) arg1));
    if (temp_fv1 <= 16.970562f) {
        var_v0 = 0;
        var_v1 = 0;
    } else {
        temp_fv1 -= 16.970562f;
        temp_ft3 = (func_xk2_800EF5E8((f32) arg1, (f32) arg0) * 4096.0f) / 360.0f;
        if (arg0) {}
        if (arg1) {}
        var_v0 = COS(temp_ft3) * temp_fv1;
        var_v1 = SIN(temp_ft3) * temp_fv1;
        if (var_v0 > 49) {
            var_v1 = (var_v1 * 49) / var_v0;
            var_v0 = 49;
        }
        if (var_v0 < -49) {
            var_v1 = (var_v1 * 49) / (-var_v0);
            var_v0 = -49;
        }
        if (var_v1 > 49) {
            var_v0 = (var_v0 * 49) / var_v1;
            var_v1 = 49;
        }
        if (var_v1 < -49) {
            var_v0 = (var_v0 * 49) / (-var_v1);
            var_v1 = -49;
        }
    }
    *arg2 = var_v0 / 49.0f;
    *arg3 = var_v1 / 49.0f;
}

void func_xk2_800D6FF0(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        Audio_TriggerSystemSE(NA_SE_68);
        D_xk2_80119918 ^= 1;
    }
}

extern s32 D_xk2_80104CB4;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CBC;
extern s32 D_xk2_80104CC0;

void func_xk2_800D7058(void) {

    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L) ||
        ((D_xk2_80119918 != 0) && (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_B))) {
        D_xk2_80104CB4 += 300;
    }
    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R) ||
        ((D_xk2_80119918 != 0) && (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_A))) {
        if (D_xk2_80104CB4 > 300) {
            D_xk2_80104CB4 -= 300;
        } else if (D_xk2_80104CBC > 300) {
            Camera* camera = gCameras;
            D_xk2_80104CB8 = D_xk2_80104CB8 + (camera->basis.x.x * 300.0f);
            D_xk2_80104CBC = D_xk2_80104CBC + (camera->basis.x.y * 300.0f);
            D_xk2_80104CC0 = D_xk2_80104CC0 + (camera->basis.x.z * 300.0f);
        }
    }

    if (D_xk2_80104CBC < 0) {
        D_xk2_80104CBC = 0;
    }
    if (D_xk2_80104CB4 < 300) {
        D_xk2_80104CB4 = 300;
    }
    if (D_xk2_80104CB4 > 16000) {
        D_xk2_80104CB4 = 16000;
    }
}

extern f32 D_xk2_80128D40;
extern f32 D_xk2_80128D44;

void func_xk2_800D71E8(void) {
    f32 temp_fv0;
    f32 temp_fv1;

    D_xk2_8011972C =
        gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);

    temp_fv0 = (D_xk2_80104CB4 * 0.04) + 15.0;
    switch (D_xk2_8011972C) {
        case BTN_CLEFT:
            temp_fv1 = -1.0f * temp_fv0;
            D_xk2_80104CB8 += temp_fv1 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv1 * D_xk2_80128D40;
            break;
        case BTN_CRIGHT:
            D_xk2_80104CB8 += temp_fv0 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv0 * D_xk2_80128D40;
            break;
        case BTN_CUP:
            D_xk2_80104CB8 += temp_fv0 * gCameras[0].basis.y.x;
            D_xk2_80104CBC += temp_fv0 * gCameras[0].basis.y.y;
            D_xk2_80104CC0 += temp_fv0 * gCameras[0].basis.y.z;
            break;
        case BTN_CDOWN:
            D_xk2_80104CB8 -= temp_fv0 * gCameras[0].basis.y.x;
            D_xk2_80104CBC -= temp_fv0 * gCameras[0].basis.y.y;
            D_xk2_80104CC0 -= temp_fv0 * gCameras[0].basis.y.z;
            break;
        case (BTN_CUP | BTN_CLEFT):
            temp_fv1 = -1.0f * temp_fv0;
            D_xk2_80104CB8 += temp_fv1 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv1 * D_xk2_80128D40;
            D_xk2_80104CB8 += temp_fv0 * gCameras[0].basis.y.x;
            D_xk2_80104CBC += temp_fv0 * gCameras[0].basis.y.y;
            D_xk2_80104CC0 += temp_fv0 * gCameras[0].basis.y.z;
            break;
        case (BTN_CDOWN | BTN_CLEFT):
            temp_fv1 = -1.0f * temp_fv0;
            D_xk2_80104CB8 += temp_fv1 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv1 * D_xk2_80128D40;
            D_xk2_80104CB8 -= temp_fv0 * gCameras[0].basis.y.x;
            D_xk2_80104CBC -= temp_fv0 * gCameras[0].basis.y.y;
            D_xk2_80104CC0 -= temp_fv0 * gCameras[0].basis.y.z;
            break;
        case (BTN_CUP | BTN_CRIGHT):
            D_xk2_80104CB8 += temp_fv0 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv0 * D_xk2_80128D40;
            D_xk2_80104CB8 += temp_fv0 * gCameras[0].basis.y.x;
            D_xk2_80104CBC += temp_fv0 * gCameras[0].basis.y.y;
            D_xk2_80104CC0 += temp_fv0 * gCameras[0].basis.y.z;
            break;
        case (BTN_CDOWN | BTN_CRIGHT):
            D_xk2_80104CB8 += temp_fv0 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv0 * D_xk2_80128D40;
            D_xk2_80104CB8 -= temp_fv0 * gCameras[0].basis.y.x;
            D_xk2_80104CBC -= temp_fv0 * gCameras[0].basis.y.y;
            D_xk2_80104CC0 -= temp_fv0 * gCameras[0].basis.y.z;
            break;
    }

    if (D_xk2_80104CB8 < -8000) {
        D_xk2_80104CB8 = -8000;
    }
    if (D_xk2_80104CB8 > 8000) {
        D_xk2_80104CB8 = 8000;
    }

    if (D_xk2_80104CBC < 0) {
        D_xk2_80104CBC = 0;
    }
    if (D_xk2_80104CBC > 8000) {
        D_xk2_80104CBC = 8000;
    }

    if (D_xk2_80104CC0 < -8000) {
        D_xk2_80104CC0 = -8000;
    }
    if (D_xk2_80104CC0 > 8000) {
        D_xk2_80104CC0 = 8000;
    }
}

extern s32 D_xk2_80104CB0;
extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800D78A0(void) {
    u16 directionButton;

    directionButton = gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_UP | BTN_DOWN | BTN_LEFT | BTN_RIGHT);
    if (D_xk2_80119918 != 0) {
        if (ABS(D_80119720->stickX) > ABS(D_80119720->stickY)) {
            if (D_80119720->stickX < -60) {
                directionButton |= BTN_LEFT;
            }
            if (D_80119720->stickX > 60) {
                directionButton |= BTN_RIGHT;
            }
        } else {
            if (D_80119720->stickY < -60) {
                directionButton |= BTN_DOWN;
            }
            if (D_80119720->stickY > 60) {
                directionButton |= BTN_UP;
            }
        }
    }

    switch (directionButton) {
        case BTN_UP:
            D_xk2_80104CB0 += 6;
            break;
        case BTN_DOWN:
            D_xk2_80104CB0 -= 6;
            break;
        case BTN_LEFT:
            D_800D6CA0.unk_14 = (D_800D6CA0.unk_14 + 6) % 360;
            break;
        case BTN_RIGHT:
            D_800D6CA0.unk_14 = (D_800D6CA0.unk_14 + (360 - 6)) % 360;
            break;
        default:
            break;
    }

    if (D_xk2_80104CB0 < -90) {
        D_xk2_80104CB0 = -90;
        D_xk2_80104CB0 = -90;
    }
    if (D_xk2_80104CB0 > 90) {
        D_xk2_80104CB0 = 90;
    }
}

extern s32 D_xk2_800F7040;

extern s32 gPartsStyleOption;
extern s32 gPitTypeOption;
extern s32 gDashTypeOption;
extern s32 gDirtTypeOption;
extern s32 gIceTypeOption;

extern u8 D_xk2_80104CA0[];

void func_xk2_800D7A4C(s32 trackPartStyle) {
    s32 var_v0;
    s32 var_v1;
    s32 var_a2;
    s32 var_a3;

    var_v0 = COURSE_CONTEXT()->courseData.pit[D_800D6CA0.unk_0C] + 1;
    var_v1 = COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C] + 1;
    var_a2 = COURSE_CONTEXT()->courseData.dirt[D_800D6CA0.unk_0C] + 1;
    var_a3 = COURSE_CONTEXT()->courseData.ice[D_800D6CA0.unk_0C] + 1;

    var_v0 = D_xk2_800F6860[var_v0];
    var_v1 = D_xk2_800F6850[var_v1];
    var_a2 = D_xk2_800F6874[var_a2];
    var_a3 = D_xk2_800F6888[var_a3];
    switch (trackPartStyle) {
        case TRACK_PART_STYLE_PIT:
            var_v0 = ~D_xk2_800F6860[gPitTypeOption + 1];
            var_v1 &= var_v0;
            var_a2 &= var_v0;
            var_a3 &= var_v0;
            var_v0 = D_xk2_800F6860[gPitTypeOption + 1];
            break;
        case TRACK_PART_STYLE_DASH:
            var_v1 = ~D_xk2_800F6850[gDashTypeOption + 1];
            var_v0 &= var_v1;
            var_a2 &= var_v1;
            var_a3 &= var_v1;
            var_v1 = D_xk2_800F6850[gDashTypeOption + 1];
            break;
        case TRACK_PART_STYLE_DIRT:
            var_a2 = ~D_xk2_800F6874[gDirtTypeOption + 1];
            var_v0 &= var_a2;
            var_v1 &= var_a2;
            var_a3 &= var_a2;
            var_a2 = D_xk2_800F6874[gDirtTypeOption + 1];
            break;
        case TRACK_PART_STYLE_SLIP:
            var_a3 = ~D_xk2_800F6888[gIceTypeOption + 1];
            var_v0 &= var_a3;
            var_v1 &= var_a3;
            var_a2 &= var_a3;
            var_a3 = D_xk2_800F6888[gIceTypeOption + 1];
            break;
    }

    if (COURSE_CONTEXT()->courseData.pit[D_800D6CA0.unk_0C] != D_xk2_800F689C[var_v0]) {
        Audio_TriggerSystemSE(NA_SE_39);
        COURSE_CONTEXT()->courseData.pit[D_800D6CA0.unk_0C] = D_xk2_800F689C[var_v0];
        D_xk2_800F7040 = 3;
    }

    if (COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C] != D_xk2_800F68B8[var_v1]) {
        Audio_TriggerSystemSE(NA_SE_39);
        COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C] = D_xk2_800F68B8[var_v1];
        D_xk2_800F7040 = 3;
        if (gPartsStyleOption != TRACK_PART_STYLE_DASH) {
            func_xk2_800EE664(0x14);
        }
    }

    if (COURSE_CONTEXT()->courseData.dirt[D_800D6CA0.unk_0C] != D_xk2_800F68D4[var_a2]) {
        Audio_TriggerSystemSE(NA_SE_39);
        COURSE_CONTEXT()->courseData.dirt[D_800D6CA0.unk_0C] = D_xk2_800F68D4[var_a2];
        D_xk2_800F7040 = 3;
    }

    if (COURSE_CONTEXT()->courseData.ice[D_800D6CA0.unk_0C] != D_xk2_800F68F0[var_a3]) {
        Audio_TriggerSystemSE(NA_SE_39);
        COURSE_CONTEXT()->courseData.ice[D_800D6CA0.unk_0C] = D_xk2_800F68F0[var_a3];
        D_xk2_800F7040 = 3;
    }
}

extern s32 D_xk2_800F7040;
extern unk_807B3C20 D_802CB6D0;

void func_xk2_800D7D80(void) {

    if (gPartsStyleOption != TRACK_PART_STYLE_PIT) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
    }

    if ((D_xk2_80104CA0[7] != 0) && (gPitTypeOption != PIT_MAX)) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    if (gPitTypeOption == PIT_MAX) {
        if (COURSE_CONTEXT()->courseData.pit[D_800D6CA0.unk_0C] != PIT_NONE) {
            Audio_TriggerSystemSE(NA_SE_39);
            func_xk2_800EF78C();
            COURSE_CONTEXT()->courseData.pit[D_800D6CA0.unk_0C] = PIT_NONE;
            D_xk2_800F7040 = 3;
        }
    } else if (gPitTypeOption != COURSE_CONTEXT()->courseData.pit[D_800D6CA0.unk_0C]) {
        func_xk2_800EF78C();
        func_xk2_800D7A4C(TRACK_PART_STYLE_PIT);
    }
}

extern unk_807B3C20 D_802CB6D0;

void func_xk2_800D7EB8(void) {
    s32 dashCount;
    s32 i;

    dashCount = 0;
    if (gPartsStyleOption != TRACK_PART_STYLE_DASH) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_AIR:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.dash[i] != DASH_NONE) {
            dashCount++;
        }
    }
    if (gDashTypeOption == DASH_MAX) {
        if (COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C] != DASH_NONE) {
            Audio_TriggerSystemSE(NA_SE_39);
            func_xk2_800EF78C();
            COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C] = DASH_NONE;
            D_xk2_800F7040 = 3;
        }
    } else {
        if ((dashCount >= 32) && (COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C] == DASH_NONE)) {
            Audio_TriggerSystemSE(NA_SE_32);
        } else if (gDashTypeOption != COURSE_CONTEXT()->courseData.dash[D_800D6CA0.unk_0C]) {
            func_xk2_800EF78C();
            func_xk2_800D7A4C(TRACK_PART_STYLE_DASH);
        }
    }
}

void func_xk2_800D8018(void) {

    if (gPartsStyleOption != TRACK_PART_STYLE_DIRT) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
    }

    if ((D_xk2_80104CA0[7] != 0) && (gDirtTypeOption != DIRT_MAX)) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    if (gDirtTypeOption == DIRT_MAX) {
        if (COURSE_CONTEXT()->courseData.dirt[D_800D6CA0.unk_0C] != DIRT_NONE) {
            Audio_TriggerSystemSE(NA_SE_39);
            func_xk2_800EF78C();
            COURSE_CONTEXT()->courseData.dirt[D_800D6CA0.unk_0C] = DIRT_NONE;
            D_xk2_800F7040 = 3;
        }
    } else if (gDirtTypeOption != COURSE_CONTEXT()->courseData.dirt[D_800D6CA0.unk_0C]) {
        func_xk2_800EF78C();
        func_xk2_800D7A4C(TRACK_PART_STYLE_DIRT);
    }
}

void func_xk2_800D8154(void) {

    if (gPartsStyleOption != TRACK_PART_STYLE_SLIP) {
        return;
    }
    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
    }

    if ((D_xk2_80104CA0[7] != 0) && (gIceTypeOption != ICE_MAX)) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    if (gIceTypeOption == ICE_MAX) {
        if (COURSE_CONTEXT()->courseData.ice[D_800D6CA0.unk_0C] != ICE_NONE) {
            Audio_TriggerSystemSE(NA_SE_39);
            func_xk2_800EF78C();
            COURSE_CONTEXT()->courseData.ice[D_800D6CA0.unk_0C] = ICE_NONE;
            D_xk2_800F7040 = 3;
        }
    } else if (gIceTypeOption != COURSE_CONTEXT()->courseData.ice[D_800D6CA0.unk_0C]) {
        func_xk2_800EF78C();
        func_xk2_800D7A4C(TRACK_PART_STYLE_SLIP);
    }
}

extern s32 gJumpTypeOption;
extern s32 gLandmineTypeOption;
extern s32 gGateTypeOption;
extern s32 gBuildingTypeOption;
extern s32 gSignTypeOption;

void func_xk2_800D8290(void) {
    s32 jumpCount;
    s32 i;

    jumpCount = 0;
    if (gPartsStyleOption != TRACK_PART_STYLE_JUMP) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.jump[i] != JUMP_NONE) {
            jumpCount++;
        }
    }
    if (gJumpTypeOption == JUMP_MAX) {
        if (COURSE_CONTEXT()->courseData.jump[D_800D6CA0.unk_0C] != JUMP_NONE) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.jump[D_800D6CA0.unk_0C] = JUMP_NONE;
        }
    } else {
        if ((jumpCount >= 8) && (COURSE_CONTEXT()->courseData.jump[D_800D6CA0.unk_0C] == JUMP_NONE)) {
            Audio_TriggerSystemSE(NA_SE_32);
        } else if (gJumpTypeOption != COURSE_CONTEXT()->courseData.jump[D_800D6CA0.unk_0C]) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.jump[D_800D6CA0.unk_0C] = gJumpTypeOption;
        }
    }
}

void func_xk2_800D8418(void) {
    s32 landmineCount;
    s32 i;

    landmineCount = 0;
    if (gPartsStyleOption != TRACK_PART_STYLE_TRAP) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.landmine[i] != LANDMINE_NONE) {
            landmineCount++;
        }
    }
    if (gLandmineTypeOption == LANDMINE_MAX) {
        if (COURSE_CONTEXT()->courseData.landmine[D_800D6CA0.unk_0C] != LANDMINE_NONE) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.landmine[D_800D6CA0.unk_0C] = LANDMINE_NONE;
        }
    } else {
        if ((landmineCount >= 8) && (COURSE_CONTEXT()->courseData.landmine[D_800D6CA0.unk_0C] == LANDMINE_NONE)) {
            Audio_TriggerSystemSE(NA_SE_32);
        } else if (gLandmineTypeOption != COURSE_CONTEXT()->courseData.landmine[D_800D6CA0.unk_0C]) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.landmine[D_800D6CA0.unk_0C] = gLandmineTypeOption;
        }
    }
}

void func_xk2_800D85A0(void) {
    s32 decorationalFeatureCount;
    s32 i;

    decorationalFeatureCount = 0;
    if (gPartsStyleOption != TRACK_PART_STYLE_GATE) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_AIR:
            switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].prev->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_ROAD:
                case TRACK_SHAPE_BORDERLESS_ROAD:
                    break;
                default:
                    Audio_TriggerSystemSE(NA_SE_32);
                    return;
            }
            break;
        case TRACK_SHAPE_ROAD:
        case TRACK_SHAPE_BORDERLESS_ROAD:
            break;
        default:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
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

    if (gGateTypeOption == GATE_MAX) {
        if (COURSE_CONTEXT()->courseData.gate[D_800D6CA0.unk_0C] != GATE_NONE) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.gate[D_800D6CA0.unk_0C] = GATE_NONE;
        }
    } else {
        if ((decorationalFeatureCount >= 16) && (COURSE_CONTEXT()->courseData.gate[D_800D6CA0.unk_0C] == GATE_NONE)) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        if (gGateTypeOption != COURSE_CONTEXT()->courseData.gate[D_800D6CA0.unk_0C]) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.gate[D_800D6CA0.unk_0C] = gGateTypeOption;
        }
    }
}

void func_xk2_800D8778(void) {
    s32 decorationalFeatureCount;
    s32 i;

    decorationalFeatureCount = 0;
    if (gPartsStyleOption != TRACK_PART_STYLE_BUILDING) {
        return;
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
    if (gBuildingTypeOption == BUILDING_MAX) {
        if (COURSE_CONTEXT()->courseData.building[D_800D6CA0.unk_0C] != BUILDING_NONE) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.building[D_800D6CA0.unk_0C] = BUILDING_NONE;
        }
    } else {
        if ((decorationalFeatureCount >= 16) &&
            (COURSE_CONTEXT()->courseData.building[D_800D6CA0.unk_0C] == BUILDING_NONE)) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        if (gBuildingTypeOption != COURSE_CONTEXT()->courseData.building[D_800D6CA0.unk_0C]) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.building[D_800D6CA0.unk_0C] = gBuildingTypeOption;
        }
    }
}

void func_xk2_800D88D8(void) {
    s32 decorationalFeatureCount;
    s32 i;

    decorationalFeatureCount = 0;
    if (gPartsStyleOption != TRACK_PART_STYLE_SIGN) {
        return;
    }

    switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_AIR:
            switch (D_802CB6D0.unk_0000[D_800D6CA0.unk_0C].prev->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_ROAD:
                case TRACK_SHAPE_BORDERLESS_ROAD:
                    break;
                default:
                    Audio_TriggerSystemSE(NA_SE_32);
                    return;
            }
            break;
        case TRACK_SHAPE_ROAD:
        case TRACK_SHAPE_BORDERLESS_ROAD:
            break;
        default:
            Audio_TriggerSystemSE(NA_SE_32);
            return;
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

    if (gSignTypeOption == SIGN_MAX) {
        if (COURSE_CONTEXT()->courseData.sign[D_800D6CA0.unk_0C] != SIGN_NONE) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.sign[D_800D6CA0.unk_0C] = SIGN_NONE;
        }
    } else {
        if ((decorationalFeatureCount >= 16) && (COURSE_CONTEXT()->courseData.sign[D_800D6CA0.unk_0C] == SIGN_NONE)) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        if (gSignTypeOption != COURSE_CONTEXT()->courseData.sign[D_800D6CA0.unk_0C]) {
            func_xk2_800EF78C();
            Audio_TriggerSystemSE(NA_SE_39);
            COURSE_CONTEXT()->courseData.sign[D_800D6CA0.unk_0C] = gSignTypeOption;
        }
    }
}

void func_xk2_800D8AB0(void) {
}

extern s32 gCreateOption;
extern s32 gDesignStyleOption;

void func_xk2_800D8AB8(void) {
    s32 temp_a1;
    s32 temp_v1;
    CourseSegment* temp_v0;
    s32 sp2C[] = { TRACK_SHAPE_ROAD, TRACK_SHAPE_WALLED_ROAD, TRACK_SHAPE_BORDERLESS_ROAD, TRACK_SHAPE_TUNNEL,
                   TRACK_SHAPE_PIPE, TRACK_SHAPE_HALF_PIPE,   TRACK_SHAPE_CYLINDER,        TRACK_SHAPE_AIR };

    if ((D_80119720->buttonPressed & BTN_A) && (gCourseEditCursorYPos >= 0x38) && (D_800D6CA0.unk_08 != 3) &&
        (gCreateOption == CREATE_OPTION_DESIGN)) {
        if (D_802CB6D0.controlPointCount < 4) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        if (D_800D6CA0.unk_0C == 0) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        if (D_800D6CA0.unk_0C != -1) {
            temp_v0 = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
            Math_VectorGetDistance(temp_v0->pos, temp_v0->next->pos);

            temp_a1 = gDesignStyleOption;
            temp_v1 = sp2C[temp_a1];
            if (((temp_v0->prev->trackSegmentInfo & TRACK_SHAPE_MASK) != sp2C[temp_a1]) &&
                ((temp_v0->next->trackSegmentInfo & TRACK_SHAPE_MASK) == sp2C[temp_a1])) {
                switch (temp_v0->prev->trackSegmentInfo & TRACK_SHAPE_MASK) {
                    case TRACK_SHAPE_ROAD:
                    case TRACK_SHAPE_BORDERLESS_ROAD:
                        break;
                }
            }
            switch (temp_a1) {
                case TRACK_DESIGN_STYLE_ROAD:
                case TRACK_DESIGN_STYLE_H_ROAD:
                case TRACK_DESIGN_STYLE_T_ROAD:
                case TRACK_DESIGN_STYLE_SPACE:
                    func_xk2_800DCF2C();
                    func_xk2_800DCFE0();
                    func_xk2_800DD0AC();
                    func_xk2_800DD568();
                    break;
                case TRACK_DESIGN_STYLE_TUNNEL:
                    func_xk2_800DD178();
                    break;
                case TRACK_DESIGN_STYLE_PIPE:
                case TRACK_DESIGN_STYLE_HALF_PIPE:
                case TRACK_DESIGN_STYLE_CYLINDER:
                    func_xk2_800DD244();
                    func_xk2_800DD350();
                    func_xk2_800DD45C();
                    break;
                default:
                    break;
            }
        }
    }
}

void func_xk2_800D8CC4(void) {

    if (!(D_80119720->buttonPressed & BTN_A)) {
        return;
    }
    if (gCourseEditCursorYPos < 0x38) {
        return;
    }
    if (D_800D6CA0.unk_08 == 2 || D_800D6CA0.unk_08 == 1 || D_800D6CA0.unk_08 == 3 || D_800D6CA0.unk_08 == 16) {
        return;
    }

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return;
    }

    if (D_802CB6D0.controlPointCount < 4) {
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    func_xk2_800D7EB8();
    func_xk2_800D7D80();
    func_xk2_800D8018();
    func_xk2_800D8154();
    func_xk2_800D8290();
    func_xk2_800D8418();
    func_xk2_800D85A0();
    func_xk2_800D8778();
    func_xk2_800D88D8();
}

extern s32 D_8076C958;

void func_xk2_800D8DAC(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    f32 sp28;
    f32 sp24;

    D_80119720 = &gControllers[gPlayerControlPorts[0]];

    temp_a0 = D_80119720->stickX;
    temp_a1 = D_80119720->stickY;
    func_xk2_800D6D90(temp_a0, temp_a1, &sp28, &sp24);
    D_80119720->stickX = sp28 * 64.0f;
    D_80119720->stickY = sp24 * 64.0f;
    temp_a0 = D_80119720->stickX;
    temp_a1 = D_80119720->stickY;
    temp_a2 = SQ(temp_a0) + SQ(temp_a1);
    if (temp_a2 > 100) {
        if (D_8076C958 > 4) {
            D_8076C958 -= 4;
        }
        func_xk2_800EE640();
    }
    if (temp_a2 > 1600) {
        if (D_xk2_800F6834 < 0.5f) {
            D_xk2_800F6834 += 0.05f;
        }
    } else {
        D_xk2_800F6834 = 0.15f;
    }
}

extern bool gInCourseEditTestRun;
extern s32 D_8076C964;
extern volatile u8 D_80794E14;
extern bool gMenuWidgetOpen;
extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;
extern s32 D_xk2_800F703C;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F704C;
extern s32 gCourseEditHighlightedIconIndex;
extern MenuWidget gCourseEditWidget;

void func_xk2_800D8F04(void) {
    s32 pad[37];
    s32 temp_v1;
    s32 sp1C;

    D_80119720 = &gControllers[gPlayerControlPorts[0]];

    temp_v1 = D_xk2_800F704C;
    if (temp_v1 != -1) {
        D_xk2_801197EC = &D_802CB6D0.unk_0000[D_xk2_800F704C];
    } else {
        D_xk2_801197EC = D_802CB6D0.unk_0000;
    }
    D_xk2_80119748 = *D_xk2_801197EC;

    if (D_80119720) {}
    func_xk2_800DBEE4();
    if (D_800D6CA0.unk_08 == 0) {
        D_xk1_8003A550 = gCourseEditCursorXPos;
        D_xk1_8003A554 = gCourseEditCursorYPos;
    }
    if (D_80794E14 == 1) {
        func_xk1_80027CFC(&gCourseEditWidget, &D_xk1_8003A550, &D_xk1_8003A554);
        return;
    }
    func_xk2_800D8AB0();
    D_xk2_80119728 = gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_UP | BTN_DOWN | BTN_LEFT | BTN_RIGHT);
    D_xk2_8011972A = gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_UP | BTN_DOWN | BTN_LEFT | BTN_RIGHT);
    D_xk2_8011972C =
        gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
    D_xk2_8011972E =
        gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
    D_xk2_801197EC = &D_802CB6D0.unk_0000[D_xk2_800F704C];
    D_xk2_80128D40 = SIN((D_800D6CA0.unk_14 << 12) / 360);
    D_xk2_80128D44 = COS((D_800D6CA0.unk_14 << 12) / 360);
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_Z) {
        D_xk2_800F703C = -1;
    }
    func_xk2_800DF54C();
    func_xk2_800F5F2C();
    if (!gInCourseEditTestRun) {
        func_xk2_800D7058();
        func_xk2_800D71E8();
        func_xk2_800D78A0();
    }
    func_xk2_800DF2EC();
    sp1C = gCourseEditHighlightedIconIndex;
    CourseEdit_UpdateHighlightedIconIndex();
    if ((sp1C != -1) && (gCourseEditHighlightedIconIndex == -1)) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
    func_xk2_800DEC1C();
    func_xk2_800DE8D0();
    func_xk2_800DECF0();
    if (!func_xk2_800E6B3C()) {
        if (D_8076C964 == 1) {
            D_xk2_800F7044 = 1;
        } else {
            D_xk2_800F7044 = 0;
        }
    }
    if ((gCourseEditCursorXPos < 230) || (gCourseEditCursorXPos >= 298) || (gCourseEditCursorYPos < 202) ||
        (gCourseEditCursorYPos >= 222)) {
        func_xk2_800D8AB8();
        func_xk2_800D8CC4();
        func_xk2_800DC67C();
        func_xk2_800DC58C();
        func_xk2_800DC4E4();
        func_xk2_800F07A4();
    }
    func_xk2_800DD8C8();
    func_xk2_800DCCD8();
    func_xk2_800DB924();
    func_xk2_800EFF40();
    func_xk2_800DC018();
    func_xk2_800DC428();
    func_xk2_800DCDD0();
    func_xk1_80027CFC(&gCourseEditWidget, &D_xk1_8003A550, &D_xk1_8003A554);
    if ((D_80119720->buttonPressed & BTN_A) && (D_800D6CA0.unk_08 == 0)) {
        D_xk1_8003A550 = gCourseEditCursorXPos;
        D_xk1_8003A554 = gCourseEditCursorYPos;
        func_xk1_80027DC8(&gCourseEditWidget, &D_xk1_8003A550, &D_xk1_8003A554);
        if (gMenuWidgetOpen) {
            D_800D6CA0.unk_08 = 1;
        }
    }
    func_xk2_800D6FF0();
}

extern s32 D_800D11C8[];

f32 D_xk2_800F692C[] = { 0.5f, 0.6f, 0.7f, 0.8f, 1.0f, 1.5f, 2.0f, 2.5f, 3.0f };

void func_xk2_800D934C(void) {
    f32 temp_fv0;
    s32 var_v0;
    s32 temp;
    s32 temp_a1;
    s32 temp_a2;

    D_80119720 = &gControllers[gPlayerControlPorts[0]];

    temp_a1 = D_80119720->stickX;
    temp_a2 = D_80119720->stickY;
    if ((SQ(temp_a1) + SQ(temp_a2)) != 0) {
        D_xk2_800F703C = -1;
    }

    var_v0 = D_800D11C8[4];
    if ((var_v0 < 0) || (var_v0 >= 9)) {
        D_800D11C8[4] = var_v0 = 4;
    }
    temp_fv0 = D_xk2_800F692C[var_v0] * D_xk2_800F6834;
    temp = gCourseEditCursorYPos;
    gCourseEditCursorXPos += (temp_fv0 * temp_a1) / 2;
    gCourseEditCursorYPos -= (temp_fv0 * temp_a2) / 2;
    if ((temp >= 36) && (gCourseEditCursorYPos < 36)) {
        Audio_TriggerSystemSE(NA_SE_35);
    }

    if (gCourseEditCursorXPos < 24) {
        gCourseEditCursorXPos = 24;
    }
    if (gCourseEditCursorXPos > 295) {
        gCourseEditCursorXPos = 295;
    }
    if (gCourseEditCursorYPos < 20) {
        gCourseEditCursorYPos = 21;
    }
    if (gCourseEditCursorYPos > 212) {
        gCourseEditCursorYPos = 212;
    }
}

void func_xk2_800D950C(void) {
    f32 temp_fv0;
    s32 var_a0;
    s32 var_v0;

    var_v0 = D_80119720->stickX;
    var_a0 = D_80119720->stickY;

    if ((SQ(var_v0) + SQ(var_a0)) < 100) {
        return;
    }
    if (var_v0 < 0) {
        var_v0 = -var_v0 * var_v0;
    } else {
        var_v0 = var_v0 * var_v0;
    }
    if (var_a0 < 0) {
        var_a0 = -var_a0 * var_a0;
    } else {
        var_a0 = var_a0 * var_a0;
    }
    temp_fv0 = D_xk2_800F692C[D_800D11C8[4]] * D_xk2_800F6834;
    gCourseEditCursorXPos += (temp_fv0 * var_v0) / 128;
    gCourseEditCursorYPos -= (temp_fv0 * var_a0) / 128;
    if (gCourseEditCursorXPos < 24) {
        gCourseEditCursorXPos = 24;
    }
    if (gCourseEditCursorXPos > 295) {
        gCourseEditCursorXPos = 295;
    }

    if (gCourseEditCursorYPos < 56) {
        gCourseEditCursorYPos = 57;
    }
    if (gCourseEditCursorYPos > 212) {
        gCourseEditCursorYPos = 212;
    }
}

extern unk_807B3C20 D_807B6528;
extern CourseInfo* gCurrentCourseInfo;

void func_xk2_800D9670(void) {
    CourseSegment* temp_s0_2;
    CourseSegment* temp_s1_2;
    bool var_s1;
    s8 temp_s0;
    s8 temp_s1;
    s32 var_s2;
    s32 var_s3;
    bool sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    f32 var_fa0;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 i;

    temp_s0 = D_80119720->stickX;
    temp_s1 = D_80119720->stickY;
    var_s2 = 0;
    var_s3 = 0;
    if ((SQ(temp_s0) + SQ(temp_s1)) < 100) {
        return;
    }

    if (gCurrentCourseInfo->length > 300000.0f) {
        func_xk2_800EE664(0x1D);
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    if (D_80119720->buttonCurrent & BTN_Z) {
        sp5C = D_xk2_800F6834 * 9.0f;
    } else {
        sp5C = D_xk2_800F6834;
    }

    sp64 = D_xk2_80119730;
    sp60 = D_xk2_80119738;
    if (func_xk1_8002DAD4() == 1) {

        if (ABS(temp_s0) > 10) {
            if (temp_s0 < 0) {
                var_s2 = -1;
            } else {
                var_s2 = 1;
            }
        }

        if (ABS(temp_s1) > 10) {
            if (temp_s1 < 0) {
                var_s3 = -1;
            } else {
                var_s3 = 1;
            }
        }

        if (((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3)) >= 0.0f) {
            var_fa0 = ((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3));
        } else {
            var_fa0 = -((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3));
        }
        if (var_fa0 > 0.6) {
            if (((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3)) > 0.0f) {
                D_xk2_80119730 += 10.0f;
            } else {
                D_xk2_80119730 -= 10.0f;
            }
        }

        if ((D_xk2_80128D40 * var_s2) >= (D_xk2_80128D44 * var_s3)) {
            var_fa0 = (D_xk2_80128D40 * var_s2) - (D_xk2_80128D44 * var_s3);
        } else {
            var_fa0 = -((D_xk2_80128D40 * var_s2) - (D_xk2_80128D44 * var_s3));
        }
        if (var_fa0 > 0.6) {
            if ((D_xk2_80128D44 * var_s3) < (D_xk2_80128D40 * var_s2)) {
                D_xk2_80119738 += 10.0f;
            } else {
                D_xk2_80119738 -= 10.0f;
            }
        }
    } else {
        if (func_xk1_8002DAD4() >= 9) {
            D_xk2_80119730 += ((D_xk2_80128D44 * sp5C) * temp_s0) + ((D_xk2_80128D40 * sp5C) * temp_s1);
            D_xk2_80119738 += ((D_xk2_80128D40 * sp5C) * temp_s0) - ((D_xk2_80128D44 * sp5C) * temp_s1);
        }
    }
    D_xk2_80119730 = (Math_Round(D_xk2_80119730) / 10) * 10;
    D_xk2_80119738 = (Math_Round(D_xk2_80119738) / 10) * 10;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        temp_s1_2 = &D_807B6528.unk_0000[i];
        temp_s0_2->pos.x = Math_Round(D_xk2_80119730) + temp_s1_2->pos.x;
        temp_s0_2->pos.x = (((s32) temp_s0_2->pos.x / 10) * 10);
        temp_s0_2->pos.z = Math_Round(D_xk2_80119738) + temp_s1_2->pos.z;
        temp_s0_2->pos.z = (((s32) temp_s0_2->pos.z / 10) * 10);
    }
    var_s1 = false;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        if (Math_VectorGetDistance(temp_s0_2->pos, temp_s0_2->prev->pos) < 498.0f) {
            var_s1 = true;
        }
        if (Math_VectorGetDistance(temp_s0_2->pos, temp_s0_2->next->pos) < 498.0f) {
            var_s1 = true;
        }
    }
    if (var_s1) {
        Audio_TriggerSystemSE(NA_SE_32);
        D_xk2_80119730 = sp64;
        D_xk2_80119738 = sp60;

        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }
            temp_s0_2 = &D_802CB6D0.unk_0000[i];
            temp_s1_2 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.x = Math_Round(D_xk2_80119730) + temp_s1_2->pos.x;
            temp_s0_2->pos.x = (((s32) temp_s0_2->pos.x / 10) * 10);
            temp_s0_2->pos.z = Math_Round(D_xk2_80119738) + temp_s1_2->pos.z;
            temp_s0_2->pos.z = (((s32) temp_s0_2->pos.z / 10) * 10);
        }
    }
    sp80 = 15000;
    sp7C = -15000;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        if (temp_s0_2->pos.x < sp80) {
            sp70 = i;
            sp80 = Math_Round(temp_s0_2->pos.x);
        }
        if (sp7C < temp_s0_2->pos.x) {
            sp6C = i;
            sp7C = Math_Round(temp_s0_2->pos.x);
        }
    }
    sp84 = false;
    if (sp80 < -15000) {
        sp84 = true;
        D_xk2_80119730 = -15000 - Math_Round(D_807B6528.unk_0000[sp70].pos.x);
    }
    if (sp7C > 15000) {
        sp84 = true;
        D_xk2_80119730 = 15000 - Math_Round(D_807B6528.unk_0000[sp6C].pos.x);
    }

    if (sp84) {
        Audio_TriggerSystemSE(NA_SE_32);

        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            temp_s0_2 = &D_802CB6D0.unk_0000[i];
            temp_s1_2 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.x = Math_Round(D_xk2_80119730) + temp_s1_2->pos.x;
            temp_s0_2->pos.x = (Math_Round(temp_s0_2->pos.x) / 10) * 10;
        }
    }
    sp84 = false;

    sp78 = 15000;
    sp74 = -15000;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        if (temp_s0_2->pos.z < sp78) {
            sp70 = i;
            sp78 = Math_Round(temp_s0_2->pos.z);
        }
        if (sp74 < temp_s0_2->pos.z) {
            sp6C = i;
            sp74 = Math_Round(temp_s0_2->pos.z);
        }
    }
    if (sp78 < -15000) {
        sp84 = true;
        D_xk2_80119738 = -15000 - Math_Round(D_807B6528.unk_0000[sp70].pos.z);
    }
    if (sp74 > 15000) {
        sp84 = true;
        D_xk2_80119738 = 15000 - Math_Round(D_807B6528.unk_0000[sp6C].pos.z);
    }
    if (sp84) {
        Audio_TriggerSystemSE(NA_SE_32);

        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            temp_s0_2 = &D_802CB6D0.unk_0000[i];
            temp_s1_2 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.z = Math_Round(D_xk2_80119738) + temp_s1_2->pos.z;
            temp_s0_2->pos.z = (Math_Round(temp_s0_2->pos.z) / 10) * 10;
        }
    }
    D_xk2_800F7040 = 3;
}

void func_xk2_800DA288(void) {
    CourseSegment* temp_s0_2;
    CourseSegment* temp_s1;
    s32 i;
    s8 temp_s0;
    s8 temp_v0;
    bool var_s1;
    bool var_s0;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    f32 sp54;
    f32 sp50;

    temp_v0 = D_80119720->stickX;
    temp_s0 = D_80119720->stickY;

    if (ABS(temp_v0) > ABS(temp_s0)) {
        return;
    }

    if ((SQ(temp_v0) + SQ(temp_s0)) < 100) {
        return;
    }
    if (gCurrentCourseInfo->length > 300000.0f) {
        func_xk2_800EE664(0x1D);
        Audio_TriggerSystemSE(NA_SE_32);
        return;
    }
    if (D_80119720->buttonCurrent & BTN_Z) {
        sp50 = D_xk2_800F6834 * 6.0f;
    } else {
        sp50 = D_xk2_800F6834;
    }

    sp54 = D_xk2_80119734;
    if (func_xk1_8002DAD4() == 1) {
        if (temp_s0 < 0) {
            D_xk2_80119734 -= 10.0f;
        } else {
            D_xk2_80119734 += 10.0f;
        }
    } else {
        if (func_xk1_8002DAD4() >= 9) {
            D_xk2_80119734 += sp50 * temp_s0;
        }
    }

    D_xk2_80119734 = (Math_Round(D_xk2_80119734) / 10) * 10;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        temp_s1 = &D_807B6528.unk_0000[i];
        temp_s0_2->pos.y = Math_Round(D_xk2_80119734) + temp_s1->pos.y;
        temp_s0_2->pos.y = ((s32) temp_s0_2->pos.y / 10) * 10;
    }
    var_s1 = false;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        if (Math_VectorGetDistance(temp_s0_2->pos, temp_s0_2->prev->pos) < 498.0f) {
            var_s1 = true;
        }

        if (Math_VectorGetDistance(temp_s0_2->pos, temp_s0_2->next->pos) < 498.0f) {
            var_s1 = true;
        }
    }
    if (var_s1) {
        Audio_TriggerSystemSE(NA_SE_32);
        D_xk2_80119734 = sp54;
        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            temp_s0_2 = &D_802CB6D0.unk_0000[i];
            temp_s1 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.y = Math_Round(D_xk2_80119734) + temp_s1->pos.y;
            temp_s0_2->pos.y = ((s32) temp_s0_2->pos.y / 10) * 10;
        }
    }
    sp64 = 10000;
    sp60 = 0;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_802CB6D0.unk_0000[i];
        if (temp_s0_2->pos.y < sp64) {
            sp5C = i;
            sp64 = Math_Round(temp_s0_2->pos.y);
        }
        if (sp60 < temp_s0_2->pos.y) {
            sp58 = i;
            sp60 = Math_Round(temp_s0_2->pos.y);
        }
    }
    var_s0 = false;
    if (sp64 < 0) {
        var_s0 = true;
        D_xk2_80119734 = -Math_Round(D_807B6528.unk_0000[sp5C].pos.y);
    }
    if (sp60 > 5000) {
        var_s0 = true;
        D_xk2_80119734 = 5000 - Math_Round(D_807B6528.unk_0000[sp58].pos.y);
    }
    if (var_s0) {
        Audio_TriggerSystemSE(NA_SE_32);
        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }
            temp_s0_2 = &D_802CB6D0.unk_0000[i];
            temp_s1 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.y = Math_Round(D_xk2_80119734) + temp_s1->pos.y;
            temp_s0_2->pos.y = (Math_Round(temp_s0_2->pos.y) / 10) * 10;
        }
    }
    D_xk2_800F7040 = 3;
}

void func_xk2_800DA984(void) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv1;
    f32 temp_fa0_4;
    s32 sp5C;
    s32 var_s0;
    s8 temp_s1;
    s8 temp_v1;
    s32 i;

    temp_s1 = D_80119720->stickX;
    temp_v1 = D_80119720->stickY;
    sp5C = 0x2710;
    var_s0 = -0x2710;

    if (ABS(temp_s1) < ABS(temp_v1)) {
        return;
    }

    if ((SQ(temp_s1) + SQ(temp_v1)) < 100) {
        return;
    }

    if (func_xk1_8002DAD4() == 1) {
        if (temp_s1 < 0) {
            D_xk2_8011973C -= 10;
        } else {
            D_xk2_8011973C += 10;
        }
    } else {
        if (func_xk1_8002DAD4() >= 9) {
            D_xk2_8011973C += Math_Round(temp_s1 * D_xk2_800F6834);
        }
    }

    D_xk2_8011973C = (D_xk2_8011973C / 10) * 10;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_fv1 = D_807B6528.unk_0000[i].radiusRight;
        temp_fa0 = D_807B6528.unk_0000[i].radiusLeft;
        temp_fa1 = 1000.0f - ((temp_fv1 + temp_fa0) / 2);
        if (sp5C > temp_fa1) {
            sp5C = temp_fa1;
        }

        if (var_s0 < 50.0f - temp_fa0) {
            var_s0 = 50.0f - temp_fa0;
        }
        if (var_s0 < 50.0f - temp_fv1) {
            var_s0 = 50.0f - temp_fv1;
        }
    }

    if (D_xk2_8011973C > sp5C) {
        D_xk2_8011973C = sp5C;
    }
    if (D_xk2_8011973C < var_s0) {
        D_xk2_8011973C = var_s0;
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        D_802CB6D0.unk_0000[i].radiusLeft = D_807B6528.unk_0000[i].radiusLeft + D_xk2_8011973C;
        D_802CB6D0.unk_0000[i].radiusRight = D_807B6528.unk_0000[i].radiusRight + D_xk2_8011973C;
        D_802CB6D0.unk_0000[i].radiusLeft = (Math_Round(D_802CB6D0.unk_0000[i].radiusLeft) / 10) * 10;
        D_802CB6D0.unk_0000[i].radiusRight = (Math_Round(D_802CB6D0.unk_0000[i].radiusRight) / 10) * 10;
        if (D_802CB6D0.unk_0000[i].radiusLeft < 50.0f) {
            D_802CB6D0.unk_0000[i].radiusLeft = 50.0f;
        }
        if (D_802CB6D0.unk_0000[i].radiusRight < 50.0f) {
            D_802CB6D0.unk_0000[i].radiusRight = 50.0f;
        }

        temp_fa0_4 = D_802CB6D0.unk_0000[i].radiusRight + D_802CB6D0.unk_0000[i].radiusLeft;
        if (temp_fa0_4 > 2000.0f) {
            D_802CB6D0.unk_0000[i].radiusLeft = D_802CB6D0.unk_0000[i].radiusLeft - ((temp_fa0_4 / 2) - 1000.0f);
            D_802CB6D0.unk_0000[i].radiusRight = 2000.0f - D_802CB6D0.unk_0000[i].radiusLeft;
        }
    }
    D_xk2_800F7040 = 3;
}

void func_xk2_800DADEC(void) {
    s32 pad[13];
    s32 i;
    s8 temp_s3;
    s8 temp_v1;

    temp_s3 = D_80119720->stickX;
    temp_v1 = D_80119720->stickY;

    if (ABS(temp_s3) < ABS(temp_v1)) {
        return;
    }

    if ((SQ(temp_s3) + SQ(temp_v1)) < 100) {
        return;
    }

    if (func_xk1_8002DAD4() == 1) {
        if (temp_s3 < 0) {
            for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
                if (D_80128690[i].unk_08 == 0) {
                    continue;
                }

                COURSE_CONTEXT()->courseData.bankAngle[i] =
                    (COURSE_CONTEXT()->courseData.bankAngle[i] + 357 + 360) % 360;
                COURSE_CONTEXT()->courseData.bankAngle[i] = (COURSE_CONTEXT()->courseData.bankAngle[i] / 3) * 3;
            }
        } else {
            for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
                if (D_80128690[i].unk_08 == 0) {
                    continue;
                }

                COURSE_CONTEXT()->courseData.bankAngle[i] = (COURSE_CONTEXT()->courseData.bankAngle[i] + 3 + 360) % 360;
                COURSE_CONTEXT()->courseData.bankAngle[i] = (COURSE_CONTEXT()->courseData.bankAngle[i] / 3) * 3;
            }
        }
    } else if (func_xk1_8002DAD4() >= 9) {
        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            COURSE_CONTEXT()->courseData.bankAngle[i] =
                (COURSE_CONTEXT()->courseData.bankAngle[i] + Math_Round((temp_s3 * D_xk2_800F6834) / 6) + 360) % 360;
            COURSE_CONTEXT()->courseData.bankAngle[i] = (COURSE_CONTEXT()->courseData.bankAngle[i] / 3) * 3;
        }
    }
    func_80074CE4(gCurrentCourseInfo);
    D_xk2_800F7040 = 3;
}

void func_xk2_800DB154(void) {
    CourseSegment* temp_s0;
    CourseSegment* temp_v1_2;
    s32 var_s0;
    s32 var_s3;
    f32 temp_fv0;
    s32 temp_ft2;
    s8 temp_s1;
    s8 temp_v1;
    s32 i;

    temp_s1 = D_80119720->stickX;
    temp_v1 = D_80119720->stickY;
    var_s0 = 0x2710;
    var_s3 = -0x2710;
    if (ABS(temp_s1) < ABS(temp_v1)) {
        return;
    }

    if ((SQ(temp_s1) + SQ(temp_v1)) < 100) {
        return;
    }

    if (func_xk1_8002DAD4() == 1) {
        if (temp_s1 < 0) {
            D_xk2_80119740 -= 10;
        } else {
            D_xk2_80119740 += 10;
        }
    } else if (func_xk1_8002DAD4() >= 9) {
        D_xk2_80119740 += Math_Round(temp_s1 * D_xk2_800F6834);
    }

    D_xk2_80119740 = (D_xk2_80119740 / 10) * 10;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_v1_2 = &D_807B6528.unk_0000[i];
        temp_fv0 = temp_v1_2->radiusRight - 50.0f;
        if (var_s0 > temp_fv0) {
            var_s0 = temp_fv0;
        }
        temp_fv0 = (temp_v1_2->radiusLeft - 50.0f) * -1.0f;
        if (var_s3 < temp_fv0) {
            var_s3 = temp_fv0;
        }
    }

    if (D_xk2_80119740 > var_s0) {
        D_xk2_80119740 = var_s0;
    }
    if (D_xk2_80119740 < var_s3) {
        D_xk2_80119740 = var_s3;
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0 = &D_802CB6D0.unk_0000[i];
        temp_v1_2 = &D_807B6528.unk_0000[i];
        temp_ft2 = temp_s0->radiusLeft + temp_s0->radiusRight;
        temp_s0->radiusLeft = temp_v1_2->radiusLeft + D_xk2_80119740;
        temp_s0->radiusRight = temp_v1_2->radiusRight - D_xk2_80119740;
        temp_s0->radiusLeft = (Math_Round(temp_s0->radiusLeft) / 10) * 10;
        temp_s0->radiusRight = (Math_Round(temp_s0->radiusRight) / 10) * 10;
        if (temp_s0->radiusLeft < 50.0f) {
            temp_s0->radiusLeft = 50.0f;
            temp_s0->radiusRight = temp_ft2 - 50;
        }
        if (temp_s0->radiusRight < 50.0f) {
            temp_s0->radiusRight = 50.0f;
            temp_s0->radiusLeft = temp_ft2 - 50;
        }
    }

    D_xk2_800F7040 = 3;
}

extern CourseData D_8010C770;

void func_xk2_800DB550(void) {
    s32 i;
    s32 j;
    Vec3f sp74;
    CourseSegment* var_s0;

    if (D_802CB6D0.controlPointCount < 2) {
        return;
    }

    j = 0;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_s0 = &D_802CB6D0.unk_0000[i];

        if ((i != 0) && (Math_VectorGetDistance(var_s0->pos, var_s0->prev->pos) < 498.0f)) {
            continue;
        }

        if ((i + 1 == D_802CB6D0.controlPointCount) &&
            (Math_VectorGetDistance(var_s0->pos, var_s0->next->pos) < 498.0f)) {
            continue;
        }

        D_8010C770.bankAngle[j] = COURSE_CONTEXT()->courseData.bankAngle[i];
        D_8010C770.pit[j] = COURSE_CONTEXT()->courseData.pit[i];
        D_8010C770.dash[j] = COURSE_CONTEXT()->courseData.dash[i];
        D_8010C770.dirt[j] = COURSE_CONTEXT()->courseData.dirt[i];
        D_8010C770.ice[j] = COURSE_CONTEXT()->courseData.ice[i];
        D_8010C770.jump[j] = COURSE_CONTEXT()->courseData.jump[i];
        D_8010C770.landmine[j] = COURSE_CONTEXT()->courseData.landmine[i];
        D_8010C770.gate[j] = COURSE_CONTEXT()->courseData.gate[i];
        D_8010C770.building[j] = COURSE_CONTEXT()->courseData.building[i];
        D_8010C770.sign[j] = COURSE_CONTEXT()->courseData.sign[i];

        D_xk2_80119920[j] = *var_s0;
        j++;
    }
    D_802CB6D0.controlPointCount = j;
    for (i = 0; i < j; i++) {
        D_802CB6D0.unk_0000[i] = D_xk2_80119920[i];

        COURSE_CONTEXT()->courseData.bankAngle[i] = D_8010C770.bankAngle[i];
        COURSE_CONTEXT()->courseData.pit[i] = D_8010C770.pit[i];
        COURSE_CONTEXT()->courseData.dash[i] = D_8010C770.dash[i];
        COURSE_CONTEXT()->courseData.dirt[i] = D_8010C770.dirt[i];
        COURSE_CONTEXT()->courseData.ice[i] = D_8010C770.ice[i];
        COURSE_CONTEXT()->courseData.jump[i] = D_8010C770.jump[i];
        COURSE_CONTEXT()->courseData.landmine[i] = D_8010C770.landmine[i];
        COURSE_CONTEXT()->courseData.gate[i] = D_8010C770.gate[i];
        COURSE_CONTEXT()->courseData.building[i] = D_8010C770.building[i];
        COURSE_CONTEXT()->courseData.sign[i] = D_8010C770.sign[i];
    }

    func_xk2_800E6F9C();

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_s0 = &D_802CB6D0.unk_0000[i];
        func_xk2_800DE210(&sp74, var_s0->prev->pos, var_s0->pos, var_s0->next->pos);
        var_s0->pos = sp74;
    }
    func_80074CE4(gCurrentCourseInfo);
}

extern s32 gPointOption;
extern s32 gMoveOption;
extern MenuWidget gPointWidget;
extern MenuDropItem gCourseEditMenuItems[];
extern s32* gCourseEditMenuOptions[];

void func_xk2_800DB924(void) {
    s32 i;
    s32 j;

    if ((gCreateOption != CREATE_OPTION_POINT) || (gMoveOption != MOVE_OPTION_CLEAR) ||
        !(D_80119720->buttonPressed & BTN_A)) {
        return;
    }

    j = 0;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 != 0) {
            continue;
        }

        D_8010C770.bankAngle[j] = COURSE_CONTEXT()->courseData.bankAngle[i];
        D_8010C770.pit[j] = COURSE_CONTEXT()->courseData.pit[i];
        D_8010C770.dash[j] = COURSE_CONTEXT()->courseData.dash[i];
        D_8010C770.dirt[j] = COURSE_CONTEXT()->courseData.dirt[i];
        D_8010C770.ice[j] = COURSE_CONTEXT()->courseData.ice[i];
        D_8010C770.jump[j] = COURSE_CONTEXT()->courseData.jump[i];
        D_8010C770.landmine[j] = COURSE_CONTEXT()->courseData.landmine[i];
        D_8010C770.gate[j] = COURSE_CONTEXT()->courseData.gate[i];
        D_8010C770.building[j] = COURSE_CONTEXT()->courseData.building[i];
        D_8010C770.sign[j] = COURSE_CONTEXT()->courseData.sign[i];

        D_xk2_80119920[j] = D_802CB6D0.unk_0000[i];
        j++;
    }

    if (D_802CB6D0.controlPointCount - j != 0) {
        Audio_TriggerSystemSE(NA_SE_39);
    }
    D_802CB6D0.controlPointCount = j;
    for (i = 0; i < j; i++) {
        D_802CB6D0.unk_0000[i] = D_xk2_80119920[i];

        COURSE_CONTEXT()->courseData.bankAngle[i] = D_8010C770.bankAngle[i];
        COURSE_CONTEXT()->courseData.pit[i] = D_8010C770.pit[i];
        COURSE_CONTEXT()->courseData.dash[i] = D_8010C770.dash[i];
        COURSE_CONTEXT()->courseData.dirt[i] = D_8010C770.dirt[i];
        COURSE_CONTEXT()->courseData.ice[i] = D_8010C770.ice[i];
        COURSE_CONTEXT()->courseData.jump[i] = D_8010C770.jump[i];
        COURSE_CONTEXT()->courseData.landmine[i] = D_8010C770.landmine[i];
        COURSE_CONTEXT()->courseData.gate[i] = D_8010C770.gate[i];
        COURSE_CONTEXT()->courseData.building[i] = D_8010C770.building[i];
        COURSE_CONTEXT()->courseData.sign[i] = D_8010C770.sign[i];
    }

    func_xk2_800E6F9C();
    func_xk2_800DB550();

    if (D_802CB6D0.controlPointCount != 0) {
        D_800D6CA0.unk_0C = 0;
    } else {
        D_800D6CA0.unk_0C = -1;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        gCreateOption = CREATE_OPTION_COURSE;
        gCourseEditMenuItems[1].contentsTex = aCourseEditPointBoldTex;
        gCourseEditMenuItems[1].widget = &gPointWidget;
        gCourseEditMenuOptions[1] = &gPointOption;
        gCourseEditMenuItems[2].contentsTex = NULL;
        gCourseEditMenuItems[2].widget = NULL;
        gPointOption = POINT_OPTION_SET;
    }
    D_xk2_800F704C = -1;
    D_xk2_800F7040 = 3;
    D_800D6CA0.unk_00 = 0;
    func_xk2_800E6F9C();
    func_xk2_800DC3F8();
    D_802CB6D0.unk_0000[0].trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000);
    if (func_xk2_800E6B3C()) {
        D_xk2_800F7044 = 0;
    }
}

s32 func_xk2_800DBC68(void) {
    s32 previousSegmentIndex;
    s32 i;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        previousSegmentIndex = D_802CB6D0.unk_0000[i].prev->segmentIndex;
        if ((D_802CB6D0.unk_0000[i].trackSegmentInfo & TRACK_FLAG_8000000) &&
            (D_802CB6D0.unk_0000[previousSegmentIndex].trackSegmentInfo & TRACK_FLAG_8000000)) {
            return 0;
        }
    }
    return 1;
}

extern u32 gGameFrameCount;

void func_xk2_800DBCF8(void) {
    s32 temp_v1;
    s32 temp_a1;
    s32 var_a2;

    temp_v1 = D_80119720->stickX;
    temp_a1 = D_80119720->stickY;

    if (SQ(temp_v1) + SQ(temp_a1) < 100) {
        return;
    }

    var_a2 = sqrtf(SQ(temp_v1) + SQ(temp_a1));
    switch (gMoveOption) {
        case MOVE_OPTION_MOVE_Y:
            if (ABS(temp_v1) > ABS(temp_a1)) {
                return;
            }
            break;
        case MOVE_OPTION_WIDTH:
        case MOVE_OPTION_BANK:
            if (ABS(temp_v1) < ABS(temp_a1)) {
                return;
            }
            break;
        case MOVE_OPTION_CENTER:
            if (ABS(temp_v1) < ABS(temp_a1)) {
                return;
            }
            if (func_xk2_800DBC68() != 0) {
                Audio_TriggerSystemSE(NA_SE_32);
                return;
            }
            break;
        default:
            break;
    }
    var_a2 = 120 / var_a2;
    if (var_a2 == 0) {
        var_a2 = 1;
    }
    if (((gGameFrameCount % var_a2) == 0) && ((func_xk1_8002DAD4() == 1) || (func_xk1_8002DAD4() >= 9))) {
        Audio_TriggerSystemSE(NA_SE_38);
    }
}

void func_xk2_800DBEE4(void) {

    if (gInCourseEditTestRun || (D_800D6CA0.unk_08 != 0)) {
        return;
    }

    switch (gCreateOption) {
        case CREATE_OPTION_COURSE:
            func_xk2_800DEB04();
            break;
        case CREATE_OPTION_POINT:
            if (D_800D6CA0.unk_00 != 0) {
                func_xk2_800DBCF8();
            }
            switch (D_800D6CA0.unk_00) {
                case 0:
                    func_xk2_800DEB04();
                    break;
                case 1:
                    switch (gMoveOption) {
                        case MOVE_OPTION_MOVE_XZ:
                            func_xk2_800D9670();
                            break;
                        case MOVE_OPTION_MOVE_Y:
                            func_xk2_800DA288();
                            break;
                        case MOVE_OPTION_WIDTH:
                            func_xk2_800DA984();
                            break;
                        case MOVE_OPTION_BANK:
                            func_xk2_800DADEC();
                            break;
                        case MOVE_OPTION_CENTER:
                            func_xk2_800DB154();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case CREATE_OPTION_DESIGN:
        case CREATE_OPTION_PARTS:
        case CREATE_OPTION_BACKGROUND:
        case CREATE_OPTION_BGM:
            func_xk2_800DEB04();
            break;
        default:
            break;
    }
}

void func_xk2_800DC018(void) {
    if (D_800D6CA0.unk_00 == 1) {
        return;
    }
    if ((gCourseEditCursorYPos < 56) || ((gCourseEditCursorXPos >= 232) && (gCourseEditCursorXPos <= 295) &&
                                         (gCourseEditCursorYPos >= 204) && (gCourseEditCursorYPos < 220))) {
        return;
    }

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_Z) {
        D_xk2_800F6838 = gCourseEditCursorXPos;
        D_xk2_800F683C = gCourseEditCursorYPos;
        D_xk2_800F6840 = gCourseEditCursorXPos;
        D_xk2_800F6844 = gCourseEditCursorYPos;
        D_800D6CA0.unk_08 = 5;
    }
}

void func_xk2_800DC0D4(void) {
    D_xk2_800F6840 = gCourseEditCursorXPos;
    D_xk2_800F6844 = gCourseEditCursorYPos;
}

s32 func_xk2_800DC0F8(void) {
    s32 i;
    s32 j;
    CourseSegment* var_s1;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;

    j = 0;
    if (gCreateOption != CREATE_OPTION_POINT) {
        return 0;
    }

    if (D_xk2_800F6838 < D_xk2_800F6840) {
        sp68 = D_xk2_800F6838;
        sp60 = D_xk2_800F6840;
    } else {
        sp68 = D_xk2_800F6840;
        sp60 = D_xk2_800F6838;
    }
    if (D_xk2_800F683C < D_xk2_800F6844) {
        sp64 = D_xk2_800F683C;
        sp5C = D_xk2_800F6844;
    } else {
        sp64 = D_xk2_800F6844;
        sp5C = D_xk2_800F683C;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (func_xk2_800EF090(D_802CB6D0.unk_0000[i].pos, &sp70, &sp6C) != 0) {
            continue;
        }
        if ((sp70 >= sp68) && (sp60 >= sp70) && (sp6C >= sp64) && (sp5C >= sp6C)) {
            j++;
            D_80128690[i].unk_08 = 1;
            D_800D6CA0.unk_00 = 1;
            func_xk2_800EF78C();
            D_xk2_80119730 = 0.0f;
            D_xk2_80119734 = 0.0f;
            D_xk2_80119738 = 0.0f;
            D_xk2_8011973C = 0;
            D_xk2_80119740 = 0;
        }
    }
    return j;
}

void func_xk2_800DC2D0(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    if ((gCreateOption != CREATE_OPTION_POINT) || (D_800D6CA0.unk_00 == 1)) {
        return;
    }
    Audio_TriggerSystemSE(NA_SE_69);
    D_xk2_800F704C = -1;
    func_xk2_800DC3F8();
    temp_v0 = func_xk2_800DC0F8();
    if (temp_v0 != 0) {
        D_xk2_800F7040 = 3;
    }
    if ((temp_v0 == 0) && (D_xk2_800F6838 == D_xk2_800F6840) && (D_xk2_800F683C == D_xk2_800F6844)) {
        func_xk2_800DC3F8();
        temp_v0_2 = func_xk2_800EFDE4(4000.0f);
        if (temp_v0_2 != -1) {
            D_800D6CA0.unk_0C = temp_v0_2;
            D_xk2_80119730 = 0.0f;
            D_xk2_80119734 = 0.0f;
            D_xk2_80119738 = 0.0f;
            D_xk2_8011973C = 0;
            D_xk2_80119740 = 0;
            D_80128690[temp_v0_2].unk_08 = 1;
            D_800D6CA0.unk_00 = 1;
            D_xk2_800F7040 = 3;
            func_xk2_800EF78C();
        }
    }
}

void func_xk2_800DC3F8(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_80128690[i].unk_08 = 0;
    }
}

void func_xk2_800DC428(void) {
    if ((gCreateOption != CREATE_OPTION_POINT) || (D_800D6CA0.unk_00 != 1)) {
        return;
    }

    if (D_80119720->buttonPressed & BTN_B) {
        D_802CB6D0 = D_807B6528;
        D_xk2_801197EC = D_802CB6D0.unk_0000;
        D_xk2_800F704C = -1;
        func_xk2_800DC3F8();
        D_800D6CA0.unk_0C = D_xk2_80119800;
        D_800D6CA0.unk_00 = 0;
    }
}

void func_xk2_800DC4E4(void) {
    if ((D_80119720->buttonPressed & BTN_A) && (D_800D6CA0.unk_08 == 0) && (gPointOption == POINT_OPTION_START) &&
        (gCreateOption == CREATE_OPTION_COURSE) && (gCourseEditCursorYPos >= 0x38) && (func_xk2_800DEFCC() == 0)) {
        D_xk2_800F7040 = 3;
        D_800D6CA0.unk_0C = 1;
        func_xk2_800DEB38();
        D_800D6CA0.unk_0C = 0;
    }
}

void func_xk2_800DC58C(void) {
    if ((D_800D6CA0.unk_00 == 1) || (D_800D6CA0.unk_08 != 0) || (gCreateOption != CREATE_OPTION_POINT) ||
        (gCourseEditCursorYPos < 56)) {
        return;
    }
    if (D_800D11C8[0] == 1) {
        D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
    }
    if (D_80119720->buttonPressed & BTN_A) {
        if (D_800D11C8[0] == 0) {
            D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
        }
        if (D_xk2_800F703C != -1) {
            Audio_TriggerSystemSE(NA_SE_30);
        } else {
            Audio_TriggerSystemSE(NA_SE_32);
        }
    }
}

extern s32 D_xk1_80030608;
extern s32 D_8076C968;

void func_xk2_800DC67C(void) {
    s32 sp16C;
    s32 sp168;
    s32 sp164;
    CourseSegment spC0;
    CourseSegment* spBC;
    s32 temp_a1;
    s32 var_v1;

    if ((D_800D6CA0.unk_08 != 0) || (gPointOption != POINT_OPTION_SET) || (gCreateOption != CREATE_OPTION_COURSE) ||
        (gCourseEditCursorYPos < 0x38) || (D_800D6CA0.unk_00 != 0)) {
        return;
    }
    if (D_800D11C8[0] == 1) {
        D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
    }
    if (D_80119720->buttonPressed & BTN_A) {
        if (D_800D11C8[0] == 0) {
            D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
        }
        if (D_xk2_800F703C != -1) {
            Audio_TriggerSystemSE(NA_SE_36);
            return;
        }
        if (D_802CB6D0.controlPointCount >= 0x40) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        Audio_TriggerSystemSE(NA_SE_36);
        D_xk2_800F704C = D_xk2_800F703C;
        if ((gCreateOption == CREATE_OPTION_COURSE) && (D_xk2_80104CA0[1] == 0) && (D_xk2_80104CA0[10] == 0)) {
            spC0 = D_800D6CA0.unk_28;
            if ((spC0.pos.x < -15000.0f) || (spC0.pos.x > 15000.0f) || (spC0.pos.y < 0.0f) || (spC0.pos.y > 5000.0f) ||
                (spC0.pos.z < -15000.0f) || (spC0.pos.z > 15000.0f)) {
                Audio_TriggerSystemSE(NA_SE_32);
                return;
            }
            if (D_8076C968 != 0) {
                sp16C = Math_Round(spC0.pos.x);
                sp168 = Math_Round(spC0.pos.y);
                sp164 = Math_Round(spC0.pos.z);
                var_v1 = ABS(sp16C);
                temp_a1 = D_xk1_80030608 / 2;
                if (var_v1 < temp_a1) {
                    sp16C = 0;
                } else if (sp16C > 0) {
                    sp16C = ((temp_a1 + sp16C) / D_xk1_80030608) * D_xk1_80030608;
                } else {
                    sp16C = ((sp16C - temp_a1) / D_xk1_80030608) * D_xk1_80030608;
                }

                var_v1 = ABS(sp168);
                if (var_v1 < temp_a1) {
                    sp168 = 0;
                } else if (sp168 > 0) {
                    sp168 = ((temp_a1 + sp168) / D_xk1_80030608) * D_xk1_80030608;
                } else {
                    sp168 = ((sp168 - temp_a1) / D_xk1_80030608) * D_xk1_80030608;
                }

                var_v1 = ABS(sp164);
                if (var_v1 < temp_a1) {
                    sp164 = 0;
                } else if (sp164 > 0) {
                    sp164 = ((temp_a1 + sp164) / D_xk1_80030608) * D_xk1_80030608;
                } else {
                    sp164 = ((sp164 - temp_a1) / D_xk1_80030608) * D_xk1_80030608;
                }
                spC0.pos.x = sp16C;
                spC0.pos.y = sp168;
                spC0.pos.z = sp164;
            }
            if (D_802CB6D0.controlPointCount != 0) {
                spBC = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
                if (Math_VectorGetDistance(spC0.pos, spBC->pos) < 498.0f) {
                    Audio_TriggerSystemSE(NA_SE_32);
                    return;
                }
                spBC = spBC->next;
                if (Math_VectorGetDistance(spC0.pos, spBC->pos) < 498.0f) {
                    Audio_TriggerSystemSE(NA_SE_32);
                    return;
                }
            }

            Audio_TriggerSystemSE(NA_SE_39);
            if ((D_xk2_800F704C == -1) && (D_802CB6D0.controlPointCount < 0x40)) {
                D_xk2_800F7040 = 3;
                func_xk2_800EF78C();
                D_xk2_800F704C = -1;
                func_xk2_800E6CA8(D_800D6CA0.unk_0C, spC0);
            }
        }
    }
}

void func_xk2_800DCCD8(void) {
    CourseSegment* temp_at = &D_800D6CA0.unk_28;
    CourseSegment* temp_v0_2;

    if ((gCreateOption != CREATE_OPTION_POINT) || (D_800D6CA0.unk_00 != 1)) {
        return;
    }
    if ((gMoveOption != MOVE_OPTION_CLEAR) && (D_80119720->buttonPressed & BTN_A)) {
        D_xk2_800F7040 = 3;
        if (D_8076C968 != 0) {
            func_xk2_800DE4F8();
        }
        if (gMoveOption != MOVE_OPTION_STRAIGHT) {
            Audio_TriggerSystemSE(NA_SE_39);
        }
        func_xk2_800DC3F8();
        temp_v0_2 = &D_802CB6D0.unk_0000[D_xk2_800F704C];
        temp_at->radiusLeft = temp_v0_2->radiusLeft;
        temp_at->radiusRight = temp_v0_2->radiusRight;
        D_xk2_800F704C = -1;
        D_800D6CA0.unk_00 = 0;
    }
}

extern s32 D_xk2_800F7058;

void func_xk2_800DCDD0(void) {
    s32 var_v1;
    s32 sp18;
    s32 var_a0;
    s32 i;

    if (gCourseEditCursorYPos < 56) {
        return;
    }

    // FAKE
    if (var_v1) {}

    if (((gCreateOption == CREATE_OPTION_COURSE) || (gCreateOption == CREATE_OPTION_DESIGN) ||
         (gCreateOption == CREATE_OPTION_PARTS)) &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_Z) && (D_802CB6D0.controlPointCount != 0)) {
        sp18 = func_xk2_800DD76C(400.0f);
        if (sp18 != -1) {
            Audio_TriggerSystemSE(NA_SE_69);

            for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
                var_a0 = D_80128690[D_802CB6D0.unk_0000[i].next->segmentIndex].unk_00;
                var_v1 = D_80128690[i].unk_00;
                if (i + 1 == D_802CB6D0.controlPointCount) {
                    var_a0 = D_xk2_800F7058;
                }
                if ((i == 0) && (var_a0 < var_v1)) {
                    var_v1 = 0;
                }
                if ((sp18 >= var_v1) && (sp18 < var_a0)) {
                    D_800D6CA0.unk_0C = i;
                }
            }
        }
    }
}

extern s32 gRoadTypeOption;

s32 D_xk2_800F6950[] = {
    (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2),
    (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3),
    (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_4),
    (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_5),
    (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_6),
};

void func_xk2_800DCF2C(void) {
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_ROAD) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if ((sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
        (D_xk2_800F6950[gRoadTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        func_xk2_800EF78C();
        Audio_TriggerSystemSE(NA_SE_39);
        sp1C->trackSegmentInfo = D_xk2_800F6950[gRoadTypeOption];
        D_xk2_800F7040 = 3;
    }
}

extern s32 gHRoadTypeOption;

s32 D_xk2_800F6964[] = {
    (TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_0),
    (TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_1),
    (TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_2),
};

void func_xk2_800DCFE0(void) {
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_H_ROAD) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if (!func_xk2_800DD688(TRACK_SHAPE_WALLED_ROAD) &&
        (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
            (D_xk2_800F6964[gHRoadTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F6964[gHRoadTypeOption];
        D_xk2_800F7040 = 3;
    }
}

extern s32 gTRoadTypeOption;

s32 D_xk2_800F6970[] = {
    (TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_0),
    (TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_1),
    (TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_2),
};

void func_xk2_800DD0AC(void) {
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_T_ROAD) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if (!func_xk2_800DD688(TRACK_SHAPE_BORDERLESS_ROAD) &&
        (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
            (D_xk2_800F6970[gTRoadTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F6970[gTRoadTypeOption];
        D_xk2_800F7040 = 3;
    }
}

extern s32 gTunnelTypeOption;

s32 D_xk2_800F697C[] = {
    (TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_0),
    (TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_1),
    (TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_2),
    (TRACK_FLAG_INSIDE | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_3),
};

void func_xk2_800DD178(void) {
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_TUNNEL) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if (!func_xk2_800DD688(TRACK_SHAPE_TUNNEL) &&
        (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
            (D_xk2_800F697C[gTunnelTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F697C[gTunnelTypeOption];
        D_xk2_800F7040 = 3;
    }
}

extern s32 gPipeTypeOption;

s32 D_xk2_800F698C[] = {
    (TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_0),
    (TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_1),
    (TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_2),
    (TRACK_FLAG_INSIDE | TRACK_SHAPE_PIPE | PIPE_3),
};

void func_xk2_800DD244(void) {
    f32 temp_fv0;
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_PIPE) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if (!func_xk2_800DD688(TRACK_SHAPE_PIPE) &&
        (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
            (D_xk2_800F698C[gPipeTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F698C[gPipeTypeOption];
        temp_fv0 = (sp1C->radiusLeft + sp1C->radiusRight) * 0.5f;
        sp1C->radiusLeft = temp_fv0;
        sp1C->radiusRight = temp_fv0;
        sp1C = sp1C->next;
        temp_fv0 = (sp1C->radiusLeft + sp1C->radiusRight) * 0.5f;
        sp1C->radiusLeft = temp_fv0;
        sp1C->radiusRight = temp_fv0;

        D_xk2_800F7040 = 3;
    }
}

extern s32 gHalfPipeTypeOption;

s32 D_xk2_800F699C[] = {
    (TRACK_SHAPE_HALF_PIPE | HALF_PIPE_0),
    (TRACK_SHAPE_HALF_PIPE | HALF_PIPE_1),
    (TRACK_SHAPE_HALF_PIPE | HALF_PIPE_2),
    (TRACK_SHAPE_HALF_PIPE | HALF_PIPE_3),
};

void func_xk2_800DD350(void) {
    f32 temp_fv0;
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_HALF_PIPE) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if (!func_xk2_800DD688(TRACK_SHAPE_HALF_PIPE) &&
        (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
            (D_xk2_800F699C[gHalfPipeTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F699C[gHalfPipeTypeOption];
        temp_fv0 = (sp1C->radiusLeft + sp1C->radiusRight) * 0.5f;
        sp1C->radiusLeft = temp_fv0;
        sp1C->radiusRight = temp_fv0;
        sp1C = sp1C->next;
        temp_fv0 = (sp1C->radiusLeft + sp1C->radiusRight) * 0.5f;
        sp1C->radiusLeft = temp_fv0;
        sp1C->radiusRight = temp_fv0;

        D_xk2_800F7040 = 3;
    }
}

extern s32 gCylinderTypeOption;

s32 D_xk2_800F69AC[] = {
    (TRACK_SHAPE_CYLINDER | CYLINDER_0),
    (TRACK_SHAPE_CYLINDER | CYLINDER_1),
    (TRACK_SHAPE_CYLINDER | CYLINDER_2),
    (TRACK_SHAPE_CYLINDER | CYLINDER_3),
};

void func_xk2_800DD45C(void) {
    f32 temp_fv0;
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_CYLINDER) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if (!func_xk2_800DD688(TRACK_SHAPE_CYLINDER) &&
        (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) !=
            (D_xk2_800F69AC[gCylinderTypeOption] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F69AC[gCylinderTypeOption];
        temp_fv0 = (sp1C->radiusLeft + sp1C->radiusRight) * 0.5f;
        sp1C->radiusLeft = temp_fv0;
        sp1C->radiusRight = temp_fv0;
        sp1C = sp1C->next;
        temp_fv0 = (sp1C->radiusLeft + sp1C->radiusRight) * 0.5f;
        sp1C->radiusLeft = temp_fv0;
        sp1C->radiusRight = temp_fv0;

        D_xk2_800F7040 = 3;
    }
}

void func_xk2_800DD568(void) {
    CourseSegment* sp1C;

    if (gDesignStyleOption != TRACK_DESIGN_STYLE_SPACE) {
        return;
    }

    sp1C = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    if ((sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) != (TRACK_SHAPE_AIR | TRACK_TYPE_NONE)) {
        Audio_TriggerSystemSE(NA_SE_39);
        func_xk2_800EF78C();
        COURSE_CONTEXT()->courseData.dash[sp1C->segmentIndex] = DASH_NONE;
        COURSE_CONTEXT()->courseData.pit[sp1C->segmentIndex] = PIT_NONE;
        COURSE_CONTEXT()->courseData.dirt[sp1C->segmentIndex] = DIRT_NONE;
        COURSE_CONTEXT()->courseData.ice[sp1C->segmentIndex] = ICE_NONE;
        sp1C->trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_SHAPE_AIR | TRACK_TYPE_NONE);
        D_xk2_800F7040 = 3;
    }
}

void func_xk2_800DD638(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_80128690[i].unk_00 = 0;
        D_80128690[i].unk_04 = 0;
        D_80128690[i].unk_08 = 0;
    }
}

bool func_xk2_800DD688(s32 arg0) {
    CourseSegment* temp_v0;
    s32 temp_v1;
    s32 temp_a1;

    temp_v0 = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    temp_v1 = temp_v0->prev->trackSegmentInfo & TRACK_FLAG_JOINABLE;
    temp_a1 = temp_v0->next->trackSegmentInfo & TRACK_FLAG_JOINABLE;

    if (temp_v1 && temp_a1) {
        return false;
    }
    if (temp_v1 || temp_a1) {
        if (arg0 == (temp_v0->prev->trackSegmentInfo & TRACK_SHAPE_MASK)) {
            return false;
        }
        if (arg0 == (temp_v0->next->trackSegmentInfo & TRACK_SHAPE_MASK)) {
            return false;
        }
        func_xk2_800EE664(0x11);
        Audio_TriggerSystemSE(NA_SE_32);
    } else {
        if ((arg0 == (temp_v0->prev->trackSegmentInfo & TRACK_SHAPE_MASK)) &&
            (arg0 == (temp_v0->next->trackSegmentInfo & TRACK_SHAPE_MASK))) {
            return false;
        }
        func_xk2_800EE664(0x11);
        Audio_TriggerSystemSE(NA_SE_32);
    }

    return true;
}

s32 func_xk2_800DD76C(f32 arg0) {
    s32 i;
    s32 sp78;
    s32 sp74;
    s32 temp_v0;
    s32 temp_v1;
    Vec3f sp60;
    s32 var_fp;
    f32 temp_fv0;

    var_fp = -1;
    for (i = 0; i < D_xk2_800F7058; i++) {
        sp60 = D_8011C220[i].pos;
        if (func_xk2_800EF090(sp60, &sp78, &sp74) != 0) {
            continue;
        }
        temp_v0 = gCourseEditCursorXPos - sp78;
        temp_v1 = gCourseEditCursorYPos - sp74;
        temp_fv0 = SQ(temp_v0) + SQ(temp_v1);
        if (temp_fv0 < arg0) {
            arg0 = temp_fv0;
            var_fp = i;
        }
    }
    return var_fp;
}

void func_xk2_800DD8C8(void) {
    if ((gCreateOption != CREATE_OPTION_POINT) || (gMoveOption != MOVE_OPTION_STRAIGHT) ||
        (gCourseEditCursorYPos <= 56)) {
        return;
    }
    if (D_80119720->buttonPressed & BTN_A) {
        func_xk2_800EFCD0();
    }

    // TODO: move to appropriate place
    PRINTF("BUBU 02\n");
    PRINTF("BUBU 03\n");
    PRINTF("BACK UP 0\n");
    PRINTF("BACK UP 1\n");
    PRINTF("BUBU 04\n");
    PRINTF("BACK UP 2\n");
    PRINTF("BUBU 05\n");
    PRINTF("BACK UP 3\n");
    PRINTF("BUBU 06\n");
    PRINTF("BUBU 07\n");
    PRINTF("BACK UP 4\n");
    PRINTF("BACK UP 5\n");
    PRINTF("BUBU 08\n");
    PRINTF("BUBU 09\n");
    PRINTF("BACK UP 6\n");
    PRINTF("BACK UP 7\n");
    PRINTF("BUBU 10\n");
    PRINTF("BACK UP 8\n");
    PRINTF("BUBU 11\n");
    PRINTF("BACK UP 9\n");
    PRINTF("BUBU 12\n");
    PRINTF("BACK UP 10\n");
    PRINTF("BUBU 13\n");
    PRINTF("BACK UP 11\n");
    PRINTF("BUBU 14\n");
    PRINTF("BACK UP 13\n");
    PRINTF("BUBU 15\n");
    PRINTF("BACK UP 14\n");
    PRINTF("BACK UP 14\n");
    PRINTF("BUBU 16\n");
    PRINTF("BACK UP 15\n");
    PRINTF("BUBU 17\n");
    PRINTF("BACK UP 16\n");
    PRINTF("BUBU 18\n");
    PRINTF("BACK UP 17\n");
    PRINTF("SPEED_LEVEL %d\n");
    PRINTF("BUBU 19\n");
    PRINTF("BUBU 20\n");
    PRINTF("BUBU 21\n");
    PRINTF("BUBU 22\n");
    PRINTF("BUBU 23\n");
    PRINTF("%d\n");
    PRINTF("DELETE BY BACK\n");
    PRINTF("DELETE BY NEXT\n");
    PRINTF("points %d->");
    PRINTF("%d\n");
    PRINTF("BACK UP 18\n");
    PRINTF("NOT KAKOMI BUT 1KO\n");
    PRINTF("SELECTED %d\n");
    PRINTF("BACK UP 19\n");
    PRINTF("KAKOMI OK\n");
    PRINTF("BUBU 24\n");
    PRINTF("BUBU 25\n");
    PRINTF("BUBU 26\n");
    PRINTF("BUBU 27\n");
    PRINTF("BUBU 28\n");
    PRINTF("BACK UP 21\n");
    PRINTF("NEAR vertexInfo is %d\n");
    PRINTF("SELECTED AREA IS %d\n");
    PRINTF("BACK UP 22\n");
    PRINTF("BACK UP 23\n");
    PRINTF("BACK UP 24\n");
    PRINTF("BACK UP 25\n");
    PRINTF("BACK UP 26\n");
    PRINTF("BACK UP 27\n");
    PRINTF("BACK UP 28\n");
    PRINTF("BACK UP 29\n");
    PRINTF("BUBU 29\n");
    PRINTF("BUBU 30\n");
    PRINTF("EDIT_MODE_COURSE 03\n");
    PRINTF("EDIT_MODE_COURSE 03\n");
    PRINTF("DO WAIT_SAVE_FILE \n");
    PRINTF("EDIT_MODE_FILE_LOADING 1\n");
    PRINTF("NAME_INPUT_AGAIN\n");
    PRINTF("EDIT_MODE_COURSE 04\n");
    PRINTF("SAVE IN WAIT\n");
}

extern u8 D_80030060[];
extern s32 gCourseEditFileOption;
extern s32 gCourseEditEntryOption;
extern s32 D_xk1_80032C20;
extern u8 D_xk1_8003A570[];
extern unk_8003A5D8 D_xk1_8003A5D8[];

extern s32 D_xk2_800F7060;
extern s32 D_xk2_800F7064;
extern s32 D_xk2_80104364;
extern s32 D_xk2_80104368;
extern s32 D_xk2_80104378;

void func_xk2_800DD938(void) {
    unk_8003A5D8* sp1C;

    if (D_80119720->buttonPressed & BTN_B) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gCourseEditFileOption = -1;
        gCourseEditEntryOption = -1;
        return;
    }
    if (!(D_80119720->buttonPressed & BTN_A)) {
        func_xk1_8002D2F0();
        return;
    }
    if (D_xk1_80032C20 == 0) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gCourseEditFileOption = -1;
        gCourseEditEntryOption = -1;
        return;
    }
    if (D_xk2_80104378 == 6) {
        D_xk2_80104378 = 0;
        Audio_TriggerSystemSE(NA_SE_37);
    } else {
        Audio_TriggerSystemSE(NA_SE_36);
    }
    D_xk2_80104364 = 0;
    D_xk2_80104368 = 0;
    sp1C = &D_xk1_8003A5D8[D_xk2_80119884];
    switch (D_80119880) {
        case 6:
            func_xk2_800F5C50();
            if (D_xk2_80119884 >= 0x18) {
                Course_Load(D_xk2_80119884 + 6);
            } else {
                Course_Load(D_xk2_80119884);
            }
            D_80030060[0] = '\0';
            func_xk2_800EACB0();
            D_xk2_800F7040 = 3;
            D_xk2_800F7060 = Math_Rand2() % 30;
            D_xk2_800F7064 = Math_Rand2() & 3;
            break;
        case 0:
            func_xk2_800F5C50();
            func_xk2_800EAF24(sp1C);
            gCourseEditFileOption = -1;
            D_800D6CA0.unk_08 = 0x13;
            return;
        case -1:
        case 9:
            if (func_xk1_8002BFA4() > 100) {
                D_800D6CA0.unk_08 = 0;
                return;
            }
            func_xk1_800294AC();
            ExpansionKit_NameEntryInit(func_xk1_8002AC24);
            D_800D6CA0.unk_08 = 2;
            return;
        case 1:
            if (!(sp1C->attr & MFS_FILE_ATTR_FORBID_W)) {
                mfsStrCpy(D_xk1_8003A570, sp1C);
                D_800D6CA0.unk_08 = 0x34;
                func_8076877C(1, "CRSD");
                // TODO: move to appropriate place
                PRINTF("EDIT_MODE_COURSE 05\n");
                PRINTF("POINTS NEAR!! HOSEI\n");
                PRINTF("POS %d, %d, %d\n");
                PRINTF("NOW_DISK_ACCESS CAN'T CURSOL_MOVE\n");
                PRINTF("BUBU 32\n");
                PRINTF("BACK UP 35\n");
                PRINTF("INITILIZE OBJECT\n");
                PRINTF("INITILIZE OBJECT END\n");
                PRINTF("OPTION IN\n");
                PRINTF("EDIT_MODE_COURSE 06\n");
                PRINTF("EDIT_MODE_COURSE 07\n");
                PRINTF("EDIT_MODE_COURSE 07\n");
                PRINTF("EDIT_MODE_COURSE 07\n");
                PRINTF("EDIT_MODE_COURSE 07\n");
                return;
            }
            break;
        case 3:
            if (!(sp1C->attr & MFS_FILE_ATTR_FORBID_W)) {
                func_xk1_800294AC();
                ExpansionKit_NameEntryInit(func_xk1_8002AC24);
                D_800D6CA0.unk_08 = 2;
                return;
            }
            break;
        case 2:
            if (!(sp1C->attr & MFS_FILE_ATTR_FORBID_W)) {
                func_xk2_800EBFE8(sp1C->name);
                func_807688D0(MFS_ENTRY_WORKING_DIR, sp1C->name, sp1C->extension, true);
                gCourseEditFileOption = -1;
                D_800D6CA0.unk_08 = 0x22;
                return;
            }
            break;
        case 7:
            func_xk2_800EAFA8(sp1C);
            break;
        default:
            break;
    }
    gCourseEditFileOption = -1;
    D_800D6CA0.unk_08 = 0;
}

void func_xk2_800DDC2C(Vec3f* arg0) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 temp_a1;
    s32 var_a0;

    sp1C = Math_Round(arg0->x);
    sp18 = Math_Round(arg0->y);
    sp14 = Math_Round(arg0->z);

    switch (gMoveOption) {
        case MOVE_OPTION_MOVE_XZ:
            var_a0 = ABS(sp1C);
            temp_a1 = D_xk1_80030608 / 2;

            if (var_a0 < temp_a1) {
                sp1C = 0;
            } else if (sp1C > 0) {
                sp1C = ((temp_a1 + sp1C) / D_xk1_80030608) * D_xk1_80030608;
            } else {
                sp1C = ((sp1C - temp_a1) / D_xk1_80030608) * D_xk1_80030608;
            }

            if (ABS(sp14) < temp_a1) {
                sp14 = 0;
            } else if (sp14 > 0) {
                sp14 = ((temp_a1 + sp14) / D_xk1_80030608) * D_xk1_80030608;
            } else {
                sp14 = ((sp14 - temp_a1) / D_xk1_80030608) * D_xk1_80030608;
            }
            break;
        case MOVE_OPTION_MOVE_Y:
            var_a0 = ABS(sp18);
            temp_a1 = D_xk1_80030608 / 2;
            if (var_a0 < temp_a1) {
                sp18 = 0;
            } else if (sp18 > 0) {
                sp18 = ((temp_a1 + sp18) / D_xk1_80030608) * D_xk1_80030608;
            } else {
                sp18 = ((sp18 - temp_a1) / D_xk1_80030608) * D_xk1_80030608;
            }
            break;
    }
    arg0->x = sp1C;
    arg0->y = sp18;
    arg0->z = sp14;
}

void func_xk2_800DDEF4(Vec3f* arg0, Vec3f arg1, Vec3f arg2, Vec3f arg3) {
    Vec3f spAC;
    s32 i = 0;
    f32 var_fs1 = 1.0f;
    f32 temp_fs0;
    f32 temp_fv0;
    Vec3f sp6C[] = {
        { 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, -1.0f },
        { -1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f },
    };

    temp_fs0 = Math_VectorGetDistance(arg2, arg1);
    temp_fv0 = Math_VectorGetDistance(arg2, arg3);
    if ((temp_fs0 > 498.0f) && (temp_fv0 > 498.0f)) {
        if (arg0) {}
        *arg0 = arg2;
        return;
    }

    spAC.y = arg2.y;
    while (true) {
        spAC.x = (sp6C[i].x * var_fs1 * 500.0f) + arg2.x;
        spAC.z = (sp6C[i].z * var_fs1 * 500.0f) + arg2.z;
        temp_fs0 = Math_VectorGetDistance(spAC, arg1);
        temp_fv0 = Math_VectorGetDistance(spAC, arg3);
        if ((temp_fs0 > 498.0f) && (temp_fv0 > 498.0f) && (spAC.x >= -15000.0f) && (spAC.x <= 15000.0f) &&
            (spAC.z >= -15000.0f) && (spAC.z <= 15000.0f)) {
            break;
        }

        if (++i == 4) {
            i = 0;
            var_fs1 += 1.0f;
        }
    }
    if (arg0) {}
    *arg0 = spAC;
}

void func_xk2_800DE210(Vec3f* arg0, Vec3f arg1, Vec3f arg2, Vec3f arg3) {
    Vec3f sp94;
    s32 i = 0;
    f32 var_fs1 = 1.0f;
    f32 temp_fs0;
    f32 temp_fv0;
    Vec3f sp6C[] = {
        { 0.0f, 1.0f, 0.0f },
        { 0.0f, -1.0f, 0.0f },
    };

    temp_fs0 = Math_VectorGetDistance(arg2, arg1);
    temp_fv0 = Math_VectorGetDistance(arg2, arg3);
    if ((temp_fs0 > 498.0f) && (temp_fv0 > 498.0f)) {
        if (arg0) {}
        *arg0 = arg2;
        return;
    }

    sp94 = arg2;
    while (true) {
        sp94.y = (sp6C[i].y * var_fs1 * 500.0f) + arg2.y;
        temp_fs0 = Math_VectorGetDistance(sp94, arg1);
        temp_fv0 = Math_VectorGetDistance(sp94, arg3);
        if ((temp_fs0 > 498.0f) && (temp_fv0 > 498.0f) && (sp94.y >= 0.0f) && (sp94.y <= 5000.0f)) {
            break;
        }

        if (++i == 2) {
            i = 0;
            var_fs1 += 1.0f;
        }
    }
    if (arg0) {}
    *arg0 = sp94;
}

void func_xk2_800DE4F8(void) {
    s32 pad[4];
    Vec3f sp8C;
    s32 pad2[8];
    CourseSegment* temp_s0;
    s32 i;

    if ((gMoveOption != MOVE_OPTION_MOVE_XZ) && (gMoveOption != MOVE_OPTION_MOVE_Y)) {
        return;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0 = &D_802CB6D0.unk_0000[i];
        sp8C.x = temp_s0->pos.x;
        sp8C.y = temp_s0->pos.y;
        sp8C.z = temp_s0->pos.z;
        func_xk2_800DDC2C(&sp8C);
        temp_s0->pos = sp8C;
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0 = &D_802CB6D0.unk_0000[i];
        switch (gMoveOption) {
            case MOVE_OPTION_MOVE_XZ:
                func_xk2_800DDEF4(&sp8C, temp_s0->prev->pos, temp_s0->pos, temp_s0->next->pos);
                break;
            case MOVE_OPTION_MOVE_Y:
                func_xk2_800DE210(&sp8C, temp_s0->prev->pos, temp_s0->pos, temp_s0->next->pos);
                break;
        }
        Math_Round(sp8C.x);
        Math_Round(sp8C.y);
        Math_Round(sp8C.z);
        temp_s0->pos = sp8C;
    }
    func_80074CE4(gCurrentCourseInfo);
}

extern s32 D_xk1_800305FC;
extern MenuWidget gCreateWidget;

void func_xk2_800DE758(void) {
    s32 pad[4];
    s32 temp_a0;
    s32 temp_v1;
    s32 sp1C;
    MenuWidget* sp18;

    if (D_800D6CA0.unk_08 == 2) {
        return;
    }

    sp18 = func_xk1_80026914(&gCourseEditWidget);
    temp_v1 = sp18->numItems;
    sp1C = D_xk1_800305FC;
    if (D_80119720->buttonCurrent & BTN_Z) {
        func_xk1_8002DCC8(&D_xk1_800305FC, temp_v1 - 1, 0);
    } else {
        func_xk1_8002DBD4(&D_xk1_800305FC, temp_v1 - 1, 0);
    }
    if ((sp18 == &gCreateWidget) && (D_xk1_800305FC != 0) && (D_802CB6D0.controlPointCount < 4)) {
        D_xk1_800305FC = 0;
        func_xk1_8002820C();
        D_xk1_8003A554 = gCreateWidget.top + 12;
        if (sp1C == 0) {
            Audio_TriggerSystemSE(NA_SE_32);
        }
    }

    temp_a0 = ((sp18->top + (D_xk1_800305FC * sp18->itemYOffset)) - func_xk1_800290B4()) + 12;
    if (D_xk1_8003A554 < temp_a0) {
        D_xk1_8003A554 += 16;
        if (D_xk1_8003A554 > temp_a0) {
            D_xk1_8003A554 = temp_a0;
        }
    }

    if (D_xk1_8003A554 > temp_a0) {
        D_xk1_8003A554 -= 16;
        if (D_xk1_8003A554 < temp_a0) {
            D_xk1_8003A554 = temp_a0;
        }
    }
    func_xk1_800269F4(&gCourseEditWidget, &D_xk1_8003A550, &D_xk1_8003A554);
}

extern u16* gCourseEditIconTextures[];

void func_xk2_800DE8D0(void) {

    if (D_80119720->buttonPressed & BTN_A) {
        if ((D_800D6CA0.unk_00 == 1) || (gCourseEditHighlightedIconIndex != 2)) {
            return;
        }
        Audio_TriggerSystemSE(NA_SE_36);
        D_8076C968 = (D_8076C968 + 1) % 2;
        if (D_8076C968 != 0) {
            gCourseEditIconTextures[2] = aCourseEditGoldGridAlignIconTex;
        } else {
            gCourseEditIconTextures[2] = aCourseEditGridAlignIconTex;
        }
    }
}

s32 func_xk2_800DE980(void) {
    if (D_80794E14 == 1) {
        return 0;
    }
    if (D_800D6CA0.unk_08 != 0) {
        return 0;
    }
    if ((gCourseEditCursorXPos >= 264) && (gCourseEditCursorXPos < 296) && (gCourseEditCursorYPos >= 20) &&
        (gCourseEditCursorYPos < 36) && (D_80119720->buttonPressed & BTN_A)) {
        return 1;
    }
    return 0;
}

s32 func_xk2_800DEA14(void) {
    return D_xk2_800F6848;
}

void func_xk2_800DEA20(void) {
    s32 sp1C;

    if (D_800D6CA0.unk_08 == 2) {
        return;
    }

    if ((D_xk2_800F684C != 1) && (D_80794E14 == 0)) {
        func_xk1_8002DAE0(&D_xk2_800F6848, 5, 1);
    }
    sp1C = D_xk2_800F684C;
    if (D_xk2_800F6848 == 5) {
        func_xk1_8002DBD4(&D_xk2_800F684C, 1, 1);
    }
    if (sp1C != D_xk2_800F684C) {
        Audio_TriggerSystemSE(NA_SE_35);
    }
    gCourseEditCursorXPos = (D_xk2_800F6848 * 48) + 48;
    gCourseEditCursorYPos = (D_xk2_800F684C * 16) + 28;
}

void func_xk2_800DEB04(void) {
    if (D_80794E14 == 0) {
        func_xk2_800D934C();
    }
}

void func_xk2_800DEB38(void) {
    CourseSegment* temp_v0;

    Audio_TriggerSystemSE(NA_SE_36);
    temp_v0 = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    D_xk2_80104CB8 = temp_v0->pos.x * 0.3f;
    D_xk2_80104CBC = temp_v0->pos.y * 0.3f;
    D_xk2_80104CC0 = temp_v0->pos.z * 0.3f;
    gCameras[0].eye.x = D_xk2_80104CB8;
    gCameras[0].eye.y = D_xk2_80104CBC + D_xk2_80104CB4;
    gCameras[0].eye.z = D_xk2_80104CC0;
}

void func_xk2_800DEC1C(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        if ((gCourseEditHighlightedIconIndex != 1) || (D_800D6CA0.unk_00 == 1)) {
            return;
        }
        Audio_TriggerSystemSE(NA_SE_36);
        if (D_8076C964 != 0) {
            D_8076C964 = 0;
            gCourseEditIconTextures[1] = aCourseEditGoldLineModeIconTex;
            return;
        }
        if (D_xk2_80104CA0[2] != 0) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        D_8076C964 = 1;
        gCourseEditIconTextures[1] = aCourseEditLineModeIconTex;
    }
}

extern s32 D_8076C96C;

void func_xk2_800DECF0(void) {

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        if ((gCourseEditHighlightedIconIndex != 3) || (D_800D6CA0.unk_00 == 1)) {
            return;
        }
        Audio_TriggerSystemSE(NA_SE_36);
        D_8076C96C ^= 1;
        if (D_8076C96C != 0) {
            gCourseEditIconTextures[3] = aCourseEditGoldQuestionIconTex;
        } else {
            gCourseEditIconTextures[3] = aCourseEditQuestionIconTex;
        }
    }
}

bool func_xk2_800DEDA8(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        if (D_xk2_80104CA0[i]) {
            return true;
        }
    }
    return false;
}

extern s32 D_800CCFBC;
extern s32 gCourseIndex;

extern s32 D_xk2_80103FF0;
extern s32 D_xk2_80103FF4;
extern s32 D_xk2_80103FF8;

void func_xk2_800DEE20(void) {
    if (gInCourseEditTestRun || (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        if ((D_800D6CA0.unk_00 == 1) || (gCourseEditHighlightedIconIndex != 0)) {
            return;
        }
        if ((D_802CB6D0.controlPointCount < 4) || (D_800D6CA0.unk_20 != -1) || (func_xk2_800DEDA8() != 0)) {
            Audio_TriggerSystemSE(NA_SE_32);
            return;
        }
        Audio_TriggerSystemSE(NA_SE_36);
        gInCourseEditTestRun = true;
        func_xk2_800F1360();
        D_xk2_80103FF0 = 0;
        D_xk2_80103FF4 = 0;
        D_xk2_80103FF8 = 0;
        D_xk2_800F7040 = 0;
        Audio_TestRunStart();
        func_xk2_800EF78C();
        D_800CCFBC = 1;
        func_80074594();
        func_80074428(gCourseIndex);
        Course_Init();
        gRacers[0].character = 0;
        gRacers[0].machineSkinIndex = 0;
        gRacers[0].unk_1A8 = 0.5f;
        Racer_Init();
        Camera_Init();
        func_8007F4E0(COURSE_CONTEXT()->courseData.venue, COURSE_CONTEXT()->courseData.skybox);
        Background_Init();
        Effects_Init();
        Course_FeaturesInit(0);
        Course_EffectsInit(0);
        Course_LandminesViewInteractDataInit();
        Course_JumpsViewInteractDataInit();
        Course_DecorationsViewInteractDataInit();
        Course_EffectsViewInteractDataInit(false);
        Minimap_InitCourseMinimap();
    }
}

s32 func_xk2_800DEFCC(void) {
    s32 i;
    s32 var_a3;

    var_a3 = D_800D6CA0.unk_0C;
    if (D_802CB6D0.controlPointCount < 4) {
        Audio_TriggerSystemSE(NA_SE_32);
        return -1;
    }

    func_xk2_800EE664(0xB);
    func_xk2_800EF78C();

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_8010C770.bankAngle[i] = COURSE_CONTEXT()->courseData.bankAngle[var_a3];
        D_8010C770.pit[i] = COURSE_CONTEXT()->courseData.pit[var_a3];
        D_8010C770.dash[i] = COURSE_CONTEXT()->courseData.dash[var_a3];
        D_8010C770.dirt[i] = COURSE_CONTEXT()->courseData.dirt[var_a3];
        D_8010C770.ice[i] = COURSE_CONTEXT()->courseData.ice[var_a3];
        D_8010C770.jump[i] = COURSE_CONTEXT()->courseData.jump[var_a3];
        D_8010C770.landmine[i] = COURSE_CONTEXT()->courseData.landmine[var_a3];
        D_8010C770.gate[i] = COURSE_CONTEXT()->courseData.gate[var_a3];
        D_8010C770.building[i] = COURSE_CONTEXT()->courseData.building[var_a3];
        D_8010C770.sign[i] = COURSE_CONTEXT()->courseData.sign[var_a3];

        D_xk2_80119920[i] = D_802CB6D0.unk_0000[var_a3];

        if (!(D_xk2_80119920[i].trackSegmentInfo & TRACK_TYPE_MASK) &&
            !(D_xk2_80119920[i].trackSegmentInfo & TRACK_SHAPE_MASK)) {
            D_xk2_80119920[i].trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2);
        }
        var_a3 = (var_a3 + 1) % D_802CB6D0.controlPointCount;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_802CB6D0.unk_0000[i] = D_xk2_80119920[i];

        COURSE_CONTEXT()->courseData.bankAngle[i] = D_8010C770.bankAngle[i];
        COURSE_CONTEXT()->courseData.pit[i] = D_8010C770.pit[i];
        COURSE_CONTEXT()->courseData.dash[i] = D_8010C770.dash[i];
        COURSE_CONTEXT()->courseData.dirt[i] = D_8010C770.dirt[i];
        COURSE_CONTEXT()->courseData.ice[i] = D_8010C770.ice[i];
        COURSE_CONTEXT()->courseData.jump[i] = D_8010C770.jump[i];
        COURSE_CONTEXT()->courseData.landmine[i] = D_8010C770.landmine[i];
        COURSE_CONTEXT()->courseData.gate[i] = D_8010C770.gate[i];
        COURSE_CONTEXT()->courseData.building[i] = D_8010C770.building[i];
        COURSE_CONTEXT()->courseData.sign[i] = D_8010C770.sign[i];
    }

    D_802CB6D0.unk_0000[0].trackSegmentInfo =
        (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_START_LINE);
    D_800D6CA0.unk_0C = 0;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_xk2_801197EC = &D_802CB6D0.unk_0000[i];
        D_xk2_801197EC->segmentIndex = i;
        D_xk2_801197EC->next = D_xk2_801197EC + 1;
        D_xk2_801197EC->prev = D_xk2_801197EC - 1;
    }
    D_802CB6D0.unk_0000[0].prev = &D_802CB6D0.unk_0000[D_802CB6D0.controlPointCount - 1];
    D_802CB6D0.unk_0000[D_802CB6D0.controlPointCount - 1].next = &D_802CB6D0.unk_0000[0];
    return 0;
}

void func_xk2_800DF2EC(void) {
    if ((gCourseEditCursorYPos < 0x34) && (gCourseEditCursorYPos >= 0x24) && (gCourseEditCursorXPos >= 0x108) &&
        (D_80119720->buttonPressed & BTN_A) && (D_800D6CA0.unk_08 != 4)) {
        Audio_TriggerSystemSE(NA_SE_36);
        D_800D6CA0.unk_08 = 4;
    }
}

void func_xk2_800DF370(void) {

    if (D_80119720->buttonPressed & BTN_A) {
        if (D_xk1_80032C20 != 0) {
            Audio_TriggerSystemSE(NA_SE_5);
            D_800D6CA0.unk_08 = 0;
            func_xk1_8002860C();
            return;
        }
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gPointOption = POINT_OPTION_SET;
        gCourseEditEntryOption = -1;
        return;
    }
    if (D_80119720->buttonPressed & BTN_B) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gPointOption = POINT_OPTION_SET;
        gCourseEditEntryOption = -1;
        return;
    }
    func_xk1_8002D2F0();
}

extern char gEditCupTrackNames[][9];
extern s32 D_xk2_80103F10;

void func_xk2_800DF42C(void) {
    s32 i;

    if (D_80119720->buttonPressed & BTN_A) {
        if (D_xk1_80032C20 != 0) {
            switch (D_80119890) {
                case 1:
                    gEditCupTrackNames[D_xk2_80103F10][0] = '\0';
                    break;
                case 2:
                    for (i = 0; i < 6; i++) {
                        gEditCupTrackNames[i][0] = '\0';
                    }
                    break;
            }
            func_xk2_800EC1D8();
            D_800D6CA0.unk_08 = 0x24;
            return;
        }
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gCourseEditEntryOption = -1;
        return;
    }
    if (D_80119720->buttonPressed & BTN_B) {
        Audio_TriggerSystemSE(NA_SE_37);
        D_800D6CA0.unk_08 = 0;
        gCourseEditEntryOption = -1;
        return;
    }
    func_xk1_8002D2F0();
}

void func_xk2_800DF54C(void) {

    if (!(D_80119720->buttonPressed & BTN_A) && (D_80119720->buttonPressed & BTN_B) && !gInCourseEditTestRun) {
        if ((D_800D6CA0.unk_08 != 1) && (D_800D6CA0.unk_08 != 0x11)) {
            func_xk2_800EF8B0();
        }
    }
}
