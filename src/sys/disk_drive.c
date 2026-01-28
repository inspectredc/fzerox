#include "global.h"

extern OSMesgQueue gDmaMesgQueue;

s32 func_800750B0(s32 startLba, void* vram, size_t diskSize, size_t bssSize) {
    void* bssStart;
    s32 sp50;
    s32 lbaCount;
    s32 pad;
    LEOCmd cmd;
    OSMesg msg;

    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize,
           lbaCount);
    PRINTF("========================================================\n");

    LeoReadWrite(&cmd, OS_READ, startLba, vram, lbaCount, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, &msg, OS_MESG_BLOCK);
    bzero(bssStart, bssSize);

    //! @bug sp50 uninitialised?
    return sp50;
}

void func_8007515C(void) {
    Dma_ClearRomCopy(SEGMENT_ROM_START(ovl_i11), SEGMENT_VRAM_START(ovl_i11), SEGMENT_ROM_SIZE(ovl_i11));
    bzero(SEGMENT_BSS_START(ovl_i11), SEGMENT_BSS_SIZE(ovl_i11));
    func_i11_800FC730();
}
