#include "global.h"
#include "fzxthread.h"
#include "fzx_game.h"
#include "segment_symbols.h"

u32 gSegments[16];
u32 D_800E33C0[3];
u32 D_800E33D0[3];

u16 D_800CD2E0 = 0;
s8 D_800CD2E4 = 0;
s8 D_800CD2E8 = 0;
s8 D_800CD2EC = 0;
s8 D_800CD2F0 = -1;
s8 D_800CD2F4 = 0;

RomOffset D_800CD2F8[] = {
    SEGMENT_ROM_START(segment_235130), SEGMENT_ROM_START(segment_239A80), SEGMENT_ROM_START(segment_23EC50),
    SEGMENT_ROM_START(segment_243D90), SEGMENT_ROM_START(segment_24A270), SEGMENT_ROM_START(segment_2507F0),
    SEGMENT_ROM_START(segment_255100), SEGMENT_ROM_START(segment_259600), SEGMENT_ROM_START(segment_25F360),
    SEGMENT_ROM_START(segment_266C20), SEGMENT_ROM_START(segment_26D780),
};

u8* D_800CD324[] = {
    SEGMENT_VRAM_START(segment_235130), SEGMENT_VRAM_START(segment_239A80), SEGMENT_VRAM_START(segment_23EC50),
    SEGMENT_VRAM_START(segment_243D90), SEGMENT_VRAM_START(segment_24A270), SEGMENT_VRAM_START(segment_2507F0),
    SEGMENT_VRAM_START(segment_255100), SEGMENT_VRAM_START(segment_259600), SEGMENT_VRAM_START(segment_25F360),
    SEGMENT_VRAM_START(segment_266C20), SEGMENT_VRAM_START(segment_26D780),
};

u8* D_800CD350[] = {
    SEGMENT_VRAM_END(segment_235130), SEGMENT_VRAM_END(segment_239A80), SEGMENT_VRAM_END(segment_23EC50),
    SEGMENT_VRAM_END(segment_243D90), SEGMENT_VRAM_END(segment_24A270), SEGMENT_VRAM_END(segment_2507F0),
    SEGMENT_VRAM_END(segment_255100), SEGMENT_VRAM_END(segment_259600), SEGMENT_VRAM_END(segment_25F360),
    SEGMENT_VRAM_END(segment_266C20), SEGMENT_VRAM_END(segment_26D780),
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
extern s32 gGameMode;

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

    switch (gGameMode) {
        case GAMEMODE_TIME_ATTACK:
            D_800E33C0[index2] = ALIGN16((uintptr_t) D_8023EAA0);
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_6:
        case GAMEMODE_D:
        case GAMEMODE_10:
        case GAMEMODE_11:
        case GAMEMODE_DEATH_RACE:
        case GAMEMODE_4009:
        case GAMEMODE_4012:
        case GAMEMODE_8008:
            D_800E33C0[index1] = ALIGN16((uintptr_t) osPhysicalToVirtual(D_800DCDB8));
            break;
        default:
            D_800E33C0[index1] = ALIGN16((uintptr_t) osPhysicalToVirtual(D_800DCDB0));
            break;
    }
}

extern u8 D_80115FC0[];

void func_80076804(void) {
    D_800E33C0[0] = ALIGN16((uintptr_t) D_80115FC0);
    D_800E33C0[1] = 0x803DA800;
    D_800E33C0[2] = ALIGN16((uintptr_t) D_8024DC80);
}

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

extern s32 D_800DCDC4;
extern s32 D_800DCDC8;

void func_80076CB8(void) {
    size_t segmentSize;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_11:
        case GAMEMODE_DEATH_RACE:
            segmentSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            break;
        case GAMEMODE_10:
            segmentSize = SEGMENT_VRAM_SIZE(create_machine_textures);
            D_800CD2E0 = 2;
            break;
        case GAMEMODE_6:
        case GAMEMODE_4009:
        case GAMEMODE_4012:
        case GAMEMODE_8008:
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

extern s32 D_800DCDCC;
extern s32 D_800DCDD0;

void func_80076E10(void) {
    size_t ramSize;

    D_800CD2E4 = 1;
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            ramSize = SEGMENT_VRAM_SIZE(segment_1E23F0);
            break;
        case GAMEMODE_D:
        case GAMEMODE_10:
            ramSize = SEGMENT_VRAM_SIZE(segment_145B70);
            break;
        default:
            D_800CD2E4 = 0;
            func_80076BA0(7, D_800DCDCC);
            return;
    }

    D_800DCDCC = osVirtualToPhysical(func_800768F4(0, ramSize));
    D_800DCDD0 = ALIGN16(D_800DCDCC + ramSize);
    func_80076BA0(7, D_800DCDCC);
}

extern s32 D_800DCDD4;
extern s32 D_800DCDD8;

void func_80076F00(void) {
    size_t segmentSize;

    D_800CD2E8 = 1;
    switch (gGameMode) {
        default:
            D_800CD2E8 = 0;
            func_80076BA0(9, D_800DCDD4);
            break;
        case GAMEMODE_10:
        case GAMEMODE_11:
        case GAMEMODE_4009:
        case GAMEMODE_4012:
            segmentSize = SEGMENT_DATA_SIZE_CONST(segment_22B0A0);
            D_800DCDD4 = osVirtualToPhysical(func_800768F4(0, segmentSize));
            D_800DCDD8 = ALIGN16(D_800DCDD4 + segmentSize);
            func_80076BA0(9, D_800DCDD4);
            break;
    }
}

extern s32 D_800DCDDC;
extern s32 D_800DCDE0;

void func_80076FC0(void) {
    size_t segmentSize;

    D_800CD2EC = 1;
    switch (gGameMode) {
        default:
            D_800CD2EC = 0;
            func_80076BA0(10, D_800DCDDC);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_6:
        case GAMEMODE_D:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_11:
        case GAMEMODE_DEATH_RACE:
            segmentSize = SEGMENT_DATA_SIZE_CONST(segment_235130);
            D_800DCDDC = osVirtualToPhysical(func_800768F4(0, segmentSize));
            D_800DCDE0 = ALIGN16(D_800DCDDC + segmentSize);
            func_80076BA0(10, D_800DCDDC);
            break;
    }
}

extern s32 D_800DCDE4;
extern s32 D_800DCDE8;

void func_80077084(void) {
    size_t segmentSize;

    D_800CD2F4 = 1;
    if (gGameMode != GAMEMODE_11) {
        D_800CD2F4 = 0;
        func_80076BA0(5, D_800DCDE4);
        return;
    }
    segmentSize = SEGMENT_DATA_SIZE_CONST(segment_2738A0);
    D_800DCDE4 = osVirtualToPhysical(func_800768F4(0, segmentSize));

    D_800DCDE8 = ALIGN16(D_800DCDE4 + segmentSize);
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

    switch (gGameMode) {
        // ovl_i8
        case GAMEMODE_6:
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
        case GAMEMODE_11:
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
        case GAMEMODE_10:
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

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_6:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_11:
        case GAMEMODE_DEATH_RACE:
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
        case GAMEMODE_4009:
        case GAMEMODE_4012:
        case GAMEMODE_FLX_TITLE:
        case GAMEMODE_8008:
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
        case GAMEMODE_800A:
        case GAMEMODE_800F:
        case GAMEMODE_8013:
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
        case GAMEMODE_FLX_MAIN_MENU:
        case GAMEMODE_800B:
        case GAMEMODE_800C:
        case GAMEMODE_8014:
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

extern u32 D_800DCDB4;

void func_80077630(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;

    if (D_800CD2E0 != 0) {
        switch (gGameMode) {
            case GAMEMODE_GP_RACE:
            case GAMEMODE_PRACTICE:
            case GAMEMODE_VS_2P:
            case GAMEMODE_VS_3P:
            case GAMEMODE_VS_4P:
            case GAMEMODE_TIME_ATTACK:
            case GAMEMODE_11:
            case GAMEMODE_DEATH_RACE:
                func_80073FA0(SEGMENT_ROM_START(segment_17B960), osPhysicalToVirtual(D_800DCDB4),
                              SEGMENT_ROM_SIZE(segment_17B960));
                romOffset = SEGMENT_ROM_START(segment_1B8550);
                ramSize = SEGMENT_VRAM_SIZE(segment_1B8550);
                break;
            case GAMEMODE_10:
                func_80073FA0(SEGMENT_ROM_START(segment_17B960), osPhysicalToVirtual(D_800DCDB4),
                              SEGMENT_ROM_SIZE(segment_17B960));
                romOffset = SEGMENT_ROM_START(create_machine_textures);
                ramSize = SEGMENT_VRAM_SIZE(create_machine_textures);
                break;
            case GAMEMODE_D:
                func_80073FA0(SEGMENT_ROM_START(segment_17B960), osPhysicalToVirtual(D_800DCDB4),
                              SEGMENT_ROM_SIZE(segment_17B960));
                romOffset = SEGMENT_ROM_START(course_edit_textures);
                ramSize = SEGMENT_VRAM_SIZE(course_edit_textures);
                break;
            case GAMEMODE_6:
            case GAMEMODE_4009:
            case GAMEMODE_4012:
            case GAMEMODE_8008:
                func_80073FA0(SEGMENT_ROM_START(segment_17B960), osPhysicalToVirtual(D_800DCDB4),
                              SEGMENT_ROM_SIZE(segment_17B960));
            default:
                D_800CD2E0 = 0;
                return;
        }

        osInvalDCache(osPhysicalToVirtual(D_800DCDC4), ramSize);
        func_800765CC(romOffset, osPhysicalToVirtual(D_800DCDC4), ramSize);
        D_800CD2E0 = 0;
    }
}

void func_80077810(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;

    if (D_800CD2E4 != 0) {
        switch (gGameMode) {
            case GAMEMODE_GP_RACE:
            case GAMEMODE_PRACTICE:
            case GAMEMODE_VS_2P:
            case GAMEMODE_VS_3P:
            case GAMEMODE_VS_4P:
            case GAMEMODE_TIME_ATTACK:
            case GAMEMODE_DEATH_RACE:
                romOffset = SEGMENT_ROM_START(segment_1E23F0);
                ramSize = SEGMENT_VRAM_SIZE(segment_1E23F0);
                break;
            case GAMEMODE_D:
            case GAMEMODE_10:
                romOffset = SEGMENT_ROM_START(segment_145B70);
                ramSize = SEGMENT_VRAM_SIZE(segment_145B70);
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

void func_800778F8(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;
    u8* sp24;

    if (D_800CD2E8 != 0) {
        switch (gGameMode) {
            case GAMEMODE_10:
            case GAMEMODE_11:
            case GAMEMODE_4009:
            case GAMEMODE_4012:
                romOffset = SEGMENT_ROM_START(segment_22B0A0);
                ramSize = SEGMENT_VRAM_SIZE(segment_22B0A0);
                sp24 = func_800768F4(1, ramSize);

                osInvalDCache(sp24, ramSize);
                func_800765CC(romOffset, sp24, ramSize);
                if (*(s32*) sp24 == (s32) 'MIO0') {
                    mio0Decode(sp24, osPhysicalToVirtual(D_800DCDD4));
                }
                D_800CD2E8 = 0;
                break;
            default:
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
    RomOffset romOffset;
    size_t ramSize;
    u8* sp18;

    if (D_800CD2EC != 0) {
        switch (gGameMode) {
            case GAMEMODE_GP_RACE:
            case GAMEMODE_PRACTICE:
            case GAMEMODE_VS_2P:
            case GAMEMODE_VS_3P:
            case GAMEMODE_VS_4P:
            case GAMEMODE_6:
            case GAMEMODE_D:
            case GAMEMODE_TIME_ATTACK:
            case GAMEMODE_11:
            case GAMEMODE_DEATH_RACE:
                sp28 = D_8010B7B2;
                romOffset = D_800CD2F8[sp28];
                ramSize = D_800CD350[sp28] - D_800CD324[sp28];
                break;
            default:
                D_800CD2EC = 0;
                return;
        }
        sp18 = func_800768F4(1, ramSize);

        osInvalDCache(sp18, ramSize);
        func_800765CC(romOffset, sp18, ramSize);
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
    RomOffset romOffset;
    size_t ramSize;
    u8* sp18;

    if (D_800CD2F0 >= 0) {
        sp28 = D_800CD2F0;

        switch (gGameMode) {
            case GAMEMODE_D:
                romOffset = D_800CD2F8[sp28];
                ramSize = D_800CD350[sp28] - D_800CD324[sp28];
                break;
            default:
                return;
        }

        sp18 = func_800768F4(1, ramSize);

        osInvalDCache(sp18, ramSize);
        func_800765CC(romOffset, sp18, ramSize);
        if (*(s32*) sp18 == (s32) 'MIO0') {
            mio0Decode(sp18, osPhysicalToVirtual(D_800DCDDC));
        }
        D_800CD2F0 = -1;
        func_8009CED0(sp28);
    }
}

void func_80077BE0(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;
    u8* sp24;

    if (D_800CD2F4 != 0) {
        if (gGameMode != GAMEMODE_11) {
            D_800CD2F4 = 0;
            return;
        }
        romOffset = SEGMENT_ROM_START(segment_2738A0);
        ramSize = SEGMENT_VRAM_SIZE(segment_2738A0);

        sp24 = func_800768F4(1, ramSize);

        osInvalDCache(sp24, ramSize);
        func_800765CC(romOffset, sp24, ramSize);
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
