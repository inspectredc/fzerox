#include "audio.h"
#include "aseq.h"
#include "sfx.h"

// clang-format off
AudioTable gSoundFontTableData = {
    { 2, 0, 0, 0 },
    {
    //    Offset, Size,   Medium,      CachePolicy,   sampleBankId1                    | sampleBankId2, numInstruments | numDrums, numSfx
        { 0,      0x2CE0, MEDIUM_CART, CACHEPOLICY_0, (SAMPLE_SOUND_EFFECTS << 8)      | SAMPLE_BGM,    (71 << 8)      | 0,        0 }, /* FONT_SOUND_EFFECTS */
        { 0x2CE0, 0xB0,   MEDIUM_CART, CACHEPOLICY_0, (SAMPLE_GUITAR << 8)             | 0xFF,          (1 << 8)       | 0,        0 }, /* FONT_GUITAR */
    }
};

u8 gSequenceFontTableData[] = {
    S16(0x4), /* SEQ_SOUND_EFFECTS */
    S16(0x6), /* SEQ_GUITAR */
    /* 0x4 */ 1, FONT_SOUND_EFFECTS,
    /* 0x6 */ 1, FONT_GUITAR,
};

static s32 sAudioTablePadding = 0;
static s32 sAudioTablePadding2 = 0;

AudioTable gSequenceTableData = {
    { SEQ_MAX, 0, 0, 0 },
    {
    //    Offset, Size,   Medium,      CachePolicy
        { 0x0,    0xC10,  MEDIUM_CART, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_SOUND_EFFECTS */
        { 0xC10,  0x30,   MEDIUM_CART, CACHEPOLICY_0, 0x0, 0x0, 0x0 }, /* SEQ_GUITAR */
    }
};

AudioTable gSampleBankTableData = {
    { SAMPLE_MAX, 0, 0, 0 },
    {
    //    Offset,    Size,     Medium,      CachePolicy
        { 0x0,       0x2AA90,  MEDIUM_CART, CACHEPOLICY_4, 0x0, 0x0, 0x0 }, /* SAMPLE_SOUND_EFFECTS */
        { 0x2AA90,   0xA048D0, MEDIUM_CART, CACHEPOLICY_4, 0x0, 0x0, 0x0 }, /* SAMPLE_BGM */
        { 0xA2F360,  0xFE70,   MEDIUM_CART, CACHEPOLICY_4, 0x0, 0x0, 0x0 }, /* SAMPLE_GUITAR */
    }
};
// clang-format on
