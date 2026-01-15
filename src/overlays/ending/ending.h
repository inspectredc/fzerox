#ifndef ENDING_H
#define ENDING_H

#include "fzx_math.h"
#include "unk_structs.h"
#include "libc/stdbool.h"

typedef enum EndingCutsceneResultsCommand {
    /* -1 */ ENDING_CS_RESULTS_DONE = -1,
    /*  0 */ ENDING_CS_RESULTS_COMPLETED_ITEM = 0,
    /*  1 */ ENDING_CS_RESULTS_CONGRATULATIONS,
    /*  2 */ ENDING_CS_RESULTS_END_SCREEN,
    /*  3 */ ENDING_CS_RESULTS_CUP_INFO,
    /*  4 */ ENDING_CS_RESULTS_RACE_RESULT,
    /*  5 */ ENDING_CS_RESULTS_TOTAL_RANKING,
} EndingCutsceneResultsCommand;

typedef struct EndingCutsceneResults {
    s16 cmd;
    s16 course;
    s16 isDrawn;
    s16 height;
    f32 left;
    f32 gapFromLast;
} EndingCutsceneResults; // size = 0x10

typedef enum PodiumState {
    /* 0 */ PODIUM_WAIT,
    /* 1 */ PODIUM_RAISE,
    /* 2 */ PODIUM_RAISED,
} PodiumState;

#define PODIUM_ACTIVATED(positionIndex) (1 << (positionIndex))

#define PODIUM_DRAW_BODY 1
#define PODIUM_DRAW_HOLE 2

typedef struct Podium {
    s16 state;
    u16 flags;
    s16 timer;
    Vec3f pos;
    Vec3f lookAt;
} Podium; // size = 0x20

typedef struct PodiumDrawData {
    Mtx bodyMtx[3];
    Mtx holeMtx[3];
    Vtx holeVtxs[3][13];
    Mtx racerCharacterMtx[3];
} PodiumDrawData; // size = 0x4B0

typedef struct FireworksLauncher {
    Vec3f pos;
    s32 left;
    s32 top;
    s8 unk_14[0x4];
    Vec3f velocity;
    s8 state;
    s8 previousState;
    f32 scale;
    s8 style;
    s16 indexStart;
    s16 count;
    s32 fuseTimer;
    s8 unk_38[0x4];
    s32 unk_3C;
} FireworksLauncher; // size = 0x40

typedef struct Firework {
    Vec3f pos;
    s32 left;
    s32 top;
    s8 unk_14[0x4];
    Vec3f velocity;
    s8 unk_24[0x4];
    s32 unk_28;
    s32 unk_2C;
    s8 unk_30[0x4];
} Firework; // size = 0x34

typedef enum EndScreenState {
    /* 0 */ END_SCREEN_INACTIVE,
    /* 1 */ END_SCREEN_FADE_IN,
    /* 2 */ END_SCREEN_WAIT,
    /* 3 */ END_SCREEN_FADE_OUT,
} EndScreenState;

typedef enum EndingState {
    /* 0 */ ENDING_START,
    /* 1 */ ENDING_FADE_IN_CONGRATULATIONS,
    /* 2 */ ENDING_SCROLL_RESULTS,
    /* 3 */ ENDING_SLOW_RACERS,
    /* 4 */ ENDING_PODIUMS,
    /* 5 */ ENDING_END_SCREEN,
    /* 6 */ ENDING_SETUP_THANKS_FOR_PLAYING,
    /* 7 */ ENDING_THANKS_FOR_PLAYING,
} EndingState;

typedef enum FireworksType {
    /* 0 */ FIREWORKS_NONE,
    /* 1 */ FIREWORKS_SIDE,
    /* 2 */ FIREWORKS_CHARACTER,
} FireworksType;

typedef enum FireworksState {
    /* 0 */ FIREWORKS_CREATE,
    /* 1 */ FIREWORKS_WAIT_FOR_LAUNCH,
    /* 2 */ FIREWORKS_LAUNCH,
    /* 3 */ FIREWORKS_EXPLODE,
} FireworksState;

typedef enum FireworksStyle {
    /*  0 */ FIREWORKS_STYLE_0,
    /*  1 */ FIREWORKS_STYLE_1,
    /*  2 */ FIREWORKS_STYLE_2,
    /*  3 */ FIREWORKS_STYLE_3,
    /*  4 */ FIREWORKS_STYLE_4,
    /*  5 */ FIREWORKS_STYLE_5,
    /*  6 */ FIREWORKS_STYLE_6,
    /* 32 */ FIREWORKS_STYLE_CHARACTER = 32,
} FireworksStyle;

#define FIREWORK_OFFSCREEN 0x200

#define MAX_FIREWORKS_LAUNCHERS 10

#define ENDING_CHARACTER_FIREWORKS (1 << 0)
#define ENDING_SHOW_PODIUM_SEQUENCE (1 << 1)
#define ENDING_DRAW_CONGRATULATIONS (1 << 2)
#define ENDING_SIDE_VIEW_FIREWORKS (1 << 3)
#define ENDING_FOLLOW_WITH_CREDITS (1 << 4)
#define ENDING_SHOW_END_SCREEN (1 << 5)
#define ENDING_NOT_ON_PODIUM (1 << 6)

s32 EndingCutscene_UpdateState(void);
Gfx* EndingCutscene_DrawScrollingResults(Gfx* gfx);
Gfx* EndingCutscene_DrawFinalResultsRaceResult(Gfx*, EndingCutsceneResults*, f32);
Gfx* EndingCutscene_DrawFinalResultsPosition(Gfx* gfx, s32 xPos, s32 yPos, s32 position, bool shouldHighlight);
Gfx* EndingCutscene_DrawFinalResultsCupInfo(Gfx*, EndingCutsceneResults*, f32);
void EndingCutscene_FadeInThanksForPlaying(void);
Gfx* EndingCutscene_DrawThanksForPlayingWindow(Gfx* gfx);
Gfx* EndingCutscene_DrawTotalRanking(Gfx*, EndingCutsceneResults*, f32);
Gfx* EndingCutscene_DrawResultsRacersKOd(Gfx* gfx, s32 left, s32 top, s32 racersKOd);
void EndingCutscene_FadeEndScreen(void);
Gfx* EndingCutscene_DrawEndScreen(Gfx* gfx);
void EndingCutscene_InitPodiums(void);
void EndingCutscene_UpdatePodiums(void);
Gfx* EndingCutscene_DrawPodiums(Gfx* gfx);

Gfx* EndingCutsceneEffects_DrawPodiumRacerCharacters(Gfx* gfx);
void EndingCutsceneEffects_Init(void);
void EndingCutsceneEffects_Update(void);

extern PodiumDrawData gPodiumDrawData[2];

extern PodiumDrawData* gPodiumDrawDataPtr;
extern s16 sCupDifficulty;
extern Podium gPodiums[3];
extern u16 gPodiumActiveFlags;

extern u16 D_i7_8014ADA8[];
extern u16 D_i7_8014AE30[];
extern u16 D_i7_8014AEB8[];

extern s16 gActiveFireworks;
extern s32 sFireworksType;

#endif // ENDING_H
