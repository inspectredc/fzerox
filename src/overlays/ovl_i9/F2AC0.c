#include "global.h"

s32 D_i9_80168CD0; // some unused bss exists in the file

typedef Gfx* (*unk_i9_80168B20)(Gfx*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef Gfx* (*unk_i9_80168BAC)(Gfx*, s32, s32, s32, s32, s32, s32);

extern u8 D_302BE38[];
extern u8 D_302C638[];
extern u8 D_302CE38[];
extern u8 D_302D638[];
extern u8 D_302DE38[];
extern u8 D_302E638[];
extern u8 D_302EE38[];
extern u8 D_302F638[];
extern u8 D_302FE38[];
extern u8 D_302FEB8[];
extern u8 D_302FF38[];
extern u8 D_302FFB8[];
extern u8 D_3030038[];
extern u8 D_30302B8[];
extern u8 D_30304B8[];
extern u8 D_30306B8[];
extern u8 D_30308B8[];
extern u8 D_3030AB8[];
extern u8 D_3030CB8[];
extern u8 D_3030EB8[];
extern u8 D_30310B8[];
extern u8 D_30312B8[];
extern u8 D_3016758[];
extern u8 D_30293C8[];
extern u8 D_3013ED8[];
extern u8 D_3023158[];
extern u8 D_301C898[];
extern u8 D_3026E68[];
extern u8 D_302A708[];
extern u8 D_3018498[];
extern u8 D_3021F78[];
extern u8 D_30175D8[];
extern u8 D_301DE58[];
extern u8 D_301F128[];
extern u8 D_3012CC8[];
extern u8 D_3025BB8[];
extern u8 D_301B5B8[];
extern u8 D_302B7F8[];
extern u8 D_3011578[];
extern u8 D_30283C8[];
extern u8 D_3015218[];
extern u8 D_3024B78[];
extern u8 D_301A068[];
extern u8 D_30300B8[];

TexturePtr D_i9_80168A70[] = {
    D_302BE38, D_302C638, D_302CE38, D_302D638, D_302DE38, D_302E638, D_302EE38, D_302F638,
};

TexturePtr D_i9_80168A90[] = {
    D_302FE38, D_302FEB8, D_302FF38, D_302FFB8, D_3030038,
};

TexturePtr D_i9_80168AA4[] = {
    D_30302B8, D_30304B8, D_30306B8, D_30308B8, D_3030AB8, D_3030CB8, D_3030EB8, D_30310B8,
    D_30312B8, D_3016758, D_30293C8, D_3013ED8, D_3023158, D_301C898, D_3026E68, D_302A708,
    D_3018498, D_3021F78, D_30175D8, D_301DE58, D_301F128, D_3012CC8, D_3025BB8, D_301B5B8,
    D_302B7F8, D_3011578, D_30283C8, D_3015218, D_3024B78, D_301A068, D_30300B8,
};

Gfx* func_i9_80119B6C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80119F20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011A2C8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011A62C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011A8A8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011BF1C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011C398(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011C810(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011CBF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011CF20(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011AAD0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011AFE8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011B47C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011B8E4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011BC3C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80116CF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80117168(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801174E4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801177F4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80117A18(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80117BFC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801180D0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80118494(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801187D8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80118A3C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80118C74(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801190F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80119470(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_8011974C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80119980(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80115F38(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801162D4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80116604(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_801168F8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);
Gfx* func_i9_80116B48(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8,
                      s32 arg9, s32 argA, s32 argB, s32 argC);

unk_i9_80168B20 D_i9_80168B20[][5] = {
    { func_i9_80119B6C, func_i9_80119F20, func_i9_8011A2C8, func_i9_8011A62C, func_i9_8011A8A8 },
    { func_i9_8011BF1C, func_i9_8011C398, func_i9_8011C810, func_i9_8011CBF0, func_i9_8011CF20 },
    { func_i9_8011AAD0, func_i9_8011AFE8, func_i9_8011B47C, func_i9_8011B8E4, func_i9_8011BC3C },
    { func_i9_80116CF0, func_i9_80117168, func_i9_801174E4, func_i9_801177F4, func_i9_80117A18 },
    { func_i9_80117BFC, func_i9_801180D0, func_i9_80118494, func_i9_801187D8, func_i9_80118A3C },
    { func_i9_80118C74, func_i9_801190F0, func_i9_80119470, func_i9_8011974C, func_i9_80119980 },
    { func_i9_80115F38, func_i9_801162D4, func_i9_80116604, func_i9_801168F8, func_i9_80116B48 },
};

Gfx* func_i9_8011D154(Gfx* gfx, s32 red1, s32 green1, s32 blue1, s32 red2, s32 green2, s32 blue2);
Gfx* func_i9_8011D5EC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011DA60(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011DE24(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011E1A0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8012498C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80125030(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801255F8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80125AC4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80125E48(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80123384(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801238FC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80123E08(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801242E8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80124664(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011E40C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011E89C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011EC68(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011F02C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011F3F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011F704(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011FACC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8011FEB0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80120298(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801205FC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80120910(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80120E14(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801212E8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801217BC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80121B68(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80121E60(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801223BC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8012290C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80122DDC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8012311C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

unk_i9_80168BAC D_i9_80168BAC[][5] = {
    { func_i9_8011D154, func_i9_8011D5EC, func_i9_8011DA60, func_i9_8011DE24, func_i9_8011E1A0 },
    { func_i9_8012498C, func_i9_80125030, func_i9_801255F8, func_i9_80125AC4, func_i9_80125E48 },
    { func_i9_80123384, func_i9_801238FC, func_i9_80123E08, func_i9_801242E8, func_i9_80124664 },
    { func_i9_8011E40C, func_i9_8011E89C, func_i9_8011EC68, func_i9_8011F02C, func_i9_8011F3F0 },
    { func_i9_8011F704, func_i9_8011FACC, func_i9_8011FEB0, func_i9_80120298, func_i9_801205FC },
    { func_i9_80120910, func_i9_80120E14, func_i9_801212E8, func_i9_801217BC, func_i9_80121B68 },
    { func_i9_80121E60, func_i9_801223BC, func_i9_8012290C, func_i9_80122DDC, func_i9_8012311C },
};

Gfx* func_i9_80127F40(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801260FC(Gfx* gfx, s32 red, s32 green, s32 blue, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801261E0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801262C0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8012638C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801275CC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127704(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127808(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801278F0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126440(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126544(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126648(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126718(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127A74(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127C28(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127D68(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127E70(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801267E8(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126950(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126AA4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126BE4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126CCC(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80126D98(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127044(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_8012720C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_801273A4(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Gfx* func_i9_80127508(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

unk_i9_80168BAC D_i9_80168C38[][5] = {
    { func_i9_80127F40, func_i9_80127F40, func_i9_80127F40, func_i9_80127F40, func_i9_80127F40 },
    { func_i9_801260FC, func_i9_801261E0, func_i9_801262C0, func_i9_8012638C, func_i9_8012638C },
    { func_i9_801275CC, func_i9_80127704, func_i9_80127808, func_i9_801278F0, func_i9_801278F0 },
    { func_i9_80126440, func_i9_80126544, func_i9_80126648, func_i9_80126718, func_i9_80126718 },
    { func_i9_80127A74, func_i9_80127C28, func_i9_80127D68, func_i9_80127E70, func_i9_80127E70 },
    { func_i9_801267E8, func_i9_80126950, func_i9_80126AA4, func_i9_80126BE4, func_i9_80126CCC },
    { func_i9_80126D98, func_i9_80127044, func_i9_8012720C, func_i9_801273A4, func_i9_80127508 },
};

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

extern Vtx D_7007958[];
extern Vtx D_7007AC8[];
extern Vtx D_7007C08[];
extern Vtx D_7007D48[];
extern Vtx D_7007D88[];
extern Vtx D_7007E08[];
extern Vtx D_7007FA8[];
extern Vtx D_70081F8[];

Gfx* func_i9_801300FC(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70081F8, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 3, 0, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 8, 0, 15, 9, 8, 0);
    gSP2Triangles(gfx++, 16, 17, 14, 0, 17, 18, 14, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 23, 32, 0, 33, 29, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 38, 36, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7007AC8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 7, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7007D48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7007D88, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7007FA8, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 6, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 18, 0, 21, 0, 2, 0);
    gSP2Triangles(gfx++, 3, 5, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 26, 24, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 30, 28, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 32, 0, 31, 34, 32, 0);
    gSP1Triangle(gfx++, 34, 36, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7007958, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 6, 0);
    gSP2Triangles(gfx++, 7, 11, 12, 0, 13, 5, 14, 0);
    gSP2Triangles(gfx++, 15, 2, 16, 0, 17, 16, 2, 0);
    gSP2Triangles(gfx++, 2, 18, 19, 0, 1, 18, 2, 0);
    gSP2Triangles(gfx++, 5, 20, 3, 0, 21, 20, 5, 0);
    gSP1Triangle(gfx++, 5, 13, 22, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7007C08, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 19, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7007E08, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 21, 19, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 25, 23, 0);

    return gfx;
}

extern Vtx D_7008468[];
extern Vtx D_7008578[];
extern Vtx D_7008618[];
extern Vtx D_7008718[];
extern Vtx D_7008908[];
extern Vtx D_7008988[];
extern Vtx D_7008B28[];

Gfx* func_i9_80130840(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7008B28, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 2, 1, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 8, 10, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 14, 13, 18, 0, 19, 16, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7008578, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 0, 9, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7008718, 31, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 25, 23, 0);
    gSP2Triangles(gfx++, 22, 26, 25, 0, 19, 21, 27, 0);
    gSP1Triangle(gfx++, 28, 29, 30, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7008908, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 0, 2, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7008468, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 1, 0, 11, 0);
    gSP2Triangles(gfx++, 11, 12, 1, 0, 9, 13, 10, 0);
    gSP2Triangles(gfx++, 10, 14, 7, 0, 4, 15, 0, 0);
    gSP1Triangle(gfx++, 16, 5, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7008618, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 4, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7008988, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 11, 13, 0, 23, 24, 25, 0);

    return gfx;
}

extern Vtx D_7008C68[];
extern Vtx D_7008CA8[];
extern Vtx D_7008DC8[];
extern Vtx D_7008E28[];
extern Vtx D_7008EA8[];

Gfx* func_i9_80130E44(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7008EA8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 2, 1, 4, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 7, 6, 8, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7008CA8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 0, 11, 1, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7008DC8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7008C68, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7008E28, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    return gfx;
}

extern Vtx D_7008FA8[];
extern Vtx D_7008FD8[];
extern Vtx D_7009038[];

Gfx* func_i9_80131130(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7009038, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 6, 8, 0);
    gSP2Triangles(gfx++, 8, 7, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 13, 12, 14, 0, 13, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7008FD8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7008FA8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_30070B8[];
extern Vtx D_30072D8[];
extern Vtx D_3007478[];
extern Vtx D_30077F8[];
extern Vtx D_30078D8[];
extern Vtx D_3007918[];
extern Vtx D_3007C18[];
extern Vtx D_3007CD8[];

Gfx* func_i9_801312F0(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3007918, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 7, 0, 8, 5, 9, 0);
    gSP2Triangles(gfx++, 2, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 3, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 6, 1, 0, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 3, 16, 4, 0, 12, 23, 13, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 25, 31, 26, 0);
    gSP2Triangles(gfx++, 30, 29, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 25, 34, 31, 0, 33, 32, 35, 0);
    gSP2Triangles(gfx++, 33, 35, 36, 0, 37, 38, 20, 0);
    gSP2Triangles(gfx++, 37, 20, 18, 0, 36, 35, 39, 0);
    gSP2Triangles(gfx++, 36, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 40, 39, 44, 0, 40, 44, 45, 0);
    gSP2Triangles(gfx++, 41, 46, 42, 0, 45, 44, 28, 0);
    gSP2Triangles(gfx++, 45, 28, 27, 0, 41, 47, 46, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3007CD8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 0, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 7, 0, 10, 4, 3, 0);
    gSP2Triangles(gfx++, 10, 11, 4, 0, 11, 12, 4, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 16, 14, 0);
    gSP2Triangles(gfx++, 17, 8, 18, 0, 8, 19, 18, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3007478, 56, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 1, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 4, 3, 0);
    gSP2Triangles(gfx++, 8, 9, 4, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 10, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 18, 20, 19, 0);
    gSP2Triangles(gfx++, 6, 5, 21, 0, 5, 22, 21, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 24, 26, 25, 0);
    gSP2Triangles(gfx++, 27, 28, 23, 0, 28, 24, 23, 0);
    gSP2Triangles(gfx++, 29, 20, 18, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 30, 32, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 34, 36, 37, 0, 35, 38, 36, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 39, 42, 43, 0);
    gSP2Triangles(gfx++, 39, 43, 40, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 47, 0, 47, 46, 48, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 49, 48, 50, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 51, 50, 52, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 53, 52, 54, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 55, 54, 45, 0);
    gSP1Triangle(gfx++, 55, 45, 44, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3007C18, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 0, 11, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 215, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30078D8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_30070B8, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 10, 13, 14, 0, 10, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 16, 19, 20, 0, 16, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 29, 27, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 30, 32, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_30077F8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 3, 0, 4, 3, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30072D8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);

    return gfx;
}

extern Vtx D_7009138[];
extern Vtx D_70092F8[];
extern Vtx D_70093F8[];
extern Vtx D_7009538[];
extern Vtx D_7009888[];
extern Vtx D_7009968[];
extern Vtx D_70099A8[];
extern Vtx D_7009A68[];

Gfx* func_i9_80131D18(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7009138, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 8, 7, 16, 0, 6, 5, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 15, 14, 24, 0, 14, 19, 24, 0);
    gSP2Triangles(gfx++, 25, 10, 21, 0, 25, 21, 26, 0);
    gSP2Triangles(gfx++, 10, 27, 21, 0, 10, 12, 27, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7009A68, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 0, 8, 1, 0, 0, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 7, 4, 0, 10, 11, 7, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 19, 18, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7009538, 53, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 0, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 13, 12, 0);
    gSP2Triangles(gfx++, 18, 19, 13, 0, 8, 7, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 8, 20, 0);
    gSP2Triangles(gfx++, 16, 15, 25, 0, 15, 26, 25, 0);
    gSP2Triangles(gfx++, 5, 0, 2, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 32, 35, 33, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 39, 40, 0);
    gSP2Triangles(gfx++, 36, 40, 37, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 43, 44, 0, 44, 43, 45, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 46, 45, 47, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 48, 47, 49, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 50, 49, 51, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 52, 51, 42, 0);
    gSP1Triangle(gfx++, 52, 42, 41, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70099A8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 215, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7009968, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70092F8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 4, 7, 8, 0, 4, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 10, 13, 14, 0, 10, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7009888, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 4, 7, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70093F8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_7009BA8[];
extern Vtx D_7009CD8[];
extern Vtx D_7009DB8[];
extern Vtx D_7009EF8[];
extern Vtx D_700A198[];
extern Vtx D_700A1F8[];
extern Vtx D_700A238[];

Gfx* func_i9_8013251C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7009BA8, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 5, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 13, 16, 14, 0);
    gSP2Triangles(gfx++, 10, 5, 17, 0, 8, 18, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700A238, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 19, 17, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 21, 23, 22, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7009EF8, 42, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 3, 4, 1, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 13, 12, 0, 6, 17, 7, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 38, 40, 41, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700A1F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7009CD8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_700A198, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 3, 0, 4, 3, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7009DB8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_700A3B8[];
extern Vtx D_700A438[];
extern Vtx D_700A4A8[];
extern Vtx D_700A4D8[];

Gfx* func_i9_80132B40(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700A3B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 2, 0);
    gSP1Triangle(gfx++, 5, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700A4D8, 45, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 19, 18, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP1Triangle(gfx++, 42, 43, 44, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700A438, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP1Triangle(gfx++, 4, 5, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700A4A8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_700A7A8[];
extern Vtx D_700A7D8[];

Gfx* func_i9_80132E04(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700A7D8, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 1, 11, 0, 8, 12, 2, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700A7A8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3009058[];
extern Vtx D_30090D8[];
extern Vtx D_3009238[];
extern Vtx D_30093A8[];
extern Vtx D_3009428[];
extern Vtx D_30094C8[];
extern Vtx D_3009508[];
extern Vtx D_30098E8[];

Gfx* func_i9_80132F44(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3009508, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 5, 0, 0, 4, 6, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 12, 11, 13, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 14, 13, 15, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 19, 18, 0);
    gSP2Triangles(gfx++, 21, 18, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 11, 10, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 35, 11, 27, 0);
    gSP2Triangles(gfx++, 36, 35, 27, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 32, 31, 41, 0);
    gSP2Triangles(gfx++, 42, 32, 41, 0, 43, 34, 33, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 49, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 58, 59, 60, 0);
    gSP1Triangle(gfx++, 59, 61, 60, 0);
    gSPVertex(gfx++, D_30098E8, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 0, 11, 1, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 13, 17, 0, 18, 16, 17, 0);
    gSP2Triangles(gfx++, 19, 2, 20, 0, 21, 19, 20, 0);
    gSP2Triangles(gfx++, 2, 1, 22, 0, 20, 2, 22, 0);
    gSP2Triangles(gfx++, 22, 1, 11, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 26, 29, 30, 0, 26, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 40, 42, 41, 0, 40, 43, 42, 0);
    gSP2Triangles(gfx++, 39, 44, 40, 0, 45, 46, 47, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_30093A8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_30094C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3009058, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30090D8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 1, 13, 2, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3009238, 23, 0);
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
    gSPVertex(gfx++, D_3009428, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 3, 5, 9, 0);

    return gfx;
}

extern Vtx D_700A908[];
extern Vtx D_700A9A8[];
extern Vtx D_700AB28[];
extern Vtx D_700AC78[];
extern Vtx D_700ACF8[];
extern Vtx D_700AD98[];
extern Vtx D_700ADD8[];
extern Vtx D_700B1D8[];

Gfx* func_i9_80133744(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700ADD8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 5, 0, 0, 4, 6, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 12, 15, 16, 0, 16, 15, 17, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 15, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 31, 0, 32, 22, 26, 0);
    gSP2Triangles(gfx++, 33, 32, 26, 0, 34, 25, 24, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 37, 39, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 49, 0, 52, 53, 41, 0);
    gSP2Triangles(gfx++, 38, 54, 43, 0, 38, 43, 42, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 58, 53, 59, 0);
    gSP2Triangles(gfx++, 60, 58, 59, 0, 53, 61, 62, 0);
    gSP1Triangle(gfx++, 59, 53, 63, 0);
    gSPVertex(gfx++, D_700B1D8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 6, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 21, 19, 0);
    gSP2Triangles(gfx++, 20, 22, 18, 0, 23, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700AC78, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700AD98, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700A908, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700A9A8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 1, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700AB28, 21, 0);
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
    gSPVertex(gfx++, D_700ACF8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 0, 9, 1, 0);

    return gfx;
}

extern Vtx D_700B378[];
extern Vtx D_700B418[];
extern Vtx D_700B538[];
extern Vtx D_700B668[];
extern Vtx D_700B708[];
extern Vtx D_700B748[];

Gfx* func_i9_80133E58(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700B748, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 3, 11, 0, 9, 11, 12, 0);
    gSP2Triangles(gfx++, 12, 11, 13, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 13, 0);
    gSP2Triangles(gfx++, 18, 13, 20, 0, 21, 11, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 19, 18, 21, 0);
    gSP2Triangles(gfx++, 26, 20, 13, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 30, 0);
    gSP2Triangles(gfx++, 35, 36, 30, 0, 28, 27, 32, 0);
    gSP2Triangles(gfx++, 28, 32, 31, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 36, 41, 0, 42, 40, 41, 0);
    gSP2Triangles(gfx++, 36, 0, 43, 0, 41, 36, 44, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 50, 53, 51, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 55, 57, 56, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700B708, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700B378, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700B418, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 2, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 5, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700B538, 19, 0);
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
    gSPVertex(gfx++, D_700B668, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_700BAE8[];
extern Vtx D_700BB48[];
extern Vtx D_700BBA8[];
extern Vtx D_700BC38[];
extern Vtx D_700BCD8[];

Gfx* func_i9_80134468(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700BCD8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 5, 4, 7, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 9, 8, 10, 0);
    gSP2Triangles(gfx++, 11, 9, 10, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP1Triangle(gfx++, 0, 21, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700BAE8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700BB48, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700BBA8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 0, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700BC38, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 3, 5, 9, 0);

    return gfx;
}

extern Vtx D_700BE38[];
extern Vtx D_700BE98[];

Gfx* func_i9_80134734(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700BE98, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 8, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 16, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700BE38, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_300A928[];
extern Vtx D_300AA08[];
extern Vtx D_300AA88[];
extern Vtx D_300ABC8[];
extern Vtx D_300AEC8[];
extern Vtx D_300B2B8[];
extern Vtx D_300B2F8[];
extern Vtx D_300B3B8[];
extern Vtx D_300B518[];

Gfx* func_i9_80134880(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_300B3B8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 7, 17, 0, 14, 18, 15, 0);
    gSP2Triangles(gfx++, 19, 20, 11, 0, 4, 6, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_300ABC8, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 11, 0);
    gSP2Triangles(gfx++, 1, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 18, 20, 19, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 22, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 33, 35, 34, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 37, 39, 38, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 43, 41, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 47, 45, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_300AEC8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 3, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 8, 6, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 13, 12, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 26, 28, 29, 0, 20, 23, 25, 0);
    gSP2Triangles(gfx++, 20, 25, 30, 0, 24, 31, 25, 0);
    gSP2Triangles(gfx++, 30, 32, 33, 0, 30, 33, 20, 0);
    gSP2Triangles(gfx++, 13, 34, 35, 0, 13, 35, 14, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 39, 37, 0);
    gSP2Triangles(gfx++, 36, 40, 39, 0, 14, 35, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 47, 49, 48, 0);
    gSP2Triangles(gfx++, 14, 41, 15, 0, 50, 34, 13, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 51, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 57, 58, 0);
    gSP2Triangles(gfx++, 59, 60, 61, 0, 59, 61, 62, 0);
    gSPVertex(gfx++, D_300B2B8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_300B518, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 2, 1, 0);
    gSP2Triangles(gfx++, 7, 6, 10, 0, 11, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_300A928, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 8, 9, 0, 5, 9, 6, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_300AA08, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_300B2F8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_300AA88, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 3, 12, 13, 0, 14, 15, 2, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_700BFF8[];
extern Vtx D_700C0D8[];
extern Vtx D_700C158[];
extern Vtx D_700C398[];
extern Vtx D_700C728[];
extern Vtx D_700C7C8[];
extern Vtx D_700C828[];
extern Vtx D_700C8E8[];

Gfx* func_i9_80135180(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700C828, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 0, 2, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700C158, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 1, 19, 2, 0);
    gSP2Triangles(gfx++, 4, 20, 6, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 26, 29, 27, 0, 0, 2, 30, 0);
    gSP2Triangles(gfx++, 18, 17, 31, 0, 32, 18, 31, 0);
    gSP2Triangles(gfx++, 33, 14, 13, 0, 33, 34, 35, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700C398, 57, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 10, 11, 9, 0);
    gSP2Triangles(gfx++, 1, 12, 2, 0, 1, 13, 12, 0);
    gSP2Triangles(gfx++, 6, 14, 0, 0, 6, 0, 2, 0);
    gSP2Triangles(gfx++, 15, 14, 6, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 22, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 19, 22, 24, 0);
    gSP2Triangles(gfx++, 19, 24, 29, 0, 23, 30, 24, 0);
    gSP2Triangles(gfx++, 29, 31, 32, 0, 29, 32, 19, 0);
    gSP2Triangles(gfx++, 16, 33, 17, 0, 16, 34, 33, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 37, 40, 38, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 45, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 53, 55, 56, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700BFF8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 8, 9, 0, 5, 9, 6, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700C0D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700C8E8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 8, 0, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700C728, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_700C7C8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_700C9E8[];
extern Vtx D_700CAA8[];
extern Vtx D_700CB28[];
extern Vtx D_700CCF8[];
extern Vtx D_700D058[];
extern Vtx D_700D0F8[];
extern Vtx D_700D158[];
extern Vtx D_700D238[];

Gfx* func_i9_80135894(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700D158, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 12, 13, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700CB28, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 11, 16, 17, 0, 18, 0, 2, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 2, 0, 26, 27, 28, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700CCF8, 54, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 8, 11, 13, 0, 8, 13, 18, 0);
    gSP2Triangles(gfx++, 12, 14, 13, 0, 18, 15, 19, 0);
    gSP2Triangles(gfx++, 18, 19, 8, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 22, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 1, 26, 0, 28, 26, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 1, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 26, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 38, 0, 40, 38, 34, 0);
    gSP2Triangles(gfx++, 42, 30, 0, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 36, 46, 47, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 1, 51, 30, 0, 36, 52, 26, 0);
    gSP2Triangles(gfx++, 34, 38, 37, 0, 34, 37, 53, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700D238, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700C9E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700CAA8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700D058, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_700D0F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_700D298[];
extern Vtx D_700D2D8[];
extern Vtx D_700D438[];
extern Vtx D_700D5D8[];

Gfx* func_i9_80135F5C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700D2D8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 6, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 10, 16, 11, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 10, 18, 19, 0, 20, 21, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700D438, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 4, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 4, 0);
    gSP1Triangle(gfx++, 24, 25, 4, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700D5D8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700D298, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_700D638[];
extern Vtx D_700D668[];
extern Vtx D_700D7B8[];

Gfx* func_i9_801361B8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700D668, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700D7B8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 0, 7, 0, 8, 3, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700D638, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_300BFB8[];
extern Vtx D_300C3B8[];
extern Vtx D_300C608[];
extern Vtx D_300C688[];
extern Vtx D_300C6C8[];
extern Vtx D_300C788[];
extern Vtx D_300C8E8[];
extern Vtx D_300C9C8[];
extern Vtx D_300CB08[];

Gfx* func_i9_80136350(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_300C788, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 4, 0, 0, 2, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 2, 12, 13, 0, 2, 13, 7, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 16, 18, 19, 0, 16, 19, 17, 0);
    gSP2Triangles(gfx++, 20, 5, 21, 0, 5, 6, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_300CB08, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 14, 12, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 34, 32, 0, 35, 36, 37, 0);
    gSP1Triangle(gfx++, 35, 37, 38, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_300C688, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_300BFB8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 11, 10, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 19, 18, 0);
    gSP2Triangles(gfx++, 20, 21, 9, 0, 22, 23, 17, 0);
    gSP2Triangles(gfx++, 24, 23, 25, 0, 3, 5, 26, 0);
    gSP2Triangles(gfx++, 3, 26, 22, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 14, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 34, 36, 37, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 38, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 42, 44, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 46, 0, 57, 56, 48, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 61, 62, 63, 0);
    gSPVertex(gfx++, D_300C3B8, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 2, 6, 7, 0, 8, 6, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 7, 10, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 21, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 25, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 29, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 35, 36, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_300C6C8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 0, 7, 1, 0);
    gSP2Triangles(gfx++, 8, 9, 2, 0, 8, 2, 1, 0);
    gSP2Triangles(gfx++, 4, 3, 10, 0, 3, 11, 10, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_300C608, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 3, 0, 4, 3, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 6, 7, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_300C8E8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_300C9C8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_700D858[];
extern Vtx D_700DBF8[];
extern Vtx D_700DC78[];
extern Vtx D_700DD38[];
extern Vtx D_700DEC8[];
extern Vtx D_700DFA8[];
extern Vtx D_700E0E8[];

Gfx* func_i9_80136C74(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700DD38, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 5, 8, 6, 0, 9, 6, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 11, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 11, 0, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 15, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 21, 23, 24, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 21, 23, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700E0E8, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 18, 16, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 21, 22, 0, 23, 24, 25, 0);
    gSP1Triangle(gfx++, 23, 26, 24, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700D858, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 13, 12, 10, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 11, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 27, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 33, 34, 31, 0);
    gSP2Triangles(gfx++, 35, 34, 33, 0, 32, 36, 33, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 32, 37, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 38, 40, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 43, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 47, 49, 50, 0);
    gSP2Triangles(gfx++, 10, 51, 52, 0, 10, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 54, 56, 57, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700DC78, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 5, 4, 8, 0, 4, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 2, 1, 0, 10, 11, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700DBF8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 0, 2, 0, 4, 2, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 5, 0, 6, 5, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_700DEC8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700DFA8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_700E298[];
extern Vtx D_700E568[];
extern Vtx D_700E5E8[];
extern Vtx D_700E6A8[];
extern Vtx D_700E7A8[];
extern Vtx D_700E7E8[];
extern Vtx D_700E888[];

Gfx* func_i9_8013737C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700E6A8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700E888, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 14, 12, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 22, 20, 0, 0, 23, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700E298, 45, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 5, 6, 1, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 9, 8, 1, 0);
    gSP2Triangles(gfx++, 10, 11, 7, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 16, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 22, 23, 20, 0, 24, 23, 22, 0);
    gSP2Triangles(gfx++, 21, 25, 22, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 21, 26, 28, 0, 27, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 21, 0, 31, 21, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 37, 0);
    gSP2Triangles(gfx++, 1, 38, 39, 0, 1, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 43, 44, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700E5E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 0, 4, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 6, 9, 7, 0, 10, 11, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_700E568, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 4, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 0, 3, 0, 6, 3, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_700E7A8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700E7E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_700EA08[];
extern Vtx D_700EC68[];
extern Vtx D_700ECA8[];
extern Vtx D_700ED48[];

Gfx* func_i9_80137968(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700EA08, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 12, 0, 15, 16, 12, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 2, 4, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 24, 27, 25, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 32, 34, 33, 0);
    gSP1Triangle(gfx++, 35, 36, 37, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700ED48, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 19, 20, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_700EC68, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700ECA8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_700EE98[];
extern Vtx D_700F008[];

Gfx* func_i9_80137C68(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700EE98, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 4, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_700F008, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_300D838[];
extern Vtx D_300D8D8[];
extern Vtx D_300D958[];
extern Vtx D_300DB78[];
extern Vtx D_300DF78[];
extern Vtx D_300E2A8[];
extern Vtx D_300E408[];
extern Vtx D_300E488[];
extern Vtx D_300E548[];

Gfx* func_i9_80137DBC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_300E408, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 0, 2, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_300E488, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_300E548, 54, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 2, 3, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 6, 8, 9, 0, 6, 5, 8, 0);
    gSP2Triangles(gfx++, 10, 7, 11, 0, 3, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 30, 32, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 37, 35, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 39, 41, 40, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 45, 43, 0);
    gSP2Triangles(gfx++, 42, 46, 47, 0, 42, 47, 45, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 48, 52, 49, 0, 48, 53, 52, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_300DB78, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 3, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 2, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 9, 4, 3, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 22, 20, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 24, 26, 25, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 35, 36, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 38, 40, 39, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 45, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 16, 18, 0, 50, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 54, 56, 55, 0);
    gSP2Triangles(gfx++, 57, 58, 59, 0, 57, 60, 58, 0);
    gSP1Triangle(gfx++, 61, 62, 63, 0);
    gSPVertex(gfx++, D_300DF78, 51, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 10, 18, 19, 0, 10, 19, 11, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 7, 36, 8, 0, 37, 30, 29, 0);
    gSP2Triangles(gfx++, 37, 29, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 46, 44, 0, 47, 48, 49, 0);
    gSP1Triangle(gfx++, 48, 50, 49, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_300D838, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_300D8D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_300E2A8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 18, 20, 19, 0, 8, 10, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_300D958, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 32, 33, 0);

    return gfx;
}

extern Vtx D_700F038[];
extern Vtx D_700F0D8[];
extern Vtx D_700F198[];
extern Vtx D_700F578[];
extern Vtx D_700F7C8[];
extern Vtx D_700F908[];
extern Vtx D_700FB48[];

Gfx* func_i9_801387D4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_700F908, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 7, 9, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 15, 0);
    gSP2Triangles(gfx++, 19, 15, 21, 0, 7, 14, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 6, 0, 28, 4, 6, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 5, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 29, 31, 0, 7, 35, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_700F0D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_700FB48, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 2, 3, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 6, 8, 9, 0, 6, 5, 8, 0);
    gSP2Triangles(gfx++, 5, 7, 10, 0, 3, 11, 12, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700F198, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 24, 26, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 28, 30, 0);
    gSP2Triangles(gfx++, 23, 32, 33, 0, 23, 33, 21, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 38, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 50, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 55, 57, 56, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 58, 61, 59, 0);
    gSPVertex(gfx++, D_700F578, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 13, 31, 0, 32, 25, 24, 0);
    gSP2Triangles(gfx++, 32, 24, 33, 0, 34, 35, 36, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700F038, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_700F7C8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_700FC18[];
extern Vtx D_700FCB8[];
extern Vtx D_70100B8[];
extern Vtx D_7010128[];
extern Vtx D_70101C8[];
extern Vtx D_7010408[];

Gfx* func_i9_80138F38(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70101C8, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 27, 25, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 16, 15, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 19, 18, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7010408, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 2, 3, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 6, 8, 9, 0, 6, 5, 8, 0);
    gSP2Triangles(gfx++, 5, 7, 10, 0, 3, 11, 12, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_700FCB8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 2, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 11, 9, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 13, 15, 14, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 29, 31, 30, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 32, 35, 33, 0, 36, 37, 38, 0);
    gSP2Triangles(gfx++, 36, 39, 37, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 41, 43, 42, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 47, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 48, 50, 51, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 52, 54, 55, 0, 56, 57, 58, 0);
    gSP2Triangles(gfx++, 56, 58, 59, 0, 60, 61, 62, 0);
    gSP1Triangle(gfx++, 60, 62, 63, 0);
    gSPVertex(gfx++, D_70100B8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_700FC18, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7010128, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_70104D8[];
extern Vtx D_7010518[];
extern Vtx D_7010878[];
extern Vtx D_70108B8[];

Gfx* func_i9_801394EC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70108B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7010518, 54, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 4, 0);
    gSP2Triangles(gfx++, 17, 18, 10, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 49, 50, 0, 51, 52, 53, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70104D8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7010878, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_7010918[];
extern Vtx D_7010948[];
extern Vtx D_7010AF8[];

Gfx* func_i9_801397B0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7010948, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP1Triangle(gfx++, 24, 25, 26, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7010918, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7010AF8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_300EDE8[];
extern Vtx D_300EF98[];
extern Vtx D_300F398[];
extern Vtx D_300F3D8[];
extern Vtx D_300F4B8[];
extern Vtx D_300F608[];
extern Vtx D_300F778[];
extern Vtx D_300F898[];
extern Vtx D_300F918[];

Gfx* func_i9_8013996C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_300F918, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 12, 14, 0);
    gSP2Triangles(gfx++, 19, 0, 20, 0, 21, 12, 18, 0);
    gSP2Triangles(gfx++, 22, 21, 18, 0, 23, 24, 10, 0);
    gSP2Triangles(gfx++, 23, 10, 7, 0, 25, 26, 27, 0);
    gSP1Triangle(gfx++, 28, 6, 29, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_300F3D8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 0, 2, 11, 0);
    gSP2Triangles(gfx++, 5, 12, 3, 0, 1, 13, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_300F898, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_300EF98, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 9, 0, 14, 15, 4, 0);
    gSP2Triangles(gfx++, 7, 14, 4, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 22, 27, 28, 0, 22, 28, 19, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 29, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 35, 36, 0);
    gSP2Triangles(gfx++, 32, 36, 35, 0, 32, 35, 29, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 37, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 40, 39, 44, 0);
    gSP2Triangles(gfx++, 40, 44, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 45, 49, 50, 0, 45, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 53, 55, 54, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 57, 59, 58, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 61, 63, 62, 0);
    gSPVertex(gfx++, D_300F398, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_300F4B8, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 5, 0, 14, 7, 15, 0);
    gSP2Triangles(gfx++, 16, 4, 17, 0, 18, 19, 20, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_300EDE8, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 10, 12, 0);
    gSP2Triangles(gfx++, 12, 14, 13, 0, 15, 14, 12, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 17, 16, 0);
    gSP2Triangles(gfx++, 16, 20, 19, 0, 16, 21, 20, 0);
    gSP2Triangles(gfx++, 9, 22, 23, 0, 9, 23, 24, 0);
    gSP2Triangles(gfx++, 5, 25, 3, 0, 2, 26, 0, 0);
    gSP1Triangle(gfx++, 24, 6, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_300F608, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 5, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 16, 18, 17, 0);
    gSP2Triangles(gfx++, 19, 7, 9, 0, 20, 21, 22, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_300F778, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    return gfx;
}

extern Vtx D_7010B28[];
extern Vtx D_7010CB8[];
extern Vtx D_70110A8[];
extern Vtx D_70110E8[];
extern Vtx D_70111A8[];
extern Vtx D_70112D8[];
extern Vtx D_7011398[];
extern Vtx D_7011418[];

Gfx* func_i9_8013A25C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7011418, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 12, 18, 13, 0, 2, 19, 20, 0);
    gSP2Triangles(gfx++, 10, 21, 22, 0, 11, 10, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 9, 11, 0, 2, 1, 28, 0);
    gSP1Triangle(gfx++, 0, 29, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70110A8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7011398, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7010CB8, 63, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 2, 7, 0, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 12, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 4, 20, 5, 0, 20, 21, 5, 0);
    gSP2Triangles(gfx++, 14, 22, 23, 0, 23, 15, 24, 0);
    gSP2Triangles(gfx++, 11, 25, 8, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 29, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 35, 36, 0);
    gSP2Triangles(gfx++, 32, 37, 38, 0, 32, 38, 29, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 39, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 43, 45, 46, 0);
    gSP2Triangles(gfx++, 42, 46, 45, 0, 42, 45, 39, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 48, 50, 49, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 52, 54, 53, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 56, 58, 57, 0);
    gSP2Triangles(gfx++, 59, 60, 61, 0, 60, 62, 61, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70110E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7010B28, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 9, 11, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 13, 11, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 16, 15, 0, 15, 19, 18, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 8, 23, 24, 0);
    gSP1Triangle(gfx++, 24, 6, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70111A8, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 8, 0, 4, 18, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70112D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_70115F8[];
extern Vtx D_7011738[];
extern Vtx D_70119E8[];
extern Vtx D_7011AA8[];
extern Vtx D_7011B08[];
extern Vtx D_7011BE8[];
extern Vtx D_7011CA8[];
extern Vtx D_7011D28[];

Gfx* func_i9_8013A9A8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7011D28, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 10, 12, 0);
    gSP2Triangles(gfx++, 0, 14, 1, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 19, 20, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70119E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 0, 2, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7011CA8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7011738, 43, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 8, 4, 9, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 16, 20, 13, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 23, 26, 25, 0, 23, 25, 21, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 28, 30, 29, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 32, 34, 33, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 36, 38, 37, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 40, 42, 41, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7011AA8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7011B08, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 3, 5, 0, 11, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70115F8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 6, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 12, 0);
    gSP2Triangles(gfx++, 8, 13, 11, 0, 14, 15, 16, 0);
    gSP1Triangle(gfx++, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7011BE8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7011E78[];
extern Vtx D_7012028[];
extern Vtx D_7012068[];
extern Vtx D_70120C8[];
extern Vtx D_70121A8[];
extern Vtx D_7012208[];
extern Vtx D_7012268[];

Gfx* func_i9_8013AFD4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7012268, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 0, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7012028, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7012208, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7011E78, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 11, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7012068, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70120C8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70121A8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_7012348[];
extern Vtx D_7012488[];
extern Vtx D_70124B8[];
extern Vtx D_7012518[];

Gfx* func_i9_8013B34C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7012518, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7012348, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP1Triangle(gfx++, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7012488, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70124B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3010938[];
extern Vtx D_3010978[];
extern Vtx D_3010BB8[];
extern Vtx D_3010D48[];
extern Vtx D_3010DE8[];
extern Vtx D_3010E88[];
extern Vtx D_30110A8[];
extern Vtx D_30114A8[];

Gfx* func_i9_8013B57C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3010978, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 21, 0, 17, 21, 18, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 22, 25, 0, 26, 25, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3010938, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3010E88, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 4, 23, 0, 24, 3, 25, 0);
    gSP2Triangles(gfx++, 3, 24, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 23, 4, 0, 31, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30110A8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 1, 0, 0);
    gSP2Triangles(gfx++, 7, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 4, 0, 42, 4, 8, 0);
    gSP2Triangles(gfx++, 7, 42, 8, 0, 4, 44, 0, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 45, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 58, 59, 60, 0);
    gSP2Triangles(gfx++, 61, 22, 21, 0, 24, 26, 62, 0);
    gSP1Triangle(gfx++, 50, 63, 51, 0);
    gSPVertex(gfx++, D_30114A8, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 9, 11, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3010BB8, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 8, 11, 12, 0);
    gSP2Triangles(gfx++, 8, 7, 11, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 5, 4, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 3, 0, 21, 0, 3, 0);
    gSP2Triangles(gfx++, 22, 19, 4, 0, 15, 23, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3010D48, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3010DE8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);

    return gfx;
}

extern Vtx D_7012578[];
extern Vtx D_70127B8[];
extern Vtx D_7012918[];
extern Vtx D_70129B8[];
extern Vtx D_7012A18[];
extern Vtx D_7012C38[];

Gfx* func_i9_8013BD04(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7012578, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 21, 0, 17, 21, 18, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 22, 25, 0, 26, 25, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7012A18, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 5, 4, 0, 25, 6, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP1Triangle(gfx++, 6, 25, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7012C38, 54, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 15, 17, 27, 0);
    gSP2Triangles(gfx++, 28, 6, 8, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 45, 19, 18, 0);
    gSP2Triangles(gfx++, 9, 11, 46, 0, 34, 47, 35, 0);
    gSP2Triangles(gfx++, 48, 0, 2, 0, 44, 43, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 50, 52, 53, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70127B8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 11, 10, 0, 5, 17, 18, 0);
    gSP2Triangles(gfx++, 15, 19, 20, 0, 15, 20, 14, 0);
    gSP1Triangle(gfx++, 10, 9, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7012918, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70129B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_7012F98[];
extern Vtx D_7013138[];
extern Vtx D_7013228[];
extern Vtx D_70132C8[];
extern Vtx D_7013328[];
extern Vtx D_70134F8[];

Gfx* func_i9_8013C360(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7012F98, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7013328, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 6, 7, 22, 0, 23, 24, 25, 0);
    gSP1Triangle(gfx++, 26, 27, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70134F8, 47, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 8, 10, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 8, 25, 0);
    gSP2Triangles(gfx++, 4, 26, 5, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 11, 13, 0);
    gSP2Triangles(gfx++, 21, 23, 32, 0, 33, 18, 20, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 7, 40, 41, 0, 42, 8, 24, 0);
    gSP2Triangles(gfx++, 14, 16, 43, 0, 44, 45, 46, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7013138, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 7, 0, 1, 7, 2, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 14, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7013228, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70132C8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_70137E8[];
extern Vtx D_70138A8[];
extern Vtx D_7013938[];
extern Vtx D_7013998[];
extern Vtx D_7013A58[];

Gfx* func_i9_8013C8EC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70137E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7013998, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7013A58, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 4, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 2, 1, 32, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70138A8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7013938, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_7013C68[];
extern Vtx D_7013C98[];
extern Vtx D_7013CC8[];
extern Vtx D_7013CF8[];
extern Vtx D_7013DB8[];

Gfx* func_i9_8013CC0C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7013C68, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7013CF8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7013DB8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP1Triangle(gfx++, 2, 1, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7013C98, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7013CC8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3011BB8[];
extern Vtx D_3011F98[];
extern Vtx D_30121F8[];
extern Vtx D_30122F8[];
extern Vtx D_3012438[];
extern Vtx D_30126C8[];
extern Vtx D_3012748[];
extern Vtx D_3012A68[];

Gfx* func_i9_8013CED0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30122F8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 10, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 26, 68, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3012438, 41, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 2, 1, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 1, 0);
    gSP2Triangles(gfx++, 3, 21, 22, 0, 3, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 4, 29, 0);
    gSP2Triangles(gfx++, 30, 10, 31, 0, 32, 8, 7, 0);
    gSP2Triangles(gfx++, 33, 34, 7, 0, 35, 36, 7, 0);
    gSP2Triangles(gfx++, 30, 37, 38, 0, 30, 39, 40, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3011BB8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 9, 0);
    gSP2Triangles(gfx++, 17, 16, 13, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 30, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 34, 30, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 43, 44, 0, 45, 46, 32, 0);
    gSP2Triangles(gfx++, 45, 32, 31, 0, 47, 34, 36, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 51, 53, 54, 0, 32, 55, 33, 0);
    gSP2Triangles(gfx++, 56, 57, 42, 0, 58, 59, 60, 0);
    gSP1Triangle(gfx++, 59, 61, 60, 0);
    gSPVertex(gfx++, D_3011F98, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 1, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 2, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 23, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 26, 30, 31, 0, 32, 33, 34, 0);
    gSP1Triangle(gfx++, 35, 36, 37, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30121F8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 4, 7, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 5, 10, 6, 0, 10, 11, 6, 0);
    gSP2Triangles(gfx++, 1, 12, 13, 0, 1, 13, 2, 0);
    gSP2Triangles(gfx++, 14, 15, 13, 0, 12, 14, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30126C8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3012A68, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 7, 17, 8, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 0, 21, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3012748, 50, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);

    return gfx;
}

extern Vtx D_7013ED8[];
extern Vtx D_70142D8[];
extern Vtx D_7014438[];
extern Vtx D_7014538[];
extern Vtx D_7014718[];
extern Vtx D_7014798[];
extern Vtx D_7014898[];
extern Vtx D_7014918[];

Gfx* func_i9_8013D814(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7014718, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 26, 68, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7014538, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7013ED8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 6, 0, 13, 12, 9, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 21, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 27, 26, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 30, 32, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 35, 37, 36, 0, 38, 25, 24, 0);
    gSP2Triangles(gfx++, 38, 39, 25, 0, 40, 27, 29, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 47, 0, 25, 48, 21, 0);
    gSP2Triangles(gfx++, 49, 50, 35, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 52, 54, 53, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 57, 56, 58, 0, 59, 60, 61, 0);
    gSP1Triangle(gfx++, 61, 62, 63, 0);
    gSPVertex(gfx++, D_70142D8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 11, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 14, 18, 15, 0);
    gSP1Triangle(gfx++, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7014438, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 7, 10, 0);
    gSP2Triangles(gfx++, 11, 10, 12, 0, 8, 13, 9, 0);
    gSP2Triangles(gfx++, 13, 14, 9, 0, 4, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 2, 5, 0, 1, 15, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7014898, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7014798, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7014918, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);

    return gfx;
}

extern Vtx D_7014B78[];
extern Vtx D_7014F38[];
extern Vtx D_7015038[];
extern Vtx D_70150B8[];
extern Vtx D_7015178[];
extern Vtx D_70151F8[];
extern Vtx D_7015318[];

Gfx* func_i9_8013DF88(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7015038, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 0, 6, 0, 7, 5, 4, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 26, 68, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7015318, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7014B78, 60, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 3, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 20, 19, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 22, 0);
    gSP2Triangles(gfx++, 31, 20, 22, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 41, 40, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 41, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 32, 34, 0, 53, 32, 54, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 57, 58, 59, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7014F38, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 10, 0);
    gSP2Triangles(gfx++, 11, 10, 13, 0, 14, 11, 13, 0);
    gSP2Triangles(gfx++, 14, 13, 15, 0, 12, 8, 10, 0);
    gSP2Triangles(gfx++, 5, 3, 2, 0, 5, 2, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7015178, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70150B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70151F8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    return gfx;
}

extern Vtx D_70154F8[];
extern Vtx D_70157F8[];
extern Vtx D_7015978[];
extern Vtx D_70159F8[];
extern Vtx D_7015B18[];

Gfx* func_i9_8013E5A8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 26, 68, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70157F8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70154F8, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 3, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 17, 16, 0, 20, 17, 19, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 24, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 29, 32, 0, 33, 34, 30, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 38, 40, 41, 0, 42, 43, 23, 0);
    gSP2Triangles(gfx++, 44, 21, 45, 0, 45, 46, 47, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7015978, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7015B18, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70159F8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    return gfx;
}

extern Vtx D_7015BD8[];
extern Vtx D_7015E18[];

Gfx* func_i9_8013E964(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 26, 68, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7015E18, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7015BD8, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 12, 0);
    gSP2Triangles(gfx++, 10, 12, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 25, 0);
    gSP2Triangles(gfx++, 28, 26, 25, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 16, 35, 17, 0);

    return gfx;
}

extern Vtx D_3013308[];
extern Vtx D_30136C8[];
extern Vtx D_3013708[];
extern Vtx D_3013948[];
extern Vtx D_30139E8[];
extern Vtx D_3013AE8[];
extern Vtx D_3013DD8[];
extern Vtx D_3013E58[];

Gfx* func_i9_8013EB2C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3013308, 60, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 15, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 22, 20, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 24, 26, 25, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 13, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3013DD8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3013708, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 10, 11, 8, 0);
    gSP2Triangles(gfx++, 12, 13, 6, 0, 13, 4, 6, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 17, 16, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30136C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3013948, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 3, 0, 4, 3, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3013E58, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30139E8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_3013AE8, 47, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 45, 15, 46, 0);

    return gfx;
}

extern Vtx D_7015ED8[];
extern Vtx D_7016288[];
extern Vtx D_70162C8[];
extern Vtx D_7016508[];
extern Vtx D_70165A8[];
extern Vtx D_70166A8[];
extern Vtx D_7016848[];
extern Vtx D_70168C8[];

Gfx* func_i9_8013F248(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7015ED8, 59, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 15, 25, 0, 15, 26, 25, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 13, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 6, 39, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 57, 58, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7016848, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70162C8, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 10, 11, 8, 0);
    gSP2Triangles(gfx++, 12, 13, 6, 0, 13, 4, 6, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 17, 16, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7016288, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7016508, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 3, 0, 4, 3, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70168C8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 0, 7, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70165A8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_70166A8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);

    return gfx;
}

extern Vtx D_7016948[];
extern Vtx D_7016D18[];
extern Vtx D_7016D58[];
extern Vtx D_7016F18[];
extern Vtx D_7016F98[];
extern Vtx D_7017028[];
extern Vtx D_7017168[];
extern Vtx D_70171A8[];

Gfx* func_i9_8013F8E0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7016948, 61, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 16, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 22, 20, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 24, 26, 25, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 36, 37, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 54, 55, 56, 0);
    gSP2Triangles(gfx++, 57, 58, 59, 0, 57, 59, 60, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7017168, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7016D58, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 20, 18, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP1Triangle(gfx++, 27, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7016D18, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7016F18, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70171A8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7016F98, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_7017028, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_7017228[];
extern Vtx D_7017468[];
extern Vtx D_7017508[];
extern Vtx D_70175C8[];
extern Vtx D_70175F8[];
extern Vtx D_70176F8[];

Gfx* func_i9_8013FF20(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7017228, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 15, 17, 0);
    gSP2Triangles(gfx++, 19, 0, 3, 0, 16, 20, 21, 0);
    gSP2Triangles(gfx++, 14, 22, 23, 0, 24, 7, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70176F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7017508, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7017468, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70175C8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_70175F8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);

    return gfx;
}

extern Vtx D_7017738[];
extern Vtx D_7017908[];
extern Vtx D_7017968[];
extern Vtx D_70179C8[];

Gfx* func_i9_801403C4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7017738, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 5, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 1, 0, 0, 13, 12, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7017968, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7017908, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_OFF);
    gSPVertex(gfx++, D_70179C8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3014518[];
extern Vtx D_3014908[];
extern Vtx D_3014B98[];
extern Vtx D_3014BF8[];
extern Vtx D_3014CB8[];
extern Vtx D_3014D78[];
extern Vtx D_3014ED8[];
extern Vtx D_3014F58[];
extern Vtx D_3015158[];

Gfx* func_i9_8014061C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3014F58, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3014ED8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3015158, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3014CB8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3014518, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 6, 13, 0);
    gSP2Triangles(gfx++, 12, 14, 6, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 15, 17, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 16, 25, 26, 0);
    gSP2Triangles(gfx++, 6, 14, 4, 0, 9, 27, 28, 0);
    gSP2Triangles(gfx++, 28, 29, 9, 0, 30, 31, 1, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 30, 1, 44, 0, 26, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 22, 48, 0, 49, 37, 50, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 51, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 57, 58, 0);
    gSP2Triangles(gfx++, 59, 60, 61, 0, 59, 61, 62, 0);
    gSPVertex(gfx++, D_3014908, 41, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 17, 0, 20, 17, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 21, 0, 23, 21, 20, 0);
    gSP2Triangles(gfx++, 25, 26, 24, 0, 25, 24, 23, 0);
    gSP2Triangles(gfx++, 27, 28, 26, 0, 27, 26, 25, 0);
    gSP2Triangles(gfx++, 19, 18, 28, 0, 19, 28, 27, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 29, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 35, 36, 0);
    gSP2Triangles(gfx++, 13, 15, 37, 0, 10, 12, 38, 0);
    gSP2Triangles(gfx++, 7, 9, 39, 0, 4, 6, 40, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3014B98, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_3014BF8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 4, 5, 0, 0, 5, 6, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 7, 9, 10, 0);
    gSP2Triangles(gfx++, 4, 9, 8, 0, 4, 8, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3014D78, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 6, 17, 7, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 0, 2, 0);

    return gfx;
}

extern Vtx D_7017A28[];
extern Vtx D_7017E08[];
extern Vtx D_7018018[];
extern Vtx D_7018078[];
extern Vtx D_70180D8[];
extern Vtx D_7018118[];
extern Vtx D_70181B8[];
extern Vtx D_7018238[];
extern Vtx D_70183F8[];

Gfx* func_i9_80140E54(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7018238, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70181B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70183F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70180D8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7017A28, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 5, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 12, 20, 21, 0);
    gSP2Triangles(gfx++, 5, 10, 3, 0, 8, 22, 23, 0);
    gSP2Triangles(gfx++, 23, 24, 8, 0, 25, 26, 1, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 14, 0, 29, 35, 36, 0);
    gSP2Triangles(gfx++, 37, 17, 38, 0, 39, 32, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 45, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 56, 57, 58, 0);
    gSP1Triangle(gfx++, 59, 60, 61, 0);
    gSPVertex(gfx++, D_7017E08, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 4, 0);
    gSP2Triangles(gfx++, 7, 4, 3, 0, 9, 10, 8, 0);
    gSP2Triangles(gfx++, 9, 8, 7, 0, 11, 12, 10, 0);
    gSP2Triangles(gfx++, 11, 10, 9, 0, 13, 14, 12, 0);
    gSP2Triangles(gfx++, 13, 12, 11, 0, 6, 5, 14, 0);
    gSP2Triangles(gfx++, 6, 14, 13, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 21, 22, 0, 0, 2, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP1Triangle(gfx++, 30, 31, 32, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7018018, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7018078, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 1, 0, 0, 4, 0, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7018118, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_7018438[];
extern Vtx D_7018838[];
extern Vtx D_7018998[];
extern Vtx D_70189F8[];
extern Vtx D_7018A58[];
extern Vtx D_7018A98[];
extern Vtx D_7018B38[];
extern Vtx D_7018BB8[];

Gfx* func_i9_80141590(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7018B38, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7018BB8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7018A58, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7018438, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 5, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 12, 20, 21, 0);
    gSP2Triangles(gfx++, 5, 10, 3, 0, 8, 22, 23, 0);
    gSP2Triangles(gfx++, 23, 24, 8, 0, 25, 26, 1, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 29, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 17, 39, 0, 40, 32, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 52, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 53, 0, 56, 53, 52, 0);
    gSP2Triangles(gfx++, 58, 59, 57, 0, 58, 57, 56, 0);
    gSP2Triangles(gfx++, 60, 61, 59, 0, 60, 59, 58, 0);
    gSP2Triangles(gfx++, 62, 63, 61, 0, 62, 61, 60, 0);
    gSP2Triangles(gfx++, 55, 54, 63, 0, 55, 63, 62, 0);
    gSPVertex(gfx++, D_7018838, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7018998, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70189F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 1, 0, 0, 4, 0, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7018A98, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_7018BF8[];
extern Vtx D_7018F38[];
extern Vtx D_7018FD8[];
extern Vtx D_7019058[];

Gfx* func_i9_80141BC8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7018FD8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7019058, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7018BF8, 52, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 10, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 1, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 12, 23, 0, 24, 21, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7018F38, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_7019098[];
extern Vtx D_7019318[];

Gfx* func_i9_80141ECC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7019098, 40, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 6, 13, 0, 14, 11, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7019318, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3015858[];
extern Vtx D_30158F8[];
extern Vtx D_3015978[];
extern Vtx D_3015A48[];
extern Vtx D_3015BA8[];
extern Vtx D_3015CE8[];
extern Vtx D_3015E88[];
extern Vtx D_3016258[];

Gfx* func_i9_80142078(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3016258, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 46, 47, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3015E88, 61, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 21, 20, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 23, 25, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 28, 27, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 43, 45, 46, 0);
    gSP2Triangles(gfx++, 16, 38, 17, 0, 16, 39, 38, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 50, 51, 48, 0);
    gSP2Triangles(gfx++, 47, 52, 48, 0, 53, 50, 48, 0);
    gSP2Triangles(gfx++, 9, 54, 55, 0, 56, 57, 9, 0);
    gSP2Triangles(gfx++, 55, 58, 59, 0, 60, 58, 55, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3015A48, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 8, 0);
    gSP2Triangles(gfx++, 5, 9, 6, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 10, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 14, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 20, 21, 0, 4, 8, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3015858, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 1, 8, 2, 0, 9, 5, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30158F8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 5, 0, 2, 5, 3, 0);
    gSP2Triangles(gfx++, 6, 7, 1, 0, 6, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3015978, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 1, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 5, 12, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3015BA8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 17, 16, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 6, 18, 105, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_3015CE8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);

    return gfx;
}

extern Vtx D_7019348[];
extern Vtx D_70193C8[];
extern Vtx D_7019428[];
extern Vtx D_70194C8[];
extern Vtx D_70195C8[];
extern Vtx D_7019708[];
extern Vtx D_7019808[];
extern Vtx D_7019B38[];

Gfx* func_i9_80142950(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7019B38, 48, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 46, 47, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7019808, 51, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 3, 5, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 13, 12, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 15, 17, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 20, 19, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 8, 30, 9, 0, 8, 31, 30, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 42, 44, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 48, 49, 46, 0, 50, 49, 48, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70194C8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7019348, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 7, 4, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70193C8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7019428, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70195C8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 5, 4, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 6, 18, 105, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_7019708, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);

    return gfx;
}

extern Vtx D_7019E38[];
extern Vtx D_7019EB8[];
extern Vtx D_7019F18[];
extern Vtx D_7019F58[];
extern Vtx D_7019FD8[];
extern Vtx D_701A078[];
extern Vtx D_701A118[];
extern Vtx D_701A428[];

Gfx* func_i9_80143080(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701A428, 40, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701A118, 49, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 3, 5, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 13, 12, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 15, 17, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 20, 19, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 8, 30, 9, 0, 8, 31, 30, 0);
    gSP2Triangles(gfx++, 7, 39, 40, 0, 41, 42, 39, 0);
    gSP2Triangles(gfx++, 43, 41, 39, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 46, 47, 44, 0, 48, 47, 46, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7019F58, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7019E38, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 7, 4, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7019EB8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7019F18, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7019FD8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 7, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 6, 18, 105, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_701A078, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_701A6A8[];
extern Vtx D_701A708[];
extern Vtx D_701A748[];
extern Vtx D_701A7C8[];
extern Vtx D_701A868[];
extern Vtx D_701A8A8[];
extern Vtx D_701AAF8[];

Gfx* func_i9_801436A4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701AAF8, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701A8A8, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 1, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 16, 27, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 30, 29, 0, 33, 36, 34, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701A748, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 2, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701A6A8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_701A708, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701A7C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 4, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 6, 18, 105, 255);
    gDPSetCombineLERP(gfx++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_OFF);
    gSPVertex(gfx++, D_701A868, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_701ACF8[];
extern Vtx D_701AE98[];
extern Vtx D_701AED8[];

Gfx* func_i9_80143BB8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701AED8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701ACF8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 1, 0, 0);
    gSP2Triangles(gfx++, 5, 4, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 10, 9, 16, 0, 17, 13, 15, 0);
    gSP2Triangles(gfx++, 4, 18, 1, 0, 19, 13, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 9, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701AE98, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);

    return gfx;
}

extern Vtx D_3016D98[];
extern Vtx D_3017178[];
extern Vtx D_3017238[];
extern Vtx D_3017318[];
extern Vtx D_3017378[];
extern Vtx D_30173F8[];
extern Vtx D_3017458[];
extern Vtx D_3017498[];

Gfx* func_i9_80143E40(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 150, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3016D98, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 9, 8, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 8, 0, 12, 8, 7, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 27, 29, 28, 0);
    gSP2Triangles(gfx++, 29, 27, 30, 0, 30, 27, 26, 0);
    gSP2Triangles(gfx++, 30, 26, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 3, 0, 35, 3, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 34, 0);
    gSP2Triangles(gfx++, 43, 42, 44, 0, 34, 42, 43, 0);
    gSP2Triangles(gfx++, 45, 38, 46, 0, 46, 38, 40, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 50, 51, 52, 0);
    gSP2Triangles(gfx++, 50, 53, 51, 0, 54, 55, 52, 0);
    gSP2Triangles(gfx++, 54, 56, 57, 0, 58, 59, 60, 0);
    gSP1Triangle(gfx++, 58, 61, 59, 0);
    gSPVertex(gfx++, D_3017178, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 5, 7, 6, 0, 4, 5, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_30173F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3017458, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3017238, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 9, 11, 0);
    gSP2Triangles(gfx++, 3, 13, 4, 0, 1, 3, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3017318, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3017378, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 5, 4, 0, 6, 5, 1, 0);
    gSP1Triangle(gfx++, 5, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3017498, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 0, 19, 1, 0);

    return gfx;
}

extern Vtx D_701B018[];
extern Vtx D_701B3F8[];
extern Vtx D_701B478[];
extern Vtx D_701B558[];
extern Vtx D_701B5B8[];
extern Vtx D_701B638[];
extern Vtx D_701B698[];
extern Vtx D_701B6D8[];

Gfx* func_i9_80144518(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 150, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701B018, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 11, 8, 7, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 25, 24, 0);
    gSP2Triangles(gfx++, 27, 24, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 3, 0, 32, 3, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 38, 39, 31, 0);
    gSP2Triangles(gfx++, 40, 39, 41, 0, 31, 39, 40, 0);
    gSP2Triangles(gfx++, 42, 35, 43, 0, 43, 35, 37, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 50, 48, 0, 51, 52, 49, 0);
    gSP2Triangles(gfx++, 51, 53, 52, 0, 54, 55, 56, 0);
    gSP2Triangles(gfx++, 54, 57, 55, 0, 58, 59, 60, 0);
    gSP1Triangle(gfx++, 61, 58, 60, 0);
    gSPVertex(gfx++, D_701B3F8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 1, 3, 2, 0, 0, 1, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701B638, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701B698, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701B478, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 4, 0);
    gSP2Triangles(gfx++, 3, 5, 13, 0, 1, 6, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701B558, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_701B5B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 4, 0);
    gSP2Triangles(gfx++, 0, 4, 5, 0, 6, 2, 1, 0);
    gSP1Triangle(gfx++, 1, 3, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701B6D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_701B778[];
extern Vtx D_701BB18[];
extern Vtx D_701BBC8[];
extern Vtx D_701BC28[];
extern Vtx D_701BCA8[];
extern Vtx D_701BD08[];
extern Vtx D_701BD48[];

Gfx* func_i9_80144B30(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 150, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701B778, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 34, 33, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 42, 40, 0, 43, 44, 41, 0);
    gSP2Triangles(gfx++, 43, 45, 44, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 55, 56, 57, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701BCA8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701BD08, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701BB18, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 2, 1, 8, 0);
    gSP2Triangles(gfx++, 9, 2, 8, 0, 4, 10, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701BBC8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 5, 4, 0, 0, 5, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_701BC28, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 2, 4, 0);
    gSP2Triangles(gfx++, 3, 1, 5, 0, 1, 0, 6, 0);
    gSP1Triangle(gfx++, 7, 5, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701BD48, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_701BDE8[];
extern Vtx D_701C108[];
extern Vtx D_701C1E8[];
extern Vtx D_701C248[];
extern Vtx D_701C2A8[];
extern Vtx D_701C2D8[];

Gfx* func_i9_801450C4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 150, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701BDE8, 50, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 30, 29, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 45, 46, 0);
    gSP1Triangle(gfx++, 47, 48, 49, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701C248, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701C2A8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701C108, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 2, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 4, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 7, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701C1E8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701C2D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 3, 9, 4, 0);

    return gfx;
}

extern Vtx D_701C378[];
extern Vtx D_701C5B8[];
extern Vtx D_701C638[];
extern Vtx D_701C698[];
extern Vtx D_701C6C8[];

Gfx* func_i9_8014553C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 150, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701C378, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 31, 32, 0);
    gSP1Triangle(gfx++, 33, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701C698, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701C5B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 2, 1, 0, 3, 5, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701C638, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701C6C8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_3017C18[];
extern Vtx D_3017D18[];
extern Vtx D_3017F78[];
extern Vtx D_3018018[];
extern Vtx D_30180F8[];
extern Vtx D_30182F8[];

Gfx* func_i9_80145860(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3017D18, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 2, 1, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 1, 0, 6, 1, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 11, 8, 0, 12, 8, 13, 0);
    gSP2Triangles(gfx++, 13, 8, 14, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 15, 14, 16, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 16, 18, 19, 0, 17, 16, 19, 0);
    gSP2Triangles(gfx++, 19, 18, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 9, 24, 26, 0);
    gSP2Triangles(gfx++, 16, 14, 9, 0, 16, 9, 26, 0);
    gSP2Triangles(gfx++, 18, 16, 26, 0, 25, 18, 26, 0);
    gSP2Triangles(gfx++, 6, 0, 27, 0, 28, 6, 27, 0);
    gSP2Triangles(gfx++, 28, 27, 29, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 31, 0, 28, 31, 6, 0);
    gSP2Triangles(gfx++, 25, 20, 18, 0, 29, 32, 30, 0);
    gSP2Triangles(gfx++, 32, 29, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 33, 29, 27, 0, 33, 27, 37, 0);
    gSP2Triangles(gfx++, 27, 0, 3, 0, 37, 27, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3018018, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_30180F8, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3017C18, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 3, 2, 8, 0, 3, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 8, 10, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3017F78, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30182F8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 6, 8, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 4, 23, 5, 0);
    gSP2Triangles(gfx++, 20, 22, 24, 0, 0, 2, 25, 0);

    return gfx;
}

extern Vtx D_701C6F8[];
extern Vtx D_701C7D8[];
extern Vtx D_701C9B8[];
extern Vtx D_701CA58[];
extern Vtx D_701CB38[];
extern Vtx D_701CC78[];

Gfx* func_i9_80145F34(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701C7D8, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 3, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 11, 0, 11, 7, 12, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 13, 12, 14, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 15, 14, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 14, 12, 8, 0);
    gSP2Triangles(gfx++, 14, 8, 20, 0, 21, 14, 20, 0);
    gSP2Triangles(gfx++, 5, 1, 22, 0, 23, 5, 22, 0);
    gSP2Triangles(gfx++, 23, 22, 24, 0, 21, 16, 14, 0);
    gSP2Triangles(gfx++, 22, 25, 24, 0, 25, 22, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 22, 1, 0, 0);
    gSP2Triangles(gfx++, 26, 22, 0, 0, 1, 3, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701CA58, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701CB38, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 0, 2, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701C6F8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 3, 2, 8, 0, 3, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701C9B8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701CC78, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 1, 23, 2, 0);
    gSP2Triangles(gfx++, 14, 16, 24, 0, 7, 25, 8, 0);

    return gfx;
}

extern Vtx D_701CE18[];
extern Vtx D_701CED8[];
extern Vtx D_701D088[];
extern Vtx D_701D128[];
extern Vtx D_701D168[];
extern Vtx D_701D268[];

Gfx* func_i9_8014651C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701CED8, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 5, 4, 6, 0);
    gSP2Triangles(gfx++, 4, 7, 6, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 4, 1, 0, 7, 4, 11, 0);
    gSP2Triangles(gfx++, 12, 7, 11, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 15, 14, 16, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 14, 22, 0);
    gSP2Triangles(gfx++, 21, 16, 14, 0, 14, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 14, 24, 0, 13, 25, 26, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701D128, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701D168, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 0, 15, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701CE18, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 3, 5, 4, 0);
    gSP2Triangles(gfx++, 2, 4, 6, 0, 2, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701D088, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701D268, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_701D3A8[];
extern Vtx D_701D548[];
extern Vtx D_701D5E8[];
extern Vtx D_701D628[];
extern Vtx D_701D6E8[];

Gfx* func_i9_80146A4C(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701D3A8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 4, 7, 8, 0);
    gSP2Triangles(gfx++, 5, 4, 8, 0, 9, 7, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 11, 15, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 16, 15, 17, 0);
    gSP2Triangles(gfx++, 15, 18, 17, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 15, 12, 0, 18, 15, 22, 0);
    gSP2Triangles(gfx++, 23, 18, 22, 0, 9, 4, 24, 0);
    gSP2Triangles(gfx++, 24, 4, 6, 0, 24, 6, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701D5E8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701D628, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701D548, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701D6E8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 0, 7, 1, 0);

    return gfx;
}

extern Vtx D_701D768[];
extern Vtx D_701D838[];
extern Vtx D_701D8D8[];
extern Vtx D_701D918[];
extern Vtx D_701D9D8[];

Gfx* func_i9_80146DB8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701D768, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 9, 11, 0, 1, 0, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701D8D8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701D918, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701D838, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_701D9D8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_30192D8[];
extern Vtx D_3019378[];
extern Vtx D_30193D8[];
extern Vtx D_3019498[];
extern Vtx D_3019518[];
extern Vtx D_3019918[];
extern Vtx D_3019D18[];
extern Vtx D_3019D58[];
extern Vtx D_3019E98[];

Gfx* func_i9_80147074(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30193D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 5, 4, 0, 8, 9, 5, 0);
    gSP2Triangles(gfx++, 10, 11, 1, 0, 11, 2, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3019498, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3019D58, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 7, 9, 0);
    gSP2Triangles(gfx++, 12, 14, 10, 0, 4, 6, 15, 0);
    gSP2Triangles(gfx++, 10, 16, 11, 0, 16, 17, 11, 0);
    gSP2Triangles(gfx++, 3, 18, 0, 0, 3, 19, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3019518, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 9, 11, 12, 0);
    gSP2Triangles(gfx++, 9, 12, 10, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 26, 24, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 32, 34, 33, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 35, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 41, 42, 0, 39, 43, 40, 0);
    gSP2Triangles(gfx++, 44, 45, 43, 0, 44, 43, 39, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 44, 0);
    gSP2Triangles(gfx++, 48, 45, 44, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 49, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 54, 56, 55, 0, 56, 57, 58, 0);
    gSP2Triangles(gfx++, 56, 58, 55, 0, 59, 12, 11, 0);
    gSP2Triangles(gfx++, 59, 11, 60, 0, 61, 62, 63, 0);
    gSPVertex(gfx++, D_3019918, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 3, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 5, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 21, 23, 0);
    gSP2Triangles(gfx++, 27, 23, 28, 0, 26, 25, 29, 0);
    gSP2Triangles(gfx++, 26, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 35, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 53, 54, 39, 0);
    gSP2Triangles(gfx++, 54, 40, 39, 0, 44, 55, 56, 0);
    gSP2Triangles(gfx++, 44, 43, 55, 0, 57, 58, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 58, 0, 50, 62, 63, 0);
    gSPVertex(gfx++, D_3019D18, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30192D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3019378, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 0, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_3019E98, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 1, 7, 2, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 12, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 19, 17, 0);
    gSP2Triangles(gfx++, 9, 11, 20, 0, 9, 20, 12, 0);

    return gfx;
}

extern Vtx D_701DA18[];
extern Vtx D_701DAB8[];
extern Vtx D_701DB18[];
extern Vtx D_701DBB8[];
extern Vtx D_701DC38[];
extern Vtx D_701E038[];
extern Vtx D_701E358[];
extern Vtx D_701E498[];

Gfx* func_i9_801479B8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701DB18, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 3, 0, 6, 7, 4, 0);
    gSP2Triangles(gfx++, 8, 9, 1, 0, 9, 2, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701DBB8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701E358, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 0, 7, 1, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 8, 10, 0, 13, 15, 11, 0);
    gSP2Triangles(gfx++, 11, 16, 12, 0, 16, 17, 12, 0);
    gSP2Triangles(gfx++, 6, 18, 3, 0, 6, 19, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701DC38, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 24, 22, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 30, 32, 31, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 33, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 37, 41, 38, 0);
    gSP2Triangles(gfx++, 42, 43, 37, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 42, 0, 46, 47, 42, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 55, 57, 54, 0, 58, 59, 60, 0);
    gSP1Triangle(gfx++, 61, 62, 63, 0);
    gSPVertex(gfx++, D_701E038, 50, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 2, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 23, 0, 36, 24, 23, 0);
    gSP2Triangles(gfx++, 27, 37, 38, 0, 27, 26, 37, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 40, 0);
    gSP2Triangles(gfx++, 32, 44, 45, 0, 46, 47, 48, 0);
    gSP1Triangle(gfx++, 46, 48, 49, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701DA18, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_701DAB8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 0, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_701E498, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 8, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 5, 7, 15, 0);
    gSP2Triangles(gfx++, 5, 15, 8, 0, 12, 16, 13, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 19, 20, 0);

    return gfx;
}

extern Vtx D_701E5E8[];
extern Vtx D_701E688[];
extern Vtx D_701E6E8[];
extern Vtx D_701E788[];
extern Vtx D_701E808[];
extern Vtx D_701EC08[];
extern Vtx D_701EDA8[];
extern Vtx D_701EF08[];

Gfx* func_i9_8014812C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701E6E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 3, 0, 6, 7, 4, 0);
    gSP2Triangles(gfx++, 8, 9, 1, 0, 9, 2, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701E788, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701EDA8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 14, 13, 19, 0);
    gSP2Triangles(gfx++, 19, 20, 14, 0, 5, 21, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701E808, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 18, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 25, 27, 26, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 32, 36, 33, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 39, 41, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 43, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 50, 51, 49, 0);
    gSP2Triangles(gfx++, 52, 48, 53, 0, 54, 55, 56, 0);
    gSP2Triangles(gfx++, 52, 57, 58, 0, 59, 49, 60, 0);
    gSP2Triangles(gfx++, 58, 61, 62, 0, 34, 33, 63, 0);
    gSPVertex(gfx++, D_701EC08, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 16, 0, 12, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701E5E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_701E688, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 0, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_701EF08, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 16, 7, 6, 0);

    return gfx;
}

extern Vtx D_701F018[];
extern Vtx D_701F0B8[];
extern Vtx D_701F138[];
extern Vtx D_701F378[];
extern Vtx D_701F618[];

Gfx* func_i9_80148778(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_701F0B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 4, 3, 0, 7, 2, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701F378, 42, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 0, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 21, 23, 22, 0, 13, 24, 14, 0);
    gSP2Triangles(gfx++, 25, 26, 9, 0, 25, 27, 26, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 10, 9, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 35, 37, 38, 0, 25, 9, 20, 0);
    gSP2Triangles(gfx++, 25, 20, 22, 0, 39, 40, 41, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701F138, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 24, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 29, 0, 33, 34, 35, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701F018, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_701F618, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 1, 3, 0);
    gSP2Triangles(gfx++, 2, 3, 4, 0, 4, 5, 6, 0);

    return gfx;
}

extern Vtx D_701F688[];
extern Vtx D_701F6F8[];
extern Vtx D_701F758[];
extern Vtx D_701F8D8[];

Gfx* func_i9_80148BF0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701F6F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_701F8D8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 8, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 15, 14, 20, 0);
    gSP1Triangle(gfx++, 21, 9, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701F758, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701F688, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 0, 0, 4, 0, 5, 0);

    return gfx;
}

extern Vtx D_301A728[];
extern Vtx D_301A7F8[];
extern Vtx D_301A8D8[];
extern Vtx D_301AAC8[];
extern Vtx D_301AEA8[];
extern Vtx D_301AF48[];
extern Vtx D_301B008[];

Gfx* func_i9_80148E3C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 50, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_301AF48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 7, 6, 1, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 10, 9, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_301A8D8, 31, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 4, 0);
    gSP2Triangles(gfx++, 0, 4, 1, 0, 3, 5, 4, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 10, 16, 14, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 27, 28, 29, 0);
    gSP1Triangle(gfx++, 27, 30, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_301B008, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 0, 0, 4, 0, 6, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 7, 10, 8, 0);
    gSP2Triangles(gfx++, 11, 12, 7, 0, 11, 7, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 8, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 14, 17, 0, 19, 18, 17, 0);
    gSP2Triangles(gfx++, 4, 6, 20, 0, 21, 22, 20, 0);
    gSP2Triangles(gfx++, 21, 20, 23, 0, 21, 23, 24, 0);
    gSP2Triangles(gfx++, 19, 25, 18, 0, 23, 26, 24, 0);
    gSP2Triangles(gfx++, 22, 4, 20, 0, 14, 8, 16, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_301AAC8, 62, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 18, 0, 30, 18, 23, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 22, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 26, 25, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 42, 44, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 16, 22, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 53, 55, 14, 0);
    gSP2Triangles(gfx++, 26, 38, 56, 0, 57, 58, 13, 0);
    gSP2Triangles(gfx++, 57, 13, 16, 0, 19, 13, 59, 0);
    gSP2Triangles(gfx++, 60, 1, 0, 0, 61, 60, 0, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_301A728, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 3, 5, 4, 0);
    gSP2Triangles(gfx++, 2, 4, 6, 0, 2, 6, 7, 0);
    gSP2Triangles(gfx++, 7, 6, 8, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 8, 10, 0, 8, 11, 10, 0);
    gSP1Triangle(gfx++, 9, 10, 12, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_301A7F8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_301AEA8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_701FA38[];
extern Vtx D_701FAF8[];
extern Vtx D_701FB98[];
extern Vtx D_701FCF8[];
extern Vtx D_70200F8[];
extern Vtx D_7020158[];
extern Vtx D_70201F8[];
extern Vtx D_70202B8[];

Gfx* func_i9_801495B8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 50, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70201F8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 2, 0, 7, 6, 1, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 10, 9, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_701FB98, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 21, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70202B8, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 8, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 14, 17, 0, 19, 18, 17, 0);
    gSP2Triangles(gfx++, 3, 6, 20, 0, 21, 22, 20, 0);
    gSP2Triangles(gfx++, 21, 20, 23, 0, 21, 23, 24, 0);
    gSP2Triangles(gfx++, 19, 25, 18, 0, 23, 26, 24, 0);
    gSP2Triangles(gfx++, 22, 3, 20, 0, 14, 8, 16, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_701FCF8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 2, 1, 14, 0, 2, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 16, 18, 0);
    gSP2Triangles(gfx++, 18, 17, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 51, 57, 0, 58, 59, 60, 0);
    gSP2Triangles(gfx++, 58, 60, 61, 0, 62, 54, 63, 0);
    gSPVertex(gfx++, D_70200F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_701FA38, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 7, 6, 8, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 9, 8, 10, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_701FAF8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7020158, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_7020468[];
extern Vtx D_70204F8[];
extern Vtx D_7020598[];
extern Vtx D_70206F8[];
extern Vtx D_7020A28[];
extern Vtx D_7020AB8[];
extern Vtx D_7020B98[];

Gfx* func_i9_80149CBC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 50, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7020AB8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 7, 1, 12, 0, 4, 13, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7020598, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 0, 7, 1, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 21, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7020B98, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 6, 8, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 12, 14, 0, 16, 15, 17, 0);
    gSP2Triangles(gfx++, 3, 5, 18, 0, 19, 20, 18, 0);
    gSP2Triangles(gfx++, 19, 18, 21, 0, 19, 21, 22, 0);
    gSP2Triangles(gfx++, 20, 3, 18, 0, 12, 8, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70206F8, 51, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 14, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 20, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 26, 34, 0);
    gSP2Triangles(gfx++, 35, 34, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 12, 0, 40, 12, 42, 0);
    gSP2Triangles(gfx++, 20, 12, 43, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 47, 49, 50, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7020468, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 6, 5, 7, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70204F8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7020A28, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_7020D08[];
extern Vtx D_7020DA8[];
extern Vtx D_7020E68[];
extern Vtx D_7021088[];
extern Vtx D_70210B8[];

Gfx* func_i9_8014A31C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    //! @bug This seems intended to be tile 2
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7020DA8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 0, 7, 1, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70210B8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 0, 4, 0, 6, 5, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 10, 0);
    gSP2Triangles(gfx++, 11, 10, 13, 0, 14, 13, 15, 0);
    gSP2Triangles(gfx++, 12, 8, 10, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 16, 2, 1, 0, 9, 8, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7020E68, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 1, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 31, 0, 26, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7020D08, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7021088, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_70211D8[];
extern Vtx D_7021238[];
extern Vtx D_7021268[];
extern Vtx D_7021308[];
extern Vtx D_7021338[];

Gfx* func_i9_8014A6D4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7021238, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7021338, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 4, 8, 5, 0, 1, 9, 2, 0);
    gSP2Triangles(gfx++, 10, 11, 1, 0, 5, 8, 12, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7021268, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 1, 0, 8, 7, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70211D8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7021308, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_301BBF8[];
extern Vtx D_301BC78[];
extern Vtx D_301BCB8[];
extern Vtx D_301BE48[];
extern Vtx D_301BEE8[];
extern Vtx D_301C2E8[];
extern Vtx D_301C538[];
extern Vtx D_301C638[];

Gfx* func_i9_8014A98C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_301BCB8, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 9, 12, 10, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 14, 16, 15, 0);
    gSP2Triangles(gfx++, 1, 17, 18, 0, 1, 19, 17, 0);
    gSP2Triangles(gfx++, 20, 5, 21, 0, 20, 8, 5, 0);
    gSP2Triangles(gfx++, 1, 18, 22, 0, 23, 22, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_301C638, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 4, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 11, 10, 12, 0);
    gSP2Triangles(gfx++, 8, 7, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 14, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 20, 21, 0, 0, 5, 1, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_301BE48, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_301BEE8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 2, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 20, 22, 23, 0, 24, 7, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 8, 7, 24, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 35, 36, 0);
    gSP2Triangles(gfx++, 32, 31, 37, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 37, 31, 41, 0, 42, 39, 38, 0);
    gSP2Triangles(gfx++, 17, 43, 44, 0, 42, 38, 45, 0);
    gSP2Triangles(gfx++, 5, 46, 47, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 49, 51, 50, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 53, 55, 54, 0, 56, 57, 58, 0);
    gSP2Triangles(gfx++, 56, 58, 59, 0, 60, 61, 62, 0);
    gSP1Triangle(gfx++, 60, 62, 63, 0);
    gSPVertex(gfx++, D_301C2E8, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 2, 0, 8, 2, 1, 0);
    gSP2Triangles(gfx++, 5, 10, 11, 0, 5, 11, 6, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP1Triangle(gfx++, 33, 35, 36, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_301BBF8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 6, 3, 2, 0, 6, 2, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_301BC78, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_301C538, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    return gfx;
}

extern Vtx D_7021408[];
extern Vtx D_7021488[];
extern Vtx D_70214C8[];
extern Vtx D_7021638[];
extern Vtx D_70216D8[];
extern Vtx D_7021AD8[];
extern Vtx D_7021C58[];
extern Vtx D_7021D38[];

Gfx* func_i9_8014B174(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70214C8, 23, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 1, 16, 17, 0, 1, 18, 16, 0);
    gSP2Triangles(gfx++, 19, 5, 20, 0, 19, 21, 5, 0);
    gSP2Triangles(gfx++, 1, 17, 22, 0, 1, 22, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7021D38, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 4, 16, 5, 0, 4, 17, 16, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7021638, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70216D8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 8, 11, 0, 11, 8, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 27, 30, 0, 28, 27, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 36, 38, 37, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 40, 42, 41, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 49, 50, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 51, 53, 54, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 55, 57, 58, 0, 59, 60, 53, 0);
    gSP2Triangles(gfx++, 59, 53, 52, 0, 56, 61, 62, 0);
    gSP2Triangles(gfx++, 56, 62, 57, 0, 49, 48, 63, 0);
    gSPVertex(gfx++, D_7021AD8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7021408, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 6, 3, 2, 0, 6, 2, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7021488, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7021C58, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);

    return gfx;
}

extern Vtx D_7021E98[];
extern Vtx D_7021F18[];
extern Vtx D_7021F58[];
extern Vtx D_7021FD8[];
extern Vtx D_7022078[];
extern Vtx D_7022478[];
extern Vtx D_70224E8[];
extern Vtx D_70225C8[];

Gfx* func_i9_8014B874(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7021F58, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 0, 2, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70225C8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 12, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7021FD8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7022078, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 10, 13, 0);
    gSP2Triangles(gfx++, 11, 10, 12, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 26, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 31, 33, 32, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 35, 37, 36, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 38, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 42, 44, 45, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 46, 48, 49, 0, 50, 51, 52, 0);
    gSP2Triangles(gfx++, 50, 52, 53, 0, 54, 55, 56, 0);
    gSP2Triangles(gfx++, 57, 58, 59, 0, 60, 61, 62, 0);
    gSP1Triangle(gfx++, 61, 63, 62, 0);
    gSPVertex(gfx++, D_7022478, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 4, 6, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7021E98, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 5, 3, 2, 0, 5, 2, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7021F18, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70224E8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);

    return gfx;
}

extern Vtx D_7022708[];
extern Vtx D_7022748[];
extern Vtx D_70227C8[];
extern Vtx D_7022868[];
extern Vtx D_7022C08[];
extern Vtx D_7022C48[];

Gfx* func_i9_8014BE8C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7022748, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7022C48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70227C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7022868, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 15, 11, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 22, 25, 0, 23, 22, 24, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 33, 35, 34, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 37, 39, 38, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 55, 56, 57, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7022708, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7022C08, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_7022D08[];
extern Vtx D_7022DB8[];
extern Vtx D_7022FB8[];
extern Vtx D_7022FF8[];

Gfx* func_i9_8014C32C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7022D08, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 2, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 6, 9, 7, 0, 9, 10, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7022FF8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 2, 0);
    gSP2Triangles(gfx++, 0, 2, 3, 0, 4, 5, 6, 0);
    gSP1Triangle(gfx++, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7022DB8, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 16, 18, 17, 0, 0, 2, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7022FB8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP1Triangle(gfx++, 0, 3, 0, 0);

    return gfx;
}

extern Vtx D_301CED8[];
extern Vtx D_301D298[];
extern Vtx D_301D338[];
extern Vtx D_301D598[];
extern Vtx D_301D6B8[];
extern Vtx D_301D808[];
extern Vtx D_301D928[];

Gfx* func_i9_8014C5D4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_301D338, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 6, 8, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 26, 25, 27, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 20, 29, 21, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 10, 34, 11, 0, 18, 35, 16, 0);
    gSP1Triangle(gfx++, 2, 36, 37, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_301D598, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 4, 0);
    gSP2Triangles(gfx++, 8, 5, 4, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_301D928, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 6, 11, 12, 0);
    gSP2Triangles(gfx++, 8, 13, 9, 0, 14, 15, 16, 0);
    gSP1Triangle(gfx++, 17, 18, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_301CED8, 60, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 17, 16, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 18, 0);
    gSP2Triangles(gfx++, 23, 22, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 28, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 32, 0);
    gSP2Triangles(gfx++, 37, 36, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 41, 22, 42, 0, 43, 22, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 46, 48, 47, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 49, 51, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 4, 56, 57, 0);
    gSP1Triangle(gfx++, 11, 58, 59, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_301D298, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_301D6B8, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP1Triangle(gfx++, 17, 19, 20, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_301D808, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 6, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 10, 16, 17, 0);

    return gfx;
}

extern Vtx D_7023078[];
extern Vtx D_7023308[];
extern Vtx D_70233A8[];
extern Vtx D_70235C8[];
extern Vtx D_70236C8[];
extern Vtx D_7023818[];
extern Vtx D_7023938[];

Gfx* func_i9_8014CD1C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70233A8, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 15, 0);
    gSP2Triangles(gfx++, 18, 16, 19, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 9, 27, 28, 0, 26, 25, 29, 0);
    gSP2Triangles(gfx++, 21, 23, 30, 0, 31, 32, 1, 0);
    gSP1Triangle(gfx++, 32, 33, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70235C8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7023938, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 4, 10, 11, 0, 12, 13, 14, 0);
    gSP1Triangle(gfx++, 13, 15, 14, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7023078, 41, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 22, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 30, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 4, 37, 38, 0);
    gSP1Triangle(gfx++, 11, 39, 40, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7023308, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70236C8, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 19, 20, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7023818, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 2, 7, 0, 4, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);

    return gfx;
}

extern Vtx D_7023A38[];
extern Vtx D_7023C48[];
extern Vtx D_7023D08[];
extern Vtx D_7023EC8[];
extern Vtx D_7023FB8[];
extern Vtx D_70240A8[];
extern Vtx D_70241C8[];

Gfx* func_i9_8014D3A0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7023D08, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 18, 20, 19, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 24, 22, 0, 25, 26, 27, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7023EC8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 12, 14, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70241C8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 0, 2, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 9, 0);
    gSP1Triangle(gfx++, 13, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7023A38, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 5, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 4, 29, 30, 0);
    gSP1Triangle(gfx++, 11, 31, 32, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7023C48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 0, 3, 0, 10, 3, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7023FB8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70240A8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 9, 11, 0, 12, 0, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);

    return gfx;
}

extern Vtx D_70242C8[];
extern Vtx D_7024468[];
extern Vtx D_70245A8[];
extern Vtx D_7024668[];
extern Vtx D_7024758[];
extern Vtx D_7024828[];

Gfx* func_i9_8014D9A4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7024468, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 12, 10, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70245A8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7024828, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70242C8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 4, 22, 23, 0, 10, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7024668, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7024758, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 4, 0, 8, 0, 9, 0);
    gSP1Triangle(gfx++, 10, 11, 12, 0);

    return gfx;
}

extern Vtx D_70248E8[];
extern Vtx D_70249A8[];
extern Vtx D_7024AA8[];
extern Vtx D_7024B08[];
extern Vtx D_7024B38[];

Gfx* func_i9_8014DE64(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70249A8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 5, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 0, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7024AA8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70248E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 6, 7, 8, 0);
    gSP1Triangle(gfx++, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7024B08, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7024B38, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_301E498[];
extern Vtx D_301E6B8[];
extern Vtx D_301E7B8[];
extern Vtx D_301E838[];
extern Vtx D_301EA18[];
extern Vtx D_301EB78[];
extern Vtx D_301EC98[];
extern Vtx D_301F088[];

Gfx* func_i9_8014E104(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_301E7B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_301E838, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 9, 8, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 3, 6, 0, 15, 17, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_301EC98, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 1, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 12, 0);
    gSP2Triangles(gfx++, 27, 12, 29, 0, 29, 11, 30, 0);
    gSP2Triangles(gfx++, 29, 12, 11, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 16, 18, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 32, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 44, 6, 45, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 3, 44, 0, 3, 6, 44, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 51, 53, 54, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 57, 58, 0);
    gSP2Triangles(gfx++, 54, 59, 60, 0, 61, 55, 62, 0);
    gSPVertex(gfx++, D_301F088, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_301E498, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 4, 0, 8, 7, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 6, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 25, 23, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 24, 27, 29, 0);
    gSP2Triangles(gfx++, 12, 30, 31, 0, 24, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_301E6B8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 5, 15, 6, 0);
    gSP2Triangles(gfx++, 1, 4, 6, 0, 1, 6, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_301EA18, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 7, 12, 13, 0, 7, 13, 14, 0);
    gSP2Triangles(gfx++, 11, 15, 16, 0, 11, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_301EB78, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 13, 15, 0, 5, 16, 17, 0);

    return gfx;
}

extern Vtx D_7024BC8[];
extern Vtx D_7024DA8[];
extern Vtx D_7024EA8[];
extern Vtx D_7024F18[];
extern Vtx D_7025128[];
extern Vtx D_7025288[];
extern Vtx D_7025358[];

Gfx* func_i9_8014E8E0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7024EA8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 3, 5, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7024F18, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 1, 18, 2, 0, 11, 10, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 25, 3, 5, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 26, 29, 27, 0, 30, 31, 32, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7025358, 61, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 8, 9, 4, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 11, 10, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 44, 42, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 16, 48, 47, 0, 43, 49, 50, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 54, 37, 39, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 58, 59, 60, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7024BC8, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 3, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 11, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 20, 24, 25, 0);
    gSP2Triangles(gfx++, 10, 26, 27, 0, 20, 28, 29, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7024DA8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 2, 0);
    gSP2Triangles(gfx++, 3, 2, 5, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 6, 8, 9, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 10, 12, 13, 0, 14, 3, 5, 0);
    gSP2Triangles(gfx++, 14, 5, 15, 0, 4, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7025128, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 3, 12, 13, 0, 3, 13, 14, 0);
    gSP2Triangles(gfx++, 7, 15, 16, 0, 7, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7025288, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP1Triangle(gfx++, 11, 7, 12, 0);

    return gfx;
}

extern Vtx D_7025728[];
extern Vtx D_70258F8[];
extern Vtx D_70259F8[];
extern Vtx D_7025A58[];
extern Vtx D_7025B98[];
extern Vtx D_7025CA8[];
extern Vtx D_7025D78[];

Gfx* func_i9_8014EFAC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70259F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7025A58, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 2, 1, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 17, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 16, 0, 0, 2, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7025D78, 40, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 5, 4, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 18, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 22, 24, 23, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7025728, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 3, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 19, 23, 24, 0, 10, 25, 26, 0);
    gSP1Triangle(gfx++, 19, 27, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70258F8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7025B98, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 2, 1, 10, 0, 11, 4, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 13, 15, 16, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7025CA8, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP1Triangle(gfx++, 11, 7, 12, 0);

    return gfx;
}

extern Vtx D_7025FF8[];
extern Vtx D_70261C8[];
extern Vtx D_7026228[];
extern Vtx D_7026348[];
extern Vtx D_7026468[];
extern Vtx D_70264F8[];

Gfx* func_i9_8014F580(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70261C8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7026228, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 4, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 2, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 1, 10, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70264F8, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 12, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 24, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7025FF8, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 3, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 19, 23, 24, 0, 10, 25, 26, 0);
    gSP1Triangle(gfx++, 19, 27, 28, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7026348, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 1, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 9, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 14, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7026468, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_7026718[];
extern Vtx D_70267E8[];
extern Vtx D_70268A8[];
extern Vtx D_7026918[];
extern Vtx D_7026948[];

Gfx* func_i9_8014FA30(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 101, 229, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70267E8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7026948, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7026718, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 1, 6, 7, 0, 8, 9, 10, 0);
    gSP1Triangle(gfx++, 11, 12, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70268A8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP1Triangle(gfx++, 5, 6, 0, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7026918, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_301F768[];
extern Vtx D_301F808[];
extern Vtx D_301F888[];
extern Vtx D_301F948[];
extern Vtx D_301FA08[];
extern Vtx D_301FDE8[];
extern Vtx D_301FE58[];
extern Vtx D_301FF98[];
extern Vtx D_3020028[];

Gfx* func_i9_8014FCC0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_301FF98, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 10, 10, 70, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3020028, 35, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 11, 17, 12, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 25, 20, 26, 0);
    gSP2Triangles(gfx++, 1, 12, 17, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 27, 0, 32, 9, 8, 0);
    gSP2Triangles(gfx++, 9, 33, 34, 0, 9, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_301F888, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 0, 2, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_301FA08, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 12, 18, 19, 0, 12, 19, 13, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 25, 27, 26, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 49, 50, 0, 24, 26, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 52, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);
    gSP1Triangle(gfx++, 60, 61, 0, 0);
    gSPVertex(gfx++, D_301FDE8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 0, 2, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_301F768, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_301F808, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_301F948, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_301FE58, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7026A08[];
extern Vtx D_7026AA8[];
extern Vtx D_7026B28[];
extern Vtx D_7026BC8[];
extern Vtx D_7026C88[];
extern Vtx D_7027088[];
extern Vtx D_70271C8[];
extern Vtx D_7027258[];

Gfx* func_i9_80150414(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70271C8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 1, 0, 4, 3, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 10, 10, 70, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7027258, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 9, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 20, 23, 21, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 25, 0, 29, 4, 6, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7026B28, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7026C88, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 5, 11, 12, 0);
    gSP2Triangles(gfx++, 5, 12, 6, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 18, 20, 19, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 17, 19, 44, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 45, 47, 48, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 49, 51, 52, 0, 53, 13, 15, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 57, 58, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 62, 63, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7026A08, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7026AA8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7026BC8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7027088, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7027438[];
extern Vtx D_70274D8[];
extern Vtx D_7027558[];
extern Vtx D_70275B8[];
extern Vtx D_7027678[];
extern Vtx D_70279B8[];
extern Vtx D_7027AF8[];
extern Vtx D_7027B88[];

Gfx* func_i9_80150AEC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7027AF8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 2, 7, 0, 4, 3, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 10, 10, 70, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7027B88, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 14, 21, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7027558, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7027678, 52, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 10, 12, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 43, 44, 0, 45, 7, 9, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 3, 6, 0, 50, 6, 51, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7027438, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70274D8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70275B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70279B8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_7027CE8[];
extern Vtx D_7027D88[];
extern Vtx D_7027E48[];
extern Vtx D_7028188[];
extern Vtx D_70281C8[];

Gfx* func_i9_801511A8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 10, 10, 70, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70281C8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7027E48, 52, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 10, 16, 11, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 29, 13, 15, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 43, 44, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 45, 47, 48, 0, 49, 50, 51, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7027CE8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7027D88, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7028188, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_70282A8[];
extern Vtx D_70282E8[];
extern Vtx D_7028348[];
extern Vtx D_7028468[];
extern Vtx D_70284A8[];

Gfx* func_i9_8015156C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 10, 10, 70, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70284A8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7028348, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 2, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 8, 17, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70282A8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_70282E8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7028468, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_3020B98[];
extern Vtx D_3020CD8[];
extern Vtx D_3021098[];
extern Vtx D_3021268[];
extern Vtx D_3021328[];
extern Vtx D_3021448[];
extern Vtx D_3021578[];

Gfx* func_i9_801517FC(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3021578, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 1, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 19, 21, 0);
    gSP2Triangles(gfx++, 22, 14, 13, 0, 23, 17, 24, 0);
    gSP2Triangles(gfx++, 18, 25, 19, 0, 26, 27, 3, 0);
    gSP2Triangles(gfx++, 28, 29, 2, 0, 3, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3021448, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 2, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 16, 17, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 147, 33, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3020CD8, 60, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 3, 6, 0, 7, 4, 6, 0);
    gSP2Triangles(gfx++, 1, 8, 2, 0, 1, 9, 10, 0);
    gSP2Triangles(gfx++, 1, 10, 4, 0, 9, 1, 11, 0);
    gSP2Triangles(gfx++, 12, 3, 13, 0, 12, 6, 3, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 2, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 20, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 30, 32, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 34, 37, 35, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 38, 40, 41, 0, 42, 43, 44, 0);
    gSP2Triangles(gfx++, 42, 45, 43, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 49, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 53, 56, 54, 0);
    gSP1Triangle(gfx++, 57, 58, 59, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 240, 180, 20, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3021098, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 8, 13, 9, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 23, 25, 26, 0);
    gSP2Triangles(gfx++, 0, 27, 1, 0, 10, 28, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3020B98, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 6, 8, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 11, 10, 8, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 13, 12, 0);
    gSP2Triangles(gfx++, 12, 16, 15, 0, 12, 17, 16, 0);
    gSP2Triangles(gfx++, 18, 19, 2, 0, 2, 4, 18, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3021268, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 0, 2, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3021328, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    return gfx;
}

extern Vtx D_7028528[];
extern Vtx D_70285E8[];
extern Vtx D_7028918[];
extern Vtx D_7028A38[];
extern Vtx D_7028AF8[];
extern Vtx D_7028BE8[];
extern Vtx D_7028D18[];

Gfx* func_i9_80151FE0(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7028D18, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 1, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 18, 17, 0);
    gSP2Triangles(gfx++, 27, 28, 3, 0, 29, 30, 2, 0);
    gSP1Triangle(gfx++, 31, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7028BE8, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 13, 15, 0, 16, 17, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 147, 33, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70285E8, 51, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 4, 7, 0);
    gSP2Triangles(gfx++, 8, 5, 7, 0, 0, 9, 10, 0);
    gSP2Triangles(gfx++, 0, 10, 5, 0, 9, 0, 11, 0);
    gSP2Triangles(gfx++, 12, 4, 13, 0, 12, 7, 4, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 2, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 20, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 27, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 31, 34, 32, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 35, 37, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 39, 42, 40, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 43, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 47, 50, 48, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 240, 180, 20, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7028918, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 9, 11, 0, 6, 8, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7028528, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 10, 11, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7028A38, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7028AF8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_7028F38[];
extern Vtx D_7028FF8[];
extern Vtx D_70292E8[];
extern Vtx D_7029408[];
extern Vtx D_70294C8[];
extern Vtx D_7029558[];
extern Vtx D_7029668[];

Gfx* func_i9_801526BC(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7029668, 13, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 8, 9, 2, 0);
    gSP1Triangle(gfx++, 10, 11, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7029558, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 11, 15, 0, 16, 10, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 147, 33, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7028FF8, 47, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 4, 7, 0);
    gSP2Triangles(gfx++, 8, 5, 7, 0, 0, 9, 10, 0);
    gSP2Triangles(gfx++, 0, 10, 5, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 4, 15, 0, 14, 7, 4, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 2, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 44, 45, 46, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 240, 180, 20, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70292E8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 0, 2, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7028F38, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 10, 11, 8, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7029408, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70294C8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_7029738[];
extern Vtx D_7029A28[];
extern Vtx D_7029AE8[];
extern Vtx D_7029BA8[];
extern Vtx D_7029BD8[];
extern Vtx D_7029CD8[];

Gfx* func_i9_80152CA8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7029CD8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 8, 9, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7029BD8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 12, 11, 14, 0, 15, 10, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 147, 33, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7029738, 47, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 4, 0, 10, 1, 12, 0);
    gSP2Triangles(gfx++, 13, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 26, 27, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 44, 45, 46, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 240, 180, 20, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7029A28, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 4, 6, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7029AE8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 0, 11, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7029BA8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_7029D78[];
extern Vtx D_7029EF8[];
extern Vtx D_7029F98[];
extern Vtx D_7029FC8[];
extern Vtx D_702A028[];
extern Vtx D_702A088[];

Gfx* func_i9_801531A4(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702A088, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 5, 7, 0, 8, 9, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702A028, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 147, 33, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7029D78, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 240, 180, 20, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7029EF8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 1, 0, 3, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7029F98, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7029FC8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_30225B8[];
extern Vtx D_3022618[];
extern Vtx D_3022718[];
extern Vtx D_3022988[];
extern Vtx D_3022CB8[];
extern Vtx D_3022D58[];
extern Vtx D_3022E18[];

Gfx* func_i9_80153538(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3022E18, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 16, 18, 17, 0, 4, 6, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3022718, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 7, 13, 8, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 5, 4, 0, 21, 14, 22, 0);
    gSP2Triangles(gfx++, 17, 23, 18, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 27, 33, 28, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 34, 36, 37, 0, 1, 0, 38, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3022988, 51, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 9, 7, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 9, 14, 7, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 11, 19, 13, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 26, 24, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 30, 28, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 20, 22, 0);
    gSP2Triangles(gfx++, 3, 38, 4, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 40, 42, 41, 0, 43, 44, 2, 0);
    gSP2Triangles(gfx++, 31, 33, 45, 0, 0, 46, 1, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 48, 50, 49, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30225B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3022618, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 2, 0, 1, 0, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3022D58, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 4, 6, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3022CB8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_702A128[];
extern Vtx D_702A188[];
extern Vtx D_702A288[];
extern Vtx D_702A4F8[];
extern Vtx D_702A808[];
extern Vtx D_702A8A8[];
extern Vtx D_702A968[];

Gfx* func_i9_80153BD4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702A968, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702A288, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 7, 13, 8, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 5, 4, 0, 21, 14, 22, 0);
    gSP2Triangles(gfx++, 17, 23, 18, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 30, 31, 32, 0);
    gSP2Triangles(gfx++, 27, 33, 28, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 34, 36, 37, 0, 1, 0, 38, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702A4F8, 49, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 7, 12, 8, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 9, 17, 10, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 24, 22, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 28, 26, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 18, 20, 0);
    gSP2Triangles(gfx++, 3, 36, 4, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 38, 40, 39, 0, 41, 42, 2, 0);
    gSP2Triangles(gfx++, 29, 31, 43, 0, 0, 44, 1, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 46, 48, 47, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702A128, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702A188, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 2, 0, 1, 0, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702A8A8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 4, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702A808, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_702AA68[];
extern Vtx D_702AAC8[];
extern Vtx D_702AB28[];
extern Vtx D_702ACC8[];
extern Vtx D_702AFB8[];
extern Vtx D_702B058[];
extern Vtx D_702B118[];

Gfx* func_i9_80154234(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702B118, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702AB28, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 4, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 12, 18, 13, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 10, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702ACC8, 47, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 5, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 6, 17, 7, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 22, 27, 23, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 31, 0, 24, 32, 25, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 36, 37, 38, 0);
    gSP2Triangles(gfx++, 36, 39, 37, 0, 40, 41, 42, 0);
    gSP2Triangles(gfx++, 40, 43, 41, 0, 44, 14, 16, 0);
    gSP2Triangles(gfx++, 18, 45, 19, 0, 46, 0, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702AA68, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702AAC8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 3, 2, 0, 1, 0, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702B058, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702AFB8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_702B218[];
extern Vtx D_702B278[];
extern Vtx D_702B388[];
extern Vtx D_702B5C8[];
extern Vtx D_702B668[];
extern Vtx D_702B728[];

Gfx* func_i9_8015483C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702B728, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702B278, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 0, 2, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 14, 15, 16, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702B388, 36, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 8, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 14, 16, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 24, 25, 26, 0);
    gSP2Triangles(gfx++, 22, 27, 23, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 24, 31, 25, 0, 32, 33, 34, 0);
    gSP1Triangle(gfx++, 18, 35, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702B218, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 3, 2, 0, 4, 2, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702B668, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 0, 11, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702B5C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);

    return gfx;
}

extern Vtx D_702B7E8[];
extern Vtx D_702B858[];
extern Vtx D_702BAA8[];

Gfx* func_i9_80154CE4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702BAA8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702B858, 37, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 0, 2, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 6, 8, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 24, 32, 25, 0, 29, 33, 30, 0);
    gSP1Triangle(gfx++, 34, 35, 36, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702B7E8, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 4, 0);
    gSP2Triangles(gfx++, 3, 5, 1, 0, 6, 3, 1, 0);

    return gfx;
}

extern Vtx D_3023798[];
extern Vtx D_3023838[];
extern Vtx D_3023878[];
extern Vtx D_3023AA8[];
extern Vtx D_3023C48[];
extern Vtx D_3024048[];
extern Vtx D_30240F8[];
extern Vtx D_30241F8[];
extern Vtx D_30242B8[];

Gfx* func_i9_80154F14(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30242B8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 100, 0, 24, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3023878, 35, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 13, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 18, 0, 13, 12, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 17, 0, 20, 17, 16, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 22, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 23, 0, 24, 28, 25, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 107, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3023C48, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 33, 0, 36, 33, 32, 0);
    gSP2Triangles(gfx++, 36, 38, 37, 0, 39, 40, 38, 0);
    gSP2Triangles(gfx++, 39, 38, 36, 0, 35, 34, 41, 0);
    gSP2Triangles(gfx++, 35, 41, 39, 0, 41, 40, 39, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 50, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 54, 56, 57, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 58, 60, 61, 0);
    gSP2Triangles(gfx++, 5, 4, 62, 0, 5, 62, 63, 0);
    gSPVertex(gfx++, D_3024048, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 2, 8, 9, 0, 2, 9, 10, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30241F8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3023798, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3023838, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_3023AA8, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 7, 11, 8, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 0, 2, 0, 24, 25, 0, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30240F8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    return gfx;
}

extern Vtx D_702BB08[];
extern Vtx D_702BB48[];
extern Vtx D_702BB88[];
extern Vtx D_702BDA8[];
extern Vtx D_702BEC8[];
extern Vtx D_702C2C8[];
extern Vtx D_702C3C8[];
extern Vtx D_702C488[];

Gfx* func_i9_801556FC(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702C488, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 100, 0, 24, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702BB88, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 19, 18, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 23, 0, 26, 23, 22, 0);
    gSP2Triangles(gfx++, 0, 2, 3, 0, 0, 3, 5, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 107, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702BEC8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 31, 32, 0, 33, 34, 30, 0);
    gSP2Triangles(gfx++, 33, 30, 29, 0, 33, 35, 34, 0);
    gSP2Triangles(gfx++, 36, 37, 35, 0, 36, 35, 33, 0);
    gSP2Triangles(gfx++, 32, 31, 38, 0, 32, 38, 36, 0);
    gSP2Triangles(gfx++, 38, 37, 36, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 39, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 2, 53, 54, 0);
    gSP2Triangles(gfx++, 2, 1, 53, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 55, 58, 56, 0, 59, 60, 61, 0);
    gSP2Triangles(gfx++, 59, 61, 62, 0, 56, 58, 63, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702C3C8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702BB08, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702BB48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_702BDA8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702C2C8, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);

    return gfx;
}

extern Vtx D_702C4C8[];
extern Vtx D_702C508[];
extern Vtx D_702C548[];
extern Vtx D_702C6C8[];
extern Vtx D_702C7E8[];
extern Vtx D_702CAA8[];
extern Vtx D_702CB48[];
extern Vtx D_702CC08[];

Gfx* func_i9_80155EB8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702CC08, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 100, 0, 24, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702C548, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 0, 2, 3, 0, 0, 3, 5, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 107, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702C7E8, 44, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 19, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 27, 28, 24, 0);
    gSP2Triangles(gfx++, 27, 24, 23, 0, 27, 29, 28, 0);
    gSP2Triangles(gfx++, 30, 31, 29, 0, 30, 29, 27, 0);
    gSP2Triangles(gfx++, 26, 25, 32, 0, 26, 32, 30, 0);
    gSP2Triangles(gfx++, 32, 31, 30, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 33, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 41, 42, 43, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702CB48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702C4C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702C508, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_702C6C8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702CAA8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_702CC48[];
extern Vtx D_702CC88[];
extern Vtx D_702CDE8[];
extern Vtx D_702CEC8[];
extern Vtx D_702D028[];
extern Vtx D_702D0C8[];
extern Vtx D_702D188[];

Gfx* func_i9_801564E8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702D188, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 100, 0, 24, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702CC88, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 107, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702CEC8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 10, 8, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702D0C8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702CC48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_702CDE8, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 2, 0, 6, 7, 8, 0);
    gSP2Triangles(gfx++, 9, 10, 11, 0, 12, 13, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702D028, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_702D1C8[];
extern Vtx D_702D208[];
extern Vtx D_702D268[];
extern Vtx D_702D428[];
extern Vtx D_702D468[];

Gfx* func_i9_801569C8(Gfx* gfx) {

    gDPSetCombineLERP(gfx++, TEXEL0, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE,
                      0, 0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702D468, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 100, 0, 24, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702D208, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 107, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702D268, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 9, 11, 10, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 27, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702D1C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702D428, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern Vtx D_30251B8[];
extern Vtx D_3025318[];
extern Vtx D_3025378[];
extern Vtx D_30253F8[];
extern Vtx D_3025438[];
extern Vtx D_3025828[];
extern Vtx D_30259B8[];
extern Vtx D_3025A78[];

Gfx* func_i9_80156CAC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30251B8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 15, 17, 16, 0);
    gSP2Triangles(gfx++, 18, 9, 19, 0, 20, 21, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_30253F8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3025A78, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 7, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 14, 0, 2, 0, 14, 15, 0, 0);
    gSP2Triangles(gfx++, 3, 5, 16, 0, 17, 3, 16, 0);
    gSP2Triangles(gfx++, 6, 18, 17, 0, 6, 17, 16, 0);
    gSP2Triangles(gfx++, 8, 18, 6, 0, 19, 10, 12, 0);
    gSP2Triangles(gfx++, 2, 1, 19, 0, 2, 19, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3025438, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 19, 25, 20, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 29, 27, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 22, 21, 44, 0, 22, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 49, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);
    gSP1Triangle(gfx++, 60, 61, 62, 0);
    gSPVertex(gfx++, D_3025828, 25, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP1Triangle(gfx++, 22, 23, 24, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3025318, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3025378, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30259B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 6, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    return gfx;
}

extern Vtx D_702D4A8[];
extern Vtx D_702D5E8[];
extern Vtx D_702D648[];
extern Vtx D_702D6C8[];
extern Vtx D_702D708[];
extern Vtx D_702DAE8[];
extern Vtx D_702DC48[];
extern Vtx D_702DD08[];

Gfx* func_i9_80157390(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702D4A8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 7, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702D6C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702DD08, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 7, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 14, 0, 2, 0, 14, 15, 0, 0);
    gSP2Triangles(gfx++, 3, 5, 16, 0, 17, 3, 16, 0);
    gSP2Triangles(gfx++, 6, 18, 17, 0, 6, 17, 16, 0);
    gSP2Triangles(gfx++, 8, 18, 6, 0, 19, 10, 12, 0);
    gSP2Triangles(gfx++, 2, 1, 19, 0, 2, 19, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702D708, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 26, 28, 27, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 29, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 33, 36, 34, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 49, 50, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 4, 6, 54, 0, 55, 56, 57, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 58, 60, 61, 0);
    gSPVertex(gfx++, D_702DAE8, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702D5E8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702D648, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702DC48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 6, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    return gfx;
}

extern Vtx D_702DE48[];
extern Vtx D_702DFA8[];
extern Vtx D_702E008[];
extern Vtx D_702E048[];
extern Vtx D_702E088[];
extern Vtx D_702E478[];
extern Vtx D_702E4A8[];
extern Vtx D_702E568[];

Gfx* func_i9_80157A50(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702DE48, 22, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 7, 9, 8, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 3, 17, 18, 0);
    gSP1Triangle(gfx++, 19, 20, 21, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702E048, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702E568, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 0, 12, 14, 0);
    gSP2Triangles(gfx++, 2, 12, 0, 0, 9, 4, 6, 0);
    gSP2Triangles(gfx++, 10, 9, 6, 0, 12, 15, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702E088, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 11, 13, 12, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 14, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 27, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 34, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 42, 47, 43, 0);
    gSP2Triangles(gfx++, 4, 6, 9, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 51, 52, 53, 0, 54, 55, 56, 0);
    gSP2Triangles(gfx++, 57, 58, 59, 0, 60, 61, 62, 0);
    gSPVertex(gfx++, D_702E478, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702DFA8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702E008, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702E4A8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 6, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    return gfx;
}

extern Vtx D_702E668[];
extern Vtx D_702E808[];
extern Vtx D_702E868[];
extern Vtx D_702E8A8[];
extern Vtx D_702EB38[];
extern Vtx D_702EC28[];

Gfx* func_i9_8015805C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702E668, 26, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 13, 12, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 17, 16, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702E868, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702EC28, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702E8A8, 41, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 9, 28, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 38, 39, 40, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702E808, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 2, 4, 3, 0, 5, 1, 0, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702EB38, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_702ECE8[];
extern Vtx D_702EDF8[];
extern Vtx D_702EE28[];
extern Vtx D_702EF48[];
extern Vtx D_702EFA8[];

Gfx* func_i9_801584F0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702ECE8, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 5, 4, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 9, 8, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 13, 16, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702EFA8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702EE28, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702EDF8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702EF48, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_30261F8[];
extern Vtx D_30265F8[];
extern Vtx D_3026658[];
extern Vtx D_30266D8[];
extern Vtx D_3026788[];
extern Vtx D_3026878[];
extern Vtx D_30269B8[];
extern Vtx D_3026B38[];

Gfx* func_i9_80158800(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30261F8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 39, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 42, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 49, 46, 48, 0);
    gSP2Triangles(gfx++, 50, 51, 0, 0, 6, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 54, 56, 57, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 61, 62, 63, 0);
    gSPVertex(gfx++, D_30265F8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3026658, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 0, 2, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3026B38, 43, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 1, 8, 3, 0, 4, 9, 5, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 13, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 31, 0, 25, 27, 32, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 36, 37, 38, 0);
    gSP2Triangles(gfx++, 36, 38, 39, 0, 40, 41, 42, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_30269B8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30266D8, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 2, 7, 8, 0);
    gSP2Triangles(gfx++, 7, 3, 8, 0, 6, 9, 10, 0);
    gSP1Triangle(gfx++, 8, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3026788, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 5, 10, 3, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 1, 14, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3026878, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_702F068[];
extern Vtx D_702F458[];
extern Vtx D_702F4B8[];
extern Vtx D_702F538[];
extern Vtx D_702F5E8[];
extern Vtx D_702F6D8[];
extern Vtx D_702F818[];
extern Vtx D_702F998[];

Gfx* func_i9_80158EEC(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702F068, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 13, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 41, 43, 44, 0);
    gSP2Triangles(gfx++, 45, 46, 47, 0, 48, 45, 47, 0);
    gSP2Triangles(gfx++, 49, 50, 0, 0, 6, 51, 52, 0);
    gSP2Triangles(gfx++, 53, 54, 55, 0, 53, 55, 56, 0);
    gSP2Triangles(gfx++, 57, 58, 59, 0, 60, 61, 62, 0);
    gSPVertex(gfx++, D_702F458, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702F4B8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 0, 2, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_702F998, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 5, 7, 6, 0);
    gSP2Triangles(gfx++, 1, 8, 3, 0, 4, 9, 5, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 4, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 31, 0, 25, 27, 32, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_702F818, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702F538, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 2, 7, 8, 0);
    gSP2Triangles(gfx++, 7, 3, 8, 0, 6, 9, 10, 0);
    gSP1Triangle(gfx++, 8, 0, 2, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_702F5E8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 5, 10, 3, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 1, 14, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_702F6D8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_702FBA8[];
extern Vtx D_702FEF8[];
extern Vtx D_702FF58[];
extern Vtx D_7030008[];
extern Vtx D_70300F8[];
extern Vtx D_7030228[];
extern Vtx D_70303A8[];

Gfx* func_i9_801595B0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_702FBA8, 53, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 33, 35, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 43, 45, 46, 0, 47, 48, 49, 0);
    gSP1Triangle(gfx++, 50, 51, 52, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_702FEF8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70303A8, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 0, 6, 1, 0, 3, 7, 4, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 13, 14, 0, 15, 16, 10, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 17, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 25, 27, 28, 0, 22, 24, 29, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7030228, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_702FF58, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 1, 4, 3, 0);
    gSP2Triangles(gfx++, 2, 7, 0, 0, 8, 9, 10, 0);
    gSP1Triangle(gfx++, 7, 8, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7030008, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 6, 8, 0);
    gSP1Triangle(gfx++, 2, 14, 0, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70300F8, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP1Triangle(gfx++, 16, 17, 18, 0);

    return gfx;
}

extern Vtx D_7030588[];
extern Vtx D_70306C8[];
extern Vtx D_70307B8[];
extern Vtx D_70308E8[];
extern Vtx D_7030A08[];

Gfx* func_i9_80159BE0(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7030588, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 4, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7030A08, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 6, 8, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 21, 23, 24, 0, 18, 20, 25, 0);
    gSP2Triangles(gfx++, 3, 5, 26, 0, 27, 2, 1, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70308E8, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_70306C8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 0, 2, 0);
    gSP1Triangle(gfx++, 5, 14, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70307B8, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 15, 17, 0);

    return gfx;
}

extern Vtx D_7030BC8[];
extern Vtx D_7030C18[];
extern Vtx D_7030C48[];
extern Vtx D_7030CA8[];

Gfx* func_i9_80159F7C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7030CA8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 4, 10, 0);
    gSP2Triangles(gfx++, 6, 8, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 0, 2, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 19, 21, 22, 0);
    gSP1Triangle(gfx++, 16, 18, 23, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7030C48, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7030BC8, 5, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP1Triangle(gfx++, 2, 3, 4, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 209, 238, 255, 255);
    gDPSetEnvColor(gfx++, 14, 99, 165, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7030C18, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    return gfx;
}

extern Vtx D_30274A8[];
extern Vtx D_3027508[];
extern Vtx D_3027568[];
extern Vtx D_3027728[];
extern Vtx D_30277A8[];
extern Vtx D_30278E8[];
extern Vtx D_3027AE8[];
extern Vtx D_3027EE8[];
extern Vtx D_30282D8[];

Gfx* func_i9_8015A1B4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_30278E8, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 3, 0, 5, 4, 3, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 6, 8, 0);
    gSP2Triangles(gfx++, 9, 8, 10, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 18, 20, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 29, 31, 30, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3027AE8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 14, 13, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 18, 17, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 38, 40, 41, 0);
    gSP2Triangles(gfx++, 42, 43, 44, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 45, 47, 48, 0, 49, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 52, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 62, 63, 0);
    gSPVertex(gfx++, D_3027EE8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 33, 32, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 37, 36, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 59, 60, 61, 0);
    gSP1Triangle(gfx++, 59, 61, 62, 0);
    gSPVertex(gfx++, D_30282D8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 2, 6, 0, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 7, 9, 10, 0, 11, 12, 13, 0);
    gSP1Triangle(gfx++, 11, 13, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3027568, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3027728, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 2, 1, 6, 0, 7, 4, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_30274A8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);
    gSP2Triangles(gfx++, 1, 0, 4, 0, 1, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3027508, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 2, 0);
    gSP2Triangles(gfx++, 3, 2, 1, 0, 0, 2, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_30277A8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_7030E28[];
extern Vtx D_7030E68[];
extern Vtx D_7030EC8[];
extern Vtx D_7030F88[];
extern Vtx D_7031048[];
extern Vtx D_7031188[];
extern Vtx D_7031348[];
extern Vtx D_7031738[];

Gfx* func_i9_8015AAE8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7031188, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 22, 23, 20, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 25, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7031348, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 43, 44, 0, 45, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 35, 52, 36, 0, 28, 53, 29, 0);
    gSP2Triangles(gfx++, 21, 54, 22, 0, 14, 55, 15, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);
    gSP1Triangle(gfx++, 60, 61, 62, 0);
    gSPVertex(gfx++, D_7031738, 49, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 31, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 41, 43, 44, 0, 45, 46, 47, 0);
    gSP1Triangle(gfx++, 45, 47, 48, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7030EC8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7030F88, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7030E28, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7030E68, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7031048, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7031A48[];
extern Vtx D_7031A88[];
extern Vtx D_7031AE8[];
extern Vtx D_7031B68[];
extern Vtx D_7031C28[];
extern Vtx D_7031CC8[];
extern Vtx D_7031E48[];
extern Vtx D_7032248[];

Gfx* func_i9_8015B1F4(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7031CC8, 24, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7031E48, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 23, 25, 26, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 37, 39, 40, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 47, 49, 50, 0, 51, 52, 53, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 54, 56, 57, 0);
    gSP2Triangles(gfx++, 58, 59, 60, 0, 61, 62, 63, 0);
    gSPVertex(gfx++, D_7032248, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 18, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 23, 0, 25, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7031AE8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7031B68, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7031A48, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 2, 3, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7031A88, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7031C28, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_7032448[];
extern Vtx D_70324A8[];
extern Vtx D_7032528[];
extern Vtx D_70325E8[];
extern Vtx D_7032688[];
extern Vtx D_70327A8[];

Gfx* func_i9_8015B7E8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7032688, 18, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70327A8, 46, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70324A8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7032528, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7032448, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 1, 0, 4, 1, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70325E8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    return gfx;
}

extern Vtx D_7032A88[];
extern Vtx D_7032AB8[];
extern Vtx D_7032B78[];
extern Vtx D_7032C08[];
extern Vtx D_7032C68[];

Gfx* func_i9_8015BC90(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7032C08, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7032C68, 32, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 4, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 20, 21, 22, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 27, 28, 0);
    gSP1Triangle(gfx++, 29, 30, 31, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7032AB8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7032A88, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7032B78, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_3028A08[];
extern Vtx D_3028A88[];
extern Vtx D_3028B08[];
extern Vtx D_3028D68[];
extern Vtx D_3028EA8[];
extern Vtx D_3028EE8[];
extern Vtx D_3028FA8[];
extern Vtx D_3029398[];

Gfx* func_i9_8015BF44(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3028A88, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 89, 84, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3028B08, 38, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 8, 0);
    gSP2Triangles(gfx++, 9, 8, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 7, 0, 15, 11, 16, 0);
    gSP2Triangles(gfx++, 17, 13, 12, 0, 18, 13, 17, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 18, 22, 13, 0);
    gSP2Triangles(gfx++, 23, 24, 25, 0, 26, 12, 14, 0);
    gSP2Triangles(gfx++, 23, 21, 24, 0, 27, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 27, 29, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 21, 20, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 24, 21, 34, 0, 0, 30, 1, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_3028FA8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 8, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 11, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 15, 17, 18, 0);
    gSP2Triangles(gfx++, 9, 19, 10, 0, 9, 20, 19, 0);
    gSP2Triangles(gfx++, 21, 22, 23, 0, 22, 24, 23, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 25, 28, 26, 0);
    gSP2Triangles(gfx++, 29, 30, 31, 0, 30, 32, 31, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 33, 36, 34, 0);
    gSP2Triangles(gfx++, 37, 3, 5, 0, 38, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 44, 46, 47, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 48, 51, 49, 0, 52, 53, 54, 0);
    gSP2Triangles(gfx++, 52, 55, 53, 0, 55, 56, 53, 0);
    gSP2Triangles(gfx++, 56, 57, 53, 0, 58, 59, 9, 0);
    gSP1Triangle(gfx++, 60, 61, 62, 0);
    gSPVertex(gfx++, D_3029398, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3028A08, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 0, 5, 0, 1, 6, 7, 0);
    gSP2Triangles(gfx++, 2, 1, 7, 0, 5, 0, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3028EA8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_3028EE8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3028D68, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    return gfx;
}

extern Vtx D_7032E68[];
extern Vtx D_7032F08[];
extern Vtx D_7032F88[];
extern Vtx D_70331F8[];
extern Vtx D_7033338[];
extern Vtx D_7033378[];
extern Vtx D_70333F8[];
extern Vtx D_70337E8[];

Gfx* func_i9_8015C634(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7032F08, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 89, 84, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7032F88, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 13, 0);
    gSP2Triangles(gfx++, 14, 13, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 16, 21, 0);
    gSP2Triangles(gfx++, 23, 18, 17, 0, 24, 18, 23, 0);
    gSP2Triangles(gfx++, 25, 26, 1, 0, 24, 27, 18, 0);
    gSP2Triangles(gfx++, 28, 0, 29, 0, 30, 17, 19, 0);
    gSP2Triangles(gfx++, 28, 1, 0, 0, 10, 31, 32, 0);
    gSP2Triangles(gfx++, 4, 10, 32, 0, 33, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 2, 1, 26, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70333F8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 15, 0, 18, 19, 20, 0);
    gSP2Triangles(gfx++, 18, 20, 21, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 22, 24, 25, 0, 16, 26, 17, 0);
    gSP2Triangles(gfx++, 27, 28, 29, 0, 28, 30, 29, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 31, 34, 32, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 36, 38, 37, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 39, 42, 40, 0);
    gSP2Triangles(gfx++, 16, 43, 26, 0, 44, 45, 46, 0);
    gSP2Triangles(gfx++, 47, 48, 49, 0, 50, 51, 52, 0);
    gSP2Triangles(gfx++, 50, 52, 53, 0, 54, 10, 12, 0);
    gSP2Triangles(gfx++, 55, 56, 57, 0, 55, 58, 56, 0);
    gSP2Triangles(gfx++, 59, 2, 60, 0, 61, 62, 16, 0);
    gSP1Triangle(gfx++, 59, 0, 2, 0);
    gSPVertex(gfx++, D_70337E8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7032E68, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7033338, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7033378, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70331F8, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);

    return gfx;
}

extern Vtx D_7033818[];
extern Vtx D_70338B8[];
extern Vtx D_7033918[];
extern Vtx D_7033B88[];
extern Vtx D_7033C18[];
extern Vtx D_7033C58[];
extern Vtx D_7033CD8[];

Gfx* func_i9_8015CD18(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70338B8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 89, 84, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7033918, 39, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 7, 0);
    gSP2Triangles(gfx++, 17, 13, 12, 0, 18, 13, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 18, 23, 13, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 27, 12, 14, 0);
    gSP2Triangles(gfx++, 24, 22, 25, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 31, 22, 21, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 35, 36, 37, 0, 25, 22, 38, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7033CD8, 58, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 3, 4, 1, 0, 4, 5, 1, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 15, 17, 18, 0, 19, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);
    gSP2Triangles(gfx++, 46, 47, 48, 0, 46, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 39, 0, 50, 52, 51, 0);
    gSP2Triangles(gfx++, 50, 53, 52, 0, 54, 22, 24, 0);
    gSP2Triangles(gfx++, 55, 19, 16, 0, 6, 8, 56, 0);
    gSP1Triangle(gfx++, 17, 19, 57, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7033818, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7033C18, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7033C58, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7033B88, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_7034078[];
extern Vtx D_7034118[];
extern Vtx D_7034148[];
extern Vtx D_7034368[];
extern Vtx D_70343F8[];
extern Vtx D_7034428[];

Gfx* func_i9_8015D344(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7034118, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 89, 84, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7034148, 34, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 6, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 15, 18, 0, 19, 20, 1, 0);
    gSP2Triangles(gfx++, 17, 21, 15, 0, 1, 0, 22, 0);
    gSP2Triangles(gfx++, 23, 16, 15, 0, 24, 25, 22, 0);
    gSP2Triangles(gfx++, 24, 26, 25, 0, 27, 1, 20, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 31, 32, 33, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7034428, 43, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 3, 10, 4, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 38, 39, 36, 0, 39, 40, 36, 0);
    gSP1Triangle(gfx++, 8, 41, 42, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7034078, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70343F8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7034368, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_70346D8[];
extern Vtx D_7034778[];
extern Vtx D_70347D8[];
extern Vtx D_7034808[];

Gfx* func_i9_8015D814(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 89, 84, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70346D8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 5, 4, 0);
    gSP2Triangles(gfx++, 1, 3, 8, 0, 9, 6, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7034808, 28, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 1, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 11, 12, 13, 0, 14, 15, 16, 0);
    gSP2Triangles(gfx++, 17, 18, 19, 0, 6, 20, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70347D8, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7034778, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_3029A88[];
extern Vtx D_3029B48[];
extern Vtx D_3029C78[];
extern Vtx D_3029CF8[];
extern Vtx D_3029FD8[];
extern Vtx D_302A128[];
extern Vtx D_302A528[];
extern Vtx D_302A628[];

Gfx* func_i9_8015DA94(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_3029C78, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_3029CF8, 46, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 9, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 13, 16, 14, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 20, 18, 0, 21, 22, 8, 0);
    gSP2Triangles(gfx++, 22, 6, 8, 0, 6, 23, 7, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 4, 3, 27, 0);
    gSP2Triangles(gfx++, 4, 27, 24, 0, 4, 24, 26, 0);
    gSP2Triangles(gfx++, 28, 1, 29, 0, 30, 26, 25, 0);
    gSP2Triangles(gfx++, 31, 32, 33, 0, 34, 35, 36, 0);
    gSP2Triangles(gfx++, 0, 37, 1, 0, 0, 2, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 40, 0);
    gSP2Triangles(gfx++, 42, 40, 44, 0, 43, 42, 45, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_302A128, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 0, 0);
    gSP2Triangles(gfx++, 5, 6, 7, 0, 8, 9, 10, 0);
    gSP2Triangles(gfx++, 8, 10, 11, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 12, 14, 15, 0, 16, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 21, 0, 22, 23, 19, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 25, 27, 26, 0);
    gSP2Triangles(gfx++, 24, 28, 25, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 30, 25, 0, 30, 31, 27, 0);
    gSP2Triangles(gfx++, 30, 27, 25, 0, 32, 33, 34, 0);
    gSP2Triangles(gfx++, 32, 34, 35, 0, 34, 36, 37, 0);
    gSP2Triangles(gfx++, 34, 37, 35, 0, 38, 35, 39, 0);
    gSP2Triangles(gfx++, 38, 32, 35, 0, 35, 37, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 52, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 62, 63, 0);
    gSPVertex(gfx++, D_302A528, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSPVertex(gfx++, D_302A628, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_3029A88, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 3, 4, 1, 0, 3, 5, 4, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 1, 4, 0, 8, 4, 9, 0);
    gSP2Triangles(gfx++, 0, 10, 11, 0, 0, 11, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_3029B48, 19, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 3, 10, 1, 0, 11, 12, 8, 0);
    gSP2Triangles(gfx++, 5, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 15, 17, 18, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_3029FD8, 21, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP1Triangle(gfx++, 18, 19, 20, 0);

    return gfx;
}

extern Vtx D_70349C8[];
extern Vtx D_7034A68[];
extern Vtx D_7034B78[];
extern Vtx D_7034BF8[];
extern Vtx D_7034ED8[];
extern Vtx D_7034FC8[];
extern Vtx D_70353C8[];

Gfx* func_i9_8015E268(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7034B78, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7034BF8, 46, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 7, 0, 3, 5, 6, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 19, 17, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 25, 0, 27, 23, 25, 0);
    gSP2Triangles(gfx++, 23, 28, 24, 0, 29, 2, 1, 0);
    gSP2Triangles(gfx++, 21, 20, 30, 0, 31, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 21, 30, 29, 0);
    gSP2Triangles(gfx++, 21, 29, 1, 0, 37, 5, 38, 0);
    gSP2Triangles(gfx++, 39, 40, 41, 0, 42, 43, 40, 0);
    gSP2Triangles(gfx++, 42, 40, 44, 0, 43, 42, 45, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7034FC8, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 13, 15, 14, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 19, 18, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 25, 27, 26, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 52, 54, 55, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 56, 58, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 62, 63, 0);
    gSPVertex(gfx++, D_70353C8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70349C8, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 3, 4, 1, 0, 3, 5, 4, 0);
    gSP2Triangles(gfx++, 6, 1, 4, 0, 6, 4, 7, 0);
    gSP2Triangles(gfx++, 0, 8, 9, 0, 0, 9, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7034A68, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 2, 7, 0, 4, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP1Triangle(gfx++, 13, 15, 16, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7034ED8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_7035408[];
extern Vtx D_7035488[];
extern Vtx D_7035598[];
extern Vtx D_70357A8[];
extern Vtx D_7035898[];

Gfx* func_i9_8015E910(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7035598, 33, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 0, 3, 4, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 4, 9, 0, 10, 11, 6, 0);
    gSP2Triangles(gfx++, 10, 12, 13, 0, 14, 0, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 18, 17, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 29, 30, 28, 0);
    gSP2Triangles(gfx++, 26, 31, 27, 0, 3, 32, 4, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7035898, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 4, 6, 5, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 19, 0, 2, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 23, 21, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 25, 27, 26, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 32, 34, 35, 0);
    gSP2Triangles(gfx++, 36, 37, 38, 0, 36, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 40, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 47, 48, 49, 0);
    gSP2Triangles(gfx++, 50, 51, 52, 0, 53, 54, 55, 0);
    gSP2Triangles(gfx++, 53, 55, 56, 0, 57, 58, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 62, 63, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7035408, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 3, 4, 1, 0, 3, 5, 4, 0);
    gSP2Triangles(gfx++, 6, 1, 4, 0, 6, 4, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7035488, 17, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 5, 10, 0);
    gSP2Triangles(gfx++, 7, 11, 12, 0, 13, 14, 15, 0);
    gSP1Triangle(gfx++, 13, 15, 16, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70357A8, 15, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP1Triangle(gfx++, 12, 13, 14, 0);

    return gfx;
}

extern Vtx D_7035C98[];
extern Vtx D_7035D78[];
extern Vtx D_7035F58[];
extern Vtx D_7035FE8[];

Gfx* func_i9_8015EE84(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7035D78, 30, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 6, 4, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 7, 0);
    gSP2Triangles(gfx++, 10, 7, 9, 0, 13, 14, 15, 0);
    gSP2Triangles(gfx++, 15, 14, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 9, 27, 0, 28, 29, 24, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7035FE8, 46, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 15, 13, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 17, 19, 18, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 26, 27, 28, 0, 26, 28, 29, 0);
    gSP2Triangles(gfx++, 30, 31, 32, 0, 30, 32, 33, 0);
    gSP2Triangles(gfx++, 34, 35, 36, 0, 37, 38, 39, 0);
    gSP2Triangles(gfx++, 40, 41, 42, 0, 43, 44, 45, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7035C98, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 3, 7, 0, 8, 2, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7035F58, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    return gfx;
}

extern Vtx D_70362C8[];
extern Vtx D_7036358[];
extern Vtx D_7036458[];
extern Vtx D_70364B8[];

Gfx* func_i9_8015F214(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7036358, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 1, 0, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_70364B8, 27, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 15, 16, 17, 0);
    gSP2Triangles(gfx++, 18, 19, 20, 0, 21, 22, 23, 0);
    gSP1Triangle(gfx++, 24, 25, 26, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_70362C8, 9, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP1Triangle(gfx++, 6, 7, 8, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 41, 136, 196, 255);
    gDPSetEnvColor(gfx++, 6, 27, 43, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7036458, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    return gfx;
}

extern Vtx D_302AD48[];
extern Vtx D_302AE28[];
extern Vtx D_302AF08[];
extern Vtx D_302AF48[];
extern Vtx D_302B008[];
extern Vtx D_302B408[];
extern Vtx D_302B5D8[];
extern Vtx D_302B698[];
extern Vtx D_302B798[];

Gfx* func_i9_8015F46C(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_302AF08, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_302AF48, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 212, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_302B698, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 5, 4, 6, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 3, 8, 9, 0, 3, 9, 0, 0);
    gSP2Triangles(gfx++, 3, 10, 8, 0, 9, 1, 0, 0);
    gSP2Triangles(gfx++, 11, 10, 5, 0, 11, 5, 7, 0);
    gSP2Triangles(gfx++, 12, 2, 13, 0, 12, 13, 14, 0);
    gSP2Triangles(gfx++, 2, 1, 15, 0, 2, 15, 13, 0);
    gSP2Triangles(gfx++, 10, 3, 5, 0, 0, 2, 12, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_302B008, 64, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 13, 14, 0, 12, 14, 15, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 18, 19, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 20, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 24, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 30, 0, 28, 30, 31, 0);
    gSP2Triangles(gfx++, 32, 33, 34, 0, 35, 36, 37, 0);
    gSP2Triangles(gfx++, 35, 37, 38, 0, 35, 39, 36, 0);
    gSP2Triangles(gfx++, 37, 40, 38, 0, 41, 42, 43, 0);
    gSP2Triangles(gfx++, 44, 45, 46, 0, 44, 46, 47, 0);
    gSP2Triangles(gfx++, 48, 49, 50, 0, 48, 50, 51, 0);
    gSP2Triangles(gfx++, 52, 53, 54, 0, 52, 54, 55, 0);
    gSP2Triangles(gfx++, 53, 56, 57, 0, 53, 57, 54, 0);
    gSP2Triangles(gfx++, 36, 58, 59, 0, 36, 59, 37, 0);
    gSP2Triangles(gfx++, 58, 11, 10, 0, 58, 10, 59, 0);
    gSP2Triangles(gfx++, 60, 61, 62, 0, 60, 62, 63, 0);
    gSPVertex(gfx++, D_302B408, 29, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 6, 0);
    gSP2Triangles(gfx++, 4, 9, 10, 0, 11, 12, 13, 0);
    gSP2Triangles(gfx++, 11, 14, 12, 0, 4, 15, 9, 0);
    gSP2Triangles(gfx++, 16, 17, 18, 0, 16, 19, 17, 0);
    gSP2Triangles(gfx++, 20, 21, 22, 0, 23, 24, 25, 0);
    gSP2Triangles(gfx++, 24, 26, 27, 0, 20, 28, 21, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_302B798, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_302AD48, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 3, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_302AE28, 14, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);
    gSP2Triangles(gfx++, 8, 10, 9, 0, 6, 11, 7, 0);
    gSP2Triangles(gfx++, 12, 0, 3, 0, 12, 13, 0, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_302B5D8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 0, 3, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7036668[];
extern Vtx D_7036728[];
extern Vtx D_70367E8[];
extern Vtx D_7036868[];
extern Vtx D_70368E8[];
extern Vtx D_7036CD8[];
extern Vtx D_7036D98[];
extern Vtx D_7036E98[];

Gfx* func_i9_8015FC70(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_70367E8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7036868, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 212, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7036D98, 16, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 3, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 8, 11, 0, 10, 11, 12, 0);
    gSP2Triangles(gfx++, 13, 4, 3, 0, 13, 14, 0, 0);
    gSP2Triangles(gfx++, 13, 0, 7, 0, 13, 15, 14, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70368E8, 63, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 7, 5, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);
    gSP2Triangles(gfx++, 0, 12, 13, 0, 0, 13, 14, 0);
    gSP2Triangles(gfx++, 15, 16, 17, 0, 15, 17, 18, 0);
    gSP2Triangles(gfx++, 19, 20, 5, 0, 19, 5, 21, 0);
    gSP2Triangles(gfx++, 22, 23, 24, 0, 25, 26, 27, 0);
    gSP2Triangles(gfx++, 28, 29, 21, 0, 28, 21, 30, 0);
    gSP2Triangles(gfx++, 28, 31, 29, 0, 21, 32, 30, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 2, 1, 36, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 37, 39, 40, 0);
    gSP2Triangles(gfx++, 41, 18, 17, 0, 41, 17, 42, 0);
    gSP2Triangles(gfx++, 43, 44, 45, 0, 43, 45, 46, 0);
    gSP2Triangles(gfx++, 26, 47, 12, 0, 48, 49, 50, 0);
    gSP2Triangles(gfx++, 51, 52, 2, 0, 51, 53, 52, 0);
    gSP2Triangles(gfx++, 54, 4, 6, 0, 20, 55, 5, 0);
    gSP2Triangles(gfx++, 56, 57, 58, 0, 6, 59, 60, 0);
    gSP2Triangles(gfx++, 10, 9, 60, 0, 57, 52, 53, 0);
    gSP2Triangles(gfx++, 49, 61, 50, 0, 24, 62, 22, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 5, G_ON);
    gSPVertex(gfx++, D_7036E98, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7036668, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 3, 4, 5, 0, 3, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7036728, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 8, 11, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7036CD8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 0, 3, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7036EF8[];
extern Vtx D_7036F38[];
extern Vtx D_7036FD8[];
extern Vtx D_7037058[];
extern Vtx D_70370D8[];
extern Vtx D_7037498[];
extern Vtx D_7037558[];

Gfx* func_i9_80160314(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7036FD8, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_7037058, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 4, 6, 7, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 212, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7037558, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 0, 2, 0, 7, 2, 8, 0);
    gSP2Triangles(gfx++, 9, 4, 10, 0, 11, 4, 3, 0);
    gSP2Triangles(gfx++, 7, 8, 9, 0, 7, 9, 10, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_70370D8, 60, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 13, 11, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 8, 0);
    gSP2Triangles(gfx++, 17, 8, 19, 0, 4, 20, 21, 0);
    gSP2Triangles(gfx++, 4, 21, 19, 0, 22, 23, 24, 0);
    gSP2Triangles(gfx++, 25, 26, 27, 0, 28, 29, 30, 0);
    gSP2Triangles(gfx++, 28, 31, 29, 0, 29, 32, 30, 0);
    gSP2Triangles(gfx++, 33, 34, 35, 0, 6, 5, 36, 0);
    gSP2Triangles(gfx++, 37, 38, 39, 0, 37, 40, 38, 0);
    gSP2Triangles(gfx++, 41, 42, 43, 0, 42, 44, 43, 0);
    gSP2Triangles(gfx++, 4, 45, 20, 0, 46, 47, 48, 0);
    gSP2Triangles(gfx++, 49, 50, 51, 0, 52, 53, 8, 0);
    gSP2Triangles(gfx++, 54, 55, 56, 0, 57, 7, 9, 0);
    gSP2Triangles(gfx++, 47, 58, 48, 0, 24, 59, 22, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7036EF8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 7, G_ON);
    gSPVertex(gfx++, D_7036F38, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    gSP2Triangles(gfx++, 1, 4, 5, 0, 1, 5, 2, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 6, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7037498, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 4, 0, 2, 0);
    gSP2Triangles(gfx++, 4, 2, 5, 0, 9, 10, 11, 0);

    return gfx;
}

extern Vtx D_7037618[];
extern Vtx D_7037658[];
extern Vtx D_70376C8[];
extern Vtx D_7037728[];
extern Vtx D_70379B8[];
extern Vtx D_7037A78[];

Gfx* func_i9_801608D8(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7037658, 7, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP1Triangle(gfx++, 4, 5, 6, 0);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 2, G_ON);
    gSPVertex(gfx++, D_70376C8, 6, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 212, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7037A78, 11, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 1, 0, 0, 3, 5, 7, 0);
    gSP2Triangles(gfx++, 8, 1, 9, 0, 3, 7, 8, 0);
    gSP2Triangles(gfx++, 3, 8, 9, 0, 4, 10, 5, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7037728, 41, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 8, 0, 9, 10, 11, 0);
    gSP2Triangles(gfx++, 12, 1, 0, 0, 7, 13, 8, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);
    gSP2Triangles(gfx++, 17, 19, 20, 0, 21, 22, 23, 0);
    gSP2Triangles(gfx++, 24, 25, 26, 0, 12, 27, 28, 0);
    gSP2Triangles(gfx++, 12, 28, 29, 0, 12, 29, 20, 0);
    gSP2Triangles(gfx++, 30, 31, 0, 0, 32, 33, 19, 0);
    gSP2Triangles(gfx++, 8, 34, 35, 0, 36, 37, 38, 0);
    gSP2Triangles(gfx++, 4, 39, 5, 0, 38, 40, 36, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7037618, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_70379B8, 12, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 4, 0);
    gSP2Triangles(gfx++, 1, 4, 2, 0, 5, 6, 7, 0);
    gSP2Triangles(gfx++, 8, 9, 10, 0, 3, 11, 4, 0);

    return gfx;
}

extern Vtx D_7037B28[];
extern Vtx D_7037B68[];
extern Vtx D_7037B98[];
extern Vtx D_7037CD8[];
extern Vtx D_7037D18[];

Gfx* func_i9_80160D90(Gfx* gfx) {

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, COMBINED, 0, SHADE, 0,
                      0, 0, 0, COMBINED);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 1, G_ON);
    gSPVertex(gfx++, D_7037B68, 3, 0);
    gSP1Triangle(gfx++, 0, 1, 2, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 212, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 3, G_ON);
    gSPVertex(gfx++, D_7037D18, 10, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    gSP2Triangles(gfx++, 4, 5, 6, 0, 7, 8, 9, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 4, G_ON);
    gSPVertex(gfx++, D_7037B98, 20, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 3, 4, 5, 0);
    gSP2Triangles(gfx++, 6, 7, 0, 0, 7, 1, 0, 0);
    gSP2Triangles(gfx++, 4, 8, 5, 0, 8, 9, 5, 0);
    gSP2Triangles(gfx++, 10, 11, 12, 0, 10, 12, 13, 0);
    gSP2Triangles(gfx++, 14, 15, 16, 0, 17, 18, 19, 0);

    gDPPipeSync(gfx++);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 6, G_ON);
    gSPVertex(gfx++, D_7037B28, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 165, 213, 250, 255);
    gDPSetEnvColor(gfx++, 19, 32, 86, 255);
    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gSPVertex(gfx++, D_7037CD8, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);

    return gfx;
}

extern u8 D_3006178[];
extern u8 D_3006A78[];
extern u8 D_3008A18[];

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

extern u8 D_3008698[];
extern u8 D_3008718[];
extern u8 D_301A268[];
extern u8 D_3026DE8[];

Gfx* func_i9_801614D0(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x10, 1, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x30, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3026DE8, 0x40, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_302B7F8, 0x50, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301A268, 0x90, 5, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0xA0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0xE0, 7, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3024AF8[];
extern u8 D_302A688[];
extern u8 D_3004B18[];

Gfx* func_i9_8016197C(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3024AF8, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_302A708, 0x20, 2, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_302A688, 0x60, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x70, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0xB0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_30295C8[];
extern u8 D_3004D18[];

Gfx* func_i9_80161C78(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_30295C8, 0x20, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_30293C8, 0x30, 3, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004D18, 0x70, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0xB0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xF0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3007E18[];
extern u8 D_3004698[];

Gfx* func_i9_80161FF8(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0x10, 1, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3007E18, 0x20, 2, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x30, 3, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_30283C8, 0x50, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x90, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3006478[];

Gfx* func_i9_80162370(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3026E68, 0x10, 1, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x50, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0x60, 3, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3026DE8, 0x70, 4, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x80, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0xC0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3022F58[];

Gfx* func_i9_80162768(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3022F58, 0x10, 1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x50, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x70, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3025BB8, 0x80, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0xC0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x100, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_300B5F8[];
extern u8 D_3012C48[];
extern u8 D_30242F8[];

Gfx* func_i9_80162B08(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_30242F8, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                      G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x110, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3024B78, 0x120, 3, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3024AF8, 0x160, 4, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x170, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x1B0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300B5F8, 0x1F0, 7, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

Gfx* func_i9_80162FE0(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3023158, 0x20, 2, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3022F58, 0x60, 3, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0xA0, 4, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0xE0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300B5F8, 0x120, 6, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3021778[];

Gfx* func_i9_80163374(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_3021778, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                      G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x110, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x130, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3021F78, 0x140, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x180, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0x1C0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3020258[];
extern u8 D_3020658[];

Gfx* func_i9_801636F4(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3020258, 0x10, 1, G_IM_FMT_I, 64, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x90, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0xA0, 3, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3020658, 0xC0, 4, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0xE0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x120, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300B5F8, 0x160, 7, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_301DA58[];

Gfx* func_i9_80163BAC(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x20, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301DA58, 0x30, 3, G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301F128, 0xB0, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xF0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0x130, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

Gfx* func_i9_80163F28(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x20, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301DA58, 0x30, 3, G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301DE58, 0xB0, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xF0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0x130, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_301C818[];

Gfx* func_i9_801642A4(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301C818, 0x20, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x30, 3, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301C898, 0x50, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x90, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_301B1B8[];

Gfx* func_i9_80164608(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_301B1B8, 0x10, 1, G_IM_FMT_I, 64, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x90, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0xA0, 3, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301B5B8, 0xB0, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xF0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x130, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3019FE8[];

Gfx* func_i9_8016497C(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301A268, 0x20, 2, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3019FE8, 0x30, 3, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_301A068, 0x40, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x80, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0xC0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300B5F8, 0x100, 7, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3018698[];

Gfx* func_i9_80164E34(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_3018698, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                      G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x110, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3018498, 0x130, 3, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x170, 4, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x1B0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

Gfx* func_i9_80165124(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x10, 1, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x20, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x40, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_30175D8, 0x50, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0x90, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3016558[];

Gfx* func_i9_80165494(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_3016558, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                      G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0x50, 2, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3016758, 0x60, 3, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0xA0, 4, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xE0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x120, 6, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3006878[];
extern u8 D_3015198[];

Gfx* func_i9_80165858(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3007E18, 0x10, 1, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3015198, 0x20, 2, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006878, 0x30, 3, G_IM_FMT_IA, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x70, 4, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3015218, 0x90, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x110, 7, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_300CDF8[];

Gfx* func_i9_80165D28(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_300CDF8, 0x10, 1, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x30, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3013ED8, 0x50, 3, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x90, 4, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xD0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004D18, 0x110, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3012BC8[];

Gfx* func_i9_801660BC(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x10, 1, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012C48, 0x30, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012CC8, 0x40, 3, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x80, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0xC0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3012BC8, 0x100, 6, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_300E8A8[];

Gfx* func_i9_80166468(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_300CDF8, 0x10, 1, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x30, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x50, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300E8A8, 0x60, 4, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x80, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0xC0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_300FAF8[];
extern u8 D_30102F8[];
extern u8 D_30103F8[];

Gfx* func_i9_801667F8(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_300FAF8, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                      G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x110, 2, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x130, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_30103F8, 0x140, 4, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_30102F8, 0x160, 5, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x180, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0x1C0, 7, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

Gfx* func_i9_80166CF4(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x10, 1, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x30, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004698, 0x40, 3, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3011578, 0x50, 4, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x90, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xD0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_300CD78[];
extern u8 D_300CEF8[];
extern u8 D_300D2F8[];

Gfx* func_i9_80167068(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_300CDF8, 0x10, 1, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300CD78, 0x30, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x40, 3, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300D2F8, 0x50, 4, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300CEF8, 0x70, 5, G_IM_FMT_I, 64, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0xF0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0x130, 7, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_300B678[];
extern u8 D_300BA78[];

Gfx* func_i9_80167530(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x10, 1, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300BA78, 0x30, 2, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300B678, 0x50, 3, G_IM_FMT_I, 64, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_300B5F8, 0xD0, 4, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0xE0, 5, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x120, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3009BE8[];
extern u8 D_3009CE8[];

Gfx* func_i9_80167898(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_3009CE8, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                      G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x110, 2, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x120, 3, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3009BE8, 0x140, 4, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3004B18, 0x160, 5, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x1A0, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3007E98[];
extern u8 D_3008918[];

Gfx* func_i9_80167C1C(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_3007E98, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                      G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3007E18, 0x110, 2, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008918, 0x120, 3, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x140, 4, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008698, 0x160, 5, G_IM_FMT_I, 16, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008A18, 0x170, 6, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3008718, 0x1B0, 7, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3006078[];
extern u8 D_3006278[];
extern u8 D_3006678[];

Gfx* func_i9_801680E8(Gfx* gfx) {

    gDPPipeSync(gfx++);

    gDPLoadMultiBlock(gfx++, D_3006278, 0x10, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                      G_TX_MIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006678, 0x50, 2, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006178, 0x90, 3, G_IM_FMT_I, 32, 16, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 4, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006078, 0xB0, 4, G_IM_FMT_I, 16, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006878, 0xD0, 5, G_IM_FMT_IA, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006A78, 0x110, 6, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiBlock_4b(gfx++, D_3006478, 0x150, 7, G_IM_FMT_I, 32, 32, 0, G_TX_MIRROR | G_TX_CLAMP,
                         G_TX_MIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    return gfx;
}

extern u8 D_3004498[];
extern u8 D_3004598[];
extern u8 D_3004718[];
extern u8 D_3004918[];

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
