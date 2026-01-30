#include "global.h"
#include "minimap.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include ASSET_HEADER(course_track_gfx.h)

u8 sCourseMinimapTex[0x1000] = { 0 };

u16 sCourseMinimapPalette[] = {
    GPACK_RGBA5551(0, 0, 0, 0),       // MINIMAP_PALETTE_CLEAR
    GPACK_RGBA5551(0, 0, 0, 1),       // MINIMAP_PALETTE_BLACK
    GPACK_RGBA5551(255, 255, 255, 1), // MINIMAP_PALETTE_WHITE
    GPACK_RGBA5551(100, 100, 100, 1), // MINIMAP_PALETTE_GREY
};

s32 sPlayerMinimapPositions[][4][2] = {
    { { 232, 132 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 246, 40 }, { 246, 152 }, { 0, 0 }, { 0, 0 } },
    { { 106, 58 }, { 106, 170 }, { 248, 58 }, { 210, 152 } },
    { { 106, 58 }, { 106, 170 }, { 248, 58 }, { 248, 170 } },
};

s32 gPlayerMinimapLapCounterToggle[] = { 0, 0, 0, 0 };

extern s32 gNumPlayers;
extern CourseInfo* gCurrentCourseInfo;

void Minimap_InitCourseMinimap(void) {
    s32 pad[23];
    s32 i;
    f32 forwardMagnitude;
    f32 minimapDimension;
    f32 t;
    s32 column;
    s32 row;
    CourseSegment* startSegment;
    CourseSegment* segment;
    f32 scale;
    Vec3f tangent;
    Vec3f pos;
    CourseInfo* courseInfo;

    courseInfo = gCurrentCourseInfo;

    if (gNumPlayers == 1) {
        scale = 1;
    } else {
        scale = 0.75f;
    }

    for (i = 0; i < MINIMAP_MAX_SIZE; i++) {
        sCourseMinimapTex[i] = MINIMAP_PALETTE_CLEAR;
    }
    segment = courseInfo->courseSegments;
    t = 0.0f;
    minimapDimension = MINIMAP_MAX_DIMENSION * scale;

    startSegment = segment;

    while (true) {
        forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
        Course_SplineGetPosition(segment, t, &pos);
        column = Math_Round(((pos.x * MINIMAP_MAX_DIMENSION * scale) / MINIMAP_WORLD_DIMENSION) + minimapDimension) / 2;
        row = Math_Round(((pos.z * MINIMAP_MAX_DIMENSION * scale) / MINIMAP_WORLD_DIMENSION) + minimapDimension);
        if ((column >= 0) && (column < MINIMAP_MAX_DIMENSION)) {
            row /= 2;
            if ((row >= 0) && (row < MINIMAP_MAX_DIMENSION)) {
                if (column > 0) {
                    sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column - 1] = MINIMAP_PALETTE_BLACK;
                }
                if (column < MINIMAP_MAX_DIMENSION - 1) {
                    sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column + 1] = MINIMAP_PALETTE_BLACK;
                }
                if (row > 0) {
                    sCourseMinimapTex[(row - 1) * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_BLACK;
                }
                if (row < MINIMAP_MAX_DIMENSION - 1) {
                    sCourseMinimapTex[(row + 1) * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_BLACK;
                }
            }
        }
        t += 200.0f / forwardMagnitude;
        if (t >= 1.0f) {
            segment = segment->next;
            if (startSegment == segment) {
                break;
            }
            t -= 1.0f;
            t *= (forwardMagnitude / Course_SplineGetTangent(segment, 0.0f, &tangent));
        }
    }

    segment = courseInfo->courseSegments;
    t = 0.0f;
    startSegment = segment;

    while (true) {
        forwardMagnitude = Course_SplineGetTangent(segment, t, &tangent);
        Course_SplineGetPosition(segment, t, &pos);
        column = Math_Round(((pos.x * MINIMAP_MAX_DIMENSION * scale) / MINIMAP_WORLD_DIMENSION) + minimapDimension) / 2;
        row = Math_Round(((pos.z * MINIMAP_MAX_DIMENSION * scale) / MINIMAP_WORLD_DIMENSION) + minimapDimension);
        if ((column > 0) && (column < MINIMAP_MAX_DIMENSION)) {
            row /= 2;
            if ((row > 0) && (row < MINIMAP_MAX_DIMENSION)) {
                if (startSegment == segment->next) {
                    sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_GREY;
                } else {
                    sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_WHITE;
                }
            }
        }
        t += 200.0f / forwardMagnitude;
        if (t >= 1.0f) {
            segment = segment->next;
            if (startSegment == segment) {
                break;
            }
            t -= 1.0f;
            t *= (forwardMagnitude / Course_SplineGetTangent(segment, 0.0f, &tangent));
        }
    }

    segment = courseInfo->courseSegments;
    Course_SplineGetTangent(segment, 0.0f, &tangent);
    Course_SplineGetPosition(segment, 0.0f, &pos);
    column = Math_Round(((pos.x * MINIMAP_MAX_DIMENSION * scale) / MINIMAP_WORLD_DIMENSION) + minimapDimension) / 2;
    row = Math_Round(((pos.z * MINIMAP_MAX_DIMENSION * scale) / MINIMAP_WORLD_DIMENSION) + minimapDimension);
    if ((column > 0) && (column < MINIMAP_MAX_DIMENSION - 1)) {
        row /= 2;
        if ((row > 0) && (row < MINIMAP_MAX_DIMENSION - 1)) {
            sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column - 1] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[row * MINIMAP_MAX_DIMENSION + column + 1] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[(row - 1) * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[(row + 1) * MINIMAP_MAX_DIMENSION + column + 0] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[(row - 1) * MINIMAP_MAX_DIMENSION + column - 1] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[(row + 1) * MINIMAP_MAX_DIMENSION + column - 1] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[(row - 1) * MINIMAP_MAX_DIMENSION + column + 1] = MINIMAP_PALETTE_BLACK;
            sCourseMinimapTex[(row + 1) * MINIMAP_MAX_DIMENSION + column + 1] = MINIMAP_PALETTE_BLACK;
        }
    }
}

extern s16 gSettingVsCom;
extern s8 gTitleDemoState;
extern s32 gGameMode;
extern s32 gTotalRacers;
extern Racer* gRacersByPosition[];
extern GhostRacer* gFastestGhostRacer;
extern u32 gGameFrameCount;

Gfx* Minimap_DrawCourseMinimap(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    Controller* controller = &gControllers[gPlayerControlPorts[playerIndex]];
    Racer* racer;
    s32 i;
    s32 numPlayers;
    s32 left;
    s32 top;
    f32 minimapScale;
    s32 playerMarkerX;
    s32 playerMarkerY;

    if ((controller->buttonPressed & BTN_CLEFT) && (numPlayersIndex >= 2)) {
        if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
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
        gDPLoadTextureBlock(
            gfx++, (sCourseMinimapTex + (i * MINIMAP_MAX_DIMENSION * (s32) (MINIMAP_MAX_DIMENSION * minimapScale)) / 2),
            G_IM_FMT_CI, G_IM_SIZ_8b, MINIMAP_MAX_DIMENSION, (s32) (MINIMAP_MAX_DIMENSION * minimapScale) / 2, 0,
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, left << 2, (s32) (top + (((i * MINIMAP_MAX_DIMENSION) / 2) * minimapScale)) << 2,
                            (s32) (left + MINIMAP_MAX_DIMENSION * minimapScale) << 2,
                            (s32) (top + ((i * MINIMAP_MAX_DIMENSION) / 2 + (MINIMAP_MAX_DIMENSION / 2)) * minimapScale)
                                << 2,
                            0, 0, 0, 1 << 10, 1 << 10);
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
        playerMarkerX =
            Math_Round(((gRacers[i].segmentPositionInfo.segmentPos.x * MINIMAP_MAX_DIMENSION * minimapScale) /
                        MINIMAP_WORLD_DIMENSION) +
                       (MINIMAP_MAX_DIMENSION * minimapScale)) /
            2;
        playerMarkerY =
            Math_Round(((gRacers[i].segmentPositionInfo.segmentPos.z * MINIMAP_MAX_DIMENSION * minimapScale) /
                        MINIMAP_WORLD_DIMENSION) +
                       (MINIMAP_MAX_DIMENSION * minimapScale)) /
            2;
        playerMarkerX += left;
        playerMarkerY += top;
        gDPPipeSync(gfx++);

        // Player Markers
        switch (i) {
            case 0:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER1_COLOR << 16 | MINIMAP_PLAYER1_COLOR);
                break;
            case 1:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER2_COLOR << 16 | MINIMAP_PLAYER2_COLOR);
                break;
            case 2:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER3_COLOR << 16 | MINIMAP_PLAYER3_COLOR);
                break;
            case 3:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER4_COLOR << 16 | MINIMAP_PLAYER4_COLOR);
                break;
        }

        gDPFillRectangle(gfx++, playerMarkerX - 1, playerMarkerY - 1, playerMarkerX + 1, playerMarkerY + 1);
    }
    if (numPlayersIndex == 0) {
        if (gGameMode == GAMEMODE_GP_RACE) {
            // Lead Non-Player Racer Marker
            if (gRacers[0].position == 1) {
                racer = gRacersByPosition[1];
            } else {
                racer = gRacersByPosition[0];
            }
            playerMarkerX =
                Math_Round(((racer->segmentPositionInfo.segmentPos.x * MINIMAP_MAX_DIMENSION * minimapScale) /
                            MINIMAP_WORLD_DIMENSION) +
                           (MINIMAP_MAX_DIMENSION * minimapScale)) /
                2;
            playerMarkerY =
                Math_Round(((racer->segmentPositionInfo.segmentPos.z * MINIMAP_MAX_DIMENSION * minimapScale) /
                            MINIMAP_WORLD_DIMENSION) +
                           (MINIMAP_MAX_DIMENSION * minimapScale)) /
                2;
            playerMarkerX += left;
            playerMarkerY += top;

            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, MINIMAP_LEADER_COLOR << 16 | MINIMAP_LEADER_COLOR);
            gDPFillRectangle(gfx++, playerMarkerX - 1, playerMarkerY - 1, playerMarkerX + 1, playerMarkerY + 1);

        } else if (gFastestGhostRacer != NULL) {
            // Ghost Racer Marker
            playerMarkerX = Math_Round(((gFastestGhostRacer->racer->segmentPositionInfo.segmentPos.x *
                                         MINIMAP_MAX_DIMENSION * minimapScale) /
                                        MINIMAP_WORLD_DIMENSION) +
                                       (MINIMAP_MAX_DIMENSION * minimapScale)) /
                            2;
            playerMarkerY = Math_Round(((gFastestGhostRacer->racer->segmentPositionInfo.segmentPos.z *
                                         MINIMAP_MAX_DIMENSION * minimapScale) /
                                        MINIMAP_WORLD_DIMENSION) +
                                       (MINIMAP_MAX_DIMENSION * minimapScale)) /
                            2;
            playerMarkerX += left;
            playerMarkerY += top;

            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, MINIMAP_GHOST_COLOR << 16 | MINIMAP_GHOST_COLOR);
            gDPFillRectangle(gfx++, playerMarkerX - 1, playerMarkerY - 1, playerMarkerX + 1, playerMarkerY + 1);
        }
    }
    if ((gGameFrameCount % 16) < 8) {
        if ((numPlayersIndex < playerIndex) && (gSettingVsCom == 0)) {
            return gfx;
        }

        playerMarkerX =
            Math_Round(((gRacers[playerIndex].segmentPositionInfo.segmentPos.x * MINIMAP_MAX_DIMENSION * minimapScale) /
                        MINIMAP_WORLD_DIMENSION) +
                       (MINIMAP_MAX_DIMENSION * minimapScale)) /
            2;
        playerMarkerY =
            Math_Round(((gRacers[playerIndex].segmentPositionInfo.segmentPos.z * MINIMAP_MAX_DIMENSION * minimapScale) /
                        MINIMAP_WORLD_DIMENSION) +
                       (MINIMAP_MAX_DIMENSION * minimapScale)) /
            2;
        playerMarkerX += left;
        playerMarkerY += top;

        gDPPipeSync(gfx++);

        switch (playerIndex) {
            case 0:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER1_COLOR << 16 | MINIMAP_PLAYER1_COLOR);
                break;
            case 1:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER2_COLOR << 16 | MINIMAP_PLAYER2_COLOR);
                break;
            case 2:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER3_COLOR << 16 | MINIMAP_PLAYER3_COLOR);
                break;
            case 3:
                gDPSetFillColor(gfx++, MINIMAP_PLAYER4_COLOR << 16 | MINIMAP_PLAYER4_COLOR);
                break;
        }

        gDPFillRectangle(gfx++, playerMarkerX - 1, playerMarkerY - 1, playerMarkerX + 1, playerMarkerY + 1);
    }

    return gfx;
}
