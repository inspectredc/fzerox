#include "global.h"

bool func_800CC220(void) {
    OSPiHandle* leoHandle = osLeoDiskInit();
    u32 data;

    osEPiReadIo(leoHandle, 0x05000508, &data);

    if (data & 0xFFFF) {
        return false;
    } else {
        return true;
    }
}
