#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "sys.h"
#include "fzxmath.h"
#include "unk_structs.h"

s32 func_8006A9E0(f32 arg0);
s32 func_8006AA38(Mtx3F* mtx);
void func_8006BC84(Mtx* arg0, MtxF* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD);
void func_8006C520(Mtx* arg0, MtxF* arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

void func_80074A90(f32* arg0, f32* arg1);
void func_80074CE4(unk_800F8510*);

s32 func_800760F8(void);
void func_800765CC(s32 arg0, s32 arg1, u32 arg2);
s32 func_80076BD4(uintptr_t arg0);

void func_8007E2B4(void);

void Fault_SetFrameBuffer(FrameBuffer* buffer, u16 width, u16 height);
void Fault_Init(void);

f32 func_8009E108(unk_8006FC8C*, f32, f32*);
f32 func_8009E538(unk_8006FC8C*, f32, Vec3f*);
void func_8009E6F0(unk_8006FC8C*, f32, Vec3f*);
f32 func_8009E85C(unk_8006FC8C*, f32, Mtx3F*, f32);

// Todo: migrate to correct overlay functions
unk_800E3A28* func_801167EC(unk_800E3A28*);
unk_800E3A28* func_80116894(unk_800E3A28*);
unk_800E3A28* func_801168EC(unk_800E3A28*);
void func_80116934(void);
void func_80116990(void);
void func_801169EC(void);
unk_800E3A28* func_80116A48(unk_800E3A28*);
unk_800E3A28* func_80116A80(unk_800E3A28*);
void func_80116E64(void);
unk_800E3A28* func_80116E8C(unk_800E3A28*);
unk_800E3A28* func_80116F48(unk_800E3A28*);
unk_800E3A28* func_80117008(unk_800E3A28*);
unk_800E3A28* func_80117038(unk_800E3A28*);
void func_8011706C(void);
unk_800E3A28* func_80117094(unk_800E3A28*);
unk_800E3A28* func_80117400(unk_800E3A28*);
void func_8011764C(void);
unk_800E3A28* func_80117684(unk_800E3A28*);
void func_801176BC(void);
unk_800E3A28* func_8011770C(unk_800E3A28*);
void func_8011774C(void);
void func_80117758(void);
unk_800E3A28* func_80117774(unk_800E3A28*);
unk_800E3A28* func_801177EC(unk_800E3A28*);
void func_80117808(void);
unk_800E3A28* func_80117854(unk_800E3A28*);
unk_800E3A28* func_8011788C(unk_800E3A28*);
unk_800E3A28* func_801178D8(unk_800E3A28*);
unk_800E3A28* func_80117934(unk_800E3A28*);
unk_800E3A28* func_8011796C(unk_800E3A28*);
unk_800E3A28* func_801179A8(unk_800E3A28*);
unk_800E3A28* func_80117A2C(unk_800E3A28*);
unk_800E3A28* func_8011B06C(unk_800E3A28*);
void func_8011B0C8(void);
unk_800E3A28* func_8011B0D0(unk_800E3A28*);
void func_8011B134(void);
unk_800E3A28* func_8011B13C(unk_800E3A28*);
void func_8011B1E4(void);
void func_8011B1EC(void);
unk_800E3A28* func_8011B214(unk_800E3A28*);
unk_800E3A28* func_80116AA8(unk_800E3A28*);
unk_800E3A28* func_80116C78(unk_800E3A28*);
unk_800E3A28* func_801174DC(unk_800E3A28*);
unk_800E3A28* func_80117760(unk_800E3A28*);
unk_800E3A28* func_801178C4(unk_800E3A28*);
unk_800E3A28* func_80117A18(unk_800E3A28*);
unk_800E3A28* func_80117A98(unk_800E3A28*);
unk_800E3A28* func_80117B74(unk_800E3A28*);
unk_800E3A28* func_80117BE0(unk_800E3A28*);
unk_800E3A28* func_80117C48(unk_800E3A28*);
unk_800E3A28* func_80117C50(unk_800E3A28*);
unk_800E3A28* func_80117D10(unk_800E3A28*);
unk_800E3A28* func_80117E98(unk_800E3A28*);
unk_800E3A28* func_80117FB4(unk_800E3A28*);
unk_800E3A28* func_801180EC(unk_800E3A28*);
unk_800E3A28* func_80118100(unk_800E3A28*);
unk_800E3A28* func_80118168(unk_800E3A28*);
unk_800E3A28* func_801181C0(unk_800E3A28*);
unk_800E3A28* func_8011821C(unk_800E3A28*);
unk_800E3A28* func_801182DC(unk_800E3A28*);
unk_800E3A28* func_80118414(unk_800E3A28*);
unk_800E3A28* func_80118674(unk_800E3A28*);
unk_800E3A28* func_80118734(unk_800E3A28*);
unk_800E3A28* func_80118790(unk_800E3A28*);
unk_800E3A28* func_801187C0(unk_800E3A28*);
unk_800E3A28* func_80118918(unk_800E3A28*);
unk_800E3A28* func_80118EC8(unk_800E3A28*);
unk_800E3A28* func_80119170(unk_800E3A28*);
unk_800E3A28* func_801193B8(unk_800E3A28*);
unk_800E3A28* func_801194F8(unk_800E3A28*);
unk_800E3A28* func_80119574(unk_800E3A28*);
unk_800E3A28* func_801197A0(unk_800E3A28*);
unk_800E3A28* func_80119834(unk_800E3A28*);
unk_800E3A28* func_80119A64(unk_800E3A28*);
unk_800E3A28* func_80119B50(unk_800E3A28*);
unk_800E3A28* func_8011B380(unk_800E3A28*);
unk_800E3A28* func_8011B3DC(unk_800E3A28*);
unk_800E3A28* func_8011B3E8(unk_800E3A28*);
unk_800E3A28* func_8011B438(unk_800E3A28*);
unk_800E3A28* func_8011B444(unk_800E3A28*);
unk_800E3A28* func_8011B668(unk_800E3A28*);
unk_800E3A28* func_8011B674(unk_800E3A28*);
unk_800E3A28* func_8011B6C4(unk_800E3A28*);
unk_800E3A28* func_80117D3C(unk_800E3A28*);
unk_800E3A28* func_80117DE0(unk_800E3A28*);
unk_800E3A28* func_80118928(unk_800E3A28*);
unk_800E3A28* func_801189C4(unk_800E3A28*);
unk_800E3A28* func_80118D44(unk_800E3A28*);
unk_800E3A28* func_80118D94(unk_800E3A28*);
unk_800E3A28* func_80118F24(unk_800E3A28*);
unk_800E3A28* func_80118F84(unk_800E3A28*);
unk_800E3A28* func_80119BB8(unk_800E3A28*);
unk_800E3A28* func_80119BC0(unk_800E3A28*);
unk_800E3A28* func_80119C80(unk_800E3A28*);
unk_800E3A28* func_80119D0C(unk_800E3A28*);
unk_800E3A28* func_80119D84(unk_800E3A28*);
unk_800E3A28* func_80119D8C(unk_800E3A28*);
unk_800E3A28* func_8011A08C(unk_800E3A28*);
unk_800E3A28* func_8011A6A0(unk_800E3A28*);
unk_800E3A28* func_8011A6EC(unk_800E3A28*);
unk_800E3A28* func_8011A73C(unk_800E3A28*);
unk_800E3A28* func_8011B2E0(unk_800E3A28*);
unk_800E3A28* func_8011B874(unk_800E3A28*);


#endif // FUNCTIONS_H
