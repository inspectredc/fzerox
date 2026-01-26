#ifndef AUDIO_H
#define AUDIO_H

#ifdef EXPANSION_KIT
#include "src/audio/disk/lib/audio.h"
#else
#include "src/audio/rom/lib/audio.h"
#endif

#endif // AUDIO_H
