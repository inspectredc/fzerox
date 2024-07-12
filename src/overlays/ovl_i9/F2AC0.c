#include "global.h"

typedef Gfx* (*unk_i9_80168B20)(Gfx*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef Gfx* (*unk_i9_80168BAC)(Gfx*, s32, s32, s32, s32, s32, s32);

extern unk_i9_80168B20 D_i9_80168B20[][5];
extern unk_i9_80168BAC D_i9_80168BAC[][5];
extern unk_i9_80168BAC D_i9_80168C38[][5];

Gfx* func_i9_80115DF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, s32 argE, s32 argF, s32 arg10) {
    gfx = D_i9_80168C38[arg4][arg1](gfx, arg5, arg6, arg7, arg8, arg9, argA);
    gfx = D_i9_80168BAC[arg3][arg1](gfx, arg5, arg6, arg7, arg8, arg9, argA);
    gfx = D_i9_80168B20[arg2][arg1](gfx, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, argF, arg10);
    return gfx;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80115F38.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801162D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80116604.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801168F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80116B48.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80116CF0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80117168.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801174E4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801177F4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80117A18.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80117BFC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801180D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80118494.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801187D8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80118A3C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80118C74.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_801190F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80119470.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011974C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80119980.s")

extern Vtx D_30326F8[];
extern Vtx D_3032738[];
extern Vtx D_3032778[];
extern Vtx D_3032878[];
extern Vtx D_3032A58[];

Gfx* func_i9_80119B6C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3032A58, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_80119F20.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011A2C8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011A62C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011A8A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011AAD0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011AFE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011B47C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011B8E4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011BC3C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011BF1C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011C398.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011C810.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011CBF0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i9/F2AC0/func_i9_8011CF20.s")

extern Vtx D_30332A8[];
extern Vtx D_3033308[];
extern Vtx D_3033468[];
extern Vtx D_30334A8[];
extern Vtx D_3033548[];
extern Vtx D_3033708[];

Gfx* func_i9_8011D154(Gfx* gfx, s32 red1, s32 green1, s32 blue1, s32 red2, s32 green2, s32 blue2) {

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPVertex(gfx++, D_3033708, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red1, green1, blue1, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, 0, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
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

    gDPLoadMultiBlock(gfx++, D_i9_80168A70[arg1], 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_i9_80168AA4[arg2], 0x110, 2, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_i9_80168A90[arg3], 0x150, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x160, 4, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x180, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x1C0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    
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
    gDPLoadMultiBlock(gfx++, D_3004918, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0x50, 2, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004598, 0x60, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004718, 0x70, 4, G_IM_FMT_I, 64, 16, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 6, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004498, 0xB0, 5, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004D18, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0x110, 7, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}
