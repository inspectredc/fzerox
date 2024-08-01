#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "sys.h"
#include "fzxmath.h"
#include "unk_structs.h"
#include "PR/leo.h"

void func_80068008(void* arg0);
void func_80068A60(void* arg0);

void func_80069700(void);

s32 func_8006A9E0(f32 arg0);
u32 func_8006A918(void);
u32 func_8006A978(void);
s32 func_8006AA38(Mtx3F* mtx);
s32 func_8006AC10(Mtx3F* mtx);
void func_8006BC84(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD);
void func_8006C520(Mtx* arg0, MtxF* arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
void func_8006CC98(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA);
void func_8006D03C(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u16* arg9);

void func_80073A04(void);
void func_80073E28(void* arg0, void* arg1, size_t arg2);
void func_80073ED0(void* arg0, void* arg1, size_t arg2);
void func_8007402C(s32 arg0);
void func_800741DC(s32 arg0);
void func_80074634(unk_800F8510* arg0);
void func_800747EC(s32 arg0);
void func_80074A90(f32* arg0, f32* arg1);
void func_80074CE4(unk_800F8510*);

void func_8007515C(void);

void func_800751FC(char* arg0);
void func_80075230(OSThread* arg0);
s32 func_800760F8(void);
s32 func_800761D4(void);
s32 func_80076340(void);
void func_800763A8(void);
void func_800765CC(u8* arg0, u8* arg1, u32 arg2);
void func_80076658(u8* arg0, u8* arg1, size_t arg2, void* arg3, size_t arg4);
void func_800766F0(void);
s32 func_80076BD4(uintptr_t arg0);
void func_80077318(void);
void func_80077C9C(void);

void func_80079EC8(void);
void func_80079F1C(void);

Gfx* func_8007AB88(Gfx*);
Gfx* func_8007ABA4(Gfx*);
Gfx* func_8007AE70(Gfx*);
Gfx* func_8007AC48(Gfx* gfx, u16 red, u16 green, u16 blue);
Gfx* func_8007AE8C(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha);
Gfx* func_8007AF40(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha);
void func_8007E2B4(void);
void func_8007E08C(void);
void func_8007F904(void);

void func_8007FCB8(void);
void func_8007FCF4(void);
void func_8007FD58(void);
void func_8007FDD0(void);
void func_8007FE48(void);
void func_8007FE98(void);
void func_8007FED4(void);

void func_8008D7E8(void);
void func_8008D824(void);
void func_8008D8E8(void);

void Fault_SetFrameBuffer(FrameBuffer* buffer, u16 width, u16 height);
void Fault_Init(void);

void func_8009CED0(u32 arg0);
s32 func_8009DEAC(unk_800F8510* arg0);
f32 func_8009E108(unk_8006FC8C*, f32, f32*);
f32 func_8009E538(unk_8006FC8C*, f32, Vec3f*);
void func_8009E6F0(unk_8006FC8C*, f32, Vec3f*);
f32 func_8009E85C(unk_8006FC8C*, f32, Mtx3F*, f32);

s32 func_800AA394(s32);

bool func_800CC220(void);

s32 func_i1_80414BA0(OSPri, OSPri, OSMesg*, s32); // LeoCJCreateLeoManager

void func_i2_800FC77C(void);
void func_i2_800FC9BC(void);
s32 func_i2_800FCE3C(void);
void func_i2_800FD184(s32);
void func_i2_80100520(s32);
void func_i2_801012CC(s32);
void func_i2_80103A70(void);
void func_i2_80103AD4(void);
s32 func_i2_80103B8C(void);
s32 func_i2_80103BE0(void);

void func_i3_80134598(void);

void func_i4_80115DF0(void);
void func_i4_801160D8(void);
s32 func_i4_8011631C(void);
s32 func_i4_801168D4(void);
s32 func_i4_80116DC4(void);
s32 func_i4_80116E10(void);
void func_i4_80116E64(void);
void func_i4_80116E8C(unk_800E3A28*);
void func_i4_80116F48(unk_800E3A28*);
void func_i4_80117008(unk_800E3A28*);
void func_i4_80117038(unk_800E3A28*);
void func_i4_8011706C(void);
void func_i4_80117094(unk_800E3A28*);
void func_i4_80117400(unk_800E3A28*);
void func_i4_8011764C(void);
void func_i4_801176BC(void);
void func_i4_8011770C(unk_800E3A28*);
void func_i4_8011774C(void);
void func_i4_80117774(unk_800E3A28*);
void func_i4_80117808(void);
void func_i4_80117854(unk_800E3A28*);
void func_i4_8011788C(unk_800E3A28*);
Gfx* func_i4_801178C4(Gfx*);
Gfx* func_i4_80117B74(Gfx*);
Gfx* func_i4_80117BE0(Gfx*, unk_800E3A28*);
Gfx* func_i4_80117D10(Gfx*);
Gfx* func_i4_80117E98(Gfx*);
Gfx* func_i4_801180EC(Gfx*);
Gfx* func_i4_801181C0(Gfx*);
Gfx* func_i4_8011821C(Gfx*);
Gfx* func_i4_80118414(Gfx*);
Gfx* func_i4_80118734(Gfx*);
Gfx* func_i4_801187C0(Gfx*);
Gfx* func_i4_80118918(Gfx*);
Gfx* func_i4_80118EC8(Gfx*);
Gfx* func_i4_80119170(Gfx*);
Gfx* func_i4_801193B8(Gfx*);
Gfx* func_i4_801194F8(Gfx*);
Gfx* func_i4_80119574(Gfx*);
Gfx* func_i4_801197A0(Gfx*);
Gfx* func_i4_80119834(Gfx*);
Gfx* func_i4_80119A64(Gfx*);
Gfx* func_i4_80119B50(Gfx*);
void func_i4_80119BB8(unk_800E3A28*);
void func_i4_80119BC0(unk_800E3A28*);
void func_i4_80119C80(unk_800E3A28*);
void func_i4_80119D0C(unk_800E3A28*);
void func_i4_80119D84(unk_800E3A28*);
void func_i4_80119D8C(unk_800E3A28*);
void func_i4_8011A08C(unk_800E3A28*);
void func_i4_8011A6A0(unk_800E3A28*);
void func_i4_8011A6EC(unk_800E3A28*);
void func_i4_8011A73C(unk_800E3A28*);
void func_i4_8011A7B8(void);
void func_i4_8011AD60(void);
s32 func_i4_8011AE2C(void);
s32 func_i4_8011AF84(void);
void func_i4_8011B06C(unk_800E3A28*);
void func_i4_8011B0C8(void);
void func_i4_8011B0D0(unk_800E3A28*);
void func_i4_8011B134(void);
void func_i4_8011B13C(unk_800E3A28*);
void func_i4_8011B1E4(void);
void func_i4_8011B1EC(void);
void func_i4_8011B214(unk_800E3A28*);
void func_i4_8011B2E0(unk_800E3A28*);
Gfx* func_i4_8011B380(Gfx*);
Gfx* func_i4_8011B3DC(Gfx*);
Gfx* func_i4_8011B3E8(Gfx*);
Gfx* func_i4_8011B438(Gfx*);
Gfx* func_i4_8011B444(Gfx*);
Gfx* func_i4_8011B668(Gfx*);
Gfx* func_i4_8011B674(Gfx*);
Gfx* func_i4_8011B6C4(Gfx*);
void func_i4_8011B874(unk_800E3A28*);

void func_i5_80116934(void);
void func_i5_80116D00(void);
s32 func_i5_80116EEC(void);
s32 func_i5_801175D0(void);
s32 func_i5_80117664(void);
void func_i5_80117684(unk_800E3A28*);
void func_i5_80117758(void);
void func_i5_801177EC(unk_800E3A28*);
void func_i5_801178D8(unk_800E3A28*);
void func_i5_80117934(unk_800E3A28*);
void func_i5_8011796C(unk_800E3A28*);
void func_i5_801179A8(unk_800E3A28*);
void func_i5_80117A2C(unk_800E3A28*);
Gfx* func_i5_80117A98(Gfx*);
Gfx* func_i5_80117BE0(Gfx*, unk_800E3A28*);
Gfx* func_i5_80117C48(Gfx*);
Gfx* func_i5_80117FB4(Gfx*);
Gfx* func_i5_80118100(Gfx*);
Gfx* func_i5_80118168(Gfx*);
Gfx* func_i5_801182DC(Gfx*);
Gfx* func_i5_80118674(Gfx*);
Gfx* func_i5_80118790(Gfx*);
void func_i5_80118928(unk_800E3A28*);
void func_i5_801189C4(unk_800E3A28*);
void func_i5_80118D44(unk_800E3A28*);
void func_i5_80118D94(unk_800E3A28*);
void func_i5_80118F24(unk_800E3A28*);
void func_i5_80118F84(unk_800E3A28*);

void func_i6_80115DF0(void);
s32 func_i6_80115FF0(void);
s32 func_i6_801167CC(void);
void func_i6_801167EC(unk_800E3A28*);
void func_i6_80116894(unk_800E3A28*);
void func_i6_801168EC(unk_800E3A28*);
void func_i6_80116934(void);
void func_i6_80116990(void);
void func_i6_801169EC(void);
void func_i6_80116A48(unk_800E3A28*);
void func_i6_80116A80(unk_800E3A28*);
Gfx* func_i6_80116AA8(Gfx*);
Gfx* func_i6_80116C78(Gfx*);
Gfx* func_i6_80117400(Gfx*);
Gfx* func_i6_801174DC(Gfx*);
Gfx* func_i6_80117760(Gfx*);
Gfx* func_i6_80117A18(Gfx*);
Gfx* func_i6_80117C50(Gfx*);
void func_i6_80117D3C(unk_800E3A28*);
void func_i6_80117DE0(unk_800E3A28*);
void func_i6_8011BF50(void);
s32 func_i6_8011BFB0(void);
s32 func_i6_8011C01C(void);
void func_i6_8011C050(void);
s32 func_i6_8011C6DC(void);
s32 func_i6_8011CD4C(void);

void func_i7_80143A90(void);
s32 func_i7_801441A0(void);
s32 func_i7_801447F4(void);

void func_i8_801439D0(void);
s32 func_i8_80143DDC(void);
s32 func_i8_80144568(void);

Gfx* func_i9_80115DF0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA, s32 argB, s32 argC, s32 argD, s32 argE, s32 argF, s32 arg10);
Gfx* func_i9_80161050(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3);

#endif // FUNCTIONS_H
