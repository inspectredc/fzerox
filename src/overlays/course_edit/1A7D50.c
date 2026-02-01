#include "global.h"
#include "fzx_font.h"
#include ASSET_HEADER(common_assets_compressed.h)

s32 D_xk2_8013A7E0;
s32 D_xk2_8013A7E4;

void func_xk2_800F6290(void) {
    func_80078104(aMenuTextTLUT, 0x200, 0, 0, 0);
    func_80078104(aMenuQuitTex, 0x200, 0, 1, 0);
    func_80078104(aMenuContinueTex, 0x400, 0, 1, 0);
    Font_LoadString("Ｍ", 5);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZＡＢ23", 6);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3);
}

extern s16 sMenuIsBusy;

void func_xk2_800F632C(void) {
    D_xk2_8013A7E4 = 60;
    D_xk2_8013A7E0 = 0;
    sMenuIsBusy = 0;
}

extern s8 gGamePaused;
extern Gfx D_4011D78[];

Gfx* func_xk2_800F634C(Gfx* gfx) {
    s32 pad[2];

    if (D_xk2_8013A7E4 > 0) {
        D_xk2_8013A7E4 -= 8;
    } else {
        D_xk2_8013A7E4 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_xk2_8013A7E4 + 100, D_xk2_8013A7E4 + 41, 0xE6 - D_xk2_8013A7E4,
                  0x85 - D_xk2_8013A7E4);

    gfx = Menus_DrawBeveledBox(gfx, 0x78, 0x3D, 0xD2, 0x71, 0, 0, 0, 0xDC);
    gSPDisplayList(gfx++, D_4011D78);

    gDPLoadTLUT_pal256(gfx++, func_800783AC(aMenuTextTLUT));

    gfx = Menus_SetOptionColor(gfx, D_xk2_8013A7E0);
    gfx = Menus_DrawRaceMenuTexture(gfx, 0xF, 0x8C, 0x50);
    gfx = Menus_SetOptionColor(gfx, D_xk2_8013A7E0 - 1);
    gfx = Menus_DrawRaceMenuTexture(gfx, 2, 0x8C, 0x5F);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gfx = func_8070D4A8(gfx, 0);
    gfx = Font_DrawScaledString(gfx, 0x7D, (D_xk2_8013A7E0 * 0xF) + 0x61, "Ｍ", 1, 5, 0, 0.8f, 0.8f);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 0xA6 - (Font_GetStringWidth("PAUSE", 6, 1) / 2), 0x4E, "PAUSE", 1, 6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    gfx = Font_DrawString(gfx, 0xA5 - (Font_GetStringWidth("PAUSE", 6, 1) / 2), 0x4D, "PAUSE", 1, 6, 0);
    if ((D_xk2_8013A7E4 == 0) && (sMenuIsBusy == 0)) {
        D_xk2_8013A7E0 = Menus_UpdateHighlightedOptionVertical(0, D_xk2_8013A7E0, 1);
        if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
            switch (D_xk2_8013A7E0) {
                case 0:
                    func_xk2_800EC8AC();
                    break;
                case 1:
                    func_xk2_800EC91C();
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
