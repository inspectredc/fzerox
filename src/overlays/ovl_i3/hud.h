#ifndef HUD_H
#define HUD_H

#include "gfx.h"

typedef struct unk_8012F450 {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 hours;
    /* 0x05 */ u8 minutes;
    /* 0x08 */ f32 minuteFraction;
} unk_8012F450; // size = 0xC

typedef struct unk_80141EA8 {
    s32 unk_00;
    s32 lapFlashTimer;
    s32 lapIntervalCounter;
    unk_8012F450 unk_0C;
    s8 unk_18[0x30];
} unk_80141EA8; // size = 0x48

extern TexturePtr gCharacterPortraitTextures[];
extern s32 gPlayerLapNumbers[];
extern unk_80141EA8 D_i3_80141EA8[];

Gfx* Hud_DrawRaceTimeInterval(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale);
Gfx* Hud_DrawBlankTimeHundredths(Gfx* gfx, s32 left, s32 top);
Gfx* Hud_DrawBlankTimeThousandths(Gfx* gfx, s32 left, s32 top);

Gfx* Hud_UpdateRaceIntervalInfo(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex, f32 scale);
Gfx* Hud_DrawReverse(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* Hud_DrawKOStars(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* Hud_DrawPlayerLives(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* Hud_DrawPracticeBestLap(Gfx* gfx);
Gfx* Hud_DrawDeathRaceTimer(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* Hud_DrawDeathRaceBest(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* Hud_DrawDeathRaceBestTime(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);

void Hud_UpdateCharacterPortraits(void);

#endif // HUD_H
