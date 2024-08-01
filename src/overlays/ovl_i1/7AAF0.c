#include "global.h"
#include "leo/leo_internal.h"

void func_i1_8040B9E0(OSPri compri, OSPri intpri, OSMesg* cmdQueueBuf, u32 cmdBufCount) {
    osCreateMesgQueue(&LEOcommand_que, cmdQueueBuf, cmdBufCount);
    osCreateMesgQueue(&LEOcontrol_que, LEOcontrol_que_buf, ARRAY_COUNT(LEOcontrol_que_buf));
    osCreateMesgQueue(&LEOevent_que, LEOevent_que_buf, ARRAY_COUNT(LEOevent_que_buf));
    osCreateMesgQueue(&LEOdma_que, LEOdma_que_buf, ARRAY_COUNT(LEOdma_que_buf));
    osCreateMesgQueue(&LEOblock_que, LEOblock_que_buf, ARRAY_COUNT(LEOblock_que_buf));
    osCreateMesgQueue(&LEOpost_que, LEOpost_que_buf, ARRAY_COUNT(LEOpost_que_buf));
    osCreateThread(&LEOcommandThread, 1, leomain, NULL, LEOcommandThreadStack + ARRAY_COUNT(LEOcommandThreadStack), compri);
    osStartThread(&LEOcommandThread);
    osCreateThread(&LEOinterruptThread, 1, leointerrupt, NULL, LEOinterruptThreadStack + ARRAY_COUNT(LEOinterruptThreadStack), intpri);
    osStartThread(&LEOinterruptThread);
    osSetEventMesg(OS_EVENT_CART, &LEOevent_que, (OSMesg)0x30000);
    osSendMesg(&LEOblock_que, NULL, 0);
}

extern u8 D_i1_8042B345;
extern OSMesgQueue LEOblock_que;
extern OSMesgQueue LEOcommand_que;

void leoCommand(void* cmd_blk_addr) {

    osRecvMesg(&LEOblock_que, NULL, 1);
    ((LEOCmd*)cmd_blk_addr)->header.status = 8;
    ((LEOCmd*)cmd_blk_addr)->header.sense = 0;

    switch (((LEOCmd*)cmd_blk_addr)->header.command) {
        case 1:
            D_i1_8042B345 = 0xFF;
            leoClr_queue();
            D_i1_8042B345 = 0;
            ((LEOCmd*)cmd_blk_addr)->header.status = 0;
            if (((LEOCmd*)cmd_blk_addr)->header.control & 0x80) {
                osSendMesg(((LEOCmd*)cmd_blk_addr)->header.post, NULL, 1);
            }
            break;
        case 5:
        case 6:
            ((LEOCmd*)cmd_blk_addr)->data.readwrite.rw_bytes = 0;
            goto block_10;
        default:
            if ((u32)(((LEOCmd*)cmd_blk_addr)->header.command - 1) >= 0xE) {
                ((LEOCmd*)cmd_blk_addr)->header.sense = 0x1F;
                ((LEOCmd*)cmd_blk_addr)->header.status = 2;
                break;
            }
    block_10:
            if (osSendMesg(&LEOcommand_que, ((LEOCmd*)cmd_blk_addr), 0) != 0) {
                ((LEOCmd*)cmd_blk_addr)->header.sense = 0x23;
                ((LEOCmd*)cmd_blk_addr)->header.status = 2;
            }
    }
    osSendMesg(&LEOblock_que, NULL, 1);
}

const u8 D_i1_804287D0[] = { 0 };

void LeoReset(void) {
    osRecvMesg(&LEOblock_que, NULL, 1);
    D_i1_8042B345 = 0xFF;
    leoClr_queue();
    D_i1_8042B345 = 0;
    osRecvMesg(&LEOevent_que, NULL, 0);
    osSendMesg(&LEOevent_que, (OSMesg)0xA0000, 1);
    osSendMesg(&LEOcommand_que, (OSMesg)D_i1_804287D0, 1);
}

s32 func_i1_8040BD40(void) {
    leoDrive_reset();
    return 0;
}

s32 func_i1_8040BD70(void) {
    LEOCmdHeader resetclear;

    resetclear.command = 0xF;
    resetclear.control = LEO_CONTROL_POST;
    resetclear.status = 0;
    resetclear.post = &LEOpost_que;
    if (osSendMesg(&LEOcommand_que, &resetclear.command, 0) != 0) {
        return LEO_SENSE_QUEUE_FULL;
    }
    osRecvMesg(&LEOpost_que, NULL, 1);
    if (resetclear.status == LEO_STATUS_GOOD) {
        return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    }
    return resetclear.sense;
}
