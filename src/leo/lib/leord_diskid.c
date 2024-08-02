#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

extern LEOCmdRead read_id_cmd;
const u8 leo_disk_id_lba[2] = { 14, 15 };

void leoReadDiskId(void) {
    LEOCmdRead dummy_cmd;
    u8* temp_pointer;
    u32 cntr;

    // Keep Disk ID Command and replace
    temp_pointer = (u8*)LEOcur_command;

    // Read Disk ID to Temp Buffer
    LEOcur_command = (LEOCmd*)&dummy_cmd;
    for (cntr = 0; cntr < (sizeof(leo_disk_id_lba)); cntr++) {
        LEOrw_flags = 0x2000;
        dummy_cmd = read_id_cmd;
        dummy_cmd.lba = leo_disk_id_lba[cntr];
        leoRead_common(0);
        if (dummy_cmd.header.sense != LEO_SENSE_UNRECOVERED_READ_ERROR) {
            break;
        }
    }

    // Put back the old ReadDiskID command
    LEOcur_command = (LEOCmd*)temp_pointer;

    // Copy Disk ID to buffer pointed by ReadDiskID command
    temp_pointer = (u8*)LEOcur_command->data.readdiskid.buffer_pointer;
    for (cntr = 0; cntr < (sizeof(LEODiskID)); cntr += sizeof(u32)) {
        *(u32*)temp_pointer = *((u32*)&LEO_TempBuffer[cntr]);
        temp_pointer += sizeof(u32);
    }

    // Copy status and sense
    LEOcur_command->header.sense = GET_ERROR(dummy_cmd);
    LEOcur_command->header.status = dummy_cmd.header.status;
}
