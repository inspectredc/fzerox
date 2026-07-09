#include "leo/leo_internal.h"
#include "leo/mfs.h"

s32 Mfs_SetRtc(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    LEOCmd cmdBlock;
    LEODiskTime diskTime;

    diskTime.pad = 0;
    diskTime.yearhi = (year > 6400) ? (year / 256) : ((year >= 150) ? 25 : 32);
    diskTime.yearlo = year % 256;
    diskTime.month = month;
    diskTime.day = day;
    diskTime.hour = hour;
    diskTime.minute = minute;
#if MFS_VERSION == MFS_VERSION_A
    diskTime.second = second;
#else
    diskTime.second = second / 2;
#endif

#if MFS_VERSION == MFS_VERSION_C
    D_80794CD8 = 10;
    if (D_80794D48) {
        return 0;
    }
#endif
    if (gLeoSetRTCFunc(&cmdBlock, &diskTime, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}

s32 Mfs_EncodeAndSetRtc(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    return Mfs_SetRtc(Mfs_EncodeTime(year % 100), Mfs_EncodeTime(month), Mfs_EncodeTime(day), Mfs_EncodeTime(hour),
                      Mfs_EncodeTime(minute), Mfs_EncodeTime(second));
}

#if MFS_VERSION == MFS_VERSION_C
LEODiskTime sLeoDiskTime;
#endif

s32 func_i1_80406168(s32* year, s32* month, s32* day, s32* hour, s32* minute, s32* second) {
    LEOCmd cmdBlock;

#if MFS_VERSION == MFS_VERSION_C
    D_80794CD8 = 9;
    if (D_80794D48) {
        if (year != NULL) {
            *year = sLeoDiskTime.yearlo;
        }
        if (month != NULL) {
            *month = sLeoDiskTime.month;
        }
        if (day != NULL) {
            *day = sLeoDiskTime.day;
        }
        if (hour != NULL) {
            *hour = sLeoDiskTime.hour;
        }
        if (minute != NULL) {
            *minute = sLeoDiskTime.minute;
        }
        if (second != NULL) {
            *second = sLeoDiskTime.second;
        }
    } else {
#endif
        if (gLeoReadRTCFunc(&cmdBlock, &D_i1_8042A5E8) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_i1_804065C0() < 0) {
            return -1;
        }
        if (year != NULL) {
            *year = cmdBlock.data.time.yearlo;
        }
        if (month != NULL) {
            *month = cmdBlock.data.time.month;
        }
        if (day != NULL) {
            *day = cmdBlock.data.time.day;
        }
        if (hour != NULL) {
            *hour = cmdBlock.data.time.hour;
        }
        if (minute != NULL) {
            *minute = cmdBlock.data.time.minute;
        }
        if (second != NULL) {
            *second = cmdBlock.data.time.second;
        }
#if MFS_VERSION == MFS_VERSION_C
    }
#endif
    return 0;
}

s32 func_i1_8040627C(s32* year, s32* month, s32* day, s32* hour, s32* minute, s32* second) {
    s32 yearE;
    s32 monthE;
    s32 dayE;
    s32 hourE;
    s32 minuteE;
    s32 secondE;

    if (func_i1_80406168(&yearE, &monthE, &dayE, &hourE, &minuteE, &secondE) < 0) {
        return -1;
    }
    if (year != NULL) {
        *year = Mfs_DecodeTime(yearE);
    }
    if (month != NULL) {
        *month = Mfs_DecodeTime(monthE);
    }
    if (day != NULL) {
        *day = Mfs_DecodeTime(dayE);
    }
    if (hour != NULL) {
        *hour = Mfs_DecodeTime(hourE);
    }
    if (minute != NULL) {
        *minute = Mfs_DecodeTime(minuteE);
    }
    if (second != NULL) {
        *second = Mfs_DecodeTime(secondE);
    }
    return 0;
}

s32 Mfs_ReadRtc(LEODiskTime* diskTime) {
    LEOCmd cmdBlock;

#if MFS_VERSION == MFS_VERSION_C
    D_80794CD8 = 9;
    if (D_80794D48) {
        bcopy(&sLeoDiskTime, diskTime, sizeof(LEODiskTime));
    } else {
#endif
        if (gLeoReadRTCFunc(&cmdBlock, &D_i1_8042A5E8) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_i1_804065C0() < 0) {
            return -1;
        }

        bcopy(&cmdBlock.data.time, diskTime, sizeof(LEODiskTime));
#if MFS_VERSION == MFS_VERSION_C
    }
#endif

    return 0;
}

void Mfs_LEODiskTimeToMfsTime(LEODiskTime* diskTime, MfsTimeFormat* mfsTime) {
    s32 sp1C;

    sp1C = Mfs_DecodeTime(diskTime->yearlo);
    if ((sp1C < 0x60) && (sp1C >= 0x16)) {
        sp1C = (sp1C + 0x4B) % 100;
    }

#if MFS_VERSION == MFS_VERSION_A
    mfsTime->unkb0 = (sp1C >= 0x60) ? ((((sp1C - 0x60) << 2) & 0xFC) | (mfsTime->unkb0 & 0xFF03))
                                    : ((((sp1C + 3) << 2) & 0xFC) | (mfsTime->unkb0 & 0xFF03));

    mfsTime->unks0 = (((Mfs_DecodeTime(diskTime->month) & 0xF) << 6) & 0x3C0) | (mfsTime->unks0 & 0xFC3F);
    mfsTime->unkb1 = (((Mfs_DecodeTime(diskTime->day) & 0x1F) * 2) & 0x3E) | (mfsTime->unkb1 & 0xFFC1);

    mfsTime->unki0 =
        ((((Mfs_DecodeTime(diskTime->hour) & 0x1F) ^ (mfsTime->unki0 >> 0xC)) << 0x1B) >> 0xF) ^ mfsTime->unki0;
    mfsTime->unks2 = (((Mfs_DecodeTime(diskTime->minute) & 0x3F) << 6) & 0xFC0) | (mfsTime->unks2 & 0xF03F);
    mfsTime->unkb3 = (Mfs_DecodeTime(diskTime->second) & 0x3F & 0x3F) | (mfsTime->unkb3 & 0xFFC0);
#else
    mfsTime->unkb0 = (sp1C >= 0x60) ? ((((sp1C - 0x60) << 1) & 0xFE) | (mfsTime->unkb0 & 0xFF01))
                                    : ((((sp1C + 3) << 1) & 0xFE) | (mfsTime->unkb0 & 0xFF01));

    mfsTime->unks0 = (((Mfs_DecodeTime(diskTime->month) & 0xF) << 5) & 0x1E0) | (mfsTime->unks0 & 0xFE1F);
    mfsTime->unkb1 = (Mfs_DecodeTime(diskTime->day) & 0x1F & 0x1F) | (mfsTime->unkb1 & 0xFFE0);

    mfsTime->unkb2 = ((((Mfs_DecodeTime(diskTime->hour) & 0x1F) << 3) & 0xF8) | (mfsTime->unkb2 & 0xFF07));
    mfsTime->unks2 = (((Mfs_DecodeTime(diskTime->minute) & 0x3F) << 5) & 0x7E0) | (mfsTime->unks2 & 0xF81F);
#if MFS_VERSION == MFS_VERSION_B
    mfsTime->unkb3 = ((Mfs_DecodeTime(diskTime->second / 2)) & 0x1F & 0x1F) | (mfsTime->unkb3 & 0xFFE0);
#else
    mfsTime->unkb3 = ((Mfs_DecodeTime(diskTime->second) / 2) & 0x1F & 0x1F) | (mfsTime->unkb3 & 0xFFE0);
#endif
#endif
}

#if MFS_VERSION == MFS_VERSION_C
void func_80762330(LEODiskTime* diskTime) {
    if (diskTime == NULL) {
        D_80794D48 = false;
        return;
    }
    D_80794D48 = true;
    bcopy(diskTime, &sLeoDiskTime, sizeof(LEODiskTime));
}
#endif
