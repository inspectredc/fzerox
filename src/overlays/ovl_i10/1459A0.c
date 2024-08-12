#include "global.h"

s32 func_80103698(void);
void func_i10_80115E30(u8*);
extern s32 D_8011183C; // ovl 2 bss

s32 func_i10_80115DF0(void) {
    D_8011183C = func_80103698();
    func_i10_80115E30(func_800768F4(1, 0x8000));
    return 0;
}

void func_i2_80101784(s32, s32);
void func_i2_80102600(s32);
void func_i2_80103728(s32, s32, u8*, s32);
bool func_i10_80115EE8(u8*);
void func_i10_80115F2C(u8*, s32);

void func_i10_80115E30(u8* arg0) {
    s32 i;
    s32 var_s2;
    s32 sp34;
    u8* var_s1;

    func_i2_80103728(0, 0, arg0, 0x8000);

    for (var_s2 = 0, i = 0, var_s1 = arg0; i < 2; var_s2++, i++, var_s1 += 0x19E0) {
        if (!func_i10_80115EE8(var_s1)) {
            break;
        }
        sp34 = i;
    }

    if (var_s2 == 2) {
        func_i2_80101784(arg0, 0);
        return;
    }
    if (var_s2 == 1) {
        func_i10_80115F2C(arg0, sp34);
    }
    func_i2_80102600(arg0);
}

extern u8 D_i2_8010ADE0[];

bool func_i10_80115EE8(u8* arg0) {
    s32 ret = false;
    s32 i;

    for (i = 0; i != 8; i++) {
        if (arg0[i] != D_i2_8010ADE0[i]) {
            ret = true;
            break;
        }
    }

    return ret;
}

void func_i10_80115F2C(u8* arg0, s32 arg1) {
    s32 i;
    // FAKE?
    u8* temp_a2 = (u8*) arg0 + arg1 * 0x19E0;

    for (i = 0; i < 8; i++) {
        temp_a2[i] = D_i2_8010ADE0[i];
    }

    func_i2_80103728(1, temp_a2 - arg0, temp_a2, 8);
}
