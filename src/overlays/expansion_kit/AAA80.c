#include "global.h"

Controller* D_xk1_8003BB50;

s32 D_xk1_80032C80 = 12;
s32 D_xk1_80032C84 = 9;
s32 D_xk1_80032C88 = 2;
s32 D_xk1_80032C8C = 0;

extern u16 gRetriggeredButtonCurrentPressed;
extern u16 gInputButtonPressed;
extern u16 gInputPressed;

void func_xk1_8002D810(Controller* controller) {
    gInputButtonPressed = STICK_TO_BUTTON(controller->stickPressed);
    if (controller->retriggerCurrentButtonPress) {
        gRetriggeredButtonCurrentPressed = STICK_TO_BUTTON(controller->stickCurrent);
    } else {
        gRetriggeredButtonCurrentPressed = 0;
    }
    gInputPressed = gInputButtonPressed | gRetriggeredButtonCurrentPressed;
}

void func_xk1_8002D86C(s32 arg0, s32 arg1) {
    D_xk1_80032C84 = arg0;
    D_xk1_80032C88 = arg1;
}

void func_xk1_8002D880(s32 arg0) {
    D_xk1_80032C80 = arg0;
}

void func_xk1_8002D88C(s32* arg0, s32 arg1, s32 arg2) {

    if (gInputPressed & BTN_LEFT) {
        (*arg0)--;
        if (arg2 == 1) {
            if (*arg0 < 0) {
                *arg0 = arg1;
            }
            if (arg1 < *arg0) {
                *arg0 = 0;
            }
        } else {
            if (*arg0 < 0) {
                *arg0 = 0;
            }
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        }
    }
    if (gInputPressed & BTN_RIGHT) {
        (*arg0)++;
        if (arg2 == 1) {
            if (*arg0 < 0) {
                *arg0 = arg1;
            }
            if (arg1 < *arg0) {
                *arg0 = 0;
            }
        } else {
            if (*arg0 < 0) {
                *arg0 = 0;
            }
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        }
    }
}

void func_xk1_8002D974(void) {
    static s32 sLastStickX = 0;
    static s32 sLastStickY = 0;

    D_xk1_8003BB50 = &gControllers[gPlayerControlPorts[0]];

    if (ABS(D_xk1_8003BB50->stickX) > D_xk1_80032C80 || ABS(D_xk1_8003BB50->stickY) > D_xk1_80032C80) {
        D_xk1_80032C8C++;
        // Changed X Direction
        if ((D_xk1_8003BB50->stickX * sLastStickX) < 0) {
            if (D_xk1_80032C80 < ABS(sLastStickX)) {
                D_xk1_80032C8C = 0;
            }
        }
        // Changed Y Direction
        if ((D_xk1_8003BB50->stickY * sLastStickY) < 0) {
            if (D_xk1_80032C80 < ABS(sLastStickY)) {
                D_xk1_80032C8C = 0;
            }
        }
    } else {
        D_xk1_80032C8C = 0;
    }

    if (D_xk1_80032C8C >= (D_xk1_80032C84 + D_xk1_80032C88)) {
        D_xk1_80032C8C = D_xk1_80032C84 - 1;
    }
    sLastStickX = D_xk1_8003BB50->stickX;
    sLastStickY = D_xk1_8003BB50->stickY;
}

s32 func_xk1_8002DAD4(void) {
    return D_xk1_80032C8C;
}

void func_xk1_8002DAE0(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 stickX;

    D_xk1_8003BB50 = &gControllers[gPlayerControlPorts[0]];

    var_v0 = 0;
    stickX = D_xk1_8003BB50->stickX;
    if (D_xk1_80032C80 < stickX) {
        var_v0 = 1;
    } else if (stickX < -D_xk1_80032C80) {
        var_v0 = -1;
    }
    if (((D_xk1_80032C8C == 1) || (D_xk1_80032C8C == D_xk1_80032C84)) && (arg0 != NULL)) {
        *arg0 += var_v0;
        if (arg2 == 1) {
            if (*arg0 < 0) {
                *arg0 = arg1;
            }
            if (arg1 < *arg0) {
                *arg0 = 0;
            }
        } else {
            if (*arg0 < 0) {
                *arg0 = 0;
            }
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        }
    }
}

void func_xk1_8002DBD4(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 stickY;

    D_xk1_8003BB50 = &gControllers[gPlayerControlPorts[0]];

    var_v0 = 0;
    stickY = D_xk1_8003BB50->stickY;
    if (D_xk1_80032C80 < stickY) {
        var_v0 = -1;
    } else if (stickY < -D_xk1_80032C80) {
        var_v0 = 1;
    }
    if (((D_xk1_80032C8C == 1) || (D_xk1_80032C8C == D_xk1_80032C84)) && (arg0 != NULL)) {
        *arg0 += var_v0;
        if (arg2 == 1) {
            if (*arg0 < 0) {
                *arg0 = arg1;
            }
            if (arg1 < *arg0) {
                *arg0 = 0;
            }
        } else {
            if (*arg0 < 0) {
                *arg0 = 0;
            }
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        }
    }
}

void func_xk1_8002DCC8(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 stickY;

    D_xk1_8003BB50 = &gControllers[gPlayerControlPorts[0]];

    var_v0 = 0;
    stickY = D_xk1_8003BB50->stickY;
    if (D_xk1_80032C80 < stickY) {
        var_v0 = -1;
    } else if (stickY < -D_xk1_80032C80) {
        var_v0 = 1;
    }
    if (((D_xk1_80032C8C == 1) || (D_xk1_80032C8C >= D_xk1_80032C84 - 1)) && (arg0 != NULL)) {
        *arg0 += var_v0;
        if (arg2 == 1) {
            if (*arg0 < 0) {
                *arg0 = arg1;
            }
            if (arg1 < *arg0) {
                *arg0 = 0;
            }
        } else {
            if (*arg0 < 0) {
                *arg0 = 0;
            }
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        }
    }
}

void func_xk1_8002DDC4(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;
    s32 stickY;

    D_xk1_8003BB50 = &gControllers[gPlayerControlPorts[0]];

    var_v0 = 0;
    stickY = D_xk1_8003BB50->stickY;
    if (D_xk1_80032C80 < stickY) {
        var_v0 = -1;
    } else if (stickY < -D_xk1_80032C80) {
        var_v0 = 1;
    }
    if (((D_xk1_80032C8C == 1) || (D_xk1_80032C8C == D_xk1_80032C84) || (D_xk1_80032C8C == D_xk1_80032C84 + 3)) &&
        (arg0 != NULL)) {
        *arg0 += var_v0;
        if (arg2 == 1) {
            if (*arg0 < 0) {
                *arg0 = arg1;
            }
            if (arg1 < *arg0) {
                *arg0 = 0;
            }
        } else {
            if (*arg0 < 0) {
                *arg0 = 0;
            }
            if (arg1 < *arg0) {
                *arg0 = arg1;
            }
        }
    }
}
