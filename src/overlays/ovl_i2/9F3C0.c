#include "global.h"
#include "assets/segment_17B960.h"

extern s8 D_800DCE5C;

void func_i2_80103A70(void) {
    func_i3_8012F324();
    func_80069700();
    func_8008C7C8();
    func_80085610();
    func_i2_801044F0();
    func_8006D414();
    D_800DCE5C = 0;
    func_i3_8011B520();
    func_i3_80134598();
    func_i3_80134548();
}

extern s16 D_800CCFE8;

s32 D_i2_80106F10 = 0;
UNUSED s8 D_i2_80106F14[] = { 0, 1, 2, 5, 4, 3, 7, 6, 5, 0, 4, 8, 2, 1, 7, 6, 8,
                              0, 7, 5, 6, 2, 3, 8, 0, 3, 4, 2, 5, 8, 7, 6, 2, 1 };

extern unk_8010B7B0 D_8010B7B0;

void func_i2_80103AD4(void) {
    D_800CCFE8 = D_i2_80106F10 = 3;
    D_800DCE5C = 0;
    func_800A4EAC();
    func_i3_80116C4C();
    func_8008C7C8();
    func_80085610();
    func_8007F4E0(D_8010B7B0.unk_000[2], D_8010B7B0.unk_000[3]);
    func_i3_801365E0();
    func_i2_801044F0();
    func_8006D448();
    func_8006E478();
    func_8006EC7C();
    func_80071260(0);
    func_i3_8012F324();
    func_i3_801356A0();
    func_i3_8011B520();
    func_i3_80134548();
}

extern s32 D_800DCE44;

s32 func_i2_80103B8C(void) {
    func_i3_8011AEA0();
    func_i2_8010466C();
    func_800952F4();
    func_8008675C();
    func_i3_80136A6C();
    func_800A5028();
    func_80074844();

    return D_800DCE44;
}

extern s32 D_800DCCFC;
extern s32 D_800DCD04;
extern Vtx* D_800E5ECC;
extern Vtx* D_800E5ED0;
extern Vtx* D_800F8520;
extern GfxPool D_1000000;
extern GfxPool* D_800DCCF0;
extern unk_struct_1DC D_800E5220[];
extern FrameBuffer* D_800DCCD0[];
extern s16 D_800CCFE4;
extern s32 gNumPlayers;

Gfx* func_i2_80103BE0(Gfx* gfx) {

    if (D_i2_80106F10 != 0) {
        D_i2_80106F10--;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPPipelineMode(gfx++, G_PM_NPRIMITIVE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

        if (D_800CCFE4 == 2) {
            gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                             OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCCFC]));
        } else {
            gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                             OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
        }

        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }
    if (gNumPlayers == 1) {
        gSPDisplayList(gfx++, D_303A8F8);
    } else {
        gSPDisplayList(gfx++, D_303A810);
    }

    gDPPipeSync(gfx++);

    if (D_800CCFE4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCCFC]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
    }
    D_800F8520 = D_800DCCF0->unk_10008;
    D_800E5ECC = D_800DCCF0->unk_21B48;
    D_800E5ED0 = &D_800DCCF0->unk_21B48[0x7FF];
    switch (gNumPlayers) { /* irregular */
        case 1:
            gfx = func_i3_801381DC(gfx, 0, 0);
            gfx = func_800A9938(gfx, 0);
            gfx = func_8006DAAC(gfx, 0);
            break;
        case 2:
            gfx = func_i3_801381DC(gfx, 0, 1);
            gfx = func_800A9938(gfx, 0);
            gfx = func_8006DAAC(gfx, 0);
            gfx = func_i3_801381DC(gfx, 1, 2);
            gfx = func_800A9938(gfx, 1);
            gfx = func_8006DAAC(gfx, 1);
            break;
        case 3:
            gfx = func_i3_801381DC(gfx, 0, 5);
            gfx = func_800A9938(gfx, 0);
            gfx = func_8006DAAC(gfx, 0);
            gfx = func_i3_801381DC(gfx, 1, 7);
            gfx = func_800A9938(gfx, 1);
            gfx = func_8006DAAC(gfx, 1);
            gfx = func_i3_801381DC(gfx, 2, 6);
            gfx = func_800A9938(gfx, 2);
            gfx = func_8006DAAC(gfx, 2);
            break;
        case 4:
            gfx = func_i3_801381DC(gfx, 0, 5);
            gfx = func_800A9938(gfx, 0);
            gfx = func_8006DAAC(gfx, 0);
            gfx = func_i3_801381DC(gfx, 1, 7);
            gfx = func_800A9938(gfx, 1);
            gfx = func_8006DAAC(gfx, 1);
            gfx = func_i3_801381DC(gfx, 2, 6);
            gfx = func_800A9938(gfx, 2);
            gfx = func_8006DAAC(gfx, 2);
            gfx = func_i3_801381DC(gfx, 3, 8);
            gfx = func_800A9938(gfx, 3);
            gfx = func_8006DAAC(gfx, 3);
            break;
    }

    gSPLoadUcodeL(gfx++, gspF3DFLX_Rej_fifo);
    gfx = func_80076C08(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gDPPipeSync(gfx++);

    if (D_800CCFE4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCCFC]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
    }

    switch (gNumPlayers) {
        case 1:
            gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 0, 0);
            gfx = func_80096CE8(gfx, 0);
            gfx = func_i3_8012CF34(gfx, 0);
            break;
        case 2:
            gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 1, 0);
            gfx = func_80096CE8(gfx, 0);
            gSPPerspNormalize(gfx++, D_800E5220[1].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 2, 1);
            gfx = func_80096CE8(gfx, 1);
            break;
        case 3:
            gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 5, 0);
            gfx = func_80096CE8(gfx, 0);
            gSPPerspNormalize(gfx++, D_800E5220[1].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 7, 1);
            gfx = func_80096CE8(gfx, 1);
            gSPPerspNormalize(gfx++, D_800E5220[2].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 6, 2);
            gfx = func_80096CE8(gfx, 2);
            break;
        case 4:
            gSPPerspNormalize(gfx++, D_800E5220[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 5, 0);
            gfx = func_80096CE8(gfx, 0);
            gSPPerspNormalize(gfx++, D_800E5220[1].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 7, 1);
            gfx = func_80096CE8(gfx, 1);
            gSPPerspNormalize(gfx++, D_800E5220[2].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 6, 2);
            gfx = func_80096CE8(gfx, 2);
            gSPPerspNormalize(gfx++, D_800E5220[3].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_20208[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_800833AC(gfx, 8, 3);
            gfx = func_80096CE8(gfx, 3);
            break;
    }

    return func_i3_8012D3D4(gfx);
}
