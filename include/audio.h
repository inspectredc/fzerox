#ifndef AUDIO_H
#define AUDIO_H

#include "libultra/ultra64.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"

struct Note;
struct NotePool;
struct SequenceChannel;
struct SequenceLayer;

typedef struct {
    /* 0x0 */ u8* startRamAddr; // start addr of the pool
    /* 0x4 */ u8* curRamAddr;   // address of the next available memory for allocation
    /* 0x8 */ s32 size;         // size of the pool
    /* 0xC */ s32 numEntries;   // number of entries allocated to the pool
} AudioAllocPool; // size = 0x10

typedef struct {
    /* 0x0 */ size_t miscPoolSize;
    /* 0x4 */ size_t unkSizes[2];
    /* 0xC */ size_t cachePoolSize;
} AudioSessionPoolSplit; // size = 0x10

typedef struct {
    /* 0x0 */ size_t persistentCommonPoolSize;
    /* 0x4 */ size_t temporaryCommonPoolSize;
} AudioCachePoolSplit; // size = 0x8

typedef struct {
    /* 0x0 */ size_t seqCacheSize;
    /* 0x4 */ size_t fontCacheSize;
    /* 0x8 */ size_t sampleBankCacheSize;
} AudioCommonPoolSplit; // size = 0xC

typedef struct {
    /* 0x00 */ s8 inUse;
    /* 0x01 */ s8 origMedium;
    /* 0x02 */ s8 sampleBankId;
    /* 0x03 */ char unk_03[0x5];
    /* 0x08 */ u8* allocatedAddr;
    /* 0x0C */ void* sampleAddr;
    /* 0x10 */ size_t size;
} SampleCacheEntry; // size = 0x14

typedef struct {
    /* 0x000 */ AudioAllocPool pool;
    /* 0x010 */ SampleCacheEntry entries[32];
    /* 0x290 */ s32 numEntries;
} AudioSampleCache; // size = 0x294

typedef struct {
    /* 0x0 */ u8* ramAddr;
    /* 0x4 */ size_t size;
    /* 0x8 */ s16 tableType;
    /* 0xA */ s16 id;
} AudioCacheEntry; // size = 0xC

typedef struct {
    /* 0x00 */ u32 numEntries;
    /* 0x04 */ AudioAllocPool pool;
    /* 0x14 */ AudioCacheEntry entries[16];
} AudioPersistentCache; // size = 0xD4

typedef struct {
    /* 0x00 */ u32 nextSide;
    /* 0x04 */ AudioAllocPool pool;
    /* 0x14 */ AudioCacheEntry entries[2];
} AudioTemporaryCache; // size = 0x2C

typedef struct {
    /* 0x00 */ AudioAllocPool pool;
    /* 0x10 */ AudioCacheEntry entries[32];
} AudioPermanentCache; // size = 0x190

typedef struct {
    /* 0x000 */ AudioPersistentCache persistent;
    /* 0x0D4 */ AudioTemporaryCache temporary;
    /* 0x100 */ s8 pad100[0x10];
} AudioCache; // size = 0x110

typedef struct {
    /* 0x0 */ union {
        u32 opArgs;
        struct {
            u8 op;
            u8 arg0;
            u8 arg1;
            u8 arg2;
        };
    };
    /* 0x4 */ union {
        void* data;
        f32 asFloat;
        s32 asInt;
        u16 asUShort;
        s8 asSbyte;
        u8 asUbyte;
        u32 asUInt;
    };
} AudioCmd; // size = 0x8

typedef struct {
    /* 0x00 */ s8 status;
    /* 0x01 */ s8 delay;
    /* 0x02 */ s8 medium;
    /* 0x04 */ u8* ramAddr;
    /* 0x08 */ uintptr_t curDevAddr;
    /* 0x0C */ u8* curRamAddr;
    /* 0x10 */ u32 bytesRemaining;
    /* 0x14 */ size_t chunkSize;
    /* 0x18 */ OSMesg retMsg;
    /* 0x1C */ OSMesgQueue* retQueue;
    /* 0x20 */ OSMesgQueue mesgQueue;
    /* 0x38 */ OSMesg msg;
    /* 0x3C */ OSIoMesg ioMesg;
} AudioAsyncLoad; // size = 0x54

typedef struct {
    /* 0x00 */ s32 sampleBankId1;
    /* 0x04 */ s32 sampleBankId2;
    /* 0x08 */ s32 baseAddr1;
    /* 0x0C */ s32 baseAddr2;
    /* 0x10 */ u32 medium1;
    /* 0x14 */ u32 medium2;
} SampleBankRelocInfo; // size = 0x18

typedef struct {
    /* 0x00 */ u8 downsampleRate;
    /* 0x01 */ u8 windowSize;
    /* 0x02 */ u16 decayRatio; // determines how much reverb persists
    /* 0x04 */ u16 volume;
    /* 0x06 */ u16 leakRtL;
    /* 0x08 */ u16 leakLtR;
    /* 0x0A */ s8 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s8 padE[0x4];
} ReverbSettings; // size = 0x12

/**
 * The high-level audio specifications requested when initializing or resetting the audio heap.
 * The audio heap can be reset on various occasions, including on most scene transitions.
 */
typedef struct {
    /* 0x00 */ u32 samplingFrequency; // Target sampling rate in Hz
    /* 0x04 */ u8 numBuffers;
    /* 0x05 */ u8 numNotes;
    /* 0x06 */ u8 numSequencePlayers;
    /* 0x07 */ u8 numReverbs;
    /* 0x08 */ ReverbSettings* reverbSettings;
    /* 0x0C */ u16 unk_14;
    /* 0x10 */ size_t persistentSeqCacheSize;  // size of cache on audio pool to store sequences persistently
    /* 0x14 */ size_t persistentFontCacheSize; // size of cache on audio pool to store soundFonts persistently
    /* 0x18 */ size_t persistentSampleBankCacheSize;      // size of cache on audio pool to store entire sample banks persistently
    /* 0x1C */ size_t temporarySeqCacheSize;   // size of cache on audio pool to store sequences temporarily
    /* 0x20 */ size_t temporaryFontCacheSize;  // size of cache on audio pool to store soundFonts temporarily
    /* 0x24 */ size_t temporarySampleBankCacheSize; // size of cache on audio pool to store entire sample banks temporarily
    /* 0x28 */ size_t persistentSampleCacheSize; // size of cache in the audio misc pool to store individual samples persistently
    /* 0x2C */ size_t temporarySampleCacheSize;  // size of cache in the audio misc pool to store individual samples temporarily
} AudioSpec; // size = 0x30

typedef struct {
    /* 0x00 */ s16 count;
    /* 0x02 */ u16 samplingFrequency; // Target sampling rate in Hz
    /* 0x04 */ u16 aiSamplingFrequency; // True sampling rate of the audio interface (AI), see `osAiSetFrequency`
    /* 0x06 */ s16 samplesPerFrameTarget;
    /* 0x08 */ s16 maxAiBufferLength;
    /* 0x0A */ s16 minAiBufferLength;
    /* 0x0C */ s16 ticksPerUpdate; // for each audio thread update, number of ticks to process audio
    /* 0x0E */ s16 samplesPerTick;
    /* 0x10 */ s16 samplesPerTickMax;
    /* 0x12 */ s16 samplesPerTickMin;
    /* 0x14 */ s16 numSequencePlayers;
    /* 0x18 */ f32 resampleRate;
    /* 0x1C */ f32 ticksPerUpdateInv; // inverse (reciprocal) of ticksPerUpdate
    /* 0x20 */ f32 ticksPerUpdateInvScaled; // ticksPerUpdateInv scaled down by a factor of 256
    /* 0x24 */ f32 ticksPerUpdateScaled; // ticksPerUpdate scaled down by a factor of 4
} AudioBufferParameters; // size = 0x28

typedef struct AudioListItem {
    // A node in a circularly linked list. Each node is either a head or an item:
    // - Items can be either detached (prev = NULL), or attached to a list.
    //   'value' points to something of interest.
    // - List heads are always attached; if a list is empty, its head points
    //   to itself. 'count' contains the size of the list.
    // If the list holds notes, 'pool' points back to the pool where it lives.
    // Otherwise, that member is NULL.
    /* 0x00 */ struct AudioListItem* prev;
    /* 0x04 */ struct AudioListItem* next;
    /* 0x08 */ union {
        void* value; // either Note* or SequenceLayer*
        s32 count;
    } u;
    /* 0x0C */ struct NotePool* pool;
} AudioListItem; // size = 0x10

typedef struct NotePool {
    /* 0x00 */ AudioListItem disabled;
    /* 0x10 */ AudioListItem decaying;
    /* 0x20 */ AudioListItem releasing;
    /* 0x30 */ AudioListItem active;
} NotePool; // size = 0x40

typedef struct {
    /* 0x00 */ u8* pc;             // program counter
    /* 0x04 */ u8* stack[4];
    /* 0x14 */ u8 remLoopIters[4]; // remaining loop iterations
    /* 0x18 */ u8 depth;
    /* 0x19 */ s8 value;
} SeqScriptState; // size = 0x1C

typedef struct {
    /* 0x000 */ u8 enabled : 1;
    /* 0x000 */ u8 finished : 1;
    /* 0x000 */ u8 muted : 1;
    /* 0x000 */ u8 seqDmaInProgress : 1;
    /* 0x000 */ u8 fontDmaInProgress : 1;
    /* 0x000 */ u8 recalculateVolume : 1;
    /* 0x000 */ u8 stopScript : 1;
    /* 0x000 */ u8 pad0_2 : 1;
    /* 0x001 */ u8 state;
    /* 0x002 */ u8 noteAllocPolicy;
    /* 0x003 */ u8 muteBehavior;
    /* 0x004 */ u8 seqId;
    /* 0x005 */ u8 defaultFont;
    /* 0x006 */ s8 pad6[0x2];
    /* 0x008 */ u16 tempo;
    /* 0x00A */ u16 tempoAcc;
    /* 0x00C */ s16 tempoChange;
    /* 0x00E */ s16 transposition;
    /* 0x010 */ u16 delay;
    /* 0x012 */ u16 fadeTimer;
    /* 0x014 */ u16 fadeTimerUnkEu;
    /* 0x016 */ s8 pad16[0x2];
    /* 0x018 */ u8* seqData;
    /* 0x01C */ f32 fadeVolume;
    /* 0x020 */ f32 fadeVelocity;
    /* 0x024 */ f32 volume;
    /* 0x028 */ f32 muteVolumeScale;
    /* 0x02C */ f32 fadeVolumeScale;
    /* 0x030 */ f32 appliedFadeVolume;
    /* 0x034 */ struct SequenceChannel* channels[16];
    /* 0x074 */ SeqScriptState scriptState;
    /* 0x090 */ u8* shortNoteVelocityTable;
    /* 0x094 */ u8* shortNoteGateTimeTable;
    /* 0x098 */ NotePool notePool;
    /* 0x0D8 */ s32 skipTicks;
    /* 0x0DC */ s32 scriptCounter;
    /* 0x0E0 */ s8 padE0[0x74];
    /* 0x154 */ s8 seqScriptIO[8];
} SequencePlayer; // size = 0x15C

typedef struct {
    /* 0x0 */ s16 delay;
    /* 0x2 */ s16 arg;
} EnvelopePoint; // size = 0x4

typedef struct {
    /* 0x0 */ u8 decayIndex; // index used to obtain adsr decay rate from adsrDecayTable
    /* 0x1 */ u8 sustain;
    /* 0x4 */ EnvelopePoint* envelope;
} AdsrSettings; // size = 0x8

typedef struct {
    /* 0x00 */ u8 mode; // bit 0x80 denotes something; the rest are an index 0-5
    /* 0x04 */ f32 cur;
    /* 0x08 */ f32 speed;
    /* 0x0C */ f32 extent;
} Portamento; // size = 0x10

typedef struct {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end;
    /* 0x08 */ u32 count;
    /* 0x10 */ u64 predictorState[4]; // only exists if count != 0. 8-byte aligned
} AdpcmLoop; // size = 0x30 or 0x10, 0x8 aligned

typedef struct {
    /* 0x00 */ s32 order;
    /* 0x04 */ s32 numPredictors;
    /* 0x08 */ u64 book[1]; // size 8 * order * numPredictors.
} AdpcmBook; // size >= 8, 0x8 aligned

typedef struct {
    /* 0x00 */ u32 codec : 4;       // The state of compression or decompression
    /* 0x00 */ u32 medium : 2;      // Medium where sample is currently stored
    /* 0x00 */ u32 unk_bit26 : 1;
    /* 0x00 */ u32 isRelocated : 1; // Has the sample header been relocated (offsets to pointers)
    /* 0x01 */ u32 size : 24;       // Size of the sample
    /* 0x04 */ u8* sampleAddr;      // Raw sample data. Offset from the start of the sample bank or absolute address to
                                    // either rom or ram
    /* 0x08 */ AdpcmLoop* loop; // Adpcm loop parameters used by the sample. Offset from the start of the sound font / pointer to ram
    /* 0x0C */ AdpcmBook* book; // Adpcm book parameters used by the sample. Offset from the start of the sound font / pointer to ram
} Sample; // size = 0x10

typedef struct {
    /* 0x00 */ Sample* sample;
    /* 0x04 */ f32 tuning;
} TunedSample; // size = 0x8

typedef struct {
    /* 0x00 */ u8 isRelocated;
    /* 0x01 */ u8 normalRangeLo;
    /* 0x02 */ u8 normalRangeHi;
    /* 0x03 */ u8 adsrDecayIndex;
    /* 0x04 */ EnvelopePoint* envelope;
    /* 0x08 */ TunedSample lowPitchTunedSample;
    /* 0x10 */ TunedSample normalPitchTunedSample;
    /* 0x18 */ TunedSample highPitchTunedSample;
} Instrument; // size = 0x20

typedef struct {
    /* 0x00 */ u8 adsrDecayIndex; // index used to obtain adsr decay rate from adsrDecayTable
    /* 0x01 */ u8 pan;
    /* 0x02 */ u8 isRelocated;    // have tunedSample.sample and envelope been relocated (offsets to pointers)
    /* 0x04 */ TunedSample tunedSample;
    /* 0x0C */ EnvelopePoint* envelope;
} Drum; // size = 0x10

typedef struct {
    /* 0x00 */ u8 numInstruments;
    /* 0x01 */ u8 numDrums;
    /* 0x02 */ u8 sampleBankId1;
    /* 0x03 */ u8 sampleBankId2;
    /* 0x04 */ Instrument** instruments;
    /* 0x08 */ Drum** drums;
} SoundFont; // size = 0x10

typedef struct SequenceChannel {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 stopScript : 1;
    /* 0x00 */ u8 muted : 1;
    /* 0x00 */ u8 hasInstrument : 1;
    /* 0x00 */ u8 reverbIndex : 1;
    /* 0x00 */ u8 largeNotes : 1;
    /* 0x00 */ u8 unused : 1;
    union {
        struct {
            /* 0x01 */ u8 freqScale : 1;
            /* 0x01 */ u8 volume : 1;
            /* 0x01 */ u8 pan : 1;
        } s;
        /* 0x01 */ u8 asByte;
    } changes;
    /* 0x02 */ u8 noteAllocPolicy;
    /* 0x03 */ u8 muteBehavior;
    /* 0x04 */ u8 targetReverbVol;
    /* 0x05 */ u8 notePriority;
    /* 0x06 */ u8 notePriority2;
    /* 0x07 */ u8 fontId;
    /* 0x08 */ u8 unkPan;
    /* 0x09 */ u8 unkPan2;
    /* 0x0A */ u8 velocityRandomVariance;
    /* 0x0B */ u8 gateTimeRandomVariance;
    /* 0x0C */ u16 delay;
    /* 0x0E */ s16 instOrWave;
    /* 0x10 */ s16 transposition;
    /* 0x12 */ s8 pad12[0x2];
    /* 0x14 */ f32 volumeScale;
    /* 0x18 */ f32 volume;
    /* 0x1C */ s32 pan;
    /* 0x20 */ f32 appliedVolume;
    /* 0x24 */ f32 freqScale;
    /* 0x28 */ u8 (*dynTable)[][2];
    /* 0x2C */ struct Note* noteUnused;
    /* 0x30 */ struct SequenceLayer* layerUnused;
    /* 0x34 */ Instrument* instrument;
    /* 0x38 */ SequencePlayer* seqPlayer;
    /* 0x3C */ struct SequenceLayer* layers[4];
    /* 0x4C */ SeqScriptState scriptState;
    /* 0x68 */ AdsrSettings adsr;
    /* 0x70 */ NotePool notePool;
    /* 0xB0 */ s8 seqScriptIO[8];
    /* 0xB8 */ u16 unkB8;
} SequenceChannel; // size = 0xBC

typedef struct SequenceLayer {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 muted : 1;
    /* 0x00 */ u8 continuousNotes : 1;
    /* 0x00 */ u8 pad0 : 1;
    /* 0x00 */ u8 notePropertiesNeedInit : 1;
    /* 0x00 */ u8 ignoreDrumPan : 1;
    /* 0x00 */ u8 bit8 : 1;
    /* 0x01 */ u8 instOrWave;
    /* 0x02 */ u8 unk_2;
    /* 0x03 */ u8 gateTime;
    /* 0x04 */ u8 portamentoTargetNote;
    /* 0x05 */ u8 pan;
    /* 0x06 */ u8 notePan;
    /* 0x07 */ s8 pad7[0x1];
    /* 0x08 */ Portamento portamento;
    /* 0x18 */ AdsrSettings adsr;
    /* 0x20 */ u16 portamentoTime;
    /* 0x22 */ s16 transposition;
    /* 0x24 */ f32 freqScale;
    /* 0x28 */ f32 bend;
    /* 0x2C */ f32 velocitySquare;
    /* 0x30 */ f32 velocitySquare2;
    /* 0x34 */ f32 noteVelocity;
    /* 0x38 */ f32 noteFreqScale;
    /* 0x3C */ u16 shortNoteDefaultDelay;
    /* 0x3E */ s16 lastDelay;
    /* 0x40 */ s16 delay;
    /* 0x42 */ s16 gateDelay;
    /* 0x44 */ s16 delay2;
    /* 0x48 */ struct Note *note;
    /* 0x4C */ Instrument* instrument;
    /* 0x50 */ TunedSample* tunedSample;
    /* 0x54 */ SequenceChannel *channel;
    /* 0x58 */ SeqScriptState state;
    /* 0x74 */ AudioListItem listItem;
} SequenceLayer; // size = 0x84

typedef struct {
    /* 0x00 */ union {
        struct A {
            /* 0x00 */ u8 unused : 1;
            /* 0x00 */ u8 hang : 1;
            /* 0x00 */ u8 decay : 1;
            /* 0x00 */ u8 release : 1;
            /* 0x00 */ 
        } s;
        /* 0x00 */ u8 asByte;
    } action;
    /* 0x01 */ u8 state;
    /* 0x02 */ s16 envIndex;
    /* 0x04 */ s16 delay;
    /* 0x06 */ s8 pad6[0x2];
    /* 0x08 */ f32 sustain;
    /* 0x0C */ f32 velocity;
    /* 0x10 */ f32 fadeOutVel;
    /* 0x14 */ f32 current;
    /* 0x18 */ f32 target;
    /* 0x1C */ s8 pad1C[0x4];
    /* 0x20 */ EnvelopePoint* envelope;
} AdsrState; // size = 0x24

typedef struct {
    /* 0x00 */ u8 reverb;
    /* 0x01 */ u8 pan;
    /* 0x02 */ s8 pad2[0x2];
    /* 0x04 */ f32 freqScale;
    /* 0x08 */ f32 velocity;
} NoteAttributes; // size = 0xC

typedef struct {
    /* 0x00 */ u8 priority;
    /* 0x01 */ u8 waveId;
    /* 0x02 */ s8 pad2[0x1];
    /* 0x03 */ u8 fontId;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ s8 pad5[0x1];
    /* 0x06 */ s16 adsrVolScaleUnused;
    /* 0x08 */ f32 portamentoFreqScale;
    /* 0x0C */ s8 padC[0x4];
    /* 0x10 */ struct SequenceLayer* prevParentLayer;
    /* 0x14 */ struct SequenceLayer* parentLayer;
    /* 0x18 */ struct SequenceLayer* wantedParentLayer;
    /* 0x1C */ NoteAttributes attributes;
    /* 0x28 */ AdsrState adsr;
    /* 0x4C */ Portamento portamento;
    /* 0x5C */ s8 pad5C[0x4];
} NotePlaybackState; // size = 0x60

typedef struct {
    struct {
        /* 0x00 */ volatile u8 enabled : 1;
        /* 0x00 */ u32 needsInit : 1;
        /* 0x00 */ u8 finished : 1;
        /* 0x00 */ u8 unused : 1;
        /* 0x00 */ s8 pad0 : 2;
        /* 0x00 */ u8 reverbIndex : 1;
        /* 0x01 */ s8 pad1 : 5;
        /* 0x01 */ u8 isSyntheticWave : 2;
        /* 0x01 */ u8 hasTwoParts : 1;
        /* 0x02 */ u8 reverb;
        /* 0x03 */ s8 pad3[0x1];
    } bitField;
    /* 0x04 */ u16 panVolLeft;
    /* 0x06 */ u16 panVolRight;
    /* 0x08 */ u16 resampleRate;
    /* 0x0C */ TunedSample* tunedSample;
} NoteSubEu; // size = 0x10

typedef struct {
    /* 0x000 */ s16 adpcmdecState[16];
    /* 0x020 */ s16 finalResampleState[16];
    /* 0x040 */ char pad40[0x40];
} NoteSynthesisBuffers; // size = 0x80

typedef struct {
    /* 0x00 */ u8 restart;
    /* 0x01 */ u8 sampleDmaIndex;
    /* 0x02 */ u8 prevHaasEffectLeftDelaySize;
    /* 0x03 */ u8 prevHaasEffectRightDelaySize;
    /* 0x04 */ u8 reverbVol;
    /* 0x05 */ u8 numParts;
    /* 0x06 */ u16 samplePosFrac;
    /* 0x08 */ s32 samplePosInt;
    /* 0x0C */ NoteSynthesisBuffers* synthesisBuffers;
    /* 0x10 */ s16 curVolLeft;
    /* 0x12 */ s16 curVolRight;
    /* 0x14 */ char unk_14[0xC];
} NoteSynthesisState; // size = 0x20

typedef struct Note {
    /* 0x00 */ AudioListItem listItem;
    /* 0x10 */ NoteSynthesisState synthesisState;
    /* 0x30 */ NotePlaybackState playbackState;
    /* 0x90 */ NoteSubEu noteSubEu;
} Note; // size = 0xA0

typedef struct {
    /* 0x00 */ s16 numSamplesAfterDownsampling;
    /* 0x02 */ s16 chunkLen;
    /* 0x04 */ s16* toDownsampleLeft;
    /* 0x08 */ s16* toDownsampleRight;
    /* 0x0C */ s32 startPos;
    /* 0x10 */ s16 lengthA;
    /* 0x12 */ s16 lengthB;
} ReverbRingBufferItem; // size = 0x14

typedef struct {
    /* 0x000 */ u8 resampleFlags;
    /* 0x001 */ u8 useReverb;
    /* 0x002 */ u8 framesToIgnore;
    /* 0x003 */ u8 curFrame;
    /* 0x004 */ u8 downsampleRate;
    /* 0x005 */ s8 unk_05;
    /* 0x006 */ u16 windowSize;
    /* 0x008 */ s16 unk_08;
    /* 0x00A */ u16 volume;
    /* 0x00C */ u16 decayRatio; // determines how much reverb persists
    /* 0x00E */ u16 unk_0E;
    /* 0x010 */ s16 leakRtL;
    /* 0x012 */ s16 leakLtR;
    /* 0x014 */ s32 nextRingBufPos;
    /* 0x018 */ s32 unk_20;
    /* 0x01C */ s32 bufSizePerChan;
    /* 0x020 */ s16* leftRingBuf;
    /* 0x024 */ s16* rightRingBuf;
    /* 0x028 */ s8 pad28[0x10];
    /* 0x038 */ ReverbRingBufferItem items[2][4];
    /* 0x0D8 */ s8 padD8[0x10];
    /* 0x0E8 */ TunedSample tunedSample;
    /* 0x0F0 */ Sample sample;
    /* 0x100 */ AdpcmLoop loop;
} SynthesisReverb; // size = 0x130

typedef struct {
    /* 0x00 */ u8* ramAddr;
    /* 0x04 */ uintptr_t devAddr;
    /* 0x08 */ u16 sizeUnused;
    /* 0x0A */ u16 size;
    /* 0x0C */ u8 unused;
    /* 0x0D */ u8 reuseIndex; // position in sSampleDmaReuseQueue1/2, if ttl == 0
    /* 0x0E */ u8 ttl;        // duration after which the DMA can be discarded
} SampleDma; // size = 0x10

typedef struct {
    /* 0x00 */ uintptr_t romAddr;
    /* 0x04 */ size_t size;
    /* 0x08 */ s8 medium;
    /* 0x09 */ s8 cachePolicy;
    /* 0x0A */ s16 shortData1;
    /* 0x0C */ s16 shortData2;
    /* 0x0E */ s16 shortData3;
} AudioTableEntry; // size = 0x10

typedef struct {
    /* 0x00 */ s16 numEntries;
    /* 0x02 */ s16 unkMediumParam;
    /* 0x04 */ uintptr_t romAddr;
    /* 0x08 */ char pad[0x8];
    /* 0x10 */ AudioTableEntry entries[1]; // (dynamic size)
} AudioTable;

typedef struct {
    /* 0x00 */ OSTask task;
    /* 0x40 */ OSMesgQueue* msgQueue;
    /* 0x44 */ OSMesg msg;
    /* 0x48 */ char unk_48[0x8];
} AudioTask; // size = 0x50

typedef struct {
    /* 0x00 */ u8 medium;
    /* 0x01 */ u8 seqOrFontId;
    /* 0x02 */ u8 instId;
    /* 0x04 */ uintptr_t curDevAddr;
    /* 0x08 */ u8* curRamAddr;
    /* 0x0C */ u8* ramAddr;
    /* 0x10 */ s32 state;
    /* 0x14 */ s32 bytesRemaining;
    /* 0x18 */ s8* status; // write-only
    /* 0x1C */ Sample sample;
    /* 0x2C */ OSMesgQueue msgQueue;
    /* 0x44 */ OSMesg msg;
    /* 0x48 */ OSIoMesg ioMesg;
} AudioSlowLoad; // size = 0x60

typedef struct {
    /* 0x00 */ s32 slowLoadPos;
    /* 0x04 */ AudioSlowLoad slowLoad[2];
} AudioSlowLoadBuffer; // size = 0xC4

typedef struct {
    /* 0x00 */ u32 endAndMediumKey;
    /* 0x04 */ Sample* sample;
    /* 0x08 */ u8* ramAddr;
    /* 0x0C */ u32 encodedInfo;
    /* 0x10 */ s32 isFree;
} AudioPreloadReq; // size = 0x14

typedef s32 (*DmaHandler)(OSPiHandle* handle, OSIoMesg* mb, s32 direction);

#define NO_LAYER ((SequenceLayer*) (-1))
#define IS_SEQUENCE_CHANNEL_VALID(ptr) ((u32) (ptr) != (u32) &gSeqChannelNone)

typedef enum {
    /* 0 */ LOAD_STATUS_NOT_LOADED, // the entry data is not loaded
    /* 1 */ LOAD_STATUS_IN_PROGRESS, // the entry data is being loaded asynchronously
    /* 2 */ LOAD_STATUS_COMPLETE, // the entry data is loaded, it may be discarded if not stored persistently, and either no longer in use, or the memory is needed for something else
    /* 3 */ LOAD_STATUS_DISCARDABLE, // the entry data is loaded, and can be discarded
    /* 4 */ LOAD_STATUS_MAYBE_DISCARDABLE, // only for font table entries, like COMPLETE but prefer discarding it over a COMPLETE entry
    /* 5 */ LOAD_STATUS_PERMANENTLY_LOADED // the entry data is loaded in the permanent pool, it won't be discarded
} AudioLoadStatus;

typedef enum {
    /* 0 */ SOUNDMODE_STEREO,
    /* 1 */ SOUNDMODE_HEADSET,
    /* 2 */ SOUNDMODE_SURROUND,
    /* 3 */ SOUNDMODE_MONO
} SoundMode;

typedef enum {
    /* 0 */ ADSR_STATE_DISABLED,
    /* 1 */ ADSR_STATE_INITIAL,
    /* 2 */ ADSR_STATE_START_LOOP,
    /* 3 */ ADSR_STATE_LOOP,
    /* 4 */ ADSR_STATE_FADE,
    /* 5 */ ADSR_STATE_HANG,
    /* 6 */ ADSR_STATE_DECAY,
    /* 7 */ ADSR_STATE_RELEASE,
    /* 8 */ ADSR_STATE_SUSTAIN
} AdsrStatus;

typedef enum {
    /* 0 */ MEDIUM_RAM,
    /* 1 */ MEDIUM_UNK,
    /* 2 */ MEDIUM_CART,
    /* 3 */ MEDIUM_DISK_DRIVE
} SampleMedium;

typedef enum {
    /* 0 */ CODEC_ADPCM,       // 16 2-byte samples (32 bytes) compressed into 4-bit samples (8 bytes) + 1 header byte
    /* 1 */ CODEC_S8,          // 16 2-byte samples (32 bytes) compressed into 8-bit samples (16 bytes)
    /* 2 */ CODEC_S16_INMEMORY,
    /* 3 */ CODEC_SMALL_ADPCM, // 16 2-byte samples (32 bytes) compressed into 2-bit samples (4 bytes) + 1 header byte
    /* 4 */ CODEC_REVERB,
    /* 5 */ CODEC_S16
} SampleCodec;

typedef enum {
    /*  0 */ SAMPLES_SFX,
    /*  1 */ SAMPLES_MAP,
    /*  2 */ SAMPLES_VOICE,
    /*  3 */ SAMPLES_INST,
    /*  4 */ SAMPLES_MAX,
    /* -1 */ SAMPLES_NONE = 255,
} SampleBank;

typedef enum {
    /* 0 */ SEQUENCE_TABLE,
    /* 1 */ FONT_TABLE,
    /* 2 */ SAMPLE_TABLE
} AudioTableType;

typedef enum {
    /* 0 */ CACHE_TEMPORARY,
    /* 1 */ CACHE_PERSISTENT,
    /* 2 */ CACHE_EITHER,
    /* 3 */ CACHE_PERMANENT
} AudioCacheType;

typedef enum {
    /* 0 */ CACHEPOLICY_0,
    /* 1 */ CACHEPOLICY_1,
    /* 2 */ CACHEPOLICY_2,
    /* 3 */ CACHEPOLICY_3,
    /* 4 */ CACHEPOLICY_4,
} AudioCachePolicy;

typedef enum {
    /* 0 */ SLOW_LOAD_WAITING,
    /* 1 */ SLOW_LOAD_START,
    /* 2 */ SLOW_LOAD_LOADING,
    /* 3 */ SLOW_LOAD_DONE
} SlowLoadState;

typedef enum {
    /* 0 */ SLOW_LOAD_STATUS_0,
    /* 1 */ SLOW_LOAD_STATUS_1,
    /* 2 */ SLOW_LOAD_STATUS_2,
    /* 3 */ SLOW_LOAD_STATUS_3
} SlowLoadStatus;

#define ADSR_DISABLE 0
#define ADSR_HANG -1
#define ADSR_GOTO -2
#define ADSR_RESTART -3

#define SEQ_IO_VAL_NONE -1

#define SEQTICKS_PER_BEAT 48

#define AUDIOLOAD_SYNC 0
#define AUDIOLOAD_ASYNC 1

#define AUDIO_RELOCATED_ADDRESS_START K0BASE

#define REFRESH_RATE_PAL 50
#define REFRESH_RATE_MPAL 60
#define REFRESH_RATE_NTSC 60

// Small deviation parameters used in estimating the max tempo
// It is unclear why these vary by region, and aren't all just 1
#define REFRESH_RATE_DEVIATION_PAL 1.001521f
#define REFRESH_RATE_DEVIATION_MPAL 0.99276f
#define REFRESH_RATE_DEVIATION_NTSC 1.00278f

#define SAMPLE_SIZE sizeof(s16)

// Samples are processed in groups of 16 called a "frame"
#define SAMPLES_PER_FRAME ADPCMFSIZE

#define AIBUF_LEN (88 * SAMPLES_PER_FRAME) // number of samples
#define AIBUF_SIZE (AIBUF_LEN * SAMPLE_SIZE) // number of bytes

#define DMEM_1CH_SIZE (13 * SAMPLES_PER_FRAME * SAMPLE_SIZE)
#define DMEM_2CH_SIZE (2 * DMEM_1CH_SIZE)

#define DMEM_TEMP 0x3C0
#define DMEM_LEFT_CH 0x940
#define DMEM_RIGHT_CH 0xAE0
#define DMEM_WET_LEFT_CH 0xC80
#define DMEM_WET_RIGHT_CH 0xE20

#define DMEM_UNCOMPRESSED_NOTE 0x580
#define DMEM_COMPRESSED_ADPCM_DATA 0x940

#define AUDIO_MK_CMD(b0,b1,b2,b3) ((((b0) & 0xFF) << 0x18) | (((b1) & 0xFF) << 0x10) | (((b2) & 0xFF) << 0x8) | (((b3) & 0xFF) << 0))

extern f32 gBendPitchOneOctaveFrequencies[];
extern f32 gBendPitchTwoSemitonesFrequencies[];
extern f32 gDefaultPanVolume[128];
extern s32 gAudioHeapSize;
extern EnvelopePoint gDefaultEnvelope[];
extern AudioSpec gAudioSpecs[];
extern s16 gSeqTicksPerBeat;
extern NoteSubEu gZeroNoteSub;
extern size_t gInitPoolSize;
extern size_t gPermanentPoolSize;
extern s32 gAudioContextInitialized;
extern AudioSlowLoadBuffer gSlowLoads;


extern u8 gSoundFontTableData[];
extern u8 gSequenceFontTableData[];
extern u8 gSequenceTableData[];
extern u8 gSampleBankTableData[];

extern SynthesisReverb gSynthReverbs[1];
extern u16 D_80025D50;
extern s8 gUseReverb;
extern s8 gNumSynthReverbs;
extern u16 D_80025D54;
extern void* gCurLoadedBook;
extern NoteSubEu* gNoteSubsEu;
extern AudioAllocPool gSessionPool;
extern AudioAllocPool gExternalPool;
extern AudioAllocPool gInitPool;
extern AudioAllocPool gMiscPool;
extern AudioAllocPool gCachePool;
extern AudioAllocPool gPersistentCommonPool;
extern AudioAllocPool gTemporaryCommonPool;
extern AudioCache gSeqCache;
extern AudioCache gFontCache;
extern AudioCache gSampleBankCache;
extern AudioPermanentCache gPermanentCache;
extern AudioSampleCache gPersistentSampleCache;
extern AudioSampleCache gTemporarySampleCache;
extern AudioSessionPoolSplit gSessionPoolSplit;
extern AudioCachePoolSplit gCachePoolSplit;
extern AudioCommonPoolSplit gPersistentCommonPoolSplit;
extern AudioCommonPoolSplit gTemporaryCommonPoolSplit;
extern u8 gSampleFontLoadStatus[0x30];
extern u8 gFontLoadStatus[0x30];
extern u8 gSeqLoadStatus[0x30];
extern volatile u8 gResetStatus;
extern u8 gSpecId;
extern s32 gResetFadeoutFramesLeft;
extern f32* gAdsrDecayTable;
extern Note* gNotes;
extern SequencePlayer gSeqPlayers[3];
extern SequenceLayer gSeqLayers[64];
extern SequenceChannel gSeqChannelNone;
extern AudioListItem gLayerFreeList;
extern NotePool gNoteFreeLists;
extern Sample* gUsedSamples[128];
extern AudioPreloadReq gPreloadSampleStack[128];
extern s32 gNumUsedSamples;
extern s32 gPreloadSampleStackTop;
extern AudioAsyncLoad gAsyncLoads[16];
extern OSMesgQueue gExternalLoadQueue;
extern OSMesg gExternalLoadMsgBuf[8];
extern OSMesgQueue gPreloadSampleQueue;
extern OSMesg gPreloadSampleMsgBuf[8];
extern OSMesgQueue gCurAudioFrameDmaQueue;
extern OSMesg gCurAudioFrameDmaMsgBuf[64];
extern OSIoMesg gCurAudioFrameDmaIoMsgBuf[64];
extern OSMesgQueue gSyncDmaQueue;
extern OSMesg gSyncDmaMsg;
extern OSIoMesg gSyncDmaIoMsg;
extern SampleDma* gSampleDmas;
extern u32 gSampleDmaCount;
extern u32 gSampleDmaListSize1;
extern u32 gSampleDmaListSize2;
extern u8 gSampleDmaReuseQueue1[0x100];
extern u8 gSampleDmaReuseQueue2[0x100];
extern u8 gSampleDmaReuseQueue1RdPos;
extern u8 gSampleDmaReuseQueue2RdPos;
extern u8 gSampleDmaReuseQueue1WrPos;
extern u8 gSampleDmaReuseQueue2WrPos;
extern AudioTable* gSequenceTable;
extern AudioTable* gSoundFontTable;
extern AudioTable* gSampleBankTable;
extern u8* gSeqFontTable;
extern u16 gNumSequences;
extern SoundFont* gSoundFontList;
extern AudioBufferParameters gAudioBufferParams;
extern size_t gSampleDmaBufSize;
extern s32 gMaxAudioCmds;
extern s32 gNumNotes;
extern s16 gMaxTempo;
extern s8 gSoundMode;
extern volatile s32 gTotalTaskCount;
extern s32 gCurAudioFrameDmaCount;
extern s32 gRspTaskIndex;
extern s32 gCurAiBufIndex;
extern Acmd* gAbiCmdBuffs[2];
extern Acmd* gCurAbiCmdBuffer;
extern AudioTask* gCurTask;
extern AudioTask gRspTask[2];
extern f32 gMaxTempoTvTypeFactors;
extern s32 gRefreshRate;
extern s16* gAiBuffers[3];
extern s16 gAiBufLengths[3];
extern u32 gAudioRandom;
extern volatile u32 gResetTimer;
extern AudioCmd gThreadCmdBuffer[256];
extern u16 gThreadCmdChannelMask[3];
extern u8 gThreadCmdWritePos;
extern u8 gThreadCmdReadPos;
extern u8 gThreadCmdQueueFinished;
extern OSMesg gAudioTaskStartMsg[1];
extern OSMesgQueue gAudioTaskStartQueue;
extern OSMesgQueue* gAudioTaskStartQueuePtr;
extern OSMesg gThreadCmdProcMsg[4];
extern OSMesgQueue gThreadCmdProcQueue;
extern OSMesgQueue* gThreadCmdProcQueuePtr;
extern OSMesg gAudioResetMsg[1];
extern OSMesgQueue gAudioResetQueue;
extern OSMesgQueue* gAudioResetQueuePtr;

extern u8 gAudioHeap[0x3B000];

void func_800AA8E4(Note* note);
void func_800AA940(void);
TunedSample* func_800AACF0(Instrument* instrument, s32 semitone);
Instrument* func_800AAD2C(s32 fontId, s32 instId);
Drum* func_800AAD58(s32 fontId, s32 drumId);
void func_800AAF5C(SequenceLayer* layer);
void func_800AAFAC(NotePool* pool);
void func_800AAFFC(void);
void func_800AB204(NotePool* pool, s32 arg1);
void func_800AB380(Note* note);
Note* func_800AB710(SequenceLayer* layer);
void func_800AB888(void);

void func_800ABCB4(Note* note);
void func_800AE624(s32 arg0);
void func_800AE7F8(s32 seqPlayerIndex);
void func_800AE8F0(void);
void* func_800AEB28(uintptr_t devAddr, size_t size, s32 arg2, u8* dmaIndexRef, s32 medium);
void func_800AEEA0(s32 numNotes);

void func_800AC744(SequencePlayer* seqPlayer);
void func_800AC7F0(AudioListItem* list, AudioListItem* item);
void func_800AE6B0(SequencePlayer* seqPlayer);
void func_800AE700(s32 seqPlayerIndex);
void func_800AEA10(void);

bool func_800AF288(s32 fontId);
bool func_800AF2C4(s32 seqId);
void func_800AF33C(s32 fontId, s32 loadStatus);
void func_800AF4D8(s32 seqId, s32 flags);
s32 func_800AF624(s32 fontId, s32 instId, s32 drumId);
void func_800AF6F4(s32 sampleBankId, s32 nChunks, s32 retData, OSMesgQueue* retQueue);
void func_800AF758(s32 seqId, s32 nChunks, s32 retData, OSMesgQueue* retQueue);
u8* func_800AF820(s32 seqId, u32* outNumFonts);
void func_800AF888(s32 seqId);
s32 func_800AF9EC(s32 seqPlayerIndex, s32 seqId, s32 arg2);
s32 func_800AFA48(s32 seqPlayerIndex, s32 seqId, s32 skipTicks);
void func_800B0754(s32 resetStatus);

void func_800B079C(void* heap, size_t heapSize);
s32 func_800B0D30(s32 fontId, u8 instId, s8* status);
void func_800B2324(void);
void func_800B2AE4(AudioAllocPool* pool, void* ramAddr, size_t size);
void* func_800B3534(s32 tableType, s32 cache, s32 id);
bool func_800B38AC(void);
void* func_800B4350(size_t size, s32 fontId, void* sampleAddr, s8 medium);
Acmd* func_800B4F4C(Acmd* aList, s32* cmdCount, s16* aiBufStart, s32 aiBufLen);

AudioTask* func_800B5FB0(void);
void func_800B68EC(u32 opArgs, f32 data);
void func_800B6910(u32 opArgs, u32 data);
void func_800B6934(u32 opArgs, s8 data);
void func_800B6964(u32 opArgs, u16 data);
void func_800B6994(void);
bool func_800B6E14(void);
s32 func_800B6EC0(s32 specId);
void func_800B6F58(void);

AudioTask* func_800BB49C(void);

#endif
