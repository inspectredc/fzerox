#include "prevent_bss_reordering.h"
#include "global.h"
#include "ending.h"
#include "fzx_game.h"
#include "fzx_hud.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_machine.h"
#include "fzx_camera.h"
#include "fzx_font.h"
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER(machine_custom_gfx.h)
#include ASSET_HEADER(hud_gfx.h)
#include ASSET_HEADER(podium_gfx.h)
#include ASSET_HEADER(common_assets_compressed.h)

PodiumDrawData* gPodiumDrawDataPtr;
s16 sTotalRacersKOd;
u16 gEndingFlags;
void* sEndingTex;
void* sEndingTextTex;
s16 sEndScreenState;
s16 sEndScreenFade;
s16 sEndScreenAlpha;
s32 sEndingState;
s16 sEndingTimer;
f32 sEndingCurrentResultsScrollTop;
s16 sCongratulationsEndingTextAlpha;
s16 sCupNameIndex;
s16 sCupNameWidth;
s16 sCupDifficulty;
s16 sDrawThanksForPlaying;
s16 sThanksForPlayingFade;
s16 sTotalScrollResults;
EndingCutsceneResults sEndingCutsceneResults[10];
Podium gPodiums[3];
u16 gPodiumActiveFlags;
Vec3f sPodiumHoleVtxPositions[7];
// FAKE! BSS REORDER PADDING
UNUSED s8 D_i7_8014BF84;
UNUSED s8 D_i7_8014BF85;
UNUSED s8 D_i7_8014BF86;
UNUSED s8 D_i7_8014BF87;
UNUSED s8 D_i7_8014BF88;
UNUSED s8 D_i7_8014BF89;
UNUSED s8 D_i7_8014BF8A;

extern s16 D_800CCFE8;
extern s32 gCupType;
extern s8 gUnlockableLevel;
extern s8 gGamePaused;
extern s16 gForceCredits;
extern s32 gCourseIndex;
extern RaceStats gCupRaceStats[1][6];
extern s32 D_i2_80106F10;
extern s16 gPlayer1OverallPosition;

extern s32 gNumPlayers;
extern s32 gDifficulty;

extern char* gTrackNames[55];

extern FrameBuffer* gFrameBuffers[];
extern GfxPool* gGfxPool;
extern s32 D_800DCD04;
extern Vtx* gEffectsVtxPtr;
extern Vtx* gEffectsVtxEndPtr;
extern Vtx* gCourseVtxPtr;

extern GfxPool D_1000000;

void* sEndingTextures[][2] = {
    { aEndingCaptainFalconMasterTex, aEndingTextCaptainFalconMasterTex },                 // CAPTAIN_FALCON
    { aEndingDrStewartTex, aEndingTextDrStewartTex },                                     // DR_STEWART
    { aEndingPicoTex, aEndingTextPicoTex },                                               // PICO
    { aEndingSamuraiGorohTex, aEndingTextSamuraiGorohTex },                               // SAMURAI_GOROH
    { aEndingJodySummerTex, aEndingTextJodySummerTex },                                   // JODY_SUMMER
    { aEndingMightyGazelleTex, aEndingTextMightyGazelleTex },                             // MIGHTY_GAZELLE
    { aEndingMrEadTex, aEndingTextMrEadTex },                                             // MR_EAD
    { aEndingBabaTex, aEndingTextBabaTex },                                               // BABA
    { aEndingOctomanTex, aEndingTextOctomanTex },                                         // OCTOMAN
    { aEndingGomarAndShiohTex, aEndingTextGomarAndShiohTex },                             // GOMAR_AND_SHIOH
    { aEndingKateAlenTex, aEndingTextKateAlenTex },                                       // KATE_ALEN
    { aEndingRogerBusterTex, aEndingTextRogerBusterTex },                                 // ROGER_BUSTER
    { aEndingJamesMcCloudTex, aEndingTextJamesMcCloudTex },                               // JAMES_MCCLOUD
    { aEndingLeonTex, aEndingTextLeonTex },                                               // LEON
    { aEndingAntonioGusterTex, aEndingTextAntonioGusterTex },                             // ANTONIO_GUSTER
    { aEndingBlackShadowTex, aEndingTextBlackShadowTex },                                 // BLACK_SHADOW
    { aEndingMichaelChainTex, aEndingTextMichaelChainTex },                               // MICHAEL_CHAIN
    { aEndingJackLevinTex, aEndingTextJackLevinTex },                                     // JACK_LEVIN
    { aEndingSuperArrowTex, aEndingTextSuperArrowTex },                                   // SUPER_ARROW
    { aEndingMrsArrowTex, aEndingTextMrsArrowTex },                                       // MRS_ARROW
    { aEndingJohnTanakaTex, aEndingTextJohnTanakaTex },                                   // JOHN_TANAKA
    { aEndingBeastmanTex, aEndingTextBeastmanTex },                                       // BEASTMAN
    { aEndingZodaTex, aEndingTextZodaTex },                                               // ZODA
    { aEndingDrClashTex, aEndingTextDrClashTex },                                         // DR_CLASH
    { aEndingSilverNeelsenTex, aEndingTextSilverNeelsenTex },                             // SILVER_NEELSEN
    { aEndingBioRexTex, aEndingTextBioRexTex },                                           // BIO_REX
    { aEndingDraqTex, aEndingTextDraqTex },                                               // DRAQ
    { aEndingBillyTex, aEndingTextBillyTex },                                             // BILLY
    { aEndingTheSkullTex, aEndingTextTheSkullTex },                                       // THE_SKULL
    { aEndingBloodFalconTex, aEndingTextBloodFalconTex },                                 // BLOOD_FALCON
    { aEndingCaptainFalconAltTex, NULL },                                                 // CAPTAIN_FALCON 2
    { aEndingCaptainFalconStandardExpertTex, aEndingTextCaptainFalconStandardExpertTex }, // CAPTAIN_FALCON 3
    { aEndingSamuraiGorohAltTex, NULL },                                                  // SAMURAI_GOROH 2
    { aEndingJodySummerAltTex, NULL },                                                    // JODY_SUMMER 2
};

void* sFinalResultPositionDigitTexs[] = {
    aFinalResultPosition0Tex, aFinalResultPosition1Tex, aFinalResultPosition2Tex, aFinalResultPosition3Tex,
    aFinalResultPosition4Tex, aFinalResultPosition5Tex, aFinalResultPosition6Tex, aFinalResultPosition7Tex,
    aFinalResultPosition8Tex, aFinalResultPosition9Tex,
};

void* sFinalResultsPositionSuffixTexs[] = { aFinalResultPositionSuffixSTTex, aFinalResultPositionSuffixNDTex,
                                            aFinalResultPositionSuffixRDTex, aFinalResultPositionSuffixTHTex };

Gfx* sPodiumDLs[] = { D_5000178, D_5001E38, D_5002B18 };

f32 sPodiumBodyScale = 0.3f;
f32 sPodiumHoleScale = 1.0f;

s16 sEndingCutsceneResultsScript[] = {
    ENDING_CS_RESULTS_CONGRATULATIONS, ENDING_CS_RESULTS_CUP_INFO,
    ENDING_CS_RESULTS_RACE_RESULT,     ENDING_CS_RESULTS_RACE_RESULT,
    ENDING_CS_RESULTS_RACE_RESULT,     ENDING_CS_RESULTS_RACE_RESULT,
    ENDING_CS_RESULTS_RACE_RESULT,     ENDING_CS_RESULTS_RACE_RESULT,
    ENDING_CS_RESULTS_TOTAL_RANKING,   ENDING_CS_RESULTS_DONE,
};

char sTotalRankingStr[] = "TOTAL RANKING";

const char* sCupNames[] = { "JACK CUP", "QUEEN CUP", "KING CUP", "JOKER CUP", "EDIT CUP", "X CUP" };

char sThanksForPlayingStr[] = "THANKS FOR PLAYING!!";

f32 sPodiumHeights[] = { 0.0f, -40.0f, -60.0f };

s32 EndingCutscene_GetEndScreenIndex(s32 difficulty, s16 character, s8 customType) {
    s32 endScreenCharacterIndex;

    switch (character) {
        case CAPTAIN_FALCON:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 30;
            } else {
                switch (difficulty) {
                    case STANDARD:
                    case EXPERT:
                        endScreenCharacterIndex = 31;
                        break;
                    case MASTER:
                        endScreenCharacterIndex = character;
                        break;
                }
            }
            break;
        case SAMURAI_GOROH:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 32;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        case JODY_SUMMER:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 33;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        default:
            endScreenCharacterIndex = character;
            break;
    }
    return endScreenCharacterIndex;
}

void EndingCutscene_Init(void) {
    EndingCutsceneResults* cutsceneResults;
    s32 cupFirstCourseIndex;
    s32 pad;
    Racer* playerRacer = &gRacers[0];
    s32 i;
    s32 j;
    void** endingTextures;
    s32 gpCourseNo;

    D_800CCFE8 = D_i2_80106F10 = 3;
    gGamePaused = false;
    gNumPlayers = 1;
    cupFirstCourseIndex = (gCourseIndex / 6) * 6;
    gCourseIndex = COURSE_ENDING;
    sCupDifficulty = gDifficulty;
    gDifficulty = MASTER;
    sTotalRacersKOd = 0;

    for (j = 0; j < 6; j++) {
        sTotalRacersKOd += gCupRaceStats[0][j].racersKOd;
    }

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
    EndingCutsceneEffects_Init();
    EndingCutscene_InitPodiums();
    sEndScreenState = END_SCREEN_INACTIVE;
    sEndScreenFade = 0;
    sEndScreenAlpha = 0;
    gEndingFlags = 0;
    if (gPlayer1OverallPosition < 4) {
        gEndingFlags |= ENDING_CHARACTER_FIREWORKS | ENDING_SHOW_PODIUM_SEQUENCE | ENDING_DRAW_CONGRATULATIONS |
                        ENDING_SIDE_VIEW_FIREWORKS;
    } else {
        gEndingFlags |= ENDING_NOT_ON_PODIUM;
    }
    if (gForceCredits) {
        gForceCredits = false;
        gEndingFlags |= ENDING_FOLLOW_WITH_CREDITS;
    } else if (gUnlockableLevel >= 2) {
        switch (sCupDifficulty) {
            case EXPERT:
            case MASTER:
                if (gCupType == JOKER_CUP && gPlayer1OverallPosition == 1) {
                    gEndingFlags |= ENDING_FOLLOW_WITH_CREDITS;
                }
                break;
        }
    }

    if (gPlayer1OverallPosition == 1) {
        switch (sCupDifficulty) {
            case STANDARD:
            case EXPERT:
            case MASTER:
                gEndingFlags |= ENDING_SHOW_END_SCREEN;
                break;
        }
    }

    sEndingCurrentResultsScrollTop = 0.0f;
    sCongratulationsEndingTextAlpha = 0;
    sEndingState = ENDING_START;
    sEndingTimer = 0;

    switch (gCupType) {
        case JACK_CUP:
            sCupNameIndex = 0;
            break;
        case QUEEN_CUP:
            sCupNameIndex = 1;
            break;
        case KING_CUP:
            sCupNameIndex = 2;
            break;
        case JOKER_CUP:
            sCupNameIndex = 3;
            break;
        case X_CUP:
            sCupNameIndex = 5;
            break;
        case EDIT_CUP:
            sCupNameIndex = 4;
            break;
    }
    sCupNameWidth = Font_GetStringWidth(sCupNames[sCupNameIndex], FONT_SET_3, 1);
    sDrawThanksForPlaying = false;
    sThanksForPlayingFade = 0;
    gPodiumActiveFlags = 0;
    gpCourseNo = 0;

    cutsceneResults = sEndingCutsceneResults;
    for (i = 0; sEndingCutsceneResultsScript[i] != ENDING_CS_RESULTS_DONE; i++) {
        cutsceneResults->isDrawn = false;
        cutsceneResults->cmd = sEndingCutsceneResultsScript[i];
        switch (cutsceneResults->cmd) {
            case ENDING_CS_RESULTS_CONGRATULATIONS:
                cutsceneResults->course = 0;
                cutsceneResults->left = 28.0f;
                cutsceneResults->gapFromLast = 104.0f;
                cutsceneResults->height = 31;
                break;
            case ENDING_CS_RESULTS_END_SCREEN:
                cutsceneResults->course = 0;
                cutsceneResults->left = 76.0f;
#ifdef VERSION_JP
                cutsceneResults->gapFromLast = 70.0f;
                cutsceneResults->height = 195;
#else
                cutsceneResults->gapFromLast = 62.0f;
                cutsceneResults->height = 203;
#endif
                break;
            case ENDING_CS_RESULTS_CUP_INFO:
                cutsceneResults->course = 0;
                cutsceneResults->left = 0.0f;
                cutsceneResults->gapFromLast = 236.0f;
                cutsceneResults->height = 52;
                break;
            case ENDING_CS_RESULTS_TOTAL_RANKING:
                cutsceneResults->course = 0;
                cutsceneResults->left = 0.0f;
                cutsceneResults->gapFromLast = 100.0f;
                cutsceneResults->height = 266;
                break;
            case ENDING_CS_RESULTS_RACE_RESULT:
                cutsceneResults->course = cupFirstCourseIndex + gpCourseNo;
                cutsceneResults->left = 76.0f;

                if (gpCourseNo != 0) {
                    cutsceneResults->gapFromLast = 120.0f;
                } else {
                    cutsceneResults->gapFromLast = 120.0f;
                }

                cutsceneResults->height = 80;
                gpCourseNo++;
                break;
        }
        cutsceneResults++;
    }
    sTotalScrollResults = cutsceneResults - sEndingCutsceneResults;
    func_80078104(aCongratulationsTex, TEX_SIZE(aCongratulationsTex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition0Tex, TEX_SIZE(aFinalResultPosition0Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition1Tex, TEX_SIZE(aFinalResultPosition1Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition2Tex, TEX_SIZE(aFinalResultPosition2Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition3Tex, TEX_SIZE(aFinalResultPosition3Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition4Tex, TEX_SIZE(aFinalResultPosition4Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition5Tex, TEX_SIZE(aFinalResultPosition5Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition6Tex, TEX_SIZE(aFinalResultPosition6Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition7Tex, TEX_SIZE(aFinalResultPosition7Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition8Tex, TEX_SIZE(aFinalResultPosition8Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPosition9Tex, TEX_SIZE(aFinalResultPosition9Tex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixSTTex, TEX_SIZE(aFinalResultPositionSuffixSTTex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixNDTex, TEX_SIZE(aFinalResultPositionSuffixNDTex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixRDTex, TEX_SIZE(aFinalResultPositionSuffixRDTex, sizeof(u16)), 0, 0, 0);
    func_80078104(aFinalResultPositionSuffixTHTex, TEX_SIZE(aFinalResultPositionSuffixTHTex, sizeof(u16)), 0, 0, 0);

    if (gEndingFlags & ENDING_SHOW_END_SCREEN) {

        endingTextures = sEndingTextures[EndingCutscene_GetEndScreenIndex(sCupDifficulty, playerRacer->character,
                                                                          playerRacer->customType)];

        sEndingTex = func_80078104(endingTextures[0], 168 * 99 * sizeof(u16), 0, 1, 0);

        if (endingTextures[1] != NULL) {
#ifdef VERSION_JP
            sEndingTextTex = func_80078104(endingTextures[1], 196 * 16 * sizeof(u16), 0, 1, 0);
#else
            sEndingTextTex = func_80078104(endingTextures[1], 196 * 32 * sizeof(u16), 0, 1, 0);
#endif
        } else {
            sEndingTextTex = NULL;
        }
    }
}

extern s32 D_800DCCFC;
extern Controller gSharedController;

s32 EndingCutscene_Update(void) {

    Controller_SetGlobalInputs(&gSharedController);
    gPodiumDrawDataPtr = &gPodiumDrawData[D_800DCCFC];
    Effects_Update();
    Racer_Update();
    Camera_Update();
    Background_Update();
    Course_Update();
    func_80074844();
    EndingCutsceneEffects_Update();
    if (sDrawThanksForPlaying) {
        EndingCutscene_FadeInThanksForPlaying();
    }
    if (sEndScreenState != END_SCREEN_INACTIVE) {
        EndingCutscene_FadeEndScreen();
    }
    EndingCutscene_UpdatePodiums();

    switch (EndingCutscene_UpdateState()) {
        case 1:
            return GAMEMODE_FLX_MAIN_MENU;
        case 2:
            return GAMEMODE_FLX_UNSKIPPABLE_CREDITS;
        case 0:
        default:
            return GAMEMODE_GP_END_CS;
    }
}

extern u16 gInputButtonPressed;
extern s32 gSlowRacersForPodium;

s32 EndingCutscene_UpdateState(void) {
    EndingCutsceneResults* cutsceneResults;
    Racer* racer;
    s32 exitState;
    f32 alphaScale;
    bool nextStateReady;
    s32 i;

    exitState = 0;
    switch (sEndingState) {
        case ENDING_START:
            if (sEndingTimer >= 120) {
                sEndingState = ENDING_FADE_IN_CONGRATULATIONS;
                sEndingTimer = 0;
            } else {
                sEndingTimer++;
            }
            break;
        case ENDING_FADE_IN_CONGRATULATIONS:
            sEndingTimer++;
            alphaScale = sEndingTimer / 30.0f;
            if (alphaScale >= 1.0f) {
                alphaScale = 1.0f;
            }
            sCongratulationsEndingTextAlpha = 255.0f * alphaScale;
            if (sEndingTimer >= 120) {
                sEndingState = ENDING_SCROLL_RESULTS;
                sCongratulationsEndingTextAlpha = 255;
                sEndingTimer = 0;
                Camera_SendEndingCameraMessage(ENDING_CAMERA_1);
            }
            break;
        case ENDING_SCROLL_RESULTS:
            sCongratulationsEndingTextAlpha = 255;
            if (sEndingTimer <= 300) {
                sEndingTimer++;
            }
            if ((sEndingTimer == 300) && (gEndingFlags & ENDING_SIDE_VIEW_FIREWORKS)) {
                sFireworksType = FIREWORKS_SIDE;
            }
            sEndingCurrentResultsScrollTop -= 0.5f;

            nextStateReady = true;
            cutsceneResults = sEndingCutsceneResults;
            for (i = 0; i < sTotalScrollResults; i++) {
                if (cutsceneResults->cmd != ENDING_CS_RESULTS_COMPLETED_ITEM) {
                    nextStateReady = false;
                }
                cutsceneResults++;
            }
            if (nextStateReady) {
                sEndingState = ENDING_SETUP_THANKS_FOR_PLAYING;
                sEndingTimer = 0;
                sFireworksType = FIREWORKS_NONE;
                if (gEndingFlags & ENDING_SHOW_PODIUM_SEQUENCE) {
                    gSlowRacersForPodium = true;
                    sEndingState = ENDING_SLOW_RACERS;
                }
            }
            break;
        case ENDING_SLOW_RACERS:
            nextStateReady = true;

            for (i = 0, racer = gRacers; i < 3; i++) {
                if (racer->speed > 0.1f) {
                    nextStateReady = false;
                    break;
                }
                racer++;
            }

            if (nextStateReady) {
                sEndingState = ENDING_PODIUMS;
                sEndingTimer = 0;
            }
            break;
        case ENDING_PODIUMS:
            sEndingTimer++;

            if (sEndingTimer == 1) {
                gPodiumActiveFlags |= PODIUM_ACTIVATED(2);
                Camera_SendEndingCameraMessage(ENDING_CAMERA_PODIUM_P3);
            }
            if (sEndingTimer == 271) {
                gPodiumActiveFlags |= PODIUM_ACTIVATED(1);
                Camera_SendEndingCameraMessage(ENDING_CAMERA_PODIUM_P2);
            }
            if (sEndingTimer == 541) {
                gPodiumActiveFlags |= PODIUM_ACTIVATED(0);
                Camera_SendEndingCameraMessage(ENDING_CAMERA_PODIUM_P1);
            }
            if (sEndingTimer > 1020) {
                if (gEndingFlags & ENDING_SHOW_END_SCREEN) {
                    sEndingState = ENDING_END_SCREEN;
                    sEndScreenState = END_SCREEN_FADE_IN;
                } else {
                    sEndingState = ENDING_SETUP_THANKS_FOR_PLAYING;
                }
                sEndingTimer = 0;
            }
            break;
        case ENDING_END_SCREEN:
            if (sEndScreenState == END_SCREEN_INACTIVE) {
                sEndingState = ENDING_SETUP_THANKS_FOR_PLAYING;
                sEndingTimer = 0;
            }
            break;
        case ENDING_SETUP_THANKS_FOR_PLAYING:
            sEndingTimer++;
            if (sEndingTimer > 0) {
                sEndingState = ENDING_THANKS_FOR_PLAYING;
                sEndingTimer = 0;
                if (gEndingFlags & ENDING_CHARACTER_FIREWORKS) {
                    sFireworksType = FIREWORKS_CHARACTER;
                }
            }
            break;
        case ENDING_THANKS_FOR_PLAYING:
            if ((sFireworksType == FIREWORKS_NONE) && (gActiveFireworks == 0)) {
                sEndingTimer++;
                if (sEndingTimer == 60) {
                    sDrawThanksForPlaying = true;
                    Audio_BetaBgmStop3();
                }
            }
            if (sEndingTimer >= 360) {
                sEndingTimer = 360;
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    exitState = 1;
                }
            }
            break;
    }

    cutsceneResults = sEndingCutsceneResults;
    for (i = 0; i < sTotalScrollResults; i++) {
        switch (cutsceneResults->cmd) {
            case ENDING_CS_RESULTS_CONGRATULATIONS:
                if ((sEndingState != ENDING_START) && !cutsceneResults->isDrawn) {
                    cutsceneResults->isDrawn = true;
                }
                break;
            case ENDING_CS_RESULTS_END_SCREEN:
                if ((sEndingState != ENDING_START) && !cutsceneResults->isDrawn) {
                    cutsceneResults->isDrawn = true;
                }
                break;
            default:
                if ((sEndingState == ENDING_SCROLL_RESULTS) && !cutsceneResults->isDrawn) {
                    cutsceneResults->isDrawn = true;
                }
                break;
        }
        cutsceneResults++;
    }
    if ((exitState != 0) && (gEndingFlags & ENDING_FOLLOW_WITH_CREDITS)) {
        exitState = 2;
    }
    return exitState;
}

Gfx* EndingCutscene_Draw(Gfx* gfx) {

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
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    gSPDisplayList(gfx++, D_303A810);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));

    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gEffectsVtxPtr = gGfxPool->effectsVtxBuffer;
    gEffectsVtxEndPtr = &gGfxPool->effectsVtxBuffer[0x7FF];
    gfx = Background_Draw(gfx, 0, SCISSOR_BOX_FULL_SCREEN);
    gfx = Course_Draw(gfx, 0);
    gfx = Course_GadgetsDraw(gfx, 0);
    gfx = EndingCutscene_DrawPodiums(gfx);

    gSPLoadUcodeL(gfx++, gspF3DLX2_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_800DCD04]));
    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
    gSPMatrix(gfx++, D_1000000.unk_20208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gfx = Camera_Draw(gfx, SCISSOR_BOX_FULL_SCREEN, 0);
    gfx = Racer_Draw(gfx, 0);
    gfx = EndingCutsceneEffects_DrawPodiumRacerCharacters(gfx);
    return EndingCutscene_DrawScrollingResults(gfx);
}

Gfx* EndingCutscene_DrawScrollingResults(Gfx* gfx) {
    EndingCutsceneResults* cutsceneResults;
    f32 textureTop;
    s32 i;

    textureTop = sEndingCurrentResultsScrollTop;

    cutsceneResults = sEndingCutsceneResults;
    for (i = 0; i < sTotalScrollResults; i++, cutsceneResults++) {
        textureTop += cutsceneResults->gapFromLast;
        if ((cutsceneResults->cmd == ENDING_CS_RESULTS_COMPLETED_ITEM) || !cutsceneResults->isDrawn ||
            textureTop > 232.0f) {
            continue;
        }

        if ((cutsceneResults->height + textureTop) < 8.0f) {
            cutsceneResults->cmd = ENDING_CS_RESULTS_COMPLETED_ITEM;
            continue;
        }
        switch (cutsceneResults->cmd) {
            case ENDING_CS_RESULTS_CONGRATULATIONS:
                if (gEndingFlags & ENDING_DRAW_CONGRATULATIONS) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sCongratulationsEndingTextAlpha);

                    gfx = func_8007B14C(gfx, func_800783AC(aCongratulationsTex), cutsceneResults->left, textureTop, 264,
                                        31, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
                }
                break;
            case ENDING_CS_RESULTS_END_SCREEN:
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sCongratulationsEndingTextAlpha);

                gfx = func_8007B14C(gfx, sEndingTex, cutsceneResults->left, textureTop, 168, 99, G_IM_FMT_RGBA,
                                    G_IM_SIZ_16b, 1, 1, 0, 0);

                if (sEndingTextTex != NULL) {
#ifdef VERSION_JP
                    gfx = func_8007B14C(gfx, sEndingTextTex, cutsceneResults->left + -14.0f, textureTop + 99.0f + 10.0f,
                                        196, 16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
#else
                    gfx = func_8007B14C(gfx, sEndingTextTex, cutsceneResults->left + -14.0f, textureTop + 99.0f + 10.0f,
                                        196, 32, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
#endif
                }
                break;
            case ENDING_CS_RESULTS_CUP_INFO:
                gfx = EndingCutscene_DrawFinalResultsCupInfo(gfx, cutsceneResults, textureTop);
                break;
            case ENDING_CS_RESULTS_RACE_RESULT:
                gfx = EndingCutscene_DrawFinalResultsRaceResult(gfx, cutsceneResults, textureTop);
                break;
            case ENDING_CS_RESULTS_TOTAL_RANKING:
                gfx = EndingCutscene_DrawTotalRanking(gfx, cutsceneResults, textureTop);
                break;
        }
    }

    if (sDrawThanksForPlaying) {
        gfx = EndingCutscene_DrawThanksForPlayingWindow(gfx);
    }
    if (sEndScreenState != END_SCREEN_INACTIVE) {
        gfx = EndingCutscene_DrawEndScreen(gfx);
    }
    return gfx;
}

Gfx* EndingCutscene_DrawFinalResultsRaceResult(Gfx* gfx, EndingCutsceneResults* cutsceneResults, f32 baseYPos) {
    s32 cupTrackNo;
    f32 left;
    bool shouldHighlight;
    s32 pad[2];
    RaceStats* raceStats;
    const char* trackName;

    cupTrackNo = cutsceneResults->course % 6;
    raceStats = &gCupRaceStats[0][cupTrackNo];
    trackName = gTrackNames[cutsceneResults->course];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    left = 160.0f;

    gfx = Font_DrawString(gfx, (left + 2.0f) - (Font_GetStringWidth(trackName, FONT_SET_3, 1) / 2),
                          (baseYPos + 16.0f) + 2.0f, trackName, 1, FONT_SET_3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    gfx = Font_DrawString(gfx, left - (Font_GetStringWidth(trackName, FONT_SET_3, 1) / 2), (baseYPos + 16.0f),
                          trackName, 1, FONT_SET_3, 0);
    gSPDisplayList(gfx++, D_8014940);

    if (raceStats->position == 1) {
        shouldHighlight = true;
    } else {
        shouldHighlight = false;
    }

    gfx = EndingCutscene_DrawFinalResultsPosition(gfx, 50, baseYPos + 26.0f, raceStats->position, shouldHighlight);
    gDPPipeSync(gfx++);
    if (0) {}
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    if (0) {}
    gDPLoadTextureBlock(gfx++, aTimerSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = Hud_DrawTimerScisThousandths(gfx, raceStats->raceTime, 110, (baseYPos + 28.0f), 1.0f);
    gDPPipeSync(gfx++);
    gfx = RecordsEntry_DrawSpeed(gfx, 194, (baseYPos + 28.0f), raceStats->maxSpeed, false, false);
    gDPPipeSync(gfx++);
    return EndingCutscene_DrawResultsRacersKOd(gfx, 110, (baseYPos + 48.0f), raceStats->racersKOd);
}

Gfx* EndingCutscene_DrawFinalResultsPosition(Gfx* gfx, s32 xPos, s32 yPos, s32 position, bool shouldHighlight) {
    s32 i;
    s32 xOffset;
    s32 width;
    s32 positionSuffix;
    s32 digits[2];
    s32 positionVar;
    s32 digit;

    positionVar = position;

    if ((position == 1) || (position == 21)) {
        positionSuffix = POSITION_SUFFIX_ST;
    } else if ((position == 2) || (position == 22)) {
        positionSuffix = POSITION_SUFFIX_ND;
    } else if ((position == 3) || (position == 23)) {
        positionSuffix = POSITION_SUFFIX_RD;
    } else {
        positionSuffix = POSITION_SUFFIX_TH;
    }

    for (i = 0; i < 2; i++) {
        digits[i] = positionVar % 10;
        positionVar /= 10;
    }

    gDPPipeSync(gfx++);

    if (shouldHighlight) {
        gfx = func_8007DB28(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 255, 255);
    }

    for (i = 0; i < 2; i++) {
        digit = digits[1 - i];
        if ((i == 0) && (digit == 0)) {
            xPos += 16;
            continue;
        }

        if (digit != 1) {
            xOffset = 0;
            width = 16;
        } else {
            xOffset = 8;
            width = 8;
        }
        gfx = func_8007B14C(gfx, func_800783AC(sFinalResultPositionDigitTexs[digit]), xPos + xOffset, yPos, width, 16,
                            G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0);
        xPos += 16;
    }

    return func_8007B14C(gfx, func_800783AC(sFinalResultsPositionSuffixTexs[positionSuffix]), xPos, yPos, 16, 16,
                         G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0);
}

Gfx* EndingCutscene_DrawTotalRanking(Gfx* gfx, EndingCutsceneResults* cutsceneResults, f32 baseYPos) {
    s32 i;
    f32 top;
    f32 left;
    s32 positionDigits[2];
    s32 ordinalSuffix;
    s32 position;
    s32 positionDigit;
    char racersKOdStr[4];

    position = gPlayer1OverallPosition;
    if ((position == 1) || (position == 21)) {
        ordinalSuffix = POSITION_SUFFIX_ST;
    } else if ((position == 2) || (position == 22)) {
        ordinalSuffix = POSITION_SUFFIX_ND;
    } else if ((position == 3) || (position == 23)) {
        ordinalSuffix = POSITION_SUFFIX_RD;
    } else {
        ordinalSuffix = POSITION_SUFFIX_TH;
    }

    for (i = 0; i < ARRAY_COUNT(positionDigits); i++) {
        positionDigits[i] = position % 10;
        position /= 10;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    left = 160.0f;
    top = baseYPos + 16.0f;

    gfx = Font_DrawString(gfx, (left + 2.0f) - (Font_GetStringWidth(sTotalRankingStr, FONT_SET_3, 1) / 2), top + 2.0f,
                          sTotalRankingStr, 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 250, 0, 255);
    gfx = Font_DrawString(gfx, left - (Font_GetStringWidth(sTotalRankingStr, FONT_SET_3, 1) / 2), top, sTotalRankingStr,
                          1, FONT_SET_3, 0);
    top += 10.0f;
    left = 122.0f;
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < ARRAY_COUNT(positionDigits); i++) {
        positionDigit = positionDigits[1 - i];
        if ((i == 0) && (positionDigit == 0)) {
            left += 28.0f;
            continue;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, aPositionDigitTexs[positionDigit], G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, (s32) (left) << 2, (s32) (top) << 2, (s32) (left + 28.0f) << 2,
                                (s32) (top + 32.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        left += 28.0f;
    }

    gDPLoadTextureBlock(gfx++, aPositionOrdinalSuffixTexs[ordinalSuffix], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPScisTextureRectangle(gfx++, (s32) (left) << 2, (s32) ((top + 12.0f)) << 2, (s32) (left + 20.0f) << 2,
                            (s32) ((top + 12.0f) + 20.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gfx = EndingCutscene_DrawResultsRacersKOd(gfx, 110, baseYPos + 70.0f, sTotalRacersKOd);

    if (sTotalRacersKOd > 0) {

        for (i = 0; i < 4; i++) {
            racersKOdStr[i] = 0;
        }

        sprintf(racersKOdStr, "%d", sTotalRacersKOd);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        i = sTotalRacersKOd / 10;
        if (sTotalRacersKOd % 10) {
            i++;
        }
        gfx = Font_DrawString(gfx, 110, (baseYPos + 70.0f) + 20.0f + (i * 10), racersKOdStr, 1, FONT_SET_3, 0);
    }
    return gfx;
}

extern const char* gDifficultyNames[];

Gfx* EndingCutscene_DrawFinalResultsCupInfo(Gfx* gfx, EndingCutsceneResults* cutsceneResults, f32 baseYPos) {
    UNUSED s32 pad;
    f32 left;
    f32 top;
    const char* name;

    name = sCupNames[sCupNameIndex];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    left = 160.0f;
    top = baseYPos + 16.0f;

    gfx = Font_DrawString(gfx, (left + 2.0f) - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), top + 2.0f, name, 1,
                          FONT_SET_3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = Font_DrawString(gfx, left - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), top, name, 1, FONT_SET_3, 0);

    top += 20.0f;
    name = gDifficultyNames[sCupDifficulty];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gfx = Font_DrawString(gfx, (left + 2.0f) - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), top + 2.0f, name, 1,
                          FONT_SET_3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    return Font_DrawString(gfx, left - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), top, name, 1, FONT_SET_3, 0);
}

void EndingCutscene_FadeInThanksForPlaying(void) {
    if (sThanksForPlayingFade < 120) {
        sThanksForPlayingFade++;
    }
}

Gfx* EndingCutscene_DrawThanksForPlayingWindow(Gfx* gfx) {
    static s32 sThanksForPlayingLeft;
    static s32 sThanksForPlayingTop;
    static s32 sThanksForPlayingWidth;
    static s32 sThanksForPlayingBackgroundAlpha;

    sThanksForPlayingBackgroundAlpha = (sThanksForPlayingFade * 255) / 120;

    gfx = func_8007A440(gfx, 12, 8, 308, 232, 0, 0, 0, sThanksForPlayingBackgroundAlpha);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sThanksForPlayingBackgroundAlpha);

    sThanksForPlayingWidth = Font_GetStringWidth(sThanksForPlayingStr, FONT_SET_1, 1);
    sThanksForPlayingLeft = (SCREEN_WIDTH - sThanksForPlayingWidth) / 2;
    sThanksForPlayingTop = SCREEN_HEIGHT / 2;

    return Font_DrawString(gfx, sThanksForPlayingLeft, sThanksForPlayingTop, sThanksForPlayingStr, 1, FONT_SET_1, 1);
}

void EndingCutscene_FadeEndScreen(void) {
    switch (sEndScreenState) {
        case END_SCREEN_FADE_IN:
            sEndScreenFade++;
            sEndScreenAlpha = (sEndScreenFade * 255) / 120;
            if (sEndScreenFade >= 120) {
                sEndScreenState = END_SCREEN_WAIT;
                sEndScreenFade = 0;
                sEndScreenAlpha = 255;
            }
            return;
        case END_SCREEN_WAIT:
            sEndScreenFade++;
            if (sEndScreenFade >= 180) {
                sEndScreenState = END_SCREEN_FADE_OUT;
                sEndScreenFade = 0;
            }
            break;
        case END_SCREEN_FADE_OUT:
            sEndScreenFade++;
            sEndScreenAlpha = 255 - (sEndScreenFade * 255) / 120;
            if (sEndScreenFade >= 120) {
                sEndScreenState = END_SCREEN_INACTIVE;
                sEndScreenFade = 0;
                sEndScreenAlpha = 0;
            }
            break;
    }
}

Gfx* EndingCutscene_DrawEndScreen(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sEndScreenAlpha);

#ifdef VERSION_JP
    gfx = func_8007B14C(gfx, sEndingTex, 76, 70, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
#else
    gfx = func_8007B14C(gfx, sEndingTex, 76, 62, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
#endif
    if (sEndingTextTex != NULL) {
#ifdef VERSION_JP
        gfx = func_8007B14C(gfx, sEndingTextTex, 62, 179, 196, 16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
#else
        gfx = func_8007B14C(gfx, sEndingTextTex, 62, 171, 196, 32, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
#endif
    }
    return gfx;
}

Gfx* EndingCutscene_DrawResultsRacersKOd(Gfx* gfx, s32 left, s32 top, s32 racersKOd) {
    s32 i;
    s32 j;
    s32 temp;
    s32 pad;
    s32 numBlocks;
    s32 remainder;

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, aHudRacersKOdTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    numBlocks = racersKOd / 10;
    remainder = racersKOd % 10;

    for (i = 0; i < numBlocks; i++) {
        temp = i * 10;
        for (j = 0; j < 10; j++) {
            gSPScisTextureRectangle(gfx++, (left + j * 10) << 2, (top + temp) << 2, (left + 8 + j * 10) << 2,
                                    (top + 8 + temp) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    if (remainder > 0) {
        for (j = 0; j < remainder; j++) {
            gSPScisTextureRectangle(gfx++, (left + j * 10) << 2, (top + numBlocks * 10) << 2, (left + 8 + j * 10) << 2,
                                    (top + 8 + numBlocks * 10) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }
    return gfx;
}

void EndingCutscene_InitPodiums(void) {
    f32 temp_fa0;
    s32 i;
    Podium* podium = gPodiums;
    Vec3f* holeVtxPositions = sPodiumHoleVtxPositions;

    if (1) {}

    for (i = 0; i < 3; podium++, i++) {
        podium->state = PODIUM_WAIT;
        podium->flags = 0;
        podium->timer = 0;
        podium->pos.x = podium->pos.z = 0.0f;
        podium->pos.y = -160.0f;
        podium->lookAt.x = 0.0f;
        podium->lookAt.y = 0.0f;
        podium->lookAt.z = 1.0f;
    }
    i = Math_Round(DEG_TO_FZXANG2(30));
    temp_fa0 = COS(i) * 60.0f;

    holeVtxPositions->x = 0.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = 0.0f;
    holeVtxPositions++;

    holeVtxPositions->x = 30.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = temp_fa0;
    holeVtxPositions++;

    holeVtxPositions->x = -30.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = temp_fa0;
    holeVtxPositions++;

    holeVtxPositions->x = -60.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = 0.0f;
    holeVtxPositions++;

    holeVtxPositions->x = -30.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = 0.0f - temp_fa0;
    holeVtxPositions++;

    holeVtxPositions->x = 30.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = 0.0f - temp_fa0;
    holeVtxPositions++;

    holeVtxPositions->x = 60.0f;
    holeVtxPositions->y = 0.0f;
    holeVtxPositions->z = 0.0f;
    holeVtxPositions++;
}

void EndingCutscene_UpdatePodiums(void) {
    Podium* podium;
    Racer* racer;
    s32 i;
    s32 j;
    s32 x;
    s32 z;
    Vtx* vtx;
    f32 podiumHoleVtxOffset;
    f32 racerHeightIncrease;

    for (i = 0, podium = gPodiums, racer = gRacers; i < 3; i++, podium++, racer++) {
        switch (podium->state) {
            case PODIUM_WAIT:
                if (gPodiumActiveFlags & PODIUM_ACTIVATED(i)) {
                    podium->state = PODIUM_RAISE;
                    podium->timer = 0;
                    podium->pos.x = racer->focusPos.x;
                    podium->pos.z = racer->focusPos.z;
                    podium->lookAt.x = racer->trueBasis.x.x;
                    podium->lookAt.y = racer->trueBasis.x.y;
                    podium->lookAt.z = racer->trueBasis.x.z;
                    Audio_TriggerSystemSE(NA_SE_64);
                }
                break;
            case PODIUM_RAISED:
                break;
            case PODIUM_RAISE:
                podium->flags |= PODIUM_DRAW_BODY | PODIUM_DRAW_HOLE;
                podium->timer++;
                podiumHoleVtxOffset = podium->timer / 60.0f;

                if (podiumHoleVtxOffset > 1.0f) {
                    podiumHoleVtxOffset = 1.0f;
                }

                vtx = gPodiumDrawDataPtr->holeVtxs[i];
                for (j = 0; j < 13; j++) {
                    if (j < 7) {
                        x = sPodiumHoleVtxPositions[j].x;
                        z = sPodiumHoleVtxPositions[j].z;
                    } else if (j == 12) {
                        x = sPodiumHoleVtxPositions[1].x * podiumHoleVtxOffset;
                        z = sPodiumHoleVtxPositions[1].z * podiumHoleVtxOffset;
                    } else {
                        x = sPodiumHoleVtxPositions[j - 5].x * podiumHoleVtxOffset;
                        z = sPodiumHoleVtxPositions[j - 5].z * podiumHoleVtxOffset;
                    }

                    SET_VTX(vtx, x, 0, z, 0, 0, 0, 0, 0, 255);
                    vtx++;
                }

                podium->pos.y = (((sPodiumHeights[i] - -160.0f) * podium->timer) / 270.0f) + -160.0f;
                if (podium->timer >= 270) {
                    podium->state = PODIUM_RAISED;
                    podium->pos.y = sPodiumHeights[i];
                    podium->timer = 0;
                }
                racerHeightIncrease = (podium->pos.y + 120.0f) - racer->shadowPos.y;
                if (racerHeightIncrease > 0.0f) {
                    racer->podiumHeight += racerHeightIncrease;
                }
                break;
        }

        if (podium->flags & PODIUM_DRAW_HOLE) {
            Matrix_SetLockedLookAt(&gPodiumDrawDataPtr->holeMtx[i], NULL, sPodiumHoleScale, sPodiumHoleScale,
                                   sPodiumHoleScale, podium->lookAt.x, podium->lookAt.y, podium->lookAt.z, 0.0f, 1.0f,
                                   0.0f, podium->pos.x, 0.0f, podium->pos.z);
        }
        if (podium->flags & PODIUM_DRAW_BODY) {
            Matrix_SetLockedLookAt(&gPodiumDrawDataPtr->bodyMtx[i], NULL, sPodiumBodyScale, sPodiumBodyScale,
                                   sPodiumBodyScale, podium->lookAt.x, podium->lookAt.y, podium->lookAt.z, 0.0f, 1.0f,
                                   0.0f, podium->pos.x, podium->pos.y, podium->pos.z);
        }
    }
}

Gfx* EndingCutscene_DrawPodiums(Gfx* gfx) {
    s32 i;
    Podium* podium;

    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CLIPPING);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTextureDetail(gfx++, G_TD_CLAMP);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);

    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, (G_RM_AA_ZB_OPA_SURF) & ~Z_CMP, (G_RM_AA_ZB_OPA_SURF2) & ~Z_CMP);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetDepthSource(gfx++, G_ZS_PRIM);
    gDPSetPrimDepth(gfx++, 0x7FC0, 0);

    for (i = 0, podium = gPodiums; i < 3; i++, podium++) {
        if (!(podium->flags & PODIUM_DRAW_HOLE)) {
            continue;
        }
        gSPMatrix(gfx++, &gPodiumDrawDataPtr->holeMtx[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, gPodiumDrawDataPtr->holeVtxs[i], 13, 0);
        gSP2Triangles(gfx++, 0, 7, 1, 0, 0, 8, 2, 0);
        gSP2Triangles(gfx++, 0, 9, 3, 0, 0, 10, 4, 0);
        gSP2Triangles(gfx++, 0, 11, 5, 0, 0, 12, 6, 0);
    }

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);

    gDPSetDepthSource(gfx++, G_ZS_PIXEL);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0, podium = gPodiums; i < 3; i++, podium++) {
        if (!(podium->flags & PODIUM_DRAW_BODY)) {
            continue;
        }
        gSPMatrix(gfx++, &gPodiumDrawDataPtr->bodyMtx[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, sPodiumDLs[i]);
    }

    return gfx;
}
