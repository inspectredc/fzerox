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

#endif
#endif // EK_FUNCTIONS_H
