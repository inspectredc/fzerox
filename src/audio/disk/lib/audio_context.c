#include "audio.h"
#include "macros.h"

s8 audioPad806ECA00[0x10];
AudioContext gAudioCtx;
AudioCustomUpdateFunction gAudioCustomUpdateFunction;
OSMesgQueue D_806F2328 ALIGNED(8);
OSMesg D_806F2340[1];
LbaVaddrPair D_806F2348;
AudioDiskInfo D_806F2350;
