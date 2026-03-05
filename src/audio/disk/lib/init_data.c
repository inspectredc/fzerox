#include "macros.h"
#include "audio.h"

TempoData gTempoData = {
    0xA00,
    SEQTICKS_PER_BEAT,
};

AudioHeapInitSizes gAudioHeapInitSizes = {
    ALIGN16(sizeof(gAudioHeap) - 0x100),
    0x10800,
    0x9800,
};
