#include "global.h"

s32 func_i6_8011DBD0(void) {
    u32 i = 0;
    s32 temp_a0;
    s32 var_v1 = 0;

    while (i < 2) {

        while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

        temp_a0 = ROM_READ(0x6E8);

        if (temp_a0 != var_v1) {
            i = 0;
        } else {
            i++;
        }

        var_v1 = temp_a0;
    }
    return temp_a0;
}
