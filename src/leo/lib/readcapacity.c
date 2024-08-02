#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 LeoReadCapacity(LEOCapacity* cmdBlock, s32 dir) {

    if (__leoActive == 0) {
        return -1;
    }

    if (dir == OS_WRITE) {
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
