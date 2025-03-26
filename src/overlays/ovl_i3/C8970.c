#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "ovl_i3.h"
#include "assets/segment_2B9EA0.h"
#include "assets/segment_17B960.h"

unk_80141FF0 D_i3_80141FF0[4];
s32 D_i3_80142170;
s16 D_i3_80142174;
s16 D_i3_80142176;
s16 D_i3_80142178;
s16 D_i3_8014217A;
s16 D_i3_8014217C;
s16 D_i3_8014217E;
unk_80142180 D_i3_80142180;
u16 D_i3_80142188;
s32 D_i3_8014218C;
TexturePtr sSkyboxTexture;
TexturePtr sVenueTexture;
TexturePtr sCloudTexture;
TexturePtr D_i3_8014219C;
unk_801421A0 D_i3_801421A0[6];
unk_80142248 D_i3_80142248[6];
unk_80142320 D_i3_80142320[100];
s32 D_i3_80143770;

u8 sCourseMinimapTex[0x1000] = { 0 };

u16 sCourseMinimapPalette[] = { GPACK_RGBA5551(0, 0, 0, 0), GPACK_RGBA5551(0, 0, 0, 1),
                                GPACK_RGBA5551(255, 255, 255, 1), GPACK_RGBA5551(100, 100, 100, 1) };

s32 sPlayerMinimapPositions[][4][2] = {
    { { 232, 132 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 246, 40 }, { 246, 152 }, { 0, 0 }, { 0, 0 } },
    { { 106, 58 }, { 106, 170 }, { 248, 58 }, { 210, 152 } },
    { { 106, 58 }, { 106, 170 }, { 248, 58 }, { 248, 170 } },
};

s32 gPlayerMinimapLapCounterToggle[] = { 0, 0, 0, 0, 0, 0 };

f32 D_i3_801407A0 = 50.0f;
f32 D_i3_801407A4 = 400.0f;
f32 D_i3_801407A8 = 100.0f;

/*
    VENUE TEXTURES
 */

// MUTE CITY
CourseVenue sVenueMuteCity = { aVenueMuteCityTex, 0.03f, 0.03f, 0.0f, 0.0f };

// PORT TOWN
CourseVenue sVenuePortTown = { aVenuePortTownTex, 0.03f, 0.03f, 0.0f, 0.0f };

// BIG BLUE / RAINBOW ROAD
CourseVenue sVenueBigBlue = { aVenueBigBlueTex, 0.03f, 0.03f, 0.01f, 0.01f };

// SAND OCEAN
CourseVenue sVenueSandOcean = { aVenueSandOceanTex, 0.03f, 0.03f, 0.0f, 0.0f };

// DEVILS FOREST / BIG HAND
CourseVenue sVenueDevilsForest = { aVenueDevilsForestTex, 0.03f, 0.03f, 0.0f, 0.0f };

// WHITE LAND
CourseVenue sVenueWhiteLand = { aVenueWhiteLandTex, 0.03f, 0.03f, 0.0f, 0.0f };

// SECTORS / SPACE PLANT
CourseVenue sVenueSector = { aVenueSectorTex, 0.03f, 0.03f, 0.0f, 0.0f };

// RED CANYON
CourseVenue sVenueRedCanyon = { aVenueRedCanyonTex, 0.03f, 0.03f, 0.0f, 0.0f };

// FIRE FIELD
CourseVenue sVenueFireField = { aVenueFireFieldTex, 0.03f, 0.03f, 0.005f, 0.005f };

// SILENCE
CourseVenue sVenueSilence = { aVenueSilenceTex, 0.03f, 0.03f, 0.0f, 0.0f };

CourseVenue* D_i3_80140874[] = {
    &sVenueMuteCity, &sVenuePortTown,  &sVenueBigBlue,   &sVenueSandOcean, &sVenueDevilsForest, &sVenueWhiteLand,
    &sVenueSector,   &sVenueRedCanyon, &sVenueFireField, &sVenueSilence,   &sVenueMuteCity,
};

/*
    BACKGROUND SKYBOXES
 */

// PURPLE SKIES
// MUTE CITY / WHITE LAND
CourseSkyboxes sSkyboxPurple = { aSkyboxPurpleTex, 252, 192, 253, 0, 0, 0, 200, 130, 240, 0, 2 };

// TURQUOISE SKIES
// SILENCE 2
CourseSkyboxes sSkyboxTurquoise = { aSkyboxTurquoiseTex, 155, 247, 245, 210, 255, 230, 155, 247, 245, 0, 2 };

// DESERT YELLOW
// SAND OCEAN
CourseSkyboxes sSkyboxDesert = { aSkyboxDesertTex, 224, 234, 210, 0, 0, 0, 225, 190, 160, 0, 2 };

// BLUE
CourseSkyboxes sSkyboxBlue = { aSkyboxBlueTex, 151, 194, 218, 210, 255, 230, 151, 194, 218, 0, 2 };

// NIGHT
// SILENCE / MUTE CITY 2
CourseSkyboxes sSkyboxNight = { aSkyboxNightTex, 2, 2, 23, 245, 162, 99, 125, 155, 185, 0, 5 };

// ORANGE DAY
// DEVILS FOREST / SECTOR ALPHA
CourseSkyboxes sSkyboxOrange = { aSkyboxOrangeTex, 255, 224, 144, 0, 0, 0, 255, 224, 204, 0, 2 };

// SUNSET
// PORT TOWN / DEVILS FOREST 2 / FIRE FIELD
CourseSkyboxes sSkyboxSunset = { aSkyboxSunsetTex, 245, 162, 99, 0, 0, 0, 245, 162, 99, 0, 2 };

// SKY BLUE
// BIG BLUE 1 & 2 / RED CANYON
CourseSkyboxes sSkyboxSkyBlue = { aSkyboxSkyBlueTex, 250, 255, 255, 0, 0, 0, 180, 200, 180, 0, 2 };

CourseSkyboxes* D_i3_80140920[] = {
    &sSkyboxPurple, &sSkyboxTurquoise, &sSkyboxDesert, &sSkyboxBlue,
    &sSkyboxNight,  &sSkyboxOrange,    &sSkyboxSunset, &sSkyboxSkyBlue,
};

/*
    BACKGROUND SPRITES AND PALETTES
 */

void* D_i3_80140940[][2] = {
    { NULL, NULL },           { D_F220810, D_F221010 }, { D_F221210, D_F221A10 }, { D_F221C10, D_F222410 },
    { D_F222610, D_F222E10 }, { D_F223010, D_F223810 }, { D_F223A10, D_F224210 }, { D_F224410, D_F224C10 },
    { D_F224E10, D_F225610 }, { D_F225810, D_F226010 }, { D_F226210, D_F226A10 }, { D_F226C10, D_F227410 },
    { D_F227610, D_F227E10 }, { D_F228010, D_F228810 }, { D_F228A10, D_F229210 }, { D_F229410, D_F229C10 },
    { D_F229E10, D_F22A610 }, { D_F22A810, D_F22B010 }, { D_F22B210, D_F22BA10 }, { D_F22BC10, D_F22C410 },
    { D_F22C610, D_F22CE10 }, { D_F22D010, D_F22D810 }, { D_F22DA10, D_F22E210 }, { D_F22E410, D_F22EC10 },
    { D_F22EE10, D_F22F610 }, { D_F22F810, D_F230010 }, { D_F230210, D_F230A10 }, { D_F230C10, D_F231410 },
    { D_F231610, D_F231E10 }, { D_F232010, D_F232810 }, { D_F232A10, D_F233210 }, { D_F233410, D_F233C10 },
    { D_F233E10, D_F234610 }, { D_F234810, D_F235010 }, { D_F235210, D_F235A10 }, { D_F235C10, D_F236410 },
    { D_F236610, D_F236E10 }, { D_F237010, D_F237810 }, { D_F237A10, D_F238210 }, { D_F238410, D_F238C10 },
    { D_F238E10, D_F239610 }, { D_F239810, D_F23A010 }, { D_F23A210, D_F23AA10 }, { D_F23AC10, D_F23B410 },
    { D_F23B610, D_F23BE10 }, { D_F23C010, D_F23C810 }, { D_F23CA10, D_F23D210 }, { D_F23D410, D_F23DC10 },
    { D_F23DE10, D_F23E610 }, { D_F23E810, D_F23F010 }, { D_F23F210, D_F23FA10 }, { D_F23FC10, D_F240410 },
    { D_F240610, D_F240E10 }, { D_F241010, D_F241810 }, { D_F241A10, D_F242210 }, { D_F242410, D_F242C10 },
};

unk_80140E58 D_i3_80140B00[] = {
    { 1, 0.0f }, { 2, 60.0f }, { 3, 120.0f }, { 4, 150.0f }, { 1, 240.0f }, { 2, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140B38[] = {
    { 54, 0.0f },
    { 55, 180.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140B50[] = {
    { 5, 0.0f }, { 17, 60.0f }, { 5, 120.0f }, { 17, 180.0f }, { 5, 240.0f }, { 17, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140B88[] = {
    { 5, 0.0f }, { 6, 60.0f }, { 7, 120.0f }, { 8, 180.0f }, { 5, 240.0f }, { 6, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140BC0[] = {
    { 33, 0.0f }, { 34, 60.0f }, { 35, 120.0f }, { 36, 180.0f }, { 33, 240.0f }, { 34, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140BF8[] = {
    { 9, 0.0f },
    { 10, 120.0f },
    { 11, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140C18[] = {
    { 21, 0.0f },
    { 22, 120.0f },
    { 23, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140C38[] = {
    { 17, 0.0f }, { 18, 60.0f }, { 19, 120.0f }, { 20, 180.0f }, { 17, 240.0f }, { 18, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140C70[] = {
    { 5, 0.0f }, { 7, 60.0f }, { 7, 120.0f }, { 8, 180.0f }, { 5, 240.0f }, { 6, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140CA8[] = {
    { 39, 0.0f }, { 40, 60.0f }, { 41, 120.0f }, { 42, 180.0f }, { 39, 240.0f }, { 40, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140CE0[] = {
    { 33, 0.0f },
    { 34, 120.0f },
    { 35, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D00[] = {
    { 29, 0.0f },
    { 30, 120.0f },
    { 31, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D20[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D28[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D30[] = {
    { 21, 0.0f },
    { 22, 120.0f },
    { 23, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D50[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D58[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140D60[] = {
    { 1, 0.0f }, { 2, 60.0f }, { 3, 120.0f }, { 4, 150.0f }, { 1, 240.0f }, { 2, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140D98[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140DA0[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140DA8[] = {
    { 21, 0.0f },
    { 22, 120.0f },
    { 23, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140DC8[] = {
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140DD0[] = {
    { 13, 0.0f },
    { 14, 120.0f },
    { 15, 240.0f },
    { 0, 0.0f },
};

unk_80140E58 D_i3_80140DF0[] = {
    { 25, 0.0f }, { 26, 60.0f }, { 27, 120.0f }, { 28, 180.0f }, { 26, 300.0f }, { 0, 0.0f },
};

unk_80140E58 D_i3_80140E20[] = {
    { 44, 0.0f }, { 45, 60.0f }, { 46, 120.0f }, { 47, 180.0f }, { 44, 240.0f }, { 45, 300.0f }, { 0, 0.0f },
};

unk_80140E58* D_i3_80140E58[] = {
    D_i3_80140B00, D_i3_80140B38, D_i3_80140B50, D_i3_80140B88, D_i3_80140BC0, D_i3_80140BF8,
    D_i3_80140C18, D_i3_80140C38, D_i3_80140C70, D_i3_80140CA8, D_i3_80140CE0, D_i3_80140D00,
    D_i3_80140D20, D_i3_80140D28, D_i3_80140D30, D_i3_80140D50, D_i3_80140D58, D_i3_80140D60,
    D_i3_80140D98, D_i3_80140DA0, D_i3_80140DA8, D_i3_80140DC8, D_i3_80140DD0, D_i3_80140DF0,
};

s16 D_i3_80140EB8[] = { 1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 17, 18, 19, 20, 21,
                        22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38 };

s16 D_i3_80140EFC[] = { 13, 14, 15, 16, 39, 40, 41, 42, 45, 46, 47, 51, 54, 55 };

UNUSED s32 D_i3_80140F18[10] = { 0 };

s8 D_i3_80140F40[][3] = {
    { 31, 10, 0 }, { 0, 15, 31 }, { 31, 31, 10 }, { 0, 0, 0 }, { 0, 0, 0 },
};

extern s32 gNumPlayers;
extern CourseInfo* gCurrentCourseInfo;

void func_i3_InitCourseMinimap(void) {
    s32 pad[23];
    s32 i;
    f32 temp_fs1;
    f32 temp_fs3;
    f32 var_fs0;
    s32 temp_s0;
    s32 temp_v0;
    CourseSegment* temp_s5;
    CourseSegment* var_s1;
    f32 sp90;
    Vec3f sp84;
    Vec3f sp78;
    CourseInfo* sp74 = gCurrentCourseInfo;

    if (gNumPlayers == 1) {
        sp90 = 1;
    } else {
        sp90 = 0.75f;
    }

    for (i = 0; i < 0x1000; i++) {
        sCourseMinimapTex[i] = 0;
    }
    var_s1 = sp74->courseSegments;
    var_fs0 = 0.0f;
    temp_fs3 = 64.0f * sp90;

    temp_s5 = var_s1;

    while (true) {
        temp_fs1 = func_8009E538(var_s1, var_fs0, &sp84);
        func_8009E6F0(var_s1, var_fs0, &sp78);
        temp_s0 = Math_Round(((sp78.x * 64.0f * sp90) / 16000.0f) + temp_fs3) / 2;
        temp_v0 = Math_Round(((sp78.z * 64.0f * sp90) / 16000.0f) + temp_fs3);
        if ((temp_s0 >= 0) && (temp_s0 < 64)) {
            temp_v0 /= 2;
            if ((temp_v0 >= 0) && (temp_v0 < 64)) {
                if (temp_s0 > 0) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 1] = 1;
                }
                if (temp_s0 < 63) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 1] = 1;
                }
                if (temp_v0 > 0) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 64] = 1;
                }
                if (temp_v0 < 63) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 64] = 1;
                }
            }
        }
        var_fs0 += 200.0f / temp_fs1;
        if (var_fs0 >= 1.0f) {
            var_s1 = var_s1->next;
            if (temp_s5 == var_s1) {
                break;
            }
            var_fs0 -= 1.0f;
            var_fs0 *= (temp_fs1 / func_8009E538(var_s1, 0.0f, &sp84));
        }
    }

    var_s1 = sp74->courseSegments;
    var_fs0 = 0.0f;
    temp_s5 = var_s1;

    while (true) {
        temp_fs1 = func_8009E538(var_s1, var_fs0, &sp84);
        func_8009E6F0(var_s1, var_fs0, &sp78);
        temp_s0 = Math_Round(((sp78.x * 64.0f * sp90) / 16000.0f) + temp_fs3) / 2;
        temp_v0 = Math_Round(((sp78.z * 64.0f * sp90) / 16000.0f) + temp_fs3);
        if ((temp_s0 > 0) && (temp_s0 < 64)) {
            temp_v0 /= 2;
            if ((temp_v0 > 0) && (temp_v0 < 64)) {
                if (temp_s5 == var_s1->next) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 0] = 3;
                } else {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 0] = 2;
                }
            }
        }
        var_fs0 += 200.0f / temp_fs1;
        if (var_fs0 >= 1.0f) {
            var_s1 = var_s1->next;
            if (temp_s5 == var_s1) {
                break;
            }
            var_fs0 -= 1.0f;
            var_fs0 *= (temp_fs1 / func_8009E538(var_s1, 0.0f, &sp84));
        }
    }

    var_s1 = sp74->courseSegments;
    func_8009E538(var_s1, 0.0f, &sp84);
    func_8009E6F0(var_s1, 0.0f, &sp78);
    temp_s0 = Math_Round(((sp78.x * 64.0f * sp90) / 16000.0f) + temp_fs3) / 2;
    temp_v0 = Math_Round(((sp78.z * 64.0f * sp90) / 16000.0f) + temp_fs3);
    if ((temp_s0 > 0) && (temp_s0 < 63)) {
        temp_v0 /= 2;
        if ((temp_v0 > 0) && (temp_v0 < 63)) {
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 0] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 1] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 1] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 64] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 64] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 65] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 63] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 63] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 65] = 1;
        }
    }
}

extern s16 gSettingVsCom;
extern Controller gControllers[];
extern s32 gPlayerControlPorts[];
extern s8 D_800CD010;
extern Gfx D_8014940[];
extern Gfx D_80149A0[];
extern s32 gGameMode;
extern s32 gTotalRacers;
extern Racer* gRacersByPosition[];
extern GhostRacer* gFastestGhostRacer;
extern u32 gGameFrameCount;

Gfx* func_i3_DrawCourseMinimap(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    Controller* controller = &gControllers[gPlayerControlPorts[playerIndex]];
    Racer* racer;
    s32 i;
    s32 numPlayers;
    s32 left;
    s32 top;
    f32 minimapScale;
    s32 playerMarkerLeftPos;
    s32 playerMarkerRightPos;

    if ((controller->buttonPressed & BTN_CLEFT) && (numPlayersIndex >= 2)) {
        if (D_800CD010 == 0) {
            gPlayerMinimapLapCounterToggle[playerIndex] = (gPlayerMinimapLapCounterToggle[playerIndex] + 1) % 2;
        }
    }
    if (((numPlayersIndex != 2) || (playerIndex != 3)) && (gPlayerMinimapLapCounterToggle[playerIndex] == 0) &&
        (numPlayersIndex >= 2)) {
        return gfx;
    }

    switch (numPlayersIndex) {
        case 0:
            minimapScale = 1.0f;
            break;
        case 1:
            minimapScale = 0.75f;
            break;
        case 2:
        case 3:
            minimapScale = 0.75f;
            break;
    }

    left = sPlayerMinimapPositions[numPlayersIndex][playerIndex][0];
    top = sPlayerMinimapPositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTLUT_pal256(gfx++, sCourseMinimapPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 2; i++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (sCourseMinimapTex + (i * 64 * (s32) (64 * minimapScale)) / 2), G_IM_FMT_CI,
                            G_IM_SIZ_8b, 64, (s32) (64 * minimapScale) / 2, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, left << 2, (s32) (top + (((i * 64) / 2) * minimapScale)) << 2,
                            (s32) (left + 64 * minimapScale) << 2,
                            (s32) (top + ((i * 64) / 2 + 32) * minimapScale) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P)) {
        numPlayers = gTotalRacers;
    } else {
        numPlayers = numPlayersIndex + 1;
    }

    for (i = 0; i < numPlayers; i++) {
        if (i == playerIndex) {
            continue;
        }
        playerMarkerLeftPos =
            Math_Round(((gRacers[i].unk_0C.unk_1C.x * 64.0f * minimapScale) / 16000.0f) + (64 * minimapScale)) / 2;
        playerMarkerRightPos =
            Math_Round(((gRacers[i].unk_0C.unk_1C.z * 64.0f * minimapScale) / 16000.0f) + (64 * minimapScale)) / 2;
        playerMarkerLeftPos += left;
        playerMarkerRightPos += top;
        gDPPipeSync(gfx++);

        // Player Markers
        switch (i) {
            case 0:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 255, 1) << 16 | GPACK_RGBA5551(0, 255, 255, 1));
                break;
            case 1:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 255, 0, 1) << 16 | GPACK_RGBA5551(255, 255, 0, 1));
                break;
            case 2:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 0, 1) << 16 | GPACK_RGBA5551(0, 255, 0, 1));
                break;
            case 3:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 127, 255, 1) << 16 | GPACK_RGBA5551(255, 127, 255, 1));
                break;
        }

        gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                         playerMarkerRightPos + 1);
    }
    if (numPlayersIndex == 0) {
        if (gGameMode == GAMEMODE_GP_RACE) {
            // Lead Non-Player Racer Marker
            if (gRacers[0].position == 1) {
                racer = gRacersByPosition[1];
            } else {
                racer = gRacersByPosition[0];
            }
            playerMarkerLeftPos =
                Math_Round(((racer->unk_0C.unk_1C.x * 64.0f * minimapScale) / 16000.0f) + (64 * minimapScale)) / 2;
            playerMarkerRightPos =
                Math_Round(((racer->unk_0C.unk_1C.z * 64.0f * minimapScale) / 16000.0f) + (64 * minimapScale)) / 2;
            playerMarkerLeftPos += left;
            playerMarkerRightPos += top;

            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 255, 1) << 16 | GPACK_RGBA5551(0, 0, 255, 1));
            gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                             playerMarkerRightPos + 1);

        } else if (gFastestGhostRacer != NULL) {
            // Ghost Racer Marker
            playerMarkerLeftPos =
                Math_Round(((gFastestGhostRacer->racer->unk_0C.unk_1C.x * 64.0f * minimapScale) / 16000.0f) +
                           (64 * minimapScale)) /
                2;
            playerMarkerRightPos =
                Math_Round(((gFastestGhostRacer->racer->unk_0C.unk_1C.z * 64.0f * minimapScale) / 16000.0f) +
                           (64 * minimapScale)) /
                2;
            playerMarkerLeftPos += left;
            playerMarkerRightPos += top;

            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
            gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                             playerMarkerRightPos + 1);
        }
    }
    if ((gGameFrameCount % 16) < 8) {
        if ((numPlayersIndex < playerIndex) && (gSettingVsCom == 0)) {
            return gfx;
        }

        playerMarkerLeftPos = Math_Round(((gRacers[playerIndex].unk_0C.unk_1C.x * 64.0f * minimapScale) / 16000.0f) +
                                         (64 * minimapScale)) /
                              2;
        playerMarkerRightPos = Math_Round(((gRacers[playerIndex].unk_0C.unk_1C.z * 64.0f * minimapScale) / 16000.0f) +
                                          (64 * minimapScale)) /
                               2;
        playerMarkerLeftPos += left;
        playerMarkerRightPos += top;

        gDPPipeSync(gfx++);

        switch (playerIndex) {
            case 0:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 255, 1) << 16 | GPACK_RGBA5551(0, 255, 255, 1));
                break;
            case 1:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 255, 0, 1) << 16 | GPACK_RGBA5551(255, 255, 0, 1));
                break;
            case 2:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 0, 1) << 16 | GPACK_RGBA5551(0, 255, 0, 1));
                break;
            case 3:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 127, 255, 1) << 16 | GPACK_RGBA5551(255, 127, 255, 1));
                break;
        }

        gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                         playerMarkerRightPos + 1);
    }

    return gfx;
}

extern s32 D_800CD510;
extern s32 gSkyboxType;
extern s32 gVenueType;

extern Player gPlayers[];
extern s32 gCourseIndex;

void func_i3_80139550(void);
void func_i3_801387EC(void);
void func_i3_80136974(Player*, unk_80141FF0* arg1, CourseVenue* arg2, f32 arg3, f32 arg4);

void func_i3_801365E0(void) {
    s32 pad;
    s32 i;
    f32 var_fs0;
    f32 var_fs1;
    CourseInfo* temp_v0;
    unk_80141FF0* var_s0;
    Player* var_s1;

    D_i3_80142170 = gNumPlayers;
    D_800CD510 = false;
    D_i3_80142180.unk_00 = D_i3_80140874[gVenueType];
    D_i3_80142180.unk_04 = D_i3_80140920[gSkyboxType];
    D_i3_80142188 = D_i3_80142180.unk_04->unk_0E;

    i = Math_Rand1() % 11;
    var_fs1 = i * 0.0005f;
    if (Math_Rand1() % 2) {
        var_fs1 = 0.0f - var_fs1;
    }
    var_fs0 = i * 0.0005f;
    if (Math_Rand1() % 2) {
        var_fs0 = 0.0f - var_fs0;
    }

    for (var_s0 = D_i3_80141FF0, var_s1 = gPlayers, i = 0; i < D_i3_80142170; var_s0++, var_s1++, i++) {
        func_i3_80136974(var_s1, var_s0, D_i3_80142180.unk_00, var_fs1, var_fs0);
    }

    temp_v0 = &gCourseInfos[gCourseIndex];
    temp_v0->unk_14[0] = D_i3_80142180.unk_04->unk_04;
    temp_v0->unk_14[1] = D_i3_80142180.unk_04->unk_05;
    temp_v0->unk_14[2] = D_i3_80142180.unk_04->unk_06;

    if ((D_i3_80142180.unk_04->unk_07 == 0) && (D_i3_80142180.unk_04->unk_08 == 0) &&
        (D_i3_80142180.unk_04->unk_09 == 0)) {
        temp_v0->unk_14[3] = D_i3_80142180.unk_04->unk_04;
        temp_v0->unk_14[4] = D_i3_80142180.unk_04->unk_05;
        temp_v0->unk_14[5] = D_i3_80142180.unk_04->unk_06;
    } else {
        temp_v0->unk_14[3] = D_i3_80142180.unk_04->unk_07;
        temp_v0->unk_14[4] = D_i3_80142180.unk_04->unk_08;
        temp_v0->unk_14[5] = D_i3_80142180.unk_04->unk_09;
    }

    D_i3_8014217A = D_i3_80142180.unk_04->unk_0A;
    D_i3_8014217C = D_i3_80142180.unk_04->unk_0B;
    D_i3_8014217E = D_i3_80142180.unk_04->unk_0C;

    if (D_i3_80142188 & 2) {
        if (gNumPlayers >= 3) {
            D_i3_8014218C = 0;
            D_i3_80142188 &= ~2;
        } else {
            D_i3_8014218C = 1;
        }
    } else {
        D_i3_8014218C = 0;
    }
    if (D_i3_80142188 & 1) {
        func_i3_80139550();
    }
    func_i3_801387EC();

    sSkyboxTexture = func_80078104(D_i3_80142180.unk_04->unk_00, 64 * 1 * sizeof(u16), 0, 0, 0);
    sVenueTexture = func_80078104(D_i3_80142180.unk_00->unk_00, 64 * 32 * sizeof(u16), 0, 0, 0);

    if (D_i3_80142188 & 2) {
        sCloudTexture = func_80078104(aCloudTex, TEX_SIZE(aCloudTex, sizeof(u8)), 0, 0, 0);
    }
    if (D_i3_80142188 & 1) {
        D_i3_8014219C = func_80078104(D_F2207C8, TEX_SIZE(D_F2207C8, sizeof(u8)), 0, 0, 0);
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        D_i3_80142174 = 1;
    } else {
        D_i3_80142174 = 0;
    }
}

const unk_80141860 D_i3_80141860 = { 400.0f, 1700.0f, 0.006f, 0.006f, 0.0f, 0.0f, 0.0f, 0.0f };

void func_i3_80136974(Player* player, unk_80141FF0* arg1, CourseVenue* arg2, f32 arg3, f32 arg4) {
    arg1->unk_00 = 0.0f;
    arg1->unk_08 = 0.0f;
    arg1->unk_04 = -750.0f;
    if (gNumPlayers == 2) {
        arg1->unk_10 = 4300.0f;
        arg1->unk_18 = 5300.0f;
    } else {
        arg1->unk_10 = 6000.0f;
        arg1->unk_18 = 7000.0f;
    }
    arg1->unk_1C.unk_00 = -750.0f;
    arg1->unk_1C.unk_04 = -750.0f;
    arg1->unk_1C.unk_08 = arg2->unk_04;
    arg1->unk_1C.unk_0C = arg2->unk_08;
    arg1->unk_1C.unk_10 = 0.0f;
    arg1->unk_1C.unk_14 = 0.0f;
    arg1->unk_1C.unk_18 = arg2->unk_0C;
    arg1->unk_1C.unk_1C = arg2->unk_10;
    arg1->unk_3C = D_i3_80141860;
    arg1->unk_3C.unk_18 = arg3;
    arg1->unk_3C.unk_1C = arg4;
    arg1->unk_5C = player->unk_AC / player->unk_A8;
}

void func_i3_80136E74(Vtx*, unk_80141FF0*, Player*, f32);
void func_i3_801374D4(Vtx*, unk_80141FF0*, Player*, f32, f32, f32, f32, f32, f32, s32, s32);
void func_i3_80137AC4(Vtx*, unk_80141FF0*, Player*, unk_80141860*, f32, f32, f32, f32, f32, f32, s32, s32, bool);
void func_i3_80138D80(void);
void func_i3_801398D0(s32, unk_80141FF0*, Player*);

extern GfxPool* gGfxPool;

void func_i3_80136A6C(void) {
    s32 pad[3];
    Player* var_s2;
    unk_80141FF0* var_s1;
    Vtx* vtx;
    s32 i;
    f32 temp;
    f32 temp2;
    f32 temp_fa0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fv1;
    s32 temp_v0;
    f32 var_fv0;
    bool var_s3;

    for (i = 0, var_s1 = D_i3_80141FF0, var_s2 = gPlayers; i < D_i3_80142170; i++, var_s1++, var_s2++) {

        var_s1->unk_00 = var_s2->unk_50.x + (var_s2->unk_80 * D_i3_801407A8);
        var_s1->unk_08 = var_s2->unk_50.z + (var_s2->unk_84 * D_i3_801407A8);
        temp_v0 = Math_Round(var_s2->unk_94.x * 5.688889f);
        temp_fa0 = TAN(temp_v0);

        var_s1->unk_0C = (var_s1->unk_10 + D_i3_801407A8) * temp_fa0 * 1.2f;
        var_s1->unk_14 = var_s1->unk_0C * var_s1->unk_5C;

        temp2 = var_s2->unk_80;
        temp = var_s2->unk_84;
        temp_fs3 = var_s1->unk_10 * temp2;
        temp_fs4 = var_s1->unk_10 * temp;
        temp_fs1 = var_s1->unk_0C * temp;
        temp_fs2 = var_s1->unk_0C * (0.0f - temp2);

        vtx = &gGfxPool->unk_29B48[i * 28 + 2 * 4];
        func_i3_80136E74(vtx, var_s1, var_s2, temp_fa0);

        vtx = &gGfxPool->unk_29B48[i * 28 + 0 * 4];
        func_i3_801374D4(vtx, var_s1, var_s2, temp_fs3, temp_fs4, 0.0f, 0.0f, temp_fs1, temp_fs2, 255, 0);

        vtx = &gGfxPool->unk_29B48[i * 28 + 1 * 4];
        func_i3_801374D4(vtx, var_s1, var_s2, 0.0f, 0.0f, 0.0f - temp_fs3, 0.0f - temp_fs4, temp_fs1, temp_fs2, 0, 255);

        if (D_i3_8014218C > 0) {
            temp_fv1 = (var_s1->unk_04 + var_s1->unk_3C.unk_04) - var_s2->unk_50.y;
            if (temp_fv1 != 0.0f) {
                if (temp_fv1 >= 0.f) {
                    var_fv0 = temp_fv1;
                } else {
                    var_fv0 = -temp_fv1;
                }
                var_fv0 /= 100.0f;
                if (var_fv0 > 1.0f) {
                    var_fv0 = 1.0f;
                }
                if (temp_fv1 > 0.0f) {
                    var_s3 = true;
                } else {
                    var_s3 = false;
                }

                vtx = &gGfxPool->unk_29B48[i * 28 + 3 * 4];
                func_i3_80137AC4(vtx, var_s1, var_s2, &var_s1->unk_3C, temp_fs3, temp_fs4, 0.0f, 0.0f, temp_fs1,
                                 temp_fs2, 255, ((1.0f - var_fv0) * 255.0f), var_s3);

                vtx = &gGfxPool->unk_29B48[i * 28 + 4 * 4];
                func_i3_80137AC4(vtx, var_s1, var_s2, &var_s1->unk_3C, 0.0f, 0.0f, 0.0f - temp_fs3, 0.0f - temp_fs4,
                                 temp_fs1, temp_fs2, ((1.0f - var_fv0) * 255.0f), 255, var_s3);

                goto block_12;
            }
        } else {
        block_12:
            if (D_i3_80142188 & 1) {
                func_i3_801398D0(i, var_s1, var_s2);
            }
        }
    }
    if (D_i3_80142176 != 0) {
        func_i3_80138D80();
    }
}

void func_i3_80136E74(Vtx* vtx, unk_80141FF0* arg1, Player* player, f32 arg3) {
    s32 i;
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    s32 temp5;
    f32 temp_fv0 = (arg1->unk_18 * arg3);
    f32 temp;
    f32 temp_ft5;
    f32 temp_fa1;
    f32 sp98[4];
    f32 sp88[4];
    f32 sp78[4];
    f32 sp68[4];
    f32 sp58[4];

    temp_fa1 = (2.0f * (player->unk_94.y * temp_fv0)) / player->unk_A8;
    temp_fv0 *= arg1->unk_5C;
    temp_ft5 = (2.0f * (player->unk_94.z * temp_fv0)) / player->unk_AC;

    sp98[0] = player->unk_50.x + (player->unk_5C.x.x * arg1->unk_18) +
              (player->unk_5C.y.x * (arg1->unk_14 + temp_ft5)) + (player->unk_5C.z.x * (arg1->unk_0C - temp_fa1));
    sp88[0] = player->unk_50.y + (player->unk_5C.x.y * arg1->unk_18) +
              (player->unk_5C.y.y * (arg1->unk_14 + temp_ft5)) + (player->unk_5C.z.y * (arg1->unk_0C - temp_fa1));
    sp78[0] = player->unk_50.z + (player->unk_5C.x.z * arg1->unk_18) +
              (player->unk_5C.y.z * (arg1->unk_14 + temp_ft5)) + (player->unk_5C.z.z * (arg1->unk_0C - temp_fa1));
    sp98[1] =
        (player->unk_50.x + (player->unk_5C.x.x * arg1->unk_18) + (player->unk_5C.y.x * (arg1->unk_14 + temp_ft5))) -
        (player->unk_5C.z.x * (arg1->unk_0C + temp_fa1));
    sp88[1] =
        (player->unk_50.y + (player->unk_5C.x.y * arg1->unk_18) + (player->unk_5C.y.y * (arg1->unk_14 + temp_ft5))) -
        (player->unk_5C.z.y * (arg1->unk_0C + temp_fa1));
    sp78[1] =
        (player->unk_50.z + (player->unk_5C.x.z * arg1->unk_18) + (player->unk_5C.y.z * (arg1->unk_14 + temp_ft5))) -
        (player->unk_5C.z.z * (arg1->unk_0C + temp_fa1));
    sp98[2] =
        ((player->unk_50.x + (player->unk_5C.x.x * arg1->unk_18)) - (player->unk_5C.y.x * (arg1->unk_14 - temp_ft5))) +
        (player->unk_5C.z.x * (arg1->unk_0C - temp_fa1));
    sp88[2] =
        ((player->unk_50.y + (player->unk_5C.x.y * arg1->unk_18)) - (player->unk_5C.y.y * (arg1->unk_14 - temp_ft5))) +
        (player->unk_5C.z.y * (arg1->unk_0C - temp_fa1));
    sp78[2] =
        ((player->unk_50.z + (player->unk_5C.x.z * arg1->unk_18)) - (player->unk_5C.y.z * (arg1->unk_14 - temp_ft5))) +
        (player->unk_5C.z.z * (arg1->unk_0C - temp_fa1));
    sp98[3] =
        ((player->unk_50.x + (player->unk_5C.x.x * arg1->unk_18)) - (player->unk_5C.y.x * (arg1->unk_14 - temp_ft5))) -
        (player->unk_5C.z.x * (arg1->unk_0C + temp_fa1));
    sp88[3] =
        ((player->unk_50.y + (player->unk_5C.x.y * arg1->unk_18)) - (player->unk_5C.y.y * (arg1->unk_14 - temp_ft5))) -
        (player->unk_5C.z.y * (arg1->unk_0C + temp_fa1));
    sp78[3] =
        ((player->unk_50.z + (player->unk_5C.x.z * arg1->unk_18)) - (player->unk_5C.y.z * (arg1->unk_14 - temp_ft5))) -
        (player->unk_5C.z.z * (arg1->unk_0C + temp_fa1));

    for (i = 0; i < 4; i++) {
        if (sp98[i] < -32000.0f) {
            sp98[i] = -32000.0f;
        } else if (sp98[i] > 32000.0f) {
            sp98[i] = 32000.0f;
        }

        if (sp88[i] < -32000.0f) {
            sp88[i] = -32000.0f;
        } else if (sp88[i] > 32000.0f) {
            sp88[i] = 32000.0f;
        }

        if (sp78[i] < -32000.0f) {
            sp78[i] = -32000.0f;
        } else if (sp78[i] > 32000.0f) {
            sp78[i] = 32000.0f;
        }

        temp = ((sp98[i] - sp98[0]) / (arg1->unk_0C * 2.0f));

        if (sp98[i] < -32000.0f) {
            sp98[i] = -32000.0f;
        } else if (sp98[i] > 32000.0f) {
            sp98[i] = 32000.0f;
        }

        if (sp88[i] < -32000.0f) {
            sp88[i] = -32000.0f;
        } else if (sp88[i] > 32000.0f) {
            sp88[i] = 32000.0f;
        }

        if (sp78[i] < -32000.0f) {
            sp78[i] = -32000.0f;
        } else if (sp78[i] > 32000.0f) {
            sp78[i] = 32000.0f;
        }

        sp58[i] = ((temp * 256.0f) * 2.0f) - 0.5f;
        temp = 1.0f - ((sp88[i] - arg1->unk_04) / (arg1->unk_14 * 2.0f));
        sp68[i] = ((temp) *64.0f) - 0.5f;
    }

    for (i = 0; i < 4; i++) {
        temp1 = sp98[i];
        temp2 = sp88[i];
        temp3 = sp78[i];
        temp4 = sp68[i] * 32.0f;
        temp5 = sp58[i] * 32.0f;

        SET_VTX(vtx, temp1, temp2, temp3, temp4, temp5, 0, 0, 0, 255);
        vtx++;
    }
}

extern s8 gGamePaused;
void func_i3_801374D4(Vtx* vtx, unk_80141FF0* arg1, Player* player, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                      f32 arg8, s32 arg9, s32 argA) {
    unk_80141860* temp_v0;
    f32 temp_fv0;
    f32 var_fv0;
    f32 var_ft4;
    s32 var_t3;
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    s32 temp5;
    f32 sp68[4];
    s32 i;
    f32 sp54[4];
    f32 sp44[4];
    f32 sp34[4];
    f32 temp_fa1 = arg1->unk_04;

    temp_v0 = &arg1->unk_1C;
    sp68[0] = arg1->unk_00 + arg3 + arg7;
    sp54[0] = arg1->unk_08 + arg4 + arg8;
    sp68[1] = arg1->unk_00 + arg3 - arg7;
    sp54[1] = arg1->unk_08 + arg4 - arg8;
    sp68[2] = arg1->unk_00 + arg5 + arg7;
    sp54[2] = arg1->unk_08 + arg6 + arg8;
    sp68[3] = arg1->unk_00 + arg5 - arg7;
    sp54[3] = arg1->unk_08 + arg6 - arg8;

    temp_fv0 = (temp_v0->unk_04 - player->unk_50.y) / (temp_fa1 - player->unk_50.y);

    if (!gGamePaused) {
        temp_v0->unk_10 += temp_v0->unk_18;
        if (temp_v0->unk_10 >= 1024.0f) {
            temp_v0->unk_10 -= 1024.0f;
        } else if (temp_v0->unk_10 < -1024.0f) {
            temp_v0->unk_10 += 1024.0f;
        }
    }
    if (!gGamePaused) {
        temp_v0->unk_14 += temp_v0->unk_1C;

        if (temp_v0->unk_14 >= 1024.0f) {
            temp_v0->unk_14 -= 1024.0f;
        } else if (temp_v0->unk_14 < -1024.0f) {
            temp_v0->unk_14 += 1024.0f;
        }
    }

    sp44[0] = ((((sp68[0] - player->unk_50.x) * temp_fv0) + player->unk_50.x) * temp_v0->unk_08) + temp_v0->unk_10;
    sp34[0] = ((((sp54[0] - player->unk_50.z) * temp_fv0) + player->unk_50.z) * temp_v0->unk_0C) + temp_v0->unk_14;
    sp44[1] = ((((sp68[1] - player->unk_50.x) * temp_fv0) + player->unk_50.x) * temp_v0->unk_08) + temp_v0->unk_10;
    sp34[1] = ((((sp54[1] - player->unk_50.z) * temp_fv0) + player->unk_50.z) * temp_v0->unk_0C) + temp_v0->unk_14;
    sp44[2] = ((((sp68[2] - player->unk_50.x) * temp_fv0) + player->unk_50.x) * temp_v0->unk_08) + temp_v0->unk_10;
    sp34[2] = ((((sp54[2] - player->unk_50.z) * temp_fv0) + player->unk_50.z) * temp_v0->unk_0C) + temp_v0->unk_14;
    sp44[3] = ((((sp68[3] - player->unk_50.x) * temp_fv0) + player->unk_50.x) * temp_v0->unk_08) + temp_v0->unk_10;
    sp34[3] = ((((sp54[3] - player->unk_50.z) * temp_fv0) + player->unk_50.z) * temp_v0->unk_0C) + temp_v0->unk_14;

    var_fv0 = sp44[0];
    var_ft4 = sp34[0];

    for (i = 1; i < 4; i++) {
        if (sp44[i] < var_fv0) {
            var_fv0 = sp44[i];
        }

        if (sp34[i] < var_ft4) {
            var_ft4 = sp34[i];
        }
    }

    if (var_fv0 > 0.0f) {
        var_fv0 = (s32) (var_fv0 + 1024.0f) / 1024 * -1024.0f;
    } else {
        var_fv0 = (s32) var_fv0 / 1024 * -1024.0f;
    }
    if (var_ft4 > 0.0f) {
        var_ft4 = (s32) (var_ft4 + 1024.0f) / 1024 * -1024.0f;
    } else {
        var_ft4 = (s32) var_ft4 / 1024 * -1024.0f;
    }

    for (i = 0; i < 4; i++) {
        sp44[i] += var_fv0;
        sp34[i] += var_ft4;
    }

    for (i = 0; i < 4; i++) {
        temp1 = sp68[i];
        temp3 = sp54[i];
        temp4 = sp44[i] * 32.0f;
        temp5 = sp34[i] * 32.0f;

        var_t3 = (i < 2) ? arg9 : argA;

        SET_VTX(vtx, temp1, (s32) (temp_fa1), temp3, temp4, temp5, var_t3, var_t3, var_t3, 255);
        vtx++;
    }
}

void func_i3_80137AC4(Vtx* vtx, unk_80141FF0* arg1, Player* player, unk_80141860* arg3, f32 arg4, f32 arg5, f32 arg6,
                      f32 arg7, f32 arg8, f32 arg9, s32 argA, s32 argB, bool argC) {
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 temp4;
    s32 var_t3;
    f32 temp_ft5;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_ft4;
    s32 pad;
    f32 sp58[4];
    s32 i;
    f32 sp44[4];
    f32 sp34[4];
    f32 sp24[4];

    if (argC) {
        var_fa0 = player->unk_50.y + arg3->unk_00;
    } else {
        var_fa0 = arg1->unk_04 + arg3->unk_04;
    }

    sp58[0] = arg1->unk_00 + arg4 + arg8;
    sp44[0] = arg1->unk_08 + arg5 + arg9;
    sp58[1] = arg1->unk_00 + arg4 - arg8;
    sp44[1] = arg1->unk_08 + arg5 - arg9;
    sp58[2] = arg1->unk_00 + arg6 + arg8;
    sp44[2] = arg1->unk_08 + arg7 + arg9;
    sp58[3] = arg1->unk_00 + arg6 - arg8;
    sp44[3] = arg1->unk_08 + arg7 - arg9;

    if (!gGamePaused) {
        arg3->unk_10 += arg3->unk_18;
        if (arg3->unk_10 >= 1024.0f) {
            arg3->unk_10 -= 1024.0f;
        } else if (arg3->unk_10 < -1024.0f) {
            arg3->unk_10 += 1024.0f;
        }
    }
    if (!gGamePaused) {
        arg3->unk_14 += arg3->unk_1C;
        if (arg3->unk_14 >= 1024.0f) {
            arg3->unk_14 -= 1024.0f;
        } else if (arg3->unk_14 < -1024.0f) {
            arg3->unk_14 += 1024.0f;
        }
    }

    if (argC) {
        temp_ft5 = ((arg1->unk_04 + arg3->unk_04) - player->unk_50.y) / (var_fa0 - player->unk_50.y);
        sp34[0] = ((((sp58[0] - player->unk_50.x) * temp_ft5) + player->unk_50.x) * arg3->unk_08) + arg3->unk_10;
        sp24[0] = ((((sp44[0] - player->unk_50.z) * temp_ft5) + player->unk_50.z) * arg3->unk_0C) + arg3->unk_14;
        sp34[1] = ((((sp58[1] - player->unk_50.x) * temp_ft5) + player->unk_50.x) * arg3->unk_08) + arg3->unk_10;
        sp24[1] = ((((sp44[1] - player->unk_50.z) * temp_ft5) + player->unk_50.z) * arg3->unk_0C) + arg3->unk_14;
        sp34[2] = ((((sp58[2] - player->unk_50.x) * temp_ft5) + player->unk_50.x) * arg3->unk_08) + arg3->unk_10;
        sp24[2] = ((((sp44[2] - player->unk_50.z) * temp_ft5) + player->unk_50.z) * arg3->unk_0C) + arg3->unk_14;
        sp34[3] = ((((sp58[3] - player->unk_50.x) * temp_ft5) + player->unk_50.x) * arg3->unk_08) + arg3->unk_10;
        sp24[3] = ((((sp44[3] - player->unk_50.z) * temp_ft5) + player->unk_50.z) * arg3->unk_0C) + arg3->unk_14;
    } else {
        sp34[0] = (sp58[0] * arg3->unk_08) + arg3->unk_10;
        sp24[0] = (sp44[0] * arg3->unk_0C) + arg3->unk_14;
        sp34[1] = (sp58[1] * arg3->unk_08) + arg3->unk_10;
        sp24[1] = (sp44[1] * arg3->unk_0C) + arg3->unk_14;
        sp34[2] = (sp58[2] * arg3->unk_08) + arg3->unk_10;
        sp24[2] = (sp44[2] * arg3->unk_0C) + arg3->unk_14;
        sp34[3] = (sp58[3] * arg3->unk_08) + arg3->unk_10;
        sp24[3] = (sp44[3] * arg3->unk_0C) + arg3->unk_14;
    }
    var_fa1 = sp34[0];
    var_ft4 = sp24[0];

    for (i = 1; i < 4; i++) {
        if (sp34[i] < var_fa1) {
            var_fa1 = sp34[i];
        }
        if (sp24[i] < var_ft4) {
            var_ft4 = sp24[i];
        }
    }

    if (var_fa1 > 0.0f) {
        var_fa1 = (f32) ((s32) (var_fa1 + 1024.0f) / 1024) * -1024.0f;
    } else {
        var_fa1 = (f32) ((s32) var_fa1 / 1024) * -1024.0f;
    }
    if (var_ft4 > 0.0f) {
        var_ft4 = (f32) ((s32) (var_ft4 + 1024.0f) / 1024) * -1024.0f;
    } else {
        var_ft4 = (f32) ((s32) var_ft4 / 1024) * -1024.0f;
    }

    for (i = 0; i < 4; i++) {
        sp34[i] += var_fa1;
        sp24[i] += var_ft4;
    }

    for (i = 0; i < 4; i++) {
        temp1 = sp58[i];
        temp2 = sp44[i];
        temp3 = sp34[i] * 32.0f;
        temp4 = sp24[i] * 32.0f;

        if (i < 2) {
            var_t3 = argA;
        } else {
            var_t3 = argB;
        }

        SET_VTX(vtx, temp1, (s32) (var_fa0), temp2, temp3, temp4, 255, 255, 255, var_t3);
        vtx++;
    }
}

extern GfxPool D_1000000;
extern Mtx D_2000000[];

Gfx* func_i7_80149760(Gfx*);
Gfx* func_i3_80139168(Gfx*);
Gfx* func_i3_80139AB0(Gfx*, s32);

Gfx* func_i3_801381DC(Gfx* gfx, s32 arg1, s32 arg2) {
    CourseSkyboxes* spEC;
    s32 pad;

    spEC = D_i3_80142180.unk_04;

    gSPPerspNormalize(gfx++, gPlayers[arg1].unk_118);

    gSPMatrix(gfx++, &D_1000000.unk_20208[arg1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gfx = func_800833AC(gfx, arg2, arg1);
    gSPDisplayList(gfx++, D_303A9E0);

    if (D_i3_80142174 != 0) {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 204);
    }
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gfx++, &D_1000000.unk_29B48[arg1 * 28], 28, 0);

    gDPLoadTextureBlock(gfx++, sSkyboxTexture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSP2Triangles(gfx++, 8, 11, 9, 0, 8, 10, 11, 0);

    if (D_i3_80142188 & 1) {
        gSPDisplayList(gfx++, D_303AA18);
        gfx = func_i3_80139AB0(gfx, arg1);
    }
    if (arg1 == 0 && (D_i3_80142176 != 0)) {
        gfx = func_i3_80139168(gfx);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, &D_1000000.unk_29B48[arg1 * 28], 28, 0);
    }

    gSPDisplayList(gfx++, D_303AA40);
    gDPSetPrimColor(gfx++, 0, 0, spEC->unk_04, spEC->unk_05, spEC->unk_06, 0);

    gDPLoadTextureBlock(gfx++, sVenueTexture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);

    gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 7, 5, 0, 4, 6, 7, 0);

    if (gGameMode == GAMEMODE_GP_END_CS) {
        gfx = func_i7_80149760(gfx);
        gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_CLIPPING);
        gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }

    if (D_i3_8014218C > 0) {
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, 0, TEXEL0, SHADE, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, TEXEL0,
                          SHADE, TEXEL0);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 0);

        gDPLoadTextureBlock(gfx++, sCloudTexture, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 12, 15, 13, 0, 12, 14, 15, 0);
        gSP2Triangles(gfx++, 16, 19, 17, 0, 16, 18, 19, 0);
    }

    return gfx;
}

extern s16 gPlayer1OverallPosition;
extern s32 gCupType;
extern GfxPool D_8024DCE0[2];

void func_i3_801387EC(void) {
    s32 pad[2];
    s32 temp;
    GfxPool* gfxPool;
    s32 i;
    s32 j;
    unk_80140E58* var_s3;
    unk_801421A0* var_s1;
    unk_80142248* temp_a0;
    s32 index;
    f32 sp9C;
    s32 var_a3;
    void** temp1;
    unk_80140E58 sp54[8];

    D_i3_80142176 = 0;
    if (gNumPlayers != 1) {
        return;
    }

    if (gCourseIndex < COURSE_EDIT_1) {
        var_s3 = D_i3_80140E58[gCourseIndex];
    } else if ((gCourseIndex >= COURSE_X_1) && (gCourseIndex <= COURSE_X_6)) {
        j = Math_Rand1() % 7;
        var_s3 = sp54;
        if (j > 0) {
            sp9C = 360.0f / j;
        }

        for (i = 0; i < j; i++) {
            if (D_i3_80142188 & 4) {
                var_s3->unk_00 = D_i3_80140EFC[Math_Rand1() % 12];
            } else {
                var_s3->unk_00 = D_i3_80140EB8[Math_Rand1() % 34];
                if ((Math_Rand1() % 3) == 0) {
                    var_s3->unk_00 = 0x35;
                }
            }
            var_s3->unk_04 = i * sp9C;
            var_s3++;
        }
        var_s3->unk_00 = 0;
        var_s3->unk_04 = 0.0f;
        var_s3 = sp54;
    } else if (gCourseIndex != COURSE_ENDING) {
        return;
    } else {
        // FAKE
        if (1) {
            var_s3 = D_i3_80140E20;
        }
        if (gPlayer1OverallPosition >= 4) {
            return;
        }
    }

    var_s1 = D_i3_801421A0;
    while (var_s3->unk_00 != 0) {
        var_s1->unk_00 = var_s3->unk_00;
        if (var_s1->unk_00 == 0x2C) {
            switch (gCupType) {
                case QUEEN_CUP:
                    var_s1->unk_00 = 0x30;
                    break;
                case KING_CUP:
                    var_s1->unk_00 = 0x31;
                    break;
                case JOKER_CUP:
                    var_s1->unk_00 = 0x32;
                    break;
                case X_CUP:
                    var_s1->unk_00 = 0x33;
                    break;
                case EDIT_CUP:
                    var_s1->unk_00 = 0x34;
                    break;
            }
        }
        var_s1->unk_02 = 0;
        var_s1->unk_04 = 0;
        i = Math_Round(DEG_TO_FZXANG2(var_s3->unk_04));

        var_s1->unk_08 = 0.0f - (SIN(i) * 8000.0f);
        var_s1->unk_0C = D_i3_801407A4;
        var_s1->unk_10 = 0.0f - (COS(i) * 8000.0f);

        temp1 = D_i3_80140940[var_s1->unk_00];

        var_s1->unk_14 = func_80078104(temp1[0], 64 * 64 / 2, 0, 0, 0);
        var_s1->unk_18 = func_80078104(temp1[1], 16 * 1 * sizeof(u16), 0, 0, 0);
        D_i3_80142176++;
        var_s1++;
        var_s3++;
    }

    for (i = 0, gfxPool = D_8024DCE0; i < 2; i++, gfxPool++) {
        u16 minus32 = -32;
        // FAKE! Not sure how to generate 0xFFE0 directly

        SET_VTX(&gfxPool->distanceFromRacerBehindE8[0], minus32, 32, 0, 0, 0, 255, 255, 255, 255);
        SET_VTX(&gfxPool->distanceFromRacerBehindE8[1], 32, 32, 0, 0x800, 0, 255, 255, 255, 255);
        SET_VTX(&gfxPool->distanceFromRacerBehindE8[2], minus32, minus32, 0, 0, 0x800, 255, 255, 255, 0);
        SET_VTX(&gfxPool->distanceFromRacerBehindE8[3], 32, minus32, 0, 0x800, 0x800, 255, 255, 255, 0);
    }
    D_i3_80142178 = 0;

    if (D_i3_80142188 & 4) {
        // clang-format off
        for (i = 0, temp_a0 = D_i3_80142248; i < 6; i++, temp_a0++) { \
            temp_a0->unk_00 = 0;
        }
        // clang-format on

        for (i = 0, var_s1 = D_i3_801421A0; i < D_i3_80142176; i++, var_s1++) {
            var_a3 = -1;
            for (j = 0, temp_a0 = D_i3_80142248; j < 6; j++, temp_a0++) {
                if (temp_a0->unk_00 == var_s1->unk_00) {
                    var_s1->unk_04 = j;
                    break;
                }

                if (temp_a0->unk_00 == 0) {
                    var_a3 = j;
                    var_s1->unk_04 = j;
                    break;
                }
            }

            if (var_a3 != -1) {
                temp_a0 = &D_i3_80142248[var_a3];
                temp_a0->unk_00 = var_s1->unk_00;
                temp_a0->unk_02 = -1;
                for (j = 0; j < 16; j++) {
                    temp_a0->unk_04[j] = var_s1->unk_18[j];
                    if (temp_a0->unk_04[j] == 0xFFFF) {
                        temp_a0->unk_02 = j;
                    }
                }
                D_i3_80142178++;
            }
        }
    }
}

u16 func_i3_8013907C(void);

void func_i3_80138D80(void) {
    s32 i;
    s32 j;
    s32 temp_v0;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;
    unk_801421A0* var_s2;
    unk_80142248* temp_a0;
    s32 playerIndex = 0;

    for (i = 0, var_s2 = D_i3_801421A0; i < D_i3_80142176; i++, var_s2++) {

        spA0.x = 0.0f - gPlayers[playerIndex].unk_5C.x.x;
        spA0.y = 0.0f - gPlayers[playerIndex].unk_5C.x.y;
        spA0.z = 0.0f - gPlayers[playerIndex].unk_5C.x.z;

        sp94.x = 0.0f - spA0.z;
        sp94.z = spA0.x;

        sp88.x = 0.0f - (sp94.z * spA0.y);
        sp88.y = (sp94.z * spA0.x) - (sp94.x * spA0.z);
        sp88.z = (sp94.x * spA0.y) - 0.0f;

        sp94.x = gPlayers[playerIndex].unk_50.x + var_s2->unk_08;
        sp94.y = 400.0f;
        sp94.z = gPlayers[playerIndex].unk_50.z + var_s2->unk_10;

        if ((sp94.x <= 23000.0f) && (sp94.x >= -23000.0f) && (sp94.z <= 23000.0f) && (sp94.z >= -23000.0f)) {
            var_s2->unk_02 = 1;
            func_8006BFCC(&gGfxPool->unk_2C368[i], NULL, D_i3_801407A0, D_i3_801407A0, D_i3_801407A0, &spA0, &sp88,
                          &sp94);
        } else {
            var_s2->unk_02 = 0;
        }
    }
    if (D_i3_80142178 > 0) {
        temp_v0 = func_i3_8013907C();

        for (i = 0; i < D_i3_80142178; i++) {
            temp_a0 = &D_i3_80142248[i];
            if (temp_a0->unk_02 != -1) {
                temp_a0->unk_04[temp_a0->unk_02] = temp_v0;
            }

            for (j = 0; j < 16; j++) {
                gGfxPool->unk_2C528[i][j] = temp_a0->unk_04[j];
            }
        }
    }
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

u16 func_i3_8013907C(void) {
    s32 temp_a1;
    s32 temp_hi;
    s32 temp;
    s32 red;
    s32 green;
    s32 blue;

    temp_hi = (gGameFrameCount >> 4) % 3;
    temp = (temp_hi + 1) % 3;
    temp_a1 = gGameFrameCount % 16;

    red = D_i3_80140F40[temp_hi][0];
    green = D_i3_80140F40[temp_hi][1];
    blue = D_i3_80140F40[temp_hi][2];

    red = ((D_i3_80140F40[temp][0] - D_i3_80140F40[temp_hi][0]) * temp_a1) / 15 + red;
    green = ((D_i3_80140F40[temp][1] - D_i3_80140F40[temp_hi][1]) * temp_a1) / 15 + green;
    blue = ((D_i3_80140F40[temp][2] - D_i3_80140F40[temp_hi][2]) * temp_a1) / 15 + blue;

    return PACK_5551(red, green, blue, 1);
}

Gfx* func_i3_80139168(Gfx* gfx) {
    unk_801421A0* var_a3;
    s32 i;

    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    if (D_i3_80142188 & 4) {
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    } else {
        gDPSetCombineLERP(gfx++, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                          SHADE, 0);
    }

    gDPSetPrimColor(gfx++, 0, 0, D_i3_8014217A, D_i3_8014217C, D_i3_8014217E, 255);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0, var_a3 = D_i3_801421A0; i < D_i3_80142176; i++, var_a3++) {
        if (var_a3->unk_02 == 0) {
            continue;
        }
        gSPMatrix(gfx++, &D_1000000.unk_2C368[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, D_1000000.distanceFromRacerBehindE8, 4, 0);
        gDPPipeSync(gfx++);

        if (D_i3_80142188 & 4) {
            gDPLoadTLUT_pal256(gfx++, D_1000000.unk_2C528[var_a3->unk_04]);
        } else {
            gDPLoadTLUT_pal256(gfx++, var_a3->unk_18);
        }
        gDPLoadTextureBlock_4b(gfx++, var_a3->unk_14, G_IM_FMT_CI, 64, 64, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
    }
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    return gfx;
}

void func_i3_80139550(void) {
    unk_80142320* var_s0;
    s32 i;
    s32 j;
    f32 temp_fv0;
    s32 temp_s1;

    if ((gNumPlayers > 0) && (gNumPlayers < 5)) {
        D_i3_80143770 = 100 / gNumPlayers;
    }

    for (i = 0, var_s0 = D_i3_80142320; i < D_i3_80143770; i++, var_s0++) {
        for (j = 0; j < 4; j++) {
            var_s0->unk_04[j] = 0;
            var_s0->unk_14[j][0] = var_s0->unk_14[j][1] = 0.0f;
        }

        var_s0->unk_0C = (Math_Rand1() % 100000) + 100000.0f;
        temp_s1 = Math_Rand1() % 0x1000;
        temp_fv0 = Math_Rand1() % 800000;
        var_s0->unk_08 = COS(temp_s1) * temp_fv0;
        var_s0->unk_10 = SIN(temp_s1) * temp_fv0;

        temp_fv0 = ((Math_Rand1() % 10) + 1) * 0.1f;
        var_s0->red = var_s0->green = 255.0f * temp_fv0;
        var_s0->blue = 64.0f * temp_fv0;
        var_s0->alpha = 255;
    }
}

void func_i3_801398D0(s32 arg0, unk_80141FF0* arg1, Player* player) {
    unk_80142320* var_v1;
    s32 i;
    f32 temp_fs0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32* ptr;

    for (i = 0, var_v1 = D_i3_80142320; i < D_i3_80143770; i++, var_v1++) {
        temp_fv0 = var_v1->unk_08;
        temp_fv1 = var_v1->unk_0C;
        temp_fa0 = var_v1->unk_10;
        temp_fa1 = temp_fv0 - player->unk_50.x;
        temp_ft4 = temp_fv1 - player->unk_50.y;
        temp_ft5 = temp_fa0 - player->unk_50.z;
        temp_fs0 =
            ((temp_fa1 * player->unk_5C.x.x) + (temp_ft4 * player->unk_5C.x.y) + (temp_ft5 * player->unk_5C.x.z));
        if (temp_fs0 <= 0.0f) {
            var_v1->unk_04[arg0] = 0;
        } else {
            temp_fa1 = player->unk_19C.xw + ((player->unk_19C.xx * temp_fv0) + (player->unk_19C.xy * temp_fv1) +
                                             (player->unk_19C.xz * temp_fa0));
            temp_ft4 = player->unk_19C.yw + ((player->unk_19C.yx * temp_fv0) + (player->unk_19C.yy * temp_fv1) +
                                             (player->unk_19C.yz * temp_fa0));
            temp_ft5 = player->unk_19C.ww + ((player->unk_19C.wx * temp_fv0) + (player->unk_19C.wy * temp_fv1) +
                                             (player->unk_19C.wz * temp_fa0));
            var_v1->unk_14[arg0][0] = player->unk_F0 + ((temp_fa1 * player->unk_E8) / temp_ft5);
            var_v1->unk_14[arg0][1] = player->unk_F4 - ((temp_ft4 * player->unk_EC) / temp_ft5);
            ptr = var_v1->unk_14[arg0];
            if ((ptr[0] < player->unk_B0) || (player->unk_B8 < ptr[0]) || ((ptr[1] < player->unk_B4)) ||
                (player->unk_BC < ptr[1])) {
                var_v1->unk_04[arg0] = 0;
            } else {
                var_v1->unk_04[arg0] = 1;
            }
        }
    }
}

Gfx* func_i3_80139AB0(Gfx* gfx, s32 arg1) {
    unk_80142320* var_v0;
    s32 i;
    s32 xl;
    s32 yl;
    s32 xh;
    s32 yh;
    f32* ptr;

    gDPLoadTextureBlock(gfx++, D_i3_8014219C, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0, var_v0 = D_i3_80142320; i < D_i3_80143770; i++, var_v0++) {
        if (var_v0->unk_04[arg1] != 0) {
            ptr = var_v0->unk_14[arg1];

            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, var_v0->red, var_v0->green, var_v0->blue, var_v0->alpha);

            xl = (ptr[0]) * 4.0f;
            yl = (ptr[1]) * 4.0f;
            xh = (ptr[0] + 8.0f) * 4.0f;
            yh = (ptr[1] + 8.0f) * 4.0f;

            gSPTextureRectangle(gfx++, xl, yl, xh, yh, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }
    gDPPipeSync(gfx++);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);

    return gfx;
}
