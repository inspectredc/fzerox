#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 func_i1_80410C60(LEOCapacity* cmdBlock, s32 control) {

    if (__leoActive == 0) {
        return -1;
    }
    
    if (control == LEO_CONTROL_WRT) {
        cmdBlock->startLBA = LEORAM_START_LBA[LEOdisk_type] - 0x18;
        cmdBlock->endLBA = LEO_LBA_MAX;
        cmdBlock->nbytes = LEORAM_BYTE[LEOdisk_type];
    } else {
        cmdBlock->startLBA = 0;
        cmdBlock->endLBA = LEO_LBA_MAX;
        cmdBlock->nbytes = 0x3D78F40; // Total capacity, approx. 64.45 MB
    }
    return 0;
}
