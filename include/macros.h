#ifndef MACROS_H
#define MACROS_H

#include "alignment.h"

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))
#define SQ(x) ((x) * (x))
#define CB(x) ((x) * (x) * (x))

#define ABS(x) ((x) >= 0 ? (x) : -(x))

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

/*
 * Macros for libultra
 */

#if defined(__sgi)
#define PRINTF
#else
#define PRINTF(...)
#endif

#define ALIGNED(x) __attribute__((aligned(x)))
#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))
#define STUBBED_PRINTF(x) ((void)(x))
#define UNUSED __attribute__((unused))

#ifndef __GNUC__
#define __attribute__(x)
#endif

#define OS_MSEC_TO_CYCLES(n)    OS_USEC_TO_CYCLES((n) * 1000LL)
#define OS_SEC_TO_CYCLES(n)     OS_MSEC_TO_CYCLES((n) * 1000LL)

#endif // MACROS_H
