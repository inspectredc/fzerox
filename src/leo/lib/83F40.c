#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 LeoTestUnitReady(LEOStatus* status) {
    LEOCmdTestUnitReady cmdBlock;

    if (!__leoActive) {
        return -1;
    }
    if (IO_READ(PI_STATUS_REG) & 1) {
        return LEO_STATUS_BUSY;
    }
    cmdBlock.header.command = 3;
    cmdBlock.header.reserve1 = 0;
    cmdBlock.header.control = 0;
    cmdBlock.header.reserve3 = 0;
    leoCommand((void*)&cmdBlock);

    while (cmdBlock.header.status == LEO_STATUS_BUSY) {}

    *status = cmdBlock.test;
    return GET_ERROR(cmdBlock);
}
