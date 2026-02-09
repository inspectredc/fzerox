#ifndef OVL_I3_H
#define OVL_I3_H

#include "unk_structs.h"

typedef struct unk_8013E7A8 {
    s16 unk_00;
    s8 unk_02;
    s8 unk_03[3];
    s8 unk_06[8];
} unk_8013E7A8; // size = 0xE

typedef struct unk_801437C0 {
    s8 unk_00;
    s8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
} unk_801437C0; // size = 0xA

void func_i3_801175A4(void);

Gfx* func_i3_8012EE90(Gfx* gfx, s32 arg1);

void RecordsEntry_ToRecordsState(void);
void RecordsEntry_UpdateNameEntry(void);
Gfx* RecordsEntry_DrawNameEntry(Gfx* gfx);

#endif // OVL_I3_H
