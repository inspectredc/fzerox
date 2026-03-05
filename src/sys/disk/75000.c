#include "global.h"
#include "leo/mfs.h"

OSMesgQueue D_807C6E90;
volatile unk_807C6EA8 D_807C6EA8;
volatile s32 D_807C6F0C;
unk_807C6F10 D_807C6F10[8];

volatile u8 D_80794E10 = 0;
u8 D_80794E14 = 0;
u8 D_80794E18 = 0;
volatile u8 D_80794E1C = 0;
volatile u8 D_80794E20 = 0;
volatile u8 D_80794E24 = 0;
volatile s32 D_80794E28 = 0;
volatile s32 D_80794E2C = 0;

void func_80767800(unk_807C6F10 arg0) {
    OSIntMask prevMask;
    s32 temp_lo;

    do {
    } while (D_80794E28 == ((D_80794E2C + 1) & 7));
    prevMask = osGetIntMask();
    osSetIntMask(OS_IM_NONE);
    D_80794E2C &= 7;
    D_807C6F10[D_80794E2C] = arg0;
    temp_lo = D_80794E2C;
    D_80794E2C = (D_80794E2C + 1) & 7;
    osSendMesg(&D_807C6E90, &D_807C6F10[temp_lo], OS_MESG_BLOCK);
    osSetIntMask(prevMask);
}

void func_80767900(void) {
    if (D_80794E2C != D_80794E28) {
        D_80794E28++;
        D_80794E28 &= 7;
    }
}

void func_80767940(void) {
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

OSMesg D_807C7030[8];

#ifdef NON_MATCHING
void func_80767958(void* entry) {
    static unk_807C6F10* D_807C7050;
    static OSMesgQueue D_807C7058;
    static OSMesg D_807C7070;
    static unk_807C6F10* D_807C7074;
    static OSMesg D_807C7078;
    static OSMesgQueue* D_807C707C;
    OSIoMesg* temp_v0_2;
    s32 temp_v0;
    s32 temp_v0_3;
    unk_807C6F10* temp_s0;
    unk_807C6F10* temp_v1;

    osCreateMesgQueue(&D_807C6E90, D_807C7030, ARRAY_COUNT(D_807C7030));
    osCreateMesgQueue(&D_807C7058, &D_807C7070, 1);
    func_80767940();

    while (true) {
        osRecvMesg(&D_807C6E90, &D_807C7050, 1);
        temp_v1 = D_807C7050;
        D_80794E14 = 1;
        if (temp_v1 != NULL) {
            temp_s0 = D_807C7050;
            func_80767900();
            switch (temp_s0->unk_00) {
                case 0:
                    D_807C7074 = temp_s0;
                    SLLeoReadWrite(D_807C7074->cmdBlock, D_807C7074->direction, D_807C7074->lba, D_807C7074->vAddr,
                                   D_807C7074->nLBAs, &D_807C7058);
                    osRecvMesg(&D_807C7058, &D_807C7078, OS_MESG_BLOCK);
                    osSendMesg(D_807C7074->mq, D_807C7078, OS_MESG_BLOCK);
                    break;
                case 1:
                    D_807C7074 = temp_s0;
                    SLLeoReadWrite_DATA(D_807C7074->cmdBlock, D_807C7074->direction, D_807C7074->lba, D_807C7074->vAddr,
                                        D_807C7074->nLBAs, &D_807C7058);
                    osRecvMesg(&D_807C7058, &D_807C7078, OS_MESG_BLOCK);
                    osSendMesg(D_807C7074->mq, D_807C7078, OS_MESG_BLOCK);
                    break;
                case 2:
                case 3:
                    D_807C7074 = temp_s0;
                    temp_v0_2 = D_807C7074->ioMesg;
                    D_807C707C = temp_v0_2->hdr.retQueue;
                    temp_v0_2->hdr.retQueue = &D_807C7058;
                    osInvalDCache(osPhysicalToVirtual(D_807C7074->ioMesg->dramAddr), D_807C7074->ioMesg->size);
                    osEPiStartDma(D_807C7074->piHandle, D_807C7074->ioMesg, D_807C7074->direction);
                    osRecvMesg(&D_807C7058, NULL, OS_MESG_BLOCK);
                    osSendMesg(D_807C707C, NULL, OS_MESG_BLOCK);
                    break;
                default:
                    D_807C7074 = temp_s0;
                    break;
            }
            D_80794E14 = 0;
            continue;
        }
        D_80794E18 = 1;
        if (D_807C6EA8.unk_00 == 4) {
            SLMFSSave(D_807C6EA8.dirId, D_807C6EA8.name, D_807C6EA8.extension, D_807C6EA8.readBuf, D_807C6EA8.fileSize,
                      D_807C6EA8.attr, D_807C6EA8.copyCount, D_807C6EA8.writeChanges);
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 5) {
            func_xk2_800EB938(D_807C6EA8.dirId, D_807C6EA8.name, D_807C6EA8.extension, D_807C6EA8.readBuf,
                              D_807C6EA8.fileSize, D_807C6EA8.attr, D_807C6EA8.copyCount, D_807C6EA8.writeChanges);
            func_80767940();
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 6) {
            SLMFSLoad(D_807C6EA8.dirId, D_807C6EA8.name, D_807C6EA8.extension, D_807C6EA8.writeBuf,
                      D_807C6EA8.fileSize);
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 7) {
            SLMFSLoadHalfway(D_807C6EA8.dirId, D_807C6EA8.name, D_807C6EA8.extension, D_807C6EA8.writeBuf,
                             D_807C6EA8.offset, D_807C6EA8.fileSize);
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 0) {
            func_800750B0(D_807C6EA8.startLba, D_807C6EA8.lbaBuf, D_807C6EA8.fileSize, D_807C6EA8.bssSize);
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 1) {
            func_80706518(D_807C6EA8.copyCount, D_807C6EA8.unk_54, D_807C6EA8.extension);
            func_80767940();
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 2) {
            SLMFSFlushManageArea();
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_00 == 3) {
            SLMFSNewDisk();
            D_80794E14 = D_80794E18 = 0;
            continue;
        }
        if (D_807C6EA8.unk_10 == 4) {

        } else {
            D_807C6EA8.unk_10 = 1;
        }

        temp_v0_3 = func_xk1_8002E368();
        switch (temp_v0_3) {
            case LEO_ERROR_GOOD:
                D_807C6EA8.unk_10 = 0;
                D_80794E14 = 0;
                D_80794E18 = 0;
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                D_807C6EA8.unk_10 = 2;
                break;
            case LEO_ERROR_COMMAND_PHASE_ERROR:
                D_807C6EA8.unk_10 = 3;
                break;
            case LEO_ERROR_DATA_PHASE_ERROR:
                D_807C6EA8.unk_10 = 4;
                D_807C6EA8.unk_08 = 3;
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
                func_8070F8A4(temp_v0_3, 0);
                while (true) {}
            default:
                break;
        }
    }
}
#else
unk_807C6F10* D_807C7050;
OSMesgQueue D_807C7058;
OSMesg D_807C7070;
unk_807C6F10* D_807C7074;
OSMesg D_807C7078;
OSMesgQueue* D_807C707C;
#pragma GLOBAL_ASM("asm/jp/ek/nonmatchings/sys/disk/75000/func_80767958.s")
#endif

s32 func_80767E30(void) {
    if (D_80794E18 == 0) {
        return 0;
    }
    switch (D_807C6EA8.unk_08) {
        case 0:
            return 0;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 14:
        case 15:
            D_807C6EA8.unk_08 = 9;
            return 1;
        default:
            return 1;
    }
}

void func_80767E98(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {

    D_807C6EA8.dirId = dirId;
    D_807C6EA8.name = name;
    D_807C6EA8.extension = extension;
    D_807C6EA8.readBuf = buf;
    D_807C6EA8.fileSize = fileSize;
    D_807C6EA8.attr = attr;
    D_807C6EA8.copyCount = copyCount;
    D_807C6EA8.writeChanges = writeChanges;
    osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
}

void func_80767F14(u16 dirId, char* name, char* extension, void* buf, s32 fileSize) {
    D_807C6EA8.dirId = dirId;
    D_807C6EA8.name = name;
    D_807C6EA8.extension = extension;
    D_807C6EA8.writeBuf = buf;
    D_807C6EA8.fileSize = fileSize;
    osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
}

void func_80767F78(s32 startLba, s32 lbaBuf, s32 fileSize, s32 bssSize) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 0;
        D_807C6EA8.startLba = startLba;
        D_807C6EA8.lbaBuf = lbaBuf;
        D_807C6EA8.fileSize = fileSize;
        D_807C6EA8.bssSize = bssSize;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_80767FE4(s32 copyCount, u8 arg1, char* extension) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 1;
        D_807C6EA8.unk_04 = 0;
        D_807C6EA8.unk_08 = 0;
        D_807C6EA8.unk_0C = 4;
        D_807C6EA8.copyCount = copyCount;
        D_807C6EA8.unk_54 = arg1;
        D_807C6EA8.extension = extension;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_8076805C(void) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 2;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_807680A4(void) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 3;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_807680EC(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 4;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_8076814C(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 5;
        D_807C6EA8.unk_08 = 6;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_807681C8(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 5;
        D_807C6EA8.unk_08 = 7;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_80768244(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 6;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_807682C0(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 10;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_8076833C(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 25;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_807683B8(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 26;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_80768434(u16 dirId, char* name, char* extension, void* buf, s32 fileSize, s32 attr, s32 copyCount,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 8;
        func_80767E98(dirId, name, extension, buf, fileSize, attr, copyCount, writeChanges);
    }
}

void func_807684AC(u16 dirId, char* name, char* extension, void* buf, s32 offset, s32 fileSize) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 7;
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.name = name;
        D_807C6EA8.extension = extension;
        D_807C6EA8.writeBuf = buf;
        D_807C6EA8.offset = offset;
        D_807C6EA8.fileSize = fileSize;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_8076852C(u16 dirId, char* name, char* extension, void* buf, s32 fileSize) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 6;
        func_80767F14(dirId, name, extension, buf, fileSize);
    }
}

void func_80768574(u16 dirId, char* name, char* extension, void* buf, s32 fileSize) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 9;
        D_807C6EA8.unk_08 = 5;
        func_80767F14(dirId, name, extension, buf, fileSize);
    }
}

void func_807685D8(u16 dirId, char* name, char* extension, void* buf, s32 fileSize) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 10;
        D_807C6EA8.unk_08 = 10;
        func_80767F14(dirId, name, extension, buf, fileSize);
    }
}

void func_80768638(u16 dirId, char* name, char* extension, void* buf, s32 fileSize) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 9;
        D_807C6EA8.unk_08 = 10;
        func_80767F14(dirId, name, extension, buf, fileSize);
    }
}

void func_8076869C(u16 dirId, char* name, char* extension) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 13;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.name = name;
        D_807C6EA8.extension = extension;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_8076870C(u16 dirId, char* name, char* extension) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 14;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.name = name;
        D_807C6EA8.extension = extension;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_8076877C(u8 arg0, char* extension) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 11;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_54 = arg0;
        D_807C6EA8.extension = extension;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_807687E0(u8 arg0, char* extension) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 12;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_54 = arg0;
        D_807C6EA8.extension = extension;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_80768844(u16 dirId, char* oldName, char* oldExtension, char* newName, char* newExtension, bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 15;
        D_807C6EA8.unk_08 = 11;
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.oldName = oldName;
        D_807C6EA8.oldExtension = oldExtension;
        D_807C6EA8.newName = newName;
        D_807C6EA8.newExtension = newExtension;
        D_807C6EA8.writeChanges = writeChanges;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_807688D0(u16 dirId, char* name, char* extension, bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 16;
        D_807C6EA8.unk_08 = 12;
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.name = name;
        D_807C6EA8.extension = extension;
        D_807C6EA8.writeChanges = writeChanges;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_8076894C(u16 dirId, char* name, char* extension) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 17;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.name = name;
        D_807C6EA8.extension = extension;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

void func_807689BC(u16 dirId, char* name, char* extension, s32 attributeToAdd, s32 attributeToRemove,
                   bool writeChanges) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 18;
        if (attributeToAdd == MFS_FILE_ATTR_FORBID_W) {
            D_807C6EA8.unk_08 = 14;
        } else {
            D_807C6EA8.unk_08 = 15;
        }
        D_807C6EA8.dirId = dirId;
        D_807C6EA8.name = name;
        D_807C6EA8.extension = extension;
        D_807C6EA8.attributeToAdd = attributeToAdd;
        D_807C6EA8.attributeToRemove = attributeToRemove;
        D_807C6EA8.writeChanges = writeChanges;
        osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
    }
}

s32 func_80768A5C(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 0;
    sp34.cmdBlock = cmdBlock;
    sp34.direction = direction;
    sp34.lba = lba;
    sp34.vAddr = vAddr;
    sp34.nLBAs = nLbas;
    sp34.mq = mq;

    func_80767800(sp34);
    return 0;
}

s32 func_80768AF0(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 1;
    sp34.cmdBlock = cmdBlock;
    sp34.direction = direction;
    sp34.lba = lba;
    sp34.vAddr = vAddr;
    sp34.nLBAs = nLbas;
    sp34.mq = mq;

    func_80767800(sp34);
    return 0;
}

s32 func_80768B88(OSPiHandle* piHandle, OSIoMesg* mb, s32 direction) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 2;
    sp34.piHandle = piHandle;
    sp34.ioMesg = mb;
    sp34.direction = direction;

    func_80767800(sp34);
    return 0;
}

s32 func_80768C08(OSPiHandle* piHandle, OSIoMesg* mb, s32 direction) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 3;
    sp34.piHandle = piHandle;
    sp34.ioMesg = mb;
    sp34.direction = direction;

    func_80767800(sp34);
    return 0;
}

extern s32 gMfsError;

bool func_80768C88(u16 dirId, char* name, char* extension) {
    if (Mfs_GetFilesPreparation(dirId) == -1) {
        return false;
    }
    while (Mfs_GetNextFileInPreparedDir() != MFS_ENTRY_DOES_NOT_EXIST) {}

    if (Mfs_GetFileIndex(dirId, name, extension) == MFS_ENTRY_DOES_NOT_EXIST) {
        if (gMfsError == N64DD_NOT_FOUND) {
            gMfsError = LEO_ERROR_GOOD;
        }
        return false;
    }
    return true;
}

extern LEODiskID D_800CD2B0;

void func_80768D30(void) {
    static LEODiskID D_807C7080;

    SLLeoReadDiskID(&D_800CD2B0);
    if (SLLeoDiskCompare(D_807C7080, D_800CD2B0)) {
        SLLeo_mfs_newdisk();
        D_807C7080 = D_800CD2B0;
    }

    PRINTF("[ERROR] RING-BUFFER EMPTY\n");
}
