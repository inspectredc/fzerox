#include "global.h"
#include "fzx_thread.h"

FaultMgr gFaultMgr;

u8 sFaultCharIndex[0x80] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0x2B,
    0xFF, 0xFF, 0x25, 0x26, 0xFF, 0x2A, 0xFF, 0x27, 0x2C, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x24, 0xFF, 0xFF, 0xFF, 0xFF, 0x28, 0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14,
    0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A,
    0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

s32 sFaultCharPixelFlags[0x40] = {
    0x70871C30, 0x8988A250, 0x88808290, 0x88831C90, 0x888402F8, 0x88882210, 0x71CF9C10, 0xF9CF9C70,
    0x8228A288, 0xF200A288, 0x0BC11C78, 0x0A222208, 0x8A222288, 0x71C21C70, 0x23C738F8, 0x5228A480,
    0x8A282280, 0x8BC822F0, 0xFA282280, 0x8A28A480, 0x8BC738F8, 0xF9C89C08, 0x82288808, 0x82088808,
    0xF2EF8808, 0x82288888, 0x82288888, 0x81C89C70, 0x8A08A270, 0x920DA288, 0xA20AB288, 0xC20AAA88,
    0xA208A688, 0x9208A288, 0x8BE8A270, 0xF1CF1CF8, 0x8A28A220, 0x8A28A020, 0xF22F1C20, 0x82AA0220,
    0x82492220, 0x81A89C20, 0x8A28A288, 0x8A28A288, 0x8A289488, 0x8A2A8850, 0x894A9420, 0x894AA220,
    0x70852220, 0xF8011000, 0x08020800, 0x10840400, 0x20040470, 0x40840400, 0x80020800, 0xF8011000,
    0x70800000, 0x88822200, 0x08820400, 0x108F8800, 0x20821000, 0x00022200, 0x20800020, 0x00000000,
};

const char* sFaultCauses[] = {
    "Interrupt",
    "TLB modification",
    "TLB exception on load",
    "TLB exception on store",
    "Address error on load",
    "Address error on store",
    "Bus error on inst.",
    "Bus error on data",
    "System call exception",
    "Breakpoint exception",
    "Reserved instruction",
    "Coprocessor unusable",
    "Arithmetic overflow",
    "Trap exception",
    "Virtual coherency on inst.",
    "Floating point exception",
    "Watchpoint exception",
    "Virtual coherency on data",
};

const char* sFloatExceptions[6] = {
    "Unimplemented operation", "Invalid operation", "Division by zero", "Overflow", "Underflow", "Inexact operation",
};

void Fault_FillRectangle(s32 xPos, s32 yPos, s32 width, s32 height) {
    u16* pixel;
    s32 i;
    s32 j;

    pixel = gFaultMgr.width * yPos + gFaultMgr.fb->data + xPos;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++, pixel++) {
            *pixel = ((*pixel & 0xE738) >> 2) | 1;
        }
        pixel += gFaultMgr.width - width;
    }
}

void Fault_DisplayChar(s32 xPos, s32 yPos, s32 index) {
    s32* charPixelFlags;
    u16* pixel;
    s32 i;
    s32 j;

    charPixelFlags = &sFaultCharPixelFlags[(index / 5) * 7];
    pixel = gFaultMgr.width * yPos + gFaultMgr.fb->data + xPos;

    for (i = 0; i < 7; i++) {
        u32 bufferPixelFlag = 0x80000000 >> ((index % 5) * 6);
        u32 charPixelFlag = *charPixelFlags++;

        for (j = 0; j < 6; j++) {
            if (bufferPixelFlag & charPixelFlag) {
                *pixel = 0xFFFF;
            } else {
                *pixel = 0x0001;
            }
            pixel++;
            bufferPixelFlag >>= 1;
        }
        pixel += gFaultMgr.width - 6;
    }
}

char* Fault_PrOut(char* buffer, const char* fmt, size_t size) {
    return (char*) memcpy(buffer, fmt, size) + size;
}

void Fault_Printf(s32 xPos, s32 yPos, const char* fmt, ...) {
    s32 charRemaining;
    s8* charPtr;
    s32 charIndex;
    char buffer[0x100];
    va_list args;
    va_start(args, fmt);

    charRemaining = _Printf(Fault_PrOut, buffer, fmt, args);

    if (charRemaining > 0) {
        charPtr = (s8*) buffer;
        while (charRemaining > 0) {
            charIndex = sFaultCharIndex[(*charPtr & 0x7F)];
            if (charIndex != 0xFF) {
                Fault_DisplayChar(xPos, yPos, charIndex);
            }
            charRemaining--;
            charPtr++;
            xPos += 6;
        }
    }
    va_end(args);
}

void Fault_Wait(s32 msec) {
    u64 time = OS_MSEC_TO_CYCLES(msec);

    osSetTime(0);

    while (osGetTime() < time) {}
}

void Fault_DisplayFloatReg(s32 xPos, s32 yPos, s32 regNum, f32* regValue) {
    u32 regAsInt = *(u32*) regValue;
    s32 regExp = ((regAsInt & 0x7F800000) >> 0x17) - 0x7F;

    if (((-0x7F < regExp) && (regExp < 0x80)) || (regAsInt == 0)) {
        Fault_Printf(xPos, yPos, "F%02d:%.3e", regNum, *regValue);
    } else {
        Fault_Printf(xPos, yPos, "F%02d:---------", regNum);
    }
}

void Fault_DisplayFloatException(u32 exceptFlags) {
    s32 i;
    u32 flag = 0x20000;

    Fault_Printf(30, 155, "FPCSR:%08XH", exceptFlags);
    for (i = 0; i < 6; i++, flag >>= 1) {
        if (exceptFlags & flag) {
            Fault_Printf(132, 155, "(%s)", sFloatExceptions[i]);
            return;
        }
    }
}

extern OSMesgQueue gSerialEventQueue;
const u16 sCrashDebuggerInputs[] = { BTN_A, BTN_CUP,    BTN_CUP, BTN_B,      BTN_CRIGHT, BTN_CRIGHT,
                                     BTN_B, BTN_CRIGHT, BTN_B,   BTN_CRIGHT, BTN_START };
extern Controller gSharedController;
#define CAUSE_INDEX(cause) ((cause >> CAUSE_EXCSHIFT) & (CAUSE_EXCMASK >> CAUSE_EXCSHIFT))

void Fault_DisplayDebugInfo(OSThread* thread) {
    __OSThreadContext* context = &thread->context;
    s16 causeIndex = CAUSE_INDEX(context->cause);
    s32 i;

    if (causeIndex == CAUSE_INDEX(EXC_WATCH)) {
        causeIndex = 16;
    }
    if (causeIndex == CAUSE_INDEX(EXC_VCED)) {
        causeIndex = 17;
    }
    osWritebackDCacheAll();

    i = 0;

    while (true) {
        osContStartReadData(&gSerialEventQueue);
        Controller_UpdateInputs();
        if (gSharedController.buttonPressed == 0) {
            continue;
        }
        if (!(gSharedController.buttonCurrent & BTN_Z)) {
            continue;
        }
        if (!(gSharedController.buttonCurrent & BTN_L)) {
            continue;
        }
        i++;
        if (sCrashDebuggerInputs[i - 1] & gSharedController.buttonPressed) {
            if (i == 11) {
                break;
            }
        } else {
            i = 0;
        }
    }

    Fault_FillRectangle(25, 20, SCREEN_WIDTH - 50, 25);
    Fault_Printf(30, 25, "THREAD:%d  (%s)", thread->id, sFaultCauses[causeIndex]);
    Fault_Printf(30, 35, "PC:%08XH   SR:%08XH   VA:%08XH", context->pc, context->sr, context->badvaddr);
    Fault_Wait(2000);
    Fault_FillRectangle(25, 45, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 55);
    Fault_Printf(30, 50, "AT:%08XH   V0:%08XH   V1:%08XH", (s32) context->at, (s32) context->v0, (s32) context->v1);
    Fault_Printf(30, 60, "A0:%08XH   A1:%08XH   A2:%08XH", (s32) context->a0, (s32) context->a1, (s32) context->a2);
    Fault_Printf(30, 70, "A3:%08XH   T0:%08XH   T1:%08XH", (s32) context->a3, (s32) context->t0, (s32) context->t1);
    Fault_Printf(30, 80, "T2:%08XH   T3:%08XH   T4:%08XH", (s32) context->t2, (s32) context->t3, (s32) context->t4);
    Fault_Printf(30, 90, "T5:%08XH   T6:%08XH   T7:%08XH", (s32) context->t5, (s32) context->t6, (s32) context->t7);
    Fault_Printf(30, 100, "S0:%08XH   S1:%08XH   S2:%08XH", (s32) context->s0, (s32) context->s1, (s32) context->s2);
    Fault_Printf(30, 110, "S3:%08XH   S4:%08XH   S5:%08XH", (s32) context->s3, (s32) context->s4, (s32) context->s5);
    Fault_Printf(30, 120, "S6:%08XH   S7:%08XH   T8:%08XH", (s32) context->s6, (s32) context->s7, (s32) context->t8);
    Fault_Printf(30, 130, "T9:%08XH   GP:%08XH   SP:%08XH", (s32) context->t9, (s32) context->gp, (s32) context->sp);
    Fault_Printf(30, 140, "S8:%08XH   RA:%08XH", (s32) context->s8, (s32) context->ra);
    Fault_DisplayFloatException(context->fpcsr);

    Fault_DisplayFloatReg(30, 170, 0, &context->fp0.f.f_even);
    Fault_DisplayFloatReg(120, 170, 2, &context->fp2.f.f_even);
    Fault_DisplayFloatReg(210, 170, 4, &context->fp4.f.f_even);
    Fault_DisplayFloatReg(30, 180, 6, &context->fp6.f.f_even);
    Fault_DisplayFloatReg(120, 180, 8, &context->fp8.f.f_even);
    Fault_DisplayFloatReg(210, 180, 10, &context->fp10.f.f_even);
    Fault_DisplayFloatReg(30, 190, 12, &context->fp12.f.f_even);
    Fault_DisplayFloatReg(120, 190, 14, &context->fp14.f.f_even);
    Fault_DisplayFloatReg(210, 190, 16, &context->fp16.f.f_even);
    Fault_DisplayFloatReg(30, 200, 18, &context->fp18.f.f_even);
    Fault_DisplayFloatReg(120, 200, 20, &context->fp20.f.f_even);
    Fault_DisplayFloatReg(210, 200, 22, &context->fp22.f.f_even);
    Fault_DisplayFloatReg(30, 210, 24, &context->fp24.f.f_even);
    Fault_DisplayFloatReg(120, 210, 26, &context->fp26.f.f_even);
    Fault_DisplayFloatReg(210, 210, 28, &context->fp28.f.f_even);
    Fault_DisplayFloatReg(30, 220, 30, &context->fp30.f.f_even);

    osViBlack(false);

    osViSwapBuffer(gFaultMgr.fb);
}

OSThread* func_80080884(void) {
    OSThread* queue = __osGetActiveQueue();

    while (queue->priority != -1) {
        if ((queue->priority > 0) && (queue->priority < 0x7F) && (queue->flags & 3)) {
            return queue;
        }
        queue = queue->tlnext;
    }
    return NULL;
}

void Fault_ThreadEntry(void* arg) {
    OSMesg dummy;
    OSThread* faultedThread;

    osSetEventMesg(OS_EVENT_CPU_BREAK, &gFaultMgr.mesgQueue, (OSMesg) 1);
    osSetEventMesg(OS_EVENT_FAULT, &gFaultMgr.mesgQueue, (OSMesg) 2);

    faultedThread = NULL;
    while (faultedThread == NULL) {
        MQ_WAIT_FOR_MESG(&gFaultMgr.mesgQueue, &dummy);
        faultedThread = func_80080884();
    }
    Fault_DisplayDebugInfo(faultedThread);
    while (true) {}
}

void Fault_SetFrameBuffer(FrameBuffer* buffer, u16 width, u16 height) {
    gFaultMgr.fb = PHYS_TO_K1(buffer);
    gFaultMgr.width = width;
    gFaultMgr.height = height;
}

void Fault_Init(void) {
    gFaultMgr.fb = (FrameBuffer*) (PHYS_TO_K1(osMemSize) - sizeof(FrameBuffer));
    gFaultMgr.width = SCREEN_WIDTH;
    gFaultMgr.height = 16;
    osCreateMesgQueue(&gFaultMgr.mesgQueue, &gFaultMgr.msg, 1);
    osCreateThread(&gFaultMgr.thread, THREAD_ID_FAULT, Fault_ThreadEntry, NULL,
                   gFaultMgr.stack + sizeof(gFaultMgr.stack), 250);
    osStartThread(&gFaultMgr.thread);
}
