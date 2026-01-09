#include "leo/mfs.h"

void Mfs_DecodeFile(LEODiskID* diskId, u8* buf, s32 size) {
    s32 j;
    s32 i;
    u8 diskIdBuf[0x20];
    u8* sp1C;

    sp1C = buf;
    bcopy(diskId, diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }
    *sp1C ^= 0x59;

    *sp1C = (((*sp1C & 0x1F) << 3) | (*sp1C & 0xE0) >> 5) & 0xFF;

    for (j = 1; j < size; j++) {
        sp1C[j] =
            ((sp1C[j] + (((((sp1C[j - 1] ^ 0xBF) & 0xF) << 4) | (((sp1C[j - 1] ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF) ^
            diskIdBuf[j & 0x1F];
    }

    *sp1C = *sp1C ^ diskIdBuf[0x17];

    i = 0;
    while (i < size) {
        sp1C[i] = (sp1C[i] ^ 0xFE) + 0x6F;
        i = ((sp1C[i] & 0xF) >> 1) + i + 4;
    }
}

void Mfs_EncodeFile(LEODiskID* diskId, u8* buf, s32 size) {
    s32 j;
    s32 i;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    u8 diskIdBuf[0x20];
    u8* sp18;

    sp18 = buf;
    bcopy(diskId, &diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }

    i = 0;
    while (i < size) {
        sp44 = ((sp18[i] & 0xF) >> 1) + i + 4;
        sp18[i] = ((sp18[i] - 0x6F) & 0xFF) ^ 0xFE;
        i = sp44;
    }
    *sp18 = *sp18 ^ diskIdBuf[0x17];
    sp40 = *sp18;

    for (j = 1; j < size; j++) {
        sp3C = sp18[j];
        sp3C ^= diskIdBuf[j & 0x1F];
        sp3C = (sp3C - (((((sp40 ^ 0xBF) & 0xF) << 4) | (((sp40 ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF;
        sp40 = sp18[j];
        sp18[j] = sp3C;
    }

    *sp18 = (((*sp18 & 7) << 5) | ((*sp18 & 0xF8) >> 3)) & 0xFF;
    *sp18 ^= 0x59;
}

s32 Mfs_DecodeWriteFile(u8* buf, s32 size) {
    LEODiskID diskId;

    if (Mfs_ReadDiskId(&diskId) < 0) {
        return -1;
    }
    Mfs_DecodeFile(&diskId, buf, size);
    return 0;
}

s32 Mfs_DecodeReadFile(u8* buf, s32 size) {
    LEODiskID diskId;

    if (Mfs_ReadDiskId(&diskId) < 0) {
        return -1;
    }
    Mfs_DecodeFile(&diskId, buf, size);
    return 0;
}

s32 Mfs_WriteFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded) {
    s32 i;
    s32 lba;
    s32 size;
    u8* bufPtr;

    if (isEncoded) {
        lba = startLBA;
        bufPtr = buf;
        for (i = 0; i < nLBAs; i++, lba++) {

            LeoLBAToByte(lba, 1, &size);
            if (D_i1_80415190 != buf) {
                bcopy(bufPtr, D_i1_80415190, size);
            }
            Mfs_DecodeWriteFile(D_i1_80415190, size);
            if (Mfs_WriteLBA(lba, D_i1_80415190, 1) < 0) {
                return -1;
            }
            bufPtr += size;
        }
    } else {
        return Mfs_WriteLBA(startLBA, buf, nLBAs);
    }

    return 0;
}

s32 Mfs_ReadFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded) {
    s32 i;
    s32 lba;
    s32 size;
    u8* bufPtr;

    if (isEncoded) {
        lba = startLBA;
        bufPtr = buf;
        for (i = 0; i < nLBAs; i++, lba++) {
            LeoLBAToByte(lba, 1, &size);
            if (Mfs_ReadLBA(lba, D_i1_80415190, 1) < 0) {
                return -1;
            }
            Mfs_DecodeReadFile(D_i1_80415190, size);
            if (D_i1_80415190 != buf) {
                bcopy(D_i1_80415190, bufPtr, size);
            }
            bufPtr += size;
        }
    } else {
        return Mfs_ReadLBA(startLBA, buf, nLBAs);
    }
    return 0;
}
