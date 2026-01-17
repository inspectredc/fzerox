#include "global.h"

bool LeoDD_CheckPresence(void) {
    OSPiHandle* leoHandle = osLeoDiskInit();
    u32 status;

    osEPiReadIo(leoHandle, LEO_STATUS, &status);

    if (status & LEO_STATUS_PRESENCE_MASK) {
        return false;
    } else {
        return true;
    }
}
