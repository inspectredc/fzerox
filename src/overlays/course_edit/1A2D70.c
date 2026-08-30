#include "global.h"

u8 D_xk2_80128D00[64];
u8 D_xk2_80104CA0[12] = { 0 };

extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F12B0(void) {
    s32 i;

    D_800D6CA0.unk_1C = -1;

    for (i = 0; i < 12; i++) {
        if ((i != 10) && (i != 1) && (i != 3)) {
            D_xk2_80104CA0[i] = 0;
        }
    }

    for (i = 0; i < 64; i++) {
        D_xk2_80128D00[i] = 0;
    }
}

void func_xk2_800F1330(s32 arg0, u8 arg1) {
    D_xk2_80128D00[arg0] |= arg1;
}

u8 func_xk2_800F1350(s32 arg0) {
    return D_xk2_80128D00[arg0];
}
