#include "global.h"
#include "fzxthread.h"

extern FaultMgr gFaultMgr;

extern u8 sFaultCharIndex[];
extern s32 sFaultCharPixelFlags[];

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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D48B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D48BC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D48D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D48E8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4900.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4918.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4930.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4944.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4958.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4970.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4988.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D49A0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D49B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D49CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D49DC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D49F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A14.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A2C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A48.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A60.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A74.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A88.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4A94.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4AA0.s")

void Fault_DisplayFloatReg(s32 xPos, s32 yPos, s32 regNum, f32* regValue) {
    u32 regAsInt = *(u32*) regValue;
    s32 regExp = ((regAsInt & 0x7F800000) >> 0x17) - 0x7F;

    if (((-0x7F < regExp) && (regExp < 0x80)) || (regAsInt == 0)) {
        Fault_Printf(xPos, yPos, "F%02d:%.3e", regNum, *regValue);
    } else {
        Fault_Printf(xPos, yPos, "F%02d:---------", regNum);
    }
}

extern const char* sFloatExceptions[];

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

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/D_800D4AE4.s")

void Fault_DisplayDebugInfo(OSThread* thread);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/sys_fault/Fault_DisplayDebugInfo.s")

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
    osCreateThread(&gFaultMgr.thread, 2, Fault_ThreadEntry, 0, gFaultMgr.stack + sizeof(gFaultMgr.stack), 250);
    osStartThread(&gFaultMgr.thread);
}
