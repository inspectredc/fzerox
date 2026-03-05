#include "global.h"
#include "ead_demo.h"
#include ASSET_HEADER(setup_gfx.h)
#include ASSET_HEADER(course_track_gfx.h)
#include "src/overlays/ovl_i2/transition.h"

Lights1 D_xk4_800F1A90 = gdSPDefLights1(50, 50, 30, 255, 200, 160, 0, 84, 84);

Vp sEADDemoVp = {
    640, 480, 511, 0, 640, 480, 511, 0,
};

extern s32 D_800CCFBC;
extern s16 D_800CCFE8;

void EADDemo_Init(void) {
    Audio_DDBgmReady(BGM_EAD_DEMO);
    Audio_DDBgmStart(BGM_EAD_DEMO);
    EADDemo_SinTableInit();
    D_800CCFBC = 2;
    D_800CCFE8 = 3;
}

extern s32 gTransitionState;

extern GfxPool D_8024E260[];
extern s32 D_800DCCFC;
extern s32 gGameMode;
extern s32 gPostEadDemoGameMode;
extern u16 gInputButtonPressed;
extern GfxPool* gGfxPool;

s32 EADDemo_Update(void) {
    gGfxPool = &D_8024E260[D_800DCCFC];
    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }
    Controller_SetGlobalInputs(&gSharedController);
    if (gInputButtonPressed & BTN_START) {
        Audio_DDBgmStop();
        D_800CCFBC = 1;
        return gPostEadDemoGameMode;
    }

    return gGameMode;
}

extern Gfx D_8076CAF8[];
extern u8 aEADDemoSugoiTex[];
extern GfxPool D_1000000;
extern FrameBuffer* gFrameBuffers[];
extern s32 D_800DCD04;

Gfx* EADDemo_Draw(Gfx* gfx) {
    static s32 D_xk4_800F1AB8 = 4800;
    static s32 D_xk4_800F1ABC = -550;
    static s32 D_xk4_800F1AC0 = 0;
    s32 angle;
    s32 i;
    u16 spFE;
    s32 pad[2];

    gSPDisplayList(gfx++, D_3000338);
    gSPDisplayList(gfx++, D_8076CAF8);
    gfx = EADDemo_DrawBackground(gfx, gFrameBuffers[D_800DCD04], 0, 0, 0x60, 0, 0, 0);
    gSPDisplayList(gfx++, D_8014940);

    for (i = 0; i < 64; i++) {
        gDPLoadTextureBlock(gfx++, aEADDemoSugoiTex + i * SCREEN_WIDTH, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 1, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, 24 << 2, (i + 32) << 2, 184 << 2, ((i + 1) + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    if (SQ(gControllers[gPlayerControlPorts[0]].stickX) > 100) {
        D_xk4_800F1AC0 += gControllers[gPlayerControlPorts[0]].stickX / 10;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z) {
        D_xk4_800F1AC0 = 0;
    }
    angle = (s32) (D_xk4_800F1AC0 * 0x1000) / 360;
    Matrix_SetLockedLookAt(gGfxPool->unk_2C5E8, NULL, 1.0f, 1.0f, 1.0f, SIN(angle), 0.0f, COS(angle), 0.0f, 1.0f, 0.0f,
                           0.0f, 0.0f, 0.0f);

    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L) {
        D_xk4_800F1AB8 += 50;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R) {
        D_xk4_800F1AB8 -= 50;
    }
    if (D_xk4_800F1AB8 < 1600) {
        D_xk4_800F1AB8 = 1600;
    }
    if (D_xk4_800F1AB8 > 4800) {
        D_xk4_800F1AB8 = 4800;
    }

    D_xk4_800F1ABC = ((4800 - D_xk4_800F1AB8) / 3) - 550;

    gSPViewport(gfx++, &sEADDemoVp);

    Matrix_SetFrustrum(gGfxPool->unk_20008, NULL, 60.0f, 64.0f, 8192.0f, 320.0f, -80.0f, 240.0f, 0.0f, &spFE);

    gSPPerspNormalize(gfx++, spFE);

    gSPMatrix(gfx++, D_1000000.unk_20008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    Matrix_SetLookAt(gGfxPool->unk_20108, NULL, 500.0f, D_xk4_800F1ABC, D_xk4_800F1AB8, 500.0f, D_xk4_800F1ABC, 0, 0, 1,
                     0);

    gSPMatrix(gfx++, D_1000000.unk_20108, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    gSPMatrix(gfx++, gGfxPool->unk_2C5E8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_3000400);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gSPNumLights(gfx++, NUMLIGHTS_1);
    gSPSetLights1(gfx++, D_xk4_800F1A90);

    gSPClipRatio(gfx++, FRUSTRATIO_4);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);

    EADDemo_DrawEADSkeleton(&gfx);
    return gfx;
}
