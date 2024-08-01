#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 LeoReadWrite(LEOCmd* cmdBlock, s32 direction, u32 LBA, void* vAddr, u32 nLBAs, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    if (direction == OS_READ) {
        cmdBlock->header.command = LEO_COMMAND_READ;
    } else {
        cmdBlock->header.command = LEO_COMMAND_WRITE;
    }
    cmdBlock->header.reserve1 = 0;
    if (mq != NULL) {
        cmdBlock->header.control = LEO_CONTROL_POST;
    } else {
        cmdBlock->header.control = 0;
    }
    cmdBlock->header.reserve3 = 0;
    cmdBlock->header.post = mq;
    cmdBlock->data.readwrite.lba = LBA;
    cmdBlock->data.readwrite.xfer_blks = nLBAs;
    cmdBlock->data.readwrite.buff_ptr = vAddr;
    leoCommand(cmdBlock);
    return 0;
}
