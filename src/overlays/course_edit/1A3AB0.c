#include "global.h"

// clang-format off
UNUSED Mtx D_xk2_80104D10 = gdSPDefMtx(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
);

UNUSED Mtx D_xk2_80104D50 = gdSPDefMtx(
    -1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
);

UNUSED Mtx D_xk2_80104D90 = gdSPDefMtx(
    0.1f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.1f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.1f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
);
// clang-format on

void func_xk2_800F1FF0(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    MtxF* var_a3;
    s32 i;
    MtxF sp10;
    s32 var_t0 = 0;

    var_a3 = &sp10;
    // FAKE var_t0
    for (i = 0; i != 4; i++) {
        var_a3->m[i][0] = (arg0->m[i][0] * arg1->m[0][var_t0 + 0]) + (arg0->m[i][1] * arg1->m[1][var_t0 + 0]) +
                          (arg0->m[i][2] * arg1->m[2][var_t0 + 0]) + (arg0->m[i][3] * arg1->m[3][var_t0 + 0]);
        var_a3->m[i][1] = (arg0->m[i][0] * arg1->m[0][var_t0 + 1]) + (arg0->m[i][1] * arg1->m[1][var_t0 + 1]) +
                          (arg0->m[i][2] * arg1->m[2][var_t0 + 1]) + (arg0->m[i][3] * arg1->m[3][var_t0 + 1]);
        var_a3->m[i][2] = (arg0->m[i][0] * arg1->m[0][var_t0 + 2]) + (arg0->m[i][1] * arg1->m[1][var_t0 + 2]) +
                          (arg0->m[i][2] * arg1->m[2][var_t0 + 2]) + (arg0->m[i][3] * arg1->m[3][var_t0 + 2]);
        var_a3->m[i][3] = (arg0->m[i][0] * arg1->m[0][var_t0 + 3]) + (arg0->m[i][1] * arg1->m[1][var_t0 + 3]) +
                          (arg0->m[i][2] * arg1->m[2][var_t0 + 3]) + (arg0->m[i][3] * arg1->m[3][var_t0 + 3]);
    }

    for (i = 0; i != 4; i++) {
        arg2->m[i][0] = var_a3->m[i][0];
        arg2->m[i][1] = var_a3->m[i][1];
        arg2->m[i][2] = var_a3->m[i][2];
        arg2->m[i][3] = var_a3->m[i][3];
    }
}

void func_xk2_800F21A4(MtxF* arg0, MtxF* arg1) {
    arg1->m[0][0] = arg0->m[0][0];
    arg1->m[0][1] = arg0->m[0][1];
    arg1->m[0][2] = arg0->m[0][2];
    arg1->m[0][3] = arg0->m[0][3];
    arg1->m[1][0] = arg0->m[1][0];
    arg1->m[1][1] = arg0->m[1][1];
    arg1->m[1][2] = arg0->m[1][2];
    arg1->m[1][3] = arg0->m[1][3];
    arg1->m[2][0] = arg0->m[2][0];
    arg1->m[2][1] = arg0->m[2][1];
    arg1->m[2][2] = arg0->m[2][2];
    arg1->m[2][3] = arg0->m[2][3];
    arg1->m[3][0] = arg0->m[3][0];
    arg1->m[3][1] = arg0->m[3][1];
    arg1->m[3][2] = arg0->m[3][2];
    arg1->m[3][3] = arg0->m[3][3];
}

void func_xk2_800F2228(MtxF* arg0) {
    arg0->m[0][0] = 1.0f;
    arg0->m[0][1] = 0.0f;
    arg0->m[0][2] = 0.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 0.0f;
    arg0->m[1][1] = 1.0f;
    arg0->m[1][2] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 0.0f;
    arg0->m[2][1] = 0.0f;
    arg0->m[2][2] = 1.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void func_xk2_800F2278(MtxF* arg0, f32 arg1) {
    arg0->m[0][0] = arg1;
    arg0->m[0][1] = 0.0f;
    arg0->m[0][2] = 0.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 0.0f;
    arg0->m[1][1] = arg1;
    arg0->m[1][2] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 0.0f;
    arg0->m[2][1] = 0.0f;
    arg0->m[2][2] = arg1;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void func_xk2_800F22CC(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->m[0][0] = 1.0f;
    arg0->m[0][1] = 0.0f;
    arg0->m[0][2] = 0.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 0.0f;
    arg0->m[1][1] = 1.0f;
    arg0->m[1][2] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 0.0f;
    arg0->m[2][1] = 0.0f;
    arg0->m[2][2] = 1.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = arg1;
    arg0->m[3][1] = arg2;
    arg0->m[3][2] = arg3;
    arg0->m[3][3] = 1.0f;
}

void func_xk2_800F232C(MtxF* arg0, f32 arg1) {
    s32 temp_ft4;

    temp_ft4 = (arg1 * 4096.0f) / 360.0f;
    arg0->m[0][0] = 1.0f;
    arg0->m[0][1] = 0.0f;
    arg0->m[0][2] = 0.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 0.0f;
    arg0->m[1][1] = COS(temp_ft4);
    arg0->m[1][2] = SIN(temp_ft4);
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 0.0f;
    arg0->m[2][1] = SIN(temp_ft4) * -1.0f;
    arg0->m[2][2] = COS(temp_ft4);
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void func_xk2_800F23E4(MtxF* arg0, f32 arg1) {
    s32 temp_ft4;

    temp_ft4 = (arg1 * 4096.0f) / 360.0f;
    arg0->m[0][0] = COS(temp_ft4);
    arg0->m[0][1] = 0.0f;
    arg0->m[0][2] = SIN(temp_ft4) * -1.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = 0.0f;
    arg0->m[1][1] = 1.0f;
    arg0->m[1][2] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = SIN(temp_ft4);
    arg0->m[2][1] = 0.0f;
    arg0->m[2][2] = COS(temp_ft4);
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void func_xk2_800F249C(MtxF* arg0, f32 arg1) {
    s32 temp_ft4;

    temp_ft4 = (arg1 * 4096.0f) / 360.0f;
    arg0->m[0][0] = COS(temp_ft4);
    arg0->m[0][1] = SIN(temp_ft4);
    arg0->m[0][2] = 0.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][0] = SIN(temp_ft4) * -1.0f;
    arg0->m[1][1] = COS(temp_ft4);
    arg0->m[2][2] = 1.0f;
    arg0->m[3][3] = 1.0f;
    arg0->m[1][2] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][0] = 0.0f;
    arg0->m[2][1] = 0.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;

    // TODO: Figure out what file this is from
    PRINTF("LAST RACE CHECK!\n");
    PRINTF("LESS POINT in last check\n");
    PRINTF("USIALLY ERROR\n");
    PRINTF("TENSION ERROR\n");
    PRINTF("NOTHING TENSION ERROR\n");
    PRINTF("CRS LENGTH ERROR\n");
    PRINTF("ERROR BY MAKE_COURSE_VERTEX\n");
    PRINTF("INIT GADGET 2\n");
    PRINTF("DIRT OVER\n");
    PRINTF("CRS LENGTH ERROR\n");
    PRINTF("ERROR BY MAKE_COURSE_VERTEX\n");
    PRINTF("INIT GADGET 1\n");
    PRINTF("DIRT OVER\n");
    PRINTF("YOU CAN RUN\n");
}
