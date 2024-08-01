#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

s32 LeoReadDiskID(LEOCmd* cmdBlock, LEODiskID* vaddr, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    cmdBlock->header.command = LEO_COMMAND_READ_DISK_ID;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    cmdBlock->data.readdiskid.buffer_pointer = vaddr;
    if (mq != NULL) {
        cmdBlock->header.control |= LEO_CONTROL_POST;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}
