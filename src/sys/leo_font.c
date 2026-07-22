#include "libultra/ultra64.h"
#include "macros.h"

UNUSED u8 D_80400000[0x8];
#if BUILD_REVISION <= REVISION_A
u8 gLeoFontBuffer[181 * 0x80];
#elif BUILD_REVISION == REVISION_B
u8 gLeoFontBuffer[96 * 0x80];
#elif BUILD_REVISION == REVISION_C
u8 gLeoFontBuffer[96 * 0x80];
u8 D_80403008[0x10];
#elif BUILD_REVISION == REVISION_D
u8 gLeoFontBuffer[110 * 0x80];
#endif
