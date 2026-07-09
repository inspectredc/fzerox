#include "leo/leo_internal.h"
#include "leo/mfs.h"
#include "libc/stdint.h"

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

#if MFS_VERSION <= MFS_VERSION_B
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

#if MFS_VERSION == MFS_VERSION_C
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

#if MFS_VERSION == MFS_VERSION_C
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
#if MFS_VERSION == MFS_VERSION_C
    u8* bufStart = buf;
#endif

    if (!((uintptr_t) buf & 0xF)) {
#if MFS_VERSION == MFS_VERSION_C
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
#if MFS_VERSION <= MFS_VERSION_B
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osInvalDCache(buf, bufSize);
#else
        osWritebackDCache(buf, bufSize);
#endif
    } else {
#if MFS_VERSION == MFS_VERSION_C
        osInvalDCache(D_i1_80415190, sizeof(D_i1_80415190));
#endif
        for (i = 0; i < nLBAs; i++) {
#if MFS_VERSION == MFS_VERSION_C
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
#if MFS_VERSION <= MFS_VERSION_B
            LeoLBAToByte(i + startLBA, 1, &bufSize);
            osInvalDCache(buf, bufSize);
#endif
            bcopy(D_i1_80415190, buf, bufSize);
            buf += bufSize;
        }

#if MFS_VERSION == MFS_VERSION_C
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
#if MFS_VERSION == MFS_VERSION_C
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
#if MFS_VERSION == MFS_VERSION_C
        LeoLBAToByte(startLBA, nLBAs, &bufSize);
        osWritebackDCache(buf, bufSize);
#endif
        for (i = 0; i < nLBAs; i++) {
            LeoLBAToByte(startLBA + i, 1, &bufSize);
            bcopy(buf, D_i1_80415190, bufSize);
#if MFS_VERSION == MFS_VERSION_C
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
