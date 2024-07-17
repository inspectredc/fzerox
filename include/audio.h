#ifndef AUDIO_H
#define AUDIO_H

#include "PR/ultratypes.h"

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
    /* 0x00 */ s16 count;
    /* 0x02 */ u16 samplingFrequency;
    /* 0x04 */ u16 aiSamplingFrequency;
    /* 0x06 */ s16 samplesPerFrameTarget;
    /* 0x08 */ s16 maxAiBufferLength;
    /* 0x0A */ s16 minAiBufferLength;
    /* 0x0C */ s16 ticksPerUpdate;
    /* 0x0E */ s16 samplesPerTick;
    /* 0x10 */ s16 samplesPerTickMax;
    /* 0x12 */ s16 samplesPerTickMin;
    /* 0x14 */ f32 resampleRate;
    /* 0x18 */ f32 ticksPerUpdateInv;
    /* 0x1C */ f32 ticksPerUpdateInvScaled;
} AudioBufferParameters; // size = 0x20

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
    s8 pad[0x1];
} SeqScriptState;

typedef struct {
    s8 pad[0x1];
} SequencePlayer;

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

typedef struct SequenceChannel {
    /* 0x00 */ u8 pad0 : 5;
    /* 0x00 */ u8 reverbIndex : 1;
    /* 0x00 */ u8 pad0_2 : 2;
    /* 0x01 */ s8 pad1[0x1];
    /* 0x02 */ u8 noteAllocPolicy;
    /* 0x03 */ u8 muteBehavior;
    /* 0x04 */ u8 targetReverbVol;
    /* 0x05 */ u8 notePriority;
    /* 0x06 */ u8 notePriority2;
    /* 0x07 */ u8 fontId;
    /* 0x08 */ s8 pad8[0x6];
    /* 0x0E */ s16 instOrWave;
    /* 0x10 */ s8 pad1E[0x1C];
    /* 0x2C */ struct Note* noteUnused;
    /* 0x30 */ struct SequenceLayer* layerUnused;
    /* 0x34 */ s8 pad34[0x4];
    /* 0x38 */ SequencePlayer* seqPlayer;
    /* 0x3C */ s8 pad3C[0x2C];
    /* 0x68 */ AdsrSettings adsr;
    /* 0x70 */ NotePool notePool;
} SequenceChannel;

typedef struct SequenceLayer {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 pad0 : 4;
    /* 0x00 */ u8 bit5 : 1;
    /* 0x00 */ u8 pad0_2 : 1;
    /* 0x00 */ u8 bit8 : 1;
    /* 0x01 */ u8 instOrWave;
    /* 0x02 */ s8 unk_2;
    /* 0x03 */ s8 pad3[0x3];
    /* 0x06 */ u8 notePan;
    /* 0x07 */ s8 pad7[0x11];
    /* 0x18 */ AdsrSettings adsr;
    /* 0x20 */ s8 pad20[0x14];
    /* 0x34 */ f32 noteVelocity;
    /* 0x38 */ f32 noteFreqMod;
    /* 0x3C */ s8 pad3C[0xC];
    /* 0x48 */ struct Note *note;
    /* 0x4C */ s8 pad4C[0x4];
    /* 0x50 */ TunedSample* tunedSample;
    /* 0x54 */ SequenceChannel *channel;
} SequenceLayer;

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
    /* 0x02 */ s8 pad2[0x6];
    /* 0x08 */ f32 sustain;
    /* 0x0C */ s8 padC[0x4];
    /* 0x10 */ f32 fadeOutVel;
    /* 0x14 */ f32 current;
    /* 0x18 */ s8 pad18[0xC];
} AdsrState; // size = 0x24

typedef struct {
    /* 0x00 */ u8 reverb;
    /* 0x01 */ u8 pan;
    /* 0x02 */ s8 pad2[0x2];
    /* 0x04 */ f32 freqMod;
    /* 0x08 */ f32 velocity;
} NoteAttributes; // size = 0xC

typedef struct {
    /* 0x00 */ u8 priority;
    /* 0x01 */ u8 waveId;
    /* 0x02 */ s8 pad2[0x1];
    /* 0x03 */ u8 fontId;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ s8 pad5[0x1];
    /* 0x06 */ s16 adsrVolModUnused;
    /* 0x08 */ f32 portamentoFreqMod;
    /* 0x0C */ f32 vibratoFreqMod;
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
    /* 0x000 */ char pad[0x80];
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
} Note;

#define NO_LAYER ((SequenceLayer*) (-1))

typedef enum {
    /* 0 */ SOUNDMODE_STEREO,
    /* 1 */ SOUNDMODE_HEADSET,
    /* 2 */ SOUNDMODE_SURROUND,
    /* 3 */ SOUNDMODE_MONO
} SoundMode;


#endif
