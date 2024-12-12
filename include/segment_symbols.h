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
    extern u8 name ## _DATA_SIZE[]; \
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

#define SEGMENT_DATA_SIZE_CONST(segment) (segment ## _DATA_SIZE)

#define SEGMENT_BSS_START(segment) (segment ## _BSS_START)
#define SEGMENT_BSS_END(segment)   (segment ## _BSS_END)
#define SEGMENT_BSS_SIZE(segment)  (SEGMENT_BSS_END(segment) - SEGMENT_BSS_START(segment))

DECLARE_BSS_SEGMENT(audio_context);

DECLARE_SEGMENT(unk_nmi);
DECLARE_SEGMENT(leo);
DECLARE_SEGMENT(ovl_i2);
DECLARE_SEGMENT(ovl_i3);
DECLARE_SEGMENT(ovl_i4);
DECLARE_SEGMENT(ovl_i5);
DECLARE_SEGMENT(ovl_i6);
DECLARE_SEGMENT(ovl_i7);
DECLARE_SEGMENT(ovl_i8);
DECLARE_SEGMENT(ovl_i9);
DECLARE_SEGMENT(ovl_i10);

DECLARE_SEGMENT(segment_145B70);
DECLARE_SEGMENT(course_edit_textures);
DECLARE_SEGMENT(create_machine_textures);
DECLARE_SEGMENT(segment_16C8A0);
DECLARE_SEGMENT(segment_17B1E0);
DECLARE_SEGMENT(segment_17B960);
DECLARE_SEGMENT(segment_1B8550);
DECLARE_SEGMENT(segment_1E23F0);
DECLARE_SEGMENT(segment_22B0A0);
DECLARE_SEGMENT(segment_235130);
DECLARE_SEGMENT(segment_239A80);
DECLARE_SEGMENT(segment_23EC50);
DECLARE_SEGMENT(segment_243D90);
DECLARE_SEGMENT(segment_24A270);
DECLARE_SEGMENT(segment_2507F0);
DECLARE_SEGMENT(segment_255100);
DECLARE_SEGMENT(segment_259600);
DECLARE_SEGMENT(segment_25F360);
DECLARE_SEGMENT(segment_266C20);
DECLARE_SEGMENT(segment_26D780);
DECLARE_SEGMENT(segment_2738A0);
DECLARE_SEGMENT(segment_2747F0);
DECLARE_SEGMENT(segment_2787F0);
DECLARE_SEGMENT(segment_27F200);
DECLARE_SEGMENT(segment_2AD1E0);
DECLARE_SEGMENT(segment_2B9EA0);

DECLARE_SEGMENT(ovl_i11);

DECLARE_SEGMENT(audio_seq);
DECLARE_SEGMENT(audio_bank);
DECLARE_SEGMENT(audio_table);

DECLARE_VRAM_SEGMENT(unk_context);
DECLARE_BSS_SEGMENT(unk_context);

#endif
