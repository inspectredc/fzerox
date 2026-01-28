#ifndef AUDIO_INTERNAL_H
#define AUDIO_INTERNAL_H

#include "libultra/ultra64.h"
#include "libc/stdint.h"
#include "libc/stdlib.h"
#include "libc/stdbool.h"
#include "PR/leo.h"

struct Note;
struct NotePool;
struct SequenceChannel;
struct SequenceLayer;

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

// Pitch sliding by up to one octave in the positive direction. Negative
// direction is "supported" by setting extent to be negative. The code
// exterpolates exponentially in the wrong direction in that case, but that
// doesn't prevent seqplayer from doing it, AFAICT.
typedef struct Portamento {
    /* 0x00 */ u8 mode; // bit 0x80 denotes something; the rest are an index 0-5
    /* 0x02 */ u16 cur;
    /* 0x04 */ u16 speed;
    /* 0x08 */ f32 extent;
} Portamento; // size = 0xC

typedef struct EnvelopePoint {
    /* 0x0 */ s16 delay;
    /* 0x2 */ s16 arg;
} EnvelopePoint; // size = 0x4

typedef struct AdpcmLoopHeader {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end; // s16 sample position where the loop ends
    /* 0x08 */ u32 count; // The number of times the loop is played before the sound completes. Setting count to -1 indicates that the loop should play indefinitely.
    /* 0x0C */ char unk_0C[0x4];
} AdpcmLoopHeader; // size = 0x10

typedef struct AdpcmLoop {
    /* 0x00 */ AdpcmLoopHeader header;
    /* 0x10 */ s16 predictorState[16]; // only exists if count != 0. 8-byte aligned
} AdpcmLoop; // size = 0x30 (or 0x10)

typedef struct AdpcmBookHeader {
    /* 0x00 */ s32 order;
    /* 0x04 */ s32 numPredictors;
} AdpcmBookHeader; // size = 0x8

/**
 * The procedure used to design the codeBook is based on an adaptive clustering algorithm.
 * The size of the codeBook is (8 * order * numPredictors) and is 8-byte aligned
 */
typedef struct AdpcmBook {
    /* 0x00 */ AdpcmBookHeader header;
    /* 0x08 */ s16 book[]; // size 8 * order * numPredictors. 8-byte aligned
} AdpcmBook; // size >= 0x8

typedef struct Sample {
    /* 0x00 */ u32 unk0 : 1;
    /* 0x00 */ u32 codec : 3; // The state of compression or decompression
    /* 0x00 */ u32 medium : 2; // Medium where sample is currently stored
    /* 0x00 */ u32 unk_bit26 : 1;
    /* 0x00 */ u32 isRelocated : 1; // Has the sample header been relocated (offsets to pointers)
    /* 0x01 */ u32 size : 24; // Size of the sample
    /* 0x04 */ u8* sampleAddr; // Raw sample data. Offset from the start of the sample bank or absolute address to either rom or ram
    /* 0x08 */ AdpcmLoop* loop; // Adpcm loop parameters used by the sample. Offset from the start of the sound font / pointer to ram
    /* 0x0C */ AdpcmBook* book; // Adpcm book parameters used by the sample. Offset from the start of the sound font / pointer to ram
} Sample; // size = 0x10

typedef struct TunedSample {
    /* 0x00 */ Sample* sample;
    /* 0x04 */ f32 tuning; // frequency scale factor
} TunedSample; // size = 0x8

typedef struct Instrument {
    /* 0x00 */ u8 isRelocated; // have the envelope and all samples been relocated (offsets to pointers)
    /* 0x01 */ u8 normalRangeLo;
    /* 0x02 */ u8 normalRangeHi;
    /* 0x03 */ u8 adsrDecayIndex; // index used to obtain adsr decay rate from adsrDecayTable
    /* 0x04 */ EnvelopePoint* envelope;
    /* 0x08 */ TunedSample lowPitchTunedSample;
    /* 0x10 */ TunedSample normalPitchTunedSample;
    /* 0x18 */ TunedSample highPitchTunedSample;
} Instrument; // size = 0x20

typedef struct Drum {
    /* 0x00 */ u8 adsrDecayIndex; // index used to obtain adsr decay rate from adsrDecayTable
    /* 0x01 */ u8 pan;
    /* 0x02 */ u8 isRelocated; // have tunedSample.sample and envelope been relocated (offsets to pointers)
    /* 0x04 */ TunedSample tunedSample;
    /* 0x0C */ EnvelopePoint* envelope;
} Drum; // size = 0x10

typedef struct SoundEffect {
    /* 0x00 */ TunedSample tunedSample;
} SoundEffect; // size = 0x08

/**
 * Stores parsed information from soundfont data
 */
typedef struct SoundFont {
    /* 0x00 */ u8 numInstruments;
    /* 0x01 */ u8 numDrums;
    /* 0x02 */ u8 sampleBankId1;
    /* 0x03 */ u8 sampleBankId2;
    /* 0x04 */ u16 numSfx;
    /* 0x08 */ Instrument** instruments;
    /* 0x0C */ Drum** drums;
    /* 0x10 */ SoundEffect* soundEffects;
} SoundFont; // size = 0x14

typedef struct ReverbRingBufferItem {
    /* 0x00 */ s16 numSamplesAfterDownsampling; // never read
    /* 0x02 */ s16 chunkLen; // never read
    /* 0x04 */ s16* toDownsampleLeft;
    /* 0x08 */ s16* toDownsampleRight; // data pointed to by left and right are adjacent in memory
    /* 0x0C */ s32 startPos; // start pos in ring buffer
    /* 0x10 */ s16 lengthA; // first length in ring buffer (from startPos, at most until end)
    /* 0x12 */ s16 lengthB; // second length in ring buffer (from pos 0)
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u16 unk_18;
} ReverbRingBufferItem; // size = 0x1C

typedef struct SynthesisReverb {
    /* 0x000 */ u8 resampleFlags;
    /* 0x001 */ u8 useReverb;
    /* 0x002 */ u8 framesToIgnore;
    /* 0x003 */ u8 curFrame;
    /* 0x004 */ u8 downsampleRate;
    /* 0x005 */ s8 unk_05;
    /* 0x006 */ u16 windowSize;
    /* 0x008 */ s16 unk_08;
    /* 0x00A */ s16 volume;
    /* 0x00C */ u16 decayRatio; // determines how much reverb persists
    /* 0x00E */ u16 unk_0E;
    /* 0x010 */ s16 leakRtl;
    /* 0x012 */ s16 leakLtr;
    /* 0x014 */ u16 unk_14;
    /* 0x016 */ s16 unk_16;
    /* 0x018 */ u8 unk_18;
    /* 0x019 */ u8 unk_19;
    /* 0x01A */ u8 unk_1A;
    /* 0x01B */ u8 unk_1B;
    /* 0x01C */ s32 nextRingBufPos;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 bufSizePerChan;
    /* 0x028 */ s16* leftRingBuf;
    /* 0x02C */ s16* rightRingBuf;
    /* 0x030 */ void* unk_30;
    /* 0x034 */ void* unk_34;
    /* 0x038 */ void* unk_38;
    /* 0x03C */ void* unk_3C;
    /* 0x040 */ ReverbRingBufferItem items[2][5];
    /* 0x158 */ ReverbRingBufferItem items2[2][5];
    /* 0x270 */ s16* filterLeft;
    /* 0x274 */ s16* filterRight;
    /* 0x278 */ s16* filterLeftState;
    /* 0x27C */ s16* filterRightState;
    /* 0x280 */ TunedSample tunedSample;
    /* 0x288 */ Sample sample;
    /* 0x298 */ AdpcmLoop loop;
} SynthesisReverb; // size = 0x2C8

typedef struct SeqScriptState {
    /* 0x00 */ u8* pc; // program counter
    /* 0x04 */ u8* stack[4];
    /* 0x14 */ u8 remLoopIters[4]; // remaining loop iterations
    /* 0x18 */ u8 depth;
    /* 0x19 */ s8 value;
} SeqScriptState; // size = 0x1C

// Also known as a Group, according to debug strings.
typedef struct SequencePlayer {
    /* 0x000 */ u8 enabled : 1;
    /* 0x000 */ u8 finished : 1;
    /* 0x000 */ u8 muted : 1;
    /* 0x000 */ u8 seqDmaInProgress : 1;
    /* 0x000 */ u8 fontDmaInProgress : 1;
    /* 0x000 */ u8 recalculateVolume : 1;
    /* 0x000 */ u8 stopScript : 1;
    /* 0x000 */ u8 applyBend : 1;
    /* 0x001 */ u8 state;
    /* 0x002 */ u8 noteAllocPolicy;
    /* 0x003 */ u8 muteBehavior;
    /* 0x004 */ u8 seqId;
    /* 0x005 */ u8 defaultFont;
    /* 0x006 */ u8 unk_06[1];
    /* 0x007 */ s8 playerIdx;
    /* 0x008 */ u16 tempo; // seqTicks per minute
    /* 0x00A */ u16 tempoAcc; // tempo accumulation, used in a discretized algorithm to apply tempo.
    /* 0x00C */ u16 tempoChange; // Used to adjust the tempo without altering the base tempo.
    /* 0x00E */ s16 transposition;
    /* 0x010 */ u16 delay;
    /* 0x012 */ u16 fadeTimer; // in ticks
    /* 0x014 */ u16 fadeTimerUnkEu;
    /* 0x018 */ u8* seqData;
    /* 0x01C */ f32 fadeVolume;
    /* 0x020 */ f32 fadeVelocity;
    /* 0x024 */ f32 volume;
    /* 0x028 */ f32 muteVolumeScale;
    /* 0x02C */ f32 fadeVolumeScale;
    /* 0x030 */ f32 appliedFadeVolume;
    /* 0x034 */ f32 bend;
    /* 0x038 */ struct SequenceChannel* channels[16];
    /* 0x078 */ SeqScriptState scriptState;
    /* 0x094 */ u8* shortNoteVelocityTable;
    /* 0x098 */ u8* shortNoteGateTimeTable;
    /* 0x09C */ NotePool notePool;
    /* 0x0DC */ s32 skipTicks;
    /* 0x0E0 */ u32 scriptCounter;
    /* 0x0E4 */ char unk_E4[0x74]; // unused struct members for sequence/sound font dma management, according to sm64 decomp
    /* 0x158 */ s8 seqScriptIO[8];
} SequencePlayer; // size = 0x160

typedef struct AdsrSettings {
    /* 0x0 */ u8 decayIndex; // index used to obtain adsr decay rate from adsrDecayTable
    /* 0x1 */ u8 sustain;
    /* 0x4 */ EnvelopePoint* envelope;
} AdsrSettings; // size = 0x8

typedef struct AdsrState {
    /* 0x00 */ union {
        struct A {
            /* 0x00 */ u8 unused : 1;
            /* 0x00 */ u8 hang : 1;
            /* 0x00 */ u8 decay : 1;
            /* 0x00 */ u8 release : 1;
            /* 0x00 */ u8 state : 4;
        } s;
        /* 0x00 */ u8 asByte;
    } action;
    /* 0x01 */ u8 envIndex;
    /* 0x02 */ s16 delay;
    /* 0x04 */ f32 sustain;
    /* 0x08 */ f32 velocity;
    /* 0x0C */ f32 fadeOutVel;
    /* 0x10 */ f32 current;
    /* 0x14 */ f32 target;
    /* 0x18 */ char unk_18[4];
    /* 0x1C */ EnvelopePoint* envelope;
} AdsrState; // size = 0x20

typedef struct StereoData {
    /* 0x00 */ u8 unused : 2;
    /* 0x00 */ u8 bit2 : 2;
    /* 0x00 */ u8 strongRight : 1;
    /* 0x00 */ u8 strongLeft : 1;
    /* 0x00 */ u8 stereoHeadsetEffects : 1;
    /* 0x00 */ u8 usesHeadsetPanEffects : 1;
} StereoData; // size = 0x1

typedef union Stereo {
    /* 0x00 */ StereoData s;
    /* 0x00 */ u8 asByte;
} Stereo; // size = 0x1

typedef struct NoteAttributes {
    /* 0x00 */ u8 reverb;
    /* 0x01 */ u8 gain; // Increases volume by a multiplicative scaling factor. Represented as a UQ4.4 number
    /* 0x02 */ u8 pan;
    /* 0x03 */ Stereo stereo;
    /* 0x04 */ u8 combFilterSize;
    /* 0x06 */ u16 combFilterGain;
    /* 0x08 */ f32 freqScale;
    /* 0x0C */ f32 velocity;
    /* 0x10 */ s16* filter;
    // /* 0x14 */ s16 filterBuf[8];
} NoteAttributes; // size = 0x14

// Also known as a SubTrack, according to sm64 debug strings.
typedef struct SequenceChannel {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 stopScript : 1;
    /* 0x00 */ u8 muted : 1; // sets SequenceLayer.muted
    /* 0x00 */ u8 hasInstrument : 1;
    /* 0x00 */ u8 stereoHeadsetEffects : 1;
    /* 0x00 */ u8 largeNotes : 1; // notes specify duration and velocity
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
    /* 0x05 */ u8 notePriority; // 0-3
    /* 0x06 */ u8 someOtherPriority;
    /* 0x07 */ u8 fontId;
    /* 0x08 */ u8 reverbIndex;
    /* 0x09 */ u8 bookOffset;
    /* 0x0A */ u8 newPan;
    /* 0x0B */ u8 panChannelWeight;  // proportion of pan that comes from the channel (0..128)
    /* 0x0C */ u8 gain; // Increases volume by a multiplicative scaling factor. Represented as a UQ4.4 number
    /* 0x0D */ u8 velocityRandomVariance;
    /* 0x0E */ u8 gateTimeRandomVariance;
    /* 0x0F */ u8 combFilterSize;
    /* 0x10 */ u16 vibratoRateStart;
    /* 0x12 */ u16 vibratoDepthStart;
    /* 0x14 */ u16 vibratoRateTarget;
    /* 0x16 */ u16 vibratoDepthTarget;
    /* 0x18 */ u16 vibratoRateChangeDelay;
    /* 0x1A */ u16 vibratoDepthChangeDelay;
    /* 0x1C */ u16 vibratoDelay;
    /* 0x1E */ u16 delay;
    /* 0x20 */ u16 combFilterGain;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ s16 instOrWave; // either 0 (none), instrument index + 1, or
                             // 0x80..0x83 for sawtooth/triangle/sine/square waves.
    /* 0x26 */ s16 transposition;
    /* 0x28 */ f32 volumeScale;
    /* 0x2C */ f32 volume;
    /* 0x30 */ s32 pan;
    /* 0x34 */ f32 appliedVolume;
    /* 0x38 */ f32 freqScale;
    /* 0x3C */ u8 (*dynTable)[][2];
    /* 0x40 */ struct Note* noteUnused;
    /* 0x44 */ struct SequenceLayer* layerUnused;
    /* 0x48 */ Instrument* instrument;
    /* 0x4C */ SequencePlayer* seqPlayer;
    /* 0x50 */ struct SequenceLayer* layers[4];
    /* 0x60 */ SeqScriptState scriptState;
    /* 0x7C */ AdsrSettings adsr;
    /* 0x84 */ NotePool notePool;
    /* 0xC4 */ s8 seqScriptIO[8]; // bridge between .seq script and audio lib, "io ports"
    /* 0xCC */ s16* filter;
    /* 0xD0 */ Stereo stereo;
    /* 0xD4 */ s32 startSamplePos;
    /* 0xD8 */ s32 unk_D8;
} SequenceChannel; // size = 0xDC

// Might also be known as a Track, according to sm64 debug strings (?).
typedef struct SequenceLayer {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 muted : 1;
    /* 0x00 */ u8 continuousNotes : 1; // keep the same note for consecutive notes with the same sound
    /* 0x00 */ u8 bit3 : 1; // "loaded"?
    /* 0x00 */ u8 ignoreDrumPan : 1;
    /* 0x00 */ u8 bit1 : 1; // "has initialized continuous notes"?
    /* 0x00 */ u8 notePropertiesNeedInit : 1;
    /* 0x01 */ Stereo stereo;
    /* 0x02 */ u8 instOrWave;
    /* 0x03 */ u8 gateTime;
    /* 0x04 */ u8 semitone;
    /* 0x05 */ u8 portamentoTargetNote;
    /* 0x06 */ u8 pan; // 0..128
    /* 0x07 */ u8 notePan;
    /* 0x08 */ s16 delay;
    /* 0x0A */ s16 gateDelay;
    /* 0x0C */ s16 delay2;
    /* 0x0E */ u16 portamentoTime;
    /* 0x10 */ s16 transposition; // #semitones added to play commands
                                  // (seq instruction encoding only allows referring to the limited range
                                  // 0..0x3F; this makes 0x40..0x7F accessible as well)
    /* 0x12 */ s16 shortNoteDefaultDelay;
    /* 0x14 */ s16 lastDelay;
    /* 0x18 */ AdsrSettings adsr;
    /* 0x20 */ Portamento portamento;
    /* 0x2C */ struct Note* note;
    /* 0x30 */ f32 freqScale;
    /* 0x34 */ f32 bend;
    /* 0x38 */ f32 velocitySquare2;
    /* 0x3C */ f32 velocitySquare; // not sure which one of those corresponds to the sm64 original
    /* 0x40 */ f32 noteVelocity;
    /* 0x44 */ f32 noteFreqScale;
    /* 0x48 */ Instrument* instrument;
    /* 0x4C */ TunedSample* tunedSample;
    /* 0x50 */ SequenceChannel* channel;
    /* 0x54 */ SeqScriptState scriptState;
    /* 0x70 */ AudioListItem listItem;
} SequenceLayer; // size = 0x80

typedef struct NoteSynthesisBuffers {
    /* 0x000 */ s16 adpcmdecState[16];
    /* 0x020 */ s16 finalResampleState[16];
    /* 0x040 */ s16 mixEnvelopeState[32];
} NoteSynthesisBuffers; // size = 0x80

typedef struct NoteSynthesisState {
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
    /* 0x14 */ char unk_14[0x6];
    /* 0x1A */ u8 combFilterNeedsInit;
    /* 0x1B */ u8 unk_1B;
    /* 0x1C */ char unk_1C[0x4];
} NoteSynthesisState; // size = 0x20

typedef struct VibratoState {
    /* 0x00 */ struct SequenceChannel* channel;
    /* 0x04 */ u32 time;
    /* 0x08 */ s16* curve; // sineWave
    /* 0x0C */ f32 depth;
    /* 0x10 */ f32 rate;
    /* 0x14 */ u8 active;
    /* 0x16 */ u16 rateChangeTimer;
    /* 0x18 */ u16 depthChangeTimer;
    /* 0x1A */ u16 delay;
} VibratoState; // size = 0x1C

typedef struct NotePlaybackState {
    /* 0x00 */ u8 priority;
    /* 0x01 */ u8 waveId;
    /* 0x02 */ u8 harmonicIndex; // the harmonic index for the synthetic wave contained in gWaveSamples (also matches the base 2 logarithm of the harmonic order)
    /* 0x03 */ u8 fontId;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 stereoHeadsetEffects;
    /* 0x06 */ s16 adsrVolScaleUnused;
    /* 0x08 */ f32 portamentoFreqScale;
    /* 0x0C */ f32 vibratoFreqScale;
    /* 0x10 */ SequenceLayer* prevParentLayer;
    /* 0x14 */ SequenceLayer* parentLayer;
    /* 0x18 */ SequenceLayer* wantedParentLayer;
    /* 0x1C */ NoteAttributes attributes;
    /* 0x30 */ AdsrState adsr;
    /* 0x50 */ Portamento portamento;
    /* 0x5C */ VibratoState vibratoState;
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ u8 unk_7C;
    /* 0x80 */ s32 startSamplePos; // initial position/index to start processing s16 samples
} NotePlaybackState; // size = 0x84

typedef struct NoteSubEu {
    struct {
        /* 0x00 */ volatile u8 enabled : 1;
        /* 0x00 */ u8 needsInit : 1;
        /* 0x00 */ u8 finished : 1; // ?
        /* 0x00 */ u8 unused : 1;
        /* 0x00 */ u8 stereoStrongRight : 1;
        /* 0x00 */ u8 stereoStrongLeft : 1;
        /* 0x00 */ u8 stereoHeadsetEffects : 1;
        /* 0x00 */ u8 usesHeadsetPanEffects : 1; // ?
    } bitField0;
    struct {
        /* 0x01 */ u8 reverbIndex : 3;
        /* 0x01 */ u8 bookOffset : 2;
        /* 0x01 */ u8 isSyntheticWave : 1;
        /* 0x01 */ u8 hasTwoParts : 1;
        /* 0x01 */ u8 useHaasEffect : 1;
    } bitField1;
    /* 0x02 */ u8 gain; // Increases volume by a multiplicative scaling factor. Represented as a UQ4.4 number
    /* 0x03 */ u8 haasEffectLeftDelaySize;
    /* 0x04 */ u8 haasEffectRightDelaySize;
    /* 0x05 */ u8 reverbVol;
    /* 0x06 */ u8 harmonicIndexCurAndPrev; // bits 3..2 store curHarmonicIndex, bits 1..0 store prevHarmonicIndex
    /* 0x07 */ u8 combFilterSize;
    /* 0x08 */ u16 targetVolLeft;
    /* 0x0A */ u16 targetVolRight;
    /* 0x0C */ u16 resamplingRateFixedPoint;
    /* 0x0E */ u16 combFilterGain;
    /* 0x10 */ union {
                 TunedSample* tunedSample;
                 s16* waveSampleAddr; // used for synthetic waves
             };
    /* 0x14 */ s16* filter;
    /* 0x18 */ char pad_18[0x8];
} NoteSubEu; // size = 0x20

typedef struct Note {
    /* 0x00 */ AudioListItem listItem;
    /* 0x10 */ NoteSynthesisState synthesisState;
    /* 0x30 */ NotePlaybackState playbackState;
    /* 0xB4 */ NoteSubEu noteSubEu;
} Note; // size = 0xE0

typedef struct ReverbSettings {
    /* 0x00 */ u8 downsampleRate;
    /* 0x02 */ u16 windowSize;
    /* 0x04 */ u16 decayRatio; // determines how much reverb persists
    /* 0x06 */ u16 unk_6;
    /* 0x08 */ u16 unk_8;
    /* 0x0A */ u16 volume;
    /* 0x0C */ u16 leakRtl;
    /* 0x0E */ u16 leakLtr;
    /* 0x10 */ s8 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ s16 lowPassFilterCutoffLeft;
    /* 0x16 */ s16 lowPassFilterCutoffRight;
} ReverbSettings; // size = 0x18

/**
 * The high-level audio specifications requested when initializing or resetting the audio heap.
 * The audio heap can be reset on various occasions, including on most scene transitions.
 */
typedef struct AudioSpec {
    /* 0x00 */ u32 samplingFrequency; // Target sampling rate in Hz
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 numNotes;
    /* 0x06 */ u8 numSequencePlayers;
    /* 0x07 */ u8 unk_07; // unused, set to zero
    /* 0x08 */ u8 unk_08; // unused, set to zero
    /* 0x09 */ u8 numReverbs;
    /* 0x0C */ ReverbSettings* reverbSettings;
    /* 0x10 */ u16 sampleDmaBufSize1; // size of buffers in the audio misc pool to store small snippets of individual samples. Stored short-lived.
    /* 0x12 */ u16 sampleDmaBufSize2; // size of buffers in the audio misc pool to store small snippets of individual samples. Stored long-lived.
    /* 0x14 */ u16 unk_14;
    /* 0x18 */ size_t persistentSeqCacheSize;  // size of cache on audio pool to store sequences persistently
    /* 0x1C */ size_t persistentFontCacheSize; // size of cache on audio pool to store soundFonts persistently
    /* 0x20 */ size_t persistentSampleBankCacheSize; // size of cache on audio pool to store entire sample banks persistently
    /* 0x24 */ size_t temporarySeqCacheSize;  // size of cache on audio pool to store sequences temporarily
    /* 0x28 */ size_t temporaryFontCacheSize; // size of cache on audio pool to store soundFonts temporarily
    /* 0x2C */ size_t temporarySampleBankCacheSize; // size of cache on audio pool to store entire sample banks temporarily
    /* 0x30 */ ssize_t persistentSampleCacheSize; // size of cache in the audio misc pool to store individual samples persistently
    /* 0x34 */ ssize_t temporarySampleCacheSize; // size of cache in the audio misc pool to store individual samples temporarily
} AudioSpec; // size = 0x38

/**
 * The audio buffer stores the fully processed digital audio before it is sent to the audio interface (AI), then to the
 * digital-analog converter (DAC), then to play on the speakers. The audio buffer is written to by the rsp after
 * processing audio commands. This struct parameterizes that buffer.
 */
typedef struct AudioBufferParameters {
    /* 0x00 */ s16 specUnk4;
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

/**
 * Meta-data associated with a pool (contained within the Audio Heap)
 */
typedef struct AudioAllocPool {
    /* 0x0 */ u8* startRamAddr; // start addr of the pool
    /* 0x4 */ u8* curRamAddr; // address of the next available memory for allocation
    /* 0x8 */ ssize_t size; // size of the pool
    /* 0xC */ s32 numEntries; // number of entries allocated to the pool
} AudioAllocPool; // size = 0x10

/**
 * Audio cache entry data to store a single entry containing either a sequence, soundfont, or entire sample banks
 */
typedef struct AudioCacheEntry {
    /* 0x0 */ u8* ramAddr;
    /* 0x4 */ size_t size;
    /* 0x8 */ s16 tableType;
    /* 0xA */ s16 id;
} AudioCacheEntry; // size = 0xC

/**
 * Audio cache entry data to store a single entry containing an individual sample
 */
typedef struct SampleCacheEntry {
    /* 0x00 */ s8 inUse;
    /* 0x01 */ s8 origMedium;
    /* 0x02 */ s8 sampleBankId;
    /* 0x03 */ char unk_03[0x5];
    /* 0x08 */ u8* allocatedAddr;
    /* 0x0C */ void* sampleAddr;
    /* 0x10 */ size_t size;
} SampleCacheEntry; // size = 0x14

/**
 * Audio cache entry data to store individual samples
 */
typedef struct AudioSampleCache {
    /* 0x000 */ AudioAllocPool pool;
    /* 0x010 */ SampleCacheEntry entries[24];
    /* 0x1F0 */ s32 numEntries;
} AudioSampleCache; // size = 0x1F4

typedef struct AudioPersistentCache {
    /* 0x00*/ u32 numEntries;
    /* 0x04*/ AudioAllocPool pool;
    /* 0x14*/ AudioCacheEntry entries[16];
} AudioPersistentCache; // size = 0xD4

typedef struct AudioTemporaryCache {
    /* 0x00*/ u32 nextSide;
    /* 0x04*/ AudioAllocPool pool;
    /* 0x14*/ AudioCacheEntry entries[2];
} AudioTemporaryCache; // size = 0x3C

typedef struct AudioCache {
    /* 0x000*/ AudioPersistentCache persistent;
    /* 0x0D4*/ AudioTemporaryCache temporary;
    /* 0x100*/ u8 unk_100[0x10];
} AudioCache; // size = 0x110

typedef struct AudioCachePoolSplit {
    /* 0x0 */ size_t persistentCommonPoolSize;
    /* 0x4 */ size_t temporaryCommonPoolSize;
} AudioCachePoolSplit; // size = 0x8

typedef struct AudioCommonPoolSplit {
    /* 0x0 */ size_t seqCacheSize;
    /* 0x4 */ size_t fontCacheSize;
    /* 0x8 */ size_t sampleBankCacheSize;
} AudioCommonPoolSplit; // size = 0xC

typedef struct AudioSessionPoolSplit {
    /* 0x0 */ size_t miscPoolSize;
    /* 0x4 */ size_t unkSizes[2];
    /* 0xC */ size_t cachePoolSize;
} AudioSessionPoolSplit; // size = 0x10

typedef struct AudioPreloadReq {
    /* 0x00 */ u32 endAndMediumKey;
    /* 0x04 */ Sample* sample;
    /* 0x08 */ u8* ramAddr;
    /* 0x0C */ u32 encodedInfo;
    /* 0x10 */ s32 isFree;
} AudioPreloadReq; // size = 0x14

/**
 * Audio commands used to transfer audio requests from the graph thread to the audio thread
 */
typedef struct AudioCmd {
    /* 0x0 */ union{
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

typedef struct AudioAsyncLoad {
    /* 0x00 */ s8 status;
    /* 0x01 */ s8 delay;
    /* 0x02 */ s8 medium;
    /* 0x04 */ u8* ramAddr;
    /* 0x08 */ uintptr_t curDevAddr;
    /* 0x0C */ u8* curRamAddr;
    /* 0x10 */ u32 bytesRemaining;
    /* 0x14 */ size_t chunkSize;
    /* 0x18 */ s32 diskLba;
    /* 0x1C */ u32 retMsg;
    /* 0x20 */ OSMesgQueue* retQueue;
    /* 0x24 */ OSMesgQueue msgQueue;
    /* 0x3C */ OSMesg msg;
    /* 0x40 */ OSIoMesg ioMesg;
} AudioAsyncLoad; // size = 0x58

typedef struct AudioSlowLoad {
    /* 0x00 */ u8 medium;
    /* 0x01 */ u8 seqOrFontId;
    /* 0x02 */ u16 instId;
    /* 0x04 */ s32 diskLba;
    /* 0x08 */ uintptr_t curDevAddr;
    /* 0x0C */ u8* curRamAddr;
    /* 0x10 */ u8* ramAddr;
    /* 0x14 */ s32 state;
    /* 0x18 */ s32 bytesRemaining;
    /* 0x1C */ s8* status; // write-only
    /* 0x20 */ Sample sample;
    /* 0x30 */ OSMesgQueue msgQueue;
    /* 0x48 */ OSMesg msg;
    /* 0x4C */ OSIoMesg ioMesg;
} AudioSlowLoad; // size = 0x64

typedef struct AudioTableHeader {
    /* 0x00 */ s16 numEntries;
    /* 0x02 */ s16 diskLba;
    /* 0x04 */ uintptr_t romAddr;
    /* 0x08 */ char pad[0x8];
} AudioTableHeader; // size = 0x10

typedef struct AudioTableEntry {
    /* 0x00 */ uintptr_t romAddr;
    /* 0x04 */ size_t size;
    /* 0x08 */ s8 medium;
    /* 0x09 */ s8 cachePolicy;
    /* 0x0A */ s16 shortData1;
    /* 0x0C */ s16 shortData2;
    /* 0x0E */ s16 shortData3;
} AudioTableEntry; // size = 0x10

typedef struct AudioTable {
    /* 0x00 */ AudioTableHeader header;
    /* 0x10 */ AudioTableEntry entries[]; // (dynamic size)
} AudioTable; // size >= 0x20

typedef struct {
    /* 0x00 */ s32 sampleBankId1;
    /* 0x04 */ s32 sampleBankId2;
    /* 0x08 */ s32 baseAddr1;
    /* 0x0C */ s32 baseAddr2;
    /* 0x10 */ u32 medium1;
    /* 0x14 */ u32 medium2;
} SampleBankRelocInfo; // size = 0x18

typedef struct SampleDma {
    /* 0x00 */ u8* ramAddr;
    /* 0x04 */ uintptr_t devAddr;
    /* 0x08 */ u16 sizeUnused;
    /* 0x0A */ u16 size;
    /* 0x0C */ u8 unused;
    /* 0x0D */ u8 reuseIndex; // position in sSampleDmaReuseQueue1/2, if ttl == 0
    /* 0x0E */ u8 ttl;        // duration after which the DMA can be discarded
} SampleDma; // size = 0x10

typedef struct StorageChange {
    uintptr_t oldAddr;
    uintptr_t newAddr;
    size_t size;
    u8 newMedium;
} StorageChange;

typedef struct AudioTask {
    /* 0x00 */ OSTask task;
    /* 0x40 */ OSMesgQueue* msgQueue;
    /* 0x44 */ void* unk_44; // probably a message that gets unused.
    /* 0x48 */ char unk_48[0x8];
} AudioTask; // size = 0x50

typedef struct NoteSubAttributes {
    /* 0x00 */ u8 reverbVol;
    /* 0x01 */ u8 gain; // Increases volume by a multiplicative scaling factor. Represented as a UQ4.4 number
    /* 0x02 */ u8 pan;
    /* 0x03 */ Stereo stereo;
    /* 0x04 */ f32 frequency;
    /* 0x08 */ f32 velocity;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ s16* filter;
    /* 0x14 */ u8 combFilterSize;
    /* 0x16 */ u16 combFilterGain;
} NoteSubAttributes; // size = 0x18

typedef struct TempoData {
    /* 0x0 */ s16 unk_00; // unused
    /* 0x2 */ s16 seqTicksPerBeat;
} TempoData; // size = 0x4

typedef struct AudioHeapInitSizes {
    /* 0x00 */ size_t heapSize; // total number of bytes allocated to the audio heap. Must be <= the size of `gAudioHeap` (ideally about the same size)
    /* 0x04 */ size_t initPoolSize; // The entire audio heap is split into two pools.
    /* 0x08 */ size_t permanentPoolSize;
} AudioHeapInitSizes; // size = 0xC

typedef struct AudioContext {
    s8 unk_0000;
    /* 0x0001 */ s8 numSynthesisReverbs;
    /* 0x0002 */ u16 unk_2;
    /* 0x0004 */ u16 unk_4;
    s8 unk_0006[0xA];
    /* 0x0010 */ s16* curLoadedBook;
    /* 0x0014 */ NoteSubEu* noteSubsEu;
    /* 0x0018 */ SynthesisReverb synthesisReverbs[1];
    s8 unk_02E0[0x30];
    /* 0x0310 */ Sample* usedSamples[128];
    /* 0x0510 */ AudioPreloadReq preloadSampleStack[128];
    /* 0x0F10 */ s32 numUsedSamples;
    /* 0x0F14 */ s32 preloadSampleStackTop;
    /* 0x0F18 */ AudioAsyncLoad asyncLoads[22];
    /* 0x16A8 */ OSMesgQueue asyncLoadDiskDriveQueue;
    /* 0x16C0 */ OSMesg asyncLoadDiskDriveMsgBuf[22];
    /* 0x1718 */ AudioAsyncLoad* curDiskDriveLoad;
    /* 0x171C */ s32 slowLoadPos;
    /* 0x1720 */ AudioSlowLoad slowLoads[2];
    /* 0x17E8 */ OSPiHandle* cartHandle;
    /* 0x17EC */ OSPiHandle* driveHandle;
    /* 0x17F0 */ OSMesgQueue externalLoadQueue;
    /* 0x1808 */ OSMesg externalLoadMsgBuf[64];
    /* 0x1908 */ OSMesgQueue preloadSampleQueue;
    /* 0x1928 */ OSMesg preloadSampleMsgBuf[64];
    /* 0x1A20 */ OSMesgQueue curAudioFrameDmaQueue;
    /* 0x1A38 */ OSMesg curAudioFrameDmaMsgBuf[32];
    /* 0x1AB8 */ OSIoMesg curAudioFrameDmaIoMsgBuf[32];
    /* 0x1DB8 */ OSMesgQueue syncDmaQueue;
    /* 0x1DD0 */ OSMesg syncDmaMesg;
    /* 0x1DD4 */ OSIoMesg syncDmaIoMesg;
    /* 0x1DEC */ SampleDma* sampleDmas;
    /* 0x1DF0 */ u32 sampleDmaCount;
    /* 0x1DF4 */ u32 sampleDmaListSize1;
    /* 0x1DF8 */ s32 unused1DF8;
    /* 0x1DFC */ u8 sampleDmaReuseQueue1[0x100];
    /* 0x1EFC */ u8 sampleDmaReuseQueue2[0x100];
    /* 0x1FFC */ u8 sampleDmaReuseQueue1RdPos;
    /* 0x1FFD */ u8 sampleDmaReuseQueue2RdPos;
    /* 0x1FFE */ u8 sampleDmaReuseQueue1WrPos;
    /* 0x1FFF */ u8 sampleDmaReuseQueue2WrPos;
    /* 0x2000 */ AudioTable* sequenceTable;
    /* 0x2004 */ AudioTable* soundFontTable;
    /* 0x2008 */ AudioTable* sampleBankTable;
    /* 0x200C */ u8* sequenceFontTable;
    /* 0x2010 */ s16 numSequences;
    /* 0x2014 */ SoundFont* soundFontList;
    /* 0x2018 */ AudioBufferParameters audioBufferParameters;
    /* 0x2040 */ f32 unk_2040;
    /* 0x2044 */ s32 sampleDmaBufSize1;
    /* 0x2048 */ s32 sampleDmaBufSize2;
    s8 unk_204C[0x10];
    /* 0x205C */ s32 sampleDmaBufSize;
    /* 0x2060 */ s32 maxAudioCmds;
    /* 0x2064 */ s32 numNotes;
    /* 0x2068 */ s16 maxTempo;
    /* 0x206A */ s8 soundMode;
    /* 0x206C */ s32 totalTaskCount;
    /* 0x2070 */ s32 curAudioFrameDmaCount;
    /* 0x2074 */ s32 rspTaskIndex; 
    /* 0x2078 */ s32 curAiBufIndex;
    /* 0x207C */ Acmd* abiCmdBufs[2];
    /* 0x2084 */ Acmd* curAbiCmdBuf;
    /* 0x2088 */ AudioTask* curTask;
    /* 0x2090 */ AudioTask rspTask[2];
    /* 0x2130 */ f32 maxTempoTvTypeFactors;
    /* 0x2134 */ s32 refreshRate;
    /* 0x2138 */ s16* aiBuffers[3];
    /* 0x2144 */ s16 aiBufLengths[3];
    /* 0x214C */ u32 audioRandom;
    /* 0x2150 */ s32 audioErrorFlags;
    /* 0x2154 */ volatile u32 resetTimer;
    s8 unk_2158[0x4];
    /* 0x215C */ s8 unk_215C;
    /* 0x2160 */ AudioAllocPool sessionPool;
    /* 0x2170 */ AudioAllocPool externalPool;
    /* 0x2180 */ AudioAllocPool initPool;
    /* 0x2190 */ AudioAllocPool miscPool;
    s8 unk_21A0[0x20];
    /* 0x21C0 */ AudioAllocPool cachePool;
    /* 0x21D0 */ AudioAllocPool persistentCommonPool;
    /* 0x21E0 */ AudioAllocPool temporaryCommonPool;
    /* 0x21F0 */ AudioCache seqCache;
    /* 0x2300 */ AudioCache fontCache;
    /* 0x2410 */ AudioCache sampleBankCache;
    /* 0x2520 */ AudioAllocPool permanentPool;
    /* 0x2530 */ AudioCacheEntry permanentCache[32];
    s8 unk_26B0[0x180];
    /* 0x2830 */ AudioSampleCache persistentSampleCache;
    /* 0x2944 */ AudioSampleCache temporarySampleCache;
    /* 0x2C18 */ AudioSessionPoolSplit sessionPoolSplit;
    /* 0x2C28 */ AudioCachePoolSplit cachePoolSplit;
    /* 0x2C30 */ AudioCommonPoolSplit persistentCommonPoolSplit;
    /* 0x2C3C */ AudioCommonPoolSplit temporaryCommonPoolSplit;
    /* 0x2C48 */ u8 sampleFontLoadStatus[0x1A];
    /* 0x2C62 */ u8 fontLoadStatus[0x1A];
    /* 0x2C7C */ u8 seqLoadStatus[0x1A];
    /* 0x2C96 */ volatile u8 resetStatus;
    /* 0x2C97 */ u8 specId;
    /* 0x2C98 */ s32 audioResetFadeOutFramesLeft;
    /* 0x2C9C */ f32* adsrDecayTable;
    /* 0x2CA0 */ u8* audioHeap;
    /* 0x2CA4 */ size_t audioHeapSize;
    /* 0x2CA8 */ Note* notes;
    /* 0x2CAC */ SequencePlayer seqPlayers[2];
    /* 0x2F6C */ SequenceLayer sequenceLayers[64];
    /* 0x4F6C */ SequenceChannel sequenceChannelNone;
    /* 0x5048 */ s32 noteSubEuOffset;
    /* 0x504C */ AudioListItem layerFreeList;
    /* 0x505C */ NotePool noteFreeLists;
    /* 0x509C */ u8 threadCmdWritePos;
    /* 0x509D */ u8 threadCmdReadPos;
    /* 0x509E */ u8 threadCmdQueueFinished;
    /* 0x50A0 */ u16 threadCmdChannelMask[2];
    /* 0x50A4 */ OSMesgQueue* audioResetQueueP;
    /* 0x50A8 */ OSMesgQueue* taskStartQueueP;
    /* 0x50AC */ OSMesgQueue* threadCmdProcQueueP;
    /* 0x50B0 */ OSMesgQueue taskStartQueue;
    /* 0x50C8 */ OSMesgQueue threadCmdProcQueue;
    /* 0x50E0 */ OSMesgQueue audioResetQueue;
    /* 0x50F8 */ OSMesg taskStartMsgBuf[1];
    /* 0x50FC */ OSMesg audioResetMsgBuf[1];
    /* 0x5100 */ OSMesg threadCmdProcMsgBuf[4];
    /* 0x5110 */ AudioCmd threadCmdBuf[256];
} AudioContext; // size = 0x5910

typedef void (*AudioCustomUpdateFunction)(void);
typedef s32 (*DmaHandler)(OSPiHandle* handle, OSIoMesg* mb, s32 direction);
typedef s32 (*LeoHandler)(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq);

#define NO_LAYER ((SequenceLayer*) (-1))
#define IS_SEQUENCE_CHANNEL_VALID(ptr) ((uintptr_t) (ptr) != (uintptr_t) &gAudioCtx.sequenceChannelNone)

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
    /* 1 */ MEDIUM_LBA,
    /* 2 */ MEDIUM_CART,
    /* 3 */ MEDIUM_DISK_DRIVE
} SampleMedium;

typedef enum {
    /* 0 */ CODEC_ADPCM,       // 16 2-byte samples (32 bytes) compressed into 4-bit samples (8 bytes) + 1 header byte
    /* 1 */ CODEC_S8,          // 16 2-byte samples (32 bytes) compressed into 8-bit samples (16 bytes)
    /* 2 */ CODEC_S16_INMEMORY,
    /* 3 */ CODEC_SMALL_ADPCM, // 16 2-byte samples (32 bytes) compressed into 2-bit samples (4 bytes) + 1 header byte
    /* 4 */ CODEC_REVERB,
    /* 5 */ CODEC_S16,
    /* 6 */ CODEC_UNK6
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

typedef enum HaasEffectDelaySide {
    /* 0 */ HAAS_EFFECT_DELAY_NONE,
    /* 1 */ HAAS_EFFECT_DELAY_LEFT, // Delay left channel so that right channel is heard first
    /* 2 */ HAAS_EFFECT_DELAY_RIGHT // Delay right channel so that left channel is heard first
} HaasEffectDelaySide;

#define MUTE_BEHAVIOR_3 (1 << 3)           // prevent further noteSubEus from playing
#define MUTE_BEHAVIOR_4 (1 << 4)           // stop something in seqLayer scripts
#define MUTE_BEHAVIOR_SOFTEN (1 << 5)      // lower volume, by default to half
#define MUTE_BEHAVIOR_STOP_NOTES (1 << 6)  // prevent further notes from playing
#define MUTE_BEHAVIOR_STOP_SCRIPT (1 << 7) // stop processing sequence/channel scripts

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

// Filter sizes
#define FILTER_SIZE (8 * SAMPLE_SIZE)
#define FILTER_BUF_PART1 (8 * SAMPLE_SIZE)
#define FILTER_BUF_PART2 (8 * SAMPLE_SIZE)

#define SAMPLE_SIZE sizeof(s16)

// Samples are processed in groups of 16 called a "frame"
#define SAMPLES_PER_FRAME ADPCMFSIZE

#define AIBUF_LEN (88 * SAMPLES_PER_FRAME) // number of samples
#define AIBUF_SIZE (AIBUF_LEN * SAMPLE_SIZE) // number of bytes

#define EXTRA_BUFFERED_AI_SAMPLES_TARGET 0x80
#define SAMPLES_TO_OVERPRODUCE 0x10

#define DMEM_1CH_SIZE (13 * SAMPLES_PER_FRAME * SAMPLE_SIZE)
#define DMEM_2CH_SIZE (2 * DMEM_1CH_SIZE)

#define DMEM_TEMP 0x3C0
#define DMEM_HAAS_TEMP 0x5C0
#define DMEM_LEFT_CH 0x940
#define DMEM_RIGHT_CH 0xAE0
#define DMEM_WET_TEMP 0x3E0
#define DMEM_WET_SCRATCH 0x720
#define DMEM_WET_LEFT_CH 0xC80
#define DMEM_WET_RIGHT_CH 0xE20

#define DMEM_UNCOMPRESSED_NOTE 0x580
#define DMEM_COMPRESSED_ADPCM_DATA 0x940

#define AUDIO_MK_CMD(b0,b1,b2,b3) ((((b0) & 0xFF) << 0x18) | (((b1) & 0xFF) << 0x10) | (((b2) & 0xFF) << 0x8) | (((b3) & 0xFF) << 0))

extern AudioContext gAudioCtx;

void Audio_NoteSetResamplingRate(Note* note, f32 freqScale);
void Audio_NoteDisable(Note* note);
void Audio_ProcessNotes(void);
TunedSample* Audio_GetInstrumentTunedSample(Instrument* instrument, s32 semitone);
Instrument* Audio_GetInstrument(s32 fontId, s32 instId);
Drum* Audio_GetDrum(s32 fontId, s32 drumId);
SoundEffect* Audio_GetSoundEffect(s32 fontId, s32 sfxId);
void Audio_SeqLayerNoteDecay(SequenceLayer* layer);
void Audio_SeqLayerNoteRelease(SequenceLayer* layer);
void Audio_InitNoteLists(NotePool* pool);
void Audio_InitNoteFreeList(void);
void Audio_NotePoolClear(NotePool* pool);
void Audio_NotePoolFill(NotePool* pool, s32 count);
void Audio_AudioListRemove(AudioListItem* item);
void Audio_AudioListPushFront(AudioListItem* item1, AudioListItem* item2);
void Audio_NoteInitForLayer(Note* note, SequenceLayer* layer);
Note* Audio_AllocNote(SequenceLayer* layer);
void Audio_NoteInitAll(void);

void Audio_NoteVibratoUpdate(Note* note);
void Audio_NoteVibratoInit(Note* note);
void Audio_NotePortamentoInit(Note* note);
void Audio_SequencePlayerProcessSound(SequencePlayer* seqPlayer);
void Audio_AdsrInit(AdsrState* adsr, EnvelopePoint* envelope, s16* volOut);
f32 Audio_AdsrUpdate(AdsrState* adsr);

void AudioSeq_ProcessSequences(s32 arg0);
void AudioSeq_InitSequencePlayerChannels(s32 playerIdx);
void AudioSeq_InitSequencePlayers(void);
void* AudioLoad_DmaSampleData(uintptr_t devAddr, size_t size, s32 arg2, u8* dmaIndexRef, s32 medium);
void AudioLoad_InitSampleDmaBuffers(s32 numNotes);

void AudioSeq_SequencePlayerDisableAsFinished(SequencePlayer* seqPlayer);
void AudioSeq_SequencePlayerDisable(SequencePlayer* seqPlayer);
void AudioSeq_AudioListPushBack(AudioListItem* list, AudioListItem* item);
void* AudioSeq_AudioListPopBack(AudioListItem* list);
void AudioSeq_SkipForwardSequence(SequencePlayer* seqPlayer);
void AudioSeq_ResetSequencePlayer(SequencePlayer* seqPlayer);
void AudioSeq_SequenceChannelDisable(SequenceChannel* channel);
u8 AudioSeq_ScriptReadU8(SeqScriptState* state);
s16 AudioSeq_ScriptReadS16(SeqScriptState* state);
u16 AudioSeq_ScriptReadCompressedU16(SeqScriptState* state);
void AudioSeq_SeqLayerProcessScriptStep1(SequenceLayer* layer);
s32 AudioSeq_SeqLayerProcessScriptStep2(SequenceLayer* layer);
s32 AudioSeq_SeqLayerProcessScriptStep3(SequenceLayer* layer, s32 cmd);
s32 AudioSeq_SeqLayerProcessScriptStep4(SequenceLayer* layer, s32 cmd);
s32 AudioSeq_SeqLayerProcessScriptStep5(SequenceLayer* layer, s32 sameTunedSample);
u8 AudioSeq_GetInstrument(SequenceChannel* channel, u8 instId, Instrument** instOut, AdsrSettings* adsr);

void AudioLoad_DecreaseSampleDmaTtls(void);
void AudioLoad_ProcessScriptLoads(void);

s32 AudioLoad_Dma(OSIoMesg* mesg, u32 priority, s32 direction, uintptr_t devAddr, void* ramAddr, size_t size, OSMesgQueue* reqQueue, s32 medium, const char* dmaType);
void AudioLoad_SyncDma(uintptr_t devAddr, u8* ramAddr, size_t size, s32 medium);
void AudioLoad_SyncDiskDrive(uintptr_t devAddr, u8* ramAddr, size_t size, s32 lba);
bool AudioLoad_IsFontLoadComplete(s32 fontId);
bool AudioLoad_IsSeqLoadComplete(s32 seqId);
bool AudioLoad_IsSampleLoadComplete(s32 sampleBankId);
void AudioLoad_SetFontLoadStatus(s32 fontId, s32 loadStatus);
void AudioLoad_SetSeqLoadStatus(s32 seqId, s32 loadStatus);
void* AudioLoad_SyncLoadFont(s32 fontId);
void* AudioLoad_SyncLoad(u32 tableType, u32 id, bool* didAllocate);
void* AudioLoad_SearchCaches(s32 tableType, u32 id);
AudioTable* AudioLoad_GetLoadTable(s32 tableType);
void AudioLoad_SyncLoadSeqParts(s32 seqId, s32 flags);
s32 AudioLoad_SyncLoadInstrument(s32 fontId, s32 instId, s32 drumId);
s32 AudioLoad_SyncInitSeqPlayerInternal(s32 playerIdx, s32 seqId, s32 arg2);
void* AudioLoad_TrySyncLoadSampleBank(u32 sampleBankId, u32* outMedium, bool noLoad);
void AudioLoad_RelocateFontAndPreloadSamples(s32 fontId, u32 fontData, SampleBankRelocInfo* sampleBankReloc, s32 async);
void* AudioLoad_AsyncLoadInner(s32 tableType, s32 id, s32 nChunks, s32 retData, OSMesgQueue* retQueue);
void AudioLoad_AsyncLoadSampleBank(s32 sampleBankId, s32 nChunks, s32 retData, OSMesgQueue* retQueue);
void AudioLoad_AsyncLoadFont(s32 fontId, s32 nChunks, s32 retData, OSMesgQueue* retQueue);
void AudioLoad_AsyncLoadSeq(s32 seqId, s32 nChunks, s32 retData, OSMesgQueue* retQueue);
s32 AudioLoad_GetLoadTableIndex(s32 tableType, u32 entryId);
void AudioLoad_RelocateSample(TunedSample* tSample, uintptr_t fontDataAddr, SampleBankRelocInfo* relocInfo);
u8* AudioLoad_GetFontsForSequence(s32 seqId, u32* outNumFonts);
void AudioLoad_SetDmaHandler(DmaHandler);
void AudioLoad_SetLeoHandler(LeoHandler);
void AudioLoad_ProcessSlowLoads(s32 resetStatus);
bool AudioLoad_ProcessSamplePreloads(s32 resetStatus);
void AudioLoad_ProcessAsyncLoads(s32 resetStatus);
AudioAsyncLoad* AudioLoad_StartAsyncLoadDiskDrive(s32 lba, uintptr_t devAddr, void* ramAddr, size_t size, s32 medium, s32 nChunks, OSMesgQueue* retQueue, s32 retMsg);
AudioAsyncLoad* AudioLoad_StartAsyncLoad(uintptr_t devAddr, void* ramAddr, size_t size, s32 medium, s32 nChunks, OSMesgQueue* retQueue, s32 retMsg);
void AudioLoad_DiscardFont(s32 fontId);
void AudioLoad_DiscardSeqFonts(s32 seqId);
void* AudioLoad_SyncLoadSeq(s32 seqId);
void AudioLoad_InitSlowLoads(void);
void AudioLoad_InitScriptLoads(void);
void AudioLoad_InitAsyncLoads(void);
s32 AudioLoad_SlowLoadSeq(s32 seqId, u8* ramAddr, s8* status);
s32 AudioLoad_SyncInitSeqPlayer(s32 playerIdx, s32 seqId, s32 arg2);
s32 AudioLoad_SyncInitSeqPlayerSkipTicks(s32 playerIdx, s32 seqId, s32 skipTicks);
void AudioLoad_ScriptLoad(s32 tableType, s32 id, s8* status);
void AudioLoad_ProcessLoads(s32 resetStatus);
void AudioLoad_Init(void* heap, size_t heapSize);
Sample* AudioLoad_GetFontSample(s32 fontId, s32 instId);
void AudioLoad_DmaSlowCopy(AudioSlowLoad* slowLoad, ssize_t size);
void AudioLoad_DmaSlowCopyDiskDrive(uintptr_t devAddr, u8* ramAddr, size_t size, s32 lba);
void AudioLoad_ProcessAsyncLoadDiskDrive(AudioAsyncLoad* asyncLoad, s32 resetStatus);
void AudioLoad_ProcessAsyncLoad(AudioAsyncLoad* asyncLoad, s32 resetStatus);
void AudioLoad_FinishAsyncLoad(AudioAsyncLoad* asyncLoad);
void AudioLoad_AsyncDma(AudioAsyncLoad* asyncLoad, size_t size);
void AudioLoad_AsyncDiskDrive(uintptr_t devAddr, u8* ramAddr, size_t size, s32 lba);
s32 AudioLoad_SlowLoadSample(s32 fontId, s32 instId, s8* status);
void AudioLoad_LoadPermanentSamples(void);

void Audio_InvalDCache(void* buf, s32 size);
void Audio_WritebackDCache(void* buf, s32 size);

void AudioHeap_DiscardFont(s32 fontId);
void* AudioHeap_AllocZeroed(AudioAllocPool* pool, size_t size);
void* AudioHeap_Alloc(AudioAllocPool* pool, size_t size);
void* AudioHeap_AllocAttemptExternal(AudioAllocPool* pool, size_t size);
void* AudioHeap_AllocDmaMemory(AudioAllocPool* pool, size_t size);
void* AudioHeap_AllocCached(s32 tableType, ssize_t size, s32 cache, s32 id);
void* AudioHeap_AllocPermanent(s32 tableType, s32 id, size_t size);
void AudioHeap_WritebackDCache(void* ramAddr, size_t size);
void* AudioHeap_AllocSampleCache(size_t size, s32 fontId, void* sampleAddr, s8 medium, s32 cache);
void AudioHeap_ApplySampleBankCache(s32 sampleBankId);
void AudioHeap_PopPersistentCache(s32 tableType);
void AudioHeap_InitPool(AudioAllocPool* pool, void* ramAddr, size_t size);
void AudioHeap_InitMainPools(size_t initPoolSize);
void* AudioHeap_SearchRegularCaches(s32 tableType, s32 cache, s32 id);
void* AudioHeap_SearchCaches(s32 tableType, s32 cache, s32 id);
void* AudioHeap_SearchPermanentCache(s32 tableType, s32 id);
void AudioHeap_ReleaseNotesForFont(s32 fontId);
void AudioHeap_LoadFilter(s16* filter, s32 lowPassCutoff, s32 highPassCutoff);
bool AudioHeap_ResetStep(void);
void AudioHeap_Init(void);
void AudioHeap_InitSampleCaches(size_t persistentSampleCacheSize, size_t temporarySampleCacheSize);
void AudioHeap_DiscardSampleBank(s32 sampleBankId);
void AudioHeap_DiscardSampleCaches(void);
void AudioHeap_DiscardSampleBanks(void);
void* AudioHeap_AllocTemporarySampleCache(size_t size, s32 fontId, void* sampleAddr, s8 medium);
SampleCacheEntry* AudioHeap_AllocTemporarySampleCacheEntry(size_t size);
SampleCacheEntry* AudioHeap_AllocPersistentSampleCacheEntry(size_t size);
void AudioHeap_DiscardSampleCacheEntry(SampleCacheEntry* entry);
void AudioHeap_UnapplySampleCache(SampleCacheEntry* entry, Sample* sample);
void AudioHeap_ApplySampleBankCacheInternal(bool apply, s32 sampleBankId);

Acmd* AudioSynth_Update(Acmd* aList, s32* cmdCount, s16* aiStart, s32 aiBufLen);
Acmd* AudioSynth_SingleAudioUpdate(s16* aiBuf, s32 aiBufLen, Acmd* aList, s32 updateIndex);
Acmd* AudioSynth_LoadRingBufferPart(Acmd* aList, u16 dmem, u16 startPos, s32 size, SynthesisReverb* reverb);
Acmd* AudioSynth_SaveRingBufferPart(Acmd* aList, u16 dmem, u16 startPos, s32 size, SynthesisReverb* reverb);
Acmd* AudioSynth_SaveBufferOffset(Acmd* aList, u16 dmem, u16 offset, s32 size, s16* buf);
Acmd* AudioSynth_ProcessNote(s32 noteIndex, NoteSubEu* noteSubEu, NoteSynthesisState* synthState, s16* aiBuf, s32 aiBufLen, Acmd* aList, s32 updateIndex);
Acmd* AudioSynth_FinalResample(Acmd* aList, NoteSynthesisState* synthState, s32 size, u16 pitch, u16 inpDmem, s32 resampleFlags);
Acmd* AudioSynth_ProcessEnvelope(Acmd* aList, NoteSubEu* noteSubEu, NoteSynthesisState* synthState, s32 aiBufLen, u16 dmemSrc, s32 haasEffectDelaySide, s32 flags);

s32 Audio_SetFontInstrument(s32 instrumentType, s32 fontId, s32 index, void* value);

AudioTask* AudioThread_CreateTask(void);
void AudioThread_QueueCmdF32(s32 opArgs, f32 data);
void AudioThread_QueueCmdS32(s32 opArgs, s32 data);
void AudioThread_QueueCmdS8(s32 opArgs, s8 data);
void AudioThread_QueueCmdU16(s32 opArgs, u16 data);
void AudioThread_ProcessSeqPlayerCmd(SequencePlayer* seqPlayer, AudioCmd* cmd);
void AudioThread_ProcessChannelCmd(SequenceChannel* channel, AudioCmd* cmd);
void AudioThread_ProcessCmds(u32 msg);
u32 AudioThread_GetAsyncLoadStatus(u32* outData);
s32 AudioThread_ScheduleProcessCmds(void);
s32 AudioThread_ResetComplete(void);
s32 AudioThread_ResetAudioHeap(s32 specId);
void AudioThread_PreNMIInternal(void);
s32 AudioThread_SilenceCheck(s32 flags);
void AudioThread_InitMesgQueues(void);

extern AudioSpec gAudioSpecs[];
extern TempoData gTempoData;
extern AudioHeapInitSizes gAudioHeapInitSizes;

extern s16 D_80771228[];

extern u8 gAudioHeap[0x2ECA00];

// Unknown Section:

typedef struct LbaVaddrPair {
    s32 lba;
    s32 vAddr;
} LbaVaddrPair;

typedef struct AudioDiskInfo {
    /* 0x00 */ s32 blockSize;
    /* 0x04 */ s32 finalLba;
    /* 0x08 */ LEOCmd cmdBlock;
    s8 unk_24[0x8];
    /* 0x2C */ s32 nLbas;
    /* 0x30 */ u8* endRamAddr;
    /* 0x34 */ s32 nextLba;
    /* 0x38 */ s32 lba;
    /* 0x3C */ uintptr_t devAddr;
    /* 0x40 */ u8* ramAddr;
    /* 0x44 */ s32 bytesRemaining;
    /* 0x48 */ s32 transferState;
    /* 0x4C */ OSMesgQueue mq;
    /* 0x64 */ OSMesg msgBuf[1];
    /* 0x68 */ LbaVaddrPair* lbaVaddrPair;
} AudioDiskInfo; // size >= 0x6C

typedef struct unk_807C1948 {
    /* 0x00 */ uintptr_t unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ uintptr_t sampleAddr;
    /* 0x18 */ s32 sampleSize;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ AudioDiskInfo diskInfo;
    /* 0x9C */ LbaVaddrPair lbaVaddrPair;
} unk_807C1948; // size = 0xA4

#endif // AUDIO_INTERNAL_H
