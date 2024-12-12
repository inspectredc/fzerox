#include "global.h"

OSPiHandle* func_i2_80103698(void);
void func_i10_80115E30(unk_801247C0*);
extern OSPiHandle* D_i2_8011183C;

s32 func_i10_80115DF0(void) {
    D_i2_8011183C = func_i2_80103698();
    func_i10_80115E30((unk_801247C0*) func_800768F4(1, sizeof(unk_801247C0)));
    return 0;
}

void func_i2_80102600(unk_801247C0*);
void func_i2_80103728(s32, size_t, void*, size_t);
bool func_i10_80115EE8(u8*);
void func_i10_80115F2C(unk_801247C0*, s32);

void func_i10_80115E30(unk_801247C0* arg0) {
    s32 i;
    s32 var_s2;
    s32 sp34;
    unk_struct_19E0* var_s1;

    func_i2_80103728(0, 0, arg0, sizeof(unk_801247C0));

    for (var_s2 = 0, i = 0, var_s1 = arg0->unk_00; i < 2; var_s2++, i++, var_s1++) {
        if (!func_i10_80115EE8(var_s1->unk_00.unk_00)) {
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

void func_i10_80115F2C(unk_801247C0* arg0, s32 arg1) {
    s32 i;
    u8* temp_a2 = arg0->unk_00[arg1].unk_00.unk_00;

    for (i = 0; i < 8; i++) {
        temp_a2[i] = D_i2_8010ADE0[i];
    }

    func_i2_80103728(1, temp_a2 - (u8*) arg0, temp_a2, 8);
}
