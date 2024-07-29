#include "global.h"

// Todo: Migrate these into appropriate functions
static const char devrostr0[] = "========================================================\n";
static const char devrostr1[] = "LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n";
static const char devrostr2[] = "========================================================\n";

extern OSMesgQueue D_800DCA68;
void func_i1_80410860(s32, s32, s32*);

s32 func_800750B0(s32 arg0, void* arg1, s32 arg2, s32 arg3) {
    void* sp54;
    s32 sp4C[2];
    s32 sp2C[8];
    void* sp28;

    func_i1_80410860(arg0, arg2, sp4C);
    osVirtualToPhysical((uintptr_t) arg1);
    sp54 = (uintptr_t) arg1 + (uintptr_t) arg2;
    osVirtualToPhysical(sp54);
    osVirtualToPhysical((uintptr_t) sp54 + (uintptr_t) arg3);
    func_i1_8040B8F0(sp2C, 0, arg0, arg1, sp4C[0], &D_800DCA68);
    osRecvMesg(&D_800DCA68, &sp28, 1);
    bzero(sp54, arg3);

    return sp4C[1];
}

void func_i2_800FC730(void);
extern u8 D_524920[];
extern u8 D_524D60[];
extern u8 D_800FC730[];
extern u8 D_800FCB70[];
extern u8 D_800FCB70_2[];

void func_8007515C(void) {
    func_80073E28(D_524920, D_800FC730, D_524D60 - D_524920);
    bzero(D_800FCB70, D_800FCB70_2 - D_800FCB70);
    func_i2_800FC730();
}
