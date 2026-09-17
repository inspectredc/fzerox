#include "global.h"
#include "machine_create.h"
#include "leo/mfs.h"
#include "fzx_machine.h"
#include "fzx_bordered_box.h"
#include "src/overlays/ovl_i2/transition.h"

s32 gMachineCreateCursorPosX;
s32 gMachineCreateCursorPosY;
f32 gMachineCreateCursorPosYF;

MachineCreateGrid gMachineCreatePartsGrid;
MachineCreateGrid gMachineCreateColorGrid;
MachineCreateGrid gMachineCreateMachineSettingsGrid;

f32 gMachineCreateMachinePitch;
f32 gMachineCreateMachineYaw;
f32 sMachineCreateViewScaleX;
f32 sMachineCreateViewScaleY;
f32 sMachineCreateViewTransX;
f32 sMachineCreateViewTransY;
CustomMachinesInfo gCustomMachinesInfoBackup;
CustomMachine gCustomMachineBackup;

u8 sCustomMachineIsSuperBackup;
u8 gCustomMachineCurrentSuperIndexBackup;
s32 gMachineCreateMachineWeight;
char* gMachineCreateSelectedFileName;

f32 gMachineCreatePartsLightSourceX = -7000.0f;
s8 sMachineCreateTransitionTimer = -1;
u8 gMachineCreateModeShowInstructions = false;
u8 gMachineCreateHighlightExit = false;
s32 sMachineCreateOptionIndex = 0;
s32 D_xk3_80136554 = 0;

void MachineCreate_InitFileMenu(void) {
    gMachineCreateCursorPosY = 87;
    gMachineCreateCursorPosYF = 87.0f;
    EKFileMenu_InitFileMenu(168, 87, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
}

extern GfxPool* gGfxPool;

void MachineCreate_UpdateView(void) {
    gGfxPool->unk_2C2C8[1].vp.vscale[0] = sMachineCreateViewScaleX * ((SCREEN_WIDTH / 2) * 4);
    gGfxPool->unk_2C2C8[1].vp.vscale[1] = sMachineCreateViewScaleY * ((SCREEN_HEIGHT / 2) * 4);
    gGfxPool->unk_2C2C8[1].vp.vscale[2] = 0x1FF;
    gGfxPool->unk_2C2C8[1].vp.vscale[3] = 0;
    gGfxPool->unk_2C2C8[1].vp.vtrans[0] = (sMachineCreateViewTransX + 25.0f + 64.0f) * 4.0f;
    gGfxPool->unk_2C2C8[1].vp.vtrans[1] = (sMachineCreateViewTransY + 90.0f + 64.0f + 2.0f) * 4.0f;
    gGfxPool->unk_2C2C8[1].vp.vtrans[2] = 0x1FF;
    gGfxPool->unk_2C2C8[1].vp.vtrans[3] = 0;
}

void MachineCreate_InitView(void) {
    sMachineCreateViewScaleX = 1.0f;
    sMachineCreateViewScaleY = 1.0f;
    sMachineCreateViewTransX = 0.0f;
    sMachineCreateViewTransY = 0.0f;
    MachineCreate_UpdateView();
    gMachineCreateMachinePitch = 0.0f;
    gMachineCreateMachineYaw = 0.0f;
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

void MachineCreate_SaveMachine(void) {
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
extern MenuWidget gMachineCreateWidget;

void MachineCreate_CloseColorMenu(void) {
    s32 mode;

    mode = gWorksMachineMode;
    gMachineCreateCursorPosY = 28;
    EKWidget_ExecuteWidgetAction(&gMachineCreateWidget, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
    gMachineCreateCursorPosY = 68;
    EKWidget_ExecuteWidgetAction(&gMachineCreateWidget, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
    switch (mode) {
        case MACHINE_MODE_BODY_COLOR:
            gMachineCreateCursorPosY = 52;
            break;
        case MACHINE_MODE_LINE_COLOR:
            gMachineCreateCursorPosY = 68;
            break;
        case MACHINE_MODE_NUMBER_COLOR:
            gMachineCreateCursorPosY = 84;
            break;
        case MACHINE_MODE_COCKPIT_COLOR:
            gMachineCreateCursorPosY = 100;
            break;
    }
    gMachineCreateCursorPosYF = gMachineCreateCursorPosY;
    BorderedBox_StartClose(gMachineCreateColorBox);
}

extern s32 gExpansionKitYesNoOptionIndex;
extern s32 gMachineCreateCursorPosX;
extern s32 gMachineCreateCursorPosY;

void MachineCreate_UpdateCursor(void) {

    switch (gWorksMachineMode) {
        case MACHINE_MODE_BODY_COLOR:
        case MACHINE_MODE_LINE_COLOR:
        case MACHINE_MODE_NUMBER_COLOR:
        case MACHINE_MODE_COCKPIT_COLOR: {
            s32 prevX = gMachineCreateColorGrid.x;
            s32 prevY = gMachineCreateColorGrid.y;
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            if (gMachineCreateColorGrid.y != 8) {
                EKController_UpdateHorizontalOption(&gMachineCreateColorGrid.x, 7, 1);
            }
            EKController_UpdateVerticalOptionSlow(&gMachineCreateColorGrid.y, 8, 0);
            if ((prevX != gMachineCreateColorGrid.x) || (prevY != gMachineCreateColorGrid.y)) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        }
        case MACHINE_MODE_PARTS: {
            s32 prevX = gMachineCreatePartsGrid.x;
            s32 prevY = gMachineCreatePartsGrid.y;
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            if (gMachineCreatePartsGrid.y != 3) {
                EKController_UpdateHorizontalOption(&gMachineCreatePartsGrid.x, 6, 1);
            }
            EKController_UpdateVerticalOptionSlow(&gMachineCreatePartsGrid.y, 3, 0);
            if ((prevX != gMachineCreatePartsGrid.x) || (prevY != gMachineCreatePartsGrid.y)) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            break;
        }
        case MACHINE_MODE_SETTING: {
            s32 prevX = gMachineCreateMachineSettingsGrid.x;
            s32 prevY = gMachineCreateMachineSettingsGrid.y;
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            if (gMachineCreateMachineSettingsGrid.y != 3) {
                EKController_UpdateHorizontalOption(&gMachineCreateMachineSettingsGrid.x, 4, 1);
            }
            EKController_UpdateVerticalOptionSlow(&gMachineCreateMachineSettingsGrid.y, 3, 0);
            if ((prevX != gMachineCreateMachineSettingsGrid.x) || (prevY != gMachineCreateMachineSettingsGrid.y)) {
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
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            EKFileMenu_UpdateOptionIndex();
            break;
        case MACHINE_MODE_MENU:
            D_xk3_80136554 = (s32) (gMachineCreateCursorPosY - 36) / 16;
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            EKController_UpdateVerticalOptionSlow(&D_xk3_80136554, 2, 0);
            gMachineCreateCursorPosY = (D_xk3_80136554 * 16) + 36;
            EKWidget_SetCursorToWidget(&gMachineCreateWidget, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
            EKWidget_SetHighlightedIndex(&gMachineCreateWidget, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
            break;
        case MACHINE_MODE_MENU_COLOR:
        case MACHINE_MODE_SELECT_LINE:
        case MACHINE_MODE_SELECT_MARK:
            D_xk3_80136554 = (s32) (gMachineCreateCursorPosY - 52) / 16;
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            EKController_UpdateVerticalOptionSlow(&D_xk3_80136554, 7, 0);
            gMachineCreateCursorPosY = (D_xk3_80136554 * 16) + 52;
            EKWidget_SetCursorToWidget(&gMachineCreateWidget, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
            EKWidget_SetHighlightedIndex(&gMachineCreateWidget, &gMachineCreateCursorPosX, &gMachineCreateCursorPosY);
            break;
        case MACHINE_MODE_0: {
            s32 prevOptionIndex = sMachineCreateOptionIndex;
            EKController_SetRepeatDelay(27, 6);
            EKController_SetDeadZone(40);
            EKController_UpdateHorizontalOption(&sMachineCreateOptionIndex, 5, 1);
            gMachineCreateCursorPosX = (sMachineCreateOptionIndex * 48) + 48;
            gMachineCreateCursorPosY = 28;
            if (prevOptionIndex != sMachineCreateOptionIndex) {
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
            EKFileMenu_UpdateYesNoOption();
            break;
        default:
            gExpansionKitYesNoOptionIndex = 0;
            break;
    }
}

void MachineCreate_UpdateViewZoom(void) {
    static u8 sZoomOutSpeed = 0;
    static u8 sZoomInSpeed = 0;
    u16 zoomIn;
    u16 zoomOut;

    if (gMachineCreateModeShowInstructions) {
        zoomIn = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_A) ||
                 (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R);
        zoomOut = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_B) ||
                  (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L);
    } else {
        zoomIn = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R;
        zoomOut = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L;
    }
    if (zoomOut && zoomIn) {
        sZoomOutSpeed = sZoomInSpeed = 0;

    } else {
        if (zoomIn) {
            sMachineCreateViewScaleX *= 1.0f + (0.002f * sZoomInSpeed);
            sMachineCreateViewScaleY = sMachineCreateViewScaleX;
            if (sZoomInSpeed < 50) {
                sZoomInSpeed++;
            }
        } else {
            sZoomInSpeed = 0;
        }
        if (zoomOut) {
            sMachineCreateViewScaleX /= 1.0f + (0.002f * sZoomOutSpeed);
            sMachineCreateViewScaleY = sMachineCreateViewScaleX;
            if (sZoomOutSpeed < 50) {
                sZoomOutSpeed++;
            }
        } else {
            sZoomOutSpeed = 0;
        }
    }
    if (sMachineCreateViewScaleX > 6.0f) {
        sMachineCreateViewScaleX = sMachineCreateViewScaleY = 6.0f;
    }
    if (sMachineCreateViewScaleX < 0.2f) {
        sMachineCreateViewScaleX = sMachineCreateViewScaleY = 0.2f;
    }
}

void MachineCreate_UpdateViewTranslation(void) {
    static u8 sMoveUpSpeed = 0;
    static u8 sMoveDownSpeed = 0;
    static u8 sMoveLeftSpeed = 0;
    static u8 sMoveRightSpeed = 0;
    static f32 sPrevMachineCreateViewScaleX = 1.0f;
    static f32 sPrevMachineCreateViewScaleY = 1.0f;
    f32 scaledRadiusDistance;

    scaledRadiusDistance = (35.0f * sMachineCreateViewScaleX) + 40.0f;

    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CLEFT) &&
        (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CRIGHT)) {
        sMoveLeftSpeed = sMoveRightSpeed = 0;
    } else {
        if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CUP) &&
            (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CDOWN)) {
            sMoveUpSpeed = sMoveDownSpeed = 0;
        } else {
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CLEFT) {
                sMachineCreateViewTransX -= 0.2f * sMoveLeftSpeed;
                if (sMoveLeftSpeed < 15) {
                    sMoveLeftSpeed++;
                }
            } else {
                sMoveLeftSpeed = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CRIGHT) {
                sMachineCreateViewTransX += 0.2f * sMoveRightSpeed;
                if (sMoveRightSpeed < 15) {
                    sMoveRightSpeed++;
                }
            } else {
                sMoveRightSpeed = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CUP) {
                sMachineCreateViewTransY -= 0.2f * sMoveUpSpeed;
                if (sMoveUpSpeed < 15) {
                    sMoveUpSpeed++;
                }
            } else {
                sMoveUpSpeed = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CDOWN) {

                sMachineCreateViewTransY += 0.2f * sMoveDownSpeed;
                if (sMoveDownSpeed < 15) {
                    sMoveDownSpeed++;
                }
            } else {
                sMoveDownSpeed = 0;
            }
        }
    }

    sMachineCreateViewTransX *=
        ((35.0f * sMachineCreateViewScaleX) + 40.0f) / ((35.0f * sPrevMachineCreateViewScaleX) + 40.0f);
    sMachineCreateViewTransY *=
        ((35.0f * sMachineCreateViewScaleY) + 40.0f) / ((35.0f * sPrevMachineCreateViewScaleY) + 40.0f);
    if (sMachineCreateViewTransX < -scaledRadiusDistance) {
        sMachineCreateViewTransX = -scaledRadiusDistance;
    } else if (scaledRadiusDistance < sMachineCreateViewTransX) {
        sMachineCreateViewTransX = scaledRadiusDistance;
    }
    if (sMachineCreateViewTransY < -scaledRadiusDistance) {
        sMachineCreateViewTransY = -scaledRadiusDistance;
    } else if (scaledRadiusDistance < sMachineCreateViewTransY) {
        sMachineCreateViewTransY = scaledRadiusDistance;
    }
    sPrevMachineCreateViewScaleX = sMachineCreateViewScaleX;
    sPrevMachineCreateViewScaleY = sMachineCreateViewScaleY;
}

void MachineCreate_UpdateMachineRotation(void) {
    static u8 sRotateUpSpeed = 0;
    static u8 sRotateDownSpeed = 0;
    static u8 sRotateLeftSpeed = 0;
    static u8 sRotateRightSpeed = 0;
    u16 rotateDown;
    u16 rotateUp;
    u16 rotateRight;
    u16 rotateLeft;

    if (gMachineCreateModeShowInstructions) {
        rotateDown = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_DOWN) ||
                     (gControllers[gPlayerControlPorts[0]].stickY <= -50);
        rotateUp = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_UP) ||
                   ((gControllers[gPlayerControlPorts[0]].stickY >= 50));
        rotateRight = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_RIGHT) ||
                      ((gControllers[gPlayerControlPorts[0]].stickX >= 50));
        rotateLeft = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_LEFT) ||
                     (gControllers[gPlayerControlPorts[0]].stickX <= -50);
    } else {
        rotateDown = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_DOWN;
        rotateUp = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_UP;
        rotateRight = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_RIGHT;
        rotateLeft = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_LEFT;
    }
    if (rotateUp && rotateDown) {
        sRotateUpSpeed = sRotateDownSpeed = 0;
    } else if (rotateLeft && rotateRight) {
        sRotateLeftSpeed = sRotateRightSpeed = 0;
    } else {
        if (rotateUp) {
            gMachineCreateMachinePitch -= 0.1f * sRotateUpSpeed;
            if (sRotateUpSpeed < 50) {
                sRotateUpSpeed++;
            }
        } else {
            sRotateUpSpeed = 0;
        }
        if (rotateDown) {

            gMachineCreateMachinePitch += 0.1f * sRotateDownSpeed;
            if (sRotateDownSpeed < 50) {
                sRotateDownSpeed++;
            }
        } else {
            sRotateDownSpeed = 0;
        }
        if (rotateLeft) {
            gMachineCreateMachineYaw -= 0.1f * sRotateLeftSpeed;
            if (sRotateLeftSpeed < 50) {
                sRotateLeftSpeed++;
            }
        } else {
            sRotateLeftSpeed = 0;
        }
        if (rotateRight) {
            gMachineCreateMachineYaw += 0.1f * sRotateRightSpeed;
            if (sRotateRightSpeed < 50) {
                sRotateRightSpeed++;
            }
        } else {
            sRotateRightSpeed = 0;
        }
    }
    if (gMachineCreateMachinePitch > 360.0f) {
        gMachineCreateMachinePitch -= 360.0f;
    } else if (gMachineCreateMachinePitch < -360.0f) {
        gMachineCreateMachinePitch += 360.0f;
    }
    if (gMachineCreateMachineYaw > 360.0f) {
        gMachineCreateMachineYaw -= 360.0f;
    } else if (gMachineCreateMachineYaw < -360.0f) {
        gMachineCreateMachineYaw += 360.0f;
    }
}

extern BorderedBoxWidget* gMachineCreateStatsBox;

void MachineCreate_UpdateStartInput(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        switch (gWorksMachineMode) {
            case MACHINE_MODE_PARTS:
                gMachineCreatePartsGrid.y = 3;
                sMachineCreateTransitionTimer = 20;
                break;
            case MACHINE_MODE_SETTING:
                if (BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_OPENED)) {
                    gMachineCreateMachineSettingsGrid.y = 3;
                    sMachineCreateTransitionTimer = 20;
                }
                break;
            case MACHINE_MODE_BODY_COLOR:
            case MACHINE_MODE_LINE_COLOR:
            case MACHINE_MODE_NUMBER_COLOR:
            case MACHINE_MODE_COCKPIT_COLOR:
                if (BorderedBox_GetInfo(gMachineCreateColorBox, IS_BORDERED_BOX_OPENED)) {
                    gMachineCreateColorGrid.y = 8;
                    sMachineCreateTransitionTimer = 20;
                }
                break;
            default:
                if (gMachineCreateModeShowInstructions) {
                    Audio_TriggerSystemSE(NA_SE_68);
                    gMachineCreateModeShowInstructions = false;
                    ExpansionKit_SetMenuHighlightDrawFlag(true);
                } else if (gWorksMachineMode == MACHINE_MODE_0) {
                    Audio_TriggerSystemSE(NA_SE_68);
                    gMachineCreateModeShowInstructions = true;
                    ExpansionKit_SetMenuHighlightDrawFlag(false);
                }
                break;
        }
    }
}

extern volatile unk_807C6EA8 D_807C6EA8;

void MachineCreate_UpdateBInput(void) {
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
                EKWidget_CloseRootWidget(&gMachineCreateWidget);
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
                MachineCreate_CloseColorMenu();
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
extern u8 gCustomMachineIsSuper;
extern u8 gMachineCreateSuperMachinesCount;
extern u8 gCustomMachineCurrentSuperIndex;

void MachineCreate_UpdateAInput(void) {
    u8 pad;

    if ((((gWorksMachineMode != MACHINE_MODE_0) && (gWorksMachineMode != MACHINE_MODE_MENU_COLOR)) ||
         ((!BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_ACTIVE)) &&
          (!BorderedBox_GetInfo(gMachineCreateColorBox, IS_BORDERED_BOX_ACTIVE)))) &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        if (gExpansionKitYesNoOptionIndex == 0) {
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
                if (gCustomMachineIsSuper && (sMachineCreateOptionIndex < 3)) {
                    D_807C6EA8.unk_08 = 22;
                    PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                    gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
                    Audio_TriggerSystemSE(NA_SE_32);
                } else {
                    EKWidget_ExecuteWidgetAction(&gMachineCreateWidget, &gMachineCreateCursorPosX,
                                                 &gMachineCreateCursorPosY);
                    gMachineCreateCursorPosYF = gMachineCreateCursorPosY;
                }
                break;
            case MACHINE_MODE_PARTS:
                switch (gMachineCreatePartsGrid.y) {
                    case MACHINE_PART_FRONT:
                        if (gMachineCreatePartsGrid.x != gCustomMachine.frontType) {
                            gCustomMachine.frontType = gMachineCreatePartsGrid.x;
                            Audio_TriggerSystemSE(NA_SE_39);
                        }
                        break;
                    case MACHINE_PART_REAR:
                        if (gMachineCreatePartsGrid.x != gCustomMachine.rearType) {
                            gCustomMachine.rearType = gMachineCreatePartsGrid.x;
                            Audio_TriggerSystemSE(NA_SE_39);
                        }
                        break;
                    case MACHINE_PART_WING:
                        if (gMachineCreatePartsGrid.x != gCustomMachine.wingType) {
                            gCustomMachine.wingType = gMachineCreatePartsGrid.x;
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
                MachineCreate_UpdateMachineSettingAInput();
                break;
            case MACHINE_MODE_BODY_COLOR:
                MachineCreate_UpdateColorSelectAInput(&gCustomMachine.red, &gCustomMachine.green, &gCustomMachine.blue);
                break;
            case MACHINE_MODE_LINE_COLOR:
                MachineCreate_UpdateColorSelectAInput(&gCustomMachine.decalR, &gCustomMachine.decalG,
                                                      &gCustomMachine.decalB);
                break;
            case MACHINE_MODE_NUMBER_COLOR:
                MachineCreate_UpdateColorSelectAInput(&gCustomMachine.numberR, &gCustomMachine.numberG,
                                                      &gCustomMachine.numberB);
                break;
            case MACHINE_MODE_COCKPIT_COLOR:
                MachineCreate_UpdateColorSelectAInput(&gCustomMachine.cockpitR, &gCustomMachine.cockpitG,
                                                      &gCustomMachine.cockpitB);
                break;
            case MACHINE_MODE_LOAD_SELECT_FILE:
                Audio_TriggerSystemSE(NA_SE_36);
                if (EKFileMenu_GetFileIndex() == 0) {
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    func_xk1_8002FFDC();
                    gCustomMachineIsSuper = false;
                } else if ((gMachineCreateSuperMachinesCount != 0) && (EKFileMenu_GetFileIndex() == 1)) {
                    PRINTF("WORKS MACHINE MODE : LOAD_SELECT_SUPER\n");
                    gWorksMachineMode = MACHINE_MODE_LOAD_SELECT_SUPER;
                    MachineCreate_FileSuperMachineListSetup();
                    MachineCreate_InitFileMenu();
                } else {
                    PRINTF("WORKS MACHINE MODE : LOAD_CONFIRM\n");
                    gWorksMachineMode = MACHINE_MODE_LOAD_CONFIRM;
                    gMachineCreateSelectedFileName = EKFileMenu_GetFileNameForDisplay();
                }
                break;
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_FILE:
                if ((gMachineCreateSuperMachinesCount != 0) && (EKFileMenu_GetFileIndex() == 0)) {
                    Audio_TriggerSystemSE(NA_SE_36);
                    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_SUPER\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER;
                    MachineCreate_FileListClearSuperSetup();
                } else {
                    gMachineCreateSelectedFileName = EKFileMenu_GetFileNameForDisplay();
                    Audio_TriggerSystemSE(NA_SE_36);
                    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_CONFIRM\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_CONFIRM;
                }
                break;
            case MACHINE_MODE_ENTRY_CLEAR_CONFIRM: {
                u8 i;
                Audio_TriggerSystemSE(NA_SE_39);
                if (mfsStrCmp(gMachineCreateSelectedFileName, &gCustomMachine.machineName) == 0) {
                    gCustomMachine.number = 31;
                }
                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] > 0) &&
                        (mfsStrCmp(&gCustomMachinesInfo.customMachines[i].machineName,
                                   gMachineCreateSelectedFileName) == 0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 0;
                        gCustomMachinesInfo.customMachines[i].number = 31;
                        func_8008D33C();
                        break;
                    }
                }
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            }
            case MACHINE_MODE_ENTRY_CLEAR_SELECT_SUPER:
                gMachineCreateSelectedFileName = EKFileMenu_GetFileNameForDisplay();
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SUPER_CONFIRM\n");
                gWorksMachineMode = MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM;
                break;
            case MACHINE_MODE_ENTRY_CLEAR_SUPER_CONFIRM: {
                u8 i;
                Audio_TriggerSystemSE(NA_SE_39);

                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] == -1) &&
                        (mfsStrCmp(gMachineCreateSelectedFileName, gSuperMachineNames[i]) == 0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 0;
                        gCustomMachinesInfo.customMachines[i].number = 31;
                        func_8008D33C();
                        break;
                    }
                }

                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                break;
            }
            case MACHINE_MODE_ENTRY_SELECT_FILE:
                Audio_TriggerSystemSE(NA_SE_36);
                if ((gMachineCreateSuperMachinesCount != 0) && (EKFileMenu_GetFileIndex() == 0)) {
                    PRINTF("WORKS MACHINE MODE : ENTRY_SELECT_SUPER\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_SELECT_SUPER;
                    MachineCreate_FileSuperMachineListSetup();
                } else {
                    gMachineCreateSelectedFileName = EKFileMenu_GetFileNameForDisplay();
                    PRINTF("WORKS MACHINE MODE : ENTRY_LOAD_NOW\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY_LOAD_NOW;
                    func_80768638(MFS_ENTRY_WORKING_DIR, gMachineCreateSelectedFileName, "CARD", &gCustomMachineWork,
                                  sizeof(CustomMachine));
                    PRINTF("SUPER MACHINE No.%d\n");
                }
                break;
            case MACHINE_MODE_LOAD_SELECT_SUPER:
            case MACHINE_MODE_ENTRY_SELECT_SUPER: {
                u8 i;
                if (gWorksMachineMode == MACHINE_MODE_ENTRY_SELECT_SUPER) {
                    gCustomMachineCurrentSuperIndexBackup = gCustomMachineCurrentSuperIndex;
                }
                Audio_TriggerSystemSE(NA_SE_36);
                gMachineCreateSelectedFileName = EKFileMenu_GetFileNameForDisplay();

                for (i = 0; i < 30; i++) {
                    if (mfsStrCmp(gMachineCreateSelectedFileName, gSuperMachineNames[i]) == 0) {
                        gCustomMachineCurrentSuperIndex = i;
                        break;
                    }
                }

                if (gWorksMachineMode == MACHINE_MODE_ENTRY_SELECT_SUPER) {
                    gCustomMachineBackup = gCustomMachine;
                    sCustomMachineIsSuperBackup = gCustomMachineIsSuper;
                    gCustomMachineIsSuper = true;
                    PRINTF("WORKS MACHINE MODE : ENTRY\n");
                    gWorksMachineMode = MACHINE_MODE_ENTRY;
                    MachineCreate_MachineSelectInit();
                } else {
                    gCustomMachineIsSuper = true;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                }
                break;
            }
            case MACHINE_MODE_DELETE_SELECT_FILE:
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : DELETE_CONFIRM\n");
                gWorksMachineMode = MACHINE_MODE_DELETE_CONFIRM;
                gMachineCreateSelectedFileName = EKFileMenu_GetFileNameForDisplay();
                break;
            case MACHINE_MODE_LOAD_CONFIRM:
                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : LOAD_NOW\n");
                gWorksMachineMode = MACHINE_MODE_LOAD_NOW;
                func_80768574(MFS_ENTRY_WORKING_DIR, gMachineCreateSelectedFileName, "CARD", &gCustomMachineWork,
                              sizeof(CustomMachine));
                break;
            case MACHINE_MODE_DELETE_CONFIRM:
            case MACHINE_MODE_CHECKSUM_ERROR: {
                u8 i;
                if (mfsStrCmp(gMachineCreateSelectedFileName, &gCustomMachine.machineName) == 0) {
                    gCustomMachine.number = 31;
                }

                for (i = 0; i < 30; i++) {
                    if ((gCustomMachinesInfo.characterCustomState[i] > 0) &&
                        (mfsStrCmp(gCustomMachinesInfo.customMachines[i].machineName, gMachineCreateSelectedFileName) ==
                         0)) {
                        gCustomMachinesInfo.characterCustomState[i] = 0;
                        gCustomMachinesInfo.customMachines[i].number = 31;
                        func_8008D33C();
                        break;
                    }
                }

                Audio_TriggerSystemSE(NA_SE_36);
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                func_807688D0(MFS_ENTRY_WORKING_DIR, gMachineCreateSelectedFileName, "CARD", true);
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

void MachineCreate_UpdateMachineNumber(void) {
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

void MachineCreate_UpdateFileMode(void) {
    u16 checksum;
    u8 i;

    switch (gWorksMachineMode) {
        case MACHINE_MODE_LOAD_NOW:
        case MACHINE_MODE_ENTRY_LOAD_NOW:
            checksum = MachineCreate_CalculateCustomMachineChecksum(&gCustomMachineWork);
            if ((gCustomMachineWork.checksum != checksum) || (checksum == 0) ||
                (MachineCreate_CustomMachineStatsIsValid(&gCustomMachineWork))) {
                D_807C6EA8.unk_08 = 21;
                PRINTF("WORKS MACHINE MODE : CHECKSUM_ERROR\n");
                gWorksMachineMode = MACHINE_MODE_CHECKSUM_ERROR;
            } else if (gWorksMachineMode == MACHINE_MODE_ENTRY_LOAD_NOW) {
                gCustomMachineBackup = gCustomMachine;
                sCustomMachineIsSuperBackup = gCustomMachineIsSuper;
                gCustomMachineCurrentSuperIndexBackup = gCustomMachineCurrentSuperIndex;
                gCustomMachineIsSuper = false;
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
                MachineCreate_MachineSelectInit();
            } else {
                gCustomMachine = gCustomMachineWork;
                MachineCreate_UpdateMachineNumber();
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
                gCustomMachineIsSuper = false;
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
            MachineCreate_InitFileMenu();
            break;
        case MACHINE_MODE_DELETE_GET_FILE:
            if (D_807C6F0C == 0) {
                PRINTF("WORKS MACHINE MODE : 0\n");
                gWorksMachineMode = MACHINE_MODE_0;
            } else {
                PRINTF("WORKS MACHINE MODE : DELETE_SELECT_FILE\n");
                gWorksMachineMode = MACHINE_MODE_DELETE_SELECT_FILE;
                MachineCreate_InitFileMenu();
            }
            break;
        case MACHINE_MODE_SAVE_FILE_EXIST:
            if (D_80794E20 == 1) {
                D_807C6EA8.unk_08 = 18;
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
                D_807C6EA8.unk_08 = 19;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
            } else {
                MachineCreate_SaveMachine();
            }
            break;
        case MACHINE_MODE_OVERWRITE_GET_FILE:
            if (D_807C6F0C == 100) {
                PRINTF("WORKS MACHINE MODE : OVERWRITE_FILE_EXIST\n");
                gWorksMachineMode = MACHINE_MODE_OVERWRITE_FILE_EXIST;
                func_8076870C(MFS_ENTRY_WORKING_DIR, gCustomMachine.machineName, "CARD");
            } else if (D_807C6F0C > 100) {
                D_807C6EA8.unk_08 = 19;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
            } else {
                MachineCreate_SaveMachine();
            }
            break;
        case MACHINE_MODE_OVERWRITE_FILE_EXIST:
            if (D_80794E20 == 1) {
                MachineCreate_SaveMachine();
            } else {
                D_807C6EA8.unk_08 = 19;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                gWorksMachineMode = MACHINE_MODE_MESSAGE_BUTTON;
            }
            break;
        default:
            break;
    }
}

s32 sMachineCreatePartWeights[][7] = {
    { 270, 290, 320, 350, 420, 580, 630 },  // MACHINE_PART_FRONT
    { 510, 560, 630, 720, 890, 930, 1170 }, // MACHINE_PART_REAR
    { 0, 100, 120, 140, 190, 250, 420 },    // MACHINE_PART_WING
};

void MachineCreate_UpdateTransition(void) {

    if (gWorksMachineMode == MACHINE_MODE_ENTRY) {
        return;
    }
    if ((gWorksMachineMode == MACHINE_MODE_PARTS) && (gMachineCreatePartsLightSourceX < 7000.0f)) {
        gMachineCreatePartsLightSourceX += 300.0f;
    }
    if ((sMachineCreateOptionIndex == 5) && !gMachineCreateModeShowInstructions) {
        gMachineCreateHighlightExit = true;
    } else {
        gMachineCreateHighlightExit = false;
    }
    if (gCustomMachineIsSuper) {
        return;
    }
    gMachineCreateMachineWeight = sMachineCreatePartWeights[MACHINE_PART_FRONT][gCustomMachine.frontType] +
                                  sMachineCreatePartWeights[MACHINE_PART_REAR][gCustomMachine.rearType] +
                                  sMachineCreatePartWeights[MACHINE_PART_WING][gCustomMachine.wingType];
    switch (gWorksMachineMode) {
        case MACHINE_MODE_SELECT_LINE:
            gCustomMachine.decal = MACHINE_DECAL((gMachineCreateCursorPosY - 52) / 16);
            break;
        case MACHINE_MODE_SELECT_MARK:
            gCustomMachine.logo = MACHINE_LOGO((gMachineCreateCursorPosY - 52) / 16);
            break;
    }
    if ((gWorksMachineMode == MACHINE_MODE_SETTING) &&
        (BorderedBox_GetInfo(gMachineCreateStatsBox, IS_BORDERED_BOX_OPENED))) {
        D_807C6EA8.unk_08 = 0;
    }
    switch (gWorksMachineMode) {
        case MACHINE_MODE_PARTS:
            if ((gMachineCreatePartsGrid.y == 3) && (sMachineCreateTransitionTimer >= 0)) {
                if (sMachineCreateTransitionTimer == 0) {
                    sMachineCreateTransitionTimer = -1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    Audio_TriggerSystemSE(NA_SE_36);
                } else {
                    sMachineCreateTransitionTimer--;
                }
            } else {
                sMachineCreateTransitionTimer = -1;
            }
            break;
        case MACHINE_MODE_SETTING:
            if ((gMachineCreateMachineSettingsGrid.y == 3) && (sMachineCreateTransitionTimer >= 0)) {
                if (sMachineCreateTransitionTimer == 0) {
                    sMachineCreateTransitionTimer = -1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    gWorksMachineMode = MACHINE_MODE_0;
                    Audio_TriggerSystemSE(NA_SE_36);
                    BorderedBox_StartClose(gMachineCreateStatsBox);
                } else {
                    sMachineCreateTransitionTimer -= 1;
                }
            } else {
                sMachineCreateTransitionTimer = -1;
            }
            break;
        case MACHINE_MODE_BODY_COLOR:
        case MACHINE_MODE_LINE_COLOR:
        case MACHINE_MODE_NUMBER_COLOR:
        case MACHINE_MODE_COCKPIT_COLOR:
            if ((gMachineCreateColorGrid.y == 8) && (sMachineCreateTransitionTimer >= 0)) {
                if (sMachineCreateTransitionTimer == 0) {
                    sMachineCreateTransitionTimer = -1;
                    MachineCreate_CloseColorMenu();
                    Audio_TriggerSystemSE(NA_SE_36);
                } else {
                    sMachineCreateTransitionTimer -= 1;
                }
            } else {
                sMachineCreateTransitionTimer = -1;
            }
            break;
        default:
            sMachineCreateTransitionTimer = -1;
            break;
    }
}

extern s32 gTransitionState;
extern volatile u8 D_80794E14;

bool MachineCreate_MenuUpdate(void) {

    func_xk1_800260E4();
    if (gWorksMachineMode == MACHINE_MODE_SAVE_FILE_EXIST_BEFORE) {
        PRINTF("WORKS MACHINE MODE : SAVE_FILE_EXIST\n");
        gWorksMachineMode = MACHINE_MODE_SAVE_FILE_EXIST;
        func_8076869C(MFS_ENTRY_WORKING_DIR, gCustomMachine.machineName, "CARD");
    }
    EKController_UpdateHeldInput();
    if ((D_80794E14 == 0) && (gTransitionState == TRANSITION_INACTIVE) && !gMachineCreateModeShowInstructions) {
        MachineCreate_UpdateCursor();
    }
    if (gWorksMachineMode != MACHINE_MODE_PARTS) {
        MachineCreate_UpdateViewZoom();
        MachineCreate_UpdateViewTranslation();
        MachineCreate_UpdateView();
    }
    MachineCreate_UpdateMachineRotation();
    if (gWorksMachineMode != MACHINE_MODE_MNAME) {
        if (gTransitionState == TRANSITION_INACTIVE) {
            MachineCreate_UpdateStartInput();
        }
        if ((D_80794E14 == 0) && (gTransitionState == TRANSITION_INACTIVE) && !gMachineCreateModeShowInstructions &&
            (!(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) ||
             !(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B))) {
            MachineCreate_UpdateBInput();
            MachineCreate_UpdateAInput();
        }
    } else {
        ExpansionKit_NameEntryUpdate(NULL, NULL);
    }
    if (D_80794E14 == 0) {
        MachineCreate_UpdateFileMode();
        MachineCreate_UpdateTransition();
    }
    if (gMachineCreateHighlightExit && (D_80794E14 == 0) && !gMachineCreateModeShowInstructions &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        return true;
    }
    return false;
}
