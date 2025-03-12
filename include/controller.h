

#ifndef CONTROLLER
#define CONTROLLER

#include "PR/os_cont.h"

#define BTN_A CONT_A          // 0x8000
#define BTN_B CONT_B          // 0x4000
#define BTN_L CONT_L          // 0x20
#define BTN_R CONT_R          // 0x10
#define BTN_Z CONT_G          // 0x2000
#define BTN_START CONT_START  // 0x1000
#define BTN_UP CONT_UP        // 0x800
#define BTN_DOWN CONT_DOWN    // 0x400
#define BTN_LEFT CONT_LEFT    // 0x200
#define BTN_RIGHT CONT_RIGHT  // 0x100
#define BTN_CUP CONT_E        // 0x8
#define BTN_CDOWN CONT_D      // 0x4
#define BTN_CLEFT CONT_C      // 0x2
#define BTN_CRIGHT CONT_F     // 0x1

#define CONT_MASK (CONT_A | CONT_B | CONT_G | CONT_START | CONT_UP | CONT_DOWN | CONT_LEFT | CONT_RIGHT | CONT_L | CONT_R | CONT_E | CONT_D | CONT_C | CONT_F)

#define BTN_R_Z_COMBO 0x80    // 0x80 - Hold R Press Z
#define BTN_Z_R_COMBO 0x40    // 0x40 - Hold Z Press R

#define STICK_UP 0x80
#define STICK_DOWN 0x40
#define STICK_LEFT 0x20
#define STICK_RIGHT 0x10

#define STICK_TO_BUTTON(input) ((input) << 4)

typedef enum ControllerPort {
    /* 0 */ PORT_1,
    /* 1 */ PORT_2,
    /* 2 */ PORT_3,
    /* 3 */ PORT_4,
    /* 4 */ PORT_DISCONNECTED,
} ControllerPort;

#endif // CONTROLLER
