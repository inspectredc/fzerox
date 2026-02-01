#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"
#include "fzx_game.h"
#include "fzx_font.h"
#include "fzx_machine.h"
#include "fzx_bordered_box.h"
#include ASSET_HEADER(machine_models.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(overlays/machine_create/machine_create_assets.h)

Vp gMachinePartViewports[3][7];
unk_801413F0 D_xk3_801413F0[2];
unk_801413F0* D_xk3_801414B0;

Gfx* sCustomMachinePartDLs[][7] = {
    { D_9015400, D_9015938, D_9015658, D_9014B40, D_9014DE0, D_9015088, D_90148F8 },
    { D_9015B58, D_9017350, D_9016DA0, D_9015F50, D_9016298, D_9016530, D_9016948 },
    { D_90186C0, D_9017B18, D_9018230, D_9017BF0, D_90183F0, D_9017D20, D_9017EC8 },
};

const char* sCharacterNamesByNumber[] = {
    "MM ガゼル",
    "ジョディ サマー",
    "ドクター スチュワート",
    "ババ",
    "サムライ ゴロー",
    "ピコ",
    "キャプテン ファルコン",
    "オクトマン",
    "ミスター EAD",
    "ジェームズ マクラウド",
    "ビリー",
    "ケイト アレン",
    "ゾーダ",
    "ジャック レビン",
    "バイオレックス",
    "アービン ゴードン",
    "アントニオ ガスター",
    "ビーストマン",
    "レオン",
    "スーパー アロー",
    "ミセス アロー",
    "ゴマー&シオー",
    "シルバー ニールセン",
    "マイケル チェーン",
    "ブラッド ファルコン",
    "ジョン タナカ",
    "ドラク",
    "ロジャー バスター",
    "ドクター クラッシュ",
    "ブラック シャドー",
};

Gfx* (*sSuperMachineDrawFuncs[])(Gfx*) = {
    Machine_DrawSuperFalconLod1,   Machine_DrawSuperFalconLod1, Machine_DrawSuperFalconLod1,
    Machine_DrawSuperStingrayLod1, Machine_DrawSuperCatLod1,
};

Gfx* (*sSuperMachineLoadTextureFuncs[])(Gfx*) = {
    Machine_DrawLoadBlueFalconTextures,   Machine_DrawLoadBlueFalconTextures, Machine_DrawLoadBlueFalconTextures,
    Machine_DrawLoadFireStingrayTextures, Machine_DrawLoadWhiteCatTextures,
};

const u8 kCharacterNumbers[] = {
    7, 3, 6, 5, 2, 1, 4, 8, 29, 9, 15, 11, 23, 22, 26, 21, 25, 14, 10, 13, 24, 20, 12, 28, 19, 27, 18, 17, 30, 16,
};

const char* gSuperMachineNames[] = {
    "SUPER FALCON", "X", "X", "SUPER STINGRAY", "SUPER CAT",
};

u8* sMachineWeightNumberTexs[] = {
    aMachineCreateWeight0Tex, aMachineCreateWeight1Tex, aMachineCreateWeight2Tex, aMachineCreateWeight3Tex,
    aMachineCreateWeight4Tex, aMachineCreateWeight5Tex, aMachineCreateWeight6Tex, aMachineCreateWeight7Tex,
    aMachineCreateWeight8Tex, aMachineCreateWeight9Tex,
};

u16 sPartsTextPositions[][7][2] = {
    { { 23, 70 }, { 62, 70 }, { 101, 70 }, { 140, 70 }, { 179, 70 }, { 218, 70 }, { 257, 70 } },
    { { 23, 107 }, { 62, 107 }, { 101, 107 }, { 140, 107 }, { 179, 107 }, { 218, 107 }, { 257, 107 } },
    { { 23, 144 }, { 62, 144 }, { 101, 144 }, { 140, 144 }, { 179, 144 }, { 218, 144 }, { 257, 144 } },
};

u16 sPartsLeftPositions[][7] = {
    { 23, 62, 101, 140, 179, 218, 257 },
    { 23, 62, 101, 140, 179, 218, 257 },
    { 23, 62, 101, 140, 179, 218, 257 },
};

u8 sPartsTopPositions[][7] = {
    { 40, 40, 40, 40, 40, 40, 40 },
    { 77, 77, 77, 77, 77, 77, 77 },
    { 114, 114, 114, 114, 114, 114, 114 },
};

u16 sPartsRightPositions[][7] = {
    { 62, 101, 140, 179, 218, 257, 296 },
    { 62, 101, 140, 179, 218, 257, 296 },
    { 62, 101, 140, 179, 218, 257, 296 },
};

u8 sPartsBottomPositions[][7] = {
    { 77, 77, 77, 77, 77, 77, 77 },
    { 114, 114, 114, 114, 114, 114, 114 },
    { 151, 151, 151, 151, 151, 151, 151 },
};

const u16 kSuperMachineWeights[] = {
    790, 0, 0, 2210, 1840,
};

const u8 kSuperMachineStatValues[][3] = {
    { 4, 3, 4 }, { 0, 0, 0 }, { 0, 0, 0 }, { 3, 4, 4 }, { 4, 4, 3 },
};

const u8 kSuperMachineEnvColors[][3] = {
    { 223, 199, 33 }, { 0, 0, 0 }, { 0, 0, 0 }, { 55, 55, 55 }, { 33, 55, 137 },
};

Gfx* MachineCreate_DrawTextureBlockRGBA16(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width - 1) << 2, (top + height - 1) << 2, 0, 0, 0,
                        4 * (1 << 10), 1 << 10);

    return gfx;
}

Gfx* MachineCreate_DrawTextureTileRGBA16(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height, u8 uls,
                                         u8 ult, u8 lrs, u8 lrt) {

    gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, uls, ult, lrs, lrt, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + uls) << 2, (top + ult) << 2, (left + lrs) << 2, (top + lrt) << 2, 0, uls << 5,
                        ult << 5, 4 * (1 << 10), 1 << 10);

    return gfx;
}

Gfx* MachineCreate_DrawTextureBlockI4(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

Gfx* MachineCreate_DrawTextureBlockI8(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

Gfx* MachineCreate_DrawFloatTextureBlockI8(Gfx* gfx, TexturePtr texture, f32 left, f32 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (u16) (left * 4.0f), (u16) (top * 4.0f), (u16) ((left + width) * 4.0f),
                        (u16) ((top + height) * 4.0f), 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern Gfx D_xk3_80137378[];

Gfx* MachineCreate_DrawMenuItem(Gfx* gfx, TexturePtr texture1, TexturePtr texture2, u16 left, u16 top, u8 width,
                                u8 height, u8 red, u8 green, u8 blue) {

    gSPDisplayList(gfx++, D_xk3_80137378);
    gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, texture1, left, top, width, height);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetTextureFilter(gfx++, G_TF_POINT);
    gfx = MachineCreate_DrawTextureBlockI4(gfx, texture2, left, top, width, height);

    return gfx;
}

Gfx* MachineCreate_DrawColorGradientTextureBlockI8(Gfx* gfx, u8* texture, u16 left, u16 top, u8 width, u8 height,
                                                   u8 startR, u8 startG, u8 startB, u8 endR, u8 endG, u8 endB) {
    u8 temp_s1;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;

    for (i = 0; i < height; i++) {
        temp_s1 = (height - i) - 1;
        red = Math_Round((f32) ((startR * temp_s1) + (endR * i)) / (height - 1));
        green = Math_Round((f32) ((startG * temp_s1) + (endG * i)) / (height - 1));
        blue = Math_Round((f32) ((startB * temp_s1) + (endB * i)) / (height - 1));
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);

        gDPLoadTextureBlock(gfx++, texture + width * i, G_IM_FMT_I, G_IM_SIZ_8b, width, 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, (top + i) << 2, (left + width) << 2, (top + i + 1) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
    }
    return gfx;
}

Gfx* MachineCreate_DrawColorGradientRectangle(Gfx* gfx, u16 left, u16 top, u16 right, u16 bottom, f32 startR,
                                              f32 startG, f32 startB, f32 endR, f32 endG, f32 endB) {
    u16 temp_s1;
    u16 height;
    u16 i;
    u8 red;
    u8 green;
    u8 blue;

    height = (bottom - top) + 1;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (i = 0; i < height; i++) {
        temp_s1 = (height - i) - 1;
        red = Math_Round(((temp_s1 * startR) + (endR * i)) / (height - 1));
        green = Math_Round(((temp_s1 * startG) + (endG * i)) / (height - 1));
        blue = Math_Round(((temp_s1 * startB) + (endB * i)) / (height - 1));
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
        gDPFillRectangle(gfx++, left, top + i, right + 1, top + i + 1);
    }
    return gfx;
}

void func_xk3_8012F594(void) {
}

s32 MachineCreate_CharacterSlotFromNumber(s32 number) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (number == kCharacterNumbers[i]) {
            return Character_GetCharacterFromSlot(i);
        }
    }

    return 0;
}

extern unk_800792D8* D_xk3_80136E60[];

void func_xk3_8012F5F0(Object* arg0) {
    OBJECT_CACHE_INDEX(arg0) = func_800792D8(D_xk3_80136E60[0]);
    OBJECT_STATE(arg0) = -1;
}

extern unk_800E3F28 D_800D63F8[];

Gfx* func_xk3_8012F628(Gfx* gfx, Object* arg1) {

    if (gWorksMachineMode != MACHINE_MODE_ENTRY) {
        gfx = func_80078F80_impl(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(arg1)], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0,
                                 0, 1.0f, 1.0f, false);
    }
    return gfx;
}

extern u8 D_xk1_800333F0;
extern u8 D_800333F4;
extern CustomMachine gCustomMachine;

void func_xk3_8012F6A8(Object* arg0) {
    s32 temp_v1;
    s32 character;
    s32 var_v0;
    u8 temp_a0;

    if (gWorksMachineMode == MACHINE_MODE_ENTRY) {
        return;
    }

    if (D_xk1_800333F0 != 0) {
        if (OBJECT_STATE(arg0) != (D_800333F4 + 30)) {
            character = Character_GetCharacterFromSlot(D_800333F4) + 30;
            if (character >= 36) {
                character %= 30;
            }
            func_800793E8(OBJECT_CACHE_INDEX(arg0), 0, D_xk3_80136E60[character]);
        }
        OBJECT_STATE(arg0) = D_800333F4 + 30;
    } else {
        if (OBJECT_STATE(arg0) != (gCustomMachine.number - 1)) {
            func_800793E8(OBJECT_CACHE_INDEX(arg0), 0,
                          D_xk3_80136E60[MachineCreate_CharacterSlotFromNumber(gCustomMachine.number)]);
        }
        OBJECT_STATE(arg0) = gCustomMachine.number - 1;
    }
}

extern u8* D_xk3_801372B8[];

void func_xk3_8012F7AC(Gfx** gfxP, char* arg1) {
    Gfx* gfx;
    u16 sp6A;
    u16 sp68;
    u8 sp67;
    char sp44[35];
    u8 sp43 = 0;

    gfx = *gfxP;
    if (mfsStrLen(arg1) >= 9) {
        sp43 = 1;
    }
    func_xk1_80026830(arg1, &sp44);
    if (sp43) {
        sp67 = mfsStrLen(&sp44) + mfsStrLen(D_xk3_801372B8[10]);
        sp6A = ((((34 - sp67) / 2) + 3) * 8);
        sp68 = 46;

        gfx = func_xk1_8002EA10(gfx, sp6A, sp68, sp6A + (sp67 * 8), 124 - sp68, GPACK_RGBA5551(130, 130, 255, 1));
    } else {
        sp67 = mfsStrLen(&sp44) + mfsStrLen(D_xk3_801372B8[10]) + mfsStrLen(D_xk3_801372B8[11]);
        sp6A = ((((34 - sp67) / 2) + 3) * 8);
        sp68 = 54;
        gfx = func_xk1_8002EA10(gfx, sp6A, sp68, sp6A + (sp67 * 8), 124 - sp68, GPACK_RGBA5551(130, 130, 255, 1));
    }

    gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 255);
    gfx = func_xk1_800262F4(gfx, sp6A, sp68, &sp44);
    sp6A += mfsStrLen(&sp44) * 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    if (sp43) {
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[10]);
        sp68 += 16;
        sp6A = (((((34 - sp67) / 2) + 3) * 8));
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[11]);
    } else {
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[10]);
        sp6A += 16;
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[11]);
    }

    func_xk1_8002D340(&gfx);
    *gfxP = gfx;
}

extern Gfx D_xk3_801373F0[];
extern u8 D_xk3_80138930[];
extern u8 aMachineCreateKgTex[];

Gfx* MachineCreate_DrawWeight(Gfx* gfx, s32 left, s32 top, s32 weight) {
    u8 i;
    signed char weighStr[4];

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = MachineCreate_DrawTextureBlockI8(gfx, D_xk3_80138930, left, top, 32, 16);
    if (weight < 1000) {
        left += 41;
    } else {
        left += 33;
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    sprintf(weighStr, "%d", weight);
    i = 0;
    while (weighStr[i] != 0) {
        gfx = MachineCreate_DrawTextureBlockI8(gfx, sMachineWeightNumberTexs[weighStr[i] - '0'], left, top, 8, 16);
        i++;
        left += 8;
    }

    left++;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateKgTex, left, top, 16, 16);

    return gfx;
}

Gfx* MachineCreate_DrawWeightAndName(Gfx* gfx, s32 weight, s8* characterName) {

    gfx = MachineCreate_DrawWeight(gfx, 170, 190, weight);
    gfx = Font_DrawString(gfx, 252 - Font_GetStringWidth(characterName, 4, 0), 219, characterName, 0, 4, 0);
    gfx = Object_UpdateAndDrawAll(gfx);
    func_800790D4();
    return gfx;
}

extern f32 D_xk3_80136540;

Gfx* MachineCreate_SetupWingTextureColor(Gfx* gfx, u8 bodyR, u8 bodyG, u8 bodyB, u8 decalR, u8 decalG, u8 decalB) {

    if (!((D_xk3_80136540 >= -100.0f) && (D_xk3_80136540 <= 100.0f))) {
        bodyR *= 0.8f;
        bodyG *= 0.8f;
        bodyB *= 0.8f;
        decalR *= 0.8f;
        decalG *= 0.8f;
        decalB *= 0.8f;
    }

    if (gCustomMachine.decal == MACHINE_DECAL(DECAL_BLOCK)) {
        gDPSetPrimColor(gfx++, 0, 0, decalR, decalG, decalB, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, bodyR, bodyG, bodyB, 255);
    }
    return gfx;
}

extern s32 D_xk3_80141294;

extern unk_80140E60 D_xk3_80140E60;

Gfx* func_xk3_801301B4(Gfx* gfx) {
    u8 i;
    u8 j;

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gfx = MachineCreate_SetupWingTextureColor(gfx, gCustomMachine.red, gCustomMachine.green, gCustomMachine.blue,
                                              gCustomMachine.decalR, gCustomMachine.decalG, gCustomMachine.decalB);
    gfx = MachineCreate_DrawFloatTextureBlockI8(gfx, aMachineCreateWing1Tex, 117.5f, 125.0f, 8, 5);
    gfx = MachineCreate_DrawFloatTextureBlockI8(gfx, aMachineCreateWing2Tex, 78.5f, 125.0f, 8, 5);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateFrontTex,
                                           sPartsTextPositions[MACHINE_PART_FRONT][gCustomMachine.frontType][0],
                                           sPartsTextPositions[MACHINE_PART_FRONT][gCustomMachine.frontType][1], 40, 8);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateRearTex,
                                           sPartsTextPositions[MACHINE_PART_REAR][gCustomMachine.rearType][0],
                                           sPartsTextPositions[MACHINE_PART_REAR][gCustomMachine.rearType][1], 40, 8);
    gfx = MachineCreate_DrawTextureBlockI8(gfx, aMachineCreateWingTex,
                                           sPartsTextPositions[MACHINE_PART_WING][gCustomMachine.wingType][0],
                                           sPartsTextPositions[MACHINE_PART_WING][gCustomMachine.wingType][1], 40, 8);
    gfx = MachineCreate_DrawWeight(gfx, 150, 155, D_xk3_80141294);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            gfx = ExpansionKit_DrawRectangleBorder(gfx, sPartsLeftPositions[i][j], sPartsTopPositions[i][j],
                                                   sPartsRightPositions[i][j], sPartsBottomPositions[i][j],
                                                   GPACK_RGBA5551(100, 100, 100, 1), 1, 1);
        }
    }
    gfx = ExpansionKit_DrawRectangleBorder(gfx, sPartsLeftPositions[MACHINE_PART_FRONT][gCustomMachine.frontType],
                                           sPartsTopPositions[MACHINE_PART_FRONT][gCustomMachine.frontType],
                                           sPartsRightPositions[MACHINE_PART_FRONT][gCustomMachine.frontType],
                                           sPartsBottomPositions[MACHINE_PART_FRONT][gCustomMachine.frontType],
                                           GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    gfx = ExpansionKit_DrawRectangleBorder(gfx, sPartsLeftPositions[MACHINE_PART_REAR][gCustomMachine.rearType],
                                           sPartsTopPositions[MACHINE_PART_REAR][gCustomMachine.rearType],
                                           sPartsRightPositions[MACHINE_PART_REAR][gCustomMachine.rearType],
                                           sPartsBottomPositions[MACHINE_PART_REAR][gCustomMachine.rearType],
                                           GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    gfx = ExpansionKit_DrawRectangleBorder(gfx, sPartsLeftPositions[MACHINE_PART_WING][gCustomMachine.wingType],
                                           sPartsTopPositions[MACHINE_PART_WING][gCustomMachine.wingType],
                                           sPartsRightPositions[MACHINE_PART_WING][gCustomMachine.wingType],
                                           sPartsBottomPositions[MACHINE_PART_WING][gCustomMachine.wingType],
                                           GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    if (D_xk3_80140E60.unk_04 == 3) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateHighlightedOkTex, 264, 155, 32, 16);
    } else {
        gfx = ExpansionKit_DrawRectangleBorderHighlight(
            gfx, sPartsLeftPositions[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00],
            sPartsTopPositions[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00],
            sPartsRightPositions[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00],
            sPartsBottomPositions[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00], 255, 64, 64, func_xk1_800290C0(), 2,
            2);
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aMachineCreateOkTex, 264, 155, 32, 16);
    }
    return gfx;
}

extern unk_801413F0* D_xk3_801414B0;
extern GfxPool* gGfxPool;

Gfx* func_xk3_80130698(Gfx* gfx, s32 arg1) {
    MtxF spC0;
    MtxF sp80;

    gDPPipeSync(gfx++);
    gSPDisplayList(gfx++, D_90186C8);

    switch (arg1) {
        case 0:
            Matrix_FromMtx(gGfxPool->unk_20108, &sp80);
            Light_SetLookAtSource(&gGfxPool->unk_21B28, &sp80);
            gSPLookAt(gfx++, &gGfxPool->unk_21B28);
            break;
        case 1:
            Matrix_SetLookAt(NULL, &spC0, D_xk3_80136540, 0.0f, 1320.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            Light_SetLookAtSource(&D_xk3_801414B0->unk_40, &spC0);
            gSPLookAt(gfx++, &D_xk3_801414B0->unk_40);
            break;
    }

    gSPTexture(gfx++, 1250, 1250, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 80);
    return gfx;
}

extern f32 D_xk3_80140E78;
extern f32 D_xk3_80140E7C;
extern GfxPool D_1000000;

Gfx* func_xk3_80130920(Gfx* gfx) {
    u16 spBE;

    if (gWorksMachineMode == MACHINE_MODE_PARTS) {
        gSPViewport(gfx++, &aMachineCreatePartsTogetherViewport);
    } else {
        gSPViewport(gfx++, &gGfxPool->unk_2C2C8[1]);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 25, 90, 153, 218);
    }

    gSPDisplayList(gfx++, D_xk3_801374A8);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPDisplayList(gfx++, D_xk3_80137538);

    Matrix_SetFrustrum(gGfxPool->unk_20008, NULL, 44.0f, 10.0f, 12800.0f, 320.0f, 0.0f, 240.0f, 0.0f, &spBE);
    Matrix_SetLookAt(gGfxPool->unk_20108, NULL, 0.0f, 880.0f, 1320.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Matrix_SetTransRot(&gGfxPool->unk_20308[1], NULL, 1.0f, Math_Round(DEG_TO_FZXANG2(D_xk3_80140E78)), 0, 0, 0.0f,
                       0.0f, 0.0f);
    Matrix_SetTransRot(&gGfxPool->unk_20308[2], NULL, 1.0f, 0, Math_Round(DEG_TO_FZXANG2(D_xk3_80140E7C)), 0, 0.0f,
                       0.0f, 0.0f);

    gSPMatrix(gfx++, &D_1000000.unk_20008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gfx++, spBE);
    gSPMatrix(gfx++, &D_1000000.unk_20308[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gfx++, &D_1000000.unk_20308[1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (D_xk1_800333F0 != 0) {
        gfx = sSuperMachineLoadTextureFuncs[D_800333F4](gfx);
        gDPSetEnvColor(gfx++, kSuperMachineEnvColors[D_800333F4][0], kSuperMachineEnvColors[D_800333F4][1],
                       kSuperMachineEnvColors[D_800333F4][2], 255);
        gfx = sSuperMachineDrawFuncs[D_800333F4](gfx);
    } else {
        gfx = Machine_DrawLoadCustomTextures(gfx, gCustomMachine.logo - 1, gCustomMachine.number - 1,
                                             gCustomMachine.decal - 1);
        gDPSetEnvColor(gfx++, gCustomMachine.red, gCustomMachine.green, gCustomMachine.blue, 255);
        gfx = Machine_DrawCustom(gfx, 0, gCustomMachine.frontType, gCustomMachine.rearType, gCustomMachine.wingType,
                                 gCustomMachine.decalR, gCustomMachine.decalG, gCustomMachine.decalB,
                                 gCustomMachine.numberR, gCustomMachine.numberG, gCustomMachine.numberB, 255, 255, 255,
                                 gCustomMachine.cockpitR, gCustomMachine.cockpitG, gCustomMachine.cockpitB);
    }
    gfx = func_xk3_80130698(gfx, 0);
    gDPSetRenderMode(gfx++, G_RM_ZB_OVL_SURF, G_RM_ZB_OVL_SURF2);

    if (D_xk1_800333F0 != 0) {
        switch (D_800333F4) {
            case CAPTAIN_FALCON:
                gSPDisplayList(gfx++, D_9012718);
                break;
            case SAMURAI_GOROH:
                gSPDisplayList(gfx++, D_9013460);
                break;
            case JODY_SUMMER:
                gSPDisplayList(gfx++, D_9013D58);
                break;
        }
    } else {
        gSPDisplayList(gfx++, sCustomMachinePartDLs[MACHINE_PART_FRONT][gCustomMachine.frontType]);
        gSPDisplayList(gfx++, sCustomMachinePartDLs[MACHINE_PART_REAR][gCustomMachine.rearType]);
        gSPDisplayList(gfx++, sCustomMachinePartDLs[MACHINE_PART_WING][gCustomMachine.wingType]);
    }
    if (gWorksMachineMode != MACHINE_MODE_PARTS) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }
    return gfx;
}

extern FrontMachineDraw sFrontMachineDrawFuncs[][5];
extern RearMachineDraw sRearMachineDrawFuncs[][5];
extern WingMachineDraw sWingMachineDrawFuncs[][5];
extern Gfx D_xk3_80137570[];

Gfx* func_xk3_80130EE0(Gfx* gfx) {
    u8 j;
    u8 i;

    gSPDisplayList(gfx++, D_xk3_801374A8);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPDisplayList(gfx++, D_xk3_80137570);
    gfx = Machine_DrawLoadCustomTextures(gfx, gCustomMachine.logo - 1, gCustomMachine.number - 1,
                                         gCustomMachine.decal - 1);
    Matrix_SetLookAt(&gGfxPool->unk_20108[1], NULL, 0.0f, 0.0f, 2000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Matrix_SetTransRot(&gGfxPool->unk_20308[3], NULL, 1.0f, 0x400, 0, 0, 0.0f, 0.0f, 0.0f);
    Matrix_SetOrtho(&D_xk3_801414B0->unk_00, NULL, 1.0f, -1550.0f, 1550.0f, -1550.0f, 1550.0f, 10.0f, 12800.0f);

    gSPMatrix(gfx++, &D_xk3_801414B0->unk_00, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20108[1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_20308[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            if ((i == MACHINE_PART_WING) && (j < 3)) {
                continue;
            }
            gSPViewport(gfx++, &gMachinePartViewports[i][j]);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, gCustomMachine.red, gCustomMachine.green, gCustomMachine.blue, 255);
            switch (i) {
                case MACHINE_PART_FRONT:
                    if (j == FRONT_3) {
                        gDPPipeSync(gfx++);
                        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
                    }
                    gfx = sFrontMachineDrawFuncs[j][0](
                        gfx, gCustomMachine.decalR, gCustomMachine.decalG, gCustomMachine.decalB,
                        gCustomMachine.numberR, gCustomMachine.numberG, gCustomMachine.numberB, 255, 255, 255,
                        gCustomMachine.cockpitR, gCustomMachine.cockpitG, gCustomMachine.cockpitB);

                    if (j == FRONT_3) {
                        gDPPipeSync(gfx++);
                        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_OPA_SURF2);
                    }
                    break;
                case MACHINE_PART_REAR:
                    switch (j) {
                        case REAR_2:
                        case REAR_3:
                        case REAR_6:
                            gDPPipeSync(gfx++);
                            gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
                            break;
                    }
                    gfx = sRearMachineDrawFuncs[j][0](gfx, gCustomMachine.decalR, gCustomMachine.decalG,
                                                      gCustomMachine.decalB, gCustomMachine.numberR,
                                                      gCustomMachine.numberG, gCustomMachine.numberB);

                    switch (j) {
                        case REAR_2:
                        case REAR_3:
                        case REAR_6:
                            gDPPipeSync(gfx++);
                            gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_OPA_SURF2);
                            break;
                    }
                    break;
                case MACHINE_PART_WING:
                    gfx = sWingMachineDrawFuncs[j][0](gfx, gCustomMachine.decalR, gCustomMachine.decalG,
                                                      gCustomMachine.decalB, gCustomMachine.numberR,
                                                      gCustomMachine.numberG, gCustomMachine.numberB);
                    break;
            }
        }
    }
    gfx = func_xk3_80130698(gfx, 1);
    gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            if ((i == MACHINE_PART_WING) && (j < 3)) {
                continue;
            }
            gSPViewport(gfx++, &gMachinePartViewports[i][j]);
            gSPDisplayList(gfx++, sCustomMachinePartDLs[i][j]);
        }
    }
    return gfx;
}

extern u8 aCreateMachineMarkTex[];
extern u8 aCreateMachineColorTex[];
extern u8 aCreateMachineBodyTex[];
extern u8 aCreateMachineLineTex[];
extern u8 aCreateMachineNumberTex[];
extern u8 aCreateMachineCockpitTex[];
extern u8 D_4001500[];
extern u8 aCreateMachineUseTex[];
extern u8 aCreateMachineClearTex[];

extern u8 D_xk3_80136548;
extern u8 D_xk3_8013654C;
extern s32 D_xk3_80136658;
extern s32 D_xk3_80136664;
extern s32 D_xk3_8013666C;
extern MenuWidget gMachineCreateWidget;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;

extern CustomMachinesInfo gCustomMachinesInfo;
extern BorderedBoxWidget* gMachineCreateColorBox;
extern char* D_xk3_80141298;

Gfx* func_xk3_80131494(Gfx* gfx) {
    static f32 D_xk3_8013680C = 0.0f;
    static s8 D_xk3_80136810 = 1;
    f32 colorInfo[6];
    f32 var_fv0;
    u16 color;
    u8 i;
    s32 pad;

    if (gWorksMachineMode == MACHINE_MODE_PARTS) {
        var_fv0 = 0.001f;
    } else {
        var_fv0 = 0.0025f;
    }

    if (D_xk3_80136810 == 1) {
        D_xk3_8013680C += var_fv0;
        if (D_xk3_8013680C >= 1.0f) {
            D_xk3_8013680C = 1.0f;
            D_xk3_80136810 = -1;
        }
    } else {
        D_xk3_8013680C -= var_fv0;
        if (D_xk3_8013680C <= 0.0f) {
            D_xk3_8013680C = 0.0f;
            D_xk3_80136810 = 1;
        }
    }

    colorInfo[0] = ((1.0f - D_xk3_8013680C) * (50.0f - 50.0f)) + (D_xk3_8013680C * 50.0f);
    colorInfo[1] = ((1.0f - D_xk3_8013680C) * (75.0f - 75.0f)) + (D_xk3_8013680C * 75.0f);
    colorInfo[2] = ((1.0f - D_xk3_8013680C) * (165.0f - 165.0f)) + (D_xk3_8013680C * 165.0f);
    colorInfo[3] = ((1.0f - D_xk3_8013680C) * (150.0f - 150.0f)) + (D_xk3_8013680C * 150.0f);
    colorInfo[4] = ((1.0f - D_xk3_8013680C) * (180.0f - 180.0f)) + (D_xk3_8013680C * 180.0f);
    colorInfo[5] = ((1.0f - D_xk3_8013680C) * (200.0f - 100.0f)) + (D_xk3_8013680C * 200.0f);

    gSPLoadUcodeL(gfx++, gspF3DEX2_Rej_fifo);
    gSPClipRatio(gfx++, FRUSTRATIO_5);
    gSPDisplayList(gfx++, D_xk3_80137378);
    gDPLoadTextureBlock(gfx++, D_xk3_80137590, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 28, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, 12 << 2, 8 << 2, 307 << 2, 27 << 2, 0, 12 << 5, 8 << 5, 4 * (1 << 10), 1 << 10);

    for (i = 1; i < 8; i++) {
        gSPTextureRectangle(gfx++, 12 << 2, (i * 28) << 2, 307 << 2, (i * 28 + 27) << 2, 0, 12 << 5, 0, 4 * (1 << 10),
                            1 << 10);
    }

    gSPTextureRectangle(gfx++, 12 << 2, 224 << 2, 307 << 2, 231 << 2, 0, 12 << 5, 0, 4 * (1 << 10), 1 << 10);

    if (gWorksMachineMode == MACHINE_MODE_PARTS) {
        gfx = func_xk3_80130920(gfx);
        gfx = MachineCreate_DrawColorGradientRectangle(gfx, 24, 41, 295, 76, colorInfo[0], colorInfo[1], colorInfo[2],
                                                       colorInfo[3], colorInfo[4], colorInfo[5]);
        gfx = MachineCreate_DrawColorGradientRectangle(gfx, 24, 78, 295, 113, colorInfo[0], colorInfo[1], colorInfo[2],
                                                       colorInfo[3], colorInfo[4], colorInfo[5]);
        gfx = MachineCreate_DrawColorGradientRectangle(gfx, 24, 115, 295, 150, colorInfo[0], colorInfo[1], colorInfo[2],
                                                       colorInfo[3], colorInfo[4], colorInfo[5]);
        gfx = func_xk3_80130EE0(gfx);
        gfx = func_xk3_801301B4(gfx);
    } else {
        gfx = MachineCreate_DrawColorGradientRectangle(gfx, 25, 90, 152, 217, colorInfo[0], colorInfo[1], colorInfo[2],
                                                       colorInfo[3], colorInfo[4], colorInfo[5]);
        if (D_xk3_80136548) {
            color = GPACK_RGBA5551(255, 70, 70, 1);
        } else {
            color = GPACK_RGBA5551(255, 255, 255, 1);
        }
        gfx = ExpansionKit_DrawRectangleBorder(gfx, 24, 89, 153, 218, color, 1, 1);

        switch (gWorksMachineMode) {
            case MACHINE_MODE_BODY_COLOR:
            case MACHINE_MODE_LINE_COLOR:
            case MACHINE_MODE_NUMBER_COLOR:
            case MACHINE_MODE_COCKPIT_COLOR:
                if (!BorderedBox_GetInfo(gMachineCreateColorBox, IS_BORDERED_BOX_OPENED)) {
                    gfx = func_xk3_80135474(gfx);
                }
                break;
            default:
                gfx = func_xk3_80135474(gfx);
                break;
        }

        gSPDisplayList(gfx++, D_xk3_801373F0);

        gfx = MachineCreate_DrawColorGradientTextureBlockI8(gfx, aMachineCreateMachineNameTex, 170, 82, 48, 12, 255,
                                                            255, 0, 255, 120, 0);
        gfx = MachineCreate_DrawColorGradientTextureBlockI8(gfx, aMachineCreateSettingsTex, 170, 118, 72, 12, 255, 255,
                                                            0, 255, 120, 0);
        gSPDisplayList(gfx++, D_xk3_80137378);
        if (D_xk1_800333F0 != 0) {
            gfx = MachineCreate_DrawTextureTileRGBA16(gfx, D_xk3_8013B280, 178, 97, 120, 16, 0, 0, 59, 15);
            gfx = MachineCreate_DrawTextureTileRGBA16(gfx, D_xk3_8013B280, 178, 97, 120, 16, 60, 0, 119, 15);
            gSPDisplayList(gfx++, D_xk3_801373F0);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_xk1_8002924C(gfx, 182, 101, "%s", gSuperMachineNames[D_800333F4]);
            if ((D_800333F4 == CAPTAIN_FALCON) && (gCustomMachinesInfo.characterCustomState[CAPTAIN_FALCON] == -1)) {
                gfx =
                    MachineCreate_DrawWeightAndName(gfx, kSuperMachineWeights[D_800333F4], sCharacterNamesByNumber[6]);
            } else if ((D_800333F4 == SAMURAI_GOROH) &&
                       (gCustomMachinesInfo.characterCustomState[SAMURAI_GOROH] == -1)) {
                gfx =
                    MachineCreate_DrawWeightAndName(gfx, kSuperMachineWeights[D_800333F4], sCharacterNamesByNumber[4]);
            } else if ((D_800333F4 == JODY_SUMMER) && (gCustomMachinesInfo.characterCustomState[JODY_SUMMER] == -1)) {
                gfx =
                    MachineCreate_DrawWeightAndName(gfx, kSuperMachineWeights[D_800333F4], sCharacterNamesByNumber[1]);
            } else {
                gfx = MachineCreate_DrawWeight(gfx, 200, 195, kSuperMachineWeights[D_800333F4]);
            }
        } else {
            gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, D_xk3_8013A980, 190, 97, 72, 16);
            if ((gWorksMachineMode != MACHINE_MODE_MNAME) && (gCustomMachine.machineName[0] != 0)) {
                gSPDisplayList(gfx++, D_xk3_801373F0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = func_xk1_8002924C(gfx, 194, 101, "%s", gCustomMachine.machineName);
            }

            if (gCustomMachine.number != 31) {
                gfx = MachineCreate_DrawWeightAndName(gfx, D_xk3_80141294,
                                                      sCharacterNamesByNumber[gCustomMachine.number - 1]);
            } else {
                gfx = MachineCreate_DrawWeight(gfx, 200, 195, D_xk3_80141294);
            }
        }
        gfx = func_xk3_80130920(gfx);
        switch (gWorksMachineMode) {
            case MACHINE_MODE_MNAME:
                gfx = ExpansionKit_NameEntryDraw(gfx, NULL, NULL);
                break;
            case MACHINE_MODE_LOAD_SELECT_FILE:
            case MACHINE_MODE_DELETE_SELECT_FILE:
            case MACHINE_MODE_ENTRY_SELECT_FILE:
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE:
                gfx = func_xk1_8002C420(gfx, 88, 54);
                gfx = func_xk1_8002B17C(gfx, 8);
                break;
            case MACHINE_MODE_LOAD_SELECT_SUPER:
            case MACHINE_MODE_ENTRY_SELECT_SUPER:
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER:
                gfx = func_xk1_8002C420(gfx, 88, 54);
                gfx = func_xk1_8002B17C(gfx, 14);
                break;
            case MACHINE_MODE_LOAD_CONFIRM:
                func_xk1_8002C720(&gfx, 88, 54, D_xk3_80141298, 0);
                func_xk1_8002D340(&gfx);
                break;
            case MACHINE_MODE_DELETE_CONFIRM:
                func_xk1_8002C720(&gfx, 88, 54, D_xk3_80141298, 2);
                func_xk1_8002D340(&gfx);
                break;
            case MACHINE_MODE_CHECKSUM_ERROR:
                func_xk1_8002C720(&gfx, 88, 90, D_xk3_80141298, 2);
                func_xk1_8002D340(&gfx);
                break;
            case MACHINE_MODE_ENTRY_CLEAR_CONFIRM:
            case MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM:
                func_xk3_8012F7AC(&gfx, D_xk3_80141298);
                break;
        }
        gfx = BorderedBox_Draw(gfx);
    }

    if (D_xk3_80136548) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx =
            MachineCreate_DrawTextureTileRGBA16(gfx, aExpansionKitPauseInstructionsTex, 48, 20, 224, 32, 0, 0, 63, 31);
        gfx = MachineCreate_DrawTextureTileRGBA16(gfx, aExpansionKitPauseInstructionsTex, 48, 20, 224, 32, 64, 0, 127,
                                                  31);
        gfx = MachineCreate_DrawTextureTileRGBA16(gfx, aExpansionKitPauseInstructionsTex, 48, 20, 224, 32, 128, 0, 191,
                                                  31);
        gfx = MachineCreate_DrawTextureTileRGBA16(gfx, aExpansionKitPauseInstructionsTex, 48, 20, 224, 32, 192, 0, 223,
                                                  31);
    } else {
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        func_xk1_800276B0(&gfx, &gMachineCreateWidget, D_xk3_80140E50, D_xk3_80140E54);
        switch (gWorksMachineMode) {
            case MACHINE_MODE_LOAD_GET_FILE:
            case MACHINE_MODE_LOAD_SELECT_FILE:
            case MACHINE_MODE_LOAD_SELECT_SUPER:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_4001500, 168,
                                                 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_DELETE_GET_FILE:
            case MACHINE_MODE_DELETE_SELECT_FILE:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_xk3_80138CB0,
                                                 168, 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_ENTRY_GET_FILE:
            case MACHINE_MODE_ENTRY_SELECT_FILE:
            case MACHINE_MODE_ENTRY_SELECT_SUPER:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuBlueBorderHighlightBackgroundTex,
                                                 aCreateMachineUseTex, 216, 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE:
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuBlueBorderHighlightBackgroundTex,
                                                 aCreateMachineClearTex, 216, 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_MNAME:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_xk3_80138B30,
                                                 168, 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_SELECT_LINE:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
                                                 aCreateMachineLineTex, 72, 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_SELECT_MARK:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
                                                 aCreateMachineMarkTex, 72, 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_MENU_COLOR:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBackgroundTex, aCreateMachineColorTex, 72,
                                                 36, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_BODY_COLOR:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBackgroundTex, aCreateMachineColorTex, 72,
                                                 36, 48, 16, 0, 0, 0);
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
                                                 aCreateMachineBodyTex, 72, 52, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_LINE_COLOR:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBackgroundTex, aCreateMachineColorTex, 72,
                                                 36, 48, 16, 0, 0, 0);
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
                                                 aCreateMachineLineTex, 72, 52, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_NUMBER_COLOR:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBackgroundTex, aCreateMachineColorTex, 72,
                                                 36, 48, 16, 0, 0, 0);
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
                                                 aCreateMachineNumberTex, 72, 52, 48, 16, 0, 0, 0);
                break;
            case MACHINE_MODE_COCKPIT_COLOR:
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBackgroundTex, aCreateMachineColorTex, 72,
                                                 36, 48, 16, 0, 0, 0);
                gfx = MachineCreate_DrawMenuItem(gfx, aExpansionKitMenuGoldBorderHighlightBackgroundTex,
                                                 aCreateMachineCockpitTex, 72, 52, 48, 16, 0, 0, 0);
                break;
        }
        gSPDisplayList(gfx++, D_xk3_80137378);
        if (D_xk3_8013654C) {
            gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aExpansionKitMenuExitHighlightTex, 265, 20, 32, 16);
        } else {
            gfx = MachineCreate_DrawTextureBlockRGBA16(gfx, aExpansionKitMenuExitTex, 265, 20, 32, 16);
        }
    }

    return gfx;
}
