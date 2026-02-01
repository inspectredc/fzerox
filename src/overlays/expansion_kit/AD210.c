#include "global.h"
#include "fzx_racer.h"
#include "fzx_machine.h"

extern CustomMachinesInfo gCustomMachinesInfo;

void func_xk1_8002FFA0(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        gCustomMachinesInfo.customMachines[i].number = 31;
        gCustomMachinesInfo.characterCustomState[i] = 0;
    }
}

extern CustomMachine gCustomMachine;

void func_xk1_8002FFDC(void) {
    gCustomMachine.body = 0;
    gCustomMachine.boost = 0;
    gCustomMachine.grip = 0;
    gCustomMachine.frontType = FRONT_0;
    gCustomMachine.rearType = REAR_0;
    gCustomMachine.wingType = WING_NONE;
    gCustomMachine.logo = MACHINE_LOGO(LOGO_SHIELD);
    gCustomMachine.number = 31;
    gCustomMachine.decal = MACHINE_DECAL(DECAL_STRIPE);
    gCustomMachine.red = 0;
    gCustomMachine.green = 255;
    gCustomMachine.blue = 0;
    gCustomMachine.numberR = 255;
    gCustomMachine.numberG = 255;
    gCustomMachine.numberB = 255;
    gCustomMachine.decalR = 255;
    gCustomMachine.decalG = 255;
    gCustomMachine.decalB = 0;
    gCustomMachine.cockpitR = 0;
    gCustomMachine.cockpitG = 0;
    gCustomMachine.cockpitB = 93;
    gCustomMachine.machineName[0] = '\0';
}
