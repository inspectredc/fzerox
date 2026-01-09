#include "libultra/ultra64.h"
#include "leo/leo_internal.h"
#include "macros.h"

u16 leoLba_to_phys(u32 lba) {
    u16 vzone;
    u16 vzone_lba_start;
    u16 pzone_cylinder_start;
    u16 zone_cylinder;
    u16 defect_amount;
    u32 pzone_prev;
    u16 defect_offset;
    u16 defect_cylinder;
    u8 pzone;

    // A cylinder track is made of two blocks, so we may be able to only read one of it if the next block is on the next
    // cylinder
    LEOtgt_param.rdwr_blocks = 2 - (lba % 2);

    // Blocks are interleaved between cylinders
    switch (lba % 4) {
        case 0:
        case 3:
            LEOtgt_param.start_block = 0;
            break;
        default:
            LEOtgt_param.start_block = 1;
            break;
    }

    // Get Virtual & Physical Disk Zones from LBA
    vzone = leoLba_to_vzone(lba);

    // Set Parameter Disk Head & Zone
    LEOtgt_param.zone = pzone = LEOVZONE_PZONEHD_TBL[LEOdisk_type][vzone];
    LEOtgt_param.head = 0;
    if (LEOtgt_param.zone > 7) {
        LEOtgt_param.zone -= 7;
        LEOtgt_param.head = 1;
    }

    // Get the start cylinder from current zone
    pzone_cylinder_start = LEOZONE_SCYL_TBL[pzone];

    // Get Virtual Zone LBA start, if Zone 0, it's LBA 0
    if (vzone != 0) {
        vzone_lba_start = LEOVZONE_TBL[LEOdisk_type][vzone - 1];
    } else {
        vzone_lba_start = 0;
    }
    // Get Cylinder relative of the current Zone
    zone_cylinder = ((lba - vzone_lba_start) / 2);
    // Calculate Physical Cylinder
    if (LEOtgt_param.head != 0) {
        LEOtgt_param.cylinder = pzone_cylinder_start - zone_cylinder;
        pzone_cylinder_start = LEOZONE_OUTERCYL_TBL[LEOtgt_param.zone - 1];
    } else {
        LEOtgt_param.cylinder = pzone_cylinder_start + zone_cylinder;
    }

    // Get the relative offset to defect tracks for the current zone (if Zone 0, then it's 0)
    if ((u32) pzone != 0) {
        defect_offset = LEO_sys_data.param.defect_num[pzone - 1];
    } else {
        defect_offset = 0;
    }
    // Get amount of defect tracks for the current zone
    defect_amount = LEO_sys_data.param.defect_num[pzone] - defect_offset;

    // Skip defective cylinders
    while (defect_amount != 0) {
        defect_cylinder = (pzone_cylinder_start + LEO_sys_data.param.defect_data[defect_offset]);
        if (LEOtgt_param.cylinder < defect_cylinder) {
            break;
        }

        LEOtgt_param.cylinder++;
        defect_offset++;
        defect_amount--;
    }

    // Set sector and block size info
    LEOtgt_param.sec_bytes = LEOBYTE_TBL1[LEOtgt_param.zone];
    LEOtgt_param.blk_bytes = LEOBYTE_TBL2[LEOtgt_param.zone];

    // For development disks
    if ((LEO_country_code == LEO_COUNTRY_NONE) && (lba < 0xC)) {
        LEOtgt_param.sec_bytes = 0xC0;
        LEOtgt_param.blk_bytes = 0x3FC0;
    }

    return 0;
}

u16 leoLba_to_vzone(u32 lba) {
    u16 i;
    const u16* ptr = LEOVZONE_TBL[LEOdisk_type];

    for (i = 0; i < ARRAY_COUNT(LEOVZONE_TBL[LEOdisk_type]); i++) {
        if (lba < *ptr) {
            return i;
        }
        ptr++;
    }

    return 0xFF;
}
