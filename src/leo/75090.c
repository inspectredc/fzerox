#include "global.h"
#include "unk_leo.h"

s32 func_i1_804065C0(void);
extern OSMesg D_i1_80428610;
extern OSMesgQueue D_i1_8042A5E8;
extern s32 (*D_i1_8042A634)(LEOCmd*, LEODiskTime*, OSMesgQueue*);

s32 func_i1_80405F80(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    LEOCmd cmd;
    LEODiskTime diskTime;

    diskTime.pad = 0;
    diskTime.yearhi = (year > 6400) ? (year / 256) : ((year >= 150) ? 25 : 32);
    diskTime.yearlo = year % 256;
    diskTime.month = month;
    diskTime.day = day;
    diskTime.hour = hour;
    diskTime.minute = minute;
    diskTime.second = second;
    if (D_i1_8042A634(&cmd, &diskTime, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    return func_i1_804065C0();
}

s32 func_i1_80406F40(s32);

s32 func_i1_80406090(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    return func_i1_80405F80(func_i1_80406F40(year % 100), func_i1_80406F40(month), func_i1_80406F40(day),
                            func_i1_80406F40(hour), func_i1_80406F40(minute), func_i1_80406F40(second));
}

extern s32 (*D_i1_8042A630)(LEOCmd*, OSMesgQueue*);

s32 func_i1_80406168(s32* yearPtr, s32* monthPtr, s32* dayPtr, s32* hourPtr, s32* minutePtr, s32* secondPtr) {
    LEOCmd cmd;

    if (D_i1_8042A630(&cmd, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    if (func_i1_804065C0() < 0) {
        return -1;
    }
    if (yearPtr != NULL) {
        *yearPtr = cmd.data.time.yearlo;
    }
    if (monthPtr != NULL) {
        *monthPtr = cmd.data.time.month;
    }
    if (dayPtr != NULL) {
        *dayPtr = cmd.data.time.day;
    }
    if (hourPtr != NULL) {
        *hourPtr = cmd.data.time.hour;
    }
    if (minutePtr != NULL) {
        *minutePtr = cmd.data.time.minute;
    }
    if (secondPtr != NULL) {
        *secondPtr = cmd.data.time.second;
    }
    return 0;
}

s32 func_i1_80406F14(s32);

s32 func_i1_8040627C(s32* yearPtr, s32* monthPtr, s32* dayPtr, s32* hourPtr, s32* minutePtr, s32* secondPtr) {
    s32 year;
    s32 month;
    s32 day;
    s32 hour;
    s32 minute;
    s32 second;

    if (func_i1_80406168(&year, &month, &day, &hour, &minute, &second) < 0) {
        return -1;
    }
    if (yearPtr != NULL) {
        *yearPtr = func_i1_80406F14(year);
    }
    if (monthPtr != NULL) {
        *monthPtr = func_i1_80406F14(month);
    }
    if (dayPtr != NULL) {
        *dayPtr = func_i1_80406F14(day);
    }
    if (hourPtr != NULL) {
        *hourPtr = func_i1_80406F14(hour);
    }
    if (minutePtr != NULL) {
        *minutePtr = func_i1_80406F14(minute);
    }
    if (secondPtr != NULL) {
        *secondPtr = func_i1_80406F14(second);
    }
    return 0;
}

s32 func_i1_80406390(LEODiskTime* arg0) {
    LEOCmd cmd;

    if (D_i1_8042A630(&cmd, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    if (func_i1_804065C0() < 0) {
        return -1;
    }

    bcopy(&cmd.data.time, arg0, sizeof(LEODiskTime));
    return 0;
}

typedef struct unk_leo_timeformat {
    union {
        struct {
            u8 unkb0, unkb1, unkb2, unkb3;
        };
        struct {
            u16 unks0, unks2;
        };
        u32 unki1;
    };
} unk_leo_timeformat;

void func_i1_8040641C(LEODiskTime* arg0, unk_leo_timeformat* arg1) {
    s32 sp1C;

    sp1C = func_i1_80406F14(arg0->yearlo);
    if ((sp1C < 0x60) && (sp1C >= 0x16)) {
        sp1C = (s32) (sp1C + 0x4B) % 100;
    }

    arg1->unkb0 = (sp1C >= 0x60) ? ((((sp1C - 0x60) << 2) & 0xFC) | (arg1->unkb0 & 0xFF03))
                                 : ((((sp1C + 3) << 2) & 0xFC) | (arg1->unkb0 & 0xFF03));

    arg1->unks0 = (((func_i1_80406F14(arg0->month) & 0xF) << 6) & 0x3C0) | (arg1->unks0 & 0xFC3F);
    arg1->unkb1 = (((func_i1_80406F14(arg0->day) & 0x1F) * 2) & 0x3E) | (arg1->unkb1 & 0xFFC1);

    arg1->unki1 = ((((func_i1_80406F14(arg0->hour) & 0x1F) ^ (arg1->unki1 >> 0xC)) << 0x1B) >> 0xF) ^ arg1->unki1;
    arg1->unks2 = (((func_i1_80406F14(arg0->minute) & 0x3F) << 6) & 0xFC0) | (arg1->unks2 & 0xF03F);
    arg1->unkb3 = (func_i1_80406F14(arg0->second) & 0x3F & 0x3F) | (arg1->unkb3 & 0xFFC0);
}

extern s32 D_i1_80428600;
extern OSMesgQueue* D_i1_80428604;
extern OSMesg D_i1_80428608;

s32 func_i1_804065C0(void) {
    if (D_i1_80428600 != 0) {
        while (osRecvMesg(&D_i1_8042A5E8, &D_i1_80428610, OS_MESG_NOBLOCK) < 0) {
            osSendMesg(D_i1_80428604, D_i1_80428608, OS_MESG_BLOCK);
        }
    } else {
        osRecvMesg(&D_i1_8042A5E8, &D_i1_80428610, OS_MESG_BLOCK);
    }
    if (D_i1_80428610 != NULL) {
        return -1;
    }
    return 0;
}

s32 func_i1_80406688(void) {
    LEOCmd cmd;

    if (LeoRezero(&cmd, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    return func_i1_804065C0();
}

s32 func_i1_804066E4(s32 arg0) {
    LEOCmd cmd;

    if (D_i1_8042A624(&cmd, arg0, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    return func_i1_804065C0();
}

extern s32 (*D_i1_8042A628)(LEOCmd*, u8, OSMesgQueue*);

s32 func_i1_80406750(u8 arg0) {
    LEOCmd cmd;

    if (D_i1_8042A628(&cmd, arg0, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    return func_i1_804065C0();
}

s32 func_i1_804067BC(s32 arg0, s32 arg1) {
    LEOCmd cmd;

    if (D_i1_8042A638(&cmd, arg0, arg1, &D_i1_8042A5E8) < 0) {
        D_i1_80428610 = 0xF7;
        return -1;
    }
    return func_i1_804065C0();
}

extern u8 D_i1_80415190[];

s32 func_i1_80406830(s32 arg0, s32 arg1, u32 arg2) {
    LEOCmd cmd;
    s32 i;
    s32 sp24;

    if (!(arg1 & 0xF)) {
        if (D_i1_8042A620(&cmd, 0, arg0, arg1, arg2, &D_i1_8042A5E8) < 0) {
            D_i1_80428610 = 0xF7;
            return -1;
        }
        if (func_i1_804065C0() < 0) {
            return -1;
        }
        LeoLBAToByte(arg0, arg2, &sp24);
        osInvalDCache((void*) arg1, sp24);
    } else {
        for (i = 0; i < arg2; i++) {
            if (D_i1_8042A620(&cmd, 0, i + arg0, D_i1_80415190, 1, &D_i1_8042A5E8) < 0) {
                D_i1_80428610 = 0xF7;
                return -1;
            }
            if (func_i1_804065C0() < 0) {
                return -1;
            }
            LeoLBAToByte(i + arg0, 1, &sp24);
            osInvalDCache((void*) arg1, sp24);
            bcopy(D_i1_80415190, (void*) arg1, sp24);
            arg1 += sp24;
        }
    }

    return 0;
}

s32 func_i1_804069DC(s32 arg0, s32 arg1, u32 arg2) {
    LEOCmd cmd;
    s32 i;
    s32 sp24;

    if (!(arg1 & 0xF)) {
        if (D_i1_8042A620(&cmd, 1, arg0, arg1, arg2, &D_i1_8042A5E8) < 0) {
            D_i1_80428610 = 0xF7;
            return -1;
        }
        if (func_i1_804065C0() < 0) {
            return -1;
        }

    } else {
        for (i = 0; i < arg2; i++) {
            LeoLBAToByte(i + arg0, 1, &sp24);
            bcopy(arg1, D_i1_80415190, sp24);
            if (D_i1_8042A620(&cmd, 1, i + arg0, D_i1_80415190, 1, &D_i1_8042A5E8) < 0) {
                D_i1_80428610 = 0xF7;
                return -1;
            }
            if (func_i1_804065C0() < 0) {
                return -1;
            }
            arg1 += sp24;
        }
    }

    return 0;
}

// File Split?

// strcmp equivalent
s32 func_i1_80406B60(u8* s1, u8* s2) {
    u8* p1 = s1;
    u8* p2 = s2;

    while (*p1) {
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

// bcmp equivalent
s32 func_i1_80406C10(u8* b1, u8* b2, size_t length) {
    u8* p1 = b1;
    u8* p2 = b2;

    while (length != 0 && *p1 && *p2) {
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

    if (*p1 == 0 && *p2 == 0) {
        return 0;
    }

    return -1;
}

// strlen equivalent
s32 func_i1_80406D14(u8* str) {
    s32 len = 0;

    if (str == NULL) {
        return 0;
    }
    while (*str++) {
        len++;
    }

    return len;
}

// strcpy equivalent
s32 func_i1_80406D70(u8* dest, u8* src) {
    u8* p1 = dest;
    u8* p2 = src;

    while (*p2) {
        *p1++ = *p2++;
    }

    *p1 = 0;
    return 0;
}

// bcopy equivalent
s32 func_i1_80406DE4(u8* dest, u8* src, size_t length) {
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

// strcat equivalent
s32 func_i1_80406E74(u8* dest, u8* src) {
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

s32 func_i1_80406F14(s32 arg0) {
    return ((arg0 >> 4) * 10) + (arg0 & 0xF);
}

s32 func_i1_80406F40(s32 arg0) {
    return ((arg0 / 10) << 4) + (arg0 % 10);
}

s32 func_i1_80406F70(u8* arg0) {
    u8* sp1C;

    if ((arg0 == NULL) || (*arg0 == 0)) {
        return -1;
    }
    if (func_i1_80406D14(arg0) >= 0x15) {
        return -1;
    }

    for (sp1C = arg0; *sp1C != 0; sp1C++) {
        if (*sp1C == 0x2F) {
            return -1;
        }
        if ((((*sp1C >= 0x20 && *sp1C < 0x7F) || (*sp1C >= 0xA1 && *sp1C < 0xE0)) && (*sp1C != 0x2F))) {
            continue;
        }
        if (*sp1C >= 0x81 && *sp1C < 0x99) {
            sp1C++;
            if (*sp1C >= 0x40 && *sp1C < 0xFD && *sp1C != 0x7F) {
                continue;
            }
            return -1;
        }
        return -1;
    }

    return 0;
}

extern u16 D_i1_80428520[];

s16 func_i1_804070EC(s32 arg0) {
    if ((arg0 >= 0x21) && (arg0 < 0x7F)) {
        return (s16) (arg0 - 0x20);
    }
    if ((arg0 >= 0xA1) && (arg0 < 0xE0)) {
        return D_i1_80428520[arg0];
    }
    return 0;
}
