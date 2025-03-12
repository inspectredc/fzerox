#include "global.h"
#include "fzx_game.h"
#include "fzx_hud.h"
#include "fzx_racer.h"
#include "ovl_i3.h"
#include "assets/segment_17B960.h"
#include "assets/segment_1B8550.h"
#include "assets/segment_2747F0.h"
#include "assets/segment_2B9EA0.h"
#include "segment_symbols.h"

f32 sPortraitTextureScale[TOTAL_RACER_COUNT];
unk_80141EA8 D_i3_80141EA8[4];
s32 sPlayerLeadInterval[4];
s32 sLeadRivalRaceTime[4];

s32 sPracticeBestLapCounter = 0;
bool sSecondLapStarted = false;
bool sFinalLapStarted = false;
s32 D_i3_8013EFFC = 180;
s32 D_i3_8013F000 = 3;
UNUSED s32 D_i3_8013F004 = 0;

s32 gPlayerLapNumbers[] = { 1, 1, 1, 1 };

UNUSED s32 D_i3_8013F018 = 0;
UNUSED s32 D_i3_8013F01C = 0;

s32 D_i3_8013F020[6][3] = { 0 };

f32 sPositionScales[] = { 1.0f, 1.0f, 1.0f, 1.0f };

bool D_i3_8013F078[] = { false, false, false, false };

TexturePtr gCharacterPortraitTextures[] = {
    aPortraitCaptainFalconTex, // CAPTAIN_FALCON
    aPortraitDrStewartTex,     // DR_STEWART
    aPortraitPicoTex,          // PICO
    aPortraitSamuraiGorohTex,  // SAMURAI_GOROH
    aPortraitJodySummerTex,    // JODY_SUMMER
    aPortraitMightyGazelleTex, // MIGHTY_GAZELLE
    aPortraitMrEadTex,         // MR_EAD
    aPortraitBabaTex,          // BABA
    aPortraitOctomanTex,       // OCTOMAN
    aPortraitGomarAndShiohTex, // GOMAR_AND_SHIOH
    aPortraitKateAlenTex,      // KATE_ALEN
    aPortraitRogerBusterTex,   // ROGER_BUSTER
    aPortraitJamesMcCloudTex,  // JAMES_MCCLOUD
    aPortraitLeonTex,          // LEON
    aPortraitAntonioGusterTex, // ANTONIO_GUSTER
    aPortraitBlackShadowTex,   // BLACK_SHADOW
    aPortraitMichaelChainTex,  // MICHAEL_CHAIN
    aPortraitJackLevinTex,     // JACK_LEVIN
    aPortraitSuperArrowTex,    // SUPER_ARROW
    aPortraitMrsArrowTex,      // MRS_ARROW
    aPortraitJohnTanakaTex,    // JOHN_TANAKA
    aPortraitBeastmanTex,      // BEASTMAN
    aPortraitZodaTex,          // ZODA
    aPortraitDrClashTex,       // DR_CLASH
    aPortraitSilverNeelsenTex, // SILVER_NEELSEN
    aPortraitBioRexTex,        // BIO_REX
    aPortraitDraqTex,          // DRAQ
    aPortraitBillyTex,         // BILLY
    aPortraitTheSkullTex,      // THE_SKULL
    aPortraitBloodFalconTex,   // BLOOD_FALCON
};

UNUSED u32 D_8013F100 = 0x2800;

TexturePtr sPositionTextures[] = {
    aPortraitPositionFirstTex,  aPortraitPositionSecondTex, aPortraitPositionThirdTex,
    aPortraitPositionFourthTex, aPortraitPositionFifthTex,  aPortraitPositionSixthTex,
};

s32 sPlayerTimerPositions[][4][2] = {
    { { 230, 38 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 0, 0 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 168, 132 } },
};

s32 sPlayerTimePositions[][4][2] = {
    { { 198, 38 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 100, 20 }, { 100, 132 }, { 0, 0 }, { 0, 0 } },
    { { 26, 20 }, { 26, 132 }, { 164, 20 }, { 0, 0 } },
    { { 26, 20 }, { 26, 132 }, { 164, 20 }, { 164, 132 } },
};

s32 sPreviousLapTimes[] = { 0, 0, 0, 0 };

u32 sEnergyBarFillColors[] = {
    (GPACK_RGBA5551(155, 0, 0, 1) << 16 | GPACK_RGBA5551(155, 0, 0, 1)),
    (GPACK_RGBA5551(220, 0, 0, 1) << 16 | GPACK_RGBA5551(220, 0, 0, 1)),
    (GPACK_RGBA5551(255, 0, 0, 1) << 16 | GPACK_RGBA5551(255, 0, 0, 1)),
    (GPACK_RGBA5551(220, 0, 0, 1) << 16 | GPACK_RGBA5551(230, 0, 0, 1)),
    (GPACK_RGBA5551(155, 0, 0, 1) << 16 | GPACK_RGBA5551(155, 0, 0, 1)),
    (GPACK_RGBA5551(0, 255, 0, 1) << 16 | GPACK_RGBA5551(0, 255, 0, 1)),
    (GPACK_RGBA5551(0, 255, 20, 1) << 16 | GPACK_RGBA5551(0, 255, 20, 1)),
    (GPACK_RGBA5551(0, 195, 35, 1) << 16 | GPACK_RGBA5551(0, 195, 35, 1)),
    (GPACK_RGBA5551(0, 160, 50, 1) << 16 | GPACK_RGBA5551(0, 160, 50, 1)),
    (GPACK_RGBA5551(0, 135, 70, 1) << 16 | GPACK_RGBA5551(0, 135, 70, 1)),
};

s32 sEnergyOutlinePositions[][4][2] = {
    { { 220, 20 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 224, 20 }, { 224, 132 }, { 0, 0 }, { 0, 0 } },
    { { 96, 20 }, { 96, 132 }, { 240, 20 }, { 0, 0 } },
    { { 96, 20 }, { 96, 132 }, { 240, 20 }, { 240, 132 } },
};

s32 sEnergyBarPositions[][4][2] = {
    { { 222, 28 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 226, 28 }, { 226, 140 }, { 0, 0 }, { 0, 0 } },
    { { 98, 26 }, { 98, 138 }, { 242, 26 }, { 0, 0 } },
    { { 98, 26 }, { 98, 138 }, { 242, 26 }, { 242, 138 } },
};

s32 sSpeedPositions[][4][2] = {
    { { 226, 204 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 226, 92 }, { 226, 204 }, { 0, 0 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 0, 0 } },
    { { 24, 20 }, { 24, 132 }, { 168, 20 }, { 168, 132 } },
};

s32 sPositionPositions[][4][2] = {
    { { 118, 20 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -4, 76 }, { -4, 188 }, { 0, 0 }, { 0, 0 } },
    { { 4, 84 }, { 4, 196 }, { 146, 84 }, { 0, 0 } },
    { { 4, 84 }, { 4, 196 }, { 146, 84 }, { 146, 196 } },
};

s32 sLapPositions[][4][2] = {
    { { 66, 20 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 24, 40 }, { 24, 152 }, { 0, 0 }, { 0, 0 } },
    { { 130, 87 }, { 130, 199 }, { 272, 87 }, { 0, 0 } },
    { { 130, 87 }, { 130, 199 }, { 272, 87 }, { 272, 199 } },
};

s32 sPortraitYPosOffsets[] = { 18, 56, 94, 132, 162, 192 };

s32 sPortraitPositionYPos[] = { 50, 88, 126, 156, 186, 216 };

s32 sIntervalPositions[][4][2] = {
    { { 120, 72 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 120, 20 }, { 120, 132 }, { 0, 0 }, { 0, 0 } },
    { { 48, 40 }, { 48, 152 }, { 196, 40 }, { 0, 0 } },
    { { 48, 40 }, { 48, 152 }, { 196, 40 }, { 196, 152 } },
};

s32 sReversePositions[][4][2] = {
    { { 104, 64 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 104, 20 }, { 104, 132 }, { 0, 0 }, { 0, 0 } },
    { { 44, 40 }, { 44, 152 }, { 188, 40 }, { 0, 0 } },
    { { 44, 40 }, { 44, 152 }, { 188, 40 }, { 188, 152 } },
};

s32 sLivesPositions[][4][2] = {
    { { 68, 48 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
};

s32 sPortraitReplacementIndexes[] = {
    0, // CAPTAIN_FALCON
    0, // DR_STEWART
    0, // PICO
    1, // SAMURAI_GOROH
    2, // JODY_SUMMER
    0, // MIGHTY_GAZELLE
    0, // MR_EAD
    0, // BABA
    0, // OCTOMAN
    0, // GOMAR_AND_SHIOH
    0, // KATE_ALEN
    0, // ROGER_BUSTER
    0, // JAMES_MCCLOUD
    0, // LEON
    0, // ANTONIO_GUSTER
    0, // BLACK_SHADOW
    0, // MICHAEL_CHAIN
    0, // JACK_LEVIN
    0, // SUPER_ARROW
    0, // MRS_ARROW
    0, // JOHN_TANAKA
    0, // BEASTMAN
    0, // ZODA
    0, // DR_CLASH
    0, // SILVER_NEELSEN
    0, // BIO_REX
    0, // DRAQ
    0, // BILLY
    0, // THE_SKULL
    0, // BLOOD_FALCON
};

Gfx* func_i3_DrawTimerDigitRectangle(Gfx* gfx, s32 left, s32 top, s32 number, f32 scale) {

    if (number >= 15) {
        return gfx;
    }

    gSPTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 8.0f) << 2, (s32) (top + 16.0f * scale) << 2, 0, 0,
                        (number * 16) << 5, 1 << 10, (s32) (1024.0f / scale));
    return gfx;
}

Gfx* func_i3_DrawTimerDigitScisRectangle(Gfx* gfx, s32 left, s32 top, s32 number, f32 scale) {

    if (number >= 15) {
        return gfx;
    }

    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 8.0f * scale) << 2,
                            (s32) (top + 16.0f * scale) << 2, 0, 0, (number * 16) << 5, (s32) (1024.0f / scale),
                            (s32) (1024.0f / scale));
    return gfx;
}

extern s32 gGameMode;

void func_i3_8012F324(void) {
    s32 i;

    sPracticeBestLapCounter = 0;
    sSecondLapStarted = false;
    sFinalLapStarted = false;

    func_80078104(aBestTex, TEX_SIZE(aBestTex, sizeof(u16)), 0, 0, 0);

    if (gGameMode == GAMEMODE_PRACTICE) {
        D_i3_8013EFFC = 360;
    } else {
        D_i3_8013EFFC = 180;
    }

    for (i = 0; i < 4; i++) {
        D_i3_80141EA8[i].unk_00 = 0;
        D_i3_80141EA8[i].unk_04 = 0;
        D_i3_80141EA8[i].lapIntervalCounter = 0;
        D_i3_80141EA8[i].unk_0C.time = 0;

        sPositionScales[i] = 1.0f;
        gPlayerLapNumbers[i] = 1;
    }
}

void func_i3_8012F450(unk_8012F450* arg0) {

    if (arg0->time < 360000) {
        arg0->time++;
    }

    arg0->hours = arg0->time / 3600;
    arg0->minutes = (arg0->time / 60) % 60;
    arg0->minuteFraction = (arg0->time % 60) / 60.0f;

    if (arg0->hours >= 100) {
        arg0->minuteFraction = 0.99f;
        arg0->minutes = 60 - 1;
        arg0->hours = 100 - 1;
    }
}

Gfx* func_i3_DrawTimerScisThousandths(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale) {
    s32 offset = 0;
    s32 timeField;

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }

    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, 0, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8.0f * scale;
    } else {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8.0f * scale;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);
    offset += 8.0f * scale;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, 0, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8.0f * scale;
    } else {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8.0f * scale;
    }

    time -= timeField * 1000;
    timeField = time / 100;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);
    offset += 8.0f * scale;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
    offset += 8.0f * scale;

    time -= timeField * 100;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
    offset += 8.0f * scale;

    time -= timeField * 10;

    return func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, time, scale);
}

Gfx* func_i3_DrawBlankTimeHundredths(Gfx* gfx, s32 left, s32 top) {
    s32 offset = 0;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    return func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
}

Gfx* func_i3_DrawBlankTimeThousandths(Gfx* gfx, s32 left, s32 top) {
    s32 offset = 0;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    return func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
}

Gfx* func_i3_DrawPlayerTimer(Gfx* gfx, s32 time, s32 numPlayersIndex, s32 playerIndex) {
    UNUSED s32 pad;
    s32 top;
    s32 left;
    s32 offset = 0;
    s32 timeField;
    f32 scale;

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }

    left = sPlayerTimerPositions[numPlayersIndex][playerIndex][0];
    top = sPlayerTimerPositions[numPlayersIndex][playerIndex][1];

    switch (numPlayersIndex) {
        case 0:
        case 1:
            scale = 1.0f;
            break;
        case 2:
        case 3:
            scale = 0.75f;
            break;
    }

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }

    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);

    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 1000;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
    }
    return gfx;
}

extern Gfx D_80149D0[];

Gfx* func_i3_DrawTimeRectangle(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 right;
    s32 left;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }

    left = sPlayerTimePositions[numPlayersIndex][playerIndex][0];
    right = sPlayerTimePositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_80149D0);
    gSPTextureRectangle(gfx++, left << 2, right << 2, (left + 23) << 2, (right + 15) << 2, 0, 0, 0, 1 << 12, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

extern s32 gTotalLapCount;
extern s16 D_800E5FBC;
extern s16 D_800E5FD0;
extern s8 D_800DCE5C;

Gfx* func_i3_UpdatePlayerHudInfo(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    UNUSED s32 pad[2];
    s32 lap;
    bool newLap;

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    lap = gRacers[playerIndex].lap;
    newLap = false;

    if (gGameMode == GAMEMODE_PRACTICE) {
        if (gRacers[playerIndex].startNewPracticeLap) {
            newLap = true;
        }
    } else if (gPlayerLapNumbers[playerIndex] < lap) {
        newLap = true;
    }

    if (newLap) {
        gRacers[playerIndex].startNewPracticeLap = false;
        gPlayerLapNumbers[playerIndex] = lap;

        D_i3_80141EA8[playerIndex].unk_04 = D_i3_8013EFFC;
        if ((gRacers[playerIndex].position != 1) || (gGameMode == GAMEMODE_TIME_ATTACK)) {
            D_i3_80141EA8[playerIndex].lapIntervalCounter = 90;
        }
        if ((lap == 2) && !sSecondLapStarted && (D_800E5FD0 != 0) && (gGameMode != GAMEMODE_PRACTICE)) {
            func_800BA8D8(0x11);
            sSecondLapStarted = true;
        }
        if ((lap == gTotalLapCount) && !sFinalLapStarted && (D_800E5FD0 != 0) && (gGameMode != GAMEMODE_PRACTICE)) {
            func_800BA8D8(0x12);
            sFinalLapStarted = true;
        }
    }

    if (D_i3_8013EFFC == D_i3_80141EA8[playerIndex].unk_04) {
        sPreviousLapTimes[playerIndex] = gRacers[playerIndex].lapTimes[(lap + 1) % 3];
    }

    func_i3_8012F450(&D_i3_80141EA8[playerIndex].unk_0C);

    if (D_i3_80141EA8[playerIndex].unk_04 > 0) {
        if (D_800DCE5C == 0) {
            D_i3_80141EA8[playerIndex].unk_04--;
        }
        if ((D_i3_80141EA8[playerIndex].unk_04 % 20) >= 5) {
            if ((numPlayersIndex != 0) && (D_800E5FBC != 0) && (gRacers[playerIndex].position != 1)) {
                return gfx;
            }

            gfx = func_i3_DrawPlayerTimer(gfx, sPreviousLapTimes[playerIndex] + 5, numPlayersIndex, playerIndex);
        }
    } else if (numPlayersIndex < 2) {
        if (gGameMode == GAMEMODE_PRACTICE) {
            return gfx;
        }
        if ((numPlayersIndex == 1) && (D_800E5FBC != 0)) {
            return gfx;
        }

        gfx = func_i3_DrawPlayerTimer(gfx, gRacers[playerIndex].raceTime + 5, numPlayersIndex, playerIndex);
    }
    return gfx;
}

extern Gfx D_80149A0[];

Gfx* func_i3_DrawEnergyBar(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    s32 energyWidth;
    s32 left;
    s32 top;
    s32 height;
    f32 scale;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }

    left = sEnergyBarPositions[numPlayersIndex][playerIndex][0];
    top = sEnergyBarPositions[numPlayersIndex][playerIndex][1];

    switch (numPlayersIndex) {
        case 0:
        case 1:
            height = 5;
            scale = 1.0f;
            break;
        case 2:
        case 3:
            height = 3;
            top++;
            scale = 0.75f;
            break;
    }

    energyWidth = Math_Round((gRacers[playerIndex].energy / gRacers[playerIndex].maxEnergy) * 68.0f * scale);

    gSPDisplayList(gfx++, D_80149A0);

    for (i = 0; i < height; i++) {
        gDPPipeSync(gfx++);
        if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_100000) {
            gDPSetFillColor(gfx++, sEnergyBarFillColors[i + 5]);
        } else {
            gDPSetFillColor(gfx++, sEnergyBarFillColors[i]);
        }

        gDPFillRectangle(gfx++, left, top + i, left + energyWidth - 1, top + i);
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

Gfx* func_i3_DrawEnergyOutlineRectangle(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    UNUSED s32 pad;
    s32 top;
    s32 left;
    s32 width;
    s32 height;
    f32 scale;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_80149D0);

    left = sEnergyOutlinePositions[numPlayersIndex][playerIndex][0];
    top = sEnergyOutlinePositions[numPlayersIndex][playerIndex][1];

    switch (numPlayersIndex) {
        case 0:
        case 1:
            scale = 1.0f;
            width = 71.0f * scale;
            height = 15.0f * scale;
            break;
        case 2:
        case 3:
            scale = 0.75f;
            width = 72.0f * scale;
            height = 16.0f * scale;
            break;
    }

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0,
                        (s32) ((1 << 12) / scale), (s32) ((1 << 10) / scale));

    return gfx;
}

extern Gfx D_80149A0[];

Gfx* func_i3_DrawPlayerSpeed(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    s32 left;
    s32 top;
    s32 height;
    s32 digit;
    s32 speedRemainder;
    s32 speed;
    s32 digitMask;
    f32 heightScale;

    if ((numPlayersIndex >= 2) && (D_i3_80141EA8[playerIndex].unk_04 != 0)) {
        return gfx;
    }

    switch (numPlayersIndex) {
        case 0:
        case 1:
            heightScale = 1.0f;
            height = 15;
            break;
        case 2:
        case 3:
            heightScale = 0.75f;
            height = 16.0f * heightScale;
            break;
    }

    digitMask = 1000;
    speedRemainder = speed = Math_Round(gRacers[playerIndex].speed * 21.6f);
    left = sSpeedPositions[numPlayersIndex][playerIndex][0];
    top = sSpeedPositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

    gDPFillRectangle(gfx++, left + 12, top, left + 35, top + height);

    gSPDisplayList(gfx++, D_80149D0);

    gDPLoadTextureBlock(gfx++, D_303B270, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 4; i++) {
        digit = speedRemainder / digitMask;
        if ((i != 3) && (digit == 0) && (speed == speedRemainder)) {
            speedRemainder %= digitMask;
            digitMask /= 10;
        } else {
            gSPTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 11) << 2,
                                (top + height) << 2, 0, 0, (digit * 16) << 5, 1 << 12, (s32) ((1 << 10) / heightScale));
            speedRemainder %= digitMask;
            digitMask /= 10;
        }
    }

    gDPLoadTextureBlock(gfx++, D_303C170, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 19) << 2, (top + height) << 2, 0, 0,
                        0, 1 << 12, (s32) ((1 << 10) / heightScale));

    return gfx;
}

extern s16 gCpuRacersRetired;
extern s32 gTotalRacers;

Gfx* func_i3_DrawRacePositionExtras(Gfx* gfx, s32 left, s32 top) {
    s32 i;
    s32 xOffset;
    s32 digit;
    s32 racersRemaining;
    s32 digitMask;
    f32 scale = 0.25f;

    digitMask = 10;
    racersRemaining = gTotalRacers - gCpuRacersRetired;

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        gDPPipeSync(gfx++);

        left -= 88;
        top += 16;

        gDPLoadTextureBlock(gfx++, aRacersLeftTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 32) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        return gfx;
    }

    gDPPipeSync(gfx++);

    top += 20;

    gDPLoadTextureBlock(gfx++, aTotalRacerDigitsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 132, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    // Draw /
    gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, ((left - 2) + 8) << 2, (top + 12) << 2, 0, 0, (10 * 12) << 5,
                        1 << 10, 1 << 10);

    xOffset = 28.0f * scale;

    left += 6;

    // Draw Remaining Racer Digits
    for (i = 0; i < 2; i++) {
        digit = racersRemaining / digitMask;
        if ((i == 0) && (digit == 0)) {
            left += xOffset;
            digitMask /= 10;
        } else {
            gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 8) << 2, (top + 12) << 2, 0, 0, (digit * 12) << 5,
                                1 << 10, 1 << 10);

            left += xOffset;
            racersRemaining %= digitMask;
            digitMask /= 10;
        }
    }

    return gfx;
}

Gfx* func_i3_DrawPositionSuffixRectangle(Gfx* gfx, s32 left, s32 top, f32 scale) {

    gSPTextureRectangle(gfx++, left << 2, (s32) (top + (12.0f * scale)) << 2, (s32) (left + (20.0f * scale)) << 2,
                        (s32) (top + (12.0f * scale) + (20.0f * scale)) << 2, 0, 0, 0, (s32) ((1 << 10) / scale),
                        (s32) ((1 << 10) / scale));

    return gfx;
}

extern Gfx D_8014940[];

Gfx* func_i3_DrawPosition(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    u8* positionTexturePtr;
    s32 positionDigit;
    f32 leftAdjustment;
    f32 scaleDiff;
    s32 positionSuffix;
    s32 top;
    s32 left;
    f32 scale;
    f32 baseScale;
    s32 digitMask;
    s32 position;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        return gfx;
    }

    if (gRacers[playerIndex].stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_RETIRED)) {
        sPositionScales[playerIndex] += 0.04f;
    }

    if (sPositionScales[playerIndex] > 1.5f) {
        sPositionScales[playerIndex] = 1.5f;
    }

    left = sPositionPositions[numPlayersIndex][playerIndex][0];
    top = sPositionPositions[numPlayersIndex][playerIndex][1];

    digitMask = 10;

    switch (numPlayersIndex) {
        case 0:
            sPositionScales[playerIndex] = 1.0f;
        /* fallthrough */
        case 1:
            baseScale = scale = 1.0f;
            break;
        case 2:
        case 3:
            baseScale = scale = 0.75f;
            break;
    }
    scale *= sPositionScales[playerIndex];

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        position = (gTotalRacers - gCpuRacersRetired) - 1;
    } else {
        position = gRacers[playerIndex].position;
    }

    if (numPlayersIndex != 0) {
        scaleDiff = scale - baseScale;
        leftAdjustment = (scaleDiff * 28.0f) / 2;
    } else {
        scaleDiff = scale - baseScale;
        leftAdjustment = scaleDiff * 28.0f;
    }

    switch (position) {
        case 1:
            positionSuffix = POSITION_SUFFIX_ST;
            break;
        case 2:
            positionSuffix = POSITION_SUFFIX_ND;
            break;
        case 3:
            positionSuffix = POSITION_SUFFIX_RD;
            break;
        default:
            positionSuffix = POSITION_SUFFIX_TH;
            break;
    }

    gSPDisplayList(gfx++, D_8014940);

    left -= leftAdjustment;
    top -= ((scaleDiff * 32.0f) / 2);

    positionTexturePtr = (u8*) aPositionDigitTexs;

    for (i = 0; i < 2; i++) {
        //! @bug the numPlayersIndex condition should be conditionally &&ed here
        if ((i == 0) & numPlayersIndex) {
            left += (s32) (28.0f * baseScale);
            position %= digitMask;
            digitMask /= 10;
        } else {
            positionDigit = position / digitMask;

            left += (i == 0 && positionDigit == 1) * 5;

            if ((i == 0) && (positionDigit == 0)) {
                left += (s32) (28.0f * scale);
                position %= digitMask;
                digitMask /= 10;
            } else {
                gDPPipeSync(gfx++);

                gDPLoadTextureBlock(gfx++, positionTexturePtr + ((positionDigit * 0x380) << 1), G_IM_FMT_RGBA,
                                    G_IM_SIZ_16b, 28, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 28.0f * scale) << 2,
                                    (s32) (top + (32.0f * scale)) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                    (s32) (1024.0f / scale));

                left += (s32) (28.0f * scale) - (i == 0 && positionDigit == 1) * 5;
                position %= digitMask;
                digitMask /= 10;
            }
        }
    }

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock(gfx++, aPositionOrdinalSuffixTexs[positionSuffix], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    if (numPlayersIndex == 0) {
        gfx = func_i3_DrawRacePositionExtras(gfx, left, top);
    }

    if (numPlayersIndex == 1) {
        gfx = func_i3_DrawPositionSuffixRectangle(gfx, left, top, scale);
    }

    return gfx;
}

Gfx* func_i3_DrawLapRectangle(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 top;
    s32 left;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if (gGameMode == GAMEMODE_DEATH_RACE) {
        return gfx;
    }
    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }
    if ((D_i3_80140788[playerIndex] != 0) && (numPlayersIndex >= 2)) {
        return gfx;
    }

    left = sLapPositions[numPlayersIndex][playerIndex][0];
    top = sLapPositions[numPlayersIndex][playerIndex][1];

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 15) << 2, (top + 11) << 2, 0, 0, 0, 1 << 12, 1 << 10);

    return gfx;
}

Gfx* func_i3_DrawLapCounter(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 top;
    s32 left;
    s32 lap;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if (gGameMode == GAMEMODE_DEATH_RACE) {
        return gfx;
    }
    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }
    if ((D_i3_80140788[playerIndex] != 0) && (numPlayersIndex >= 2)) {
        return gfx;
    }

    lap = gPlayerLapNumbers[playerIndex];
    if (gTotalLapCount < lap) {
        lap = gTotalLapCount;
    }

    left = sLapPositions[numPlayersIndex][playerIndex][0];
    top = sLapPositions[numPlayersIndex][playerIndex][1];

    top += 14;

    // Lap Number

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 11) << 2, 0, 0, (lap * 12) << 5, 1 << 12,
                        1 << 10);
    left += 8;

    // Lap /

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 11) << 2, 0, 0, 0, 1 << 12, 1 << 10);
    left += 8;

    // Lap Count

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 11) << 2, 0, 0, (gTotalLapCount * 12) << 5,
                        1 << 12, 1 << 10);

    return gfx;
}

Gfx* func_i3_UpdateRaceIntervalInfo(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex, f32 scale);
Gfx* func_i3_DrawReverse(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* func_i3_DrawKOStars(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* func_i3_DrawPlayerLives(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* func_i3_DrawPracticeBestLap(Gfx* gfx);
Gfx* func_i3_DrawDeathRaceTimer(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* func_i3_DrawDeathRaceBest(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);
Gfx* func_i3_DrawDeathRaceBestTime(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex);

extern s32 gNumPlayers;

Gfx* func_i3_DrawHUD(Gfx* gfx) {

    gSPDisplayList(gfx++, D_8014940);

    switch (gNumPlayers) {
        case 1:
            // Time
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawTimeRectangle(gfx, 0, 0);

            gfx = func_i3_DrawDeathRaceBest(gfx, 0, 0);

            // Timer
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 0, 0);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 0, 0, 1.0f);

            // Best Lap Time
            gfx = func_i3_DrawPracticeBestLap(gfx);
            gfx = func_i3_DrawDeathRaceTimer(gfx, 0, 0);

            gfx = func_i3_DrawDeathRaceBestTime(gfx, 0, 0);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 0, 0);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 0, 0);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 0, 0);

            gfx = func_i3_DrawEnergyBar(gfx, 0, 0);

            gfx = func_i3_DrawReverse(gfx, 0, 0);

            gfx = func_i3_DrawPlayerLives(gfx, 0, 0);

            gfx = func_i3_DrawKOStars(gfx, 0, 0);
            break;
        case 2:
            // Timer
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 1, 0);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 1, 1);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 1, 0, 1.0f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 1, 1, 1.0f);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 1, 0);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 1, 1);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 1, 0);
            gfx = func_i3_DrawLapRectangle(gfx, 1, 1);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 1, 0);
            gfx = func_i3_DrawLapCounter(gfx, 1, 1);

            gfx = func_i3_DrawEnergyBar(gfx, 1, 0);
            gfx = func_i3_DrawEnergyBar(gfx, 1, 1);

            gfx = func_i3_DrawReverse(gfx, 1, 0);
            gfx = func_i3_DrawReverse(gfx, 1, 1);
            break;
        case 3:
            // Timer
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 2, 0);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 2, 1);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 2, 2);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 2, 0, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 2, 1, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 2, 2, 0.75f);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 2, 0);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 2, 1);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 2, 2);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 2, 0);
            gfx = func_i3_DrawLapRectangle(gfx, 2, 1);
            gfx = func_i3_DrawLapRectangle(gfx, 2, 2);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 2, 0);
            gfx = func_i3_DrawLapCounter(gfx, 2, 1);
            gfx = func_i3_DrawLapCounter(gfx, 2, 2);

            gfx = func_i3_DrawEnergyBar(gfx, 2, 0);
            gfx = func_i3_DrawEnergyBar(gfx, 2, 1);
            gfx = func_i3_DrawEnergyBar(gfx, 2, 2);

            gfx = func_i3_DrawReverse(gfx, 2, 0);
            gfx = func_i3_DrawReverse(gfx, 2, 1);
            gfx = func_i3_DrawReverse(gfx, 2, 2);
            break;
        case 4:
            // Timer
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 0);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 1);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 2);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 3);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 0, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 1, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 2, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 3, 0.75f);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 0);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 1);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 2);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 3);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 3, 0);
            gfx = func_i3_DrawLapRectangle(gfx, 3, 1);
            gfx = func_i3_DrawLapRectangle(gfx, 3, 2);
            gfx = func_i3_DrawLapRectangle(gfx, 3, 3);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 3, 0);
            gfx = func_i3_DrawLapCounter(gfx, 3, 1);
            gfx = func_i3_DrawLapCounter(gfx, 3, 2);
            gfx = func_i3_DrawLapCounter(gfx, 3, 3);

            gfx = func_i3_DrawEnergyBar(gfx, 3, 0);
            gfx = func_i3_DrawEnergyBar(gfx, 3, 1);
            gfx = func_i3_DrawEnergyBar(gfx, 3, 2);
            gfx = func_i3_DrawEnergyBar(gfx, 3, 3);

            gfx = func_i3_DrawReverse(gfx, 3, 0);
            gfx = func_i3_DrawReverse(gfx, 3, 1);
            gfx = func_i3_DrawReverse(gfx, 3, 2);
            gfx = func_i3_DrawReverse(gfx, 3, 3);
            break;
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

void func_i3_UpdatePortraitScales(void) {
    s32 i;

    for (i = 0; i < gTotalRacers; i++) {
        if (gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000) {
            sPortraitTextureScale[i] = 1.0f;
        } else if (gRacers[i].stateFlags & RACER_STATE_FLAGS_80000) {
            sPortraitTextureScale[i] -= 0.01f;
            if (sPortraitTextureScale[i] < 0.01f) {
                sPortraitTextureScale[i] = 0.01f;
            }
        }
    }
}

extern Racer* gRacersByPosition[];

void func_i3_80132D78(void) {
    s32 i;
    s32 var_v1;
    Racer* racer;

    for (i = 0; i < 6; i++) {
        racer = gRacersByPosition[i];
        if (racer->stateFlags & RACER_STATE_FLAGS_80000 && racer->position < 6) {
            D_i3_8013F020[i][1] = 90;
            D_i3_8013F020[i][2] = racer->character;
        }
    }

    for (i = 0, var_v1 = 0; i < 6; i++) {
        if (D_i3_8013F020[i][1] != 0) {
            if (D_i3_8013F020[i][1] != 0) {
                D_i3_8013F020[i][1]--;
            }
        } else {
            D_i3_8013F020[i][2] = var_v1;
            var_v1++;
        }
    }
}

extern u32 gGameFrameCount;

void func_i3_UpdateCharacterPortraits(void);

Gfx* func_i3_DrawRacePortraits(Gfx* gfx) {
    s32 i;
    s32 position;
    s32 portraitWidth;
    s32 portraitHeight;
    s32 portraitBaseXPos;
    s32 portraitBaseYPos;
    f32 scale;
    Racer* racer;
    s32 character;

    if (D_i3_8013F000 != 0) {
        D_i3_8013F000--;
        func_i3_UpdateCharacterPortraits();
    }

    gSPDisplayList(gfx++, D_8014940);

    func_i3_UpdatePortraitScales();

    // Draw Top 6 Positions for GAMEMODE_GP_RACE, otherwise draw just the player
    for (position = 0, i = 0; i < 6; i++, position++) {
        if (gTotalRacers == i) {
            break;
        }

        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
            racer = gRacers;
        } else {
            racer = gRacersByPosition[position];
        }
        if (i < 3) {
            scale = 1.0f;
            scale *= sPortraitTextureScale[racer->id];

            portraitWidth = Math_Round(32.0f * scale);
            portraitHeight = Math_Round(32.0f * scale);
            portraitBaseXPos = (32 - portraitWidth) / 2;
            portraitBaseYPos = (32 - portraitHeight) / 2;
        } else {
            scale = 0.75f;
            scale *= sPortraitTextureScale[racer->id];

            portraitWidth = Math_Round(32.0f * scale);
            portraitHeight = Math_Round(32.0f * scale);
            portraitBaseXPos = (24.0f - portraitWidth) / 2;
            portraitBaseYPos = (24.0f - portraitHeight) / 2;
        }
        character = racer->character;
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (portraitBaseXPos + 24) << 2, (portraitBaseYPos + sPortraitYPosOffsets[i]) << 2,
                            Math_Round(portraitBaseXPos + 24 + portraitWidth) << 2,
                            Math_Round(portraitBaseYPos + sPortraitYPosOffsets[i] + portraitHeight) << 2, 0, 0, 0,
                            Math_Round(1024.0f / scale), Math_Round(1024.0f / scale));

        if (gGameMode != GAMEMODE_GP_RACE) {
            break;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, sPositionTextures[position], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 6, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 24 << 2, sPortraitPositionYPos[i] << 2, (24 + 16) << 2,
                            (sPortraitPositionYPos[i] + 6) << 2, 0, 0, 0, Math_Round(1024.0f), Math_Round(1024.0f));

        // Flash effect around border of players character portrait
        if ((gRacers[0].position - 1 == i) && ((gGameFrameCount % 20U) >= 5)) {
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (portraitBaseXPos + 24) << 2, (portraitBaseYPos + sPortraitYPosOffsets[i]) << 2,
                                Math_Round(portraitBaseXPos + 24 + portraitWidth) << 2,
                                Math_Round(portraitBaseYPos + sPortraitYPosOffsets[i] + portraitHeight) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
        }
    }
    return gfx;
}

Gfx* func_i3_DrawTimerWithPosition(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale) {
    s32 offset = 0;
    UNUSED s32 pad;
    s32 timeField;

    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }
    time -= (timeField * 60000);
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 1000;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
    }
    return gfx;
}

Gfx* func_i3_DrawRaceTimeInterval(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale) {
    s32 offset = 0;
    UNUSED s32 pad;
    s32 timeField;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    if (time <= -MAX_TIMER) {
        time = -MAX_TIMER;
    }
    if (time < -4) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, scale);
        time = -time;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PLUS, scale);
    }
    if (time < 0) {
        time = -time;
    }

    offset += 8;

    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);

    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 1000;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);

    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
    }
    return gfx;
}

extern GhostRacer* gFastestGhostRacer;

Gfx* func_i3_UpdateRaceIntervalInfo(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex, f32 scale) {
    Racer* leadRivalRacer;
    s32 i;
    s32 raceTime;
    s32 completedLaps;

    if (D_i3_80141EA8[playerIndex].lapIntervalCounter != 0) {
        D_i3_80141EA8[playerIndex].lapIntervalCounter--;
    } else {
        return gfx;
    }

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) && (gFastestGhostRacer == NULL)) {
        return gfx;
    }

    // Update lap interval on first frame of new lap update
    if (D_i3_80141EA8[playerIndex].lapIntervalCounter == 89) {

        completedLaps = gPlayerLapNumbers[playerIndex] - 1;

        // Select leading racer that isn't this player
        if (gRacers[playerIndex].position == 1) {
            leadRivalRacer = gRacersByPosition[1];
        } else {
            leadRivalRacer = gRacersByPosition[0];
        }

        sLeadRivalRaceTime[playerIndex] = 0;

        if (gGameMode == GAMEMODE_TIME_ATTACK) {
            for (i = 0; i < completedLaps; i++) {
                sLeadRivalRaceTime[playerIndex] += gFastestGhostRacer->ghost->lapTimes[i];
            }
        } else {
            for (i = 0; i < completedLaps; i++) {
                sLeadRivalRaceTime[playerIndex] += leadRivalRacer->lapTimes[i];
            }
        }

        raceTime = 0;
        for (i = 0; i < completedLaps; i++) {
            raceTime += gRacers[playerIndex].lapTimes[i];
        }

        sPlayerLeadInterval[playerIndex] = raceTime - sLeadRivalRaceTime[playerIndex];

        if (sPlayerLeadInterval[playerIndex] >= 0) {
            sPlayerLeadInterval[playerIndex] += 5;
        } else {
            sPlayerLeadInterval[playerIndex] -= 5;
        }
    }
    if ((D_i3_80141EA8[playerIndex].lapIntervalCounter % 20) >= 5) {
        gfx = func_i3_DrawRaceTimeInterval(gfx, sPlayerLeadInterval[playerIndex],
                                           sIntervalPositions[numPlayersIndex][playerIndex][0],
                                           sIntervalPositions[numPlayersIndex][playerIndex][1], scale);
    }

    return gfx;
}

extern s32 D_800F80A8[];

Gfx* func_i3_DrawReverse(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    f32 scale;
    s32 left;
    s32 top;
    s32 width;
    UNUSED s32 pad[3];

    if (D_800F80A8[playerIndex] < 100) {
        if (D_i3_8013F078[playerIndex]) {
            func_800BA3E4(playerIndex, 3);
            D_i3_8013F078[playerIndex] = false;
        }
        return gfx;
    }
    if (D_800DCE5C != 0) {
        return gfx;
    }
    switch (numPlayersIndex) {
        case 0:
        case 1:
            scale = 1.0f;
            width = 111;
            break;
        case 2:
        case 3:
            scale = 0.75f;
            width = 112.0f * scale;
            break;
    }

    if (!D_i3_8013F078[playerIndex]) {
        func_800BA2F0(playerIndex, 3);
        D_i3_8013F078[playerIndex] = true;
    }
    if ((gGameFrameCount % 20U) >= 5) {
        return gfx;
    }

    left = sReversePositions[numPlayersIndex][playerIndex][0];
    top = sReversePositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_80149D0);
    gDPLoadTLUT_pal256(gfx++, aReversePalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 23; i++) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, (aReverseTex + i * 0xE0), G_IM_FMT_CI, G_IM_SIZ_8b, 112, 2, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, (s32) (top + (i * 2 * scale)) << 2, (left + width) << 2,
                            (s32) (top + ((i * 2 + 1) * scale)) << 2, 0, 0, 0, (s32) (4096.0f / scale),
                            (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

void func_i3_InitRacePortraits(void) {
    s32 i;

    D_i3_8013F000 = 3;

    for (i = 0; i < ARRAY_COUNT(sPortraitTextureScale); i++) {
        sPortraitTextureScale[i] = 1.0f;
    }
}

extern s32 gLivesChangeCounter;

void func_i3_ResetLivesChangeCounter(void) {
    gLivesChangeCounter = 0;
}

extern s32 gPreviousLivesCount;
extern s16 gPlayerLives[];

void func_i3_TriggerLivesIncrease(void) {
    gPreviousLivesCount = gPlayerLives[0] - 1;
    gLivesChangeCounter = 90;
}

void func_i3_TriggerLivesDecrease(void) {
    gPreviousLivesCount = gPlayerLives[0] + 1;
    gLivesChangeCounter = 90;
}

extern s16 gRacersKOd;

Gfx* func_i3_DrawKOStars(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    s32 left;
    s32 top;

    if (!((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE))) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_80149D0);

    gDPLoadTextureBlock(gfx++, aHudRacersKOdTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    top = 464;
    i = gRacersKOd;
    while (i != 0) {
        left = 1140;
        while (left > 940) {
            gSPTextureRectangle(gfx++, left, top, left + 28, top + 28, 0, 0, 0, 1 << 12, 1 << 10);

            left -= 40;
            if (--i == 0) {
                break;
            }
        }
        top -= 36;
    }

    return gfx;
}

Gfx* func_i3_DrawPlayerLives(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    s32 numLives;
    s32 left;
    s32 top;

    if (gGameMode != GAMEMODE_GP_RACE) {
        return gfx;
    }

    if (gLivesChangeCounter > 0) {
        gLivesChangeCounter--;
    }
    if (gLivesChangeCounter != 0) {
        if (gPlayerLives[playerIndex] < gPreviousLivesCount) {
            numLives = gPlayerLives[playerIndex];
        } else {
            numLives = gPreviousLivesCount;
        }
    } else {
        numLives = gPlayerLives[playerIndex];
    }

    left = sLivesPositions[numPlayersIndex][playerIndex][0];
    top = sLivesPositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_80149D0);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aHudLivesLeftIconTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < numLives; i++) {
        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 7) << 2, 0, 0, 0, 1 << 12, 1 << 10);
        left += 10;
        // Start New Row
        if ((i % 5) == 4) {
            left -= 50;
            top += 9;
        }
    }

    // Flash Change In Life Icon
    if ((gLivesChangeCounter != 0) && ((gGameFrameCount % 20U) >= 5)) {
        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 7) << 2, 0, 0, 0, 1 << 12, 1 << 10);
    }

    return gfx;
}

// Replaces Falcon/Summer/Goroh Portrait Textures With Alternate Texture
void func_i3_ReplaceCharacterPortrait(s32 character) {
    size_t textureOffset;
    s32 textureIndex;
    void* vramOffset;
    void* romOffset;

    textureIndex = sPortraitReplacementIndexes[character];

    textureOffset = textureIndex * 0x800;
    vramOffset = (Segment_GetAddress(4) + SEGMENT_OFFSET(aPortraitCaptainFalconTex)) + textureOffset;

    textureOffset = textureIndex * 0x800;
    romOffset = (SEGMENT_ROM_START(segment_2747F0) + SEGMENT_OFFSET(D_276FF0)) + textureOffset;

    Dma_LoadAssetsAsync(romOffset, vramOffset, 0x800);
}

void func_i3_UpdateCharacterPortraits(void) {
    s32 i;

    for (i = 0; i < gTotalRacers; i++) {
        if (gRacers[i].customType >= 2) {
            func_i3_ReplaceCharacterPortrait(gRacers[i].character);
        }
    }
}

extern s32 gPracticeBestLap;
extern s16 gStartNewBestLap;

Gfx* func_i3_DrawPracticeBestLap(Gfx* gfx) {
    s32 left;
    s32 top;

    if (gGameMode != GAMEMODE_PRACTICE) {
        return gfx;
    }

    if (gStartNewBestLap) {
        func_800BA8D8(0x38);
        gStartNewBestLap = false;
        sPracticeBestLapCounter = 180;
    }

    if (sPracticeBestLapCounter != 0) {
        if (D_800DCE5C == 0) {
            sPracticeBestLapCounter--;
        }
        if ((sPracticeBestLapCounter % 20) >= 5) {
            gfx = func_i3_DrawTimerWithPosition(gfx, gPracticeBestLap + 5, 128, 36, 1.0f);
        }
    } else {
        if (gPracticeBestLap == (600000 - 1)) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
            gfx = func_i3_DrawBlankTimeHundredths(gfx, 128, 36);
        } else {
            gfx = func_i3_DrawTimerWithPosition(gfx, gPracticeBestLap + 5, 128, 36, 1.0f);
        }
    }

    left = 128;
    top = 20;

    // Best
    gDPLoadTextureBlock(gfx++, func_800783AC(aBestTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    left = 144;
    top = 20;

    // Lap
    gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_i3_DrawDeathRaceTimer(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 offset = 0;
    s32 top;
    s32 left;
    UNUSED s32 pad[2];
    s32 timeField;
    s32 time;

    if (gGameMode != GAMEMODE_DEATH_RACE) {
        return gfx;
    }

    time = gRacers[playerIndex].raceTime + 5;
    left = sPlayerTimerPositions[numPlayersIndex][playerIndex][0];
    top = sPlayerTimerPositions[numPlayersIndex][playerIndex][1];

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, 1.0f);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, 1.0f);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, 1.0f);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, 1.0f);
        offset += 8;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, 1.0f);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, 1.0f);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, 1.0f);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, 1.0f);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, 1.0f);
        offset += 8;
    }
    time -= timeField * 1000;
    timeField = time / 10;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, 1.0f);
    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, 1.0f);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, 1.0f);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, 1.0f);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, 1.0f);
    }

    return gfx;
}

Gfx* func_i3_DrawDeathRaceBest(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 left;
    s32 top;

    if (gGameMode != GAMEMODE_DEATH_RACE) {
        return gfx;
    }

    left = sPlayerTimePositions[numPlayersIndex][playerIndex][0];
    top = sPlayerTimePositions[numPlayersIndex][playerIndex][1];
    top += 16;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    // Best
    gDPLoadTextureBlock(gfx++, func_800783AC(aBestTex), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 12) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern CourseRecordInfo* gCurrentCourseRecordInfo;

Gfx* func_i3_DrawDeathRaceBestTime(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 left;
    s32 top;

    if (gGameMode != GAMEMODE_DEATH_RACE) {
        return gfx;
    }

    left = sPlayerTimePositions[numPlayersIndex][playerIndex][0] + 32;
    top = sPlayerTimePositions[numPlayersIndex][playerIndex][1] + 16;

    if (gCurrentCourseRecordInfo->timeRecord[0] == MAX_TIMER) {
        gDPPipeSync(gfx++);
        gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE,
                          0, TEXEL0, 0);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
        gfx = func_i3_DrawBlankTimeHundredths(gfx, left, top);
    } else {
        gfx = func_i3_DrawTimerWithPosition(gfx, gCurrentCourseRecordInfo->timeRecord[0] + 5, left, top, 1.0f);
    }

    return gfx;
}
