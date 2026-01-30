#include "libultra/ultra64.h"
#include "macros.h"

UNUSED u8 D_80400000[0x8];
#ifndef EXPANSION_KIT
#ifdef VERSION_JP
u8 gLeoFontBuffer[181 * 0x80];
#else
u8 gLeoFontBuffer[96 * 0x80];
#endif
#else
u8 gLeoFontBuffer[110 * 0x80];
#endif
