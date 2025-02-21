#include "ovl_i6.h"
#include "controller.h"

SaveContext gSaveContext;

s32 gDefaultSubOptionLimits[] = { 2, 1, 0, 2, 0, 2, 0, 0 };

s32 gMaxSubOptionLimits[] = { 3, 1, 0, 2, 0, 3, 0, 0 };

u16 gUnlockEverythingInputs[] = { BTN_L, BTN_Z, BTN_R, BTN_CUP, BTN_CDOWN, BTN_CLEFT, BTN_CRIGHT, BTN_START };
