#include "global.h"

s32 func_xk1_8002FB30(s8* str) {
    u8 i;
    s32 var_v1;

    var_v1 = 0;
    for (i = 0; str[i] != 0; i++) {
        if (str[i] == '1') {
            var_v1 += 7;
        } else {
            var_v1 += 9;
        }
    }
    return var_v1 - 1;
}
