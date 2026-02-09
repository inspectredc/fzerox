#include "global.h"
#include "course_select.h"
#include "fzx_game.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include ASSET_HEADER(setup_gfx.h)

s32 D_801197B0[8];
Vtx* D_i5_801197D0;

s32 gCourseModelCupType = 0;
s32 D_i5_801190B4 = 0;
s32 gCourseModelCupCourseNo = 0;

extern s8 D_i5_8007B9EC[];
extern s32 D_8076CB44;
extern u8 D_80794E14;

void func_i5_80115DF0(void) {
#ifdef EXPANSION_KIT
    D_i5_801197D0 = Arena_Allocate(ALLOC_FRONT, 0x3600 * sizeof(Vtx));
#endif
    func_i5_801161D8();
}

void func_i5_80115E10(void) {
#ifndef EXPANSION_KIT
    if (D_i5_801190B4 > 0) {
        if (D_i5_801190B4 < 7) {
            func_i5_80116678(gCourseModelCupType);
        }
        D_i5_801190B4--;
    }
#else
    static s32 D_i5_8007B07C = 0;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;
    s32 i;
    bool var_a3;

    if ((D_i5_801190B4 > 0) && (D_i5_801190B4 < 7) && (D_i5_8007B07C == 0)) {
        if (gCourseModelCupType >= 4) {
            D_8076CB44 = 1;
        } else {
            D_8076CB44 = 0;
        }
        D_i5_8007B07C = 1;
        func_80704050(true);
        func_80702448(gCourseModelCupType * 6 + gCourseModelCupCourseNo);
        func_80704050(false);
    }

    if ((D_8076CB44 == 0) && (D_i5_8007B07C == 1)) {
        D_i5_8007B07C = 0;
        func_80074428(gCourseModelCupType * 6 + gCourseModelCupCourseNo);
        func_80074634(&gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo]);
        Course_SegmentLengthsInit(&gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo]);
        D_801197B0[gCourseModelCupCourseNo] =
            func_800A2D2C(&gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo],
                          &D_i5_801197D0[gCourseModelCupCourseNo * 0x900]);
        gCourseModelCupCourseNo++;
        D_i5_801190B4--;
    }
    if ((D_8076CB44 == 1) && (D_i5_8007B07C == 1)) {
        var_a3 = false;
        if (D_80794E14 == 0) {
            for (i = 0; i < 3; i++) {
                if ((ghostSave[i].record.encodedCourseIndex !=
                     gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo].encodedCourseIndex)) {
                    continue;
                }

                if (ghostSave[i].record.encodedCourseIndex == 0) {
                    continue;
                }
                if (1) {}

                var_a3 = true;
            }
            if (var_a3) {
                D_i5_8007B9EC[gCourseModelCupType * 6 + gCourseModelCupCourseNo] |= 1;
            }
            D_i5_8007B07C = 0;
            func_80074428(gCourseModelCupType * 6 + gCourseModelCupCourseNo);
            func_80074634(&gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo]);
            Course_SegmentLengthsInit(&gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo]);
            D_801197B0[gCourseModelCupCourseNo] =
                func_800A2D2C(&gCourseInfos[gCourseModelCupType * 6 + gCourseModelCupCourseNo],
                              &D_i5_801197D0[gCourseModelCupCourseNo * 0x900]);
            gCourseModelCupCourseNo++;
            D_i5_801190B4--;
        }
    }
    if (D_i5_801190B4 >= 7) {
        D_i5_801190B4--;
    }
#endif
    Camera_Update();
}

extern GfxPool D_1000000;

extern GfxPool* gGfxPool;
extern s32 D_800DCCFC;
extern Camera gCameras[];
extern s32 gSelectedMode;
extern s32 gCupType;
extern char gEditCupTrackNames[][9];

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
    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
    gSPMatrix(gfx++, D_1000000.unk_20008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_1000000.unk_20108, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

#ifndef EXPANSION_KIT
    guScale(gGfxPool->unk_20308, 0.25f, 0.25f, 0.25f);
#else
    Matrix_SetLockedLookAt(gGfxPool->unk_20308, NULL, 0.25f, 0.25f, 0.25f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                           0.0f, 0.0f);
#endif
    gSPMatrix(gfx++, K0_TO_PHYS(gGfxPool->unk_20308), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (D_i5_801190B4 < 6) {
        for (i = 0; i < gCourseModelCupCourseNo; i++) {
#ifdef EXPANSION_KIT
            if ((gCupType == EDIT_CUP) && (gSelectedMode == MODE_TIME_ATTACK) && (gEditCupTrackNames[i][0] == '\0')) {
                continue;
            }
#endif
            gSPViewport(gfx++, &D_i5_80118FF0[D_800DCCFC][i]);
#ifndef EXPANSION_KIT
            gfx = Course_DrawModel(gfx, &D_i5_801197D0[i * 0xC00], D_801197B0[i]);
#else
            gfx = Course_DrawModel(gfx, &D_i5_801197D0[i * 0x900], D_801197B0[i]);
#endif
        }
    }
    return gfx;
}

void func_i5_801161D8(void) {
    s32 i;

#ifndef EXPANSION_KIT
    D_i5_801197D0 = (Vtx*) Arena_Allocate(ALLOC_FRONT, 0x4800 * sizeof(Vtx));
#endif

    for (i = 0; i < 6; i++) {
        D_i5_80118FF0[0][i].vp.vscale[0] = (SCREEN_WIDTH / 4) << 2;
        D_i5_80118FF0[0][i].vp.vscale[1] = (SCREEN_HEIGHT / 4) << 2;
        D_i5_80118FF0[0][i].vp.vscale[2] = 0x1FF;
        D_i5_80118FF0[0][i].vp.vscale[3] = 0;
        D_i5_80118FF0[0][i].vp.vtrans[0] = 640 + i * 0x500;
        D_i5_80118FF0[0][i].vp.vtrans[1] = 600;
        D_i5_80118FF0[0][i].vp.vtrans[2] = 0x1FF;
        D_i5_80118FF0[0][i].vp.vtrans[3] = 0;
        D_i5_80118FF0[1][i].vp.vscale[0] = (SCREEN_WIDTH / 4) << 2;
        D_i5_80118FF0[1][i].vp.vscale[1] = (SCREEN_HEIGHT / 4) << 2;
        D_i5_80118FF0[1][i].vp.vscale[2] = 0x1FF;
        D_i5_80118FF0[1][i].vp.vscale[3] = 0;
        D_i5_80118FF0[1][i].vp.vtrans[0] = 640 + i * 0x500;
        D_i5_80118FF0[1][i].vp.vtrans[1] = 600;
        D_i5_80118FF0[1][i].vp.vtrans[2] = 0x1FF;
        D_i5_80118FF0[1][i].vp.vtrans[3] = 0;
    }
}

void func_i5_801164A8(s32 left) {
    s32 i;

    for (i = 0; i < 6; i++) {
        Vp* vp = &D_i5_80118FF0[D_800DCCFC][i];

        vp->vp.vscale[0] = (SCREEN_WIDTH / 4) << 2;
        vp->vp.vscale[1] = (SCREEN_HEIGHT / 4) << 2;
        vp->vp.vscale[2] = 0x1FF;
        vp->vp.vscale[3] = 0;
        vp->vp.vtrans[0] = 640 + (left + i * 0x500);
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

#ifndef EXPANSION_KIT
void func_i5_80116678(s32 cupType) {

    if (cupType == X_CUP) {
        Course_Load(cupType * 6 + gCourseModelCupCourseNo);
        func_80074634(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        Course_SegmentLengthsInit(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        D_801197B0[gCourseModelCupCourseNo] = func_800A2D2C(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo],
                                                            &D_i5_801197D0[gCourseModelCupCourseNo * 0xC00]);
        gCourseModelCupCourseNo++;
    } else {
        Course_Load(cupType * 6 + gCourseModelCupCourseNo);
        func_80074634(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        Course_SegmentLengthsInit(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo]);
        D_801197B0[gCourseModelCupCourseNo] = func_800A2D2C(&gCourseInfos[cupType * 6 + gCourseModelCupCourseNo],
                                                            &D_i5_801197D0[gCourseModelCupCourseNo * 0xC00]);
        gCourseModelCupCourseNo++;
    }
}
#endif
