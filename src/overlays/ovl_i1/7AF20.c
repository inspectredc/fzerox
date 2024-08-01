#include "global.h"
#include "leo/leo_internal.h"

u32 read_write_track(void);

void leointerrupt(void* arg) {
    u32 result;
    u32 tg_blocks;

    osCreateMesgQueue(&LEOc2ctrl_que, (OSMesg)&LEOc2ctrl_que_buf, 1);

    while (true) {
        osStopThread(&LEOinterruptThread);
        tg_blocks = LEOcur_command->data.readwrite.xfer_blks;
        LEOwrite_pointer = LEOcur_command->data.readwrite.buff_ptr;
        do {
            leoLba_to_phys(LEOtgt_param.lba);
            if (LEOrw_flags & 0x8000) {
                result = leoSeek_i(1);
            } else {
                result = leoSeek_i(0);
            }

            if (result != 0) {
                goto complete;
            }

            if (LEOrw_flags & 0x2000) {
                LEOtgt_param.rdwr_blocks = 1;
            } else if (LEOtgt_param.rdwr_blocks > tg_blocks) {
                LEOtgt_param.rdwr_blocks = tg_blocks;
            }
            LEOtgt_param.lba += LEOtgt_param.rdwr_blocks;
            tg_blocks -= LEOtgt_param.rdwr_blocks;
            result = read_write_track();
            if (result != 0) {
                goto complete;
            }

            LEOcur_command->data.readwrite.rw_bytes = LEOwrite_pointer - (u8*)LEOcur_command->data.readwrite.buff_ptr;
        } while (tg_blocks != 0);
        result = 0x90000; // Inaccessible?

    complete:;

        osSendMesg(&LEOcontrol_que, result, 1);
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7AF20/read_write_track.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7AF20/func_i1_8040C820.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7AF20/func_i1_8040C898.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7AF20/func_i1_8040C998.s")
