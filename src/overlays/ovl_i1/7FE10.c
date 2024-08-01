#include "libultra/ultra64.h"
#include "libc/stdbool.h"
#include "leo/leo_internal.h"

u8 __locReadTimer(__LOCTime* time);
u8 __locSetTimer(__LOCTime* time);

void leoTranslate(void) {
    u32 lba;
    u32 calc_bytes;
    u32 calc_blks;
    u32 byte_p_blk;
    u16 zone;
    u16 vzone;
    u8 flag; // boolean
    if (LEOcur_command->data.readwrite.lba >= NUM_LBAS) {

        LEOcur_command->header.sense = LEO_SENSE_LBA_OUT_OF_RANGE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    lba = LEOcur_command->data.readwrite.lba + 0x18;
    calc_blks = 0;
    calc_bytes = 0;
    flag = vzone = 1;

    if (LEOcur_command->header.control & LEO_CONTROL_TBL) {
        calc_bytes = LEOcur_command->data.readwrite.xfer_blks;

        while (calc_bytes != 0) {
            if (flag || (LEOVZONE_TBL[LEOdisk_type][vzone] == lba)) {
                vzone = leoLba_to_vzone(lba);
                zone = LEOVZONE_PZONEHD_TBL[LEOdisk_type][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = LEOBYTE_TBL2[zone];
            }
            if (calc_bytes < byte_p_blk) {
                calc_bytes = 0;
            } else {
                calc_bytes -= byte_p_blk;
            }
            calc_blks++;
            lba++;

            if ((calc_bytes != 0) && (lba >= 0x10DC)) {
                LEOcur_command->header.sense = LEO_SENSE_LBA_OUT_OF_RANGE;
                LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = false;
        }
        LEOcur_command->data.readwrite.buff_ptr = calc_blks;
    } else {
        calc_blks = LEOcur_command->data.readwrite.xfer_blks;

        while (calc_blks != 0) {
            if (flag || (LEOVZONE_TBL[LEOdisk_type][vzone] == lba)) {
                vzone = leoLba_to_vzone(lba);
                zone = LEOVZONE_PZONEHD_TBL[LEOdisk_type][vzone];
                if (zone >= 8) {
                    zone -= 7;
                }
                byte_p_blk = LEOBYTE_TBL2[zone];
            }
            calc_bytes += byte_p_blk;
            calc_blks--;
            lba++;
            if ((calc_blks != 0) && (lba >= 0x10DC)) {
                LEOcur_command->header.sense = LEO_SENSE_LBA_OUT_OF_RANGE;
                LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                return;
            }
            flag = false;
        }
        LEOcur_command->data.readwrite.buff_ptr = calc_bytes;
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}

void leoReadTimer(void) {
    u8* rdparam;
    u8 data[4];
    u8 sense_code;
    __LOCTime time;
    
    sense_code = __locReadTimer(&time);
    LEOcur_command->data.time.yearlo = time.year;
    LEOcur_command->data.time.month = time.month;
    LEOcur_command->data.time.day = time.day;
    LEOcur_command->data.time.hour = time.hour;
    LEOcur_command->data.time.minute = time.minute;
    LEOcur_command->data.time.second = time.second;
    if (sense_code != 0) {
        LEOcur_command->header.sense = sense_code;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    if ((u8)LEOcur_command->data.time.yearlo >= 0x96U) {
        LEOcur_command->data.time.yearhi = 0x19;
    } else {
        LEOcur_command->data.time.yearhi = 0x20;
    }
    LEOcur_command->header.status = 0;
}

static const u8 ymdupper[6] = { 99, 12, 31, 23, 59, 59 };
static const u8 dayupper[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void leoSetTimer(void) {
    LEOCmdReadTimer rd_timer;
    u8* p_tmp = &LEOcur_command->data.time.yearlo;
    u32 year;
    u32 month;
    u32 temp;
    u32 ymd;
    u8 result;
    __LOCTime time;

    // Verify values (if they're correct BCD or within limits)

    for (ymd = 0; ymd < 6; ymd++) {
        temp = *p_tmp;

        // Verify right nybble (only right nybble for some reason)
        if ((temp & 0xF) > 9) {
            // nybble is above 0x9 therefore the BCD value is invalid
            LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
            LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
            return;
        }

        // Convert BCD value to binary value
        temp = temp - ((temp >> 4) * 6);

        switch (ymd) {
            case 2:
                // Day value check
                if (temp > dayupper[month]) {
                    if (temp != 0x1D || year & 3) {
                        LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                        return;
                    }
                }
            case 1:
                // Month value cannot be 0
                if (temp == 0) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
            default:
                // Verify max value of each time info
                if (temp > ymdupper[ymd]) {
                    LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
                    LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
                    return;
                }
        }

        year = month;
        month = temp;
        p_tmp++;
    }

    // Every value has been ymd good, now set the values in hardware

    // Prepare the time info to use
    time.year = LEOcur_command->data.time.yearlo;
    time.month = LEOcur_command->data.time.month;
    time.day = LEOcur_command->data.time.day;
    time.hour = LEOcur_command->data.time.hour;
    time.minute = LEOcur_command->data.time.minute;
    time.second = LEOcur_command->data.time.second;

    // Set the new time
    result = __locSetTimer(&time);
    if (result != 0) {
        LEOcur_command->header.sense = result;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    // Get the time
    result = __locReadTimer(&time);
    if (result != 0) {
        LEOcur_command->header.sense = result;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    // Check if the time is set correctly
    if ((time.year != LEOcur_command->data.time.yearlo) || (time.month != LEOcur_command->data.time.month) ||
        (time.day != LEOcur_command->data.time.day) || (time.hour != LEOcur_command->data.time.hour) ||
        (time.minute != LEOcur_command->data.time.minute) || (time.second != LEOcur_command->data.time.second)) {
        LEOcur_command->header.sense = LEO_SENSE_ILLEGAL_TIMER_VALUE;
        LEOcur_command->header.status = LEO_STATUS_CHECK_CONDITION;
        return;
    }
    LEOcur_command->header.status = LEO_STATUS_GOOD;
}

u8 __locReadTimer(__LOCTime* time) {
    u32 data;
    u8 sense_code;

    sense_code = leoSend_asic_cmd_w(ASIC_READ_TIMER_MINUTE, 0U);
    if (sense_code != 0) {
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    time->minute = (u8)((u32)(data & 0xFF000000) >> 0x18);
    time->second = (u8)((u32)(data & 0xFF0000) >> 0x10);
    sense_code = leoSend_asic_cmd_w(ASIC_READ_TIMER_DATE, 0U);
    if (sense_code != 0) {
        time->minute &= ~0x80;
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);
    time->day = (u8)((u32)(data & 0xFF000000) >> 0x18);
    time->hour = (u8)((u32)(data & 0xFF0000) >> 0x10);
    sense_code = leoSend_asic_cmd_w(ASIC_READ_TIMER_YEAR, 0U);
    if (sense_code != 0) {
        time->minute &= ~0x80;
        return sense_code;
    }
    osEPiReadIo(LEOPiInfo, LEO_DATA, &data);

    time->year = (u8)((u32)(data & 0xFF000000) >> 0x18);
    time->month = (u8)((u32)(data & 0xFF0000) >> 0x10);
    if (time->minute & 0x80) {
        time->minute &= ~0x80;
        return 5;
    }
    return 0;
}

u8 __locSetTimer(__LOCTime* time) {
    u32 yearMonth;
    u32 dayHour;
    u32 minuteSecond;
    u8 result;

    yearMonth = (time->year << 0x18) + (time->month << 0x10);
    dayHour = (time->day << 0x18) + (time->hour << 0x10);
    minuteSecond = (time->minute << 0x18) + (time->second << 0x10);
    result = leoSend_asic_cmd_w(ASIC_SET_TIMER_YEAR, yearMonth);

    if ((result != 0) || (result = leoSend_asic_cmd_w(ASIC_SET_TIMER_DATE, dayHour),
         (result != 0)) || (result = leoSend_asic_cmd_w(ASIC_SET_TIMER_MINUTE, minuteSecond),
         (result != 0))) {
        return result;
    }
    return 0;
}
