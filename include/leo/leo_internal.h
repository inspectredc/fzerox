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

typedef struct {
    /* 0x00 */ u8* pntr;
    /* 0x04 */ u8* c2buff_e;
    /* 0x08 */ u8 err_pos[4];
    /* 0x0C */ u8 err_num;
    /* 0x0D */ u8 bytes;
    /* 0x0E */ u16 blkbytes;
} block_param_form; // size = 0x10

typedef struct {
    /* 0x0 */ u8 year;
    /* 0x1 */ u8 month;
    /* 0x2 */ u8 day;
    /* 0x3 */ u8 hour;
    /* 0x4 */ u8 minute;
    /* 0x5 */ u8 second;
} __LOCTime; // size = 0x6

/* Memory Map */
#define LEO_BASE_REG 0x05000000

#define LEO_CMD (LEO_BASE_REG + 0x508)
#define LEO_STATUS (LEO_BASE_REG + 0x508)

#define LEO_BM_CTL (LEO_BASE_REG + 0x510)
#define LEO_BM_STATUS (LEO_BASE_REG + 0x510)

#define LEO_SEQ_CTL (LEO_BASE_REG + 0x518)
#define LEO_SEQ_STATUS (LEO_BASE_REG + 0x518)

#define LEO_C2_BUFF (LEO_BASE_REG + 0x000)      //C2 Sector Buffer
#define LEO_SECTOR_BUFF (LEO_BASE_REG + 0x400)  //Data Sector Buffer
#define LEO_DATA (LEO_BASE_REG + 0x500)         //Data
#define LEO_MISC_REG (LEO_BASE_REG + 0x504)     //Misc Register
#define LEO_CUR_TK (LEO_BASE_REG + 0x50C)       //Current Track
#define LEO_ERR_SECTOR (LEO_BASE_REG + 0x514)   //Sector Error Status
#define LEO_CUR_SECTOR (LEO_BASE_REG + 0x51C)   //Current Sector
#define LEO_HARD_RESET (LEO_BASE_REG + 0x520)   //Hard Reset
#define LEO_C1_S0 (LEO_BASE_REG + 0x524)        //C1
#define LEO_HOST_SECBYTE (LEO_BASE_REG + 0x528) //Sector Size (in bytes)
#define LEO_C1_S2 (LEO_BASE_REG + 0x52C)        //C1
#define LEO_SEC_BYTE (LEO_BASE_REG + 0x530)     //Sectors per Block, Full Size
#define LEO_C1_S4 (LEO_BASE_REG + 0x534)        //C1
#define LEO_C1_S6 (LEO_BASE_REG + 0x538)        //C1
#define LEO_CUR_ADDR (LEO_BASE_REG + 0x53C)     //Current Address?
#define LEO_ID_REG (LEO_BASE_REG + 0x540)       //ID
#define LEO_TEST_REG (LEO_BASE_REG + 0x544)     //Test Read
#define LEO_TEST_PIN_SEL (LEO_BASE_REG + 0x548) //Test Write
#define LEO_RAM_ADDR (LEO_BASE_REG + 0x580)     //Microsequencer RAM

#define LEO_COUNTRY_JPN		0xE848D316
#define LEO_COUNTRY_USA		0x2263EE56
#define LEO_COUNTRY_NONE	0x00000000

#define LEO_CMD_TYPE_0 0
#define LEO_CMD_TYPE_1 1
#define LEO_CMD_TYPE_2 2

#define LEO_STATUS_PRESENCE_MASK 0xFFFF

#define LEO_STATUS_DATA_REQUEST 0x40000000
#define LEO_STATUS_C2_TRANSFER 0x10000000
#define LEO_STATUS_BUFFER_MANAGER_ERROR 0x08000000
#define LEO_STATUS_BUFFER_MANAGER_INTERRUPT 0x04000000
#define LEO_STATUS_MECHANIC_INTERRUPT 0x02000000
#define LEO_STATUS_DISK_PRESENT 0x01000000
#define LEO_STATUS_BUSY_STATE 0x00800000
#define LEO_STATUS_RESET_STATE 0x00400000
#define LEO_STATUS_MOTOR_NOT_SPINNING 0x00100000
#define LEO_STATUS_HEAD_RETRACTED 0x00080000
#define LEO_STATUS_WRITE_PROTECT_ERROR 0x00040000
#define LEO_STATUS_MECHANIC_ERROR 0x00020000
#define LEO_STATUS_DISK_CHANGE 0x00010000

#define LEO_CUR_TK_INDEX_LOCK 0x60000000

#define LEO_BM_STATUS_RUNNING 0x80000000      //Running
#define LEO_BM_STATUS_ERROR 0x04000000        //Error
#define LEO_BM_STATUS_MICRO 0x02000000        //Micro Status?
#define LEO_BM_STATUS_BLOCK 0x01000000        //Block Transfer
#define LEO_BM_STATUS_C1CORRECTION 0x00800000 //C1 Correction
#define LEO_BM_STATUS_C1DOUBLE 0x00400000     //C1 Double
#define LEO_BM_STATUS_C1SINGLE 0x00200000     //C1 Single
#define LEO_BM_STATUS_C1ERROR 0x00010000      //C1 Error

#define LEO_BM_CTL_START 0x80000000             //Start Buffer Manager
#define LEO_BM_CTL_MODE 0x40000000              //Buffer Manager Mode
#define LEO_BM_CTL_IMASK 0x20000000             //BM Interrupt Mask
#define LEO_BM_CTL_RESET 0x10000000             //Buffer Manager Reset
#define LEO_BM_CTL_DISABLE_OR 0x08000000        //Disable OR Check?
#define LEO_BM_CTL_DISABLE_C1 0x04000000        //Disable C1 Correction
#define LEO_BM_CTL_BLOCK 0x02000000             //Block Transfer
#define LEO_BM_CTL_CLR_MECHANIC_INTR 0x01000000 //Mechanic Interrupt Reset

/* ASIC commands */
#define ASIC_NO_OPERATION          0x00000000
#define ASIC_RD_SEEK               0x00010001
#define ASIC_WR_SEEK               0x00020001
#define ASIC_RECAL                 0x00030001
#define ASIC_SLEEP                 0x00040000
#define ASIC_START                 0x00050001
#define ASIC_SET_STBY              0x00060000
#define ASIC_SET_SLEEP             0x00070000
#define ASIC_CLR_CHGFLG            0x00080000
#define ASIC_CLR_RSTFLG            0x00090000
#define ASIC_RD_VERSION            0x000a0000
#define ASIC_SET_DTYPE             0x000b0001
#define ASIC_REQ_STATUS            0x000c0000
#define ASIC_STANDBY               0x000d0000
#define ASIC_INDEX_LOCK_RETRY      0x000e0001
#define ASIC_SET_TIMER_YEAR        0x000f0000
#define ASIC_SET_TIMER_DATE        0x00100000
#define ASIC_SET_TIMER_MINUTE      0x00110000
#define ASIC_READ_TIMER_YEAR       0x00120000
#define ASIC_READ_TIMER_DATE       0x00130000
#define ASIC_READ_TIMER_MINUTE     0x00140000
#define ASIC_SET_LED_TIMER         0x00150000
#define ASIC_READ_PROGRAM_VERSION  0x001B0000
#define ASIC_NEED_DISK_IN          0x00000001
#define ASIC_SOFT_RESET_CODE       0x000a0000
#define ASIC_HARD_RESET_CODE       0xaaaa0000

/* Special Case Control Queue Messages */
#define LEO_MSG_CONTROL_FORCE_ACCEPT    0x90000
#define LEO_MSG_CONTROL_C2_CORRECTION   0x80000

u8 leoChk_asic_ready(u32 asic_cmd);
u8 leoDetect_index_w(void);
u8 leoSeek_i(u16 rwmode);
s32 leoRecv_event_mesg(s32 control);
u16 leoLba_to_phys(u32 lba);
u8 leoRead_system_area(void);
u8 leoWait_mecha_cmd_done(u32 asic_cmd);
u8 leoSend_asic_cmd_w(u32 asic_cmd, u32 asic_data);
u32 leoChk_err_retry(u32 sense);
u8 leoChk_cur_drvmode(void);
void leoDrive_reset(void);
u32 leoChkUnit_atten(void);
u32 leoRetUnit_atten(void);
void leointerrupt(void*);
void leomain(void*);
void leoRead_common(u32 offset);
void leoClrUA_RESET(void);
void leoClrUA_MEDIUM_CHANGED(void);
void leoInitUnit_atten(void);
void leoClr_queue(void);
void LeoReset(void);
void leoSet_mseq(u16 rwmode);
u8 leoRecal_w(void);
u8 leoSeek_w(void);
s32 __osLeoInterrupt(void);
u16 leoC2_Correction(void);
u16 leoLba_to_vzone(u32 lba);
s32 __leoSetReset(void);
u8 leoAnalize_asic_status(void);

extern const u8 LEOBYTE_TBL1[9];
extern const u16 LEOBYTE_TBL2[9];
extern const u16 LEOVZONE_TBL[][0x10];
extern const u16 LEOZONE_SCYL_TBL[16];
extern const u8 LEOVZONE_PZONEHD_TBL[][0x10];
extern const u16 LEOZONE_OUTERCYL_TBL[8];
extern const u16 LEORAM_START_LBA[7];
extern const s32 LEORAM_BYTE[7];

extern s32 __leoActive;
extern s32 LEO_country_code;

extern s32 (*D_i1_8042A620)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);
extern s32 (*D_i1_8042A624)(LEOCmd*, u32, OSMesgQueue*);
extern s32 (*D_i1_8042A628)(LEOCmd*, u8, OSMesgQueue*);
extern s32 (*D_i1_8042A62C)(LEOCmd*, LEODiskID*, OSMesgQueue*);
extern s32 (*D_i1_8042A630)(LEOCmd*, OSMesgQueue*);
extern s32 (*D_i1_8042A634)(LEOCmd*, LEODiskTime*, OSMesgQueue*);
extern s32 (*D_i1_8042A638)(LEOCmd*, u32, u32, OSMesgQueue*);
extern s32 (*D_i1_8042A63C)(LEOCmd*, OSMesgQueue*);

extern u32 LEOasic_bm_ctl_shadow;
extern u32 LEOasic_seq_ctl_shadow;
extern u8 LEOdrive_flag;
extern u8 LEOclr_que_flag;
extern u8 LEOdisk_type;
extern OSIoMesg LEOPiDmaParam;
extern OSPiHandle* LEOPiInfo;
extern u8* LEOwrite_pointer;
extern u8* LEOc2ctrl_que_buf;
extern LEOVersion __leoVersion;
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

extern u8 LEO_TempBuffer[0xE8];
extern block_param_form LEOc2_param;

#endif
