#include "global.h"
#include "audio.h"
#include "fzx_camera.h"
#include "fzx_racer.h"
#include "fzx_game.h"
#include "fzx_course.h"
#include "fzx_machine.h"
#include "fzx_save.h"
#include "fzx_effects.h"
#include "unk_gfx.h"
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER(machine_custom_gfx.h)
#include ASSET_HEADER(hud_gfx.h)
#include ASSET_HEADER(machine_global_gfx.h)
#include ASSET_HEADER(machine_models.h)

s32 gTotalRacers;
Racer* sLastRacer;
Racer* sRivalRacer;
Vtx* gEffectsVtxPtr;
Vtx* gEffectsVtxEndPtr;
s16 gPlayerLives[4];
s16 gPlayerCharacters[4];
s16 gPlayerMachineSkins[4];
f32 gPlayerEngine[4];
s32 gVsRacePlayerVictoryCount[4];
s32 gVsRacePlayerPoints[4];
s32 D_800E5F20[4];
s32 D_800E5F30[4];
Racer* gRacersByPosition[30];
s32 gNearestRacer;
s16 D_800E5FBC;
s16 sSpunOutRacers;
s16 D_800E5FC0;
s16 gRacersRetired;
s16 gRacersFinished;
s16 gCpuRacersRetired;
s16 gPlayerRacersRetired;
s16 gPlayerRacersFinished;
s16 sLastMultiplayerTotalRacerCount;
s16 sLastMultiplayerPlayerCount;
s16 gEnableRaceSfx;
s16 gRacersKOd;
s16 D_800E5FD4;
s16 D_800E5FD6;
s32 sRaceFrameCount;
s32 gPracticeBestLap;
s16 gStartNewBestLap;
s16 gCurrentTimeAttackRecordPosition;
s16 gCurrentTimeAttackHasMaxSpeed;
s16 gBestTimedLap;
Vec3s* sPipeFogColors;
Vec3s* sTunnelFogColors;
s32 D_800E5FF0;
Ghost gGhosts[3];
Ghost* gFastestGhost;
s8 sGhostReplayRecordingBuffer[16200];
s32 sGhostReplayRecordingSize;
s32 sGhostReplayRecordingEnd;
s32 sReplayRecordFrameCount;
s8* sGhostReplayRecordingPtr;
s32 sReplayRecordPosX;
s32 sReplayRecordPosY;
s32 sReplayRecordPosZ;
s16 D_800F5DE4;
s16 gUnableToRecordGhost;
s16 D_800F5DE8;
s16 D_800F5DEA;
GhostRacer gGhostRacers[3];
s32 D_800F5E8C;
GhostRacer* gFastestGhostRacer;
UNUSED s32 D_800F5E94;
s32 gRaceIntroTimer;
RacerPairInfo sRacerPairInfo[TOTAL_RACER_COUNT * (TOTAL_RACER_COUNT - 1) / 2];
f32 D_800F809C;
f32 D_800F80A0;
f32 D_800F80A4;
s32 gPlayerReverseTimer[4];
s32 D_800F80B8;
f32 sCourseHalfLength;
f32 sCourseNegativeHalfLength;
s16 D_800F80C4;
Machine gMachines[30];
CustomMachineInfo sCustomMachineInfo[30];
u8 sRecordsMachineIndices[7];

TexturePtr sPosition1PMarkerTexs[] = {
    aFirstPlaceMarker1PTex,
    aSecondPlaceMarker1PTex,
    aThirdPlaceMarker1PTex,
};

TexturePtr sPositionMPMarkerTexs[] = {
    aFirstPlaceMarkerMPTex,
    aSecondPlaceMarkerMPTex,
    aThirdPlaceMarkerMPTex,
};

TexturePtr D_800CDAB8[] = {
    aExplosion1Tex, aExplosion2Tex, aExplosion3Tex, aExplosion4Tex,
    aExplosion5Tex, aExplosion6Tex, aExplosion7Tex, aExplosion8Tex,
};

// Machine Models
Gfx* D_800CDAD8[] = {
    D_9001210, D_9001DA0, D_90027D0, D_9003050, D_9003870, D_9003F90, D_900CF48, D_90057A8, D_90061A0, D_9006A70,
    D_90078F0, D_9008060, D_90089A0, D_9009358, D_9009980, D_900A150, D_900AC40, D_900B288, D_900BD28, D_900C550,
    D_9004B98, D_900D898, D_900DFF8, D_900E698, D_900EFE8, D_900F790, D_90100F8, D_9010C38, D_90113D8, D_9011EA8,
};

Gfx* D_800CDB50[] = {
    D_9015400, D_9015938, D_9015658, D_9014B40, D_9014DE0, D_9015088, D_90148F8,
};

Gfx* D_800CDB6C[] = {
    D_9015B58, D_9017350, D_9016DA0, D_9015F50, D_9016298, D_9016530, D_9016948,
};

Gfx* D_800CDB88[] = {
    D_90186C0, D_9017B18, D_9018230, D_9017BF0, D_90183F0, D_9017D20, D_9017EC8,
};

Vtx* D_800CDBA4[] = {
    D_3004F18, D_3006C78, D_3008C18, D_300A4E8, D_300BB78, D_300D3F8, D_3020758, D_30104F8, D_3011778,
    D_3012EC8, D_30140D8, D_3015418, D_3016958, D_30177D8, D_3018E98, D_301A2E8, D_301B7B8, D_301CA98,
    D_301E058, D_301F328, D_300E9A8, D_3022178, D_3023358, D_3024D78, D_3025DB8, D_3027068, D_30285C8,
    D_3029648, D_302A908, D_302B9F8, D_3036A78, D_3036EB8, D_30372F8, D_3037738, D_3037B78, D_3037FB8,
    D_30383F8, D_3038838, D_3038C78, D_30390B8, D_30394F8, D_3039938, D_3039D78, D_303A1B8,
};

TexturePtr D_800CDC54[] = {
    D_3004F58, D_3006CB8, D_3008C58, D_300A528, D_300BBB8, D_300D438, D_3020798, D_3010538, D_30117B8,
    D_3012F08, D_3014118, D_3015458, D_3016998, D_3017818, D_3018ED8, D_301A328, D_301B7F8, D_301CAD8,
    D_301E098, D_301F368, D_300E9E8, D_30221B8, D_3023398, D_3024DB8, D_3025DF8, D_30270A8, D_3028608,
    D_3029688, D_302A948, D_302BA38, D_3036AB8, D_3036EF8, D_3037338, D_3037778, D_3037BB8, D_3037FF8,
    D_3038438, D_3038878, D_3038CB8, D_30390F8, D_3039538, D_3039978, D_3039DB8, D_303A1F8,
};

// Shadow Types
u8 D_800CDD04[] = { 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28,
                    0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27,
                    0x28, 0x29, 0x1E, 0x24, 0x23, 0x1F, 0x20, 0x21, 0x22, 0x1E, 0x24, 0x23, 0x1F,
                    0x20, 0x21, 0x22, 0x1E, 0x24, 0x23, 0x1F, 0x20, 0x21, 0x22 };

// Machine Load Textures
Gfx* D_800CDD38[] = {
    D_8022F8C0, D_802308E0, D_80231900, D_80232920, D_80233940, D_80234960, D_80235980, D_802369A0,
    D_802379C0, D_802389E0, D_80239A00, D_8023AA20, D_8023BA40, D_8023CA60, D_8023DA80, D_8023EAA0,
    D_8023FAC0, D_80240AE0, D_80241B00, D_80242B20, D_80243B40, D_80244B60, D_80245B80, D_80246BA0,
    D_80247BC0, D_80248BE0, D_80249C00, D_8024AC20, D_8024BC40, D_8024CC60,
};

// Machine Models (6 Different LOD)
Gfx* D_800CDDB0[] = {
    D_8022FA58, D_8022FE48, D_80230198, D_80230480, D_802306F0, D_7045098,  D_80230A78, D_80230E68, D_802311B8,
    D_802314A0, D_80231710, D_7045098,  D_80231A98, D_80231E88, D_802321D8, D_802324C0, D_80232730, D_7045098,
    D_80232AB8, D_80232EA8, D_802331F8, D_802334E0, D_80233750, D_7045098,  D_80233AD8, D_80233EC8, D_80234218,
    D_80234500, D_80234770, D_7045098,  D_80234AF8, D_80234EE8, D_80235238, D_80235520, D_80235790, D_7045098,
    D_80235B18, D_80235F08, D_80236258, D_80236540, D_802367B0, D_7045098,  D_80236B38, D_80236F28, D_80237278,
    D_80237560, D_802377D0, D_7045098,  D_80237B58, D_80237F48, D_80238298, D_80238580, D_802387F0, D_7045098,
    D_80238B78, D_80238F68, D_802392B8, D_802395A0, D_80239810, D_7045098,  D_80239B98, D_80239F88, D_8023A2D8,
    D_8023A5C0, D_8023A830, D_7045098,  D_8023ABB8, D_8023AFA8, D_8023B2F8, D_8023B5E0, D_8023B850, D_7045098,
    D_8023BBD8, D_8023BFC8, D_8023C318, D_8023C600, D_8023C870, D_7045098,  D_8023CBF8, D_8023CFE8, D_8023D338,
    D_8023D620, D_8023D890, D_7045098,  D_8023DC18, D_8023E008, D_8023E358, D_8023E640, D_8023E8B0, D_7045098,
    D_8023EC38, D_8023F028, D_8023F378, D_8023F660, D_8023F8D0, D_7045098,  D_8023FC58, D_80240048, D_80240398,
    D_80240680, D_802408F0, D_7045098,  D_80240C78, D_80241068, D_802413B8, D_802416A0, D_80241910, D_7045098,
    D_80241C98, D_80242088, D_802423D8, D_802426C0, D_80242930, D_7045098,  D_80242CB8, D_802430A8, D_802433F8,
    D_802436E0, D_80243950, D_7045098,  D_80243CD8, D_802440C8, D_80244418, D_80244700, D_80244970, D_7045098,
    D_80244CF8, D_802450E8, D_80245438, D_80245720, D_80245990, D_7045098,  D_80245D18, D_80246108, D_80246458,
    D_80246740, D_802469B0, D_7045098,  D_80246D38, D_80247128, D_80247478, D_80247760, D_802479D0, D_7045098,
    D_80247D58, D_80248148, D_80248498, D_80248780, D_802489F0, D_7045098,  D_80248D78, D_80249168, D_802494B8,
    D_802497A0, D_80249A10, D_7045098,  D_80249D98, D_8024A188, D_8024A4D8, D_8024A7C0, D_8024AA30, D_7045098,
    D_8024ADB8, D_8024B1A8, D_8024B4F8, D_8024B7E0, D_8024BA50, D_7045098,  D_8024BDD8, D_8024C1C8, D_8024C518,
    D_8024C800, D_8024CA70, D_7045098,  D_8024CDF8, D_8024D1E8, D_8024D538, D_8024D820, D_8024DA90, D_7045098,
};

Gfx* D_800CE080[] = {
    D_7045278, D_70469D8, D_70476D8, D_7047F70, D_7048550, D_7045098,
};

Gfx* (*sMachineLoadTexturesFuncs[])(Gfx*) = {
    Machine_DrawLoadBlueFalconTextures,      // CAPTAIN_FALCON
    Machine_DrawLoadGoldenFoxTextures,       // DR_STEWART
    Machine_DrawLoadWildGooseTextures,       // PICO
    Machine_DrawLoadFireStingrayTextures,    // SAMURAI_GOROH
    Machine_DrawLoadWhiteCatTextures,        // JODY_SUMMER
    Machine_DrawLoadRedGazelleTextures,      // MIGHTY_GAZELLE
    Machine_DrawLoadGreatStarTextures,       // MR_EAD
    Machine_DrawLoadIronTigerTextures,       // BABA
    Machine_DrawLoadDeepClawTextures,        // OCTOMAN
    Machine_DrawLoadTwinNorittaTextures,     // GOMAR_AND_SHIOH
    Machine_DrawLoadSuperPiranhaTextures,    // KATE_ALEN
    Machine_DrawLoadMightyHurricaneTextures, // ROGER_BUSTER
    Machine_DrawLoadLittleWyvernTextures,    // JAMES_MCCLOUD
    Machine_DrawLoadSpaceAnglerTextures,     // LEON
    Machine_DrawLoadGreenPantherTextures,    // ANTONIO_GUSTER
    Machine_DrawLoadBlackBullTextures,       // BLACK_SHADOW
    Machine_DrawLoadWildBoarTextures,        // MICHAEL_CHAIN
    Machine_DrawLoadAstroRobinTextures,      // JACK_LEVIN
    Machine_DrawLoadKingMeteorTextures,      // SUPER_ARROW
    Machine_DrawLoadQueenMeteorTextures,     // MRS_ARROW
    Machine_DrawLoadWonderWaspTextures,      // JOHN_TANAKA
    Machine_DrawLoadHyperSpeederTextures,    // BEASTMAN
    Machine_DrawLoadDeathAnchorTextures,     // ZODA
    Machine_DrawLoadCrazyBearTextures,       // DR_CLASH
    Machine_DrawLoadNightThunderTextures,    // SILVER_NEELSEN
    Machine_DrawLoadBigFangTextures,         // BIO_REX
    Machine_DrawLoadMightyTyphoonTextures,   // DRAQ
    Machine_DrawLoadMadWolfTextures,         // BILLY
    Machine_DrawLoadSonicPhantomTextures,    // THE_SKULL
    Machine_DrawLoadBloodHawkTextures,       // BLOOD_FALCON
    Machine_DrawLoadBlueFalconTextures,      // Super Falcon
    Machine_DrawLoadFireStingrayTextures,    // Super Stingray
    Machine_DrawLoadWhiteCatTextures,        // Super Cat
};

Gfx* (*sMachineDrawFuncs[][5])(Gfx*) = {
    { Machine_DrawBlueFalconLod1, Machine_DrawBlueFalconLod2, Machine_DrawBlueFalconLod3, Machine_DrawBlueFalconLod4,
      Machine_DrawBlueFalconLod5 }, // CAPTAIN_FALCON
    { Machine_DrawGoldenFoxLod1, Machine_DrawGoldenFoxLod2, Machine_DrawGoldenFoxLod3, Machine_DrawGoldenFoxLod4,
      Machine_DrawGoldenFoxLod5 }, // DR_STEWART
    { Machine_DrawWildGooseLod1, Machine_DrawWildGooseLod2, Machine_DrawWildGooseLod3, Machine_DrawWildGooseLod4,
      Machine_DrawWildGooseLod5 }, // PICO
    { Machine_DrawFireStingrayLod1, Machine_DrawFireStingrayLod2, Machine_DrawFireStingrayLod3,
      Machine_DrawFireStingrayLod4, Machine_DrawFireStingrayLod5 }, // SAMURAI_GOROH
    { Machine_DrawWhiteCatLod1, Machine_DrawWhiteCatLod2, Machine_DrawWhiteCatLod3, Machine_DrawWhiteCatLod4,
      Machine_DrawWhiteCatLod5 }, // JODY_SUMMER
    { Machine_DrawRedGazelleLod1, Machine_DrawRedGazelleLod2, Machine_DrawRedGazelleLod3, Machine_DrawRedGazelleLod4,
      Machine_DrawRedGazelleLod5 }, // MIGHTY_GAZELLE
    { Machine_DrawGreatStarLod1, Machine_DrawGreatStarLod2, Machine_DrawGreatStarLod3, Machine_DrawGreatStarLod4,
      Machine_DrawGreatStarLod5 }, // MR_EAD
    { Machine_DrawIronTigerLod1, Machine_DrawIronTigerLod2, Machine_DrawIronTigerLod3, Machine_DrawIronTigerLod4,
      Machine_DrawIronTigerLod5 }, // BABA
    { Machine_DrawDeepClawLod1, Machine_DrawDeepClawLod2, Machine_DrawDeepClawLod3, Machine_DrawDeepClawLod4,
      Machine_DrawDeepClawLod5 }, // OCTOMAN
    { Machine_DrawTwinNorittaLod1, Machine_DrawTwinNorittaLod2, Machine_DrawTwinNorittaLod3,
      Machine_DrawTwinNorittaLod4, Machine_DrawTwinNorittaLod5 }, // GOMAR_AND_SHIOH
    { Machine_DrawSuperPiranhaLod1, Machine_DrawSuperPiranhaLod2, Machine_DrawSuperPiranhaLod3,
      Machine_DrawSuperPiranhaLod4, Machine_DrawSuperPiranhaLod5 }, // KATE_ALEN
    { Machine_DrawMightyHurricaneLod1, Machine_DrawMightyHurricaneLod2, Machine_DrawMightyHurricaneLod3,
      Machine_DrawMightyHurricaneLod4, Machine_DrawMightyHurricaneLod5 }, // ROGER_BUSTER
    { Machine_DrawLittleWyvernLod1, Machine_DrawLittleWyvernLod2, Machine_DrawLittleWyvernLod3,
      Machine_DrawLittleWyvernLod4, Machine_DrawLittleWyvernLod5 }, // JAMES_MCCLOUD
    { Machine_DrawSpaceAnglerLod1, Machine_DrawSpaceAnglerLod2, Machine_DrawSpaceAnglerLod3,
      Machine_DrawSpaceAnglerLod4, Machine_DrawSpaceAnglerLod5 }, // LEON
    { Machine_DrawGreenPantherLod1, Machine_DrawGreenPantherLod2, Machine_DrawGreenPantherLod3,
      Machine_DrawGreenPantherLod4, Machine_DrawGreenPantherLod5 }, // ANTONIO_GUSTER
    { Machine_DrawBlackBullLod1, Machine_DrawBlackBullLod2, Machine_DrawBlackBullLod3, Machine_DrawBlackBullLod4,
      Machine_DrawBlackBullLod5 }, // BLACK_SHADOW
    { Machine_DrawWildBoarLod1, Machine_DrawWildBoarLod2, Machine_DrawWildBoarLod3, Machine_DrawWildBoarLod4,
      Machine_DrawWildBoarLod5 }, // MICHAEL_CHAIN
    { Machine_DrawAstroRobinLod1, Machine_DrawAstroRobinLod2, Machine_DrawAstroRobinLod3, Machine_DrawAstroRobinLod4,
      Machine_DrawAstroRobinLod5 }, // JACK_LEVIN
    { Machine_DrawKingMeteorLod1, Machine_DrawKingMeteorLod2, Machine_DrawKingMeteorLod3, Machine_DrawKingMeteorLod4,
      Machine_DrawKingMeteorLod5 }, // SUPER_ARROW
    { Machine_DrawQueenMeteorLod1, Machine_DrawQueenMeteorLod2, Machine_DrawQueenMeteorLod3,
      Machine_DrawQueenMeteorLod4, Machine_DrawQueenMeteorLod5 }, // MRS_ARROW
    { Machine_DrawWonderWaspLod1, Machine_DrawWonderWaspLod2, Machine_DrawWonderWaspLod3, Machine_DrawWonderWaspLod4,
      Machine_DrawWonderWaspLod5 }, // JOHN_TANAKA
    { Machine_DrawHyperSpeederLod1, Machine_DrawHyperSpeederLod2, Machine_DrawHyperSpeederLod3,
      Machine_DrawHyperSpeederLod4, Machine_DrawHyperSpeederLod5 }, // BEASTMAN
    { Machine_DrawDeathAnchorLod1, Machine_DrawDeathAnchorLod2, Machine_DrawDeathAnchorLod3,
      Machine_DrawDeathAnchorLod4, Machine_DrawDeathAnchorLod5 }, // ZODA
    { Machine_DrawCrazyBearLod1, Machine_DrawCrazyBearLod2, Machine_DrawCrazyBearLod3, Machine_DrawCrazyBearLod4,
      Machine_DrawCrazyBearLod5 }, // DR_CLASH
    { Machine_DrawNightThunderLod1, Machine_DrawNightThunderLod2, Machine_DrawNightThunderLod3,
      Machine_DrawNightThunderLod4, Machine_DrawNightThunderLod5 }, // SILVER_NEELSEN
    { Machine_DrawBigFangLod1, Machine_DrawBigFangLod2, Machine_DrawBigFangLod3, Machine_DrawBigFangLod4,
      Machine_DrawBigFangLod5 }, // BIO_REX
    { Machine_DrawMightyTyphoonLod1, Machine_DrawMightyTyphoonLod2, Machine_DrawMightyTyphoonLod3,
      Machine_DrawMightyTyphoonLod4, Machine_DrawMightyTyphoonLod5 }, // DRAQ
    { Machine_DrawMadWolfLod1, Machine_DrawMadWolfLod2, Machine_DrawMadWolfLod3, Machine_DrawMadWolfLod4,
      Machine_DrawMadWolfLod5 }, // BILLY
    { Machine_DrawSonicPhantomLod1, Machine_DrawSonicPhantomLod2, Machine_DrawSonicPhantomLod3,
      Machine_DrawSonicPhantomLod4, Machine_DrawSonicPhantomLod5 }, // THE_SKULL
    { Machine_DrawBloodHawkLod1, Machine_DrawBloodHawkLod2, Machine_DrawBloodHawkLod3, Machine_DrawBloodHawkLod4,
      Machine_DrawBloodHawkLod5 }, // BLOOD_FALCON
    { Machine_DrawSuperFalconLod1, Machine_DrawSuperFalconLod2, Machine_DrawSuperFalconLod3,
      Machine_DrawSuperFalconLod4, Machine_DrawSuperFalconLod5 }, // Super Falcon
    { Machine_DrawSuperStingrayLod1, Machine_DrawSuperStingrayLod2, Machine_DrawSuperStingrayLod3,
      Machine_DrawSuperStingrayLod4, Machine_DrawSuperStingrayLod5 }, // Super Stingray
    { Machine_DrawSuperCatLod1, Machine_DrawSuperCatLod2, Machine_DrawSuperCatLod3, Machine_DrawSuperCatLod4,
      Machine_DrawSuperCatLod5 }, // Super Cat
};

#define VOICE_FEMALE 0
#define VOICE_MALE 1

u8 sCharacterVoices[] = {
    VOICE_MALE,   // CAPTAIN_FALCON
    VOICE_MALE,   // DR_STEWART
    VOICE_MALE,   // PICO
    VOICE_MALE,   // SAMURAI_GOROH
    VOICE_FEMALE, // JODY_SUMMER
    VOICE_MALE,   // MIGHTY_GAZELLE
    VOICE_MALE,   // MR_EAD
    VOICE_FEMALE, // BABA
    VOICE_MALE,   // OCTOMAN
    VOICE_MALE,   // GOMAR_AND_SHIOH
    VOICE_FEMALE, // KATE_ALEN
    VOICE_MALE,   // ROGER_BUSTER
    VOICE_MALE,   // JAMES_MCCLOUD
    VOICE_MALE,   // LEON
    VOICE_MALE,   // ANTONIO_GUSTER
    VOICE_MALE,   // BLACK_SHADOW
    VOICE_MALE,   // MICHAEL_CHAIN
    VOICE_MALE,   // JACK_LEVIN
    VOICE_MALE,   // SUPER_ARROW
    VOICE_FEMALE, // MRS_ARROW
    VOICE_MALE,   // JOHN_TANAKA
    VOICE_MALE,   // BEASTMAN
    VOICE_MALE,   // ZODA
    VOICE_MALE,   // DR_CLASH
    VOICE_MALE,   // SILVER_NEELSEN
    VOICE_MALE,   // BIO_REX
    VOICE_MALE,   // DRAQ
    VOICE_MALE,   // BILLY
    VOICE_MALE,   // THE_SKULL
    VOICE_MALE,   // BLOOD_FALCON
};

// Dma Read Data
u8 D_800CE3D0[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0A, 0x14, 0x1E, 0x28, 0x32, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x32, 0x28, 0x1E,
    0x14, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x1E, 0x32, 0x46, 0x5A,
    0x6E, 0x5A, 0x46, 0x32, 0x1E, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x14, 0x32, 0x50, 0x6E, 0x8C, 0xAA, 0xC8, 0xE6, 0xC8,
    0xAA, 0x8C, 0x6E, 0x50, 0x32, 0x14, 0x00, 0x00, 0x00,
};

s16 gSettingVsHandicap = 0;
s16 gSettingVsCom = 1;

f32 D_800CE4D8 = 2000.0f;

s8 gTotalLives[] = { 5, 4, 3, 2 };

Vec3s sVenuePipeFogColors[] = {
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
};

Vec3s sVenueTunnelFogColors[] = {
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
};

s32 gRacePositionPoints[] = {
    100, 93, 87, 81, 76, 71, 66, 62, 58, 54, 50, 47, 44, 41, 38,
    35,  33, 31, 29, 27, 25, 23, 22, 21, 20, 19, 18, 17, 16, 15,
};

s32 sVsRacePositionPoints[] = { 5, 3, 1, 0 };

f32 D_800CE748 = 0.1f;
f32 D_800CE74C = 0.1f;
f32 D_800CE750 = 0.1f;

f32 D_800CE754 = 250.0f;

UNUSED Vec3f D_800CE758 = { 0 };

s16 D_800CE764 = 60;
s32 D_800CE768 = 700;
f32 D_800CE76C = 0.01f;
f32 D_800CE770 = 25.0f;
s32 sInitialBoostTimer = 100;
f32 sEnergyRefillScale = 0.008f;
s16 D_800CE77C = 0;
s16 D_800CE780 = 1;
s16 D_800CE784 = 0;

#if BUILD_REVISION >= REVISION_C
s16 gGreyscaleMachinePart = false;
#endif

// clang-format off
BoosterInfo sBoosterInfos[] = {
    { 4, { { -87.0f, 22.0f, -208.0f }, { -87.0f, 60.0f, -208.0f }, { 87.0f, 22.0f, -208.0f }, { 87.0f, 60.0f, -208.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 4, { { -73.0f, 25.0f, -202.0f }, { -26.0f, 25.0f, -202.0f }, { 24.0f, 25.0f, -202.0f }, { 72.0f, 25.0f, -202.0f } }, { 12.0f, 12.0f, 12.0f, 12.0f } },
    { 3, { { 28.0f, 36.0f, -236.0f }, { -31.0f, 36.0f, -236.0f }, { 0.0f, 127.0f, -262.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 2, { { -33.0f, 55.0f, -170.0f }, { 33.0f, 52.0f, -170.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 4, { { -50.0f, 19.0f, -222.0f }, { 48.0f, 19.0f, -222.0f }, { -83.0f, 19.0f, -222.0f }, { 81.0f, 19.0f, -222.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 1, { { 2.0f, 29.0f, -226.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 21.0f, 0.0f, 0.0f, 0.0f } },
    { 4, { { -68.0f, 58.0f, -205.0f }, { -23.0f, 58.0f, -205.0f }, { 22.0f, 58.0f, -205.0f }, { 67.0f, 58.0f, -205.0f } }, { 12.0f, 12.0f, 12.0f, 12.0f } },
    { 2, { { -85.0f, 31.0f, -276.0f }, { 85.0f, 31.0f, -276.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 12.0f, 12.0f, 0.0f, 0.0f } },
    { 4, { { -52.0f, 29.0f, -213.0f }, { -17.0f, 29.0f, -213.0f }, { 17.0f, 29.0f, -213.0f }, { 52.0f, 29.0f, -213.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 2, { { -82.0f, 40.0f, -215.0f }, { 82.0f, 40.0f, -215.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 12.0f, 12.0f, 0.0f, 0.0f } },
    { 2, { { -35.0f, 36.0f, -188.0f }, { 35.0f, 36.0f, -188.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 86.0f, -200.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 23.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -67.0f, 50.0f, -218.0f }, { 67.0f, 50.0f, -218.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 42.0f, -230.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -27.0f, 36.0f, -201.0f }, { 27.0f, 36.0f, -201.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 3, { { -56.0f, 30.0f, -235.0f }, { 54.0f, 30.0f, -235.0f }, { 0.0f, 30.0f, -235.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 2, { { -30.0f, 37.0f, -218.0f }, { 29.0f, 37.0f, -218.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 17.0f, 17.0f, 0.0f, 0.0f } },
    { 2, { { -32.0f, 35.0f, -229.0f }, { 33.0f, 35.0f, -229.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 9.0f, 9.0f, 0.0f, 0.0f } },
    { 3, { { -45.0f, 37.0f, -208.0f }, { 45.0f, 37.0f, -208.0f }, { 0.0f, 115.0f, -208.0f }, { 0.0f, 0.0f, 0.0f } }, { 19.0f, 19.0f, 19.0f, 0.0f } },
    { 2, { { 0.0f, 32.0f, -228.0f }, { 0.0f, 95.0f, -221.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 2, { { -27.0f, 94.0f, -136.0f }, { 27.0f, 94.0f, -136.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 3, { { -86.0f, 28.0f, -242.0f }, { 87.0f, 28.0f, -242.0f }, { 0.0f, 33.0f, -242.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 20.0f, 0.0f } },
    { 1, { { 0.0f, 91.0f, -220.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 18.0f, 0.0f, 0.0f, 0.0f } },
    { 3, { { -62.0f, 65.0f, -226.0f }, { 60.0f, 65.0f, -226.0f }, { 0.0f, 65.0f, -226.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 4, { { -83.0f, 30.0f, -220.0f }, { -28.0f, 30.0f, -220.0f }, { 28.0f, 30.0f, -220.0f }, { 83.0f, 30.0f, -220.0f } }, { 15.0f, 15.0f, 15.0f, 15.0f } },
    { 3, { { -75.0f, 31.0f, -226.0f }, { 75.0f, 31.0f, -226.0f }, { 0.0f, 100.0f, -226.0f }, { 0.0f, 0.0f, 0.0f } }, { 22.0f, 22.0f, 20.0f, 0.0f } },
    { 3, { { 0.0f, 33.0f, -210.0f }, { 0.0f, 90.0f, -210.0f }, { 0.0f, 150.0f, -210.0f }, { 0.0f, 0.0f, 0.0f } }, { 17.0f, 17.0f, 17.0f, 0.0f } },
    { 1, { { 0.0f, 123.0f, -206.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 28.0f, -225.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 0.0f, 0.0f, 0.0f } },
    { 4, { { -84.0f, 25.0f, -234.0f }, { -28.0f, 25.0f, -234.0f }, { 28.0f, 25.0f, -234.0f }, { 83.0f, 25.0f, -234.0f } }, { 17.0f, 17.0f, 17.0f, 17.0f } },
    { 1, { { 0.0f, 34.0f, -224.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -130.0f, 40.0f, -225.0f }, { 130.0f, 40.0f, -225.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 2, { { -30.0f, 46.0f, -228.0f }, { 30.0f, 46.0f, -228.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 0.0f, 0.0f } },
    { 2, { { -32.0f, 33.0f, -232.0f }, { 32.0f, 33.0f, -232.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 3, { { -65.0f, 30.0f, -240.0f }, { 65.0f, 30.0f, -240.0f }, { 0.0f, 30.0f, -240.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 16.0f, 0.0f } },
    { 2, { { -95.0f, 30.0f, -229.0f }, { 100.0f, 30.0f, -229.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 4, { { -98.0f, 34.0f, -229.0f }, { -33.0f, 34.0f, -229.0f }, { 32.0f, 34.0f, -229.0f }, { 97.0f, 34.0f, -229.0f } }, { 18.0f, 18.0f, 18.0f, 18.0f } },
};
// clang-format on

f32 D_800CF15C = 0.1f;

f32 gBodyHealthValues[] = {
    190.0f, 178.0f, 166.0f, 154.0f, 142.0f,
};

f32 D_800CF174[] = {
    0.210f, 0.207f, 0.204f, 0.201f, 0.198f,
};

f32 D_800CF188[] = {
    1.277f, 1.237f, 1.197f, 1.157f, 1.117f,
};

f32 D_800CF19C[] = {
    0.397f, 0.367f, 0.337f, 0.307f, 0.277f,
};

// clang-format off
Machine sDefaultMachines[] = {
    { CUSTOM_MACHINE_DEFAULT, 0, 0, { 0, 211, 0, 77 }, { 0, 0, 87, 77 }, { 255, 102, 48, 77 }, 7, { BODY_B, BOOST_C, GRIP_B }, 1260 },                // CAPTAIN_FALCON
    { CUSTOM_MACHINE_DEFAULT, 1, 1, { 255, 226, 43, 120 }, { 205, 255, 133, 80 }, { 25, 255, 255, 160 }, 3, { BODY_D, BOOST_A, GRIP_D }, 1420 },      // DR_STEWART
    { CUSTOM_MACHINE_DEFAULT, 2, 2, { 0, 75, 190, 100 }, { 134, 81, 65, 100 }, { 73, 163, 16, 100 }, 6, { BODY_B, BOOST_B, GRIP_C }, 1620 },          // PICO
    { CUSTOM_MACHINE_DEFAULT, 3, 3, { 245, 52, 72, 43 }, { 72, 52, 121, 120 }, { 146, 52, 245, 65 }, 5, { BODY_A, BOOST_D, GRIP_B }, 1960 },          // SAMURAI_GOROH
    { CUSTOM_MACHINE_DEFAULT, 4, 4, { 111, 255, 0, 255 }, { 79, 0, 182, 168 }, { 184, 0, 133, 0 }, 2, { BODY_C, BOOST_C, GRIP_A }, 1150 },            // JODY_SUMMER
    { CUSTOM_MACHINE_DEFAULT, 5, 5, { 255, 0, 74, 36 }, { 0, 0, 74, 101 }, { 0, 190, 74, 46 }, 1, { BODY_E, BOOST_A, GRIP_C }, 1330 },                // MIGHTY_GAZELLE
    { CUSTOM_MACHINE_DEFAULT, 6, 6, { 143, 255, 77, 57 }, { 73, 104, 198, 188 }, { 232, 3, 216, 35 }, 9, { BODY_E, BOOST_A, GRIP_D }, 1870 },         // MR_EAD
    { CUSTOM_MACHINE_DEFAULT, 7, 7, { 143, 60, 146, 220 }, { 144, 60, 216, 220 }, { 192, 60, 146, 146 }, 4, { BODY_B, BOOST_D, GRIP_A }, 1780 },      // BABA
    { CUSTOM_MACHINE_DEFAULT, 8, 8, { 146, 255, 14, 44 }, { 0, 108, 75, 148 }, { 17, 0, 26, 196 }, 8, { BODY_B, BOOST_B, GRIP_C }, 990 },             // OCTOMAN
    { CUSTOM_MACHINE_DEFAULT, 9, 9, { 100, 240, 239, 92 }, { 100, 201, 98, 184 }, { 100, 64, 195, 227 }, 22, { BODY_E, BOOST_A, GRIP_C }, 780 },      // GOMAR_AND_SHIOH
    { CUSTOM_MACHINE_DEFAULT, 10, 10, { 71, 255, 58, 99 }, { 202, 240, 58, 223 }, { 196, 0, 58, 102 }, 12, { BODY_B, BOOST_C, GRIP_B }, 1010 },       // KATE_ALEN
    { CUSTOM_MACHINE_DEFAULT, 11, 11, { 0, 196, 20, 121 }, { 90, 33, 41, 101 }, { 90, 33, 121, 20 }, 28, { BODY_E, BOOST_B, GRIP_B }, 1780 },         // ROGER_BUSTER
    { CUSTOM_MACHINE_DEFAULT, 12, 12, { 160, 255, 223, 123 }, { 160, 168, 112, 251 }, { 180, 0, 255, 255 }, 10, { BODY_E, BOOST_B, GRIP_B }, 1390 },  // JAMES_MCCLOUD
    { CUSTOM_MACHINE_DEFAULT, 13, 13, { 71, 255, 255, 150 }, { 79, 198, 84, 150 }, { 151, 0, 144, 150 }, 19, { BODY_C, BOOST_C, GRIP_A }, 910 },      // LEON
    { CUSTOM_MACHINE_DEFAULT, 14, 14, { 10, 53, 255, 92 }, { 50, 201, 240, 238 }, { 20, 255, 0, 63 }, 17, { BODY_A, BOOST_B, GRIP_D }, 2060 },        // ANTONIO_GUSTER
    { CUSTOM_MACHINE_DEFAULT, 15, 15, { 30, 54, 82, 122 }, { 30, 35, 54, 107 }, { 30, 192, 82, 14 }, 30, { BODY_A, BOOST_E, GRIP_A }, 2340 },         // BLACK_SHADOW
    { CUSTOM_MACHINE_DEFAULT, 16, 16, { 206, 25, 249, 22 }, { 84, 168, 218, 217 }, { 22, 29, 3, 174 }, 24, { BODY_A, BOOST_C, GRIP_C }, 2110 },       // MICHAEL_CHAIN
    { CUSTOM_MACHINE_DEFAULT, 17, 17, { 71, 255, 28, 56 }, { 79, 0, 80, 56 }, { 151, 0, 42, 56 }, 14, { BODY_B, BOOST_D, GRIP_A }, 1050 },            // JACK_LEVIN
    { CUSTOM_MACHINE_DEFAULT, 18, 18, { 141, 29, 46, 38 }, { 15, 21, 46, 130 }, { 36, 184, 46, 29 }, 20, { BODY_E, BOOST_B, GRIP_B }, 860 },          // SUPER_ARROW
    { CUSTOM_MACHINE_DEFAULT, 19, 19, { 141, 29, 46, 38 }, { 15, 21, 46, 130 }, { 36, 184, 46, 29 }, 21, { BODY_E, BOOST_B, GRIP_B }, 1140 },         // MRS_ARROW
    { CUSTOM_MACHINE_DEFAULT, 20, 20, { 14, 200, 213, 22 }, { 145, 51, 14, 95 }, { 213, 195, 14, 38 }, 26, { BODY_D, BOOST_A, GRIP_D }, 900 },        // JOHN_TANAKA
    { CUSTOM_MACHINE_DEFAULT, 21, 21, { 19, 190, 165, 20 }, { 64, 190, 12, 60 }, { 90, 190, 12, 20 }, 18, { BODY_C, BOOST_C, GRIP_A }, 1460 },        // BEASTMAN
    { CUSTOM_MACHINE_DEFAULT, 22, 22, { 26, 219, 217, 155 }, { 30, 230, 0, 24 }, { 57, 255, 0, 156 }, 13, { BODY_E, BOOST_A, GRIP_C }, 1620 },        // ZODA
    { CUSTOM_MACHINE_DEFAULT, 23, 23, { 203, 121, 255, 255 }, { 203, 205, 255, 149 }, { 84, 212, 255, 244 }, 29, { BODY_A, BOOST_B, GRIP_E }, 2220 }, // DR_CLASH
    { CUSTOM_MACHINE_DEFAULT, 24, 24, { 3, 218, 28, 118 }, { 3, 17, 181, 118 }, { 46, 17, 104, 118 }, 23, { BODY_B, BOOST_A, GRIP_E }, 1530 },        // SILVER_NEELSEN
    { CUSTOM_MACHINE_DEFAULT, 25, 25, { 51, 203, 0, 9 }, { 48, 0, 126, 131 }, { 28, 0, 20, 166 }, 15, { BODY_B, BOOST_D, GRIP_A }, 1520 },            // BIO_REX
    { CUSTOM_MACHINE_DEFAULT, 26, 26, { 72, 21, 179, 69 }, { 90, 120, 49, 72 }, { 0, 149, 67, 137 }, 27, { BODY_C, BOOST_A, GRIP_D }, 950 },          // DRAQ
    { CUSTOM_MACHINE_DEFAULT, 27, 27, { 254, 227, 20, 104 }, { 244, 62, 72, 99 }, { 65, 34, 24, 150 }, 11, { BODY_B, BOOST_B, GRIP_C }, 1490 },       // BILLY
    { CUSTOM_MACHINE_DEFAULT, 28, 28, { 31, 232, 192, 91 }, { 63, 0, 0, 91 }, { 223, 0, 176, 91 }, 16, { BODY_C, BOOST_A, GRIP_D }, 1010 },           // THE_SKULL
    { CUSTOM_MACHINE_DEFAULT, 29, 29, { 200, 0, 63, 40 }, { 0, 72, 214, 38 }, { 0, 255, 42, 105 }, 25, { BODY_B, BOOST_A, GRIP_E }, 1170 },           // BLOOD_FALCON
    { CUSTOM_MACHINE_SUPER_FALCON, 0, 0, { 223, 34, 12, 224 }, { 199, 34, 50, 239 }, { 33, 34, 109, 240 }, 7, { BODY_A, BOOST_B, GRIP_A }, 790 },
    { CUSTOM_MACHINE_SUPER_STINGRAY, 3, 3, { 55, 42, 85, 10 }, { 55, 59, 11, 123 }, { 55, 136, 24, 125 }, 5, { BODY_B, BOOST_A, GRIP_A }, 2210 },
    { CUSTOM_MACHINE_SUPER_CAT, 4, 4, { 33, 42, 0, 134 }, { 55, 42, 134, 0 }, { 137, 42, 73, 72 }, 2, { BODY_A, BOOST_A, GRIP_B }, 1840 },
};
// clang-format on

// Machine Part Weights
s16 D_800CF488[] = {
    270, 290, 320, 350, 420, 580, 630,
};

s16 D_800CF498[] = {
    510, 560, 630, 720, 890, 930, 1170,
};

s16 D_800CF4A8[] = {
    0, 100, 120, 140, 190, 250, 420,
};

void (*D_800CF4B8[])(Racer*) = {
    func_8008EC38, // TRACK_SHAPE_ROAD
    func_8008EC58, // TRACK_SHAPE_WALLED_ROAD
    func_8008EC98, // TRACK_SHAPE_PIPE
    func_8008F550, // TRACK_SHAPE_CYLINDER
    func_8008FC80, // TRACK_SHAPE_HALF_PIPE
    func_8008EC78, // TRACK_SHAPE_TUNNEL
    func_80090490, // TRACK_SHAPE_AIR
    func_80090568, // TRACK_SHAPE_BORDERLESS_ROAD
};

#ifndef EXPANSION_KIT
u8 D_800CF4D8[] = {
    BGM_MUTE_CITY,  BGM_SILENCE,       BGM_SAND_OCEAN,    BGM_DEVILS_FOREST, BGM_BIG_BLUE,   BGM_PORT_TOWN,
    BGM_SECTOR,     BGM_RED_CANYON,    BGM_DEVILS_FOREST, BGM_MUTE_CITY,     BGM_BIG_BLUE,   BGM_WHITE_LAND,
    BGM_SAND_OCEAN, BGM_SILENCE,       BGM_SECTOR,        BGM_RED_CANYON,    BGM_WHITE_LAND, BGM_MUTE_CITY,
    BGM_SECTOR,     BGM_DEVILS_FOREST, BGM_RED_CANYON,    BGM_SAND_OCEAN,    BGM_PORT_TOWN,  BGM_WHITE_LAND,
};
#else
u8 D_800CF4D8[] = {
    BGM_MUTE_CITY,    BGM_SILENCE,       BGM_SAND_OCEAN,    BGM_DEVILS_FOREST, BGM_BIG_BLUE,   BGM_PORT_TOWN,
    BGM_SECTOR,       BGM_RED_CANYON,    BGM_DEVILS_FOREST, BGM_MUTE_CITY,     BGM_BIG_BLUE,   BGM_WHITE_LAND,
    BGM_SAND_OCEAN,   BGM_SILENCE,       BGM_SECTOR,        BGM_RED_CANYON,    BGM_WHITE_LAND, BGM_MUTE_CITY,
    BGM_RAINBOW_ROAD, BGM_DEVILS_FOREST, BGM_RED_CANYON,    BGM_SAND_OCEAN,    BGM_PORT_TOWN,  BGM_WHITE_LAND,
};
#endif

#ifndef EXPANSION_KIT
u8 D_800CF4F0[] = {
    BGM_MUTE_CITY,     // VENUE_MUTE_CITY
    BGM_PORT_TOWN,     // VENUE_PORT_TOWN
    BGM_BIG_BLUE,      // VENUE_BIG_BLUE
    BGM_SAND_OCEAN,    // VENUE_SAND_OCEAN
    BGM_DEVILS_FOREST, // VENUE_DEVILS_FOREST
    BGM_WHITE_LAND,    // VENUE_WHITE_LAND
    BGM_SECTOR,        // VENUE_SECTOR
    BGM_RED_CANYON,    // VENUE_RED_CANYON
    BGM_SAND_OCEAN,    // VENUE_FIRE_FIELD
    BGM_SILENCE,       // VENUE_SILENCE
    BGM_MUTE_CITY,     // VENUE_ENDING
};
#endif

s32 Racer_GetRacerIdFromPosition(s32 position) {
    s32 i;

    for (i = 0; i < gTotalRacers; i++) {
        if (position == gRacers[i].position) {
            return i;
        }
    }
    return -1;
}

extern s32 gNumPlayers;
extern s8 gTitleDemoState;
extern s32 gGameMode;

extern CourseInfo* gCurrentCourseInfo;

void Racer_SetupStartPositions(void) {
    f32 t;
    f32 height;
    f32 var_fv0;
#ifdef EXPANSION_KIT
    f32 var_fs1;
#endif
    s32 i;
    s32 j;
    CourseSegment* racerStartSegment;
    Racer* racer;
    s32 index;

    func_i3_80115E74();

    racerStartSegment = gCurrentCourseInfo->courseSegments[0].prev;
    t = 1.0f;
    for (i = 20; i > 0; i--) {
        t -= 7.3f / Course_SplineGetTangent(racerStartSegment, t, &gRacers[0].segmentPositionInfo.segmentForward);
    }

#ifndef EXPANSION_KIT
    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) &&
        (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
#else
    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) &&
        (gTitleDemoState == TITLE_DEMO_INACTIVE) && (gGameMode != GAMEMODE_COURSE_EDIT)) {
#endif
        if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
            height = 1.99f;
        } else {
            height = 0;
        }
    } else {
        height = 7.99f;
    }

    for (j = 1; j <= gTotalRacers; j++) {
        index = Racer_GetRacerIdFromPosition(j);
        racer = &gRacers[index];
        racer->segmentPositionInfo.courseSegment = racerStartSegment;
        racer->segmentPositionInfo.segmentTValue = t;
        Course_SplineGetPosition(racerStartSegment, t, &racer->segmentPositionInfo.segmentPos);
        racer->segmentPositionInfo.pos = racer->segmentPositionInfo.lastGroundedPos =
            racer->segmentPositionInfo.segmentPos;
        racer->segmentPositionInfo.segmentDisplacement.x = racer->segmentPositionInfo.segmentDisplacement.y =
            racer->segmentPositionInfo.segmentDisplacement.z = racer->segmentPositionInfo.distanceFromSegment = 0.0f;
        racer->segmentPositionInfo.segmentForwardMagnitude =
            Course_SplineGetTangent(racer->segmentPositionInfo.courseSegment, racer->segmentPositionInfo.segmentTValue,
                                    &racer->segmentPositionInfo.segmentForward);
        racer->segmentPositionInfo.segmentLengthProportion = Course_SplineGetLengthInfo(
            racer->segmentPositionInfo.courseSegment, racer->segmentPositionInfo.segmentTValue, &racer->lapDistance);
        Course_SplineGetBasis(racer->segmentPositionInfo.courseSegment, racer->segmentPositionInfo.segmentTValue,
                              &racer->segmentBasis, racer->segmentPositionInfo.segmentLengthProportion);

#ifdef EXPANSION_KIT
        var_fs1 = ((racer->segmentPositionInfo.segmentLengthProportion *
                    (racer->segmentPositionInfo.courseSegment->next->radiusLeft -
                     racer->segmentPositionInfo.courseSegment->radiusLeft)) +
                   racer->segmentPositionInfo.courseSegment->radiusLeft +
                   (racer->segmentPositionInfo.segmentLengthProportion *
                    (racer->segmentPositionInfo.courseSegment->next->radiusRight -
                     racer->segmentPositionInfo.courseSegment->radiusRight)) +
                   racer->segmentPositionInfo.courseSegment->radiusRight) *
                  0.125f;
        if (var_fs1 > 50.0f) {
            var_fs1 = 50.0f;
        }
#endif

        if (gTotalRacers >= 4) {
            var_fv0 = 3.0f;
        } else {
            var_fv0 = gTotalRacers - 1;
        }
#ifndef EXPANSION_KIT
        var_fv0 = (((j - 1) & 3) * 2 - var_fv0) * 50.0f;
#else
        var_fv0 = (((j - 1) & 3) * 2 - var_fv0) * var_fs1;
#endif
        func_8009EBEC(
            &racer->segmentPositionInfo,
            racer->segmentPositionInfo.pos.x + (height * racer->segmentBasis.y.x) + (var_fv0 * racer->segmentBasis.z.x),
            racer->segmentPositionInfo.pos.y + (height * racer->segmentBasis.y.y) + (var_fv0 * racer->segmentBasis.z.y),
            racer->segmentPositionInfo.pos.z + (height * racer->segmentBasis.y.z) + (var_fv0 * racer->segmentBasis.z.z),
            100, 1.0f);
        if (gNumPlayers == 1) {
            var_fv0 = 100.0f;
#ifdef EXPANSION_KIT
        } else if (var_fs1 <= 23.0f) {
            var_fv0 = 46.0f;
#endif
        } else {
            var_fv0 = 0.1f;
        }

        for (i = 20; i > 0; i--) {
            t -= (var_fv0 / 20.0f) / racer->segmentPositionInfo.segmentForwardMagnitude;
            if (t < 0.0f) {
                racerStartSegment = racerStartSegment->prev;
                t *= (racer->segmentPositionInfo.segmentForwardMagnitude /
                      Course_SplineGetTangent(racerStartSegment, 1.0f, &racer->segmentPositionInfo.segmentForward));
                t += 1.0f;
            }
        }
    }
}

extern s8 gTitleDemoState;

void Racer_UpdateRivalRacer(void) {
    s32 var_a2;
    s32 var_a3;
    Racer* temp;
    Racer* var_a0;
    Racer* var_v0;
    Racer* var_v1;

    if ((gGameMode != GAMEMODE_GP_RACE) || ((gTotalRacers - gRacersRetired) < 2) ||
        (gTitleDemoState != TITLE_DEMO_INACTIVE)) {
        sRivalRacer = NULL;
        return;
    }
    var_v0 = gRacers;
    while (var_v0->stateFlags & RACER_STATE_RETIRED) {
        var_v0++;
    }
    var_v1 = var_v0 + 1;
    while (var_v1->stateFlags & RACER_STATE_RETIRED) {
        var_v1++;
    }

    if (var_v0->points < var_v1->points) {
        temp = var_v0;
        var_v0 = var_v1;
        var_v1 = temp;
        var_a2 = var_v1->points;
        var_a3 = var_v0->points;
    } else {
        var_a2 = var_v0->points;
        var_a3 = var_v1->points;
    }

    var_a0 = sLastRacer;
    do {
        if (var_a0->stateFlags & RACER_STATE_RETIRED) {
            continue;
        }
        if (var_a2 < var_a0->points) {
            var_v1 = var_v0;
            var_a3 = var_a2;
            var_v0 = var_a0;
            var_a2 = var_a0->points;
        } else if ((var_a3 < var_a0->points) && (var_a0 != var_v0)) {
            var_v1 = var_a0;
            var_a3 = var_a0->points;
        }
    } while (--var_a0 >= gRacers);

    if (var_a2 == 0) {
        sRivalRacer = NULL;
        return;
    }
    if (var_v0 == gRacers) {
        sRivalRacer = var_v1;
        return;
    }
    sRivalRacer = var_v0;
}

void Racer_IncreaseLife(s32 playerIndex) {

    gPlayerLives[playerIndex]++;

    func_i3_80128D8C();
    Hud_TriggerLivesIncrease();
    if (gEnableRaceSfx) {
        Audio_TriggerSystemSE(NA_SE_NONE);
    }
    D_800F80C4 = 0;
}

void Racer_DecreaseLife(s32 playerIndex) {

    if (--gPlayerLives[playerIndex] >= 0) {
        Hud_TriggerLivesDecrease();
    }
    if (gEnableRaceSfx) {
        Audio_TriggerSystemSE(NA_SE_44);
    }
    D_800F80C4 = 0;
}

void Racer_RetireRacer(Racer* racer) {

    if (!(racer->stateFlags & (RACER_STATE_FINISHED | RACER_STATE_RETIRED))) {
        racer->stateFlags |= RACER_STATE_RETIRED;
        racer->energy = 0.0f;
        gRacersRetired++;
        if (racer->id < gNumPlayers) {
            gPlayerRacersRetired++;
        } else if (D_800E5FBC == 0) {
            gCpuRacersRetired++;
            if ((gGameMode == GAMEMODE_DEATH_RACE) && (gTotalRacers == (gCpuRacersRetired + 1))) {
                gRacers[0].stateFlags |= (RACER_STATE_FINISHED | RACER_STATE_CPU_CONTROLLED);
                gRacers[0].raceTime += Math_Rand2() % 16;
                gRacers[0].energy = gRacers[0].maxEnergy;
                D_800F5DE8 = D_800E5FBC = 1;
                Audio_PlayerFinished(gRacers[0].id);
                Audio_PlayerEngineStop(gRacers[0].id);
                func_8007E0CC();
            }
        }
        racer->raceDistancePosition = (sRaceFrameCount + ((gTotalRacers - racer->position) / 10.0f)) - 600000.0f;
        if (gGameMode == GAMEMODE_GP_RACE) {
            if (racer->id < gNumPlayers) {
                D_800F80C4 = -1;
            }
            if (racer == sRivalRacer) {
                Racer_UpdateRivalRacer();
            }
        }
    }
}

void Racer_StopRacerSfx(Racer* racer) {

    if (gEnableRaceSfx) {
        if (racer->soundEffectFlags & RACER_SE_FLAGS_PIT) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_PIT;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_4);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_DIRT) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_DIRT;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_5);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_ICE) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_ICE;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_11);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_200) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_200;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_6);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_DRIFT_SLIDE) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_DRIFT_SLIDE;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_10);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_AIRBORNE;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_8);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_ENGINE_ECHO) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_ENGINE_ECHO;
            Audio_PlayerEngineEchoStop(racer->id);
        }
        if (racer->soundEffectFlags & RACER_SE_FLAGS_BRAKE) {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_BRAKE;
            Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_9);
        }
        Audio_PlayerEngineStop(racer->id);
    } else {
        racer->soundEffectFlags &=
            ~(RACER_SE_FLAGS_PIT | RACER_SE_FLAGS_DIRT | RACER_SE_FLAGS_ICE | RACER_SE_FLAGS_200 |
              RACER_SE_FLAGS_DRIFT_SLIDE | RACER_SE_FLAGS_AIRBORNE | RACER_SE_FLAGS_ENGINE_ECHO | RACER_SE_FLAGS_BRAKE);
    }
}

// todo: figure out 0.6899998f as a fraction
f32 func_8008960C(f32 arg0) {
    if (arg0 != 0.0f) {
        return 1.0f / (((1.0f + 0.6899998f) / arg0) - 0.6899998f);
    }
    return 0.0f;
}

f32 func_80089654(f32 arg0) {
    if (arg0 != 0.0f) {
        return (1.0f + 0.6899998f) / ((1.0f / arg0) + 0.6899998f);
    }
    return 0.0f;
}

void func_8008969C(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        gRacers[i].character = gPlayerCharacters[i];
        gRacers[i].machineSkinIndex = gPlayerMachineSkins[i];
    }
}

void func_80089724(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        gPlayerCharacters[i] = gRacers[i].character;
        gPlayerMachineSkins[i] = gRacers[i].machineSkinIndex;
        gRacers[i].unk_1A8 = func_8008960C(gPlayerEngine[i]);
    }
}

void func_80089800(void) {
    s32 i;
    s16 j;
    s32 index0;
    s32 index1;

    j = 0;

    for (i = 1; i < 30; i++) {
        if (j == gPlayerCharacters[0]) {
            j++;
        }
        gRacers[i].character = j++;
        gRacers[i].machineSkinIndex = 0;
    }

    for (i = 0; i < 28; i++) {
        index0 = (Math_Rand1() & 0x1FFFF) % 29 + 1;
        index1 = (Math_Rand2() & 0x1FFFF) % 29 + 1;

        j = gRacers[index0].character;
        gRacers[index0].character = gRacers[index1].character;
        gRacers[index1].character = j;
    }
}

void func_80089934(void) {
    s32 i;
    s32 j;
    s32 var_s0;
    Racer* temp_s1;
    Racer* var_v0;

    for (i = 1; i < gTotalRacers; i++) {
        if (i >= gNumPlayers) {
            do {
                gRacers[i].character = (Math_Rand2() & 0x1FFFF) % 30;
                gRacers[i].machineSkinIndex = (Math_Rand1() & 0x1FFFF) % 4;
                for (j = 0; j < gNumPlayers; j++) {
                    if ((gRacers[i].character == gRacers[j].character) &&
                        (gRacers[i].machineSkinIndex == gRacers[j].machineSkinIndex)) {
                        break;
                    }
                }
            } while (j < gNumPlayers);
        }
    }
}

void func_80089A74(MachineInfo* arg0) {
    u8 customType;
    CustomMachineInfo* temp_v0;

    arg0->character = gRacers[0].character;
    arg0->bodyR = (s32) gRacers[0].bodyRF;
    arg0->bodyG = (s32) gRacers[0].bodyGF;
    arg0->bodyB = (s32) gRacers[0].bodyBF;
    arg0->customType = customType = gRacers[0].customType;
    if (customType == CUSTOM_MACHINE_EDITED) {
        temp_v0 = &sCustomMachineInfo[gRacers[0].character];
        arg0->frontType = temp_v0->frontType;
        arg0->rearType = temp_v0->rearType;
        arg0->wingType = temp_v0->wingType;
        arg0->logo = temp_v0->logo;
        arg0->number = gMachines[gRacers[0].character].number - 1;
        arg0->decal = temp_v0->decal;
        arg0->numberR = temp_v0->numberR;
        arg0->numberG = temp_v0->numberG;
        arg0->numberB = temp_v0->numberB;
        arg0->decalR = temp_v0->decalR;
        arg0->decalG = temp_v0->decalG;
        arg0->decalB = temp_v0->decalB;
        arg0->cockpitR = temp_v0->cockpitR;
        arg0->cockpitG = temp_v0->cockpitG;
        arg0->cockpitB = temp_v0->cockpitB;
    } else {
        arg0->frontType = arg0->rearType = arg0->wingType = arg0->logo = arg0->number = arg0->decal = arg0->numberR =
            arg0->numberG = arg0->numberB = arg0->decalR = arg0->decalG = arg0->decalB = arg0->cockpitR =
                arg0->cockpitG = arg0->cockpitB = 0;
    }
}

extern s32 gCurrentGhostType;

void func_80089BD0(void) {
    s32 i;
    s32 j;
    s32 var_a1_3;
    s32* var_a0_3;
    s32* var_v1_10;
    Ghost* ghost;

    if (D_800F5DE8 != 0) {
        for (i = 0; i < 5; i++) {
            if (gRacers[0].raceTime < gCurrentCourseInfo->timeRecord[i]) {
                gCurrentTimeAttackRecordPosition = i + 1;

                for (j = 3; j >= i; j--) {

                    gCurrentCourseInfo->timeRecord[j + 1] = gCurrentCourseInfo->timeRecord[j];
                    gCurrentCourseInfo->recordMachineInfos[j + 1] = gCurrentCourseInfo->recordMachineInfos[j];
                    gCurrentCourseInfo->recordEngines[j + 1] = gCurrentCourseInfo->recordEngines[j];
                    *(s32*) &gCurrentCourseInfo->recordNames[j + 1] = *(s32*) &gCurrentCourseInfo->recordNames[j];

                    sRecordsMachineIndices[j + 1] = sRecordsMachineIndices[j];
                }

                gCurrentCourseInfo->timeRecord[i] = gRacers[0].raceTime;

                func_80089A74(&gCurrentCourseInfo->recordMachineInfos[i]);

                gCurrentCourseInfo->recordEngines[i] = gPlayerEngine[0];
                sRecordsMachineIndices[i] = gRacers[0].machineIndex;
                break;
            }
        }

        if (gCurrentCourseInfo->maxSpeed < gRacers[0].maxSpeed) {
            gCurrentTimeAttackHasMaxSpeed = true;
            gCurrentCourseInfo->maxSpeed = gRacers[0].maxSpeed;

            func_80089A74(&gCurrentCourseInfo->maxSpeedMachine);
            sRecordsMachineIndices[5] = gRacers[0].machineIndex;
        }

        var_a1_3 = gCurrentCourseInfo->bestTime;
        for (i = 0; i < 3; i++) {
            if (gRacers[0].lapTimes[i] < var_a1_3) {
                j = i;
                var_a1_3 = gRacers[0].lapTimes[i];
            }
        }

        if (var_a1_3 < gCurrentCourseInfo->bestTime) {
            gBestTimedLap = j + 1;
            gCurrentCourseInfo->bestTime = var_a1_3;
            func_80089A74(&gCurrentCourseInfo->bestTimeMachine);
            sRecordsMachineIndices[6] = gRacers[0].machineIndex;
        }
    }

    if (D_800F5DEA) {
        for (j = 0; j < 3; j++) {
            if (gGhosts[j].encodedCourseIndex == 0) {
                break;
            }
        }

        var_a1_3 = -1;
        if (j == 3) {
            for (i = 0; i < 3; i++) {
                if ((gGhosts[i].encodedCourseIndex != gCurrentCourseInfo->encodedCourseIndex) ||
                    ((gCurrentGhostType == GHOST_PLAYER) && (gGhosts[i].ghostType != GHOST_PLAYER))) {
                    j = i;
                    var_a1_3 = gGhosts[i].raceTime;
                    break;
                }
            }

            // FAKE
            if (1) {}

            if (var_a1_3 != -1) {
                for (i = j + 1; i < 3; i++) {
                    if ((gCurrentCourseInfo->encodedCourseIndex != gGhosts[i].encodedCourseIndex) ||
                        ((gCurrentGhostType == GHOST_PLAYER) && (gGhosts[i].ghostType != GHOST_PLAYER))) {
                        if (var_a1_3 < gGhosts[i].raceTime) {
                            j = i;
                            var_a1_3 = gGhosts[i].raceTime;
                        }
                    }
                }
            } else {
                for (i = 0; i < 3; i++) {
                    if ((gCurrentCourseInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) &&
                        (gGhosts[i].ghostType == GHOST_PLAYER)) {
                        j = i;
                        var_a1_3 = gGhosts[i].raceTime;
                        break;
                    }
                }

                for (i = j + 1; i < 3; i++) {
                    if ((gCurrentCourseInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) &&
                        (gGhosts[i].ghostType == GHOST_PLAYER)) {
                        if (var_a1_3 < gGhosts[i].raceTime) {
                            j = i;
                            var_a1_3 = gGhosts[i].raceTime;
                        }
                    }
                }

                if (gRacers[0].raceTime >= var_a1_3) {
                    j = 3;
                }
            }
        }

        if (j < 3) {
            ghost = &gGhosts[j];

            for (i = 0; i < 3; i++) {
                if (ghost == gGhostRacers[i].ghost) {
                    gGhostRacers[i].exists = gGhostRacers[i].initialized = false;
                }
            }
            ghost->ghostType = GHOST_PLAYER;
            ghost->encodedCourseIndex = gCurrentCourseInfo->encodedCourseIndex;
            ghost->raceTime = gRacers[0].raceTime;

            for (i = 0; i < 3; i++) {
                ghost->lapTimes[i] = gRacers[0].lapTimes[i];
            }

            ghost->replayEnd = sGhostReplayRecordingEnd;
            ghost->replaySize = sGhostReplayRecordingSize;

            func_80089A74(&ghost->machineInfo);

            i = (sGhostReplayRecordingSize - 1) & ~3;
            var_v1_10 = (s32*) &sGhostReplayRecordingBuffer[i];
            var_a0_3 = (s32*) &ghost->replayData[i];
            ghost->replayChecksum = 0;
            do {
                ghost->replayChecksum += * var_a0_3-- = *var_v1_10--;
            } while (var_v1_10 >= (s32*) sGhostReplayRecordingBuffer);
            if ((gFastestGhost == NULL) || (ghost->raceTime < gFastestGhost->raceTime)) {
                gFastestGhost = ghost;
            }
        }
    }
}

void Racer_UpdateRacePositions(void) {
    Racer* activeRacer;
    Racer* finishedRacer;
    s32 bestRaceTime;
    Racer* racer;
    s32 position;
    s32 lastPosition;
    f32 var_fv0;

    racer = sLastRacer;
    do {
        racer->position = 0;
        racer--;
    } while (racer >= gRacers);

    position = 1;
    lastPosition = gTotalRacers;

    do {
        activeRacer = NULL;
        finishedRacer = NULL;
        racer = sLastRacer;

        do {
            if (racer->position != 0) {
                continue;
            }
            if (racer->stateFlags & RACER_STATE_FINISHED) {
                if ((finishedRacer == NULL) || (racer->raceTime < bestRaceTime)) {
                    bestRaceTime = racer->raceTime;
                    finishedRacer = racer;
                }
            } else if ((activeRacer == NULL) || (racer->raceDistancePosition < var_fv0)) {
                var_fv0 = racer->raceDistancePosition;
                activeRacer = racer;
            }
        } while (--racer >= gRacers);

        if (finishedRacer != NULL) {
            gRacersByPosition[position - 1] = finishedRacer;

            finishedRacer->position = position;
            position++;
        }
        if (activeRacer != NULL) {
            gRacersByPosition[lastPosition - 1] = activeRacer;

            activeRacer->position = lastPosition;
            lastPosition--;
        }
    } while (lastPosition >= position);
}

extern s32 gTotalLapCount;

void func_8008AA8C(void) {
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    Racer* racer;

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->stateFlags & RACER_STATE_FINISHED) {
            continue;
        }

        if (racer->stateFlags & RACER_STATE_CRASHED) {
            racer->raceTime = 0;
        } else if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
            racer->stateFlags &= ~RACER_STATE_ACTIVE;
            racer->stateFlags |= RACER_STATE_CRASHED;
            D_800E5FC0++;
            Racer_RetireRacer(racer);
            racer->raceTime = 0;
        } else {
            racer->stateFlags |= RACER_STATE_FINISHED;
            var_a0 = 0;
            if (racer->lapTimes[1] != 0) {
                var_a1 = racer->lapTimes[0] - racer->lapTimes[1];
                if (var_a1 < 0) {
                    var_a1 = 0;
                }
            } else {
                var_a1 = 0;
            }

            racer->raceTime = (s32) (((racer->raceTime - var_a1) * gTotalLapCount) * gCurrentCourseInfo->length /
                                     racer->raceDistance) +
                              var_a1;

            var_a1 = 0;
            var_a0 = 0;
            while (true) {
                if (racer->lapTimes[var_a0] == 0) {
                    break;
                }

                var_a1 += racer->lapTimes[var_a0];

                var_a0++;

                if (var_a0 >= gTotalLapCount) {
                    break;
                }
            }

            while (var_a0 < gTotalLapCount) {
                racer->lapTimes[var_a0] = (racer->raceTime - var_a1) / (gTotalLapCount - var_a0);
                var_a1 += racer->lapTimes[var_a0];
                var_a0++;
            }
        }
    }
    Racer_UpdateRacePositions();
    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FINISHED)) {
        var_v1 = gTotalRacers - 1;
        while (var_v1 >= 0) {
            if (gRacersByPosition[var_v1]->raceTime != 0) {
                break;
            }
            var_v1--;
        }

        while (var_v1 >= 0) {
            gRacersByPosition[var_v1]->points += gRacePositionPoints[var_v1];
            var_v1--;
        }
        D_800E5FD6 = D_800E5FD4;
    }
}

void Racer_UpdateRacerPairInfo(void) {
    Racer* racer1;
    Racer* racer2;
    f32 closestDistanceBehind;
    f32 racerPairDistance;
    Racer* closestRacerBehind;
    f32 lapDistanceDiff;
    f32 halfLapDistance;
    s32 temp_a2;
    u32 i;
    RacerPairInfo* racerPairInfo;

    if (gTotalRacers < 2) {
        gRacers[0].racerAhead = gRacers[0].racerBehind = NULL;
        gRacers[0].distanceToRacerAhead = gRacers[0].distanceFromRacerBehind = gCurrentCourseInfo->length;
        return;
    }

    halfLapDistance = gCurrentCourseInfo->length * 0.5f;
    racerPairInfo = &sRacerPairInfo[((s32) (gTotalRacers * (gTotalRacers - 1)) >> 1) - 1];
    racer1 = sLastRacer;

    do {
        racer2 = racer1 - 1;
        do {
            lapDistanceDiff = racer2->lapDistance - racer1->lapDistance;
            if (lapDistanceDiff < 0.0f) {
                lapDistanceDiff = -lapDistanceDiff;
                if (lapDistanceDiff < halfLapDistance) {
                    racerPairInfo->leadRacer = racer1;
                    racerPairInfo->trailRacer = racer2;
                    racerPairInfo->trailToLeadDistance = lapDistanceDiff;
                    racerPairInfo->leadToTrailDistance = gCurrentCourseInfo->length - lapDistanceDiff;
                } else {
                    racerPairInfo->leadRacer = racer2;
                    racerPairInfo->trailRacer = racer1;
                    racerPairInfo->trailToLeadDistance = gCurrentCourseInfo->length - lapDistanceDiff;
                    racerPairInfo->leadToTrailDistance = lapDistanceDiff;
                }
            } else if (lapDistanceDiff < halfLapDistance) {
                racerPairInfo->leadRacer = racer2;
                racerPairInfo->trailRacer = racer1;
                racerPairInfo->trailToLeadDistance = lapDistanceDiff;
                racerPairInfo->leadToTrailDistance = gCurrentCourseInfo->length - lapDistanceDiff;
            } else {
                racerPairInfo->leadRacer = racer1;
                racerPairInfo->trailRacer = racer2;
                racerPairInfo->trailToLeadDistance = gCurrentCourseInfo->length - lapDistanceDiff;
                racerPairInfo->leadToTrailDistance = lapDistanceDiff;
            }
            racer2--;
            racerPairInfo--;
        } while (racer2 >= gRacers);
        racer1--;
    } while (racer1 > gRacers);

    racer1 = sLastRacer;
    temp_a2 = (s32) (racer1->id * (racer1->id - 1)) >> 1;

    closestDistanceBehind = gCurrentCourseInfo->length + 10.0f;

    for (racer2 = racer1 - 1; racer2 >= gRacers; racer2--) {

        racer2->racerAhead = NULL;
        racerPairInfo = &sRacerPairInfo[temp_a2 + racer2->id];
        if (racer2 == racerPairInfo->trailRacer) {
            racerPairDistance = racerPairInfo->trailToLeadDistance;
        } else {
            racerPairDistance = racerPairInfo->leadToTrailDistance;
        }
        if (racerPairDistance < closestDistanceBehind) {
            closestDistanceBehind = racerPairDistance;
            closestRacerBehind = racer2;
        }
    }

    racer1->racerBehind = closestRacerBehind;
    closestRacerBehind->racerAhead = racer1;
    closestRacerBehind->distanceToRacerAhead = closestDistanceBehind;
    racer1->distanceFromRacerBehind = closestDistanceBehind;

    for (i = gTotalRacers - 2; i > 0; i--) {
        racer1 = closestRacerBehind;
        closestDistanceBehind = gCurrentCourseInfo->length + 10.0f;
        temp_a2 = (s32) (closestRacerBehind->id * (closestRacerBehind->id - 1)) >> 1;

        for (racer2 = gRacers; racer2 < racer1; racer2++) {
            if (racer2->racerAhead != NULL) {
                continue;
            }

            racerPairInfo = &sRacerPairInfo[temp_a2 + racer2->id];
            if (racer2 == racerPairInfo->trailRacer) {
                racerPairDistance = racerPairInfo->trailToLeadDistance;
            } else {
                racerPairDistance = racerPairInfo->leadToTrailDistance;
            }
            if (racerPairDistance < closestDistanceBehind) {
                closestDistanceBehind = racerPairDistance;
                closestRacerBehind = racer2;
            }
        }

        for (racer2 = racer2 + 1; racer2 < sLastRacer; racer2++) {
            if (racer2->racerAhead != NULL) {
                continue;
            }

            temp_a2 = racer2->id;
            racerPairInfo = &sRacerPairInfo[((s32) (temp_a2 * (temp_a2 - 1)) >> 1) + racer1->id];
            if (racer2 == racerPairInfo->trailRacer) {
                racerPairDistance = racerPairInfo->trailToLeadDistance;
            } else {
                racerPairDistance = racerPairInfo->leadToTrailDistance;
            }
            if (racerPairDistance < closestDistanceBehind) {
                closestDistanceBehind = racerPairDistance;
                closestRacerBehind = racer2;
            }
        }
        racer1->racerBehind = closestRacerBehind;
        closestRacerBehind->racerAhead = racer1;
        closestRacerBehind->distanceToRacerAhead = closestDistanceBehind;
        racer1->distanceFromRacerBehind = closestDistanceBehind;
    }

    racer1 = sLastRacer;
    closestRacerBehind->racerBehind = racer1;
    racer1->racerAhead = closestRacerBehind;
    racerPairInfo = &sRacerPairInfo[((s32) (racer1->id * (racer1->id - 1)) >> 1) + closestRacerBehind->id];
    if (closestRacerBehind == racerPairInfo->leadRacer) {
        closestDistanceBehind = racerPairInfo->trailToLeadDistance;
    } else {
        closestDistanceBehind = racerPairInfo->leadToTrailDistance;
    }
    racer1->distanceToRacerAhead = closestDistanceBehind;
    closestRacerBehind->distanceFromRacerBehind = closestDistanceBehind;
}

void Racer_UpdateNearestRacer(void) {
    s32 i;
    f32 closestDistance;

    closestDistance = gCurrentCourseInfo->length;

    for (i = gTotalRacers - 1; i > 0; i--) {
        if (sRacerPairInfo[(i * (i - 1)) >> 1].trailToLeadDistance < closestDistance) {
            closestDistance = sRacerPairInfo[(i * (i - 1)) >> 1].trailToLeadDistance;
            gNearestRacer = i;
        }
    }
}

extern s32 gDifficulty;
extern s16 gLastRandomCourseIndex;

void func_8008B1CC(void) {
    s32 numRacers = ARRAY_COUNT(gRacers) - 1;
    s32 i;

    if (numRacers) {}

    D_800E5FD6 = D_800E5FF0 = 0;
    gLastRandomCourseIndex = -1;

    for (i = numRacers; i >= 0; i--) {
        gRacers[i].points = 0;
    }

    gPlayerLives[0] = gPlayerLives[1] = gPlayerLives[2] = gPlayerLives[3] = gTotalLives[gDifficulty];
}

s32 func_8008B23C(MachineInfo* arg0, MachineInfo* arg1) {
    s32 i;
    u8* var_v0 = (u8*) arg0;
    u8* var_v1 = (u8*) arg1;

    for (i = sizeof(MachineInfo); i > 0; i--, var_v0++, var_v1++) {
        if (*var_v0 != *var_v1) {
            return -1;
        }
    }

    return 0;
}

f32 Racer_InitMachineStats(Racer* racer, f32 arg1) {
    Machine* temp_a1;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fs1;
    f32 temp_fv1;
    f32 temp_ret;
    f32 temp_fa1;

    temp_fs0 = (racer->unk_1F0 - 780.0f) / 1560.0f;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x078) >> 0xF) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x780) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f);

    racer->unk_1B4 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 = racer->unk_1B4;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x0A0) >> 0x15) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x95C) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f);
    racer->unk_1B0 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += racer->unk_1B0;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x1BC) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0x978) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f)) *
          temp_fs0)) +
        ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f);
    racer->unk_1B8 = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += racer->unk_1B8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x2C4) >> 0xE) & 0xFF) - (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF);
    temp_fv1 = (((f32) ((ROM_READ(0x988) >> 0x18) & 0xFF) - (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF);
    racer->unk_1BC = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += racer->unk_1BC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x2FC) >> 0x12) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0xA20) >> 0xC) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f)) *
          temp_fs0) +
         ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f));
    racer->unk_1C8 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += racer->unk_1C8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x36C) >> 0x10) & 0xFF) - (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF);
    temp_fv1 = ((((f32) ((ROM_READ(0x1BC) >> 0xA) & 0xFF) - (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF)) * temp_fs0) +
                (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF));
    racer->unk_1CC = racer->unk_1C8 / (((temp_fv1 - temp_fv0) * arg1) + temp_fv0 +
                                       (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f))));
    temp_fs1 += racer->unk_1CC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((ROM_READ(0x374) >> 3) & 0xFF) - ((f32) ((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
               (((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f);
    temp_fv1 =
        (((((ROM_READ(0x1C8) >> 4) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
        (((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f);
    temp_a1 = &gMachines[racer->character];
    racer->unk_1F8 = D_800CF188[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += racer->unk_1F8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        (((f32) ((ROM_READ(0x384) >> 5) & 0xFF) - ((f32) ((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x248) >> 0xB) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f)) *
         temp_fs0) +
        (((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f);
    racer->unk_1FC = D_800CF19C[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += racer->unk_1FC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((ROM_READ(0x38C) & 0xFF) - (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f)) * temp_fs0) +
               (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((ROM_READ(0x250) >> 3) & 0xFF) * 0.001f) - (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f);

    temp_fa1 = ((temp_fv1 - temp_fv0) * racer->unk_1A8) + temp_fv0;

    racer->unk_1C0 = (D_800CF174[temp_a1->machineStats[BOOST_STAT]] + temp_fa1) / racer->unk_1B8;
    temp_fs1 += racer->unk_1C0;
    racer->unk_1C4 = (D_800CF174[2] + temp_fa1) / racer->unk_1B8;
    temp_fs1 += racer->unk_1C4;
    temp_ret = func_80089654(arg1);
    temp_ret = func_80089654(temp_ret);
    temp_ret = func_80089654(temp_ret);
    racer->unk_1D0 = ((D_800CF15C - 1.0f) * temp_ret) + 1.0f;

    return temp_ret;
}

void Racer_InitRacer(Racer* racer) {
    s32 pad[4];
    f32 temp;
    f32 temp_fv0_4;
    f32 var_fs0;
    s32 i;
    Machine* machine;

    machine = &gMachines[racer->character];
    racer->customType = machine->customType;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        racer->machineIndex = 0;
    } else {
        racer->machineIndex = racer->character;
    }

    racer->shadowType = machine->shadowType;
    racer->boostersType = machine->boostersType;
    racer->bodyRF = racer->bodyR = machine->red[racer->machineSkinIndex];
    racer->bodyGF = racer->bodyG = machine->green[racer->machineSkinIndex];
    racer->bodyBF = racer->bodyB = machine->blue[racer->machineSkinIndex];
    racer->attackHighlightR = racer->attackHighlightG = racer->attackHighlightB = racer->shadowR = racer->shadowG =
        racer->shadowB = 0;
    racer->bodyLowEnergyR = 255.0f;
    racer->bodyLowEnergyG = 0.0f;
    racer->bodyLowEnergyB = 0.0f;
    racer->bodyLowEnergyGradientR = racer->bodyRF - racer->bodyLowEnergyR;
    racer->bodyLowEnergyGradientG = racer->bodyGF - racer->bodyLowEnergyG;
    racer->bodyLowEnergyGradientB = racer->bodyBF - racer->bodyLowEnergyB;
#ifndef EXPANSION_KIT
    if ((gTitleDemoState != TITLE_DEMO_INACTIVE) || (gGameMode == GAMEMODE_PRACTICE) ||
        (gGameMode == GAMEMODE_DEATH_RACE)) {
#else
    if ((gTitleDemoState != TITLE_DEMO_INACTIVE) || (gGameMode == GAMEMODE_PRACTICE) ||
        (gGameMode == GAMEMODE_DEATH_RACE) || (gGameMode == GAMEMODE_COURSE_EDIT)) {
#endif
        racer->stateFlags =
            RACER_STATE_ACTIVE | RACER_STATE_FLAGS_20000000 | RACER_STATE_CAN_BOOST | RACER_STATE_FLAGS_8000;
    } else {
        racer->stateFlags = RACER_STATE_ACTIVE | RACER_STATE_FLAGS_20000000 | RACER_STATE_FLAGS_8000;
    }
    if ((racer->id >= gNumPlayers) || (D_800CE77C != 0) || (gGameMode == GAMEMODE_RECORDS) ||
        (gGameMode == GAMEMODE_GP_END_CS) || (gTitleDemoState != TITLE_DEMO_INACTIVE)) {
        racer->stateFlags |= RACER_STATE_CPU_CONTROLLED;
    }
    racer->segmentPositionInfo.segmentLengthProportion = Course_SplineGetLengthInfo(
        racer->segmentPositionInfo.courseSegment, racer->segmentPositionInfo.segmentTValue, &racer->lapDistance);

    Course_SplineGetBasis(racer->segmentPositionInfo.courseSegment, racer->segmentPositionInfo.segmentTValue,
                          &racer->segmentBasis, racer->segmentPositionInfo.segmentLengthProportion);

    racer->modelBasis = racer->trueBasis = racer->segmentBasis;
    racer->modelPos = racer->focusPos = racer->segmentPositionInfo.pos;

    racer->gravityUp.x = racer->tiltUp.x = racer->upFromGround.x = racer->trueBasis.y.x;
    racer->gravityUp.y = racer->tiltUp.y = racer->upFromGround.y = racer->trueBasis.y.y;
    racer->gravityUp.z = racer->tiltUp.z = racer->upFromGround.z = racer->trueBasis.y.z;

    for (i = 0; i < 3; i++) {
        racer->lapTimes[i] = NULL;
    }

    racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 1;
    racer->shadowPos.y = -54321.0f;
    racer->lapsCompletedDistance = -gCurrentCourseInfo->length;
    racer->attackState = ATTACK_STATE_NONE;
    racer->driftAttackDirection = DRIFT_ATTACK_LEFT;
    racer->raceDistance = racer->raceDistancePosition = racer->lapsCompletedDistance + racer->lapDistance;
    racer->unk_2A4 = ((Math_Rand2() & 0x1FFFF) % 150) + 1;
    racer->lapsCompleted = 1;
    racer->unk_28C = NULL;
    racer->soundEffectFlags = RACER_SE_FLAGS_8000;
    racer->startNewPracticeLap = racer->unk_288 = racer->zButtonTimer = racer->rButtonTimer = racer->unk_27C =
        racer->bodyWhiteTimer = racer->spinOutTimer = racer->completedLapsTime = racer->raceTime = racer->lap =
            racer->unk_204 = racer->unk_208 = racer->unk_20C = racer->boostTimer = racer->unk_214 =
                racer->vibrationStrength = 0;
    var_fs0 = racer->attackHighlightScale = racer->unk_1E8 = racer->recoilTilt.x = racer->recoilTilt.y =
        racer->recoilTilt.z = racer->pitForceFieldSize = racer->jumpBoost = racer->tiltUpInput = racer->unk_238 =
            racer->unk_200 = racer->heightAboveGround = racer->accelerationForce = racer->driftAttackForce =
                racer->speed = racer->maxSpeed = racer->unk_198 = racer->focusVelocity.x = racer->focusVelocity.y =
                    racer->focusVelocity.z = racer->unk_68.x = racer->unk_68.y = racer->unk_68.z = racer->unk_5C.x =
                        racer->unk_5C.y = racer->unk_5C.z = racer->unk_80.x = racer->unk_80.y = racer->unk_80.z =
                            racer->velocity.x = racer->velocity.y = racer->velocity.z = var_fs0 = 0.0f;
    racer->podiumHeight = racer->energyRegain = 0.0f;
    racer->shadowColorStrength = 1.0f;
    racer->unk_1EC = 2000.0f / SPEED_CONVERSION;
    racer->unk_17C = D_800F80A4;

    racer->unk_1E0 = (((machine->weight - 780.0f) * -0.0050000027f) / 1560.0f) + 0.054f;
    racer->unk_1E4 = (((machine->weight - 780.0f) * -0.004999999f) / 1560.0f) + 0.03f;
    racer->unk_1F0 = machine->weight;
    racer->collidingStrength =
        ((4 - machine->machineStats[BODY_STAT]) * 312.0f) + 780.0f + ((312.0f * (machine->weight - 780.0f)) / 1560.0f);

    // racer->collidingStrength = SQ(racer->collidingStrength);
    // FAKE
    racer->collidingStrength = racer->collidingStrength * (temp = racer->collidingStrength);

    for (i = 0; i < 2;) {
        temp_fv0_4 = Racer_InitMachineStats(racer, racer->unk_1A8);
        if (temp_fv0_4 == var_fs0) {
            i++;
        } else {
            i = 0;
        }
        var_fs0 = temp_fv0_4;
    }

    racer->unk_234 = 1.7f;

    racer->energy = racer->maxEnergy = gBodyHealthValues[machine->machineStats[BODY_STAT]];
    racer->boostEnergyUsage = racer->maxEnergy * 0.0015f;
    racer->unk_31C = racer->unk_1C4 - 1.0f;
    racer->unk_320 = (0.5f - racer->unk_1A8) * 0.5f;
    racer->unk_324 = 1.0f / (2.0f * racer->unk_1BC);
    racer->unk_328 = 1.0f - racer->unk_1D0;
    racer->energyIncrease = racer->maxEnergy * sEnergyRefillScale;

    racer->currentRadiusLeft = (racer->segmentPositionInfo.segmentLengthProportion *
                                (racer->segmentPositionInfo.courseSegment->next->radiusLeft -
                                 racer->segmentPositionInfo.courseSegment->radiusLeft)) +
                               racer->segmentPositionInfo.courseSegment->radiusLeft;
    racer->currentRadiusRight = (racer->segmentPositionInfo.segmentLengthProportion *
                                 (racer->segmentPositionInfo.courseSegment->next->radiusRight -
                                  racer->segmentPositionInfo.courseSegment->radiusRight)) +
                                racer->segmentPositionInfo.courseSegment->radiusRight;
}

extern OSMesgQueue D_800DCAB0;
extern s16 gRacerPositionsById[];
extern GfxPool D_8024DCE0[2];
extern s16 gPlayer1OverallPosition;

void Racer_Init(void) {
    s32 i;
    s32 j;
    s32 var_a3;
    s32 var_t0;
    Racer* racer;
    GhostRacer* ghostRacer;
    MachineInfo machineInfo;
    OSMesg sp68;

    sPipeFogColors = &sVenuePipeFogColors[COURSE_CONTEXT()->courseData.venue * PIPE_MAX];
    sTunnelFogColors = &sVenueTunnelFogColors[COURSE_CONTEXT()->courseData.venue * TUNNEL_MAX];
    gPracticeBestLap = 600000 - 1;
    D_800F809C = D_800F80A0 = 0.0f;
    sRaceFrameCount = gStartNewBestLap = gRacersKOd = D_800F80C4 = D_800F80B8 = D_800E5FBC = sSpunOutRacers =
        D_800E5FC0 = gRacersRetired = gRacersFinished = gCpuRacersRetired = gPlayerRacersRetired =
            gPlayerRacersFinished = 0;
    sCourseHalfLength = gCurrentCourseInfo->length * 0.5;
    sCourseNegativeHalfLength = -sCourseHalfLength;
    if (gGameMode != GAMEMODE_GP_RACE) {
        D_800E5FD6 = 0;
    }
    D_800E5FD4 = D_800E5FD6;
    D_800E5FF0++;

    if (gNumPlayers == 1) {
        switch (gGameMode) {
            case GAMEMODE_RECORDS:
            case GAMEMODE_TIME_ATTACK:
#ifdef EXPANSION_KIT
            case GAMEMODE_COURSE_EDIT:
#endif
                gTotalRacers = 1;
                break;
            case GAMEMODE_GP_END_CS:
                if (gPlayer1OverallPosition < 4) {
                    gTotalRacers = 3;
                    for (i = 1; i < 4; i++) {
                        for (j = 0; j < 30; j++) {
                            if (gRacerPositionsById[j] == i) {
                                break;
                            }
                        }
                        gRacers[0].lapTimes[i - 1] = (gRacers[j].character << 0x10) | gRacers[j].machineSkinIndex;
                    }

                    for (i = 0; i < 3; i++) {
                        gRacers[i].character = (gRacers[0].lapTimes[i] >> 0x10);
                        gRacers[i].machineSkinIndex = gRacers[0].lapTimes[i] & 0xFFFF;
                    }
                } else {
                    gTotalRacers = 1;
                }
                break;
            default:
                if (gGameMode == GAMEMODE_PRACTICE || gGameMode == GAMEMODE_DEATH_RACE || D_800E5FF0 == 1) {
                    func_80089800();
                }
                gTotalRacers = 30;
                break;
        }
    } else {
        if (gSettingVsCom != 0) {
            gTotalRacers = 4;
            func_80089934();
        } else {
            gTotalRacers = gNumPlayers;
        }
        if ((gTotalRacers != sLastMultiplayerTotalRacerCount) || (gNumPlayers != sLastMultiplayerPlayerCount)) {
            sLastMultiplayerTotalRacerCount = gTotalRacers;
            sLastMultiplayerPlayerCount = gNumPlayers;
            for (i = 0; i < 4; i++) {
                gVsRacePlayerVictoryCount[i] = gVsRacePlayerPoints[i] = 0;
            }
        }
    }
    sLastRacer = &gRacers[gTotalRacers - 1];
    if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
        for (i = 29; i >= 0; i--) {
            gRacers[i].character = i;
            gRacers[i].machineSkinIndex = 0;
        }
        for (var_a3 = 33; var_a3 > 0; var_a3--) {
            i = (Math_Rand1() & 0x1FFFF) % 30;
            j = (Math_Rand2() & 0x1FFFF) % 30;

            var_t0 = gRacers[i].character;
            gRacers[i].character = gRacers[j].character;
            gRacers[j].character = var_t0;
        }
    }
    if (gNumPlayers >= 2) {
        for (i = 0; i < gTotalRacers; i++) {
            gRacers[i].position = i + 1;
        }
    }

    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
        D_800F80A4 = 7.0f;
    } else {
        D_800F80A4 = 5.0f;
    }
    Racer_SetupStartPositions();
    osRecvMesg(&D_800DCAB0, &sp68, OS_MESG_NOBLOCK);
    osRecvMesg(&D_800DCAB0, &sp68, OS_MESG_BLOCK);
    for (i = 0; i < gTotalRacers; i++) {
        gRacers[i].id = i;
#ifdef EXPANSION_KIT
        if (gGameMode != GAMEMODE_COURSE_EDIT) {
#endif
            Cpu_InitRacer(&gRacers[i]);
#ifdef EXPANSION_KIT
        }
#endif
        Racer_InitRacer(&gRacers[i]);
        if (i < gNumPlayers) {
            gRacers[i].unk_2A4 = 0;
            gControllers[gPlayerControlPorts[i]].unk_72 = gControllers[gPlayerControlPorts[i]].unk_78 = 1;
            D_800E5F20[i] = D_800E5F30[i] = 0;
        }
    }

    Racer_UpdateRacerPairInfo();
    Racer_UpdateRacePositions();
    Racer_UpdateNearestRacer();

    for (i = 0; i < ARRAY_COUNT(sRacerPairInfo); i++) {
        sRacerPairInfo[i].areColliding = false;
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            Lights_SetSource(&D_8024DCE0[i].unk_21A88[j], 100, 100, 100, 255, 255, 255, 69, 69, 69);
        }
    }

    for (i = 0; i < 4; i++) {
        gPlayerReverseTimer[i] = 0;
    }

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        for (racer = sLastRacer; racer > gRacers; racer--) {
            racer->energy *= 0.5f;
            racer->maxEnergy *= 0.5f;
        }
    }
    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) &&
        (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
#ifndef EXPANSION_KIT
        D_800CE780 = 1;
        gRaceIntroTimer = 460;
#endif
        gEnableRaceSfx = true;
#ifdef EXPANSION_KIT

        if (gGameMode == GAMEMODE_COURSE_EDIT) {
            D_800CE780 = 0;
            gRaceIntroTimer = 100;
            for (racer = sLastRacer; racer >= gRacers; racer--) {
                racer->unk_17C = 13.0f;
                racer->unk_2A4 = 0;
            }
        } else {
            D_800CE780 = 1;
            gRaceIntroTimer = 460;
        }
#endif
    } else {
        gEnableRaceSfx = false;
        gRaceIntroTimer = 0;

#if BUILD_REVISION <= REVISION_B
        if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
#else
        if (gTitleDemoState != TITLE_DEMO_INACTIVE && gGameMode != GAMEMODE_RECORDS) {
#endif
            D_800CE780 = 1;
        } else {
            D_800CE780 = 0;
        }
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->stateFlags |= RACER_STATE_FLAGS_400000;
            racer->unk_17C = 13.0f;
            racer->unk_2A4 = 0;
        }
    }
    Racer_UpdateRivalRacer();

    for (i = 0; i < 3; i++) {
        gGhostRacers[i].exists = false;
    }
    gCurrentTimeAttackRecordPosition = gCurrentTimeAttackHasMaxSpeed = gBestTimedLap = D_800F5DE4 = D_800F5DEA =
        D_800F5DE8 = 0;
    gFastestGhostRacer = NULL;
    gFastestGhost = NULL;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        sReplayRecordPosX = Math_Round(gRacers[0].segmentPositionInfo.pos.x);
        sReplayRecordPosY = Math_Round(gRacers[0].segmentPositionInfo.pos.y);
        sReplayRecordPosZ = Math_Round(gRacers[0].segmentPositionInfo.pos.z);
        if (gCurrentGhostType != GHOST_NONE) {
            func_80089A74(&machineInfo);
            var_a3 = var_t0 = 0x40000000;

            for (i = 0; i < 3; i++) {
                if (gCurrentCourseInfo->encodedCourseIndex != gGhosts[i].encodedCourseIndex) {
                    continue;
                }

                if (gGhosts[i].ghostType == GHOST_PLAYER) {
                    if (gGhosts[i].raceTime < var_t0) {
                        var_t0 = gGhosts[i].raceTime;
                        gFastestGhost = &gGhosts[i];
                    }
                }
                if (gGhosts[i].ghostType != gCurrentGhostType) {
                    continue;
                }

                ghostRacer = &gGhostRacers[i];

                if (gGhosts[i].raceTime < var_a3) {
                    var_a3 = gGhosts[i].raceTime;
                    gFastestGhostRacer = ghostRacer;
                }
                ghostRacer->exists = true;
                ghostRacer->ghost = &gGhosts[i];
                ghostRacer->replayPtr = gGhosts[i].replayData;
                ghostRacer->frameCount = 0;
                ghostRacer->replayIndex = 0;
                ghostRacer->initialized = false;
                ghostRacer->scale = 1.0f;
                ghostRacer->replayPosX = sReplayRecordPosX;
                ghostRacer->replayPosY = sReplayRecordPosY;
                ghostRacer->replayPosZ = sReplayRecordPosZ;
                ghostRacer->racer = &gRacers[i + 1];
                gRacers[i + 1] = gRacers[0];
                racer = ghostRacer->racer;

                racer->id = i + 1;
                racer->character = ghostRacer->ghost->machineInfo.character;

                if (func_8008B23C(&ghostRacer->ghost->machineInfo, &machineInfo) != 0) {
                    racer->machineIndex = i + 7;
                } else {
                    racer->machineIndex = gRacers[0].machineIndex;
                }

#ifndef EXPANSION_KIT
                racer->shadowType = gMachines[racer->character].shadowType;
                racer->boostersType = gMachines[racer->character].boostersType;
#else
                if (ghostRacer->ghost->machineInfo.customType == CUSTOM_MACHINE_EDITED) {
                    racer->shadowType = D_800CDD04[ghostRacer->ghost->machineInfo.frontType * 7 +
                                                   ghostRacer->ghost->machineInfo.rearType];
                    racer->boostersType = ghostRacer->ghost->machineInfo.rearType + 30;
                } else {
                    racer->shadowType = sDefaultMachines[racer->character].shadowType;
                    racer->boostersType = sDefaultMachines[racer->character].boostersType;
                }
#endif
                racer->bodyR = ghostRacer->ghost->machineInfo.bodyR;
                racer->bodyG = ghostRacer->ghost->machineInfo.bodyG;
                racer->bodyB = ghostRacer->ghost->machineInfo.bodyB;
            }
        }
        sGhostReplayRecordingPtr = sGhostReplayRecordingBuffer;
        gUnableToRecordGhost = sReplayRecordFrameCount = sGhostReplayRecordingSize = 0;
    }
}

#ifndef EXPANSION_KIT
void func_8008D33C(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        gMachines[i] = sDefaultMachines[i];
    }
}
#else
extern CustomMachinesInfo gCustomMachinesInfo;
extern u8 D_i2_80111848[];

#ifdef NON_MATCHING
void func_8008D33C(void) {
    CustomMachineInfo* temp_a2;
    s32 characterSlot;
    s32 i;
    CustomMachine* temp_a1;

    for (i = 29; i >= 0; i--) {
        characterSlot = Character_GetSlotFromCharacter(i);
        temp_a1 = &gCustomMachinesInfo.customMachines[characterSlot];
        if (gCustomMachinesInfo.characterCustomState[characterSlot] > 0) {
            temp_a2 = &sCustomMachineInfo[i];
            temp_a2->decalR = temp_a1->decalR;
            temp_a2->decalG = temp_a1->decalG;
            temp_a2->decalB = temp_a1->decalB;
            temp_a2->numberR = temp_a1->numberR;
            temp_a2->numberG = temp_a1->numberG;
            temp_a2->numberB = temp_a1->numberB;
            temp_a2->cockpitR = temp_a1->cockpitR;
            temp_a2->cockpitG = temp_a1->cockpitG;
            temp_a2->cockpitB = temp_a1->cockpitB;
            temp_a2->frontType = temp_a1->frontType;
            temp_a2->rearType = temp_a1->rearType;
            temp_a2->wingType = temp_a1->wingType;
            temp_a2->decal = temp_a1->decal - 1;
            temp_a2->logo = temp_a1->logo - 1;
            gMachines[i].shadowType = D_800CDD04[(temp_a2->frontType * 7) + temp_a2->rearType];
            gMachines[i].boostersType = temp_a2->rearType + 30;
            gMachines[i].customType = CUSTOM_MACHINE_EDITED;
            gMachines[i].number = sDefaultMachines[i].number;
            gMachines[i].red[0] = temp_a1->red;
            gMachines[i].green[0] = temp_a1->green;
            gMachines[i].blue[0] = temp_a1->blue;
            gMachines[i].red[1] = temp_a1->red + 0x40;
            gMachines[i].green[1] = temp_a1->green + 0x40;
            gMachines[i].blue[1] = temp_a1->blue + 0x40;
            gMachines[i].red[2] = temp_a1->red + 0x80;
            gMachines[i].green[2] = temp_a1->green + 0x80;
            gMachines[i].blue[2] = temp_a1->blue + 0x80;
            gMachines[i].red[3] = temp_a1->red + 0xC0;
            gMachines[i].green[3] = temp_a1->green + 0xC0;
            gMachines[i].blue[3] = temp_a1->blue + 0xC0;
            gMachines[i].machineStats[BODY_STAT] = BODY_E - temp_a1->body;
            gMachines[i].machineStats[BOOST_STAT] = BOOST_E - temp_a1->boost;
            gMachines[i].machineStats[GRIP_STAT] = GRIP_E - temp_a1->grip;
            gMachines[i].weight =
                D_800CF488[temp_a2->frontType] + D_800CF498[temp_a2->rearType] + D_800CF4A8[temp_a2->wingType];
        } else if (gCustomMachinesInfo.characterCustomState[characterSlot] < 0) {
            if ((i == CAPTAIN_FALCON) && (D_i2_80111848[CAPTAIN_FALCON] != 0)) {
                gMachines[i] = sDefaultMachines[30];
            } else {
                if ((i == SAMURAI_GOROH) && (D_i2_80111848[SAMURAI_GOROH] != 0)) {
                    gMachines[i] = sDefaultMachines[31];
                } else if ((i == JODY_SUMMER) && (D_i2_80111848[JODY_SUMMER] != 0)) {
                    gMachines[i] = sDefaultMachines[32];
                } else {
                    gMachines[i] = sDefaultMachines[i];
                }
            }
        } else {
            gMachines[i] = sDefaultMachines[i];
        }
    }
}
#else
void func_8008D33C(void);
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/game/racer/func_8008D33C.s")
#endif
#endif

void func_8008D3C4(s32 character, s32 arg1) {
    Gfx* gfx;
    s32 i;
    Machine* machine = &gMachines[character];

    if (machine->customType == CUSTOM_MACHINE_EDITED) {
        gfx = Machine_DrawLoadCustomTextures(D_800CDD38[arg1], sCustomMachineInfo[character].logo, machine->number - 1,
                                             sCustomMachineInfo[character].decal);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = Machine_DrawCustom(D_800CDDB0[arg1 * 6 + i], i, sCustomMachineInfo[character].frontType,
                                     sCustomMachineInfo[character].rearType, sCustomMachineInfo[character].wingType,
                                     sCustomMachineInfo[character].decalR, sCustomMachineInfo[character].decalG,
                                     sCustomMachineInfo[character].decalB, sCustomMachineInfo[character].numberR,
                                     sCustomMachineInfo[character].numberG, sCustomMachineInfo[character].numberB, 255,
                                     255, 255, sCustomMachineInfo[character].cockpitR,
                                     sCustomMachineInfo[character].cockpitG, sCustomMachineInfo[character].cockpitB);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (machine->customType != CUSTOM_MACHINE_DEFAULT) {
        character = machine->customType - CUSTOM_MACHINE_SUPER_FALCON + 30;
    } else {
        character = character;
    }

    gfx = sMachineLoadTexturesFuncs[character](D_800CDD38[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = sMachineDrawFuncs[character][i](D_800CDDB0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8008D5F4(MachineInfo* machineInfo, s32 arg1) {
    s32 pad[2];
    s32 var_v1;
    Gfx* gfx;
    s32 i;

    if (machineInfo->customType == CUSTOM_MACHINE_EDITED) {
        gfx = Machine_DrawLoadCustomTextures(D_800CDD38[arg1], machineInfo->logo, machineInfo->number,
                                             machineInfo->decal);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx =
                Machine_DrawCustom(D_800CDDB0[arg1 * 6 + i], i, machineInfo->frontType, machineInfo->rearType,
                                   machineInfo->wingType, machineInfo->decalR, machineInfo->decalG, machineInfo->decalB,
                                   machineInfo->numberR, machineInfo->numberG, machineInfo->numberB, 255, 255, 255,
                                   machineInfo->cockpitR, machineInfo->cockpitG, machineInfo->cockpitB);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (machineInfo->customType != CUSTOM_MACHINE_DEFAULT) {
        var_v1 = machineInfo->customType - CUSTOM_MACHINE_SUPER_FALCON + 30;
    } else {
        var_v1 = machineInfo->character;
    }

    gfx = sMachineLoadTexturesFuncs[var_v1](D_800CDD38[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = sMachineDrawFuncs[var_v1][i](D_800CDDB0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8008D7E8(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        func_8008D3C4(i, i);
    }
}

extern s32 gCourseIndex;

void func_8008D824(void) {
    CourseInfo* courseInfo;
    s32 i;
    u8 var;

    courseInfo = &gCourseInfos[gCourseIndex];

    for (i = 4; i >= 0; i--) {
        sRecordsMachineIndices[i] = i + 1;
        func_8008D5F4(&courseInfo->recordMachineInfos[i], sRecordsMachineIndices[i]);
    }

    var = 5;
    sRecordsMachineIndices[var] = var + 1;
    func_8008D5F4(&courseInfo->maxSpeedMachine, sRecordsMachineIndices[var]);
    var = 6;
    sRecordsMachineIndices[var] = var + 1;
    func_8008D5F4(&courseInfo->bestTimeMachine, sRecordsMachineIndices[var]);
}

void func_8008D8E8(void) {
    s32 i;

#ifndef EXPANSION_KIT
    func_800A4DF0();
#endif
    func_8008D3C4(gPlayerCharacters[0], 0);
    func_8008D824();

    for (i = 0; i < 3; i++) {
        if (gCurrentCourseInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) {
            func_8008D5F4(&gGhosts[i].machineInfo, i + 7);
        }
    }
}

void func_8008D97C(void) {
    Gfx* gfx;
    s32 i;
    s32 index;
    s32 j;

    for (i = 29; i >= 0; i--) {
        index = i;
        gfx = sMachineLoadTexturesFuncs[index](D_800CDD38[i]);
        gSPEndDisplayList(gfx);
        for (j = 4; j >= 0; j--) {
            gfx = sMachineDrawFuncs[index][j](D_800CDDB0[i * 6 + j]);
            gSPEndDisplayList(gfx);
        }
    }
}

void func_8008DA68(void) {
    s32 i;

    D_800E5FD6 = D_800E5FF0 = 0;
    sLastMultiplayerTotalRacerCount = sLastMultiplayerPlayerCount = 0;

    for (i = 0; i < ARRAY_COUNT(gRacers); i++) {
        gRacers[i].character = (s8) (i % ARRAY_COUNT(gRacers));
        gRacers[i].machineSkinIndex = 0;
        gRacers[i].unk_1A8 = func_8008960C(0.5f);
        if (i < 4) {
            gPlayerCharacters[i] = gRacers[i].character;
            gPlayerMachineSkins[i] = gRacers[i].machineSkinIndex;
            gPlayerEngine[i] = 0.5f;
        }
    }
    func_8008D33C();
}

void func_8008DB98(void) {
    func_8008DA68();
}

void func_8008DBB8(Racer* arg0, s32 arg1) {
    Racer* temp_v0;

    if (arg1 < arg0->unk_288) {
        return;
    }

    temp_v0 = arg0->unk_28C;
    if (temp_v0 == NULL) {
        return;
    }
    if (temp_v0->stateFlags & (RACER_STATE_FINISHED | RACER_STATE_RETIRED | RACER_STATE_SPINNING_OUT)) {
        return;
    }

    D_800E5FD4++;
    gRacersKOd++;
    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacersKOd == 5)) {
        gPlayerLives[0]++;
        func_i3_80128D8C();
        Hud_TriggerLivesIncrease();
        if (gEnableRaceSfx) {
            Audio_TriggerSystemSE(NA_SE_NONE);
        }
    }
    temp_v0->energyRegain += temp_v0->maxEnergy * 0.125f;
    if ((gNumPlayers == 1) && gEnableRaceSfx) {
        Audio_TriggerSystemSE(NA_SE_57);
    }
}

void Racer_ReceiveDamage(Racer* racer, f32 damageStrength) {
    s32 pad[7];
    f32 x;
    f32 y;
    f32 z;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 i;

    if (racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED)) {
        if (((racer->stateFlags & (RACER_STATE_ACTIVE | RACER_STATE_CRASHED)) ==
             (RACER_STATE_ACTIVE | RACER_STATE_CRASHED)) &&
            (D_800CE770 < damageStrength)) {
            racer->stateFlags &= ~RACER_STATE_ACTIVE;
            racer->trueBasis = racer->segmentBasis;
            D_800E5FC0++;
            if (racer->id < gNumPlayers) {
                Racer_StopRacerSfx(racer);
            }
            if (gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(racer->id, NA_SE_8);
            }
            if (racer->machineLod != 0) {
                if (racer->unk_28C == NULL) {
                    x = y = z = 0.0f;
                } else {
                    x = racer->unk_28C->velocity.x;
                    y = racer->unk_28C->velocity.y;
                    z = racer->unk_28C->velocity.z;
                }
                Effects_SpawnExplosion2(racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                                        racer->segmentPositionInfo.pos.z, x, y, z, 40.0f, racer);

                temp_s5 = racer->bodyRF;
                temp_s6 = racer->bodyGF;
                temp_s7 = racer->bodyBF;

                i = (racer->id < gNumPlayers) ? 60 : 30;
                do {

                    temp_fs2 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    temp_fs0 = ((Math_Rand2() & 0x1FFFF) * (7.0f / 131071.0f)) + 3.5f;

                    temp_fs1 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    Effects_SpawnMachineDebris(
                        ((s32) (Math_Rand2() % 32) - 0x10) + racer->segmentPositionInfo.pos.x,
                        ((s32) (Math_Rand1() % 32) - 0x10) + racer->segmentPositionInfo.pos.y,
                        ((s32) (Math_Rand1() % 32) - 0x10) + racer->segmentPositionInfo.pos.z,
                        x + (racer->trueBasis.z.x * temp_fs2) + (temp_fs0 * racer->trueBasis.y.x) +
                            (temp_fs1 * racer->trueBasis.x.x),
                        y + (racer->trueBasis.z.y * temp_fs2) + (temp_fs0 * racer->trueBasis.y.y) +
                            (temp_fs1 * racer->trueBasis.x.y),
                        z + (racer->trueBasis.z.z * temp_fs2) + (temp_fs0 * racer->trueBasis.y.z) +
                            (temp_fs1 * racer->trueBasis.x.z),
                        &racer->trueBasis, temp_s5, temp_s6, temp_s7, racer);
                    i--;
                } while (i != 0);
            }
        }
    } else {
#if BUILD_REVISION >= REVISION_C
        if (D_800CE780 != 0) {
#endif
            racer->energy -= damageStrength;
#if BUILD_REVISION >= REVISION_C
        }
#endif
        racer->stateFlags |= RACER_STATE_RECEIVED_DAMAGE;
        if (racer->energy < 0.0f) {
            if (racer->machineLod == 0) {
                racer->energy = 0.1f;
                return;
            }
            racer->energy = 0.0f;
            racer->unk_238 = 0.2f * damageStrength;
            if (racer->unk_238 > 1.0f) {
                racer->unk_238 = 1.0f;
            }
            if (Math_Rand1() % 2) {
                racer->unk_238 *= -1.0f;
            }

            if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
                racer->stateFlags |= RACER_STATE_SPINNING_OUT;
                racer->stateFlags &= ~RACER_STATE_FLAGS_400000;
                racer->spinOutTimer = 1;
                racer->unk_234 = 2.0f;
                func_8008DBB8(racer, 60);
            }
        }
    }
}
void Racer_HitWall(Racer* racer, f32 lateralVelocity, f32 wallDirection, f32 edgeDisplacement) {
    s32 pad;
    Racer* var;
    f32 var_fv0;

    var_fv0 = racer->segmentBasis.z.x * edgeDisplacement;
    racer->segmentPositionInfo.segmentDisplacement.x -= var_fv0;
    racer->segmentPositionInfo.pos.x -= var_fv0;
    racer->segmentPositionInfo.lastGroundedPos.x -= var_fv0;

    var_fv0 = racer->segmentBasis.z.y * edgeDisplacement;
    racer->segmentPositionInfo.segmentDisplacement.y -= var_fv0;
    racer->segmentPositionInfo.pos.y -= var_fv0;
    racer->segmentPositionInfo.lastGroundedPos.y -= var_fv0;

    var_fv0 = racer->segmentBasis.z.z * edgeDisplacement;
    racer->segmentPositionInfo.segmentDisplacement.z -= var_fv0;
    racer->segmentPositionInfo.pos.z -= var_fv0;
    racer->segmentPositionInfo.lastGroundedPos.z -= var_fv0;

    racer->segmentPositionInfo.distanceFromSegment = sqrtf(SQ(racer->segmentPositionInfo.segmentDisplacement.x) +
                                                           SQ(racer->segmentPositionInfo.segmentDisplacement.y) +
                                                           SQ(racer->segmentPositionInfo.segmentDisplacement.z));

    if (lateralVelocity * wallDirection <= 0.0f) {
        return;
    }

    if (lateralVelocity * wallDirection > 0.01f) {
        if (racer->machineLod != 0) {
            Effects_SpawnCollisionSparks(
                racer->segmentPositionInfo.pos.x + ((wallDirection * 15.0f) * racer->segmentBasis.z.x),
                racer->segmentPositionInfo.pos.y + ((wallDirection * 15.0f) * racer->segmentBasis.z.y),
                racer->segmentPositionInfo.pos.z + ((wallDirection * 15.0f) * racer->segmentBasis.z.z),
                racer->velocity.x, racer->velocity.y, racer->velocity.z,
                (lateralVelocity * wallDirection * 1.5f) + 18.0f, racer);
        }
        if (gEnableRaceSfx) {
            Audio_PlayerTriggerSEStart(racer->id, NA_SE_3);
        }
        Racer_ReceiveDamage(racer, lateralVelocity * wallDirection * 0.7f);
    }

    racer->velocity.x = (racer->velocity.x - racer->unk_234 * lateralVelocity * racer->segmentBasis.z.x) * 0.998f;
    racer->velocity.y = (racer->velocity.y - racer->unk_234 * lateralVelocity * racer->segmentBasis.z.y) * 0.998f;
    racer->velocity.z = (racer->velocity.z - racer->unk_234 * lateralVelocity * racer->segmentBasis.z.z) * 0.998f;

    // FAKE
    var = racer;
    var->recoilTilt.x = var->segmentBasis.z.x * (-0.15f * lateralVelocity);
    var->recoilTilt.y = var->segmentBasis.z.y * (-0.15f * lateralVelocity);
    var->recoilTilt.z = var->segmentBasis.z.z * (-0.15f * lateralVelocity);

    racer->stateFlags |= RACER_STATE_COLLISION_RECOIL;
}

void func_8008E418(Racer* racer) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = ((racer->gravityUp.x * racer->tiltUp.x) + (racer->gravityUp.y * racer->tiltUp.y) +
                (racer->gravityUp.z * racer->tiltUp.z)) *
               0.15f * racer->tiltUpInput;

    racer->tiltUp.x = racer->trueBasis.y.x + (temp_fv0 * racer->trueBasis.x.x);
    racer->tiltUp.y = racer->trueBasis.y.y + (temp_fv0 * racer->trueBasis.x.y);
    racer->tiltUp.z = racer->trueBasis.y.z + (temp_fv0 * racer->trueBasis.x.z);

    temp_fv1 = 1.0f / sqrtf(SQ(racer->tiltUp.x) + SQ(racer->tiltUp.y) + SQ(racer->tiltUp.z));
    racer->tiltUp.x *= temp_fv1;
    racer->tiltUp.y *= temp_fv1;
    racer->tiltUp.z *= temp_fv1;
}

void func_8008E504(Racer* racer) {

    racer->gravityUp.x -= 0.5f * racer->gravityUp.x;
    racer->gravityUp.y += 0.5f * (1.0f - racer->gravityUp.y);
    racer->gravityUp.z -= 0.5f * racer->gravityUp.z;
}

void func_8008E54C(Racer* racer, f32 airborneRange) {
    f32 temp_ft4;
    f32 lateralOffset;
    f32 temp_fv0;

    if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
        racer->currentRadiusLeft += 57.5f;
        racer->currentRadiusRight += 57.5f;
        func_80090568(racer);

        racer->currentRadiusLeft -= 57.5f;
        racer->currentRadiusRight -= 57.5f;
        if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
            return;
        }
        lateralOffset = (racer->segmentBasis.z.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                        (racer->segmentBasis.z.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                        (racer->segmentBasis.z.z * racer->segmentPositionInfo.segmentDisplacement.z);
        if ((lateralOffset < -racer->currentRadiusRight) || (racer->currentRadiusLeft < lateralOffset)) {
            racer->stateFlags |= RACER_STATE_FLAGS_80000000;
            Racer_ReceiveDamage(racer, 2.0f);
            Effects_SpawnCollisionSparks(racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                                         racer->segmentPositionInfo.pos.z, racer->velocity.x, racer->velocity.y,
                                         racer->velocity.z, 40.0f, racer);
            if (gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(racer->id, NA_SE_3);
            }
        }
    } else {
        lateralOffset = (racer->segmentBasis.z.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                        (racer->segmentBasis.z.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                        (racer->segmentBasis.z.z * racer->segmentPositionInfo.segmentDisplacement.z);
        racer->heightAboveGround = (racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                                   (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                                   (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z);
        racer->upFromGround.x = racer->segmentBasis.y.x;
        racer->upFromGround.y = racer->segmentBasis.y.y;
        racer->upFromGround.z = racer->segmentBasis.y.z;

        if (airborneRange < racer->heightAboveGround) {
            racer->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (racer->id < gNumPlayers) {
                if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                    racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                    }
                }
            }
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }

        if (racer->heightAboveGround < 0.0f) {
            temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.x;
            racer->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
            racer->segmentPositionInfo.pos.x -= temp_fv0;
            racer->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

            temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.y;
            racer->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
            racer->segmentPositionInfo.pos.y -= temp_fv0;
            racer->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

            temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.z;
            racer->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
            racer->segmentPositionInfo.pos.z -= temp_fv0;
            racer->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

            racer->heightAboveGround = 0.0f;

            temp_ft4 = (racer->segmentBasis.y.x * racer->velocity.x) + (racer->segmentBasis.y.y * racer->velocity.y) +
                       (racer->segmentBasis.y.z * racer->velocity.z);
            if (temp_ft4 < 0.0f) {
                racer->velocity.x -= temp_ft4 * racer->segmentBasis.y.x;
                racer->velocity.y -= temp_ft4 * racer->segmentBasis.y.y;
                racer->velocity.z -= temp_ft4 * racer->segmentBasis.y.z;
                if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                    Audio_Chakuchi(racer->id, temp_ft4);
                }
            }
        }

        if (racer->heightAboveGround <= 15.0f) {
            racer->stateFlags &= ~RACER_STATE_AIRBORNE;
            if (racer->id < gNumPlayers) {

                if (racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE) {
                    racer->soundEffectFlags &= ~RACER_SE_FLAGS_AIRBORNE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_8);
                    }
                }
            }

            racer->gravityUp.x = racer->tiltUp.x = racer->segmentBasis.y.x;
            racer->gravityUp.y = racer->tiltUp.y = racer->segmentBasis.y.y;
            racer->gravityUp.z = racer->tiltUp.z = racer->segmentBasis.y.z;

        } else {
            racer->stateFlags |= RACER_STATE_AIRBORNE;
            if (racer->id < gNumPlayers) {
                if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                    racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                    }
                }
            }
            func_8008E418(racer);
            func_8008E504(racer);

            if (racer->heightAboveGround < 30.0f) {

                temp_ft4 = (racer->heightAboveGround - 15.0f) / 15.0f;
                racer->gravityUp.x =
                    (racer->gravityUp.x - racer->segmentBasis.y.x) * temp_ft4 + racer->segmentBasis.y.x;
                racer->gravityUp.y =
                    (racer->gravityUp.y - racer->segmentBasis.y.y) * temp_ft4 + racer->segmentBasis.y.y;
                racer->gravityUp.z =
                    (racer->gravityUp.z - racer->segmentBasis.y.z) * temp_ft4 + racer->segmentBasis.y.z;

                racer->tiltUp.x = (racer->tiltUp.x - racer->segmentBasis.y.x) * temp_ft4 + racer->tiltUp.x;
                racer->tiltUp.y = (racer->tiltUp.y - racer->segmentBasis.y.y) * temp_ft4 + racer->tiltUp.y;
                racer->tiltUp.z = (racer->tiltUp.z - racer->segmentBasis.y.z) * temp_ft4 + racer->tiltUp.z;

                temp_fv0 = 1.0f / sqrtf(SQ(racer->tiltUp.x) + SQ(racer->tiltUp.y) + SQ(racer->tiltUp.z));
                racer->tiltUp.x *= temp_fv0;
                racer->tiltUp.y *= temp_fv0;
                racer->tiltUp.z *= temp_fv0;
            }
        }

        if (lateralOffset < -racer->currentRadiusRight) {
            Racer_HitWall(racer,
                          (racer->segmentBasis.z.x * racer->velocity.x) +
                              (racer->segmentBasis.z.y * racer->velocity.y) +
                              (racer->segmentBasis.z.z * racer->velocity.z),
                          -1.0f, racer->currentRadiusRight + lateralOffset);
        } else if (racer->currentRadiusLeft < lateralOffset) {
            Racer_HitWall(racer,
                          (racer->segmentBasis.z.x * racer->velocity.x) +
                              (racer->segmentBasis.z.y * racer->velocity.y) +
                              (racer->segmentBasis.z.z * racer->velocity.z),
                          1.0f, lateralOffset - racer->currentRadiusLeft);
        } else {
            racer->segmentPositionInfo.distanceFromSegment =
                sqrtf(SQ(racer->segmentPositionInfo.segmentDisplacement.x) +
                      SQ(racer->segmentPositionInfo.segmentDisplacement.y) +
                      SQ(racer->segmentPositionInfo.segmentDisplacement.z));
        }

        racer->shadowPos.x = racer->segmentPositionInfo.pos.x - (racer->heightAboveGround * racer->segmentBasis.y.x);
        racer->shadowPos.y = racer->segmentPositionInfo.pos.y - (racer->heightAboveGround * racer->segmentBasis.y.y);
        racer->shadowPos.z = racer->segmentPositionInfo.pos.z - (racer->heightAboveGround * racer->segmentBasis.y.z);
    }
}

void func_8008EC38(Racer* racer) {
    func_8008E54C(racer, 40.0f);
}

void func_8008EC58(Racer* racer) {
    func_8008E54C(racer, 145.0f);
}

void func_8008EC78(Racer* racer) {
    func_8008E54C(racer, 210.0f);
}

extern f32 gTrackJoinUpperLength[];

void func_8008EC98(Racer* racer) {
    f32 pipeRadius;
    f32 temp_fv0;
    f32 var_fv1;
    f32 joinProportion;
    f32 x;
    f32 y;
    f32 z;
    f32 var_fs0;

    if (racer->segmentPositionInfo.segmentTValue < racer->segmentPositionInfo.courseSegment->previousJoinEndTValue) {
        pipeRadius = joinProportion =
            racer->segmentPositionInfo.segmentLengthProportion / racer->segmentPositionInfo.courseSegment->joinScale;
        pipeRadius *= racer->currentRadiusLeft;
        var_fs0 = racer->currentRadiusLeft;
    } else if (racer->segmentPositionInfo.courseSegment->nextJoinStartTValue <
               racer->segmentPositionInfo.segmentTValue) {
        pipeRadius = joinProportion = (1.0f - racer->segmentPositionInfo.segmentLengthProportion) /
                                      racer->segmentPositionInfo.courseSegment->joinScale;
        pipeRadius *= racer->currentRadiusLeft;
        var_fs0 = -racer->currentRadiusLeft;
    } else {
        pipeRadius = racer->currentRadiusLeft;
        var_fs0 = 0.0f;
    }

    racer->heightAboveGround = racer->currentRadiusLeft - racer->segmentPositionInfo.distanceFromSegment;
    if (racer->segmentPositionInfo.distanceFromSegment > 0.01f) {
        var_fv1 = -1.0f / racer->segmentPositionInfo.distanceFromSegment;
        racer->upFromGround.x = racer->segmentPositionInfo.segmentDisplacement.x * var_fv1;
        racer->upFromGround.y = racer->segmentPositionInfo.segmentDisplacement.y * var_fv1;
        racer->upFromGround.z = racer->segmentPositionInfo.segmentDisplacement.z * var_fv1;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = ((racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                   (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                   (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z)) -
                  23.0f;
        if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
            if ((var_fv1 >= 0.0f) || (racer->currentRadiusLeft < racer->segmentPositionInfo.distanceFromSegment)) {
                func_8008E418(racer);
                func_8008E504(racer);
                racer->shadowPos.y = -54321.0f;
                return;
            }
            racer->stateFlags &= ~RACER_STATE_FLAGS_80000000;
        } else if (var_fv1 >= 0.0f) {
            racer->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (racer->id < gNumPlayers) {
                if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                    racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                    }
                }
            }
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
    } else if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
        if (racer->currentRadiusLeft < racer->segmentPositionInfo.distanceFromSegment) {
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
        racer->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = pipeRadius + (racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                  (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                  (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z);
        if (var_fv1 < racer->heightAboveGround) {
            racer->heightAboveGround = var_fv1;
            racer->upFromGround.x = racer->segmentBasis.y.x;
            racer->upFromGround.y = racer->segmentBasis.y.y;
            racer->upFromGround.z = racer->segmentBasis.y.z;

            racer->tiltUp.x =
                (gTrackJoinUpperLength[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * racer->segmentBasis.y.x) +
                (var_fs0 * racer->segmentBasis.x.x);
            racer->tiltUp.y =
                (gTrackJoinUpperLength[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * racer->segmentBasis.y.y) +
                (var_fs0 * racer->segmentBasis.x.y);
            racer->tiltUp.z =
                (gTrackJoinUpperLength[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * racer->segmentBasis.y.z) +
                (var_fs0 * racer->segmentBasis.x.z);

            var_fv1 = 1.0f / sqrtf(SQ(racer->tiltUp.x) + SQ(racer->tiltUp.y) + SQ(racer->tiltUp.z));

            racer->tiltUp.x *= var_fv1;
            racer->tiltUp.y *= var_fv1;
            racer->tiltUp.z *= var_fv1;

            if (racer->heightAboveGround < 0.0f) {
                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.x;
                racer->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
                racer->segmentPositionInfo.pos.x -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.y;
                racer->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
                racer->segmentPositionInfo.pos.y -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.z;
                racer->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
                racer->segmentPositionInfo.pos.z -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

                racer->segmentPositionInfo.distanceFromSegment =
                    sqrtf(SQ(racer->segmentPositionInfo.segmentDisplacement.x) +
                          SQ(racer->segmentPositionInfo.segmentDisplacement.y) +
                          SQ(racer->segmentPositionInfo.segmentDisplacement.z));
                racer->heightAboveGround = 0.0f;

                var_fs0 = (racer->segmentBasis.y.x * racer->velocity.x) +
                          (racer->segmentBasis.y.y * racer->velocity.y) + (racer->segmentBasis.y.z * racer->velocity.z);
                if (var_fs0 < 0.0f) {
                    racer->velocity.x -= var_fs0 * racer->segmentBasis.y.x;
                    racer->velocity.y -= var_fs0 * racer->segmentBasis.y.y;
                    racer->velocity.z -= var_fs0 * racer->segmentBasis.y.z;
                    if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                        Audio_Chakuchi(racer->id, var_fs0);
                    }
                }
            }
        } else {
            racer->tiltUp = racer->upFromGround;
        }
        x = ((racer->tiltUp.x - racer->segmentBasis.y.x) * joinProportion) + racer->segmentBasis.y.x;
        y = ((racer->tiltUp.y - racer->segmentBasis.y.y) * joinProportion) + racer->segmentBasis.y.y;
        z = ((racer->tiltUp.z - racer->segmentBasis.y.z) * joinProportion) + racer->segmentBasis.y.z;

        var_fv1 = sqrtf(SQ(x) + SQ(y) + SQ(z));
        if (var_fv1 > 0.01f) {
            var_fv1 = 1.0f / var_fv1;
            racer->tiltUp.x = var_fv1 * x;
            racer->tiltUp.y = var_fv1 * y;
            racer->tiltUp.z = var_fv1 * z;
        }

        racer->gravityUp.x =
            ((racer->upFromGround.x - racer->segmentBasis.y.x) * joinProportion) + racer->segmentBasis.y.x;
        racer->gravityUp.y =
            ((racer->upFromGround.y - racer->segmentBasis.y.y) * joinProportion) + racer->segmentBasis.y.y;
        racer->gravityUp.z =
            ((racer->upFromGround.z - racer->segmentBasis.y.z) * joinProportion) + racer->segmentBasis.y.z;
    } else {
        racer->gravityUp = racer->tiltUp = racer->upFromGround;
    }

    if (racer->currentRadiusLeft < racer->segmentPositionInfo.distanceFromSegment) {
        var_fv1 = racer->currentRadiusLeft / racer->segmentPositionInfo.distanceFromSegment;
        racer->segmentPositionInfo.distanceFromSegment = racer->currentRadiusLeft;

        racer->segmentPositionInfo.segmentDisplacement.x *= var_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.x + racer->segmentPositionInfo.segmentPos.x;
        racer->segmentPositionInfo.lastGroundedPos.x = temp_fv0;
        racer->segmentPositionInfo.pos.x = temp_fv0;

        racer->segmentPositionInfo.segmentDisplacement.y *= var_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.y + racer->segmentPositionInfo.segmentPos.y;
        racer->segmentPositionInfo.lastGroundedPos.y = temp_fv0;
        racer->segmentPositionInfo.pos.y = temp_fv0;

        racer->segmentPositionInfo.segmentDisplacement.z *= var_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.z + racer->segmentPositionInfo.segmentPos.z;
        racer->segmentPositionInfo.lastGroundedPos.z = temp_fv0;
        racer->segmentPositionInfo.pos.z = temp_fv0;

        racer->heightAboveGround = 0.0f;

        var_fs0 = (racer->upFromGround.x * racer->velocity.x) + (racer->upFromGround.y * racer->velocity.y) +
                  (racer->upFromGround.z * racer->velocity.z);
        if (var_fs0 < 0.0f) {
            racer->velocity.x -= var_fs0 * racer->upFromGround.x;
            racer->velocity.y -= var_fs0 * racer->upFromGround.y;
            racer->velocity.z -= var_fs0 * racer->upFromGround.z;
            if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                Audio_Chakuchi(racer->id, var_fs0);
            }
        }
    }

    racer->shadowPos.x = racer->segmentPositionInfo.pos.x - (racer->heightAboveGround * racer->upFromGround.x);
    racer->shadowPos.y = racer->segmentPositionInfo.pos.y - (racer->heightAboveGround * racer->upFromGround.y);
    racer->shadowPos.z = racer->segmentPositionInfo.pos.z - (racer->heightAboveGround * racer->upFromGround.z);

    if (racer->heightAboveGround <= 15.0f) {
        racer->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
    } else {
        racer->stateFlags |= RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
    }
}

void func_8008F550(Racer* racer) {
    f32 var_fa1;
    f32 temp_fv1;
    f32 cylinderRadius;
    f32 joinProportion;
    f32 x;
    f32 y;
    f32 z;
    f32 temp_fv0;

    if (racer->segmentPositionInfo.segmentTValue < racer->segmentPositionInfo.courseSegment->previousJoinEndTValue) {
        cylinderRadius = joinProportion =
            racer->segmentPositionInfo.segmentLengthProportion / racer->segmentPositionInfo.courseSegment->joinScale;
        cylinderRadius *= racer->currentRadiusLeft;
        var_fa1 = racer->currentRadiusLeft;
    } else if (racer->segmentPositionInfo.courseSegment->nextJoinStartTValue <
               racer->segmentPositionInfo.segmentTValue) {
        var_fa1 = -racer->currentRadiusLeft;
        cylinderRadius = joinProportion = (1.0f - racer->segmentPositionInfo.segmentLengthProportion) /
                                          racer->segmentPositionInfo.courseSegment->joinScale;
        cylinderRadius *= racer->currentRadiusLeft;
    } else {
        var_fa1 = 0.0f;
        cylinderRadius = racer->currentRadiusLeft;
    }

    racer->heightAboveGround = racer->segmentPositionInfo.distanceFromSegment - cylinderRadius;
    if (racer->segmentPositionInfo.distanceFromSegment > 0.01f) {
        temp_fv1 = 1.0f / racer->segmentPositionInfo.distanceFromSegment;
        racer->upFromGround.x = racer->segmentPositionInfo.segmentDisplacement.x * temp_fv1;
        racer->upFromGround.y = racer->segmentPositionInfo.segmentDisplacement.y * temp_fv1;
        racer->upFromGround.z = racer->segmentPositionInfo.segmentDisplacement.z * temp_fv1;
    }

    racer->shadowPos.x = racer->segmentPositionInfo.pos.x - (racer->heightAboveGround * racer->upFromGround.x);
    racer->shadowPos.y = racer->segmentPositionInfo.pos.y - (racer->heightAboveGround * racer->upFromGround.y);
    racer->shadowPos.z = racer->segmentPositionInfo.pos.z - (racer->heightAboveGround * racer->upFromGround.z);
    if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((racer->currentRadiusLeft + 200.0f) < racer->segmentPositionInfo.distanceFromSegment) {
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
        racer->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else {
        if ((racer->currentRadiusLeft + 200.0f) < racer->segmentPositionInfo.distanceFromSegment) {
            racer->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (racer->id < gNumPlayers) {
                if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                    racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                    }
                }
            }
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
    }

    if (var_fa1 != 0.0f) {

        x = ((racer->upFromGround.x - racer->segmentBasis.y.x) * joinProportion) + racer->segmentBasis.y.x;
        y = ((racer->upFromGround.y - racer->segmentBasis.y.y) * joinProportion) + racer->segmentBasis.y.y;
        z = ((racer->upFromGround.z - racer->segmentBasis.y.z) * joinProportion) + racer->segmentBasis.y.z;

        temp_fv1 = sqrtf(SQ(x) + SQ(y) + SQ(z));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            racer->tiltUp.x = temp_fv1 * x;
            racer->tiltUp.y = temp_fv1 * y;
            racer->tiltUp.z = temp_fv1 * z;
        }

        temp_fv1 = 1.0f - joinProportion;
        x = racer->segmentBasis.y.x * SQ(temp_fv1);
        y = racer->segmentBasis.y.y * SQ(temp_fv1);
        z = racer->segmentBasis.y.z * SQ(temp_fv1);

        racer->gravityUp.x = ((racer->upFromGround.x - x) * joinProportion) + x;
        racer->gravityUp.y = ((racer->upFromGround.y - y) * joinProportion) + y;
        racer->gravityUp.z = ((racer->upFromGround.z - z) * joinProportion) + z;
        temp_fv1 = (joinProportion * 200.0f) + cylinderRadius +
                   (racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                   (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                   (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z);
        if (temp_fv1 < racer->heightAboveGround) {
            racer->heightAboveGround = temp_fv1;
            racer->upFromGround.x = racer->segmentBasis.y.x;
            racer->upFromGround.y = racer->segmentBasis.y.y;
            racer->upFromGround.z = racer->segmentBasis.y.z;
            if (racer->heightAboveGround < 0.0f) {

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.x;
                racer->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
                racer->segmentPositionInfo.pos.x -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.y;
                racer->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
                racer->segmentPositionInfo.pos.y -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.z;
                racer->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
                racer->segmentPositionInfo.pos.z -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

                racer->segmentPositionInfo.distanceFromSegment =
                    sqrtf(SQ(racer->segmentPositionInfo.segmentDisplacement.x) +
                          SQ(racer->segmentPositionInfo.segmentDisplacement.y) +
                          SQ(racer->segmentPositionInfo.segmentDisplacement.z));
                racer->heightAboveGround = 0.0f;
            }
        }
    } else {
        racer->gravityUp = racer->tiltUp = racer->upFromGround;
    }

    if (racer->segmentPositionInfo.distanceFromSegment < cylinderRadius) {
        temp_fv1 = cylinderRadius / racer->segmentPositionInfo.distanceFromSegment;
        racer->segmentPositionInfo.distanceFromSegment = cylinderRadius;

        racer->segmentPositionInfo.segmentDisplacement.x *= temp_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.x + racer->segmentPositionInfo.segmentPos.x;
        racer->segmentPositionInfo.lastGroundedPos.x = temp_fv0;
        racer->segmentPositionInfo.pos.x = temp_fv0;

        racer->segmentPositionInfo.segmentDisplacement.y *= temp_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.y + racer->segmentPositionInfo.segmentPos.y;
        racer->segmentPositionInfo.lastGroundedPos.y = temp_fv0;
        racer->segmentPositionInfo.pos.y = temp_fv0;

        racer->segmentPositionInfo.segmentDisplacement.z *= temp_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.z + racer->segmentPositionInfo.segmentPos.z;
        racer->segmentPositionInfo.lastGroundedPos.z = temp_fv0;
        racer->segmentPositionInfo.pos.z = temp_fv0;

        racer->heightAboveGround = 0.0f;

        var_fa1 = (racer->upFromGround.x * racer->velocity.x) + (racer->upFromGround.y * racer->velocity.y) +
                  (racer->upFromGround.z * racer->velocity.z);
        if (var_fa1 < 0.0f) {
            racer->velocity.x -= (var_fa1 * racer->upFromGround.x);
            racer->velocity.y -= (var_fa1 * racer->upFromGround.y);
            racer->velocity.z -= (var_fa1 * racer->upFromGround.z);

            if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                Audio_Chakuchi(racer->id, var_fa1);
            }
        }
    }

    if (racer->heightAboveGround <= 15.0f) {
        racer->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
    } else {
        racer->stateFlags |= RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
    }
}

void func_8008FC80(Racer* racer) {
    f32 halfPipeRadius;
    f32 var_fs0;
    f32 temp_fv1;
    f32 joinProportion;
    f32 x;
    f32 y;
    f32 z;
    f32 temp_fv0;

    if (racer->segmentPositionInfo.segmentTValue < racer->segmentPositionInfo.courseSegment->previousJoinEndTValue) {
        halfPipeRadius = joinProportion =
            racer->segmentPositionInfo.segmentLengthProportion / racer->segmentPositionInfo.courseSegment->joinScale;
        halfPipeRadius *= racer->currentRadiusLeft;
        var_fs0 = racer->currentRadiusLeft;
    } else if (racer->segmentPositionInfo.courseSegment->nextJoinStartTValue <
               racer->segmentPositionInfo.segmentTValue) {
        halfPipeRadius = joinProportion = (1.0f - racer->segmentPositionInfo.segmentLengthProportion) /
                                          racer->segmentPositionInfo.courseSegment->joinScale;
        halfPipeRadius *= racer->currentRadiusLeft;
        var_fs0 = -racer->currentRadiusLeft;
    } else {
        halfPipeRadius = racer->currentRadiusLeft;
        var_fs0 = 0.0f;
    }

    racer->heightAboveGround = racer->currentRadiusLeft - racer->segmentPositionInfo.distanceFromSegment;
    if (racer->segmentPositionInfo.distanceFromSegment > 0.01f) {
        temp_fv1 = -1.0f / racer->segmentPositionInfo.distanceFromSegment;
        racer->upFromGround.x = racer->segmentPositionInfo.segmentDisplacement.x * temp_fv1;
        racer->upFromGround.y = racer->segmentPositionInfo.segmentDisplacement.y * temp_fv1;
        racer->upFromGround.z = racer->segmentPositionInfo.segmentDisplacement.z * temp_fv1;
    }

    temp_fv1 = (((racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                 (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                 (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z)) -
                23.0f) +
               (halfPipeRadius * 0.3826834f);
    if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((temp_fv1 >= 0.0f) || (racer->currentRadiusLeft < racer->segmentPositionInfo.distanceFromSegment)) {
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
        racer->stateFlags &= ~RACER_STATE_FLAGS_80000000;

    } else if (temp_fv1 >= 0.0f) {
        racer->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
        func_8008E418(racer);
        func_8008E504(racer);
        racer->shadowPos.y = -54321.0f;
        return;
    }

    if (var_fs0 != 0.0f) {
        temp_fv1 = halfPipeRadius + (racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                   (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                   (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z);
        if (temp_fv1 < racer->heightAboveGround) {
            racer->heightAboveGround = temp_fv1;
            racer->upFromGround.x = racer->segmentBasis.y.x;
            racer->upFromGround.y = racer->segmentBasis.y.y;
            racer->upFromGround.z = racer->segmentBasis.y.z;
            racer->tiltUp.x =
                (gTrackJoinUpperLength[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * racer->upFromGround.x) +
                (var_fs0 * racer->segmentBasis.x.x);
            racer->tiltUp.y =
                (gTrackJoinUpperLength[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * racer->upFromGround.y) +
                (var_fs0 * racer->segmentBasis.x.y);
            racer->tiltUp.z =
                (gTrackJoinUpperLength[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * racer->upFromGround.z) +
                (var_fs0 * racer->segmentBasis.x.z);

            temp_fv1 = 1.0f / sqrtf(SQ(racer->tiltUp.x) + SQ(racer->tiltUp.y) + SQ(racer->tiltUp.z));

            racer->tiltUp.x *= temp_fv1;
            racer->tiltUp.y *= temp_fv1;
            racer->tiltUp.z *= temp_fv1;

            if (racer->heightAboveGround < 0.0f) {
                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.x;
                racer->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
                racer->segmentPositionInfo.pos.x -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.y;
                racer->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
                racer->segmentPositionInfo.pos.y -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

                temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.z;
                racer->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
                racer->segmentPositionInfo.pos.z -= temp_fv0;
                racer->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

                racer->segmentPositionInfo.distanceFromSegment =
                    sqrtf(SQ(racer->segmentPositionInfo.segmentDisplacement.x) +
                          SQ(racer->segmentPositionInfo.segmentDisplacement.y) +
                          SQ(racer->segmentPositionInfo.segmentDisplacement.z));
                racer->heightAboveGround = 0.0f;

                var_fs0 = (racer->segmentBasis.y.x * racer->velocity.x) +
                          (racer->segmentBasis.y.y * racer->velocity.y) + (racer->segmentBasis.y.z * racer->velocity.z);
                if (var_fs0 < 0.0f) {
                    racer->velocity.x -= var_fs0 * racer->segmentBasis.y.x;
                    racer->velocity.y -= var_fs0 * racer->segmentBasis.y.y;
                    racer->velocity.z -= var_fs0 * racer->segmentBasis.y.z;
                    if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                        Audio_Chakuchi(racer->id, var_fs0);
                    }
                }
            }
        } else {
            racer->tiltUp = racer->upFromGround;
        }

        x = ((racer->tiltUp.x - racer->segmentBasis.y.x) * joinProportion) + racer->segmentBasis.y.x;
        y = ((racer->tiltUp.y - racer->segmentBasis.y.y) * joinProportion) + racer->segmentBasis.y.y;
        z = ((racer->tiltUp.z - racer->segmentBasis.y.z) * joinProportion) + racer->segmentBasis.y.z;

        temp_fv1 = sqrtf(SQ(x) + SQ(y) + SQ(z));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            racer->tiltUp.x = temp_fv1 * x;
            racer->tiltUp.y = temp_fv1 * y;
            racer->tiltUp.z = temp_fv1 * z;
        }
    } else {
        racer->tiltUp = racer->upFromGround;
    }

    if (racer->currentRadiusLeft < racer->segmentPositionInfo.distanceFromSegment) {
        temp_fv1 = racer->currentRadiusLeft / racer->segmentPositionInfo.distanceFromSegment;
        racer->segmentPositionInfo.distanceFromSegment = racer->currentRadiusLeft;

        racer->segmentPositionInfo.segmentDisplacement.x *= temp_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.x + racer->segmentPositionInfo.segmentPos.x;
        racer->segmentPositionInfo.lastGroundedPos.x = temp_fv0;
        racer->segmentPositionInfo.pos.x = temp_fv0;
        racer->segmentPositionInfo.segmentDisplacement.y *= temp_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.y + racer->segmentPositionInfo.segmentPos.y;
        racer->segmentPositionInfo.lastGroundedPos.y = temp_fv0;
        racer->segmentPositionInfo.pos.y = temp_fv0;
        racer->segmentPositionInfo.segmentDisplacement.z *= temp_fv1;
        temp_fv0 = racer->segmentPositionInfo.segmentDisplacement.z + racer->segmentPositionInfo.segmentPos.z;
        racer->segmentPositionInfo.lastGroundedPos.z = temp_fv0;
        racer->segmentPositionInfo.pos.z = temp_fv0;

        racer->heightAboveGround = 0.0f;

        var_fs0 = (racer->upFromGround.x * racer->velocity.x) + (racer->upFromGround.y * racer->velocity.y) +
                  (racer->upFromGround.z * racer->velocity.z);
        if (var_fs0 < 0.0f) {
            racer->velocity.x -= var_fs0 * racer->upFromGround.x;
            racer->velocity.y -= var_fs0 * racer->upFromGround.y;
            racer->velocity.z -= var_fs0 * racer->upFromGround.z;
            if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                Audio_Chakuchi(racer->id, var_fs0);
            }
        }
    }

    racer->gravityUp.x = racer->segmentBasis.y.x;
    racer->gravityUp.y = racer->segmentBasis.y.y;
    racer->gravityUp.z = racer->segmentBasis.y.z;
    racer->shadowPos.x = racer->segmentPositionInfo.pos.x - (racer->heightAboveGround * racer->upFromGround.x);
    racer->shadowPos.y = racer->segmentPositionInfo.pos.y - (racer->heightAboveGround * racer->upFromGround.y);
    racer->shadowPos.z = racer->segmentPositionInfo.pos.z - (racer->heightAboveGround * racer->upFromGround.z);

    if (racer->heightAboveGround <= 15.0f) {
        racer->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
    } else {
        racer->stateFlags |= RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
    }
}

void func_80090490(Racer* racer) {

    racer->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
    if (racer->id < gNumPlayers) {
        if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
            racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
            if (gEnableRaceSfx) {
                Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
            }
        }
    }

    racer->shadowPos.y = -54321.0f;

    racer->heightAboveGround = (racer->segmentPositionInfo.segmentDisplacement.x * racer->segmentBasis.y.x) +
                               (racer->segmentPositionInfo.segmentDisplacement.y * racer->segmentBasis.y.y) +
                               (racer->segmentPositionInfo.segmentDisplacement.z * racer->segmentBasis.y.z);

    racer->upFromGround.x = racer->segmentBasis.y.x;
    racer->upFromGround.y = racer->segmentBasis.y.y;
    racer->upFromGround.z = racer->segmentBasis.y.z;
    func_8008E418(racer);
    func_8008E504(racer);
}

void func_80090568(Racer* racer) {
    f32 temp_fv1;
    f32 sp48;
    f32 temp_fv0;

    sp48 = (racer->segmentBasis.z.x * racer->segmentPositionInfo.segmentDisplacement.x) +
           (racer->segmentBasis.z.y * racer->segmentPositionInfo.segmentDisplacement.y) +
           (racer->segmentBasis.z.z * racer->segmentPositionInfo.segmentDisplacement.z);

    racer->heightAboveGround = (racer->segmentBasis.y.x * racer->segmentPositionInfo.segmentDisplacement.x) +
                               (racer->segmentBasis.y.y * racer->segmentPositionInfo.segmentDisplacement.y) +
                               (racer->segmentBasis.y.z * racer->segmentPositionInfo.segmentDisplacement.z);

    racer->upFromGround.x = racer->segmentBasis.y.x;
    racer->upFromGround.y = racer->segmentBasis.y.y;
    racer->upFromGround.z = racer->segmentBasis.y.z;

    if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((racer->heightAboveGround < -100.0f) || (racer->heightAboveGround > 30.0f) ||
            (sp48 < -racer->currentRadiusRight) || (racer->currentRadiusLeft < sp48)) {
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
        racer->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else {
        if ((racer->heightAboveGround > 30.0f) || (sp48 < -racer->currentRadiusRight) ||
            (racer->currentRadiusLeft < sp48)) {
            racer->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (racer->id < gNumPlayers) {
                if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                    racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                    }
                }
            }
            func_8008E418(racer);
            func_8008E504(racer);
            racer->shadowPos.y = -54321.0f;
            return;
        }
    }

    if (racer->heightAboveGround < 0.0f) {

        temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.x;
        racer->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
        racer->segmentPositionInfo.pos.x -= temp_fv0;
        racer->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

        temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.y;
        racer->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
        racer->segmentPositionInfo.pos.y -= temp_fv0;
        racer->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

        temp_fv0 = racer->heightAboveGround * racer->segmentBasis.y.z;
        racer->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
        racer->segmentPositionInfo.pos.z -= temp_fv0;
        racer->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

        racer->heightAboveGround = 0.0f;
        sp48 = (racer->segmentBasis.y.x * racer->velocity.x) + (racer->segmentBasis.y.y * racer->velocity.y) +
               (racer->segmentBasis.y.z * racer->velocity.z);

        if (sp48 < 0.0f) {
            racer->velocity.x -= sp48 * racer->segmentBasis.y.x;
            racer->velocity.y -= sp48 * racer->segmentBasis.y.y;
            racer->velocity.z -= sp48 * racer->segmentBasis.y.z;
            if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                Audio_Chakuchi(racer->id, sp48);
            }
        }
    }

    if (racer->heightAboveGround <= 15.0f) {
        racer->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
        racer->gravityUp.x = racer->tiltUp.x = racer->segmentBasis.y.x;
        racer->gravityUp.y = racer->tiltUp.y = racer->segmentBasis.y.y;
        racer->gravityUp.z = racer->tiltUp.z = racer->segmentBasis.y.z;
    } else {
        racer->stateFlags |= RACER_STATE_AIRBORNE;
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_AIRBORNE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_AIRBORNE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_8);
                }
            }
        }
        func_8008E418(racer);
        func_8008E504(racer);

        if (racer->heightAboveGround < 30.0f) {
            temp_fv1 = (racer->heightAboveGround - 15.0f) / 15.0f;

            racer->gravityUp.x = ((racer->gravityUp.x - racer->segmentBasis.y.x) * temp_fv1) + racer->segmentBasis.y.x;
            racer->gravityUp.y = ((racer->gravityUp.y - racer->segmentBasis.y.y) * temp_fv1) + racer->segmentBasis.y.y;
            racer->gravityUp.z = ((racer->gravityUp.z - racer->segmentBasis.y.z) * temp_fv1) + racer->segmentBasis.y.z;

            racer->tiltUp.x = ((racer->tiltUp.x - racer->segmentBasis.y.x) * temp_fv1) + racer->tiltUp.x;
            racer->tiltUp.y = ((racer->tiltUp.y - racer->segmentBasis.y.y) * temp_fv1) + racer->tiltUp.y;
            racer->tiltUp.z = ((racer->tiltUp.z - racer->segmentBasis.y.z) * temp_fv1) + racer->tiltUp.z;

            temp_fv1 = 1.0f / sqrtf(SQ(racer->tiltUp.x) + SQ(racer->tiltUp.y) + SQ(racer->tiltUp.z));
            racer->tiltUp.x *= temp_fv1;
            racer->tiltUp.y *= temp_fv1;
            racer->tiltUp.z *= temp_fv1;
        }
    }
    racer->shadowPos.x = racer->segmentPositionInfo.pos.x - (racer->heightAboveGround * racer->segmentBasis.y.x);
    racer->shadowPos.y = racer->segmentPositionInfo.pos.y - (racer->heightAboveGround * racer->segmentBasis.y.y);
    racer->shadowPos.z = racer->segmentPositionInfo.pos.z - (racer->heightAboveGround * racer->segmentBasis.y.z);
}

void func_80090AFC(Racer* racer) {

    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
        func_8008DBB8(racer, 120);
    }
    racer->stateFlags = (racer->stateFlags & ~RACER_STATE_FLAGS_400000) | RACER_STATE_FALLING_OFF_TRACK;

    if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
        if (sCharacterVoices[racer->character] != VOICE_FEMALE) {
            Audio_PlayerTriggerSEStart(racer->id, NA_SE_52);
        } else {
            Audio_PlayerTriggerSEStart(racer->id, NA_SE_53);
        }
        Racer_StopRacerSfx(racer);
    }
}

extern u32 gGameFrameCount;

void Racer_UpdateFromControls(Racer* racer, Controller* controller) {
    bool isDrifting;
    s32 i;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    f32 var_fa1;
    f32 sp12C;
    f32 sp128;
    f32 var_fv1;
    f32 var_fs1;
    f32 var_fs0;
    f32 var_ft4;
    Vec3f sp10C;
    Mtx3F spE8;
    f32 directionChange;
    s32 pad;
    Effect* effectsEnd;
    Effect* effect;
    Landmine* landmine;
    Landmine* landminesEnd;
    Jump* jump;
    Jump* jumpsEnd;
    u16 buttonReleased;
    u16 buttonCurrent;
    u16 buttonPressed;
    s32 pad2;
    s32 spinOutTimer;

    if (!(racer->stateFlags & RACER_STATE_FLAGS_400000)) {
        buttonCurrent = buttonPressed = buttonReleased = 0;
        racer->tiltUpInput = 0.0f;
        sp12C = racer->unk_238;
        racer->unk_238 *= 0.99f;
    } else {
        buttonCurrent = controller->buttonCurrent;
        buttonPressed = controller->buttonPressed;
        buttonReleased = controller->buttonReleased;
        racer->tiltUpInput = controller->stickY / 63.0f;

        if (racer->tiltUpInput < -1.0f) {
            racer->tiltUpInput = -1.0f;
        } else if (racer->tiltUpInput > 1.0f) {
            racer->tiltUpInput = 1.0f;
        }
        sp12C = controller->stickX / 63.0f;

        if (sp12C < -1.0f) {
            sp12C = -1.0f;
        } else if (sp12C > 1.0f) {
            sp12C = 1.0f;
        }
    }

    spE8 = racer->trueBasis;

    sp10C.x = racer->segmentPositionInfo.pos.x + racer->velocity.x;
    sp10C.y = racer->segmentPositionInfo.pos.y + racer->velocity.y;
    sp10C.z = racer->segmentPositionInfo.pos.z + racer->velocity.z;

    racer->stateFlags &= ~COURSE_EFFECT_MASK;
    effect = racer->segmentPositionInfo.courseSegment->effectsStart;
    if ((effect != NULL) && !(racer->stateFlags & RACER_STATE_AIRBORNE)) {
        effectsEnd = racer->segmentPositionInfo.courseSegment->effectsEnd;
        if (racer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_FLAG_8000000) {
            var_fa1 = (racer->segmentPositionInfo.segmentDisplacement.x * racer->segmentBasis.z.x) +
                      (racer->segmentPositionInfo.segmentDisplacement.y * racer->segmentBasis.z.y) +
                      (racer->segmentPositionInfo.segmentDisplacement.z * racer->segmentBasis.z.z) +
                      (0.5f * (racer->currentRadiusRight - racer->currentRadiusLeft));

            do {
                if (var_fa1 < effect->unk_0C.x) {
                    continue;
                }
                if (effect->unk_18.x < var_fa1) {
                    continue;
                }
                if (racer->segmentPositionInfo.segmentTValue < effect->segmentTValueStart) {
                    continue;
                }
                if (effect->segmentTValueEnd < racer->segmentPositionInfo.segmentTValue) {
                    continue;
                }
                racer->stateFlags |= effect->effectType;
                break;
            } while (++effect != effectsEnd);

        } else {

            do {
                if (racer->segmentPositionInfo.segmentTValue < effect->segmentTValueStart) {
                    continue;
                }

                if (effect->segmentTValueEnd < racer->segmentPositionInfo.segmentTValue) {
                    continue;
                }

                if ((((racer->segmentPositionInfo.segmentDisplacement.y * effect->unk_0C.z) -
                      (racer->segmentPositionInfo.segmentDisplacement.z * effect->unk_0C.y)) *
                     racer->segmentBasis.x.x) +
                        (((racer->segmentPositionInfo.segmentDisplacement.z * effect->unk_0C.x) -
                          (racer->segmentPositionInfo.segmentDisplacement.x * effect->unk_0C.z)) *
                         racer->segmentBasis.x.y) +
                        (((racer->segmentPositionInfo.segmentDisplacement.x * effect->unk_0C.y) -
                          (racer->segmentPositionInfo.segmentDisplacement.y * effect->unk_0C.x)) *
                         racer->segmentBasis.x.z) <
                    0.0f) {
                    continue;
                }

                if ((((effect->unk_18.y * racer->segmentPositionInfo.segmentDisplacement.z) -
                      (effect->unk_18.z * racer->segmentPositionInfo.segmentDisplacement.y)) *
                     racer->segmentBasis.x.x) +
                        (((effect->unk_18.z * racer->segmentPositionInfo.segmentDisplacement.x) -
                          (effect->unk_18.x * racer->segmentPositionInfo.segmentDisplacement.z)) *
                         racer->segmentBasis.x.y) +
                        (((effect->unk_18.x * racer->segmentPositionInfo.segmentDisplacement.y) -
                          (effect->unk_18.y * racer->segmentPositionInfo.segmentDisplacement.x)) *
                         racer->segmentBasis.x.z) <
                    0.0f) {
                    continue;
                }

                racer->stateFlags |= effect->effectType;
                break;

            } while (++effect != effectsEnd);
        }
    }
    if ((sp12C > 0.1f) || (sp12C < -0.1f)) {
        var_fs1 = racer->trueBasis.x.x;
        var_fs0 = racer->trueBasis.x.y;
        var_ft4 = racer->trueBasis.x.z;

        if (racer->spinOutTimer != 0) {
            var_fa1 = 0.2f;
        } else {
            if (buttonCurrent & (BTN_Z | BTN_R)) {
                if (racer->driftAttackForce != 0.f) {
                    var_fa1 = ((racer->unk_1E0 - racer->unk_1E4) * 0.4f) + racer->unk_1E4;
                } else {
                    var_fa1 = racer->unk_1E0;
                }
            } else if (racer->stateFlags & RACER_STATE_FLAGS_20000000) {
                if (buttonCurrent & BTN_A) {
                    var_fa1 = racer->unk_1E4;
                } else {
                    var_fa1 = ((racer->unk_1E0 - racer->unk_1E4) * 0.125f) + racer->unk_1E4;
                }
            } else {
                var_fa1 = racer->unk_1E0;
            }
        }
        var_fa1 *= sp12C;

        racer->trueBasis.x.x -= (var_fa1 * racer->trueBasis.z.x);
        racer->trueBasis.x.y -= (var_fa1 * racer->trueBasis.z.y);
        racer->trueBasis.x.z -= (var_fa1 * racer->trueBasis.z.z);

        racer->trueBasis.z.x =
            (racer->trueBasis.y.y * racer->trueBasis.x.z) - (racer->trueBasis.y.z * racer->trueBasis.x.y);
        racer->trueBasis.z.y =
            (racer->trueBasis.y.z * racer->trueBasis.x.x) - (racer->trueBasis.y.x * racer->trueBasis.x.z);
        racer->trueBasis.z.z =
            (racer->trueBasis.y.x * racer->trueBasis.x.y) - (racer->trueBasis.y.y * racer->trueBasis.x.x);

        var_fa1 = 1.0f / sqrtf(SQ(racer->trueBasis.z.x) + SQ(racer->trueBasis.z.y) + SQ(racer->trueBasis.z.z));
        racer->trueBasis.z.x *= var_fa1;
        racer->trueBasis.z.y *= var_fa1;
        racer->trueBasis.z.z *= var_fa1;

        var_fs1 -= racer->trueBasis.x.x =
            (racer->trueBasis.z.y * racer->trueBasis.y.z) - (racer->trueBasis.z.z * racer->trueBasis.y.y);
        var_fs0 -= racer->trueBasis.x.y =
            (racer->trueBasis.z.z * racer->trueBasis.y.x) - (racer->trueBasis.z.x * racer->trueBasis.y.z);
        var_ft4 -= racer->trueBasis.x.z =
            (racer->trueBasis.z.x * racer->trueBasis.y.y) - (racer->trueBasis.z.y * racer->trueBasis.y.x);
        directionChange = sqrtf(SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4));
    } else {
        directionChange = 0.0f;
    }
    if (racer->spinOutTimer != 0) {
        var_fs1 = var_ft4 = 0.997f;
    } else if (racer->stateFlags & RACER_STATE_CRASHED) {
        var_fs1 = var_ft4 = 0.98305196f;
    } else {
        var_ft4 = 0.997f;
        var_fs1 = 0.996f;
    }
    if ((racer->boostTimer == 0) &&
        ((racer->stateFlags & (RACER_STATE_AIRBORNE | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DIRT)) {
        var_fs1 *= 0.987f;
        var_ft4 *= 0.987f;
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_DIRT)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_DIRT;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_5);
                }
            }
        }
    } else {
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_DIRT) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_DIRT;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_5);
                }
            }
        }
    }

    if (buttonCurrent & BTN_CDOWN) {
        var_fs1 *= 0.987f;
        var_ft4 *= 0.987f;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            var_fs1 *= 0.9f;
            var_ft4 *= 0.9f;
        }
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_BRAKE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_BRAKE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_9);
                }
            }
        }
    } else {
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_BRAKE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_BRAKE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_9);
                }
            }
        }
    }

    var_fs1 *= ((racer->trueBasis.z.x * racer->velocity.x) + (racer->trueBasis.z.y * racer->velocity.y) +
                (racer->trueBasis.z.z * racer->velocity.z));
    var_fs0 = ((racer->trueBasis.y.x * racer->velocity.x) + (racer->trueBasis.y.y * racer->velocity.y) +
               (racer->trueBasis.y.z * racer->velocity.z)) *
              0.94f;
    var_ft4 *= ((racer->trueBasis.x.x * racer->velocity.x) + (racer->trueBasis.x.y * racer->velocity.y) +
                (racer->trueBasis.x.z * racer->velocity.z));
    racer->velocity.x =
        (racer->trueBasis.z.x * var_fs1) + (racer->trueBasis.y.x * var_fs0) + (racer->trueBasis.x.x * var_ft4);
    racer->velocity.y =
        (racer->trueBasis.z.y * var_fs1) + (racer->trueBasis.y.y * var_fs0) + (racer->trueBasis.x.y * var_ft4);
    racer->velocity.z =
        (racer->trueBasis.z.z * var_fs1) + (racer->trueBasis.y.z * var_fs0) + (racer->trueBasis.x.z * var_ft4);

    if ((buttonPressed & BTN_B) && (racer->boostTimer == 0) && (racer->energy != 0.0) &&
        (racer->stateFlags & RACER_STATE_CAN_BOOST)) {
        racer->shadowColorStrength = 1.3f;
        racer->shadowBaseR = racer->shadowBaseB = 91.0f;
        racer->shadowBaseG = 255.0f;
        racer->boostTimer = sInitialBoostTimer;
        racer->soundEffectFlags |= RACER_SE_FLAGS_BOOST;
        if (gEnableRaceSfx) {
            Audio_PlayerTriggerSEStart(racer->id, NA_SE_7);
        }
    } else {
#ifndef EXPANSION_KIT
        if ((racer->stateFlags & (RACER_STATE_CRASHED | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DASH) {
#else
        if ((racer->stateFlags & (RACER_STATE_CRASHED | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DASH &&
            racer->stateFlags & RACER_STATE_FLAGS_400000) {
#endif
            buttonCurrent |= BTN_A;
            racer->shadowColorStrength = 1.3f;
            racer->shadowBaseR = 255.0f;
            racer->shadowBaseG = 223.0f;
            racer->shadowBaseB = 0.0f;
            racer->stateFlags |= RACER_STATE_DASH_PAD_BOOST;
            racer->boostTimer = sInitialBoostTimer;
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_BOOST)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_BOOST;
                if (gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, NA_SE_7);
                }
            }
        } else {
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_BOOST;
        }
    }

    if (!(racer->stateFlags & RACER_STATE_TOUCHING_LANDMINE)) {
        landmine = racer->segmentPositionInfo.courseSegment->landminesStart;
        if (landmine != NULL) {
            landminesEnd = racer->segmentPositionInfo.courseSegment->landminesEnd;
            do {
                var_fs1 = landmine->pos.x - racer->segmentPositionInfo.pos.x;
                var_fs0 = landmine->pos.y - racer->segmentPositionInfo.pos.y;
                var_ft4 = landmine->pos.z - racer->segmentPositionInfo.pos.z;
                if ((SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4)) < 900.0f) {
                    racer->acceleration.x += (15.0f * racer->tiltUp.x);
                    racer->acceleration.y += (15.0f * racer->tiltUp.y);
                    racer->acceleration.z += (15.0f * racer->tiltUp.z);
                    racer->stateFlags |= RACER_STATE_TOUCHING_LANDMINE;
                    Racer_ReceiveDamage(racer, 12.5f);
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_HIT_LANDMINE);
                    }
                    break;
                }
            } while (++landmine != landminesEnd);
        }
    }

    if (!(racer->stateFlags & RACER_STATE_JUMP_BOOST)) {
        jump = racer->segmentPositionInfo.courseSegment->jumpsStart;
        if (jump != NULL) {
            jumpsEnd = racer->segmentPositionInfo.courseSegment->jumpsEnd;
            do {
                var_fs1 = racer->segmentPositionInfo.pos.x - jump->pos.x;
                var_fs0 = racer->segmentPositionInfo.pos.y - jump->pos.y;
                var_ft4 = racer->segmentPositionInfo.pos.z - jump->pos.z;
                var_fa1 = (jump->basis.x.x * var_fs1) + (jump->basis.x.y * var_fs0) + (jump->basis.x.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (jump->dimensions.z < var_fa1) {
                    continue;
                }

                var_fa1 = (jump->basis.z.x * var_fs1) + (jump->basis.z.y * var_fs0) + (jump->basis.z.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (jump->dimensions.x < var_fa1) {
                    continue;
                }

                var_fa1 = (jump->basis.y.x * var_fs1) + (jump->basis.y.y * var_fs0) + (jump->basis.y.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (jump->dimensions.y < var_fa1) {
                    continue;
                }

                racer->stateFlags |= RACER_STATE_JUMP_BOOST;
                racer->jumpBoost = (racer->speed * 0.3f) + 0.5f;
                if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, NA_SE_55);
                }
                break;

            } while (++jump != jumpsEnd);
        }
    }
    racer->acceleration.x += (-1.0f * racer->gravityUp.x);
    racer->acceleration.y += (-1.0f * racer->gravityUp.y);
    racer->acceleration.z += (-1.0f * racer->gravityUp.z);
    if (racer->stateFlags & RACER_STATE_JUMP_BOOST) {
        racer->acceleration.x += (racer->jumpBoost * racer->tiltUp.x);
        racer->acceleration.y += (racer->jumpBoost * racer->tiltUp.y);
        racer->acceleration.z += (racer->jumpBoost * racer->tiltUp.z);
        racer->jumpBoost *= 0.8f;
    }
    if (!(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        var_fa1 = racer->unk_17C - racer->heightAboveGround;
        if (var_fa1 > 0.0f) {
            var_fa1 -= ((racer->velocity.x * racer->upFromGround.x) + (racer->velocity.y * racer->upFromGround.y) +
                        (racer->velocity.z * racer->upFromGround.z));

            racer->unk_198 = var_fa1 * 0.2f;

            racer->acceleration.x += (racer->unk_198 * racer->upFromGround.x);
            racer->acceleration.y += (racer->unk_198 * racer->upFromGround.y);
            racer->acceleration.z += (racer->unk_198 * racer->upFromGround.z);
            if (racer->jumpBoost < 0.5f) {
                racer->stateFlags &= ~(RACER_STATE_JUMP_BOOST | RACER_STATE_TOUCHING_LANDMINE);
            }
        } else {
            racer->unk_198 = 0.0f;
        }
    } else {
        racer->unk_198 = 0.0f;
    }
    racer->zButtonTimer++;
    racer->rButtonTimer++;
    if (buttonPressed & BTN_R_Z_COMBO) {
        buttonPressed |= BTN_Z;
        buttonCurrent |= BTN_R;
        racer->zButtonTimer = 10;
    } else if (buttonPressed & BTN_Z_R_COMBO) {
        buttonPressed |= BTN_R;
        buttonCurrent |= BTN_Z;
        racer->rButtonTimer = 10;
    }

    switch (buttonPressed & (BTN_Z | BTN_R)) {
        case BTN_Z:
            if ((racer->zButtonTimer < 15) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0x80;
                racer->unk_280 = 0x100;
                if (buttonCurrent & BTN_R) {
                    racer->attackState = ATTACK_STATE_SPIN;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_2);
                    }
                } else {
                    racer->attackState = ATTACK_STATE_SIDE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_6);
                    }
                }
            }
            racer->zButtonTimer = 0;
            break;
        case BTN_R:
            if ((racer->rButtonTimer < 15) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0xF80;
                racer->unk_280 = -0x100;
                if (buttonCurrent & BTN_Z) {
                    racer->attackState = ATTACK_STATE_SPIN;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_2);
                    }
                } else {
                    racer->attackState = ATTACK_STATE_SIDE;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_6);
                    }
                }
            }
            racer->rButtonTimer = 0;
            break;
        default:
            break;
    }

    isDrifting = false;
    if (racer->attackState == ATTACK_STATE_SIDE) {
        if (racer->unk_280 < 0) {
            racer->driftAttackDirection = DRIFT_ATTACK_RIGHT;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->driftAttackDirection = DRIFT_ATTACK_LEFT;
        }
        if (var_fa1 < 0.0f) {
            racer->driftAttackForce = 5.0f;
        } else if (var_fa1 < 6.0f) {
            racer->driftAttackForce = 5.0f - (0.8333333f * var_fa1);
        } else {
            racer->driftAttackForce = 0.0f;
        }

        var_fs1 = racer->driftAttackForce * racer->trueBasis.z.x;
        var_fs0 = racer->driftAttackForce * racer->trueBasis.z.y;
        var_ft4 = racer->driftAttackForce * racer->trueBasis.z.z;
        var_fa1 = (racer->gravityUp.x * var_fs1) + (var_fs0 * racer->gravityUp.y) + (var_ft4 * racer->gravityUp.z);
        if (racer->driftAttackDirection == DRIFT_ATTACK_RIGHT) {
            racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->gravityUp.x));
            racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->gravityUp.y));
            racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->gravityUp.z));
        } else { // DRIFT_ATTACK_LEFT
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->gravityUp.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->gravityUp.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->gravityUp.z));
        }
    } else if (racer->attackState == ATTACK_STATE_SPIN) {
        if (racer->unk_280 < 0) {
            racer->driftAttackDirection = DRIFT_ATTACK_RIGHT;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->driftAttackDirection = DRIFT_ATTACK_LEFT;
        }
        if (var_fa1 < 0.0f) {
            racer->driftAttackForce = 0.5f;
        } else if (var_fa1 < 2.0f) {
            racer->driftAttackForce = 0.5f - (0.25f * var_fa1);
        } else {
            racer->driftAttackForce = 0.0f;
        }

        var_fs1 = racer->driftAttackForce * racer->trueBasis.z.x;
        var_fs0 = racer->driftAttackForce * racer->trueBasis.z.y;
        var_ft4 = racer->driftAttackForce * racer->trueBasis.z.z;
        if (racer->driftAttackDirection == DRIFT_ATTACK_RIGHT) {
            racer->acceleration.x -= var_fs1;
            racer->acceleration.y -= var_fs0;
            racer->acceleration.z -= var_ft4;
        } else { // DRIFT_ATTACK_LEFT
            racer->acceleration.x += var_fs1;
            racer->acceleration.y += var_fs0;
            racer->acceleration.z += var_ft4;
        }
    } else {
        switch (buttonCurrent & (BTN_Z | BTN_R)) {
            case 0:
            case (BTN_Z | BTN_R):
                racer->driftAttackForce = 0.0f;
                break;
            default:
                if ((buttonCurrent & (BTN_Z | BTN_R)) == BTN_Z) {
                    var_fa1 = racer->unk_5C.x;
                    racer->driftAttackDirection = DRIFT_ATTACK_LEFT;
                } else {
                    racer->driftAttackDirection = DRIFT_ATTACK_RIGHT;
                    var_fa1 = -racer->unk_5C.x;
                }
                if (var_fa1 < 0.0f) {
                    racer->driftAttackForce = 1.0f;
                } else if (var_fa1 < 8.0f) {
                    racer->driftAttackForce = 1.0f - (0.125f * var_fa1);
                } else {
                    racer->driftAttackForce = 0.0f;
                }
                if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
                    racer->driftAttackForce *= 0.2f;
                }

                var_fs1 = racer->driftAttackForce * racer->trueBasis.z.x;
                var_fs0 = racer->driftAttackForce * racer->trueBasis.z.y;
                var_ft4 = racer->driftAttackForce * racer->trueBasis.z.z;
                var_fa1 =
                    (racer->gravityUp.x * var_fs1) + (var_fs0 * racer->gravityUp.y) + (var_ft4 * racer->gravityUp.z);
                if (racer->driftAttackDirection == DRIFT_ATTACK_RIGHT) {
                    racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->gravityUp.x));
                    racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->gravityUp.y));
                    racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->gravityUp.z));
                } else { // DRIFT_ATTACK_LEFT
                    racer->acceleration.x += (var_fs1 - (var_fa1 * racer->gravityUp.x));
                    racer->acceleration.y += (var_fs0 - (var_fa1 * racer->gravityUp.y));
                    racer->acceleration.z += (var_ft4 - (var_fa1 * racer->gravityUp.z));
                }

                isDrifting = true;
                break;
        }
    }
    if (racer->id < gNumPlayers) {
        if (isDrifting) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_DRIFT_SLIDE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_DRIFT_SLIDE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_10);
                }
            }
        } else {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_DRIFT_SLIDE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_DRIFT_SLIDE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_10);
                }
            }
        }
    }

    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT)) &&
        ((racer->stateFlags & COURSE_EFFECT_MASK) != COURSE_EFFECT_ICE)) {
        sp128 = (racer->trueBasis.z.x * racer->velocity.x) + (racer->trueBasis.z.y * racer->velocity.y) +
                (racer->trueBasis.z.z * racer->velocity.z);

        if (sp128 < 0.0f) {
            var_fa1 = -1.0f;
            sp128 = -sp128;
        } else {
            var_fa1 = 1.0f;
        }
        if (buttonPressed & BTN_A) {
            racer->unk_204 = 30;
            racer->unk_214 = 27;
            if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(racer->id, NA_SE_41);
            }
        } else {
            if (racer->unk_214 != 0) {
                racer->unk_214--;
            }
        }
        if ((racer->stateFlags & (RACER_STATE_AIRBORNE | RACER_STATE_RECEIVED_DAMAGE)) || (racer->unk_208 != 0) ||
            (buttonCurrent & (BTN_Z | BTN_R))) {

            if (racer->unk_208 != 0) {
                racer->unk_208--;
            }

            if (racer->unk_204 != 0) {
                racer->unk_204--;
            }
            racer->stateFlags &= ~RACER_STATE_FLAGS_20000000;

            if (racer->unk_1FC < sp128) {
                sp128 = racer->unk_1FC;
            }
        } else {
            if ((racer->unk_204 != 0) || !(buttonCurrent & BTN_A)) {
                if (racer->unk_204 != 0) {
                    racer->unk_204--;
                }
                racer->stateFlags |= RACER_STATE_FLAGS_20000000;

                if (racer->unk_1F8 < sp128) {
                    sp128 = racer->unk_1F8;
                }
            } else if (racer->stateFlags & RACER_STATE_FLAGS_20000000) {
                if (racer->unk_1F8 < sp128) {
                    racer->stateFlags &= ~RACER_STATE_FLAGS_20000000;
                    sp128 = racer->unk_1FC;
                }
            } else {
                if (racer->unk_1FC < sp128) {
                    sp128 = racer->unk_1FC;
                } else {
                    racer->stateFlags |= RACER_STATE_FLAGS_20000000;
                }
            }
        }

        sp128 *= var_fa1;
        racer->velocity.x -= sp128 * racer->trueBasis.z.x;
        racer->velocity.y -= sp128 * racer->trueBasis.z.y;
        racer->velocity.z -= sp128 * racer->trueBasis.z.z;
        if (((racer->unk_5C.x < -8.0f) || (racer->unk_5C.x > 8.0f)) && !(racer->stateFlags & RACER_STATE_AIRBORNE)) {

            racer->unk_20C++;
            var_fa1 = racer->unk_20C / 100.0f;
            if (var_fa1 >= 1.0f) {
                racer->unk_200 = racer->unk_1C8;
            } else if (racer->unk_200 < var_fa1) {
                racer->unk_200 = racer->unk_1C8 * var_fa1;
            }
            if (racer->id < gNumPlayers) {
                if (!(racer->soundEffectFlags & RACER_SE_FLAGS_200)) {
                    racer->soundEffectFlags |= RACER_SE_FLAGS_200;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_6);
                    }
                }
            }
        } else {
            racer->unk_20C = 0;
            if (racer->id < gNumPlayers) {
                if (racer->soundEffectFlags & RACER_SE_FLAGS_200) {
                    racer->soundEffectFlags &= ~RACER_SE_FLAGS_200;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_6);
                    }
                }
            }
        }
    } else {
        racer->unk_20C = 0;
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_200) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_200;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_6);
                }
            }
        }
    }

    if (racer->unk_200 != 0.0f) {
        var_fs1 = racer->unk_1B4;
        var_fs0 = racer->unk_1B8;
        var_ft4 = (racer->unk_31C * racer->unk_200) + 1.0f;
        racer->unk_200 -= racer->unk_1CC;
        if (racer->unk_200 < 0.0f) {
            racer->unk_200 = 0.0f;
        }
    } else {
        var_fs1 = racer->unk_1B0;
        var_fs0 = racer->unk_1B8;
        var_ft4 = 1.0f;
    }
    if ((gNumPlayers >= 2) && (gSettingVsHandicap == 2)) {
        var_fv1 = (gRacersByPosition[0]->raceDistance - racer->raceDistance);
        var_fv1 /= D_800CE4D8;
        if (var_fv1 >= 1.0f) {
            var_fs1 += 0.03f;
            var_fs0 += 0.03f;
        } else {
            var_fs1 += 0.03f * var_fv1;
            var_fs0 += 0.03f * var_fv1;
        }
    }
    if (racer->boostTimer != 0) {
        if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
            if (var_ft4 < racer->unk_1C4) {
                var_ft4 = racer->unk_1C4;
            }
        } else {
            if (var_ft4 < racer->unk_1C0) {
                var_ft4 = racer->unk_1C0;
            }
#ifdef EXPANSION_KIT
            if (gGameMode != GAMEMODE_COURSE_EDIT) {
#endif
                if ((gNumPlayers == 1) || (gSettingVsHandicap == 0)) {
                    sp128 = racer->boostEnergyUsage;
                } else {
                    sp128 = (gRacersByPosition[0]->raceDistance - racer->raceDistance);
                    sp128 /= D_800CE4D8;
                    if (sp128 >= 1.0f) {
                        sp128 = racer->boostEnergyUsage * 0.1f;
                    } else {
                        sp128 = (((1.0f - sp128) * 0.9f) + 0.1f) * racer->boostEnergyUsage;
                    }
                }
                racer->energy -= sp128;
                if (racer->energy < 0.0f) {
                    racer->boostTimer = 1;
                    racer->energy = 0.0f;
                }
#ifdef EXPANSION_KIT
            }
#endif
        }
        racer->boostTimer--;
        if (racer->boostTimer == 0) {
            racer->stateFlags &= ~RACER_STATE_DASH_PAD_BOOST;
            racer->soundEffectFlags &= ~RACER_SE_FLAGS_BOOST;
        }
    }
    var_fs1 *= var_ft4;
    var_fs0 *= var_ft4;

    if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
        if (racer->id < gNumPlayers) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_ICE)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_ICE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_11);
                }
            }
        }
        var_ft4 = racer->speed;
    } else {
        if (racer->id < gNumPlayers) {
            if (racer->soundEffectFlags & RACER_SE_FLAGS_ICE) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_ICE;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_11);
                }
            }
        }
        var_ft4 = racer->unk_5C.z;
    }
    if (((buttonCurrent | buttonReleased) & BTN_A) && (racer->speed < racer->unk_1EC)) {
        if (var_ft4 <= 0.0f) {
            var_ft4 = 0.0f;
            var_fv1 = var_fs1;
        } else {
            var_fv1 = racer->unk_1BC;
            if (var_ft4 < var_fv1) {
                var_fa1 = var_ft4 / var_fv1;

                // FAKE
                if (1) {}
                sp128 = 1.0f - SQ((2.0f * var_fa1) - 1.0f);
                if (var_fs1 < var_fs0) {
                    sp128 *= (var_fs0 - var_fs1) * racer->unk_320;
                } else {
                    sp128 *= (var_fs1 - var_fs0) * racer->unk_320;
                }
                var_fv1 = ((var_fs0 - var_fs1) * var_fa1) + var_fs1 + sp128;
            } else {
                if (racer->unk_1E8 == 0.0f) {
                    var_fv1 = var_fs0;
                } else {
                    var_fv1 = ((D_800CF174[BOOST_E] - var_fs0) * racer->unk_1E8) + var_fs0;
                }
            }
        }
        var_fv1 -= ((directionChange * 0.5f) + (racer->driftAttackForce * 0.16f));
        if (var_fv1 < 0.0f) {
            racer->accelerationForce = 0.0f;
        } else {
            if (var_fv1 <= racer->accelerationForce) {
                racer->accelerationForce = var_fv1;
            } else {
                var_ft4 *= racer->unk_324;
                // FAKE
                if (1) {}
                if (1) {}
                if (1) {}
                if (1) {}
                if (var_ft4 < 1.0f) {
                    var_ft4 = (racer->unk_328 * var_ft4) + racer->unk_1D0;
                } else {
                    var_ft4 = 1.0f;
                }
                racer->accelerationForce += ((var_fv1 - racer->accelerationForce) * var_ft4);
            }

            var_fs1 = racer->accelerationForce * racer->trueBasis.x.x;
            var_fs0 = racer->accelerationForce * racer->trueBasis.x.y;
            var_ft4 = racer->accelerationForce * racer->trueBasis.x.z;
            var_fa1 = (racer->gravityUp.x * var_fs1) + (var_fs0 * racer->gravityUp.y) + (var_ft4 * racer->gravityUp.z);
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->gravityUp.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->gravityUp.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->gravityUp.z));
        }
    } else {
        racer->accelerationForce = 0.0f;
    }
    racer->velocity.x += racer->acceleration.x;
    racer->velocity.y += racer->acceleration.y;
    racer->velocity.z += racer->acceleration.z;
    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));
    if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        racer->velocity.x *= 0.94f;
        racer->velocity.z *= 0.94f;
        racer->segmentPositionInfo.pos.x += racer->velocity.x;
        racer->segmentPositionInfo.pos.y += racer->velocity.y;
        racer->segmentPositionInfo.pos.z += racer->velocity.z;
        racer->segmentPositionInfo.segmentDisplacement.x += racer->velocity.x;
        racer->segmentPositionInfo.segmentDisplacement.y += racer->velocity.y;
        racer->segmentPositionInfo.segmentDisplacement.z += racer->velocity.z;
        racer->segmentPositionInfo.distanceFromSegment = sqrtf(SQ(racer->segmentPositionInfo.segmentDisplacement.x) +
                                                               SQ(racer->segmentPositionInfo.segmentDisplacement.y) +
                                                               SQ(racer->segmentPositionInfo.segmentDisplacement.z));
        D_800CF4B8[TRACK_SHAPE_INDEX(TRACK_SHAPE_AIR)](racer);
        if (racer->segmentPositionInfo.pos.y < -2750.0f) {
            racer->stateFlags &= ~RACER_STATE_ACTIVE;
#ifdef EXPANSION_KIT
            if (gGameMode != GAMEMODE_COURSE_EDIT) {
#endif
                racer->stateFlags |= RACER_STATE_CRASHED;
#ifdef EXPANSION_KIT
            }
#endif
            D_800E5FC0++;
            Racer_RetireRacer(racer);

            if (racer->id < gNumPlayers) {
                Racer_StopRacerSfx(racer);
            }
            if ((racer->id < gNumPlayers) || (gRacers[0].stateFlags & RACER_STATE_FALLING_OFF_TRACK)) {
                Effects_SpawnExplosion1(racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                                        racer->segmentPositionInfo.pos.z, 0.0f, 0.0f, 0.0f, 600.0f, racer);
                if (gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, NA_SE_8);
                    if ((racer->id == 0) && (gNumPlayers == 1)) {
                        Audio_LevelSEFadeout();
                    }
                }
                racer->trueBasis.x.y = 0.0f;
                racer->trueBasis.y.x = 0.0f;
                racer->trueBasis.z.z = 0.0f;
                racer->trueBasis.x.x = 0.0f;
                racer->trueBasis.y.z = 0.0f;
                racer->trueBasis.z.y = 0.0f;
                racer->trueBasis.x.z = 1.0f;
                racer->trueBasis.y.y = 1.0f;
                racer->trueBasis.z.x = 1.0f;
                Effects_SpawnFallExplosion(14.0f, racer);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 10000;
                controller->unk_8C = 500;
                controller->unk_90 = 5;
            }
        }
    } else {
        if (racer->speed > 138.9f) {
            var_fa1 = 138.9f / racer->speed;
            racer->speed = 138.9f;
            racer->velocity.x *= var_fa1;
            racer->velocity.y *= var_fa1;
            racer->velocity.z *= var_fa1;
        }
        if (racer->id < gNumPlayers) {
            var_fa1 = 1;
            i = 100;
        } else {
            var_fa1 = 5;
            i = 3;
        }

        if (func_8009EBEC(&racer->segmentPositionInfo, racer->segmentPositionInfo.pos.x + racer->velocity.x,
                          racer->segmentPositionInfo.pos.y + racer->velocity.y,
                          racer->segmentPositionInfo.pos.z + racer->velocity.z, i, var_fa1) == 0) {
            sp128 = racer->lapDistance;
            racer->lapDistance = func_8009DFA0(&racer->segmentPositionInfo);

            racer->currentRadiusLeft = (racer->segmentPositionInfo.segmentLengthProportion *
                                        (racer->segmentPositionInfo.courseSegment->next->radiusLeft -
                                         racer->segmentPositionInfo.courseSegment->radiusLeft)) +
                                       racer->segmentPositionInfo.courseSegment->radiusLeft;
            racer->currentRadiusRight = (racer->segmentPositionInfo.segmentLengthProportion *
                                         (racer->segmentPositionInfo.courseSegment->next->radiusRight -
                                          racer->segmentPositionInfo.courseSegment->radiusRight)) +
                                        racer->segmentPositionInfo.courseSegment->radiusRight;

            var_fa1 = 1.0f / racer->segmentPositionInfo.segmentForwardMagnitude;
            racer->segmentBasis.x.x = racer->segmentPositionInfo.segmentForward.x * var_fa1;
            racer->segmentBasis.x.y = racer->segmentPositionInfo.segmentForward.y * var_fa1;
            racer->segmentBasis.x.z = racer->segmentPositionInfo.segmentForward.z * var_fa1;

            racer->segmentBasis.y.x = (racer->segmentPositionInfo.segmentLengthProportion *
                                       (racer->segmentPositionInfo.courseSegment->next->up.x -
                                        racer->segmentPositionInfo.courseSegment->up.x)) +
                                      racer->segmentPositionInfo.courseSegment->up.x;
            racer->segmentBasis.y.y = (racer->segmentPositionInfo.segmentLengthProportion *
                                       (racer->segmentPositionInfo.courseSegment->next->up.y -
                                        racer->segmentPositionInfo.courseSegment->up.y)) +
                                      racer->segmentPositionInfo.courseSegment->up.y;
            racer->segmentBasis.y.z = (racer->segmentPositionInfo.segmentLengthProportion *
                                       (racer->segmentPositionInfo.courseSegment->next->up.z -
                                        racer->segmentPositionInfo.courseSegment->up.z)) +
                                      racer->segmentPositionInfo.courseSegment->up.z;

#ifdef EXPANSION_KIT
            if ((racer->segmentBasis.y.x == 0.0f) && (racer->segmentBasis.y.y == 0.0f) &&
                (racer->segmentBasis.y.z == 0.0f)) {
                func_i2_800B0FAC(racer->segmentPositionInfo.courseSegment, &racer->segmentBasis);
            } else {
#endif
                racer->segmentBasis.z.x = (racer->segmentBasis.y.y * racer->segmentBasis.x.z) -
                                          (racer->segmentBasis.y.z * racer->segmentBasis.x.y);
                racer->segmentBasis.z.y = (racer->segmentBasis.y.z * racer->segmentBasis.x.x) -
                                          (racer->segmentBasis.y.x * racer->segmentBasis.x.z);
                racer->segmentBasis.z.z = (racer->segmentBasis.y.x * racer->segmentBasis.x.y) -
                                          (racer->segmentBasis.y.y * racer->segmentBasis.x.x);
#ifdef EXPANSION_KIT
                if ((racer->segmentBasis.z.x == 0.0f) && (racer->segmentBasis.z.y == 0.0f) &&
                    (racer->segmentBasis.z.z == 0.0f)) {
                    func_i2_800B0FAC(racer->segmentPositionInfo.courseSegment, &racer->segmentBasis);
                } else {
#endif

                    var_fa1 = 1.0f / sqrtf(SQ(racer->segmentBasis.z.x) + SQ(racer->segmentBasis.z.y) +
                                           SQ(racer->segmentBasis.z.z));

                    racer->segmentBasis.z.x *= var_fa1;
                    racer->segmentBasis.z.y *= var_fa1;
                    racer->segmentBasis.z.z *= var_fa1;

                    racer->segmentBasis.y.x = (racer->segmentBasis.x.y * racer->segmentBasis.z.z) -
                                              (racer->segmentBasis.x.z * racer->segmentBasis.z.y);
                    racer->segmentBasis.y.y = (racer->segmentBasis.x.z * racer->segmentBasis.z.x) -
                                              (racer->segmentBasis.x.x * racer->segmentBasis.z.z);
                    racer->segmentBasis.y.z = (racer->segmentBasis.x.x * racer->segmentBasis.z.y) -
                                              (racer->segmentBasis.x.y * racer->segmentBasis.z.x);
#ifdef EXPANSION_KIT
                }
            }
#endif
            if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED | RACER_STATE_FALLING_OFF_TRACK)) &&
                (gRaceIntroTimer < 40) && (gGameMode != GAMEMODE_RECORDS)) {

                sp128 -= racer->lapDistance;
                racer->unk_288++;
                racer->unk_2A4++;
#if OS_TV_TYPE == OS_TV_TYPE_NTSC
                racer->raceTime = (s32) (racer->unk_2A4 * 50) / 3;
#else
                racer->raceTime = racer->unk_2A4 * 20;
#endif
                if (sCourseHalfLength < sp128) {
                    racer->lapsCompletedDistance += gCurrentCourseInfo->length;
                    racer->lap++;
                    if ((racer->lap == racer->lapsCompleted + 1) && (racer->lap <= (gTotalLapCount + 1))) {
                        racer->lapsCompleted = racer->lap;
                        racer->stateFlags |= RACER_STATE_CAN_BOOST;
#if OS_TV_TYPE == OS_TV_TYPE_NTSC
                        i = racer->raceTime -
                            (s32) ((50.0f * racer->lapDistance) / (3.0f * (gCurrentCourseInfo->length - sp128)));
#else
                        i = racer->raceTime -
                            (s32) ((20.0f * racer->lapDistance) / (gCurrentCourseInfo->length - sp128));
#endif
                        racer->lapTimes[racer->lap - 2] = (s32) (i - racer->completedLapsTime);
                        racer->completedLapsTime = i;
                        racer->startNewPracticeLap = true;
#ifndef EXPANSION_KIT
                        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
#else
                        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE) ||
                            (gGameMode == GAMEMODE_COURSE_EDIT)) {
#endif
                            if (racer == gRacers) {
                                if (racer->lapTimes[racer->lap - 2] < gPracticeBestLap) {
                                    gPracticeBestLap = racer->lapTimes[racer->lap - 2];
                                    gStartNewBestLap = true;
                                }
                            }
                            if (racer->lap == (gTotalLapCount + 1)) {
                                racer->lap = racer->lapsCompleted = 1;
                                racer->lapsCompletedDistance = 0;
                            }
                        } else if (racer->lap == (gTotalLapCount + 1)) {
                            racer->raceTime = i;
                            racer->stateFlags |= RACER_STATE_FINISHED | RACER_STATE_CPU_CONTROLLED;
                            racer->energy = racer->maxEnergy;

                            if (racer->id < gNumPlayers) {
                                gControllers[gPlayerControlPorts[racer->id]].unk_72 = 0;
                                gPlayerRacersFinished++;
                            }
                            gRacersFinished++;
                            D_800F5DE8 = true;

                            if (racer->id < gNumPlayers) {
                                if (gEnableRaceSfx) {
                                    Audio_PlayerTriggerSEStart(racer->id, NA_SE_15);
                                    Audio_PlayerFinished(racer->id);
                                }
                                Racer_StopRacerSfx(racer);
                                if (gNumPlayers == 1) {
                                    func_8007E0CC();
                                } else if (gRacersFinished == 1) {
                                    func_8007E0CC();
                                }
                            }
                        }
                    }
                } else if (sp128 < sCourseNegativeHalfLength) {
                    racer->lap--;
                    racer->lapsCompletedDistance -= gCurrentCourseInfo->length;
                }
                racer->raceDistance = racer->raceDistancePosition = racer->lapsCompletedDistance + racer->lapDistance;
            }

            D_800CF4B8[TRACK_SHAPE_INDEX((u32) racer->segmentPositionInfo.courseSegment->trackSegmentInfo &
                                         TRACK_SHAPE_MASK)](racer);
            if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
                if ((racer->segmentPositionInfo.pos.x < -20000.0f) || (racer->segmentPositionInfo.pos.x > 20000.0f) ||
                    (racer->segmentPositionInfo.pos.z < -20000.0f) || (racer->segmentPositionInfo.pos.z > 20000.0f) ||
                    ((racer->velocity.y < 0.0f) &&
                     (racer->segmentPositionInfo.segmentDisplacement.y < -racer->currentRadiusLeft) &&
                     (((racer->segmentPositionInfo.segmentDisplacement.x * racer->velocity.x) +
                       (racer->segmentPositionInfo.segmentDisplacement.y * racer->velocity.y) +
                       (racer->segmentPositionInfo.segmentDisplacement.z * racer->velocity.z)) >= 0.0f))) {
                    func_80090AFC(racer);
                }
            }
        } else {
            racer->segmentPositionInfo.pos = sp10C;
            func_80090AFC(racer);
        }
    }
    racer->trueBasis.y.x += 0.19f * racer->tiltUp.x;
    racer->trueBasis.y.y += 0.19f * racer->tiltUp.y;
    racer->trueBasis.y.z += 0.19f * racer->tiltUp.z;
    if (Math_OrthonormalizeAroundUp(&racer->trueBasis) != 0) {
        racer->trueBasis = spE8;
    }
    if (racer->unk_198 != 0.0f) {
        sp128 = racer->heightAboveGround;
    } else {
        sp128 = racer->unk_17C;
    }

    var_fa1 = racer->focusPos.x;
    var_fv1 = racer->focusPos.x = racer->segmentPositionInfo.pos.x - (sp128 * racer->trueBasis.y.x);
    racer->focusVelocity.x = var_fv1 - var_fa1;

    var_fa1 = racer->focusPos.y;
    var_fv1 = racer->focusPos.y = racer->segmentPositionInfo.pos.y - (sp128 * racer->trueBasis.y.y);
    racer->focusVelocity.y = var_fv1 - var_fa1;

    var_fa1 = racer->focusPos.z;
    var_fv1 = racer->focusPos.z = racer->segmentPositionInfo.pos.z - (sp128 * racer->trueBasis.y.z);
    racer->focusVelocity.z = var_fv1 - var_fa1;

    racer->unk_80.x = racer->segmentPositionInfo.pos.x - sp10C.x;
    racer->unk_80.y = racer->segmentPositionInfo.pos.y - sp10C.y;
    racer->unk_80.z = racer->segmentPositionInfo.pos.z - sp10C.z;

    racer->unk_68.x = (spE8.z.x * racer->unk_80.x) + (spE8.z.y * racer->unk_80.y) + (spE8.z.z * racer->unk_80.z);
    racer->unk_68.y = (spE8.y.x * racer->unk_80.x) + (spE8.y.y * racer->unk_80.y) + (spE8.y.z * racer->unk_80.z);
    racer->unk_68.z = (spE8.x.x * racer->unk_80.x) + (spE8.x.y * racer->unk_80.y) + (spE8.x.z * racer->unk_80.z);
    racer->unk_5C.x = (racer->trueBasis.z.x * racer->velocity.x) + (racer->trueBasis.z.y * racer->velocity.y) +
                      (racer->trueBasis.z.z * racer->velocity.z);
    racer->unk_5C.y = (racer->trueBasis.y.x * racer->velocity.x) + (racer->trueBasis.y.y * racer->velocity.y) +
                      (racer->trueBasis.y.z * racer->velocity.z);
    racer->unk_5C.z = (racer->trueBasis.x.x * racer->velocity.x) + (racer->trueBasis.x.y * racer->velocity.y) +
                      (racer->trueBasis.x.z * racer->velocity.z);
    if ((racer->id < gNumPlayers) && (controller->unk_74 != 0)) {

        if (!(racer->stateFlags & (RACER_STATE_RETIRED | RACER_STATE_SPINNING_OUT))) {
            if (racer->stateFlags & RACER_STATE_RECEIVED_DAMAGE) {
                if (D_800E5F20[racer->id] == 0) {
                    D_800E5F20[racer->id] = 1;
                    controller->unk_88 = 4000;
                    controller->unk_8C = 0;
                    controller->unk_90 = 0;
                    goto skip;
                }
            } else {
                if (D_800E5F20[racer->id] != 0) {
                    D_800E5F20[racer->id]--;
                }
                if (racer->boostTimer == sInitialBoostTimer - 1) {
                    controller->unk_88 = 1000;
                    controller->unk_8C = controller->unk_90 = 0;
                    goto skip;
                } else if (racer->boostTimer != 0) {
                    controller->unk_8C = (racer->boostTimer * 300) / sInitialBoostTimer;
                    goto skip;
                }
            }

            if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_DIRT) {
                if (D_800E5F30[racer->id] == 0) {
                    D_800E5F30[racer->id] = 150;
                    controller->unk_88 = 2000;
                    controller->unk_8C = 300;
                    controller->unk_90 = 1;
                    goto skip;
                } else if (D_800E5F30[racer->id] >= 2) {
                    D_800E5F30[racer->id]--;
                    goto skip;
                }
            } else {
                D_800E5F30[racer->id] = 0;
            }

            var_ft4 = racer->unk_80.x;
            var_fs0 = racer->unk_80.y;
            var_fs1 = racer->unk_80.z;
            i = (s32) (sqrtf(SQ(var_ft4) + SQ(var_fs0) + SQ(var_fs1)) * D_800CE754);
            if (i > 1000) {
                i = 1000;
            }
            controller->unk_8C = i;
            controller->unk_90 = 0;
        skip:;
        }
    }

    if ((racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_AIRBORNE | RACER_STATE_SPINNING_OUT |
                              COURSE_EFFECT_MASK)) == COURSE_EFFECT_PIT) {
        racer->energy += racer->energyIncrease;
        if (racer->maxEnergy < racer->energy) {
            racer->energy = racer->maxEnergy;
        }

        if (racer->pitForceFieldSize < 1.0f) {
            racer->pitForceFieldSize += 0.1f;
            if (racer->pitForceFieldSize >= 1.0f) {
                racer->pitForceFieldSize = 1.0f;
            } else if ((racer->id < gNumPlayers) && (racer->pitForceFieldSize == 0.1f)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_PIT;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, NA_LEVEL_SE_4);
                }
            }
        }
    } else {
        if (racer->pitForceFieldSize > 0.0f) {
            racer->pitForceFieldSize -= 0.1f;
            if (racer->pitForceFieldSize <= 0.0f) {
                racer->pitForceFieldSize = 0.0f;
                if (racer->id < gNumPlayers) {
                    racer->soundEffectFlags &= ~RACER_SE_FLAGS_PIT;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStop(racer->id, NA_LEVEL_SE_4);
                    }
                }
            }
        }
    }
    racer->vibrationStrength = (racer->vibrationStrength + (s32) (racer->accelerationForce * 4000.0f)) & 0xFFF;

    var_fa1 = SIN(racer->vibrationStrength) * (racer->speed * 0.007f);
    if (racer->soundEffectFlags & RACER_SE_FLAGS_DIRT) {
        var_fa1 *= 5.0f;
    }
    racer->modelPos.x = racer->segmentPositionInfo.pos.x + (var_fa1 * racer->modelBasis.y.x);
    racer->modelPos.y = racer->segmentPositionInfo.pos.y + (var_fa1 * racer->modelBasis.y.y);
    racer->modelPos.z = racer->segmentPositionInfo.pos.z + (var_fa1 * racer->modelBasis.y.z);
    if (racer->spinOutTimer != 0) {
        racer->modelPos.x += ((f32) (Math_Rand1() % 65536) * (1.8f / 65535.0f)) - 0.9f;
        racer->modelPos.y += ((f32) (Math_Rand1() % 65536) * (1.8f / 65535.0f)) - 0.9f;
        racer->modelPos.z += ((f32) (Math_Rand2() % 65536) * (1.8f / 65535.0f)) - 0.9f;
    }

    if (racer->unk_27C != 0) {
        if (racer->attackState == ATTACK_STATE_SIDE) {
            racer->modelBasis.x.x = racer->trueBasis.x.x;
            racer->modelBasis.x.y = racer->trueBasis.x.y;
            racer->modelBasis.x.z = racer->trueBasis.x.z;
        } else { // ATTACK_STATE_SPIN
            var_fs1 = COS(racer->unk_27C);
            var_fs0 = SIN(racer->unk_27C);
            racer->modelBasis.x.x = (racer->trueBasis.x.x * var_fs1) + (var_fs0 * racer->trueBasis.z.x);
            racer->modelBasis.x.y = (racer->trueBasis.x.y * var_fs1) + (var_fs0 * racer->trueBasis.z.y);
            racer->modelBasis.x.z = (racer->trueBasis.x.z * var_fs1) + (var_fs0 * racer->trueBasis.z.z);
        }

        if (racer->attackState == ATTACK_STATE_SIDE) {
            racer->unk_27C += racer->unk_280;
            if ((racer->unk_27C == -0x80) || (racer->unk_27C == 0x1080)) {
                racer->unk_204 = 30;
                racer->unk_27C = 0;
                racer->attackState = ATTACK_STATE_NONE;
            }
        } else { // ATTACK_STATE_SPIN
            racer->unk_27C += racer->unk_280;
            if (racer->unk_280 < 0) {
                racer->unk_280 += 2;
                if (racer->unk_27C <= 0) {
                    racer->unk_27C += 0x1000;
                    if (racer->unk_280 > -50) {
                        racer->unk_27C = 0;
                        racer->attackState = ATTACK_STATE_NONE;
                    } else if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_2);
                    }
                }
            } else {
                racer->unk_280 -= 2;
                if (racer->unk_27C >= 0x1000) {
                    racer->unk_27C -= 0x1000;
                    if (racer->unk_280 < 50) {
                        racer->unk_27C = 0;
                        racer->attackState = ATTACK_STATE_NONE;
                    } else if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_2);
                    }
                }
            }
        }
    } else {
        racer->modelBasis.x.x = racer->trueBasis.x.x;
        racer->modelBasis.x.y = racer->trueBasis.x.y;
        racer->modelBasis.x.z = racer->trueBasis.x.z;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            racer->modelPos.x += (var_fs1 = racer->podiumHeight * racer->trueBasis.y.x);
            racer->modelPos.y += (var_fs0 = racer->podiumHeight * racer->trueBasis.y.y);
            racer->modelPos.z += (var_ft4 = racer->podiumHeight * racer->trueBasis.y.z);
            racer->shadowPos.x += var_fs1;
            racer->shadowPos.y += var_fs0;
            racer->shadowPos.z += var_ft4;
        }
    }
    var_fa1 = racer->unk_68.x * 0.6f;

    racer->modelBasis.y.x += 0.19f * (racer->trueBasis.y.x + (var_fa1 * racer->trueBasis.z.x));
    racer->modelBasis.y.y += 0.19f * (racer->trueBasis.y.y + (var_fa1 * racer->trueBasis.z.y));
    racer->modelBasis.y.z += 0.19f * (racer->trueBasis.y.z + (var_fa1 * racer->trueBasis.z.z));

    racer->modelBasis.z.x =
        (racer->modelBasis.y.y * racer->modelBasis.x.z) - (racer->modelBasis.y.z * racer->modelBasis.x.y);
    racer->modelBasis.z.y =
        (racer->modelBasis.y.z * racer->modelBasis.x.x) - (racer->modelBasis.y.x * racer->modelBasis.x.z);
    racer->modelBasis.z.z =
        (racer->modelBasis.y.x * racer->modelBasis.x.y) - (racer->modelBasis.y.y * racer->modelBasis.x.x);

    var_fa1 = 1.0f / sqrtf(SQ(racer->modelBasis.z.x) + SQ(racer->modelBasis.z.y) + SQ(racer->modelBasis.z.z));

    racer->modelBasis.z.x *= var_fa1;
    racer->modelBasis.z.y *= var_fa1;
    racer->modelBasis.z.z *= var_fa1;

    racer->modelBasis.y.x =
        (racer->modelBasis.x.y * racer->modelBasis.z.z) - (racer->modelBasis.x.z * racer->modelBasis.z.y);
    racer->modelBasis.y.y =
        (racer->modelBasis.x.z * racer->modelBasis.z.x) - (racer->modelBasis.x.x * racer->modelBasis.z.z);
    racer->modelBasis.y.z =
        (racer->modelBasis.x.x * racer->modelBasis.z.y) - (racer->modelBasis.x.y * racer->modelBasis.z.x);
    if (racer->stateFlags & RACER_STATE_COLLISION_RECOIL) {
        racer->modelBasis.y.x += racer->recoilTilt.x *= 0.8f;
        racer->modelBasis.y.y += racer->recoilTilt.y *= 0.8f;
        racer->modelBasis.y.z += racer->recoilTilt.z *= 0.8f;

        var_fa1 = 1.0f / sqrtf(SQ(racer->modelBasis.y.x) + SQ(racer->modelBasis.y.y) + SQ(racer->modelBasis.y.z));
        if (var_fa1 > 0.99f) {
            racer->stateFlags &= ~RACER_STATE_COLLISION_RECOIL;
        }

        racer->modelBasis.y.x *= var_fa1;
        racer->modelBasis.y.y *= var_fa1;
        racer->modelBasis.y.z *= var_fa1;

        racer->modelBasis.z.x =
            (racer->modelBasis.y.y * racer->modelBasis.x.z) - (racer->modelBasis.y.z * racer->modelBasis.x.y);
        racer->modelBasis.z.y =
            (racer->modelBasis.y.z * racer->modelBasis.x.x) - (racer->modelBasis.y.x * racer->modelBasis.x.z);
        racer->modelBasis.z.z =
            (racer->modelBasis.y.x * racer->modelBasis.x.y) - (racer->modelBasis.y.y * racer->modelBasis.x.x);

        var_fa1 = 1.0f / sqrtf(SQ(racer->modelBasis.z.x) + SQ(racer->modelBasis.z.y) + SQ(racer->modelBasis.z.z));

        racer->modelBasis.z.x *= var_fa1;
        racer->modelBasis.z.y *= var_fa1;
        racer->modelBasis.z.z *= var_fa1;

        racer->modelBasis.x.x =
            (racer->modelBasis.z.y * racer->modelBasis.y.z) - (racer->modelBasis.z.z * racer->modelBasis.y.y);
        racer->modelBasis.x.y =
            (racer->modelBasis.z.z * racer->modelBasis.y.x) - (racer->modelBasis.z.x * racer->modelBasis.y.z);
        racer->modelBasis.x.z =
            (racer->modelBasis.z.x * racer->modelBasis.y.y) - (racer->modelBasis.z.y * racer->modelBasis.y.x);
    }

    if (racer->bodyWhiteTimer != 0) {
        racer->bodyWhiteTimer--;
    }
    if (racer->spinOutTimer != 0) {
        if (!((*(vu32*) &gGameFrameCount + (0, racer->id)) & 3) && (racer->machineLod != 0)) {
            sp10C.x = (s32) ((Math_Rand1() % 32) - 16) + racer->segmentPositionInfo.pos.x;
            sp10C.y = (s32) ((Math_Rand1() % 32) - 16) + racer->segmentPositionInfo.pos.y;
            sp10C.z = (s32) ((Math_Rand1() % 32) - 16) + racer->segmentPositionInfo.pos.z;
            Effects_SpawnExplosion1(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x, racer->velocity.y, racer->velocity.z,
                                    (f32) ((Math_Rand2() % 16) + ((racer->spinOutTimer * 5) / 150) + 5), racer);
            if (!((racer->id + gGameFrameCount) & 4) && gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(racer->id, NA_SE_5);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 3000;
                controller->unk_8C = 0;
                controller->unk_90 = 0;
            }

            for (i = 2; i > 0; i--) {
                var_fs1 = ((f32) (Math_Rand2() & 0x1FFFF) * (9.0f / 131071.0f)) - 4.5f;
                var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * (5.0f / 131071.0f)) + 2.0f;
                var_ft4 = ((f32) (Math_Rand2() & 0x1FFFF) * (9.0f / 131071.0f)) - 4.5f;
                Effects_SpawnFlyingSparks(sp10C.x, sp10C.y, sp10C.z,
                                          racer->velocity.x + (var_fs1 * racer->trueBasis.z.x) +
                                              (var_fs0 * racer->trueBasis.y.x) + (var_ft4 * racer->trueBasis.x.x),
                                          racer->velocity.y + (var_fs1 * racer->trueBasis.z.y) +
                                              (var_fs0 * racer->trueBasis.y.y) + (var_ft4 * racer->trueBasis.x.y),
                                          racer->velocity.z + (var_fs1 * racer->trueBasis.z.z) +
                                              (var_fs0 * racer->trueBasis.y.z) + (var_ft4 * racer->trueBasis.x.z),
                                          racer);
            }
        }

        racer->spinOutTimer++;
        if (racer->spinOutTimer > 150) {
            racer->spinOutTimer = 0;
            racer->stateFlags &= ~RACER_STATE_SPINNING_OUT;
            racer->stateFlags |= RACER_STATE_CRASHED;
            racer->unk_17C = 10.0f;
            sSpunOutRacers++;
            Racer_RetireRacer(racer);
            if (racer->machineLod != 0) {
                Effects_SpawnExplosion2(racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                                        racer->segmentPositionInfo.pos.z, racer->velocity.x, racer->velocity.y,
                                        racer->velocity.z, 80.0f, racer);
                if (racer->id < gNumPlayers) {
                    i = 60;
                } else {
                    i = 30;
                }
                sp13C = racer->bodyRF;
                sp138 = racer->bodyGF;
                sp134 = racer->bodyBF;
                do {
                    var_fs1 = ((f32) (Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
                    var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * (7.0f / 131071.0f)) + 3.5f;
                    var_ft4 = ((f32) (Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
                    Effects_SpawnMachineDebris((s32) ((Math_Rand2() % 32) - 16) + racer->segmentPositionInfo.pos.x,
                                               (s32) ((Math_Rand2() % 32) - 16) + racer->segmentPositionInfo.pos.y,
                                               (s32) ((Math_Rand2() % 32) - 16) + racer->segmentPositionInfo.pos.z,
                                               racer->velocity.x + (var_fs1 * racer->trueBasis.z.x) +
                                                   (var_fs0 * racer->trueBasis.y.x) + (var_ft4 * racer->trueBasis.x.x),
                                               racer->velocity.y + (var_fs1 * racer->trueBasis.z.y) +
                                                   (var_fs0 * racer->trueBasis.y.y) + (var_ft4 * racer->trueBasis.x.y),
                                               racer->velocity.z + (var_fs1 * racer->trueBasis.z.z) +
                                                   (var_fs0 * racer->trueBasis.y.z) + (var_ft4 * racer->trueBasis.x.z),
                                               &racer->trueBasis, sp13C, sp138, sp134, racer);
                    i--;
                } while (i != 0);
                if (gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, NA_SE_8);
                }
                if (racer->id < gNumPlayers) {
                    controller->unk_88 = 10000;
                    controller->unk_8C = 500;
                    controller->unk_90 = 5;
                }
            }
        }
    }
    if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
        var_fa1 = racer->energy / racer->maxEnergy;
        if ((racer->id < gNumPlayers) && (var_fa1 < 0.3f)) {
            spinOutTimer = racer->spinOutTimer;
            if ((spinOutTimer == 0) && gEnableRaceSfx) {
                if (var_fa1 >= 0.2f) {
                    if (!(*(vu32*) &gGameFrameCount & 0x1F)) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_LOW_ENERGY_SLOW);
                    }
                } else if (var_fa1 >= 0.1f) {
                    if (!(*(vu32*) &gGameFrameCount & 0xF)) {
                        Audio_PlayerTriggerSEStart(racer->id, NA_SE_LOW_ENERGY_MEDIUM);
                    }
                } else if (!(*(vu32*) &gGameFrameCount & 7)) {
                    Audio_PlayerTriggerSEStart(racer->id, NA_SE_LOW_ENERGY_FAST);
                }
            }
        }
        if (!(*(vu32*) &gGameFrameCount & 0x8)) {}
        if (!(*(vu32*) &gGameFrameCount & 0x10)) {}
        if (!(gGameFrameCount & 8) && ((var_fa1 < 0.2f) || ((var_fa1 < 0.5f) && !(gGameFrameCount & 0x10)))) {
            var_fa1 *= 2;
            var_fs1 = (racer->bodyLowEnergyGradientR * var_fa1) + racer->bodyLowEnergyR;
            var_fs0 = (racer->bodyLowEnergyGradientG * var_fa1) + racer->bodyLowEnergyG;
            var_ft4 = (racer->bodyLowEnergyGradientB * var_fa1) + racer->bodyLowEnergyB;
            var_fa1 = (f32) (gGameFrameCount & 7) / 7.0f;
            var_fs1 = ((racer->bodyRF - var_fs1) * var_fa1) + var_fs1;
            var_fs0 = ((racer->bodyGF - var_fs0) * var_fa1) + var_fs0;
            var_ft4 = ((racer->bodyBF - var_ft4) * var_fa1) + var_ft4;
        } else {
            var_fs1 = racer->bodyRF;
            var_fs0 = racer->bodyGF;
            var_ft4 = racer->bodyBF;
        }

        var_fa1 = racer->bodyWhiteTimer / 5.0f;
        racer->bodyR = ((255.0f - var_fs1) * var_fa1) + var_fs1;
        racer->bodyG = ((255.0f - var_fs0) * var_fa1) + var_fs0;
        racer->bodyB = ((255.0f - var_ft4) * var_fa1) + var_ft4;
        if (racer->attackState == ATTACK_STATE_SPIN) {
            var_fa1 = SIN(racer->unk_27C & 0x7FF);
            racer->attackHighlightScale = (0.1f * var_fa1) + 1.05f;
            racer->attackHighlightR = 255;
            racer->attackHighlightG = 255 - (s32) (255.0f * var_fa1);
            racer->attackHighlightB = 0;
        } else if (racer->attackState == ATTACK_STATE_SIDE) {
            racer->attackHighlightScale = 1.075f;
            racer->attackHighlightR = 255;
            racer->attackHighlightG = 0;
            racer->attackHighlightB = 0;
        } else {
            racer->attackHighlightScale = 0.0f;
        }
    } else {
        racer->bodyR = racer->bodyRF;
        racer->bodyG = racer->bodyGF;
        racer->bodyB = racer->bodyBF;
        if (((Math_Rand1() & 0x1FFFF) < 0x444) && (racer->machineLod != 0)) {
            var_fs1 = (((f32) (Math_Rand1() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            var_fs0 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 1.5f) + 0.5f;
            var_ft4 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            sp10C.x = (s32) ((Math_Rand2() % 32) - 16) + racer->segmentPositionInfo.pos.x;
            sp10C.y = (s32) ((Math_Rand1() % 32) - 16) + racer->segmentPositionInfo.pos.y;
            sp10C.z = (s32) ((Math_Rand1() % 32) - 16) + racer->segmentPositionInfo.pos.z;

            Effects_SpawnCollisionSparks(sp10C.x, sp10C.y, sp10C.z,
                                         racer->velocity.x + (var_fs1 * racer->trueBasis.z.x) +
                                             (var_fs0 * racer->trueBasis.y.x) + (var_ft4 * racer->trueBasis.x.x),
                                         racer->velocity.y + (var_fs1 * racer->trueBasis.z.y) +
                                             (var_fs0 * racer->trueBasis.y.y) + (var_ft4 * racer->trueBasis.x.y),
                                         racer->velocity.z + (var_fs1 * racer->trueBasis.z.z) +
                                             (var_fs0 * racer->trueBasis.y.z) + (var_ft4 * racer->trueBasis.x.z),
                                         10.0f, racer);
            Effects_SpawnSmoke(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x + racer->tiltUp.x,
                               racer->velocity.y + racer->tiltUp.y, racer->velocity.z + racer->tiltUp.z, 20.0f, racer);

            if (racer->id < gNumPlayers) {
                Audio_PlayerTriggerSEStart(racer->id, NA_SE_50);
            }
            racer->attackHighlightScale = 1.03f;
            racer->attackHighlightR = racer->attackHighlightG = 255;
            racer->attackHighlightB = 0;
        } else {
            racer->attackHighlightScale = 0.0f;
        }
    }

    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_8000))) {
        racer->unk_17C += ((13.0f - racer->unk_17C) * 0.05f);
        if (racer->unk_17C > 13.0f) {
            racer->unk_17C = 13.0f;
            racer->stateFlags |= RACER_STATE_FLAGS_8000;
        }
    } else if ((D_800F80A4 == racer->unk_17C) && (controller->buttonCurrent != 0) && (gRaceIntroTimer < 250)) {
        racer->stateFlags &= ~RACER_STATE_FLAGS_8000;
        racer->shadowColorStrength = 1.3f;
        racer->shadowBaseR = 0.0f;
        racer->shadowBaseG = 205.0f;
        racer->shadowBaseB = 255.0f;
        if (racer->id < gNumPlayers) {
#ifdef EXPANSION_KIT
            func_800BAE5C(racer->id);
#endif
            Audio_PlayerTriggerSEStart(racer->id, NA_SE_40);
        }
    }

    if (racer->shadowColorStrength != 1.0f) {
        var_fa1 = (racer->shadowColorStrength - 1.0f) / 0.29999995f;
        var_fa1 *= var_fa1;
        racer->shadowR = racer->shadowBaseR * var_fa1;
        racer->shadowG = racer->shadowBaseG * var_fa1;
        racer->shadowB = racer->shadowBaseB * var_fa1;
        racer->shadowColorStrength -= 0.003f;
        if (racer->shadowColorStrength < 1) {
            racer->shadowColorStrength = 1.0f;
        }
    } else {
        racer->shadowR = racer->shadowG = racer->shadowB = 0;
    }
    if (racer->id < gNumPlayers) {
        if ((racer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_FLAG_INSIDE) &&
            !(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
            if (!(racer->soundEffectFlags & RACER_SE_FLAGS_ENGINE_ECHO)) {
                racer->soundEffectFlags |= RACER_SE_FLAGS_ENGINE_ECHO;
                if (gEnableRaceSfx) {
                    Audio_PlayerEngineEchoStart(racer->id);
                }
            }
        } else {

            if (racer->soundEffectFlags & RACER_SE_FLAGS_ENGINE_ECHO) {
                racer->soundEffectFlags &= ~RACER_SE_FLAGS_ENGINE_ECHO;
                if (gEnableRaceSfx) {
                    Audio_PlayerEngineEchoStop(racer->id);
                }
            }
        }
    }
}

void func_80094FF4(s32 position) {
    if (!(position > -0x80 && position < 0x80)) {
        sGhostReplayRecordingSize += 3;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = -0x80;
            *sGhostReplayRecordingPtr++ = ((position & 0xFFFF) >> 8);
            *sGhostReplayRecordingPtr++ = position & 0xFF;
        } else {
            sGhostReplayRecordingSize -= 3;
            gUnableToRecordGhost = true;
            D_800F5DE4 = 0;
        }
    } else {
        sGhostReplayRecordingSize++;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = position;
        } else {
            sGhostReplayRecordingSize--;
            gUnableToRecordGhost = true;
            D_800F5DE4 = 0;
        }
    }
}

s32 func_800950E8(GhostRacer* ghostRacer) {
    s32 temp1 = *ghostRacer->replayPtr++;

    if (temp1 == -0x80) {
        temp1 = *ghostRacer->replayPtr++;
        temp1 <<= 8;
        temp1 |= (u8) *ghostRacer->replayPtr++;
        ghostRacer->replayIndex += 3;
    } else {
        ghostRacer->replayIndex++;
    }

    return temp1;
}

void func_80095144(void) {
    s32 i;

    for (i = 0; i < gNumPlayers; i++) {
        gControllers[gPlayerControlPorts[i]].unk_72 = 0;
    }

    if (D_800F80C4 == 1) {
        Racer_IncreaseLife(0);
    } else if (D_800F80C4 == -1) {
        Racer_DecreaseLife(0);
    }
}

void Racer_UpdateMovement(Racer* racer) {
    Controller dummyController;
    f32 preInputEnergy;

    if (racer->stateFlags & RACER_STATE_CPU_CONTROLLED) {
        preInputEnergy = racer->energy;
        Cpu_GenerateInputs(racer, &dummyController);
        if (preInputEnergy < racer->energy) {
            racer->energy = preInputEnergy;
        }
        if ((gRaceIntroTimer > 40) && (racer->unk_2A4 != 0)) {
            dummyController.buttonCurrent = 0;
            if (gRaceIntroTimer < 250) {
                racer->unk_2A4--;
            }
        }
        Racer_UpdateFromControls(racer, &dummyController);
    } else {
        Racer_UpdateFromControls(racer, &gControllers[gPlayerControlPorts[racer->id]]);
        racer->unk_33C = -racer->segmentPositionInfo.segmentDisplacement.x * racer->segmentBasis.z.x -
                         racer->segmentPositionInfo.segmentDisplacement.y * racer->segmentBasis.z.y -
                         racer->segmentPositionInfo.segmentDisplacement.z * racer->segmentBasis.z.z;
    }
}

extern s8 gGamePaused;
extern GfxPool* gGfxPool;
extern s32 gFastestGhostTime;

void Racer_Update(void) {
    f32 xVelocityDiff;
    f32 yVelocityDiff;
    f32 zVelocityDiff;
    f32 sp128;
    f32 temp_fv1_3;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fs0;
    f32 var_fs1;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 var_fs2;
    f32 var_ft4;
    s32 posDiff;
    GhostRacer* ghostRacer;
    RacerPairInfo* racerPair;
    s32 i;
    Mtx3F spCC;
    Racer* racer;
    Racer* racer2;
#ifdef EXPANSION_KIT
    bool spC0;
#endif
    Camera* camera;

    sRaceFrameCount++;

#ifdef EXPANSION_KIT
    spC0 = false;
#endif

    if (gRaceIntroTimer != 0) {
        if (!gGamePaused) {
            if (gRaceIntroTimer == 460) {
                func_8007E08C();
                if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                    Audio_StartDemo();
                }
#ifndef EXPANSION_KIT
                for (i = 0; i < gNumPlayers; i++) {
                    func_800BAE5C(i);
                }
#endif
            }

            gRaceIntroTimer--;
            if (gRaceIntroTimer == 40) {
#ifdef EXPANSION_KIT
                if (func_807424CC() != 0) {
                    gRaceIntroTimer++;
                    spC0 = true;
                } else {
#endif
                    for (racer = sLastRacer; racer >= gRacers; racer--) {
                        racer->stateFlags |= RACER_STATE_FLAGS_400000;
                    }
#ifdef EXPANSION_KIT
                }
#endif
            } else if ((gRaceIntroTimer == 255) && (gGameMode == GAMEMODE_TIME_ATTACK)) {
                D_800F5DE4 = 1;
                sReplayRecordFrameCount = 0;
                sReplayRecordPosX = Math_Round(gRacers[0].segmentPositionInfo.pos.x);
                sReplayRecordPosY = Math_Round(gRacers[0].segmentPositionInfo.pos.y);
                sReplayRecordPosZ = Math_Round(gRacers[0].segmentPositionInfo.pos.z);

                for (ghostRacer = &gGhostRacers[2]; ghostRacer >= gGhostRacers; ghostRacer--) {
                    if (ghostRacer->exists) {
                        ghostRacer->initialized = true;
                        ghostRacer->frameCount = 0;
                        posDiff = func_800950E8(ghostRacer);
                        ghostRacer->replayPosX = posDiff + sReplayRecordPosX;
                        ghostRacer->pos.x = gRacers[0].segmentPositionInfo.pos.x + (posDiff * 0.5f);
                        posDiff = func_800950E8(ghostRacer);
                        ghostRacer->replayPosY = posDiff + sReplayRecordPosY;
                        ghostRacer->pos.y = gRacers[0].segmentPositionInfo.pos.y + (posDiff * 0.5f);
                        posDiff = func_800950E8(ghostRacer);
                        ghostRacer->replayPosZ = posDiff + sReplayRecordPosZ;
                        ghostRacer->pos.z = gRacers[0].segmentPositionInfo.pos.z + (posDiff * 0.5f);
                    }
                }
            }
        }

        for (i = gNumPlayers - 1; i >= 0; i--) {
            racer2 = &gRacers[i];
            camera = &gCameras[i];
            spCC.x.x = -camera->basis.x.x;
            spCC.x.y = -camera->basis.x.y;
            spCC.x.z = -camera->basis.x.z;
            spCC.y.x = racer2->trueBasis.y.x;
            spCC.y.y = racer2->trueBasis.y.y;
            spCC.y.z = racer2->trueBasis.y.z;
            Math_OrthonormalizeAroundUp(&spCC);
            if (gRaceIntroTimer > 220) {
                var_fs0 = (gRaceIntroTimer - 220) / 240.0f;
            } else if (gRaceIntroTimer > 30) {
                var_fs0 = 0.0f;
            } else {
                var_fs0 = (30 - gRaceIntroTimer) / 30.0f;
            }
            var_fs0 = (1500.0f * var_fs0 * var_fs0) + 33.0f;
            var_fs2 = var_fs0 - racer2->heightAboveGround;
            Matrix_SetLockedLookAt(&gGfxPool->unk_21988[i], NULL, 0.2f, 0.2f, 0.2f, spCC.x.x, spCC.x.y, spCC.x.z,
                                   spCC.y.x, spCC.y.y, spCC.y.z,
                                   (racer2->segmentPositionInfo.pos.x + (var_fs2 * racer2->trueBasis.y.x) +
                                    (50.0f * racer2->trueBasis.x.x)) -
                                       (var_fs0 * camera->basis.x.x),
                                   (racer2->segmentPositionInfo.pos.y + (var_fs2 * racer2->trueBasis.y.y) +
                                    (50.0f * racer2->trueBasis.x.y)) -
                                       (var_fs0 * camera->basis.x.y),
                                   (racer2->segmentPositionInfo.pos.z + (var_fs2 * racer2->trueBasis.y.z) +
                                    (50.0f * racer2->trueBasis.x.z)) -
                                       (var_fs0 * camera->basis.x.z));
        }
    }

    if (gGamePaused) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->modelMatrixInit = racer->shadowMatrixInit = racer->attackHighlightMatrixInit = false;
        }
        gControllers[gGameFrameCount % 4].unk_78 = 1;
        return;
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        racer->modelMatrixInit = racer->shadowMatrixInit = racer->attackHighlightMatrixInit = false;
        racer->stateFlags &= ~RACER_STATE_RECEIVED_DAMAGE;
        racer->acceleration.z = 0.0f;
        racer->acceleration.y = 0.0f;
        racer->acceleration.x = 0.0f;
        if ((racer->energyRegain != 0.0f) && !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
            racer->energy += racer->energyRegain;
            if (racer->energy > racer->maxEnergy) {
                racer->energy = racer->maxEnergy;
            }
            racer->energyRegain = 0.0f;
        }
    }

    if (gNumPlayers != 1) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 1;
        }
    }
    if (gTotalRacers >= 2) {
        racer = sLastRacer;
        do {
            if (!(racer->stateFlags & RACER_STATE_ACTIVE)) {
                continue;
            }

            i = (s32) (racer->id * (racer->id - 1)) >> 1;
            racer2 = racer - 1;
            do {
                if (racer2->stateFlags & RACER_STATE_ACTIVE) {
                    racerPair = &sRacerPairInfo[i + racer2->id];
                    if (racerPair->trailToLeadDistance > 92.0f) {
                        racerPair->areColliding = false;
                        continue;
                    }
                    var_fa0 = racer2->segmentPositionInfo.pos.x - racer->segmentPositionInfo.pos.x;
                    var_fa1 = racer2->segmentPositionInfo.pos.z - racer->segmentPositionInfo.pos.z;
                    sp110 = var_fa0;
                    sp108 = var_fa1;

                    if (SQ(var_fa0) + SQ(var_fa1) > 2116.0f) {
                        racerPair->areColliding = false;
                        continue;
                    }

                    sp10C = racer2->segmentPositionInfo.pos.y - racer->segmentPositionInfo.pos.y;
                    if ((SQ(var_fa0) + SQ(var_fa1) + SQ(sp10C)) > 2116.0f) {
                        racerPair->areColliding = false;
                        continue;
                    }

                    sp128 = sqrtf((SQ(var_fa0) + SQ(var_fa1) + SQ(sp10C)));
                    if (racer->stateFlags & RACER_STATE_CRASHED) {
                        var_fs2 = racer->collidingStrength * 0.333f;
                    } else {
                        var_fs2 = racer->collidingStrength;
                    }
                    if (racer2->stateFlags & RACER_STATE_CRASHED) {
                        var_fs1 = racer2->collidingStrength * 0.333f;
                    } else {
                        var_fs1 = racer2->collidingStrength;
                    }
                    temp_fv1_3 = var_fs2 + var_fs1;
                    var_fs2 /= temp_fv1_3;
                    var_fs1 /= temp_fv1_3;
                    xVelocityDiff = racer2->velocity.x - racer->velocity.x;
                    yVelocityDiff = racer2->velocity.y - racer->velocity.y;
                    zVelocityDiff = racer2->velocity.z - racer->velocity.z;
                    if (!racerPair->areColliding) {
                        if (racer->id < gNumPlayers) {
                            racer2->unk_288 = 0;
                            racer2->unk_28C = racer;
                        }
                        if (racer2->id < gNumPlayers) {
                            racer->unk_288 = 0;
                            racer->unk_28C = racer2;
                        }
                        if (sp128 < 0.01f) {
                            temp_fv1_3 = 1.0f / sqrtf(SQ(xVelocityDiff) + SQ(yVelocityDiff) + SQ(zVelocityDiff));
                            var_fa0 = temp_fv1_3 * xVelocityDiff;
                            var_fa1 = temp_fv1_3 * yVelocityDiff;
                            var_ft4 = temp_fv1_3 * zVelocityDiff;
                        } else {
                            temp_fv1_3 = 1.0f / sp128;
                            var_fa0 = temp_fv1_3 * sp110;
                            var_fa1 = temp_fv1_3 * sp10C;
                            var_ft4 = temp_fv1_3 * sp108;
                        }
                        var_fs0 = (var_fa0 * xVelocityDiff) + (var_fa1 * yVelocityDiff) + (var_ft4 * zVelocityDiff);

                        if (var_fs0 < 0.0f) {
                            var_fs0 = -var_fs0;
                        }
                        if ((racer2->machineLod != 0) &&
                            (Effects_SpawnCollisionSparks(
                                 ((racer->segmentPositionInfo.pos.x + racer2->segmentPositionInfo.pos.x) * 0.5f) +
                                     (6.0f * racer->trueBasis.y.x),
                                 ((racer->segmentPositionInfo.pos.y + racer2->segmentPositionInfo.pos.y) * 0.5f) +
                                     (6.0f * racer->trueBasis.y.y),
                                 ((racer->segmentPositionInfo.pos.z + racer2->segmentPositionInfo.pos.z) * 0.5f) +
                                     (6.0f * racer->trueBasis.y.z),
                                 (racer->velocity.x + racer2->velocity.x) * 0.5f,
                                 (racer->velocity.y + racer2->velocity.y) * 0.5f,
                                 (racer->velocity.z + racer2->velocity.z) * 0.5f, var_fs0 + 12.0f, racer2) == 0)) {
                            racer->bodyWhiteTimer = racer2->bodyWhiteTimer;
                        }
                        var_fs0 *= 1.1f;
                        if (racer->attackState == ATTACK_STATE_NONE) {
                            if (racer2->attackState == ATTACK_STATE_NONE) {
                                Racer_ReceiveDamage(racer, var_fs1 * var_fs0);
                                Racer_ReceiveDamage(racer2, var_fs2 * var_fs0);
                            } else if ((racer2 == gRacers) && (gNumPlayers == 1)) {
                                Racer_ReceiveDamage(racer, var_fs0 * 10.0f);
                            } else {
                                Racer_ReceiveDamage(racer, var_fs0);
                            }
                        } else if (racer2->attackState == ATTACK_STATE_NONE) {
                            Racer_ReceiveDamage(racer2, var_fs0);
                        } else {
                            Racer_ReceiveDamage(racer, var_fs1 * var_fs0);
                            Racer_ReceiveDamage(racer2, var_fs2 * var_fs0);
                        }
                        if (gEnableRaceSfx) {
                            Audio_PlayerTriggerSEStart(racer2->id, NA_SE_4);
                        }
                    }
                    racerPair->areColliding = true;
                    if (((sp110 * xVelocityDiff) + (sp10C * yVelocityDiff) + (sp108 * zVelocityDiff)) <= 0.0f) {
                        if (sp128 < 0.01f) {
                            temp_fv1_3 = -46.0f / sqrtf(SQ(xVelocityDiff) + SQ(yVelocityDiff) + SQ(zVelocityDiff));
                            var_fa0 = temp_fv1_3 * xVelocityDiff;
                            var_fa1 = temp_fv1_3 * yVelocityDiff;
                            var_ft4 = temp_fv1_3 * zVelocityDiff;
                        } else {
                            if ((racer->attackState | racer2->attackState) != ATTACK_STATE_NONE) {
                                var_fs0 = 46.0f - sp128;
                                if (var_fs0 < 3) {
                                    var_fs0 = 3;
                                }
                                var_fs0 /= sp128;
                            } else {
                                var_fs0 = 46.0f - sp128;
                                var_fs0 /= sp128;
                            }
                            var_fa0 = var_fs0 * sp110;
                            var_fa1 = var_fs0 * sp10C;
                            var_ft4 = var_fs0 * sp108;
                        }
                        if (racer->attackState != ATTACK_STATE_NONE) {
                            if (racer2->attackState == ATTACK_STATE_NONE) {
                                var_fs2 = 3.0f;
                                var_fs1 = 0.0f;
                                racer2->unk_208 = 60;
                            }
                        } else if (racer2->attackState != ATTACK_STATE_NONE) {
                            var_fs2 = 0.0f;
                            var_fs1 = 3.0f;
                            racer->unk_208 = 60;
                        }
                        racer->acceleration.x -= var_fs1 * var_fa0;
                        racer->acceleration.y -= var_fs1 * var_fa1;
                        racer->acceleration.z -= var_fs1 * var_ft4;
                        racer->recoilTilt.x = (-0.15f * var_fs1) * var_fa0;
                        racer->recoilTilt.y = (-0.15f * var_fs1) * var_fa1;
                        racer->recoilTilt.z = (-0.15f * var_fs1) * var_ft4;
                        racer->stateFlags |= RACER_STATE_COLLISION_RECOIL;
                        racer2->acceleration.x += var_fs2 * var_fa0;
                        racer2->acceleration.y += var_fs2 * var_fa1;
                        racer2->acceleration.z += var_fs2 * var_ft4;
                        racer2->recoilTilt.x = (0.15f * var_fs2) * var_fa0;
                        racer2->recoilTilt.y = (0.15f * var_fs2) * var_fa1;
                        racer2->recoilTilt.z = (0.15f * var_fs2) * var_ft4;
                        racer2->stateFlags |= RACER_STATE_COLLISION_RECOIL;
                    }
                }
            } while (--racer2 >= gRacers);
        } while (--racer > gRacers);
    }
    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->stateFlags & RACER_STATE_ACTIVE) {
            Racer_UpdateMovement(racer);
        }
    }

    for (i = 0; i < gNumPlayers; i++) {
        racer2 = &gRacers[i];
        if ((racer2->maxSpeed < racer2->speed) &&
            !(racer2->stateFlags &
              (RACER_STATE_CRASHED | RACER_STATE_AIRBORNE | RACER_STATE_FINISHED | RACER_STATE_FALLING_OFF_TRACK)) &&
            (gPlayerReverseTimer[i] == 0)) {
            racer2->maxSpeed = racer2->speed;
        }
    }

#ifndef EXPANSION_KIT
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
#else
    if (gGameMode == GAMEMODE_TIME_ATTACK && !spC0) {
#endif
        sReplayRecordFrameCount++;
        if ((D_800F5DE4 != 0) && !(sReplayRecordFrameCount & 1)) {
            var_fs0 = gRacers[0].segmentPositionInfo.pos.x;
            i = Math_Round(var_fs0);
            func_80094FF4(i - sReplayRecordPosX);
            sReplayRecordPosX = i;
            var_fs0 = gRacers[0].segmentPositionInfo.pos.y;
            i = Math_Round(var_fs0);
            func_80094FF4(i - sReplayRecordPosY);
            sReplayRecordPosY = i;
            var_fs0 = gRacers[0].segmentPositionInfo.pos.z;
            i = Math_Round(var_fs0);
            func_80094FF4(i - sReplayRecordPosZ);
            sReplayRecordPosZ = i;
            if (D_800F5DE8 && !gUnableToRecordGhost && !D_800F5DEA) {
                D_800F5DEA = true;
                sGhostReplayRecordingEnd = sGhostReplayRecordingSize;
            }
        }
        for (ghostRacer = &gGhostRacers[2]; ghostRacer >= gGhostRacers; ghostRacer--) {
            if ((ghostRacer->exists) && (ghostRacer->initialized)) {
                racer = ghostRacer->racer;
                sp110 = racer->modelPos.x + racer->velocity.x;
                sp10C = racer->modelPos.y + racer->velocity.y;
                sp108 = racer->modelPos.z + racer->velocity.z;
                racer->velocity.x = ghostRacer->pos.x - racer->modelPos.x;
                racer->velocity.y = ghostRacer->pos.y - racer->modelPos.y;
                racer->velocity.z = ghostRacer->pos.z - racer->modelPos.z;
                racer->modelPos = ghostRacer->pos;

                if (func_8009EBEC(&racer->segmentPositionInfo, racer->modelPos.x, racer->modelPos.y, racer->modelPos.z,
                                  100, 1.0f) != 0) {
                    ghostRacer->exists = ghostRacer->initialized = false;
                } else {
                    racer->segmentPositionInfo.segmentLengthProportion =
                        Course_SplineGetLengthInfo(racer->segmentPositionInfo.courseSegment,
                                                   racer->segmentPositionInfo.segmentTValue, &racer->lapDistance);

                    Course_SplineGetBasis(racer->segmentPositionInfo.courseSegment,
                                          racer->segmentPositionInfo.segmentTValue, &racer->segmentBasis,
                                          racer->segmentPositionInfo.segmentLengthProportion);
                    racer->currentRadiusLeft = (racer->segmentPositionInfo.segmentLengthProportion *
                                                (racer->segmentPositionInfo.courseSegment->next->radiusLeft -
                                                 racer->segmentPositionInfo.courseSegment->radiusLeft)) +
                                               racer->segmentPositionInfo.courseSegment->radiusLeft;
                    racer->currentRadiusRight = (racer->segmentPositionInfo.segmentLengthProportion *
                                                 (racer->segmentPositionInfo.courseSegment->next->radiusRight -
                                                  racer->segmentPositionInfo.courseSegment->radiusRight)) +
                                                racer->segmentPositionInfo.courseSegment->radiusRight;
                    D_800CF4B8[TRACK_SHAPE_INDEX((u32) racer->segmentPositionInfo.courseSegment->trackSegmentInfo &
                                                 TRACK_SHAPE_MASK)](racer);

                    ghostRacer->frameCount++;
                    if (ghostRacer->frameCount & 1) {
                        ghostRacer->pos.x = ghostRacer->replayPosX;
                        ghostRacer->pos.y = ghostRacer->replayPosY;
                        ghostRacer->pos.z = ghostRacer->replayPosZ;
                        if (ghostRacer->replayIndex >= ghostRacer->ghost->replaySize) {
                            ghostRacer->exists = ghostRacer->initialized = false;
                        }
                    } else {
                        posDiff = func_800950E8(ghostRacer);
                        ghostRacer->replayPosX += posDiff;
                        ghostRacer->pos.x += (posDiff * 0.5f);
                        posDiff = func_800950E8(ghostRacer);
                        ghostRacer->replayPosY += posDiff;
                        ghostRacer->pos.y += (posDiff * 0.5f);
                        posDiff = func_800950E8(ghostRacer);
                        ghostRacer->replayPosZ += posDiff;
                        ghostRacer->pos.z += (posDiff * 0.5f);
                    }

                    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));

                    spCC = racer->trueBasis;
                    if (racer->speed > 1.0f) {
                        racer->trueBasis.x.x = ghostRacer->pos.x - racer->modelPos.x;
                        racer->trueBasis.x.y = ghostRacer->pos.y - racer->modelPos.y;
                        racer->trueBasis.x.z = ghostRacer->pos.z - racer->modelPos.z;
                    }
                    racer->trueBasis.y.x += 0.19f * racer->tiltUp.x;
                    racer->trueBasis.y.y += 0.19f * racer->tiltUp.y;
                    racer->trueBasis.y.z += 0.19f * racer->tiltUp.z;
                    if (Math_OrthonormalizeAroundUp(&racer->trueBasis) != 0) {
                        racer->trueBasis = spCC;
                    }

                    racer->unk_80.x = racer->modelPos.x - sp110;
                    racer->unk_80.y = racer->modelPos.y - sp10C;
                    racer->unk_80.z = racer->modelPos.z - sp108;
                    var_fs0 = racer->unk_68.x;
                    racer->unk_68.x = ((spCC.z.x * (racer->unk_80.x)) + (spCC.z.y * racer->unk_80.y) +
                                       (spCC.z.z * racer->unk_80.z) + var_fs0) *
                                      0.5f;
                    racer->unk_68.y =
                        (spCC.y.x * (racer->unk_80.x)) + (spCC.y.y * racer->unk_80.y) + (spCC.y.z * racer->unk_80.z);
                    racer->unk_68.z =
                        (spCC.x.x * (racer->unk_80.x)) + (spCC.x.y * racer->unk_80.y) + (spCC.x.z * racer->unk_80.z);
                    racer->unk_5C.x = (racer->trueBasis.z.x * racer->velocity.x) +
                                      (racer->trueBasis.z.y * racer->velocity.y) +
                                      (racer->trueBasis.z.z * racer->velocity.z);
                    racer->unk_5C.y = (racer->trueBasis.y.x * racer->velocity.x) +
                                      (racer->trueBasis.y.y * racer->velocity.y) +
                                      (racer->trueBasis.y.z * racer->velocity.z);
                    racer->unk_5C.z = (racer->trueBasis.x.x * racer->velocity.x) +
                                      (racer->trueBasis.x.y * racer->velocity.y) +
                                      (racer->trueBasis.x.z * racer->velocity.z);
                    racer->modelBasis.x.x = racer->trueBasis.x.x;
                    racer->modelBasis.x.y = racer->trueBasis.x.y;
                    racer->modelBasis.x.z = racer->trueBasis.x.z;

                    var_fs0 = racer->unk_68.x * 0.6f;
                    racer->modelBasis.y.x += 0.19f * (racer->trueBasis.y.x + (var_fs0 * racer->trueBasis.z.x));
                    racer->modelBasis.y.y += 0.19f * (racer->trueBasis.y.y + (var_fs0 * racer->trueBasis.z.y));
                    racer->modelBasis.y.z += 0.19f * (racer->trueBasis.y.z + (var_fs0 * racer->trueBasis.z.z));
                    Math_OrthonormalizeAroundForward(&racer->modelBasis);
                    if (ghostRacer->ghost->replayEnd < ghostRacer->replayIndex) {
                        if (ghostRacer->scale != 0.f) {
                            ghostRacer->scale -= 0.02f;
                            if (ghostRacer->scale <= 0.0f) {
                                ghostRacer->exists = ghostRacer->initialized = false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (gGameFrameCount & 1) {
        Racer_UpdateRacerPairInfo();
    } else {
        if ((D_800E5FBC == 0) || (gNumPlayers == 1)) {
            Racer_UpdateRacePositions();
        }

        for (i = 0; i < gNumPlayers; i++) {
            racer2 = &gRacers[i];
            if ((((racer2->segmentBasis.x.x * racer2->velocity.x) + (racer2->segmentBasis.x.y * racer2->velocity.y) +
                  (racer2->segmentBasis.x.z * racer2->velocity.z)) < -0.3f) &&
                !(racer2->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FALLING_OFF_TRACK))) {
                gPlayerReverseTimer[i]++;
                if (gPlayerReverseTimer[i] == 100) {
                    Audio_TriggerSystemSE(NA_SE_60);
                }
            } else {
                gPlayerReverseTimer[i] = 0;
            }
        }
    }
    if (gTotalRacers >= 2) {
        if (gNumPlayers == 1) {
            Racer_UpdateNearestRacer();
            if (gEnableRaceSfx) {
                Audio_SetNearestEnemy(gNearestRacer);
            }
        }
#ifndef EXPANSION_KIT
        if ((gRacersByPosition[0]->id < gNumPlayers) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_PRACTICE)) {
#else
        if ((gRacersByPosition[0]->id < gNumPlayers) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_COURSE_EDIT)) {
#endif
            var_fs0 = gRacersByPosition[0]->raceDistance - gRacersByPosition[1]->raceDistance;
            if (var_fs0 > 4000.0f) {
                if (!(gRacersByPosition[0]->soundEffectFlags & RACER_SE_FLAGS_4000)) {
                    gRacersByPosition[0]->soundEffectFlags |= RACER_SE_FLAGS_4000;
                    if (gEnableRaceSfx) {
                        Audio_TriggerSystemSE(NA_SE_59);
                    }
                }
            } else if (var_fs0 < 2000.0f) {
                gRacersByPosition[0]->soundEffectFlags &= ~RACER_SE_FLAGS_4000;
            }
        }
    }
    if (D_800E5FBC == 0) {
        if (gNumPlayers == 1) {
            if (gRacers[0].stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED)) {
                D_800E5FBC = 1;
            }
        } else {
            i = gRacersRetired + gRacersFinished;

            if ((i >= (gTotalRacers - 1)) || (gNumPlayers == (gPlayerRacersRetired + gPlayerRacersFinished))) {
                D_800E5FBC = 1;
                if (gGameFrameCount & 1) {
                    Racer_UpdateRacePositions();
                }
                for (racer = &gRacers[gTotalRacers - 1]; racer >= gRacers; racer--) {
                    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED))) {
                        racer->stateFlags |= RACER_STATE_FINISHED | RACER_STATE_CPU_CONTROLLED;
                        racer->energy = racer->maxEnergy;
                        if (gEnableRaceSfx) {
                            if (racer->position == 1) {
                                Audio_PlayerTriggerSEStart(racer->id, NA_SE_15);
                            }
                            Audio_PlayerFinished(racer->id);
                            Audio_PlayerEngineStop(racer->id);
                            if ((i != 0) && (gPlayerRacersFinished == 0)) {
                                i = 0;
                                func_8007E0CC();
                            }
                        }
                    }
                }

                for (i = gTotalRacers - 2; i >= 0; i--) {
                    gVsRacePlayerPoints[gRacersByPosition[i]->id] += sVsRacePositionPoints[i];
                }
                gVsRacePlayerVictoryCount[gRacersByPosition[0]->id]++;
            }
        }
    } else {
        D_800F80B8++;
        switch (D_800F80B8) {
            case 60:
                func_80095144();
                break;
            case 30:
                if (gRacers[0].stateFlags & RACER_STATE_FINISHED) {
                    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
                        Audio_TriggerSystemSE(NA_SE_61);
                        break;
                    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
                        if ((gCurrentGhostType == GHOST_PLAYER) || (gCurrentGhostType == GHOST_NONE)) {
                            Audio_TriggerSystemSE(NA_SE_61);
                        } else if (gRacers[0].raceTime < gFastestGhostTime) {
                            Audio_TriggerSystemSE(NA_SE_67);
                        }
                    }
                }
                break;
            case 120:
                if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FINISHED) &&
                    (gRacers[0].position == 1)) {
                    Audio_TriggerSystemSE(NA_SE_51);
                }
                break;
        }
    }
}

extern GfxPool D_1000000;

#ifdef NON_MATCHING
Gfx* Racer_Draw(Gfx* gfx, s32 playerIndex) {
    s32 var_s3; // sp5CC
    s32 var_s4; // sp5C8
    s32 sp5C4;
    Camera* camera;
    MtxF sp580;
    Racer* playerRacer;
    Racer* racer;
    f32 sp574;
    f32 sp570;
    f32 sp56C;
    f32 sp568;
    f32 sp564;
    f32 sp560;
    f32 sp55C;
    f32 sp558;
    f32 temp_fs4; // sp554
    f32 temp_fs5; // sp550
    f32 sp54C;
    f32 temp_fs1; // sp548
    f32 temp_fs3; // sp544
    f32 temp_fs2; // sp540
    f32 sp53C;
    f32 sp538;
    f32 sp534;
    f32 temp_fa1;
    f32 temp_fv1;
    f32 temp_fv0;
    f32 temp_fa0;
    f32 temp_fs0;
    Lights1* temp_v0_7;
    Vec3s* var_v0;
    s32 var_s7;
    BoosterInfo* boosterInfo;
    MachineEffect* temp_s1;
    FlyingSparkEffect* flyingSpark;
    FallExplosionEffect* fallExplosion;
    MachineDebrisEffect* machineDebris;
    Vec3f* boosterPos;
    GhostRacer* sp4F8;
    TexturePtr var_s2;

    camera = &gCameras[playerIndex];

    sp56C = (camera->basis.x.x * 100.0f) - camera->eye.x;
    sp568 = (camera->basis.x.y * 100.0f) - camera->eye.y;
    sp564 = (camera->basis.x.z * 100.0f) - camera->eye.z;

    sp580.m[3][2] = camera->projectionMtx.m[3][2] -
                    (camera->projectionMtx.m[2][2] *
                     (sp580.m[3][3] = ((-sp56C * camera->viewMtx.m[0][2]) - (sp568 * camera->viewMtx.m[1][2])) -
                                      (sp564 * camera->viewMtx.m[2][2])));
    sp580.m[3][0] =
        (camera->projectionMtx.m[0][0] *
         ((sp56C * camera->viewMtx.m[0][0]) + (sp568 * camera->viewMtx.m[1][0]) + (sp564 * camera->viewMtx.m[2][0]))) -
        (camera->projectionMtx.m[2][0] * sp580.m[3][3]);
    sp580.m[3][1] =
        (camera->projectionMtx.m[1][1] *
         ((sp56C * camera->viewMtx.m[0][1]) + (sp568 * camera->viewMtx.m[1][1]) + (sp564 * camera->viewMtx.m[2][1]))) -
        (camera->projectionMtx.m[2][1] * sp580.m[3][3]);

    sp580.m[0][0] = camera->projectionViewMtx.m[0][0];
    sp580.m[0][1] = camera->projectionViewMtx.m[0][1];
    sp580.m[0][2] = camera->projectionViewMtx.m[0][2];
    sp580.m[0][3] = camera->projectionViewMtx.m[0][3];
    sp580.m[1][0] = camera->projectionViewMtx.m[1][0];
    sp580.m[1][1] = camera->projectionViewMtx.m[1][1];
    sp580.m[1][2] = camera->projectionViewMtx.m[1][2];
    sp580.m[1][3] = camera->projectionViewMtx.m[1][3];
    sp580.m[2][0] = camera->projectionViewMtx.m[2][0];
    sp580.m[2][1] = camera->projectionViewMtx.m[2][1];
    sp580.m[2][2] = camera->projectionViewMtx.m[2][2];
    sp580.m[2][3] = camera->projectionViewMtx.m[2][3];

#ifndef EXPANSION_KIT
    if (gGameMode != GAMEMODE_GP_END_CS) {
#else
    if (gGameMode == GAMEMODE_GP_END_CS || gGameMode == GAMEMODE_COURSE_EDIT) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = 1;
            racer->unk_2B3 = 2;
        }
    } else {
#endif
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 0;
            if (racer->stateFlags & RACER_STATE_ACTIVE) {
                temp_fa0 = ((sp580.m[0][2] * racer->segmentPositionInfo.pos.x) +
                            (sp580.m[1][2] * racer->segmentPositionInfo.pos.y) +
                            (sp580.m[2][2] * racer->segmentPositionInfo.pos.z)) +
                           sp580.m[3][2];
                if ((temp_fa0 < 0.0f) || (temp_fa0 > 2500.0f)) {
                    continue;
                }
                sp574 = 1.0f / (((sp580.m[0][3] * racer->segmentPositionInfo.pos.x) +
                                 (sp580.m[1][3] * racer->segmentPositionInfo.pos.y) +
                                 (sp580.m[2][3] * racer->segmentPositionInfo.pos.z)) +
                                sp580.m[3][3]);

                temp_fs0 = sp574 * (((sp580.m[0][0] * racer->segmentPositionInfo.pos.x) +
                                     (sp580.m[1][0] * racer->segmentPositionInfo.pos.y) +
                                     (sp580.m[2][0] * racer->segmentPositionInfo.pos.z)) +
                                    sp580.m[3][0]);
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                temp_fs0 = sp574 * (((sp580.m[0][1] * racer->segmentPositionInfo.pos.x) +
                                     (sp580.m[1][1] * racer->segmentPositionInfo.pos.y) +
                                     (sp580.m[2][1] * racer->segmentPositionInfo.pos.z)) +
                                    sp580.m[3][1]);
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                if (temp_fa0 < 230.0f) {
                    racer->machineLod = 1;
                } else if (temp_fa0 < 290.0f) {
                    racer->machineLod = 2;
                } else if (temp_fa0 < 380.0f) {
                    racer->machineLod = 3;
                } else if (temp_fa0 < 470.0f) {
                    racer->machineLod = 4;
                } else if (temp_fa0 < 1500.0f) {
                    racer->machineLod = 5;
                } else {
                    racer->machineLod = 6;
                }

                if (temp_fa0 < 800.0f) {
                    racer->unk_2B2 = 1;
                }
                if (temp_fa0 < 400.0f) {
                    racer->unk_2B3 = 2;
                } else if (temp_fa0 < 900.0f) {
                    racer->unk_2B3 = 1;
                }
            }
        }
#ifndef EXPANSION_KIT
    } else {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = 1;
            racer->unk_2B3 = 2;
        }
#endif
    }
    if (gNumPlayers >= 3) {
        for (racer = &gRacers[gNumPlayers - 1]; racer >= gRacers; racer--) {
            if ((racer->machineLod != 0) && (racer->machineLod < 6)) {
                racer->machineLod++;
            }
            if (racer->unk_2B3 == 2) {
                racer->unk_2B3 = 1;
            }
        }
    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (!sp4F8->exists) {
                continue;
            }
            racer = sp4F8->racer;
            racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 0;
            if (sp4F8->exists) {
                temp_fa0 = ((sp580.m[0][2] * racer->segmentPositionInfo.pos.x) +
                            (sp580.m[1][2] * racer->segmentPositionInfo.pos.y) +
                            (sp580.m[2][2] * racer->segmentPositionInfo.pos.z)) +
                           sp580.m[3][2];
                if ((temp_fa0 < 0.0f) || (temp_fa0 > 2500.0f)) {
                    continue;
                }
                sp574 = 1.0f / (((sp580.m[0][3] * racer->segmentPositionInfo.pos.x) +
                                 (sp580.m[1][3] * racer->segmentPositionInfo.pos.y) +
                                 (sp580.m[2][3] * racer->segmentPositionInfo.pos.z)) +
                                sp580.m[3][3]);

                temp_fs0 = sp574 * (((sp580.m[0][0] * racer->segmentPositionInfo.pos.x) +
                                     (sp580.m[1][0] * racer->segmentPositionInfo.pos.y) +
                                     (sp580.m[2][0] * racer->segmentPositionInfo.pos.z)) +
                                    sp580.m[3][0]);
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }
                temp_fs0 = sp574 * (((sp580.m[0][1] * racer->segmentPositionInfo.pos.x) +
                                     (sp580.m[1][1] * racer->segmentPositionInfo.pos.y) +
                                     (sp580.m[2][1] * racer->segmentPositionInfo.pos.z)) +
                                    sp580.m[3][1]);
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                if (temp_fa0 < 230.0f) {
                    racer->machineLod = 1;
                } else if (temp_fa0 < 290.0f) {
                    racer->machineLod = 2;
                } else if (temp_fa0 < 380.0f) {
                    racer->machineLod = 3;
                } else if (temp_fa0 < 470.0f) {
                    racer->machineLod = 4;
                } else if (temp_fa0 < 1500.0f) {
                    racer->machineLod = 5;
                } else {
                    racer->machineLod = 6;
                }

                if (temp_fa0 < 800.0f) {
                    racer->unk_2B2 = 1;
                }
                if (temp_fa0 < 400.0f) {
                    racer->unk_2B3 = 2;
                } else if (temp_fa0 < 900.0f) {
                    racer->unk_2B3 = 1;
                }
            }
        }
    }
    if (gRaceIntroTimer < 280) {
        gSPDisplayList(gfx++, D_303A758);
        if (gGameMode == GAMEMODE_GP_END_CS) {
            gSPSetGeometryMode(gfx++, G_ZBUFFER);
            gDPSetRenderMode(gfx++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);
        }

        for (racer = sLastRacer; racer >= gRacers; racer--) {

            if ((racer->unk_2B2 == 0) || (racer->shadowPos.y == -54321.0f)) {
                continue;
            }
            if (!racer->shadowMatrixInit) {
                if (racer->attackState == ATTACK_STATE_SIDE) {
                    temp_fs0 = ((COS(racer->unk_27C) * 0.15f) + 0.85f) * D_800CE750;
                } else {
                    temp_fs0 = D_800CE750;
                }

                Matrix_SetLockedLookAtFromVectors(&gGfxPool->unk_20A88[racer->id], NULL,
                                                  racer->shadowColorStrength * D_800CE748, 0.1f,
                                                  racer->shadowColorStrength * temp_fs0, &racer->modelBasis.x,
                                                  &racer->upFromGround, &racer->shadowPos);
                racer->shadowMatrixInit = true;
            }
            gSPMatrix(gfx++, &D_1000000.unk_20A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                gDPLoadTextureBlock_4b(gfx++, D_800CDC54[racer->shadowType], G_IM_FMT_I, 32, 64, 0,
                                       G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                       G_TX_NOLOD);
                gDPSetPrimColor(gfx++, 0, 0, racer->shadowR, racer->shadowG, racer->shadowB, 200);
                gSPVertex(gfx++, D_800CDBA4[racer->shadowType], 4, 0);
            } else {
                gDPLoadTextureBlock_4b(gfx++, D_70488A8, G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                                       G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);
                gSPVertex(gfx++, D_7048868, 4, 0);
            }
            gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
        }
        if (gGameMode == GAMEMODE_TIME_ATTACK) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);

            for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
                if (!sp4F8->exists) {
                    continue;
                }
                racer = sp4F8->racer;
                if ((racer->unk_2B2 == 0) || (racer->shadowPos.y == -54321.0f)) {
                    continue;
                }
                Matrix_SetLockedLookAtFromVectors(&gGfxPool->unk_20A88[racer->id], NULL, sp4F8->scale * D_800CE748,
                                                  0.1f, sp4F8->scale * D_800CE750, &racer->modelBasis.x,
                                                  &racer->upFromGround, &racer->shadowPos);
                gSPMatrix(gfx++, &D_1000000.unk_20A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPLoadTextureBlock_4b(gfx++, D_800CDC54[racer->shadowType], G_IM_FMT_I, 32, 64, 0,
                                       G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                       G_TX_NOLOD);
                gSPVertex(gfx++, D_800CDBA4[racer->shadowType], 4, 0);
                gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
            }
        }
    } else {
        gRacers[0].speed = gRacers[1].speed = gRacers[2].speed = gRacers[3].speed = 0.0f;
    }

    gSPDisplayList(gfx++, D_303A7D8);

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->attackHighlightScale == 0) {
            continue;
        }
        if (racer->machineLod == 0) {
            continue;
        }
        if (racer->machineLod < 6) {
            if (!racer->attackHighlightMatrixInit) {
                Matrix_ScaleFrom3DMatrix(
                    &gGfxPool->unk_21208[racer->id], NULL, racer->attackHighlightScale * D_800CE748,
                    racer->attackHighlightScale * D_800CE74C, racer->attackHighlightScale * D_800CE750,
                    &racer->modelBasis, &racer->modelPos);
                racer->attackHighlightMatrixInit = true;
            }
            gSPMatrix(gfx++, &D_1000000.unk_21208[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gfx++);
            gDPSetBlendColor(gfx++, racer->attackHighlightR, racer->attackHighlightG, racer->attackHighlightB, 255);

            if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                gSPDisplayList(gfx++, D_800CDDB0[racer->machineIndex * 6 + racer->machineLod - 1]);
            } else {
                gSPDisplayList(gfx++, D_800CE080[racer->machineLod - 1]);
            }
        }
    }
    playerRacer = &gRacers[playerIndex];

    if (playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_FLAG_INSIDE) {
        if (playerRacer->segmentPositionInfo.courseSegment->nextJoinStartTValue <
            playerRacer->segmentPositionInfo.segmentTValue) {
            temp_fs0 = (1.0f - playerRacer->segmentPositionInfo.segmentLengthProportion) /
                       playerRacer->segmentPositionInfo.courseSegment->joinScale;
        } else if (playerRacer->segmentPositionInfo.segmentTValue <
                   playerRacer->segmentPositionInfo.courseSegment->previousJoinEndTValue) {
            temp_fs0 = playerRacer->segmentPositionInfo.segmentLengthProportion /
                       playerRacer->segmentPositionInfo.courseSegment->joinScale;
        } else {
            var_s3 = 50;
            var_s4 = 50;
            sp5C4 = 50;
            goto block_115;
        }
        var_s3 = Math_Round(temp_fs0 * -50.0f) + 100;
        var_s4 = Math_Round(temp_fs0 * -50.0f) + 100;
        sp5C4 = Math_Round(temp_fs0 * -50.0f) + 100;
    } else {
        var_s3 = 100;
        var_s4 = 100;
        sp5C4 = 100;
    }
block_115:
    temp_v0_7 = &gGfxPool->unk_21A88[playerIndex];
    temp_v0_7->a.l.colc[0] = var_s3;
    temp_v0_7->a.l.col[0] = var_s3;
    temp_v0_7->a.l.colc[1] = var_s4;
    temp_v0_7->a.l.col[1] = var_s4;
    temp_v0_7->a.l.colc[2] = sp5C4;
    temp_v0_7->a.l.col[2] = sp5C4;
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_303A5F8);
    } else {
        gSPDisplayList(gfx++, D_303A6A8);
    }

    gSPLight(gfx++, &D_1000000.unk_21A88[playerIndex].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_21A88[playerIndex].a, 2);

    if ((playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_FLAG_INSIDE) &&
        !(playerRacer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        sp560 = playerRacer->segmentBasis.y.x;
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[0] = Math_Round(sp560 * 120.0f);
        sp55C = playerRacer->segmentBasis.y.y;
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[1] = Math_Round(sp55C * 120.0f);
        sp558 = playerRacer->segmentBasis.y.z;
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[2] = Math_Round(sp558 * 120.0f);
        if ((playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_PIPE) {
            var_v0 =
                &sPipeFogColors[playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        } else {
            var_v0 =
                &sTunnelFogColors[playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        }
        var_s3 = var_v0->x;
        sp5C4 = var_v0->y;
        var_s4 = var_v0->z;
    } else {
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[0] = gGfxPool->unk_21A88[playerIndex].l[0].l.dir[1] =
            gGfxPool->unk_21A88[playerIndex].l[0].l.dir[2] = 0x45;
        sp560 = 0.57735f;
        sp55C = 0.57735f;
        sp558 = 0.57735f;
        var_s3 = gCurrentCourseInfo->racerFogColors[0];
        sp5C4 = gCurrentCourseInfo->racerFogColors[1];
        var_s4 = gCurrentCourseInfo->racerFogColors[2];
    }
    if (gGameMode != GAMEMODE_GP_END_CS) {
        gGfxPool->unk_21AE8[playerIndex].l.unk_08[0] = Math_Round((sp560 - camera->basis.x.x) * 16383.0f);
        gGfxPool->unk_21AE8[playerIndex].l.unk_08[1] = Math_Round((sp55C - camera->basis.x.y) * 16383.0f);
        gGfxPool->unk_21AE8[playerIndex].l.unk_08[2] = Math_Round((sp558 - camera->basis.x.z) * 16383.0f);
        gSPDmaRead(gfx++, 0x8B0, D_800CE3D0, ARRAY_COUNT(D_800CE3D0));
        gSPLookAtY(gfx++, &D_1000000.unk_21AE8[playerIndex]);
        gDPSetFogColor(gfx++, var_s3, sp5C4, var_s4, 255);
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->machineLod == 0) {
            continue;
        }
        if (!racer->modelMatrixInit) {
            Matrix_ScaleFrom3DMatrix(&gGfxPool->unk_20308[racer->id], &racer->modelMatrix, D_800CE748, D_800CE74C,
                                     D_800CE750, &racer->modelBasis, &racer->modelPos);
            racer->modelMatrixInit = true;
        }
        if (racer->stateFlags & RACER_STATE_CRASHED) {
            continue;
        }
        gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_800CDD38[racer->machineIndex]);
        gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 255);
        gSPDisplayList(gfx++, D_800CDDB0[racer->machineIndex * 6 + racer->machineLod - 1]);
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_90186C8);
        Light_SetLookAtSource(&gGfxPool->unk_21B28, &camera->viewMtx);
        gSPLookAt(gfx++, &gGfxPool->unk_21B28);
        gSPTexture(gfx++, D_800CE768, D_800CE768, 0, G_TX_RENDERTILE, G_ON);

        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        if (COURSE_CONTEXT()->courseData.skybox == SKYBOX_BLUE) {
            var_s2 = D_9000A10;
        } else {
            var_s2 = D_9000208;
        }

        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, var_s2);
        gDPLoadBlock(gfx++, G_TX_RENDERTILE, 0, 0, 1023, 256);
        gDPTileSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        D_800F809C += ((camera->basis.z.x * gRacers->velocity.x) + (camera->basis.z.y * gRacers->velocity.y) +
                       (camera->basis.z.z * gRacers->velocity.z)) *
                      D_800CE76C;
        var_s7 = (s32) (D_800F809C * 4.0f) & 0xFF;

        D_800F80A0 += ((camera->basis.y.x * gRacers->velocity.x) + (camera->basis.y.y * gRacers->velocity.y) +
                       (camera->basis.y.z * gRacers->velocity.z)) *
                      D_800CE76C;
        sp5C4 = (s32) (D_800F80A0 * 4.0f) & 0xFF;

        gDPSetTileSize(gfx++, G_TX_RENDERTILE, var_s7, sp5C4, sp5C4 + 0xFC, sp5C4 + 0xFC);

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_800CE764);

        for (racer = sLastRacer; racer >= gRacers; racer--) {
            gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gfx = func_8009CEA0(gfx, racer->character);
        }
    }

    var_s7 = 0;
    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->machineLod == 0) {
            continue;
        }
        if (racer->stateFlags & RACER_STATE_CRASHED) {
            if (var_s7 == 0) {
                gSPDisplayList(gfx++, D_7045150);
                var_s7 = 1;
            }
            gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 255);
            gSPDisplayList(gfx++, D_800CE080[racer->machineLod - 1]);
        }
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++,
                         Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL |
                             GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                         Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL |
                             GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (!sp4F8->exists) {
                continue;
            }
            racer = sp4F8->racer;
            if (racer->machineLod == 0) {
                continue;
            }
            Matrix_ScaleFrom3DMatrix(&gGfxPool->unk_20308[racer->id], &racer->modelMatrix, sp4F8->scale * D_800CE748,
                                     sp4F8->scale * D_800CE74C, sp4F8->scale * D_800CE750, &racer->modelBasis,
                                     &racer->modelPos);
            gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gfx++, D_800CDD38[racer->machineIndex]);
            gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 160);
            gSPDisplayList(gfx++, D_800CDDB0[racer->machineIndex * 6 + racer->machineLod - 1]);
        }
    }
    sp560 = camera->basis.z.x;
    sp55C = camera->basis.z.y;
    sp558 = camera->basis.z.z;
    sp56C = camera->basis.y.x;
    sp568 = camera->basis.y.y;
    sp564 = camera->basis.y.z;

    gSPDisplayList(gfx++, aSetupBoosterDL);

    if (!gGamePaused) {
        sp5C4 = gGameFrameCount;
    } else {
        sp5C4 = 1;
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if ((racer->unk_2B3 == 0) || (racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
            continue;
        }

        boosterInfo = &sBoosterInfos[racer->boostersType];

        var_s3 = (3 - (sp5C4 & 3)) << 1;
        if (var_s3 < racer->unk_214) {
            var_s3 = racer->unk_214;
        }
        sp574 = var_s3 * 0.2f;

        // Boost color
        temp_fs0 = (f32) racer->boostTimer / sInitialBoostTimer;
        if (temp_fs0 != 0) {
            sp574 += (7.5f * sqrtf(temp_fs0));
            if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
                gDPSetEnvColor(gfx++, 255, 223, 0, 255);
            } else {
                gDPSetEnvColor(gfx++, 91, 255, 91, 255);
            }
        } else {
            gDPSetEnvColor(gfx++, 0, 255, 255, 255);
        }

        sp570 = (racer->unk_17C - D_800F80A4) / (13.0f - D_800F80A4);

        for (var_s7 = boosterInfo->count - 1; var_s7 >= 0; var_s7--) {
            boosterPos = &boosterInfo->pos[var_s7];

            temp_fs0 = boosterInfo->size[var_s7] * 0.35f;

            temp_fs4 = ((racer->modelMatrix.m[0][0] * boosterPos->x) + (racer->modelMatrix.m[1][0] * boosterPos->y) +
                        (racer->modelMatrix.m[2][0] * (boosterPos->z - (temp_fs0 * 3.6f)))) +
                       racer->modelMatrix.m[3][0];
            temp_fs5 = ((racer->modelMatrix.m[0][1] * boosterPos->x) + (racer->modelMatrix.m[1][1] * boosterPos->y) +
                        (racer->modelMatrix.m[2][1] * (boosterPos->z - (temp_fs0 * 3.6f)))) +
                       racer->modelMatrix.m[3][1];
            sp54C = ((racer->modelMatrix.m[0][2] * boosterPos->x) + (racer->modelMatrix.m[1][2] * boosterPos->y) +
                     (racer->modelMatrix.m[2][2] * (boosterPos->z - (temp_fs0 * 3.6f)))) +
                    racer->modelMatrix.m[3][2];

            temp_fs0 += sp574;
            temp_fs0 *= sp570;
            temp_fs1 = temp_fs0 * sp56C;
            gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            temp_fs2 = temp_fs0 * sp568;
            gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
            temp_fs3 = temp_fs0 * sp564;
            gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + temp_fs3);

            gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
            gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
            temp_fs1 = temp_fs0 * sp560;
            gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            temp_fs2 = temp_fs0 * sp55C;
            gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
            temp_fs3 = temp_fs0 * sp558;
            gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
            gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
            gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
            gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                gEffectsVtxPtr[2].v.tc[1] = 0;
            gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                gEffectsVtxPtr[3].v.tc[1] = 0x3FF;
            if (racer->unk_2B3 == 2) {
                temp_fs0 = racer->speed * 0.9f;
                gEffectsVtxPtr[4].v.ob[0] = Math_Round(temp_fs4 - (racer->modelBasis.x.x * temp_fs0));
                gEffectsVtxPtr[4].v.ob[1] = Math_Round(temp_fs5 - (racer->modelBasis.x.y * temp_fs0));
                gEffectsVtxPtr[4].v.ob[2] = Math_Round(sp54C - (racer->modelBasis.x.z * temp_fs0));
                gEffectsVtxPtr[4].v.tc[0] = 0x3FF;
                gEffectsVtxPtr[4].v.tc[1] = 0;
                gEffectsVtxPtr += 5;
            } else {
                gEffectsVtxPtr += 4;
            }
        }
        if (racer->unk_2B3 == 2) {
            var_s7 = boosterInfo->count * 5;
            gSPVertex(gfx++, gEffectsVtxPtr - var_s7, var_s7, 0);

            switch (boosterInfo->count) {
                case 4:
                    gSP2Triangles(gfx++, 16, 17, 18, 0, 15, 16, 18, 0);
                    gSP2Triangles(gfx++, 10, 11, 13, 0, 16, 19, 18, 0);
                    gSP2Triangles(gfx++, 11, 14, 13, 0, 11, 12, 13, 0);
                /* fallthrough */
                case 2:
                    gSP2Triangles(gfx++, 6, 7, 8, 0, 5, 6, 8, 0);
                    gSP2Triangles(gfx++, 0, 1, 3, 0, 6, 9, 8, 0);
                    gSP2Triangles(gfx++, 1, 4, 3, 0, 1, 2, 3, 0);
                    break;
                case 3:
                    gSP2Triangles(gfx++, 11, 12, 13, 0, 10, 11, 13, 0);
                    gSP2Triangles(gfx++, 5, 6, 8, 0, 11, 14, 13, 0);
                    gSP2Triangles(gfx++, 6, 9, 8, 0, 6, 7, 8, 0);
                /* fallthrough */
                case 1:
                    gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                    gSP1Triangle(gfx++, 1, 4, 3, 0);
                    break;
            }

        } else {
            var_s7 = boosterInfo->count * 4;
            gSPVertex(gfx++, gEffectsVtxPtr - var_s7, var_s7, 0);

            switch (boosterInfo->count) {
                case 4:
                    gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 13, 15, 0);
                /* fallthrough */
                case 3:
                    gSP2Triangles(gfx++, 9, 10, 11, 0, 8, 9, 11, 0);
                /* fallthrough */
                case 2:
                    gSP2Triangles(gfx++, 5, 6, 7, 0, 4, 5, 7, 0);
                /* fallthrough */
                case 1:
                    gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                    break;
            }
        }
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetEnvColor(gfx++, 255, 0, 255, 160);

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (!sp4F8->exists) {
                continue;
            }
            racer = sp4F8->racer;
            if (racer->unk_2B3 == 0) {
                continue;
            }
            boosterInfo = &sBoosterInfos[racer->boostersType];

            sp574 = (f32) ((3 - (sp5C4 & 3)) << 1) * 0.2f;
            for (var_s7 = boosterInfo->count - 1; var_s7 >= 0; var_s7--) {
                boosterPos = &boosterInfo->pos[var_s7];

                temp_fs0 = boosterInfo->size[var_s7] * 0.35f;
                temp_fs4 =
                    ((racer->modelMatrix.m[0][0] * boosterPos->x) + (racer->modelMatrix.m[1][0] * boosterPos->y) +
                     (racer->modelMatrix.m[2][0] * (boosterPos->z - (temp_fs0 * 3.6f)))) +
                    racer->modelMatrix.m[3][0];
                temp_fs5 =
                    ((racer->modelMatrix.m[0][1] * boosterPos->x) + (racer->modelMatrix.m[1][1] * boosterPos->y) +
                     (racer->modelMatrix.m[2][1] * (boosterPos->z - (temp_fs0 * 3.6f)))) +
                    racer->modelMatrix.m[3][1];
                sp54C = ((racer->modelMatrix.m[0][2] * boosterPos->x) + (racer->modelMatrix.m[1][2] * boosterPos->y) +
                         (racer->modelMatrix.m[2][2] * (boosterPos->z - (temp_fs0 * 3.6f)))) +
                        racer->modelMatrix.m[3][2];

                temp_fs0 += sp574;

                temp_fs1 = temp_fs0 * sp56C;
                gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0 * sp568;
                gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0 * sp564;
                gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + temp_fs3);
                gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs3);

                temp_fs1 = temp_fs0 * sp560;
                gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0 * sp55C;
                gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0 * sp558;
                gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
                gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                    gEffectsVtxPtr[2].v.tc[1] = 0;
                gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                    gEffectsVtxPtr[3].v.tc[1] = 0x3FF;
                if (racer->unk_2B3 == 2) {
                    temp_fs0 = racer->speed * 0.9f;
                    gEffectsVtxPtr[4].v.ob[0] = Math_Round(temp_fs4 - (racer->modelBasis.x.x * temp_fs0));
                    gEffectsVtxPtr[4].v.ob[1] = Math_Round(temp_fs5 - (racer->modelBasis.x.y * temp_fs0));
                    gEffectsVtxPtr[4].v.ob[2] = Math_Round(sp54C - (racer->modelBasis.x.z * temp_fs0));
                    gEffectsVtxPtr[4].v.tc[0] = 0x3FF;
                    gEffectsVtxPtr[4].v.tc[1] = 0;
                    gEffectsVtxPtr += 5;
                } else {
                    gEffectsVtxPtr += 4;
                }
            }
            if (racer->unk_2B3 == 2) {
                var_s7 = boosterInfo->count * 5;
                gSPVertex(gfx++, gEffectsVtxPtr - var_s7, var_s7, 0);

                switch (boosterInfo->count) {
                    case 4:
                        gSP2Triangles(gfx++, 16, 17, 18, 0, 15, 16, 18, 0);
                        gSP2Triangles(gfx++, 10, 11, 13, 0, 16, 19, 18, 0);
                        gSP2Triangles(gfx++, 11, 14, 13, 0, 11, 12, 13, 0);
                    /* fallthrough */
                    case 2:
                        gSP2Triangles(gfx++, 6, 7, 8, 0, 5, 6, 8, 0);
                        gSP2Triangles(gfx++, 0, 1, 3, 0, 6, 9, 8, 0);
                        gSP2Triangles(gfx++, 1, 4, 3, 0, 1, 2, 3, 0);
                        break;
                    case 3:
                        gSP2Triangles(gfx++, 11, 12, 13, 0, 10, 11, 13, 0);
                        gSP2Triangles(gfx++, 5, 6, 8, 0, 11, 14, 13, 0);
                        gSP2Triangles(gfx++, 6, 9, 8, 0, 6, 7, 8, 0);
                    /* fallthrough */
                    case 1:
                        gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                        gSP1Triangle(gfx++, 1, 4, 3, 0);
                        break;
                }
            } else {
                var_s7 = boosterInfo->count * 4;
                gSPVertex(gfx++, gEffectsVtxPtr - var_s7, var_s7, 0);

                switch (boosterInfo->count) {
                    case 4:
                        gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 13, 15, 0);
                    /* fallthrough */
                    case 3:
                        gSP2Triangles(gfx++, 9, 10, 11, 0, 8, 9, 11, 0);
                    /* fallthrough */
                    case 2:
                        gSP2Triangles(gfx++, 5, 6, 7, 0, 4, 5, 7, 0);
                    /* fallthrough */
                    case 1:
                        gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                        break;
                }
            }
        }
    }
    gSPDisplayList(gfx++, D_4007FB8);

    for (var_s3 = gExplosions1Count, var_s7 = (gExplosions1Index - 1) & 0x1F;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 3)); var_s7 = (var_s7 - 1) & 0x1F, var_s3--) {
        temp_s1 = &gExplosions1[var_s7];

        temp_fs1 = temp_s1->scale * sp56C;
        temp_fs3 = temp_s1->scale * sp568;
        temp_fs2 = temp_s1->scale * sp564;
        sp53C = temp_s1->scale * sp560;
        sp538 = temp_s1->scale * sp55C;
        sp534 = temp_s1->scale * sp558;

        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_s1->pos.x + temp_fs1);
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_s1->pos.y + temp_fs3);
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(temp_s1->pos.z + temp_fs2);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_s1->pos.x - temp_fs1);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_s1->pos.y - temp_fs3);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(temp_s1->pos.z - temp_fs2);
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_s1->pos.x + sp53C);
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_s1->pos.y + sp538);
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(temp_s1->pos.z + sp534);
        gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_s1->pos.x - sp53C);
        gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_s1->pos.y - sp538);
        gEffectsVtxPtr[3].v.ob[2] = Math_Round(temp_s1->pos.z - sp534);

        gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] = gEffectsVtxPtr[2].v.tc[1] =
            0;
        gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] = gEffectsVtxPtr[3].v.tc[1] =
            0x7FF;

        gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
        gDPPipeSync(gfx++);

        if (temp_s1->timer < 8) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->timer * 16), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->timer * 32), 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->timer * 16), 255);
            gDPSetEnvColor(gfx++, 0x1FF - (temp_s1->timer * 32), 0, 0, 0x17F - (temp_s1->timer * 16));
        }

        gDPLoadTextureBlock(gfx++, D_800CDAB8[temp_s1->timer >> 1], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        gEffectsVtxPtr += 4;
    }

    for (var_s3 = gExplosions2Count, var_s7 = (gExplosions2Index - 1) & 7;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 3)); var_s7 = (var_s7 - 1) & 7, var_s3--) {
        temp_s1 = &gExplosions2[var_s7];
        temp_fs1 = temp_s1->scale * sp56C;
        temp_fs3 = temp_s1->scale * sp568;
        temp_fs2 = temp_s1->scale * sp564;
        sp53C = temp_s1->scale * sp560;
        sp538 = temp_s1->scale * sp55C;
        sp534 = temp_s1->scale * sp558;

        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_s1->pos.x + temp_fs1);
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_s1->pos.y + temp_fs3);
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(temp_s1->pos.z + temp_fs2);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_s1->pos.x - temp_fs1);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_s1->pos.y - temp_fs3);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(temp_s1->pos.z - temp_fs2);
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_s1->pos.x + sp53C);
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_s1->pos.y + sp538);
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(temp_s1->pos.z + sp534);
        gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_s1->pos.x - sp53C);
        gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_s1->pos.y - sp538);
        gEffectsVtxPtr[3].v.ob[2] = Math_Round(temp_s1->pos.z - sp534);

        gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] = gEffectsVtxPtr[2].v.tc[1] =
            0;
        gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] = gEffectsVtxPtr[3].v.tc[1] =
            0x7FF;

        gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
        gDPPipeSync(gfx++);

        if (temp_s1->timer < 16) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->timer * 8), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->timer * 16), 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->timer * 8), 255);
            gDPSetEnvColor(gfx++, 511 - (temp_s1->timer * 16), 0, 0, 383 - (temp_s1->timer * 8));
        }

        gDPLoadTextureBlock(gfx++, D_800CDAB8[temp_s1->timer >> 2], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        gEffectsVtxPtr += 4;
    }

    gSPDisplayList(gfx++, D_4007FD8);

    for (var_s3 = gMachineDebrisCount, var_s7 = (gMachineDebrisIndex - 1) & 0x7F;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 2)); var_s7 = (var_s7 - 1) & 0x7F, var_s3--) {
        machineDebris = &gMachineDebris[var_s7];
        gEffectsVtxPtr[0].v.ob[0] = machineDebris->cornerPos1.x;
        gEffectsVtxPtr[0].v.ob[1] = machineDebris->cornerPos1.y;
        gEffectsVtxPtr[0].v.ob[2] = machineDebris->cornerPos1.z;
        gEffectsVtxPtr[1].v.ob[0] = machineDebris->cornerPos2.x;
        gEffectsVtxPtr[1].v.ob[1] = machineDebris->cornerPos2.y;
        gEffectsVtxPtr[1].v.ob[2] = machineDebris->cornerPos2.z;
        gEffectsVtxPtr[2].v.ob[0] = machineDebris->cornerPos3.x;
        gEffectsVtxPtr[2].v.ob[1] = machineDebris->cornerPos3.y;
        gEffectsVtxPtr[2].v.ob[2] = machineDebris->cornerPos3.z;
        gEffectsVtxPtr[0].v.cn[0] = machineDebris->red;
        gEffectsVtxPtr[0].v.cn[1] = machineDebris->green;
        gEffectsVtxPtr[0].v.cn[2] = machineDebris->blue;
        gEffectsVtxPtr[0].v.cn[3] = machineDebris->alpha;
        gSPVertex(gfx++, gEffectsVtxPtr, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gEffectsVtxPtr += 3;
    }

    gSPDisplayList(gfx++, D_4008000);

    for (var_s3 = gFlyingSparksCount, var_s7 = (gFlyingSparksIndex - 1) & 0x1F;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 2)); var_s7 = (var_s7 - 1) & 0x1F, var_s3--) {
        flyingSpark = &gFlyingSparks[var_s7];
        gEffectsVtxPtr[0].v.ob[0] = Math_Round(flyingSpark->pos.x - (3.0f * flyingSpark->velocity.x));
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(flyingSpark->pos.y - (3.0f * flyingSpark->velocity.y));
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(flyingSpark->pos.z - (3.0f * flyingSpark->velocity.z));
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(flyingSpark->pos.x + flyingSpark->basis.z.x);
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(flyingSpark->pos.y + flyingSpark->basis.z.y);
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(flyingSpark->pos.z + flyingSpark->basis.z.z);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(flyingSpark->pos.x - flyingSpark->basis.z.x);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(flyingSpark->pos.y - flyingSpark->basis.z.y);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(flyingSpark->pos.z - flyingSpark->basis.z.z);

        gEffectsVtxPtr[0].v.cn[0] = 0xFF;
        gEffectsVtxPtr[0].v.cn[1] = gEffectsVtxPtr[0].v.cn[2] = 0;
        gEffectsVtxPtr[0].v.cn[3] = 0;
        gEffectsVtxPtr[1].v.cn[0] = gEffectsVtxPtr[2].v.cn[0] = gEffectsVtxPtr[1].v.cn[1] = gEffectsVtxPtr[2].v.cn[1] =
            0xFF;
        gEffectsVtxPtr[1].v.cn[2] = gEffectsVtxPtr[2].v.cn[2] = 0;
        gEffectsVtxPtr[1].v.cn[3] = gEffectsVtxPtr[2].v.cn[3] = 0xFF;
        gSPVertex(gfx++, gEffectsVtxPtr, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);
        gEffectsVtxPtr += 3;
    }

    gSPDisplayList(gfx++, D_4008028);

    for (var_s3 = gCollisionSparkCount, var_s7 = (gCollisionSparkIndex - 1) & 0x1F;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 3)); var_s7 = (var_s7 - 1) & 0x1F, var_s3--) {
        temp_s1 = &gCollisionSparks[var_s7];
        if (temp_s1->racer->unk_2B3 == 0) {
            continue;
        }

        sp5C4 = temp_s1->timer - 1;
        sp574 = SQ(sp5C4) * -0.15f;
        temp_fs4 = temp_s1->pos.x + (sp574 * temp_s1->racer->trueBasis.y.x);
        temp_fs5 = temp_s1->pos.y + (sp574 * temp_s1->racer->trueBasis.y.y);
        sp54C = temp_s1->pos.z + (sp574 * temp_s1->racer->trueBasis.y.z);

        temp_fs1 = temp_s1->scale * sp56C;
        temp_fs3 = temp_s1->scale * sp568;
        temp_fs2 = temp_s1->scale * sp564;
        sp53C = temp_s1->scale * sp560;
        sp538 = temp_s1->scale * sp55C;
        sp534 = temp_s1->scale * sp558;

        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + sp53C);
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + sp538);
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + sp534);
        gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - sp53C);
        gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - sp538);
        gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - sp534);
        gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] = gEffectsVtxPtr[2].v.tc[1] =
            0;
        gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] = gEffectsVtxPtr[3].v.tc[1] =
            0x7FF;

        gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1->timer >> 1, G_ON);
        gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->timer * 8), 255);
        gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->timer * 16), 0, 255 - (temp_s1->timer * 4));
        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
        gEffectsVtxPtr += 4;
    }

    gSPDisplayList(gfx++, D_4008130);

    for (var_s3 = gSmokesCount, var_s7 = (gSmokesIndex - 1) & 0x1F;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 3)); var_s7 = (var_s7 - 1) & 0x1F, var_s3--) {
        temp_s1 = &gSmokes[var_s7];
        if (temp_s1->racer->unk_2B3 == 0) {
            continue;
        }

        temp_fs1 = temp_s1->scale * sp56C;
        temp_fs3 = temp_s1->scale * sp568;
        temp_fs2 = temp_s1->scale * sp564;
        sp53C = temp_s1->scale * sp560;
        sp538 = temp_s1->scale * sp55C;
        sp534 = temp_s1->scale * sp558;
        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_s1->pos.x + temp_fs1);
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_s1->pos.y + temp_fs3);
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(temp_s1->pos.z + temp_fs2);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_s1->pos.x - temp_fs1);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_s1->pos.y - temp_fs3);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(temp_s1->pos.z - temp_fs2);
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_s1->pos.x + sp53C);
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_s1->pos.y + sp538);
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(temp_s1->pos.z + sp534);
        gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_s1->pos.x - sp53C);
        gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_s1->pos.y - sp538);
        gEffectsVtxPtr[3].v.ob[2] = Math_Round(temp_s1->pos.z - sp534);
        gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] = gEffectsVtxPtr[2].v.tc[1] =
            0;
        gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] = gEffectsVtxPtr[3].v.tc[1] =
            0x7FF;
        gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1->timer >> 2, G_ON);
        gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
        gDPPipeSync(gfx++);
        gDPSetEnvColor(gfx++, 180, 150, 100, 230 - (temp_s1->timer * 4));
        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
        gEffectsVtxPtr += 4;
    }

    gSPDisplayList(gfx++, aSetupPitForceFieldDL);

    if (!gGamePaused) {
        var_s3 = gGameFrameCount & 7;
    } else {
        var_s3 = 0;
    }

    for (racer = sLastRacer; (racer >= gRacers) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 3)); racer--) {
        if ((racer->pitForceFieldSize == 0.0f) || (racer->unk_2B3 == 0)) {
            continue;
        }
        temp_fs0 = 3.0f - ((1.0f - racer->pitForceFieldSize) * 19.0f);
        temp_fs4 = racer->segmentPositionInfo.pos.x + (temp_fs0 * racer->trueBasis.y.x);
        temp_fs5 = racer->segmentPositionInfo.pos.y + (temp_fs0 * racer->trueBasis.y.y);
        sp54C = racer->segmentPositionInfo.pos.z + (temp_fs0 * racer->trueBasis.y.z);
        temp_fs0 = racer->pitForceFieldSize * 38.0f;
        temp_fs1 = temp_fs0 * sp56C;
        temp_fs3 = temp_fs0 * sp568;
        temp_fs2 = temp_fs0 * sp564;
        temp_fs0 = racer->pitForceFieldSize * 40.0f;
        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
        temp_fs1 = temp_fs0 * sp560;
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
        temp_fs2 = temp_fs0 * sp55C;
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
        temp_fs3 = temp_fs0 * sp558;
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
        gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
        gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
        gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
        gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] = gEffectsVtxPtr[3].v.tc[1] = gEffectsVtxPtr[0].v.tc[1] =
            0x20;
        gEffectsVtxPtr[2].v.tc[1] = gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
            0x7E0;
        gSPTexture(gfx++, 0x8000, 0x8000, 0, var_s3, G_ON);
        gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
        gEffectsVtxPtr += 4;
    }

    gSPDisplayList(gfx++, aSetupFallExplosionDL);

    for (var_s3 = gFallExplosionsCount, var_s7 = (gFallExplosionsIndex - 1) & 0x1F;
         (var_s3 != 0) && (gEffectsVtxPtr <= (gEffectsVtxEndPtr - 7)); var_s7 = (var_s7 - 1) & 0x1F, var_s3--) {
        fallExplosion = &gFallExplosions[var_s7];
        racer = fallExplosion->racer;
        var_s4 = fallExplosion->timer - 5;
        if (fallExplosion->timer == 0) {
            continue;
        }

        if ((var_s4 >= 0) && (var_s4 < 60)) {
            if (gEffectsVtxPtr > (gEffectsVtxEndPtr - 3)) {
                break;
            }

            temp_fs0 = SIN(((s32) (var_s4 << 10) / 60)) * 163.64f;

            if (var_s4 < 20) {
                sp5C4 = 255;
            } else {
                sp5C4 = (s32) ((60 - var_s4) * 255) / 40;
            }

            temp_fs0 *= fallExplosion->scale;
            temp_fs1 = temp_fs0 * sp56C;
            gEffectsVtxPtr[0].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x + temp_fs1);
            temp_fs2 = temp_fs0 * sp568;
            gEffectsVtxPtr[0].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y + temp_fs2);
            temp_fs3 = temp_fs0 * sp564;
            gEffectsVtxPtr[0].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z + temp_fs3);
            gEffectsVtxPtr[2].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x - temp_fs1);
            gEffectsVtxPtr[2].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y - temp_fs2);
            gEffectsVtxPtr[2].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z - temp_fs3);
            temp_fs1 = temp_fs0 * sp560;
            gEffectsVtxPtr[1].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x + temp_fs1);
            temp_fs2 = temp_fs0 * sp55C;
            gEffectsVtxPtr[1].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y + temp_fs2);
            temp_fs3 = temp_fs0 * sp558;
            gEffectsVtxPtr[1].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z + temp_fs3);
            gEffectsVtxPtr[3].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x - temp_fs1);
            gEffectsVtxPtr[3].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y - temp_fs2);
            gEffectsVtxPtr[3].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z - temp_fs3);
            gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                gEffectsVtxPtr[2].v.tc[1] = 0x40;
            gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                gEffectsVtxPtr[3].v.tc[1] = 0x1FBF;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, 0, G_ON);
            gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, sp5C4, 80, 255);
            gDPSetEnvColor(gfx++, sp5C4, 0, 0, sp5C4);
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            gEffectsVtxPtr += 4;
        }

        if (fallExplosion->timer < 26) {
            if (gEffectsVtxPtr > (gEffectsVtxEndPtr - 3)) {
                break;
            }
            temp_fs0 = (fallExplosion->scale * 163.64f * (f32) fallExplosion->timer) / 26.0f;
            temp_fs1 = racer->trueBasis.x.x * temp_fs0;
            temp_fs3 = racer->trueBasis.x.y * temp_fs0;
            temp_fs2 = racer->trueBasis.x.z * temp_fs0;
            sp53C = racer->trueBasis.z.x * temp_fs0;
            sp538 = racer->trueBasis.z.y * temp_fs0;
            sp534 = racer->trueBasis.z.z * temp_fs0;
            gEffectsVtxPtr[0].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x + temp_fs1);
            gEffectsVtxPtr[0].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y + temp_fs3);
            gEffectsVtxPtr[0].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z + temp_fs2);
            gEffectsVtxPtr[2].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x - temp_fs1);
            gEffectsVtxPtr[2].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y - temp_fs3);
            gEffectsVtxPtr[2].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z - temp_fs2);
            gEffectsVtxPtr[1].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x + sp53C);
            gEffectsVtxPtr[1].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y + sp538);
            gEffectsVtxPtr[1].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z + sp534);
            gEffectsVtxPtr[3].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x - sp53C);
            gEffectsVtxPtr[3].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y - sp538);
            gEffectsVtxPtr[3].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z - sp534);
            gEffectsVtxPtr[2].v.tc[1] = 0x40;

            gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                gEffectsVtxPtr[2].v.tc[1];
            gEffectsVtxPtr[3].v.tc[1] = 0x1FBF;
            gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                gEffectsVtxPtr[3].v.tc[1];
            gSPTexture(gfx++, 0x8000, 0x8000, 0, 1, G_ON);
            gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 100, 255, 255, 255);
            gDPSetEnvColor(gfx++, 0, 0, 255, (((26 - fallExplosion->timer) * 255) / 26));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            gEffectsVtxPtr += 4;
        }
    }

#ifndef EXPANSION_KIT
    if (gRaceIntroTimer != 0) {
#else
    if (gRaceIntroTimer != 0 && gGameMode != GAMEMODE_COURSE_EDIT) {
#endif
        gSPDisplayList(gfx++, D_400A258);

        gSPMatrix(gfx++, &D_1000000.unk_21988[playerIndex], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPDisplayList(gfx++, aCountdownSignDL);

        if (((gRaceIntroTimer <= 220) && (gRaceIntroTimer >= 210)) ||
            ((gRaceIntroTimer <= 160) && (gRaceIntroTimer >= 150)) ||
            ((gRaceIntroTimer <= 100) && (gRaceIntroTimer >= 90)) || (gRaceIntroTimer <= 40)) {
            var_s2 = aCountdownMrZeroMouthOpenTex;
        } else {
            var_s2 = aCountdownMrZeroMouthClosedTex;
        }

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                            G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        gSPDisplayList(gfx++, D_400A480);

        if (gRaceIntroTimer > 220) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        } else {
            if (gRaceIntroTimer > 160) {
                var_s2 = aCountdown3Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 220)) {
                    Audio_TriggerSystemSE(NA_SE_47);
                }
            } else if (gRaceIntroTimer > 100) {
                var_s2 = aCountdown2Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 160)) {
                    Audio_TriggerSystemSE(NA_SE_9);
                }
            } else if (gRaceIntroTimer > 40) {
                var_s2 = aCountdown1Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 100)) {
                    Audio_TriggerSystemSE(NA_SE_10);
                }
            } else {
                var_s2 = aCountdownGoTex;
                if ((playerIndex == 0) && (!gGamePaused)) {
                    if (gRaceIntroTimer == 40) {
                        Audio_TriggerSystemSE(NA_SE_11);
                    }
                    if ((gRaceIntroTimer == 1) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
                        if (gCurrentCourseInfo->courseIndex < COURSE_EDIT_1) {
                            func_8007E0AC(D_800CF4D8[gCurrentCourseInfo->courseIndex]);
                        } else if (gCurrentCourseInfo->courseIndex == COURSE_DEATH_RACE) {
                            func_8007E0AC(BGM_DEATHRACE2);
                        } else {
#ifndef EXPANSION_KIT
                            func_8007E0AC(D_800CF4F0[COURSE_CONTEXT()->courseData.venue]);
#else
                            func_8007E0AC(Course_GetBgm());
#endif
                        }
                    }
                }
            }

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                                G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        }
        gSPVertex(gfx++, D_400AA28, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    } else if ((gTotalRacers >= 2) && !(playerRacer->stateFlags & (RACER_STATE_FINISHED | RACER_STATE_RETIRED)) &&
               (gGameMode != GAMEMODE_GP_END_CS)) {
        gSPDisplayList(gfx++, D_4007EA8);
#ifndef EXPANSION_KIT
        if ((gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_DEATH_RACE)) {
#else

        if ((gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_COURSE_EDIT)) {
#endif
            if (gTotalRacers < 3) {
                var_s4 = gTotalRacers;
            } else {
                var_s4 = 3;
            }

            for (var_s3 = 0; var_s3 < var_s4; var_s3++) {

                racer = gRacersByPosition[var_s3];
                if (racer->machineLod == 0) {
                    continue;
                }
                if ((playerIndex == racer->id) || (racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED))) {
                    continue;
                }
                if (racer->id < playerIndex) {
                    var_s7 = ((s32) ((playerIndex - 1) * playerIndex) >> 1) + racer->id;
                } else {
                    var_s7 = ((s32) (racer->id * (racer->id - 1)) >> 1) + playerIndex;
                }

                if ((sRacerPairInfo[var_s7].trailToLeadDistance < 800.0f)) {
                    continue;
                }

                temp_fs4 = racer->segmentPositionInfo.pos.x + (20.0f * racer->trueBasis.y.x);
                temp_fs5 = racer->segmentPositionInfo.pos.y + (20.0f * racer->trueBasis.y.y);
                sp54C = racer->segmentPositionInfo.pos.z + (20.0f * racer->trueBasis.y.z);
                sp574 = 1.0f / (((camera->projectionViewMtx.m[0][3] * temp_fs4) +
                                 (camera->projectionViewMtx.m[1][3] * temp_fs5) +
                                 (camera->projectionViewMtx.m[2][3] * sp54C)) +
                                camera->projectionViewMtx.m[3][3]);
                sp56C =
                    (((camera->projectionViewMtx.m[0][0] * temp_fs4) + (camera->projectionViewMtx.m[1][0] * temp_fs5) +
                      (camera->projectionViewMtx.m[2][0] * sp54C)) +
                     camera->projectionViewMtx.m[3][0]) *
                    sp574;
                sp568 =
                    (((camera->projectionViewMtx.m[0][1] * temp_fs4) + (camera->projectionViewMtx.m[1][1] * temp_fs5) +
                      (camera->projectionViewMtx.m[2][1] * sp54C)) +
                     camera->projectionViewMtx.m[3][1]) *
                    sp574;
                sp564 =
                    (((camera->projectionViewMtx.m[0][2] * temp_fs4) + (camera->projectionViewMtx.m[1][2] * temp_fs5) +
                      (camera->projectionViewMtx.m[2][2] * sp54C)) +
                     camera->projectionViewMtx.m[3][2]) *
                    sp574;
                gDPPipeSync(gfx++);
                gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);

                if (gNumPlayers < 2) {
                    gDPLoadTextureBlock(gfx++, sPosition1PMarkerTexs[var_s3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 30, 0,
                                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                        G_TX_NOLOD, G_TX_NOLOD);

                    var_s7 = ((s32) ((camera->currentVpScaleX * sp56C) + camera->currentVpTransX + 0.5f) - 12) << 2;
                    sp5C4 = ((s32) ((-camera->currentVpScaleY * sp568) + camera->currentVpTransY + 0.5f) - 30) << 2;
                    gSPScisTextureRectangle(gfx++, var_s7, sp5C4, var_s7 + (24 * 4 - 1), sp5C4 + (30 * 4 - 1), 0, 0, 0,
                                            1 << 10, 1 << 10);
                } else {
                    gDPLoadTextureBlock(gfx++, sPositionMPMarkerTexs[var_s3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                        G_TX_NOLOD, G_TX_NOLOD);

                    var_s7 = ((s32) ((camera->currentVpScaleX * sp56C) + camera->currentVpTransX + 0.5f) - 8) << 2;
                    sp5C4 = ((s32) ((-camera->currentVpScaleY * sp568) + camera->currentVpTransY + 0.5f) - 16) << 2;
                    gSPScisTextureRectangle(gfx++, var_s7, sp5C4, var_s7 + (16 * 4 - 1), sp5C4 + (16 * 4 - 1), 0, 0, 0,
                                            1 << 10, 1 << 10);
                }
            }

            // FAKE
            if (1) {}

            if ((gGameMode == GAMEMODE_GP_RACE) && (sRivalRacer != NULL) && (sRivalRacer->machineLod != 0) &&
                !(sRivalRacer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED)) &&
                (gRacers[0].position >= sRivalRacer->position)) {
                temp_fs4 = sRivalRacer->segmentPositionInfo.pos.x + (20.0f * sRivalRacer->trueBasis.y.x);
                temp_fs5 = sRivalRacer->segmentPositionInfo.pos.y + (20.0f * sRivalRacer->trueBasis.y.y);
                sp54C = sRivalRacer->segmentPositionInfo.pos.z + (20.0f * sRivalRacer->trueBasis.y.z);
                sp574 = 1.0f / (((camera->projectionViewMtx.m[0][3] * temp_fs4) +
                                 (camera->projectionViewMtx.m[1][3] * temp_fs5) +
                                 (camera->projectionViewMtx.m[2][3] * sp54C)) +
                                camera->projectionViewMtx.m[3][3]);
                sp56C =
                    (((camera->projectionViewMtx.m[0][0] * temp_fs4) + (camera->projectionViewMtx.m[1][0] * temp_fs5) +
                      (camera->projectionViewMtx.m[2][0] * sp54C)) +
                     camera->projectionViewMtx.m[3][0]) *
                    sp574;
                sp568 =
                    (((camera->projectionViewMtx.m[0][1] * temp_fs4) + (camera->projectionViewMtx.m[1][1] * temp_fs5) +
                      (camera->projectionViewMtx.m[2][1] * sp54C)) +
                     camera->projectionViewMtx.m[3][1]) *
                    sp574;
                sp564 =
                    (((camera->projectionViewMtx.m[0][2] * temp_fs4) + (camera->projectionViewMtx.m[1][2] * temp_fs5) +
                      (camera->projectionViewMtx.m[2][2] * sp54C)) +
                     camera->projectionViewMtx.m[3][2]) *
                    sp574;
                gDPPipeSync(gfx++);
                gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);
                gDPLoadTextureBlock(gfx++, aRivalMarkerTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                var_s7 = ((s32) ((camera->currentVpScaleX * sp56C) + camera->currentVpTransX + 0.5f) - 0x10) << 2;
                sp5C4 = ((s32) ((-camera->currentVpScaleY * sp568) + camera->currentVpTransY + 0.5f) - 0x10) << 2;
                gSPScisTextureRectangle(gfx++, var_s7, sp5C4, var_s7 + (32 * 4 - 1), sp5C4 + (16 * 4 - 1), 0, 0, 0,
                                        1 << 10, 1 << 10);
            }
            gDPPipeSync(gfx++);
        }

        gDPSetDepthSource(gfx++, G_ZS_PIXEL);

        if (playerRacer->distanceFromRacerBehind < 3000.0f) {
            do {
                if ((playerRacer->position != playerRacer->racerBehind->position - 1) ||
                    (playerRacer->racerBehind->stateFlags & RACER_STATE_RETIRED)) {
                    break;
                }
                sp56C = playerRacer->segmentPositionInfo.pos.x - playerRacer->racerBehind->segmentPositionInfo.pos.x;
                sp568 = playerRacer->segmentPositionInfo.pos.y - playerRacer->racerBehind->segmentPositionInfo.pos.y;
                sp564 = playerRacer->segmentPositionInfo.pos.z - playerRacer->racerBehind->segmentPositionInfo.pos.z;
                temp_fs2 = (sp56C * camera->basis.x.x) + (sp568 * camera->basis.x.y) + (sp564 * camera->basis.x.z);
                if (temp_fs2 < 0.0f) {
                    break;
                }
                temp_fs1 = (sp56C * camera->basis.z.x) + (sp568 * camera->basis.z.y) + (sp564 * camera->basis.z.z);
                temp_fs3 = (sp56C * camera->basis.y.x) + (sp568 * camera->basis.y.y) + (sp564 * camera->basis.y.z);
                temp_fv0 = SQ(temp_fs1) + SQ(temp_fs3);

                if ((temp_fv0 < 0.1f)) {
                    break;
                }
                sp56C = ((camera->currentScissorRight - camera->currentScissorLeft) * 0.5f) + 4.0f;
                sp568 = ((camera->currentScissorBottom - camera->currentScissorTop) * 0.5f) - 4.0f;
                temp_fv0 = sqrtf((SQ(sp56C) + SQ(sp568)) / temp_fv0);
                temp_fs1 *= temp_fv0;
                temp_fs3 *= temp_fv0;

                if (sp568 < temp_fs3) {
                    temp_fv0 = sp568 / temp_fs3;
                    temp_fs1 *= temp_fv0;
                    temp_fs3 *= temp_fv0;
                }

                gSPClearGeometryMode(gfx++, G_ZBUFFER);
                gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                if (gGamePaused) {
                    var_s7 = 255;
                } else {
                    var_s7 = 255 - ((gGameFrameCount & 0xF) * 16);
                }

                gDPSetPrimColor(gfx++, 0, 0, 255, var_s7, 0,
                                (255 - (s32) (playerRacer->distanceFromRacerBehind * 0.085f)));

                if (gNumPlayers < 2) {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarker1PTex, G_IM_FMT_IA, 32, 23, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    var_s7 =
                        ((s32) (((camera->currentScissorLeft + camera->currentScissorRight) * 0.5f) + temp_fs1 + 0.5f) -
                         16)
                        << 2;
                    sp5C4 =
                        ((s32) (((camera->currentScissorTop + camera->currentScissorBottom) * 0.5f) + temp_fs3 + 0.5f) -
                         28)
                        << 2;

                    gSPScisTextureRectangle(gfx++, var_s7, sp5C4, var_s7 + (32 * 4 - 1), sp5C4 + (23 * 4 - 1), 0, 0, 0,
                                            1 << 10, 1 << 10);
                } else {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarkerMPTex, G_IM_FMT_IA, 16, 10, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    var_s7 =
                        ((s32) (((camera->currentScissorLeft + camera->currentScissorRight) * 0.5f) + temp_fs1 + 0.5f) -
                         8)
                        << 2;
                    sp5C4 =
                        ((s32) (((camera->currentScissorTop + camera->currentScissorBottom) * 0.5f) + temp_fs3 + 0.5f) -
                         10)
                        << 2;
                    gSPScisTextureRectangle(gfx++, var_s7, sp5C4, var_s7 + (16 * 4 - 1), sp5C4 + (10 * 4 - 1), 0, 0, 0,
                                            1 << 10, 1 << 10);
                }

                if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_DEATH_RACE)) {
                    if (playerRacer->distanceFromRacerBehind < 1000.0f) {
                        if (!(playerRacer->soundEffectFlags & RACER_SE_FLAGS_8000)) {
                            playerRacer->soundEffectFlags |= RACER_SE_FLAGS_8000;
                            if (gEnableRaceSfx) {
                                Audio_TriggerSystemSE(NA_SE_58);
                            }
                        }
                    } else if (playerRacer->distanceFromRacerBehind > 2500.0f) {
                        playerRacer->soundEffectFlags &= ~RACER_SE_FLAGS_8000;
                    }
                }
            } while (false);
        }
    }

    return gfx;
}
#else
#ifndef EXPANSION_KIT
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/racer/Racer_Draw.s")
#elif VERSION_US
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/racer/Racer_Draw.s")
#elif VERSION_PAL
#pragma GLOBAL_ASM("asm/pal/rev0/nonmatchings/game/racer/Racer_Draw.s")
#endif
#else
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/game/racer/Racer_Draw.s")
#endif
#endif

Gfx* func_8009CBE8(Gfx* gfx, s32 arg1, s32 red, s32 green, s32 blue) {
    u8 character;

    if (arg1 < 6) {
        character = sRecordsMachineIndices[arg1 - 1];
    } else if (arg1 == 6) {
        character = sRecordsMachineIndices[5];
    } else {
        character = sRecordsMachineIndices[6];
    }

    gSPDisplayList(gfx++, D_800CDD38[character]);
    gDPSetEnvColor(gfx++, red, green, blue, 255);
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CCBC(Gfx* gfx, s32 character, s32 arg2) {
    Machine* machine = &gMachines[character];
    s32 color;

    gSPDisplayList(gfx++, D_800CDD38[character]);
#if BUILD_REVISION >= REVISION_C
    if (gGreyscaleMachinePart && (machine->customType == CUSTOM_MACHINE_DEFAULT)) {
        color = (machine->red[arg2] * 77) + (machine->green[arg2] * 151) + (machine->blue[arg2] * 28);
        color >>= 8;
        gDPSetEnvColor(gfx++, color, color, color, 255);
    } else {
#endif
        gDPSetEnvColor(gfx++, machine->red[arg2], machine->green[arg2], machine->blue[arg2], 255);
#if BUILD_REVISION >= REVISION_C
    }
#endif
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CD60(Gfx* gfx, s32 character) {
    Machine* machine = &gMachines[character];

    gDPLoadTextureBlock_4b(gfx++, D_800CDC54[machine->shadowType], G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);

    gSPVertex(gfx++, D_800CDBA4[machine->shadowType], 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    return gfx;
}

Gfx* func_8009CE70(Gfx* gfx, s32 character) {
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CEA0(Gfx* gfx, s32 character) {
#ifdef EXPANSION_KIT
    s32 characterSlot;
    CustomMachine* customMachine;

    characterSlot = Character_GetSlotFromCharacter(character);

    if (gCustomMachinesInfo.characterCustomState[characterSlot] > 0) {
        customMachine = &gCustomMachinesInfo.customMachines[characterSlot];
        gSPDisplayList(gfx++, D_800CDB50[customMachine->frontType]);
        gSPDisplayList(gfx++, D_800CDB6C[customMachine->rearType]);
        gSPDisplayList(gfx++, D_800CDB88[customMachine->wingType]);
    } else if (gCustomMachinesInfo.characterCustomState[characterSlot] < 0) {
        if ((character == CAPTAIN_FALCON) && (D_i2_80111848[CAPTAIN_FALCON] != 0)) {
            gSPDisplayList(gfx++, D_9012718);
        } else if ((character == SAMURAI_GOROH) && (D_i2_80111848[SAMURAI_GOROH] != 0)) {
            gSPDisplayList(gfx++, D_9013460);
        } else if ((character == JODY_SUMMER) && (D_i2_80111848[JODY_SUMMER] != 0)) {
            gSPDisplayList(gfx++, D_9013D58);
        } else {
            gSPDisplayList(gfx++, D_800CDAD8[character]);
        }
    } else {
#endif
        gSPDisplayList(gfx++, D_800CDAD8[character]);
#ifdef EXPANSION_KIT
    }
#endif
    return gfx;
}
