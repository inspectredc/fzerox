#include "global.h"
#include "fzxthread.h"

u16 D_800CD2E0 = 0;
s8 D_800CD2E4 = 0;
s8 D_800CD2E8 = 0;
s8 D_800CD2EC = 0;
s8 D_800CD2F0 = -1;
s8 D_800CD2F4 = 0;

RomOffset D_800CD2F8[] = {
    SEGMENT_ROM_START(mio0_segment_3),  SEGMENT_ROM_START(mio0_segment_4),  SEGMENT_ROM_START(mio0_segment_5),
    SEGMENT_ROM_START(mio0_segment_6),  SEGMENT_ROM_START(mio0_segment_7),  SEGMENT_ROM_START(mio0_segment_8),
    SEGMENT_ROM_START(mio0_segment_9),  SEGMENT_ROM_START(mio0_segment_10), SEGMENT_ROM_START(mio0_segment_11),
    SEGMENT_ROM_START(mio0_segment_12), SEGMENT_ROM_START(mio0_segment_13),
};

u8* D_800CD324[] = {
    SEGMENT_VRAM_START(mio0_segment_3),  SEGMENT_VRAM_START(mio0_segment_4),  SEGMENT_VRAM_START(mio0_segment_5),
    SEGMENT_VRAM_START(mio0_segment_6),  SEGMENT_VRAM_START(mio0_segment_7),  SEGMENT_VRAM_START(mio0_segment_8),
    SEGMENT_VRAM_START(mio0_segment_9),  SEGMENT_VRAM_START(mio0_segment_10), SEGMENT_VRAM_START(mio0_segment_11),
    SEGMENT_VRAM_START(mio0_segment_12), SEGMENT_VRAM_START(mio0_segment_13),
};

u8* D_800CD350[] = {
    SEGMENT_VRAM_END(mio0_segment_3),  SEGMENT_VRAM_END(mio0_segment_4),  SEGMENT_VRAM_END(mio0_segment_5),
    SEGMENT_VRAM_END(mio0_segment_6),  SEGMENT_VRAM_END(mio0_segment_7),  SEGMENT_VRAM_END(mio0_segment_8),
    SEGMENT_VRAM_END(mio0_segment_9),  SEGMENT_VRAM_END(mio0_segment_10), SEGMENT_VRAM_END(mio0_segment_11),
    SEGMENT_VRAM_END(mio0_segment_12), SEGMENT_VRAM_END(mio0_segment_13),
};

void func_80076490(void) {
}

extern OSMesgQueue D_800DCA68;
extern OSIoMesg D_800DCCA8;
extern OSPiHandle* D_800DCCDC;

void func_80076498(u32 romAddr, u32 ramAddr, size_t size) {
    OSMesg msgBuf[7];

    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(ramAddr);
    D_800DCCA8.devAddr = romAddr;
    D_800DCCA8.size = size;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, msgBuf);
}

void func_80076528(u32 romAddr, u32 ramAddr, size_t size, void* bssAddr, size_t bssSize) {
    OSMesg msgBuf[7];

    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(ramAddr);
    D_800DCCA8.devAddr = romAddr;
    D_800DCCA8.size = size;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    bzero(bssAddr, bssSize);
    MQ_WAIT_FOR_MESG(&D_800DCA68, msgBuf);
}

void func_800765CC(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks;

    numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80076498(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }
    remainder = size % 1024;
    if (remainder != 0) {
        func_80076498(romAddr, ramAddr, remainder);
    }
}

void func_80076658(u8* romAddr, u8* ramAddr, size_t size, void* bssAddr, size_t bssSize) {
    s32 remainder;
    s32 i;
    s32 numBlocks;

    numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80076498(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }
    remainder = size % 1024;
    if (remainder != 0) {
        func_80076528(romAddr, ramAddr, remainder, bssAddr, bssSize);
    }
}

extern u32 D_800DCDB0;
extern u32 D_800DCDB8;
extern s32 D_800DCE44;

extern uintptr_t D_800E33C0[3];
extern u8 D_8023EAA0[];
extern u8 D_80115DF0[];
extern u8 D_8024DC80[];

// FAKE, weird access into array here, perhaps some macro usage?
void func_800766F0(void) {
    s32 index1 = 1;
    s32 index2 = 2;

    D_800E33C0[0] = ALIGN16((uintptr_t) D_80115DF0);
    D_800E33C0[2] = ALIGN16((uintptr_t) D_8024DC80);

    switch (D_800DCE44) {
        case 0xE:
            D_800E33C0[index2] = ALIGN16((uintptr_t) D_8023EAA0);
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0xD:
        case 0x10:
        case 0x11:
        case 0x15:
        case 0x4009:
        case 0x4012:
        case 0x8008:
            D_800E33C0[index1] = ALIGN16((uintptr_t) osPhysicalToVirtual(D_800DCDB8));
            break;
        default:
            D_800E33C0[index1] = ALIGN16((uintptr_t) osPhysicalToVirtual(D_800DCDB0));
            break;
    }
}

extern u32 D_800E33C0[];
extern u8 D_80115FC0[];

void func_80076804(void) {
    D_800E33C0[0] = ALIGN16((uintptr_t) D_80115FC0);
    D_800E33C0[1] = 0x803DA800;
    D_800E33C0[2] = ALIGN16((uintptr_t) D_8024DC80);
}

extern u32 D_800E33D0[];

void func_80076848(void) {
    D_800E33D0[0] = 0x801D9800;
    D_800E33D0[1] = 0x803DA800;
    D_800E33D0[2] = ALIGN16((uintptr_t) D_8024DC80);
}

// Add to memory start and return start of newly allocated block
u8* func_80076884(s32 arg0, size_t arg1) {
    u8* ret = D_800E33C0[arg0];

    arg1 = ALIGN16(arg1);
    D_800E33C0[arg0] += arg1;

    return ret;
}

// Get memory block (non-allocating mode, used for compressed blocks)
u8* func_800768B0(s32 arg0, size_t arg1) {
    u8* ret = D_800E33C0[arg0];

    return ret;
}

// Take from memory end and return new memory end
u8* func_800768C8(s32 arg0, size_t arg1) {

    arg1 = ALIGN16(arg1);
    D_800E33D0[arg0] -= arg1;

    return (u8*) D_800E33D0[arg0];
}

u8* func_800768F4(s32 arg0, size_t arg1) {
    size_t sp54[3];
    s8 sp50[3];
    u8* sp4C;
    s32 i;
    s32 j;
    s32 temp;

    // Sets initial array of memory indexes and the sizes left in the 3 memory blocks
    for (i = 0; i < 3; i++) {
        sp50[i] = i;
        sp54[i] = D_800E33D0[i] - D_800E33C0[i];
    }

    // Sort memory indexes in order of size (without disturbing order of memory blocks)
    // Smallest -> Largest
    for (i = 2; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (sp54[sp50[j]] >= sp54[sp50[j + 1]]) {
                temp = sp50[j];
                sp50[j] = sp50[j + 1];
                sp50[j + 1] = temp;
            }
        }
    }

    // Check the smallest memory block this can be allocated into
    for (i = 0; i < 3; i++) {
        if (arg1 < sp54[sp50[i]]) {
            break;
        }
    }

    // If not enough size in any block, default to memory block with largest available space
    // Exit with NULL under a certain condition (todo)
    if (i >= 3) {
        i = 2;
        if (arg0 == 2) {
            return NULL;
        }
    }

    switch (arg0) {
        case 0:
            sp4C = func_80076884(sp50[i], arg1);
            break;
        case 1:
            sp4C = func_800768B0(sp50[i], arg1);
            break;
        case 2:
            sp4C = func_800768C8(sp50[i], arg1);
            break;
    }
    return sp4C;
}

extern u32 gSegments[];

s32 func_80076B80(s32 arg0, s32 arg1) {
    gSegments[arg0] = K0_TO_PHYS(arg1);
    return gSegments[arg0];
}

s32 func_80076BA0(s32 arg0, s32 arg1) {
    gSegments[arg0] = arg1;
    return arg1;
}

s32 func_80076BB8(s32 arg0) {
    return PHYS_TO_K0(gSegments[arg0]);
}

s32 func_80076BD4(uintptr_t arg0) {
    return PHYS_TO_K0(gSegments[SEGMENT_NUMBER(arg0)] + SEGMENT_OFFSET(arg0));
}

Gfx* func_80076C08(Gfx* gfx) {
    s32 i;

    for (i = 0; i < 16; i++) {
        gSPSegment(gfx++, i, gSegments[i]);
    }

    return gfx;
}

extern u8 D_4000000[];
extern u8 D_4006240[];
extern u8 D_4029EA0[];

extern s32 D_800DCDC4;
extern s32 D_800DCDC8;
extern s32 D_800DCE44;

void func_80076CB8(void) {
    size_t segmentSize;

    switch (D_800DCE44) {
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0xE:
        case 0x11:
        case 0x15:
            segmentSize = D_4029EA0 - D_4000000;
            break;
        case 0x10:
            segmentSize = D_4006240 - D_4000000;
            D_800CD2E0 = 2;
            break;
        case 0x6:
        case 0x4009:
        case 0x4012:
        case 0x8008:
            D_800CD2E0 = 2;
            func_80076BA0(4, D_800DCDC4);
            return;
        default:
            D_800CD2E0 = 0;
            func_80076BA0(4, D_800DCDC4);
            return;
    }
    D_800DCDC4 = osVirtualToPhysical(func_800768F4(0, segmentSize));
    D_800DCDC8 = ALIGN16(D_800DCDC4 + segmentSize);
    func_80076BA0(4, D_800DCDC4);
}

extern u8 D_7000000[];
extern u8 D_700DA40[];
extern u8 D_7048CB0[];

extern s32 D_800DCDCC;
extern s32 D_800DCDD0;

void func_80076E10(void) {
    size_t var_a2;

    D_800CD2E4 = 1;
    switch (D_800DCE44) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 14:
        case 21:
            var_a2 = D_7048CB0 - D_7000000;
            break;
        case 13:
        case 16:
            var_a2 = D_700DA40 - D_7000000;
            break;
        default:
            D_800CD2E4 = 0;
            func_80076BA0(7, D_800DCDCC);
            return;
    }

    D_800DCDCC = osVirtualToPhysical(func_800768F4(0, var_a2));
    D_800DCDD0 = ALIGN16(D_800DCDCC + var_a2);
    func_80076BA0(7, D_800DCDCC);
}

extern u8 D_18750[];

extern s32 D_800DCDD4;
extern s32 D_800DCDD8;

void func_80076F00(void) {
    size_t sp1C;

    D_800CD2E8 = 1;
    switch (D_800DCE44) {
        default:
            D_800CD2E8 = 0;
            func_80076BA0(9, D_800DCDD4);
            break;
        case 0x10:
        case 0x11:
        case 0x4009:
        case 0x4012:
            sp1C = D_18750;
            D_800DCDD4 = osVirtualToPhysical(func_800768F4(0, sp1C));
            D_800DCDD8 = ALIGN16(D_800DCDD4 + sp1C);
            func_80076BA0(9, D_800DCDD4);
            break;
    }
}

extern u8 D_BFC0[];

extern s32 D_800DCDDC;
extern s32 D_800DCDE0;

void func_80076FC0(void) {
    size_t sp1C;

    D_800CD2EC = 1;
    switch (D_800DCE44) {
        default:
            D_800CD2EC = 0;
            func_80076BA0(0xA, D_800DCDDC);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 13:
        case 14:
        case 17:
        case 21:
            sp1C = D_BFC0;
            D_800DCDDC = osVirtualToPhysical(func_800768F4(0, sp1C));
            D_800DCDE0 = ALIGN16(D_800DCDDC + sp1C);
            func_80076BA0(0xA, D_800DCDDC);
            break;
    }
}

extern u8 D_3680[];
extern s32 D_800DCDE4;
extern s32 D_800DCDE8;

void func_80077084(void) {
    size_t sp1C;

    D_800CD2F4 = 1;
    if (D_800DCE44 != 0x11) {
        D_800CD2F4 = 0;
        func_80076BA0(5, D_800DCDE4);
        return;
    }
    sp1C = D_3680;
    D_800DCDE4 = osVirtualToPhysical(func_800768F4(0, sp1C));

    D_800DCDE8 = ALIGN16(D_800DCDE4 + sp1C);
    func_80076BA0(5, D_800DCDE4);
}

void func_8007712C(void) {
    s32 pad[2];
    uintptr_t vramStart;
    uintptr_t vramTextStart;
    uintptr_t vramDataStart;
    uintptr_t vramBssStart;
    RomOffset romStart;
    size_t segmentRomSize;
    size_t segmentVramSize;
    size_t segmentTextSize;
    size_t segmentDataSize;
    size_t segmentBssSize;

    switch (D_800DCE44) {
        // ovl_i8
        case 6:
            vramTextStart = SEGMENT_TEXT_START(ovl_i8);
            vramStart = SEGMENT_VRAM_START(ovl_i8);
            vramDataStart = SEGMENT_DATA_START(ovl_i8);
            vramBssStart = SEGMENT_BSS_START(ovl_i8);
            romStart = SEGMENT_ROM_START(ovl_i8);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i8);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i8);
            segmentRomSize = SEGMENT_BSS_START(ovl_i8) - SEGMENT_VRAM_START(ovl_i8);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i8);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i8);
            break;
        // ovl_i7
        case 17:
            vramTextStart = SEGMENT_TEXT_START(ovl_i7);
            vramStart = SEGMENT_VRAM_START(ovl_i7);
            vramDataStart = SEGMENT_DATA_START(ovl_i7);
            vramBssStart = SEGMENT_BSS_START(ovl_i7);
            romStart = SEGMENT_ROM_START(ovl_i7);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i7);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i7);
            segmentRomSize = SEGMENT_BSS_START(ovl_i7) - SEGMENT_VRAM_START(ovl_i7);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i7);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i7);
            break;
        // ovl_i9
        case 16:
            vramTextStart = SEGMENT_TEXT_START(ovl_i9);
            vramStart = SEGMENT_VRAM_START(ovl_i9);
            vramDataStart = SEGMENT_DATA_START(ovl_i9);
            vramBssStart = SEGMENT_BSS_START(ovl_i9);
            romStart = SEGMENT_ROM_START(ovl_i9);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i9);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i9);
            segmentRomSize = SEGMENT_BSS_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i9);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i9);
            break;
        default:
            return;
    }

    func_80076884(0, segmentVramSize);
    osInvalICache(vramTextStart, segmentTextSize);
    osInvalDCache(vramDataStart, segmentDataSize);
    func_80076658(romStart, vramStart, segmentRomSize, vramBssStart, segmentBssSize);
}

void func_80077318(void) {
    s32 pad[3];
    uintptr_t vramStart;
    uintptr_t vramTextStart;
    uintptr_t vramDataStart;
    uintptr_t vramBssStart;
    RomOffset romStart;
    size_t segmentRomSize;
    size_t segmentVramSize;
    size_t segmentTextSize;
    size_t segmentDataSize;
    size_t segmentBssSize;

    switch (D_800DCE44) {
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0xE:
        case 0x11:
        case 0x15:
            // ovl_i3
            vramTextStart = SEGMENT_TEXT_START(ovl_i3);
            vramStart = SEGMENT_VRAM_START(ovl_i3);
            vramDataStart = SEGMENT_DATA_START(ovl_i3);
            vramBssStart = SEGMENT_BSS_START(ovl_i3);
            romStart = SEGMENT_ROM_START(ovl_i3);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i3);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i3);
            segmentRomSize = SEGMENT_BSS_START(ovl_i3) - SEGMENT_VRAM_START(ovl_i3);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i3);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i3);
            break;
        case 0x4009:
        case 0x4012:
        case 0x8000:
        case 0x8008:
            // ovl_i4
            vramTextStart = SEGMENT_TEXT_START(ovl_i4);
            vramStart = SEGMENT_VRAM_START(ovl_i4);
            vramDataStart = SEGMENT_DATA_START(ovl_i4);
            vramBssStart = SEGMENT_BSS_START(ovl_i4);
            romStart = SEGMENT_ROM_START(ovl_i4);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i4);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i4);
            segmentRomSize = SEGMENT_BSS_START(ovl_i4) - SEGMENT_VRAM_START(ovl_i4);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i4);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i4);
            break;
        case 0x800A:
        case 0x800F:
        case 0x8013:
            // ovl_i5
            vramTextStart = SEGMENT_TEXT_START(ovl_i5);
            vramStart = SEGMENT_VRAM_START(ovl_i5);
            vramDataStart = SEGMENT_DATA_START(ovl_i5);
            vramBssStart = SEGMENT_BSS_START(ovl_i5);
            romStart = SEGMENT_ROM_START(ovl_i5);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i5);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i5);
            segmentRomSize = SEGMENT_BSS_START(ovl_i5) - SEGMENT_VRAM_START(ovl_i5);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i5);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i5);
            break;
        case 0x8007:
        case 0x800B:
        case 0x800C:
        case 0x8014:
            // ovl_i6
            vramTextStart = SEGMENT_TEXT_START(ovl_i6);
            vramStart = SEGMENT_VRAM_START(ovl_i6);
            vramDataStart = SEGMENT_DATA_START(ovl_i6);
            vramBssStart = SEGMENT_BSS_START(ovl_i6);
            romStart = SEGMENT_ROM_START(ovl_i6);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i6);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i6);
            segmentRomSize = SEGMENT_BSS_START(ovl_i6) - SEGMENT_VRAM_START(ovl_i6);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i6);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i6);
            break;
        default:
            return;
    }

    func_80076884(0, segmentVramSize);
    if (1) {}
    osInvalICache(vramTextStart, segmentTextSize);
    osInvalDCache(vramDataStart, segmentDataSize);
    func_80076658(romStart, vramStart, segmentRomSize, vramBssStart, segmentBssSize);
    func_8007712C();
    D_800CD2E0 = 1;
    func_80076CB8();
    func_80076E10();
    func_80076F00();
    func_80076FC0();
    func_80077084();
}

extern u8 D_1535B0[];
extern u8 D_166660[];
extern u8 D_17B960[];
extern u8 D_1B8550[];
extern u8 D_4000000[];
extern u8 D_4006240[];
extern u8 D_40130B0[];
extern u8 D_4029EA0[];

extern u32 D_800DCDB4;

void func_80077630(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;

    if (D_800CD2E0 != 0) {
        switch (D_800DCE44) {
            case 0x1:
            case 0x2:
            case 0x3:
            case 0x4:
            case 0x5:
            case 0xE:
            case 0x11:
            case 0x15:
                func_80073FA0(D_17B960, osPhysicalToVirtual(D_800DCDB4), D_1B8550 - D_17B960);
                romOffset = D_1B8550;
                ramSize = D_4029EA0 - D_4000000;
                break;
            case 0x10:
                func_80073FA0(D_17B960, osPhysicalToVirtual(D_800DCDB4), D_1B8550 - D_17B960);
                romOffset = D_166660;
                ramSize = D_4006240 - D_4000000;
                break;
            case 0xD:
                func_80073FA0(D_17B960, osPhysicalToVirtual(D_800DCDB4), D_1B8550 - D_17B960);
                romOffset = D_1535B0;
                ramSize = D_40130B0 - D_4000000;
                break;
            case 0x6:
            case 0x4009:
            case 0x4012:
            case 0x8008:
                func_80073FA0(D_17B960, osPhysicalToVirtual(D_800DCDB4), D_1B8550 - D_17B960);
            default:
                D_800CD2E0 = 0;
                return;
        }

        osInvalDCache(osPhysicalToVirtual(D_800DCDC4), ramSize);
        func_800765CC(romOffset, osPhysicalToVirtual(D_800DCDC4), ramSize);
        D_800CD2E0 = 0;
    }
}

extern u8 D_145B70[];
extern u8 D_1E23F0[];
extern u8 D_7000000[];
extern u8 D_700DA40[];
extern u8 D_7048CB0[];

extern s32 D_800DCE44;

void func_80077810(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;

    if (D_800CD2E4 != 0) {
        switch (D_800DCE44) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 14:
            case 21:
                romOffset = D_1E23F0;
                ramSize = D_7048CB0 - D_7000000;
                break;
            case 13:
            case 16:
                romOffset = D_145B70;
                ramSize = D_700DA40 - D_7000000;
                break;
            default:
                D_800CD2E4 = 0;
                return;
        }
        osInvalDCache(osPhysicalToVirtual(D_800DCDCC), ramSize);
        func_800765CC(romOffset, osPhysicalToVirtual(D_800DCDCC), ramSize);
        D_800CD2E4 = 0;
    }
}

extern u8 D_22B0A0[];
extern u8 D_9000000[];
extern u8 D_900A090[];

void func_800778F8(void) {
    s32 pad[3];
    size_t ramSize;
    u8* sp24;

    if (D_800CD2E8 != 0) {
        switch (D_800DCE44) {
            default:
                D_800CD2E8 = 0;
                break;
            case 0x10:
            case 0x11:
            case 0x4009:
            case 0x4012:
                ramSize = D_900A090 - D_9000000;
                sp24 = func_800768F4(1, ramSize);

                osInvalDCache(sp24, ramSize);
                func_800765CC(D_22B0A0, sp24, ramSize);
                if (*(s32*) sp24 == (s32) 'MIO0') {
                    mio0Decode(sp24, osPhysicalToVirtual(D_800DCDD4));
                }
                D_800CD2E8 = 0;
                break;
        }
    }
}

extern s8 D_8010B7B2;

void func_800779D0(void) {
    s32 pad;
    s32 sp28;
    s32 pad2;
    RomOffset sp20;
    size_t sp1C;
    u8* sp18;

    if (D_800CD2EC != 0) {
        switch (D_800DCE44) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 13:
            case 14:
            case 17:
            case 21:
                sp28 = D_8010B7B2;
                sp20 = D_800CD2F8[sp28];
                sp1C = D_800CD350[sp28] - D_800CD324[sp28];
                break;
            default:
                D_800CD2EC = 0;
                return;
        }
        sp18 = func_800768F4(1, sp1C);

        osInvalDCache(sp18, sp1C);
        func_800765CC(sp20, sp18, sp1C);
        if (*(s32*) sp18 == (s32) 'MIO0') {
            mio0Decode(sp18, osPhysicalToVirtual(D_800DCDDC));
        }
        D_800CD2EC = 0;
        func_8009CED0(sp28);
    }
}

void func_80077AD8(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0xA) && (D_800CD2F0 < 0)) {
        D_800CD2F0 = arg0;
    }
}

void func_80077B04(void) {
    s32 pad;
    s32 sp28;
    s32 pad2;
    RomOffset sp20;
    s32 sp1C;
    u8* sp18;

    if (D_800CD2F0 >= 0) {
        sp28 = D_800CD2F0;

        switch (D_800DCE44) {
            case 0xD:
                sp20 = D_800CD2F8[sp28];
                sp1C = D_800CD350[sp28] - D_800CD324[sp28];
                break;
            default:
                return;
        }

        sp18 = func_800768F4(1, sp1C);

        osInvalDCache(sp18, sp1C);
        func_800765CC(sp20, sp18, sp1C);
        if (*(s32*) sp18 == (s32) 'MIO0') {
            mio0Decode(sp18, osPhysicalToVirtual(D_800DCDDC));
        }
        D_800CD2F0 = -1;
        func_8009CED0(sp28);
    }
}

extern u8 D_2738A0[];
extern u8 D_5000000[];
extern u8 D_5000F50[];

void func_80077BE0(void) {
    s32 pad[3];
    size_t sp1C;
    u8* sp24;

    if (D_800CD2F4 != 0) {
        if (D_800DCE44 != 0x11) {
            D_800CD2F4 = 0;
            return;
        }
        sp1C = D_5000F50 - D_5000000;

        sp24 = func_800768F4(1, sp1C);

        osInvalDCache(sp24, sp1C);
        func_800765CC(D_2738A0, sp24, sp1C);
        if (*(s32*) sp24 == (s32) 'MIO0') {
            mio0Decode(sp24, osPhysicalToVirtual(D_800DCDE4));
        }
        D_800CD2F4 = 0;
    }
}

void func_80077C9C(void) {
    func_80077630();
    func_80077810();
    func_800778F8();
    func_800779D0();
    func_80077B04();
    func_80077BE0();
}
