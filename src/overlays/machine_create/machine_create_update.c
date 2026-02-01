#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"
#include "fzx_machine.h"
#include "fzx_bordered_box.h"
#include "src/overlays/ovl_i2/transition.h"

s32 D_xk3_80140E50;
s32 D_xk3_80140E54;
f32 D_xk3_80140E58;

unk_80140E60 D_xk3_80140E60;
unk_80140E60 D_xk3_80140E68;
unk_80140E60 D_xk3_80140E70;

f32 D_xk3_80140E78;
f32 D_xk3_80140E7C;
f32 D_xk3_80140E80;
f32 D_xk3_80140E84;
f32 D_xk3_80140E88;
f32 D_xk3_80140E8C;
CustomMachinesInfo gCustomMachinesInfoBackup;
CustomMachine gCustomMachineBackup;

u8 D_xk3_80141290;
u8 D_xk3_80141291;
s32 D_xk3_80141294;
char* D_xk3_80141298;

f32 D_xk3_80136540 = -7000.0f;
s8 D_xk3_80136544 = -1;
u8 D_xk3_80136548 = false;
u8 D_xk3_8013654C = false;
s32 D_xk3_80136550 = 0;
s32 D_xk3_80136554 = 0;

void func_xk3_8012B950(void) {
    D_xk3_80140E54 = 0x57;
    D_xk3_80140E58 = 87.0f;
    func_xk1_8002B150(0xA8, 0x57, &D_xk3_80140E50, &D_xk3_80140E54);
}

extern GfxPool* gGfxPool;

void func_xk3_8012B99C(void) {
    gGfxPool->unk_2C2C8[1].vp.vscale[0] = D_xk3_80140E80 * 640.0f;
    gGfxPool->unk_2C2C8[1].vp.vscale[1] = D_xk3_80140E84 * 480.0f;
    gGfxPool->unk_2C2C8[1].vp.vscale[2] = 0x1FF;
    gGfxPool->unk_2C2C8[1].vp.vscale[3] = 0;
    gGfxPool->unk_2C2C8[1].vp.vtrans[0] = (D_xk3_80140E88 + 25.0f + 64.0f) * 4.0f;
    gGfxPool->unk_2C2C8[1].vp.vtrans[1] = (D_xk3_80140E8C + 90.0f + 64.0f + 2.0f) * 4.0f;
    gGfxPool->unk_2C2C8[1].vp.vtrans[2] = 0x1FF;
    gGfxPool->unk_2C2C8[1].vp.vtrans[3] = 0;
}

void func_xk3_8012BABC(void) {
    D_xk3_80140E80 = 1.0f;
    D_xk3_80140E84 = 1.0f;
    D_xk3_80140E88 = 0.0f;
    D_xk3_80140E8C = 0.0f;
    func_xk3_8012B99C();
    D_xk3_80140E78 = 0.0f;
    D_xk3_80140E7C = 0.0f;
}

u16 MachineCreate_CalculateCustomMachineChecksum(CustomMachine* customMachine) {
    u8 i;
    u16 checksum = 0;
    u8* ptr = (u8*) customMachine;

    for (i = 0; i < 30; i++) {
        checksum += *ptr++;
    }

    return checksum;
}

extern u8 kCharacterNumbers[];
extern CustomMachine gCustomMachine;
extern CustomMachine gCustomMachineWork;
extern CustomMachinesInfo gCustomMachinesInfo;

void func_xk3_8012BB48(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] > 0) {
            if (mfsStrCmp(&gCustomMachinesInfo.customMachines[i].machineName, &gCustomMachine.machineName) == 0) {
                gCustomMachinesInfo.customMachines[i] = gCustomMachine;
                gCustomMachinesInfo.customMachines[i].number = kCharacterNumbers[i];
                break;
            }
        }
    }

    PRINTF("WORKS MACHINE MODE : 0\n");
    gWorksMachineMode = MACHINE_MODE_0;
    gCustomMachineWork.checksum = MachineCreate_CalculateCustomMachineChecksum(&gCustomMachineWork);
    func_80768244(MFS_ENTRY_WORKING_DIR, gCustomMachineWork.machineName, "CARD", &gCustomMachineWork,
                  sizeof(CustomMachine), 0, 0xFF, true);
}

extern BorderedBoxWidget* gMachineCreateColorBox;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;
extern f32 D_xk3_80140E58;
extern MenuWidget gMachineCreateWidget;

void func_xk3_8012BC98(void) {
    s32 mode;

    mode = gWorksMachineMode;
    D_xk3_80140E54 = 0x1C;
    func_xk1_80027DC8(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
    D_xk3_80140E54 = 0x44;
    func_xk1_80027DC8(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
    switch (mode) {
        case MACHINE_MODE_BODY_COLOR:
            D_xk3_80140E54 = 0x34;
            break;
        case MACHINE_MODE_LINE_COLOR:
            D_xk3_80140E54 = 0x44;
            break;
        case MACHINE_MODE_NUMBER_COLOR:
            D_xk3_80140E54 = 0x54;
            break;
        case MACHINE_MODE_COCKPIT_COLOR:
            D_xk3_80140E54 = 0x64;
            break;
    }
    D_xk3_80140E58 = D_xk3_80140E54;
    BorderedBox_StartClose(gMachineCreateColorBox);
}

extern s32 D_xk1_80032C20;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;

void func_xk3_8012BD84(void) {

    switch (gWorksMachineMode) {
        case MACHINE_MODE_BODY_COLOR:
        case MACHINE_MODE_LINE_COLOR:
        case MACHINE_MODE_NUMBER_COLOR:
        case MACHINE_MODE_COCKPIT_COLOR: {
            s32 sp34 = D_xk3_80140E68.unk_00;
            s32 sp30 = D_xk3_80140E68.unk_04;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E68.unk_04 != 8) {
                func_xk1_8002DAE0(&D_xk3_80140E68, 7, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E68.unk_04, 8, 0);
            if ((sp34 != D_xk3_80140E68.unk_00) || (sp30 != D_xk3_80140E68.unk_04)) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        }
        case MACHINE_MODE_PARTS: {
            s32 sp2C = D_xk3_80140E60.unk_00;
            s32 sp28 = D_xk3_80140E60.unk_04;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E60.unk_04 != 3) {
                func_xk1_8002DAE0(&D_xk3_80140E60, 6, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E60.unk_04, 3, 0);
            if ((sp2C != D_xk3_80140E60.unk_00) || (sp28 != D_xk3_80140E60.unk_04)) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        }
        case MACHINE_MODE_SETTING: {
            s32 sp24 = D_xk3_80140E70.unk_00;
            s32 sp20 = D_xk3_80140E70.unk_04;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E70.unk_04 != 3) {
                func_xk1_8002DAE0(&D_xk3_80140E70, 4, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E70.unk_04, 3, 0);
            if ((sp24 != D_xk3_80140E70.unk_00) || (sp20 != D_xk3_80140E70.unk_04)) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        }
        case MACHINE_MODE_LOAD_SELECT_FILE:
        case MACHINE_MODE_LOAD_SELECT_SUPER:
        case MACHINE_MODE_DELETE_SELECT_FILE:
        case MACHINE_MODE_ENTRY_SELECT_FILE:
        case MACHINE_MODE_ENTRY_SELECT_SUPER:
        case MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE:
        case MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER:
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002BBA4();
            break;
        case MACHINE_MODE_MENU:
            D_xk3_80136554 = (s32) (D_xk3_80140E54 - 0x24) / 16;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002DBD4(&D_xk3_80136554, 2, 0);
            D_xk3_80140E54 = (D_xk3_80136554 * 0x10) + 0x24;
            func_xk1_800269F4(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
            func_xk1_80027CFC(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
            break;
        case MACHINE_MODE_MENU_COLOR:
        case MACHINE_MODE_SELECT_LINE:
        case MACHINE_MODE_SELECT_MARK:
            D_xk3_80136554 = (s32) (D_xk3_80140E54 - 0x34) / 16;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002DBD4(&D_xk3_80136554, 7, 0);
            D_xk3_80140E54 = (D_xk3_80136554 * 0x10) + 0x34;
            func_xk1_800269F4(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
            func_xk1_80027CFC(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
            break;
        case MACHINE_MODE_0: {
            s32 sp1C = D_xk3_80136550;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002DAE0(&D_xk3_80136550, 5, 1);
            D_xk3_80140E50 = (D_xk3_80136550 * 0x30) + 0x30;
            D_xk3_80140E54 = 0x1C;
            if (sp1C != D_xk3_80136550) {
                Audio_TriggerSystemSE(NA_SE_35);
            }
            break;
        }
    }
    switch (gWorksMachineMode) {
        case MACHINE_MODE_LOAD_CONFIRM:
        case MACHINE_MODE_OVERWRITE_CONFIRM:
        case MACHINE_MODE_DELETE_CONFIRM:
        case MACHINE_MODE_ENTRY_ALLCLEAR_CONFIRM:
        case MACHINE_MODE_ENTRY_CLEAR_CONFIRM:
        case MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM:
        case MACHINE_MODE_CHECKSUM_ERROR:
            func_xk1_8002D2F0();
            break;
        default:
            D_xk1_80032C20 = 0;
            break;
    }
}

void func_xk3_8012C1C8(void) {
    static u8 D_xk3_80136558 = 0;
    static u8 D_xk3_8013655C = 0;
    f32 var_ft4;
    f32 var_fv0;
    u16 var_a0;
    u16 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a1;
    u16 temp_v1;

    if (D_xk3_80136548) {
        temp_v1 = gControllers[gPlayerControlPorts[0]].buttonCurrent;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_A) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R) != 0;
        }
        var_a0 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_B) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L) != 0;
        }
        var_a1 = var_v0;
    } else {
        var_a0 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R;
        var_a1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L;
    }
    if (var_a1 && var_a0) {
        D_xk3_8013655C = 0;
        D_xk3_80136558 = 0;

    } else {
        if (var_a0) {
            D_xk3_80140E80 *= 1.0f + (0.002f * D_xk3_8013655C);
            D_xk3_80140E84 = D_xk3_80140E80;
            if (D_xk3_8013655C < 50) {
                D_xk3_8013655C++;
            }
        } else {
            D_xk3_8013655C = 0;
        }
        if (var_a1) {
            D_xk3_80140E80 /= (1.0f + (0.002f * D_xk3_80136558));
            D_xk3_80140E84 = D_xk3_80140E80;
            if (D_xk3_80136558 < 50) {
                D_xk3_80136558++;
            }
        } else {
            D_xk3_80136558 = 0;
        }
    }
    if (D_xk3_80140E80 > 6.0f) {
        D_xk3_80140E80 = D_xk3_80140E84 = 6.0f;
    }
    if (D_xk3_80140E80 < 0.2f) {
        D_xk3_80140E80 = D_xk3_80140E84 = 0.2f;
    }
}

void func_xk3_8012C408(void) {
    static u8 D_xk3_80136560 = 0;
    static u8 D_xk3_80136564 = 0;
    static u8 D_xk3_80136568 = 0;
    static u8 D_xk3_8013656C = 0;
    static f32 D_xk3_80136570 = 1.0f;
    static f32 D_xk3_80136574 = 1.0f;
    f32 temp_fa0;

    temp_fa0 = (35.0f * D_xk3_80140E80) + 40.0f;

    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CLEFT) &&
        (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CRIGHT)) {
        D_xk3_8013656C = 0;
        D_xk3_80136568 = 0;
    } else {
        if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CUP) &&
            (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CDOWN)) {
            D_xk3_80136564 = 0;
            D_xk3_80136560 = 0;
        } else {
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CLEFT) {
                D_xk3_80140E88 -= 0.2f * D_xk3_80136568;
                if (D_xk3_80136568 < 15) {
                    D_xk3_80136568++;
                }
            } else {
                D_xk3_80136568 = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CRIGHT) {
                D_xk3_80140E88 += 0.2f * D_xk3_8013656C;
                if (D_xk3_8013656C < 15) {
                    D_xk3_8013656C++;
                }
            } else {
                D_xk3_8013656C = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CUP) {
                D_xk3_80140E8C -= 0.2f * D_xk3_80136560;
                if (D_xk3_80136560 < 15) {
                    D_xk3_80136560++;
                }
            } else {
                D_xk3_80136560 = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CDOWN) {

                D_xk3_80140E8C += 0.2f * D_xk3_80136564;
                if (D_xk3_80136564 < 15) {
                    D_xk3_80136564++;
                }
            } else {
                D_xk3_80136564 = 0;
            }
        }
    }

    D_xk3_80140E88 *= ((35.0f * D_xk3_80140E80) + 40.0f) / ((35.0f * D_xk3_80136570) + 40.0f);
    D_xk3_80140E8C *= ((35.0f * D_xk3_80140E84) + 40.0f) / ((35.0f * D_xk3_80136574) + 40.0f);
    if (D_xk3_80140E88 < -temp_fa0) {
        D_xk3_80140E88 = -temp_fa0;
    } else if (temp_fa0 < D_xk3_80140E88) {
        D_xk3_80140E88 = temp_fa0;
    }
    if (D_xk3_80140E8C < -temp_fa0) {
        D_xk3_80140E8C = -temp_fa0;
    } else if (temp_fa0 < D_xk3_80140E8C) {
        D_xk3_80140E8C = temp_fa0;
    }
    D_xk3_80136570 = D_xk3_80140E80;
    D_xk3_80136574 = D_xk3_80140E84;
}

void func_xk3_8012C744(void) {
    static u8 D_xk3_80136578 = 0;
    static u8 D_xk3_8013657C = 0;
    static u8 D_xk3_80136580 = 0;
    static u8 D_xk3_80136584 = 0;
    s32 var_v0;
    u16 var_a1;
    u16 var_a2;
    u16 var_a3;
    u16 var_v1;

    if (D_xk3_80136548) {
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_DOWN) != 0;
        if (var_v0 == 0) {
            var_v0 = gControllers[gPlayerControlPorts[0]].stickY <= -50;
        }
        var_a1 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_UP) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].stickY < 50) ^ 1;
        }
        var_a2 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_RIGHT) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].stickX < 50) ^ 1;
        }
        var_a3 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_LEFT) != 0;
        if (var_v0 == 0) {
            var_v0 = gControllers[gPlayerControlPorts[0]].stickX <= -50;
        }
        var_v1 = var_v0;
    } else {
        var_a1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_DOWN;
        var_a2 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_UP;
        var_a3 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_RIGHT;
        var_v1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_LEFT;
    }
    if (var_a2 && var_a1) {
        D_xk3_8013657C = 0;
        D_xk3_80136578 = 0;
    } else if (var_v1 && var_a3) {
        D_xk3_80136584 = 0;
        D_xk3_80136580 = 0;
    } else {
        if (var_a2) {
            D_xk3_80140E78 -= 0.1f * D_xk3_80136578;
            if (D_xk3_80136578 < 50) {
                D_xk3_80136578++;
            }
        } else {
            D_xk3_80136578 = 0;
        }
        if (var_a1) {

            D_xk3_80140E78 += 0.1f * D_xk3_8013657C;
            if (D_xk3_8013657C < 50) {
                D_xk3_8013657C++;
            }
        } else {
            D_xk3_8013657C = 0;
        }
        if (var_v1) {
            D_xk3_80140E7C -= 0.1f * D_xk3_80136580;
            if (D_xk3_80136580 < 50) {
                D_xk3_80136580++;
            }
        } else {
            D_xk3_80136580 = 0;
        }
        if (var_a3) {
            D_xk3_80140E7C += 0.1f * D_xk3_80136584;
            if (D_xk3_80136584 < 50) {
                D_xk3_80136584++;
            }
        } else {
            D_xk3_80136584 = 0;
        }
    }
    if (D_xk3_80140E78 > 360.0f) {
        D_xk3_80140E78 -= 360.0f;
    } else if (D_xk3_80140E78 < -360.0f) {
        D_xk3_80140E78 += 360.0f;
    }
    if (D_xk3_80140E7C > 360.0f) {
        D_xk3_80140E7C -= 360.0f;
    } else if (D_xk3_80140E7C < -360.0f) {
        D_xk3_80140E7C += 360.0f;
    }
}

extern BorderedBoxWidget* gMachineCreateStatsBox;

void func_xk3_8012CAC8(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        switch (gWorksMachineMode) {
            case MACHINE_MODE_PARTS:
                D_xk3_80140E60.unk_04 = 3;
                D_xk3_80136544 = 20;
                break;
            case MACHINE_MODE_SETTING:
                if (BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_OPENED)) {
                    D_xk3_80140E70.unk_04 = 3;
                    D_xk3_80136544 = 20;
                }
                break;
            case MACHINE_MODE_BODY_COLOR:
            case MACHINE_MODE_LINE_COLOR:
            case MACHINE_MODE_NUMBER_COLOR:
            case MACHINE_MODE_COCKPIT_COLOR:
                if (BorderedBox_GetInfo(gMachineCreateColorBox, IS_BORDERED_BOX_OPENED)) {
                    D_xk3_80140E68.unk_04 = 8;
                    D_xk3_80136544 = 20;
                }
                break;
            default:
                if (D_xk3_80136548) {
                    Audio_TriggerSystemSE(NA_SE_68);
                    D_xk3_80136548 = false;
                    ExpansionKit_SetMenuHighlightDrawFlag(true);
                } else if (gWorksMachineMode == MACHINE_MODE_0) {
                    Audio_TriggerSystemSE(NA_SE_68);
                    D_xk3_80136548 = true;
                    ExpansionKit_SetMenuHighlightDrawFlag(false);
                }
                break;
        }
    }
}

extern volatile unk_807C6EA8 D_807C6EA8;

void func_xk3_8012CC10(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        switch (gWorksMachineMode) {
            case MACHINE_MODE_MENU:
            case MACHINE_MODE_MENU_COLOR:
            case MACHINE_MODE_SELECT_LINE:
            case MACHINE_MODE_SELECT_MARK:
                switch (gWorksMachineMode) {
                    case MACHINE_MODE_SELECT_LINE:
                    case MACHINE_MODE_SELECT_MARK:
                        gCustomMachine = gCustomMachineWork;
                        break;
                    default:
                        break;
                }
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                func_xk1_80027B74(&gMachineCreateWidget);
                break;
            case MACHINE_MODE_PARTS:
            case MACHINE_MODE_SETTING:
                if (gWorksMachineMode == MACHINE_MODE_SETTING) {
                    BorderedBox_StartClose(gMachineCreateStatsBox);
                }
                gCustomMachine = gCustomMachineWork;
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                Audio_TriggerSystemSE(NA_SE_37);
                break;
            case MACHINE_MODE_BODY_COLOR:
            case MACHINE_MODE_LINE_COLOR:
            case MACHINE_MODE_NUMBER_COLOR:
            case MACHINE_MODE_COCKPIT_COLOR:
                gCustomMachine = gCustomMachineWork;
                func_xk3_8012BC98();
                Audio_TriggerSystemSE(NA_SE_37);
                break;
            case MACHINE_MODE_MESSAGE_BUTTON:
                Audio_TriggerSystemSE(NA_SE_37);
                D_807C6EA8.unk_08 = 0;
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            case MACHINE_MODE_LOAD_CONFIRM:
            case MACHINE_MODE_OVERWRITE_CONFIRM:
            case MACHINE_MODE_DELETE_CONFIRM:
            case MACHINE_MODE_ENTRY_ALLCLEAR_CONFIRM:
            case MACHINE_MODE_ENTRY_CLEAR_CONFIRM:
            case MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM:
            case MACHINE_MODE_CHECKSUM_ERROR:
                Audio_TriggerSystemSE(NA_SE_37);
                D_807C6EA8.unk_08 = 0;
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            case MACHINE_MODE_LOAD_SELECT_FILE:
            case MACHINE_MODE_LOAD_SELECT_SUPER:
            case MACHINE_MODE_DELETE_SELECT_FILE:
            case MACHINE_MODE_ENTRY_SELECT_FILE:
            case MACHINE_MODE_ENTRY_SELECT_SUPER:
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE:
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER:
                Audio_TriggerSystemSE(NA_SE_37);
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                func_xk1_8002BD34();
                break;
            default:
                break;
        }
    }
}

extern const char* gSuperMachineNames[];
extern u8 D_xk1_800333F0;
extern u8 D_xk3_80137160;
extern u8 D_800333F4;

void func_xk3_8012CE44(void) {
    u8 pad;

    if ((((gWorksMachineMode != MACHINE_MODE_0) && (gWorksMachineMode != MACHINE_MODE_MENU_COLOR)) ||
         ((!BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_ACTIVE)) &&
          (!BorderedBox_GetInfo(gMachineCreateColorBox, IS_BORDERED_BOX_ACTIVE)))) &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        if (D_xk1_80032C20 == 0) {
            switch (gWorksMachineMode) {
                case MACHINE_MODE_LOAD_CONFIRM:
                case MACHINE_MODE_OVERWRITE_CONFIRM:
                case MACHINE_MODE_DELETE_CONFIRM:
                case MACHINE_MODE_ENTRY_ALLCLEAR_CONFIRM:
                case MACHINE_MODE_ENTRY_CLEAR_CONFIRM:
                case MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM:
                case MACHINE_MODE_CHECKSUM_ERROR:
                    Audio_TriggerSystemSE(NA_SE_37);
                    D_807C6EA8.unk_08 = 0;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    return;
                default:
                    break;
            }
        }

        switch (gWorksMachineMode) {
            case MACHINE_MODE_0:
            case MACHINE_MODE_MENU:
            case MACHINE_MODE_MENU_COLOR:
            case MACHINE_MODE_SELECT_LINE:
            case MACHINE_MODE_SELECT_MARK:
                if ((D_xk1_800333F0 != 0) && (D_xk3_80136550 < 3)) {
                    D_807C6EA8.unk_08 = 0x16;
                    PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                    gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
                    Audio_TriggerSystemSE(NA_SE_32);
                } else {
                    func_xk1_80027DC8(&gMachineCreateWidget, &D_xk3_80140E50, &D_xk3_80140E54);
                    D_xk3_80140E58 = D_xk3_80140E54;
                }
                break;
            case MACHINE_MODE_PARTS:
                switch (D_xk3_80140E60.unk_04) {
                    case 0:
                        if (D_xk3_80140E60.unk_00 != gCustomMachine.frontType) {
                            gCustomMachine.frontType = D_xk3_80140E60.unk_00;
                            Audio_TriggerSystemSE(NA_SE_39);
                        }
                        break;
                    case 1:
                        if (D_xk3_80140E60.unk_00 != gCustomMachine.rearType) {
                            gCustomMachine.rearType = D_xk3_80140E60.unk_00;
                            Audio_TriggerSystemSE(NA_SE_39);
                        }
                        break;
                    case 2:
                        if (D_xk3_80140E60.unk_00 != gCustomMachine.wingType) {
                            gCustomMachine.wingType = D_xk3_80140E60.unk_00;
                            Audio_TriggerSystemSE(NA_SE_39);
                        }
                        break;
                    case 3:
                        PRINTF("WORKS MACHINE MODE : 0\n");
                        gWorksMachineMode = MACHINE_MODE_0;
                        Audio_TriggerSystemSE(NA_SE_36);
                        break;
                }
                break;
            case MACHINE_MODE_SETTING:
                func_xk3_8013571C();
                break;
            case MACHINE_MODE_BODY_COLOR:
                func_xk3_80135E58(&gCustomMachine.red, &gCustomMachine.green, &gCustomMachine.blue);
                break;
            case MACHINE_MODE_LINE_COLOR:
                func_xk3_80135E58(&gCustomMachine.decalR, &gCustomMachine.decalG, &gCustomMachine.decalB);
                break;
            case MACHINE_MODE_NUMBER_COLOR:
                func_xk3_80135E58(&gCustomMachine.numberR, &gCustomMachine.numberG, &gCustomMachine.numberB);
                break;
            case MACHINE_MODE_COCKPIT_COLOR:
                func_xk3_80135E58(&gCustomMachine.cockpitR, &gCustomMachine.cockpitG, &gCustomMachine.cockpitB);
                break;
            case MACHINE_MODE_LOAD_SELECT_FILE:
                Audio_TriggerSystemSE(NA_SE_36);
                if (func_xk1_8002BD14() == 0) {
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    func_xk1_8002FFDC();
                    D_xk1_800333F0 = 0;
                } else if ((D_xk3_80137160 != 0) && (func_xk1_8002BD14() == 1)) {
                    PRINTF("WORKS MACHINE MODE : LOAD_SELECT_SUPER\n");
                    gWorksMachineMode = MACHINE_MODE_LOAD_SELECT_SUPER;
                    func_xk3_801360B8();
                    func_xk3_8012B950();
                } else {
                    PRINTF("WORKS MACHINE MODE : LOAD_CONFIRM\n");
                    gWorksMachineMode = MACHINE_MODE_LOAD_CONFIRM;
                    D_xk3_80141298 = func_xk1_8002BCC4();
                }
                break;
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE:
                if ((D_xk3_80137160 != 0) && (func_xk1_8002BD14() == 0)) {
                    Audio_TriggerSystemSE(NA_SE_36);
                    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_SUPER\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER;
                    func_xk3_80136320();
                } else {
                    D_xk3_80141298 = func_xk1_8002BCC4();
                    Audio_TriggerSystemSE(NA_SE_36);
                    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_CONFIRM\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_CONFIRM;
                }
                break;
            case MACHINE_MODE_ENTRY_CLEAR_CONFIRM: {
                u8 i;
                Audio_TriggerSystemSE(NA_SE_39);
                if (mfsStrCmp(D_xk3_80141298, &gCustomMachine.machineName) == 0) {
                    gCustomMachine.number = 31;
                }
                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] > 0) &&
                        (mfsStrCmp(&gCustomMachinesInfo.customMachines[i].machineName, D_xk3_80141298) == 0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 0;
                        gCustomMachinesInfo.customMachines[i].number = 31;
                        func_8071E0C0();
                        break;
                    }
                }
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            }
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER:
                D_xk3_80141298 = func_xk1_8002BCC4();
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SUPER_CONFIRM\n");
                gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM;
                break;
            case MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM: {
                u8 i;
                Audio_TriggerSystemSE(NA_SE_39);

                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] == -1) &&
                        (mfsStrCmp(D_xk3_80141298, gSuperMachineNames[i]) == 0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 0;
                        gCustomMachinesInfo.customMachines[i].number = 31;
                        func_8071E0C0();
                        break;
                    }
                }

                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            }
            case MACHINE_MODE_ENTRY_SELECT_FILE:
                Audio_TriggerSystemSE(NA_SE_36);
                if ((D_xk3_80137160 != 0) && (func_xk1_8002BD14() == 0)) {
                    PRINTF("WORKS MACHINE MODE : ENTRY_SELECT_SUPER\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_SELECT_SUPER;
                    func_xk3_801360B8();
                } else {
                    D_xk3_80141298 = func_xk1_8002BCC4();
                    PRINTF("WORKS MACHINE MODE : ENTRY_LOAD_NOW\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_LOAD_NOW;
                    func_80768638(MFS_ENTRY_WORKING_DIR, D_xk3_80141298, "CARD", &gCustomMachineWork,
                                  sizeof(CustomMachine));
                    PRINTF("SUPER MACHINE No.%d\n");
                }
                break;
            case MACHINE_MODE_LOAD_SELECT_SUPER:
            case MACHINE_MODE_ENTRY_SELECT_SUPER: {
                u8 i;
                if (gWorksMachineMode == MACHINE_MODE_ENTRY_SELECT_SUPER) {
                    D_xk3_80141291 = D_800333F4;
                }
                Audio_TriggerSystemSE(NA_SE_36);
                D_xk3_80141298 = func_xk1_8002BCC4();

                for (i = 0; i < 30; i++) {
                    if (mfsStrCmp(D_xk3_80141298, gSuperMachineNames[i]) == 0) {
                        D_800333F4 = i;
                        break;
                    }
                }

                if (gWorksMachineMode == MACHINE_MODE_ENTRY_SELECT_SUPER) {
                    gCustomMachineBackup = gCustomMachine;
                    D_xk3_80141290 = D_xk1_800333F0;
                    D_xk1_800333F0 = 1;
                    PRINTF("WORKS MACHINE MODE : ENTRY\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY;
                    func_xk3_80132F50();
                } else {
                    D_xk1_800333F0 = 1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                }
                break;
            }
            case MACHINE_MODE_DELETE_SELECT_FILE:
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : DELETE_CONFIRM\n");
                gWorksMachineMode = MACHINE_MODE_DELETE_CONFIRM;
                D_xk3_80141298 = func_xk1_8002BCC4();
                break;
            case MACHINE_MODE_LOAD_CONFIRM:
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : LOAD_NOW\n");
                gWorksMachineMode = MACHINE_MODE_LOAD_NOW;
                func_80768574(MFS_ENTRY_WORKING_DIR, D_xk3_80141298, "CARD", &gCustomMachineWork,
                              sizeof(CustomMachine));
                break;
            case MACHINE_MODE_DELETE_CONFIRM:
            case MACHINE_MODE_CHECKSUM_ERROR: {
                u8 i;
                if (mfsStrCmp(D_xk3_80141298, &gCustomMachine.machineName) == 0) {
                    gCustomMachine.number = 31;
                }

                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] > 0) &&
                        (mfsStrCmp(gCustomMachinesInfo.customMachines[i].machineName, D_xk3_80141298) == 0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 0;
                        gCustomMachinesInfo.customMachines[i].number = 31;
                        func_8071E0C0();
                        break;
                    }
                }

                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                func_807688D0(MFS_ENTRY_WORKING_DIR, D_xk3_80141298, "CARD", true);
                break;
            }
            case MACHINE_MODE_OVERWRITE_CONFIRM:
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : OVERWRITE_GET_FILE\n");
                gWorksMachineMode = MACHINE_MODE_OVERWRITE_GET_FILE;
                func_807687E0(0, "CARD");
                break;
            case MACHINE_MODE_ENTRY_ALLCLEAR_CONFIRM:
                func_xk1_8002FC70();
                D_807C6EA8.unk_08 = 0;
                Audio_TriggerSystemSE(NA_SE_5);
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            case MACHINE_MODE_MESSAGE_BUTTON:
                D_807C6EA8.unk_08 = 0;
                Audio_TriggerSystemSE(NA_SE_37);
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            default:
                break;
        }
    }
}

void func_xk3_8012D700(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((gCustomMachinesInfo.characterCustomState[i] > 0) &&
            (mfsStrCmp(gCustomMachinesInfo.customMachines[i].machineName, gCustomMachine.machineName) == 0)) {
            gCustomMachine.number = kCharacterNumbers[i];
            return;
        }
    }
    gCustomMachine.number = 31;
}

extern volatile u8 D_80794E20;
extern volatile s32 D_807C6F0C;

void func_xk3_8012D79C(void) {
    u16 checksum;
    u8 i;

    switch (gWorksMachineMode) {
        case MACHINE_MODE_LOAD_NOW:
        case MACHINE_MODE_ENTRY_LOAD_NOW:
            checksum = MachineCreate_CalculateCustomMachineChecksum(&gCustomMachineWork);
            if ((gCustomMachineWork.checksum != checksum) || (checksum == 0) ||
                (MachineCreate_CustomMachineStatsIsValid(&gCustomMachineWork))) {
                D_807C6EA8.unk_08 = 0x15;
                PRINTF("WORKS MACHINE MODE : CHECKSUM_ERROR\n");
                gWorksMachineMode = MACHINE_MODE_CHECKSUM_ERROR;
            } else if (gWorksMachineMode == MACHINE_MODE_ENTRY_LOAD_NOW) {
                gCustomMachineBackup = gCustomMachine;
                D_xk3_80141290 = D_xk1_800333F0;
                D_xk3_80141291 = D_800333F4;
                D_xk1_800333F0 = 0;
                gCustomMachine = gCustomMachineWork;
                gCustomMachinesInfoBackup = gCustomMachinesInfo;

                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] > 0) &&
                        (mfsStrCmp(gCustomMachinesInfo.customMachines[i].machineName, gCustomMachine.machineName) ==
                         0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 1;
                        break;
                    }
                }
                PRINTF("WORKS MACHINE MODE : ENTRY\n");
                gWorksMachineMode = MACHINE_MODE_ENTRY;
                func_xk3_80132F50();
            } else {
                gCustomMachine = gCustomMachineWork;
                func_xk3_8012D700();
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                D_xk1_800333F0 = 0;
            }
            break;
        case MACHINE_MODE_LOAD_GET_FILE:
        case MACHINE_MODE_ENTRY_GET_FILE:
            if (D_807C6F0C == 0) {
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            }
            if (gWorksMachineMode == MACHINE_MODE_ENTRY_GET_FILE) {
                PRINTF("WORKS MACHINE MODE : ENTRY_SELECT_FILE\n");
                gWorksMachineMode = MACHINE_MODE_ENTRY_SELECT_FILE;
            } else {
                PRINTF("WORKS MACHINE MODE : LOAD_SELECT_FILE\n");
                gWorksMachineMode = MACHINE_MODE_LOAD_SELECT_FILE;
            }
            func_xk3_8012B950();
            break;
        case MACHINE_MODE_DELETE_GET_FILE:
            if (D_807C6F0C == 0) {
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
            } else {
                PRINTF("WORKS MACHINE MODE : DELETE_SELECT_FILE\n");
                gWorksMachineMode = MACHINE_MODE_DELETE_SELECT_FILE;
                func_xk3_8012B950();
            }
            break;
        case MACHINE_MODE_SAVE_FILE_EXIST:
            if (D_80794E20 == 1) {
                D_807C6EA8.unk_08 = 0x12;
                PRINTF("WORKS MACHINE MODE : OVERWRITE_CONFIRM\n");
                gWorksMachineMode = MACHINE_MODE_OVERWRITE_CONFIRM;
            } else {
                PRINTF("WORKS MACHINE MODE : SAVE_GET_FILE\n");
                gWorksMachineMode = MACHINE_MODE_SAVE_GET_FILE;
                func_807687E0(0, "CARD");
            }
            break;
        case MACHINE_MODE_SAVE_GET_FILE:
            if (D_807C6F0C >= 100) {
                D_807C6EA8.unk_08 = 0x13;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
            } else {
                func_xk3_8012BB48();
            }
            break;
        case MACHINE_MODE_OVERWRITE_GET_FILE:
            if (D_807C6F0C == 100) {
                PRINTF("WORKS MACHINE MODE : OVERWRITE_FILE_EXIST\n");
                gWorksMachineMode = MACHINE_MODE_OVERWRITE_FILE_EXIST;
                func_8076870C(MFS_ENTRY_WORKING_DIR, gCustomMachine.machineName, "CARD");
            } else if (D_807C6F0C > 100) {
                D_807C6EA8.unk_08 = 0x13;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
            } else {
                func_xk3_8012BB48();
            }
            break;
        case MACHINE_MODE_OVERWRITE_FILE_EXIST:
            if (D_80794E20 == 1) {
                func_xk3_8012BB48();
            } else {
                D_807C6EA8.unk_08 = 0x13;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
            }
            break;
        default:
            break;
    }
}

s32 D_xk3_80136588[][7] = {
    { 270, 290, 320, 350, 420, 580, 630 },  // MACHINE_PART_FRONT
    { 510, 560, 630, 720, 890, 930, 1170 }, // MACHINE_PART_REAR
    { 0, 100, 120, 140, 190, 250, 420 },    // MACHINE_PART_WING
};

void func_xk3_8012DBFC(void) {

    if (gWorksMachineMode == MACHINE_MODE_ENTRY) {
        return;
    }
    if ((gWorksMachineMode == MACHINE_MODE_PARTS) && (D_xk3_80136540 < 7000.0f)) {
        D_xk3_80136540 += 300.0f;
    }
    if ((D_xk3_80136550 == 5) && !D_xk3_80136548) {
        D_xk3_8013654C = true;
    } else {
        D_xk3_8013654C = false;
    }
    if (D_xk1_800333F0 != 0) {
        return;
    }
    D_xk3_80141294 = D_xk3_80136588[MACHINE_PART_FRONT][gCustomMachine.frontType] +
                     D_xk3_80136588[MACHINE_PART_REAR][gCustomMachine.rearType] +
                     D_xk3_80136588[MACHINE_PART_WING][gCustomMachine.wingType];
    switch (gWorksMachineMode) {
        case MACHINE_MODE_SELECT_LINE:
            gCustomMachine.decal = MACHINE_DECAL((D_xk3_80140E54 - 0x34) / 16);
            break;
        case MACHINE_MODE_SELECT_MARK:
            gCustomMachine.logo = MACHINE_LOGO((D_xk3_80140E54 - 0x34) / 16);
            break;
    }
    if ((gWorksMachineMode == MACHINE_MODE_SETTING) &&
        (BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_OPENED))) {
        D_807C6EA8.unk_08 = 0;
    }
    switch (gWorksMachineMode) {
        case MACHINE_MODE_PARTS:
            if ((D_xk3_80140E60.unk_04 == 3) && (D_xk3_80136544 >= 0)) {
                if (D_xk3_80136544 == 0) {
                    D_xk3_80136544 = -1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    Audio_TriggerSystemSE(NA_SE_36);
                } else {
                    D_xk3_80136544--;
                }
            } else {
                D_xk3_80136544 = -1;
            }
            break;
        case MACHINE_MODE_SETTING:
            if ((D_xk3_80140E70.unk_04 == 3) && (D_xk3_80136544 >= 0)) {
                if (D_xk3_80136544 == 0) {
                    D_xk3_80136544 = -1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    Audio_TriggerSystemSE(NA_SE_36);
                    BorderedBox_StartClose(gMachineCreateStatsBox);
                } else {
                    D_xk3_80136544 -= 1;
                }
            } else {
                D_xk3_80136544 = -1;
            }
            break;
        case MACHINE_MODE_BODY_COLOR:
        case MACHINE_MODE_LINE_COLOR:
        case MACHINE_MODE_NUMBER_COLOR:
        case MACHINE_MODE_COCKPIT_COLOR:
            if ((D_xk3_80140E68.unk_04 == 8) && (D_xk3_80136544 >= 0)) {
                if (D_xk3_80136544 == 0) {
                    D_xk3_80136544 = -1;
                    func_xk3_8012BC98();
                    Audio_TriggerSystemSE(NA_SE_36);
                } else {
                    D_xk3_80136544 -= 1;
                }
            } else {
                D_xk3_80136544 = -1;
            }
            break;
        default:
            D_xk3_80136544 = -1;
            break;
    }
}

extern s32 gTransitionState;
extern volatile u8 D_80794E14;

bool func_xk3_8012DF04(void) {

    func_xk1_800260E4();
    if (gWorksMachineMode == MACHINE_MODE_SAVE_FILE_EXIST_BEFORE) {
        PRINTF("WORKS MACHINE MODE : SAVE_FILE_EXIST\n");
        gWorksMachineMode = MACHINE_MODE_SAVE_FILE_EXIST;
        func_8076869C(MFS_ENTRY_WORKING_DIR, gCustomMachine.machineName, "CARD");
    }
    func_xk1_8002D974();
    if ((D_80794E14 == 0) && (gTransitionState == TRANSITION_INACTIVE) && !D_xk3_80136548) {
        func_xk3_8012BD84();
    }
    if (gWorksMachineMode != MACHINE_MODE_PARTS) {
        func_xk3_8012C1C8();
        func_xk3_8012C408();
        func_xk3_8012B99C();
    }
    func_xk3_8012C744();
    if (gWorksMachineMode != MACHINE_MODE_MNAME) {
        if (gTransitionState == TRANSITION_INACTIVE) {
            func_xk3_8012CAC8();
        }
        if ((D_80794E14 == 0) && (gTransitionState == TRANSITION_INACTIVE) && !D_xk3_80136548 &&
            (!(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) ||
             !(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B))) {
            func_xk3_8012CC10();
            func_xk3_8012CE44();
        }
    } else {
        ExpansionKit_NameEntryUpdate(NULL, NULL);
    }
    if (D_80794E14 == 0) {
        func_xk3_8012D79C();
        func_xk3_8012DBFC();
    }
    if (D_xk3_8013654C && (D_80794E14 == 0) && !D_xk3_80136548 &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        return true;
    }
    return false;
}
