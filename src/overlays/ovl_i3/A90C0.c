#include "global.h"
#include "fzx_racer.h"

f32 func_i3_80115DF0(f32 arg0) {
    if (arg0 < 0.0f) {
        return 0.0f - arg0;
    }
    return arg0;
}

s32 func_i3_80115E1C(s32 arg0) {
    if (arg0 < 0) {
        return -arg0;
    }
    return arg0;
}

void func_i3_80115E34(unk_802C4920* arg0) {

    arg0->unk_34D = (arg0->unk_00 % 5) + 2;
    if ((arg0->unk_00 < 0xF) && (arg0->unk_34D == 2)) {
        arg0->unk_34D = 1;
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i3/A90C0/func_i3_80115E74.s")

extern s32 D_800CD008;
extern unk_800F8510* D_800F8510;
extern s32 D_800F8514;
extern s32 D_i3_80141990;
extern s32 D_i3_80141994;
extern u32 D_i3_8013E328[];

void func_i3_80116974(void) {
    s32 sp1C[19];

    if (D_800F8514 < 0x18) {
        if (func_i2_801037CC(&sp1C, D_800F8514) == 0) {
            D_i3_80141990 = D_i3_8013E328[D_800F8514 * 4 + D_800CD008];
        } else {
            D_i3_80141990 = 0x36EE7F;
        }
        if (D_800CD008 >= 2) {
            if (D_800F8510->unk_20 < sp1C[2]) {
                D_i3_80141990 = (D_i3_80141990 - sp1C[2]) + D_800F8510->unk_20;
            }
        }
    } else {
        D_i3_80141990 = 0x36EE7F;
    }
    D_i3_80141994 = D_i3_80141990;
}

void func_i3_801175A4(void);
extern s32 D_800CD000;
extern s32 D_800CD00C;
extern s32 D_800E5EC0;
extern f32 D_i3_8013E9E0[];
extern s32 D_i3_8013E9EC[];

void func_i3_80116A50(unk_802C4920* arg0) {
    s32 var_s3;
    s32 i;
    unk_802C4920* var_s0;
    f32 temp_ft3;
    f32 temp_fv0;
    f32 var_fs0;

    temp_ft3 = D_800F8510->unk_0C * D_800CD00C;

    if (D_800E5EC0 < arg0->unk_368) {
        for (i = D_800CD000, var_fs0 = temp_ft3, var_s3 = 0; i < D_800E5EC0; i++) {
            var_s0 = &gRacers[i];
            if ((D_800E5EC0 >= var_s0->unk_368) && (arg0->unk_00 != var_s0->unk_00)) {
                temp_fv0 = func_i3_80115DF0(arg0->unk_23C - var_s0->unk_23C);
                if (temp_fv0 < var_fs0) {
                    var_fs0 = temp_fv0;
                    var_s3 = i;
                }
            }
        }
        arg0->unk_368 = gRacers[var_s3].unk_368;
        if (D_800E5EC0 < arg0->unk_368) {
            arg0->unk_368 = 1;
        }
        func_i3_801175A4();
    }

    arg0->unk_398 = D_i3_80141990 - ((temp_ft3 - arg0->unk_23C) / temp_ft3) * D_i3_8013E9E0[D_800CD008] +
                    D_i3_8013E9EC[arg0->unk_368 + D_800CD008 * 30];
}

extern s16* D_i3_8013DBE8;

void func_i3_80116C4C(void) {
    D_i3_8013DBE8 = func_800768F4(0, 0x400);
}

extern s32 D_80141900;
extern s32 D_i3_80141904;
extern s32 D_i3_80141918;
extern s32 D_i3_8014191C;
extern s32 D_i3_80141920;
extern s32 D_i3_80141924;
extern s32 D_i3_80141928;
extern s32 D_i3_8014192C;
extern s32 D_i3_80141930;
extern s32 D_i3_80141934;
extern s32 D_i3_80141938;
extern s32 D_i3_8014193C;
extern s32 D_i3_80141940;
extern s32 D_i3_80141944;
extern s32 D_i3_80141948;
extern s32 D_i3_8014194C;
extern s32 D_i3_80141950;
extern s32 D_i3_80141954;
extern s32 D_i3_80141958;
extern s32 D_i3_8014195C;
extern s32 D_i3_80141960;
extern s32 D_i3_80141964;
extern s32 D_i3_80141968;
extern s32 D_i3_8014196C;
extern s32 D_i3_80141970;
extern s32 D_i3_80141974;
extern s32 D_i3_80141978;
extern s32 D_i3_8014197C;
extern s32 D_i3_80141980;
extern s32 D_i3_80141984;
extern s32 D_i3_80141988;
extern s32 D_i3_8014198C;

extern s32 D_800CD004;
extern s32 D_800DCE44;

extern unk_802C4920* D_i3_80141910;

typedef struct unk_8013E7A8 {
    s16 unk_00;
    s8 unk_02;
    s8 unk_03[0xB];
} unk_8013E7A8;
extern unk_8013E7A8 D_i3_8013E7A8[];
extern s16 D_i3_8013E94C[];
extern s16* D_i3_8013DBE8;
extern u32 D_i3_8013DB80[]; // segmented offsets
extern u32 D_i3_8013E4A8[]; // sizes?
extern u32 D_i3_8013E628[];
extern s16 D_i3_8013E94C[];
extern f32 D_i3_8013EBD0[];
extern f32 D_i3_8013EC30[];

void func_i3_80116C74(unk_802C4920* arg0) {
    f32 var_fa0;
    s32 padC0[7];
    s32 sp48[30];
    s32 pad[3];
    s32 i;
    s32 j;

    D_i3_80141910 = gRacers;
    D_80141900 = 0;
    if (arg0->unk_00 == 0) {
        func_i3_80116974();
        if (D_800F8514 < 0x18) {
            func_80077CF0(D_i3_8013DB80[D_800F8514], 0x400, D_i3_8013DBE8);
        } else {
            for (i = 0; i < 0x200; i += 2) {
                D_i3_8013DBE8[i + 0] = 0x45;
                D_i3_8013DBE8[i + 1] = 0;
            }
        }

        if (D_800DCE44 == 6) {
            arg0->unk_1A8 = 0.5f;
        }

        if ((D_800CD004 == 4) || (D_800CD004 == 5)) {
            D_i3_80141904 = 0;
        } else {
            D_i3_80141904 = 1;
        }

        for (i = 0; i < 30; i++) {
            sp48[i] = 0xFF;
            for (j = 0; j < D_800E5EC0; j++) {
                if (gRacers[j].unk_2C8 == i) {
                    sp48[i] = j;
                    break;
                }
            }
        }

        D_i3_80141918 = sp48[0];
        D_i3_8014191C = sp48[1];
        D_i3_80141920 = sp48[2];
        D_i3_80141924 = sp48[3];
        D_i3_80141928 = sp48[4];
        D_i3_8014192C = sp48[5];
        D_i3_80141930 = sp48[6];
        D_i3_80141934 = sp48[7];
        D_i3_80141938 = sp48[8];
        D_i3_8014193C = sp48[9];
        D_i3_80141940 = sp48[10];
        D_i3_80141944 = sp48[11];
        D_i3_80141948 = sp48[12];
        D_i3_8014194C = sp48[13];
        D_i3_80141950 = sp48[14];
        D_i3_80141954 = sp48[15];
        D_i3_80141958 = sp48[16];
        D_i3_8014195C = sp48[17];
        D_i3_80141960 = sp48[18];
        D_i3_80141964 = sp48[19];
        D_i3_80141968 = sp48[20];
        D_i3_8014196C = sp48[21];
        D_i3_80141970 = sp48[22];
        D_i3_80141974 = sp48[23];
        D_i3_80141978 = sp48[24];
        D_i3_8014197C = sp48[25];
        D_i3_80141980 = sp48[26];
        D_i3_80141984 = sp48[27];
        D_i3_80141988 = sp48[28];
        D_i3_8014198C = sp48[29];
    }

    arg0->unk_358 = 0xFFFF;
    arg0->unk_330 = 0.01f;
    arg0->unk_334 = func_8006A918() % 32768 / 32767.0f * 20.0f + 350.0f;
    arg0->unk_338 = func_8006A978() % 32768 / 32767.0f * 0.01f + 0.3f;
    arg0->unk_354 = func_8006A918() % 32768 / 32767.0f + 5.0f;
    arg0->unk_340 = func_8006A918() % 8 + 15;
    arg0->unk_3A4 = 0;
    arg0->unk_39C = 0;
    arg0->unk_398 = 0;
    arg0->unk_394 = 0;
    arg0->unk_390 = 0;
    arg0->unk_36C = 0;
    arg0->unk_384 = 0;
    arg0->unk_1E8 = 0.0f;
    arg0->unk_364 = 0.0f;
    arg0->unk_360 = 0.0f;
    arg0->unk_38C = 0.0f;
    arg0->unk_3A0 = D_800E5EC0;
    arg0->unk_1EC = 2500.0f / 27.0f;

    if (D_800DCE44 == 1) {
        arg0->unk_360 = D_i3_8013EBD0[D_i3_8013E7A8[arg0->unk_2C8].unk_02 * 4 + D_800CD008];
        arg0->unk_364 = D_i3_8013EC30[D_i3_8013E7A8[arg0->unk_2C8].unk_02 * 4 + D_800CD008] + arg0->unk_360;
    }

    arg0->unk_370 = 0;
    arg0->unk_33C = ((arg0->unk_24C.z.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.z.y * arg0->unk_0C.unk_28.y) +
                     (arg0->unk_24C.z.z * arg0->unk_0C.unk_28.z)) *
                    -1.0f;
    arg0->unk_340 = func_8006A978() % 2 + 1;

    arg0->unk_36C = D_i3_8013E7A8[arg0->unk_2C8].unk_00;

    if (D_i3_8013E7A8[arg0->unk_2C8].unk_02 < 2) {
        arg0->unk_36C |= 0x200;
    }

    arg0->unk_380 = 0;
    arg0->unk_37C = 0;
    arg0->unk_378 = 0;
    arg0->unk_374 = 0;

    if (D_800DCE44 == 0x11) {
        arg0->unk_1A8 = func_8008960C(0.1f);
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
        arg0->unk_330 = 0.01f;
        arg0->unk_334 = func_8006A918() % 32768 / 32767.0f * 20.0f + 500.0f;
    }

    if (arg0->unk_00 >= D_800CD000) {
        if (D_800F8514 < 0x18) {
            if (D_800E5EC0 >= arg0->unk_368) {
                arg0->unk_39C = D_i3_8013E4A8[D_800F8514 * 4 + D_800CD008] +
                                D_i3_8013E628[D_800F8514 * 4 + D_800CD008] * (arg0->unk_368 - 1);
            }
        }
        if ((D_i3_80141910->unk_2AC == arg0->unk_2AC - 4) || (D_i3_80141910->unk_2AC == (arg0->unk_2AC + 4)) ||
            (D_800CD000 >= 2)) {
            var_fa0 = D_i3_80141910->unk_1A8;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        } else if ((D_800CD008 == 3) && (D_i3_8013E94C[D_800F8514] != 0)) {
            var_fa0 = (func_8006A918() % 256 / 255.0f + 10.0f) / 14.0f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = func_8008960C(var_fa0);
        } else {
            var_fa0 = D_i3_80141910->unk_1A8;
            var_fa0 += func_8006A978() % 32768 / 32767.0f * 0.2f - 0.1f;
            if (var_fa0 > 0.95f) {
                var_fa0 = 0.95f;
            }
            if (var_fa0 < 0.0f) {
                var_fa0 = 0.0f;
            }
            arg0->unk_1A8 = var_fa0;
        }
        if (D_800F8514 == 0xC) {
            if (arg0->unk_1A8 > 0.8f) {
                arg0->unk_1A8 = 0.8f;
            }
            if (arg0->unk_1A8 < 0.6f) {
                arg0->unk_1A8 = 0.6f;
            }
        }
        if (D_800DCE44 == 0x15) {
            arg0->unk_1A8 = (func_8006A918() % 256 / 255.0f) * 0.2f;
        }
        arg0->unk_1EC = 2500.0f / 27.0f;
        arg0->unk_1E8 = 0.0f;
    }
}

extern s32 D_800CD00C;
extern s16 D_80115DE0;
extern unk_802C4920* D_800E5F40[];
extern s32 D_i3_80141990;
extern s32 D_i3_80141994;
extern f32 D_i3_8013DBF0[];
extern f32 D_i3_8013DC04[];

void func_i3_801175A4(void) {
    f32 temp_fv0;
    s32 temp_a1;
    s32 var_t0;
    s32 var_a3;
    s32 i;
    s32 temp1;
    s16 sp54[30];
    s32 temp2;
    s32 temp_v0;
    s32 temp_t3;
    s32 var_v0_2;

    D_i3_80141910 = gRacers;

    temp_fv0 = D_800F8510->unk_0C * D_800CD00C;
    if ((D_800E5F40[0]->unk_2A8 == 2) && (D_i3_80141904 == 0)) {
        var_a3 = 0;
        var_t0 = 0;
        for (i = 0; i < D_800E5EC0; i++) {
            if (gRacers[i].unk_2A8 >= 2) {
                var_t0++;
                var_a3 += gRacers[i].unk_290[0];
            }
        }

        if (var_t0 != 0) {
            if (D_800CD004 == 5) {
                var_v0_2 = D_i3_8013DC04[D_800CD008] * ((f32) (s32) ((f32) var_a3 / var_t0) * D_800CD00C);
            } else {
                var_v0_2 = D_i3_8013DBF0[D_800CD008] * ((f32) (s32) ((f32) var_a3 / var_t0) * D_800CD00C);
            }
            if (var_v0_2 < D_i3_80141994) {
                D_i3_80141990 = var_v0_2;
                D_i3_80141994 = D_i3_80141990;
            }
            if (var_t0 >= D_80115DE0) {
                D_i3_80141904 = 1;
            }
        }
    }
    if ((D_i3_80141910->unk_2AC == 1) && (D_i3_80141910->unk_2A8 >= 2)) {
        for (i = 0; i < D_800E5EC0; i++) {
            if (D_800E5F40[i]->unk_368 < D_800E5EC0) {
                break;
            }
        }

        if (i < ((D_800E5EC0 * 2) / 3)) {
            if ((D_i3_80141910->unk_23C - D_800E5F40[i]->unk_23C) > 3000.0f) {
                temp_a1 = ((temp_fv0 - D_i3_80141910->unk_23C) / temp_fv0) * 1000.0f;
                temp_a1 += 1000;
                temp2 = ((D_i3_80141910->unk_2A0 / D_i3_80141910->unk_23C) * temp_fv0) + temp_a1;
                if (temp2 < D_i3_80141994) {
                    D_i3_80141990 = temp2;
                }
            }
        }
    }

    for (i = 0; i < D_800E5EC0; i++) {
        sp54[i] = i;
    }

    for (i = 0; i < D_800E5EC0 - 1; i++) {
        for (temp_a1 = i + 1; temp_a1 < D_800E5EC0; temp_a1++) {
            if ((gRacers[sp54[i]].unk_368 > gRacers[sp54[temp_a1]].unk_368) ||
                ((gRacers[sp54[i]].unk_368 == gRacers[sp54[temp_a1]].unk_368) &&
                 (gRacers[sp54[i]].unk_23C < gRacers[sp54[temp_a1]].unk_23C))) {
                temp_t3 = sp54[i];
                sp54[i] = sp54[temp_a1];
                sp54[temp_a1] = temp_t3;
            }
        }
    }

    for (i = 0; i < D_800E5EC0; i++) {
        if (gRacers[sp54[i]].unk_368 <= D_800E5EC0) {
            gRacers[sp54[i]].unk_368 = i + 1;
        }
    }
}

extern f32 D_i3_8013DC18[];

f32 func_i3_801179DC(unk_802C4920* arg0) {
    return D_i3_8013DC18[D_800F8514 * 4 + D_800CD008] * (2500.0f / 27.0f);
}

extern f32 D_i3_8013DFA0[];

f32 func_i3_80117A1C(unk_802C4920* arg0) {
    return D_i3_8013DFA0[D_800F8514 * 4 + D_800CD008];
}

void func_i3_80117A4C(unk_802C4920* arg0, s32 arg1) {
    unk_802C4920* temp_v0 = &gRacers[arg1];

    if ((arg0->unk_368 < D_800E5EC0) && (arg1 < D_800E5EC0)) {
        if (temp_v0->unk_368 < D_800E5EC0) {
            arg0->unk_368 = temp_v0->unk_368;
            arg0->unk_398 = temp_v0->unk_398;

            if (temp_v0->unk_33C < arg0->unk_33C) {
                arg0->unk_33C = temp_v0->unk_33C + 92.0f;
            } else {
                arg0->unk_33C = temp_v0->unk_33C - 92.0f;
            }
            arg0->unk_352 = 255;
        }
    }
}

void func_i3_80117B04(unk_802C4920* arg0, unk_800DCE98* arg1) {
}

void func_i3_80117B10(unk_802C4920* arg0, unk_800DCE98* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141960);
}

void func_i3_80117B38(unk_802C4920* arg0, unk_800DCE98* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141944);
}

void func_i3_80117B60(unk_802C4920* arg0, unk_800DCE98* arg1) {
    func_i3_80117A4C(arg0, D_i3_80141940);
}

void func_i3_80117B88(unk_802C4920* arg0, unk_800DCE98* arg1) {
    if ((arg0->unk_2B4 != 0) && (D_i3_80141910->unk_23C < arg0->unk_23C) && (arg0->unk_04 & 0x04000000)) {
        arg1->unk_7C |= 0x80;
    }
}

void func_i3_80117BD8(unk_802C4920* arg0, unk_800DCE98* arg1) {
}

void func_i3_80117BE4(unk_802C4920* arg0, unk_800DCE98* arg1) {
}

extern u32 D_800CCFE0;
extern s32 D_800CD00C;
extern s8 D_800CD010;
extern s32 D_800F80A8;
extern s32 D_i3_80141908;
extern s32 D_i3_8014190C;
extern s32 D_i3_80141998;
extern unk_8010B7B0 D_8010B7B0;
extern void (*D_i3_8013EC90[])(unk_802C4920*, unk_800DCE98*);
extern f32 D_i3_8013ED10[];
extern f32 D_i3_8013ED1C[];
#ifdef NON_MATCHING
// regalloc (0.0f vs 0.f vs 0?) and missing branch instruction
void func_i3_80117BF0(unk_802C4920* arg0, unk_800DCE98* arg1) {
    f32 spBC;
    s32 temps;
    f32 spB4;
    s32 i;
    s32 pad;
    f32 temp_fa1;
    f32 temp_fv1;
    f32 var_fv0;
    f32 sp9C;
    s32 var_a1;
    f32 sp94;
    f32 temp4;
    f32 temp5;
    f32 temp6;
    s32 var_a3; // sp84
    f32 temp1;
    s32 sp7C;
    f32 temp2;
    bool sp74;
    bool sp70;
    Mtx3F sp4C;
    f32 temp3;
    unk_802C4920* sp44;
    unk_802C4920* sp40;

    if ((arg0->unk_00 & 3) != (D_800CCFE0 % 4) && (D_800DCE44 != 0x11)) {
        arg1->unk_7E = 0;
        arg1->unk_6C = arg0->unk_374;
        arg1->unk_6D = arg0->unk_378;
        arg1->unk_7C = 0;
        arg1->unk_7A = arg0->unk_380;
        return;
    }
    arg1->unk_7A = arg1->unk_7C = arg1->unk_7E = 0;
    if (arg0->unk_2B4 != 0) {
        sp70 = true;
    } else {
        sp70 = false;
    }
    sp44 = arg0->unk_2B8;
    sp40 = arg0->unk_2BC;
    sp94 = ((-arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x) - (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) -
           (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z);
    if (arg0->unk_1F8 < 2.0f) {
        arg0->unk_1F8 = 10.0f;
        arg0->unk_1E0 = 0.108f;
        arg0->unk_1E4 = 0.06f;
        if (arg0->unk_00 >= D_800CD000) {
            arg0->unk_1AC = 0.f;
        }
    }
    if ((D_800DCE44 == 3) || (D_800DCE44 == 4)) {
        if (arg0->unk_00 >= D_800CD000) {
            if (D_800CD000 == 3) {
                var_a1 = 0x1E;
                for (i = 0; i < D_800CD000; i++) {
                    if (gRacers[i].unk_2AC < var_a1) {
                        var_a1 = gRacers[i].unk_2AC;
                        var_a3 = i;
                    }
                }
            } else if (arg0->unk_00 == 2) {
                var_a3 = 0;
            } else {
                var_a3 = 1;
            }

            temp_fv1 = (gRacers[var_a3].unk_23C + arg0->unk_38C) - arg0->unk_23C;
            if (temp_fv1 > 0) {
                arg0->unk_1EC = 69.44444f;
                arg0->unk_1E8 = temp_fv1 * 0.0003f;
                if (arg0->unk_1E8 > 1.0f) {
                    arg0->unk_1E8 = 1.0f;
                }
            } else {
                arg0->unk_1EC = gRacers[var_a3].unk_98 - (temp_fv1 * 0.0002f);
                if ((D_800CD00C == arg0->unk_2A8) &&
                    (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) {
                    arg0->unk_1EC = gRacers[var_a3].unk_98 - (temp_fv1 * 0.002f);
                }
                arg0->unk_1E8 = 0.f;
            }
            if ((D_800CD00C == arg0->unk_2A8) && (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) {
                arg0->unk_1E8 = 0.f;
            }
            arg0->unk_38C = 0.0f;
        }
    }
    if (D_i3_80141998 != 0) {
        if (D_800DCE44 == 2) {
            arg0->unk_1EC = func_i3_801179DC(arg0);
            arg0->unk_1E8 = func_i3_80117A1C(arg0);
        }
    } else if (((D_800CD000 == 1) && (D_i3_80141910->unk_04 & 0x02000000)) || (arg0->unk_04 & 0x02000000) ||
               (arg0->unk_00 < D_800CD000)) {
        arg0->unk_1E8 = 0.f;
        arg0->unk_1EC = (2500.0f / 27.0f);
        arg0->unk_1B4 = 1.00894f;
        arg0->unk_1B0 = 1.156336f;
        arg0->unk_1B8 = 0.119168f;
        arg0->unk_1BC = 36.769516f;
        arg0->unk_1C4 = 1.726068f;
        arg0->unk_1D0 = 0.198282f;
        if ((D_800CD000 == 1) && (D_800E5EC0 != 1) && (arg0->unk_00 != 0) && (D_i3_80141910->unk_04 & 0x02000000)) {
            if ((sp44->unk_00 == 0) && (arg0->unk_2C0 < 2000.0f)) {
                arg0->unk_1EC = (625.0f / 27.0f);
            } else if ((sp40->unk_00 == 0) && (arg0->unk_2C4 < 2000.0f)) {
                arg0->unk_1E8 = 1.0f;
                arg1->unk_7C |= 0x4000;
            }
        }
    } else if ((arg0->unk_274 + arg0->unk_270) < 184.0f) {
        arg0->unk_1E8 = 0.f;
        arg0->unk_1EC = (2500.0f / 27.0f);
    } else if (D_800CD000 == 1) {
        if (arg0->unk_352 != 0xFF) {
            spBC = (gRacers[arg0->unk_352].unk_23C + arg0->unk_38C) - arg0->unk_23C;
            func_i3_80115DF0(D_i3_80141910->unk_23C - arg0->unk_23C);
            if ((func_i3_80115DF0(spBC) < 460.0f) && sp70 && (arg0->unk_2A0 > 1000)) {
                if ((arg0->unk_352 >= D_800CD000) && ((arg0->unk_00 + D_800CCFE0) % 16) < 4) {
                    spB4 = ((-gRacers[arg0->unk_352].unk_0C.unk_28.x * gRacers[arg0->unk_352].unk_24C.z.x) -
                            (gRacers[arg0->unk_352].unk_0C.unk_28.y * gRacers[arg0->unk_352].unk_24C.z.y)) -
                           (gRacers[arg0->unk_352].unk_0C.unk_28.z * gRacers[arg0->unk_352].unk_24C.z.z);
                    if (func_8006A978() % 2) {
                        arg0->unk_33C = spB4 + 23.0f;
                    } else {
                        arg0->unk_33C = spB4 - 23.0f;
                    }
                }
            }
            if (spBC < 2000.0f) {
                arg0->unk_1EC = gRacers[arg0->unk_352].unk_98 + (spBC * 0.01f);
            } else {
                arg0->unk_1EC = (625.0f / 9.0f);
            }
            arg0->unk_1E8 = 1.2f;
            if (sp70 && (arg0->unk_2A0 > 1000) && ((arg0->unk_274 + arg0->unk_270) > 138.0f) &&
                (func_i3_80115DF0(gRacers[arg0->unk_352].unk_23C - arg0->unk_23C) < 184.0f)) {
                spB4 = ((f32) (func_8006A918() % 32768) / 32767.0f) + 0.00001f;

                if (func_i3_80115DF0(gRacers[arg0->unk_352].unk_33C - arg0->unk_33C) < 92.0f) {
                    if (((arg0->unk_352 != 0) && (spB4 < 0.15f) && (arg0->unk_36C & 0x200)) || (spB4 < arg0->unk_360)) {
                        if (arg0->unk_390 == 0) {
                            if (arg0->unk_33C < gRacers[arg0->unk_352].unk_33C) {
                                arg0->unk_390 = 5;
                            } else {
                                arg0->unk_390 = -5;
                            }
                        }
                    } else if ((((arg0->unk_352 != 0) && (spB4 < 0.2f) && (arg0->unk_36C & 0x200)) ||
                                (spB4 < arg0->unk_364)) &&
                               (((D_800CD008 >= 2) && (D_i3_80141910->unk_23C < arg0->unk_23C)) ||
                                ((D_i3_80141910->unk_23C + 138.0f) < arg0->unk_23C))) {
                        if (func_8006A978() % 2) {
                            arg1->unk_7C |= 0x80;
                        } else {
                            arg1->unk_7C |= 0x40;
                        }
                    }
                }
            }
            if (arg0->unk_2A8 == 1) {
                var_fv0 = func_i3_801179DC(arg0);
                if (var_fv0 < arg0->unk_1EC) {
                    arg0->unk_1EC = var_fv0;
                }
                var_fv0 = func_i3_80117A1C(arg0);
                if (var_fv0 < arg0->unk_1E8) {
                    arg0->unk_1E8 = var_fv0;
                }
            }
            if ((u32) (u8) (arg0->unk_00 + D_800CCFE0) < 4) {
                if (arg0->unk_352 < D_800CD000) {
                    arg0->unk_38C =
                        ((func_8006A978() % 32768 / 32767.0f * 400.0f + 30.0f) + 200.0f) - (80 * -D_800CD008 + 240);
                } else {
                    arg0->unk_38C = 30.0f;
                }
            }

            if (((D_800CD00C == arg0->unk_2A8) &&
                 (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) ||
                ((gRacers[arg0->unk_352].unk_368 == 0xFE) && (D_800DCE44 != 2) && (D_800DCE44 != 0x15))) {
                arg0->unk_352 = 255;
                if (arg0->unk_2A8 >= 2) {
                    func_i3_80116A50(arg0);
                }
            }
        } else if ((arg0->unk_2A8 >= 2) || (D_800CD010 == 1)) {
            if ((arg0->unk_398 == 0) || ((u32) (arg0->unk_00 + D_800CCFE0) % 64) < 4) {
                func_i3_80116A50(arg0);
            }

            var_fv0 = (D_800F8510->unk_0C * (D_800CD00C - 1)) / (arg0->unk_398 - arg0->unk_290[0]);
            spBC = (((arg0->unk_2A0 - arg0->unk_290[0]) * var_fv0) + D_800F8510->unk_0C) - arg0->unk_23C;
            spB4 = ((((arg0->unk_2A0 - arg0->unk_290[0]) - 0x11) * var_fv0) + D_800F8510->unk_0C) - arg0->unk_23C;

            var_fv0 = func_i3_80115DF0(D_i3_80141910->unk_23C - arg0->unk_23C);
            arg0->unk_1EC = (spBC * 0.05f) + (spBC - spB4);
            arg0->unk_1E8 = 0.3f;
            if (spBC > 0.0f) {
                if (spBC > 200.0f) {
                    arg0->unk_1E8 = 0.0f;
                    arg1->unk_7C |= 0x4000;
                    if (spBC > 1000.0f) {
                        arg0->unk_1EC = (2500.0f / 27.0f);
                    }
                }
            } else if ((var_fv0 < 2000.0f) && (D_800CD00C == arg0->unk_2A8) &&
                       (((s32) (D_800F8510->unk_08 * 2) / 3) < arg0->unk_0C.unk_00->unk_30)) {
                spBC = D_i3_80141910->unk_98 - 2.3148148f;
                if ((var_fv0 < 0.0f) && (arg0->unk_1EC < spBC)) {
                    arg0->unk_1EC = spBC;
                }
            }
        } else {
            if (arg0->unk_39C != 0) {
                spBC = (arg0->unk_2A0 * (D_800F8510->unk_0C / arg0->unk_39C)) - arg0->unk_23C;
                temp_fa1 = ((arg0->unk_2A0 - 0x11) * (D_800F8510->unk_0C / arg0->unk_39C)) - arg0->unk_23C;
                if (arg0->unk_23C > 0.0f) {
                    arg0->unk_1EC = (spBC * 0.05f) + (spBC - temp_fa1);
                    arg0->unk_1E8 = 1.0f;
                } else {
                    arg0->unk_1EC = (2500.0f / 27.0f);
                    arg0->unk_1E8 = 0.0f;
                }
            } else {
                arg0->unk_1EC = func_i3_801179DC(arg0);
                arg0->unk_1E8 = func_i3_80117A1C(arg0);
            }
        }
    }
    var_a3 = arg0->unk_0C.unk_00->unk_30 * 4;
    if (arg0->unk_0C.unk_08 >= 0.5f) {
        var_a3 += 2;
    }

    if (D_i3_8013DBE8[var_a3] < arg0->unk_1EC) {
        arg0->unk_1EC = D_i3_8013DBE8[var_a3];
    }
    if (((D_80141900 >= 0x15) || (D_800F80A8 >= 0x1F)) && (D_800CD000 == 1) && (arg0->unk_00 != 0) &&
        (arg0->unk_2A0 >= 0x2711) && !(D_i3_80141910->unk_04 & 0x08000000) &&
        (func_i3_80115DF0(D_i3_80141910->unk_33C - sp94) < 138.0f)) {

        var_fv0 = D_i3_80141910->unk_23C - arg0->unk_23C;
        while (var_fv0 > D_800F8510->unk_0C * 0.5f) {
            var_fv0 -= D_800F8510->unk_0C;
        }

        while (var_fv0 < D_800F8510->unk_0C * -0.5f) {
            var_fv0 += D_800F8510->unk_0C;
        }

        if (var_fv0 < 0) {
            var_fv0 = 0.0f - var_fv0;
        }
        if (var_fv0 < 500.0f) {
            if (func_8006A918() % 2) {
                arg1->unk_7C |= 0x80;
            } else {
                arg1->unk_7C |= 0x40;
            }
        }
    }
    if (D_800F8514 == 0xC) {
        sp7C = arg0->unk_0C.unk_00->unk_30;
        if ((sp7C >= 4) && (sp7C < 0x10)) {
            arg0->unk_1EC = (2500.0f / 27.0f);
            arg0->unk_1E8 = 1.0f;
        }
    }
    arg1->unk_7A |= 0x8000;
    if (arg0->unk_340 < arg0->unk_20C) {
        arg1->unk_7C |= 0x8000;
    }

    sp74 = false;
    if ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) == 0x80) {
        if ((arg0->unk_0C.unk_00->unk_34->unk_34->unk_34->unk_20 & 0x1C0) != 0x80) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        } else if ((arg0->unk_0C.unk_00->unk_34->unk_34->unk_20 & 0x1C0) != 0x80) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        } else if ((arg0->unk_0C.unk_00->unk_34->unk_20 & 0x1C0) != 0x80) {
            sp74 = true;
            arg0->unk_330 = 10.0f;
        }
    }

    if (func_8009D16C(&arg0->unk_0C, arg0->unk_0C.unk_34.x + (arg0->unk_330 * arg0->unk_74.x),
                      arg0->unk_0C.unk_34.y + (arg0->unk_330 * arg0->unk_74.y),
                      arg0->unk_0C.unk_34.z + (arg0->unk_330 * arg0->unk_74.z), &sp4C) == 0) {
        if (((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0x80) && ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0xC0)) {
            temp4 = arg0->unk_C0.x.x;
            temp5 = arg0->unk_C0.x.y;
            temp6 = arg0->unk_C0.x.z;
            if (D_800DCE44 == 0x11) {
                arg0->unk_33C = D_i3_8013ED1C[arg0->unk_00] * 46.0f;
                if (arg0->unk_00 != 0) {
                    temp3 = ((gRacers[0].unk_23C - D_i3_8013ED10[arg0->unk_00]) - arg0->unk_23C);
                    arg0->unk_1EC = gRacers[0].unk_98 + (temp3 * 0.1f);
                    arg0->unk_1E8 = 1.0f;
                }
            }
            temp1 = (arg0->unk_338 * (((arg0->unk_33C + (arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x)) +
                                       (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) +
                                      (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z))) *
                    1.2f;
            temp1 += (arg0->unk_334 * ((temp4 * sp4C.z.x) + (temp5 * sp4C.z.y) + (temp6 * sp4C.z.z)) * 1.2f);
            var_a3 = func_8006A9E0(temp1);
        } else if (!sp74) {
            var_a3 = func_8006A9E0(-arg0->unk_334 * ((arg0->unk_C0.z.x * sp4C.x.x) + (arg0->unk_C0.z.y * sp4C.x.y) +
                                                     (arg0->unk_C0.z.z * sp4C.x.z)));
            if (!(func_8006A978() % 64)) {
                if (func_8006A918() % 2) {
                    arg0->unk_370 = (func_8006A978() % 16) + 20;
                } else {
                    arg0->unk_370 = -20 - (func_8006A918() % 16);
                }
            }

            if (arg0->unk_370 != 0) {
                var_a3 += (s32) (arg0->unk_334 / 20.0f);
                arg0->unk_370--;
            }
        } else {
            arg0->unk_370 = 0;
            temp1 = (arg0->unk_338 * DOT_XYZ(&arg0->unk_C0.z, &arg0->unk_24C.y) * 160.0f);
            var_a3 = func_8006A9E0(temp1 - (arg0->unk_334 * 0.5f *
                                            ((arg0->unk_C0.z.x * sp4C.x.x) + (arg0->unk_C0.z.y * -sp4C.x.y) +
                                             (arg0->unk_C0.z.z * sp4C.x.z))));
        }
        if (arg0->unk_04 & 0x04000000) {
            var_a1 = func_8006A9E0(-arg0->unk_334 * 0.1f * DOT_XYZ(&arg0->unk_C0.y, &sp4C.x));

            if (D_800F8514 == 0xC) {
                if ((arg0->unk_0C.unk_00->unk_30 >= 7) && (arg0->unk_0C.unk_00->unk_30 < 0xF)) {
                    if (arg0->unk_A0 > 400.0f) {
                        var_a3 = 0;
                    }
                    var_a1 = (s32) ((var_a1 * 0.25f) - (arg0->unk_A0 * 0.015f));
                    var_a3 *= 5;
                }
            }

            if (var_a1 < -0x46) {
                var_a1 = -0x46;
            } else if (var_a1 >= 0x47) {
                var_a1 = 0x46;
            }
            var_a3 /= 5;
            if (((arg0->unk_0C.unk_00->unk_20 & 0x1C0) == 0xC0) ||
                ((arg0->unk_0C.unk_00->unk_34->unk_20 & 0x1C0) == 0x180) ||
                ((arg0->unk_0C.unk_00->unk_34->unk_34->unk_20 & 0x1C0) == 0x180)) {
                var_a1 = 0x46;
                arg1->unk_7A &= 0x7FFF;
                arg1->unk_7C &= 0x7FFF;
                arg1->unk_7E &= 0x7FFF;
            }

            if (arg0->unk_33C > 0.0f) {
                arg0->unk_33C -= arg0->unk_354;
            } else {
                arg0->unk_33C += arg0->unk_354;
            }
            arg0->unk_1EC = (2500.0f / 27.0f);
            if (arg0->unk_1E8 >= 1.0f) {
                arg0->unk_1E8 = 1.0f;
            }
        } else {
            var_a1 = 0x46;
            if (((arg0->unk_0C.unk_00->unk_34->unk_20 & 0x1C0) == 0x180) && (arg0->unk_0C.unk_08 > 0.5f)) {
                arg0->unk_1EC = 69.44444f;
            }
        }
        if (var_a3 < -0x46) {
            var_a3 = -0x46;
            arg1->unk_7A |= 0x2000;
        } else if (var_a3 >= 0x47) {
            var_a3 = 0x46;
            arg1->unk_7A |= 0x10;
        }
        arg1->unk_6C = (var_a3 * 5) / 8;
        arg1->unk_6D = var_a1;
        if (D_800CD000 == 1) {
            if (sp70 && (arg0->unk_2A0 > 1000) && (D_800CD008 >= 2) && (arg0->unk_00 != 0) && (D_800E5EC0 != 1) &&
                (arg0->unk_36C & 0x200)) {
                if ((arg0->unk_2C4 < 23.0f) &&
                    (((D_800CD008 >= 2) && (D_i3_80141910->unk_23C < arg0->unk_23C)) ||
                     ((D_i3_80141910->unk_23C + 138.0f) < arg0->unk_23C)) &&
                    ((func_8006A978() % 32768) < 16)) {
                    if (func_8006A978() % 2) {
                        arg1->unk_7C |= 0x80;
                    } else {
                        arg1->unk_7C |= 0x40;
                    }
                }
                if ((arg0->unk_2C4 < 23.0f) && (func_i3_80115DF0(sp40->unk_33C - arg0->unk_33C) < 138.0f) &&
                    (arg0->unk_390 == 0) && (((f32) (func_8006A918() % 32768) / 32767.0f) < 0.01f)) {
                    if (arg0->unk_33C < sp40->unk_33C) {
                        arg0->unk_390 = 5;
                    } else {
                        arg0->unk_390 = -5;
                    }
                }
            }

            if (arg0->unk_390 < 0) {
                arg0->unk_390++;
                if (((arg0->unk_390 == -3) || (arg0->unk_390 == -1)) &&
                    ((D_800CD008 >= 2) || (func_i3_80115DF0(D_i3_80141910->unk_23C - arg0->unk_23C) > 184.0f)) &&
                    (D_i3_80141910->unk_23C < arg0->unk_23C)) {
                    arg1->unk_7C |= 0x2000;
                }
            } else if (arg0->unk_390 > 0) {
                arg0->unk_390--;
                if (((arg0->unk_390 == 3) || (arg0->unk_390 == 1)) &&
                    ((D_800CD008 >= 2) || ((arg0->unk_23C - D_i3_80141910->unk_23C) > 184.0f)) &&
                    (D_i3_80141910->unk_23C < arg0->unk_23C)) {
                    arg1->unk_7C |= 0x10;
                }
            }
            if (!(func_8006A978() % 2048)) {
                arg0->unk_36C &= ~0xC00;
            }
        }
        if (arg0->unk_04 & 1) {
            arg0->unk_394 = 0xB4;
        }

        if (arg0->unk_394 > 0) {
            arg0->unk_394--;
        }

        var_a3 = arg0->unk_0C.unk_00->unk_30;
        if (var_a3 != arg0->unk_358) {
            arg0->unk_344 = D_8010B7B0.unk_6E0[var_a3];
            arg0->unk_345 = D_8010B7B0.unk_6A0[var_a3];
            arg0->unk_346 = D_8010B7B0.unk_620[var_a3];
            arg0->unk_347 = D_8010B7B0.unk_660[var_a3];
            arg0->unk_348 = D_8010B7B0.unk_5A0[var_a3];
            if (D_800CD008 >= 2) {
                arg0->unk_349 = D_8010B7B0.unk_5E0[var_a3];
            } else {
                arg0->unk_349 = -1;
            }

            arg0->unk_35C = arg0->unk_0C.unk_00->unk_20 & 0x38000;
            arg0->unk_358 = var_a3;

            if (++var_a3 >= D_800F8510->unk_08) {
                var_a3 = 0;
            }
            arg0->unk_34A = D_8010B7B0.unk_6E0[var_a3];
            arg0->unk_34B = D_8010B7B0.unk_620[var_a3];
            arg0->unk_34C = D_8010B7B0.unk_5E0[var_a3];
            arg0->unk_34E = 6;
            if (arg0->unk_344 != -1) {
                arg0->unk_34E = 5;
            }
            if (arg0->unk_346 != -1) {
                arg0->unk_34E = 4;
            }
            if (arg0->unk_348 != -1) {
                arg0->unk_34E = 3;
            }
            if (arg0->unk_345 == 1) {
                arg0->unk_34E = 2;
            }
            if (arg0->unk_345 == 2) {
                arg0->unk_34E = 1;
            }
        }

        if (arg0->unk_36C & 0x800) {
            var_a3 = (arg0->unk_0C.unk_00->unk_20 & 0x1C0);
            if ((var_a3 == 0x80) || (var_a3 == 0xC0)) {
                if (arg0->unk_2C8 & 1) {
                    arg1->unk_6C += 0x2A;
                    if (arg1->unk_6C >= 0x47) {
                        arg1->unk_6C = 0x46;
                    }
                } else {
                    arg1->unk_6C -= 0x2A;
                    if (arg1->unk_6C < -0x46) {
                        arg1->unk_6C = -0x46;
                    }
                }
            } else {
                var_a3 = (u32) ((arg0->unk_2C8 * 5) + D_800CCFE0) % 280U;
                if (var_a3 >= 0x8D) {
                    var_a3 = -var_a3;
                }
                if (var_a3 >= 0x47) {
                    var_a3 = 0x8C - var_a3;
                }
                if (var_a3 < -0x46) {
                    var_a3 = -0x8C - var_a3;
                }
                arg1->unk_6C = var_a3;
                if (D_i3_80141910->unk_23C < arg0->unk_23C) {
                    if (func_8006A978() % 2) {
                        arg1->unk_7C |= 0x80;
                    } else {
                        arg1->unk_7C |= 0x40;
                    }
                }
            }
        } else {
            if (((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0x80) && ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0xC0) &&
                (D_800DCE44 != 0x11)) {
                if ((D_800F8514 < 0x18) && (((arg0->unk_2A0 >= 0x7D1) &&
                                             (((arg0->unk_368 % 6) < 2) ||
                                              (func_i3_80115DF0(arg0->unk_23C - D_i3_80141910->unk_23C) > 5000.0f))) ||
                                            (arg0->unk_00 < D_800CD000))) {
                    var_a3 = arg0->unk_0C.unk_00->unk_30 * 4;
                    if (arg0->unk_0C.unk_08 >= 0.5f) {
                        var_a3 += 2;
                    }
                    var_a1 = var_a3 + 2;
                    if (var_a1 >= (D_800F8510->unk_08 * 4)) {
                        var_a1 = 0;
                    }
                    sp7C = D_i3_8013DBE8[var_a3 + 1];
                    temps = D_i3_8013DBE8[var_a1 + 1];
                    spBC = (temps - sp7C) * arg0->unk_0C.unk_08 + sp7C;
                    if (D_800E5EC0 != 1) {
                        if (sp44->unk_00 != arg0->unk_352) {
                            if ((arg0->unk_2C0 < 92.0f) && (func_i3_80115DF0(sp44->unk_33C - spBC) < 69.0f)) {
                                if (spBC < sp44->unk_33C) {
                                    arg0->unk_33C = spBC - 92.0f;
                                } else {
                                    arg0->unk_33C = spBC + 92.0f;
                                }
                            } else {
                                arg0->unk_33C = spBC;
                            }
                        }
                    } else {
                        arg0->unk_33C = spBC;
                    }
                    if ((var_a3 != arg0->unk_358) && (sp7C & 1) && (arg0->unk_00 < D_800CD000)) {
                        var_fv0 = arg0->unk_228 / arg0->unk_22C;
                        if (var_fv0 > 0.3f) {
                            arg1->unk_7C |= 0xC000;
                        }
                        arg0->unk_358 = arg0->unk_0C.unk_00->unk_30;
                    }
                    arg0->unk_388 = var_a3;
                    arg0->unk_330 = 0.1f;
                } else {
                    arg0->unk_330 = arg0->unk_98 * 0.1f;
                    sp9C = (arg0->unk_274 - arg0->unk_270) * 0.5f;
                    var_fv0 = arg0->unk_228 / arg0->unk_22C;
                    switch (arg0->unk_34E) {
                        case 1:
                            if (D_800F8514 != 0x11) {
                                if (arg0->unk_33C < sp9C + 92.0f) {
                                    arg0->unk_33C = sp9C + 92.0f;
                                }
                            } else {
                                if (arg0->unk_33C > sp9C - 230.0f) {
                                    arg0->unk_33C = sp9C - 230.0f;
                                }
                            }
                            break;
                        case 2:
                            if (D_800F8514 != 0x11) {
                                if (arg0->unk_33C > sp9C - 230.0f) {
                                    arg0->unk_33C = sp9C - 230.0f;
                                }
                            } else {
                                if (arg0->unk_33C < sp9C + 92.0f) {
                                    arg0->unk_33C = sp9C + 92.0f;
                                }
                            }
                            break;
                        case 3:
                            if ((arg0->unk_348 == 0) && (var_fv0 < 0.99f)) {
                                arg0->unk_33C = ((-arg0->unk_0C.unk_28.x * arg0->unk_24C.z.x) -
                                                 (arg0->unk_0C.unk_28.y * arg0->unk_24C.z.y)) -
                                                (arg0->unk_0C.unk_28.z * arg0->unk_24C.z.z);

                                if (func_i3_80115DF0(sp9C - arg0->unk_33C) < 146.0f) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C += arg0->unk_354 * 10.0f;
                                    } else {
                                        arg0->unk_33C -= arg0->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((arg0->unk_348 == 1) && (var_fv0 < 0.99f)) {
                                arg0->unk_33C = sp94;
                                if ((D_800DCE44 == 0x15) && (arg0->unk_00 >= D_800CD000)) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += (arg0->unk_354 * 10.0f);
                                    }
                                } else {
                                    if (arg0->unk_33C > ((sp9C - 100.0f) - 46.0f)) {
                                        arg0->unk_33C -= arg0->unk_354 * 10.0f;
                                    }
                                }
                                break;
                            }

                            if ((arg0->unk_348 == 2) && ((arg0->unk_2A8 == 1) || (var_fv0 < 0.99f))) {
                                arg0->unk_33C = sp94;
                                if (arg0->unk_33C < (sp9C + 100.0f + 46.0f)) {
                                    arg0->unk_33C += arg0->unk_354 * 10.0f;
                                }
                                break;
                            }
                            /* fallthrough */
                        case 4:
                            if ((arg0->unk_346 != -1) && (arg0->unk_36C & 4)) {
                                if ((arg0->unk_346 == 0) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 4.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_346 == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                    break;
                                }

                                if (arg0->unk_346 == 1) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += arg0->unk_354 * 4.0f;
                                        goto block_359;
                                    }
                                }
                                if (arg0->unk_346 == 3) {
                                    if (func_i3_80115DF0(sp9C - arg0->unk_33C) > 146.0f) {
                                        if (arg0->unk_33C < sp9C) {
                                            arg0->unk_33C -= arg0->unk_354 * 4.0f;
                                        } else {
                                            arg0->unk_33C += arg0->unk_354 * 4.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            /* fallthrough */
                        case 5:
                        block_359:
                            if (arg0->unk_344 != -1) {
                                if ((arg0->unk_344 == 2) && (arg0->unk_33C > (sp9C - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                } else if ((arg0->unk_344 == 1) && (arg0->unk_33C < (sp9C + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }
                            }
                            /* fallthrough */
                        case 6:
                            if ((D_800E5EC0 != 1) && (sp44->unk_00 != arg0->unk_352) && (arg0->unk_2C0 < 92.0f) &&
                                (func_i3_80115DF0(sp44->unk_33C - arg0->unk_33C) < 92.0f)) {
                                if ((arg0->unk_33C > 0.0f) && (arg0->unk_274 < (arg0->unk_33C + 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354;
                                    break;
                                }
                                if ((arg0->unk_33C < 0.0f) && ((46.0f - arg0->unk_33C) < arg0->unk_270)) {
                                    arg0->unk_33C += arg0->unk_354;
                                    break;
                                }
                                if (sp44->unk_33C < arg0->unk_33C) {
                                    arg0->unk_33C += arg0->unk_354;
                                    break;
                                }

                                arg0->unk_33C -= arg0->unk_354;
                                break;
                            }

                            if ((arg0->unk_349 != -1) && (arg0->unk_36C & 1)) {
                                if ((arg0->unk_349 == 0) && (arg0->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_80115DF0(arg0->unk_33C - sp9C) < 230.0f)) {
                                    arg0->unk_33C = sp9C;
                                    break;
                                }
                                if ((arg0->unk_349 == 1) && (arg0->unk_0C.unk_08 < 0.8f) &&
                                    (func_i3_80115DF0(arg0->unk_33C - ((-1.0f * arg0->unk_270) + 100.0f)) < 230.0f)) {
                                    arg0->unk_33C = (arg0->unk_270 * -1.0f) + 100.0f;
                                    break;
                                }
                                if ((arg0->unk_349 == 2) && (arg0->unk_0C.unk_08 < 0.8f)) {
                                    if (func_i3_80115DF0(arg0->unk_33C - (arg0->unk_274 - 100.0f)) < 230.0f) {
                                        arg0->unk_33C = arg0->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }
                            if ((arg0->unk_347 != -1) && (arg0->unk_36C & 1)) {
                                if ((arg0->unk_347 == 0) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (sp9C < arg0->unk_33C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_347 == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                }

                                if ((arg0->unk_347 == 1) && (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }

                                if ((arg0->unk_347 == 3) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 146.0f)) {
                                    if (arg0->unk_33C < sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }
                            }

                            if ((arg0->unk_34B != -1) && (arg0->unk_36C & 0x10)) {
                                if ((arg0->unk_34B == 0) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 77.0f)) {
                                    if (arg0->unk_33C > sp9C) {
                                        arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    } else {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    }
                                    break;
                                }

                                if ((arg0->unk_34B == 2) && (arg0->unk_33C > ((sp9C + 100.0f) - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                }
                                if (arg0->unk_34B == 1) {
                                    if (arg0->unk_33C < ((sp9C - 100.0f) + 46.0f)) {
                                        arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    } else {
                                        goto block_429;
                                    }
                                } else {
                                block_429:
                                    if ((arg0->unk_34B == 3) && (func_i3_80115DF0(sp9C - arg0->unk_33C) > 146.0f)) {
                                        if (arg0->unk_33C < sp9C) {
                                            arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                        } else {
                                            arg0->unk_33C += arg0->unk_354 * 3.0f;
                                        }
                                        break;
                                    }
                                }
                            }
                            if ((arg0->unk_34A != -1) && (arg0->unk_36C & 8)) {
                                if ((arg0->unk_34A == 2) && (arg0->unk_33C > (sp9C - 46.0f))) {
                                    arg0->unk_33C -= arg0->unk_354 * 3.0f;
                                    break;
                                } else if ((arg0->unk_34A == 1) && (arg0->unk_33C < (sp9C + 46.0f))) {
                                    arg0->unk_33C += arg0->unk_354 * 3.0f;
                                    break;
                                }
                            }

                            if ((arg0->unk_34C != -1) && (arg0->unk_36C & 0x20)) {
                                if ((arg0->unk_34C == 0) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                    (func_i3_80115DF0(arg0->unk_33C - sp9C) < 230.0f)) {
                                    arg0->unk_33C = sp9C;
                                    break;
                                } else {
                                    if ((arg0->unk_34C == 1) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_80115DF0(arg0->unk_33C - ((-1.0f * arg0->unk_270) + 100.0f)) <
                                         230.0f)) {
                                        arg0->unk_33C = (arg0->unk_270 * -1.0f) + 100.0f;
                                        break;
                                    }
                                    if ((arg0->unk_34C == 2) && (arg0->unk_0C.unk_08 < 0.5f) &&
                                        (func_i3_80115DF0(arg0->unk_33C - (arg0->unk_274 - 100.0f)) < 230.0f)) {
                                        arg0->unk_33C = arg0->unk_274 - 100.0f;
                                        break;
                                    }
                                }
                            }

                            if ((arg0->unk_2A0 >= 0x7D1) && !(func_8006A918() & 0x7F0)) {
                                if (!(func_8006A918() % 2)) {
                                    arg0->unk_33C -= 46.0f;
                                } else {
                                    arg0->unk_33C += 46.0f;
                                }
                            }
                            break;
                    }
                }
            }
        }
        D_i3_8013EC90[arg0->unk_2C8](arg0, arg1);
        if ((D_800CD000 == 1) && (arg0->unk_00 != 0)) {
            var_fv0 = arg0->unk_23C - D_i3_80141910->unk_23C;
            if ((var_fv0 > -230.0f) && (var_fv0 < -11.5f) &&
                (func_i3_80115DF0(sp94 - D_i3_80141910->unk_33C) < 92.0f)) {
                if (D_i3_80141910->unk_33C < sp94) {
                    arg0->unk_33C = D_i3_80141910->unk_33C + 92.0f;
                } else {
                    arg0->unk_33C = D_i3_80141910->unk_33C - 92.0f;
                }
            }
        }

        if ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) == 0x100) {
            spBC = 92.0f;
        } else if ((arg0->unk_0C.unk_00->unk_20 & 0x1C0) != 0x1C0) {
            if (arg0->unk_35C == 0x8000) {
                spBC = 23.0f;
            } else {
                spBC = 50.600002f;
            }
        } else {
            spBC = 92.0f;
        }
        if ((arg0->unk_35C == 0x18000) || ((arg0->unk_35C == 0x20000) && (arg0->unk_0C.unk_08 > 0.6f)) ||
            ((arg0->unk_35C == 0x28000) && (arg0->unk_0C.unk_08 < 0.4f))) {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + spBC)) {
                    arg0->unk_33C = (arg0->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + (spBC * 0.5f))) {
                    arg0->unk_33C = arg0->unk_274 - (spBC * 0.5f);
                }
            }
        } else if ((arg0->unk_35C == 0x10000) || ((arg0->unk_35C == 0x20000) && (arg0->unk_0C.unk_08 < 0.4f)) ||
                   ((arg0->unk_35C == 0x28000) && (arg0->unk_0C.unk_08 > 0.6f))) {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + (spBC * 0.5f))) {
                    arg0->unk_33C = (arg0->unk_270 - (spBC * 0.5f)) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + spBC)) {
                    arg0->unk_33C = arg0->unk_274 - spBC;
                }
            }
        } else {
            if (arg0->unk_33C < 0.0f) {
                if (arg0->unk_270 < ((arg0->unk_33C * -1.0f) + spBC)) {
                    arg0->unk_33C = (arg0->unk_270 - spBC) * -1.0f;
                }
            } else {
                if (arg0->unk_274 < (arg0->unk_33C + spBC)) {
                    arg0->unk_33C = arg0->unk_274 - spBC;
                }
            }
        }
        if ((D_800CD000 == 1) && (arg0->unk_00 != 0)) {
            var_fv0 = D_i3_80141910->unk_23C - arg0->unk_23C;
            if ((var_fv0 > 0.0f) && (var_fv0 < spBC) &&
                (func_i3_80115DF0(D_i3_80141910->unk_33C - arg0->unk_33C) < 69.0f)) {
                if (D_i3_80141910->unk_98 < arg0->unk_1EC) {
                    arg0->unk_1EC = D_i3_80141910->unk_98;
                }
            }
        }
        if (arg0->unk_1EC < (625.0f / 27.0f)) {
            arg0->unk_1EC = (625.0f / 27.0f);
        }
        if ((arg0->unk_04 & 0x02000000) || (D_800DCE44 == 0x11)) {
            arg0->unk_36C &= ~0xA00;
            if (arg0->unk_00 < D_800CD000) {
                arg1->unk_7C &= ~0x4000;
            }
            if (D_i3_80141908 != 0) {
                // FAKE!
                if (1) {}
                var_a1 = 0;
                for (i = 0; i < D_800E5EC0; i++) {
                    if (gRacers[i].unk_35C == 0x8000) {
                        var_a1++;
                    }
                }

                if (var_a1 == D_800E5EC0) {
                    if (arg0->unk_00 == 0) {
                        D_i3_8014190C++;
                    }
                    if (D_i3_8014190C > 60) {
                        arg0->unk_1EC = arg0->unk_98 * 0.1f;
                        arg1->unk_7A |= 4;
                        arg1->unk_7A &= 0x7FFF;
                        arg1->unk_7C &= 0x7FFF;
                        arg1->unk_7E &= 0x7FFF;
                    }
                }
            }
            if (arg0->unk_36C & 0x1000) {
                arg1->unk_7A |= 4;
                arg1->unk_7A &= 0x7FFF;
                arg1->unk_7C &= 0x7FFF;
                arg1->unk_7E &= 0x7FFF;
            }
        }
        arg0->unk_374 = arg1->unk_6C;
        arg0->unk_378 = arg1->unk_6D;
        arg0->unk_37C = arg1->unk_7C;
        arg0->unk_380 = arg1->unk_7A;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i3/A90C0/func_i3_80117BF0.s")
void func_i3_80117BF0(unk_802C4920* arg0, unk_800DCE98* arg1);
#endif

extern s32 D_i3_801419B0;
extern s32 D_i3_801419B4;

void func_i3_8011AE70(void) {
    D_i3_801419B0 = D_i3_801419B4 = 0;
}

extern s32 D_i3_801419A8;
extern s32 D_i3_801419AC;

void func_i3_8011AE88(void) {
    D_i3_801419A8 = D_i3_801419AC = 0;
}
