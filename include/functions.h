#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "sys.h"
#include "fzxmath.h"
#include "unk_structs.h"

s32 func_8006A9E0(f32 arg0);
void func_8006BC84(s16* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD);
void func_8006C520(s16* arg0, f32* arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

void func_80074A90(f32* arg0, f32* arg1);
void func_80074CE4(unk_800F8510*);

s32 func_80076BD4(uintptr_t arg0);

f32 func_8009E108(unk_8006FC8C*, f32, f32*);
f32 func_8009E538(unk_8006FC8C*, f32, Vec3f*);
void func_8009E6F0(unk_8006FC8C*, f32, Vec3f*);
void func_8009E85C(unk_8006FC8C*, f32, unk_struct_24*, f32);


#endif // FUNCTIONS_H
