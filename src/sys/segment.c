#include "global.h"
#include "fzx_game.h"
#include "fzx_course.h"
#include "segment_symbols.h"

uintptr_t gSegments[16];
uintptr_t gArenaStartPtrs[ARENA_COUNT];
uintptr_t gArenaEndPtrs[ARENA_COUNT];

u16 D_800CD2E0 = 0;
s8 D_800CD2E4 = false;
s8 D_800CD2E8 = false;
s8 D_800CD2EC = false;
s8 D_800CD2F0 = -1;
s8 D_800CD2F4 = false;

RomOffset D_800CD2F8[] = {
    SEGMENT_ROM_START(mute_city_textures), // VENUE_MUTE_CITY
    SEGMENT_ROM_START(port_town_textures), // VENUE_PORT_TOWN
    SEGMENT_ROM_START(big_blue_textures), // VENUE_BIG_BLUE
    SEGMENT_ROM_START(sand_ocean_textures), // VENUE_SAND_OCEAN
    SEGMENT_ROM_START(devils_forest_textures), // VENUE_DEVILS_FOREST
    SEGMENT_ROM_START(white_land_textures), // VENUE_WHITE_LAND
    SEGMENT_ROM_START(sector_textures), // VENUE_SECTOR
    SEGMENT_ROM_START(red_canyon_textures), // VENUE_RED_CANYON
    SEGMENT_ROM_START(fire_field_textures), // VENUE_FIRE_FIELD
    SEGMENT_ROM_START(silence_textures), // VENUE_SILENCE
    SEGMENT_ROM_START(ending_venue_textures), // VENUE_ENDING
};

u8* D_800CD324[] = {
    SEGMENT_VRAM_START(mute_city_textures), // VENUE_MUTE_CITY
    SEGMENT_VRAM_START(port_town_textures), // VENUE_PORT_TOWN
    SEGMENT_VRAM_START(big_blue_textures), // VENUE_BIG_BLUE
    SEGMENT_VRAM_START(sand_ocean_textures), // VENUE_SAND_OCEAN
    SEGMENT_VRAM_START(devils_forest_textures), // VENUE_DEVILS_FOREST
    SEGMENT_VRAM_START(white_land_textures), // VENUE_WHITE_LAND
    SEGMENT_VRAM_START(sector_textures), // VENUE_SECTOR
    SEGMENT_VRAM_START(red_canyon_textures), // VENUE_RED_CANYON
    SEGMENT_VRAM_START(fire_field_textures), // VENUE_FIRE_FIELD
    SEGMENT_VRAM_START(silence_textures), // VENUE_SILENCE
    SEGMENT_VRAM_START(ending_venue_textures), // VENUE_ENDING
};

u8* D_800CD350[] = {
    SEGMENT_VRAM_END(mute_city_textures), // VENUE_MUTE_CITY
    SEGMENT_VRAM_END(port_town_textures), // VENUE_PORT_TOWN
    SEGMENT_VRAM_END(big_blue_textures), // VENUE_BIG_BLUE
    SEGMENT_VRAM_END(sand_ocean_textures), // VENUE_SAND_OCEAN
    SEGMENT_VRAM_END(devils_forest_textures), // VENUE_DEVILS_FOREST
    SEGMENT_VRAM_END(white_land_textures), // VENUE_WHITE_LAND
    SEGMENT_VRAM_END(sector_textures), // VENUE_SECTOR
    SEGMENT_VRAM_END(red_canyon_textures), // VENUE_RED_CANYON
    SEGMENT_VRAM_END(fire_field_textures), // VENUE_FIRE_FIELD
    SEGMENT_VRAM_END(silence_textures), // VENUE_SILENCE
    SEGMENT_VRAM_END(ending_venue_textures), // VENUE_ENDING
};

extern uintptr_t gSegment17B1E0VramEnd;
extern uintptr_t gSegment17B960VramEnd;
extern s32 gGameMode;

extern u8 D_8023EAA0[];
extern u8 D_80115DF0[];
extern u8 D_8024DC80[];

void Arena_StartInit(void) {
    uintptr_t* block1 = &gArenaStartPtrs[0];
    uintptr_t* block2 = &gArenaStartPtrs[1];
    uintptr_t* block3 = &gArenaStartPtrs[2];

    *block1 = ALIGN16((uintptr_t) D_80115DF0);
    *block3 = ALIGN16((uintptr_t) D_8024DC80);

    switch (gGameMode) {
        case GAMEMODE_TIME_ATTACK:
            *block3 = ALIGN16((uintptr_t) D_8023EAA0);
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            *block2 = ALIGN16((uintptr_t) osPhysicalToVirtual(gSegment17B960VramEnd));
            break;
        default:
            *block2 = ALIGN16((uintptr_t) osPhysicalToVirtual(gSegment17B1E0VramEnd));
            break;
    }
}

extern u8 D_80115FC0[];

void Arena_DefaultStartInit(void) {
    gArenaStartPtrs[0] = ALIGN16((uintptr_t) D_80115FC0);
    gArenaStartPtrs[1] = 0x803DA800;
    gArenaStartPtrs[2] = ALIGN16((uintptr_t) D_8024DC80);
}

void Arena_EndInit(void) {
    gArenaEndPtrs[0] = 0x801D9800;
    gArenaEndPtrs[1] = 0x803DA800;
    gArenaEndPtrs[2] = ALIGN16((uintptr_t) D_8024DC80);
}

// Add to memory start and return start of newly allocated block
void* Arena_AllocateFront(s32 arenaIndex, size_t size) {
    void* ret = gArenaStartPtrs[arenaIndex];

    size = ALIGN16(size);
    gArenaStartPtrs[arenaIndex] += size;

    return ret;
}

// Get memory block (non-allocating mode, used for compressed blocks)
void* Arena_GetStartPtr(s32 arenaIndex, size_t size) {
    void* ret = gArenaStartPtrs[arenaIndex];

    return ret;
}

// Take from memory end and return new memory end
void* Arena_AllocateBack(s32 arenaIndex, size_t size) {

    size = ALIGN16(size);
    gArenaEndPtrs[arenaIndex] -= size;

    return (void*) gArenaEndPtrs[arenaIndex];
}

void* Arena_Allocate(s32 allocationType, size_t size) {
    size_t arenaSizes[ARENA_COUNT];
    s8 sortedArenaIndices[ARENA_COUNT];
    void* allocatePtr;
    s32 i;
    s32 j;
    s32 temp;

    // Sets initial array of memory indexes and the sizes left in the 3 memory blocks
    for (i = 0; i < ARENA_COUNT; i++) {
        sortedArenaIndices[i] = i;
        arenaSizes[i] = gArenaEndPtrs[i] - gArenaStartPtrs[i];
    }

    // Sort memory indexes in order of size (without disturbing order of memory blocks)
    // Smallest -> Largest
    for (i = ARENA_COUNT - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arenaSizes[sortedArenaIndices[j]] >= arenaSizes[sortedArenaIndices[j + 1]]) {
                temp = sortedArenaIndices[j];
                sortedArenaIndices[j] = sortedArenaIndices[j + 1];
                sortedArenaIndices[j + 1] = temp;
            }
        }
    }

    // Check the smallest memory block this can be allocated into
    for (i = 0; i < ARENA_COUNT; i++) {
        if (size < arenaSizes[sortedArenaIndices[i]]) {
            break;
        }
    }

    // If not enough size in any block, default to memory block with largest available space
    // Exit with NULL under a certain condition (todo)
    if (i >= ARENA_COUNT) {
        i = ARENA_COUNT - 1;
        if (allocationType == ALLOC_BACK) {
            return NULL;
        }
    }

    switch (allocationType) {
        case ALLOC_FRONT:
            allocatePtr = Arena_AllocateFront(sortedArenaIndices[i], size);
            break;
        case ALLOC_PEEK:
            allocatePtr = Arena_GetStartPtr(sortedArenaIndices[i], size);
            break;
        case ALLOC_BACK:
            allocatePtr = Arena_AllocateBack(sortedArenaIndices[i], size);
            break;
    }
    return allocatePtr;
}

s32 Segment_SetPhysicalAddress(s32 segment, s32 addr) {
    gSegments[segment] = K0_TO_PHYS(addr);
    return gSegments[segment];
}

s32 Segment_SetAddress(s32 segment, s32 addr) {
    gSegments[segment] = addr;
    return gSegments[segment];
}

s32 Segment_GetAddress(s32 segment) {
    return PHYS_TO_K0(gSegments[segment]);
}

s32 Segment_SegmentedToVirtual(uintptr_t segmentedAddr) {
    return PHYS_TO_K0(gSegments[SEGMENT_NUMBER(segmentedAddr)] + SEGMENT_OFFSET(segmentedAddr));
}

Gfx* Segment_SetTableAddresses(Gfx* gfx) {
    s32 i;

    for (i = 0; i < 16; i++) {
        gSPSegment(gfx++, i, gSegments[i]);
    }

    return gfx;
}

extern s32 gSegment1B8550VramStart;
extern s32 gSegment1B8550VramEnd;

void Segment_SetupSegment4(void) {
    size_t segmentSize;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            segmentSize = SEGMENT_VRAM_SIZE(hud_gfx);
            break;
        case GAMEMODE_CREATE_MACHINE:
            segmentSize = SEGMENT_VRAM_SIZE(create_machine_textures);
            D_800CD2E0 = 2;
            break;
        case GAMEMODE_RECORDS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            D_800CD2E0 = 2;
            Segment_SetAddress(4, gSegment1B8550VramStart);
            return;
        default:
            D_800CD2E0 = 0;
            Segment_SetAddress(4, gSegment1B8550VramStart);
            return;
    }
    gSegment1B8550VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    gSegment1B8550VramEnd = ALIGN16(gSegment1B8550VramStart + segmentSize);
    Segment_SetAddress(4, gSegment1B8550VramStart);
}

extern s32 gSegment1E23F0VramStart;
extern s32 gSegment1E23F0VramEnd;

void Segment_SetupSegment7(void) {
    size_t ramSize;

    D_800CD2E4 = true;
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            ramSize = SEGMENT_VRAM_SIZE(machine_global_gfx);
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            ramSize = SEGMENT_VRAM_SIZE(expansion_kit_textures_beta);
            break;
        default:
            D_800CD2E4 = false;
            Segment_SetAddress(7, gSegment1E23F0VramStart);
            return;
    }

    gSegment1E23F0VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, ramSize));
    gSegment1E23F0VramEnd = ALIGN16(gSegment1E23F0VramStart + ramSize);
    Segment_SetAddress(7, gSegment1E23F0VramStart);
}

extern s32 gSegment22B0A0VramStart;
extern s32 gSegment22B0A0VramEnd;

void Segment_SetupSegment9(void) {
    size_t segmentSize;

    D_800CD2E8 = true;
    switch (gGameMode) {
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            segmentSize = SEGMENT_DATA_SIZE_CONST(machine_models);
            break;
        default:
            D_800CD2E8 = false;
            Segment_SetAddress(9, gSegment22B0A0VramStart);
            return;
    }
    gSegment22B0A0VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    gSegment22B0A0VramEnd = ALIGN16(gSegment22B0A0VramStart + segmentSize);
    Segment_SetAddress(9, gSegment22B0A0VramStart);
}

extern uintptr_t gSegment235130VramStart;
extern uintptr_t gSegment235130VramEnd;

void Segment_SetupSegment10(void) {
    size_t segmentSize;

    D_800CD2EC = true;
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            segmentSize = SEGMENT_DATA_SIZE_CONST(mute_city_textures);
            break;
        default:
            D_800CD2EC = false;
            Segment_SetAddress(10, gSegment235130VramStart);
            return;
    }
    gSegment235130VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    gSegment235130VramEnd = ALIGN16((intptr_t) gSegment235130VramStart + segmentSize);
    Segment_SetAddress(10, gSegment235130VramStart);
}

extern uintptr_t gSegment2738A0VramStart;
extern uintptr_t gSegment2738A0VramEnd;

void Segment_SetupSegment5(void) {
    size_t segmentSize;

    D_800CD2F4 = true;
    switch (gGameMode) {
        case GAMEMODE_GP_END_CS:
            segmentSize = SEGMENT_DATA_SIZE_CONST(podium_gfx);
            break;
        default:
            D_800CD2F4 = false;
            Segment_SetAddress(5, gSegment2738A0VramStart);
            return;
    }

    gSegment2738A0VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    gSegment2738A0VramEnd = ALIGN16((intptr_t) gSegment2738A0VramStart + segmentSize);
    Segment_SetAddress(5, gSegment2738A0VramStart);
}

void Segment_LoadOverlays2(void) {
    bool isOverlay = false;
    RomOffset diskStart;
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
        case GAMEMODE_RECORDS:
            vramTextStart = SEGMENT_TEXT_START(records);
            vramStart = SEGMENT_VRAM_START(records);
            vramDataStart = SEGMENT_DATA_START(records);
            vramBssStart = SEGMENT_BSS_START(records);
            romStart = SEGMENT_ROM_START(records);
            segmentTextSize = SEGMENT_TEXT_SIZE(records);
            segmentDataSize = SEGMENT_DATA_SIZE(records);
            segmentRomSize = SEGMENT_BSS_START(records) - SEGMENT_VRAM_START(records);
            segmentVramSize = SEGMENT_VRAM_SIZE(records);
            segmentBssSize = SEGMENT_BSS_SIZE(records);
            break;
        case GAMEMODE_GP_END_CS:
            vramTextStart = SEGMENT_TEXT_START(ending);
            vramStart = SEGMENT_VRAM_START(ending);
            vramDataStart = SEGMENT_DATA_START(ending);
            vramBssStart = SEGMENT_BSS_START(ending);
            romStart = SEGMENT_ROM_START(ending);
            segmentTextSize = SEGMENT_TEXT_SIZE(ending);
            segmentDataSize = SEGMENT_DATA_SIZE(ending);
            segmentRomSize = SEGMENT_BSS_START(ending) - SEGMENT_VRAM_START(ending);
            segmentVramSize = SEGMENT_VRAM_SIZE(ending);
            segmentBssSize = SEGMENT_BSS_SIZE(ending);
            break;
        case GAMEMODE_CREATE_MACHINE:
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

    Arena_AllocateFront(0, segmentVramSize);
    CLEAR_TEXT_CACHE(vramTextStart, segmentTextSize);
    CLEAR_DATA_CACHE(vramDataStart, segmentDataSize);
    Dma_LoadOverlay(romStart, vramStart, segmentRomSize, vramBssStart, segmentBssSize);
}

void Segment_LoadOverlays(void) {
    s32 pad;
    bool isOverlay = false;
    RomOffset diskStart;
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
        case GAMEMODE_RECORDS:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
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
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_TITLE:
        case GAMEMODE_FLX_MACHINE_SELECT:
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
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
            vramTextStart = SEGMENT_TEXT_START(course_select);
            vramStart = SEGMENT_VRAM_START(course_select);
            vramDataStart = SEGMENT_DATA_START(course_select);
            vramBssStart = SEGMENT_BSS_START(course_select);
            romStart = SEGMENT_ROM_START(course_select);
            segmentTextSize = SEGMENT_TEXT_SIZE(course_select);
            segmentDataSize = SEGMENT_DATA_SIZE(course_select);
            segmentRomSize = SEGMENT_BSS_START(course_select) - SEGMENT_VRAM_START(course_select);
            segmentVramSize = SEGMENT_VRAM_SIZE(course_select);
            segmentBssSize = SEGMENT_BSS_SIZE(course_select);
            break;
        case GAMEMODE_FLX_MAIN_MENU:
        case GAMEMODE_FLX_SKIPPABLE_CREDITS:
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
        case GAMEMODE_FLX_OPTIONS_MENU:
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

    Arena_AllocateFront(0, segmentVramSize);
    if (1) {}
    CLEAR_TEXT_CACHE(vramTextStart, segmentTextSize);
    CLEAR_DATA_CACHE(vramDataStart, segmentDataSize);
    Dma_LoadOverlay(romStart, vramStart, segmentRomSize, vramBssStart, segmentBssSize);
    Segment_LoadOverlays2();
    D_800CD2E0 = 1;
    Segment_SetupSegment4();
    Segment_SetupSegment7();
    Segment_SetupSegment9();
    Segment_SetupSegment10();
    Segment_SetupSegment5();
}

extern uintptr_t gSegment17B960VramStart;

void Segment_LoadSegment4(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;

    if (D_800CD2E0 == 0) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            Dma_LoadAssetsAsync(SEGMENT_ROM_START(machine_custom_gfx), osPhysicalToVirtual(gSegment17B960VramStart),
                                SEGMENT_ROM_SIZE(machine_custom_gfx));
            romOffset = SEGMENT_ROM_START(hud_gfx);
            ramSize = SEGMENT_VRAM_SIZE(hud_gfx);
            break;
        case GAMEMODE_CREATE_MACHINE:
            Dma_LoadAssetsAsync(SEGMENT_ROM_START(machine_custom_gfx), osPhysicalToVirtual(gSegment17B960VramStart),
                                SEGMENT_ROM_SIZE(machine_custom_gfx));
            romOffset = SEGMENT_ROM_START(create_machine_textures);
            ramSize = SEGMENT_VRAM_SIZE(create_machine_textures);
            break;
        case GAMEMODE_COURSE_EDIT:
            Dma_LoadAssetsAsync(SEGMENT_ROM_START(machine_custom_gfx), osPhysicalToVirtual(gSegment17B960VramStart),
                                SEGMENT_ROM_SIZE(machine_custom_gfx));
            romOffset = SEGMENT_ROM_START(course_edit_textures_beta);
            ramSize = SEGMENT_VRAM_SIZE(course_edit_textures_beta);
            break;
        case GAMEMODE_RECORDS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            Dma_LoadAssetsAsync(SEGMENT_ROM_START(machine_custom_gfx), osPhysicalToVirtual(gSegment17B960VramStart),
                                SEGMENT_ROM_SIZE(machine_custom_gfx));
        default:
            D_800CD2E0 = 0;
            return;
    }

    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment1B8550VramStart), ramSize);
    Dma_LoadAssets(romOffset, osPhysicalToVirtual(gSegment1B8550VramStart), ramSize);
    D_800CD2E0 = 0;
}

void Segment_LoadSegment7(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;

    if (!D_800CD2E4) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            romOffset = SEGMENT_ROM_START(machine_global_gfx);
            ramSize = SEGMENT_VRAM_SIZE(machine_global_gfx);
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            romOffset = SEGMENT_ROM_START(expansion_kit_textures_beta);
            ramSize = SEGMENT_VRAM_SIZE(expansion_kit_textures_beta);
            break;
        default:
            D_800CD2E4 = false;
            return;
    }
    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize);
    Dma_LoadAssets(romOffset, osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize);
    D_800CD2E4 = false;
}

void Segment_LoadSegment9(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;
    u8* vram;

    if (!D_800CD2E8) {
        return;
    }
    switch (gGameMode) {
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            romOffset = SEGMENT_ROM_START(machine_models);
            ramSize = SEGMENT_VRAM_SIZE(machine_models);
            break;
        default:
            D_800CD2E8 = false;
            return;
    }

    vram = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(vram, ramSize);
    Dma_LoadAssets(romOffset, vram, ramSize);
    if (*(s32*) vram == (s32) 'MIO0') {
        mio0Decode(vram, osPhysicalToVirtual(gSegment22B0A0VramStart));
    }
    D_800CD2E8 = false;
}

void Segment_LoadSegment10(void) {
    s32 pad;
    s32 venue;
    s32 pad2;
    RomOffset romOffset;
    size_t ramSize;
    u8* vram;

    if (!D_800CD2EC) {
        return;
    }
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            venue = COURSE_CONTEXT()->courseData.venue;
            romOffset = D_800CD2F8[venue];
            ramSize = D_800CD350[venue] - D_800CD324[venue];
            break;
        default:
            D_800CD2EC = false;
            return;
    }
    vram = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(vram, ramSize);
    Dma_LoadAssets(romOffset, vram, ramSize);
    if (*(s32*) vram == (s32) 'MIO0') {
        mio0Decode(vram, osPhysicalToVirtual(gSegment235130VramStart));
    }
    D_800CD2EC = false;
    func_8009CED0(venue);
}

void func_80077AD8(s32 venue) {
    if ((venue >= VENUE_MUTE_CITY) && (venue <= VENUE_SILENCE) && (D_800CD2F0 < 0)) {
        D_800CD2F0 = venue;
    }
}

void Segment_LoadSegment10CourseEdit(void) {
    s32 pad;
    s32 venue;
    s32 pad2;
    RomOffset romOffset;
    size_t ramSize;
    u8* vram;

    if (D_800CD2F0 < 0) {
        return;
    }
    venue = D_800CD2F0;

    switch (gGameMode) {
        case GAMEMODE_COURSE_EDIT:
            romOffset = D_800CD2F8[venue];
            ramSize = D_800CD350[venue] - D_800CD324[venue];
            break;
        default:
            return;
    }

    vram = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(vram, ramSize);
    Dma_LoadAssets(romOffset, vram, ramSize);
    if (*(s32*) vram == (s32) 'MIO0') {
        mio0Decode(vram, osPhysicalToVirtual(gSegment235130VramStart));
    }
    D_800CD2F0 = -1;
    func_8009CED0(venue);
}

void Segment_LoadSegment5(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;
    u8* vram;

    if (!D_800CD2F4) {
        return;
    }
    if (gGameMode != GAMEMODE_GP_END_CS) {
        D_800CD2F4 = false;
        return;
    }
    romOffset = SEGMENT_ROM_START(podium_gfx);
    ramSize = SEGMENT_VRAM_SIZE(podium_gfx);

    vram = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(vram, ramSize);
    Dma_LoadAssets(romOffset, vram, ramSize);
    if (*(s32*) vram == (s32) 'MIO0') {
        mio0Decode(vram, osPhysicalToVirtual(gSegment2738A0VramStart));
    }
    D_800CD2F4 = false;
}

void Segment_LoadAssets(void) {
    Segment_LoadSegment4();
    Segment_LoadSegment7();
    Segment_LoadSegment9();
    Segment_LoadSegment10();
    Segment_LoadSegment10CourseEdit();
    Segment_LoadSegment5();
}
