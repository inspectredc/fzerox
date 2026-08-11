#include "global.h"

Controller* sExpansionKitController;

s32 sInputDeadZone = 12;
s32 sInitialInputRepeatDelay = 9;
s32 sInputRepeatInterval = 2;
s32 sInputFramesHeld = 0;

extern u16 gRetriggeredButtonCurrentPressed;
extern u16 gInputButtonPressed;
extern u16 gInputPressed;

void EKController_SetGlobalInputs(Controller* controller) {
    gInputButtonPressed = STICK_TO_BUTTON(controller->stickPressed);
    if (controller->retriggerCurrentButtonPress) {
        gRetriggeredButtonCurrentPressed = STICK_TO_BUTTON(controller->stickCurrent);
    } else {
        gRetriggeredButtonCurrentPressed = 0;
    }
    gInputPressed = gInputButtonPressed | gRetriggeredButtonCurrentPressed;
}

void EKController_SetRepeatDelay(s32 delay, s32 interval) {
    sInitialInputRepeatDelay = delay;
    sInputRepeatInterval = interval;
}

void EKController_SetDeadZone(s32 deadZone) {
    sInputDeadZone = deadZone;
}

void EKController_UpdateHorizontalOptionNoRepeat(s32* optionIndex, s32 maxIndex, s32 wrapMode) {

    if (gInputPressed & BTN_LEFT) {
        (*optionIndex)--;
        if (wrapMode == 1) {
            if (*optionIndex < 0) {
                *optionIndex = maxIndex;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = 0;
            }
        } else {
            if (*optionIndex < 0) {
                *optionIndex = 0;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = maxIndex;
            }
        }
    }
    if (gInputPressed & BTN_RIGHT) {
        (*optionIndex)++;
        if (wrapMode == 1) {
            if (*optionIndex < 0) {
                *optionIndex = maxIndex;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = 0;
            }
        } else {
            if (*optionIndex < 0) {
                *optionIndex = 0;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = maxIndex;
            }
        }
    }
}

void EKController_UpdateHeldInput(void) {
    static s32 sLastStickX = 0;
    static s32 sLastStickY = 0;

    sExpansionKitController = &gControllers[gPlayerControlPorts[0]];

    if (ABS(sExpansionKitController->stickX) > sInputDeadZone ||
        ABS(sExpansionKitController->stickY) > sInputDeadZone) {
        sInputFramesHeld++;
        // Changed X Direction
        if ((sExpansionKitController->stickX * sLastStickX) < 0) {
            if (sInputDeadZone < ABS(sLastStickX)) {
                sInputFramesHeld = 0;
            }
        }
        // Changed Y Direction
        if ((sExpansionKitController->stickY * sLastStickY) < 0) {
            if (sInputDeadZone < ABS(sLastStickY)) {
                sInputFramesHeld = 0;
            }
        }
    } else {
        sInputFramesHeld = 0;
    }

    if (sInputFramesHeld >= (sInitialInputRepeatDelay + sInputRepeatInterval)) {
        sInputFramesHeld = sInitialInputRepeatDelay - 1;
    }
    sLastStickX = sExpansionKitController->stickX;
    sLastStickY = sExpansionKitController->stickY;
}

s32 EKController_GetInputFramesHeld(void) {
    return sInputFramesHeld;
}

void EKController_UpdateHorizontalOption(s32* optionIndex, s32 maxIndex, s32 wrapMode) {
    s32 direction;
    s32 stickX;

    sExpansionKitController = &gControllers[gPlayerControlPorts[0]];

    direction = 0;
    stickX = sExpansionKitController->stickX;
    if (sInputDeadZone < stickX) {
        direction = 1;
    } else if (stickX < -sInputDeadZone) {
        direction = -1;
    }
    if (((sInputFramesHeld == 1) || (sInputFramesHeld == sInitialInputRepeatDelay)) && (optionIndex != NULL)) {
        *optionIndex += direction;
        if (wrapMode == 1) {
            if (*optionIndex < 0) {
                *optionIndex = maxIndex;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = 0;
            }
        } else {
            if (*optionIndex < 0) {
                *optionIndex = 0;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = maxIndex;
            }
        }
    }
}

void EKController_UpdateVerticalOptionSlow(s32* optionIndex, s32 maxIndex, s32 wrapMode) {
    s32 direction;
    s32 stickY;

    sExpansionKitController = &gControllers[gPlayerControlPorts[0]];

    direction = 0;
    stickY = sExpansionKitController->stickY;
    if (sInputDeadZone < stickY) {
        direction = -1;
    } else if (stickY < -sInputDeadZone) {
        direction = 1;
    }
    if (((sInputFramesHeld == 1) || (sInputFramesHeld == sInitialInputRepeatDelay)) && (optionIndex != NULL)) {
        *optionIndex += direction;
        if (wrapMode == 1) {
            if (*optionIndex < 0) {
                *optionIndex = maxIndex;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = 0;
            }
        } else {
            if (*optionIndex < 0) {
                *optionIndex = 0;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = maxIndex;
            }
        }
    }
}

void EKController_UpdateVerticalOptionFast(s32* optionIndex, s32 maxIndex, s32 wrapMode) {
    s32 direction;
    s32 stickY;

    sExpansionKitController = &gControllers[gPlayerControlPorts[0]];

    direction = 0;
    stickY = sExpansionKitController->stickY;
    if (sInputDeadZone < stickY) {
        direction = -1;
    } else if (stickY < -sInputDeadZone) {
        direction = 1;
    }
    if (((sInputFramesHeld == 1) || (sInputFramesHeld >= sInitialInputRepeatDelay - 1)) && (optionIndex != NULL)) {
        *optionIndex += direction;
        if (wrapMode == 1) {
            if (*optionIndex < 0) {
                *optionIndex = maxIndex;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = 0;
            }
        } else {
            if (*optionIndex < 0) {
                *optionIndex = 0;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = maxIndex;
            }
        }
    }
}

void EKController_UpdateVerticalOptionStaggered(s32* optionIndex, s32 maxIndex, s32 wrapMode) {
    s32 direction;
    s32 stickY;

    sExpansionKitController = &gControllers[gPlayerControlPorts[0]];

    direction = 0;
    stickY = sExpansionKitController->stickY;
    if (sInputDeadZone < stickY) {
        direction = -1;
    } else if (stickY < -sInputDeadZone) {
        direction = 1;
    }
    if (((sInputFramesHeld == 1) || (sInputFramesHeld == sInitialInputRepeatDelay) ||
         (sInputFramesHeld == sInitialInputRepeatDelay + 3)) &&
        (optionIndex != NULL)) {
        *optionIndex += direction;
        if (wrapMode == 1) {
            if (*optionIndex < 0) {
                *optionIndex = maxIndex;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = 0;
            }
        } else {
            if (*optionIndex < 0) {
                *optionIndex = 0;
            }
            if (maxIndex < *optionIndex) {
                *optionIndex = maxIndex;
            }
        }
    }
}
