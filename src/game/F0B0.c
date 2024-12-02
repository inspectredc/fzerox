#include "global.h"

extern OSMesgQueue D_800DCA68;

s32 func_800750B0(s32 startLBA, void* arg1, u32 numBytes, size_t size) {
    void* sp54;
    s32 sp50;
    s32 numLBAs;
    s32 pad;
    LEOCmd cmd;
    void* sp28;

    LeoByteToLBA(startLBA, numBytes, &numLBAs);
    osVirtualToPhysical(arg1);
    sp54 = (uintptr_t) arg1 + numBytes;
    osVirtualToPhysical(sp54);
    osVirtualToPhysical((uintptr_t) sp54 + size);
    LeoReadWrite(&cmd, OS_READ, startLBA, arg1, numLBAs, &D_800DCA68);
    osRecvMesg(&D_800DCA68, &sp28, OS_MESG_BLOCK);
    bzero(sp54, size);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLBA, sp54, size, arg1, numLBAs);
    PRINTF("========================================================\n");

    //! @bug sp50 uninitialised?
    return sp50;
}

void func_i2_800FC730(void);

void func_8007515C(void) {
    func_80073E28(SEGMENT_ROM_START(ovl_i11), SEGMENT_VRAM_START(ovl_i11), SEGMENT_ROM_SIZE(ovl_i11));
    bzero(SEGMENT_BSS_START(ovl_i11), SEGMENT_BSS_SIZE(ovl_i11));
    func_i2_800FC730();
}
