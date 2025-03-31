#include "global.h"
#include "course_select.h"
#include "fzx_game.h"
#include "assets/segment_17B1E0.h"

void func_i5_80115DF0(void) {
    func_i5_801161D8();
}

void func_i5_80115E10(void) {

    if (D_i5_801190B4 > 0) {
        if (D_i5_801190B4 < 7) {
            func_i5_80116678(gCourseModelCupType);
        }
        D_i5_801190B4--;
    }
    func_8008675C();
}

extern GfxPool D_1000000;

extern GfxPool* gGfxPool;
extern s32 D_800DCCFC;
extern Player gPlayers[];

s32 D_801197B0[8];
Vtx* D_i5_801197D0;

// Track 3D Models
Gfx* func_i5_80115E64(Gfx* gfx) {
    s32 i;

    gSPDisplayList(gfx++, D_3000338);
    gDPPipeSync(gfx++);
    gSPSetGeometryMode(gfx++, G_CLIPPING);
    gSPClipRatio(gfx++, FRUSTRATIO_6);

    switch (gCupSelectOption) {
        case 0:
            gDPSetPrimColor(gfx++, 0, 0, 192, 64, 64, 255);
            break;
        case 1:
            gDPSetPrimColor(gfx++, 0, 0, 100, 150, 255, 255);
            break;
        case 2:
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 100, 255);
            break;
        case 3:
            gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            break;
        default:
            gDPSetPrimColor(gfx++, 0, 0, 200, 90, 255, 255);
            break;
    }

    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
    gSPMatrix(gfx++, D_1000000.unk_20008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_1000000.unk_20108, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    guScale(gGfxPool->unk_20308, 0.25f, 0.25f, 0.25f);
    gSPMatrix(gfx++, K0_TO_PHYS(gGfxPool->unk_20308), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (D_i5_801190B4 < 6) {
        for (i = 0; i < gCourseModelCupCourseNo; i++) {
            gSPViewport(gfx++, &D_i5_80118FF0[D_800DCCFC][i]);
            gfx = func_800A92FC(gfx, &D_i5_801197D0[i * 0xC00], D_801197B0[i]);
        }
    }
    return gfx;
}

void func_i5_801161D8(void) {
    s32 i;

    D_i5_801197D0 = (Vtx*) func_800768F4(0, 0x4800 * sizeof(Vtx));

    for (i = 0; i < 6; i++) {
        D_i5_80118FF0[0][i].vp.vscale[0] = SCREEN_WIDTH;
        D_i5_80118FF0[0][i].vp.vscale[1] = SCREEN_HEIGHT;
        D_i5_80118FF0[0][i].vp.vscale[2] = 0x1FF;
        D_i5_80118FF0[0][i].vp.vscale[3] = 0;
        D_i5_80118FF0[0][i].vp.vtrans[0] = 640 + i * 0x500;
        D_i5_80118FF0[0][i].vp.vtrans[1] = 600;
        D_i5_80118FF0[0][i].vp.vtrans[2] = 0x1FF;
        D_i5_80118FF0[0][i].vp.vtrans[3] = 0;
        D_i5_80118FF0[1][i].vp.vscale[0] = SCREEN_WIDTH;
        D_i5_80118FF0[1][i].vp.vscale[1] = SCREEN_HEIGHT;
        D_i5_80118FF0[1][i].vp.vscale[2] = 0x1FF;
        D_i5_80118FF0[1][i].vp.vscale[3] = 0;
        D_i5_80118FF0[1][i].vp.vtrans[0] = 640 + i * 0x500;
        D_i5_80118FF0[1][i].vp.vtrans[1] = 600;
        D_i5_80118FF0[1][i].vp.vtrans[2] = 0x1FF;
        D_i5_80118FF0[1][i].vp.vtrans[3] = 0;
    }
}

void func_i5_801164A8(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        Vp* vp = &D_i5_80118FF0[D_800DCCFC][i];

        vp->vp.vscale[0] = SCREEN_WIDTH;
        vp->vp.vscale[1] = SCREEN_HEIGHT;
        vp->vp.vscale[2] = 0x1FF;
        vp->vp.vscale[3] = 0;
        vp->vp.vtrans[0] = 640 + (arg0 + i * 0x500);
        vp->vp.vtrans[1] = 600;
        vp->vp.vtrans[2] = 0x1FF;
        vp->vp.vtrans[3] = 0;
    }
}

void CourseModel_Init(s32 cupType) {
    gCourseModelCupType = cupType;
    D_i5_801190B4 = 8;
    gCourseModelCupCourseNo = 0;
}

void func_i5_80116678(s32 cupType) {

    if (cupType == X_CUP) {
        func_8007402C(cupType * 6 + gCourseModelCupCourseNo);
        func_80074634(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        func_8009F508(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        D_801197B0[gCourseModelCupCourseNo] = func_800A2D2C(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo],
                                                            &D_i5_801197D0[gCourseModelCupCourseNo * 0xC00]);
        gCourseModelCupCourseNo++;
    } else {
        func_8007402C(cupType * 6 + gCourseModelCupCourseNo);
        func_80074634(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        func_8009F508(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        D_801197B0[gCourseModelCupCourseNo] = func_800A2D2C(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo],
                                                            &D_i5_801197D0[gCourseModelCupCourseNo * 0xC00]);
        gCourseModelCupCourseNo++;
    }
}
