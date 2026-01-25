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
#include "assets/course_track_gfx.h"
#include "assets/machine_custom_gfx.h"
#include "assets/hud_gfx.h"
#include "assets/machine_global_gfx.h"
#include "assets/machine_models.h"

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
s16 D_800E5FBE;
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
Vec3s* D_800E5FE8;
Vec3s* D_800E5FEC;
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
f32 D_800F80BC;
f32 D_800F80C0;
s16 D_800F80C4;
Machine gMachines[30];
CustomMachineInfo sCustomMachineInfo[30];
u8 D_800F8504[7];

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
    D_9001210, D_9001DA0, D_90027D0, D_9003050, D_9003870, D_9003F90, D_900CF48, D_90057A8, D_90061A0,
    D_9006A70, D_90078F0, D_9008060, D_90089A0, D_9009358, D_9009980, D_900A150, D_900AC40, D_900B288,
    D_900BD28, D_900C550, D_9004B98, D_900D898, D_900DFF8, D_900E698, D_900EFE8, D_900F790, D_90100F8,
    D_9010C38, D_90113D8, D_9011EA8, D_9015400, D_9015938, D_9015658, D_9014B40, D_9014DE0, D_9015088,
    D_90148F8, D_9015B58, D_9017350, D_9016DA0, D_9015F50, D_9016298, D_9016530, D_9016948, D_90186C0,
    D_9017B18, D_9018230, D_9017BF0, D_90183F0, D_9017D20, D_9017EC8,
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

UNUSED u8 D_800CDD04[] = { 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28,
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

Vec3s D_800CE4E0[] = {
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
};

Vec3s D_800CE5D0[] = {
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

s32 D_800CE738[] = { 5, 3, 1, 0 };

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

UNUSED s16 D_800CF488[] = {
    270, 290, 320, 350, 420, 580, 630, 0, 510, 560, 630, 720, 890, 930, 1170, 0, 0, 100, 120, 140, 190, 250, 420, 0,
};

void func_8008EC38(Racer*);
void func_8008EC58(Racer*);
void func_8008EC98(Racer*);
void func_8008F550(Racer*);
void func_8008FC80(Racer*);
void func_8008EC78(Racer*);
void func_80090490(Racer*);
void func_80090568(Racer*);

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

u8 D_800CF4D8[] = {
    0, 1, 2, 5, 4, 3, 7, 6, 5, 0, 4, 8, 2, 1, 7, 6, 8, 0, 7, 5, 6, 2, 3, 8,
};

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

s32 func_80088CE0(s32 position) {
    s32 i;

    for (i = 0; i < gTotalRacers; i++) {
        if (position == gRacers[i].position) {
            return i;
        }
    }
    return -1;
}

void func_i3_80115E74(void);
s32 func_8009EBEC(RacerSegmentPositionInfo*, f32, f32, f32, s32, f32);

extern s32 gNumPlayers;
extern s8 gTitleDemoState;
extern s32 gGameMode;

extern CourseInfo* gCurrentCourseInfo;

// Set up racer positions before the start line
void func_80088D28(void) {
    f32 var_fs0;
    f32 var_fs4;
    f32 var_fv0;
    s32 i;
    s32 j;
    CourseSegment* var_s2;
    Racer* temp_s1;
    s32 index;

    func_i3_80115E74();

    var_s2 = gCurrentCourseInfo->courseSegments->prev;
    var_fs0 = 1.0f;
    for (i = 20; i > 0; i--) {
        var_fs0 -= 7.3f / Course_SplineGetTangent(var_s2, var_fs0, &gRacers[0].segmentPositionInfo.segmentForward);
    }

    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) &&
        (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
        if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
            var_fs4 = 1.99f;
        } else {
            var_fs4 = 0;
        }
    } else {
        var_fs4 = 7.99f;
    }

    for (j = 1; j <= gTotalRacers; j++) {
        index = func_80088CE0(j);
        temp_s1 = &gRacers[index];
        temp_s1->segmentPositionInfo.courseSegment = var_s2;
        temp_s1->segmentPositionInfo.segmentTValue = var_fs0;
        Course_SplineGetPosition(var_s2, var_fs0, &temp_s1->segmentPositionInfo.segmentPos);
        temp_s1->segmentPositionInfo.pos = temp_s1->segmentPositionInfo.lastGroundedPos =
            temp_s1->segmentPositionInfo.segmentPos;
        temp_s1->segmentPositionInfo.segmentDisplacement.x = 0.0f;
        temp_s1->segmentPositionInfo.segmentDisplacement.y = 0.0f;
        temp_s1->segmentPositionInfo.segmentDisplacement.z = 0.0f;
        temp_s1->segmentPositionInfo.distanceFromSegment = 0.0f;
        temp_s1->segmentPositionInfo.segmentForwardMagnitude = Course_SplineGetTangent(
            temp_s1->segmentPositionInfo.courseSegment, temp_s1->segmentPositionInfo.segmentTValue,
            &temp_s1->segmentPositionInfo.segmentForward);
        temp_s1->segmentPositionInfo.segmentLengthProportion =
            Course_SplineGetLengthInfo(temp_s1->segmentPositionInfo.courseSegment,
                                       temp_s1->segmentPositionInfo.segmentTValue, &temp_s1->lapDistance);
        Course_SplineGetBasis(temp_s1->segmentPositionInfo.courseSegment, temp_s1->segmentPositionInfo.segmentTValue,
                              &temp_s1->segmentBasis, temp_s1->segmentPositionInfo.segmentLengthProportion);
        if (gTotalRacers >= 4) {
            var_fv0 = 3.0f;
        } else {
            var_fv0 = gTotalRacers - 1;
        }
        var_fv0 = (((j - 1) & 3) * 2 - var_fv0) * 50.0f;
        func_8009EBEC(&temp_s1->segmentPositionInfo,
                      temp_s1->segmentPositionInfo.pos.x + (var_fs4 * temp_s1->segmentBasis.y.x) +
                          (var_fv0 * temp_s1->segmentBasis.z.x),
                      temp_s1->segmentPositionInfo.pos.y + (var_fs4 * temp_s1->segmentBasis.y.y) +
                          (var_fv0 * temp_s1->segmentBasis.z.y),
                      temp_s1->segmentPositionInfo.pos.z + (var_fs4 * temp_s1->segmentBasis.y.z) +
                          (var_fv0 * temp_s1->segmentBasis.z.z),
                      100, 1.0f);
        if (gNumPlayers == 1) {
            var_fv0 = 100.0f;
        } else {
            var_fv0 = 0.1f;
        }

        for (i = 20; i > 0; i--) {
            var_fs0 -= (var_fv0 / 20.0f) / temp_s1->segmentPositionInfo.segmentForwardMagnitude;
            if (var_fs0 < 0.0f) {
                var_s2 = var_s2->prev;
                var_fs0 *= (temp_s1->segmentPositionInfo.segmentForwardMagnitude /
                            Course_SplineGetTangent(var_s2, 1.0f, &temp_s1->segmentPositionInfo.segmentForward));
                var_fs0 += 1.0f;
            }
        }
    }
}

extern s8 gTitleDemoState;

void func_800890B4(void) {
    s16 temp_a0;
    s16 temp_a1;
    s32 var_a2;
    s32 var_a3;
    s32 temp_t5;
    s32 temp_t9;
    Racer* temp;
    Racer* var_a0;
    Racer* var_v0;
    Racer* var_v1;

    if ((gGameMode != GAMEMODE_GP_RACE) || ((gTotalRacers - gRacersRetired) < 2) || (gTitleDemoState != 0)) {
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
        if (!(var_a0->stateFlags & RACER_STATE_RETIRED)) {
            if (var_a2 < var_a0->points) {
                var_v1 = var_v0;
                var_a3 = var_a2;
                var_v0 = var_a0;
                var_a2 = var_a0->points;
            } else if ((var_a3 < var_a0->points) && (var_a0 != var_v0)) {
                var_v1 = var_a0;
                var_a3 = var_a0->points;
            }
        }
        var_a0--;
    } while (var_a0 >= gRacers);

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

void func_i3_80128D8C(void);
void Hud_TriggerLivesIncrease(void);

void func_80089220(s32 playerIndex) {

    gPlayerLives[playerIndex]++;

    func_i3_80128D8C();
    Hud_TriggerLivesIncrease();
    if (gEnableRaceSfx) {
        Audio_TriggerSystemSE(NA_SE_NONE);
    }
    D_800F80C4 = 0;
}

void Hud_TriggerLivesDecrease(void);

void func_8008927C(s32 playerIndex) {

    if (--gPlayerLives[playerIndex] >= 0) {
        Hud_TriggerLivesDecrease();
    }
    if (gEnableRaceSfx) {
        Audio_TriggerSystemSE(NA_SE_44);
    }
    D_800F80C4 = 0;
}

void func_800892E0(Racer* racer) {

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
                D_800E5FBC = 1;
                gRacers[0].energy = gRacers[0].maxEnergy;
                D_800F5DE8 = D_800E5FBC;
                func_800BA2B4(gRacers[0].id);
                func_800BAB68(gRacers[0].id);
                func_8007E0CC();
            }
        }
        racer->raceDistancePosition = (sRaceFrameCount + ((gTotalRacers - racer->position) / 10.0f)) - 600000.0f;
        if (gGameMode == GAMEMODE_GP_RACE) {
            if (racer->id < gNumPlayers) {
                D_800F80C4 = -1;
            }
            if (racer == sRivalRacer) {
                func_800890B4();
            }
        }
    }
}

void func_800894C0(Racer* arg0) {

    if (gEnableRaceSfx) {
        if (arg0->unk_08 & 0x800) {
            arg0->unk_08 &= ~0x800;
            Audio_PlayerLevelSEStop(arg0->id, 4);
        }
        if (arg0->unk_08 & 0x400) {
            arg0->unk_08 &= ~0x400;
            Audio_PlayerLevelSEStop(arg0->id, 5);
        }
        if (arg0->unk_08 & 0x20) {
            arg0->unk_08 &= ~0x20;
            Audio_PlayerLevelSEStop(arg0->id, 11);
        }
        if (arg0->unk_08 & 0x200) {
            arg0->unk_08 &= ~0x200;
            Audio_PlayerLevelSEStop(arg0->id, 6);
        }
        if (arg0->unk_08 & 0x40) {
            arg0->unk_08 &= ~0x40;
            Audio_PlayerLevelSEStop(arg0->id, 10);
        }
        if (arg0->unk_08 & 0x2000) {
            arg0->unk_08 &= ~0x2000;
            Audio_PlayerLevelSEStop(arg0->id, 8);
        }
        if (arg0->unk_08 & 0x100) {
            arg0->unk_08 &= ~0x100;
            func_800BAB50(arg0->id);
        }
        if (arg0->unk_08 & 0x80) {
            arg0->unk_08 &= ~0x80;
            Audio_PlayerLevelSEStop(arg0->id, 9);
        }
        func_800BAB68(arg0->id);
    } else {
        arg0->unk_08 &= ~(0x800 | 0x400 | 0x20 | 0x200 | 0x40 | 0x2000 | 0x100 | 0x80);
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

                    D_800F8504[j + 1] = D_800F8504[j];
                }

                gCurrentCourseInfo->timeRecord[i] = gRacers[0].raceTime;

                func_80089A74(&gCurrentCourseInfo->recordMachineInfos[i]);

                gCurrentCourseInfo->recordEngines[i] = gPlayerEngine[0];
                D_800F8504[i] = gRacers[0].machineIndex;
                break;
            }
        }

        if (gCurrentCourseInfo->maxSpeed < gRacers[0].maxSpeed) {
            gCurrentTimeAttackHasMaxSpeed = 1;
            gCurrentCourseInfo->maxSpeed = gRacers[0].maxSpeed;

            func_80089A74(&gCurrentCourseInfo->maxSpeedMachine);
            D_800F8504[5] = gRacers[0].machineIndex;
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
            D_800F8504[6] = gRacers[0].machineIndex;
        }
    }

    if (D_800F5DEA != 0) {
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

void func_8008A978(void) {
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
        // FAKE
        if (gRacersByPosition[0]) {}

        do {
            if (racer->position == 0) {
                if (racer->stateFlags & RACER_STATE_FINISHED) {
                    if ((finishedRacer == NULL) || (racer->raceTime < bestRaceTime)) {
                        bestRaceTime = racer->raceTime;
                        finishedRacer = racer;
                    }
                } else if ((activeRacer == NULL) || (racer->raceDistancePosition < var_fv0)) {
                    var_fv0 = racer->raceDistancePosition;
                    activeRacer = racer;
                }
            }
            racer--;
        } while (racer >= gRacers);

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
            func_800892E0(racer);
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
    func_8008A978();
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

void func_8008AD38(void) {
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

void func_8008B150(void) {
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

f32 func_8008B2D8(Racer*, f32);

f32 func_8008B2D8(Racer* arg0, f32 arg1) {
    Machine* temp_a1;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fs1;
    f32 temp_fv1;
    f32 temp_ret;
    f32 temp_fa1;

    temp_fs0 = (arg0->unk_1F0 - 780.0f) / 1560.0f;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x078) >> 0xF) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x780) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f);

    arg0->unk_1B4 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 = arg0->unk_1B4;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x0A0) >> 0x15) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x95C) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f);
    arg0->unk_1B0 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += arg0->unk_1B0;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x1BC) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0x978) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f)) *
          temp_fs0)) +
        ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f);
    arg0->unk_1B8 = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1B8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x2C4) >> 0xE) & 0xFF) - (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF);
    temp_fv1 = (((f32) ((ROM_READ(0x988) >> 0x18) & 0xFF) - (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF);
    arg0->unk_1BC = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1BC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x2FC) >> 0x12) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0xA20) >> 0xC) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f)) *
          temp_fs0) +
         ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f));
    arg0->unk_1C8 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += arg0->unk_1C8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x36C) >> 0x10) & 0xFF) - (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF);
    temp_fv1 = ((((f32) ((ROM_READ(0x1BC) >> 0xA) & 0xFF) - (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF)) * temp_fs0) +
                (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF));
    arg0->unk_1CC = arg0->unk_1C8 / (((temp_fv1 - temp_fv0) * arg1) + temp_fv0 +
                                     (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f))));
    temp_fs1 += arg0->unk_1CC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((ROM_READ(0x374) >> 3) & 0xFF) - ((f32) ((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
               (((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f);
    temp_fv1 =
        (((((ROM_READ(0x1C8) >> 4) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
        (((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f);
    temp_a1 = &gMachines[arg0->character];
    arg0->unk_1F8 = D_800CF188[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1F8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        (((f32) ((ROM_READ(0x384) >> 5) & 0xFF) - ((f32) ((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x248) >> 0xB) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f)) *
         temp_fs0) +
        (((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f);
    arg0->unk_1FC = D_800CF19C[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1FC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((ROM_READ(0x38C) & 0xFF) - (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f)) * temp_fs0) +
               (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((ROM_READ(0x250) >> 3) & 0xFF) * 0.001f) - (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f);

    temp_fa1 = ((temp_fv1 - temp_fv0) * arg0->unk_1A8) + temp_fv0;

    arg0->unk_1C0 = (D_800CF174[temp_a1->machineStats[BOOST_STAT]] + temp_fa1) / arg0->unk_1B8;
    temp_fs1 += arg0->unk_1C0;
    arg0->unk_1C4 = (D_800CF174[2] + temp_fa1) / arg0->unk_1B8;
    temp_fs1 += arg0->unk_1C4;
    temp_ret = func_80089654(arg1);
    temp_ret = func_80089654(temp_ret);
    temp_ret = func_80089654(temp_ret);
    arg0->unk_1D0 = ((D_800CF15C - 1.0f) * temp_ret) + 1.0f;

    return temp_ret;
}

void func_8008C14C(Racer* arg0) {
    s32 pad[7];
    f32 temp;
    f32 temp_fv0_4;
    f32 var_fs0;
    s32 i;
    Mtx3F spE8;
    Machine* temp_s2;

    temp_s2 = &gMachines[arg0->character];
    arg0->customType = temp_s2->customType;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        arg0->machineIndex = 0;
    } else {
        arg0->machineIndex = arg0->character;
    }

    arg0->shadowType = temp_s2->shadowType;
    arg0->boostersType = temp_s2->boostersType;
    arg0->bodyRF = arg0->bodyR = temp_s2->red[arg0->machineSkinIndex];
    arg0->bodyGF = arg0->bodyG = temp_s2->green[arg0->machineSkinIndex];
    arg0->bodyBF = arg0->bodyB = temp_s2->blue[arg0->machineSkinIndex];
    arg0->unk_2DA = arg0->unk_2DC = arg0->unk_2DE = arg0->shadowR = arg0->shadowG = arg0->shadowB = 0;
    arg0->unk_2EC = 255.0f;
    arg0->unk_2F0 = 0.0f;
    arg0->unk_2F4 = 0.0f;
    arg0->unk_2F8 = arg0->bodyRF - arg0->unk_2EC;
    arg0->unk_2FC = arg0->bodyGF - arg0->unk_2F0;
    arg0->unk_300 = arg0->bodyBF - arg0->unk_2F4;
    if ((gTitleDemoState != 0) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
        arg0->stateFlags =
            RACER_STATE_ACTIVE | RACER_STATE_FLAGS_20000000 | RACER_STATE_CAN_BOOST | RACER_STATE_FLAGS_8000;
    } else {
        arg0->stateFlags = RACER_STATE_ACTIVE | RACER_STATE_FLAGS_20000000 | RACER_STATE_FLAGS_8000;
    }
    if ((arg0->id >= gNumPlayers) || (D_800CE77C != 0) || (gGameMode == GAMEMODE_RECORDS) ||
        (gGameMode == GAMEMODE_GP_END_CS) || (gTitleDemoState != 0)) {
        arg0->stateFlags |= RACER_STATE_CPU_CONTROLLED;
    }
    arg0->segmentPositionInfo.segmentLengthProportion = Course_SplineGetLengthInfo(
        arg0->segmentPositionInfo.courseSegment, arg0->segmentPositionInfo.segmentTValue, &arg0->lapDistance);

    Course_SplineGetBasis(arg0->segmentPositionInfo.courseSegment, arg0->segmentPositionInfo.segmentTValue,
                          &arg0->segmentBasis, arg0->segmentPositionInfo.segmentLengthProportion);
    // FAKE spE8 is compiler stack from a chain struct copy
    spE8 = arg0->segmentBasis;
    arg0->trueBasis = spE8;
    arg0->unk_E8 = spE8;

    spE8.x = arg0->segmentPositionInfo.pos;

    arg0->focusPos = spE8.x;
    arg0->unk_10C = spE8.x;

    arg0->gravityUp.x = arg0->tiltUp.x = arg0->unk_19C.x = arg0->trueBasis.y.x;
    arg0->gravityUp.y = arg0->tiltUp.y = arg0->unk_19C.y = arg0->trueBasis.y.y;
    arg0->gravityUp.z = arg0->tiltUp.z = arg0->unk_19C.z = arg0->trueBasis.y.z;

    for (i = 0; i < 3; i++) {
        arg0->lapTimes[i] = NULL;
    }

    arg0->machineLod = arg0->unk_2B2 = arg0->unk_2B3 = 1;
    arg0->shadowPos.y = -54321.0f;
    arg0->lapsCompletedDistance = -gCurrentCourseInfo->length;
    arg0->unk_284 = 0;
    arg0->unk_286 = 0;
    arg0->raceDistance = arg0->raceDistancePosition = arg0->lapsCompletedDistance + arg0->lapDistance;
    arg0->unk_2A4 = ((Math_Rand2() & 0x1FFFF) % 150) + 1;
    arg0->lapsCompleted = 1;
    arg0->unk_28C = NULL;
    arg0->unk_08 = 0x8000;
    arg0->startNewPracticeLap = arg0->unk_288 = arg0->unk_278 = arg0->unk_27A = arg0->unk_27C = arg0->bodyWhiteTimer =
        arg0->spinOutTimer = arg0->completedLapsTime = arg0->raceTime = arg0->lap = arg0->unk_204 = arg0->unk_208 =
            arg0->unk_20C = arg0->boostTimer = arg0->unk_214 = arg0->unk_210 = 0;
    arg0->unk_118.x = arg0->unk_118.y = arg0->unk_118.z = arg0->pitForceFieldSize = arg0->unk_1DC = arg0->unk_E4 =
        arg0->unk_238 = arg0->unk_200 = arg0->heightAboveGround = arg0->unk_1D4 = arg0->unk_1D8 = arg0->speed =
            arg0->maxSpeed = arg0->unk_198 = arg0->focusVelocity.x = arg0->focusVelocity.y = arg0->focusVelocity.z =
                arg0->unk_68.x = arg0->unk_68.y = arg0->unk_68.z = arg0->unk_5C.x = arg0->unk_5C.y = arg0->unk_5C.z =
                    arg0->unk_80.x = arg0->unk_80.y = arg0->unk_80.z = arg0->velocity.x = arg0->velocity.y =
                        arg0->velocity.z = var_fs0 = 0.0f;
    arg0->podiumHeight = arg0->unk_230 = arg0->unk_178 = arg0->unk_1E8 = 0.0f;
    arg0->shadowColorStrength = 1.0f;
    arg0->unk_1EC = 2500.0f / 27.0f;
    arg0->unk_17C = D_800F80A4;

    arg0->unk_1E0 = (((temp_s2->weight - 780.0f) * -0.0050000027f) / 1560.0f) + 0.054f;
    arg0->unk_1E4 = (((temp_s2->weight - 780.0f) * -0.004999999f) / 1560.0f) + 0.03f;
    arg0->unk_1F0 = temp_s2->weight;
    arg0->unk_1F4 =
        ((4 - temp_s2->machineStats[BODY_STAT]) * 312.0f) + 780.0f + ((312.0f * (temp_s2->weight - 780.0f)) / 1560.0f);

    // arg0->unk_1F4 = SQ(arg0->unk_1F4);
    // FAKE
    arg0->unk_1F4 = arg0->unk_1F4 * (temp = arg0->unk_1F4);

    for (i = 0; i < 2;) {
        temp_fv0_4 = func_8008B2D8(arg0, arg0->unk_1A8);
        if (temp_fv0_4 == var_fs0) {
            i++;
        } else {
            i = 0;
        }
        var_fs0 = temp_fv0_4;
    }

    arg0->unk_234 = 1.7f;

    arg0->energy = arg0->maxEnergy = gBodyHealthValues[temp_s2->machineStats[BODY_STAT]];
    arg0->boostEnergyUsage = arg0->maxEnergy * 0.0015f;
    arg0->unk_31C = arg0->unk_1C4 - 1.0f;
    arg0->unk_320 = (0.5f - arg0->unk_1A8) * 0.5f;
    arg0->unk_324 = 1.0f / (2.0f * arg0->unk_1BC);
    arg0->unk_328 = 1.0f - arg0->unk_1D0;
    arg0->energyIncrease = arg0->maxEnergy * sEnergyRefillScale;

    arg0->currentRadiusLeft = (arg0->segmentPositionInfo.segmentLengthProportion *
                               (arg0->segmentPositionInfo.courseSegment->next->radiusLeft -
                                arg0->segmentPositionInfo.courseSegment->radiusLeft)) +
                              arg0->segmentPositionInfo.courseSegment->radiusLeft;
    arg0->currentRadiusRight = (arg0->segmentPositionInfo.segmentLengthProportion *
                                (arg0->segmentPositionInfo.courseSegment->next->radiusRight -
                                 arg0->segmentPositionInfo.courseSegment->radiusRight)) +
                               arg0->segmentPositionInfo.courseSegment->radiusRight;
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
    Racer* var_s1_2;
    GhostRacer* temp_s0_2;
    MachineInfo sp6C;
    OSMesg sp68;

    D_800E5FE8 = &D_800CE4E0[COURSE_CONTEXT()->courseData.venue * 4];
    D_800E5FEC = &D_800CE5D0[COURSE_CONTEXT()->courseData.venue * 4];
    gPracticeBestLap = 600000 - 1;
    D_800F809C = D_800F80A0 = 0.0f;
    sRaceFrameCount = gStartNewBestLap = gRacersKOd = D_800F80C4 = D_800F80B8 = D_800E5FBC = D_800E5FBE = D_800E5FC0 =
        gRacersRetired = gRacersFinished = gCpuRacersRetired = gPlayerRacersRetired = gPlayerRacersFinished = 0;
    D_800F80BC = gCurrentCourseInfo->length * 0.5;
    D_800F80C0 = -D_800F80BC;
    if (gGameMode != GAMEMODE_GP_RACE) {
        D_800E5FD6 = 0;
    }
    D_800E5FD4 = D_800E5FD6;
    D_800E5FF0++;

    if (gNumPlayers == 1) {
        switch (gGameMode) {
            case GAMEMODE_RECORDS:
            case GAMEMODE_TIME_ATTACK:
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
    if (gTitleDemoState != 0) {
        for (i = 29; i >= 0; i--) {
            gRacers[i].character = i;
            gRacers[i].machineSkinIndex = 0;
        }
        var_a3 = 0x21;
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
    func_80088D28();
    osRecvMesg(&D_800DCAB0, &sp68, OS_MESG_NOBLOCK);
    osRecvMesg(&D_800DCAB0, &sp68, OS_MESG_BLOCK);
    for (i = 0; i < gTotalRacers; i++) {
        gRacers[i].id = i;
        Cpu_InitRacer(&gRacers[i]);
        func_8008C14C(&gRacers[i]);
        if (i < gNumPlayers) {
            gRacers[i].unk_2A4 = 0;
            gControllers[gPlayerControlPorts[i]].unk_72 = gControllers[gPlayerControlPorts[i]].unk_78 = 1;
            D_800E5F30[i] = 0;
            D_800E5F20[i] = 0;
        }
    }

    func_8008AD38();
    func_8008A978();
    func_8008B150();

    for (i = 0; i < ARRAY_COUNT(sRacerPairInfo); i++) {
        sRacerPairInfo[i].unk_10 = 0;
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
        for (var_s1_2 = sLastRacer; var_s1_2 > gRacers; var_s1_2--) {
            var_s1_2->energy *= 0.5f;
            var_s1_2->maxEnergy *= 0.5f;
        }
    }
    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) &&
        (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
        D_800CE780 = 1;
        gRaceIntroTimer = 460;
        gEnableRaceSfx = 1;
    } else {
        gEnableRaceSfx = 0;
        gRaceIntroTimer = 0;

        if (gTitleDemoState != 0) {
            D_800CE780 = 1;
        } else {
            D_800CE780 = 0;
        }
        for (var_s1_2 = sLastRacer; var_s1_2 >= gRacers; var_s1_2--) {
            var_s1_2->stateFlags |= RACER_STATE_FLAGS_400000;
            var_s1_2->unk_17C = 13.0f;
            var_s1_2->unk_2A4 = 0;
        }
    }
    func_800890B4();

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
            func_80089A74(&sp6C);
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

                temp_s0_2 = &gGhostRacers[i];

                if (gGhosts[i].raceTime < var_a3) {
                    var_a3 = gGhosts[i].raceTime;
                    gFastestGhostRacer = temp_s0_2;
                }
                temp_s0_2->exists = true;
                temp_s0_2->ghost = &gGhosts[i];
                temp_s0_2->replayPtr = gGhosts[i].replayData;
                temp_s0_2->frameCount = 0;
                temp_s0_2->replayIndex = 0;
                temp_s0_2->initialized = false;
                temp_s0_2->scale = 1.0f;
                temp_s0_2->replayPosX = sReplayRecordPosX;
                temp_s0_2->replayPosY = sReplayRecordPosY;
                temp_s0_2->replayPosZ = sReplayRecordPosZ;
                temp_s0_2->racer = &gRacers[i + 1];
                gRacers[i + 1] = gRacers[0];
                var_s1_2 = temp_s0_2->racer;

                var_s1_2->id = i + 1;
                var_s1_2->character = temp_s0_2->ghost->machineInfo.character;

                if (func_8008B23C(&temp_s0_2->ghost->machineInfo, &sp6C) != 0) {
                    var_s1_2->machineIndex = i + 7;
                } else {
                    var_s1_2->machineIndex = gRacers[0].machineIndex;
                }

                var_s1_2->shadowType = gMachines[var_s1_2->character].shadowType;
                var_s1_2->boostersType = gMachines[var_s1_2->character].boostersType;
                var_s1_2->bodyR = temp_s0_2->ghost->machineInfo.bodyR;
                var_s1_2->bodyG = temp_s0_2->ghost->machineInfo.bodyG;
                var_s1_2->bodyB = temp_s0_2->ghost->machineInfo.bodyB;
            }
        }
        sGhostReplayRecordingPtr = sGhostReplayRecordingBuffer;
        gUnableToRecordGhost = sReplayRecordFrameCount = sGhostReplayRecordingSize = 0;
    }
}

void func_8008D33C(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        gMachines[i] = sDefaultMachines[i];
    }
}

void func_8008D3C4(s32 character, s32 arg1) {
    Gfx* gfx;
    s32 i;
    Machine* temp_v0 = &gMachines[character];

    if (temp_v0->customType == CUSTOM_MACHINE_EDITED) {
        gfx = Machine_DrawLoadCustomTextures(D_800CDD38[arg1], sCustomMachineInfo[character].logo, temp_v0->number - 1,
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
    if (temp_v0->customType != CUSTOM_MACHINE_DEFAULT) {
        character = temp_v0->customType - CUSTOM_MACHINE_SUPER_FALCON + 30;
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

void func_8008D5F4(MachineInfo* arg0, s32 arg1) {
    s32 pad[2];
    s32 var_v1;
    Gfx* gfx;
    s32 i;

    if (arg0->customType == CUSTOM_MACHINE_EDITED) {
        gfx = Machine_DrawLoadCustomTextures(D_800CDD38[arg1], arg0->logo, arg0->number, arg0->decal);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = Machine_DrawCustom(D_800CDDB0[arg1 * 6 + i], i, arg0->frontType, arg0->rearType, arg0->wingType,
                                     arg0->decalR, arg0->decalG, arg0->decalB, arg0->numberR, arg0->numberG,
                                     arg0->numberB, 255, 255, 255, arg0->cockpitR, arg0->cockpitG, arg0->cockpitB);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (arg0->customType != CUSTOM_MACHINE_DEFAULT) {
        var_v1 = arg0->customType - CUSTOM_MACHINE_SUPER_FALCON + 30;
    } else {
        var_v1 = arg0->character;
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
    CourseInfo* sp2C;
    s32 i;
    u8 var;

    sp2C = &gCourseInfos[gCourseIndex];

    for (i = 4; i >= 0; i--) {
        D_800F8504[i] = i + 1;
        func_8008D5F4(&sp2C->recordMachineInfos[i], D_800F8504[i]);
    }

    var = 5;
    D_800F8504[var] = var + 1;
    func_8008D5F4(&sp2C->maxSpeedMachine, D_800F8504[var]);
    var = 6;
    D_800F8504[var] = var + 1;
    func_8008D5F4(&sp2C->bestTimeMachine, D_800F8504[var]);
}

void func_800A4DF0(void);

void func_8008D8E8(void) {
    s32 i;

    func_800A4DF0();
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

extern s16 sLastMultiplayerTotalRacerCount;
extern s16 sLastMultiplayerPlayerCount;

void func_8008DA68(void) {
    s32 i;

    D_800E5FD6 = D_800E5FF0 = 0;
    sLastMultiplayerTotalRacerCount = sLastMultiplayerPlayerCount = 0;

    for (i = 0; i < ARRAY_COUNT(gRacers); i++) {
        gRacers[i].character = (s8) (i % ARRAY_COUNT(gRacers));
        gRacers[i].machineSkinIndex = 0;
        gRacers[i].unk_1A8 = func_8008960C(0.5f);
        if (i < 4) {
            gPlayerCharacters[i] = (s16) gRacers[i].character;
            gPlayerMachineSkins[i] = gRacers[i].machineSkinIndex;
            gPlayerEngine[i] = 0.5f;
        }
    }
    func_8008D33C();
}

void func_8008DB98(void) {
    func_8008DA68();
}

extern s16 gRacersKOd;

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
    temp_v0->unk_230 += temp_v0->maxEnergy * 0.125f;
    if ((gNumPlayers == 1) && gEnableRaceSfx) {
        Audio_TriggerSystemSE(0x39);
    }
}

void func_8008DCD8(Racer* arg0, f32 arg1) {
    s32 pad[7];
    Vec3f sp90;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 i;

    if (arg0->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED)) {
        if (((arg0->stateFlags & (RACER_STATE_ACTIVE | RACER_STATE_CRASHED)) ==
             (RACER_STATE_ACTIVE | RACER_STATE_CRASHED)) &&
            (D_800CE770 < arg1)) {
            arg0->stateFlags &= ~RACER_STATE_ACTIVE;
            arg0->trueBasis = arg0->segmentBasis;
            D_800E5FC0++;
            if (arg0->id < gNumPlayers) {
                func_800894C0(arg0);
            }
            if (gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(arg0->id, 8);
            }
            if (arg0->machineLod != 0) {
                if (arg0->unk_28C == NULL) {
                    sp90.x = 0.0f;
                    sp90.y = 0.0f;
                    sp90.z = 0.0f;
                } else {
                    sp90.z = arg0->unk_28C->velocity.x;
                    sp90.y = arg0->unk_28C->velocity.y;
                    sp90.x = arg0->unk_28C->velocity.z;
                }
                Effects_SpawnExplosion2(arg0->segmentPositionInfo.pos.x, arg0->segmentPositionInfo.pos.y,
                                        arg0->segmentPositionInfo.pos.z, sp90.z, sp90.y, sp90.x, 40.0f, arg0);

                temp_s5 = arg0->bodyRF;
                temp_s6 = arg0->bodyGF;
                temp_s7 = arg0->bodyBF;

                i = (arg0->id < gNumPlayers) ? 60 : 30;
                do {

                    temp_fs2 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    temp_fs0 = ((Math_Rand2() & 0x1FFFF) * (7.0f / 131071.0f)) + 3.5f;

                    temp_fs1 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    Effects_SpawnMachineDebris(((s32) (Math_Rand2() % 32) - 0x10) + arg0->segmentPositionInfo.pos.x,
                                               ((s32) (Math_Rand1() % 32) - 0x10) + arg0->segmentPositionInfo.pos.y,
                                               ((s32) (Math_Rand1() % 32) - 0x10) + arg0->segmentPositionInfo.pos.z,
                                               sp90.z + (arg0->trueBasis.z.x * temp_fs2) +
                                                   (temp_fs0 * arg0->trueBasis.y.x) + (temp_fs1 * arg0->trueBasis.x.x),
                                               sp90.y + (arg0->trueBasis.z.y * temp_fs2) +
                                                   (temp_fs0 * arg0->trueBasis.y.y) + (temp_fs1 * arg0->trueBasis.x.y),
                                               sp90.x + (arg0->trueBasis.z.z * temp_fs2) +
                                                   (temp_fs0 * arg0->trueBasis.y.z) + (temp_fs1 * arg0->trueBasis.x.z),
                                               &arg0->trueBasis, temp_s5, temp_s6, temp_s7, arg0);
                    i--;
                } while (i != 0);
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_RECEIVED_DAMAGE;
        arg0->energy -= arg1;
        if (arg0->energy < 0.0f) {
            if (arg0->machineLod == 0) {
                arg0->energy = 0.1f;
                return;
            }
            arg0->energy = 0.0f;
            arg0->unk_238 = 0.2f * arg1;
            if (arg0->unk_238 > 1.0f) {
                arg0->unk_238 = 1.0f;
            }
            if (Math_Rand1() % 2) {
                arg0->unk_238 *= -1.0f;
            }

            if (!(arg0->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
                arg0->stateFlags |= RACER_STATE_SPINNING_OUT;
                arg0->stateFlags &= ~RACER_STATE_FLAGS_400000;
                arg0->spinOutTimer = 1;
                arg0->unk_234 = 2.0f;
                func_8008DBB8(arg0, 60);
            }
        }
    }
}

void func_8008E188(Racer* arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 pad;
    Racer* var;
    f32 var_fv0;

    var_fv0 = arg0->segmentBasis.z.x * arg3;
    arg0->segmentPositionInfo.segmentDisplacement.x -= var_fv0;
    arg0->segmentPositionInfo.pos.x -= var_fv0;
    arg0->segmentPositionInfo.lastGroundedPos.x -= var_fv0;

    var_fv0 = arg0->segmentBasis.z.y * arg3;
    arg0->segmentPositionInfo.segmentDisplacement.y -= var_fv0;
    arg0->segmentPositionInfo.pos.y -= var_fv0;
    arg0->segmentPositionInfo.lastGroundedPos.y -= var_fv0;

    var_fv0 = arg0->segmentBasis.z.z * arg3;
    arg0->segmentPositionInfo.segmentDisplacement.z -= var_fv0;
    arg0->segmentPositionInfo.pos.z -= var_fv0;
    arg0->segmentPositionInfo.lastGroundedPos.z -= var_fv0;

    arg0->segmentPositionInfo.distanceFromSegment = sqrtf(SQ(arg0->segmentPositionInfo.segmentDisplacement.x) +
                                                          SQ(arg0->segmentPositionInfo.segmentDisplacement.y) +
                                                          SQ(arg0->segmentPositionInfo.segmentDisplacement.z));

    if (arg1 * arg2 <= 0.0f) {
        return;
    }

    if (arg1 * arg2 > 0.01f) {
        if (arg0->machineLod != 0) {
            Effects_SpawnCollisionSparks(arg0->segmentPositionInfo.pos.x + ((arg2 * 15.0f) * arg0->segmentBasis.z.x),
                                         arg0->segmentPositionInfo.pos.y + ((arg2 * 15.0f) * arg0->segmentBasis.z.y),
                                         arg0->segmentPositionInfo.pos.z + ((arg2 * 15.0f) * arg0->segmentBasis.z.z),
                                         arg0->velocity.x, arg0->velocity.y, arg0->velocity.z,
                                         (arg1 * arg2 * 1.5f) + 18.0f, arg0);
        }
        if (gEnableRaceSfx) {
            Audio_PlayerTriggerSEStart(arg0->id, 3);
        }
        func_8008DCD8(arg0, arg1 * arg2 * 0.7f);
    }

    arg0->velocity.x = (arg0->velocity.x - arg0->unk_234 * arg1 * arg0->segmentBasis.z.x) * 0.998f;
    arg0->velocity.y = (arg0->velocity.y - arg0->unk_234 * arg1 * arg0->segmentBasis.z.y) * 0.998f;
    arg0->velocity.z = (arg0->velocity.z - arg0->unk_234 * arg1 * arg0->segmentBasis.z.z) * 0.998f;

    // FAKE
    var = arg0;
    var->unk_118.x = var->segmentBasis.z.x * (-0.15f * arg1);
    var->unk_118.y = var->segmentBasis.z.y * (-0.15f * arg1);
    var->unk_118.z = var->segmentBasis.z.z * (-0.15f * arg1);

    arg0->stateFlags |= RACER_STATE_COLLISION_RECOIL;
}

void func_8008E418(Racer* arg0) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 = ((arg0->gravityUp.x * arg0->tiltUp.x) + (arg0->gravityUp.y * arg0->tiltUp.y) +
                (arg0->gravityUp.z * arg0->tiltUp.z)) *
               0.15f * arg0->unk_E4;

    arg0->tiltUp.x = arg0->trueBasis.y.x + (temp_fv0 * arg0->trueBasis.x.x);
    arg0->tiltUp.y = arg0->trueBasis.y.y + (temp_fv0 * arg0->trueBasis.x.y);
    arg0->tiltUp.z = arg0->trueBasis.y.z + (temp_fv0 * arg0->trueBasis.x.z);

    temp_fv1 = 1.0f / sqrtf(SQ(arg0->tiltUp.x) + SQ(arg0->tiltUp.y) + SQ(arg0->tiltUp.z));
    arg0->tiltUp.x *= temp_fv1;
    arg0->tiltUp.y *= temp_fv1;
    arg0->tiltUp.z *= temp_fv1;
}

void func_8008E504(Racer* arg0) {

    arg0->gravityUp.x -= 0.5f * arg0->gravityUp.x;
    arg0->gravityUp.y += 0.5f * (1.0f - arg0->gravityUp.y);
    arg0->gravityUp.z -= 0.5f * arg0->gravityUp.z;
}

void func_80090568(Racer*);

void func_8008E54C(Racer* arg0, f32 arg1) {
    f32 temp_ft4;
    f32 sp50;
    f32 temp_fv0;

    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        arg0->currentRadiusLeft += 57.5f;
        arg0->currentRadiusRight += 57.5f;
        func_80090568(arg0);

        arg0->currentRadiusLeft -= 57.5f;
        arg0->currentRadiusRight -= 57.5f;
        if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
            return;
        }
        sp50 = (arg0->segmentBasis.z.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
               (arg0->segmentBasis.z.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
               (arg0->segmentBasis.z.z * arg0->segmentPositionInfo.segmentDisplacement.z);
        if ((sp50 < -arg0->currentRadiusRight) || (arg0->currentRadiusLeft < sp50)) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000;
            func_8008DCD8(arg0, 2.0f);
            Effects_SpawnCollisionSparks(arg0->segmentPositionInfo.pos.x, arg0->segmentPositionInfo.pos.y,
                                         arg0->segmentPositionInfo.pos.z, arg0->velocity.x, arg0->velocity.y,
                                         arg0->velocity.z, 40.0f, arg0);
            if (gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(arg0->id, 3);
            }
        }
    } else {
        sp50 = (arg0->segmentBasis.z.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
               (arg0->segmentBasis.z.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
               (arg0->segmentBasis.z.z * arg0->segmentPositionInfo.segmentDisplacement.z);
        arg0->heightAboveGround = (arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                                  (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                                  (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z);
        arg0->unk_19C.x = arg0->segmentBasis.y.x;
        arg0->unk_19C.y = arg0->segmentBasis.y.y;
        arg0->unk_19C.z = arg0->segmentBasis.y.z;

        if (arg1 < arg0->heightAboveGround) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(arg0->id, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->shadowPos.y = -54321.0f;
            return;
        }

        if (arg0->heightAboveGround < 0.0f) {
            temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.x;
            arg0->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
            arg0->segmentPositionInfo.pos.x -= temp_fv0;
            arg0->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

            temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.y;
            arg0->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
            arg0->segmentPositionInfo.pos.y -= temp_fv0;
            arg0->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

            temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.z;
            arg0->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
            arg0->segmentPositionInfo.pos.z -= temp_fv0;
            arg0->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

            arg0->heightAboveGround = 0.0f;

            temp_ft4 = (arg0->segmentBasis.y.x * arg0->velocity.x) + (arg0->segmentBasis.y.y * arg0->velocity.y) +
                       (arg0->segmentBasis.y.z * arg0->velocity.z);
            if (temp_ft4 < 0.0f) {
                arg0->velocity.x -= temp_ft4 * arg0->segmentBasis.y.x;
                arg0->velocity.y -= temp_ft4 * arg0->segmentBasis.y.y;
                arg0->velocity.z -= temp_ft4 * arg0->segmentBasis.y.z;
                if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                    func_800BB3C4(arg0->id, temp_ft4);
                }
            }
        }

        if (arg0->heightAboveGround <= 15.0f) {
            arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {

                if (arg0->unk_08 & 0x2000) {
                    arg0->unk_08 &= ~0x2000;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStop(arg0->id, 8);
                    }
                }
            }

            arg0->gravityUp.x = arg0->tiltUp.x = arg0->segmentBasis.y.x;
            arg0->gravityUp.y = arg0->tiltUp.y = arg0->segmentBasis.y.y;
            arg0->gravityUp.z = arg0->tiltUp.z = arg0->segmentBasis.y.z;

        } else {
            arg0->stateFlags |= RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(arg0->id, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);

            if (arg0->heightAboveGround < 30.0f) {

                temp_ft4 = (arg0->heightAboveGround - 15.0f) / 15.0f;
                arg0->gravityUp.x = (arg0->gravityUp.x - arg0->segmentBasis.y.x) * temp_ft4 + arg0->segmentBasis.y.x;
                arg0->gravityUp.y = (arg0->gravityUp.y - arg0->segmentBasis.y.y) * temp_ft4 + arg0->segmentBasis.y.y;
                arg0->gravityUp.z = (arg0->gravityUp.z - arg0->segmentBasis.y.z) * temp_ft4 + arg0->segmentBasis.y.z;

                arg0->tiltUp.x = (arg0->tiltUp.x - arg0->segmentBasis.y.x) * temp_ft4 + arg0->tiltUp.x;
                arg0->tiltUp.y = (arg0->tiltUp.y - arg0->segmentBasis.y.y) * temp_ft4 + arg0->tiltUp.y;
                arg0->tiltUp.z = (arg0->tiltUp.z - arg0->segmentBasis.y.z) * temp_ft4 + arg0->tiltUp.z;

                temp_fv0 = 1.0f / sqrtf(SQ(arg0->tiltUp.x) + SQ(arg0->tiltUp.y) + SQ(arg0->tiltUp.z));
                arg0->tiltUp.x *= temp_fv0;
                arg0->tiltUp.y *= temp_fv0;
                arg0->tiltUp.z *= temp_fv0;
            }
        }

        if (sp50 < -arg0->currentRadiusRight) {
            func_8008E188(arg0,
                          (arg0->segmentBasis.z.x * arg0->velocity.x) + (arg0->segmentBasis.z.y * arg0->velocity.y) +
                              (arg0->segmentBasis.z.z * arg0->velocity.z),
                          -1.0f, arg0->currentRadiusRight + sp50);
        } else if (arg0->currentRadiusLeft < sp50) {
            func_8008E188(arg0,
                          (arg0->segmentBasis.z.x * arg0->velocity.x) + (arg0->segmentBasis.z.y * arg0->velocity.y) +
                              (arg0->segmentBasis.z.z * arg0->velocity.z),
                          1.0f, sp50 - arg0->currentRadiusLeft);
        } else {
            arg0->segmentPositionInfo.distanceFromSegment = sqrtf(SQ(arg0->segmentPositionInfo.segmentDisplacement.x) +
                                                                  SQ(arg0->segmentPositionInfo.segmentDisplacement.y) +
                                                                  SQ(arg0->segmentPositionInfo.segmentDisplacement.z));
        }

        arg0->shadowPos.x = arg0->segmentPositionInfo.pos.x - (arg0->heightAboveGround * arg0->segmentBasis.y.x);
        arg0->shadowPos.y = arg0->segmentPositionInfo.pos.y - (arg0->heightAboveGround * arg0->segmentBasis.y.y);
        arg0->shadowPos.z = arg0->segmentPositionInfo.pos.z - (arg0->heightAboveGround * arg0->segmentBasis.y.z);
    }
}

void func_8008EC38(Racer* arg0) {
    func_8008E54C(arg0, 40.0f);
}

void func_8008EC58(Racer* arg0) {
    func_8008E54C(arg0, 145.0f);
}

void func_8008EC78(Racer* arg0) {
    func_8008E54C(arg0, 210.0f);
}

extern f32 D_800CF8E8[];

void func_8008EC98(Racer* arg0) {
    f32 var_fv0;
    f32 temp_fv0;
    f32 var_fv1;
    f32 sp60;
    f32 var_fs0;
    f32 sp58;
    f32 sp54;

    if (arg0->segmentPositionInfo.segmentTValue < arg0->segmentPositionInfo.courseSegment->unk_68) {
        var_fv0 = sp60 =
            arg0->segmentPositionInfo.segmentLengthProportion / arg0->segmentPositionInfo.courseSegment->unk_70;
        var_fv0 *= arg0->currentRadiusLeft;
        var_fs0 = arg0->currentRadiusLeft;
    } else if (arg0->segmentPositionInfo.courseSegment->unk_6C < arg0->segmentPositionInfo.segmentTValue) {
        var_fv0 = sp60 = (1.0f - arg0->segmentPositionInfo.segmentLengthProportion) /
                         arg0->segmentPositionInfo.courseSegment->unk_70;
        var_fv0 *= arg0->currentRadiusLeft;
        var_fs0 = -arg0->currentRadiusLeft;
    } else {
        var_fv0 = arg0->currentRadiusLeft;
        var_fs0 = 0.0f;
    }

    arg0->heightAboveGround = arg0->currentRadiusLeft - arg0->segmentPositionInfo.distanceFromSegment;
    if (arg0->segmentPositionInfo.distanceFromSegment > 0.01f) {
        var_fv1 = -1.0f / arg0->segmentPositionInfo.distanceFromSegment;
        arg0->unk_19C.x = arg0->segmentPositionInfo.segmentDisplacement.x * var_fv1;
        arg0->unk_19C.y = arg0->segmentPositionInfo.segmentDisplacement.y * var_fv1;
        arg0->unk_19C.z = arg0->segmentPositionInfo.segmentDisplacement.z * var_fv1;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = ((arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                   (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                   (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z)) -
                  23.0f;
        if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
            if ((var_fv1 >= 0.0f) || (arg0->currentRadiusLeft < arg0->segmentPositionInfo.distanceFromSegment)) {
                func_8008E418(arg0);
                func_8008E504(arg0);
                arg0->shadowPos.y = -54321.0f;
                return;
            }
            arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
        } else if (var_fv1 >= 0.0f) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(arg0->id, 8);
                    }
                }
            }
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->shadowPos.y = -54321.0f;
            return;
        }
    } else if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if (arg0->currentRadiusLeft < arg0->segmentPositionInfo.distanceFromSegment) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->shadowPos.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = var_fv0 + (arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                  (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                  (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z);
        if (var_fv1 < arg0->heightAboveGround) {
            arg0->heightAboveGround = var_fv1;
            arg0->unk_19C.x = arg0->segmentBasis.y.x;
            arg0->unk_19C.y = arg0->segmentBasis.y.y;
            arg0->unk_19C.z = arg0->segmentBasis.y.z;

            arg0->tiltUp.x = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->segmentBasis.y.x) +
                             (var_fs0 * arg0->segmentBasis.x.x);
            arg0->tiltUp.y = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->segmentBasis.y.y) +
                             (var_fs0 * arg0->segmentBasis.x.y);
            arg0->tiltUp.z = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->segmentBasis.y.z) +
                             (var_fs0 * arg0->segmentBasis.x.z);

            if (false) {
                // FAKE: ARTIFICIALLY INCREASE COMPILER STACK
                arg0->tiltUp.x = arg0->tiltUp.y = arg0->tiltUp.z;
            }

            var_fv1 = 1.0f / sqrtf(SQ(arg0->tiltUp.x) + SQ(arg0->tiltUp.y) + SQ(arg0->tiltUp.z));

            arg0->tiltUp.x *= var_fv1;
            arg0->tiltUp.y *= var_fv1;
            arg0->tiltUp.z *= var_fv1;

            if (arg0->heightAboveGround < 0.0f) {
                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.x;
                arg0->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
                arg0->segmentPositionInfo.pos.x -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.y;
                arg0->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
                arg0->segmentPositionInfo.pos.y -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.z;
                arg0->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
                arg0->segmentPositionInfo.pos.z -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

                arg0->segmentPositionInfo.distanceFromSegment =
                    sqrtf(SQ(arg0->segmentPositionInfo.segmentDisplacement.x) +
                          SQ(arg0->segmentPositionInfo.segmentDisplacement.y) +
                          SQ(arg0->segmentPositionInfo.segmentDisplacement.z));
                arg0->heightAboveGround = 0.0f;

                var_fs0 = (arg0->segmentBasis.y.x * arg0->velocity.x) + (arg0->segmentBasis.y.y * arg0->velocity.y) +
                          (arg0->segmentBasis.y.z * arg0->velocity.z);
                if (var_fs0 < 0.0f) {
                    arg0->velocity.x -= var_fs0 * arg0->segmentBasis.y.x;
                    arg0->velocity.y -= var_fs0 * arg0->segmentBasis.y.y;
                    arg0->velocity.z -= var_fs0 * arg0->segmentBasis.y.z;
                    if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                        func_800BB3C4(arg0->id, var_fs0);
                    }
                }
            }
        } else {
            arg0->tiltUp = arg0->unk_19C;
        }
        var_fs0 = ((arg0->tiltUp.x - arg0->segmentBasis.y.x) * sp60) + arg0->segmentBasis.y.x;
        sp58 = ((arg0->tiltUp.y - arg0->segmentBasis.y.y) * sp60) + arg0->segmentBasis.y.y;
        sp54 = ((arg0->tiltUp.z - arg0->segmentBasis.y.z) * sp60) + arg0->segmentBasis.y.z;

        var_fv1 = sqrtf(SQ(var_fs0) + SQ(sp58) + SQ(sp54));
        if (var_fv1 > 0.01f) {
            var_fv1 = 1.0f / var_fv1;
            arg0->tiltUp.x = var_fv1 * var_fs0;
            arg0->tiltUp.y = var_fv1 * sp58;
            arg0->tiltUp.z = var_fv1 * sp54;
        }

        arg0->gravityUp.x = ((arg0->unk_19C.x - arg0->segmentBasis.y.x) * sp60) + arg0->segmentBasis.y.x;
        arg0->gravityUp.y = ((arg0->unk_19C.y - arg0->segmentBasis.y.y) * sp60) + arg0->segmentBasis.y.y;
        arg0->gravityUp.z = ((arg0->unk_19C.z - arg0->segmentBasis.y.z) * sp60) + arg0->segmentBasis.y.z;
    } else {
        arg0->gravityUp = arg0->tiltUp = arg0->unk_19C;
    }

    if (arg0->currentRadiusLeft < arg0->segmentPositionInfo.distanceFromSegment) {
        var_fv1 = arg0->currentRadiusLeft / arg0->segmentPositionInfo.distanceFromSegment;
        arg0->segmentPositionInfo.distanceFromSegment = arg0->currentRadiusLeft;

        arg0->segmentPositionInfo.segmentDisplacement.x *= var_fv1;
        arg0->segmentPositionInfo.pos.x = arg0->segmentPositionInfo.lastGroundedPos.x =
            arg0->segmentPositionInfo.segmentDisplacement.x + arg0->segmentPositionInfo.segmentPos.x;

        arg0->segmentPositionInfo.segmentDisplacement.y *= var_fv1;
        arg0->segmentPositionInfo.pos.y = arg0->segmentPositionInfo.lastGroundedPos.y =
            arg0->segmentPositionInfo.segmentDisplacement.y + arg0->segmentPositionInfo.segmentPos.y;

        arg0->segmentPositionInfo.segmentDisplacement.z *= var_fv1;
        arg0->segmentPositionInfo.pos.z = arg0->segmentPositionInfo.lastGroundedPos.z =
            arg0->segmentPositionInfo.segmentDisplacement.z + arg0->segmentPositionInfo.segmentPos.z;

        arg0->heightAboveGround = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fs0 < 0.0f) {
            arg0->velocity.x -= var_fs0 * arg0->unk_19C.x;
            arg0->velocity.y -= var_fs0 * arg0->unk_19C.y;
            arg0->velocity.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                func_800BB3C4(arg0->id, var_fs0);
            }
        }
    }

    arg0->shadowPos.x = arg0->segmentPositionInfo.pos.x - (arg0->heightAboveGround * arg0->unk_19C.x);
    arg0->shadowPos.y = arg0->segmentPositionInfo.pos.y - (arg0->heightAboveGround * arg0->unk_19C.y);
    arg0->shadowPos.z = arg0->segmentPositionInfo.pos.z - (arg0->heightAboveGround * arg0->unk_19C.z);

    if (arg0->heightAboveGround <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
    }
}

void func_8008F550(Racer* arg0) {
    f32 var_fa1;
    f32 temp_fv1;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fv0;

    if (arg0->segmentPositionInfo.segmentTValue < arg0->segmentPositionInfo.courseSegment->unk_68) {
        sp5C = sp58 =
            arg0->segmentPositionInfo.segmentLengthProportion / arg0->segmentPositionInfo.courseSegment->unk_70;
        sp5C *= arg0->currentRadiusLeft;
        var_fa1 = arg0->currentRadiusLeft;
    } else if (arg0->segmentPositionInfo.courseSegment->unk_6C < arg0->segmentPositionInfo.segmentTValue) {
        var_fa1 = -arg0->currentRadiusLeft;
        sp5C = sp58 = (1.0f - arg0->segmentPositionInfo.segmentLengthProportion) /
                      arg0->segmentPositionInfo.courseSegment->unk_70;
        sp5C *= arg0->currentRadiusLeft;
    } else {
        var_fa1 = 0.0f;
        sp5C = arg0->currentRadiusLeft;
    }

    arg0->heightAboveGround = arg0->segmentPositionInfo.distanceFromSegment - sp5C;
    if (arg0->segmentPositionInfo.distanceFromSegment > 0.01f) {
        temp_fv1 = 1.0f / arg0->segmentPositionInfo.distanceFromSegment;
        arg0->unk_19C.x = arg0->segmentPositionInfo.segmentDisplacement.x * temp_fv1;
        arg0->unk_19C.y = arg0->segmentPositionInfo.segmentDisplacement.y * temp_fv1;
        arg0->unk_19C.z = arg0->segmentPositionInfo.segmentDisplacement.z * temp_fv1;
    }

    arg0->shadowPos.x = arg0->segmentPositionInfo.pos.x - (arg0->heightAboveGround * arg0->unk_19C.x);
    arg0->shadowPos.y = arg0->segmentPositionInfo.pos.y - (arg0->heightAboveGround * arg0->unk_19C.y);
    arg0->shadowPos.z = arg0->segmentPositionInfo.pos.z - (arg0->heightAboveGround * arg0->unk_19C.z);
    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((arg0->currentRadiusLeft + 200.0f) < arg0->segmentPositionInfo.distanceFromSegment) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->shadowPos.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else if ((arg0->currentRadiusLeft + 200.0f) < arg0->segmentPositionInfo.distanceFromSegment) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->shadowPos.y = -54321.0f;
        return;
    }

    if (var_fa1 != 0.0f) {

        sp54 = ((arg0->unk_19C.x - arg0->segmentBasis.y.x) * sp58) + arg0->segmentBasis.y.x;
        sp50 = ((arg0->unk_19C.y - arg0->segmentBasis.y.y) * sp58) + arg0->segmentBasis.y.y;
        sp4C = ((arg0->unk_19C.z - arg0->segmentBasis.y.z) * sp58) + arg0->segmentBasis.y.z;

        temp_fv1 = sqrtf(SQ(sp54) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->tiltUp.x = temp_fv1 * sp54;
            arg0->tiltUp.y = temp_fv1 * sp50;
            arg0->tiltUp.z = temp_fv1 * sp4C;
        }

        temp_fv1 = 1.0f - sp58;
        sp54 = arg0->segmentBasis.y.x * SQ(temp_fv1);
        sp50 = arg0->segmentBasis.y.y * SQ(temp_fv1);
        sp4C = arg0->segmentBasis.y.z * SQ(temp_fv1);

        arg0->gravityUp.x = ((arg0->unk_19C.x - sp54) * sp58) + sp54;
        arg0->gravityUp.y = ((arg0->unk_19C.y - sp50) * sp58) + sp50;
        arg0->gravityUp.z = ((arg0->unk_19C.z - sp4C) * sp58) + sp4C;
        temp_fv1 = (sp58 * 200.0f) + sp5C + (arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                   (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                   (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z);
        if (temp_fv1 < arg0->heightAboveGround) {
            arg0->heightAboveGround = temp_fv1;
            arg0->unk_19C.x = arg0->segmentBasis.y.x;
            arg0->unk_19C.y = arg0->segmentBasis.y.y;
            arg0->unk_19C.z = arg0->segmentBasis.y.z;
            if (arg0->heightAboveGround < 0.0f) {

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.x;
                arg0->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
                arg0->segmentPositionInfo.pos.x -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.y;
                arg0->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
                arg0->segmentPositionInfo.pos.y -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.z;
                arg0->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
                arg0->segmentPositionInfo.pos.z -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

                arg0->segmentPositionInfo.distanceFromSegment =
                    sqrtf(SQ(arg0->segmentPositionInfo.segmentDisplacement.x) +
                          SQ(arg0->segmentPositionInfo.segmentDisplacement.y) +
                          SQ(arg0->segmentPositionInfo.segmentDisplacement.z));
                arg0->heightAboveGround = 0.0f;
            }
        }
    } else {
        arg0->gravityUp = arg0->tiltUp = arg0->unk_19C;
    }

    if (arg0->segmentPositionInfo.distanceFromSegment < sp5C) {
        temp_fv1 = sp5C / arg0->segmentPositionInfo.distanceFromSegment;
        arg0->segmentPositionInfo.distanceFromSegment = sp5C;

        arg0->segmentPositionInfo.segmentDisplacement.x *= temp_fv1;
        temp_fv0 = arg0->segmentPositionInfo.segmentDisplacement.x + arg0->segmentPositionInfo.segmentPos.x;
        arg0->segmentPositionInfo.lastGroundedPos.x = temp_fv0;
        arg0->segmentPositionInfo.pos.x = temp_fv0;

        arg0->segmentPositionInfo.segmentDisplacement.y *= temp_fv1;
        temp_fv0 = arg0->segmentPositionInfo.segmentDisplacement.y + arg0->segmentPositionInfo.segmentPos.y;
        arg0->segmentPositionInfo.lastGroundedPos.y = temp_fv0;
        arg0->segmentPositionInfo.pos.y = temp_fv0;

        arg0->segmentPositionInfo.segmentDisplacement.z *= temp_fv1;
        temp_fv0 = arg0->segmentPositionInfo.segmentDisplacement.z + arg0->segmentPositionInfo.segmentPos.z;
        arg0->segmentPositionInfo.lastGroundedPos.z = temp_fv0;
        arg0->segmentPositionInfo.pos.z = temp_fv0;

        arg0->heightAboveGround = 0.0f;

        var_fa1 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fa1 < 0.0f) {
            arg0->velocity.x -= (var_fa1 * arg0->unk_19C.x);
            arg0->velocity.y -= (var_fa1 * arg0->unk_19C.y);
            arg0->velocity.z -= (var_fa1 * arg0->unk_19C.z);

            if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                func_800BB3C4(arg0->id, var_fa1);
            }
        }
    }

    if (arg0->heightAboveGround <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
    }
}

void func_8008FC80(Racer* arg0) {
    f32 var_fv0;
    f32 var_fs0;
    f32 temp_fv1;
    f32 sp58;
    f32 temp_fv0;
    f32 sp50;
    f32 sp4C;

    if (arg0->segmentPositionInfo.segmentTValue < arg0->segmentPositionInfo.courseSegment->unk_68) {
        var_fv0 = sp58 =
            arg0->segmentPositionInfo.segmentLengthProportion / arg0->segmentPositionInfo.courseSegment->unk_70;
        var_fv0 *= arg0->currentRadiusLeft;
        var_fs0 = arg0->currentRadiusLeft;
    } else if (arg0->segmentPositionInfo.courseSegment->unk_6C < arg0->segmentPositionInfo.segmentTValue) {
        var_fv0 = sp58 = (1.0f - arg0->segmentPositionInfo.segmentLengthProportion) /
                         arg0->segmentPositionInfo.courseSegment->unk_70;
        var_fv0 *= arg0->currentRadiusLeft;
        var_fs0 = -arg0->currentRadiusLeft;
    } else {
        var_fv0 = arg0->currentRadiusLeft;
        var_fs0 = 0.0f;
    }

    arg0->heightAboveGround = arg0->currentRadiusLeft - arg0->segmentPositionInfo.distanceFromSegment;
    if (arg0->segmentPositionInfo.distanceFromSegment > 0.01f) {
        temp_fv1 = -1.0f / arg0->segmentPositionInfo.distanceFromSegment;
        arg0->unk_19C.x = arg0->segmentPositionInfo.segmentDisplacement.x * temp_fv1;
        arg0->unk_19C.y = arg0->segmentPositionInfo.segmentDisplacement.y * temp_fv1;
        arg0->unk_19C.z = arg0->segmentPositionInfo.segmentDisplacement.z * temp_fv1;
    }

    temp_fv1 = (((arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                 (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                 (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z)) -
                23.0f) +
               (var_fv0 * 0.3826834f);
    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((temp_fv1 >= 0.0f) || (arg0->currentRadiusLeft < arg0->segmentPositionInfo.distanceFromSegment)) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->shadowPos.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;

    } else if (temp_fv1 >= 0.0f) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->shadowPos.y = -54321.0f;
        return;
    }

    if (var_fs0 != 0.0f) {
        temp_fv1 = var_fv0 + (arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                   (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                   (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z);
        if (temp_fv1 < arg0->heightAboveGround) {
            arg0->heightAboveGround = temp_fv1;
            arg0->unk_19C.x = arg0->segmentBasis.y.x;
            arg0->unk_19C.y = arg0->segmentBasis.y.y;
            arg0->unk_19C.z = arg0->segmentBasis.y.z;
            arg0->tiltUp.x = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.x) +
                             (var_fs0 * arg0->segmentBasis.x.x);
            arg0->tiltUp.y = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.y) +
                             (var_fs0 * arg0->segmentBasis.x.y);
            arg0->tiltUp.z = (D_800CF8E8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.z) +
                             (var_fs0 * arg0->segmentBasis.x.z);

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->tiltUp.x) + SQ(arg0->tiltUp.y) + SQ(arg0->tiltUp.z));

            arg0->tiltUp.x *= temp_fv1;
            arg0->tiltUp.y *= temp_fv1;
            arg0->tiltUp.z *= temp_fv1;

            if (arg0->heightAboveGround < 0.0f) {
                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.x;
                arg0->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
                arg0->segmentPositionInfo.pos.x -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.y;
                arg0->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
                arg0->segmentPositionInfo.pos.y -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

                temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.z;
                arg0->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
                arg0->segmentPositionInfo.pos.z -= temp_fv0;
                arg0->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

                arg0->segmentPositionInfo.distanceFromSegment =
                    sqrtf(SQ(arg0->segmentPositionInfo.segmentDisplacement.x) +
                          SQ(arg0->segmentPositionInfo.segmentDisplacement.y) +
                          SQ(arg0->segmentPositionInfo.segmentDisplacement.z));
                arg0->heightAboveGround = 0.0f;

                var_fs0 = (arg0->segmentBasis.y.x * arg0->velocity.x) + (arg0->segmentBasis.y.y * arg0->velocity.y) +
                          (arg0->segmentBasis.y.z * arg0->velocity.z);
                if (var_fs0 < 0.0f) {
                    arg0->velocity.x -= var_fs0 * arg0->segmentBasis.y.x;
                    arg0->velocity.y -= var_fs0 * arg0->segmentBasis.y.y;
                    arg0->velocity.z -= var_fs0 * arg0->segmentBasis.y.z;
                    if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                        func_800BB3C4(arg0->id, var_fs0);
                    }
                }
            }
        } else {
            arg0->tiltUp = arg0->unk_19C;
        }

        var_fs0 = ((arg0->tiltUp.x - arg0->segmentBasis.y.x) * sp58) + arg0->segmentBasis.y.x;
        sp50 = ((arg0->tiltUp.y - arg0->segmentBasis.y.y) * sp58) + arg0->segmentBasis.y.y;
        sp4C = ((arg0->tiltUp.z - arg0->segmentBasis.y.z) * sp58) + arg0->segmentBasis.y.z;

        temp_fv1 = sqrtf(SQ(var_fs0) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->tiltUp.x = temp_fv1 * var_fs0;
            arg0->tiltUp.y = temp_fv1 * sp50;
            arg0->tiltUp.z = temp_fv1 * sp4C;
        }
    } else {
        arg0->tiltUp = arg0->unk_19C;
    }

    if (arg0->currentRadiusLeft < arg0->segmentPositionInfo.distanceFromSegment) {
        temp_fv1 = arg0->currentRadiusLeft / arg0->segmentPositionInfo.distanceFromSegment;
        arg0->segmentPositionInfo.distanceFromSegment = arg0->currentRadiusLeft;

        arg0->segmentPositionInfo.segmentDisplacement.x *= temp_fv1;
        arg0->segmentPositionInfo.pos.x = arg0->segmentPositionInfo.lastGroundedPos.x =
            arg0->segmentPositionInfo.segmentDisplacement.x + arg0->segmentPositionInfo.segmentPos.x;
        arg0->segmentPositionInfo.segmentDisplacement.y *= temp_fv1;
        arg0->segmentPositionInfo.pos.y = arg0->segmentPositionInfo.lastGroundedPos.y =
            arg0->segmentPositionInfo.segmentDisplacement.y + arg0->segmentPositionInfo.segmentPos.y;
        arg0->segmentPositionInfo.segmentDisplacement.z *= temp_fv1;
        arg0->segmentPositionInfo.pos.z = arg0->segmentPositionInfo.lastGroundedPos.z =
            arg0->segmentPositionInfo.segmentDisplacement.z + arg0->segmentPositionInfo.segmentPos.z;

        arg0->heightAboveGround = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fs0 < 0.0f) {
            arg0->velocity.x -= var_fs0 * arg0->unk_19C.x;
            arg0->velocity.y -= var_fs0 * arg0->unk_19C.y;
            arg0->velocity.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                func_800BB3C4(arg0->id, var_fs0);
            }
        }
    }

    arg0->gravityUp.x = arg0->segmentBasis.y.x;
    arg0->gravityUp.y = arg0->segmentBasis.y.y;
    arg0->gravityUp.z = arg0->segmentBasis.y.z;
    arg0->shadowPos.x = arg0->segmentPositionInfo.pos.x - (arg0->heightAboveGround * arg0->unk_19C.x);
    arg0->shadowPos.y = arg0->segmentPositionInfo.pos.y - (arg0->heightAboveGround * arg0->unk_19C.y);
    arg0->shadowPos.z = arg0->segmentPositionInfo.pos.z - (arg0->heightAboveGround * arg0->unk_19C.z);

    if (arg0->heightAboveGround <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
    }
}

void func_80090490(Racer* arg0) {

    arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
    if (arg0->id < gNumPlayers) {
        if (!(arg0->unk_08 & 0x2000)) {
            arg0->unk_08 |= 0x2000;
            if (gEnableRaceSfx) {
                Audio_PlayerLevelSEStart(arg0->id, 8);
            }
        }
    }

    arg0->shadowPos.y = -54321.0f;

    arg0->heightAboveGround = (arg0->segmentPositionInfo.segmentDisplacement.x * arg0->segmentBasis.y.x) +
                              (arg0->segmentPositionInfo.segmentDisplacement.y * arg0->segmentBasis.y.y) +
                              (arg0->segmentPositionInfo.segmentDisplacement.z * arg0->segmentBasis.y.z);

    arg0->unk_19C.x = arg0->segmentBasis.y.x;
    arg0->unk_19C.y = arg0->segmentBasis.y.y;
    arg0->unk_19C.z = arg0->segmentBasis.y.z;
    func_8008E418(arg0);
    func_8008E504(arg0);
}

void func_80090568(Racer* arg0) {
    f32 temp_fv1;
    f32 sp48;
    f32 temp_fv0;

    sp48 = (arg0->segmentBasis.z.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
           (arg0->segmentBasis.z.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
           (arg0->segmentBasis.z.z * arg0->segmentPositionInfo.segmentDisplacement.z);

    arg0->heightAboveGround = (arg0->segmentBasis.y.x * arg0->segmentPositionInfo.segmentDisplacement.x) +
                              (arg0->segmentBasis.y.y * arg0->segmentPositionInfo.segmentDisplacement.y) +
                              (arg0->segmentBasis.y.z * arg0->segmentPositionInfo.segmentDisplacement.z);

    arg0->unk_19C.x = arg0->segmentBasis.y.x;
    arg0->unk_19C.y = arg0->segmentBasis.y.y;
    arg0->unk_19C.z = arg0->segmentBasis.y.z;

    // FAKE
    if ((arg0->stateFlags ^ 0) & RACER_STATE_FLAGS_80000000) {
        if ((arg0->heightAboveGround < -100.0f) || (arg0->heightAboveGround > 30.0f) ||
            (sp48 < -arg0->currentRadiusRight) || (arg0->currentRadiusLeft < sp48)) {
            func_8008E418(arg0);
            func_8008E504(arg0);
            arg0->shadowPos.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else if ((arg0->heightAboveGround > 30.0f) || (sp48 < -arg0->currentRadiusRight) ||
               (arg0->currentRadiusLeft < sp48)) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);
        arg0->shadowPos.y = -54321.0f;
        return;
    }

    if (arg0->heightAboveGround < 0.0f) {

        temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.x;
        arg0->segmentPositionInfo.segmentDisplacement.x -= temp_fv0;
        arg0->segmentPositionInfo.pos.x -= temp_fv0;
        arg0->segmentPositionInfo.lastGroundedPos.x -= temp_fv0;

        temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.y;
        arg0->segmentPositionInfo.segmentDisplacement.y -= temp_fv0;
        arg0->segmentPositionInfo.pos.y -= temp_fv0;
        arg0->segmentPositionInfo.lastGroundedPos.y -= temp_fv0;

        temp_fv0 = arg0->heightAboveGround * arg0->segmentBasis.y.z;
        arg0->segmentPositionInfo.segmentDisplacement.z -= temp_fv0;
        arg0->segmentPositionInfo.pos.z -= temp_fv0;
        arg0->segmentPositionInfo.lastGroundedPos.z -= temp_fv0;

        arg0->heightAboveGround = 0.0f;
        sp48 = (arg0->segmentBasis.y.x * arg0->velocity.x) + (arg0->segmentBasis.y.y * arg0->velocity.y) +
               (arg0->segmentBasis.y.z * arg0->velocity.z);

        if (sp48 < 0.0f) {
            arg0->velocity.x -= sp48 * arg0->segmentBasis.y.x;
            arg0->velocity.y -= sp48 * arg0->segmentBasis.y.y;
            arg0->velocity.z -= sp48 * arg0->segmentBasis.y.z;
            if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
                func_800BB3C4(arg0->id, sp48);
            }
        }
    }

    if (arg0->heightAboveGround <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(arg0->id, 8);
                }
            }
        }
        arg0->gravityUp.x = arg0->tiltUp.x = arg0->segmentBasis.y.x;
        arg0->gravityUp.y = arg0->tiltUp.y = arg0->segmentBasis.y.y;
        arg0->gravityUp.z = arg0->tiltUp.z = arg0->segmentBasis.y.z;
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(arg0->id, 8);
                }
            }
        }
        func_8008E418(arg0);
        func_8008E504(arg0);

        if (arg0->heightAboveGround < 30.0f) {
            temp_fv1 = (arg0->heightAboveGround - 15.0f) / 15.0f;

            arg0->gravityUp.x = ((arg0->gravityUp.x - arg0->segmentBasis.y.x) * temp_fv1) + arg0->segmentBasis.y.x;
            arg0->gravityUp.y = ((arg0->gravityUp.y - arg0->segmentBasis.y.y) * temp_fv1) + arg0->segmentBasis.y.y;
            arg0->gravityUp.z = ((arg0->gravityUp.z - arg0->segmentBasis.y.z) * temp_fv1) + arg0->segmentBasis.y.z;

            arg0->tiltUp.x = ((arg0->tiltUp.x - arg0->segmentBasis.y.x) * temp_fv1) + arg0->tiltUp.x;
            arg0->tiltUp.y = ((arg0->tiltUp.y - arg0->segmentBasis.y.y) * temp_fv1) + arg0->tiltUp.y;
            arg0->tiltUp.z = ((arg0->tiltUp.z - arg0->segmentBasis.y.z) * temp_fv1) + arg0->tiltUp.z;

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->tiltUp.x) + SQ(arg0->tiltUp.y) + SQ(arg0->tiltUp.z));
            arg0->tiltUp.x *= temp_fv1;
            arg0->tiltUp.y *= temp_fv1;
            arg0->tiltUp.z *= temp_fv1;
        }
    }
    arg0->shadowPos.x = arg0->segmentPositionInfo.pos.x - (arg0->heightAboveGround * arg0->segmentBasis.y.x);
    arg0->shadowPos.y = arg0->segmentPositionInfo.pos.y - (arg0->heightAboveGround * arg0->segmentBasis.y.y);
    arg0->shadowPos.z = arg0->segmentPositionInfo.pos.z - (arg0->heightAboveGround * arg0->segmentBasis.y.z);
}

void func_80090AFC(Racer* arg0) {

    if (!(arg0->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
        func_8008DBB8(arg0, 120);
    }
    arg0->stateFlags = (arg0->stateFlags & ~RACER_STATE_FLAGS_400000) | RACER_STATE_FALLING_OFF_TRACK;

    if ((arg0->id < gNumPlayers) && gEnableRaceSfx) {
        if (sCharacterVoices[arg0->character] != VOICE_FEMALE) {
            Audio_PlayerTriggerSEStart(arg0->id, 52);
        } else {
            Audio_PlayerTriggerSEStart(arg0->id, 53);
        }
        func_800894C0(arg0);
    }
}

extern u32 gGameFrameCount;

#ifdef NON_MATCHING
void func_80090BCC(Racer* racer, Controller* controller) {
    bool var_v1;
    s32 i;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    f32 var_fa1; // sp130
    f32 sp12C;
    f32 sp128;
    f32 var_fv1;
    f32 var_fs1;
    f32 var_fs0;
    f32 var_ft4; // sp118
    Vec3f sp10C;
    Mtx3F spE8;
    f32 spE4;
    CourseSegment* temp_v1;
    unk_802D3E38* temp_a0;
    unk_802D3E38* var_v0;
    unk_802D3978* var_v0_2;
    unk_802D3978* temp2;
    unk_802D3D38* var_v0_3;
    unk_802D3D38* temp;
    u16 buttonReleased; // spC6
    u16 buttonCurrent;
    u16 buttonPressed;
    f32 temp_fa0;
    s32 pad;

    if (!(racer->stateFlags & RACER_STATE_FLAGS_400000)) {
        buttonReleased = 0;
        buttonPressed = 0;
        buttonCurrent = 0;
        racer->unk_E4 = 0.0f;
        sp12C = racer->unk_238;
        racer->unk_238 *= 0.99f;
    } else {
        buttonCurrent = controller->buttonCurrent;
        buttonPressed = controller->buttonPressed;
        buttonReleased = controller->buttonReleased;
        racer->unk_E4 = controller->stickY / 63.0f;

        if (racer->unk_E4 < -1.0f) {
            racer->unk_E4 = -1.0f;
        } else if (racer->unk_E4 > 1.0f) {
            racer->unk_E4 = 1.0f;
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
    temp_v1 = racer->segmentPositionInfo.courseSegment;

    racer->stateFlags &= ~COURSE_EFFECT_MASK;
    var_v0 = temp_v1->unk_54;
    if ((var_v0 != NULL) && !(racer->stateFlags & RACER_STATE_AIRBORNE)) {
        temp_a0 = temp_v1->unk_58;
        if (temp_v1->trackSegmentInfo & TRACK_FLAG_8000000) {
            var_fa1 = (racer->segmentPositionInfo.segmentDisplacement.x * racer->segmentBasis.z.x) +
                      (racer->segmentPositionInfo.segmentDisplacement.y * racer->segmentBasis.z.y) +
                      (racer->segmentPositionInfo.segmentDisplacement.z * racer->segmentBasis.z.z) +
                      (0.5f * (racer->currentRadiusRight - racer->currentRadiusLeft));

            do {
                if (var_fa1 < var_v0->unk_0C.x) {
                    continue;
                }
                if (var_v0->unk_18.x < var_fa1) {
                    continue;
                }
                if (racer->segmentPositionInfo.segmentTValue < var_v0->unk_04) {
                    continue;
                }
                if (var_v0->unk_08 < racer->segmentPositionInfo.segmentTValue) {
                    continue;
                }
                racer->stateFlags |= var_v0->effectType;
                break;
            } while (++var_v0 != temp_a0);

        } else {

            do {
                if (racer->segmentPositionInfo.segmentTValue < var_v0->unk_04) {
                    continue;
                }

                if (var_v0->unk_08 < racer->segmentPositionInfo.segmentTValue) {
                    continue;
                }

                if ((((racer->segmentPositionInfo.segmentDisplacement.y * var_v0->unk_0C.z) -
                      (racer->segmentPositionInfo.segmentDisplacement.z * var_v0->unk_0C.y)) *
                     racer->segmentBasis.x.x) +
                        (((racer->segmentPositionInfo.segmentDisplacement.z * var_v0->unk_0C.x) -
                          (racer->segmentPositionInfo.segmentDisplacement.x * var_v0->unk_0C.z)) *
                         racer->segmentBasis.x.y) +
                        (((racer->segmentPositionInfo.segmentDisplacement.x * var_v0->unk_0C.y) -
                          (racer->segmentPositionInfo.segmentDisplacement.y * var_v0->unk_0C.x)) *
                         racer->segmentBasis.x.z) <
                    0.0f) {
                    continue;
                }

                if ((((var_v0->unk_18.y * racer->segmentPositionInfo.segmentDisplacement.z) -
                      (var_v0->unk_18.z * racer->segmentPositionInfo.segmentDisplacement.y)) *
                     racer->segmentBasis.x.x) +
                        (((var_v0->unk_18.z * racer->segmentPositionInfo.segmentDisplacement.x) -
                          (var_v0->unk_18.x * racer->segmentPositionInfo.segmentDisplacement.z)) *
                         racer->segmentBasis.x.y) +
                        (((var_v0->unk_18.x * racer->segmentPositionInfo.segmentDisplacement.y) -
                          (var_v0->unk_18.y * racer->segmentPositionInfo.segmentDisplacement.x)) *
                         racer->segmentBasis.x.z) <
                    0.0f) {
                    continue;
                }

                racer->stateFlags |= var_v0->effectType;
                break;

            } while (++var_v0 != temp_a0);
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
                if (racer->unk_1D8 != 0.f) {
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

        temp_fa0 = 1.0f / sqrtf(SQ(racer->trueBasis.z.x) + SQ(racer->trueBasis.z.y) + SQ(racer->trueBasis.z.z));
        racer->trueBasis.z.x *= temp_fa0;
        racer->trueBasis.z.y *= temp_fa0;
        racer->trueBasis.z.z *= temp_fa0;

        var_fs1 -= racer->trueBasis.x.x =
            (racer->trueBasis.z.y * racer->trueBasis.y.z) - (racer->trueBasis.z.z * racer->trueBasis.y.y);
        var_fs0 -= racer->trueBasis.x.y =
            (racer->trueBasis.z.z * racer->trueBasis.y.x) - (racer->trueBasis.z.x * racer->trueBasis.y.z);
        var_ft4 -= racer->trueBasis.x.z =
            (racer->trueBasis.z.x * racer->trueBasis.y.y) - (racer->trueBasis.z.y * racer->trueBasis.y.x);
        spE4 = sqrtf(SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4));
    } else {
        spE4 = 0.0f;
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
            if (!(racer->unk_08 & 0x400)) {
                racer->unk_08 |= 0x400;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, 5);
                }
            }
        }
    } else if (racer->id < gNumPlayers) {
        if (racer->unk_08 & 0x400) {
            racer->unk_08 &= ~0x400;
            if (gEnableRaceSfx) {
                Audio_PlayerLevelSEStop(racer->id, 5);
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
            if (!(racer->unk_08 & 0x80)) {
                racer->unk_08 |= 0x80;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, 9);
                }
            }
        }
    } else if (racer->id < gNumPlayers) {
        if (racer->unk_08 & 0x80) {
            racer->unk_08 &= ~0x80;
            if (gEnableRaceSfx) {
                Audio_PlayerLevelSEStop(racer->id, 9);
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
        racer->unk_08 |= 0x1000;
        if (gEnableRaceSfx) {
            Audio_PlayerTriggerSEStart(racer->id, 7);
        }
    } else {
        if ((racer->stateFlags & (RACER_STATE_CRASHED | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DASH) {
            buttonCurrent |= BTN_A;
            racer->shadowColorStrength = 1.3f;
            racer->shadowBaseR = 255.0f;
            racer->shadowBaseG = 223.0f;
            racer->shadowBaseB = 0.0f;
            racer->stateFlags |= RACER_STATE_DASH_PAD_BOOST;
            racer->boostTimer = sInitialBoostTimer;
            if (!(racer->unk_08 & 0x1000)) {
                racer->unk_08 |= 0x1000;
                if (gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, 7);
                }
            }
        } else {
            racer->unk_08 &= ~0x1000;
        }
    }

    if (!(racer->stateFlags & RACER_STATE_TOUCHING_LANDMINE)) {
        temp_v1 = racer->segmentPositionInfo.courseSegment;
        var_v0_2 = temp_v1->unk_4C;
        if (var_v0_2 != NULL) {
            temp2 = temp_v1->unk_50;
            do {
                var_fs1 = var_v0_2->unk_04.x - racer->segmentPositionInfo.pos.x;
                var_fs0 = var_v0_2->unk_04.y - racer->segmentPositionInfo.pos.y;
                var_ft4 = var_v0_2->unk_04.z - racer->segmentPositionInfo.pos.z;
                if ((SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4)) < 900.0f) {
                    racer->acceleration.x += (15.0f * racer->tiltUp.x);
                    racer->acceleration.y += (15.0f * racer->tiltUp.y);
                    racer->acceleration.z += (15.0f * racer->tiltUp.z);
                    racer->stateFlags |= RACER_STATE_TOUCHING_LANDMINE;
                    func_8008DCD8(racer, 12.5f);
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 1);
                    }
                    break;
                }
            } while (++var_v0_2 != temp2);
        }
    }

    if (!(racer->stateFlags & RACER_STATE_JUMP_BOOST)) {
        temp_v1 = racer->segmentPositionInfo.courseSegment;
        var_v0_3 = temp_v1->unk_44;
        if (var_v0_3 != NULL) {
            temp = temp_v1->unk_48;
            do {
                var_fs1 = racer->segmentPositionInfo.pos.x - var_v0_3->unk_00.x;
                var_fs0 = racer->segmentPositionInfo.pos.y - var_v0_3->unk_00.y;
                var_ft4 = racer->segmentPositionInfo.pos.z - var_v0_3->unk_00.z;
                var_fa1 = (var_v0_3->unk_0C.x.x * var_fs1) + (var_v0_3->unk_0C.x.y * var_fs0) +
                          (var_v0_3->unk_0C.x.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.z < var_fa1) {
                    continue;
                }

                var_fa1 = (var_v0_3->unk_0C.z.x * var_fs1) + (var_v0_3->unk_0C.z.y * var_fs0) +
                          (var_v0_3->unk_0C.z.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.x < var_fa1) {
                    continue;
                }

                var_fa1 = (var_v0_3->unk_0C.y.x * var_fs1) + (var_v0_3->unk_0C.y.y * var_fs0) +
                          (var_v0_3->unk_0C.y.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.y < var_fa1) {
                    continue;
                }

                racer->stateFlags |= RACER_STATE_JUMP_BOOST;
                racer->unk_1DC = (racer->speed * 0.3f) + 0.5f;
                if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, 0x37);
                }
                break;

            } while (++var_v0_3 != temp);
        }
    }
    racer->acceleration.x += (-1.0f * racer->gravityUp.x);
    racer->acceleration.y += (-1.0f * racer->gravityUp.y);
    racer->acceleration.z += (-1.0f * racer->gravityUp.z);
    if (racer->stateFlags & RACER_STATE_JUMP_BOOST) {
        racer->acceleration.x += (racer->unk_1DC * racer->tiltUp.x);
        racer->acceleration.y += (racer->unk_1DC * racer->tiltUp.y);
        racer->acceleration.z += (racer->unk_1DC * racer->tiltUp.z);
        racer->unk_1DC *= 0.8f;
    }
    if (!(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        var_fa1 = racer->unk_17C - racer->heightAboveGround;
        if (var_fa1 > 0.0f) {
            var_fa1 -= ((racer->velocity.x * racer->unk_19C.x) + (racer->velocity.y * racer->unk_19C.y) +
                        (racer->velocity.z * racer->unk_19C.z));

            racer->unk_198 = var_fa1 * 0.2f;

            racer->acceleration.x += (racer->unk_198 * racer->unk_19C.x);
            racer->acceleration.y += (racer->unk_198 * racer->unk_19C.y);
            racer->acceleration.z += (racer->unk_198 * racer->unk_19C.z);
            if (racer->unk_1DC < 0.5f) {
                racer->stateFlags &= ~(RACER_STATE_JUMP_BOOST | RACER_STATE_TOUCHING_LANDMINE);
            }
        } else {
            racer->unk_198 = 0.0f;
        }
    } else {
        racer->unk_198 = 0.0f;
    }
    racer->unk_278++;
    racer->unk_27A++;
    if (buttonPressed & BTN_R_Z_COMBO) {
        buttonPressed |= BTN_Z;
        buttonCurrent |= BTN_R;
        racer->unk_278 = 10;
    } else if (buttonPressed & BTN_Z_R_COMBO) {
        buttonCurrent |= BTN_Z;
        buttonPressed |= BTN_R;
        racer->unk_27A = 10;
    }

    switch (buttonPressed & (BTN_Z | BTN_R)) {
        case BTN_Z:
            if ((racer->unk_278 < 0xF) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0x80;
                racer->unk_280 = 0x100;
                if (buttonCurrent & BTN_R) {
                    racer->unk_284 = 2;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 2);
                    }
                } else {
                    racer->unk_284 = 1;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 6);
                    }
                }
            }
            racer->unk_278 = 0;
            break;
        case BTN_R:
            if ((racer->unk_27A < 0xF) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0xF80;
                racer->unk_280 = -0x100;
                if (buttonCurrent & BTN_Z) {
                    racer->unk_284 = 2;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 2);
                    }
                } else {
                    racer->unk_284 = 1;
                    if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 6);
                    }
                }
            }
            racer->unk_27A = 0;
            break;
        default:
            break;
    }

    var_v1 = false;
    if (racer->unk_284 == 1) {
        if (racer->unk_280 < 0) {
            racer->unk_286 = 1;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->unk_286 = 0;
        }
        if (var_fa1 < 0.0f) {
            racer->unk_1D8 = 5.0f;
        } else if (var_fa1 < 6.0f) {
            racer->unk_1D8 = 5.0f - (0.8333333f * var_fa1);
        } else {
            racer->unk_1D8 = 0.0f;
        }

        var_fs1 = racer->unk_1D8 * racer->trueBasis.z.x;
        var_fs0 = racer->unk_1D8 * racer->trueBasis.z.y;
        var_ft4 = racer->unk_1D8 * racer->trueBasis.z.z;
        var_fa1 = (racer->gravityUp.x * var_fs1) + (var_fs0 * racer->gravityUp.y) + (var_ft4 * racer->gravityUp.z);
        if (racer->unk_286 == 1) {
            racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->gravityUp.x));
            racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->gravityUp.y));
            racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->gravityUp.z));
        } else {
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->gravityUp.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->gravityUp.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->gravityUp.z));
        }
    } else if (racer->unk_284 == 2) {
        if (racer->unk_280 < 0) {
            racer->unk_286 = 1;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->unk_286 = 0;
        }
        if (var_fa1 < 0.0f) {
            racer->unk_1D8 = 0.5f;
        } else if (var_fa1 < 2.0f) {
            racer->unk_1D8 = 0.5f - (0.25f * var_fa1);
        } else {
            racer->unk_1D8 = 0.0f;
        }

        var_fs1 = racer->unk_1D8 * racer->trueBasis.z.x;
        var_fs0 = racer->unk_1D8 * racer->trueBasis.z.y;
        var_ft4 = racer->unk_1D8 * racer->trueBasis.z.z;
        if (racer->unk_286 == 1) {
            racer->acceleration.x -= var_fs1;
            racer->acceleration.y -= var_fs0;
            racer->acceleration.z -= var_ft4;
        } else {
            racer->acceleration.x += var_fs1;
            racer->acceleration.y += var_fs0;
            racer->acceleration.z += var_ft4;
        }
    } else {
        switch (buttonCurrent & (BTN_Z | BTN_R)) {
            case 0:
            case (BTN_Z | BTN_R):
                racer->unk_1D8 = 0.0f;
                break;
            default:
                if ((buttonCurrent & (BTN_Z | BTN_R)) == BTN_Z) {
                    var_fa1 = racer->unk_5C.x;
                    racer->unk_286 = 0;
                } else {
                    racer->unk_286 = 1;
                    var_fa1 = -racer->unk_5C.x;
                }
                if (var_fa1 < 0.0f) {
                    racer->unk_1D8 = 1.0f;
                } else if (var_fa1 < 8.0f) {
                    racer->unk_1D8 = 1.0f - (0.125f * var_fa1);
                } else {
                    racer->unk_1D8 = 0.0f;
                }
                if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
                    racer->unk_1D8 *= 0.2f;
                }

                var_fs1 = racer->unk_1D8 * racer->trueBasis.z.x;
                var_fs0 = racer->unk_1D8 * racer->trueBasis.z.y;
                var_ft4 = racer->unk_1D8 * racer->trueBasis.z.z;
                var_fa1 =
                    (racer->gravityUp.x * var_fs1) + (var_fs0 * racer->gravityUp.y) + (var_ft4 * racer->gravityUp.z);
                if (racer->unk_286 == 1) {
                    racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->gravityUp.x));
                    racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->gravityUp.y));
                    racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->gravityUp.z));
                } else {
                    racer->acceleration.x += (var_fs1 - (var_fa1 * racer->gravityUp.x));
                    racer->acceleration.y += (var_fs0 - (var_fa1 * racer->gravityUp.y));
                    racer->acceleration.z += (var_ft4 - (var_fa1 * racer->gravityUp.z));
                }

                var_v1 = true;
                break;
        }
    }
    if (racer->id < gNumPlayers) {
        if (var_v1) {
            if (!(racer->unk_08 & 0x40)) {
                racer->unk_08 |= 0x40;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, 0xA);
                }
            }
        } else {
            if (racer->unk_08 & 0x40) {
                racer->unk_08 &= ~0x40;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, 0xA);
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
            racer->unk_204 = 0x1E;
            racer->unk_214 = 0x1B;
            if ((racer->id < gNumPlayers) && gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(racer->id, 0x29);
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
                if (!(racer->unk_08 & 0x200)) {
                    racer->unk_08 |= 0x200;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStart(racer->id, 6);
                    }
                }
            }
        } else {
            racer->unk_20C = 0;
            if (racer->id < gNumPlayers) {
                if (racer->unk_08 & 0x200) {
                    racer->unk_08 &= ~0x200;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStop(racer->id, 6);
                    }
                }
            }
        }
    } else {
        racer->unk_20C = 0;
        if (racer->id < gNumPlayers) {
            if (racer->unk_08 & 0x200) {
                racer->unk_08 &= ~0x200;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, 6);
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
        }
        racer->boostTimer--;
        if (racer->boostTimer == 0) {
            racer->stateFlags &= ~RACER_STATE_DASH_PAD_BOOST;
            racer->unk_08 &= ~0x1000;
        }
    }
    var_fs1 *= var_ft4;
    var_fs0 *= var_ft4;

    if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x20)) {
                racer->unk_08 |= 0x20;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, 0xB);
                }
            }
        }
        var_ft4 = racer->speed;
    } else {
        if (racer->id < gNumPlayers) {
            if (racer->unk_08 & 0x20) {
                racer->unk_08 &= ~0x20;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStop(racer->id, 0xB);
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
                    var_fv1 = ((D_800CF174[4] - var_fs0) * racer->unk_1E8) + var_fs0;
                }
            }
        }
        var_fv1 -= ((spE4 * 0.5f) + (racer->unk_1D8 * 0.16f));
        if (var_fv1 < 0.0f) {
            racer->unk_1D4 = 0.0f;
        } else {
            if (var_fv1 <= racer->unk_1D4) {
                racer->unk_1D4 = var_fv1;
            } else {
                var_ft4 *= racer->unk_324;
                if (var_ft4 < 1.0f) {
                    var_ft4 = (racer->unk_328 * var_ft4) + racer->unk_1D0;
                } else {
                    var_ft4 = 1.0f;
                }
                racer->unk_1D4 += ((var_fv1 - racer->unk_1D4) * var_ft4);
            }

            var_fs1 = racer->unk_1D4 * racer->trueBasis.x.x;
            var_fs0 = racer->unk_1D4 * racer->trueBasis.x.y;
            var_ft4 = racer->unk_1D4 * racer->trueBasis.x.z;
            var_fa1 = (racer->gravityUp.x * var_fs1) + (var_fs0 * racer->gravityUp.y) + (var_ft4 * racer->gravityUp.z);
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->gravityUp.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->gravityUp.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->gravityUp.z));
        }
    } else {
        racer->unk_1D4 = 0.0f;
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
            racer->stateFlags |= RACER_STATE_CRASHED;
            D_800E5FC0++;
            func_800892E0(racer);

            if (racer->id < gNumPlayers) {
                func_800894C0(racer);
            }
            if ((racer->id < gNumPlayers) || (gRacers[0].stateFlags & RACER_STATE_FALLING_OFF_TRACK)) {
                Effects_SpawnExplosion1(racer->segmentPositionInfo.pos.x, racer->segmentPositionInfo.pos.y,
                                        racer->segmentPositionInfo.pos.z, 0.0f, 0.0f, 0.0f, 600.0f, racer);
                if (gEnableRaceSfx) {
                    Audio_PlayerTriggerSEStart(racer->id, 8);
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
                controller->unk_88 = 0x2710;
                controller->unk_8C = 0x1F4;
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
            var_fa1 = 1.0f;
            i = 100;
        } else {
            var_fa1 = 5.0f;
            i = 3;
        }

        if (func_8009EBEC(&racer->segmentPositionInfo, racer->segmentPositionInfo.pos.x + racer->velocity.x,
                          racer->segmentPositionInfo.pos.y + racer->velocity.y,
                          racer->segmentPositionInfo.pos.z + racer->velocity.z, i, var_fa1) == 0) {
            sp128 = racer->lapDistance;
            racer->lapDistance = func_8009DFA0(&racer->segmentPositionInfo);
            temp_v1 = racer->segmentPositionInfo.courseSegment;

            racer->currentRadiusLeft = (racer->segmentPositionInfo.segmentLengthProportion *
                                        (temp_v1->next->radiusLeft - temp_v1->radiusLeft)) +
                                       temp_v1->radiusLeft;
            racer->currentRadiusRight = (racer->segmentPositionInfo.segmentLengthProportion *
                                         (temp_v1->next->radiusRight - temp_v1->radiusRight)) +
                                        temp_v1->radiusRight;

            var_fa1 = 1.0f / racer->segmentPositionInfo.segmentForwardMagnitude;
            racer->segmentBasis.x.x = racer->segmentPositionInfo.segmentForward.x * var_fa1;
            racer->segmentBasis.x.y = racer->segmentPositionInfo.segmentForward.y * var_fa1;
            racer->segmentBasis.x.z = racer->segmentPositionInfo.segmentForward.z * var_fa1;

            racer->segmentBasis.y.x =
                (racer->segmentPositionInfo.segmentLengthProportion * (temp_v1->next->unk_0C.x - temp_v1->unk_0C.x)) +
                temp_v1->unk_0C.x;
            racer->segmentBasis.y.y =
                (racer->segmentPositionInfo.segmentLengthProportion * (temp_v1->next->unk_0C.y - temp_v1->unk_0C.y)) +
                temp_v1->unk_0C.y;
            racer->segmentBasis.y.z =
                (racer->segmentPositionInfo.segmentLengthProportion * (temp_v1->next->unk_0C.z - temp_v1->unk_0C.z)) +
                temp_v1->unk_0C.z;

            racer->segmentBasis.z.x = (racer->segmentBasis.y.y * racer->segmentBasis.x.z) -
                                      (racer->segmentBasis.y.z * racer->segmentBasis.x.y);
            racer->segmentBasis.z.y = (racer->segmentBasis.y.z * racer->segmentBasis.x.x) -
                                      (racer->segmentBasis.y.x * racer->segmentBasis.x.z);
            racer->segmentBasis.z.z = (racer->segmentBasis.y.x * racer->segmentBasis.x.y) -
                                      (racer->segmentBasis.y.y * racer->segmentBasis.x.x);

            temp_fa0 =
                1.0f / sqrtf(SQ(racer->segmentBasis.z.x) + SQ(racer->segmentBasis.z.y) + SQ(racer->segmentBasis.z.z));

            racer->segmentBasis.z.x *= temp_fa0;
            racer->segmentBasis.z.y *= temp_fa0;
            racer->segmentBasis.z.z *= temp_fa0;

            racer->segmentBasis.y.x = (racer->segmentBasis.x.y * racer->segmentBasis.z.z) -
                                      (racer->segmentBasis.x.z * racer->segmentBasis.z.y);
            racer->segmentBasis.y.y = (racer->segmentBasis.x.z * racer->segmentBasis.z.x) -
                                      (racer->segmentBasis.x.x * racer->segmentBasis.z.z);
            racer->segmentBasis.y.z = (racer->segmentBasis.x.x * racer->segmentBasis.z.y) -
                                      (racer->segmentBasis.x.y * racer->segmentBasis.z.x);
            if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED | RACER_STATE_FALLING_OFF_TRACK)) &&
                (gRaceIntroTimer < 40) && (gGameMode != GAMEMODE_RECORDS)) {

                sp128 -= racer->lapDistance;
                racer->unk_288++;
                racer->unk_2A4++;
                racer->raceTime = (s32) (racer->unk_2A4 * 50) / 3;
                if (D_800F80BC < sp128) {
                    racer->lapsCompletedDistance += gCurrentCourseInfo->length;
                    racer->lap++;
                    if ((racer->lap == racer->lapsCompleted + 1) && ((gTotalLapCount + 1) >= racer->lap)) {
                        racer->lapsCompleted = racer->lap;
                        racer->stateFlags |= RACER_STATE_CAN_BOOST;
                        i = racer->raceTime -
                            (s32) ((50.0f * racer->lapDistance) / (3.0f * (gCurrentCourseInfo->length - sp128)));
                        racer->lapTimes[racer->lap - 2] = (s32) (i - racer->completedLapsTime);
                        racer->completedLapsTime = i;
                        racer->startNewPracticeLap = true;
                        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
                            if (racer == gRacers) {
                                if (racer->lapTimes[racer->lap - 2] < gPracticeBestLap) {
                                    gPracticeBestLap = racer->lapTimes[racer->lap - 2];
                                    gStartNewBestLap = true;
                                }
                            }
                            if ((gTotalLapCount + 1) == racer->lap) {
                                racer->lap = racer->lapsCompleted = 1;
                                racer->lapsCompletedDistance = 0;
                            }
                        } else if ((gTotalLapCount + 1) == racer->lap) {
                            racer->raceTime = i;
                            racer->stateFlags |= RACER_STATE_FINISHED | RACER_STATE_CPU_CONTROLLED;
                            racer->energy = racer->maxEnergy;

                            if (racer->id < gNumPlayers) {
                                gControllers[gPlayerControlPorts[racer->id]].unk_72 = 0;
                                gPlayerRacersFinished++;
                            }
                            gRacersFinished++;
                            D_800F5DE8 = 1;

                            if (racer->id < gNumPlayers) {
                                if (gEnableRaceSfx) {
                                    Audio_PlayerTriggerSEStart(racer->id, 0xF);
                                    func_800BA2B4(racer->id);
                                }
                                func_800894C0(racer);
                                if (gNumPlayers == 1) {
                                    func_8007E0CC();
                                } else if (gRacersFinished == 1) {
                                    func_8007E0CC();
                                }
                            }
                        }
                    }
                } else if (sp128 < D_800F80C0) {
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
    var_fv1 = racer->segmentPositionInfo.pos.x - (sp128 * racer->trueBasis.y.x);
    racer->focusPos.x = var_fv1;
    racer->focusVelocity.x = var_fv1 - var_fa1;

    var_fa1 = racer->focusPos.y;
    var_fv1 = racer->segmentPositionInfo.pos.y - (sp128 * racer->trueBasis.y.y);
    racer->focusPos.y = var_fv1;
    racer->focusVelocity.y = var_fv1 - var_fa1;

    var_fa1 = racer->focusPos.z;
    var_fv1 = racer->segmentPositionInfo.pos.z - (sp128 * racer->trueBasis.y.z);
    racer->focusPos.z = var_fv1;
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
                racer->unk_08 |= 0x800;
                if (gEnableRaceSfx) {
                    Audio_PlayerLevelSEStart(racer->id, 4);
                }
            }
        }
    } else {
        if (racer->pitForceFieldSize > 0.0f) {
            racer->pitForceFieldSize -= 0.1f;
            if (racer->pitForceFieldSize <= 0.0f) {
                racer->pitForceFieldSize = 0.0f;
                if (racer->id < gNumPlayers) {
                    racer->unk_08 &= ~0x800;
                    if (gEnableRaceSfx) {
                        Audio_PlayerLevelSEStop(racer->id, 4);
                    }
                }
            }
        }
    }
    racer->unk_210 = (racer->unk_210 + (s32) (racer->unk_1D4 * 4000.0f)) & 0xFFF;

    var_fa1 = SIN(racer->unk_210) * (racer->speed * 0.007f);
    if (racer->unk_08 & 0x400) {
        var_fa1 *= 5.0f;
    }
    racer->unk_10C.x = racer->segmentPositionInfo.pos.x + (var_fa1 * racer->unk_E8.y.x);
    racer->unk_10C.y = racer->segmentPositionInfo.pos.y + (var_fa1 * racer->unk_E8.y.y);
    racer->unk_10C.z = racer->segmentPositionInfo.pos.z + (var_fa1 * racer->unk_E8.y.z);
    if (racer->spinOutTimer != 0) {
        racer->unk_10C.x += ((f32) (Math_Rand1() & 0xFFFF) * 0.000027466238f) - 0.9f;
        racer->unk_10C.y += ((f32) (Math_Rand1() & 0xFFFF) * 0.000027466238f) - 0.9f;
        racer->unk_10C.z += ((f32) (Math_Rand2() & 0xFFFF) * 0.000027466238f) - 0.9f;
    }

    if (racer->unk_27C != 0) {
        if (racer->unk_284 == 1) {
            racer->unk_E8.x.x = racer->trueBasis.x.x;
            racer->unk_E8.x.y = racer->trueBasis.x.y;
            racer->unk_E8.x.z = racer->trueBasis.x.z;
        } else {
            var_fs1 = COS(racer->unk_27C);
            var_fs0 = SIN(racer->unk_27C);
            racer->unk_E8.x.x = (racer->trueBasis.x.x * var_fs1) + (var_fs0 * racer->trueBasis.z.x);
            racer->unk_E8.x.y = (racer->trueBasis.x.y * var_fs1) + (var_fs0 * racer->trueBasis.z.y);
            racer->unk_E8.x.z = (racer->trueBasis.x.z * var_fs1) + (var_fs0 * racer->trueBasis.z.z);
        }

        if (racer->unk_284 == 1) {
            racer->unk_27C += racer->unk_280;
            if ((racer->unk_27C == -0x80) || (racer->unk_27C == 0x1080)) {
                racer->unk_204 = 0x1E;
                racer->unk_27C = 0;
                racer->unk_284 = 0;
            }
        } else {
            racer->unk_27C += racer->unk_280;
            if (racer->unk_280 < 0) {
                racer->unk_280 += 2;
                if (racer->unk_27C <= 0) {
                    racer->unk_27C += 0x1000;
                    if (racer->unk_280 >= -0x31) {
                        racer->unk_27C = 0;
                        racer->unk_284 = 0;
                    } else if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 2);
                    }
                }
            } else {
                racer->unk_280 -= 2;
                if (racer->unk_27C >= 0x1000) {
                    racer->unk_27C -= 0x1000;
                    if (racer->unk_280 < 0x32) {
                        racer->unk_27C = 0;
                        racer->unk_284 = 0;
                    } else if (gEnableRaceSfx) {
                        Audio_PlayerTriggerSEStart(racer->id, 2);
                    }
                }
            }
        }
    } else {
        racer->unk_E8.x.x = racer->trueBasis.x.x;
        racer->unk_E8.x.y = racer->trueBasis.x.y;
        racer->unk_E8.x.z = racer->trueBasis.x.z;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            racer->unk_10C.x += (var_fs1 = racer->podiumHeight * racer->trueBasis.y.x);
            racer->unk_10C.y += (var_fs0 = racer->podiumHeight * racer->trueBasis.y.y);
            racer->unk_10C.z += (var_ft4 = racer->podiumHeight * racer->trueBasis.y.z);
            racer->shadowPos.x += var_fs1;
            racer->shadowPos.y += var_fs0;
            racer->shadowPos.z += var_ft4;
        }
    }
    var_fa1 = racer->unk_68.x * 0.6f;

    racer->unk_E8.y.x += 0.19f * (racer->trueBasis.y.x + (var_fa1 * racer->trueBasis.z.x));
    racer->unk_E8.y.y += 0.19f * (racer->trueBasis.y.y + (var_fa1 * racer->trueBasis.z.y));
    racer->unk_E8.y.z += 0.19f * (racer->trueBasis.y.z + (var_fa1 * racer->trueBasis.z.z));

    racer->unk_E8.z.x = (racer->unk_E8.y.y * racer->unk_E8.x.z) - (racer->unk_E8.y.z * racer->unk_E8.x.y);
    racer->unk_E8.z.y = (racer->unk_E8.y.z * racer->unk_E8.x.x) - (racer->unk_E8.y.x * racer->unk_E8.x.z);
    racer->unk_E8.z.z = (racer->unk_E8.y.x * racer->unk_E8.x.y) - (racer->unk_E8.y.y * racer->unk_E8.x.x);

    temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_E8.z.x) + SQ(racer->unk_E8.z.y) + SQ(racer->unk_E8.z.z));

    racer->unk_E8.z.x *= temp_fa0;
    racer->unk_E8.z.y *= temp_fa0;
    racer->unk_E8.z.z *= temp_fa0;

    racer->unk_E8.y.x = (racer->unk_E8.x.y * racer->unk_E8.z.z) - (racer->unk_E8.x.z * racer->unk_E8.z.y);
    racer->unk_E8.y.y = (racer->unk_E8.x.z * racer->unk_E8.z.x) - (racer->unk_E8.x.x * racer->unk_E8.z.z);
    racer->unk_E8.y.z = (racer->unk_E8.x.x * racer->unk_E8.z.y) - (racer->unk_E8.x.y * racer->unk_E8.z.x);
    if (racer->stateFlags & RACER_STATE_COLLISION_RECOIL) {
        racer->unk_E8.y.x += racer->unk_118.x *= 0.8f;
        racer->unk_E8.y.y += racer->unk_118.y *= 0.8f;
        racer->unk_E8.y.z += racer->unk_118.z *= 0.8f;

        var_fa1 = 1.0f / sqrtf(SQ(racer->unk_E8.y.x) + SQ(racer->unk_E8.y.y) + SQ(racer->unk_E8.y.z));
        if (var_fa1 > 0.99f) {
            racer->stateFlags &= ~RACER_STATE_COLLISION_RECOIL;
        }

        racer->unk_E8.y.x *= var_fa1;
        racer->unk_E8.y.y *= var_fa1;
        racer->unk_E8.y.z *= var_fa1;

        racer->unk_E8.z.x = (racer->unk_E8.y.y * racer->unk_E8.x.z) - (racer->unk_E8.y.z * racer->unk_E8.x.y);
        racer->unk_E8.z.y = (racer->unk_E8.y.z * racer->unk_E8.x.x) - (racer->unk_E8.y.x * racer->unk_E8.x.z);
        racer->unk_E8.z.z = (racer->unk_E8.y.x * racer->unk_E8.x.y) - (racer->unk_E8.y.y * racer->unk_E8.x.x);

        temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_E8.z.x) + SQ(racer->unk_E8.z.y) + SQ(racer->unk_E8.z.z));

        racer->unk_E8.z.x *= temp_fa0;
        racer->unk_E8.z.y *= temp_fa0;
        racer->unk_E8.z.z *= temp_fa0;

        racer->unk_E8.x.x = (racer->unk_E8.z.y * racer->unk_E8.y.z) - (racer->unk_E8.z.z * racer->unk_E8.y.y);
        racer->unk_E8.x.y = (racer->unk_E8.z.z * racer->unk_E8.y.x) - (racer->unk_E8.z.x * racer->unk_E8.y.z);
        racer->unk_E8.x.z = (racer->unk_E8.z.x * racer->unk_E8.y.y) - (racer->unk_E8.z.y * racer->unk_E8.y.x);
    }

    if (racer->bodyWhiteTimer != 0) {
        racer->bodyWhiteTimer--;
    }
    if (racer->spinOutTimer != 0) {
        if (!((racer->id + gGameFrameCount) & 3) && (racer->machineLod != 0)) {
            sp10C.x = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.x;
            sp10C.y = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.y;
            sp10C.z = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.z;
            Effects_SpawnExplosion1(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x, racer->velocity.y, racer->velocity.z,
                                    (f32) ((Math_Rand2() & 0xF) + ((s32) (racer->spinOutTimer * 5) / 150) + 5), racer);
            if (!((racer->id + gGameFrameCount) & 4) && gEnableRaceSfx) {
                Audio_PlayerTriggerSEStart(racer->id, 5);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 0xBB8;
                controller->unk_8C = 0;
                controller->unk_90 = 0;
            }

            for (i = 2; i > 0; i--) {
                var_fs1 = ((f32) (Math_Rand2() & 0x1FFFF) * 0.000068665075f) - 4.5f;
                var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.000038147264f) + 2.0f;
                var_ft4 = ((f32) (Math_Rand2() & 0x1FFFF) * 0.000068665075f) - 4.5f;
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

            racer->stateFlags &= ~RACER_STATE_SPINNING_OUT;
            racer->spinOutTimer = 0;
            racer->stateFlags |= RACER_STATE_CRASHED;
            racer->unk_17C = 10.0f;
            D_800E5FBE++;
            func_800892E0(racer);
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
                    var_fs1 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;
                    var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00005340617f) + 3.5f;
                    var_ft4 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;
                    Effects_SpawnMachineDebris((s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.x,
                                               (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.y,
                                               (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.z,
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
                    Audio_PlayerTriggerSEStart(racer->id, 8);
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
        if ((racer->id < gNumPlayers) && (var_fa1 < 0.3f) && (racer->spinOutTimer == 0) && gEnableRaceSfx) {
            if (var_fa1 >= 0.2f) {
                if (!(gGameFrameCount & 0x1F)) {
                    Audio_PlayerTriggerSEStart(racer->id, 0x13);
                }
            } else if (var_fa1 >= 0.1f) {
                if (!(gGameFrameCount & 0xF)) {
                    Audio_PlayerTriggerSEStart(racer->id, 0x14);
                }
            } else if (!(gGameFrameCount & 7)) {
                Audio_PlayerTriggerSEStart(racer->id, 0x15);
            }
        }
        if (!(gGameFrameCount & 8) && ((var_fa1 < 0.2f) || ((var_fa1 < 0.5f) && !(gGameFrameCount & 0x10)))) {
            var_fa1 *= 2;
            var_fs1 = (racer->unk_2F8 * var_fa1) + racer->unk_2EC;
            var_fs0 = (racer->unk_2FC * var_fa1) + racer->unk_2F0;
            var_ft4 = (racer->unk_300 * var_fa1) + racer->unk_2F4;
            var_fa1 = (f32) ((u32) gGameFrameCount & 7) / 7.0f;
            var_fs1 += ((racer->bodyRF - var_fs1) * var_fa1);
            var_fs0 += ((racer->bodyGF - var_fs0) * var_fa1);
            var_ft4 += ((racer->bodyBF - var_ft4) * var_fa1);
        } else {
            var_fs1 = racer->bodyRF;
            var_fs0 = racer->bodyGF;
            var_ft4 = racer->bodyBF;
        }

        var_fa1 = racer->bodyWhiteTimer / 5.0f;
        racer->bodyR = ((255.0f - var_fs1) * var_fa1) + var_fs1;
        racer->bodyG = ((255.0f - var_fs0) * var_fa1) + var_fs0;
        racer->bodyB = ((255.0f - var_ft4) * var_fa1) + var_ft4;
        if (racer->unk_284 == 2) {
            var_fa1 = SIN(racer->unk_27C & 0x7FF);
            racer->unk_178 = (0.1f * var_fa1) + 1.05f;
            racer->unk_2DA = 0xFF;
            racer->unk_2DC = 0xFF - (s32) (255.0f * var_fa1);
            racer->unk_2DE = 0;
        } else if (racer->unk_284 == 1) {
            racer->unk_178 = 1.075f;
            racer->unk_2DA = 0xFF;
            racer->unk_2DC = 0;
            racer->unk_2DE = 0;
        } else {
            racer->unk_178 = 0.0f;
        }
    } else {
        racer->bodyR = racer->bodyRF;
        racer->bodyG = racer->bodyGF;
        racer->bodyB = racer->bodyBF;
        if (((Math_Rand1() & 0x1FFFF) < 0x444) && (racer->machineLod != 0)) {
            var_fs1 = (((f32) (Math_Rand1() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            var_fs0 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 1.5f) + 0.5f;
            var_ft4 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            sp10C.x = (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.x;
            sp10C.y = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.y;
            sp10C.z = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->segmentPositionInfo.pos.z;

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
                Audio_PlayerTriggerSEStart(racer->id, 0x32);
            }
            racer->unk_178 = 1.03f;
            racer->unk_2DA = racer->unk_2DC = 0xFF;
            racer->unk_2DE = 0;
        } else {
            racer->unk_178 = 0.0f;
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
            Audio_PlayerTriggerSEStart(racer->id, 0x28);
        }
    }

    if (racer->shadowColorStrength != 1.0f) {
        var_fa1 = (racer->shadowColorStrength - 1.0f) / 0.29999995f;
        var_fa1 *= var_fa1;
        racer->shadowR = racer->shadowBaseR * var_fa1;
        racer->shadowG = racer->shadowBaseG * var_fa1;
        racer->shadowB = racer->shadowBaseB * var_fa1;
        racer->shadowColorStrength -= 0.003f;
        if (racer->shadowColorStrength < 1.f) {
            racer->shadowColorStrength = 1.0f;
        }
    } else {
        racer->shadowR = racer->shadowG = racer->shadowB = 0;
    }
    if (racer->id < gNumPlayers) {
        if ((racer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_FLAG_20000000) &&
            !(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
            if (!(racer->unk_08 & 0x100)) {
                racer->unk_08 |= 0x100;
                if (gEnableRaceSfx) {
                    func_800BAB34(racer->id);
                }
            }
        } else {

            if (racer->unk_08 & 0x100) {
                racer->unk_08 &= ~0x100;
                if (gEnableRaceSfx) {
                    func_800BAB50(racer->id);
                }
            }
        }
    }
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/racer/func_80090BCC.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/racer/func_80090BCC.s")
#endif
#endif

void func_80094FF4(s32 position) {
    if (!(position > -0x80 && position < 0x80)) {
        sGhostReplayRecordingSize += 3;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = -0x80;
            *sGhostReplayRecordingPtr++ = ((position & 0xFFFF) >> 8);
            *sGhostReplayRecordingPtr++ = position & 0xFF;
        } else {
            sGhostReplayRecordingSize -= 3;
            gUnableToRecordGhost = 1;
            D_800F5DE4 = 0;
        }
    } else {
        sGhostReplayRecordingSize++;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = position;
        } else {
            sGhostReplayRecordingSize--;
            gUnableToRecordGhost = 1;
            D_800F5DE4 = 0;
        }
    }
}

s32 func_800950E8(GhostRacer* arg0) {
    s32 temp1 = *arg0->replayPtr++;

    if (temp1 == -0x80) {
        temp1 = *arg0->replayPtr++;
        temp1 <<= 8;
        temp1 |= (u8) *arg0->replayPtr++;
        arg0->replayIndex += 3;
    } else {
        arg0->replayIndex++;
    }

    return temp1;
}

void func_80095144(void) {
    s32 i;

    for (i = 0; i < gNumPlayers; i++) {
        gControllers[gPlayerControlPorts[i]].unk_72 = 0;
    }

    if (D_800F80C4 == 1) {
        func_80089220(0);
    } else if (D_800F80C4 == -1) {
        func_8008927C(0);
    }
}

void func_80090BCC(Racer*, Controller*);
void Cpu_GenerateInputs(Racer*, Controller*);

void func_800951DC(Racer* racer) {
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
        func_80090BCC(racer, &dummyController);
    } else {
        func_80090BCC(racer, &gControllers[gPlayerControlPorts[racer->id]]);
        racer->unk_33C = -racer->segmentPositionInfo.segmentDisplacement.x * racer->segmentBasis.z.x -
                         racer->segmentPositionInfo.segmentDisplacement.y * racer->segmentBasis.z.y -
                         racer->segmentPositionInfo.segmentDisplacement.z * racer->segmentBasis.z.z;
    }
}

extern s8 gGamePaused;
extern GfxPool* gGfxPool;
extern s32 gFastestGhostTime;

void Racer_Update(void) {
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
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
    GhostRacer* var_s0;
    RacerPairInfo* temp_s2;
    s32 i;
    Mtx3F spCC;
    Racer* racer;
    Racer* racer2;
    Camera* camera;

    sRaceFrameCount++;
    if (gRaceIntroTimer != 0) {
        if (!gGamePaused) {
            if (gRaceIntroTimer == 460) {
                func_8007E08C();
                if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                    func_800BB018();
                }
                for (i = 0; i < gNumPlayers; i++) {
                    func_800BAE5C(i);
                }
            }

            gRaceIntroTimer--;
            if (gRaceIntroTimer == 40) {
                for (racer = sLastRacer; racer >= gRacers; racer--) {
                    racer->stateFlags |= RACER_STATE_FLAGS_400000;
                }
            } else if ((gRaceIntroTimer == 255) && (gGameMode == GAMEMODE_TIME_ATTACK)) {
                D_800F5DE4 = 1;
                sReplayRecordFrameCount = 0;
                sReplayRecordPosX = Math_Round(gRacers[0].segmentPositionInfo.pos.x);
                sReplayRecordPosY = Math_Round(gRacers[0].segmentPositionInfo.pos.y);
                sReplayRecordPosZ = Math_Round(gRacers[0].segmentPositionInfo.pos.z);

                for (var_s0 = &gGhostRacers[2]; var_s0 >= gGhostRacers; var_s0--) {
                    if (var_s0->exists) {
                        var_s0->initialized = true;
                        var_s0->frameCount = 0;
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosX = posDiff + sReplayRecordPosX;
                        var_s0->pos.x = gRacers[0].segmentPositionInfo.pos.x + (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosY = posDiff + sReplayRecordPosY;
                        var_s0->pos.y = gRacers[0].segmentPositionInfo.pos.y + (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosZ = posDiff + sReplayRecordPosZ;
                        var_s0->pos.z = gRacers[0].segmentPositionInfo.pos.z + (posDiff * 0.5f);
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
            racer->unk_164 = racer->unk_165 = racer->unk_166 = 0;
        }
        gControllers[(gGameFrameCount & 3)].unk_78 = 1;
        return;
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        racer->unk_164 = racer->unk_165 = racer->unk_166 = 0;
        racer->stateFlags &= ~RACER_STATE_RECEIVED_DAMAGE;
        racer->acceleration.z = 0.0f;
        racer->acceleration.y = 0.0f;
        racer->acceleration.x = 0.0f;
        if ((racer->unk_230 != 0.0f) && !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
            racer->energy += racer->unk_230;
            if (racer->maxEnergy < racer->energy) {
                racer->energy = racer->maxEnergy;
            }
            racer->unk_230 = 0.0f;
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
                    temp_s2 = &sRacerPairInfo[i + racer2->id];
                    if (temp_s2->trailToLeadDistance > 92.0f) {
                        temp_s2->unk_10 = 0;
                        continue;
                    }
                    var_fa0 = racer2->segmentPositionInfo.pos.x - racer->segmentPositionInfo.pos.x;
                    var_fa1 = racer2->segmentPositionInfo.pos.z - racer->segmentPositionInfo.pos.z;
                    sp110 = var_fa0;
                    sp108 = var_fa1;

                    if (SQ(var_fa0) + SQ(var_fa1) > 2116.f) {
                        temp_s2->unk_10 = 0;
                        continue;
                    }

                    sp10C = racer2->segmentPositionInfo.pos.y - racer->segmentPositionInfo.pos.y;
                    if ((SQ(var_fa0) + SQ(var_fa1) + SQ(sp10C)) > 2116.0f) {
                        temp_s2->unk_10 = 0;
                        continue;
                    }

                    sp128 = sqrtf((SQ(var_fa0) + SQ(var_fa1) + SQ(sp10C)));
                    if (racer->stateFlags & RACER_STATE_CRASHED) {
                        var_fs2 = racer->unk_1F4 * 0.333f;
                    } else {
                        var_fs2 = racer->unk_1F4;
                    }
                    if (racer2->stateFlags & RACER_STATE_CRASHED) {
                        var_fs1 = racer2->unk_1F4 * 0.333f;
                    } else {
                        var_fs1 = racer2->unk_1F4;
                    }
                    temp_fv1_3 = var_fs2 + var_fs1;
                    var_fs2 /= temp_fv1_3;
                    var_fs1 /= temp_fv1_3;
                    temp_fs3 = racer2->velocity.x - racer->velocity.x;
                    temp_fs4 = racer2->velocity.y - racer->velocity.y;
                    temp_fs5 = racer2->velocity.z - racer->velocity.z;
                    if (temp_s2->unk_10 == 0) {
                        if (racer->id < gNumPlayers) {
                            racer2->unk_288 = 0;
                            racer2->unk_28C = racer;
                        }
                        if (racer2->id < gNumPlayers) {
                            racer->unk_288 = 0;
                            racer->unk_28C = racer2;
                        }
                        if (sp128 < 0.01f) {
                            temp_fv1_3 = 1.0f / sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fs5));
                            var_fa0 = temp_fv1_3 * temp_fs3;
                            var_fa1 = temp_fv1_3 * temp_fs4;
                            var_ft4 = temp_fv1_3 * temp_fs5;
                        } else {
                            temp_fv1_3 = 1.0f / sp128;
                            var_fa0 = temp_fv1_3 * sp110;
                            var_fa1 = temp_fv1_3 * sp10C;
                            var_ft4 = temp_fv1_3 * sp108;
                        }
                        var_fs0 = (var_fa0 * temp_fs3) + (var_fa1 * temp_fs4) + (var_ft4 * temp_fs5);

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
                        if (racer->unk_284 == 0) {
                            if (racer2->unk_284 == 0) {
                                func_8008DCD8(racer, var_fs1 * var_fs0);
                                func_8008DCD8(racer2, var_fs2 * var_fs0);
                            } else if ((racer2 == gRacers) && (gNumPlayers == 1)) {
                                func_8008DCD8(racer, var_fs0 * 10.0f);
                            } else {
                                func_8008DCD8(racer, var_fs0);
                            }
                        } else if (racer2->unk_284 == 0) {
                            func_8008DCD8(racer2, var_fs0);
                        } else {
                            func_8008DCD8(racer, var_fs1 * var_fs0);
                            func_8008DCD8(racer2, var_fs2 * var_fs0);
                        }
                        if (gEnableRaceSfx) {
                            Audio_PlayerTriggerSEStart(racer2->id, 4);
                        }
                    }
                    temp_s2->unk_10 = 1;
                    if (((sp110 * temp_fs3) + (sp10C * temp_fs4) + (sp108 * temp_fs5)) <= 0.0f) {
                        if (sp128 < 0.01f) {
                            temp_fv1_3 = -46.0f / sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fs5));
                            var_fa0 = temp_fv1_3 * temp_fs3;
                            var_fa1 = temp_fv1_3 * temp_fs4;
                            var_ft4 = temp_fv1_3 * temp_fs5;
                        } else {
                            if ((racer->unk_284 | racer2->unk_284) != 0) {
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
                        if (racer->unk_284 != 0) {
                            if (racer2->unk_284 == 0) {
                                var_fs2 = 3.0f;
                                var_fs1 = 0.0f;
                                racer2->unk_208 = 0x3C;
                            }
                        } else if (racer2->unk_284 != 0) {
                            var_fs2 = 0.0f;
                            var_fs1 = 3.0f;
                            racer->unk_208 = 0x3C;
                        }
                        racer->acceleration.x -= var_fs1 * var_fa0;
                        racer->acceleration.y -= var_fs1 * var_fa1;
                        racer->acceleration.z -= var_fs1 * var_ft4;
                        racer->unk_118.x = (-0.15f * var_fs1) * var_fa0;
                        racer->unk_118.y = (-0.15f * var_fs1) * var_fa1;
                        racer->unk_118.z = (-0.15f * var_fs1) * var_ft4;
                        racer->stateFlags |= RACER_STATE_COLLISION_RECOIL;
                        racer2->acceleration.x += var_fs2 * var_fa0;
                        racer2->acceleration.y += var_fs2 * var_fa1;
                        racer2->acceleration.z += var_fs2 * var_ft4;
                        racer2->unk_118.x = (0.15f * var_fs2) * var_fa0;
                        racer2->unk_118.y = (0.15f * var_fs2) * var_fa1;
                        racer2->unk_118.z = (0.15f * var_fs2) * var_ft4;
                        racer2->stateFlags |= RACER_STATE_COLLISION_RECOIL;
                    }
                }
            } while (--racer2 >= gRacers);
        } while (--racer > gRacers);
    }
    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->stateFlags & RACER_STATE_ACTIVE) {
            func_800951DC(racer);
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

    if (gGameMode == GAMEMODE_TIME_ATTACK) {
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
            if ((D_800F5DE8 != 0) && (gUnableToRecordGhost == 0) && (D_800F5DEA == 0)) {
                D_800F5DEA = 1;
                sGhostReplayRecordingEnd = sGhostReplayRecordingSize;
            }
        }
        for (var_s0 = &gGhostRacers[2]; var_s0 >= gGhostRacers; var_s0--) {
            if ((var_s0->exists) && (var_s0->initialized)) {
                racer = var_s0->racer;
                sp110 = racer->unk_10C.x + racer->velocity.x;
                sp10C = racer->unk_10C.y + racer->velocity.y;
                sp108 = racer->unk_10C.z + racer->velocity.z;
                racer->velocity.x = var_s0->pos.x - racer->unk_10C.x;
                racer->velocity.y = var_s0->pos.y - racer->unk_10C.y;
                racer->velocity.z = var_s0->pos.z - racer->unk_10C.z;
                racer->unk_10C = var_s0->pos;

                if (func_8009EBEC(&racer->segmentPositionInfo, racer->unk_10C.x, racer->unk_10C.y, racer->unk_10C.z,
                                  100, 1.0f) != 0) {
                    var_s0->exists = var_s0->initialized = false;
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

                    var_s0->frameCount++;
                    if (var_s0->frameCount & 1) {
                        var_s0->pos.x = var_s0->replayPosX;
                        var_s0->pos.y = var_s0->replayPosY;
                        var_s0->pos.z = var_s0->replayPosZ;
                        if (var_s0->replayIndex >= var_s0->ghost->replaySize) {
                            var_s0->exists = var_s0->initialized = false;
                        }
                    } else {
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosX += posDiff;
                        var_s0->pos.x += (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosY += posDiff;
                        var_s0->pos.y += (posDiff * 0.5f);
                        posDiff = func_800950E8(var_s0);
                        var_s0->replayPosZ += posDiff;
                        var_s0->pos.z += (posDiff * 0.5f);
                    }

                    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));

                    spCC = racer->trueBasis;
                    if (racer->speed > 1.0f) {
                        racer->trueBasis.x.x = var_s0->pos.x - racer->unk_10C.x;
                        racer->trueBasis.x.y = var_s0->pos.y - racer->unk_10C.y;
                        racer->trueBasis.x.z = var_s0->pos.z - racer->unk_10C.z;
                    }
                    racer->trueBasis.y.x += 0.19f * racer->tiltUp.x;
                    racer->trueBasis.y.y += 0.19f * racer->tiltUp.y;
                    racer->trueBasis.y.z += 0.19f * racer->tiltUp.z;
                    if (Math_OrthonormalizeAroundUp(&racer->trueBasis) != 0) {
                        racer->trueBasis = spCC;
                    }

                    racer->unk_80.x = racer->unk_10C.x - sp110;
                    racer->unk_80.y = racer->unk_10C.y - sp10C;
                    racer->unk_80.z = racer->unk_10C.z - sp108;
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
                    racer->unk_E8.x.x = racer->trueBasis.x.x;
                    racer->unk_E8.x.y = racer->trueBasis.x.y;
                    racer->unk_E8.x.z = racer->trueBasis.x.z;

                    var_fs0 = racer->unk_68.x * 0.6f;
                    racer->unk_E8.y.x += 0.19f * (racer->trueBasis.y.x + (var_fs0 * racer->trueBasis.z.x));
                    racer->unk_E8.y.y += 0.19f * (racer->trueBasis.y.y + (var_fs0 * racer->trueBasis.z.y));
                    racer->unk_E8.y.z += 0.19f * (racer->trueBasis.y.z + (var_fs0 * racer->trueBasis.z.z));
                    Math_OrthonormalizeAroundForward(&racer->unk_E8);
                    if (var_s0->ghost->replayEnd < var_s0->replayIndex) {
                        if (var_s0->scale != 0.f) {
                            var_s0->scale -= 0.02f;
                            if (var_s0->scale <= 0.0f) {
                                var_s0->exists = var_s0->initialized = false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (gGameFrameCount & 1) {
        func_8008AD38();
    } else {
        if ((D_800E5FBC == 0) || (gNumPlayers == 1)) {
            func_8008A978();
        }

        for (i = 0; i < gNumPlayers; i++) {
            racer2 = &gRacers[i];
            if ((((racer2->segmentBasis.x.x * racer2->velocity.x) + (racer2->segmentBasis.x.y * racer2->velocity.y) +
                  (racer2->segmentBasis.x.z * racer2->velocity.z)) < -0.3f) &&
                !(racer2->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FALLING_OFF_TRACK))) {
                gPlayerReverseTimer[i]++;
                if (gPlayerReverseTimer[i] == 100) {
                    Audio_TriggerSystemSE(0x3C);
                }
            } else {
                gPlayerReverseTimer[i] = 0;
            }
        }
    }
    if (gTotalRacers >= 2) {
        if (gNumPlayers == 1) {
            func_8008B150();
            if (gEnableRaceSfx) {
                func_800BA2E0(gNearestRacer);
            }
        }
        if ((gRacersByPosition[0]->id < gNumPlayers) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_PRACTICE)) {
            var_fs0 = gRacersByPosition[0]->raceDistance - gRacersByPosition[1]->raceDistance;
            if (var_fs0 > 4000.0f) {
                if (!(gRacersByPosition[0]->unk_08 & 0x4000)) {
                    gRacersByPosition[0]->unk_08 |= 0x4000;
                    if (gEnableRaceSfx) {
                        Audio_TriggerSystemSE(0x3B);
                    }
                }
            } else if (var_fs0 < 2000.0f) {
                gRacersByPosition[0]->unk_08 &= ~0x4000;
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
                    func_8008A978();
                }
                for (racer = &gRacers[gTotalRacers - 1]; racer >= gRacers; racer--) {
                    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED))) {
                        racer->stateFlags |= RACER_STATE_FINISHED | RACER_STATE_CPU_CONTROLLED;
                        racer->energy = racer->maxEnergy;
                        if (gEnableRaceSfx) {
                            if (racer->position == 1) {
                                Audio_PlayerTriggerSEStart(racer->id, 0xF);
                            }
                            func_800BA2B4(racer->id);
                            func_800BAB68(racer->id);
                            if ((i != 0) && (gPlayerRacersFinished == 0)) {
                                i = 0;
                                func_8007E0CC();
                            }
                        }
                    }
                }

                for (i = gTotalRacers - 2; i >= 0; i--) {
                    gVsRacePlayerPoints[gRacersByPosition[i]->id] += D_800CE738[i];
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
                        Audio_TriggerSystemSE(0x3D);
                        break;
                    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
                        if ((gCurrentGhostType == GHOST_PLAYER) || (gCurrentGhostType == GHOST_NONE)) {
                            Audio_TriggerSystemSE(0x3D);
                        } else if (gRacers[0].raceTime < gFastestGhostTime) {
                            Audio_TriggerSystemSE(0x43);
                        }
                    }
                }
                break;
            case 120:
                if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FINISHED) &&
                    (gRacers[0].position == 1)) {
                    Audio_TriggerSystemSE(0x33);
                }
                break;
        }
    }
}

extern MachineEffect gCollisionSparks[32];
extern s32 gCollisionSparkIndex;
extern s32 gCollisionSparkCount;
extern MachineEffect gExplosions1[32];
extern s32 gExplosions1Index;
extern s32 gExplosions1Count;
extern MachineEffect gExplosions2[8];
extern s32 gExplosions2Index;
extern s32 gExplosions2Count;
extern FlyingSparkEffect gFlyingSparks[32];
extern s32 gFlyingSparksIndex;
extern s32 gFlyingSparksCount;
extern MachineEffect gSmokes[32];
extern s32 gSmokesIndex;
extern s32 gSmokesCount;
extern FallExplosionEffect gFallExplosions[32];
extern s32 gFallExplosionsIndex;
extern s32 gFallExplosionsCount;
extern MachineDebrisEffect gMachineDebris[128];
extern s32 gMachineDebrisIndex;
extern s32 gMachineDebrisCount;
extern GfxPool D_1000000;

#ifdef NON_EQUIVALENT
Gfx* Racer_Draw(Gfx* gfx, s32 playerIndex) {
    s32 var_s3; // sp5CC
    s32 var_s4; // sp5C8
    s32 sp5C4;
    MtxF sp580;
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
    GhostRacer* sp4F8;
    Camera* camera;
    Racer* playerRacer;
    f32 sp84;
    s32 i;
    Lights1* temp_v0_7;
    Racer* racer;
    Racer* temp_v0_14;
    Racer* temp_v0_27;
    Vec3s* var_v0;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fs0;
    f32 temp_fs0_10;
    f32 temp_fs0_11;
    f32 temp_fs0_14;
    f32 temp_fs0_15;
    f32 temp_fs0_18;
    f32 temp_fs0_5;
    f32 temp_fs0_6;

    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_14;
    f32 temp_fv0_15;
    f32 temp_fv0_16;
    f32 temp_fv0_17;
    f32 temp_fv0_18;
    f32 temp_fv0_19;
    f32 temp_fv0_20;
    f32 temp_fv0_21;
    f32 temp_fv0_22;
    f32 temp_fv0_23;
    f32 temp_fv0_24;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f32 temp_fv1_10;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_9;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs1;
    f32 var_fs3;

    s32 temp_s7_7;
    s32 temp_a3_4;

    s32 temp_a1_2;
    s32 temp_s4;
    s32 temp_v1_2;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_6;
    s32 var_s4_5;
    s32 var_s7;
    TexturePtr var_s2;
    CourseSegment* temp_v0_6;
    BoosterInfo* boosterInfo;
    GhostRacer* temp_t8;
    GhostRacer* temp_v0_10;
    GhostRacer* temp_v0_4;
    GhostRacer* var_v1;
    MachineEffect* temp_s1;
    MachineEffect* temp_s1_4;
    MachineEffect* temp_s1_5;
    FlyingSparkEffect* temp_s1_3;
    FallExplosionEffect* temp_s1_6;
    Mtx* mtx;
    MachineDebrisEffect* temp_v0_13;
    s32 temp;

    camera = &gCameras[playerIndex];

    temp_fv1 = (camera->basis.x.x * 100.0f) - camera->eye.x;
    temp_fv0 = (camera->basis.x.y * 100.0f) - camera->eye.y;
    temp_fa0 = (camera->basis.x.z * 100.0f) - camera->eye.z;
    temp_fa1 = ((-temp_fv1 * camera->viewMtx.zx) - (temp_fv0 * camera->viewMtx.zy)) - (camera->viewMtx.zz * temp_fa0);
    sp580.ww = temp_fa1;
    sp580.zw = camera->projectionMtx.zw - (temp_fa1 * camera->projectionMtx.zz);
    sp580.xw = (camera->projectionMtx.xx *
                ((temp_fv1 * camera->viewMtx.xx) + (temp_fv0 * camera->viewMtx.xy) + (temp_fa0 * camera->viewMtx.xz))) -
               (temp_fa1 * camera->projectionMtx.xz);
    sp580.xx = camera->projectionViewMtx.xx;
    sp580.xy = camera->projectionViewMtx.xy;
    sp580.yw = (camera->projectionMtx.yy *
                ((temp_fv1 * camera->viewMtx.yx) + (temp_fv0 * camera->viewMtx.yy) + (temp_fa0 * camera->viewMtx.yz))) -
               (temp_fa1 * camera->projectionMtx.yz);
    sp580.yx = camera->projectionViewMtx.yx;
    sp580.zx = camera->projectionViewMtx.zx;
    sp580.wx = camera->projectionViewMtx.wx;
    sp580.yy = camera->projectionViewMtx.yy;
    sp580.zy = camera->projectionViewMtx.zy;
    sp580.wy = camera->projectionViewMtx.wy;
    sp580.xz = camera->projectionViewMtx.xz;
    sp580.yz = camera->projectionViewMtx.yz;
    sp580.zz = camera->projectionViewMtx.zz;
    sp580.wz = camera->projectionViewMtx.wz;
    if (gGameMode != GAMEMODE_GP_END_CS) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 0;
            if (racer->stateFlags & RACER_STATE_ACTIVE) {
                temp_fv0_2 = racer->segmentPositionInfo.pos.x;
                temp_fv1_2 = racer->segmentPositionInfo.pos.y;
                temp_fa1_2 = racer->segmentPositionInfo.pos.z;
                temp_fa0_2 = sp580.zw + ((sp580.zx * temp_fv0_2) + (sp580.zy * temp_fv1_2) + (sp580.zz * temp_fa1_2));
                if ((temp_fa0_2 < 0.0f) || (temp_fa0_2 > 2500.0f)) {
                    continue;
                }
                sp574 =
                    1.0f / (sp580.ww + ((sp580.wx * temp_fv0_2) + (sp580.wy * temp_fv1_2) + (sp580.wz * temp_fa1_2)));

                temp_fs0 =
                    (sp580.xw + ((sp580.xx * temp_fv0_2) + (sp580.xy * temp_fv1_2) + (sp580.xz * temp_fa1_2))) * sp574;
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                temp_fs0 =
                    (sp580.yw + ((sp580.yx * temp_fv0_2) + (sp580.yy * temp_fv1_2) + (sp580.yz * temp_fa1_2))) * sp574;
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                if (temp_fa0_2 < 230.0f) {
                    racer->machineLod = 1;
                } else if (temp_fa0_2 < 290.0f) {
                    racer->machineLod = 2;
                } else if (temp_fa0_2 < 380.0f) {
                    racer->machineLod = 3;
                } else if (temp_fa0_2 < 470.0f) {
                    racer->machineLod = 4;
                } else if (temp_fa0_2 < 1500.0f) {
                    racer->machineLod = 5;
                } else {
                    racer->machineLod = 6;
                }

                if (temp_fa0_2 < 800.0f) {
                    racer->unk_2B2 = 1;
                }
                if (temp_fa0_2 < 400.0f) {
                    racer->unk_2B3 = 2;
                } else if (temp_fa0_2 < 900.0f) {
                    racer->unk_2B3 = 1;
                }
            }
        }
    } else {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = 1;
            racer->unk_2B3 = 2;
        }
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
        for (var_v1 = &gGhostRacers[2]; var_v1 >= gGhostRacers; var_v1--) {
            if (var_v1->exists) {
                racer = var_v1->racer;
                racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 0;
                if (var_v1->exists) {
                    temp_fv0_3 = racer->segmentPositionInfo.pos.x;
                    temp_fv1_3 = racer->segmentPositionInfo.pos.y;
                    temp_fa1_3 = racer->segmentPositionInfo.pos.z;
                    temp_fa0_2 =
                        sp580.zw + ((sp580.zx * temp_fv0_3) + (sp580.zy * temp_fv1_3) + (sp580.zz * temp_fa1_3));
                    if ((temp_fa0_2 < 0.0f) || (temp_fa0_2 > 2500.0f)) {
                        continue;
                    }
                    sp574 = 1.0f /
                            (sp580.ww + ((sp580.wx * temp_fv0_3) + (sp580.wy * temp_fv1_3) + (sp580.wz * temp_fa1_3)));

                    temp_fs0 =
                        (sp580.xw + ((sp580.xx * temp_fv0_3) + (sp580.xy * temp_fv1_3) + (sp580.xz * temp_fa1_3))) *
                        sp574;
                    if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                        continue;
                    }
                    temp_fs0 =
                        (sp580.yw + ((sp580.yx * temp_fv0_3) + (sp580.yy * temp_fv1_3) + (sp580.yz * temp_fa1_3))) *
                        sp574;
                    if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                        continue;
                    }

                    if (temp_fa0_2 < 230.0f) {
                        racer->machineLod = 1;
                    } else if (temp_fa0_2 < 290.0f) {
                        racer->machineLod = 2;
                    } else if (temp_fa0_2 < 380.0f) {
                        racer->machineLod = 3;
                    } else if (temp_fa0_2 < 470.0f) {
                        racer->machineLod = 4;
                    } else if (temp_fa0_2 < 1500.0f) {
                        racer->machineLod = 5;
                    } else {
                        racer->machineLod = 6;
                    }

                    if (temp_fa0_2 < 800.0f) {
                        racer->unk_2B2 = 1;
                    }
                    if (temp_fa0_2 < 400.0f) {
                        racer->unk_2B3 = 2;
                    } else if (temp_fa0_2 < 900.0f) {
                        racer->unk_2B3 = 1;
                    }
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

            if ((racer->unk_2B2 != 0) && (racer->shadowPos.y != -54321.0f)) {
                if (racer->unk_165 == 0) {
                    if (racer->unk_284 == 1) {
                        var_fs0 = ((COS(racer->unk_27C) * 0.15f) + 0.85f) * D_800CE750;
                    } else {
                        var_fs0 = D_800CE750;
                    }

                    Matrix_SetLockedLookAtFromVectors(
                        &gGfxPool->unk_20A88[racer->id], NULL, racer->shadowColorStrength * D_800CE748, 0.1f,
                        racer->shadowColorStrength * var_fs0, &racer->unk_E8.x, &racer->unk_19C, &racer->shadowPos);
                    racer->unk_165 = 1;
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
        }
        if (gGameMode == GAMEMODE_TIME_ATTACK) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);

            for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
                if (sp4F8->exists) {
                    racer = sp4F8->racer;
                    if ((racer->unk_2B2 != 0) && (racer->shadowPos.y != -54321.0f)) {
                        Matrix_SetLockedLookAtFromVectors(&gGfxPool->unk_20A88[racer->id], NULL,
                                                          sp4F8->scale * D_800CE748, 0.1f, sp4F8->scale * D_800CE750,
                                                          &racer->unk_E8.x, &racer->unk_19C, &racer->shadowPos);
                        gSPMatrix(gfx++, &D_1000000.unk_20A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gDPLoadTextureBlock_4b(gfx++, D_800CDC54[racer->shadowType], G_IM_FMT_I, 32, 64, 0,
                                               G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                               G_TX_NOLOD);
                        gSPVertex(gfx++, D_800CDBA4[racer->shadowType], 4, 0);
                        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
                    }
                }
            }
        }
    } else {
        gRacers[0].speed = gRacers[1].speed = gRacers[2].speed = gRacers[3].speed = 0.0f;
    }

    gSPDisplayList(gfx++, D_303A7D8);

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->unk_178 != 0.0f) {
            if ((racer->machineLod != 0) && (racer->machineLod < 6)) {
                if (racer->unk_166 == 0) {
                    Matrix_ScaleFrom3DMatrix(&gGfxPool->unk_21208[racer->id], NULL, racer->unk_178 * D_800CE748,
                                             racer->unk_178 * D_800CE74C, racer->unk_178 * D_800CE750, &racer->unk_E8,
                                             &racer->unk_10C);
                    racer->unk_166 = 1;
                }
                gSPMatrix(gfx++, &D_1000000.unk_21208[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gfx++);
                gDPSetBlendColor(gfx++, racer->unk_2DA, racer->unk_2DC, racer->unk_2DE, 255);

                if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                    gSPDisplayList(gfx++, D_800CDDB0[racer->machineIndex * 6 + racer->machineLod - 1]);
                } else {
                    gSPDisplayList(gfx++, D_800CE080[racer->machineLod - 1]);
                }
            }
        }
    }
    playerRacer = &gRacers[playerIndex];

    temp_v0_6 = playerRacer->segmentPositionInfo.courseSegment;
    if (temp_v0_6->trackSegmentInfo & TRACK_FLAG_20000000) {
        if (temp_v0_6->unk_6C < playerRacer->segmentPositionInfo.segmentTValue) {
            var_fs0_2 = (1.0f - playerRacer->segmentPositionInfo.segmentLengthProportion) / temp_v0_6->unk_70;
        } else if (playerRacer->segmentPositionInfo.segmentTValue < temp_v0_6->unk_68) {
            var_fs0_2 = playerRacer->segmentPositionInfo.segmentLengthProportion / temp_v0_6->unk_70;
        } else {
            var_s3 = 50;
            var_s4 = 50;
            sp5C4 = 50;
            goto block_115;
        }
        var_s3 = Math_Round(var_fs0_2 * -50.0f) + 100;
        var_s4 = Math_Round(var_fs0_2 * -50.0f) + 100;
        sp5C4 = Math_Round(var_fs0_2 * -50.0f) + 100;
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

    if ((playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_FLAG_20000000) &&
        !(playerRacer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        sp560 = playerRacer->segmentBasis.y.x;
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[0] = Math_Round(sp560 * 120.0f);
        sp55C = playerRacer->segmentBasis.y.y;
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[1] = Math_Round(sp55C * 120.0f);
        sp558 = playerRacer->segmentBasis.y.z;
        gGfxPool->unk_21A88[playerIndex].l[0].l.dir[2] = Math_Round(sp558 * 120.0f);
        if ((playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_PIPE) {
            var_v0 = &D_800E5FE8[playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        } else {
            var_v0 = &D_800E5FEC[playerRacer->segmentPositionInfo.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
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
        if (racer->machineLod != 0) {
            if (racer->unk_164 == 0) {
                Matrix_ScaleFrom3DMatrix(&gGfxPool->unk_20308[racer->id], &racer->unk_124, D_800CE748, D_800CE74C,
                                         D_800CE750, &racer->unk_E8, &racer->unk_10C);
                racer->unk_164 = 1;
            }
            if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(gfx++, D_800CDD38[racer->machineIndex]);
                gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 255);
                gSPDisplayList(gfx++, D_800CDDB0[racer->machineIndex * 6 + racer->machineLod - 1]);
            }
        }
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_90186C8);
        Light_SetLookAtSource(&gGfxPool->unk_21B28, &camera->viewMtx);
        gSPLookAt(gfx++, &gGfxPool->unk_21B28);
        gSPTexture(gfx++, D_800CE768, D_800CE768, 0, G_TX_RENDERTILE, G_ON);

        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        if (COURSE_CONTEXT()->courseData.skybox == 3) {
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
        temp_a1_2 = (s32) (D_800F809C * 4.0f) & 0xFF;

        D_800F80A0 += ((camera->basis.y.x * gRacers->velocity.x) + (camera->basis.y.y * gRacers->velocity.y) +
                       (camera->basis.y.z * gRacers->velocity.z)) *
                      D_800CE76C;
        temp_v1_2 = (s32) (D_800F80A0 * 4.0f) & 0xFF;

        gDPSetTileSize(gfx++, G_TX_RENDERTILE, temp_a1_2, temp_v1_2, temp_v1_2 + 0xFC, temp_v1_2 + 0xFC);

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_800CE764);

        for (racer = sLastRacer; racer >= gRacers; racer--) {
            gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gfx = func_8009CEA0(gfx, racer->character);
        }
    }

    var_s7 = 0;
    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if ((racer->machineLod != 0) && (racer->stateFlags & RACER_STATE_CRASHED)) {
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
            if (sp4F8->exists) {
                racer = sp4F8->racer;
                if (racer->machineLod != 0) {
                    Matrix_ScaleFrom3DMatrix(&gGfxPool->unk_20308[racer->id], &racer->unk_124,
                                             sp4F8->scale * D_800CE748, sp4F8->scale * D_800CE74C,
                                             sp4F8->scale * D_800CE750, &racer->unk_E8, &racer->unk_10C);
                    gSPMatrix(gfx++, &D_1000000.unk_20308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPDisplayList(gfx++, D_800CDD38[racer->machineIndex]);
                    gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 240);
                    gSPDisplayList(gfx++, D_800CDDB0[racer->machineIndex * 6 + racer->machineLod - 1]);
                }
            }
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
        if ((racer->unk_2B3 != 0) && !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
            boosterInfo = &sBoosterInfos[racer->boostersType];

            var_s3_3 = (3 - (sp5C4 & 3)) * 2;
            if ((3 - (sp5C4 & 3)) * 2 < racer->unk_214) {
                var_s3_3 = racer->unk_214;
            }
            sp574 = var_s3_3 * 0.2f;

            // Boost color
            temp_fs0_5 = (f32) racer->boostTimer / sInitialBoostTimer;
            if (temp_fs0_5 != 0.0f) {
                sp574 += (7.5f * sqrtf(temp_fs0_5));
                if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
                    gDPSetEnvColor(gfx++, 255, 223, 0, 255);
                } else {
                    gDPSetEnvColor(gfx++, 91, 255, 91, 255);
                }
            } else {
                gDPSetEnvColor(gfx++, 0, 255, 255, 255);
            }

            sp570 = (racer->unk_17C - D_800F80A4) / (13.0f - D_800F80A4);

            for (var_s3_4 = boosterInfo->count - 1; var_s3_4 >= 0; var_s3_4--) {
                temp_fs0_6 = boosterInfo->size[var_s3_4] * 0.35f;
                temp_fv0_12 = boosterInfo->pos[var_s3_4].x;
                temp_fv1_4 = boosterInfo->pos[var_s3_4].y;
                temp_fa0_4 = boosterInfo->pos[var_s3_4].z - (temp_fs0_6 * 3.6f);
                temp_fs4 = racer->unk_124.xw + ((racer->unk_124.xx * temp_fv0_12) + (racer->unk_124.xy * temp_fv1_4) +
                                                (racer->unk_124.xz * temp_fa0_4));
                temp_fs5 = racer->unk_124.yw + ((racer->unk_124.yx * temp_fv0_12) + (racer->unk_124.yy * temp_fv1_4) +
                                                (racer->unk_124.yz * temp_fa0_4));
                sp54C = racer->unk_124.zw + ((racer->unk_124.zx * temp_fv0_12) + (racer->unk_124.zy * temp_fv1_4) +
                                             (racer->unk_124.zz * temp_fa0_4));

                temp_fs0_6 += sp574;
                temp_fs0_6 *= sp570;
                temp_fs1 = temp_fs0_6 * sp56C;
                gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0_6 * sp568;
                gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0_6 * sp564;
                gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + temp_fs3);

                gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
                temp_fs1 = temp_fs0_6 * sp560;
                gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0_6 * sp55C;
                gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0_6 * sp558;
                gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
                gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                    gEffectsVtxPtr[2].v.tc[1] = 0;
                gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                    gEffectsVtxPtr[3].v.tc[1] = 0x3FF;
                if (racer->unk_2B3 == 2) {
                    temp_fs0_6 = racer->speed * 0.9f;
                    gEffectsVtxPtr[4].v.ob[0] = Math_Round(temp_fs4 - (racer->unk_E8.x.x * temp_fs0_6));
                    gEffectsVtxPtr[4].v.ob[1] = Math_Round(temp_fs5 - (racer->unk_E8.x.y * temp_fs0_6));
                    gEffectsVtxPtr[4].v.ob[2] = Math_Round(sp54C - (racer->unk_E8.x.z * temp_fs0_6));
                    gEffectsVtxPtr[4].v.tc[0] = 0x3FF;
                    gEffectsVtxPtr[4].v.tc[1] = 0;
                    gEffectsVtxPtr += 5;
                } else {
                    gEffectsVtxPtr += 4;
                }
            }
            if (racer->unk_2B3 == 2) {
                temp = boosterInfo->count * 5;
                gSPVertex(gfx++, gEffectsVtxPtr - temp, temp, 0);

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
                gSPVertex(gfx++, gEffectsVtxPtr - boosterInfo->count * 4, boosterInfo->count * 4, 0);

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
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetEnvColor(gfx++, 255, 0, 255, 160);

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (sp4F8->exists) {
                racer = sp4F8->racer;
                if (racer->unk_2B3 != 0) {
                    boosterInfo = &sBoosterInfos[racer->boostersType];

                    sp84 = (f32) ((3 - (sp5C4 & 3)) * 2) * 0.2f;
                    for (var_s3_4 = boosterInfo->count - 1; var_s3_4 >= 0; var_s3_4--) {

                        temp_fs0_10 = boosterInfo->size[var_s3_4] * 0.35f;
                        temp_fv0_13 = boosterInfo->pos[var_s3_4].x;
                        temp_fv1_5 = boosterInfo->pos[var_s3_4].y;
                        temp_fa0_5 = boosterInfo->pos[var_s3_4].z - (temp_fs0_10 * 3.6f);
                        temp_fs4 =
                            racer->unk_124.xw + ((racer->unk_124.xx * temp_fv0_13) + (racer->unk_124.xy * temp_fv1_5) +
                                                 (racer->unk_124.xz * temp_fa0_5));
                        temp_fs5 =
                            racer->unk_124.yw + ((racer->unk_124.yx * temp_fv0_13) + (racer->unk_124.yy * temp_fv1_5) +
                                                 (racer->unk_124.yz * temp_fa0_5));
                        sp54C =
                            racer->unk_124.zw + ((racer->unk_124.zx * temp_fv0_13) + (racer->unk_124.zy * temp_fv1_5) +
                                                 (racer->unk_124.zz * temp_fa0_5));

                        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + (temp_fs1 = temp_fs0_10 * sp56C));
                        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + (temp_fs2 = temp_fs0_10 * sp568));
                        gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + (temp_fs3 = temp_fs0_10 * sp564));
                        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                        gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
                        temp_fs0_10 += sp84;

                        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + (temp_fs1 = temp_fs0_10 * sp560));
                        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + (temp_fs2 = temp_fs0_10 * sp55C));
                        gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + (temp_fs3 = temp_fs0_10 * sp558));
                        gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                        gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                        gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                        gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                            gEffectsVtxPtr[2].v.tc[1] = 0;
                        gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                            gEffectsVtxPtr[3].v.tc[1] = 0x3FF;
                        if (racer->unk_2B3 == 2) {
                            temp_fs0_11 = racer->speed * 0.9f;
                            gEffectsVtxPtr[4].v.ob[0] = Math_Round(temp_fs4 - (racer->unk_E8.x.x * temp_fs0_11));
                            gEffectsVtxPtr[4].v.ob[1] = Math_Round(temp_fs5 - (racer->unk_E8.x.y * temp_fs0_11));
                            gEffectsVtxPtr[4].v.ob[2] = Math_Round(sp54C - (racer->unk_E8.x.z * temp_fs0_11));
                            gEffectsVtxPtr[4].v.tc[0] = 0x3FF;
                            gEffectsVtxPtr[4].v.tc[1] = 0;
                            gEffectsVtxPtr += 5;
                        } else {
                            gEffectsVtxPtr += 4;
                        }
                    }
                    if (racer->unk_2B3 == 2) {
                        temp = boosterInfo->count * 5;
                        gSPVertex(gfx++, gEffectsVtxPtr - temp, temp, 0);

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
                        temp = boosterInfo->count * 4;
                        gSPVertex(gfx++, gEffectsVtxPtr - temp, temp, 0);

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
        }
    }
    gSPDisplayList(gfx++, D_4007FB8);

    var_s3_6 = gExplosions1Count;

    var_s7 = (gExplosions1Index - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((u32) (gEffectsVtxEndPtr - 3) >= (u32) gEffectsVtxPtr)) {
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

        var_s3_6--;

        var_s7 = (var_s7 - 1) & 0x1F;

        gEffectsVtxPtr += 4;
    }
    var_s3_6 = gExplosions2Count;
    var_s7 = (gExplosions2Index - 1) & 7;
    while ((var_s3_6 != 0) && ((gEffectsVtxEndPtr - 3) >= gEffectsVtxPtr)) {
        temp_s1 = &gExplosions2[var_s7];
        temp_fs1 = temp_s1->scale * sp56C;
        temp_fs3 = temp_s1->scale * sp568;
        temp_fs2 = temp_s1->scale * sp564;
        sp538 = temp_s1->scale * sp55C;
        sp53C = temp_s1->scale * sp560;
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
            gDPSetEnvColor(gfx++, 0x1FF - (temp_s1->timer * 16), 0, 0, 0x17F - (temp_s1->timer * 8));
        }

        gDPLoadTextureBlock(gfx++, D_800CDAB8[temp_s1->timer >> 2], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        var_s3_6--;

        var_s7 = (var_s7 - 1) & 7;

        gEffectsVtxPtr += 4;
    }

    gSPDisplayList(gfx++, D_4007FD8);

    var_s3_6 = gMachineDebrisCount;

    var_s7 = (gMachineDebrisIndex - 1) & 0x7F;
    while ((var_s3_6 != 0) && ((gEffectsVtxEndPtr - 2) >= gEffectsVtxPtr)) {

        temp_v0_13 = &gMachineDebris[var_s7];
        gEffectsVtxPtr[0].v.ob[0] = temp_v0_13->cornerPos1.x;
        gEffectsVtxPtr[0].v.ob[1] = temp_v0_13->cornerPos1.y;
        gEffectsVtxPtr[0].v.ob[2] = temp_v0_13->cornerPos1.z;
        gEffectsVtxPtr[1].v.ob[0] = temp_v0_13->cornerPos2.x;
        gEffectsVtxPtr[1].v.ob[1] = temp_v0_13->cornerPos2.y;
        gEffectsVtxPtr[1].v.ob[2] = temp_v0_13->cornerPos2.z;
        gEffectsVtxPtr[2].v.ob[0] = temp_v0_13->cornerPos3.x;
        gEffectsVtxPtr[2].v.ob[1] = temp_v0_13->cornerPos3.y;
        gEffectsVtxPtr[2].v.ob[2] = temp_v0_13->cornerPos3.z;
        gEffectsVtxPtr[0].v.cn[0] = temp_v0_13->red;
        gEffectsVtxPtr[0].v.cn[1] = temp_v0_13->green;
        gEffectsVtxPtr[0].v.cn[2] = temp_v0_13->blue;
        gEffectsVtxPtr[0].v.cn[3] = temp_v0_13->alpha;
        gSPVertex(gfx++, gEffectsVtxPtr, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x7F;
        gEffectsVtxPtr += 3;
    }

    gSPDisplayList(gfx++, D_4008000);

    var_s3_6 = gFlyingSparksCount;
    var_s7 = (gFlyingSparksIndex - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((gEffectsVtxEndPtr - 2) >= gEffectsVtxPtr)) {
        temp_s1_3 = &gFlyingSparks[var_s7];
        gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_s1_3->pos.x - (3.0f * temp_s1_3->velocity.x));
        gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_s1_3->pos.y - (3.0f * temp_s1_3->velocity.y));
        gEffectsVtxPtr[0].v.ob[2] = Math_Round(temp_s1_3->pos.z - (3.0f * temp_s1_3->velocity.z));
        gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_s1_3->pos.x + temp_s1_3->basis.z.x);
        gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_s1_3->pos.y + temp_s1_3->basis.z.y);
        gEffectsVtxPtr[1].v.ob[2] = Math_Round(temp_s1_3->pos.z + temp_s1_3->basis.z.z);
        gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_s1_3->pos.x - temp_s1_3->basis.z.x);
        gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_s1_3->pos.y - temp_s1_3->basis.z.y);
        gEffectsVtxPtr[2].v.ob[2] = Math_Round(temp_s1_3->pos.z - temp_s1_3->basis.z.z);

        gEffectsVtxPtr[0].v.cn[0] = 0xFF;
        gEffectsVtxPtr[0].v.cn[1] = gEffectsVtxPtr[0].v.cn[2] = 0;
        gEffectsVtxPtr[0].v.cn[3] = 0;
        gEffectsVtxPtr[1].v.cn[0] = gEffectsVtxPtr[2].v.cn[0] = gEffectsVtxPtr[1].v.cn[1] = gEffectsVtxPtr[2].v.cn[1] =
            0xFF;
        gEffectsVtxPtr[1].v.cn[2] = gEffectsVtxPtr[2].v.cn[2] = 0;
        gEffectsVtxPtr[1].v.cn[3] = gEffectsVtxPtr[2].v.cn[3] = 0xFF;
        gSPVertex(gfx++, gEffectsVtxPtr, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
        gEffectsVtxPtr += 3;
    }

    gSPDisplayList(gfx++, D_4008028);

    var_s3_6 = gCollisionSparkCount;
    var_s7 = (gCollisionSparkIndex - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((gEffectsVtxEndPtr - 3) >= gEffectsVtxPtr)) {
        temp_s1_4 = &gCollisionSparks[var_s7];
        temp_v0_14 = temp_s1_4->racer;
        if (temp_v0_14->unk_2B3 != 0) {
            temp_fv1_6 = SQ(temp_s1_4->timer - 1) * -0.15f;
            temp_fs4 = temp_s1_4->pos.x + (temp_fv1_6 * temp_v0_14->trueBasis.y.x);
            temp_fs5 = temp_s1_4->pos.y + (temp_fv1_6 * temp_v0_14->trueBasis.y.y);
            sp54C = temp_s1_4->pos.z + (temp_fv1_6 * temp_v0_14->trueBasis.y.z);

            temp_fv0_16 = temp_s1_4->scale;
            temp_fs1 = temp_fv0_16 * sp56C;
            temp_fs3 = temp_fv0_16 * sp568;
            temp_fs2 = temp_fv0_16 * sp564;
            sp53C = temp_fv0_16 * sp560;
            sp538 = temp_fv0_16 * sp55C;
            sp534 = temp_fv0_16 * sp558;

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
            gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                gEffectsVtxPtr[2].v.tc[1] = 0;
            gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                gEffectsVtxPtr[3].v.tc[1] = 0x7FF;

            gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1_4->timer >> 1, G_ON);
            gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1_4->timer * 8), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1_4->timer * 16), 0, 255 - (temp_s1_4->timer * 4));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            gEffectsVtxPtr += 4;
        }
        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    gSPDisplayList(gfx++, D_4008130);

    var_s3_6 = gSmokesCount;
    var_s7 = (gSmokesIndex - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((gEffectsVtxEndPtr - 3) >= gEffectsVtxPtr)) {
        temp_s1_5 = &gSmokes[var_s7];
        if (temp_s1_5->racer->unk_2B3 != 0) {
            temp_fv0_17 = temp_s1_5->scale;
            temp_fs1 = temp_fv0_17 * sp56C;
            temp_fs3 = temp_fv0_17 * sp568;
            temp_fs2 = temp_fv0_17 * sp564;
            sp53C = temp_fv0_17 * sp560;
            sp538 = temp_fv0_17 * sp55C;
            sp534 = temp_fv0_17 * sp558;
            gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_s1_5->pos.x + temp_fs1);
            gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_s1_5->pos.y + temp_fs3);
            gEffectsVtxPtr[0].v.ob[2] = Math_Round(temp_s1_5->pos.z + temp_fs2);
            gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_s1_5->pos.x - temp_fs1);
            gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_s1_5->pos.y - temp_fs3);
            gEffectsVtxPtr[2].v.ob[2] = Math_Round(temp_s1_5->pos.z - temp_fs2);
            gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_s1_5->pos.x + sp53C);
            gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_s1_5->pos.y + sp538);
            gEffectsVtxPtr[1].v.ob[2] = Math_Round(temp_s1_5->pos.z + sp534);
            gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_s1_5->pos.x - sp53C);
            gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_s1_5->pos.y - sp538);
            gEffectsVtxPtr[3].v.ob[2] = Math_Round(temp_s1_5->pos.z - sp534);
            gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] = gEffectsVtxPtr[1].v.tc[1] =
                gEffectsVtxPtr[2].v.tc[1] = 0;
            gEffectsVtxPtr[0].v.tc[1] = gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] =
                gEffectsVtxPtr[3].v.tc[1] = 0x7FF;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1_5->timer >> 1, G_ON);
            gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, 180, 150, 100, 230 - (temp_s1_4->timer * 4));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            gEffectsVtxPtr += 4;
        }
        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    gSPDisplayList(gfx++, aSetupPitForceFieldDL);

    if (!gGamePaused) {
        var_s3_6 = gGameFrameCount & 7;
    } else {
        var_s3_6 = 0;
    }

    racer = sLastRacer;
    while ((racer >= gRacers) && ((gEffectsVtxEndPtr - 3) >= gEffectsVtxPtr)) {
        if ((racer->pitForceFieldSize != 0.0f) && (racer->unk_2B3 != 0)) {
            temp_fs0_14 = 3.0f - ((1.0f - racer->pitForceFieldSize) * 19.0f);
            temp_fs4 = racer->segmentPositionInfo.pos.x + (temp_fs0_14 * racer->trueBasis.y.x);
            temp_fs5 = racer->segmentPositionInfo.pos.y + (temp_fs0_14 * racer->trueBasis.y.y);
            temp_fs0_15 = racer->pitForceFieldSize * 38.0f;
            sp54C = racer->segmentPositionInfo.pos.z + (temp_fs0_14 * racer->trueBasis.y.z);
            temp_fs1 = temp_fs0_15 * sp56C;
            temp_fs3 = temp_fs0_15 * sp568;
            temp_fs2 = temp_fs0_15 * sp564;
            temp_fs0_15 = racer->pitForceFieldSize * 40.0f;
            gEffectsVtxPtr[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            gEffectsVtxPtr[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
            gEffectsVtxPtr[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
            gEffectsVtxPtr[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            gEffectsVtxPtr[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
            gEffectsVtxPtr[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
            temp_fs1 = temp_fs0_15 * sp560;
            gEffectsVtxPtr[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp55C;
            gEffectsVtxPtr[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp558;
            gEffectsVtxPtr[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
            gEffectsVtxPtr[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            gEffectsVtxPtr[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
            gEffectsVtxPtr[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
            gEffectsVtxPtr[2].v.tc[0] = gEffectsVtxPtr[3].v.tc[0] = gEffectsVtxPtr[3].v.tc[1] =
                gEffectsVtxPtr[0].v.tc[1] = 0x20;
            gEffectsVtxPtr[2].v.tc[1] = gEffectsVtxPtr[0].v.tc[0] = gEffectsVtxPtr[1].v.tc[0] =
                gEffectsVtxPtr[1].v.tc[1] = 0x7E0;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, var_s3_6, G_ON);
            gSPVertex(gfx++, gEffectsVtxPtr, 4, 0);
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            gEffectsVtxPtr += 4;
        }
        racer--;
    }

    gSPDisplayList(gfx++, aSetupFallExplosionDL);

    var_s3_6 = gFallExplosionsCount;
    var_s7 = (gFallExplosionsIndex - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((gEffectsVtxEndPtr - 7) >= gEffectsVtxPtr)) {
        temp_s1_6 = &gFallExplosions[var_s7];
        racer = temp_s1_6->racer;
        temp_s4 = temp_s1_6->timer - 5;
        if (temp_s1_6->timer == 0) {
            break;
        }

        if ((temp_s4 >= 0) && (temp_s4 < 60)) {
            f32 temp;
            if ((gEffectsVtxEndPtr - 3) < gEffectsVtxPtr) {
                break;
            }

            temp = SIN(((s32) (temp_s4 << 0xA) / 60)) * 163.64f;

            if (temp_s4 < 20) {
                sp5C4 = 255;
            } else {
                sp5C4 = (s32) ((60 - temp_s4) * 255) / 40;
            }

            temp_fs0_15 = temp * temp_s1_6->scale;
            temp_fs1 = temp_fs0_15 * sp56C;
            gEffectsVtxPtr[0].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp568;
            gEffectsVtxPtr[0].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp564;
            gEffectsVtxPtr[0].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z + temp_fs3);
            gEffectsVtxPtr[2].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x - temp_fs1);
            gEffectsVtxPtr[2].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y - temp_fs2);
            gEffectsVtxPtr[2].v.ob[2] = Math_Round(racer->segmentPositionInfo.pos.z - temp_fs3);
            temp_fs1 = temp_fs0_15 * sp560;
            gEffectsVtxPtr[1].v.ob[0] = Math_Round(racer->segmentPositionInfo.pos.x + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp55C;
            gEffectsVtxPtr[1].v.ob[1] = Math_Round(racer->segmentPositionInfo.pos.y + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp558;
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

        if (temp_s1_6->timer < 0x1A) {
            if ((gEffectsVtxEndPtr - 3) < gEffectsVtxPtr) {
                break;
            }
            temp_fs0_18 = (temp_s1_6->scale * 163.64f * (f32) temp_s1_6->timer) / 26.0f;
            temp_fs1 = racer->trueBasis.x.x * temp_fs0_18;
            temp_fs3 = racer->trueBasis.x.y * temp_fs0_18;
            temp_fs2 = racer->trueBasis.x.z * temp_fs0_18;
            sp53C = racer->trueBasis.z.x * temp_fs0_18;
            sp538 = racer->trueBasis.z.y * temp_fs0_18;
            sp534 = racer->trueBasis.z.z * temp_fs0_18;
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
            gDPSetEnvColor(gfx++, 0, 0, 255, (((26 - temp_s1_6->timer) * 255) / 26));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            gEffectsVtxPtr += 4;
        }

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    if (gRaceIntroTimer != 0) {
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
                    Audio_TriggerSystemSE(0x2F);
                }
            } else if (gRaceIntroTimer > 100) {
                var_s2 = aCountdown2Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 160)) {
                    Audio_TriggerSystemSE(NA_SE_9);
                }
            } else if (gRaceIntroTimer > 40) {
                var_s2 = aCountdown1Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 100)) {
                    Audio_TriggerSystemSE(0xA);
                }
            } else {
                var_s2 = aCountdownGoTex;
                if ((playerIndex == 0) && (!gGamePaused)) {
                    if (gRaceIntroTimer == 40) {
                        Audio_TriggerSystemSE(0xB);
                    }
                    if ((gRaceIntroTimer == 1) && (gTitleDemoState == TITLE_DEMO_INACTIVE)) {
                        if (gCurrentCourseInfo->courseIndex < COURSE_EDIT_1) {
                            func_8007E0AC(D_800CF4D8[gCurrentCourseInfo->courseIndex]);
                        } else if (gCurrentCourseInfo->courseIndex == COURSE_X_1) {
                            func_8007E0AC(0x18);
                        } else {
                            func_8007E0AC(D_800CF4F0[COURSE_CONTEXT()->courseData.venue]);
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
        if ((gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_DEATH_RACE)) {
            if (gTotalRacers < 3) {
                var_s4_5 = gTotalRacers;
            } else {
                var_s4_5 = 3;
            }

            for (i = 0; i < var_s4_5; i++) {

                racer = gRacersByPosition[i];
                if (racer->machineLod != 0) {
                    if ((playerIndex != racer->id) &&
                        !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED))) {
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
                        temp_fv0_19 = racer->segmentPositionInfo.pos.z + (20.0f * racer->trueBasis.y.z);
                        temp_fv1_7 =
                            1.0f / (camera->projectionViewMtx.ww + ((camera->projectionViewMtx.wx * temp_fs4) +
                                                                    (camera->projectionViewMtx.wy * temp_fs5) +
                                                                    (camera->projectionViewMtx.wz * temp_fv0_19)));
                        sp56C = (camera->projectionViewMtx.xw + ((camera->projectionViewMtx.xx * temp_fs4) +
                                                                 (camera->projectionViewMtx.xy * temp_fs5) +
                                                                 (camera->projectionViewMtx.xz * temp_fv0_19))) *
                                temp_fv1_7;
                        sp568 = (camera->projectionViewMtx.yw + ((camera->projectionViewMtx.yx * temp_fs4) +
                                                                 (camera->projectionViewMtx.yy * temp_fs5) +
                                                                 (camera->projectionViewMtx.yz * temp_fv0_19))) *
                                temp_fv1_7;
                        sp564 = (camera->projectionViewMtx.zw + ((camera->projectionViewMtx.zx * temp_fs4) +
                                                                 (camera->projectionViewMtx.zy * temp_fs5) +
                                                                 (camera->projectionViewMtx.zz * temp_fv0_19))) *
                                temp_fv1_7;
                        gDPPipeSync(gfx++);
                        gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);

                        if (gNumPlayers < 2) {
                            gDPLoadTextureBlock(gfx++, sPosition1PMarkerTexs[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 30, 0,
                                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            temp_s7_7 =
                                ((s32) ((camera->currentVpScaleX * sp56C) + camera->currentVpTransX + 0.5f) - 0xC) << 2;
                            sp5C4 = ((s32) ((-camera->currentVpScaleY * sp568) + camera->currentVpTransY + 0.5f) - 0x1E)
                                    << 2;
                            gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (24 * 4 - 1),
                                                    sp5C4 + (30 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                        } else {
                            gDPLoadTextureBlock(gfx++, sPositionMPMarkerTexs[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            temp_s7_7 = ((s32) ((camera->currentVpScaleX * sp56C) + camera->currentVpTransX + 0.5f) - 8)
                                        << 2;
                            sp5C4 = ((s32) ((-camera->currentVpScaleY * sp568) + camera->currentVpTransY + 0.5f) - 0x10)
                                    << 2;
                            gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (16 * 4 - 1),
                                                    sp5C4 + (16 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                        }
                    }
                }
            }
            if ((gGameMode == GAMEMODE_GP_RACE) && (sRivalRacer != NULL) && (sRivalRacer->machineLod != 0) &&
                !(sRivalRacer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FINISHED)) &&
                (gRacers[0].position >= sRivalRacer->position)) {
                temp_fs4 = sRivalRacer->segmentPositionInfo.pos.x + (20.0f * sRivalRacer->trueBasis.y.x);
                temp_fs5 = sRivalRacer->segmentPositionInfo.pos.y + (20.0f * sRivalRacer->trueBasis.y.y);
                temp_fv0_19 = sRivalRacer->segmentPositionInfo.pos.z + (20.0f * sRivalRacer->trueBasis.y.z);
                temp_fv1_7 = 1.0f / (camera->projectionViewMtx.ww + ((camera->projectionViewMtx.wx * temp_fs4) +
                                                                     (camera->projectionViewMtx.wy * temp_fs5) +
                                                                     (camera->projectionViewMtx.wz * temp_fv0_19)));
                sp56C = (camera->projectionViewMtx.xw +
                         ((camera->projectionViewMtx.xx * temp_fs4) + (camera->projectionViewMtx.xy * temp_fs5) +
                          (camera->projectionViewMtx.xz * temp_fv0_19))) *
                        temp_fv1_7;
                sp568 = (camera->projectionViewMtx.yw +
                         ((camera->projectionViewMtx.yx * temp_fs4) + (camera->projectionViewMtx.yy * temp_fs5) +
                          (camera->projectionViewMtx.yz * temp_fv0_19))) *
                        temp_fv1_7;
                sp564 = (camera->projectionViewMtx.zw +
                         ((camera->projectionViewMtx.zx * temp_fs4) + (camera->projectionViewMtx.zy * temp_fs5) +
                          (camera->projectionViewMtx.zz * temp_fv0_19))) *
                        temp_fv1_7;
                gDPPipeSync(gfx++);
                gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);
                gDPLoadTextureBlock(gfx++, aRivalMarkerTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                temp_s7_7 = ((s32) ((camera->currentVpScaleX * sp56C) + camera->currentVpTransX + 0.5f) - 0x10) << 2;
                sp5C4 = ((s32) ((-camera->currentVpScaleY * sp568) + camera->currentVpTransY + 0.5f) - 0x10) << 2;
                gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (32 * 4 - 1), sp5C4 + (16 * 4 - 1), 0, 0,
                                        0, 1 << 10, 1 << 10);
            }
            gDPPipeSync(gfx++);
        }

        gDPSetDepthSource(gfx++, G_ZS_PIXEL);

        if (playerRacer->distanceFromRacerBehind < 3000.0f) {
            temp_v0_27 = playerRacer->racerBehind;
            if ((temp_v0_27->position == (playerRacer->position + 1)) &&
                !(temp_v0_27->stateFlags & RACER_STATE_RETIRED)) {
                temp_fa0_6 = playerRacer->segmentPositionInfo.pos.x - temp_v0_27->segmentPositionInfo.pos.x;
                temp_fv1_9 = playerRacer->segmentPositionInfo.pos.y - temp_v0_27->segmentPositionInfo.pos.y;
                sp564 = playerRacer->segmentPositionInfo.pos.z - temp_v0_27->segmentPositionInfo.pos.z;
                if ((((camera->basis.x.x * temp_fa0_6) + (temp_fv1_9 * camera->basis.x.y) +
                      (sp564 * camera->basis.x.z)) < 0.0f)) {
                    goto end;
                }
                var_fs1 =
                    (camera->basis.z.x * temp_fa0_6) + (temp_fv1_9 * camera->basis.z.y) + (sp564 * camera->basis.z.z);
                var_fs3 =
                    (camera->basis.y.x * temp_fa0_6) + (temp_fv1_9 * camera->basis.y.y) + (sp564 * camera->basis.y.z);
                temp_fv0_21 = SQ(var_fs1) + SQ(var_fs3);

                if ((temp_fv0_21 < 0.1f)) {
                    goto end;
                }
                temp_fa1_4 = ((camera->currentScissorRight - camera->currentScissorLeft) * 0.5f) + 4.0f;
                sp568 = ((camera->currentScissorBottom - camera->currentScissorTop) * 0.5f) - 4.0f;
                temp_fv0_22 = sqrtf((SQ(temp_fa1_4) + SQ(sp568)) / temp_fv0_21);
                var_fs1 *= temp_fv0_22;
                var_fs3 *= temp_fv0_22;
                if (sp568 < var_fs3) {
                    temp_fv0_22 = sp568 / var_fs3;
                    var_fs1 *= temp_fv0_22;
                    var_fs3 *= temp_fv0_22;
                }

                gSPClearGeometryMode(gfx++, G_ZBUFFER);
                gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                if (gGamePaused) {
                    var_s7 = 255;
                } else {
                    var_s7 = 255 - ((gGameFrameCount & 0xF) * 0x10);
                }

                gDPSetPrimColor(gfx++, 0, 0, 255, var_s7, 0,
                                (255 - (s32) (playerRacer->distanceFromRacerBehind * 0.085f)));

                if (gNumPlayers < 2) {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarker1PTex, G_IM_FMT_IA, 32, 23, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    temp_s7_7 =
                        ((s32) (((camera->currentScissorLeft + camera->currentScissorRight) * 0.5f) + var_fs1 + 0.5f) -
                         0x10)
                        << 2;
                    temp_a3_4 =
                        ((s32) (((camera->currentScissorTop + camera->currentScissorBottom) * 0.5f) + var_fs3 + 0.5f) -
                         0x1C)
                        << 2;

                    gSPScisTextureRectangle(gfx++, temp_s7_7, temp_a3_4, temp_s7_7 + (32 * 4 - 1),
                                            temp_a3_4 + (23 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                } else {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarkerMPTex, G_IM_FMT_IA, 16, 10, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    temp_s7_7 =
                        ((s32) (((camera->currentScissorLeft + camera->currentScissorRight) * 0.5f) + var_fs1 + 0.5f) -
                         8)
                        << 2;
                    temp_a3_4 =
                        ((s32) (((camera->currentScissorTop + camera->currentScissorBottom) * 0.5f) + var_fs3 + 0.5f) -
                         0xA)
                        << 2;
                    gSPScisTextureRectangle(gfx++, temp_s7_7, temp_a3_4, temp_s7_7 + (16 * 4 - 1),
                                            temp_a3_4 + (10 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                }

                if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_DEATH_RACE)) {
                    if (playerRacer->distanceFromRacerBehind < 1000.0f) {
                        if (!(playerRacer->unk_08 & 0x8000)) {
                            playerRacer->unk_08 |= 0x8000;
                            if (gEnableRaceSfx) {
                                Audio_TriggerSystemSE(0x3A);
                            }
                        }
                    } else if (playerRacer->distanceFromRacerBehind > 2500.0f) {
                        playerRacer->unk_08 &= ~0x8000;
                    }
                }
            }
        }
    }
end:
    return gfx;
}
#else
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/game/racer/Racer_Draw.s")
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/racer/Racer_Draw.s")
#endif
#endif

Gfx* func_8009CBE8(Gfx* gfx, s32 arg1, s32 red, s32 green, s32 blue) {
    u8 character;

    if (arg1 < 6) {
        character = D_800F8504[arg1 - 1];
    } else if (arg1 == 6) {
        character = D_800F8504[5];
    } else {
        character = D_800F8504[6];
    }

    gSPDisplayList(gfx++, D_800CDD38[character]);
    gDPSetEnvColor(gfx++, red, green, blue, 255);
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CCBC(Gfx* gfx, s32 character, s32 arg2) {
    Machine* temp_t0 = &gMachines[character];

    gSPDisplayList(gfx++, D_800CDD38[character]);
    gDPSetEnvColor(gfx++, temp_t0->red[arg2], temp_t0->green[arg2], temp_t0->blue[arg2], 255);
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CD60(Gfx* gfx, s32 character) {
    Machine* temp_v1 = &gMachines[character];

    gDPLoadTextureBlock_4b(gfx++, D_800CDC54[temp_v1->shadowType], G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);

    gSPVertex(gfx++, D_800CDBA4[temp_v1->shadowType], 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    return gfx;
}

Gfx* func_8009CE70(Gfx* gfx, s32 character) {
    gSPDisplayList(gfx++, D_800CDDB0[character * 6]);
    return gfx;
}

Gfx* func_8009CEA0(Gfx* gfx, s32 character) {
    gSPDisplayList(gfx++, D_800CDAD8[character]);
    return gfx;
}
