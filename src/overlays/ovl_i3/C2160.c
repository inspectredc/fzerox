#include "global.h"

extern GfxPool* gGfxPool;
extern s32 gNumPlayers;

Gfx* func_i3_8012EE90(Gfx* gfx, s32 playerIndex) {
    u16 sp46;
    f32 var_fv0;

    var_fv0 = 0;
    if (gNumPlayers == 2) {
        var_fv0 = -60.0f;
    }

    func_8006D03C(&gGfxPool->unk_20008[playerIndex], NULL, 45.0f, 16.0f, 4096.0f, 320.0f, 0, 240.0f, var_fv0, &sp46);
    gSPPerspNormalize(gfx++, sp46);
    func_8006CC98(&gGfxPool->unk_20108[playerIndex], NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f, 0.0f, 1.0f, 0.0f);
    return gfx;
}
