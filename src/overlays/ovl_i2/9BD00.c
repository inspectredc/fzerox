#include "global.h"

void func_i2_80103728(s32, size_t, void*, size_t);
extern u8 D_801247C0[];
extern u8 D_80127B80[];
extern u8 D_80127BC0[];
extern u8 D_8012C740[];

void func_i2_801003B0(void* arg0) {
    func_i2_80103728(0, D_80127B80 - D_801247C0, arg0, 0x40);
}

extern u8 D_80127BC0[];

void func_i2_801003EC(void* arg0) {
    func_i2_80103728(0, D_80127BC0 - D_801247C0, arg0, 0x3F80);
}

void func_i2_80100428(void* arg0, s32 arg1) {
    func_i2_80103728(0, &D_801247C0[arg1 * 128] - D_801247C0 + 0x7380, arg0, 0x80);
}

void func_i2_8010046C(void* arg0) {
    func_i2_80103728(0, D_8012C740 - D_801247C0, arg0, 0x60);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801004A8.s")

extern unk_800E5FF8 D_800E5FF8[];
extern u32 D_800CD3CC;

s32 func_i2_80100810(s32, s32);
s32 func_i2_8010387C(s32);

s32 func_i2_80100520(s32 arg0) {
    s32 i;
    s32 sp18;
    s32 temp_a1 = D_802A6B40[arg0].unk_00;
    unk_800E5FF8* var_v0 = D_800E5FF8;

    for (i = 0; i < 3; i++) {
        if (temp_a1 != var_v0->unk_0000) {
            var_v0->unk_0000 = 0;
        }
        var_v0++;
    }
    switch (D_800CD3CC) {
        case 3:
        case 4:
            break;
        case 0:
        case 1:
            sp18 = func_i2_80100810(arg0, -1);
            break;
        case 2:
            sp18 = func_i2_8010387C(arg0);
            break;
    }
    return sp18;
}

s32 func_i2_801005CC(s32 arg0) {
    s32 i;
    s32 var_a0;
    s32 var_v1;
    unk_800E5FF8* var_a1;

    var_v1 = -1;

    for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
        if (var_a1->unk_0000 == 0) {
            var_v1 = i;
            break;
        }
    }

    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
        if (var_a1->unk_3F68 != 1) {
            var_v1 = i;
            break;
        }
    }

    var_a0 = -1;
    if (var_v1 != -1) {
        return var_v1;
    }

    for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
        if (arg0 != (var_a1->unk_0000 % 32)) {
            var_v1 = i;
            var_a0 = var_a1->unk_0004;
            break;
        }
    }

    if (var_a0 != -1) {
        for (i = var_v1 + 1, var_a1 = &D_800E5FF8[i]; i < 3; i++, var_a1++) {
            if (arg0 != (var_a1->unk_0000 % 32)) {
                if (var_a0 < var_a1->unk_0004) {
                    var_a0 = var_a1->unk_0004;
                    var_v1 = i;
                }
            }
        }
    } else {
        for (i = 0, var_a1 = D_800E5FF8; i < 3; i++, var_a1++) {
            if (arg0 == (var_a1->unk_0000 % 32)) {
                if (var_a0 < var_a1->unk_0004) {
                    var_a0 = var_a1->unk_0004;
                    var_v1 = i;
                }
            }
        }
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100810.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100950.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100B38.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100C18.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100C60.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100C9C.s")

void func_i2_80100DDC(u8* arg0, s32 arg1, u16 arg2);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100DDC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100E64.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100ED4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100F7C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80100FEC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101034.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010107C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801010D0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101118.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801011FC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801012CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101310.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101414.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801014D4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101590.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101690.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801016DC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101784.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801017B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801018A8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101944.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101B8C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101C04.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101C78.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101CCC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101D18.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101DE8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101E68.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101EBC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101F24.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101F9C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80101FEC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102110.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801021B4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102214.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102350.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801023D8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801024F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010259C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102600.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102784.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102A7C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102B20.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102CA4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80102F70.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010300C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103108.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103310.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801033B8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801034F8.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010356C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010358C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801035B0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801035E4.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103608.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010362C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103650.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103674.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103698.s")

extern OSMesgQueue D_800DCA68;
extern OSIoMesg D_i2_801117B0;
extern OSPiHandle* D_i2_8011183C;

void func_i2_80103728(s32 arg0, size_t arg1, void* arg2, size_t arg3) {
    osWritebackDCache(arg2, arg3);
    osInvalDCache(osPhysicalToVirtual((uintptr_t) arg2), arg3);
    D_i2_801117B0.hdr.pri = 0;
    D_i2_801117B0.hdr.retQueue = &D_800DCA68;
    D_i2_801117B0.dramAddr = arg2;
    D_i2_801117B0.devAddr = arg1 + 0x08000000;
    D_i2_801117B0.size = arg3;
    osEPiStartDma(D_i2_8011183C, &D_i2_801117B0, arg0);
    osRecvMesg(&D_800DCA68, NULL, OS_MESG_BLOCK);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_801037CC.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010382C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_8010387C.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/func_i2_80103930.s")

extern u8 D_i2_8010ADE8[];
extern u8 D_i2_8010D7F0[];

void func_i2_801039BC(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            D_i2_8010D7F0[i * 0x19E0 + j] = D_i2_8010ADE8[j];
            func_i2_80100DDC(D_i2_8010D7F0, i, 0x1234);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/D_i2_8010ADE0.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i2/9BD00/D_i2_8010ADE8.s")
