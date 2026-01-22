#include "global.h"

extern GfxPool* gGfxPool;
extern s32 gNumPlayers;

Gfx* func_i3_8012EE90(Gfx* gfx, s32 playerIndex) {
    u16 perspectiveScale;
    f32 frustrumCenterY;

    frustrumCenterY = 0;
    if (gNumPlayers == 2) {
        frustrumCenterY = -60.0f;
    }

    Matrix_SetFrustrum(&gGfxPool->unk_20008[playerIndex], NULL, 45.0f, 16.0f, 4096.0f, SCREEN_WIDTH, 0, SCREEN_HEIGHT,
                       frustrumCenterY, &perspectiveScale);
    gSPPerspNormalize(gfx++, perspectiveScale);
    Matrix_SetLookAt(&gGfxPool->unk_20108[playerIndex], NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f, 0.0f, 1.0f, 0.0f);
    return gfx;
}
