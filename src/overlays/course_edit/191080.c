#include "global.h"
#include "fzx_camera.h"
#include "fzx_course.h"
#include "fzx_expansion_kit.h"
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

extern MenuDropItem gRoadTypeMenuItems;
extern MenuDropItem gHRoadTypeMenuItems;
extern MenuDropItem gPipeTypeMenuItems;
extern MenuDropItem gCylinderTypeMenuItems;
extern MenuDropItem gHalfPipeTypeMenuItems;
extern MenuDropItem gTunnelTypeMenuItems;
extern MenuDropItem gTRoadTypeMenuItems;

s32 D_xk2_800F7030 = 0;
s32 D_xk2_800F7034 = 0;
s32 D_xk2_800F7038 = 16;
s32 D_xk2_800F703C = -1;
s32 D_xk2_800F7040 = 0;
s32 D_xk2_800F7044 = 0;
s32 D_xk2_800F7048 = 0;
s32 D_xk2_800F704C = -1;
s32 D_xk2_800F7050 = 0;
s32 D_xk2_800F7054 = 0;
s32 D_xk2_800F7058 = 0;
s32 gCourseEditHighlightedIconIndex = -1;
s32 D_xk2_800F7060 = 0;
s32 D_xk2_800F7064 = 0;
s32 D_xk2_800F7068 = -1;
s32 D_xk2_800F706C = -1;
s8 D_xk2_800F7070[][4] = {
    { 64, 64, 64, 1 },     // TRACK_SHAPE_ROAD
    { 192, 64, 64, 1 },    // TRACK_SHAPE_WALLED_ROAD
    { 100, 150, 255, 10 }, // TRACK_SHAPE_PIPE
    { 64, 192, 64, 10 },   // TRACK_SHAPE_CYLINDER
    { 255, 255, 100, 10 }, // TRACK_SHAPE_HALF_PIPE
    { 192, 64, 64, 10 },   // TRACK_SHAPE_TUNNEL
    { 64, 192, 64, 1 },    // TRACK_SHAPE_AIR
    { 100, 150, 255, 1 },  // TRACK_SHAPE_BORDERLESS_ROAD
};

u8 D_xk2_800F7090[][8] = {
    { 0x20, 0x8F, 0xB3, 0xDB, 0x00, 0x00, 0x00, 0x00 }, { 0x20, 0x48, 0x8F, 0xB3, 0xDB, 0x00, 0x00, 0x00 },
    { 0x20, 0x95, 0xB2, 0x97, 0x00, 0x00, 0x00, 0x00 }, { 0xBC, 0xD8, 0xDD, 0x8B, 0xB0, 0x00, 0x00, 0x00 },
    { 0xCA, 0xB0, 0xCC, 0x95, 0xB2, 0x97, 0x00, 0x00 }, { 0x20, 0xC4, 0xDD, 0xC8, 0xD9, 0x00, 0x00, 0x00 },
    { 0x20, 0xBD, 0x98, 0xB0, 0xBD, 0x00, 0x00, 0x00 }, { 0x20, 0x54, 0x8F, 0xB3, 0xDB, 0x00, 0x00, 0x00 },
};

u8 D_xk2_800F70D0[][3] = {
    140, 200, 255, // TRACK_SHAPE_ROAD
    80,  200, 140, // TRACK_SHAPE_WALLED_ROAD
    200, 180, 255, // TRACK_SHAPE_PIPE
    90,  180, 180, // TRACK_SHAPE_CYLINDER
    120, 255, 200, // TRACK_SHAPE_HALF_PIPE
    255, 255, 150, // TRACK_SHAPE_TUNNEL
    200, 200, 200, // TRACK_SHAPE_AIR
    255, 200, 255, // TRACK_SHAPE_BORDERLESS_ROAD
};

s32 D_xk2_800F70E8[] = {
    -1, // ROAD_START_LINE
    -1, // ROAD_1
    0,  // ROAD_2
    1,  // ROAD_3
    2,  // ROAD_4
    3,  // ROAD_5
    4,  // ROAD_6
    1,  // ROAD_7 ?
    2,  // ROAD_8 ?
    3,  // ROAD_9 ?
};

MenuDropItem* D_xk2_800F7110[] = {
    &gRoadTypeMenuItems,     // TRACK_SHAPE_ROAD
    &gHRoadTypeMenuItems,    // TRACK_SHAPE_WALLED_ROAD
    &gPipeTypeMenuItems,     // TRACK_SHAPE_PIPE
    &gCylinderTypeMenuItems, // TRACK_SHAPE_CYLINDER
    &gHalfPipeTypeMenuItems, // TRACK_SHAPE_HALF_PIPE
    &gTunnelTypeMenuItems,   // TRACK_SHAPE_TUNNEL
    NULL,                    // TRACK_SHAPE_AIR
    &gTRoadTypeMenuItems,    // TRACK_SHAPE_BORDERLESS_ROAD
};

extern unk_807B3C20 D_802CB6D0;

void func_xk2_800DF5C0(void) {
    s32 i;

    if (gControllers[1].buttonPressed & BTN_START) {
        for (i = 0; i < D_802CB6D0.controlPointCount; i++) {}
    }
}

extern bool gInCourseEditTestRun;
extern Mtx D_xk2_80119838;

Gfx* func_xk2_800DF5FC(Gfx* gfx) {

    switch (D_xk2_800F7030) {
        case 0:
            D_xk2_800F7030 = 1;
            Matrix_SetLockedLookAt(&D_xk2_80119838, NULL, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                                   0.0f, 0.0f);
            break;
        case 1:
            func_xk2_800DF5C0();
            func_xk1_800260E4();
            if (!gInCourseEditTestRun) {
                gSPMatrix(gfx++, K0_TO_PHYS(&D_xk2_80119838), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            }
            gfx = func_xk2_800DF6FC(gfx);
            break;
    }
    return gfx;
}

void func_xk2_800F3DAC(Gfx** gfxP);
void func_xk1_8002D340(Gfx** gfxP);
void func_xk2_800F5250(Gfx** gfxP);

extern Mtx D_2000000[];
extern Gfx D_30004A8[];
extern Gfx D_3000540[];
extern u8* D_xk1_800331F0[];
extern s32 D_80119880;
extern u16* gCourseEditIconTextures[];
extern Gfx D_3000510[];
extern u8 D_80794E14;
extern s32 D_8076C964;
extern unk_800D6CA0 D_800D6CA0;

extern s32 gCourseEditCursorXPos;
extern s32 gCourseEditCursorYPos;
extern s32 D_xk2_800F7404;
extern s32 D_xk2_80119918;

extern u8 D_xk2_80104CA0[];

Gfx* func_xk2_800DF6FC(Gfx* gfx) {

    gSPDisplayList(gfx++, D_30004A8);
    gSPDisplayList(gfx++, D_9014AA0);

    if (gInCourseEditTestRun) {
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(gfx++);
        gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gfx = Background_Draw(gfx, 0, SCISSOR_BOX_FULL_SCREEN);
        gfx = Course_Draw(gfx, 0);
        gfx = Course_GadgetsDraw(gfx, 0);
        gSPLoadUcodeL(gfx++, gspF3DFLX2_Rej_fifo);
        func_xk2_800E1FC0(&gfx);
        gfx = Racer_Draw(gfx, 0);
        gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_xk2_800E1FC0(&gfx);
        gfx = Minimap_DrawCourseMinimap(gfx, 0, 0);
        gfx = Hud_DrawPlayerSpeed(gfx, 0, 0);
        return Hud_DrawReverse(gfx, 0, 0);
    }
    if (func_xk2_800E6B3C()) {
        D_xk2_80104CA0[2] = 1;
        D_8076C964 = 0;
        gCourseEditIconTextures[1] = aCourseEditGoldLineModeIconTex;
        D_xk2_800F7044 = 0;
    }
    gfx = func_xk2_800E5870(gfx);
    gSPDisplayList(gfx++, D_9014B68);
    gSPDisplayList(gfx++, aExecuteCourseEditAxisDL);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((D_802CB6D0.controlPointCount >= 4) && (D_xk2_800F7044 == 1) && (D_800D6CA0.unk_20 == -1)) {
        gSPDisplayList(gfx++, D_9014BA0);
        if (D_xk2_800F7404 == 0) {
            gfx = func_i2_800BDAA4(gfx);
        }
    }
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((D_802CB6D0.controlPointCount >= 4) && (D_800D6CA0.unk_20 == -1) && (D_xk2_800F7404 == 0) &&
        (D_xk2_80104CA0[10] == 0)) {
        gfx = Course_GadgetsDraw(gfx, 0);
    }
    if (D_xk2_800F7404 != 0) {
        D_xk2_800F7404 = 0;
    } else {
        gfx = func_xk2_800E2104(gfx);
        gfx = func_xk2_800E04E0(gfx);
        gfx = func_xk2_800EA248(gfx);
        gfx = func_xk2_800EA4E4(gfx);
    }
    gfx = func_xk2_800E7518(gfx);
    func_xk2_800F61DC(&gfx);
    func_xk2_800E9234();
    gSPDisplayList(gfx++, D_9014BC0);
    func_xk2_800E93B0(&gfx);
    func_xk2_800E9504(&gfx);
    func_xk2_800E95E0(&gfx);
    func_xk2_800E96F4(&gfx);
    func_xk2_800E9808(&gfx);
    func_xk2_800E98D8(&gfx);
    CourseEdit_DrawIcons(&gfx);
    gfx = func_xk2_800E8F7C(gfx);
    gfx = func_xk2_800E54A4(gfx);
    gfx = func_xk2_800E5058(gfx);
    gfx = func_xk2_800E4984(gfx);
    gfx = func_xk2_800EDF90(gfx);
    func_xk2_800F2B48(&gfx);
    if (D_xk2_80119918 != 0) {
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 30, 70, 255);
        gSPTextureRectangle(gfx++, 0 << 2, 0 << 2, SCREEN_WIDTH << 2, 56 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    } else {
        gfx = func_xk2_800E8080(gfx);
    }
    gfx = func_xk2_800E5214(gfx);
    func_xk2_800F3164(&gfx);
    if (D_80794E14 == 0) {
        gfx = func_xk2_800EA3B0(gfx);
    }

    if ((D_800D6CA0.unk_08 == 0x11) || (D_800D6CA0.unk_08 == 0x23) || (D_800D6CA0.unk_08 == 0xFF)) {
        func_xk1_8002D340(&gfx);
    }
    if (D_800D6CA0.unk_08 == 0xFF) {
        func_xk2_800EECD4(&gfx, 0, 0x48, D_xk1_800331F0[30], 30);
    }
    if (D_xk2_80119918 == 0) {
        gfx = func_xk2_800E0320(gfx);
    }
    func_xk2_800EE8A0(&gfx);
    func_xk2_800EE67C(&gfx);
    if (D_xk2_80119918 == 0) {
        func_xk2_800F3548(&gfx);
        func_xk2_800F3600(&gfx);
    }
    func_xk2_800F3DAC(&gfx);
    if (D_800D6CA0.unk_08 == 4) {
        func_xk2_800F5250(&gfx);
    }
    if (D_800D6CA0.unk_08 == 2) {
        gfx = ExpansionKit_NameEntryDraw(gfx, &gCourseEditCursorXPos, &gCourseEditCursorYPos);
        if (D_80119880 == 9) {
            s32 x = 24;
            s32 y = 56;
            s32 width = 256;
            gSPDisplayList(gfx++, D_3000510);
            gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
            gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + width + 2) << 2, y << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
            gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 16) << 2, (x + width + 2) << 2, (y + 16 + 2) << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, x << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x + width) << 2, y << 2, (x + width + 2) << 2, (y + 16) << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
            gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPDisplayList(gfx++, D_3000540);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_xk1_800264C0(gfx, 0x18, 0x38, 0x10);
        }
    }
    func_xk2_800EA8E8(&gfx);
    func_xk2_800EA948(&gfx);
    return gfx;
}

extern unk_80128C94* D_80128C94;

void func_xk2_800DFFF8(void) {
    CourseSegment* var_s0;
    Vtx* vtx;
    s32 i;
    Vec3f sp68;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;

    if (D_802CB6D0.controlPointCount < 2) {
        return;
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_s0 = &D_802CB6D0.unk_0000[i];
        Course_SplineGetTangent(var_s0, 0.0f, &sp68);
        Math_NormalizeXYZ(&sp68.x, &sp68.y, &sp68.z);

        temp_fa1 = (var_s0->up.y * sp68.z) - (sp68.y * var_s0->up.z);
        temp_ft4 = (var_s0->up.z * sp68.x) - (sp68.z * var_s0->up.x);
        temp_ft5 = (var_s0->up.x * sp68.y) - (sp68.x * var_s0->up.y);
        vtx = &D_80128C94->unk_0180[i * 6];
        vtx->v.ob[0] = var_s0->pos.x;
        vtx->v.ob[1] = var_s0->pos.y;
        vtx->v.ob[2] = var_s0->pos.z;
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x;
        vtx->v.ob[1] = 0;
        vtx->v.ob[2] = var_s0->pos.z;
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x + (300.0f * sp68.x);
        vtx->v.ob[1] = var_s0->pos.y + (300.0f * sp68.y);
        vtx->v.ob[2] = var_s0->pos.z + (300.0f * sp68.z);
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x + (300.0f * var_s0->up.x);
        vtx->v.ob[1] = var_s0->pos.y + (300.0f * var_s0->up.y);
        vtx->v.ob[2] = var_s0->pos.z + (300.0f * var_s0->up.z);
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x + (var_s0->radiusLeft * temp_fa1);
        vtx->v.ob[1] = var_s0->pos.y + (var_s0->radiusLeft * temp_ft4);
        vtx->v.ob[2] = var_s0->pos.z + (var_s0->radiusLeft * temp_ft5);
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x - (var_s0->radiusRight * temp_fa1);
        vtx->v.ob[1] = var_s0->pos.y - (var_s0->radiusRight * temp_ft4);
        vtx->v.ob[2] = var_s0->pos.z - (var_s0->radiusRight * temp_ft5);
    }
}

extern Gfx D_8014940[];
extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;

Gfx* func_xk2_800E0320(Gfx* gfx) {
    s32 var_v0;
    s32 var_v1;

    if (D_800D6CA0.unk_00 == 1) {
        return gfx;
    }
    // clang-format off
    if (D_800D6CA0.unk_08 == 1) {
        var_v0 = D_xk1_8003A550; \
        var_v1 = D_xk1_8003A554;
    } else {
        var_v0 = gCourseEditCursorXPos; \
        var_v1 = gCourseEditCursorYPos;
    }
    // clang-format on
    if (D_800D6CA0.unk_08 == 0x20) {
        return gfx;
    }
    if (D_800D6CA0.unk_08 == 4) {
        return gfx;
    }
    if (D_800D6CA0.unk_08 == 3) {
        return gfx;
    }

    if (D_800D6CA0.unk_08 == 0x10) {
        return gfx;
    }
    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, aCourseEditCursorTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, var_v0 << 2, var_v1 << 2, (var_v0 + 16) << 2, (var_v1 + 16) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

extern u32 gGameFrameCount;
extern s32 D_800DCCFC;
extern unk_80128690 D_80128690[];

Gfx* func_xk2_800E04E0(Gfx* gfx) {
    s32 i;
    s32 spC0;
    s32 spBC;
    s32 spB8;
    f32 var_fs1;
    Vec3f spA8;
    s32 var_a0;

    if (gInCourseEditTestRun) {
        return gfx;
    }
    spC0 = func_xk2_800EFDE4(150.0f);
    gSPDisplayList(gfx++, D_9014C60);

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        gDPPipeSync(gfx++);
        if (D_80128690[i].unk_08 != 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == D_800D6CA0.unk_1C) && (D_800DCCFC != 0)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == D_800D6CA0.unk_20) && (D_800DCCFC != 0)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == spC0) && (D_800D6CA0.unk_00 != 1)) {
            if (D_800DCCFC != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        } else if (i == 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 255, 128);
        } else {
            var_a0 = Math_Round(D_802CB6D0.unk_0000[i].pos.y);
            if (var_a0 < 0) {
                var_a0 = 0;
            }
            var_a0 = (var_a0 * 255) / 5000;
            gDPSetPrimColor(gfx++, 0, 0, var_a0, var_a0, 255, 255);
        }
        spA8 = D_802CB6D0.unk_0000[i].pos;

        if (func_xk2_800EF090(spA8, &spBC, &spB8) != 0) {
            continue;
        }

        if (D_80128690[i].unk_08 != 0) {
            var_fs1 = ((gGameFrameCount % 10) * 0.2f) + 1.0f;
        } else {
            var_fs1 = 1.0f;
        }

        gSPTextureRectangle(gfx++, Math_Round(spBC - (4.0f * var_fs1)) << 2, Math_Round(spB8 - (4.0f * var_fs1)) << 2,
                            Math_Round(spBC + (4.0f * var_fs1)) << 2, Math_Round(spB8 + (4.0f * var_fs1)) << 2, 0, 0, 0,
                            Math_Round((1 << 10) / var_fs1), Math_Round((1 << 10) / var_fs1));
    }
    return gfx;
}

s32 func_xk2_800E08FC(s32 arg0) {
    CourseSegment* var_a0;
    s32 i;
    s32 var_a1;
    s32 var_a3;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_a0 = &D_802CB6D0.unk_0000[i];
        var_a1 = D_80128690[var_a0->segmentIndex].unk_00;
        var_a3 = D_80128690[var_a0->segmentIndex].unk_04;
        if (var_a1 > var_a3) {
            var_a1 = 0;
        }
        if ((arg0 >= var_a1) && (arg0 < var_a3)) {
            break;
        }
    }
    return i;
}

extern unk_80128C94 D_6000000;

extern s32 D_800DCD04;
extern s32 gCreateOption;

extern unk_8011C220 D_8011C220[];

Gfx* func_xk2_800E0988(Gfx* gfx) {
    s32 i;
    s32 var_a2;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);
    gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_NOOP2);

    if ((D_800D6CA0.unk_20 != -1) || (D_802CB6D0.controlPointCount < 4)) {
        return func_xk2_800E73DC(gfx);
    }
    if (D_xk2_800F7044 != 0) {
        return gfx;
    } else if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }

    for (i = 0; i < D_xk2_800F7058; i++) {
        if ((func_xk2_800E08FC(i) == D_800D6CA0.unk_0C) && (D_800DCD04 == 0) &&
            (gCreateOption != CREATE_OPTION_POINT)) {
            continue;
        }
        gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
        gDPPipeSync(gfx++);
        var_a2 = TRACK_SHAPE_INDEX(D_8011C220[i].unk_00 & TRACK_SHAPE_MASK);

        gDPSetPrimColor(gfx++, 0, 0, D_xk2_800F7070[var_a2][0], D_xk2_800F7070[var_a2][1], D_xk2_800F7070[var_a2][2],
                        255);
        gSPLineW3D(gfx++, 0, 1, D_xk2_800F7070[var_a2][3], 0);
    }
    return gfx;
}

Gfx* func_xk2_800E0BD0(Gfx* gfx) {
    CourseSegment* var_v1_6;
    s32 var_t4;
    s32 var_t5;
    s32 i;

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }

    if (gCreateOption == CREATE_OPTION_POINT) {
        return gfx;
    }

    if (D_800D6CA0.unk_20 != -1) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_NOOP2);
        if (D_800D6CA0.unk_0C != -1) {
            var_t5 = D_800D6CA0.unk_0C;
        } else {
            var_t5 = 0;
        }
        var_t4 = D_802CB6D0.unk_0000[var_t5].next->segmentIndex;
        if (var_t4 < var_t5) {
            for (i = 0; i < var_t4; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }

            for (i = var_t5; i < D_802CB6D0.controlPointCount; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        } else {
            for (i = var_t5; i < var_t4; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        }
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - D_xk2_800F7034);
    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);

    if (D_800D6CA0.unk_0C != -1) {
        var_v1_6 = &D_802CB6D0.unk_0000[D_800D6CA0.unk_0C];
    } else {
        var_v1_6 = &D_802CB6D0.unk_0000[0];
    }

    var_t5 = D_80128690[var_v1_6->segmentIndex].unk_00;
    var_t4 = D_80128690[var_v1_6->segmentIndex].unk_04;

    if (var_t4 < var_t5) {
        for (i = 0; i < var_t4; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }

        for (i = var_t5; i < D_xk2_800F7058; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    } else {
        for (i = var_t5; i < var_t4; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    }

    return gfx;
}

Gfx* func_xk2_800E17E0(Gfx* gfx, s32 arg1) {
    s32 var_t5;
    s32 var_t4;
    s32 i;

    var_t5 = D_80128690[arg1].unk_00;
    var_t4 = D_80128690[arg1].unk_04;

    if (var_t4 < var_t5) {
        if (var_t5 < 0x10000) {
            for (i = 0; i < var_t4; i++) {
                gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }

            for (i = var_t5; i < D_xk2_800F7058; i++) {
                gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        }
    } else {
        for (i = var_t5; i < var_t4; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    }
    return gfx;
}

extern s32 gPartsStyleOption;

Gfx* func_xk2_800E1B28(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_TRAP) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.landmine[i] == LANDMINE_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1BCC(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_DASH) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.dash[i] == DASH_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1C70(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_JUMP) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.jump[i] == JUMP_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1D14(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_GATE) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.gate[i] == GATE_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1DB8(Gfx* gfx) {
    s32 i;

    if (gPartsStyleOption != TRACK_PART_STYLE_SIGN) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.sign[i] == SIGN_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1E5C(Gfx* gfx) {

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }
    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }
    if (D_800D6CA0.unk_20 != -1) {
        return gfx;
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, D_xk2_800F7034);

    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);

    gfx = func_xk2_800E1B28(gfx);
    gfx = func_xk2_800E1BCC(gfx);
    gfx = func_xk2_800E1C70(gfx);
    gfx = func_xk2_800E1D14(gfx);
    gfx = func_xk2_800E1DB8(gfx);
    return gfx;
}

void func_xk2_800E1F40(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;

    gfx = *gfxP;

    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 6, 0);
        gSPDisplayList(gfx++, D_70207A0);
    }

    *gfxP = gfx;
}

extern Gfx D_3000338[];
extern FrameBuffer* gFrameBuffers[];

void func_xk2_800E1FC0(Gfx** gfxP) {
    Gfx* gfx;

    gfx = Segment_SetTableAddresses(*gfxP);
    gSPDisplayList(gfx++, D_3000338);
    gSPSetGeometryMode(gfx++, G_CLIPPING);
    gSPClipRatio(gfx++, FRUSTRATIO_2);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    gDPSetDepthImage(gfx++, K0_TO_PHYS(0x803DBC00));
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gfx = func_xk2_800F1428(gfx);
    if (!gInCourseEditTestRun) {
        gSPMatrix(gfx++, K0_TO_PHYS(&D_xk2_80119838), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    }
    *gfxP = gfx;
}

Gfx* func_xk2_800E2104(Gfx* gfx) {

    if (gInCourseEditTestRun) {
        return gfx;
    }

    gSPLoadUcodeL(gfx++, gspL3DEX2_fifo);
    func_xk2_800E1FC0(&gfx);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gfx = func_xk2_800E0988(gfx);
    gfx = func_xk2_800E1E5C(gfx);
    gfx = func_xk2_800E0BD0(gfx);
    func_xk2_800E1F40(&gfx);
    gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
    func_xk2_800E1FC0(&gfx);

    // TODO: move to more appropriate place
    PRINTF("(%d - %d)\n");
    PRINTF("LINE vtxi0 %d, vtxi1 %d\n");
    return gfx;
}

extern Gfx D_3000540[];
extern s32 D_xk1_80032AD0;
extern CourseSegment* D_xk2_801197EC;
extern s32 D_xk2_80119918;
extern s32 D_xk2_80128CA0;

void func_xk2_800E2238(Gfx** gfxP) {
    u8 sp290[0x40];
    s32 var_a1;
    s32 left;
    s32 top;
    s32 sp280;
    s32 temp_t0_4;
    Gfx* gfx;
    MenuDropItem* temp_t0_3;

    top = 60;
    left = 232;
    if (D_xk2_80119918 != 0) {
        return;
    }
    gfx = *gfxP;
    if (D_xk2_800F703C == -1) {
        return;
    }
    if (gCourseEditCursorXPos > 224) {
        left = 24;
    }
    D_xk2_80128CA0 = 0x40;
    D_xk2_801197EC = &D_802CB6D0.unk_0000[D_xk2_800F703C];
    func_xk2_800EA028(&gfx, left, top, 64, 116);
    left += 4;
    top += 4;
    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 0x38) << 2, (top + 0x32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    var_a1 = (D_xk2_801197EC->segmentIndex + 1) / 10;
    if (var_a1) {
        gDPLoadTextureBlock(gfx++, aCourseEditNumberSheetTex + var_a1 * 0x90, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (left + 3) << 2, top << 2, (left + 15) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
    }
    var_a1 = (D_xk2_801197EC->segmentIndex + 1) % 10;

    gDPLoadTextureBlock(gfx++, aCourseEditNumberSheetTex + var_a1 * 0x90, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + 15) << 2, top << 2, (left + 0x1B) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gDPLoadTextureBlock(gfx++, aCourseEditNumberTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + 0x1B) << 2, top << 2, (left + 0x33) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    left += 4;
    top += 16;

    temp_t0_4 = D_xk2_801197EC->trackSegmentInfo & TRACK_SHAPE_MASK;
    switch (temp_t0_4) {
        case TRACK_SHAPE_ROAD:
            sp280 = D_xk2_800F70E8[D_xk2_801197EC->trackSegmentInfo & TRACK_TYPE_MASK];
            break;
        case TRACK_SHAPE_AIR:
            sp280 = 0;
            break;
        default:
            sp280 = D_xk2_801197EC->trackSegmentInfo & TRACK_TYPE_MASK;
            func_xk2_800EDE68(sp290, sp280 + 1, 2);
            break;
    }

    func_xk2_800EDE68(sp290, sp280 + 1, 2);
    if (sp280 != -1) {
        var_a1 = TRACK_SHAPE_INDEX((u32) (D_xk2_801197EC->trackSegmentInfo & TRACK_SHAPE_MASK));
        if (var_a1 == TRACK_SHAPE_INDEX(TRACK_SHAPE_AIR)) {
            var_a1 = 0;
        }
        temp_t0_3 = D_xk2_800F7110[var_a1];
        temp_t0_3 += sp280;

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        gDPLoadTextureBlock(gfx++, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            48, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        gDPLoadTextureBlock(gfx++, temp_t0_3->subContentsRGBATex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (left + 0x13) << 2, (top + 2) << 2, (left + 0x2D) << 2, ((top + 2) + 12) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        gDPLoadTextureBlock_4b(gfx++, temp_t0_3->contentsTex, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    } else {
        gDPPipeSync(gfx++);

        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        gDPLoadTextureBlock(gfx++, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            48, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        gDPLoadTextureBlock(gfx++, aCourseEditSRoadTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (left + 0x13) << 2, (top + 2) << 2, (left + 0x2D) << 2, ((top + 2) + 12) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        gDPLoadTextureBlock_4b(gfx++, aCourseEditSTex, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    top += 20;
    temp_t0_4 = TRACK_SHAPE_INDEX((u32) (D_xk2_801197EC->trackSegmentInfo & TRACK_SHAPE_MASK));

    gSPDisplayList(gfx++, D_3000510);
    if (D_xk2_801197EC->segmentIndex != 0) {
        gDPSetPrimColor(gfx++, 0, 0, D_xk2_800F70D0[temp_t0_4][0], D_xk2_800F70D0[temp_t0_4][1],
                        D_xk2_800F70D0[temp_t0_4][2], 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 120, 130, 255, 255);
    }

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 48) << 2, (top + 10) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    top++;
    {
        s32 sp98[8] = {
            1, // TRACK_SHAPE_ROAD
            1, // TRACK_SHAPE_WALLED_ROAD
            0, // TRACK_SHAPE_PIPE
            0, // TRACK_SHAPE_CYLINDER
            0, // TRACK_SHAPE_HALF_PIPE
            0, // TRACK_SHAPE_TUNNEL
            0, // TRACK_SHAPE_AIR
            1, // TRACK_SHAPE_BORDERLESS_ROAD
        };

        D_xk1_80032AD0 = sp98[temp_t0_4];
        if (D_xk2_801197EC->segmentIndex != 0) {
            gfx = func_xk1_8002924C(gfx, left, top, D_xk2_800F7090[temp_t0_4]);
        } else {
            u8 sp90[5] = { 0x83, 0xD8, 0xAF, 0x8F, 0x00 };

            D_xk1_80032AD0 = 0;
            gfx = func_xk1_8002924C(gfx, left, top, sp90);
        }

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        top += 14;

        func_xk2_800EDAD0(&gfx, left, top, "X");
        func_xk2_800EDE68(sp290, Math_Round(D_xk2_801197EC->pos.x / 10.0f), 7);
        func_xk2_800EDAD0(&gfx, left, top, sp290);
        top += 8;
        func_xk2_800EDAD0(&gfx, left, top, "Y");
        func_xk2_800EDE68(sp290, Math_Round(D_xk2_801197EC->pos.y / 10.0f), 7);
        func_xk2_800EDAD0(&gfx, left, top, sp290);
        top += 8;
        func_xk2_800EDAD0(&gfx, left, top, "Z");
        func_xk2_800EDE68(sp290, Math_Round(D_xk2_801197EC->pos.z / 10.0f), 7);
        func_xk2_800EDAD0(&gfx, left, top, sp290);

        top += 9;

        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        gSPTextureRectangle(gfx++, (left - 4) << 2, top << 2, (left + 52) << 2, (top + 2) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        top += 3;

        D_xk1_80032AD0 = 0;
        gfx = func_xk1_8002924C(gfx, left, top, "%c%c%c", 0x90, 0xDD, 0xB8);
        func_xk2_800EDE68(sp290, COURSE_CONTEXT()->courseData.bankAngle[D_xk2_800F703C] % 360, 7);
        func_xk2_800EDAD0(&gfx, left, top, sp290);
        gfx = func_xk1_8002924C(gfx, left + 0x28, top + 1, "%c", 0xDF);

        top += 9;
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

        gSPTextureRectangle(gfx++, (left - 4) << 2, top << 2, (left + 52) << 2, (top + 2) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        gSPDisplayList(gfx++, D_3000540);

        top += 3;
        D_xk1_80032AD0 = 1;
        gfx = func_xk1_8002924C(gfx, left, top, "%c%c%c%c", 0xD0, 0xC1, 0xCA, 0x90);
        func_xk2_800EDE68(sp290, Math_Round((D_xk2_801197EC->radiusLeft + D_xk2_801197EC->radiusRight) / 10.0f), 3);
        func_xk2_800EDAD0(&gfx, left + 32, top, sp290);
        top += 8;
        func_xk2_800EDE68(sp290, Math_Round(D_xk2_801197EC->radiusLeft / 10.0f), 3);
        func_xk2_800EDAD0(&gfx, left, top, sp290);
        func_xk2_800EDAD0(&gfx, left + 18, top, "-");
        func_xk2_800EDE68(sp290, Math_Round(D_xk2_801197EC->radiusRight / 10.0f), 7);
        func_xk2_800EDAD0(&gfx, left, top, sp290);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);

        gfx = func_xk1_8002924C(gfx, left - 2, top, "L");
        gfx = func_xk1_8002924C(gfx, left + 44, top, "R");
    }

    *gfxP = gfx;
}

extern CourseInfo* gCurrentCourseInfo;

void func_xk2_800E38A8(Gfx** gfxP) {
    u8 sp28[0x40];
    Gfx* gfx;

    gfx = *gfxP;
    gSPDisplayList(gfx++, D_8014940);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    func_xk2_800EDE68(sp28, Math_Round(gCurrentCourseInfo->length * 0.1f), 6);
    func_xk2_800EDAD0(&gfx, 0xF8, 0xBA, sp28);
    func_xk2_800EDAD0(&gfx, 0x11F, 0xBA, "M");
    *gfxP = gfx;
}

void func_xk2_800E396C(Gfx** gfxP, CourseSegment* arg1) {
    s32 spDC;
    s32 spD8;
    s32 var_ra;
    u8 sp94[0x40];
    Gfx* gfx;

    if (func_xk2_800EF090(arg1->pos, &spDC, &spD8) != 0) {
        return;
    }
    gfx = *gfxP;
    // clang-format off
    spDC -= 15; \
    spD8 -= 34;
    // clang format on
    var_ra = spDC;
    if (var_ra <= 0) {
        var_ra = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, (var_ra - 1) << 2, (spD8 - 1) << 2, (spDC + 31 + 1) << 2, spD8 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (spDC - 1) << 2, (spD8 - 1) << 2, spDC << 2, (spD8 + 24 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (spDC + 31) << 2, (spD8 - 1) << 2, (spDC + 31 + 1) << 2, (spD8 + 24 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (var_ra - 1) << 2, (spD8 + 24) << 2, (spDC + 31 + 1) << 2, (spD8 + 24 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);

    gSPTextureRectangle(gfx++, var_ra << 2, spD8 << 2, (spDC + 31) << 2, (spD8 + 24) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 150, 255, 150, 160);
    func_xk2_800EDE68(sp94, Math_Round(arg1->pos.x / 10.0f), 5);
    func_xk2_800EDC88(&gfx, spDC, spD8, sp94);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 150, 255, 160);
    func_xk2_800EDE68(sp94, Math_Round(arg1->pos.y / 10.0f), 5);
    func_xk2_800EDC88(&gfx, spDC, spD8 + 8, sp94);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 150, 255, 255, 160);
    func_xk2_800EDE68(sp94, Math_Round(arg1->pos.z / 10.0f), 5);
    func_xk2_800EDC88(&gfx, spDC, spD8 + 0x10, sp94);
    *gfxP = gfx;
}

void func_xk2_800E3E90(Gfx** gfxP, CourseSegment* arg1) {
    s32 spD4;
    s32 spD0;
    s32 var_t4;
    s32 width = 42;
    s32 height = 16;
    u8 sp84[0x40];
    Gfx* gfx;

    if (func_xk2_800EF090(arg1->pos, &spD4, &spD0) != 0) {
        return;
    }
    gfx = *gfxP;
    // clang-format off
    spD4 -= 0x15; \
    spD0 -= 0x18;
    // clang-format on
    var_t4 = spD4;
    if (var_t4 <= 0) {
        var_t4 = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, (var_t4 - 1) << 2, (spD0 - 1) << 2, (spD4 + width + 1) << 2, spD0 << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (spD4 - 1) << 2, (spD0 - 1) << 2, spD4 << 2, (spD0 + height + 1) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (spD4 + width) << 2, (spD0 - 1) << 2, (spD4 + width + 1) << 2, (spD0 + height + 1) << 2,
                        0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (var_t4 - 1) << 2, (spD0 + height) << 2, (spD4 + width + 1) << 2,
                        (spD0 + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);

    gSPTextureRectangle(gfx++, var_t4 << 2, spD0 << 2, (spD4 + width) << 2, (spD0 + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_xk1_8002924C(gfx, spD4, spD0, "L");
    gfx = func_xk1_8002924C(gfx, spD4 + 0x24, spD0, "R");
    func_xk2_800EDA34(&gfx);
    func_xk2_800EDE68(sp84, Math_Round(arg1->radiusLeft / 10.0f), 3);
    func_xk2_800EDC88(&gfx, spD4, spD0 + 8, sp84);
    func_xk2_800EDC88(&gfx, spD4 + 0x12, spD0 + 8, "-");
    func_xk2_800EDE68(sp84, Math_Round(arg1->radiusRight / 10.0f), 3);
    func_xk2_800EDC88(&gfx, spD4 + 0x18, spD0 + 8, sp84);
    *gfxP = gfx;
}

void func_xk2_800E4364(Gfx** gfxP, CourseSegment* arg1) {
    s32 spD4;
    s32 spD0;
    s32 var_t4;
    s32 width = 24;
    s32 height = 8;
    u8 sp84[0x40];
    Gfx* gfx;

    if (func_xk2_800EF090(arg1->pos, &spD4, &spD0) != 0) {
        return;
    }

    gfx = *gfxP;
    // clang-format off
    spD4 -= 12; \
    spD0 -= 16;
    // clang-format on
    var_t4 = spD4;
    if (var_t4 <= 0) {
        var_t4 = 1;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, (var_t4 - 1) << 2, (spD0 - 1) << 2, (spD4 + width + 1) << 2, spD0 << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (spD4 - 1) << 2, (spD0 - 1) << 2, spD4 << 2, (spD0 + height + 1) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, (spD4 + width) << 2, (spD0 - 1) << 2, (spD4 + width + 1) << 2, (spD0 + height + 1) << 2,
                        0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (var_t4 - 1) << 2, (spD0 + height) << 2, (spD4 + width + 1) << 2,
                        (spD0 + height + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 160);

    gSPTextureRectangle(gfx++, var_t4 << 2, spD0 << 2, (spD4 + width) << 2, (spD0 + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    func_xk2_800EDE68(&sp84, COURSE_CONTEXT()->courseData.bankAngle[arg1->segmentIndex] % 360, 3);
    func_xk2_800EDAD0(&gfx, spD4, spD0, &sp84);
    gfx = func_xk1_8002924C(gfx, spD4 + 0x10, spD0, "%c", 0xDF);

    *gfxP = gfx;
}

extern s32 D_800D11C8[];
extern s32 gMoveOption;

void func_xk2_800E47B4(Gfx** gfxP) {
    s32 pad[0x12];
    Gfx* gfx;
    Gfx* gfx2;
    s32 i;

    if ((D_800D11C8[1] == 0) || gInCourseEditTestRun || (gCreateOption != CREATE_OPTION_POINT)) {
        return;
    }
    gfx = *gfxP;
    gfx2 = D_80128C94->unk_110C8;
    func_xk2_800EDA34(&gfx2);

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        switch (gMoveOption) {
            case MOVE_OPTION_MOVE_XZ:
            case MOVE_OPTION_MOVE_Y:
                func_xk2_800E396C(&gfx2, &D_802CB6D0.unk_0000[i]);
                break;
            case MOVE_OPTION_WIDTH:
            case MOVE_OPTION_CENTER:
                func_xk2_800E3E90(&gfx2, &D_802CB6D0.unk_0000[i]);
                break;
            case MOVE_OPTION_BANK:
                func_xk2_800E4364(&gfx2, &D_802CB6D0.unk_0000[i]);
                break;
        }
    }
    gSPEndDisplayList(gfx2++);

    if (gfx2 - D_80128C94->unk_110C8 > ARRAY_COUNT(D_80128C94->unk_110C8)) {
        PRINTF("GFX SIZE OVER ERROR(POINT INFO) %d\n");
        *(s8*) NULL = *(s8*) NULL;
    }
    gSPDisplayList(gfx++, D_6000000.unk_110C8);

    *gfxP = gfx;
}

Gfx* func_xk2_800E4984(Gfx* gfx) {

    D_xk2_80128CA0 = 0;
    gSPDisplayList(gfx++, D_8014940);
    func_xk2_800E2238(&gfx);
    if ((gCreateOption != CREATE_OPTION_COURSE) && (gCreateOption != CREATE_OPTION_POINT)) {
        return gfx;
    }

    func_xk2_800E47B4(&gfx);
    return gfx;
}

Gfx* func_xk2_800E49FC(Gfx* gfx) {
    s32 dashCount;
    s32 i;
    u8 sp40[0x40];
    u8 sp38[5] = { 0x8B, 0xAF, 0xBC, 0xAD, 0x00 };

    dashCount = 0;

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_DASH) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if (COURSE_CONTEXT()->courseData.dash[i] != DASH_NONE) {
            dashCount++;
        }
    }
    gSPDisplayList(gfx++, D_3000540);

    if (dashCount >= 32) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, 0xE8, 0xBA, &sp38);
    func_xk2_800EDE68(sp40, dashCount, 2);
    func_xk2_800EDAD0(&gfx, 0x108, 0xBA, sp40);
    gfx = func_xk1_8002924C(gfx, 0x114, 0xBA, "/");
    func_xk2_800EDE68(sp40, 0x20, 2);
    func_xk2_800EDAD0(&gfx, 0x11B, 0xBA, sp40);

    return gfx;
}

extern CourseFeaturesInfo gCourseFeaturesInfo;

Gfx* func_xk2_800E4BA0(Gfx* gfx) {
    u8 sp30[0x40];
    u8 sp28[5] = { 0x87, 0xAC, 0xDD, 0x97, 0x00 };

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_JUMP) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_3000540);

    if (gCourseFeaturesInfo.jumpCount >= 8) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, 0xE8, 0xBA, sp28);
    func_xk2_800EDE68(sp30, gCourseFeaturesInfo.jumpCount, 1);
    func_xk2_800EDAD0(&gfx, 0x10E, 0xBA, sp30);
    gfx = func_xk1_8002924C(gfx, 0x114, 0xBA, "/");
    func_xk2_800EDE68(sp30, 8, 1);
    func_xk2_800EDAD0(&gfx, 0x122, 0xBA, sp30);

    return gfx;
}

Gfx* func_xk2_800E4D04(Gfx* gfx) {
    u8 sp30[0x40];
    u8 sp28[5] = { 0xC4, 0xD7, 0xAF, 0x97, 0x00 };

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_TRAP) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_3000540);

    if ((gCourseFeaturesInfo.landmineCount / 6) >= 8) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, 0xE8, 0xBA, sp28);
    func_xk2_800EDE68(sp30, gCourseFeaturesInfo.landmineCount / 6, 1);
    func_xk2_800EDAD0(&gfx, 0x10E, 0xBA, sp30);
    gfx = func_xk1_8002924C(gfx, 0x114, 0xBA, "/");
    func_xk2_800EDE68(sp30, 8, 1);
    func_xk2_800EDAD0(&gfx, 0x122, 0xBA, sp30);

    return gfx;
}

Gfx* func_xk2_800E4E80(Gfx* gfx) {
    s32 decorationalFeatureCount;
    s32 i;
    u8 sp40[0x40];
    u8 sp38[5] = { 0xB5, 0x92, 0x87, 0xAA, 0x00 };

    decorationalFeatureCount = 0;

    if (gCreateOption != CREATE_OPTION_PARTS) {
        return gfx;
    }

    if (gPartsStyleOption != TRACK_PART_STYLE_GATE && gPartsStyleOption != TRACK_PART_STYLE_BUILDING &&
        gPartsStyleOption != TRACK_PART_STYLE_SIGN) {
        return gfx;
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
    gSPDisplayList(gfx++, D_3000540);

    if (decorationalFeatureCount >= 16) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, 0xE8, 0xBA, &sp38);
    func_xk2_800EDE68(sp40, decorationalFeatureCount, 2);
    func_xk2_800EDAD0(&gfx, 0x108, 0xBA, sp40);
    gfx = func_xk1_8002924C(gfx, 0x114, 0xBA, "/");
    func_xk2_800EDE68(sp40, 0x10, 2);
    func_xk2_800EDAD0(&gfx, 0x11C, 0xBA, sp40);

    return gfx;
}

extern s32 gVenueOption;
extern MenuWidget gVenueWidget;

Gfx* func_xk2_800E5058(Gfx* gfx) {
    s32 venueIndex;
    u8 sp3C[0x40];
    u8 sp34[5] = { 0x99, 0xB2, 0xDD, 0xC4, 0x00 };

    if (gVenueWidget.highlightedIndex != -1) {
        venueIndex = gVenueWidget.highlightedIndex;
    } else {
        venueIndex = gVenueOption;
    }

    gSPDisplayList(gfx++, D_3000540);

    if (D_xk2_80119918 == 0) {
        if ((gCreateOption == CREATE_OPTION_COURSE) || (gCreateOption == CREATE_OPTION_POINT)) {
            if (D_802CB6D0.controlPointCount >= 0x40) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
            D_xk1_80032AD0 = 0;
            gfx = func_xk1_8002924C(gfx, 0xE8, 0xC2, sp34);
            func_xk2_800EDE68(sp3C, D_802CB6D0.controlPointCount, 2);
            func_xk2_800EDAD0(&gfx, 0x108, 0xC2, sp3C);
            gfx = func_xk1_8002924C(gfx, 0x114, 0xC2, "/");
            func_xk2_800EDE68(sp3C, 0x40, 2);
            func_xk2_800EDAD0(&gfx, 0x11B, 0xC2, sp3C);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_xk1_8002924C(gfx, 0xE8, 0xC2, "BG %d", venueIndex + 1);
        }
    }

    // TODO: move to more appropriate place
    PRINTF("CRS DEVIDE OVER ERROR crs_vertexes = %d\n");
    PRINTF("CRS REAL LENGTH ERROR\n");
    PRINTF("TENSION %d\n");
    PRINTF("MAKE_LINE_VERTEX_ERROR0\n");
    PRINTF("MAKE_LINE_VERTEX_ERROR2\n");
    PRINTF("EDIT_MODE_COURSE 20\n");
    PRINTF("INIT GADGET\n");

    return gfx;
}

u8* sBGMNameTextures[] = {
    aCourseEditMuteCity1Tex,    aCourseEditSilenceTex,       aCourseEditSandOceanTex,    aCourseEditPortTownTex,
    aCourseEditBigBlueTex,      aCourseEditDevilsForestTex,  aCourseEditRedCanyonTex,    aCourseEditSectorTex,
    aCourseEditWhiteLandTex,    aCourseEditRainbowRoadTex,   aCourseEditRegenerationTex, aCourseEditRollerCoasterTex,
    aCourseEditBigFootTex,      aCourseEditJaponTex,         aCourseEditMuteCity1Tex,    aCourseEditSilenceTex,
    aCourseEditSandOceanTex,    aCourseEditPortTownTex,      aCourseEditBigBlueTex,      aCourseEditDevilsForestTex,
    aCourseEditRedCanyonTex,    aCourseEditSectorTex,        aCourseEditWhiteLandTex,    aCourseEditRainbowRoadTex,
    aCourseEditRegenerationTex, aCourseEditRollerCoasterTex, aCourseEditBigFootTex,      aCourseEditJaponTex,
};

extern MenuWidget gBGMWidget;

Gfx* func_xk2_800E5214(Gfx* gfx) {
    s32 highlightedIndex;
    s32 temp_v0;

    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    if (gBGMWidget.highlightedIndex != -1) {
        if (gBGMWidget.highlightedIndex != -1) {}
        highlightedIndex = gBGMWidget.highlightedIndex;
        temp_v0 = (highlightedIndex * 0x10) - func_xk1_800290B4() + 0x28;
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);

        gSPTextureRectangle(gfx++, 119 << 2, (temp_v0 - 1) << 2, 185 << 2, (temp_v0 + 8 + 1) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        gSPDisplayList(gfx++, D_8014940);

        gDPSetRenderMode(gfx++, CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_PASS,
                         CVG_DST_CLAMP | ZMODE_OPA | FORCE_BL | G_RM_NOOP2);

        gDPSetAlphaCompare(gfx++, G_AC_NONE);

        gDPLoadTextureBlock_4b(gfx++, sBGMNameTextures[highlightedIndex + 14], G_IM_FMT_I, 64, 8, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, 120 << 2, temp_v0 << 2, 184 << 2, (temp_v0 + 8) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    return gfx;
}

Gfx* func_xk2_800E54A4(Gfx* gfx) {

    if (D_xk2_80119918 != 0) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);
    gSPDisplayList(gfx++, D_3000540);
    gfx = func_xk2_800E49FC(gfx);
    gfx = func_xk2_800E4D04(gfx);
    gfx = func_xk2_800E4BA0(gfx);
    gfx = func_xk2_800E4E80(gfx);
    if ((gCreateOption != CREATE_OPTION_COURSE) && (gCreateOption != CREATE_OPTION_POINT)) {
        return gfx;
    }
    func_xk2_800E38A8(&gfx);
    return gfx;
}

extern s32 D_xk1_80030608;

void func_xk2_800E5570(void) {

    if (D_800D6CA0.unk_08 != 0) {
        return;
    }
    D_xk2_800F7050 = D_800D6CA0.unk_28.pos.x;
    D_xk2_800F7054 = D_800D6CA0.unk_28.pos.z;
    if (D_xk2_800F7050 < -32000) {
        D_xk2_800F7050 = -32000;
    }
    if (D_xk2_800F7050 > 32000) {
        D_xk2_800F7050 = 32000;
    }

    if (D_xk2_800F7054 < -32000) {
        D_xk2_800F7054 = -32000;
    }
    if (D_xk2_800F7054 > 32000) {
        D_xk2_800F7054 = 32000;
    }
    if (D_xk2_800F7050 < 0) {
        D_xk2_800F7050 = (Math_Round(D_xk2_800F7050) - (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    } else {
        D_xk2_800F7050 = (Math_Round(D_xk2_800F7050) + (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    }
    if (D_xk2_800F7054 < 0) {
        D_xk2_800F7054 = (Math_Round(D_xk2_800F7054) - (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    } else {
        D_xk2_800F7054 = (Math_Round(D_xk2_800F7054) + (D_xk1_80030608 * 10)) / (D_xk1_80030608 * 20);
    }

    D_xk2_800F7050 *= D_xk1_80030608 * 20;
    D_xk2_800F7054 *= D_xk1_80030608 * 20;
    if (D_xk2_800F7050 < -15000) {
        D_xk2_800F7050 = -15000;
    }
    if (D_xk2_800F7050 > 15000) {
        D_xk2_800F7050 = 15000;
    }

    if (D_xk2_800F7054 < -15000) {
        D_xk2_800F7054 = -15000;
    }
    if (D_xk2_800F7054 > 15000) {
        D_xk2_800F7054 = 15000;
    }
}

extern s32 D_xk2_80104CB0;
extern Gfx D_xk2_80136EF8[];

Gfx* func_xk2_800E5870(Gfx* gfx) {

    if (gInCourseEditTestRun) {
        return gfx;
    }
    func_xk2_800E5570();
    gSPDisplayList(gfx++, D_9014AE8);
    if (D_xk2_80104CB0 < 0) {
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gDPSetCombineMode(gfx++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    }
    gSPDisplayList(gfx++, D_xk2_80136EF8);
    return gfx;
}

void func_xk2_800E5920(void) {
    s32 i;

    for (i = 0; i < D_xk2_800F7058; i++) {
        D_80128C94->unk_1980[i].v.ob[0] = D_8011C220[i].pos.x;
        D_80128C94->unk_1980[i].v.ob[1] = D_8011C220[i].pos.y;
        D_80128C94->unk_1980[i].v.ob[2] = D_8011C220[i].pos.z;
    }
    D_80128C94->unk_1980[i].v.ob[0] = D_8011C220[0].pos.x;
    D_80128C94->unk_1980[i].v.ob[1] = D_8011C220[0].pos.y;
    D_80128C94->unk_1980[i].v.ob[2] = D_8011C220[0].pos.z;

    if (D_xk2_800F7058 > 896) {
        D_xk2_800F7058--;
    }
}

extern s32 gSegmentChunkCount;

void func_xk2_800E5A38(s32 arg0) {

    D_xk2_80104CA0[10] = 0;
    D_xk2_80104CA0[1] = 0;
    D_xk2_80104CA0[11] = 0;
    if (D_xk2_800F7040 != 2) {
        D_xk2_80104CA0[3] = 0;
    }
    if (gSegmentChunkCount >= 0x2FF) {
        D_xk2_80104CA0[10] = 1;
    }
    if (gCurrentCourseInfo->length > 250000.0f) {
        D_xk2_80104CA0[1] = 1;
    }
    if ((D_802CB6D0.controlPointCount >= 4) && (gCurrentCourseInfo->length < 3000.0f)) {
        D_xk2_80104CA0[11] = 1;
    }
    if (D_800D6CA0.unk_08 != 0x10) {
        if (D_xk2_800F7040 == 3) {
            D_800D6CA0.unk_1C = -1;
            D_xk2_800F706C = -1;
            if (arg0 & 0x10000) {
                D_xk2_80104CA0[3] = 1;
                D_xk2_800F706C = arg0 & 0xFFFF;
                D_800D6CA0.unk_1C = func_xk2_800E9134(D_xk2_800F706C);
            }
        } else {
            D_xk2_800F7068 = -1;
            if (arg0 & 0x10000) {
                D_xk2_80104CA0[3] = 1;
                D_xk2_800F7068 = arg0 & 0xFFFF;
            }
        }
    }
}

extern s32 D_xk2_800F6820;

s32 D_xk2_800F71F0 = 0;

void func_xk2_800E5B6C(void) {
    s32 temp_v0;

    if (!gInCourseEditTestRun) {
        gCurrentCourseInfo->courseSegments = D_802CB6D0.unk_0000;
        gCurrentCourseInfo->segmentCount = D_802CB6D0.controlPointCount;
    }
    if (gCurrentCourseInfo->segmentCount < 4) {
        D_xk2_800F7068 = -1;
        D_xk2_800F706C = -1;
        gSegmentChunkCount = 0;
        func_xk2_800E5D90(gCurrentCourseInfo);
        func_xk2_800E5A38(0);
    } else if (D_xk2_800F7040 != 0) {
        if (D_xk2_800F6820 != 0) {
            if (D_800D6CA0.unk_00 == 1) {
                func_800A4D0C(0);
            } else if (D_xk2_800F7040 == 3) {
                func_800A4D0C(2);
            } else {
                func_800A4D0C(1);
            }
        } else {
            func_800A4D0C(0);
        }
        D_xk2_80104CA0[0] = 0;
        D_800D6CA0.unk_20 = func_i2_800B39B4(gCurrentCourseInfo);

        if (D_800D6CA0.unk_20 == -1) {
            D_800D6CA0.unk_20 = func_i2_800BE8BC(gCurrentCourseInfo);
        }
        if (D_800D6CA0.unk_20 != -1) {
            D_xk2_800F7068 = -1;
            D_xk2_800F706C = -1;
            gSegmentChunkCount = 0;
            D_xk2_80104CA0[0] = 1;
            func_xk2_800E5D90(gCurrentCourseInfo);
            func_xk2_800E5A38(0);
        } else {
            func_807034F0(gCurrentCourseInfo);
            func_i2_800B3360(gCurrentCourseInfo);
            Course_SegmentLengthsInit(gCurrentCourseInfo);
            if (Course_SegmentJoinsInit(gCurrentCourseInfo) != 0) {
                D_xk2_80104CA0[4] = 1;
            }
            if ((D_xk2_800F7040 == 3) || (D_xk2_800F7040 == 2)) {
                D_xk2_800F71F0 = temp_v0 = func_xk2_800F2750();
                func_xk2_800E5A38(temp_v0);
            }
            func_xk2_800E6270(gCurrentCourseInfo);
            func_xk2_800E5920();
        }
    }
}

void func_xk2_800E5D90(CourseInfo* courseInfo) {
    CourseSegment* var_s0;
    f32 var_fv1;
    f32 var_fs0;
    s32 j;
    s32 var_s1;
    s32 var_s3;
    s32 i;
    s32 var_v0;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;

    var_fs0 = 0.0f;
    var_s0 = D_802CB6D0.unk_0000;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        sp7C = var_s0->pos;
        sp70 = var_s0->next->pos;

        var_fv1 = sqrtf(SQ(sp70.x - sp7C.x) + SQ(sp70.y - sp7C.y) + SQ(sp70.z - sp7C.z));
        var_fs0 += var_fv1;
        var_s0 = var_s0->next;
    }

    gCurrentCourseInfo->length = var_fs0;
    if (var_fs0 > 281200.0f) {
        var_v0 = (s32) (var_fs0 / 703.0f);
    } else {
        var_v0 = 0x190;
    }

    var_s1 = 0;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_s0 = &D_802CB6D0.unk_0000[i];

        sp7C = var_s0->pos;
        sp70 = var_s0->next->pos;
        var_fv1 = sqrtf(SQ(sp70.x - sp7C.x) + SQ(sp70.y - sp7C.y) + SQ(sp70.z - sp7C.z));
        var_s3 = var_fv1 / var_v0;

        if (var_s3 == 0) {
            var_s3 = 1;
        }
        var_fv1 /= var_s3;
        sp64.x = sp70.x - sp7C.x;
        sp64.y = sp70.y - sp7C.y;
        sp64.z = sp70.z - sp7C.z;
        Math_VectorSetScale(&sp64, var_fv1);
        D_80128690[i].unk_00 = var_s1;

        for (j = 0; j < var_s3; j++, var_s1++) {
            D_8011C220[var_s1].pos.x = (j * sp64.x) + sp7C.x;
            D_8011C220[var_s1].pos.y = (j * sp64.y) + sp7C.y;
            D_8011C220[var_s1].pos.z = (j * sp64.z) + sp7C.z;
            D_8011C220[var_s1].unk_00 = var_s0->trackSegmentInfo;
        }

        D_80128690[i].unk_04 = var_s1;
        if (var_s1 > 0x340) {
            break;
        }
    }
    D_80128690[0].unk_00 = var_s1;
    D_xk2_800F7058 = var_s1;
}

extern Mtx3F D_80033840[];
extern SegmentChunk gSegmentChunks[];

void func_xk2_800E6270(CourseInfo* courseInfo) {
    s32 i;
    s32 var_s3;
    unk_8011C220* var_s1;
    CourseSegment* var_s2;
    CourseSegment* spCC;
    f32 temp_fv0;
    f32 spC4;
    s32 pad[2];
    Vec3f spB0;
    Vec3f spA4;
    s32 pad2[2];
    Mtx3F sp78;

    D_xk2_800F7058 = 0;
    var_s2 = courseInfo->courseSegments;
    var_s1 = D_8011C220;
    courseInfo->segmentCount = D_802CB6D0.controlPointCount;
    spCC = var_s2;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_80128690[i].unk_00 = 0x10000;
    }

    while (true) {
        if (1) {}
        if (var_s2->startChunk == NULL) {
            break;
        }
        var_s3 = var_s2->startChunk - gSegmentChunks;
        D_80128690[var_s2->segmentIndex].unk_00 = D_xk2_800F7058;
        var_s1->pos = var_s2->pos;
        var_s1->unk_00 = var_s2->trackSegmentInfo;
        var_s1->unk_04 = 0.0f;
        Course_SplineGetBasis(var_s2, 0.0f, &sp78, 0.0f);
        var_s1->basis = sp78;
        var_s1++;

        D_xk2_800F7058++;
        if (D_xk2_800F7058 >= 0x380) {
            D_8011C220[D_xk2_800F7058] = D_8011C220[D_xk2_800F7058 - 1];
            break;
        }

        if (gSegmentChunks[var_s3].segmentTValue == 0.0f) {
            var_s3++;
        }
        if (var_s2->segmentIndex != gSegmentChunks[var_s3].segmentIndex) {
            var_s3 = (var_s3 + 1) % gSegmentChunkCount;
        }
        if ((var_s2->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) {

            temp_fv0 = Math_VectorGetDistance(var_s2->pos, var_s2->next->pos);
            var_s3 = (s32) (temp_fv0 / 400.0f);
            if (var_s3 < 2) {
                var_s3 = 2;
            }
            spB0.x = var_s2->next->pos.x - var_s2->pos.x;
            spB0.y = var_s2->next->pos.y - var_s2->pos.y;
            spB0.z = var_s2->next->pos.z - var_s2->pos.z;

            Math_VectorSetScale(&spB0, (s32) (temp_fv0 / var_s3));
            for (i = 1; i < var_s3; i++) {
                var_s1->unk_00 = var_s2->trackSegmentInfo;
                var_s1->pos.x = (f32) (var_s2->pos.x + (spB0.x * i));
                var_s1->pos.y = (f32) (var_s2->pos.y + (spB0.y * i));
                var_s1->pos.z = (f32) (var_s2->pos.z + (spB0.z * i));
                var_s1++;
                D_xk2_800F7058++;
                if (D_xk2_800F7058 >= 0x380) {
                    D_8011C220[D_xk2_800F7058] = D_8011C220[D_xk2_800F7058 - 1];
                    D_80128690[var_s2->segmentIndex].unk_04 = D_xk2_800F7058;
                    break;
                }
            }
        } else {
            while (true) {
                if (var_s2->segmentIndex != gSegmentChunks[var_s3].segmentIndex) {
                    break;
                }

                if (gSegmentChunks[var_s3].segmentTValue == 1.0f) {
                    break;
                }

                if ((D_xk2_800F7058 == (D_80128690[var_s2->segmentIndex].unk_00 + 1)) &&
                    (gSegmentChunks[var_s3].segmentTValue > 0.5f)) {
                    var_s1->unk_00 = var_s2->trackSegmentInfo;
                    var_s1->unk_04 = 0.5f;
                    Course_SplineGetPosition(var_s2, 0.5f, &var_s1->pos);
                    Course_SplineGetBasis(var_s2, 0.5f, &sp78, Course_SplineGetLengthInfo(var_s2, 0.5f, &spC4));
                    var_s1->basis = sp78;
                } else {
                    var_s1->unk_00 = var_s2->trackSegmentInfo;
                    var_s1->unk_04 = gSegmentChunks[var_s3].segmentTValue;
                    var_s1->pos.x = gSegmentChunks[var_s3].pos.x;
                    var_s1->pos.y = gSegmentChunks[var_s3].pos.y;
                    var_s1->pos.z = gSegmentChunks[var_s3].pos.z;
                    var_s1->basis = D_80033840[var_s3];
                }
                var_s1++;
                var_s3++;
                D_xk2_800F7058++;

                if (gSegmentChunkCount < var_s3) {
                    D_8011C220[D_xk2_800F7058] = D_8011C220[D_xk2_800F7058 - 1];
                    D_80128690[var_s2->segmentIndex].unk_04 = D_xk2_800F7058;
                    break;
                }

                if (D_xk2_800F7058 >= 0x380) {
                    D_8011C220[D_xk2_800F7058] = D_8011C220[D_xk2_800F7058 - 1];
                    D_80128690[var_s2->segmentIndex].unk_04 = D_xk2_800F7058;
                    break;
                }
            }
            if (D_xk2_800F7058 == (D_80128690[var_s2->segmentIndex].unk_00 + 1)) {
                Course_SplineGetPosition(var_s2, 0.5f, &spA4);
                var_s1->pos = spA4;
                var_s1->unk_00 = var_s2->trackSegmentInfo;
                var_s1->unk_04 = 0.5f;
                Course_SplineGetBasis(var_s2, 0.5f, &sp78, Course_SplineGetLengthInfo(var_s2, 0.5f, &spC4));
                var_s1->basis = sp78;
                var_s1++;
                D_xk2_800F7058++;
                if (D_xk2_800F7058 >= 0x380) {
                    D_8011C220[D_xk2_800F7058] = D_8011C220[D_xk2_800F7058 - 1];
                    D_80128690[var_s2->segmentIndex].unk_04 = D_xk2_800F7058;
                    break;
                }
            }
        }

        D_80128690[var_s2->segmentIndex].unk_04 = D_xk2_800F7058;
        D_8011C220[D_xk2_800F7058] = D_8011C220[0];

        var_s2 = var_s2->next;
        if (spCC == var_s2) {
            break;
        }
        if (D_xk2_800F7058 >= 0x380) {
            D_8011C220[D_xk2_800F7058] = D_8011C220[D_xk2_800F7058 - 1];
            break;
        }
    }
    D_xk2_800F7058++;
}

bool func_xk2_800E6B3C(void) {
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_t1;
    s32 temp_t3;
    s32 temp_v0;
    s32 temp_v1;
    s32 i;
    s32 var_s3;
    s32 var_t4;
    CourseSegment* var_s0;

    var_s3 = false;
    if (D_800D6CA0.unk_08 == 2) {
        return false;
    }
    var_s0 = &D_802CB6D0;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++, var_s0 = var_s0->next) {
        temp_a3 = var_s0->prev->trackSegmentInfo & TRACK_SHAPE_MASK;
        temp_a0 = var_s0->next->trackSegmentInfo & TRACK_SHAPE_MASK;
        temp_v0 = var_s0->trackSegmentInfo & TRACK_SHAPE_MASK;
        temp_t1 = var_s0->prev->trackSegmentInfo & TRACK_FLAG_JOINABLE;
        temp_t3 = var_s0->next->trackSegmentInfo & TRACK_FLAG_JOINABLE;

        switch (var_s0->trackSegmentInfo & TRACK_SHAPE_MASK) {
            case TRACK_SHAPE_ROAD:
            case TRACK_SHAPE_AIR:
                break;
            case TRACK_SHAPE_WALLED_ROAD:
            case TRACK_SHAPE_PIPE:
            case TRACK_SHAPE_CYLINDER:
            case TRACK_SHAPE_HALF_PIPE:
            case TRACK_SHAPE_TUNNEL:
            case TRACK_SHAPE_BORDERLESS_ROAD:
                if (((temp_v0 != temp_a3) && !temp_t1) || ((temp_v0 != temp_a0) && !temp_t3)) {
                    var_s3 = true;
                    if ((temp_v0 != temp_a3) && !temp_t1) {
                        func_xk2_800F1330(var_s0->segmentIndex, 1);
                    }
                }
                break;
            default:
                var_s3 = true;
                break;
        }
    }
    return var_s3;
}

extern s32 D_xk2_80128D6C;

void func_xk2_800E6CA8(s32 arg0, CourseSegment arg1) {
    s32 pad[2];
    CourseSegment* temp_v1;
    s32 i;

    if (arg0 != -1) {
        if (D_802CB6D0.controlPointCount >= 2) {
            arg1.trackSegmentInfo = D_802CB6D0.unk_0000[arg0].trackSegmentInfo;
            if (!(arg1.trackSegmentInfo & TRACK_TYPE_MASK) && !(arg1.trackSegmentInfo & TRACK_SHAPE_MASK)) {
                arg1.trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2);
            }
        }

        for (i = D_802CB6D0.controlPointCount; i > arg0; i--) {
            D_802CB6D0.unk_0000[i] = D_802CB6D0.unk_0000[i - 1];
            D_802CB6D0.unk_0000[i].segmentIndex = i;

            gCourseCtx.courseData.bankAngle[i] = gCourseCtx.courseData.bankAngle[i - 1];
            D_80128690[i] = D_80128690[i - 1];

            gCourseCtx.courseData.pit[i] = gCourseCtx.courseData.pit[i - 1];
            gCourseCtx.courseData.dash[i] = gCourseCtx.courseData.dash[i - 1];
            gCourseCtx.courseData.dirt[i] = gCourseCtx.courseData.dirt[i - 1];
            gCourseCtx.courseData.ice[i] = gCourseCtx.courseData.ice[i - 1];
            gCourseCtx.courseData.jump[i] = gCourseCtx.courseData.jump[i - 1];
            gCourseCtx.courseData.landmine[i] = gCourseCtx.courseData.landmine[i - 1];
            gCourseCtx.courseData.gate[i] = gCourseCtx.courseData.gate[i - 1];
            gCourseCtx.courseData.building[i] = gCourseCtx.courseData.building[i - 1];
            gCourseCtx.courseData.sign[i] = gCourseCtx.courseData.sign[i - 1];
        }
    }

    temp_v1 = &D_802CB6D0.unk_0000[arg0 + 1];
    temp_v1->segmentIndex = arg0 + 1;
    temp_v1->pos.x = Math_Round(arg1.pos.x);
    temp_v1->pos.y = Math_Round(arg1.pos.y);
    temp_v1->pos.z = Math_Round(arg1.pos.z);
    temp_v1->up.x = 0.0f;
    temp_v1->up.y = 1.0f;
    temp_v1->up.z = 0.0f;
    temp_v1->radiusLeft = arg1.radiusLeft;
    temp_v1->radiusRight = arg1.radiusRight;
    temp_v1->trackSegmentInfo = arg1.trackSegmentInfo;
    gCourseCtx.courseData.bankAngle[arg0 + 1] = D_xk2_80128D6C;
    gCourseCtx.courseData.pit[arg0 + 1] = PIT_NONE;
    gCourseCtx.courseData.dash[arg0 + 1] = DASH_NONE;
    gCourseCtx.courseData.dirt[arg0 + 1] = DIRT_NONE;
    gCourseCtx.courseData.ice[arg0 + 1] = ICE_NONE;
    gCourseCtx.courseData.jump[arg0 + 1] = JUMP_NONE;
    gCourseCtx.courseData.landmine[arg0 + 1] = LANDMINE_NONE;
    gCourseCtx.courseData.gate[arg0 + 1] = GATE_NONE;
    gCourseCtx.courseData.building[arg0 + 1] = BUILDING_NONE;
    gCourseCtx.courseData.sign[arg0 + 1] = SIGN_NONE;
    D_800D6CA0.unk_0C = arg0 + 1;

    D_802CB6D0.controlPointCount++;
    D_xk2_800F7060 = Math_Rand2() % 30;
    D_xk2_800F7064 = Math_Rand2() & 3;
    func_xk2_800E6F9C();
}

void func_xk2_800E6F9C(void) {
    CourseSegment* var_v0;
    s32 i;

    var_v0 = D_802CB6D0.unk_0000;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_v0->segmentIndex = i;
        var_v0->next = var_v0 + 1;
        var_v0->prev = var_v0 - 1;
        var_v0++;
    }
    if (D_802CB6D0.controlPointCount != 0) {
        D_802CB6D0.unk_0000[0].prev = &D_802CB6D0.unk_0000[D_802CB6D0.controlPointCount - 1];
        D_802CB6D0.unk_0000[D_802CB6D0.controlPointCount - 1].next = &D_802CB6D0.unk_0000[0];
    } else {
        D_802CB6D0.unk_0000[0].segmentIndex = 0;
        D_802CB6D0.unk_0000[0].prev = D_802CB6D0.unk_0000;
        D_802CB6D0.unk_0000[0].next = D_802CB6D0.unk_0000;
    }
}

extern Vtx D_xk2_80128DF8[];

#ifdef NON_MATCHING
void func_xk2_800E7028(s32 arg0) {
    s32 i;
    s32 j;
    Vtx* vtx;
    Gfx* gfx;
    s32 temp_v1;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_t4;
    s32 temp_lo;

    temp_lo = 8000 / arg0;

    for (i = 0; i < 30; i++) {
        for (j = 0; j < 30; j++) {
            vtx = &D_xk2_80128DF8[((i * 30) + j) * 4];
            temp_v1 = (j * 8000) / arg0;
            temp_v1 %= 256;
            temp_t1 = (i * 8000) / arg0;
            temp_t1 %= 256;

            vtx->v.ob[0] = ((j - 15) * 1000);
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = ((i - 15) * 1000);
            vtx->v.tc[0] = temp_v1 << 6;
            vtx->v.tc[1] = temp_t1 << 6;
            vtx++;
            vtx->v.ob[0] = ((j - 14) * 1000);
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = ((i - 15) * 1000);
            vtx->v.tc[0] = (temp_v1 + temp_lo) << 6;
            vtx->v.tc[1] = temp_t1 << 6;
            vtx++;
            vtx->v.ob[0] = ((j - 15) * 1000);
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = ((i - 14) * 1000);
            vtx->v.tc[0] = temp_v1 << 6;
            vtx->v.tc[1] = (temp_t1 + temp_lo) << 6;
            vtx++;
            vtx->v.ob[0] = ((j - 14) * 1000);
            vtx->v.ob[1] = 0;
            vtx->v.ob[2] = ((i - 14) * 1000);
            vtx->v.tc[0] = (temp_v1 + temp_lo) << 6;
            vtx->v.tc[1] = (temp_t1 + temp_lo) << 6;
            vtx++;
        }
    }
    gfx = D_xk2_80136EF8;
    for (i = 0; i < 120; i++) {
        vtx = &D_xk2_80128DF8[i * 4];
        gSPVertex(gfx++, vtx, 4, 0);
        gSP2Triangles(gfx++, 2, 1, 0, 0, 1, 2, 3, 0);
    }

    gSPEndDisplayList(gfx++);
}
#else
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/overlays/course_edit/191080/func_xk2_800E7028.s")
#endif

void func_xk2_800E72BC(void) {
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;
    s32 i;

    var_fv0 = 65536.0f;
    var_fv1 = -65536.0f;
    var_fa0 = 65536.0f;
    var_fa1 = -65536.0f;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (var_fv0 > D_802CB6D0.unk_0000[i].pos.x) {
            var_fv0 = D_802CB6D0.unk_0000[i].pos.x;
        }
        if (var_fv1 < D_802CB6D0.unk_0000[i].pos.x) {
            var_fv1 = D_802CB6D0.unk_0000[i].pos.x;
        }

        if (var_fa0 > D_802CB6D0.unk_0000[i].pos.z) {
            var_fa0 = D_802CB6D0.unk_0000[i].pos.z;
        }
        if (var_fa1 < D_802CB6D0.unk_0000[i].pos.z) {
            var_fa1 = D_802CB6D0.unk_0000[i].pos.z;
        }
    }
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        D_802CB6D0.unk_0000[i].pos.x -= (var_fv0 + var_fv1) / 2;
        D_802CB6D0.unk_0000[i].pos.z -= (var_fa0 + var_fa1) / 2;
    }
    D_xk2_800F7040 = 3;
}

Gfx* func_xk2_800E73DC(Gfx* gfx) {
    s32 i;

    if (D_802CB6D0.controlPointCount < 2) {
        return gfx;
    }

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        if ((i == D_800D6CA0.unk_0C) && (D_800DCD04 != 0)) {
            continue;
        }
        gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
        gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_802CB6D0.controlPointCount) * 6], 1, 1);
        gSPLine3D(gfx++, 0, 1, 0);
    }
    return gfx;
}

extern s32 D_xk2_800F6838;
extern s32 D_xk2_800F683C;
extern s32 D_xk2_800F6840;
extern s32 D_xk2_800F6844;

Gfx* func_xk2_800E7518(Gfx* gfx) {
    s32 var_t1;
    s32 var_t3;
    s32 var_t4;
    s32 var_v0;

    if (D_xk2_80119918 != 0) {
        return gfx;
    }
    if (D_800D6CA0.unk_08 != 5) {
        return gfx;
    }
    if (gCreateOption != CREATE_OPTION_POINT) {
        return gfx;
    }
    if (!(gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z)) {
        return gfx;
    }
    if (gCourseEditCursorYPos < 0x38) {
        return gfx;
    }
    if (D_xk2_800F6838 < D_xk2_800F6840) {
        var_t3 = D_xk2_800F6838;
        var_t4 = D_xk2_800F6840;
    } else {
        var_t3 = D_xk2_800F6840;
        var_t4 = D_xk2_800F6838;
    }
    if (D_xk2_800F683C < D_xk2_800F6844) {
        var_t1 = D_xk2_800F683C;
        var_v0 = D_xk2_800F6844;
    } else {
        var_t1 = D_xk2_800F6844;
        var_v0 = D_xk2_800F683C;
    }

    gSPDisplayList(gfx++, D_3000510);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gSPTextureRectangle(gfx++, var_t3 << 2, var_t1 << 2, var_t4 << 2, (var_t1 + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, var_t3 << 2, var_v0 << 2, (var_t4 + 1) << 2, (var_v0 + 1) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);
    gSPTextureRectangle(gfx++, var_t3 << 2, var_t1 << 2, (var_t3 + 1) << 2, var_v0 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, var_t4 << 2, var_t1 << 2, (var_t4 + 1) << 2, var_v0 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

void func_xk2_800E77F0(void) {
    D_800D6CA0.unk_00 = 0;
    D_800D6CA0.unk_04 = 0;
    D_800D6CA0.unk_08 = 0;
    D_800D6CA0.unk_28.trackSegmentInfo = 0x18000000;
    D_800D6CA0.unk_20 = -1;
    D_800D6CA0.unk_1C = -1;
    D_800D6CA0.unk_24 = 0;
    D_800D6CA0.unk_0C = -1;
    D_800D6CA0.unk_10 = -1;
    D_800D6CA0.unk_14 = 0;
    D_800D6CA0.unk_28.radiusLeft = 260.0f;
    D_800D6CA0.unk_28.radiusRight = 260.0f;
    D_800D6CA0.unk_28.up.x = 0.0f;
    D_800D6CA0.unk_28.up.y = 1.0f;
    D_800D6CA0.unk_28.up.z = 0.0f;
}

void func_xk2_800E7854(void) {

    D_xk2_800F7034 += D_xk2_800F7038;

    // clang-format off
    if (D_xk2_800F7034 >= 255) {
        D_xk2_800F7034 = 255; \
        D_xk2_800F7038 = -0x10;
    }
    if (D_xk2_800F7034 <= 0) {
        D_xk2_800F7034 = 0; \
        D_xk2_800F7038 = 0x10;
    }
    // clang-format on
    func_xk2_800DFFF8();
    func_xk2_800E5B6C();
    func_xk2_800E7BA8();
    func_xk2_800E7990();
    func_xk2_800E7A78();
    func_8070304C();
    func_80703234();
    if ((D_802CB6D0.controlPointCount >= 4) && (D_800D6CA0.unk_20 == -1)) {
        Course_FeaturesInit(0);
        if (D_xk2_800F7040 != 0) {
            Course_EffectsInit(0);
        }
        Course_LandminesViewInteractDataInit();
        Course_JumpsViewInteractDataInit();
        if (D_800D6CA0.unk_00 == 1) {
            Course_EffectsViewInteractDataInit(true);
        } else if (D_xk2_800F7040 != 0) {
            Course_EffectsViewInteractDataInit(false);
        }
        Course_DecorationsViewInteractDataInit();
    }
    func_xk2_800F1938();
}

extern Vec3f D_xk2_80119818;

void func_xk2_800E7990(void) {
    CourseSegment* var_s0;
    s32 i;

    D_xk2_80104CA0[8] = 0;
    if (D_800D6CA0.unk_20 != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    D_xk2_80119818.y = 0.0f;
    var_s0 = D_802CB6D0.unk_0000;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        Course_SplineGetPosition(var_s0, 0.5f, &D_xk2_80119818);
        if (D_xk2_80119818.y < -375.0f) {
            D_xk2_80104CA0[8] = 1;
            return;
        }

        var_s0 = var_s0->next;
    }
}

extern Vec3f D_xk2_80119828;

void func_xk2_800E7A78(void) {
    CourseSegment* var_s0;
    s32 i;

    D_xk2_80104CA0[9] = 0;
    if (D_800D6CA0.unk_20 != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    D_xk2_80119828.x = 0.0f;
    D_xk2_80119828.z = 0.0f;
    var_s0 = D_802CB6D0.unk_0000;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        Course_SplineGetPosition(var_s0, 0.5f, &D_xk2_80119828);
        if ((D_xk2_80119828.x < -15000.0f) || (D_xk2_80119828.x > 15000.0f) || (D_xk2_80119828.z < -15000.0f) ||
            (D_xk2_80119828.z > 15000.0f)) {
            D_xk2_80104CA0[9] = 1;
            return;
        }

        var_s0 = var_s0->next;
    }
}

void func_xk2_800E7BA8(void) {
    CourseSegment* var_s0;
    s32 i;
    f32 sp114;
    CourseSegment* temp_s1;
    CourseSegment* temp_s2;
    Vec3f sp100;
    Vec3f spF4;
    Vec3f spE8;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_ft4;
    Mtx3F spB8;
    Mtx3F sp94;
    Mtx3F sp70;
    f32 temp_fv0;
    f32 temp_fs0;
    f32 var_fs1;

    var_fs1 = 200.0f;
    if (D_800D6CA0.unk_20 != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }
    var_s0 = D_802CB6D0.unk_0000[0].prev;
    temp_fs0 = Course_SplineGetLengthInfo(var_s0, 0.0f, &sp114);
    Course_SplineGetPosition(var_s0, 0.0f, &spF4);
    Course_SplineGetBasis(var_s0, 0.0f, &sp94, temp_fs0);
    var_s0 = var_s0->next;
    temp_fs0 = Course_SplineGetLengthInfo(var_s0, 0.0f, &sp114);
    Course_SplineGetPosition(var_s0, 0.0f, &sp100);
    Course_SplineGetBasis(var_s0, 0.0f, &spB8, temp_fs0);

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_s0 = &D_802CB6D0.unk_0000[i];

        temp_s1 = var_s0->next;
        temp_s2 = var_s0->prev;
        temp_fs0 = Course_SplineGetLengthInfo(temp_s1, 0.0f, &sp114);
        Course_SplineGetPosition(temp_s1, 0.0f, &spE8);
        Course_SplineGetBasis(temp_s1, 0.0f, &sp70, temp_fs0);

        temp_fv1 = ((temp_s2->radiusLeft * sp94.z.x) + spF4.x) - (sp100.x + (var_s0->radiusLeft * spB8.z.x));
        temp_fa1 = ((temp_s2->radiusLeft * sp94.z.y) + spF4.y) - (sp100.y + (var_s0->radiusLeft * spB8.z.y));
        temp_ft4 = ((temp_s2->radiusLeft * sp94.z.z) + spF4.z) - (sp100.z + (var_s0->radiusLeft * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }

        temp_fv1 = (spF4.x - (temp_s2->radiusRight * sp94.z.x)) - (sp100.x - (var_s0->radiusRight * spB8.z.x));
        temp_fa1 = (spF4.y - (temp_s2->radiusRight * sp94.z.y)) - (sp100.y - (var_s0->radiusRight * spB8.z.y));
        temp_ft4 = (spF4.z - (temp_s2->radiusRight * sp94.z.z)) - (sp100.z - (var_s0->radiusRight * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }

        temp_fv1 = ((temp_s1->radiusLeft * sp70.z.x) + spE8.x) - (sp100.x + (var_s0->radiusLeft * spB8.z.x));
        temp_fa1 = ((temp_s1->radiusLeft * sp70.z.y) + spE8.y) - (sp100.y + (var_s0->radiusLeft * spB8.z.y));
        temp_ft4 = ((temp_s1->radiusLeft * sp70.z.z) + spE8.z) - (sp100.z + (var_s0->radiusLeft * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }

        temp_fv1 = (spE8.x - (temp_s1->radiusRight * sp70.z.x)) - (sp100.x - (var_s0->radiusRight * spB8.z.x));
        temp_fa1 = (spE8.y - (temp_s1->radiusRight * sp70.z.y)) - (sp100.y - (var_s0->radiusRight * spB8.z.y));
        temp_ft4 = (spE8.z - (temp_s1->radiusRight * sp70.z.z)) - (sp100.z - (var_s0->radiusRight * spB8.z.z));
        temp_fv0 = sqrtf(SQ(temp_fv1) + SQ(temp_fa1) + SQ(temp_ft4));
        if (temp_fv0 < var_fs1) {
            var_fs1 = temp_fv0;
        }
        spF4 = sp100;
        sp94 = spB8;
        sp100 = spE8;
        spB8 = sp70;
    }
    if (var_fs1 < 150.0f) {
        D_xk2_80104CA0[6] = 1;
    }
}

extern Gfx D_3000540[];
extern MenuWidget gCreateWidget;
extern MenuWidget gCourseEditWidget;
extern s32* gCourseEditMenuOptions[];

Gfx* func_xk2_800E8080(Gfx* gfx) {
    static bool D_xk2_800F71F4 = false;
    s32 i;
    MenuDropItem* temp_a2;
    s32 temp_t2_2;
    s32 temp_t1;
    s32 var_t0;

    gSPDisplayList(gfx++, D_9014908);

    for (i = 0; i < 5; i++) {
        if (gCourseEditWidget.menuItems[i].widget == NULL) {
            continue;
        }

        var_t0 = *gCourseEditMenuOptions[i];
        if (var_t0 == -1) {
            continue;
        }
        // FAKE
        temp_a2 = &gCourseEditWidget.menuItems[i].widget->menuItems[(0, var_t0)];

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        gDPLoadTextureBlock(gfx++, temp_a2->backgroundSelectedTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, ((i * 48) + 24) << 2, 36 << 2, ((i * 48) + 72) << 2, 52 << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        if (temp_a2->subContentsRGBATex != NULL) {
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, temp_a2->subContentsRGBATex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, ((i * 48) + 0x2B) << 2, 38 << 2, ((i * 48) + 0x45) << 2, 50 << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
        }

        if (temp_a2->contentsTex != NULL) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, temp_a2->contentsTex, G_IM_FMT_I, temp_a2->contentsWidth,
                                   temp_a2->contentsHeight, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, ((i * 48) + 24) << 2, 36 << 2, ((i * 48) + temp_a2->contentsWidth + 0x18) << 2,
                                (temp_a2->contentsHeight + 0x34) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }

        if (temp_a2->subContentsI4Tex != NULL) {
            temp_t2_2 = 16;
            temp_t1 = 16;
            // FAKE
            var_t0 = ((i * 48) + 0x34);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, temp_a2->subContentsI4Tex, G_IM_FMT_I, temp_t2_2, temp_t1, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, ((i * 48) + 0x34) << 2, 36 << 2, ((i * 48) + 0x44) << 2, 52 << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
        }
    }
    {
        Gfx* sp148;
        sp148 = D_80128C94->unk_F9A0;
        func_xk1_800276B0(&sp148, &gCourseEditWidget, D_xk1_8003A550, D_xk1_8003A554);
        gSPEndDisplayList(sp148++);
    }

    gSPDisplayList(gfx++, D_6000000.unk_F9A0);

    {
        MenuWidget* temp_v0_2;
        s32 pad;
        temp_v0_2 = func_xk1_80026914(&gCourseEditWidget);
        if (D_802CB6D0.controlPointCount < 4) {
            if (temp_v0_2 == &gCreateWidget) {

                temp_t2_2 = temp_v0_2->left;
                temp_t1 = temp_v0_2->top + temp_v0_2->itemYOffset;

                gSPDisplayList(gfx++, D_3000510);
                gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 128);

                gSPTextureRectangle(gfx++, temp_t2_2 << 2, temp_t1 << 2, (temp_t2_2 + 48) << 2, (temp_t1 + 80) << 2, 0,
                                    0, 0, 1 << 10, 1 << 10);

                gSPDisplayList(gfx++, D_3000540);
                func_xk2_800EECD4(&gfx, temp_t2_2 + 48, temp_t1 + 16, D_xk1_800331F0[24], 24);
            }
        }
    }
    gfx = func_xk2_800EBB24(gfx);

    gDPPipeSync(gfx++);

    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    if ((gCourseEditCursorXPos >= 264) && (gCourseEditCursorXPos < 296) && (gCourseEditCursorYPos >= 20) &&
        (gCourseEditCursorYPos < 36)) {

        gDPLoadTextureBlock(gfx++, aExpansionKitMenuExitHighlightTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, aExpansionKitMenuExitTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    }

    gSPTextureRectangle(gfx++, 264 << 2, 20 << 2, 296 << 2, 36 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    if ((gCourseEditCursorXPos >= 264) && (gCourseEditCursorXPos < 296) && (gCourseEditCursorYPos >= 36) &&
        (gCourseEditCursorYPos < 52)) {
        if (!D_xk2_800F71F4) {
            Audio_TriggerSystemSE(NA_SE_35);
        }
        D_xk2_800F71F4 = true;
    } else {
        if (D_xk2_800F71F4) {
            Audio_TriggerSystemSE(NA_SE_35);
        }
        D_xk2_800F71F4 = false;
    }

    if (D_xk2_800F71F4) {
        gDPLoadTextureBlock(gfx++, aExpansionKitMenuOptionHighlightTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, aExpansionKitMenuOptionTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
    }

    gSPTextureRectangle(gfx++, 264 << 2, 36 << 2, 296 << 2, 52 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    if (D_xk2_800F7048 != 0) {
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 128);

        gSPTextureRectangle(gfx++, 24 << 2, 20 << 2, 296 << 2, 36 << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gfx++, 24 << 2, 36 << 2, 296 << 2, 52 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    return gfx;
}

extern u8 D_80030060[];

Gfx* func_xk2_800E8F7C(Gfx* gfx) {

    if (D_xk2_80119918 != 0) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
    gSPTextureRectangle(gfx++, 231 << 2, 177 << 2, 297 << 2, 203 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);
    gSPTextureRectangle(gfx++, 232 << 2, 178 << 2, 296 << 2, 202 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gSPDisplayList(gfx++, D_3000540);

    if (D_80030060[0] == '\0') {
        gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 0);
        return func_xk1_8002924C(gfx, 0xE8, 0xB2, "No Title");
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 0);
    return func_xk1_8002924C(gfx, 0xE8, 0xB2, "%s", D_80030060);
}

s32 func_xk2_800E9134(s32 arg0) {
    s32 i;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 var_v1;
    CourseSegment* var_a0;

    var_v1 = -1;

    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {
        var_a0 = &D_802CB6D0.unk_0000[i];

        temp_lo = var_a0->startChunk - gSegmentChunks;
        temp_lo_2 = var_a0->endChunk - gSegmentChunks;
        if (temp_lo < temp_lo_2) {
            if ((arg0 >= temp_lo) && (arg0 < temp_lo_2)) {
                var_v1 = i;
                break;
            }
        } else if (((arg0 >= 0) && (arg0 < temp_lo_2)) || (arg0 >= temp_lo)) {
            var_v1 = i;
            break;
        }
    }
    return var_v1;
}

f32 D_xk2_800F71F8 = 0.0f;

void func_xk2_800E9234(void) {
    static f32 D_xk2_800F71FC = 0.0f;
    static s32 D_xk2_800F7200 = 1;
    D_xk2_800F71F8 += D_xk2_800F71FC;
    if (D_xk2_800F7200 != 0) {
        D_xk2_800F71FC += 1.0f;
        if (D_xk2_800F71F8 >= 6.0f) {
            D_xk2_800F71FC = -2.0f;
            D_xk2_800F7200 = 0;
        }
    } else if (D_xk2_800F71F8 <= 0.0f) {
        D_xk2_800F71F8 = 0.0f;
        D_xk2_800F71FC = 0.0f;
        D_xk2_800F7200 = 1;
    }
}

void func_xk2_800E92E4(Gfx** gfxP, s32 arg1, s32 arg2) {
    Gfx* gfx;

    arg1 = arg1 - 8;
    arg2 = ((s32) (D_xk2_800F71F8 + 0.5f) + arg2) - 0x1C;
    if ((arg1 >= 0) && (arg1 < SCREEN_WIDTH) && (arg2 >= 40) && (arg2 < SCREEN_HEIGHT)) {
        gfx = *gfxP;

        gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 16) << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        *gfxP = gfx;
    }
}

void func_xk2_800E93B0(Gfx** gfxP) {
    Gfx* gfx;
    s32 sp38;
    s32 sp34;
    Vec3f sp28;

    if (D_800D6CA0.unk_20 != -1) {
        return;
    }
    gfx = *gfxP;
    if (D_xk2_800F7068 != -1) {
        sp28 = gSegmentChunks[D_xk2_800F7068].pos;
        if (func_xk2_800EF090(sp28, &sp38, &sp34) == 0) {
            func_xk2_800E92E4(&gfx, sp38, sp34);
        }
    }

    if (D_800D6CA0.unk_1C != -1) {
        sp28 = D_802CB6D0.unk_0000[D_800D6CA0.unk_1C].pos;
        if (func_xk2_800EF090(sp28, &sp38, &sp34) == 0) {
            func_xk2_800E92E4(&gfx, sp38, sp34);
        }
    }
    *gfxP = gfx;
}

void func_xk2_800E9504(Gfx** gfxP) {
    Gfx* gfx;
    s32 sp38;
    s32 sp34;
    Vec3f sp28;

    if (D_800D6CA0.unk_20 == -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        D_800D6CA0.unk_20 = -1;
        return;
    }
    gfx = *gfxP;
    sp28 = D_802CB6D0.unk_0000[D_800D6CA0.unk_20].pos;
    if (func_xk2_800EF090(sp28, &sp38, &sp34) == 0) {
        func_xk2_800E92E4(&gfx, sp38, sp34);
    }
    *gfxP = gfx;
}

void func_xk2_800E95E0(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 sp54;
    s32 sp50;
    Vec3f sp44;

    gfx = *gfxP;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (func_xk2_800F1350(i) & 1) {
            sp44 = D_802CB6D0.unk_0000[i].pos;

            if (func_xk2_800EF090(sp44, &sp54, &sp50) == 0) {
                func_xk2_800E92E4(&gfx, sp54, sp50);
            }
        }
    }
    *gfxP = gfx;
}

void func_xk2_800E96F4(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 sp54;
    s32 sp50;
    Vec3f sp44;

    gfx = *gfxP;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        if (func_xk2_800F1350(i) & 2) {
            sp44 = D_802CB6D0.unk_0000[i].pos;
            if (func_xk2_800EF090(sp44, &sp54, &sp50) == 0) {
                func_xk2_800E92E4(&gfx, sp54, sp50);
            }
        }
    }
    *gfxP = gfx;
}

extern Vec3f D_xk2_80119818;

void func_xk2_800E9808(Gfx** gfxP) {
    Gfx* gfx;
    s32 sp28;
    s32 sp24;

    if (D_800D6CA0.unk_20 != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        D_xk2_80119818.y = 0.0f;
        return;
    }
    if (D_xk2_80119818.y >= -375.0f) {
        return;
    }
    gfx = *gfxP;
    if (func_xk2_800EF090(D_xk2_80119818, &sp28, &sp24) == 0) {
        func_xk2_800E92E4(&gfx, sp28, sp24);
    }
    *gfxP = gfx;
}

void func_xk2_800E98D8(Gfx** gfxP) {
    CourseSegment* var_s0;
    s32 sp78;
    s32 sp74;
    Vec3f sp68;
    s32 i;
    Gfx* gfx;

    if (D_800D6CA0.unk_20 != -1) {
        return;
    }
    if (D_802CB6D0.controlPointCount < 4) {
        return;
    }

    gfx = *gfxP;
    var_s0 = D_802CB6D0.unk_0000;
    for (i = 0; i < D_802CB6D0.controlPointCount; i++) {

        Course_SplineGetPosition(var_s0, 0.5f, &sp68);
        if (((sp68.x < -15000.0f) || (sp68.x > 15000.0f) || (sp68.z < -15000.0f) || (sp68.z > 15000.0f)) &&
            (func_xk2_800EF090(sp68, &sp78, &sp74) == 0)) {
            func_xk2_800E92E4(&gfx, sp78, sp74);
        }
        var_s0 = var_s0->next;
    }
    *gfxP = gfx;
}

#define COURSE_EDIT_ICONS_X_POS 232
#define COURSE_EDIT_ICONS_Y_POS 204
#define COURSE_EDIT_ICON_WIDTH 16
#define COURSE_EDIT_ICON_HEIGHT 16
#define COURSE_EDIT_NUM_ICONS 4

s32 CourseEdit_UpdateHighlightedIconIndex(void) {
    s32 highlightedIconXPos;

    if ((gCreateOption == CREATE_OPTION_POINT) && (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z)) {
        gCourseEditHighlightedIconIndex = -1;
        return -1;
    }
    if (D_800D6CA0.unk_08 != 0) {
        return -1;
    }
    if (D_800D6CA0.unk_00 == 1) {
        gCourseEditHighlightedIconIndex = -1;
        return -1;
    }
    if (gCourseEditHighlightedIconIndex == -1) {
        if ((gCourseEditCursorXPos < COURSE_EDIT_ICONS_X_POS) ||
            (gCourseEditCursorXPos >= COURSE_EDIT_ICONS_X_POS + COURSE_EDIT_NUM_ICONS * COURSE_EDIT_ICON_WIDTH)) {
            return gCourseEditHighlightedIconIndex;
        }
        if ((gCourseEditCursorYPos < COURSE_EDIT_ICONS_Y_POS) ||
            (gCourseEditCursorYPos >= COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT)) {
            return gCourseEditHighlightedIconIndex;
        }
        gCourseEditHighlightedIconIndex = (gCourseEditCursorXPos - COURSE_EDIT_ICONS_X_POS) / COURSE_EDIT_ICON_WIDTH;
        Audio_TriggerSystemSE(NA_SE_35);
    } else {
        highlightedIconXPos =
            (gCourseEditHighlightedIconIndex * COURSE_EDIT_ICON_WIDTH) + (COURSE_EDIT_ICONS_X_POS - 2);
        if ((gCourseEditCursorXPos >= highlightedIconXPos) &&
            (gCourseEditCursorXPos < (highlightedIconXPos + 2 + COURSE_EDIT_ICON_WIDTH + 2)) &&
            (gCourseEditCursorYPos >= COURSE_EDIT_ICONS_Y_POS - 2) &&
            (gCourseEditCursorYPos < COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT + 2)) {
            return gCourseEditHighlightedIconIndex;
        }
        if ((gCourseEditCursorXPos < COURSE_EDIT_ICONS_X_POS) ||
            (gCourseEditCursorXPos >= COURSE_EDIT_ICONS_X_POS + COURSE_EDIT_NUM_ICONS * COURSE_EDIT_ICON_WIDTH)) {
            gCourseEditHighlightedIconIndex = -1;
            return -1;
        }
        if ((gCourseEditCursorYPos < COURSE_EDIT_ICONS_Y_POS) ||
            (gCourseEditCursorYPos >= COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT)) {
            gCourseEditHighlightedIconIndex = -1;
            return -1;
        }
        Audio_TriggerSystemSE(NA_SE_35);
        gCourseEditHighlightedIconIndex = (gCourseEditCursorXPos - COURSE_EDIT_ICONS_X_POS) / COURSE_EDIT_ICON_WIDTH;
    }
    return gCourseEditHighlightedIconIndex;
}

void CourseEdit_DrawIcons(Gfx** gfxP) {
    Gfx* gfx;
    s32 highlightLeft;
    s32 i;
    s32 left;
    s32 highlightedIconIndex;

    gfx = *gfxP;
    if (D_xk2_80119918 != 0) {
        return;
    }

    gSPDisplayList(gfx++, D_8014940);

    left = COURSE_EDIT_ICONS_X_POS;
    for (i = 0; i < 4; i++, left += COURSE_EDIT_ICON_WIDTH) {
        gDPLoadTextureBlock(gfx++, gCourseEditIconTextures[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, COURSE_EDIT_ICON_WIDTH,
                            COURSE_EDIT_ICON_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, COURSE_EDIT_ICONS_Y_POS << 2, (left + COURSE_EDIT_ICON_WIDTH) << 2,
                            (COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    highlightedIconIndex = gCourseEditHighlightedIconIndex;
    if ((highlightedIconIndex >= 0) && (highlightedIconIndex < 4)) {
        highlightLeft = (highlightedIconIndex * COURSE_EDIT_ICON_WIDTH) + COURSE_EDIT_ICONS_X_POS;
        gDPLoadTextureBlock(gfx++, gCourseEditIconTextures[highlightedIconIndex], G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            COURSE_EDIT_ICON_WIDTH, COURSE_EDIT_ICON_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, (highlightLeft - 2) << 2, (COURSE_EDIT_ICONS_Y_POS - 2) << 2,
                            (highlightLeft + COURSE_EDIT_ICON_WIDTH + 2) << 2,
                            (COURSE_EDIT_ICONS_Y_POS + COURSE_EDIT_ICON_HEIGHT + 2) << 2, 0, 0, 0, (1 << 10) * 4 / 5,
                            (1 << 10) * 4 / 5);
    }
    *gfxP = gfx;
}

void func_xk2_800EA028(Gfx** gfxP, s32 left, s32 top, s32 width, s32 height) {
    Gfx* gfx;
    s32 pad[4];

    gfx = *gfxP;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureTile(gfx++, aCourseEditInfoBackgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 24, 8, 16, 8, 16, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + 4) << 2, (top + 4) << 2, (left + width - 4) << 2, (top + height - 4) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);

    *gfxP = gfx;
}

Gfx* func_xk2_800EA248(Gfx* gfx) {
    s32 sp7C;
    s32 sp78;
    s32 pad[2];
    Vec3f sp64;
    s32 pad2[11];

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }
    if (gInCourseEditTestRun) {
        return gfx;
    }
    sp64 = D_802CB6D0.unk_0000[1].pos;

    if (func_xk2_800EF090(sp64, &sp7C, &sp78) != 0) {
        return gfx;
    }
    sp7C -= 12;
    sp78 -= 12;
    gSPDisplayList(gfx++, D_9014CB8);

    gSPTextureRectangle(gfx++, sp7C << 2, sp78 << 2, (sp7C + 24) << 2, (sp78 + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern s32 D_xk2_80103F10;

Gfx* func_xk2_800EA3B0(Gfx* gfx) {

    if (D_800D6CA0.unk_08 != 3) {
        return gfx;
    }
    if (D_80119880 == 5) {
        gSPDisplayList(gfx++, D_8014940);
        func_xk1_8002AF1C(&gfx, 0xD0, 0x48, 0xA, 3);
        if (1) {}
        gDPPipeSync(gfx++);
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);

        D_xk1_80032AD0 = 0;
        gfx = func_xk1_8002924C(gfx, 0xD8, 0x50, "  %c%c%c%d", 0xBA, 0xB0, 0xBD, D_xk2_80103F10 + 1);
    }
    gfx = func_xk1_8002B17C(gfx, 8);

    return gfx;
}

extern Gfx D_3000400[];

Lights2 D_xk2_800F7208 = gdSPDefLights2(64, 64, 64, 255, 255, 255, 0, 0, 120, 255, 255, 255, 0, 0, 120);

Gfx* func_xk2_800EA4E4(Gfx* gfx) {
    static s32 D_xk2_800F7230 = 0;
    static f32 D_xk2_800F7234 = 0.0f;
    CourseSegment* temp_a0;
    f32 temp_fs0;
    f32 spDC;
    f32 var_fs0;
    f32 temp_fv1;
    Vec3f spC8;
    Vec3f spBC;
    Mtx3F sp98;
    s32 pad;

    if (D_802CB6D0.controlPointCount < 4) {
        return gfx;
    }
    if (D_800D6CA0.unk_20 != -1) {
        return gfx;
    }
    if (gInCourseEditTestRun) {
        return gfx;
    }

    if (D_xk2_800F7230 >= D_802CB6D0.controlPointCount) {
        D_xk2_800F7230 = 0;
        D_xk2_800F7234 = 0.0f;
    }
    temp_a0 = &D_802CB6D0.unk_0000[D_xk2_800F7230];

    temp_fs0 = Course_SplineGetLengthInfo(temp_a0, D_xk2_800F7234, &spDC);
    Course_SplineGetPosition(temp_a0, D_xk2_800F7234, &spC8);
    Course_SplineGetBasis(temp_a0, D_xk2_800F7234, &sp98, temp_fs0);
    Matrix_SetLockedLookAt(&D_80128C94->unk_0100, NULL, 1.0f, 1.0f, 1.0f, sp98.x.x, sp98.x.y, sp98.x.z, sp98.y.x,
                           sp98.y.y, sp98.y.z, spC8.x, spC8.y, spC8.z);
    Course_SplineGetTangent(temp_a0, D_xk2_800F7234, &spBC);
    var_fs0 = 250.0f;

    while (true) {
        temp_fv1 = var_fs0 / Course_SplineGetTangent(temp_a0, D_xk2_800F7234, &spBC);
        if (temp_fv1 < 1.0f) {
            break;
        }
        var_fs0 /= temp_fv1 + 1;
    }
    D_xk2_800F7234 += temp_fv1;
    if (D_xk2_800F7234 >= 1.0f) {
        D_xk2_800F7230++;
        D_xk2_800F7234 -= 1.0f;
    }

    gSPLoadUcodeL(gfx++, gspF3DLX2_Rej_fifo);
    func_xk2_800E1FC0(&gfx);
    gSPMatrix(gfx++, &D_6000000.unk_0100, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_3000400);

    gSPSetLights2(gfx++, D_xk2_800F7208);

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);

    gfx = func_8072DF40(gfx, D_xk2_800F7060, D_xk2_800F7064);
    gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
    func_xk2_800E1FC0(&gfx);
    return gfx;
}

void func_xk2_800EA8E8(Gfx** gfxP) {
    s32 pad[3];
    Gfx* gfx;

    if (D_800D6CA0.unk_08 != 0x11) {
        return;
    }
    gfx = *gfxP;
    func_xk2_800EECD4(&gfx, 0, 0x48, D_xk1_800331F0[18], 18);
    *gfxP = gfx;
}

void func_xk2_800EA948(Gfx** gfxP) {
    s32 pad[3];
    Gfx* gfx;

    if (D_800D6CA0.unk_08 != 0x23) {
        return;
    }
    gfx = *gfxP;
    func_xk2_800EECD4(&gfx, 0, 0x48, D_xk1_800331F0[23], 23);
    *gfxP = gfx;
}
