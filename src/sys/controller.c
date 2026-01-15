#include "global.h"

OSContStatus gControllerStatus[MAXCONTROLLERS];
OSContPad gControllerPads[MAXCONTROLLERS];
Controller gControllers[MAXCONTROLLERS + 1];
Controller gSharedController;
s32 gPlayerControlPorts[MAXCONTROLLERS];
s32 gControllersConnected;

s32 D_800CD160 = 15;
s32 D_800CD164 = 5;
s16 gControllerReadDataStarted = false;
s16 D_800CD16C = false;

void Controller_Reset(void) {
    s32 i;

    if (gControllerReadDataStarted) {
        Controller_UpdateInputs();
        gControllerReadDataStarted = false;
    }

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (osMotorStop(&gControllers[i].pfs) == 0) {
            gControllers[i].unk_74 = 1;
        } else {
            gControllers[i].unk_74 = 0;
        }
        gControllers[i].unk_72 = gControllers[i].unk_76 = 0;
    }
}

void Controller_ClearInputs(void) {
    Controller* controller;

    // clang-format off
    controller = &gControllers[4];\
    do {
        if (controller->errno == 0) {
            controller->retriggerCurrentButtonPress = controller->buttonCurrent = controller->buttonPressed = controller->buttonReleased = controller->buttonPrev = 0;
            controller->stickX = controller->stickY = controller->stickCurrent = controller->stickPressed = controller->stickReleased = controller->stickPrev = 0;
            controller->sameInputsHeldCounter = 0;
        }
        controller--;
    } while (controller >= gControllers);
    // clang-format on

    gSharedController.retriggerCurrentButtonPress = gSharedController.buttonCurrent = gSharedController.buttonPressed =
        gSharedController.buttonReleased = 0;
    gSharedController.stickX = gSharedController.stickY = gSharedController.stickCurrent =
        gSharedController.stickPressed = gSharedController.stickReleased = 0;
}

extern OSMesgQueue gSerialEventQueue;
extern s32 D_800CCFB0;
extern bool gResetStarted;
extern OSMesg D_800E12B0;

void Controller_UpdateInputs(void) {
    s32 i;
    s32 j;
    u16 buttonDiff;
    s32 sharedStickX;
    s32 sharedStickY;
    s32 connectedControllerCount;
    s32 pad[2];
    Controller* controller;
    OSContPad* contPad;

    gSharedController.retriggerCurrentButtonPress = gSharedController.buttonCurrent = gSharedController.buttonPressed =
        gSharedController.buttonReleased = 0;
    connectedControllerCount = 0;
    sharedStickX = sharedStickY = 0;
    gSharedController.stickCurrent = gSharedController.stickPressed = gSharedController.stickReleased = 0;

    controller = &gControllers[4];
    i = 4;
    //! @bug OOB array access, no reads are done before going back in bounds
    contPad = &gControllerPads[4];

    osRecvMesg(&gSerialEventQueue, &D_800E12B0, OS_MESG_BLOCK);
    osContGetReadData(gControllerPads);
    do {
        controller--;
        contPad--;
        i--;

        if (controller->errno == 0) {
            if ((controller->errno = contPad->errno) != 0) {
                gControllersConnected--;

                for (j = 3; j >= 0; j--) {
                    if (i == gPlayerControlPorts[j]) {
                        gPlayerControlPorts[j] = PORT_DISCONNECTED;
                        break;
                    }
                }
            } else {
                connectedControllerCount++;
                controller->buttonPrev = controller->buttonCurrent;
                gSharedController.buttonCurrent |= controller->buttonCurrent = contPad->button & CONT_MASK;

                buttonDiff = (controller->buttonPrev ^ controller->buttonCurrent);

                gSharedController.buttonPressed |= controller->buttonPressed = buttonDiff & controller->buttonCurrent;
                gSharedController.buttonReleased |= controller->buttonReleased = buttonDiff & controller->buttonPrev;

                sharedStickX += controller->stickX = contPad->stick_x;
                sharedStickY += controller->stickY = contPad->stick_y;

                controller->stickPrev = controller->stickCurrent;

                if (controller->stickX < -50) {
                    controller->stickCurrent = STICK_LEFT;
                } else if (controller->stickX > 50) {
                    controller->stickCurrent = STICK_RIGHT;
                } else {
                    controller->stickCurrent = 0;
                }

                if (controller->stickY < -50) {
                    controller->stickCurrent |= STICK_DOWN;
                } else if (controller->stickY > 50) {
                    controller->stickCurrent |= STICK_UP;
                }

                gSharedController.stickCurrent |= controller->stickCurrent;

                buttonDiff = (controller->stickPrev ^ controller->stickCurrent);

                gSharedController.stickPressed |= controller->stickPressed = buttonDiff & controller->stickCurrent;
                gSharedController.stickReleased |= controller->stickReleased = buttonDiff & controller->stickPrev;

                controller->retriggerCurrentButtonPress = false;
                if (((controller->buttonCurrent != 0) || (controller->stickCurrent != 0)) &&
                    (controller->buttonPrev == controller->buttonCurrent) &&
                    (controller->stickPrev == controller->stickCurrent)) {
                    controller->sameInputsHeldCounter++;
                    if ((controller->sameInputsHeldCounter >= D_800CD160) &&
                        (((controller->sameInputsHeldCounter - D_800CD160) % D_800CD164) == 0)) {
                        controller->retriggerCurrentButtonPress = true;
                    }
                } else {
                    controller->sameInputsHeldCounter = 0;
                }
                gSharedController.retriggerCurrentButtonPress |= controller->retriggerCurrentButtonPress;
                if (controller->unk_78 != 0) {
                    if (osMotorInit(&gSerialEventQueue, &controller->pfs, i) == 0) {
                        osMotorStop(&controller->pfs);
                        controller->unk_74 = 1;
                    } else {
                        controller->unk_74 = 0;
                    }
                    controller->unk_88 = controller->unk_8C = controller->unk_90 = 0;
                    controller->unk_78 = controller->unk_76 = 0;
                } else if ((controller->unk_72 == 0) || gResetStarted) {
                    if ((controller->unk_74 == 1) && ((controller->unk_76 == 1) || !(((i << 5) + D_800CCFB0) & 0x7F))) {
                        if (osMotorStop(&controller->pfs) == 0) {
                            controller->unk_76 = 0;
                        } else {
                            controller->unk_74 = 0;
                        }
                    }
                } else if (controller->unk_74 == 1) {
                    controller->unk_88 += controller->unk_8C;
                    controller->unk_8C -= controller->unk_90;
                    if (controller->unk_8C < 0) {
                        controller->unk_8C = 0;
                    }

                    if (controller->unk_88 >= 1000) {
                        controller->unk_88 -= 1000;
                        if (controller->unk_76 == 0) {
                            if (osMotorStart(&controller->pfs) == 0) {
                                controller->unk_76 = 1;
                            } else {
                                controller->unk_74 = 0;
                            }
                        }
                    } else {
                        if (controller->unk_76 == 1) {
                            if (osMotorStop(&controller->pfs) == 0) {
                                controller->unk_76 = 0;
                            } else {
                                controller->unk_74 = 0;
                            }
                        }
                    }
                }
            }
        }
    } while (controller != gControllers);

    if (connectedControllerCount != 0) {
        gSharedController.stickX = sharedStickX / connectedControllerCount;

        gSharedController.stickY = sharedStickY / connectedControllerCount;
    }
}

void Controller_Init(void) {
    s32 i;
    u8 sp53;

    osContInit(&gSerialEventQueue, &sp53, gControllerStatus);
    gControllersConnected = 0;

    for (i = 0; i < MAXCONTROLLERS; i++) {

        gControllers[i].errno = gControllerStatus[i].errno;
        gControllers[i].unk_72 = gControllers[i].unk_74 = gControllers[i].unk_76 = gControllers[i].unk_78 = 0;
        gControllers[i].unk_88 = gControllers[i].unk_8C = gControllers[i].unk_90 = 0;
        if (gControllerStatus[i].errno == 0) {
            gPlayerControlPorts[gControllersConnected] = i;
            gControllersConnected++;
            if (osMotorInit(&gSerialEventQueue, &gControllers[i].pfs, i) == 0) {
                osMotorStop(&gControllers[i].pfs);
                gControllers[i].unk_74 = 1;
            }
        }
    }

    for (i = gControllersConnected; i < 4; i++) {
        gPlayerControlPorts[i] = PORT_DISCONNECTED;
    }

    Controller_ClearInputs();
}
