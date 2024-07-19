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
    /* 0x0 */ u8* ramAddr;
    /* 0x4 */ u32 size;
    /* 0x8 */ s16 tableType;
    /* 0xA */ s16 id;
} AudioCacheEntry; // size = 0xC

typedef struct {
    /* 0x00*/ u32 numEntries;
    /* 0x04*/ AudioAllocPool pool;
    /* 0x14*/ AudioCacheEntry entries[16];
} AudioPersistentCache; // size = 0xD4

typedef struct {
    /* 0x00*/ u32 nextSide;
    /* 0x04*/ AudioAllocPool pool;
    /* 0x14*/ AudioCacheEntry entries[2];
} AudioTemporaryCache;

typedef struct {
    /* 0x000*/ AudioPersistentCache persistent;
    /* 0x0D4*/ AudioTemporaryCache temporary;
} AudioCache;

typedef struct {
    /* 0x00 */ s16 count;
    /* 0x02 */ u16 samplingFrequency;
    /* 0x04 */ u16 aiSamplingFrequency;
    /* 0x06 */ s16 samplesPerFrameTarget;
    /* 0x08 */ s16 maxAiBufferLength;
    /* 0x0A */ s16 minAiBufferLength;
    /* 0x0C */ s16 ticksPerUpdate;
    /* 0x0E */ s16 samplesPerTick;
    /* 0x10 */ s16 numSequencePlayers;
    /* 0x12 */ s16 samplesPerTickMin;
    /* 0x18 */ f32 resampleRate;
    /* 0x1C */ f32 ticksPerUpdateInv;
    /* 0x20 */ f32 ticksPerUpdateInvScaled;
} AudioBufferParameters; // size = 0x24

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
    /* 0x028 */ f32 muteVolumeMod;
    /* 0x02C */ f32 fadeVolumeMod;
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

typedef struct {
    /* 0x00 */ u8 adsrDecayIndex; // index used to obtain adsr decay rate from adsrDecayTable
    /* 0x01 */ u8 pan;
    /* 0x02 */ u8 isRelocated;    // have tunedSample.sample and envelope been relocated (offsets to pointers)
    /* 0x04 */ TunedSample tunedSample;
    /* 0x0C */ EnvelopePoint* envelope;
} Drum; // size = 0x10

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
            /* 0x01 */ u8 freqMod : 1;
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
    /* 0x14 */ f32 volumeMod;
    /* 0x18 */ f32 volume;
    /* 0x1C */ s32 pan;
    /* 0x20 */ f32 appliedVolume;
    /* 0x24 */ f32 freqMod;
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
} SequenceChannel;

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
    /* 0x24 */ f32 freqMod;
    /* 0x28 */ f32 bend;
    /* 0x2C */ f32 velocitySquare;
    /* 0x30 */ f32 velocitySquare2;
    /* 0x34 */ f32 noteVelocity;
    /* 0x38 */ f32 noteFreqMod;
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
} Note; // size = 0xA0

typedef struct {
    /* 0x000 */ s8 pad0[0xE8];
    /* 0x0E8 */ TunedSample tunedSample;
    /* 0x0F0 */ s8 pad[0x40];
} SynthesisReverb; // size = 0x130

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

#define ADSR_DISABLE 0
#define ADSR_HANG -1
#define ADSR_GOTO -2
#define ADSR_RESTART -3

#define SEQ_IO_VAL_NONE -1

#define SEQTICKS_PER_BEAT 48

extern AudioBufferParameters gAudioBufferParams;
extern f32* D_800268B8; // gAudioContext.adsrDecayTable
extern s8 gAudioSoundMode;
extern f32 gDefaultPanVolume[128];
extern s32 gNumNotes;
extern Note* gNotes;
extern NoteSubEu gZeroNoteSub;
extern AudioAllocPool gMiscPool;
extern EnvelopePoint gDefaultEnvelope[];
extern SequenceChannel gSeqChannelNone;
extern SynthesisReverb gSynthesisReverbs[];
extern f32 gBendPitchOneOctaveFrequencies[];
extern f32 gBendPitchTwoSemitonesFrequencies[256];
extern SequencePlayer gSeqPlayers[4];
extern SequenceLayer gSeqLayers[64];

void func_800AA940(void);
TunedSample* func_800AACF0(Instrument* instrument, s32 arg1);
Instrument* func_800AAD2C(s32 arg0, s32 arg1);
Drum* func_800AAD58(s32 arg0, s32 arg1);
void func_800AAF5C(SequenceLayer* layer);
void func_800AAFAC(NotePool* pool);
void func_800AB204(NotePool* pool, s32 count);
Note* func_800AB710(SequenceLayer* layer);

void func_800ABCB4(Note* note);

s32 func_800B0D30(s32 fontId, u8 instId, s8* status);
void* func_800B3534(s32 tableType, s32 cache, s32 id);

#endif
