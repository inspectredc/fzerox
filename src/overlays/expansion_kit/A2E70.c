#include "global.h"

s32 D_xk1_80030050 = 1;

void func_xk1_80025C00(s32 arg0) {
    D_xk1_80030050 = arg0;
}

s32 func_xk1_80025C0C(void) {
    return D_xk1_80030050;
}
