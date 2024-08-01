#include "global.h"

bool func_800CC220(void) {
    OSPiHandle* leoHandle = osLeoDiskInit();
    u32 status;

    osEPiReadIo(leoHandle, LEO_STATUS, &status);

    if (status & LEO_STATUS_PRESENCE_MASK) {
        return false;
    } else {
        return true;
    }
}
