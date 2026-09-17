#include "global.h"
#include "fzx_font.h"
#include "src/overlays/ovl_i3/menus.h"
#include ASSET_HEADER(common_assets_compressed.h)

s32 sCourseEditPauseMenuOptionIndex;
s32 sCourseEditPauseScissorBoxSize;

void CourseEdit_TestRunPauseMenuInit(void) {
    TextureCache_LoadAndCache(aMenuTextTLUT, 0x200, false, false, false);
    TextureCache_LoadAndCache(aMenuQuitTex, 0x200, false, true, false);
    TextureCache_LoadAndCache(aMenuContinueTex, 0x400, false, true, false);
    Font_LoadString("Ｍ", 5);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZＡＢ23", 6);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3);
}

extern s16 sMenuIsBusy;

void CourseEdit_TestRunPauseMenuStart(void) {
    sCourseEditPauseScissorBoxSize = 60;
    sCourseEditPauseMenuOptionIndex = 0;
    sMenuIsBusy = 0;
}

extern s8 gGamePaused;
extern Gfx D_4011D78[];

Gfx* CourseEdit_TestRunPauseMenuDraw(Gfx* gfx) {
    s32 pad[2];

    if (sCourseEditPauseScissorBoxSize > 0) {
        sCourseEditPauseScissorBoxSize -= 8;
    } else {
        sCourseEditPauseScissorBoxSize = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, sCourseEditPauseScissorBoxSize + 100, sCourseEditPauseScissorBoxSize + 41,
                  230 - sCourseEditPauseScissorBoxSize, 133 - sCourseEditPauseScissorBoxSize);

    gfx = Menus_DrawBeveledBox(gfx, 120, 61, 210, 113, 0, 0, 0, 220);
    gSPDisplayList(gfx++, D_4011D78);

    gDPLoadTLUT_pal256(gfx++, TextureCache_GetCached(aMenuTextTLUT));

    gfx = Menus_SetOptionColor(gfx, sCourseEditPauseMenuOptionIndex);
    gfx = Menus_DrawRaceMenuTexture(gfx, 15, 140, 80);
    gfx = Menus_SetOptionColor(gfx, sCourseEditPauseMenuOptionIndex - 1);
    gfx = Menus_DrawRaceMenuTexture(gfx, 2, 140, 95);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8007DB28(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 125, (sCourseEditPauseMenuOptionIndex * 15) + 97, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 166 - (Font_GetStringWidth("PAUSE", 6, 1) / 2), 78, "PAUSE", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    gfx = Font_DrawString(gfx, 165 - (Font_GetStringWidth("PAUSE", 6, 1) / 2), 77, "PAUSE", 1, 6, 0);
    if ((sCourseEditPauseScissorBoxSize == 0) && (sMenuIsBusy == 0)) {
        sCourseEditPauseMenuOptionIndex = Menus_UpdateHighlightedOptionVertical(0, sCourseEditPauseMenuOptionIndex, 1);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
            switch (sCourseEditPauseMenuOptionIndex) {
                case 0:
                    CourseEdit_UnpauseTestRun();
                    break;
                case 1:
                    CourseEdit_ExitTestRun();
                    break;
            }
        }
        if ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) &&
            !(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
            gGamePaused = false;
            Audio_TriggerSystemSE(NA_SE_12);
            Audio_PauseSet(AUDIO_PAUSE_UNPAUSED);
        }
    }
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

    return gfx;
}
