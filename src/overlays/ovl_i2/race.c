#include "global.h"
#include "fzx_course.h"
#include "fzx_camera.h"
#include ASSET_HEADER(machine_custom_gfx.h)

extern s8 gGamePaused;

s32 D_i2_80106F10 = 0;

u8 D_i2_80106F14[] = { BGM_MUTE_CITY,  BGM_SILENCE,    BGM_SAND_OCEAN, BGM_DEVILS_FOREST, BGM_BIG_BLUE,
                       BGM_PORT_TOWN,  BGM_SECTOR,     BGM_RED_CANYON, BGM_DEVILS_FOREST, BGM_MUTE_CITY,
                       BGM_BIG_BLUE,   BGM_WHITE_LAND, BGM_SAND_OCEAN, BGM_SILENCE,       BGM_SECTOR,
                       BGM_RED_CANYON, BGM_WHITE_LAND, BGM_MUTE_CITY,  BGM_SECTOR,        BGM_DEVILS_FOREST,
                       BGM_RED_CANYON, BGM_SAND_OCEAN, BGM_PORT_TOWN,  BGM_WHITE_LAND,    BGM_MUTE_CITY,
                       BGM_PORT_TOWN,  BGM_BIG_BLUE,   BGM_SAND_OCEAN, BGM_DEVILS_FOREST, BGM_WHITE_LAND,
                       BGM_SECTOR,     BGM_RED_CANYON, BGM_SAND_OCEAN, BGM_SILENCE,       BGM_MUTE_CITY,
                       BGM_MUTE_CITY };

void func_i2_80103A70(void) {
    func_i3_8012F324();
    Controller_Reset();
    Racer_Init();
    Camera_Init();
    Effects_Init();
    func_8006D414();
    gGamePaused = false;
    Menus_Init();
    Hud_ResetLivesChangeCounter();
    Hud_InitRacePortraits();
}

extern s16 D_800CCFE8;

void Race_Init(void) {
    D_800CCFE8 = D_i2_80106F10 = 3;
    gGamePaused = false;
    Course_Init();
    func_i3_80116C4C();
    Racer_Init();
    Camera_Init();
    func_8007F4E0(COURSE_CONTEXT()->courseData.venue, COURSE_CONTEXT()->courseData.skybox);
    Background_Init();
    Effects_Init();
    Course_LandminesViewInteractDataInit();
    Course_JumpsViewInteractDataInit();
    Course_DecorationsViewInteractDataInit();
    Course_EffectsViewInteractDataInit(false);
    func_i3_8012F324();
    Minimap_InitCourseMinimap();
    Menus_Init();
    Hud_InitRacePortraits();
}

extern s32 gGameMode;

s32 Race_Update(void) {
    Menus_Update();
    Effects_Update();
    Racer_Update();
    Camera_Update();
    Background_Update();
    Course_Update();
    func_80074844();

    return gGameMode;
}

extern s32 D_800DCCFC;
extern s32 D_800DCD04;
extern Vtx* gEffectsVtxPtr;
extern Vtx* gEffectsVtxEndPtr;
extern Vtx* gCourseVtxPtr;
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;
extern Camera gCameras[];
extern FrameBuffer* gFrameBuffers[];
extern s16 D_800CCFE4;
extern s32 gNumPlayers;

Gfx* Race_Draw(Gfx* gfx) {

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
                             OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCCFC]));
        } else {
            gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                             OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
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
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCCFC]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    }
    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gEffectsVtxPtr = gGfxPool->effectsVtxBuffer;
    gEffectsVtxEndPtr = &gGfxPool->effectsVtxBuffer[0x7FF];
    switch (gNumPlayers) {
        case 1:
            gfx = Background_Draw(gfx, 0, SCISSOR_BOX_FULL_SCREEN);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            break;
        case 2:
            gfx = Background_Draw(gfx, 0, SCISSOR_BOX_TOP_HALF);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            gfx = Background_Draw(gfx, 1, SCISSOR_BOX_BOTTOM_HALF);
            gfx = Course_Draw(gfx, 1);
            gfx = Course_GadgetsDraw(gfx, 1);
            break;
        case 3:
            gfx = Background_Draw(gfx, 0, SCISSOR_BOX_TOP_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            gfx = Background_Draw(gfx, 1, SCISSOR_BOX_BOTTOM_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 1);
            gfx = Course_GadgetsDraw(gfx, 1);
            gfx = Background_Draw(gfx, 2, SCISSOR_BOX_TOP_RIGHT_QUARTER);
            gfx = Course_Draw(gfx, 2);
            gfx = Course_GadgetsDraw(gfx, 2);
            break;
        case 4:
            gfx = Background_Draw(gfx, 0, SCISSOR_BOX_TOP_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            gfx = Background_Draw(gfx, 1, SCISSOR_BOX_BOTTOM_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 1);
            gfx = Course_GadgetsDraw(gfx, 1);
            gfx = Background_Draw(gfx, 2, SCISSOR_BOX_TOP_RIGHT_QUARTER);
            gfx = Course_Draw(gfx, 2);
            gfx = Course_GadgetsDraw(gfx, 2);
            gfx = Background_Draw(gfx, 3, SCISSOR_BOX_BOTTOM_RIGHT_QUARTER);
            gfx = Course_Draw(gfx, 3);
            gfx = Course_GadgetsDraw(gfx, 3);
            break;
    }

    gSPLoadUcodeL(gfx++, gspF3DFLX2_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gDPPipeSync(gfx++);

    if (D_800CCFE4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCCFC]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    }

    switch (gNumPlayers) {
        case 1:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_FULL_SCREEN, 0);
            gfx = Racer_Draw(gfx, 0);
            gfx = Menus_Player1SpecialDraw(gfx, 0);
            break;
        case 2:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_HALF, 0);
            gfx = Racer_Draw(gfx, 0);
            gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_HALF, 1);
            gfx = Racer_Draw(gfx, 1);
            break;
        case 3:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_LEFT_QUARTER, 0);
            gfx = Racer_Draw(gfx, 0);
            gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_LEFT_QUARTER, 1);
            gfx = Racer_Draw(gfx, 1);
            gSPPerspNormalize(gfx++, gCameras[2].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_RIGHT_QUARTER, 2);
            gfx = Racer_Draw(gfx, 2);
            break;
        case 4:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_LEFT_QUARTER, 0);
            gfx = Racer_Draw(gfx, 0);
            gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_LEFT_QUARTER, 1);
            gfx = Racer_Draw(gfx, 1);
            gSPPerspNormalize(gfx++, gCameras[2].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_RIGHT_QUARTER, 2);
            gfx = Racer_Draw(gfx, 2);
            gSPPerspNormalize(gfx++, gCameras[3].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_20208[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_RIGHT_QUARTER, 3);
            gfx = Racer_Draw(gfx, 3);
            break;
    }

    return Menus_Draw(gfx);
}
