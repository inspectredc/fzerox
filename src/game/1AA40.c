#include "global.h"

void func_80080A40(unk_800E51B8** arg0) {
    *arg0 = NULL;
}

s32 D_800E51B0;
unk_800E51B8 D_800E51B8[3];

void func_80080A48(void) {
    s32 i;
    unk_800E51B8* var_v1;

    D_800E51B0 = 0;

    for (i = 0, var_v1 = D_800E51B8; i < 3; i++, var_v1++) {
        var_v1->unk_00 = 0;
        var_v1->unk_04 = -1;
        var_v1->unk_18 = var_v1->unk_1A = 0;
        var_v1->unk_06 = var_v1->unk_08 = var_v1->unk_0A = var_v1->unk_0C = var_v1->unk_0E = var_v1->unk_10 =
            var_v1->unk_12 = 0;
    }
}

unk_800E51B8* func_80080AA8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u16 arg5, unk_800E51B8_unk_1C_func arg6) {
    s32 var_v0;
    s32 i;
    unk_800E51B8* var_v1;
    s64 one = 1;

    for (i = 0, var_v1 = D_800E51B8; i < 3; i++, var_v1++) {
        if (arg0 == var_v1->unk_04) {
            return NULL;
        }
    }

    for (i = 0, var_v1 = D_800E51B8; i < 3; i++, var_v1++) {
        if (var_v1->unk_04 == -1) {
            break;
        }
    }

    if (i == 3) {
        return NULL;
    }
    D_800E51B0++;
    var_v1->unk_00 = one;
    var_v1->unk_04 = arg0;
    var_v1->unk_06 = 0;
    var_v1->unk_08 = arg1 + (arg3 / 2);
    var_v1->unk_0A = arg2 + ((s32) (arg4 - 2) / 2);
    var_v1->unk_0C = arg1;
    var_v1->unk_0E = arg2;
    var_v1->unk_10 = 0;
    var_v1->unk_12 = 2;
    var_v1->unk_14 = arg3;
    var_v1->unk_16 = arg4;
    var_v1->unk_18 = GPACK_RGBA5551(0, 0, 0, 1);
    var_v1->unk_1A = arg5;
    var_v1->unk_1C = arg6;
    return var_v1;
}

void func_80080BDC(unk_800E51B8* arg0) {
    arg0->unk_00 = 4;
    arg0->unk_06 = 0;
    arg0->unk_0C = arg0->unk_08;
    arg0->unk_0E = arg0->unk_0A;
    arg0->unk_14 = arg0->unk_10;
    arg0->unk_16 = arg0->unk_12;
}

void func_80080C0C(void) {
    s32 i;
    unk_800E51B8* var_v1;
    f32 temp1;

    for (i = 0, var_v1 = D_800E51B8; i < 3; i++, var_v1++) {
        if (var_v1->unk_04 == -1) {
            continue;
        }

        switch (var_v1->unk_00) {
            case 1:
                var_v1->unk_06++;
                temp1 = (var_v1->unk_06 / 10.0f);

                var_v1->unk_08 = var_v1->unk_0C + ((s16) ((var_v1->unk_14 / 2.0f) * (1.0f - temp1)));
                var_v1->unk_10 = var_v1->unk_14 * temp1;

                if (var_v1->unk_06 >= 10) {
                    var_v1->unk_00 = 2;
                    var_v1->unk_06 = 0;
                    var_v1->unk_10 = var_v1->unk_14;
                    var_v1->unk_08 = var_v1->unk_0C;
                }
                break;
            case 2:
                var_v1->unk_06++;
                temp1 = (var_v1->unk_06 / 10.0f);

                var_v1->unk_0A = var_v1->unk_0E + (s16) (((var_v1->unk_16 - 2) / 2.0f) * (1.0f - temp1));
                var_v1->unk_12 = (s16) ((var_v1->unk_16 - 2) * temp1) + 2;

                if (var_v1->unk_06 >= 10) {
                    var_v1->unk_00 = 3;
                    var_v1->unk_06 = 0;
                    var_v1->unk_12 = var_v1->unk_16;
                    var_v1->unk_0A = var_v1->unk_0E;
                }
                break;
            case 3:
                break;
            case 4:
                var_v1->unk_06++;
                temp1 = (var_v1->unk_06 / 10.0f);

                var_v1->unk_0A = var_v1->unk_0E + (s16) (((var_v1->unk_16 - 2) / 2.0f) * temp1);
                var_v1->unk_12 = (var_v1->unk_16 - 2) * (1.0f - temp1);

                if (var_v1->unk_06 >= 10) {
                    var_v1->unk_00 = 5;
                    var_v1->unk_06 = 0;
                    var_v1->unk_12 = 2;
                    var_v1->unk_0A = var_v1->unk_0E + ((var_v1->unk_16 - 2) / 2);
                }
                break;
            case 5:
                var_v1->unk_06++;
                temp1 = (var_v1->unk_06 / 10.0f);

                var_v1->unk_08 = var_v1->unk_0C + (s16) ((var_v1->unk_14 / 2.0f) * temp1);
                var_v1->unk_10 = var_v1->unk_14 * (1.0f - temp1);

                if (var_v1->unk_06 >= 11) {
                    var_v1->unk_00 = 0;
                    var_v1->unk_04 = -1;
                    D_800E51B0--;
                }
                break;
        }
    }
}

extern Gfx D_80149A0[];

Gfx* func_80080E90(Gfx* gfx) {
    s32 i;
    unk_800E51B8* var_s0;

    for (i = 0, var_s0 = D_800E51B8; i < 3; i++, var_s0++) {
        if (var_s0->unk_04 == -1) {
            continue;
        }
        gSPDisplayList(gfx++, D_80149A0);
        gDPSetFillColor(gfx++, var_s0->unk_1A << 16 | var_s0->unk_1A);
        gDPFillRectangle(gfx++, var_s0->unk_08, var_s0->unk_0A, ((var_s0->unk_08 + var_s0->unk_10) - 1),
                         ((var_s0->unk_0A + var_s0->unk_12) - 1));

        gDPPipeSync(gfx++);
        gDPSetFillColor(gfx++, var_s0->unk_18 << 16 | var_s0->unk_18);
        gDPFillRectangle(gfx++, var_s0->unk_08 + 1, var_s0->unk_0A + 1, ((var_s0->unk_08 + var_s0->unk_10) - 2),
                         ((var_s0->unk_0A + var_s0->unk_12) - 2));

        if ((var_s0->unk_1C != NULL) && (var_s0->unk_00 == 3)) {
            gfx = var_s0->unk_1C(gfx, var_s0->unk_08, var_s0->unk_0A);
        }
    }
    return gfx;
}

bool func_8008108C(unk_800E51B8* arg0, s32 arg1) {
    bool ret = false;

    switch (arg1) {
        case 0:
            ret = ((arg0 != NULL) && (arg0->unk_00 != 0)) ? true : false;
            break;
        case 1:
            ret = (arg0->unk_00 == 3) ? true : false;
            break;
        default:
            break;
    }

    return ret;
}
