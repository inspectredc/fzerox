#include "leo/leo_internal.h"

leo_sys_form LEO_sys_data;

OSThread LEOcommandThread;
OSThread LEOinterruptThread;

u8 LEOcommandThreadStack[0x400];
u8 LEOinterruptThreadStack[0x400];

OSMesgQueue LEOcommand_que;
OSMesgQueue LEOevent_que;
OSMesgQueue LEOcontrol_que;
OSMesgQueue LEOdma_que;
OSMesgQueue LEOblock_que;

OSMesg LEOevent_que_buf[1];
OSMesg LEOcontrol_que_buf[1];
OSMesg LEOdma_que_buf[2];
OSMesg LEOblock_que_buf[1];

u8* LEOwrite_pointer;
LEOCmd* LEOcur_command;

u32 LEOasic_bm_ctl_shadow;
u32 LEOasic_seq_ctl_shadow;

u8 LEOdrive_flag;
u8 LEOclr_que_flag;

u16 LEOrw_flags;

u8 LEOdisk_type;

tgt_param_form LEOtgt_param;

s32 LEO_country_code;
