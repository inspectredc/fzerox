#ifndef FZX_THREAD_H
#define FZX_THREAD_H

#include "libultra/ultra64.h"
#include "gfx.h"

#define MQ_GET_MESG(mq, mesg) (osRecvMesg((mq), (OSMesg*) (mesg), OS_MESG_NOBLOCK) != -1)
#define MQ_WAIT_FOR_MESG(mq, mesg) osRecvMesg((mq), (OSMesg*) (mesg), OS_MESG_BLOCK)
#define MQ_CLEAR_QUEUE(mq) do {s32 m1 = -1; s32 mesg; do {} while(osRecvMesg((mq), (OSMesg*) &(mesg), OS_MESG_NOBLOCK) != m1);} while(0)

#endif // FZX_THREAD_H
