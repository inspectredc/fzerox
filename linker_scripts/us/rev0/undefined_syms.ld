leoBootID = 0x800001A0;

// AUDIO
gAudioBufferParams = 0x8002AA20;
gAudioSoundMode = 0x8002AA56;
gNumNotes = 0x8002AA50;
gNotes = 0x800268BC;
gNoteFreeLists = 0x80028EA8; //size:0x40
gMiscPool = 0x80025D98;
gLayerFreeList = 0x80028E98;
gSeqChannelNone = 0x80028DD8;
gFontCache = 0x80025F08;
gSeqLayers = 0x80026CD8;
gMaxTempo = 0x8002AA54;
gSynthesisReverbs = 0x80025C10;
gAudioRandom = 0x8002AB34;
gSoundFontList = 0x8002AA18;
gSeqFontTable = 0x8002AA10;
gSeqPlayers = 0x800268C0;
gCurAudioFrameDmaQueue = 0x8002A0A0;
gCurAudioFrameDmaIoMsgBuf = 0x8002A1B8;
gSampleDmas = 0x8002A7F0;
gSampleDmaCount = 0x8002A7F4;
gSampleDmaListSize1 = 0x8002A7F8;
gSampleDmaReuseQueue1 = 0x8002A800;
gSampleDmaReuseQueue2 = 0x8002A900;
gSampleDmaReuseQueue1RdPos = 0x8002AA00;
gSampleDmaReuseQueue2RdPos = 0x8002AA01;
gSampleDmaReuseQueue1WrPos = 0x8002AA02;
gSampleDmaReuseQueue2WrPos = 0x8002AA03;
gCurAudioFrameDmaCount = 0x8002AA5C;
gSampleDmaBufSize = 0x8002AA48;
gExternalPool = 0x80025D78;
gFontLoadStatus = 0x80026850;
gSeqLoadStatus = 0x80026880;
gSampleFontLoadStatus = 0x80026820;
gSequenceTable = 0x8002AA04;
gSoundFontTable = 0x8002AA08;
gSampleBankTable = 0x8002AA0C;
gResetTimer = 0x8002AB3C;
gSyncDmaQueue = 0x8002A7B8;
gSyncDmaMsg = 0x8002A7D0;
gSyncDmaIoMsg = 0x8002A7D8;
gInitPool = 0x80025D88;
gPermanentCache = 0x80026128;
gResetStatus = 0x800268B0;
gSpecId = 0x800268B1;
gNumSequences = 0x8002AA14;
gAiBuffers = 0x8002AB20;
gAiBufLengths = 0x8002AB2C;
gExternalLoadQueue = 0x8002A030;
gExternalLoadMsgBuf = 0x8002A048;
gPreloadSampleQueue = 0x8002A068;
gPreloadSampleMsgBuf = 0x8002A080;
gCurAudioFrameDmaQueue = 0x8002A0A0;
gCurAudioFrameDmaMsgBuf = 0x8002A0B8;
gTotalTaskCount = 0x8002AA58;
gRspTaskIndex = 0x8002AA60;
gCurAiBufIndex = 0x8002AA64;
gSoundMode = 0x8002AA56;
gCurTask = 0x8002AA74;
gRspTask = 0x8002AA78;
gMaxTempoTvTypeFactors = 0x8002AB18;
gRefreshRate = 0x8002AB1C;
gAsyncLoads = 0x80029AF0;
gUsedSamples = 0x80028EE8;
gNumUsedSamples = 0x80029AE8;
gPreloadSampleStackTop = 0x80029AEC;
gPreloadSampleStack = 0x800290E8;
gAdsrDecayTable = 0x800268B8;
gAudioHeap = 0x8002B400;
gSessionPool = 0x80025D68;
gCachePool = 0x80025DC8;
gPersistentCommonPool = 0x80025DD8;
gTemporaryCommonPool = 0x80025DE8;
gSeqCache = 0x80025DF8;
gSampleBankCache = 0x80026018;
gNumSynthReverbs = 0x80025D53;
gSynthReverbs = 0x80025C10;
gResetFadeoutFramesLeft = 0x800268B4;
gMaxAudioCmds = 0x8002AA4C;
gSessionPoolSplit = 0x800267E8;
gCachePoolSplit = 0x800267F8;
gPersistentCommonPoolSplit = 0x80026800;
gTemporaryCommonPoolSplit = 0x80026810;
gNoteSubsEu = 0x80025D64;
gAbiCmdBuffs = 0x8002AA68;
gPersistentSampleCache = 0x800262B8;
gTemporarySampleCache = 0x80026550;
gCurLoadedBook = 0x80025D60;
gUseReverb = 0x80025D52;
gThreadCmdBuffer = 0x8002AB40;
gThreadCmdChannelMask = 0x8002B340;
gThreadCmdWritePos = 0x8002B346;
gThreadCmdReadPos = 0x8002B347;
gThreadCmdQueueFinished = 0x8002B348;
sAudioTaskStartMsg = 0x8002B34C;
sAudioTaskStartQueue = 0x8002B350;
gAudioTaskStartQueue = 0x8002B368;
sThreadCmdProcMsg = 0x8002B370;
sThreadCmdProcQueue = 0x8002B380;
gThreadCmdProcQueue = 0x8002B398;
sAudioResetMsg = 0x8002B39C;
sAudioResetQueue = 0x8002B3A0;
gAudioResetQueue = 0x8002B3B8;
gAudioTaskCountQ = 0x8002AA58;
gAudioTaskIndexQ = 0x8002AA60;
gCurAbiCmdBuffer = 0x8002AA70;
gAudioCurTask = 0x8002AA74;
gAudioRspTasks = 0x8002AA78;
gSequenceChannelNone = 0x80028DD8;

gAudioCtxStart = 0x80025C00;
gAudioCtxEnd = 0x8002B3C0;

// before buffers
D_8025DCE8 = 0x8025DCE8;

// OVERLAYS/SEGMENTS SPLITS
// ovl 11
D_800FC730 = 0x800FC730;
D_800FCB70_2 = 0x800FCB70;

// ovl 9
D_i9_80168A70 = 0x80168A70;
D_i9_80168CD0 = 0x80168CD0;
D_i9_80168CE0 = 0x80168CE0;
D_i9_80115DF0 = 0x80115DF0;

// before buffers
D_802D5C40 = 0x802D5C40;
D_802A6B40_2 = 0x802A6B40;
D_802A6B40_3 = 0x802A6B40;