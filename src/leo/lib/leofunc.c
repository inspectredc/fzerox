#include "libultra/ultra64.h"
#include "leo/leo_internal.h"
#include "macros.h"

OSMesgQueue LEOpost_que;
OSMesg LEOpost_que_buf[1];

void leoInitialize(OSPri compri, OSPri intpri, OSMesg* cmdQueueBuf, u32 cmdBufCount) {
    osCreateMesgQueue(&LEOcommand_que, cmdQueueBuf, cmdBufCount);
    osCreateMesgQueue(&LEOcontrol_que, LEOcontrol_que_buf, ARRAY_COUNT(LEOcontrol_que_buf));
    osCreateMesgQueue(&LEOevent_que, LEOevent_que_buf, ARRAY_COUNT(LEOevent_que_buf));
    osCreateMesgQueue(&LEOdma_que, LEOdma_que_buf, ARRAY_COUNT(LEOdma_que_buf));
    osCreateMesgQueue(&LEOblock_que, LEOblock_que_buf, ARRAY_COUNT(LEOblock_que_buf));
    osCreateMesgQueue(&LEOpost_que, LEOpost_que_buf, ARRAY_COUNT(LEOpost_que_buf));
    osCreateThread(&LEOcommandThread, 1, leomain, NULL, LEOcommandThreadStack + ARRAY_COUNT(LEOcommandThreadStack),
                   compri);
    osStartThread(&LEOcommandThread);
    osCreateThread(&LEOinterruptThread, 1, leointerrupt, NULL,
                   LEOinterruptThreadStack + ARRAY_COUNT(LEOinterruptThreadStack), intpri);
    osStartThread(&LEOinterruptThread);
    osSetEventMesg(OS_EVENT_CART, &LEOevent_que, (OSMesg) 0x30000);
    osSendMesg(&LEOblock_que, NULL, OS_MESG_NOBLOCK);
}

extern OSMesgQueue LEOblock_que;
extern OSMesgQueue LEOcommand_que;

void leoCommand(void* cmd_blk_addr) {

    osRecvMesg(&LEOblock_que, NULL, OS_MESG_BLOCK);
    ((LEOCmd*) cmd_blk_addr)->header.status = LEO_STATUS_BUSY;
    ((LEOCmd*) cmd_blk_addr)->header.sense = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;

    switch (((LEOCmd*) cmd_blk_addr)->header.command) {
        case LEO_COMMAND_CLEAR_QUE:
            LEOclr_que_flag = -1;
            leoClr_queue();
            LEOclr_que_flag = 0;
            ((LEOCmd*) cmd_blk_addr)->header.status = LEO_STATUS_GOOD;
            if (((LEOCmd*) cmd_blk_addr)->header.control & LEO_CONTROL_POST) {
                osSendMesg(((LEOCmd*) cmd_blk_addr)->header.post, NULL, OS_MESG_BLOCK);
            }
            break;
        case LEO_COMMAND_READ:
        case LEO_COMMAND_WRITE:
            ((LEOCmd*) cmd_blk_addr)->data.readwrite.rw_bytes = 0;
            goto cmd_queing;
        default:
            if ((u32) (((LEOCmd*) cmd_blk_addr)->header.command - 1) >= LEO_COMMAND_SET_TIMER) {
                ((LEOCmd*) cmd_blk_addr)->header.sense = LEO_SENSE_INVALID_COMMAND_OPERATION_CODE;
                ((LEOCmd*) cmd_blk_addr)->header.status = LEO_STATUS_CHECK_CONDITION;
                break;
            }
        cmd_queing:
            if (osSendMesg(&LEOcommand_que, ((LEOCmd*) cmd_blk_addr), OS_MESG_NOBLOCK) != 0) {
                ((LEOCmd*) cmd_blk_addr)->header.sense = LEO_SENSE_QUEUE_FULL;
                ((LEOCmd*) cmd_blk_addr)->header.status = LEO_STATUS_CHECK_CONDITION;
            }
    }
    osSendMesg(&LEOblock_que, NULL, OS_MESG_BLOCK);
}

const u8 D_i1_804287D0[] = { 0 };

void LeoReset(void) {
    osRecvMesg(&LEOblock_que, NULL, OS_MESG_BLOCK);
    LEOclr_que_flag = -1;
    leoClr_queue();
    LEOclr_que_flag = 0;
    osRecvMesg(&LEOevent_que, NULL, OS_MESG_NOBLOCK);
    osSendMesg(&LEOevent_que, (OSMesg) ASIC_SOFT_RESET_CODE, OS_MESG_BLOCK);
    osSendMesg(&LEOcommand_que, (OSMesg) D_i1_804287D0, OS_MESG_BLOCK);
}

s32 __leoSetReset(void) {
    leoDrive_reset();
    return LEO_ERROR_GOOD;
}

s32 LeoResetClear(void) {
    LEOCmdHeader resetclear;

    resetclear.command = LEO_COMMAND_RESET_CLEAR;
    resetclear.control = LEO_CONTROL_POST;
    resetclear.status = LEO_STATUS_GOOD;
    resetclear.post = &LEOpost_que;
    if (osSendMesg(&LEOcommand_que, &resetclear.command, OS_MESG_NOBLOCK) != 0) {
        return LEO_SENSE_QUEUE_FULL;
    }
    osRecvMesg(&LEOpost_que, NULL, OS_MESG_BLOCK);
    if (resetclear.status == LEO_STATUS_GOOD) {
        return LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
    }
    return resetclear.sense;
}
