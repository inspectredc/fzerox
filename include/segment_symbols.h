#ifndef SEGMENT_SYMBOLS_H
#define SEGMENT_SYMBOLS_H

#include <PR/ultratypes.h>

#define DECLARE_VRAM_SEGMENT(name) \
    extern u8 name ## _VRAM[]; \
    extern u8 name ## _VRAM_END[]

#define DECLARE_ROM_SEGMENT(name) \
    extern u8 name ## _ROM_START[]; \
    extern u8 name ## _ROM_END[]

#define DECLARE_TEXT_SEGMENT(name)   \
    extern u8 name ## _TEXT_START[]; \
    extern u8 name ## _TEXT_END[]

#define DECLARE_DATA_SEGMENT(name)   \
    extern u8 name ## _DATA_START[]; \
    extern u8 name ## _RODATA_END[]

#define DECLARE_BSS_SEGMENT(name)   \
    extern u8 name ## _BSS_START[]; \
    extern u8 name ## _BSS_END[]

#define DECLARE_SEGMENT(name) \
    DECLARE_VRAM_SEGMENT(name); \
    DECLARE_ROM_SEGMENT(name); \
    DECLARE_TEXT_SEGMENT(name); \
    DECLARE_DATA_SEGMENT(name); \
    DECLARE_BSS_SEGMENT(name)

#define SEGMENT_VRAM_START(segment) (segment ## _VRAM)
#define SEGMENT_VRAM_END(segment)   (segment ## _VRAM_END)
#define SEGMENT_VRAM_SIZE(segment)  (SEGMENT_VRAM_END(segment) - SEGMENT_VRAM_START(segment))

#define SEGMENT_ROM_START(segment) (segment ## _ROM_START)
#define SEGMENT_ROM_END(segment)   (segment ## _ROM_END)
#define SEGMENT_ROM_SIZE(segment)  (SEGMENT_ROM_END(segment) - SEGMENT_ROM_START(segment))

#define SEGMENT_TEXT_START(segment) (segment ## _TEXT_START)
#define SEGMENT_TEXT_END(segment)   (segment ## _TEXT_END)
#define SEGMENT_TEXT_SIZE(segment)  (SEGMENT_TEXT_END(segment) - SEGMENT_TEXT_START(segment))

#define SEGMENT_DATA_START(segment) (segment ## _DATA_START)
#define SEGMENT_DATA_END(segment)   (segment ## _RODATA_END)
#define SEGMENT_DATA_SIZE(segment)  (SEGMENT_DATA_END(segment) - SEGMENT_DATA_START(segment))

#define SEGMENT_BSS_START(segment) (segment ## _BSS_START)
#define SEGMENT_BSS_END(segment)   (segment ## _BSS_END)
#define SEGMENT_BSS_SIZE(segment)  (SEGMENT_BSS_END(segment) - SEGMENT_BSS_START(segment))

DECLARE_BSS_SEGMENT(audio_context);

DECLARE_SEGMENT(ovl_i3);
DECLARE_SEGMENT(ovl_i4);
DECLARE_SEGMENT(ovl_i5);
DECLARE_SEGMENT(ovl_i6);
DECLARE_SEGMENT(ovl_i7);
DECLARE_SEGMENT(ovl_i8);
DECLARE_SEGMENT(ovl_i9);

DECLARE_SEGMENT(mio0_segment_3);
DECLARE_SEGMENT(mio0_segment_4);
DECLARE_SEGMENT(mio0_segment_5);
DECLARE_SEGMENT(mio0_segment_6);
DECLARE_SEGMENT(mio0_segment_7);
DECLARE_SEGMENT(mio0_segment_8);
DECLARE_SEGMENT(mio0_segment_9);
DECLARE_SEGMENT(mio0_segment_10);
DECLARE_SEGMENT(mio0_segment_11);
DECLARE_SEGMENT(mio0_segment_12);
DECLARE_SEGMENT(mio0_segment_13);

DECLARE_SEGMENT(ovl_i11);

DECLARE_VRAM_SEGMENT(unk_context);
DECLARE_BSS_SEGMENT(unk_context);

#endif
