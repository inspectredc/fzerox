#include "global.h"
#include "fzxthread.h"

void func_80076490(void) {
}

extern OSMesgQueue D_800DCA68;
extern OSIoMesg D_800DCCA8;
extern OSPiHandle* D_800DCCDC;

void func_80076498(u32 arg0, u32 arg1, u32 arg2) {
    OSMesg sp1C[7];

    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(arg1);
    D_800DCCA8.devAddr = arg0;
    D_800DCCA8.size = arg2;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, sp1C);
}

void func_80076528(u32 arg0, u32 arg1, u32 arg2, void* arg3, s32 arg4) {
    OSMesg sp24[7];

    D_800DCCA8.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800DCCA8.hdr.retQueue = &D_800DCA68;
    D_800DCCA8.dramAddr = osPhysicalToVirtual(arg1);
    D_800DCCA8.devAddr = arg0;
    D_800DCCA8.size = arg2;
    D_800DCCDC->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCDC, &D_800DCCA8, OS_READ);
    bzero(arg3, arg4);
    MQ_WAIT_FOR_MESG(&D_800DCA68, sp24);
}

void func_800765CC(u8* arg0, u8* arg1, u32 arg2) {
    s32 temp_a2;
    s32 i;
    s32 temp_s3;

    temp_s3 = arg2 >> 0xA;

    for (i = 0; i < temp_s3; i++) {
        func_80076498(arg0, arg1, 0x400);

        arg0 += 0x400;
        arg1 += 0x400;
    }
    temp_a2 = arg2 & 0x3FF;
    if (temp_a2) {
        func_80076498(arg0, arg1, temp_a2);
    }
}

void func_80076658(u8* arg0, u8* arg1, size_t arg2, void* arg3, size_t arg4) {
    s32 temp_a2;
    s32 i;
    s32 temp_s3;

    temp_s3 = arg2 >> 0xA;

    for (i = 0; i < temp_s3; i++) {
        func_80076498(arg0, arg1, 0x400);

        arg0 += 0x400;
        arg1 += 0x400;
    }
    temp_a2 = arg2 & 0x3FF;
    if (temp_a2 != 0) {
        func_80076528(arg0, arg1, temp_a2, arg3, arg4);
    }
}

// https://decomp.me/scratch/S5I3s matching but symbols are wrong
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_800766F0.s")

extern u32 D_800E33C0[];
extern s32 D_80115FC0;
extern s32 D_8024DC80;

void func_80076804(void) {
    D_800E33C0[0] = ALIGN16((u32) &D_80115FC0);
    D_800E33C0[1] = 0x803DA800;
    D_800E33C0[2] = ALIGN16((u32) &D_8024DC80);
}

extern u32 D_800E33D0[];

void func_80076848(void) {
    D_800E33D0[0] = 0x801D9800;
    D_800E33D0[1] = 0x803DA800;
    D_800E33D0[2] = ALIGN16((u32) &D_8024DC80);
}

s32 func_80076884(s32 arg0, u32 arg1) {
    s32 ret = D_800E33C0[arg0];
    arg1 = ALIGN16(arg1);

    D_800E33C0[arg0] += arg1;
    return ret;
}

s32 func_800768B0(s32 arg0, s32 arg1) {
    s32 temp = D_800E33C0[arg0];
    return temp;
}

s32 func_800768C8(s32 arg0, u32 arg1) {

    arg1 = ALIGN16(arg1);

    D_800E33D0[arg0] -= arg1;
    return D_800E33D0[arg0];
}

u8* func_800768F4(s32, s32);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_800768F4.s")

extern u32 D_800E3380[];

s32 func_80076B80(s32 arg0, s32 arg1) {
    D_800E3380[arg0] = arg1 & 0x1FFFFFFF;
    return D_800E3380[arg0];
}

s32 func_80076BA0(s32 arg0, s32 arg1) {
    D_800E3380[arg0] = arg1;
    return arg1;
}

s32 func_80076BB8(s32 arg0) {
    return D_800E3380[arg0] | 0x80000000;
}

s32 func_80076BD4(uintptr_t arg0) {
    return (D_800E3380[(u32) (arg0 * 0x10) >> 0x1C] + (arg0 & 0xFFFFFF)) | 0x80000000;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80076C08.s")

// https://decomp.me/scratch/yuyPZ matches but uses fake hack for symbols
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80076CB8.s")

// https://decomp.me/scratch/bE19n matches but uses fake hack for symbols
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80076E10.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80076F00.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80076FC0.s")

// https://decomp.me/scratch/RFvOY matches but uses fake hack for symbols
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80077084.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_8007712C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80077318.s")

void func_80077630(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80077630.s")

extern u8 D_145B70[];
extern u8 D_1E23F0[];
extern u8 D_7000000[];
extern u8 D_700DA40[];
extern u8 D_7048CB0[];
extern s8 D_800CD2E4;
extern u32 D_800DCDCC;
extern s32 D_800DCE44;

void func_80077810(void) {
    s32 pad[2];
    u8* sp1C;
    size_t sp18;

    if (D_800CD2E4 != 0) {
        switch (D_800DCE44) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 14:
            case 21:
                sp1C = D_1E23F0;
                sp18 = D_7048CB0 - D_7000000;
                break;
            case 13:
            case 16:
                sp1C = D_145B70;
                sp18 = D_700DA40 - D_7000000;
                break;
            default:
                D_800CD2E4 = 0;
                return;
        }
        osInvalDCache(osPhysicalToVirtual(D_800DCDCC), sp18);
        func_800765CC(sp1C, osPhysicalToVirtual(D_800DCDCC), sp18);
        D_800CD2E4 = 0;
    }
}

void func_800778F8(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_800778F8.s")

void func_800779D0(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_800779D0.s")

extern s8 D_800CD2F0;

void func_80077AD8(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0xA) && (D_800CD2F0 < 0)) {
        D_800CD2F0 = arg0;
    }
}

void func_80077B04(void);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/10490/func_80077B04.s")

void func_800AA620(u8*, void*);

extern u8 D_2738A0[];
extern u8 D_5000000[];
extern u8 D_5000F50[];

extern s8 D_800CD2F4;
extern u32 D_800DCDE4;
extern s32 D_800DCE44;

void func_80077BE0(void) {
    s32 pad[3];
    s32 sp1C;
    u8* sp24;

    if (D_800CD2F4 != 0) {
        if (D_800DCE44 != 0x11) {
            D_800CD2F4 = 0;
            return;
        }
        sp1C = D_5000F50 - D_5000000;

        sp24 = func_800768F4(1, sp1C);

        osInvalDCache(sp24, sp1C);
        func_800765CC(D_2738A0, sp24, sp1C);
        if (*(s32*) sp24 == (s32) 'MIO0') {
            func_800AA620(sp24, osPhysicalToVirtual(D_800DCDE4));
        }
        D_800CD2F4 = 0;
    }
}

void func_80077C9C(void) {
    func_80077630();
    func_80077810();
    func_800778F8();
    func_800779D0();
    func_80077B04();
    func_80077BE0();
}
