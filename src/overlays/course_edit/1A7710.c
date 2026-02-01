#include "global.h"
#include "fzx_camera.h"
#include ASSET_HEADER_EK(course_edit_textures.h)

Vec3f D_xk2_8013A740;
UNUSED s32 D_xk2_8013A750[2];
Mtx D_xk2_8013A758;
Mtx D_xk2_8013A798;

s32 D_xk2_80119680 = 0;
s32 D_xk2_80119684 = -1;

void func_xk2_800F5C50(void) {
    D_xk2_80119680 = 0;
}

void func_xk2_800F5C5C(void) {
    Matrix_SetOrtho(&D_xk2_8013A758, NULL, 1.0f, -160.0f, 160.0f, -120.0f, 120.0f, 16.0f, 256.0f);
    Matrix_SetLookAt(&D_xk2_8013A798, NULL, 0.0f, 0.0f, 128.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

s32 func_xk2_800F5D10(void) {
    return D_xk2_80119680;
}

extern GfxPool* gGfxPool;

void func_xk2_800F5D1C(void) {
    static s32 D_xk2_80119688 = 0;
    s32 spB4;
    Vtx* vtx;
    MtxF sp70;
    s32 pad[8];
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv1;
    f32 temp_ft2;
    f32 temp_ft2_2;
    f32 sp38;

    D_xk2_80119688 = (D_xk2_80119688 + 8) % 360;
    spB4 = (D_xk2_80119688 * 0x1000) / 360;

    Matrix_SetAxisRotation(NULL, &sp70, 1.0f, spB4, gCameras[0].basis.x.x, gCameras[0].basis.x.y, gCameras[0].basis.x.z,
                           0.0f, 0.0f, 0.0f);

    vtx = gGfxPool->unk_365E8;
    temp_fv1 = COS(spB4) * 24.0f;
    temp_ft4 = SIN(spB4) * -24.0f;
    temp_ft5 = SIN(spB4) * 24.0f;
    sp38 = COS(spB4) * 24.0f;
    temp_ft2 = 0.0f;
    temp_ft2_2 = 0.0f;

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

extern s32 D_8076C968;
extern s32 D_xk2_80104CB4;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CBC;
extern s32 D_xk2_80104CC0;
extern unk_807B3C20 D_802CB6D0;
extern unk_800D6CA0 D_800D6CA0;
extern s32 gCourseEditCursorXPos;
extern s32 gCourseEditCursorYPos;
extern s32 D_xk2_800F7040;

void func_xk2_800F5F2C(void) {
    static s32 D_xk2_8011968C = 0;
    static s32 D_xk2_80119690 = 0;

    if (D_xk2_80119680 != 0) {
        func_xk2_800F5D1C();
    }
    if (D_xk2_8011968C != 0) {
        D_xk2_8011968C--;
    }

    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
        D_xk2_80119680 = 0;
    }
    if (D_800D6CA0.unk_00 == 1) {
        D_xk2_80119680 = 0;
    }
    if ((D_xk2_80119690 == 0) || (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z)) {
        D_xk2_80119690 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z;
        return;
    }
    if (gCourseEditCursorYPos < 0x38) {
        D_xk2_80119690 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z;
        return;
    }
    if (D_xk2_8011968C != 0) {
        D_xk2_80119684 = func_xk2_800EFDE4(4000.0f);
        if (D_xk2_80119684 == -1) {
            return;
        }
        D_xk2_80119680 = 1;
        gCourseEditCursorXPos = 160;
        gCourseEditCursorYPos = 120;
        if (D_8076C968 != 0) {
            func_xk2_800DE4F8();
        }
        D_xk2_800F7040 = 3;
        if (D_800D6CA0.unk_00 == 1) {
            D_800D6CA0.unk_00 = 0;
        }
        func_xk2_800DC3F8();
        D_xk2_8013A740 = D_802CB6D0.unk_0000[D_xk2_80119684].pos;
        D_xk2_80104CB8 = D_802CB6D0.unk_0000[D_xk2_80119684].pos.x * 0.3f;
        D_xk2_80104CBC = D_802CB6D0.unk_0000[D_xk2_80119684].pos.y * 0.3f;
        D_xk2_80104CC0 = D_802CB6D0.unk_0000[D_xk2_80119684].pos.z * 0.3f;
        gCameras[0].eye.x = D_xk2_80104CB8;
        gCameras[0].eye.y = D_xk2_80104CBC + D_xk2_80104CB4;
        gCameras[0].eye.z = D_xk2_80104CC0;
    } else {
        D_xk2_8011968C = 8;
    }
    D_xk2_80119690 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z;
}

extern GfxPool D_1000000;

void func_xk2_800F61DC(Gfx** gfxP) {
    Gfx* gfx;

    if ((D_xk2_80119680 == 0) || (D_800D6CA0.unk_08 != 0)) {
        return;
    }
    gfx = *gfxP;

    gSPMatrix(gfx++, &D_xk2_8013A758, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_xk2_8013A798, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_9014D18);
    gSPVertex(gfx++, D_1000000.unk_365E8, 4, 0);
    gSP2Triangles(gfx++, 0, 3, 1, 0, 1, 3, 2, 0);
    *gfxP = gfx;
}
