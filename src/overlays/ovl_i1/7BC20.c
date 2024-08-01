#include "global.h"
#include "leo/leo_internal.h"

extern void (*LEO_cmd_tbl[])(void);
extern s32 D_i1_8042B33C;
extern s32 D_i1_8042B340;
extern u8 D_i1_8042B344;
extern u8 D_i1_8042B345;
extern u8 D_i1_8042B348;
extern OSIoMesg LEOPiDmaParam;
extern s32 LEO_country_code;
extern OSPiHandle* D_i1_8042B380;

#ifdef IDO53
void leomain(void* arg0) {
    u32 cur_status;
    s32 sense_code;

    ((u8*)&LEO_country_code)[0] = *(u8*)0xA0000010;
    ((u8*)&LEO_country_code)[1] = *(u8*)0xA0000090;
    ((u8*)&LEO_country_code)[2] = *(u8*)0xA0000110;
    ((u8*)&LEO_country_code)[3] = *(u8*)0xA0000190;

    D_i1_8042B340 = 0;
    D_i1_8042B33C = 0;
    D_i1_8042B344 = 0;
    D_i1_8042B345 = 0;
    leoInitUnit_atten();
    D_i1_8042B380 = osLeoDiskInit();
    LEOPiDmaParam.hdr.pri = 1;
    LEOPiDmaParam.hdr.retQueue = &LEOdma_que;
    osEPiReadIo(D_i1_8042B380, 0x05000508, &cur_status);
    if (!(cur_status & 0x400000)) {
        if ((cur_status & 0x06800000)) {
            leoDrive_reset();
        }
    }

    while (true) {
        osRecvMesg(&LEOcommand_que, (void** ) &LEOcur_command, 1);
        if (LEOcur_command->header.command == 0) {
            leoDrive_reset();
            osRecvMesg(&LEOevent_que, NULL, 0);
            continue;
        }
        sense_code = leoChk_asic_ready(0x10001);
        cur_status = leoChkUnit_atten();
        if (cur_status == 0) {
            if (sense_code == 0) {
                goto block_43;
            }
        } else {
            switch (sense_code) {
                case 3:
                case 41:
                case 43:
                    break;
                case 49:
                    if (leoRetUnit_atten() == 0x2B) {
                        sense_code = 0x2B;
                    }
                    break;
                default:
                    sense_code = leoRetUnit_atten();
            }
        }
        switch (sense_code) {
            case 47:
                switch (LEOcur_command->header.command) {
                    case 12:
                        func_i1_8041015C();
                        /* fallthrough */
                    case 2:
                    case 13:
                    case 14:
                    case 15:
                        goto block_43;
                }
                break;
            case 49:
                switch (LEOcur_command->header.command) {
                    case 2:
                    case 11:
                    case 13:
                    case 14:
                    case 15:
                        goto block_43;
                    default:
                        sense_code = 0x2A;
                }
                break;
            case 43:
                switch (LEOcur_command->header.command) {
                    case 15:
                        func_i1_80410134();
                        /* fallthrough */
                    case 2:
                    case 13:
                    case 14:
                        goto block_43;
                }
                break;
        }

        if (LEOcur_command->header.command == 3) {
            LEOcur_command->data.time.pad = leoChk_cur_drvmode();
        }
        LEOcur_command->header.sense = (u8) sense_code;
        LEOcur_command->header.status = 2;
        while (false) {
            block_43:
            if (D_i1_8042B344 == 0) {
                switch (LEOcur_command->header.command) {
                    case 2:
                    case 3:
                    case 11:
                    case 13:
                    case 14:
                    case 15:
                        goto block_59;
                }
    
                if (LEO_country_code == 0) {
                    osEPiReadIo(D_i1_8042B380, 0x05000540U, &cur_status);
                    if ((cur_status & 0x70000) != 0x40000) {
                        while (true) {}
                    }
                }
                    
                if (leoRead_system_area() != 0) {
                    LEOcur_command->header.status = 2;
                    break;
                } 
                
                if ((LEOcur_command->header.sense = leoSend_asic_cmd_w(0xB0001, LEO_sys_data.param.disk_type << 16)) != 0) {
                    LEOcur_command->header.status = 2;
                    break;
                } 
                                        
                if ((LEO_sys_data.param.disk_type & 0xF0) != 0x10) {
                    goto block_57;
                }
                D_i1_8042B348 = LEO_sys_data.param.disk_type & 0xF;
                if ((D_i1_8042B348) >= 7) {
    block_57:
                    LEOcur_command->header.sense = 0xB;
                    LEOcur_command->header.status = 2;
                    break;
                } 
                D_i1_8042B344 = 0xFF;
            }
    block_59:
            LEO_cmd_tbl[LEOcur_command->header.command]();
        }
        if (LEOcur_command->header.control & LEO_CONTROL_POST) {
            osSendMesg(LEOcur_command->header.post, (OSMesg)LEOcur_command->header.sense, 1);
        }
        if (D_i1_8042B345 != 0) {
            leoClr_queue();
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7BC20/leomain.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7BC20/leoRead_system_area.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7BC20/func_i1_8040D2F0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7BC20/func_i1_8040D320.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7BC20/func_i1_8040D530.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i1/7BC20/D_i1_804287E0.s")
