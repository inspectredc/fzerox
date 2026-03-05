#include "audio.h"
#include "aseq.h"
#include "sfx.h"

// clang-format off
AudioTable gSoundFontTable = {
    { FONT_MAX, 0, 0, 0 },
    {
    //    Offset, Size,   Medium,     CachePolicy,    sampleBankId1                          | sampleBankId2, numInstruments | numDrums, numSfx
        { 0,      0xB0,   MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_GUITAR << 8)                   | 0xFF,          (1 << 8)       | 0,        0 }, /* FONT_GUITAR */
        { 0xB0,   0x2CF0, MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DD_SOUND_EFFECTS << 8)         | SAMPLE_BGM,    (71 << 8)      | 0,        0 }, /* FONT_SOUND_EFFECTS */
        { 0x2DA0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_MUTE_CITY << 8)          | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_MUTE_CITY */
        { 0x2F20, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_SILENCE << 8)            | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_SILENCE */
        { 0x30A0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_SAND_OCEAN << 8)         | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_SAND_OCEAN */
        { 0x3220, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_PORT_TOWN << 8)          | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_PORT_TOWN */
        { 0x33A0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_BIG_BLUE << 8)           | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_BIG_BLUE */
        { 0x3520, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_DEVILS_FOREST << 8)      | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_DEVILS_FOREST */
        { 0x36A0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_RED_CANYON << 8)         | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_RED_CANYON */
        { 0x3820, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_SECTOR << 8)             | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_SECTOR */
        { 0x39A0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_WHITE_LAND << 8)         | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_WHITE_LAND */
        { 0x3B20, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_RAINBOW_ROAD << 8)       | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_RAINBOW_ROAD */
        { 0x3CA0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_NEW_03 << 8)             | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_NEW_03 */
        { 0x3E20, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_NEW_02 << 8)             | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_NEW_02 */
        { 0x3FA0, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_NEW_01 << 8)             | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_NEW_01 */
        { 0x4120, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_NEW_04 << 8)             | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_NEW_04 */
        { 0x42A0, 0xD0,   MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_TITLE << 8)              | 0xFF,          (1 << 8)       | 0,        0 }, /* FONT_DDBGM_TITLE */
        { 0x4370, 0xD0,   MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_SELECT << 8)             | 0xFF,          (1 << 8)       | 0,        0 }, /* FONT_DDBGM_SELECT */
        { 0x4440, 0xD0,   MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_OPTION << 8)             | 0xFF,          (1 << 8)       | 0,        0 }, /* FONT_DDBGM_OPTION */
        { 0x4510, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_DEATHRACE << 8)          | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_DEATHRACE */
        { 0x4690, 0x890,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_COURSE_EDITOR << 8)      | 0xFF,          (11 << 8)      | 0,        0 }, /* FONT_DDBGM_COURSE_EDITOR */
        { 0x4F20, 0x950,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_MACHINE_EDITOR << 8)     | 0xFF,          (6 << 8)       | 0,        0 }, /* FONT_DDBGM_MACHINE_EDITOR */
        { 0x5870, 0x180,  MEDIUM_LBA, CACHEPOLICY_0,  (SAMPLE_DDBGM_EAD_DEMO << 8)           | 0xFF,          (2 << 8)       | 0,        0 }, /* FONT_DDBGM_EAD_DEMO */
    }
};

u8 gSequenceFontTable[] = {
    S16(0x2E), /* SEQ_GUITAR */
    S16(0x30), /* SEQ_SOUND_EFFECTS */
    S16(0x32), /* SEQ_DDBGM_MUTE_CITY */
    S16(0x34), /* SEQ_DDBGM_SILENCE */
    S16(0x36), /* SEQ_DDBGM_SAND_OCEAN */
    S16(0x38), /* SEQ_DDBGM_PORT_TOWN */
    S16(0x3A), /* SEQ_DDBGM_BIG_BLUE */
    S16(0x3C), /* SEQ_DDBGM_DEVILS_FOREST */
    S16(0x3E), /* SEQ_DDBGM_RED_CANYON */
    S16(0x40), /* SEQ_DDBGM_SECTOR */
    S16(0x42), /* SEQ_DDBGM_WHITE_LAND */
    S16(0x44), /* SEQ_DDBGM_RAINBOW_ROAD */
    S16(0x46), /* SEQ_DDBGM_NEW_03 */
    S16(0x48), /* SEQ_DDBGM_NEW_02 */
    S16(0x4A), /* SEQ_DDBGM_NEW_01 */
    S16(0x4C), /* SEQ_DDBGM_NEW_04 */
    S16(0x4E), /* SEQ_DDBGM_TITLE */
    S16(0x50), /* SEQ_DDBGM_SELECT */
    S16(0x52), /* SEQ_DDBGM_OPTION */
    S16(0x54), /* SEQ_DDBGM_DEATHRACE */
    S16(0x56), /* SEQ_DDBGM_COURSE_EDITOR */
    S16(0x58), /* SEQ_DDBGM_MACHINE_EDITOR */
    S16(0x5A), /* SEQ_DDBGM_EAD_DEMO */
    /* 0x2E */ 1, FONT_GUITAR,
    /* 0x30 */ 1, FONT_SOUND_EFFECTS,
    /* 0x32 */ 1, FONT_DDBGM_MUTE_CITY,
    /* 0x34 */ 1, FONT_DDBGM_SILENCE,
    /* 0x36 */ 1, FONT_DDBGM_SAND_OCEAN,
    /* 0x38 */ 1, FONT_DDBGM_PORT_TOWN,
    /* 0x3A */ 1, FONT_DDBGM_BIG_BLUE,
    /* 0x3C */ 1, FONT_DDBGM_DEVILS_FOREST,
    /* 0x3E */ 1, FONT_DDBGM_RED_CANYON,
    /* 0x40 */ 1, FONT_DDBGM_SECTOR,
    /* 0x42 */ 1, FONT_DDBGM_WHITE_LAND,
    /* 0x44 */ 1, FONT_DDBGM_RAINBOW_ROAD,
    /* 0x46 */ 1, FONT_DDBGM_NEW_03,
    /* 0x48 */ 1, FONT_DDBGM_NEW_02,
    /* 0x4A */ 1, FONT_DDBGM_NEW_01,
    /* 0x4C */ 1, FONT_DDBGM_NEW_04,
    /* 0x4E */ 1, FONT_DDBGM_TITLE,
    /* 0x50 */ 1, FONT_DDBGM_SELECT,
    /* 0x52 */ 1, FONT_DDBGM_OPTION,
    /* 0x54 */ 1, FONT_DDBGM_DEATHRACE,
    /* 0x56 */ 1, FONT_DDBGM_COURSE_EDITOR,
    /* 0x58 */ 1, FONT_DDBGM_MACHINE_EDITOR,
    /* 0x5A */ 1, FONT_DDBGM_EAD_DEMO,
};

static s32 sAudioTablePadding = 0;

AudioTable gSequenceTable = {
    { SEQ_MAX, 0, 0, 0 },
    {
    //    Offset, Size,   Medium,     CachePolicy
        { 0x0,    0x30,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_GUITAR */
        { 0x30,   0xB50,  MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_SOUND_EFFECTS */
        { 0xB80,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_MUTE_CITY */
        { 0xBC0,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_SILENCE */
        { 0xC00,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_SAND_OCEAN */
        { 0xC40,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_PORT_TOWN */
        { 0xC80,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_BIG_BLUE */
        { 0xCC0,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_DEVILS_FOREST */
        { 0xD00,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_RED_CANYON */
        { 0xD40,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_SECTOR */
        { 0xD80,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_WHITE_LAND */
        { 0xDC0,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_RAINBOW_ROAD */
        { 0xE00,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_NEW_03 */
        { 0xE40,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_NEW_02 */
        { 0xE80,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_NEW_01 */
        { 0xEC0,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_NEW_04 */
        { 0xF00,  0x30,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_TITLE */
        { 0xF30,  0x30,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_SELECT */
        { 0xF60,  0x30,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_OPTION */
        { 0xF90,  0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_DEATHRACE */
        { 0xFD0,  0x1930, MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_COURSE_EDITOR */
        { 0x2900, 0x13B0, MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_MACHINE_EDITOR */
        { 0x3CB0, 0x40,   MEDIUM_LBA, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_DDBGM_EAD_DEMO */
    }
};

AudioTable gSampleBankTable = {
    { SAMPLE_MAX, 0, 0, 0 },
    {
    //    Offset,    Size,     Medium,      CachePolicy
        { 0x0,       0x2AA90,  MEDIUM_CART, CACHEPOLICY_4, 0x0, 0x0, 0x0 }, /* SAMPLE_SOUND_EFFECTS */
        { 0x2AA90,   0xA048D0, MEDIUM_CART, CACHEPOLICY_4, 0x0, 0x0, 0x0 }, /* SAMPLE_BGM */
        { 0xA2F360,  0xFE70,   MEDIUM_CART, CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_GUITAR */
        { 0x0,       0x2AA90,  MEDIUM_LBA,  CACHEPOLICY_1, 0x0, 0x0, 0x0 }, /* SAMPLE_DD_SOUND_EFFECTS */
        { 0x2AA90,   0x1A42A0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_MUTE_CITY */
        { 0x1CED30,  0x24C0C0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_SILENCE */
        { 0x41ADF0,  0x1A4AA0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_SAND_OCEAN */
        { 0x5BF890,  0x203500, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_PORT_TOWN */
        { 0x7C2D90,  0x216D20, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_BIG_BLUE */
        { 0x9D9AB0,  0x17A420, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_DEVILS_FOREST */
        { 0xB53ED0,  0x20C3E0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_RED_CANYON */
        { 0xD602B0,  0x18D1E0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_SECTOR */
        { 0xEED490,  0x226C20, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_WHITE_LAND */
        { 0x11140B0, 0x248F00, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_RAINBOW_ROAD */
        { 0x135CFB0, 0x22C820, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_NEW_03 */
        { 0x15897D0, 0x249C20, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_NEW_02 */
        { 0x17D33F0, 0x245C80, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_NEW_01 */
        { 0x1A19070, 0x1658A0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_NEW_04 */
        { 0x4621D0,  0x73920,  MEDIUM_CART, CACHEPOLICY_4, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_TITLE */
        { 0x4D5AF0,  0x3CD00,  MEDIUM_CART, CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_SELECT */
        { 0x8B1210,  0x23580,  MEDIUM_CART, CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_OPTION */
        { 0x1B7E910, 0x1193E0, MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_DEATHRACE */
        { 0x1C97CF0, 0x404A0,  MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_COURSE_EDITOR */
        { 0x1CD8190, 0x3E220,  MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_MACHINE_EDITOR */
        { 0x1D163B0, 0x85A40,  MEDIUM_LBA,  CACHEPOLICY_2, 0x0, 0x0, 0x0 }, /* SAMPLE_DDBGM_EAD_DEMO */
    }
};
// clang-format on
