#ifndef EK_FUNCTIONS_H
#define EK_FUNCTIONS_H

#ifdef EXPANSION_KIT

#include "sys.h"
#include "controller.h"
#include "fzx_math.h"
#include "fzx_object.h"
#include "unk_structs.h"
#include "PR/leo.h"
#include "audio.h"

void func_80767958(void* entry);
void func_806F33D0(FrameBuffer* fb);
s32 func_80768A5C(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq);
s32 func_80768AF0(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq);
s32 func_80768C08(OSPiHandle*, OSIoMesg*, s32);

void DiskDrive_InitRomSegmentPairs(void);
void func_80704DB0(char*, char*);
void DiskMount_Init(void);

s32 AudioLoad_GetStartLbaAddr(s32 lba, uintptr_t* devAddrPtr);
void AudioLoad_DiskDrive(s32 lba, uintptr_t devAddr, u8* ramAddr, s32 totalSize);
s32 AudioLoad_DiskInit(AudioDiskInfo* diskInfo, s32 lba, uintptr_t devAddr, u8* ramAddr, s32 bytesRemaining);
s32 AudioLoad_DiskLoad(AudioDiskInfo* diskInfo);
void func_80738B84(unk_807C1948* arg0);

void func_80738944(void);
void func_80739EE0(void);

void Audio_Reset(u8 playerIndex);
void func_8074184C(u8 playerIndex);
void Audio_SEStart(u8 channelIndex, u8 ioData);
void Audio_StopChannelSE(u8 channelIndex);
void Audio_DisablePlayerSE(void);

void func_80704CE0(void);
void func_80706518(s32, s32, char*);
void func_80707B08(void);
s32 func_80707780(void);
void SLMFSNewDisk(void);
void SLMFSNewDisk2(void);
void SLMFSDeleteFile(u16 dirId, char* name, char* extension, bool writeChanges);
void SLMFSRecoverManageArea(void);
s32 SLLeoReadDiskID(LEODiskID* diskId);

s32 DiskDrive_LoadOverlay(s32 startLba, void* vram, s32 diskSize, s32 bssSize);

#endif
#endif // EK_FUNCTIONS_H
