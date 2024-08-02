#include "global.h"
#include "fzxthread.h"

s32 func_80403040(s32*, s32*, s32*, s32*);
extern OSMesgQueue D_800DCA68;
extern OSPiHandle* D_800DCCE0;
extern OSIoMesg D_800E4330;

typedef struct unk_8007F86C_arg_1 {
    s8 pad[0x80];
} unk_8007F86C_arg_1;

void func_8007F7D0(s32* arg0, unk_8007F86C_arg_1* arg1, s32* arg2, s32* arg3, s32* arg4) {
    u32 temp_t8 = func_80403040(arg0, arg2, arg3, arg4) + 0xA0000;

    D_800E4330.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800E4330.hdr.retQueue = &D_800DCA68;
    D_800E4330.dramAddr = arg1;
    D_800E4330.devAddr = temp_t8;
    D_800E4330.size = 0x80;
    D_800DCCE0->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCE0, &D_800E4330, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, NULL);
}

void func_8007F86C(s32* arg0, unk_8007F86C_arg_1* arg1, s32* arg2, s32* arg3, s32* arg4);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/197D0/func_8007F86C.s")

extern s32 D_800CD520;
extern s32 D_800E4350;
extern s32 D_800E44D0;
extern s32 D_800E4650;
extern unk_8007F86C_arg_1 D_80400008;

void func_8007F904(void) {
    func_8007F86C(&D_800CD520, &D_80400008, &D_800E4350, &D_800E44D0, &D_800E4650);
}

extern s16* D_800E4348;

void func_8007F94C(void) {
    D_800E4348 = osViGetNextFramebuffer();
}

extern s16* D_800E434C;

void func_8007F970(void) {
    u8 i;
    u16 j;

    for (i = 75; i < 191; i++) {
        for (j = 22; j < 298; j++) {
            D_800E434C = (i * 320) + &D_800E4348[j];
            *D_800E434C = 1;
        }
    }
}

void func_800751C0(void);
extern FrameBuffer* D_800DCCD0[];

void func_8007F9E0(void) {
    u8 i;
    u64* temp_v1;
    u64* var_v0;

    func_800751C0();

    for (i = 0; i < 3; i++) {
        temp_v1 = (u64*) D_800DCCD0[i];
        var_v0 = &temp_v1[19199];

        // FAKE
        while (var_v0 >= temp_v1) {
            var_v0--;
            var_v0[1] = 0x0001000100010001;
        }
    }

    func_800751C0();
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/197D0/func_8007FA64.s")

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/game/197D0/func_8007FB80.s")

void func_8007FB80(s32, s32, char*);

void func_8007FC68(s32 arg0) {
    char sp1C[4];

    sprintf(sp1C, "%02d", arg0);
    func_8007FB80(0x61, 0x50, "Error Number");
    func_8007FB80(0xC9, 0x50, sp1C);
}

void func_8007FCB8(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x28, 0x6E, "Please refer to the User's Guide.");
}

void func_8007FCF4(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x2D, 0x5A, "Caution : Please do not remove");
    func_8007FB80(0x2D, 0x6E, "the disk while the access lamp");
    func_8007FB80(0x2D, 0x82, "is blinking.");
}

void func_8007FD58(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x2D, 0x6E, "Caution : Please do not remove");
    func_8007FB80(0x2D, 0x82, "the disk while the access lamp");
    func_8007FB80(0x2D, 0x96, "is blinking.");
    func_8007FB80(0x2D, 0xAA, "Please insert the disk.");
}

void func_8007FDD0(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x35, 0x6E, "The eject button may have");
    func_8007FB80(0x35, 0x82, "been pushed. Please remove");
    func_8007FB80(0x35, 0x96, "the Disk once and completely");
    func_8007FB80(0x35, 0xAA, "reinsert it.");
}

void func_8007FE48(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x38, 0x64, "The wrong disk may have");
    func_8007FB80(0x38, 0x78, "been inserted. Please check.");
}

void func_8007FE98(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x3B, 0x6E, "Has the disk been inserted?");
}

void func_8007FED4(void) {
    func_8007F94C();
    func_8007F970();
    func_8007FB80(0x37, 0x64, "Please insert initial disk");
    func_8007FB80(0x37, 0x78, "used when turned power ON.");
}
