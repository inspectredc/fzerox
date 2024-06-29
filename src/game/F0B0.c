#include "global.h"

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F0B0/func_800750B0.s")

// todo: clean this up, D_800FCB70_2 shouldnt really exist like this
/*
void func_80073E28(void*, void*, size_t);
void func_i2_800FC730(void);
extern u8 D_524920[];
extern u8 D_524D60[];
extern u8 D_800FC730[];
extern u8 D_800FCB70[];
extern u8 D_800FCB70_2[];

void func_8007515C(void) {
    func_80073E28(D_524920, D_800FC730, D_524D60 - D_524920);
    // vram size 0, with two different symbols?
    bzero(D_800FCB70, D_800FCB70_2 - D_800FCB70);
    func_i2_800FC730();
}
 */

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/F0B0/func_8007515C.s")
