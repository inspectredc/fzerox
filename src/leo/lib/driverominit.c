#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/piint.h"
#include "macros.h"
#include "libc/stdbool.h"
#include "leo/leo_internal.h"

#if LEO_VERSION == LEO_VERSION_B
OSPiHandle DriveRomHandle ALIGNED(8);

OSPiHandle* osDriveRomInit(void) {
    static u32 first = true;
    register u32 value;
    register s32 status;
    register u32 prevInt;
    register u32 latency;
    register u32 pageSize;
    register u32 relDuration;
    register u32 pulse;

    __osPiGetAccess();

    if (!first) {
        __osPiRelAccess();
        return &DriveRomHandle;
    }

    first = false;
    DriveRomHandle.type = DEVICE_TYPE_BULK;
    DriveRomHandle.baseAddress = PHYS_TO_K1(PI_DOM1_ADDR1);
    DriveRomHandle.domain = PI_DOMAIN1;
    DriveRomHandle.speed = 0;
    bzero(&DriveRomHandle.transferInfo, sizeof(__OSTranxInfo));

    status = IO_READ(PI_STATUS_REG);
    while (status & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        status = IO_READ(PI_STATUS_REG);
    }

    latency = IO_READ(PI_BSD_DOM1_LAT_REG);
    pageSize = IO_READ(PI_BSD_DOM1_PGS_REG);
    relDuration = IO_READ(PI_BSD_DOM1_RLS_REG);
    pulse = IO_READ(PI_BSD_DOM1_PWD_REG);

    IO_WRITE(PI_BSD_DOM1_LAT_REG, 255);
    IO_WRITE(PI_BSD_DOM1_PGS_REG, 0);
    IO_WRITE(PI_BSD_DOM1_RLS_REG, 3);
    IO_WRITE(PI_BSD_DOM1_PWD_REG, 255);

    value = IO_READ(DriveRomHandle.baseAddress);
    DriveRomHandle.latency = value & 0xFF;
    DriveRomHandle.pageSize = (value >> 0x10) & 0xF;
    DriveRomHandle.relDuration = (value >> 0x14) & 0xF;
    DriveRomHandle.pulse = (value >> 8) & 0xFF;

    IO_WRITE(PI_BSD_DOM1_LAT_REG, latency);
    IO_WRITE(PI_BSD_DOM1_PGS_REG, pageSize);
    IO_WRITE(PI_BSD_DOM1_RLS_REG, relDuration);
    IO_WRITE(PI_BSD_DOM1_PWD_REG, pulse);

    prevInt = __osDisableInt();
    DriveRomHandle.next = __osPiTable;
    __osPiTable = &DriveRomHandle;
    __osRestoreInt(prevInt);
    __osPiRelAccess();

    return &DriveRomHandle;
}
#endif
