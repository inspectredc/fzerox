#ifndef TRANSITION_H
#define TRANSITION_H

#include "libultra/ultra64.h"
#include "other_types.h"
#include "fzx_math.h"

typedef struct LargeTile {
    s8 state;
    u8 alpha;
} LargeTile; // size = 0x2

typedef struct WhirlTile {
    s8 state;
    Vec3f pos;
    Vec3f velocity;
} WhirlTile; // size = 0x1C

typedef struct SpiralTile {
    s8 state;
    s8 scaleTimer;
    Vec3f pos;
    f32 scale;
} SpiralTile; // size = 0x14

typedef struct TransitionInfo {
    s32 work0;
    s32 work1;
    s32 work2;
    s32 work3;
    s32 work4;
} TransitionInfo; // size = 0x14

typedef struct Transition {
    s32 activeTransitionType;
    s32 queuedTransitionType;
    s32 state;
    s16 timer;
    s16 argument;
    u16 appearType;
    u16 flags;
    TexturePtr backgroundBuffer;
    void* workBuffer;
    TransitionInfo transitionInfo;
} Transition; // size = 0x30

typedef enum TransitionState {
    /* 0 */ TRANSITION_INACTIVE,
    /* 1 */ TRANSITION_APPEARING,
    /* 2 */ TRANSITION_HIDING,
} TransitionState;

typedef enum TransitionAppearType {
    /* 0 */ TRANSITION_HIDE,
    /* 1 */ TRANSITION_APPEAR,
} TransitionAppearType;

#define TRANSITION_BORDER_WIDTH 12
#define TRANSITION_BORDER_HEIGHT 8
#define TRANSITION_BACKGROUND_WIDTH (SCREEN_WIDTH - TRANSITION_BORDER_WIDTH * 2)
#define TRANSITION_BACKGROUND_HEIGHT (SCREEN_HEIGHT - TRANSITION_BORDER_HEIGHT * 2)

typedef enum TransitionType {
    /*  0 */ TRANSITION_TYPE_NONE,
    /*  1 */ TRANSITION_TYPE_SMALL_TILES,
    /*  2 */ TRANSITION_TYPE_LARGE_TILES,
    /*  3 */ TRANSITION_TYPE_TILED_WHIRL,
    /*  4 */ TRANSITION_TYPE_TILED_SPIRAL,
    /*  5 */ TRANSITION_TYPE_FADE,
    /*  6 */ TRANSITION_TYPE_STATIC_FADE,
    /*  7 */ TRANSITION_TYPE_PHASED_STRIPS,
    /*  8 */ TRANSITION_TYPE_GREYSCALE_PALETTE,
    /*  9 */ TRANSITION_TYPE_WIPE,
    /* 10 */ TRANSITION_TYPE_INSTANT,
} TransitionType;

#define TRANSITION_STATE_INACTIVE 0

#define TRANSITION_FLAG_SET_BACKGROUND_BUFFER (1 << 0)
#define TRANSITION_FLAG_DRAW (1 << 1)
#define TRANSITION_FLAG_FILL_BLACK (1 << 2)
#define TRANSITION_FLAG_FINISHED (1 << 3)
#define TRANSITION_FLAG_GREYSCALE (1 << 4)
#define TRANSITION_FLAG_INVERSE_GREYSCALE (1 << 5)
#define TRANSITION_FLAG_CONVERT_TO_PALETTE (1 << 6)

typedef enum TransitionSmallTilesState {
    /* 1 */ SMALL_TILES_START_HIDE = 1,
    /* 2 */ SMALL_TILES_WAIT,
    /* 3 */ SMALL_TILES_START_APPEAR,
    /* 4 */ SMALL_TILES_FINISHED,
} TransitionSmallTilesState;

#define SMALL_TILES_WIDTH 4
#define SMALL_TILES_HEIGHT 4
#define SMALL_TILES_COLUMNS (TRANSITION_BACKGROUND_WIDTH / SMALL_TILES_WIDTH)
#define SMALL_TILES_ROWS (TRANSITION_BACKGROUND_HEIGHT / SMALL_TILES_HEIGHT)
#define SMALL_TILES_WORK_SIZE (SMALL_TILES_COLUMNS * SMALL_TILES_ROWS / 2)

typedef enum SmallTilesTileState {
    /* 0 */ SMALL_TILES_TILE_UNSET,
    /* 1 */ SMALL_TILES_TILE_SET,
    /* 2 */ SMALL_TILES_TILE_FINISHED,
} SmallTilesTileState;

typedef enum TransitionLargeTilesState {
    /* 1 */ LARGE_TILES_START = 1,
    /* 2 */ LARGE_TILES_FINISHED,
} TransitionLargeTilesState;

#define LARGE_TILES_COLUMNS 8
#define LARGE_TILES_ROWS 8
#define LARGE_TILES_WIDTH (TRANSITION_BACKGROUND_WIDTH / LARGE_TILES_COLUMNS)
#define LARGE_TILES_HEIGHT (TRANSITION_BACKGROUND_HEIGHT / LARGE_TILES_ROWS)
#define LARGE_TILES_COUNT (LARGE_TILES_COLUMNS * LARGE_TILES_ROWS)

#define LARGE_TILES_REMAINING(info) ((info)->work0)

typedef enum LargeTilesTileState {
    /* 0 */ LARGE_TILES_TILE_UNSET,
    /* 1 */ LARGE_TILES_TILE_SET,
    /* 2 */ LARGE_TILES_TILE_FINISHED,
} LargeTilesTileState;

#define TILED_COLUMNS 8
#define TILED_ROWS 8
#define TILED_WIDTH (TRANSITION_BACKGROUND_WIDTH / TILED_COLUMNS)
#define TILED_HEIGHT (TRANSITION_BACKGROUND_HEIGHT / TILED_ROWS)
#define TILED_COUNT (TILED_COLUMNS * TILED_ROWS)

typedef enum TransitionTiledWhirlState {
    /* 1 */ TILED_WHIRL_START = 1,
    /* 2 */ TILED_WHIRL_WAIT,
    /* 3 */ TILED_WHIRL_FINISHED,
} TransitionTiledWhirlState;

typedef enum WhirlTilesTileState {
    /* 0 */ WHIRL_TILES_TILE_UNSET,
    /* 1 */ WHIRL_TILES_TILE_SET,
    /* 2 */ WHIRL_TILES_TILE_FINISHED,
} WhirlTilesTileState;

#define WHIRL_CORNER_ARG(transition) ((transition)->argument)

typedef enum TransitionTiledSpiralState {
    /* 1 */ TILED_SPIRAL_START = 1,
    /* 2 */ TILED_SPIRAL_WAIT,
    /* 3 */ TILED_SPIRAL_FINISHED,
} TransitionTiledSpiralState;

typedef enum SpiralTilesTileState {
    /* 0 */ SPIRAL_TILES_TILE_UNSET,
    /* 1 */ SPIRAL_TILES_TILE_SET,
    /* 2 */ SPIRAL_TILES_TILE_FINISHED,
} SpiralTilesTileState;

typedef enum SpiralTileDirection {
    /* 0 */ TILED_SPIRAL_RIGHT,
    /* 1 */ TILED_SPIRAL_DOWN,
    /* 2 */ TILED_SPIRAL_LEFT,
    /* 3 */ TILED_SPIRAL_UP,
} SpiralTileDirection;

#define SPIRAL_TILE_SET_COUNT(info) ((info)->work0)
#define SPIRAL_TILE_COLUMN(info) ((info)->work1)
#define SPIRAL_TILE_ROW(info) ((info)->work2)
#define SPIRAL_TILE_DIRECTION(info) ((info)->work3)

typedef enum TransitionFadeState {
    /* 1 */ FADE_OUT_START = 1,
    /* 2 */ FADE_WAIT,
    /* 3 */ FADE_IN_START,
    /* 4 */ FADE_FINISHED,
} TransitionFadeState;

#define FADE_TIMER_ARG(transition) ((transition)->argument)
#define FADE_RED(info) ((info)->work0)
#define FADE_GREEN(info) ((info)->work1)
#define FADE_BLUE(info) ((info)->work2)
#define FADE_ALPHA(info) ((info)->work3)
#define FADE_TIMER(info) ((info)->work4)

typedef enum TransitionWipeState {
    /* 1 */ WIPE_START = 1,
    /* 2 */ WIPE_FINISHED,
} TransitionWipeState;

typedef enum WipeDirection {
    /* 0 */ WIPE_DIRECTION_LEFT,
    /* 1 */ WIPE_DIRECTION_RIGHT,
    /* 2 */ WIPE_DIRECTION_UP,
    /* 3 */ WIPE_DIRECTION_DOWN,
} WipeDirection;

#define WIPE_DIRECTION_ARG(transition) ((transition)->argument)
#define WIPE_LEFT(info) ((info)->work0)
#define WIPE_TOP(info) ((info)->work1)

typedef enum TransitionPhasedStripsState {
    /* 1 */ PHASED_STRIPS_START = 1,
    /* 2 */ PHASED_STRIPS_WAIT,
    /* 3 */ PHASED_STRIPS_FINISHED,
} TransitionPhasedStripsState;

#define PHASED_STRIP_HEIGHT 4

typedef enum TransitionGreyscaleState {
    /* 1 */ GREYSCALE_PALETTE_START = 1,
    /* 2 */ GREYSCALE_PALETTE_WAIT,
    /* 3 */ GREYSCALE_PALETTE_FINISHED,
} TransitionGreyscaleState;

#define GREYSCALE_PALETTE_INDEX(info) ((info)->work0)

bool Transition_Queue(s32 appearType, s32 transitionType);
bool Transition_QueueRandom(s32 appearType, bool instantTransitionAllowed);
s32 Transition_Update(void);
void Transition_PopQueue(Transition* transition);
void Transition_SmallTilesInit(Transition* transition);
void Transition_SmallTilesUpdate(Transition* transition);
bool Transition_SmallTilesUpdateState(Transition* transition);
s32 Transition_SmallTilesFindUnsetSurroundingTiles(Transition* transition, s32 tileIndex, bool* surroundingTileUnset);
s32 Transition_SmallTilesGetTileState(Transition* transition, s32 tileIndex);
void Transition_SmallTilesSetTileState(Transition* transition, s32 tileIndex, s8 tileState);
Gfx* Transition_SmallTilesDraw(Gfx* gfx, Transition* transition);
void Transition_LargeTilesInit(Transition* transition);
void Transition_LargeTilesUpdate(Transition* transition);
bool Transition_LargeTilesUpdateState(Transition* transition);
Gfx* Transition_LargeTilesDraw(Gfx* gfx, Transition* transition);
void Transition_TiledWhirlInit(Transition* transition);
void Transition_TiledWhirlUpdate(Transition* transition);
bool Transition_TiledWhirlUpdateState(Transition* transition);
Gfx* Transition_TiledDraw(Gfx* gfx, Transition* transition);
void Transition_TiledSpiralInit(Transition* transition);
void Transition_TiledSpiralUpdate(Transition* transition);
bool Transition_TiledSpiralUpdateState(Transition* transition);
void Transition_FadeInit(Transition* transition, s32 alpha, s32 fadeTime);
void Transition_FadeUpdate(Transition* transition);
Gfx* Transition_FadeDraw(Gfx* gfx, Transition* transition);
void Transition_WipeInit(Transition* transition);
void Transition_WipeUpdate(Transition* transition);
Gfx* Transition_WipeDraw(Gfx* gfx, Transition* transition);
void Transition_PhasedStripsInit(Transition* transition);
void Transition_PhasedStripsUpdate(Transition* transition);
bool Transition_PhasedStripsUpdateState(Transition* transition);
Gfx* Transition_PhasedStripsDraw(Gfx* gfx, Transition* transition);
void Transition_GreyscalePaletteInit(Transition* transition);
void Transition_GreyscalePaletteUpdate(Transition* transition);
bool Transition_GreyscalePaletteUpdateState(Transition* transition);
Gfx* Transition_GreyscalePaletteDraw(Gfx* gfx, Transition* transition);

#endif // TRANSITION_H
