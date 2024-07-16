#ifndef MACROS_H
#define MACROS_H

#include "alignment.h"

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))
#define SQ(x) ((x) * (x))
#define CB(x) ((x) * (x) * (x))

#define ABS(x) ((x) >= 0 ? (x) : -(x))

#define CROSS_X(v1Ptr, v2Ptr) ((v1Ptr)->y * (v2Ptr)->z - (v1Ptr)->z * (v2Ptr)->y)
#define CROSS_Y(v1Ptr, v2Ptr) ((v1Ptr)->z * (v2Ptr)->x - (v1Ptr)->x * (v2Ptr)->z)
#define CROSS_Z(v1Ptr, v2Ptr) ((v1Ptr)->x * (v2Ptr)->y - (v1Ptr)->y * (v2Ptr)->x)
#define SQ_SUM(vPtr) (SQ((vPtr)->x) + SQ((vPtr)->y) + SQ((vPtr)->z))
#define DOT_XYZ(v1Ptr, v2Ptr) ((v1Ptr)->x * (v2Ptr)->x + (v1Ptr)->y * (v2Ptr)->y + (v1Ptr)->z * (v2Ptr)->z)
#define DIST_DOT_XYZ(v1Ptr, v2APtr, v2BPtr) ((v1Ptr)->x * ((v2APtr)->x - (v2BPtr)->x) + (v1Ptr)->y * ((v2APtr)->y - (v2BPtr)->y) + (v1Ptr)->z * ((v2APtr)->z - (v2BPtr)->z))


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
