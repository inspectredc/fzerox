#include "global.h"

typedef Gfx* (*unk_i9_80168B20)(Gfx*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef Gfx* (*unk_i9_80168BAC)(Gfx*, s32, s32, s32, s32, s32, s32);

extern unk_i9_80168B20 D_i9_80168B20[][5];
extern unk_i9_80168BAC D_i9_80168BAC[][5];
extern unk_i9_80168BAC D_i9_80168C38[][5];

Gfx* func_i9_80115DF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, s32 argE, s32 argF, s32 arg10) {
    gfx = D_i9_80168C38[arg4][arg1](gfx, arg5, arg6, arg7, arg8, arg9, argA);
    gfx = D_i9_80168BAC[arg3][arg1](gfx, arg5, arg6, arg7, arg8, arg9, argA);
    gfx = D_i9_80168B20[arg2][arg1](gfx, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, argF, arg10);
    return gfx;
}

extern Vtx D_30314B8[];
extern Vtx D_3031548[];
extern Vtx D_3031668[];
extern Vtx D_3031848[];

Gfx* func_i9_80115F38(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3031848, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP1Triangle(gfx++, 4, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_30314B8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 0, 3, 0, 5, 6, 7, 0);
    gSP1Triangle(gfx++, 5, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3031668, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 8, 10, 0, 11, 9, 12, 0);
    gSP2Triangles(gfx++, 13, 4, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 25, 23, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 27, 29, 28, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3031548, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 2, 1, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 12, 11, 17, 0);

    return gfx;
}

extern Vtx D_7037DB8[];
extern Vtx D_7037E28[];
extern Vtx D_7037F18[];
extern Vtx D_70380C8[];

Gfx* func_i9_801162D4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70380C8, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7037DB8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7037F18, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 6, 10, 0);
    gSP2Triangles(gfx++, 11, 4, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 22, 20, 0, 23, 24, 25, 0);
    gSP1Triangle(gfx++, 24, 26, 25, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7037E28, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 8, 0);

    return gfx;
}

extern Vtx D_7038118[];
extern Vtx D_7038188[];
extern Vtx D_7038278[];
extern Vtx D_7038388[];

Gfx* func_i9_80116604(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038388, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038118, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038278, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 12, 10, 0, 13, 14, 15, 0);
    gSP1Triangle(gfx++, 14, 16, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7038188, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 8, 0);

    return gfx;
}

extern Vtx D_70383E8[];
extern Vtx D_70384A8[];
extern Vtx D_7038578[];

Gfx* func_i9_801168F8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038578, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70384A8, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 1, 9, 10, 0);
    gSP1Triangle(gfx++, 11, 12, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_70383E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 3, 6, 0, 7, 2, 8, 0);
    gSP1Triangle(gfx++, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_70385A8[];
extern Vtx D_7038608[];

Gfx* func_i9_80116B48(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038608, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 2, 7, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_70385A8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3031898[];
extern Vtx D_30318D8[];
extern Vtx D_3031958[];
extern Vtx D_3031A98[];

Gfx* func_i9_80116CF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_3031898, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_30318D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3031A98, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 2, 1, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 7, 9, 14, 0, 12, 11, 15, 0);
    gSP2Triangles(gfx++, 12, 2, 16, 0, 12, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 18, 20, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 25, 23, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 27, 30, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 30, 33, 31, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 32, 35, 33, 0, 34, 36, 35, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3031958, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 1, 19, 2, 0);

    return gfx;
}

extern Vtx D_7038688[];
extern Vtx D_70386C8[];
extern Vtx D_7038748[];
extern Vtx D_7038888[];

Gfx* func_i9_80117168(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7038688, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70386C8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038888, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 2, 1, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 7, 9, 14, 0, 12, 11, 15, 0);
    gSP2Triangles(gfx++, 12, 2, 16, 0, 12, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 18, 20, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 25, 23, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7038748, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 1, 19, 2, 0);

    return gfx;
}

extern Vtx D_7038A28[];
extern Vtx D_7038A68[];
extern Vtx D_7038AA8[];
extern Vtx D_7038B88[];

Gfx* func_i9_801174E4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7038A28, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038A68, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038B88, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 12, 17, 18, 0, 12, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 20, 22, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 27, 25, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7038AA8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 3, 5, 0, 11, 12, 13, 0);

    return gfx;
}

extern Vtx D_7038D48[];
extern Vtx D_7038DD8[];

Gfx* func_i9_801177F4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038DD8, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 6, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 20, 22, 0, 24, 25, 26, 0);
    gSP1Triangle(gfx++, 24, 27, 25, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7038D48, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_7038F98[];
extern Vtx D_7038FC8[];

Gfx* func_i9_80117A18(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038FC8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 2, 1, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 5, 4, 0, 0, 2, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7038F98, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3031CE8[];
extern Vtx D_3031D78[];
extern Vtx D_3031F28[];
extern Vtx D_3032158[];

Gfx* func_i9_80117BFC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032158, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 1, 0, 7, 3, 5, 0);
    gSP1Triangle(gfx++, 3, 6, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3031CE8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP1Triangle(gfx++, 5, 4, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3031F28, 35, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 5, 7, 0);
    gSP2Triangles(gfx++, 9, 3, 2, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 16, 17, 0);
    gSP2Triangles(gfx++, 13, 18, 16, 0, 19, 11, 20, 0);
    gSP2Triangles(gfx++, 19, 21, 11, 0, 9, 2, 22, 0);
    gSP2Triangles(gfx++, 11, 21, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 6, 26, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 2, 3, 0, 0, 26, 5, 31, 0);
    gSP2Triangles(gfx++, 4, 32, 0, 0, 4, 33, 32, 0);
    gSP1Triangle(gfx++, 33, 34, 32, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3031D78, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP1Triangle(gfx++, 24, 25, 26, 0);

    return gfx;
}

extern Vtx D_70390C8[];
extern Vtx D_7039138[];
extern Vtx D_7039278[];
extern Vtx D_7039498[];

Gfx* func_i9_801180D0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039498, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 7, 0, 8, 9, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70390C8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP1Triangle(gfx++, 4, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039278, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 2, 3, 0, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 6, 8, 9, 0, 10, 6, 9, 0);
    gSP2Triangles(gfx++, 11, 3, 2, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 15, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 13, 21, 0, 11, 2, 22, 0);
    gSP2Triangles(gfx++, 13, 23, 24, 0, 25, 26, 5, 0);
    gSP2Triangles(gfx++, 27, 8, 5, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 4, 31, 0, 0, 4, 32, 31, 0);
    gSP1Triangle(gfx++, 32, 33, 31, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7039138, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7039548[];
extern Vtx D_70395B8[];
extern Vtx D_70396D8[];
extern Vtx D_7039858[];

Gfx* func_i9_80118494(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039858, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039548, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP1Triangle(gfx++, 4, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70396D8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 4, 6, 0);
    gSP2Triangles(gfx++, 8, 1, 9, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 5, 16, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 3, 21, 2, 0, 3, 22, 21, 0);
    gSP1Triangle(gfx++, 22, 23, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_70395B8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    return gfx;
}

extern Vtx D_70398A8[];
extern Vtx D_7039968[];
extern Vtx D_7039A88[];

Gfx* func_i9_801187D8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039A88, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039968, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 1, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 9, 11, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 10, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_70398A8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7039AD8[];
extern Vtx D_7039B08[];
extern Vtx D_7039C28[];

Gfx* func_i9_80118A3C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039C28, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039B08, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 5, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 1, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7039AD8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_30321D8[];
extern Vtx D_3032268[];
extern Vtx D_3032358[];

Gfx* func_i9_80118C74(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_30321D8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 0, 3, 0, 5, 6, 7, 0);
    gSP1Triangle(gfx++, 5, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032358, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 10, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 14, 16, 15, 0, 17, 18, 15, 0);
    gSP2Triangles(gfx++, 18, 19, 15, 0, 11, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 6, 23, 0, 1, 24, 2, 0);
    gSP2Triangles(gfx++, 24, 25, 2, 0, 25, 26, 2, 0);
    gSP2Triangles(gfx++, 26, 27, 2, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 15, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 5, 4, 39, 0);
    gSP2Triangles(gfx++, 18, 40, 19, 0, 17, 41, 18, 0);
    gSP2Triangles(gfx++, 42, 43, 17, 0, 44, 45, 42, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 25, 49, 46, 0);
    gSP2Triangles(gfx++, 24, 50, 25, 0, 1, 51, 24, 0);
    gSP2Triangles(gfx++, 52, 36, 53, 0, 52, 37, 36, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 55, 57, 56, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3032268, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_7039C58[];
extern Vtx D_7039CC8[];
extern Vtx D_7039DB8[];

Gfx* func_i9_801190F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039C58, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039DB8, 50, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 5, 0, 7, 8, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 5, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 17, 19, 18, 0, 19, 20, 18, 0);
    gSP2Triangles(gfx++, 20, 21, 18, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 14, 29, 0);
    gSP2Triangles(gfx++, 8, 30, 9, 0, 7, 31, 8, 0);
    gSP2Triangles(gfx++, 32, 33, 7, 0, 34, 35, 32, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 36, 0);
    gSP2Triangles(gfx++, 17, 41, 39, 0, 42, 43, 17, 0);
    gSP2Triangles(gfx++, 44, 25, 45, 0, 44, 26, 25, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 47, 49, 48, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_7039CC8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_703A0D8[];
extern Vtx D_703A148[];
extern Vtx D_703A238[];

Gfx* func_i9_80119470(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A0D8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A238, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 11, 0);
    gSP2Triangles(gfx++, 16, 17, 14, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 18, 0, 3, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 27, 25, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 29, 31, 30, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703A148, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_703A438[];
extern Vtx D_703A4F8[];

Gfx* func_i9_8011974C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A4F8, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 3, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 10, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 15, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 25, 27, 26, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703A438, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_703A6B8[];
extern Vtx D_703A748[];

Gfx* func_i9_80119980(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A748, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 12, 10, 0, 13, 14, 15, 0);
    gSP1Triangle(gfx++, 14, 16, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703A6B8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_30326F8[];
extern Vtx D_3032738[];
extern Vtx D_3032778[];
extern Vtx D_3032878[];
extern Vtx D_3032A58[];

Gfx* func_i9_80119B6C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032A58, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_30326F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032738, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032878, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 0, 2, 0);
    gSP2Triangles(gfx++, 10, 7, 16, 0, 10, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 18, 20, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 25, 23, 0);
    gSP2Triangles(gfx++, 26, 5, 27, 0, 5, 4, 27, 0);
    gSP2Triangles(gfx++, 28, 12, 29, 0, 13, 12, 28, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3032778, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    return gfx;
}

extern Vtx D_703A858[];
extern Vtx D_703A898[];
extern Vtx D_703A8D8[];
extern Vtx D_703A998[];
extern Vtx D_703AB78[];

Gfx* func_i9_80119F20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703AB78, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703A858, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A898, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A998, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 4, 12, 5, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 10, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 18, 20, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 25, 23, 0, 26, 15, 27, 0);
    gSP2Triangles(gfx++, 15, 14, 27, 0, 28, 0, 29, 0);
    gSP1Triangle(gfx++, 1, 0, 28, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703A8D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_703ABA8[];
extern Vtx D_703ABE8[];
extern Vtx D_703AC28[];
extern Vtx D_703ACE8[];
extern Vtx D_703AE88[];

Gfx* func_i9_8011A2C8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703AE88, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703ABA8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703ABE8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703ACE8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 4, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 14, 16, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 21, 19, 0, 22, 11, 23, 0);
    gSP1Triangle(gfx++, 24, 6, 25, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703AC28, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_703AEB8[];
extern Vtx D_703AF78[];
extern Vtx D_703B0E8[];

Gfx* func_i9_8011A62C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B0E8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703AF78, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 11, 13, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 15, 18, 16, 0);
    gSP2Triangles(gfx++, 19, 2, 20, 0, 21, 8, 22, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703AEB8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_703B118[];
extern Vtx D_703B178[];
extern Vtx D_703B298[];

Gfx* func_i9_8011A8A8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B298, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B178, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703B118, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3032A98[];
extern Vtx D_3032AD8[];
extern Vtx D_3032B98[];
extern Vtx D_3032C18[];
extern Vtx D_3032D58[];

Gfx* func_i9_8011AAD0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032AD8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 1, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 3, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 7, 3, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 8, 11, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_3032A98, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032B98, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 0, 7, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032D58, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 4, 0);
    gSP2Triangles(gfx++, 0, 4, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 6, 8, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 10, 13, 11, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 16, 15, 0);
    gSP2Triangles(gfx++, 1, 0, 25, 0, 21, 23, 26, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3032C18, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_703B2C8[];
extern Vtx D_703B308[];
extern Vtx D_703B398[];
extern Vtx D_703B3D8[];
extern Vtx D_703B518[];

Gfx* func_i9_8011AFE8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B308, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703B2C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B398, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B518, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 3, 5, 12, 0, 13, 7, 14, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 0, 0, 10, 9, 20, 0);
    gSP2Triangles(gfx++, 21, 8, 7, 0, 18, 22, 19, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703B3D8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 13, 15, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_703B688[];
extern Vtx D_703B6C8[];
extern Vtx D_703B738[];
extern Vtx D_703B778[];
extern Vtx D_703B818[];

Gfx* func_i9_8011B47C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B6C8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 5, 3, 0, 5, 6, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703B688, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B738, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B818, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 4, 0, 1, 0, 7, 0);
    gSP2Triangles(gfx++, 0, 5, 8, 0, 0, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 15, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703B778, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703B978[];
extern Vtx D_703B9B8[];
extern Vtx D_703BA18[];
extern Vtx D_703BA98[];

Gfx* func_i9_8011B8E4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B9B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 1, 5, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703B978, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BA98, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 8, 7, 0);
    gSP2Triangles(gfx++, 4, 3, 9, 0, 3, 8, 9, 0);
    gSP2Triangles(gfx++, 2, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 15, 13, 0, 14, 16, 17, 0);
    gSP1Triangle(gfx++, 0, 18, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703BA18, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 0, 7, 0);

    return gfx;
}

extern Vtx D_703BBC8[];
extern Vtx D_703BC08[];
extern Vtx D_703BC78[];
extern Vtx D_703BCD8[];

Gfx* func_i9_8011BC3C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BC08, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 1, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703BBC8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BCD8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 3, 7, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703BC78, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3032F08[];
extern Vtx D_3032F68[];
extern Vtx D_3032FE8[];
extern Vtx D_3033128[];
extern Vtx D_3033268[];

Gfx* func_i9_8011BF1C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033268, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032F08, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032F68, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033128, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 3, 5, 10, 0, 10, 5, 11, 0);
    gSP2Triangles(gfx++, 2, 12, 0, 0, 0, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 9, 7, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 17, 19, 0, 18, 15, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_3032FE8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 13, 15, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_703BD58[];
extern Vtx D_703BDB8[];
extern Vtx D_703BE38[];
extern Vtx D_703BF78[];
extern Vtx D_703C078[];

Gfx* func_i9_8011C398(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C078, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BD58, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BDB8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BF78, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 3, 5, 10, 0, 10, 5, 11, 0);
    gSP2Triangles(gfx++, 12, 9, 7, 0, 13, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703BE38, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 13, 15, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_703C0B8[];
extern Vtx D_703C118[];
extern Vtx D_703C158[];
extern Vtx D_703C298[];
extern Vtx D_703C378[];

Gfx* func_i9_8011C810(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C378, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C0B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C118, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C298, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 9, 11, 0, 8, 13, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703C158, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 12, 10, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 16, 18, 0);

    return gfx;
}

extern Vtx D_703C3B8[];
extern Vtx D_703C418[];
extern Vtx D_703C548[];
extern Vtx D_703C628[];

Gfx* func_i9_8011CBF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C628, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C3B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C548, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 2, 6, 0, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 7, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703C418, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 15, 17, 0);

    return gfx;
}

extern Vtx D_703C668[];
extern Vtx D_703C728[];
extern Vtx D_703C788[];

Gfx* func_i9_8011CF20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C788, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 5, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C728, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg7, arg8, arg9, 255);
    gDPSetEnvColor(gfx++, argA, argB, argC, 255);
    gSPVertex(gfx++, D_703C668, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_30332A8[];
extern Vtx D_3033308[];
extern Vtx D_3033468[];
extern Vtx D_30334A8[];
extern Vtx D_3033548[];
extern Vtx D_3033708[];

Gfx* func_i9_8011D154(Gfx* gfx, s32 red1, s32 green1, s32 blue1, s32 red2, s32 green2, s32 blue2) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033708, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red1, green1, blue1, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033308, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 19, 21, 20, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red2, green2, blue2, 255);
    gSPVertex(gfx++, D_3033548, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 0, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 7, 9, 8, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 11, 13, 12, 0, 0, 2, 5, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_30332A8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033468, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_30334A8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703C808[];
extern Vtx D_703C868[];
extern Vtx D_703C988[];
extern Vtx D_703C9C8[];
extern Vtx D_703CA68[];
extern Vtx D_703CC28[];

Gfx* func_i9_8011D5EC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703CC28, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C868, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703CA68, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 5, 8, 7, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 10, 12, 11, 0, 13, 4, 6, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703C808, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C988, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703C9C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703CCC8[];
extern Vtx D_703CD28[];
extern Vtx D_703CE48[];
extern Vtx D_703CE88[];
extern Vtx D_703CF28[];
extern Vtx D_703D0D8[];

Gfx* func_i9_8011DA60(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D0D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703CD28, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703CF28, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 5, 8, 9, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 11, 13, 12, 0, 14, 4, 6, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703CCC8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703CE48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703CE88, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703D178[];
extern Vtx D_703D1D8[];
extern Vtx D_703D298[];
extern Vtx D_703D338[];
extern Vtx D_703D448[];

Gfx* func_i9_8011DE24(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D448, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D1D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703D338, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 14, 15, 16, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703D178, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D298, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703D4E8[];
extern Vtx D_703D5A8[];
extern Vtx D_703D5E8[];
extern Vtx D_703D678[];

Gfx* func_i9_8011E1A0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D678, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D4E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703D5E8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D5A8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    return gfx;
}

extern Vtx D_30337A8[];
extern Vtx D_30338A8[];
extern Vtx D_3033928[];
extern Vtx D_3033968[];
extern Vtx D_3033A08[];
extern Vtx D_3033C68[];

Gfx* func_i9_8011E40C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033C68, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_30338A8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 7, 3, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3033A08, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 37, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_30337A8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033928, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3033968, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703D6D8[];
extern Vtx D_703D7D8[];
extern Vtx D_703D858[];
extern Vtx D_703D898[];
extern Vtx D_703D938[];
extern Vtx D_703DB58[];

Gfx* func_i9_8011E89C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703DB58, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D7D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 7, 3, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703D938, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703D6D8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703D858, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703D898, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703DBF8[];
extern Vtx D_703DCE8[];
extern Vtx D_703DD68[];
extern Vtx D_703DDA8[];
extern Vtx D_703DE48[];
extern Vtx D_703E058[];

Gfx* func_i9_8011EC68(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E058, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703DCE8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 7, 3, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703DE48, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP1Triangle(gfx++, 30, 31, 32, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703DBF8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703DD68, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703DDA8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703E0F8[];
extern Vtx D_703E1B8[];
extern Vtx D_703E238[];
extern Vtx D_703E2D8[];
extern Vtx D_703E488[];

Gfx* func_i9_8011F02C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E488, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E1B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 3, 7, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703E2D8, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP1Triangle(gfx++, 24, 25, 26, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703E0F8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E238, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703E528[];
extern Vtx D_703E588[];
extern Vtx D_703E608[];
extern Vtx D_703E6A8[];
extern Vtx D_703E6D8[];

Gfx* func_i9_8011F3F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E6D8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E588, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 0, 2, 0, 3, 5, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703E6A8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703E528, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E608, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_3033D08[];
extern Vtx D_3033E28[];
extern Vtx D_3033EA8[];
extern Vtx D_3033F48[];
extern Vtx D_3033FE8[];
extern Vtx D_3034148[];

Gfx* func_i9_8011F704(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3034148, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033E28, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3033FE8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_3033D08, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033EA8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3033F48, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703E738[];
extern Vtx D_703E858[];
extern Vtx D_703E8D8[];
extern Vtx D_703E978[];
extern Vtx D_703EA18[];
extern Vtx D_703EB68[];

Gfx* func_i9_8011FACC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703EB68, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E858, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703EA18, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 19, 20, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703E738, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703E8D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703E978, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703EBF8[];
extern Vtx D_703ED08[];
extern Vtx D_703ED88[];
extern Vtx D_703EE28[];
extern Vtx D_703EEC8[];
extern Vtx D_703EFE8[];

Gfx* func_i9_8011FEB0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703EFE8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703ED08, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703EEC8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703EBF8, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 14, 15, 16, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703ED88, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703EE28, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_703F078[];
extern Vtx D_703F158[];
extern Vtx D_703F1D8[];
extern Vtx D_703F278[];
extern Vtx D_703F398[];

Gfx* func_i9_80120298(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F398, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F158, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 0, 2, 0, 3, 5, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703F278, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703F078, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F1D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_703F428[];
extern Vtx D_703F488[];
extern Vtx D_703F518[];
extern Vtx D_703F5B8[];
extern Vtx D_703F648[];

Gfx* func_i9_801205FC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F648, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F488, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 2, 0, 3, 5, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703F5B8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703F428, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F518, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_30341E8[];
extern Vtx D_3034328[];
extern Vtx D_30343C8[];
extern Vtx D_3034508[];
extern Vtx D_3034598[];
extern Vtx D_3034818[];

Gfx* func_i9_80120910(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3034818, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3034328, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 3, 7, 4, 0);
    gSP2Triangles(gfx++, 8, 1, 6, 0, 4, 7, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3034598, 40, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_30341E8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_30343C8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 3, 18, 19, 0, 3, 19, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3034508, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 6, 8, 0);

    return gfx;
}

extern Vtx D_703F6A8[];
extern Vtx D_703F7E8[];
extern Vtx D_703F888[];
extern Vtx D_703F9C8[];
extern Vtx D_703FA58[];
extern Vtx D_703FBE8[];

Gfx* func_i9_80120E14(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703FBE8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F7E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 3, 7, 4, 0);
    gSP2Triangles(gfx++, 8, 1, 6, 0, 4, 7, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_703FA58, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 4, 10, 5, 0, 11, 12, 1, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703F6A8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703F888, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 3, 18, 19, 0, 3, 19, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703F9C8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 6, 8, 0);

    return gfx;
}

extern Vtx D_703FC88[];
extern Vtx D_703FDC8[];
extern Vtx D_703FE68[];
extern Vtx D_703FFA8[];
extern Vtx D_7040038[];
extern Vtx D_70401C8[];

Gfx* func_i9_801212E8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70401C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703FDC8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 3, 7, 4, 0);
    gSP2Triangles(gfx++, 8, 1, 6, 0, 4, 7, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7040038, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 4, 10, 5, 0, 11, 12, 1, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_703FC88, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703FE68, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 3, 18, 19, 0, 3, 19, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_703FFA8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 6, 8, 0);

    return gfx;
}

extern Vtx D_7040268[];
extern Vtx D_7040308[];
extern Vtx D_70403A8[];
extern Vtx D_7040438[];
extern Vtx D_7040528[];

Gfx* func_i9_801217BC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040528, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040308, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 1, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 5, 8, 0);
    gSP2Triangles(gfx++, 0, 2, 9, 0, 5, 4, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7040438, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 6, 14, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7040268, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70403A8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 1, 0, 0, 5, 7, 8, 0);

    return gfx;
}

extern Vtx D_70405B8[];
extern Vtx D_70405F8[];
extern Vtx D_7040688[];
extern Vtx D_70406E8[];
extern Vtx D_7040718[];

Gfx* func_i9_80121B68(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040718, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70405F8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 1, 0, 8, 3, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_70406E8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_70405B8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040688, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_30348B8[];
extern Vtx D_3034958[];
extern Vtx D_3034A38[];
extern Vtx D_3034B48[];
extern Vtx D_3034BC8[];
extern Vtx D_3034EC8[];

Gfx* func_i9_80121E60(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3034EC8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3034958, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 3, 0, 7, 5, 8, 0);
    gSP2Triangles(gfx++, 4, 6, 9, 0, 10, 0, 11, 0);
    gSP2Triangles(gfx++, 7, 3, 5, 0, 10, 1, 0, 0);
    gSP2Triangles(gfx++, 2, 1, 12, 0, 13, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3034BC8, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 19, 21, 20, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 9, 28, 10, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 35, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 45, 46, 47, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_30348B8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3034A38, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 2, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 9, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 10, 9, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3034B48, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 5, 0, 3, 6, 7, 0);

    return gfx;
}

extern Vtx D_7040778[];
extern Vtx D_7040818[];
extern Vtx D_7040918[];
extern Vtx D_70409D8[];
extern Vtx D_7040A58[];
extern Vtx D_7040CB8[];

Gfx* func_i9_801223BC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040CB8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040818, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 3, 10, 4, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 7, 9, 0, 15, 12, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7040A58, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 5, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 29, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 36, 2, 1, 0);
    gSP1Triangle(gfx++, 3, 37, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7040778, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040918, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 6, 8, 7, 0);
    gSP1Triangle(gfx++, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70409D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 0, 0, 5, 6, 7, 0);

    return gfx;
}

extern Vtx D_7040D58[];
extern Vtx D_7040DE8[];
extern Vtx D_7040EE8[];
extern Vtx D_7040FA8[];
extern Vtx D_7041028[];
extern Vtx D_70411D8[];

Gfx* func_i9_8012290C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70411D8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040DE8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 3, 10, 4, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 7, 9, 0, 15, 12, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7041028, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP1Triangle(gfx++, 24, 25, 26, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7040D58, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7040EE8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 6, 8, 7, 0);
    gSP1Triangle(gfx++, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7040FA8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 0, 0, 5, 6, 7, 0);

    return gfx;
}

extern Vtx D_7041268[];
extern Vtx D_70412C8[];
extern Vtx D_7041398[];
extern Vtx D_7041418[];
extern Vtx D_70414D8[];

Gfx* func_i9_80122DDC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70414D8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70412C8, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 4, 3, 8, 0);
    gSP2Triangles(gfx++, 1, 0, 9, 0, 10, 5, 4, 0);
    gSP2Triangles(gfx++, 2, 1, 11, 0, 9, 0, 12, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7041418, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7041268, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041398, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 2, 6, 7, 0);

    return gfx;
}

extern Vtx D_7041568[];
extern Vtx D_7041608[];
extern Vtx D_7041648[];
extern Vtx D_7041678[];

Gfx* func_i9_8012311C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041678, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041568, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 1, 0, 3, 0, 6, 8, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7041648, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041608, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_3034F68[];
extern Vtx D_3035108[];
extern Vtx D_3035308[];
extern Vtx D_3035348[];
extern Vtx D_3035388[];
extern Vtx D_30355E8[];

Gfx* func_i9_80123384(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_30355E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3035108, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 19, 17, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 24, 26, 25, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 20, 31, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3035388, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 14, 16, 15, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 18, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 22, 24, 23, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_3034F68, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3035308, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3035348, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    return gfx;
}

extern Vtx D_70416D8[];
extern Vtx D_7041858[];
extern Vtx D_7041A38[];
extern Vtx D_7041A78[];
extern Vtx D_7041AB8[];
extern Vtx D_7041CC8[];

Gfx* func_i9_801238FC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041CC8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041858, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 22, 24, 23, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 18, 29, 19, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7041AB8, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_70416D8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041A38, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7041A78, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    return gfx;
}

extern Vtx D_7041D68[];
extern Vtx D_7041E18[];
extern Vtx D_7041FD8[];
extern Vtx D_7042018[];
extern Vtx D_7042058[];
extern Vtx D_7042278[];

Gfx* func_i9_80123E08(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042278, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041E18, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 19, 21, 20, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7042058, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 8, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 3, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7041D68, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP1Triangle(gfx++, 8, 9, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7041FD8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7042018, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    return gfx;
}

extern Vtx D_7042308[];
extern Vtx D_7042368[];
extern Vtx D_7042428[];
extern Vtx D_7042468[];
extern Vtx D_7042648[];

Gfx* func_i9_801242E8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042648, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042368, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7042468, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7042308, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042428, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    return gfx;
}

extern Vtx D_70426D8[];
extern Vtx D_7042738[];
extern Vtx D_70427F8[];
extern Vtx D_7042838[];
extern Vtx D_7042928[];

Gfx* func_i9_80124664(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042928, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042738, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7042838, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_70426D8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70427F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    return gfx;
}

extern Vtx D_3035688[];
extern Vtx D_3035788[];
extern Vtx D_3035A48[];
extern Vtx D_3035A88[];
extern Vtx D_3035B48[];
extern Vtx D_3035F28[];
extern Vtx D_3035FE8[];

Gfx* func_i9_8012498C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3035FE8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3035788, 44, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 27, 25, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 29, 31, 30, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 33, 35, 34, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 43, 41, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3035B48, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 3, 9, 4, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 11, 16, 12, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 24, 26, 25, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 28, 30, 29, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 35, 37, 36, 0);
    gSP2Triangles(gfx++, 2, 38, 39, 0, 40, 41, 17, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 51, 53, 54, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 55, 57, 58, 0, 59, 60, 61, 0);
    gSPVertex(gfx++, D_3035F28, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_3035688, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3035A48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3035A88, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 7, 9, 4, 0);
    gSP2Triangles(gfx++, 3, 10, 11, 0, 3, 11, 0, 0);

    return gfx;
}

extern Vtx D_7042988[];
extern Vtx D_7042A08[];
extern Vtx D_7042C48[];
extern Vtx D_7042C88[];
extern Vtx D_7042D48[];
extern Vtx D_7043058[];

Gfx* func_i9_80125030(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043058, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042A08, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 2, 24, 0, 0, 2, 25, 24, 0);
    gSP2Triangles(gfx++, 5, 26, 3, 0, 26, 27, 3, 0);
    gSP2Triangles(gfx++, 15, 28, 13, 0, 28, 29, 13, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 12, 34, 10, 0, 12, 35, 34, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7042D48, 49, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 12, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 19, 21, 20, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 23, 25, 24, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 30, 32, 31, 0);
    gSP2Triangles(gfx++, 5, 33, 34, 0, 35, 36, 15, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 46, 47, 48, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7042988, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7042C48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7042C88, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 7, 9, 4, 0);
    gSP2Triangles(gfx++, 3, 10, 11, 0, 3, 11, 0, 0);

    return gfx;
}

extern Vtx D_70430F8[];
extern Vtx D_7043178[];
extern Vtx D_7043378[];
extern Vtx D_70433F8[];
extern Vtx D_7043608[];

Gfx* func_i9_801255F8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043608, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043178, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 2, 24, 0, 0, 5, 25, 3, 0);
    gSP2Triangles(gfx++, 15, 26, 13, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 12, 31, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_70433F8, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP1Triangle(gfx++, 30, 31, 32, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_70430F8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043378, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    return gfx;
}

extern Vtx D_7043698[];
extern Vtx D_70436F8[];
extern Vtx D_70437F8[];
extern Vtx D_7043858[];
extern Vtx D_70439E8[];

Gfx* func_i9_80125AC4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70439E8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70436F8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 9, 6, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 5, 13, 3, 0);
    gSP2Triangles(gfx++, 12, 14, 10, 0, 2, 15, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7043858, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 2, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 6, 8, 7, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 10, 12, 11, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0,
                      COMBINED);
    gSPVertex(gfx++, D_7043698, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70437F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_7043A78[];
extern Vtx D_7043B38[];
extern Vtx D_7043B98[];
extern Vtx D_7043C58[];

Gfx* func_i9_80125E48(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043C58, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043A78, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7043B98, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043B38, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3036088[];

Gfx* func_i9_801260FC(Gfx* gfx, s32 red, s32 green, s32 blue, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3036088, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP1Triangle(gfx++, 7, 9, 10, 0);
    return gfx;
}

extern Vtx D_7043CE8[];

Gfx* func_i9_801261E0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043CE8, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP1Triangle(gfx++, 8, 9, 10, 0);

    return gfx;
}

extern Vtx D_7043D98[];

Gfx* func_i9_801262C0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043D98, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    return gfx;
}

extern Vtx D_7043E18[];

Gfx* func_i9_8012638C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043E18, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3036138[];

Gfx* func_i9_80126440(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3036138, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    return gfx;
}

extern Vtx D_7043E78[];

Gfx* func_i9_80126544(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043E78, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    return gfx;
}

extern Vtx D_7043F78[];

Gfx* func_i9_80126648(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7043F78, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7044038[];

Gfx* func_i9_80126718(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044038, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_3036238[];

Gfx* func_i9_801267E8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3036238, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 14, 16, 11, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 8, 0, 8, 20, 21, 0);
    gSP1Triangle(gfx++, 8, 21, 17, 0);

    return gfx;
}

extern Vtx D_70440F8[];

Gfx* func_i9_80126950(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70440F8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 11, 13, 8, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 19, 14, 0);

    return gfx;
}

extern Vtx D_7044238[];

Gfx* func_i9_80126AA4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044238, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 9, 11, 6, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 15, 17, 12, 0);

    return gfx;
}

extern Vtx D_7044358[];

Gfx* func_i9_80126BE4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044358, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 9, 6, 0);

    return gfx;
}

extern Vtx D_70443F8[];

Gfx* func_i9_80126CCC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70443F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);

    return gfx;
}

extern Vtx D_3036398[];
extern Vtx D_3036518[];

Gfx* func_i9_80126D98(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3036398, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 14, 16, 17, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 8, 18, 19, 0, 8, 19, 9, 0);
    gSP2Triangles(gfx++, 0, 20, 21, 0, 0, 21, 1, 0);
    gSP2Triangles(gfx++, 6, 22, 23, 0, 6, 23, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_3036518, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 8, 11, 12, 0);
    gSP2Triangles(gfx++, 8, 12, 9, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 14, 17, 18, 0);
    gSP2Triangles(gfx++, 14, 18, 15, 0, 19, 20, 21, 0);
    gSP1Triangle(gfx++, 19, 21, 22, 0);

    return gfx;
}

extern Vtx D_7044438[];
extern Vtx D_7044538[];

Gfx* func_i9_80127044(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044438, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7044538, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    return gfx;
}

extern Vtx D_7044618[];
extern Vtx D_70446D8[];

Gfx* func_i9_8012720C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044618, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_70446D8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    return gfx;
}

extern Vtx D_70447B8[];
extern Vtx D_7044878[];

Gfx* func_i9_801273A4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_70447B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gSPVertex(gfx++, D_7044878, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_7044908[];

Gfx* func_i9_80127508(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044908, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3036688[];

Gfx* func_i9_801275CC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3036688, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 18, 0, 13, 17, 11, 0);
    gSP1Triangle(gfx++, 21, 22, 23, 0);

    return gfx;
}

extern Vtx D_7044938[];

Gfx* func_i9_80127704(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044938, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7044A78[];

Gfx* func_i9_80127808(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044A78, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);

    return gfx;
}

extern Vtx D_7044B58[];

Gfx* func_i9_801278F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044B58, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7044C18[];

Gfx* func_i9_801279C0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044C18, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3036808[];

Gfx* func_i9_80127A74(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3036808, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 19, 21, 20, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 26, 3, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 15, 0, 32, 16, 15, 0);
    gSP2Triangles(gfx++, 33, 29, 34, 0, 29, 28, 34, 0);
    gSP2Triangles(gfx++, 3, 35, 4, 0, 1, 36, 2, 0);
    gSP2Triangles(gfx++, 9, 37, 10, 0, 7, 38, 8, 0);

    return gfx;
}

extern Vtx D_7044C78[];

Gfx* func_i9_80127C28(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044C78, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 10, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 3, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 16, 15, 0, 29, 26, 25, 0);

    return gfx;
}

extern Vtx D_7044E58[];

Gfx* func_i9_80127D68(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044E58, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    return gfx;
}

extern Vtx D_7044FD8[];

Gfx* func_i9_80127E70(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7044FD8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

Gfx* func_i9_80127F40(Gfx* gfx, s32 red, s32 green, s32 blue, s32 arg4, s32 arg5, s32 arg6) {
    return gfx;
}

extern Vtx D_3000788[];
extern Vtx D_3000868[];
extern Vtx D_3000A78[];
extern Vtx D_3000AF8[];
extern Vtx D_3000C38[];
extern Vtx D_3000C98[];
extern Vtx D_3001098[];
extern Vtx D_30013C8[];
extern Vtx D_3001488[];

Gfx* func_i9_80127F54(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30013C8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3001488, 53, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 6, 8, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 13, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 18, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 9, 0, 26, 19, 21, 0);
    gSP2Triangles(gfx++, 26, 20, 19, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 3, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 12, 11, 2, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 14, 35, 33, 0);
    gSP2Triangles(gfx++, 14, 33, 32, 0, 14, 36, 35, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 38, 40, 39, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 44, 42, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 46, 48, 47, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 52, 50, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3000C38, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3000A78, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3000C98, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 4, 8, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 17, 20, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 20, 0);
    gSP2Triangles(gfx++, 25, 20, 17, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 11, 10, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 27, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 40, 42, 43, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 47, 0, 48, 38, 27, 0);
    gSP2Triangles(gfx++, 48, 27, 49, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 10, 51, 34, 0, 52, 53, 26, 0);
    gSP2Triangles(gfx++, 53, 28, 26, 0, 4, 54, 5, 0);
    gSP2Triangles(gfx++, 55, 56, 35, 0, 57, 44, 47, 0);
    gSP2Triangles(gfx++, 33, 32, 58, 0, 42, 41, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 63, 61, 0);
    gSPVertex(gfx++, D_3001098, 51, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 8, 0);
    gSP2Triangles(gfx++, 4, 6, 7, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 10, 9, 0, 12, 13, 10, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 21, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 25, 28, 26, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 29, 32, 30, 0);
    gSP2Triangles(gfx++, 27, 33, 34, 0, 27, 35, 33, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 10, 38, 11, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 39, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 46, 44, 43, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 49, 48, 50, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3000788, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 4, 8, 9, 0, 4, 9, 5, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_3000868, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 6, 8, 9, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 16, 18, 19, 0, 20, 16, 19, 0);
    gSP2Triangles(gfx++, 18, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 18, 22, 27, 0);
    gSP2Triangles(gfx++, 28, 20, 19, 0, 13, 15, 29, 0);
    gSP2Triangles(gfx++, 30, 29, 31, 0, 1, 32, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3000AF8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7000008[];
extern Vtx D_70000C8[];
extern Vtx D_70002C8[];
extern Vtx D_7000408[];
extern Vtx D_7000468[];
extern Vtx D_7000868[];
extern Vtx D_7000A38[];
extern Vtx D_7000AF8[];
extern Vtx D_7000ED8[];

Gfx* func_i9_801289DC(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7000A38, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7000AF8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 18, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 51, 46, 0);
    gSP2Triangles(gfx++, 49, 52, 50, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 59, 60, 61, 0);
    gSPVertex(gfx++, D_7000ED8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7000408, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7000468, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 6, 4, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 20, 31, 21, 0);
    gSP2Triangles(gfx++, 32, 27, 30, 0, 25, 24, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 50, 53, 51, 0);
    gSP2Triangles(gfx++, 49, 53, 54, 0, 51, 37, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 59, 60, 61, 0);
    gSP1Triangle(gfx++, 8, 62, 63, 0);
    gSPVertex(gfx++, D_7000868, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 10, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 22, 21, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 27, 26, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7000008, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70000C8, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 6, 8, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 7, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 17, 20, 0, 19, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 19, 23, 28, 0, 29, 21, 20, 0);
    gSP2Triangles(gfx++, 14, 16, 30, 0, 14, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70002C8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7000F08[];
extern Vtx D_7000FB8[];
extern Vtx D_7001188[];
extern Vtx D_7001228[];
extern Vtx D_7001288[];
extern Vtx D_7001678[];
extern Vtx D_70017D8[];
extern Vtx D_7001898[];

Gfx* func_i9_801292C0(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70017D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7001898, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7001228, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7001288, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 21, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 41, 43, 0, 44, 40, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 49, 47, 50, 0);
    gSP2Triangles(gfx++, 51, 42, 52, 0, 30, 53, 54, 0);
    gSP2Triangles(gfx++, 53, 55, 54, 0, 56, 57, 58, 0);
    gSP2Triangles(gfx++, 56, 59, 57, 0, 60, 61, 62, 0);
    gSPVertex(gfx++, D_7001678, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 3, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 12, 11, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 17, 16, 18, 0);
    gSP1Triangle(gfx++, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7000F08, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP1Triangle(gfx++, 7, 9, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7000FB8, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 11, 14, 0);
    gSP2Triangles(gfx++, 13, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 13, 17, 21, 0, 22, 15, 14, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7001188, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_7001A78[];
extern Vtx D_7001B58[];
extern Vtx D_7001BF8[];
extern Vtx D_7001E58[];
extern Vtx D_7001F18[];

Gfx* func_i9_80129974(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7001E58, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7001F18, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 7, 0, 8, 9, 10, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7001BF8, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 16, 15, 0, 17, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 22, 24, 23, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 25, 28, 26, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP1Triangle(gfx++, 35, 36, 37, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7001A78, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7001B58, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_7001FC8[];
extern Vtx D_7002058[];
extern Vtx D_70020F8[];
extern Vtx D_7002288[];
extern Vtx D_7002348[];

Gfx* func_i9_80129D04(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7002288, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7002348, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70020F8, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 7, 0, 5, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP1Triangle(gfx++, 22, 23, 24, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7001FC8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7002058, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_30017D8[];
extern Vtx D_3001858[];
extern Vtx D_30019B8[];
extern Vtx D_3001B28[];
extern Vtx D_3001BA8[];
extern Vtx D_3001CE8[];
extern Vtx D_3001D28[];
extern Vtx D_3002128[];

Gfx* func_i9_80129FC4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3001D28, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 5, 0, 0, 4, 6, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 12, 11, 13, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 14, 13, 15, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 19, 18, 0);
    gSP2Triangles(gfx++, 22, 18, 23, 0, 11, 10, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 25, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 11, 24, 0, 30, 29, 24, 0);
    gSP2Triangles(gfx++, 30, 24, 31, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 34, 36, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 44, 46, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 57, 58, 56, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 58, 60, 56, 0);
    gSP1Triangle(gfx++, 61, 62, 63, 0);
    gSPVertex(gfx++, D_3002128, 54, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 7, 9, 8, 0);
    gSP2Triangles(gfx++, 9, 7, 10, 0, 11, 9, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 12, 14, 0);
    gSP2Triangles(gfx++, 13, 5, 16, 0, 14, 13, 16, 0);
    gSP2Triangles(gfx++, 16, 5, 4, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 20, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 33, 35, 34, 0);
    gSP2Triangles(gfx++, 33, 36, 35, 0, 28, 27, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 39, 41, 40, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 45, 43, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 47, 49, 48, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 50, 53, 51, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3001B28, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3001CE8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30017D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3001858, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 1, 13, 2, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_30019B8, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 3, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 11, 0, 2, 12, 0, 0);
    gSP2Triangles(gfx++, 9, 13, 7, 0, 14, 15, 8, 0);
    gSP2Triangles(gfx++, 15, 9, 8, 0, 1, 0, 16, 0);
    gSP2Triangles(gfx++, 1, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 19, 4, 20, 0, 21, 18, 22, 0);
    gSP1Triangle(gfx++, 5, 18, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3001BA8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 0, 10, 1, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_70023A8[];
extern Vtx D_7002448[];
extern Vtx D_70025A8[];
extern Vtx D_70026F8[];
extern Vtx D_7002778[];
extern Vtx D_7002818[];
extern Vtx D_7002858[];
extern Vtx D_7002C58[];

Gfx* func_i9_8012A8B0(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7002858, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 5, 0, 0, 4, 6, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 2, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 11, 14, 15, 0, 15, 14, 16, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 21, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 14, 26, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 30, 32, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 37, 36, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 39, 43, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 47, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 51, 52, 50, 0, 52, 53, 50, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 54, 56, 57, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 61, 53, 62, 0);
    gSP1Triangle(gfx++, 63, 61, 62, 0);
    gSPVertex(gfx++, D_7002C58, 42, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 10, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 22, 24, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 26, 29, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 40, 38, 0, 37, 41, 40, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70026F8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7002818, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70023A8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7002448, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 1, 13, 2, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70025A8, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 5, 0, 11, 6, 5, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 13, 19, 20, 0);
    gSP2Triangles(gfx++, 19, 1, 20, 0, 2, 13, 12, 0);
    gSP1Triangle(gfx++, 16, 15, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7002778, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 0, 9, 1, 0);

    return gfx;
}

extern Vtx D_7002EF8[];
extern Vtx D_7002F98[];
extern Vtx D_7003098[];
extern Vtx D_70031C8[];
extern Vtx D_7003268[];
extern Vtx D_70032A8[];
extern Vtx D_7003698[];

Gfx* func_i9_8012B010(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70032A8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 3, 9, 0, 7, 9, 10, 0);
    gSP2Triangles(gfx++, 10, 9, 11, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 11, 0);
    gSP2Triangles(gfx++, 16, 11, 18, 0, 19, 9, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 21, 0);
    gSP2Triangles(gfx++, 26, 27, 11, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 34, 35, 31, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 37, 47, 0, 48, 46, 47, 0);
    gSP2Triangles(gfx++, 37, 0, 49, 0, 47, 37, 50, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 0, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 57, 58, 0);
    gSP2Triangles(gfx++, 59, 60, 61, 0, 62, 59, 61, 0);
    gSPVertex(gfx++, D_7003698, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 8, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7003268, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7002EF8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7002F98, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 4, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7003098, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 4, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 13, 15, 14, 0, 16, 12, 17, 0);
    gSP2Triangles(gfx++, 9, 8, 1, 0, 18, 15, 16, 0);
    gSP1Triangle(gfx++, 7, 5, 4, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70031C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_7003798[];
extern Vtx D_70037F8[];
extern Vtx D_7003858[];
extern Vtx D_70038E8[];
extern Vtx D_7003988[];

Gfx* func_i9_8012B6C4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7003988, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 5, 4, 7, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 9, 8, 10, 0);
    gSP2Triangles(gfx++, 11, 9, 10, 0, 2, 12, 13, 0);
    gSP2Triangles(gfx++, 0, 14, 13, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP1Triangle(gfx++, 30, 31, 32, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7003798, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70037F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7003858, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 0, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70038E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 3, 5, 9, 0);

    return gfx;
}

extern Vtx D_7003B98[];
extern Vtx D_7003BD8[];

Gfx* func_i9_8012B9C4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7003BD8, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 2, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 3, 0, 10, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7003B98, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    return gfx;
}

extern Vtx D_3002488[];
extern Vtx D_3002568[];
extern Vtx D_30025E8[];
extern Vtx D_3002828[];
extern Vtx D_3002B08[];
extern Vtx D_3002EF8[];
extern Vtx D_3003168[];
extern Vtx D_3003228[];
extern Vtx D_3003388[];

Gfx* func_i9_8012BB50(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3003228, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 10, 17, 11, 0);
    gSP2Triangles(gfx++, 18, 9, 19, 0, 1, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3002828, 46, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 1, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 9, 11, 10, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 15, 13, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 23, 25, 24, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 27, 29, 28, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 33, 31, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 37, 35, 0);
    gSP2Triangles(gfx++, 38, 5, 39, 0, 5, 7, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3002B08, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 20, 26, 21, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 27, 29, 16, 0);
    gSP2Triangles(gfx++, 7, 30, 31, 0, 7, 31, 8, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 35, 33, 0);
    gSP2Triangles(gfx++, 32, 36, 35, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 45, 47, 46, 0);
    gSP2Triangles(gfx++, 37, 39, 48, 0, 49, 50, 14, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 51, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 57, 58, 0);
    gSP2Triangles(gfx++, 59, 60, 61, 0, 59, 61, 62, 0);
    gSPVertex(gfx++, D_3002EF8, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 12, 14, 13, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 16, 18, 17, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 21, 22, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 19, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 25, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 32, 34, 33, 0, 34, 35, 33, 0);
    gSP1Triangle(gfx++, 36, 37, 38, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3003388, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 4, 3, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 8, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3002488, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 8, 9, 0, 5, 9, 6, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3002568, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3003168, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_30025E8, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 3, 12, 13, 0, 14, 15, 2, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);

    return gfx;
}

extern Vtx D_7003DE8[];
extern Vtx D_7003EC8[];
extern Vtx D_7003F48[];
extern Vtx D_7004008[];
extern Vtx D_7004228[];
extern Vtx D_7004618[];
extern Vtx D_7004758[];
extern Vtx D_70047F8[];
extern Vtx D_7004858[];
extern Vtx D_7004918[];

Gfx* func_i9_8012C564(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7004858, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 1, 11, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7004008, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 16, 18, 17, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 22, 20, 0, 23, 11, 24, 0);
    gSP2Triangles(gfx++, 8, 7, 25, 0, 26, 8, 25, 0);
    gSP2Triangles(gfx++, 27, 4, 3, 0, 27, 3, 28, 0);
    gSP2Triangles(gfx++, 23, 9, 11, 0, 29, 12, 30, 0);
    gSP2Triangles(gfx++, 12, 14, 30, 0, 31, 32, 33, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7004228, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 24, 26, 27, 0, 18, 21, 23, 0);
    gSP2Triangles(gfx++, 18, 23, 28, 0, 22, 29, 23, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 28, 32, 18, 0);
    gSP2Triangles(gfx++, 15, 33, 16, 0, 15, 34, 33, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 37, 40, 38, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 45, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 53, 55, 56, 0);
    gSP2Triangles(gfx++, 57, 58, 6, 0, 59, 60, 61, 0);
    gSP2Triangles(gfx++, 60, 14, 61, 0, 62, 0, 2, 0);
    gSPVertex(gfx++, D_7004618, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 3, 5, 0, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 9, 11, 6, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 12, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 16, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7003DE8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 8, 9, 0, 5, 9, 6, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7003EC8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSPVertex(gfx++, D_7003F48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7004918, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 1, 0, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7004758, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_70047F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_7004A08[];
extern Vtx D_7004AC8[];
extern Vtx D_7004B48[];
extern Vtx D_7004D48[];
extern Vtx D_7005128[];
extern Vtx D_7005248[];
extern Vtx D_70052E8[];
extern Vtx D_7005348[];
extern Vtx D_7005428[];

Gfx* func_i9_8012CD8C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7005348, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7004B48, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 0, 2, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7004D48, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 8, 11, 13, 0, 8, 13, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 18, 25, 8, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 28, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 31, 0);
    gSP2Triangles(gfx++, 37, 38, 35, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 36, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 45, 0, 47, 45, 41, 0);
    gSP2Triangles(gfx++, 49, 37, 0, 0, 50, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 56, 57, 58, 0);
    gSP2Triangles(gfx++, 1, 59, 37, 0, 43, 60, 32, 0);
    gSP2Triangles(gfx++, 41, 45, 44, 0, 41, 44, 61, 0);
    gSPVertex(gfx++, D_7005128, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 3, 5, 0, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 9, 11, 6, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7005428, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7004A08, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7004AC8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7005248, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_70052E8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_7005488[];
extern Vtx D_70054C8[];
extern Vtx D_7005648[];
extern Vtx D_70058D8[];

Gfx* func_i9_8012D524(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70054C8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 6, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 10, 16, 11, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7005648, 41, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 4, 0);
    gSP2Triangles(gfx++, 25, 26, 4, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 35, 36, 33, 0, 37, 38, 39, 0);
    gSP1Triangle(gfx++, 39, 40, 37, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70058D8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7005488, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_7005938[];
extern Vtx D_7005968[];
extern Vtx D_7005AB8[];

Gfx* func_i9_8012D7CC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7005968, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7005AB8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 0, 7, 0, 8, 3, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7005938, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3003468[];
extern Vtx D_30034E8[];
extern Vtx D_3003758[];
extern Vtx D_30037D8[];
extern Vtx D_3003918[];
extern Vtx D_3003978[];
extern Vtx D_3003D58[];
extern Vtx D_30040F8[];
extern Vtx D_3004238[];
extern s16 D_800CE784;
extern f32 D_800CF160[];
extern OSMesgQueue D_800DCAB0;
void func_i2_801039BC(s32);

Gfx* func_i9_8012D998(Gfx* gfx) {
    OSMesg sp1AC;
    s32 temp_v1;
    s32 var_a1;
    u32 var_a0;

    osRecvMesg(&D_800DCAB0, &sp1AC, OS_MESG_NOBLOCK);
    osRecvMesg(&D_800DCAB0, &sp1AC, OS_MESG_BLOCK);
    var_a0 = 0;
    var_a1 = 0;
    while (var_a0 < 2) {
        while (IO_READ(0x4600010) & 3) {}

        temp_v1 = IO_READ(0x10000510);
        if (temp_v1 == var_a1) {
            var_a0++;
        } else {
            var_a0 = 0;
        }
        var_a1 = temp_v1;
    }

    if (temp_v1 & 1) {
        D_800CE784++;
        if (D_800CE784 >= 13) {
            D_800CF160[0] = D_800CF160[1] = D_800CF160[2] = D_800CF160[3] = D_800CF160[4] = 1.0f;
            func_i2_801039BC(var_a0);
        }
    }

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30040F8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3004238, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 13, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 3, 0, 21, 14, 16, 0);
    gSP2Triangles(gfx++, 21, 15, 14, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 0, 0, 6, 31, 30, 0);
    gSP2Triangles(gfx++, 32, 6, 30, 0, 27, 33, 28, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 8, 37, 35, 0);
    gSP2Triangles(gfx++, 8, 35, 34, 0, 8, 7, 37, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3003918, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3003758, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3003978, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 2, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 3, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 9, 6, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 25, 19, 26, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 26, 0, 18, 31, 19, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 34, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 13, 12, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 50, 49, 51, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 53, 55, 56, 0, 57, 44, 33, 0);
    gSP2Triangles(gfx++, 57, 33, 58, 0, 57, 58, 59, 0);
    gSP1Triangle(gfx++, 60, 61, 40, 0);
    gSPVertex(gfx++, D_3003D58, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 10, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 18, 0, 21, 18, 22, 0);
    gSP2Triangles(gfx++, 21, 19, 18, 0, 23, 17, 19, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 19, 24, 0);
    gSP2Triangles(gfx++, 22, 26, 27, 0, 18, 26, 22, 0);
    gSP2Triangles(gfx++, 18, 28, 26, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 36, 38, 37, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 42, 40, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 46, 44, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 50, 48, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 26, 56, 27, 0);
    gSP1Triangle(gfx++, 56, 55, 57, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3003468, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_30034E8, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 9, 11, 0, 12, 11, 13, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 0, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 20, 22, 23, 0, 24, 20, 23, 0);
    gSP2Triangles(gfx++, 22, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 22, 26, 31, 0);
    gSP2Triangles(gfx++, 32, 24, 23, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 33, 35, 36, 0, 33, 37, 38, 0);
    gSP2Triangles(gfx++, 33, 38, 34, 0, 0, 19, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30037D8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7005C18[];
extern Vtx D_7005C78[];
extern Vtx D_7005CF8[];
extern Vtx D_7005DE8[];
extern Vtx D_7005E48[];
extern Vtx D_7006238[];
extern Vtx D_7006548[];
extern Vtx D_7006688[];
extern Vtx D_70066C8[];
extern Vtx D_7006788[];

Gfx* func_i9_8012E4E4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70066C8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7006788, 35, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 12, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 7, 29, 30, 0, 7, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 4, 33, 0, 34, 32, 33, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7005DE8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7005C18, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7005E48, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 3, 5, 6, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 22, 25, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 25, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 32, 30, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 33, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 38, 41, 42, 0);
    gSP2Triangles(gfx++, 38, 42, 39, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 61, 60, 59, 0);
    gSP1Triangle(gfx++, 61, 59, 62, 0);
    gSPVertex(gfx++, D_7006238, 49, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 6, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 14, 11, 15, 0, 14, 12, 11, 0);
    gSP2Triangles(gfx++, 16, 10, 12, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 16, 12, 14, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 11, 23, 15, 0, 11, 24, 23, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 37, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 38, 44, 45, 0);
    gSP1Triangle(gfx++, 46, 47, 48, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7005C78, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7005CF8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 8, 11, 12, 0, 13, 14, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7006548, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 12, 10, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);
    gSPVertex(gfx++, D_7006688, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_70069B8[];
extern Vtx D_7006A38[];
extern Vtx D_7006B08[];
extern Vtx D_7006ED8[];
extern Vtx D_7006F38[];
extern Vtx D_7007078[];
extern Vtx D_70070D8[];
extern Vtx D_7007198[];

Gfx* func_i9_8012ECF4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70070D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7007198, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7006ED8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7007078, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7006B08, 61, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 4, 10, 0);
    gSP2Triangles(gfx++, 4, 11, 5, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 20, 19, 21, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 22, 21, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 24, 27, 25, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 40, 43, 41, 0, 44, 40, 42, 0);
    gSP2Triangles(gfx++, 41, 43, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 47, 49, 48, 0, 50, 51, 52, 0);
    gSP2Triangles(gfx++, 50, 53, 51, 0, 54, 55, 56, 0);
    gSP2Triangles(gfx++, 57, 58, 59, 0, 0, 2, 60, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70069B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7006A38, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 4, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 7, 11, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7006F38, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 0, 2, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7007378[];
extern Vtx D_70073B8[];
extern Vtx D_7007418[];
extern Vtx D_70074B8[];
extern Vtx D_7007578[];

Gfx* func_i9_8012F30C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70074B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7007578, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 18, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 14, 16, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70073B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7007378, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7007418, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 0, 2, 9, 0);

    return gfx;
}

extern Vtx D_7007778[];
extern Vtx D_70077B8[];
extern Vtx D_7007878[];

Gfx* func_i9_8012F608(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70077B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7007878, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 1, 10, 0);
    gSP1Triangle(gfx++, 11, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7007778, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

// #pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012F7BC.s")
extern Vtx D_3005358[];
extern Vtx D_30054E8[];
extern Vtx D_3005568[];
extern Vtx D_3005708[];
extern Vtx D_3005AE8[];
extern Vtx D_3005B88[];
extern Vtx D_3005C08[];
extern Vtx D_3005DA8[];
extern Vtx D_3005DF8[];

Gfx* func_i9_8012F7BC(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3005DF8, 40, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 2, 1, 4, 0, 3, 5, 6, 0);
    gSP2Triangles(gfx++, 4, 3, 6, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 6, 5, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 12, 11, 13, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 14, 13, 15, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 17, 18, 0);
    gSP2Triangles(gfx++, 16, 15, 18, 0, 18, 17, 19, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 22, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 25, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 0, 0);
    gSP2Triangles(gfx++, 39, 37, 0, 0, 0, 38, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_30054E8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 1, 7, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3005708, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 5, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 10, 12, 0);
    gSP2Triangles(gfx++, 5, 7, 9, 0, 8, 9, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 15, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 25, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 39, 41, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 56, 57, 10, 0);
    gSP2Triangles(gfx++, 17, 58, 18, 0, 59, 60, 61, 0);
    gSPVertex(gfx++, D_3005AE8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3005B88, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 0, 2, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3005DA8, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP1Triangle(gfx++, 0, 4, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3005358, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 3, 4, 0, 0, 0, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 9, 10, 8, 0, 10, 11, 8, 0);
    gSP2Triangles(gfx++, 12, 8, 11, 0, 1, 0, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 13, 17, 1, 0);
    gSP2Triangles(gfx++, 11, 18, 12, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 13, 0, 0, 5, 23, 0, 0);
    gSP1Triangle(gfx++, 24, 6, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_3005568, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 4, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3005C08, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 0, 10, 1, 0, 11, 7, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 16, 18, 25, 0);

    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801300FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80130840.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80130E44.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80131130.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801312F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80131D18.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013251C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80132B40.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80132E04.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80132F44.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80133744.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80133E58.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80134468.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80134734.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80134880.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80135180.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80135894.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80135F5C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801361B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80136350.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80136C74.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013737C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80137968.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80137C68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80137DBC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801387D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80138F38.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801394EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801397B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013996C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013A25C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013A9A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013AFD4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013B34C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013B57C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013BD04.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013C360.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013C8EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013CC0C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013CED0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013D814.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013DF88.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013E5A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013E964.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013EB2C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013F248.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013F8E0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8013FF20.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801403C4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014061C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80140E54.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80141590.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80141BC8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80141ECC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80142078.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80142950.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80143080.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801436A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80143BB8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80143E40.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80144518.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80144B30.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801450C4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014553C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80145860.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80145F34.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014651C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80146A4C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80146DB8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80147074.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801479B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014812C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80148778.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80148BF0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80148E3C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801495B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80149CBC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014A31C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014A6D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014A98C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014B174.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014B874.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014BE8C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014C32C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014C5D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014CD1C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014D3A0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014D9A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014DE64.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014E104.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014E8E0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014EFAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014F580.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014FA30.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8014FCC0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80150414.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80150AEC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801511A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015156C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801517FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80151FE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801526BC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80152CA8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801531A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80153538.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80153BD4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80154234.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015483C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80154CE4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80154F14.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801556FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80155EB8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801564E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801569C8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80156CAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80157390.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80157A50.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015805C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801584F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80158800.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80158EEC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801595B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80159BE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80159F7C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015A1B4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015AAE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015B1F4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015B7E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015BC90.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015BF44.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015C634.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015CD18.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015D344.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015D814.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015DA94.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015E268.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015E910.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015EE84.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015F214.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015F46C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8015FC70.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80160314.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801608D8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80160D90.s")

extern u16 D_3006178[];
extern u16 D_3006A78[];
extern u16 D_3008A18[];
extern void* D_i9_80168A70[];
extern void* D_i9_80168A90[];
extern void* D_i9_80168AA4[];

Gfx* func_i9_80161050(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_i9_80168A70[arg1], 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                      G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_i9_80168AA4[arg2], 0x110, 2, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_i9_80168A90[arg3], 0x150, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x160, 4, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x180, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x1C0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801614D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8016197C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80161C78.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80161FF8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80162370.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80162768.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80162B08.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80162FE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80163374.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801636F4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80163BAC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80163F28.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801642A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80164608.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8016497C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80164E34.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80165124.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80165494.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80165858.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80165D28.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801660BC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80166468.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801667F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80166CF4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80167068.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80167530.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80167898.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80167C1C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801680E8.s")

extern u16 D_3004498[];
extern u16 D_3004598[];
extern u16 D_3004698[];
extern u16 D_3004718[];
extern u16 D_3004918[];
extern u16 D_3004B18[];
extern u16 D_3004D18[];

Gfx* func_i9_801685B4(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPLoadMultiBlock(gfx++, D_3004918, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                      G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0x50, 2, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004598, 0x60, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004718, 0x70, 4, G_IM_FMT_I, 64, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 6, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004498, 0xB0, 5, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004D18, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0x110, 7, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}
