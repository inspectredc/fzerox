#include "global.h"

// Appears to be a custom version of osAiSetNextBuffer
s32 func_800B4BC0(void* buff, u32 len) {
    static u8 hdwrBugFlag = false;
    u8* bptr;
    u32 status;

    bptr = buff;
    if (hdwrBugFlag) {
        bptr -= 0x2000;
    }
    if (!(((uintptr_t) buff + len) & 0x1FFF)) {
        hdwrBugFlag = true;
    } else {
        hdwrBugFlag = false;
    }
    status = IO_READ(AI_STATUS_REG);
    if (status & 0x80000000) {
        return -1;
    }
    IO_WRITE(AI_DRAM_ADDR_REG, OS_PHYSICAL_TO_K0(bptr));
    IO_WRITE(AI_LEN_REG, len);
    return 0;
}
