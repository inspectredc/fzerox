#include "global.h"

s32 func_i6_8011DBD0(void) {
    u32 i = 0;
    s32 temp_a0;
    s32 var_v1 = 0;

    while (i < 2) {

        while(IO_READ(0x4600010) % 4) {}
        
        temp_a0 = IO_READ(0x100006E8);
        
        if (temp_a0 != var_v1) {
            i = 0;
        } else {
            i++;
        }

        var_v1 = temp_a0;
    } 
    return temp_a0;
}
