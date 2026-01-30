#include "leo/leo_internal.h"
#include "leo/mfs.h"
#include "libc/stdint.h"

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
#else // MFS_VERSION_B
    diskTime.second = second / 2;
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

#if MFS_VERSION == MFS_VERSION_B
LEODiskTime sLeoDiskTime;
#endif

s32 func_i1_80406168(s32* year, s32* month, s32* day, s32* hour, s32* minute, s32* second) {
    LEOCmd cmdBlock;

#if MFS_VERSION == MFS_VERSION_B
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
#if MFS_VERSION == MFS_VERSION_B
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

#if MFS_VERSION == MFS_VERSION_B
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
#if MFS_VERSION == MFS_VERSION_B
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
#else // MFS_VERSION_B
    mfsTime->unkb0 = (sp1C >= 0x60) ? ((((sp1C - 0x60) << 1) & 0xFE) | (mfsTime->unkb0 & 0xFF01))
                                    : ((((sp1C + 3) << 1) & 0xFE) | (mfsTime->unkb0 & 0xFF01));

    mfsTime->unks0 = (((Mfs_DecodeTime(diskTime->month) & 0xF) << 5) & 0x1E0) | (mfsTime->unks0 & 0xFE1F);
    mfsTime->unkb1 = (Mfs_DecodeTime(diskTime->day) & 0x1F & 0x1F) | (mfsTime->unkb1 & 0xFFE0);

    mfsTime->unkb2 = ((((Mfs_DecodeTime(diskTime->hour) & 0x1F) << 3) & 0xF8) | (mfsTime->unkb2 & 0xFF07));
    mfsTime->unks2 = (((Mfs_DecodeTime(diskTime->minute) & 0x3F) << 5) & 0x7E0) | (mfsTime->unks2 & 0xF81F);
    mfsTime->unkb3 = ((Mfs_DecodeTime(diskTime->second) / 2) & 0x1F & 0x1F) | (mfsTime->unkb3 & 0xFFE0);
#endif
}

#if MFS_VERSION == MFS_VERSION_B
void func_80762330(LEODiskTime* diskTime) {
    if (diskTime == NULL) {
        D_80794D48 = false;
        return;
    }
    D_80794D48 = true;
    bcopy(diskTime, &sLeoDiskTime, sizeof(LEODiskTime));
}
#endif

s32 func_i1_804065C0(void) {
    if (D_i1_80428600 != 0) {
        while (osRecvMesg(&D_i1_8042A5E8, &gMfsError, OS_MESG_NOBLOCK) < 0) {
            osSendMesg(D_i1_80428604, D_i1_80428608, OS_MESG_BLOCK);
        }
    } else {
        osRecvMesg(&D_i1_8042A5E8, &gMfsError, OS_MESG_BLOCK);
    }
    if (gMfsError != LEO_ERROR_GOOD) {
        return -1;
    }
    return 0;
}

#if MFS_VERSION == MFS_VERSION_A
s32 Mfs_Rezero(void) {
    LEOCmd cmdBlock;

    if (LeoRezero(&cmdBlock, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}

s32 Mfs_Seek(s32 lba) {
    LEOCmd cmdBlock;

    if (gLeoSeekFunc(&cmdBlock, lba, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}
#endif

s32 Mfs_SpdlMotor(LEOSpdlMode mode) {
    LEOCmd cmdBlock;

#if MFS_VERSION == MFS_VERSION_B
    if (mode == LEO_MOTOR_SLEEP) {
        D_80794CD8 = 6;
    } else {
        D_80794CD8 = 7;
    }
#endif

    if (gLeoSpdlMotorFunc(&cmdBlock, mode, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}

s32 Mfs_ModeSelectAsync(s32 standby, s32 sleep) {
    LEOCmd cmdBlock;

#if MFS_VERSION == MFS_VERSION_B
    D_80794CD8 = 0xB;
#endif
    if (gLeoModeSelectAsyncFunc(&cmdBlock, standby, sleep, &D_i1_8042A5E8) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_i1_804065C0();
}

s32 Mfs_ReadLBA(u32 startLBA, u8* buf, u32 nLBAs) {
    LEOCmd cmdBlock;
    s32 i;
    s32 bufSize;
#if MFS_VERSION == MFS_VERSION_B
    u8* bufStart = buf;
#endif

    if (!((uintptr_t) buf & 0xF)) {
#if MFS_VERSION == MFS_VERSION_B
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osInvalDCache(buf, bufSize);
        D_80794CD8 = 2;
#endif
        if (gLeoReadWriteFunc(&cmdBlock, OS_READ, startLBA, buf, nLBAs, &D_i1_8042A5E8) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_i1_804065C0() < 0) {
            return -1;
        }
#if MFS_VERSION == MFS_VERSION_A
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osInvalDCache(buf, bufSize);
#else // MFS_VERSION_B
        osWritebackDCache(buf, bufSize);
#endif
    } else {
#if MFS_VERSION == MFS_VERSION_B
        osInvalDCache(D_i1_80415190, sizeof(D_i1_80415190));
#endif
        for (i = 0; i < nLBAs; i++) {
#if MFS_VERSION == MFS_VERSION_B
            LeoLBAToByte(startLBA + i, 1, &bufSize);
            D_80794CD8 = 2;
#endif
            if (gLeoReadWriteFunc(&cmdBlock, OS_READ, i + startLBA, D_i1_80415190, 1, &D_i1_8042A5E8) < 0) {
                gMfsError = N64DD_MANAGER_NOT_CREATED;
                return -1;
            }
            if (func_i1_804065C0() < 0) {
                return -1;
            }
#if MFS_VERSION == MFS_VERSION_A
            LeoLBAToByte(i + startLBA, 1, &bufSize);
            osInvalDCache(buf, bufSize);
#endif
            bcopy(D_i1_80415190, buf, bufSize);
            buf += bufSize;
        }

#if MFS_VERSION == MFS_VERSION_B
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osWritebackDCache(bufStart, bufSize);
#endif
    }

    return 0;
}

s32 Mfs_WriteLBA(u32 startLBA, u8* buf, u32 nLBAs) {
    LEOCmd cmdBlock;
    s32 i;
    s32 bufSize;

    if (!((uintptr_t) buf & 0xF)) {
#if MFS_VERSION == MFS_VERSION_B
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osWritebackDCache(buf, bufSize);
        D_80794CD8 = 3;
#endif
        if (gLeoReadWriteFunc(&cmdBlock, OS_WRITE, startLBA, buf, nLBAs, &D_i1_8042A5E8) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_i1_804065C0() < 0) {
            return -1;
        }

    } else {
#if MFS_VERSION == MFS_VERSION_B
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osWritebackDCache(buf, bufSize);
#endif
        for (i = 0; i < nLBAs; i++) {
            LeoLBAToByte(startLBA + i, 1, &bufSize);
            bcopy(buf, D_i1_80415190, bufSize);
#if MFS_VERSION == MFS_VERSION_B
            osWritebackDCache(D_i1_80415190, sizeof(D_i1_80415190));
            D_80794CD8 = 3;
#endif
            if (gLeoReadWriteFunc(&cmdBlock, OS_WRITE, startLBA + i, D_i1_80415190, 1, &D_i1_8042A5E8) < 0) {
                gMfsError = N64DD_MANAGER_NOT_CREATED;
                return -1;
            }
            if (func_i1_804065C0() < 0) {
                return -1;
            }
            buf += bufSize;
        }
    }

    return 0;
}

s32 mfsStrCmp(u8* s1, u8* s2) {
    u8* p1 = s1;
    u8* p2 = s2;

    while (*p1 != 0) {
        if (*p1 < *p2) {
            return -1;
        }
        if (*p1++ > *p2++) {
            return 1;
        }
    }

    if (*p2 == 0) {
        return 0;
    }
    return -1;
}

s32 mfsStrnCmp(u8* b1, u8* b2, size_t length) {
    u8* p1 = b1;
    u8* p2 = b2;

    while ((length != 0) && (*p1 != 0) && (*p2 != 0)) {
        if (*p1 < *p2) {
            return -1;
        }
        if (*p1++ > *p2++) {
            return 1;
        }
        length--;
    }

    if (length == 0) {
        return 0;
    }

    if ((*p1 == 0) && (*p2 == 0)) {
        return 0;
    }
    
#if MFS_VERSION == MFS_VERSION_A
    return -1;
#else
    return (*p1 != 0) ? 1 : -1;
#endif
}

s32 mfsStrLen(u8* str) {
    s32 len = 0;

    if (str == NULL) {
        return 0;
    }
    while (*str++) {
        len++;
    }

    return len;
}

s32 mfsStrCpy(u8* dest, u8* src) {
    u8* p1 = dest;
    u8* p2 = src;

    while (*p2) {
        *p1++ = *p2++;
    }

    *p1 = 0;
    return 0;
}

s32 mfsStrnCpy(u8* dest, u8* src, size_t length) {
    u8* p1 = dest;
    u8* p2 = src;
    size_t i;

    i = 0;
    while (*p2) {
        *p1++ = *p2++;

        if (++i == length) {
            return 0;
        }
    }

    *p1 = 0;
    return 0;
}

s32 mfsStrCat(u8* dest, u8* src) {
    u8* p1 = dest;
    u8* p2 = src;

    while (*p1) {
        p1++;
    }
    while (*p2) {
        *p1++ = *p2++;
    }

    *p1 = 0;
    return 0;
}

s32 Mfs_DecodeTime(s32 timeUnit) {
    return ((timeUnit >> 4) * 10) + (timeUnit & 0xF);
}

s32 Mfs_EncodeTime(s32 timeUnit) {
    return ((timeUnit / 10) << 4) + (timeUnit % 10);
}
