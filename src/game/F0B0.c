#include "global.h"

// Todo: Migrate these into appropriate functions
static const char devrostr0[] = "========================================================\n";
static const char devrostr1[] = "LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n";
static const char devrostr2[] = "========================================================\n";

extern OSMesgQueue D_800DCA68;

s32 func_800750B0(s32 arg0, void* arg1, s32 arg2, s32 arg3) {
    void* sp54;
    s32 sp4C[2];
    s32 pad;
    LEOCmd sp2C;
    void* sp28;

    LeoByteToLBA(arg0, arg2, sp4C);
    osVirtualToPhysical((uintptr_t) arg1);
    sp54 = (uintptr_t) arg1 + (uintptr_t) arg2;
    osVirtualToPhysical(sp54);
    osVirtualToPhysical((uintptr_t) sp54 + (uintptr_t) arg3);
    LeoReadWrite(&sp2C, 0, arg0, arg1, sp4C[0], &D_800DCA68);
    osRecvMesg(&D_800DCA68, &sp28, 1);
    bzero(sp54, arg3);

    return sp4C[1];
}

void func_i2_800FC730(void);

void func_8007515C(void) {
    func_80073E28(SEGMENT_ROM_START(ovl_i11), SEGMENT_VRAM_START(ovl_i11), SEGMENT_ROM_SIZE(ovl_i11));
    bzero(SEGMENT_BSS_START(ovl_i11), SEGMENT_BSS_SIZE(ovl_i11));
    func_i2_800FC730();
}
