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

Gfx* func_i9_80115F38(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801162D4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80116604(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801168F8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7038578, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80116B48(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80116CF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80117168(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801174E4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801177F4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80117A18(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80117BFC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801180D0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80118494(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801187D8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039A88, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80118A3C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039C28, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80118C74(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_801190F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_7039C58, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80119470(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 1, 0, TEXEL0, 0, 0, 0, 0, 1, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703A0D8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011974C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80119980(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_80119F20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703AB78, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011A2C8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703AE88, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011A62C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B0E8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011A8A8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B298, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011AAD0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032AD8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 1, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 3, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 7, 3, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 8, 11, 10, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011AFE8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B308, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011B47C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B6C8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 5, 3, 0, 5, 6, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011B8E4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B9B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 1, 5, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703B978, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011BC3C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BC08, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 1, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703BBC8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011BF1C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033268, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011C398(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C078, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011C810(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C378, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011CBF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C628, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C3B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

Gfx* func_i9_8011CF20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_703C788, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 5, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011D5EC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011DA60.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011DE24.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011E1A0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011E40C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011E89C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011EC68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011F02C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011F3F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011F704.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011FACC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011FEB0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80120298.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801205FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80120910.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80120E14.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801212E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801217BC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80121B68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80121E60.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801223BC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012290C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80122DDC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012311C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80123384.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801238FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80123E08.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801242E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80124664.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012498C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80125030.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801255F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80125AC4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80125E48.s")

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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801261E0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801262C0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012638C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126440.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126544.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126648.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126718.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801267E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126950.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126AA4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126BE4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126CCC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80126D98.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127044.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012720C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801273A4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127508.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801275CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127704.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127808.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801278F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801279C0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127A74.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127C28.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127D68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127E70.s")

Gfx* func_i9_80127F40(Gfx* gfx, s32 red, s32 green, s32 blue, s32 arg4, s32 arg5, s32 arg6) {
    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80127F54.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801289DC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801292C0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80129974.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80129D04.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80129FC4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012A8B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012B010.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012B6C4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012B9C4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012BB50.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012C564.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012CD8C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012D524.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012D7CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012D998.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012E4E4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012ECF4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012F30C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012F608.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8012F7BC.s")

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
