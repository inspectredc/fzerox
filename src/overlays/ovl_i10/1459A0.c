#include "global.h"
#include "fzx_save.h"

void func_i10_80115E30(SaveContext*);
extern OSPiHandle* gSramPiHandlePtr;

s32 func_i10_80115DF0(void) {
    gSramPiHandlePtr = Sram_Init();
    func_i10_80115E30((SaveContext*) func_800768F4(1, sizeof(SaveContext)));
    return 0;
}

void Save_Load(SaveContext*);
bool func_i10_80115EE8(u8*);
void func_i10_80115F2C(SaveContext*, s32);

void func_i10_80115E30(SaveContext* saveContext) {
    s32 i;
    s32 var_s2;
    s32 sp34;
    ProfileSave* var_s1;

    Sram_ReadWrite(OS_READ, 0, saveContext, sizeof(SaveContext));

    for (var_s2 = 0, i = 0, var_s1 = saveContext->profileSaves; i < 2; var_s2++, i++, var_s1++) {
        if (!func_i10_80115EE8(var_s1->saveSettings.fileName)) {
            break;
        }
        sp34 = i;
    }

    if (var_s2 == 2) {
        Save_Init(saveContext, 0);
        return;
    }
    if (var_s2 == 1) {
        func_i10_80115F2C(saveContext, sp34);
    }
    Save_Load(saveContext);
}

extern const char D_i2_8010ADE0[];

bool func_i10_80115EE8(u8* arg0) {
    s32 ret = false;
    s32 i;

    for (i = 0; i != 8; i++) {
        if (arg0[i] != D_i2_8010ADE0[i]) {
            ret = true;
            break;
        }
    }

    return ret;
}

void func_i10_80115F2C(SaveContext* arg0, s32 arg1) {
    s32 i;
    u8* temp_a2 = arg0->profileSaves[arg1].saveSettings.fileName;

    for (i = 0; i < 8; i++) {
        temp_a2[i] = D_i2_8010ADE0[i];
    }

    Sram_ReadWrite(OS_WRITE, temp_a2 - (u8*) arg0, temp_a2, 8);
}
