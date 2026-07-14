#include "global.h"
#include "fzx_cache.h"
#include "transition.h"
#include "fzx_camera.h"
#include "fzx_game.h"
#include ASSET_HEADER(course_track_gfx.h)

s16 sWipePos;
u16 sTiledPerspectiveScale;
s16 sTransitionIntermediateFillBlack;
Transition sTransition;
s16 sTransitionTypeArgument;
s16 sTransitionTypeWithArgument;
u16* sTransitionPalettePtr;
u16 sTransitionPalette[32];

s16 D_i2_80106DA0 = true;
s32 gTransitionState = TRANSITION_INACTIVE;
s16 sSurroundingTilesRelativeIndex[] = {
    -SMALL_TILES_COLUMNS - 1, -SMALL_TILES_COLUMNS, -SMALL_TILES_COLUMNS + 1, -1, 1,
    SMALL_TILES_COLUMNS - 1,  SMALL_TILES_COLUMNS,  SMALL_TILES_COLUMNS + 1
};

UNUSED Gfx D_i2_80106DB8[] = {
    gsSPEndDisplayList(),
};

f32 sStripMoveSpeed = 3.25f;

s32 sSurroundingTileSkipChanceMask[] = { 7, 3, 3, 1, 1, 0, 0, 0 };

void Transition_Init(void) {
    Transition* transition = &sTransition;

    transition->activeTransitionType = transition->queuedTransitionType = 0;
    transition->state = 0;
    transition->timer = 0;
    transition->argument = 0;
    transition->flags = 0;
    transition->backgroundBuffer = NULL;
    transition->workBuffer = NULL;
    sTransitionTypeArgument = 0;
    sTransitionTypeWithArgument = 0;
    sWipePos = 0;
    sTransitionIntermediateFillBlack = 0;
}

extern s32 gNumPlayers;
extern s16 gGameModeChangeState;
extern s32 gGameMode;

void Transition_HideSet(void) {
    gTransitionState = TRANSITION_HIDING;

    if (gGameModeChangeState == GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START)) {
        Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_PHASED_STRIPS);
            break;
        case GAMEMODE_GP_END_CS:
            Transition_SetArgument(TRANSITION_TYPE_FADE, 120);
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_COURSE_EDIT:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
            break;
#ifdef EXPANSION_KIT
        case GAMEMODE_CREATE_MACHINE:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_STATIC_FADE);
            break;
#endif
        case GAMEMODE_FLX_COURSE_SELECT:
            Transition_SetArgument(TRANSITION_TYPE_FADE, 40);
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_FLX_MACHINE_SELECT:
#ifndef EXPANSION_KIT
            if (gNumPlayers == 1) {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
            } else {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            }
#else
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_STATIC_FADE);
#endif
            break;
        case GAMEMODE_FLX_MAIN_MENU:
            if (gGameModeChangeState == GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START)) {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
            } else {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_SMALL_TILES);
            }
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            if (gGameModeChangeState == GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START)) {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
            } else {
                Transition_QueueRandom(TRANSITION_HIDE, true);
            }
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_STATIC_FADE);
            break;
        case GAMEMODE_RECORDS:
            if (gGameModeChangeState != GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START)) {
                Transition_QueueRandom(TRANSITION_HIDE, true);
            } else {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
            }
            break;
        default:
            Transition_QueueRandom(TRANSITION_HIDE, true);
            break;
    }
}

extern s32 gQueuedGameMode;

void Transition_AppearSet(void) {
    gTransitionState = TRANSITION_APPEARING;

    if (gGameModeChangeState == GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_INIT)) {
        Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
        return;
    }

    switch (gQueuedGameMode) {
        case GAMEMODE_FLX_TITLE:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_SMALL_TILES);
            break;
        case GAMEMODE_GP_END_CS:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
#ifndef EXPANSION_KIT
        case GAMEMODE_FLX_MACHINE_SELECT:
#endif
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_FADE);
            break;
#ifdef EXPANSION_KIT
        case GAMEMODE_FLX_MACHINE_SELECT:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_STATIC_FADE);
            break;
#endif
        case GAMEMODE_COURSE_EDIT:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
            break;
#ifdef EXPANSION_KIT
        case GAMEMODE_CREATE_MACHINE:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_STATIC_FADE);
            break;
#endif
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            if (gGameModeChangeState == GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_INIT)) {
                Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_UP);
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_WIPE);
            } else {
                Transition_QueueRandom(TRANSITION_APPEAR, true);
            }
            break;
        case GAMEMODE_FLX_MAIN_MENU:
            if (gGameModeChangeState == GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_INIT)) {
                Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_DOWN);
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_WIPE);
            } else {
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_PHASED_STRIPS);
            }
            break;
        case GAMEMODE_RECORDS:
            if (gGameModeChangeState != GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_INIT)) {
                Transition_QueueRandom(TRANSITION_APPEAR, true);
            } else {
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_WIPE);
            }
            break;
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
            Transition_SetArgument(TRANSITION_TYPE_FADE, 60);
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_FADE);
            break;
        default:
            Transition_QueueRandom(TRANSITION_APPEAR, true);
            break;
    }
}

extern u32 gGameFrameCount;

bool Transition_Queue(s32 appearType, s32 transitionType) {
    size_t backgroundBufferSize;
    size_t workBufferSize;
    Transition* transition = &sTransition;

    transition->queuedTransitionType = transitionType;
    transition->appearType = appearType;
    if (transition->queuedTransitionType != sTransitionTypeWithArgument) {
        transition->argument = 0;
    } else {
        transition->argument = sTransitionTypeArgument;
        sTransitionTypeWithArgument = TRANSITION_TYPE_NONE;
        sTransitionTypeArgument = 0;
    }
    sTransitionPalettePtr = NULL;

    switch (transitionType) {
        case TRANSITION_TYPE_SMALL_TILES:
            backgroundBufferSize = 0;
            workBufferSize = SMALL_TILES_WORK_SIZE;
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = LARGE_TILES_COUNT * sizeof(LargeTile);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = TILED_COUNT * sizeof(WhirlTile);
            transition->argument = gGameFrameCount % 2;
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = TILED_COUNT * sizeof(SpiralTile);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            backgroundBufferSize = 0;
            workBufferSize = 0;
            break;
        case TRANSITION_TYPE_WIPE:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0;
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = TRANSITION_BACKGROUND_HEIGHT * sizeof(f32);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            if (appearType != TRANSITION_HIDE) {
                if (sTransitionIntermediateFillBlack) {
                    transition->queuedTransitionType = TRANSITION_TYPE_STATIC_FADE;
                    backgroundBufferSize = 0;
                    workBufferSize = 0;
                    break;
                }
            }
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0xC0;
            break;
        default:
            backgroundBufferSize = 0;
            workBufferSize = 0;
            break;
    }

    if (((transition->backgroundBuffer = Arena_Allocate(ALLOC_BACK, backgroundBufferSize)) == NULL) ||
        ((transition->workBuffer = Arena_Allocate(ALLOC_BACK, workBufferSize)) == NULL)) {
        transition->queuedTransitionType = TRANSITION_TYPE_FADE;
        return true;
    }
    if (transition->queuedTransitionType == TRANSITION_TYPE_GREYSCALE_PALETTE) {
        sTransitionPalettePtr = sTransitionPalette;
    }
    return false;
}

void Transition_SetArgument(s32 transitionType, s32 argument) {
    sTransitionTypeWithArgument = transitionType;
    sTransitionTypeArgument = argument;
}

const s32 kTransitionRandomSelection[] = { TRANSITION_TYPE_SMALL_TILES,  TRANSITION_TYPE_LARGE_TILES,
                                           TRANSITION_TYPE_TILED_WHIRL,  TRANSITION_TYPE_TILED_SPIRAL,
                                           TRANSITION_TYPE_FADE,         TRANSITION_TYPE_STATIC_FADE,
                                           TRANSITION_TYPE_PHASED_STRIPS };

bool Transition_QueueRandom(s32 appearType, bool instantTransitionAllowed) {
    s32 instantTransitionChance;
    u32 randomTransition;
    bool allocFailed;

    if (appearType == TRANSITION_HIDE) {
        instantTransitionChance = Math_Rand1() % 8;
        if (instantTransitionAllowed) {
            if (instantTransitionChance < 2) {
                randomTransition = Math_Rand1();
                allocFailed = Transition_Queue(appearType, kTransitionRandomSelection[randomTransition % 7]);
            } else {
                allocFailed = Transition_Queue(appearType, TRANSITION_TYPE_INSTANT);
            }
        } else {
            randomTransition = Math_Rand1();
            allocFailed = Transition_Queue(appearType, kTransitionRandomSelection[randomTransition % 7]);
        }
    } else {
        randomTransition = Math_Rand1();
        allocFailed = Transition_Queue(appearType, kTransitionRandomSelection[randomTransition % 7]);
    }
    return allocFailed;
}

s32 Transition_Update(void) {
    Transition* transition = &sTransition;

    if (transition->queuedTransitionType != TRANSITION_TYPE_NONE) {
        Transition_PopQueue(transition);
    }

    switch (transition->activeTransitionType) {
        case TRANSITION_TYPE_NONE:
            break;
        case TRANSITION_TYPE_SMALL_TILES:
            Transition_SmallTilesUpdate(transition);
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            Transition_LargeTilesUpdate(transition);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            Transition_TiledWhirlUpdate(transition);
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            Transition_TiledSpiralUpdate(transition);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            Transition_FadeUpdate(transition);
            break;
        case TRANSITION_TYPE_WIPE:
            Transition_WipeUpdate(transition);
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            Transition_PhasedStripsUpdate(transition);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            Transition_GreyscalePaletteUpdate(transition);
            break;
        case TRANSITION_TYPE_INSTANT:
        default:
            break;
    }

    if (gTransitionState != TRANSITION_INACTIVE && transition->flags & TRANSITION_FLAG_FINISHED) {
        gTransitionState = TRANSITION_INACTIVE;
    }

    return transition->flags & TRANSITION_FLAG_FINISHED;
}

void Transition_PopQueue(Transition* transition) {

    transition->activeTransitionType = transition->queuedTransitionType;
    transition->queuedTransitionType = TRANSITION_TYPE_NONE;
    transition->timer = 0;
    transition->flags = TRANSITION_FLAG_DRAW;

    switch (transition->activeTransitionType) {
        case TRANSITION_TYPE_INSTANT:
            transition->flags &= ~TRANSITION_FLAG_DRAW;
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
        case TRANSITION_TYPE_SMALL_TILES:
            if (transition->appearType != TRANSITION_HIDE) {
                transition->state = SMALL_TILES_START_APPEAR;
            } else {
                transition->state = SMALL_TILES_START_HIDE;
            }
            Transition_SmallTilesInit(transition);
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            if (transition->appearType == TRANSITION_HIDE) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = LARGE_TILES_START;
            Transition_LargeTilesInit(transition);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            if (transition->appearType == TRANSITION_HIDE) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = TILED_WHIRL_START;
            Transition_TiledWhirlInit(transition);
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            if (transition->appearType == TRANSITION_HIDE) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = TILED_SPIRAL_START;
            Transition_TiledSpiralInit(transition);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            if (transition->appearType != TRANSITION_HIDE) {
                transition->state = FADE_IN_START;
                Transition_FadeInit(transition, 255, 20);
            } else {
                transition->state = FADE_OUT_START;
                Transition_FadeInit(transition, 0, 20);
            }
            break;
        case TRANSITION_TYPE_WIPE:
            if (transition->appearType == TRANSITION_HIDE) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = WIPE_START;
            Transition_WipeInit(transition);
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            if (transition->appearType == TRANSITION_HIDE) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = PHASED_STRIPS_START;
            Transition_PhasedStripsInit(transition);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            if (transition->appearType == TRANSITION_HIDE) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = GREYSCALE_PALETTE_START;
            Transition_GreyscalePaletteInit(transition);
            break;
    }

    if (transition->appearType == TRANSITION_HIDE) {
        if (transition->flags & TRANSITION_FLAG_FILL_BLACK) {
            sTransitionIntermediateFillBlack = true;
        } else {
            sTransitionIntermediateFillBlack = false;
        }
    }
}

Gfx* Transition_Draw(Gfx* gfx) {
    Transition* transition = &sTransition;

    if (!(transition->flags & TRANSITION_FLAG_DRAW)) {
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    gfx = func_8006A00C(gfx, SCISSOR_BOX_FULL_SCREEN);

    if (transition->flags & TRANSITION_FLAG_FILL_BLACK) {
        gSPDisplayList(gfx++, aSetupFillBlackDL);
        gDPFillRectangle(gfx++, TRANSITION_BORDER_WIDTH, TRANSITION_BORDER_HEIGHT,
                         SCREEN_WIDTH - TRANSITION_BORDER_WIDTH - 1, SCREEN_HEIGHT - TRANSITION_BORDER_HEIGHT - 1);
    }
    switch (transition->activeTransitionType) {
        case TRANSITION_TYPE_SMALL_TILES:
            gfx = Transition_SmallTilesDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            gfx = Transition_LargeTilesDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            gfx = Transition_TiledDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            gfx = Transition_TiledDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            gfx = Transition_FadeDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_WIPE:
            gfx = Transition_WipeDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            gfx = Transition_PhasedStripsDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            gfx = Transition_GreyscalePaletteDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_INSTANT:
            break;
    }
    if (transition->flags & TRANSITION_FLAG_FINISHED) {
        transition->activeTransitionType = TRANSITION_TYPE_NONE;
        transition->state = TRANSITION_STATE_INACTIVE;
        transition->flags &= ~TRANSITION_FLAG_DRAW;
        // Clear background arena
        Arena_EndInit();
    }
    return gfx;
}

extern FrameBuffer* gFrameBuffers[];
extern s16 D_800CCFE4;
extern s32 D_800DCD08;
extern s32 D_800DCD00;

void Transition_SetBackgroundBuffer(void) {
    s32 pad;
    s32 column;
    s32 row;
    s32 var_v0;
    u16* frameBufferPtr;
    u16* backgroundBufferPtr;
    Transition* transition = &sTransition;

    if (!(transition->flags & TRANSITION_FLAG_SET_BACKGROUND_BUFFER)) {
        return;
    }

    transition->flags &= ~TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    backgroundBufferPtr = transition->backgroundBuffer;
    if (D_800CCFE4 == 3) {
        var_v0 = D_800DCD08;
    } else {
        var_v0 = D_800DCD00;
    }

    osInvalDCache(gFrameBuffers[var_v0], SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u16));

    for (row = 0; row < TRANSITION_BACKGROUND_HEIGHT; row++) {
        frameBufferPtr = &gFrameBuffers[var_v0]->array[row + TRANSITION_BORDER_HEIGHT][TRANSITION_BORDER_WIDTH];

        for (column = 0; column < TRANSITION_BACKGROUND_WIDTH; column++, backgroundBufferPtr++, frameBufferPtr++) {
            *backgroundBufferPtr = *frameBufferPtr;
        }
    }

    if (transition->flags & TRANSITION_FLAG_GREYSCALE) {
        TextureUtils_ConvertToGreyscale(transition->backgroundBuffer,
                                        TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16));
    }
    if (transition->flags & TRANSITION_FLAG_INVERSE_GREYSCALE) {
        Graphics_ConvertToInverseGreyscale(transition->backgroundBuffer,
                                           TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16));
    }
    if (transition->flags & TRANSITION_FLAG_CONVERT_TO_PALETTE) {
        //! @bug passes in size of texture instead of pixel count, causing overflow read
        TextureUtils_GeneratePalette(transition->backgroundBuffer, sTransitionPalettePtr,
                                     TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16));
    }
}

void Transition_SmallTilesInit(Transition* transition) {
    s32 i;
    u8* tileStateBufferPtr = transition->workBuffer;
    s32 tileColumn;
    s32 tileRow;

    for (i = 0; i < SMALL_TILES_WORK_SIZE; i++) {
        *tileStateBufferPtr++ = SMALL_TILES_TILE_UNSET;
    }

    for (i = 0; i < 5; i++) {
        tileColumn = Math_Rand1() % SMALL_TILES_COLUMNS;
        tileRow = Math_Rand1() % SMALL_TILES_ROWS;
        Transition_SmallTilesSetTileState(transition, (tileRow * SMALL_TILES_COLUMNS) + tileColumn,
                                          SMALL_TILES_TILE_SET);
    }
}

void Transition_SmallTilesUpdate(Transition* transition) {

    switch (transition->state) {
        case SMALL_TILES_START_HIDE:
            if (Transition_SmallTilesUpdateState(transition)) {
                transition->state = SMALL_TILES_WAIT;
                transition->timer = 0;
            }
            break;
        case SMALL_TILES_WAIT:
            transition->timer++;
            if (transition->timer >= 3) {
                transition->state = SMALL_TILES_FINISHED;
            }
            break;
        case SMALL_TILES_START_APPEAR:
            if (Transition_SmallTilesUpdateState(transition)) {
                transition->state = SMALL_TILES_FINISHED;
            }
            break;
        case SMALL_TILES_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
        case TRANSITION_STATE_INACTIVE:
        default:
            break;
    }
}

bool Transition_SmallTilesUpdateState(Transition* transition) {
    s32 surroundingTilesUnset;
    bool transitionComplete;
    s32 tileIndexToSet;
    s8* tileStateBufferPtr;
    u32 surroundingTilesIndex;
    s32 i;
    s32 pad[6];
    bool surroundingTileUnset[8];

    for (i = 0; i < SMALL_TILES_COLUMNS * SMALL_TILES_ROWS; i++) {
        if (Transition_SmallTilesGetTileState(transition, i) == SMALL_TILES_TILE_SET) {
            surroundingTilesUnset = Transition_SmallTilesFindUnsetSurroundingTiles(transition, i, surroundingTileUnset);
            if (surroundingTilesUnset == 0) {
                Transition_SmallTilesSetTileState(transition, i, SMALL_TILES_TILE_FINISHED);
                continue;
            }

            if ((Math_Rand1() & sSurroundingTileSkipChanceMask[surroundingTilesUnset - 1])) {
                continue;
            }

            surroundingTilesIndex = Math_Rand1() % 8;

            while (!surroundingTileUnset[surroundingTilesIndex]) {
                surroundingTilesIndex++;
                surroundingTilesIndex %= 8;
            }

            tileIndexToSet = (sSurroundingTilesRelativeIndex[surroundingTilesIndex] % SMALL_TILES_WORK_SIZE) + i;
            if (tileIndexToSet < 0) {
                tileIndexToSet += SMALL_TILES_WORK_SIZE;
            }
            Transition_SmallTilesSetTileState(transition, tileIndexToSet, SMALL_TILES_TILE_SET);
        }
    }

    if (++transition->timer <= 60) {
        transitionComplete = true;

        for (i = 0, tileStateBufferPtr = transition->workBuffer; i < SMALL_TILES_WORK_SIZE; i++, tileStateBufferPtr++) {
            if (!(*tileStateBufferPtr & 0xF0) || !(*tileStateBufferPtr & 0xF)) {
                transitionComplete = false;
                break;
            }
        }

    } else {
        transitionComplete = true;
        // clang-format off
        for (i = 0, tileStateBufferPtr = transition->workBuffer; i < SMALL_TILES_WORK_SIZE; i++) { \
            *tileStateBufferPtr++ = (SMALL_TILES_TILE_FINISHED << 4) | SMALL_TILES_TILE_FINISHED;
        }
        // clang-format on
    }
    return transitionComplete;
}

s32 Transition_SmallTilesFindUnsetSurroundingTiles(Transition* transition, s32 tileIndex, bool* surroundingTileUnset) {
    s32 tileToCheck;
    s32 i;
    s32 unsetTilesFound = 0;

    for (i = 0; i < ARRAY_COUNT(sSurroundingTilesRelativeIndex); i++) {
        tileToCheck = (sSurroundingTilesRelativeIndex[i] % SMALL_TILES_WORK_SIZE) + tileIndex;
        if (tileToCheck < 0) {
            tileToCheck += SMALL_TILES_WORK_SIZE;
        }
        if (Transition_SmallTilesGetTileState(transition, tileToCheck) == 0) {
            unsetTilesFound++;
            surroundingTileUnset[i] = true;
        } else {
            surroundingTileUnset[i] = false;
        }
    }
    return unsetTilesFound;
}

s32 Transition_SmallTilesGetTileState(Transition* transition, s32 tileIndex) {
    s8* workByte = (s8*) transition->workBuffer + (tileIndex >> 1);
    s8 tileState;

    if (tileIndex & 1) {
        tileState = (*workByte & 0xF);
    } else {
        tileState = (*workByte >> 4);
    }
    return tileState;
}

void Transition_SmallTilesSetTileState(Transition* transition, s32 tileIndex, s8 tileState) {
    s8* workByte = (s8*) transition->workBuffer + (tileIndex >> 1);

    if (tileIndex & 1) {
        *workByte = (*workByte & 0xF0) | tileState;
    } else {
        *workByte = (*workByte & 0xF) | (tileState << 4);
    }
}

Gfx* Transition_SmallTilesDraw(Gfx* gfx, Transition* transition) {
    s32 tileTop;
    s32 groupedHiddenTileCount;
    s32 column;
    s32 tileIndex;
    s32 hiddenTileColumnStart;
    s32 row;
    s32 tileLeft;

    gSPDisplayList(gfx++, aSetupFillBlackDL);
    tileIndex = 0;

    for (row = 0; row < SMALL_TILES_ROWS; row++) {
        groupedHiddenTileCount = 0;
        for (column = 0; column < SMALL_TILES_COLUMNS; column++, tileIndex++) {
            if (transition->appearType != TRANSITION_HIDE) {
                if (Transition_SmallTilesGetTileState(transition, tileIndex) != SMALL_TILES_TILE_UNSET) {
                    tileLeft = hiddenTileColumnStart * SMALL_TILES_WIDTH;
                    tileTop = (row * SMALL_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT;
                    if (groupedHiddenTileCount == 0) {
                        continue;
                    }
                } else {
                    if (groupedHiddenTileCount == 0) {
                        hiddenTileColumnStart = column;
                    }
                    groupedHiddenTileCount++;
                    continue;
                }
            } else {
                if (Transition_SmallTilesGetTileState(transition, tileIndex) == SMALL_TILES_TILE_UNSET) {
                    tileLeft = hiddenTileColumnStart * SMALL_TILES_WIDTH;
                    tileTop = (row * SMALL_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT;
                    if (groupedHiddenTileCount == 0) {
                        continue;
                    }
                } else {
                    if (groupedHiddenTileCount == 0) {
                        hiddenTileColumnStart = column;
                    }
                    groupedHiddenTileCount++;
                    continue;
                }
            }

            gDPFillRectangle(gfx++, tileLeft + TRANSITION_BORDER_WIDTH, tileTop,
                             ((groupedHiddenTileCount * SMALL_TILES_WIDTH) + tileLeft + TRANSITION_BORDER_WIDTH - 1),
                             (tileTop + SMALL_TILES_HEIGHT - 1));
            groupedHiddenTileCount = 0;
        }

        tileLeft = hiddenTileColumnStart * SMALL_TILES_WIDTH;
        tileTop = (row * SMALL_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT;
        if (groupedHiddenTileCount != 0) {
            gDPFillRectangle(gfx++, tileLeft + TRANSITION_BORDER_WIDTH, tileTop,
                             ((groupedHiddenTileCount * SMALL_TILES_WIDTH) + tileLeft + TRANSITION_BORDER_WIDTH - 1),
                             (tileTop + SMALL_TILES_HEIGHT - 1));
            groupedHiddenTileCount = 0;
        }
    }
    return gfx;
}

void Transition_LargeTilesInit(Transition* transition) {
    s32 i;
    LargeTile* tile;
    TransitionInfo* tilesInfo = &transition->transitionInfo;

    LARGE_TILES_REMAINING(tilesInfo) = LARGE_TILES_COUNT;
    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;

    for (i = 0, tile = transition->workBuffer; i < LARGE_TILES_COUNT; i++, tile++) {
        tile->state = LARGE_TILES_TILE_UNSET;
        tile->alpha = 0xFF;
    }
}

void Transition_LargeTilesUpdate(Transition* transition) {
    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case LARGE_TILES_START:
            if (Transition_LargeTilesUpdateState(transition)) {
                transition->state = LARGE_TILES_FINISHED;
            }
            break;
        case LARGE_TILES_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

bool Transition_LargeTilesUpdateState(Transition* transition) {
    bool finishedAllTiles;
    s32 i;
    s32 alpha;
    s32 tileIndexToSet;
    TransitionInfo* tilesInfo;
    LargeTile* tile;

    tile = transition->workBuffer;
    tilesInfo = &transition->transitionInfo;
    transition->timer++;
    if (transition->timer > 0) {
        transition->timer = 0;
        for (i = 0; i < 2; i++) {
            if (LARGE_TILES_REMAINING(tilesInfo) > 0) {
                tileIndexToSet = Math_Rand1() % LARGE_TILES_COUNT;
                while ((tile + tileIndexToSet)->state != LARGE_TILES_TILE_UNSET) {
                    tileIndexToSet++;
                    tileIndexToSet %= LARGE_TILES_COUNT;
                }

                (tile + tileIndexToSet)->state = LARGE_TILES_TILE_SET;
                LARGE_TILES_REMAINING(tilesInfo)--;
            }
        }
    }

    tile = transition->workBuffer;
    finishedAllTiles = true;

    for (i = 0; i < LARGE_TILES_COUNT; i++, tile++) {
        if (tile->state != LARGE_TILES_TILE_FINISHED) {
            finishedAllTiles = false;
        }
        if (tile->state == LARGE_TILES_TILE_SET) {
            alpha = tile->alpha - 8;
            if (alpha < 0) {
                tile->state = LARGE_TILES_TILE_FINISHED;
                alpha = 0;
            }
            tile->alpha = alpha;
        }
    }

    return finishedAllTiles;
}

Gfx* Transition_LargeTilesDraw(Gfx* gfx, Transition* transition) {
    s32 row;
    s32 column;
    LargeTile* tile;

    gSPDisplayList(gfx++, D_80147B0);

    for (row = 0; row < LARGE_TILES_ROWS; row++) {
        for (column = 0; column < LARGE_TILES_COLUMNS; column++) {
            tile = (LargeTile*) transition->workBuffer + (row * LARGE_TILES_COLUMNS + column);
            if (tile->state == LARGE_TILES_TILE_FINISHED) {
                continue;
            }
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, tile->alpha);

            gDPLoadTextureTile(gfx++, transition->backgroundBuffer, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                               TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, (column * LARGE_TILES_WIDTH),
                               (row * LARGE_TILES_HEIGHT), ((column + 1) * LARGE_TILES_WIDTH) - 1,
                               ((row + 1) * LARGE_TILES_HEIGHT) - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gfx++, ((column * LARGE_TILES_WIDTH) + TRANSITION_BORDER_WIDTH) << 2,
                                ((row * LARGE_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT) << 2,
                                (((column + 1) * LARGE_TILES_WIDTH) + TRANSITION_BORDER_WIDTH) << 2,
                                (((row + 1) * LARGE_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT) << 2, 0,
                                (column * LARGE_TILES_WIDTH) << 5, (row * LARGE_TILES_HEIGHT) << 5, 1 << 10, 1 << 10);
        }
    }
    return gfx;
}

extern GfxPool D_8024DCE0[2];

void Transition_TiledWhirlInit(Transition* transition) {
    s32 pad[11];
    f32 sp104[4];
    f32 spF4[4];
    f32 spE4[4];
    f32 spD4[4];
    s32 pad2[4];
    s32 i;
    s32 row;
    s32 column;
    s32 vtxCorner;
    Vtx* vtx;
    s32 s;
    s32 t;
    s32 x;
    s32 y;
    s32 var_a1;
    WhirlTile* whirlTile;
    TransitionInfo* tiledWhirlInfo = &transition->transitionInfo;

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    tiledWhirlInfo->work0 = -1;

    for (i = 0; i < 2; i++) {
        vtx = D_8024DCE0[i].backgroundTileVtxBuffer;
        sp104[0] = sp104[2] = -33.3f;
        sp104[1] = sp104[3] = sp104[0] + 66.6f + 1.0f;
        spF4[0] = spF4[1] = 25.199999f;
        spF4[2] = spF4[3] = spF4[0] - 50.399998f;

        for (row = 0; row < TILED_ROWS; row++) {
            for (column = 0; column < TILED_COLUMNS; column++) {
                for (vtxCorner = 0; vtxCorner < 4; vtxCorner++) {
                    if (vtxCorner & 1) {
                        spE4[vtxCorner] = (column + 1) * TILED_WIDTH;
                    } else {
                        spE4[vtxCorner] = column * TILED_WIDTH;
                    }
                    if (vtxCorner >= 2) {
                        spD4[vtxCorner] = (row + 1) * TILED_HEIGHT;
                    } else {
                        spD4[vtxCorner] = row * TILED_HEIGHT;
                    }
                    x = Math_Round(sp104[vtxCorner]);
                    y = Math_Round(spF4[vtxCorner]);
                    s = spE4[vtxCorner] * 32.0f;
                    t = spD4[vtxCorner] * 32.0f;
                    SET_VTX(vtx, x, y, 0, s, t, 0, 0, 0, 0);
                    vtx++;
                }
            }
        }
    }

    for (row = 0; row < TILED_ROWS; row++) {
        for (column = 0; column < TILED_COLUMNS; column++) {
            whirlTile = (WhirlTile*) transition->workBuffer + (column + row * TILED_COLUMNS);
            whirlTile->state = WHIRL_TILES_TILE_UNSET;
            whirlTile->pos.x = (column * 66.6f) + -233.09999f;
            whirlTile->pos.y = 176.4f - (row * 50.399998f);
            whirlTile->pos.z = 0.0f;
            whirlTile->velocity.x = 0.0f;
            whirlTile->velocity.y = 0.0f;
            whirlTile->velocity.z = 0.0f;
        }
    }
}

extern GfxPool* gGfxPool;

void Transition_TiledWhirlUpdate(Transition* transition) {
    s32 i;
    s32 temp_v0;
    bool isDrawing;
    WhirlTile* whirlTile;
    MtxF mtxF;

    isDrawing = false;

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case TILED_WHIRL_START:
            isDrawing = true;
            if (Transition_TiledWhirlUpdateState(transition) != 0) {
                transition->state = TILED_WHIRL_WAIT;
                transition->timer = 0;
            }
            break;
        case TILED_WHIRL_WAIT:
            isDrawing = true;
            transition->timer++;
            if (transition->timer >= 3) {
                transition->state = TILED_WHIRL_FINISHED;
                transition->timer = 0;
            }
            break;
        case TILED_WHIRL_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
    if (isDrawing) {
        Matrix_SetFrustrum(gGfxPool->unk_2B248, &mtxF, 60.0f, 16.0f, 8129.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, 0.0f,
                           &sTiledPerspectiveScale);
        Matrix_SetLookAt(gGfxPool->unk_2B288, &mtxF, 0.0f, 0.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        whirlTile = transition->workBuffer;
        for (i = 0; i < TILED_COUNT; i++) {
            Matrix_SetLockedLookAt(&gGfxPool->unk_2B2C8[i], &mtxF, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                                   whirlTile->pos.x, whirlTile->pos.y, whirlTile->pos.z);
            whirlTile++;
        }
    }
}

bool Transition_TiledWhirlUpdateState(Transition* transition) {
    bool whirlFinished;
    s32 j;
    s32 i;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_4;
    TransitionInfo* tiledWhirlInfo = &transition->transitionInfo;
    WhirlTile* whirlTile;

    transition->timer++;
    if (transition->timer >= 2) {
        transition->timer = 0;
        var_v1 = 0;

        if (tiledWhirlInfo->work0 < 0xF) {
            tiledWhirlInfo->work0++;
        }

        if (WHIRL_CORNER_ARG(transition) != 0) {
            for (i = tiledWhirlInfo->work0; i >= 0; i--, var_v1++) {
                if (i >= TILED_COLUMNS) {
                    continue;
                }

                for (j = 0; j < var_v1 + 1; j++) {
                    var_v1_2 = (TILED_ROWS - 1) - j;
                    if (var_v1_2 >= 0) {
                        whirlTile = (WhirlTile*) transition->workBuffer + ((var_v1_2 * TILED_COLUMNS) + i);
                        if (whirlTile->state == WHIRL_TILES_TILE_UNSET) {
                            whirlTile->state = WHIRL_TILES_TILE_SET;
                        }
                    }
                }
            }
        } else {
            var_v1_4 = 0;
            for (i = (TILED_COLUMNS - 1) - tiledWhirlInfo->work0; i < TILED_COLUMNS; i++, var_v1_4++) {
                if (i < 0) {
                    continue;
                }

                for (j = 0; j < var_v1_4 + 1; j++) {
                    if (j < TILED_ROWS) {
                        whirlTile = (WhirlTile*) transition->workBuffer + ((j * TILED_COLUMNS) + i);
                        if (whirlTile->state == WHIRL_TILES_TILE_UNSET) {
                            whirlTile->state = WHIRL_TILES_TILE_SET;
                        }
                    }
                }
            }
        }
    }

    for (i = 0, whirlTile = transition->workBuffer; i < TILED_COUNT; i++, whirlTile++) {
        if (whirlTile->state == WHIRL_TILES_TILE_SET) {
            whirlTile->velocity.x += 0.0f;
            whirlTile->velocity.y += 0.0f;
            whirlTile->velocity.z += -60.0f;
            whirlTile->pos.x += whirlTile->velocity.x;
            whirlTile->pos.y += whirlTile->velocity.y;
            whirlTile->pos.z += whirlTile->velocity.z;
            if (whirlTile->pos.z < -10000.0f) {
                whirlTile->state = WHIRL_TILES_TILE_FINISHED;
                whirlTile->pos.z = -10000.0f;
            }
        }
    }

    whirlFinished = true;
    for (i = 0, whirlTile = transition->workBuffer; i < TILED_COUNT; i++, whirlTile++) {
        if (whirlTile->state != WHIRL_TILES_TILE_FINISHED) {
            whirlFinished = false;
        }
    }
    return whirlFinished;
}

extern GfxPool D_1000000;

Gfx* Transition_TiledDraw(Gfx* gfx, Transition* transition) {
    s32 pad[2];
    s32 row;
    s32 column;
    f32 alphaScale;
    WhirlTile* whirlTile;
    s32 tileIndex;

    gSPDisplayList(gfx++, D_8014810);

    if (transition->activeTransitionType == TRANSITION_TYPE_TILED_WHIRL) {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        whirlTile = transition->workBuffer;
    }
    gSPPerspNormalize(gfx++, sTiledPerspectiveScale);
    gSPMatrix(gfx++, D_1000000.unk_2B248, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_1000000.unk_2B288, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    for (row = 0; row < TILED_ROWS; row++) {
        for (column = 0; column < TILED_COLUMNS; column++) {
            tileIndex = (row * TILED_COLUMNS) + column;
            if (transition->activeTransitionType == TRANSITION_TYPE_TILED_WHIRL) {
                alphaScale = 1.0f - (whirlTile + tileIndex)->pos.z / -10000.0f;
                if (alphaScale < 0.0f) {
                    alphaScale = 0.0f;
                }
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (s32) (255.0f * alphaScale));
            }

            gSPMatrix(gfx++, &D_1000000.unk_2B2C8[tileIndex], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(gfx++, &D_1000000.backgroundTileVtxBuffer[tileIndex * 4], 4, 0);

            gDPLoadTextureTile(gfx++, transition->backgroundBuffer, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                               TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, (column * TILED_WIDTH),
                               (row * TILED_HEIGHT), ((column + 1) * TILED_WIDTH) - 1, ((row + 1) * TILED_HEIGHT) - 1,
                               0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);

            gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
        }
    }
    return gfx;
}

void Transition_TiledSpiralInit(Transition* transition) {
    s32 i;
    s32 row;
    s32 column;
    s32 vtxCorner;
    Vtx* vtx;
    s32 s;
    s32 t;
    s32 x;
    s32 y;
    SpiralTile* spiralTile;
    TransitionInfo* tiledSpiralInfo = &transition->transitionInfo;
    f32 spC4[4];
    f32 spB4[4];
    f32 spA4[4];
    f32 sp94[4];

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    SPIRAL_TILE_SET_COUNT(tiledSpiralInfo) = TILED_COUNT;
    SPIRAL_TILE_COLUMN(tiledSpiralInfo) = -1;
    SPIRAL_TILE_ROW(tiledSpiralInfo) = 0;
    SPIRAL_TILE_DIRECTION(tiledSpiralInfo) = 0;

    for (i = 0; i < 2; i++) {
        vtx = D_8024DCE0[i].backgroundTileVtxBuffer;
        spC4[0] = spC4[2] = -33.3f;
        spC4[1] = spC4[3] = spC4[0] + 66.6f + 1;
        spB4[0] = spB4[1] = 25.199999f;
        spB4[2] = spB4[3] = spB4[0] - 50.399998f;

        for (row = 0; row < TILED_ROWS; row++) {
            for (column = 0; column < TILED_COLUMNS; column++) {
                for (vtxCorner = 0; vtxCorner < 4; vtxCorner++) {
                    x = Math_Round(spC4[vtxCorner]);
                    y = Math_Round(spB4[vtxCorner]);
                    if (vtxCorner & 1) {
                        spA4[vtxCorner] = (column + 1) * TILED_WIDTH;
                    } else {
                        spA4[vtxCorner] = column * TILED_WIDTH;
                    }
                    if (vtxCorner >= 2) {
                        sp94[vtxCorner] = (row + 1) * TILED_HEIGHT;
                    } else {
                        sp94[vtxCorner] = row * TILED_HEIGHT;
                    }
                    s = spA4[vtxCorner] * 32.0f;
                    t = sp94[vtxCorner] * 32.0f;
                    SET_VTX(vtx, x, y, 0, s, t, 0, 0, 0, 0);
                    vtx++;
                }
            }
        }
    }

    for (row = 0; row < TILED_ROWS; row++) {
        for (column = 0; column < TILED_COLUMNS; column++) {
            spiralTile = (SpiralTile*) transition->workBuffer + (column + row * TILED_COLUMNS);
            spiralTile->state = SPIRAL_TILES_TILE_UNSET;
            spiralTile->pos.x = (column * 66.6f) + -233.09999f;
            spiralTile->pos.y = 176.4f - (row * 50.399998f);
            spiralTile->pos.z = 0.0f;
            spiralTile->scale = 1.0f;
            spiralTile->scaleTimer = 0;
        }
    }
}

void Transition_TiledSpiralUpdate(Transition* transition) {
    s32 i;
    bool isDrawing;
    SpiralTile* spiralTile;
    MtxF mtxF;

    isDrawing = false;
    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case TILED_SPIRAL_START:
            isDrawing = true;
            if (Transition_TiledSpiralUpdateState(transition)) {
                transition->state = TILED_SPIRAL_WAIT;
                transition->timer = 0;
            }
            break;
        case TILED_SPIRAL_WAIT:
            isDrawing = true;
            transition->timer++;
            if (transition->timer >= 3) {
                transition->state = TILED_SPIRAL_FINISHED;
                transition->timer = 0;
            }
            break;
        case TILED_SPIRAL_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }

    if (isDrawing) {
        Matrix_SetFrustrum(gGfxPool->unk_2B248, &mtxF, 60.0f, 16.0f, 8129.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, 0.0f,
                           &sTiledPerspectiveScale);
        Matrix_SetLookAt(gGfxPool->unk_2B288, &mtxF, 0.0f, 0.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        spiralTile = transition->workBuffer;
        for (i = 0; i < TILED_COUNT; i++) {
            Matrix_SetLockedLookAt(&gGfxPool->unk_2B2C8[i], &mtxF, spiralTile->scale, spiralTile->scale,
                                   spiralTile->scale, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, spiralTile->pos.x,
                                   spiralTile->pos.y, spiralTile->pos.z);
            spiralTile++;
        }
    }
}

bool Transition_TiledSpiralUpdateState(Transition* transition) {
    bool spiralFinished;
    s32 i;
    s32 j;
    TransitionInfo* tiledSpiralInfo = &transition->transitionInfo;
    SpiralTile* spiralTile;

    for (i = 0; i < 2; i++) {
        if (SPIRAL_TILE_SET_COUNT(tiledSpiralInfo) <= 0) {
            continue;
        }

        SPIRAL_TILE_SET_COUNT(tiledSpiralInfo)--;

        switch (SPIRAL_TILE_DIRECTION(tiledSpiralInfo)) {
            case TILED_SPIRAL_RIGHT:
                SPIRAL_TILE_COLUMN(tiledSpiralInfo)++;
                spiralTile = (SpiralTile*) transition->workBuffer +
                             (SPIRAL_TILE_ROW(tiledSpiralInfo) * TILED_COLUMNS + SPIRAL_TILE_COLUMN(tiledSpiralInfo));
                if (SPIRAL_TILE_COLUMN(tiledSpiralInfo) >= TILED_COLUMNS ||
                    spiralTile->state != SPIRAL_TILES_TILE_UNSET) {
                    SPIRAL_TILE_COLUMN(tiledSpiralInfo)--;
                    SPIRAL_TILE_ROW(tiledSpiralInfo)++;
                    SPIRAL_TILE_DIRECTION(tiledSpiralInfo) = TILED_SPIRAL_DOWN;
                }
                break;
            case TILED_SPIRAL_DOWN:
                SPIRAL_TILE_ROW(tiledSpiralInfo)++;
                spiralTile = (SpiralTile*) transition->workBuffer +
                             (SPIRAL_TILE_ROW(tiledSpiralInfo) * TILED_COLUMNS + SPIRAL_TILE_COLUMN(tiledSpiralInfo));
                if (SPIRAL_TILE_ROW(tiledSpiralInfo) >= TILED_ROWS || spiralTile->state != SPIRAL_TILES_TILE_UNSET) {
                    SPIRAL_TILE_ROW(tiledSpiralInfo)--;
                    SPIRAL_TILE_COLUMN(tiledSpiralInfo)--;
                    SPIRAL_TILE_DIRECTION(tiledSpiralInfo) = TILED_SPIRAL_LEFT;
                }
                break;
            case TILED_SPIRAL_LEFT:
                SPIRAL_TILE_COLUMN(tiledSpiralInfo)--;
                spiralTile = (SpiralTile*) transition->workBuffer +
                             (SPIRAL_TILE_ROW(tiledSpiralInfo) * TILED_COLUMNS + SPIRAL_TILE_COLUMN(tiledSpiralInfo));
                if (SPIRAL_TILE_COLUMN(tiledSpiralInfo) < 0 || spiralTile->state != SPIRAL_TILES_TILE_UNSET) {
                    SPIRAL_TILE_COLUMN(tiledSpiralInfo)++;
                    SPIRAL_TILE_ROW(tiledSpiralInfo)--;
                    SPIRAL_TILE_DIRECTION(tiledSpiralInfo) = TILED_SPIRAL_UP;
                }
                break;
            case TILED_SPIRAL_UP:
                SPIRAL_TILE_ROW(tiledSpiralInfo)--;
                spiralTile = (SpiralTile*) transition->workBuffer +
                             (SPIRAL_TILE_ROW(tiledSpiralInfo) * TILED_COLUMNS + SPIRAL_TILE_COLUMN(tiledSpiralInfo));
                if (SPIRAL_TILE_ROW(tiledSpiralInfo) < 0 || spiralTile->state != SPIRAL_TILES_TILE_UNSET) {
                    SPIRAL_TILE_ROW(tiledSpiralInfo)++;
                    SPIRAL_TILE_COLUMN(tiledSpiralInfo)++;
                    SPIRAL_TILE_DIRECTION(tiledSpiralInfo) = TILED_SPIRAL_RIGHT;
                }
                break;
            default:
                break;
        }
        spiralTile = (SpiralTile*) transition->workBuffer +
                     (SPIRAL_TILE_ROW(tiledSpiralInfo) * TILED_COLUMNS + SPIRAL_TILE_COLUMN(tiledSpiralInfo));
        spiralTile->state = SPIRAL_TILES_TILE_SET;
    }

    for (i = 0, spiralTile = transition->workBuffer; i < TILED_COUNT; i++, spiralTile++) {
        if (spiralTile->state == SPIRAL_TILES_TILE_SET) {
            if (spiralTile->scaleTimer <= 10) {
                spiralTile->scale = (10 - spiralTile->scaleTimer) / 10.0f;
                spiralTile->scaleTimer++;

            } else {
                spiralTile->state = SPIRAL_TILES_TILE_FINISHED;
                spiralTile->scale = 0.0f;
            }
        }
    }

    spiralFinished = true;
    for (i = 0, spiralTile = transition->workBuffer; i < TILED_COUNT; i++, spiralTile++) {
        if (spiralTile->state != SPIRAL_TILES_TILE_FINISHED) {
            spiralFinished = false;
        }
    }
    return spiralFinished;
}

void Transition_FadeInit(Transition* transition, s32 alpha, s32 fadeTime) {
    TransitionInfo* fadeInfo = &transition->transitionInfo;

    FADE_RED(fadeInfo) = FADE_GREEN(fadeInfo) = FADE_BLUE(fadeInfo) = 0;
    FADE_ALPHA(fadeInfo) = alpha;

    if (FADE_TIMER_ARG(transition) != 0) {
        FADE_TIMER(fadeInfo) = FADE_TIMER_ARG(transition);
    } else {
        FADE_TIMER(fadeInfo) = fadeTime;
    }
}

void Transition_FadeUpdate(Transition* transition) {
    TransitionInfo* fadeInfo = &transition->transitionInfo;

    switch (transition->state) {
        case FADE_OUT_START:
            FADE_ALPHA(fadeInfo) = (transition->timer * 255.0f) / FADE_TIMER(fadeInfo);
            transition->timer++;
            if (FADE_TIMER(fadeInfo) < transition->timer) {
                transition->state = FADE_WAIT;
                transition->timer = 0;
                FADE_ALPHA(fadeInfo) = 255;
            }
            break;
        case FADE_WAIT:
            transition->timer++;
            if (transition->timer >= 2) {
                transition->state = FADE_FINISHED;
            }
            break;
        case FADE_IN_START:
            FADE_ALPHA(fadeInfo) = ((FADE_TIMER(fadeInfo) - transition->timer) * 255.0f) / FADE_TIMER(fadeInfo);
            transition->timer++;

            if (FADE_TIMER(fadeInfo) < transition->timer) {
                transition->state = FADE_FINISHED;
                transition->timer = 0;
                FADE_ALPHA(fadeInfo) = 0;
            }
            break;
        case FADE_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
        case TRANSITION_STATE_INACTIVE:
        default:
            break;
    }
}

Gfx* Transition_FadeDraw(Gfx* gfx, Transition* transition) {
    TransitionInfo* fadeInfo = &transition->transitionInfo;

    gSPDisplayList(gfx++, D_8014888);

    if (transition->activeTransitionType == TRANSITION_TYPE_STATIC_FADE) {
        gDPSetAlphaCompare(gfx++, G_AC_DITHER);
    }

    gDPSetPrimColor(gfx++, 0, 0, FADE_RED(fadeInfo), FADE_GREEN(fadeInfo), FADE_BLUE(fadeInfo), FADE_ALPHA(fadeInfo));

    gDPFillRectangle(gfx++, TRANSITION_BORDER_WIDTH, TRANSITION_BORDER_HEIGHT, SCREEN_WIDTH - TRANSITION_BORDER_WIDTH,
                     SCREEN_HEIGHT - TRANSITION_BORDER_HEIGHT);

    return gfx;
}

void Transition_WipeInit(Transition* transition) {
    TransitionInfo* wipeInfo = &transition->transitionInfo;

    WIPE_LEFT(wipeInfo) = TRANSITION_BORDER_WIDTH;
    WIPE_TOP(wipeInfo) = TRANSITION_BORDER_HEIGHT;
    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;

    switch (WIPE_DIRECTION_ARG(transition)) {
        case WIPE_DIRECTION_LEFT:
        case WIPE_DIRECTION_RIGHT:
            sWipePos = WIPE_LEFT(wipeInfo);
            break;
        case WIPE_DIRECTION_UP:
        case WIPE_DIRECTION_DOWN:
            sWipePos = WIPE_TOP(wipeInfo);
            break;
    }
}

void Transition_WipeUpdate(Transition* transition) {
    TransitionInfo* wipeInfo = &transition->transitionInfo;

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case WIPE_START:
            switch (WIPE_DIRECTION_ARG(transition)) {
                case WIPE_DIRECTION_LEFT:
                    WIPE_LEFT(wipeInfo) = TRANSITION_BORDER_WIDTH -
                                          (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_WIDTH) / 20.0f);
                    sWipePos = WIPE_LEFT(wipeInfo);
                    break;
                case WIPE_DIRECTION_RIGHT:
                    WIPE_LEFT(wipeInfo) = TRANSITION_BORDER_WIDTH +
                                          (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_WIDTH) / 20.0f);
                    sWipePos = WIPE_LEFT(wipeInfo);
                    break;
                case WIPE_DIRECTION_UP:
                    WIPE_TOP(wipeInfo) = TRANSITION_BORDER_HEIGHT -
                                         (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_HEIGHT) / 20.0f);
                    sWipePos = WIPE_TOP(wipeInfo);
                    break;
                case WIPE_DIRECTION_DOWN:
                    WIPE_TOP(wipeInfo) = TRANSITION_BORDER_HEIGHT +
                                         (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_HEIGHT) / 20.0f);
                    sWipePos = WIPE_TOP(wipeInfo);
                    break;
            }

            transition->timer++;
            if (transition->timer > 20) {
                transition->state = WIPE_FINISHED;
                transition->timer = 0;
                WIPE_LEFT(wipeInfo) = SCREEN_WIDTH - TRANSITION_BORDER_WIDTH;
            }
            break;
        case WIPE_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

Gfx* Transition_WipeDraw(Gfx* gfx, Transition* transition) {
    TransitionInfo* wipeInfo = &transition->transitionInfo;

    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return TextureUtils_Draw(gfx, transition->backgroundBuffer, WIPE_LEFT(wipeInfo), WIPE_TOP(wipeInfo),
                             TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0,
                             false, false, false);
}

void Transition_PhasedStripsInit(Transition* transition) {
    s32 i;
    f32* stripLeftPtr;

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;

    for (i = 0, stripLeftPtr = transition->workBuffer; i < TRANSITION_BACKGROUND_HEIGHT; i++, stripLeftPtr++) {
        *stripLeftPtr = TRANSITION_BORDER_WIDTH;
    }
}

void Transition_PhasedStripsUpdate(Transition* transition) {

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case PHASED_STRIPS_START:
            if (Transition_PhasedStripsUpdateState(transition)) {
                transition->state = PHASED_STRIPS_WAIT;
                transition->timer = 0;
            }
            break;
        case PHASED_STRIPS_WAIT:
            transition->timer++;
            if (transition->timer >= 2) {
                transition->state = PHASED_STRIPS_FINISHED;
                transition->timer = 0;
            }
            break;
        case PHASED_STRIPS_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

bool Transition_PhasedStripsUpdateState(Transition* transition) {
    f32 stripMoveDistance;
    s32 distanceOffset;
    s32 stripMoveDistanceScale;
    s32 row;
    bool phasedStripsFinished;
    f32* stripLeftPtr;
    s32 centralRow = TRANSITION_BACKGROUND_HEIGHT / 2;

    phasedStripsFinished = true;

    for (row = 0, stripLeftPtr = transition->workBuffer; row < TRANSITION_BACKGROUND_HEIGHT; row++, stripLeftPtr++) {
        distanceOffset = centralRow - row;

        if (distanceOffset < 0) {
            distanceOffset = -distanceOffset;
        }

        distanceOffset = centralRow - distanceOffset;
        stripMoveDistanceScale = (transition->timer * sStripMoveSpeed) - distanceOffset;

        if (stripMoveDistanceScale < 0) {
            stripMoveDistanceScale = 0;
        }
        stripMoveDistance = stripMoveDistanceScale * 0.5f;

        if (row & 1) {
            stripMoveDistance = 0.0f - stripMoveDistance;
        }
        *stripLeftPtr += stripMoveDistance;
        if ((*stripLeftPtr >= TRANSITION_BORDER_WIDTH) && (*stripLeftPtr < SCREEN_WIDTH - TRANSITION_BORDER_WIDTH)) {
            phasedStripsFinished = false;
        }
    }
    transition->timer++;

    return phasedStripsFinished;
}

#ifdef NON_MATCHING
Gfx* Transition_PhasedStripsDraw(Gfx* gfx, Transition* transition) {
    f32* stripLeftPtr;
    u16* backgroundTexture;
    s32 strip;
    s32 stripRow;
    s32 sp30[2];
    s32 width = TRANSITION_BACKGROUND_WIDTH;
    s32 top;
    s32 xl;
    s32 xh;
    s32 yl;
    s32 yh;
    s32 stripHeight;

    gSPDisplayList(gfx++, D_8014940);

    sp30[1] = TRANSITION_BACKGROUND_HEIGHT / PHASED_STRIP_HEIGHT;
    sp30[0] = 0;

    stripHeight = PHASED_STRIP_HEIGHT;
    backgroundTexture = transition->backgroundBuffer;
    stripLeftPtr = transition->workBuffer;

    for (strip = 0; strip < sp30[1]; strip++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureTile(gfx++, backgroundTexture + strip * (TRANSITION_BACKGROUND_WIDTH * PHASED_STRIP_HEIGHT),
                           G_IM_FMT_RGBA, G_IM_SIZ_16b, TRANSITION_BACKGROUND_WIDTH, PHASED_STRIP_HEIGHT, 0, 0,
                           TRANSITION_BACKGROUND_WIDTH - 1, PHASED_STRIP_HEIGHT - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        for (stripRow = 0; stripRow < stripHeight; stripRow++) {
            if ((*stripLeftPtr < -TRANSITION_BACKGROUND_WIDTH + TRANSITION_BORDER_WIDTH) ||
                (*stripLeftPtr > TRANSITION_BACKGROUND_WIDTH + TRANSITION_BORDER_WIDTH)) {
                stripLeftPtr++;
                continue;
            }

            top = (strip * PHASED_STRIP_HEIGHT) + stripRow;
            xl = *stripLeftPtr * 4.0f;
            xh = (*stripLeftPtr + width) * 4.0f;

            stripLeftPtr++;

            gSPScisTextureRectangle(gfx++, xl, (top + TRANSITION_BORDER_HEIGHT) << 2, xh,
                                    (top + (TRANSITION_BORDER_HEIGHT + 1)) << 2, 0, 0, stripRow << 5, 1 << 10, 1 << 10);
        }
    }

    return gfx;
}
#else
#ifndef EXPANSION_KIT
#ifdef VERSION_JP
#pragma GLOBAL_ASM("asm/jp/rev0/nonmatchings/overlays/ovl_i2/transition/Transition_PhasedStripsDraw.s")
#elif VERSION_US
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/transition/Transition_PhasedStripsDraw.s")
#elif VERSION_PAL
#pragma GLOBAL_ASM("asm/pal/rev0/nonmatchings/overlays/ovl_i2/transition/Transition_PhasedStripsDraw.s")
#endif
#else
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/overlays/ovl_i2/transition/Transition_PhasedStripsDraw.s")
#endif
#endif

void Transition_GreyscalePaletteInit(Transition* transition) {
    TransitionInfo* greyscalePaletteInfo = &transition->transitionInfo;

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    transition->flags |= TRANSITION_FLAG_GREYSCALE;
    transition->flags |= TRANSITION_FLAG_CONVERT_TO_PALETTE;
    GREYSCALE_PALETTE_INDEX(greyscalePaletteInfo) = -8;
}

void Transition_GreyscalePaletteUpdate(Transition* transition) {

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case GREYSCALE_PALETTE_START:
            if (Transition_GreyscalePaletteUpdateState(transition)) {
                transition->state = GREYSCALE_PALETTE_WAIT;
                transition->timer = 0;
            }
            break;
        case GREYSCALE_PALETTE_WAIT:
            transition->timer++;
            if (transition->timer >= 4) {
                transition->state = GREYSCALE_PALETTE_FINISHED;
                transition->timer = 0;
            }
            break;
        case GREYSCALE_PALETTE_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

bool Transition_GreyscalePaletteUpdateState(Transition* transition) {
    bool greyscalePaletteFinished = false;

    if (GREYSCALE_PALETTE_INDEX(&transition->transitionInfo) >= 0) {
        sTransitionPalette[GREYSCALE_PALETTE_INDEX(&transition->transitionInfo)] = 0;
    }
    transition->timer++;
    if (transition->timer >= 2) {
        transition->timer = 0;
        GREYSCALE_PALETTE_INDEX(&transition->transitionInfo)++;
        if (GREYSCALE_PALETTE_INDEX(&transition->transitionInfo) > 31) {
            GREYSCALE_PALETTE_INDEX(&transition->transitionInfo) = 31;
            greyscalePaletteFinished = true;
        }
    }
    return greyscalePaletteFinished;
}

Gfx* Transition_GreyscalePaletteDraw(Gfx* gfx, Transition* transition) {
    return TextureUtils_DrawIndexedBlocks(gfx, transition->backgroundBuffer, sTransitionPalettePtr, G_IM_FMT_CI, 1,
                                          TRANSITION_BORDER_WIDTH, TRANSITION_BORDER_HEIGHT,
                                          TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT,
                                          INDEXED_DRAW_USE_TLUT | INDEXED_DRAW_SMALL_BLOCKS);
}
