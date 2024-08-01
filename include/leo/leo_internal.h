#ifndef LEO_INTERNAL_H
#define LEO_INTERNAL_H

#include "libultra/ultra64.h"
#include "PR/leo.h"

typedef struct {
  /* 0x0 */ u16 lba;
  /* 0x2 */ u16 cylinder;
  /* 0x4 */ u16 blk_bytes;
  /* 0x6 */ u8 sec_bytes;
  /* 0x7 */ u8 head;
  /* 0x8 */ u8 zone;
  /* 0x9 */ u8 rdwr_blocks;
  /* 0xA */ u8 start_block;
} tgt_param_form; // size = 0xC

typedef union {
    /* 0x00 */ struct {
        /* 0x00 */ u32 country;
        /* 0x04 */ u8 fmt_type;
        /* 0x05 */ u8 disk_type;
        /* 0x06 */ u16 ipl_load_len;
        /* 0x08 */ u8 defect_num[20];
        /* 0x1C */ void* loadptr;
        /* 0x20 */ u8 defect_data[192];
        /* 0xE0 */ u16 rom_end_lba;
        /* 0xE2 */ u16 ram_start_lba;
        /* 0xE4 */ u16 ram_end_lba;
    } param;
    /* 0x00 */ u64 u64_data[29];
} leo_sys_form; // size = 0xE8

extern u8 leoSeek_i(u16 rwmode);
extern void leointerrupt(void*);
extern void leomain(void*);
extern u16 leoLba_to_phys(u32 lba);
s32 leoRead_system_area(void);
u8 leoChk_asic_ready(u32);
u8 leoSend_asic_cmd_w(u32, u32);
u8 leoChk_cur_drvmode(void);
void leoDrive_reset(void);
u32 leoChkUnit_atten(void);
u32 leoRetUnit_atten(void);
void func_i1_80410134(void);
void func_i1_8041015C(void);
void leoInitUnit_atten(void);
void leoClr_queue(void);
void LeoReset(void);

extern s32 __leoActive;

extern s32 (*D_i1_8042A620)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);
extern s32 (*D_i1_8042A624)(LEOCmd*, u32, OSMesgQueue*);
extern s32 (*D_i1_8042A628)(LEOCmd*, u8, OSMesgQueue*);
extern s32 (*D_i1_8042A62C)(LEOCmd*, LEODiskID*, OSMesgQueue*);
extern s32 (*D_i1_8042A630)(LEOCmd*, OSMesgQueue*);
extern s32 (*D_i1_8042A634)(LEOCmd*, LEODiskTime*, OSMesgQueue*);
extern s32 (*D_i1_8042A638)(LEOCmd*, u32, u32, OSMesgQueue*);
extern s32 (*D_i1_8042A63C)(LEOCmd*, OSMesgQueue*);

extern u8* LEOwrite_pointer;
extern u8* LEOc2ctrl_que_buf;
extern LEOCmd* LEOcur_command;
extern OSMesgQueue LEOblock_que;
extern OSMesgQueue LEOevent_que;
extern OSMesgQueue LEOc2ctrl_que;
extern OSMesgQueue LEOcontrol_que;
extern OSMesgQueue LEOpost_que;
extern OSMesgQueue LEOcommand_que;
extern OSMesgQueue LEOdma_que;
extern OSMesg LEOevent_que_buf[1];
extern OSMesg LEOcontrol_que_buf[1];
extern OSMesg LEOdma_que_buf[2];
extern OSMesg LEOblock_que_buf[1];
extern OSMesg LEOpost_que_buf[1];
extern u8 LEOcommandThreadStack[0x400];
extern u8 LEOinterruptThreadStack[0x400];
extern OSThread LEOcommandThread;
extern OSThread LEOinterruptThread;
extern tgt_param_form LEOtgt_param;
extern u16 LEOrw_flags;
extern leo_sys_form LEO_sys_data;

#endif
