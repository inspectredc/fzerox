#include "global.h"
#include "fzxthread.h"
#include "audio.h"

extern s32 D_800D8430;
extern OSThread D_800DC030;
extern OSMesgQueue D_800DCAF8;
extern void* D_800DCC80;

void func_800678B8(void*);
void func_80067A10(void*);

void func_80067060(void) {
    osInitialize();
    osCreateMesgQueue(&D_800DCAF8, &D_800DCC80, 1);
    osSetEventMesg(0xEU, &D_800DCAF8, (void*) 0x1B);
    osCreateThread(&D_800DC030, 1, func_800678B8, NULL, &D_800D8430, 0x64);
    osStartThread(&D_800DC030);
}

s32 D_800CCFA0 = 0;
s32 D_800CCFA4 = 0;

void func_800670E8(void) {
    osSpTaskYield();
    D_800CCFA0 = 1;
    D_800CCFA4 = 1;
}

extern OSTask* D_800DCCC4;

void func_80067118(void) {
    osSpTaskLoad(D_800DCCC4);
    osSpTaskStartGo(D_800DCCC4);
    D_800CCFA0 = 2;
    D_800CCFA4 = 1;
}

extern OSTask* D_800DCCC0;

void func_8006715C(void) {
    osDpSetStatus(0x3C0);
    osSpTaskLoad(D_800DCCC0);
    osSpTaskStartGo(D_800DCCC0);
    D_800CCFA0 = 3;
    D_800CCFA4 = 1;
}

void func_800671A8(void) {
    osSpTaskLoad(D_800DCCC0);
    osSpTaskStartGo(D_800DCCC0);
    D_800CCFA0 = 3;
    D_800CCFA4 = 1;
}

extern FrameBuffer* D_800DCCD0[];

// Segments
extern u8 D_72120[];
extern u8 D_98080[];
extern u8 D_80428F70[];
extern u8 D_8042BC40[];
extern u8 D_80403010[];

extern OSMesgQueue D_800DCA68;
extern OSMesgQueue D_800DCA80;
extern OSMesgQueue D_800DCA98;
extern OSMesgQueue D_800DCAB0;
extern OSMesgQueue D_800DCAC8;
extern OSMesgQueue D_800DCAE0;
extern OSMesgQueue D_800DCB10;
extern OSMesg D_800DCC28;
extern OSMesg D_800DCC2C;
extern OSMesg D_800DCC30;
extern OSMesg D_800DCC34;
extern OSMesg D_800DCC38;
extern OSMesg D_800DCC40;
extern OSMesg D_800DCC84;
extern OSThread D_800DC390;
extern OSThread D_800DC540;
extern OSThread D_800DC6F0;

s32 D_800CCFA8 = 0;
s32 D_800CCFAC = 0;
s32 D_800CCFB0 = 1;
s32 D_800CCFB4 = 0;
s32 D_800CCFB8 = 1;
s32 D_800CCFBC = 1;
s32 D_800CCFC0 = 0;
s32 D_800CCFC4 = 0;
s8 D_800CCFC8 = 1;
s8 D_800CCFCC = 1;
s8 D_800CCFD0 = 1;
s8 D_800CCFD4 = 1;

extern s32 D_800DCCC8;
extern bool D_800DCCCC;

extern u32 D_800D9830;
extern u32 D_800DA030;
extern u32 D_800DB230;

void func_80069F5C(FrameBuffer*);

void func_800671EC(void* arg0) {
    OSMesg msg;
    s32 var_a0;
    u64* var_v1;
    s32 i;

    osCreateMesgQueue(&D_800DCA68, &D_800DCC28, 1);
    osCreateMesgQueue(&D_800DCA98, &D_800DCC30, 1);
    osCreateMesgQueue(&D_800DCAB0, &D_800DCC34, 1);
    osCreateMesgQueue(&D_800DCAC8, &D_800DCC38, 1);
    osCreateMesgQueue(&D_800DCAE0, &D_800DCC40, 0x10);
    osCreateMesgQueue(&D_800DCA80, &D_800DCC2C, 1);
    osCreateMesgQueue(&D_800DCB10, &D_800DCC84, 1);
    osSetEventMesg(5, &D_800DCA80, (OSMesg) 0xB);
    osSetEventMesg(4, &D_800DCAE0, (OSMesg) 0x18);
    osSetEventMesg(9, &D_800DCAE0, (OSMesg) 0x19);
    osViSetEvent(&D_800DCAE0, (OSMesg) 0x1A, 1U);
    D_800DCCC8 = 0;
    D_800DCCCC = func_800CC220();
    var_v1 = (u64*) D_800DCCD0[0];

    // clang-format off
    for (var_a0 = 0; var_a0 < (SCREEN_WIDTH * SCREEN_HEIGHT) / 4; var_a0++) {\
        var_v1[var_a0] = 1;
    }
    // clang-format on

    func_80069F5C(D_800DCCD0[1]);
    func_80069F5C(D_800DCCD0[2]);
    osViSwapBuffer(D_800DCCD0[0]);

    while (osViGetCurrentFramebuffer() != D_800DCCD0[0]) {}

    osViBlack(0);

    if (osAppNMIBuffer[15] != 0x20DE1529) {
        if (osGetMemSize() >= 0x800000) {
            D_800CCFC0 = 1;
        } else {
            D_800CCFC0 = 0;
        }
        osAppNMIBuffer[14] = D_800CCFC0;
    } else {
        D_800CCFC0 = osAppNMIBuffer[14];
    }

    if (D_800CCFC0 != 0) {
        func_80073E28(SEGMENT_ROM_START(leo), SEGMENT_VRAM_START(leo), SEGMENT_ROM_SIZE(leo));
        bzero(SEGMENT_BSS_START(leo), SEGMENT_BSS_SIZE(leo));
        if (D_800DCCCC) {
            func_8007F904();
        }
        func_800751FC("EFZE");
        if (D_800DCCCC) {
            func_80076340();
        }
    }

    osCreateThread(&D_800DC6F0, 7, func_80067A10, NULL, &D_800DB230, 100);
    osStartThread(&D_800DC6F0);

    if ((D_800CCFC0 != 0) && D_800DCCCC) {
        func_800763A8();
    }
    if ((D_800CCFC0 != 0) && D_800DCCCC && (func_800761D4() == 2)) {
        func_8007515C();
    }
    osViSwapBuffer(D_800DCCD0[1]);

    while (osViGetCurrentFramebuffer() != D_800DCCD0[1]) {}

    func_80069F5C(D_800DCCD0[0]);
    osViSwapBuffer(D_800DCCD0[0]);

    while (osViGetCurrentFramebuffer() != D_800DCCD0[0]) {}

    osViBlack(0);

    if ((D_800CCFC0 != 0) && D_800DCCCC) {
        func_8007F904();
    }
    func_80075230(&D_800DC540);
    // Audio Thread
    osCreateThread(&D_800DC390, 4, func_80068A60, NULL, &D_800DA030, 20);
    if (D_800CCFD0 != 0) {
        osStartThread(&D_800DC390);
    }
    D_800CCFC4 = 1;
    osCreateThread(&D_800DC540, 5, func_80068008, NULL, &D_800D9830, 10);
    if (D_800CCFCC != 0) {
        osStartThread(&D_800DC540);
    }

    while (1) {
        osRecvMesg(&D_800DCAE0, &msg, 1);
        if (msg == (OSMesg) 0x18) {
            switch (D_800CCFA0) {
                case 1:
                    if (osSpTaskYielded(D_800DCCC0)) {
                        D_800CCFA8 = 1;
                    }
                    func_80067118();
                    break;
                case 2:
                    if (D_800CCFA8 != 0) {
                        D_800CCFA8 = 0;
                        func_800671A8();
                    } else if (D_800CCFAC != 0) {
                        D_800CCFAC = 0;
                        func_8006715C();
                    } else {
                        D_800CCFA0 = 0;
                        D_800CCFA4 = 0;
                    }
                    break;
                case 3:
                    D_800CCFA0 = 0;
                    D_800CCFA4 = 0;
                    break;
            }
        } else if (msg == (OSMesg) 0x1A) {
            osSendMesg(&D_800DCA98, (OSMesg) 0x1F, 0);
            if ((++D_800CCFB0 - D_800CCFB4) >= D_800CCFB8) {
                D_800CCFB4 = D_800CCFB0;
                D_800CCFB8 = D_800CCFBC;
                osSendMesg(&D_800DCAB0, (OSMesg) 0x29, 0);
            }
        } else if (msg == (OSMesg) 0x16) {
            osWritebackDCacheAll();
            if (D_800CCFA4 != 0) {
                if (D_800CCFA0 != 1) {
                    func_800670E8();
                }
            } else {
                func_80067118();
            }
        } else if ((msg == (OSMesg) 0x15) && (D_800DCCC8 == 0)) {
            osWritebackDCacheAll();
            if (D_800CCFA4 != 0) {
                D_800CCFAC = 1;
            } else {
                func_8006715C();
            }
        } else if (msg == (OSMesg) 0x19) {
            osSendMesg(&D_800DCAC8, (OSMesg) 0x2A, 0);
        }
    }
}

extern s8 D_800CCFC8;
extern OSViMode D_800D1DA0;
extern OSViMode D_800D2660;
extern s32 D_800D8830;
extern OSThread D_800DC1E0;
extern OSMesgQueue D_800DCA50;
extern void* D_800DCB28;
extern OSPiHandle* D_800DCCDC;
extern OSPiHandle* D_800DCCE0;
extern FrameBuffer D_801D9800;
extern FrameBuffer D_80200000;
extern FrameBuffer D_803DA800;

void func_800678B8(void* arg0) {
    D_800DCCD0[0] = &D_801D9800;
    D_800DCCD0[1] = &D_80200000;
    D_800DCCD0[2] = &D_803DA800;
    osCreateViManager(0xFE);
    if (osTvType == 1) {
        osViSetMode(&D_800D1DA0);
    } else {
        osViSetMode(&D_800D2660);
    }
    osViSetSpecialFeatures(2);
    osViSetSpecialFeatures(8);
    osViSetSpecialFeatures(0x20);
    osViSetSpecialFeatures(0x80);
    osViBlack(1);
    osCreatePiManager(0x96, &D_800DCA50, &D_800DCB28, 0x40);
    D_800DCCDC = osCartRomInit();
    D_800DCCE0 = osDriveRomInit();
    Fault_Init();
    Fault_SetFrameBuffer(&D_801D9800, 0x140, 0x10);
    osCreateThread(&D_800DC1E0, 3, func_800671EC, NULL, &D_800D8830, 0x63);
    if (D_800CCFC8 != 0) {
        osStartThread(&D_800DC1E0);
    }
    osSetThreadPri(NULL, 0);

    while (true) {}
}

void LeoReset(void);

void func_80067A10(void* arg0) {
    void* sp1C;

    MQ_WAIT_FOR_MESG(&D_800DCAF8, &sp1C);
    if ((D_800DCCC8 == 0) && (D_800CCFC4 != 0)) {
        func_800BA248();
    }
    D_800DCCC8 = 1;
    osViBlack(1);
    osViSetYScale(1.0f);
    if ((D_800CCFC0 != 0) && D_800DCCCC) {
        LeoReset();
    }
    func_80069700();

    while (true) {}
}
