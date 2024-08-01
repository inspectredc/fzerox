#include "global.h"
#include "unk_leo.h"

s32 func_i1_80404108(LEODiskID*);
s32 func_i1_804069DC(s32, u8*, u32);
s32 func_i1_80406830(s32, u8*, u32);
extern u8 D_i1_80415190[];

// Decode and encode functions?
void func_i1_8040A070(LEODiskID* arg0, u8* arg1, s32 arg2) {
    s32 j;
    s32 i;
    u8 diskIdBuf[0x20];
    u8* sp1C;

    sp1C = arg1;
    bcopy(arg0, diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }
    *sp1C ^= 0x59;

    *sp1C = (((*sp1C & 0x1F) << 3) | (*sp1C & 0xE0) >> 5) & 0xFF;

    for (j = 1; j < arg2; j++) {
        sp1C[j] = ((sp1C[j] + (((((sp1C[j - 1] ^ 0xBF) & 0xF) << 4) | (((sp1C[j - 1] ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF) ^ diskIdBuf[j & 0x1F];
    }

    *sp1C = *sp1C ^ diskIdBuf[0x17];

    i = 0;
    while (i < arg2) {
        sp1C[i] = (sp1C[i] ^ 0xFE) + 0x6F;
        i = ((sp1C[i] & 0xF) >> 1) + i + 4;
    }
}

void func_i1_8040A220(LEODiskID* arg0, u8* arg1, s32 arg2) {
    s32 j;
    s32 i;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    u8 diskIdBuf[0x20];
    u8* sp18;

    sp18 = arg1;
    bcopy(arg0, &diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }

    i = 0;
    while (i < arg2) {
        sp44 = ((sp18[i] & 0xF) >> 1) + i + 4;
        sp18[i] = ((sp18[i] - 0x6F) & 0xFF) ^ 0xFE;
        i = sp44;
    }
    *sp18 = *sp18 ^ diskIdBuf[0x17];
    sp40 = *sp18;

    for (j = 1; j < arg2; j++) {
        sp3C = sp18[j];
        sp3C ^= diskIdBuf[j & 0x1F];
        sp3C = (sp3C - (((((sp40 ^ 0xBF) & 0xF) << 4) | (((sp40 ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF;
        sp40 = sp18[j];
        sp18[j] = sp3C;
    }

    *sp18 = (((*sp18 & 7) << 5) | ((*sp18 & 0xF8) >> 3)) & 0xFF;
    *sp18 ^= 0x59;
}

s32 func_i1_8040A424(u8* buf, size_t size) {
    LEODiskID diskId;

    if (func_i1_80404108(&diskId) < 0) {
        return -1;
    }
    func_i1_8040A070(&diskId, buf, size);
    return 0;
}

s32 func_i1_8040A47C(u8* buf, size_t size) {
    LEODiskID diskId;

    if (func_i1_80404108(&diskId) < 0) {
        return -1;
    }
    func_i1_8040A070(&diskId, buf, size);
    return 0;
}

s32 func_i1_8040A4D4(s32 arg0, u8* arg1, u32 arg2, s32 arg3) {
    u32 sp24;
    s32 sp20;
    s32 sp1C;
    u8* sp18;

    if (arg3 != 0) {
        sp20 = arg0;
        sp18 = arg1;

        for (sp24 = 0; sp24 < arg2; sp24++, sp20++) {
            LeoLBAToByte(sp20, 1, &sp1C);
            if (D_i1_80415190 != arg1) {
                bcopy(sp18, D_i1_80415190, sp1C);
            }
            func_i1_8040A424(D_i1_80415190, sp1C);
            if (func_i1_804069DC(sp20, D_i1_80415190, 1) < 0) {
                return -1;
            }
            sp18 += sp1C;
        }
    } else {
        return func_i1_804069DC(arg0, arg1, arg2);
    }

    return 0;
}

s32 func_i1_8040A5F8(s32 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    u8* sp18;

    if (arg3 != 0) {
        sp20 = arg0;
        sp18 = arg1;

        for (sp24 = 0; sp24 < arg2; sp24++, sp20++) {
            LeoLBAToByte(sp20, 1, &sp1C);
            if (func_i1_80406830(sp20, D_i1_80415190, 1) < 0) {
                return -1;
            }
            func_i1_8040A47C(D_i1_80415190, sp1C);
            if (D_i1_80415190 != arg1) {
                bcopy(D_i1_80415190, sp18, sp1C);
            }
            sp18 += sp1C;
        }
    } else {
        return func_i1_80406830(arg0, arg1, arg2);    
    }
        
    return 0;
}
