#include "global.h"

extern GfxPool* D_800DCCF0;
extern s32 D_800CD000;

Gfx* func_i3_8012EE90(Gfx* gfx, s32 arg1) {
    u16 sp46;
    f32 var_fv0;

    var_fv0 = 0;
    if (D_800CD000 == 2) {
        var_fv0 = -60.0f;
    }

    func_8006D03C(&D_800DCCF0->unk_20008[arg1], NULL, 45.0f, 16.0f, 4096.0f, 320.0f, 0,
                  240.0f, var_fv0, &sp46);
    gSPPerspNormalize(gfx++, sp46);
    func_8006CC98(&D_800DCCF0->unk_20108[arg1], NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f,
                  0.0f, 1.0f, 0.0f);
    return gfx;
}
