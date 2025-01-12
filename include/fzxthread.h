#ifndef FZX_THREAD_H
#define FZX_THREAD_H

#include "libultra/ultra64.h"
#include "gfx.h"

#define MQ_GET_MESG(mq, mesg) (osRecvMesg((mq), (OSMesg*) (mesg), OS_MESG_NOBLOCK) != -1)
#define MQ_WAIT_FOR_MESG(mq, mesg) osRecvMesg((mq), (OSMesg*) (mesg), OS_MESG_BLOCK)
#define MQ_CLEAR_QUEUE(mq) do {s32 m1 = -1; s32 mesg; do {} while(osRecvMesg((mq), (OSMesg*) &(mesg), OS_MESG_NOBLOCK) != m1);} while(0)

// Main Message Queue
#define EVENT_MESG_SI 0xB
#define EVENT_MESG_GFX_TASK_SET 0x15
#define EVENT_MESG_AUDIO_TASK_SET 0x16
#define EVENT_MESG_SP 0x18
#define EVENT_MESG_DP 0x19
#define EVENT_MESG_VI 0x1A

// Audio Task Message Queue
#define EVENT_MESG_NEXT_AUDIO_TASK 0x1F

typedef enum SpTaskState {
    /* 0 */ SP_TASK_INACTIVE,
    /* 1 */ SP_TASK_YIELDING,
    /* 2 */ SP_TASK_AUDIO,
    /* 3 */ SP_TASK_GFX,
} SpTaskState;

typedef enum ThreadID {
    /* 0 */ THREAD_ID_SYSTEM,
    /* 1 */ THREAD_ID_IDLE,
    /* 2 */ THREAD_ID_FAULT,
    /* 3 */ THREAD_ID_MAIN,
    /* 4 */ THREAD_ID_AUDIO,
    /* 5 */ THREAD_ID_GAME,
    /* 6 */ THREAD_ID_6,
    /* 7 */ THREAD_ID_RESET,
} ThreadID;

#endif // FZX_THREAD_H
