#include "global.h"
#include "fzxthread.h"
#include "PR/leo.h"

OSIoMesg D_800E4330;
s16* D_800E4348;
s16* D_800E434C;
s32 D_800E4350[96];
s32 D_800E44D0[96];
s32 D_800E4650[96];

s32 D_800CD520[] = { 0x6CA06F18, 0x6CB82A14, 0x6CBE4314, 0x6CC29A14, 0x6CDE8D16, 0x6CFADB14, 0x6D249B14, 0x6D422314,
                     0x6D445D14, 0x6D594D14, 0x6D675414, 0x6D6F870E, 0x6D7F2402, 0x6D829108, 0x6D872102, 0x6D885A14,
                     0x6D998B14, 0x6DB15A14, 0x6DC28A14, 0x6DD88B14, 0x6DF08A14, 0x6E068B14, 0x6E1E8B14, 0x6E368A14,
                     0x6E4C8B14, 0x6E648B14, 0x6E7C270E, 0x6E802A0E, 0x6E86970E, 0x6E9A850C, 0x6EA6970E, 0x6EBA7A14,
                     0x6ED0DB14, 0x6EFAAA14, 0x6F169A14, 0x6F32AB14, 0x6F509A14, 0x6F6C9A14, 0x6F889A14, 0x6FA4AB14,
                     0x6FC2AA14, 0x6FDE2A14, 0x6FE47B14, 0x6FFC9A14, 0x70188A14, 0x702EBA14, 0x704F9A14, 0x706BBB14,
                     0x708F9A14, 0x70ABBB14, 0x70CF9A14, 0x70EB9B14, 0x7109AA14, 0x71259B14, 0x7143AA14, 0x715FEA14,
                     0x7186AA14, 0x71A2AA14, 0x71BE9A14, 0x71DA3D14, 0x71E87A14, 0x71FE4D14, 0x720C5214, 0x721190FC,
                     0x6CA06F18, 0x722C8910, 0x72408B14, 0x72588910, 0x726C7C16, 0x72868910, 0x729A6A14, 0x72AB8C10,
                     0x72C57A14, 0x72DB2A14, 0x72E14E14, 0x72F07A14, 0x73062A14, 0x730CB810, 0x73277810, 0x73398910,
                     0x734D8C10, 0x73678C10, 0x73815810, 0x738F7910, 0x73A34A12, 0x73AE780E, 0x73C0870E, 0x73D0B70E,
                     0x73E8770E, 0x73F88B0E, 0x7410770E, 0x74205D14, 0x74352A14, 0x743B6D14, 0x74506114, 0x00000000 };

u16 D_800CD6A0[] = {
    0x0001, 0x1085, 0x2109, 0x318D, 0x4211, 0x5295, 0x6319, 0x739D,
    0x8C63, 0x9CE7, 0xAD6B, 0xBDEF, 0xCE73, 0xDEF7, 0xEF7B, 0xFFFF,
};

extern OSMesgQueue D_800DCA68;
extern OSPiHandle* D_800DCCE0;

typedef struct unk_8007F86C_arg_1 {
    s8 pad[0x80];
} unk_8007F86C_arg_1;

void func_8007F7D0(s32* arg0, unk_8007F86C_arg_1* arg1, s32* arg2, s32* arg3, s32* arg4) {
    uintptr_t fontAddr = LeoGetAAdr2(arg0, arg2, arg3, arg4) + DDROM_FONT_START;

    D_800E4330.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800E4330.hdr.retQueue = &D_800DCA68;
    D_800E4330.dramAddr = arg1;
    D_800E4330.devAddr = fontAddr;
    D_800E4330.size = sizeof(unk_8007F86C_arg_1);
    D_800DCCE0->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(D_800DCCE0, &D_800E4330, OS_READ);
    MQ_WAIT_FOR_MESG(&D_800DCA68, NULL);
}

void func_8007F86C(s32* arg0, unk_8007F86C_arg_1* arg1, s32* arg2, s32* arg3, s32* arg4) {
    s32 i;
    s32 j;

    for (i = 0, j = 0; arg0[i] != 0; j++, i++) {
        func_8007F7D0(arg0[i], &arg1[j], &arg2[i], &arg3[i], &arg4[i]);
    }
}

extern unk_8007F86C_arg_1 D_80400008[];

void func_8007F904(void) {
    func_8007F86C(D_800CD520, D_80400008, D_800E4350, D_800E44D0, D_800E4650);
}

void func_8007F94C(void) {
    D_800E4348 = osViGetNextFramebuffer();
}

void func_8007F970(void) {
    u8 i;
    u16 j;

    for (i = 75; i < 191; i++) {
        for (j = 22; j < 298; j++) {
            D_800E434C = D_800E4348 + (i * SCREEN_WIDTH) + j;
            *D_800E434C = 1;
        }
    }
}

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

void func_8007FA64(s32 arg0, s32 arg1, u8* arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 i;
    u16 j;
    u8 temp_a3;
    u32 temp_t1;
    u8* var_v0 = arg2;

    arg1 += 12;

    for (i = (arg1 - arg5); i < (arg1 - arg5) + arg4; i++) {
        for (j = arg0; j < arg0 + arg3; j += 2, var_v0++) {
            temp_a3 = *var_v0 >> 4;
            temp_t1 = *var_v0 & 0xFF;
            D_800E434C = D_800E4348 + (i * SCREEN_WIDTH) + j;
            temp_t1 &= 0xF;
            if (temp_a3 != 0) {
                *D_800E434C = D_800CD6A0[temp_a3];
            }
            if (j + 1 < arg0 + arg3) {
                D_800E434C++;
                if (temp_t1) {
                    *D_800E434C = D_800CD6A0[temp_t1];
                }
            }
        }
    }
}

void func_8007FB80(s32 arg0, s32 arg1, s8* arg2) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s2;
    s32* temp_s3;
    s8 var_s1;
    s8* var_s0;
    s32 i;

    for (i = 0; arg2[i] != 0; i++) {
        temp_v1 = arg2[i] - 32;
        func_8007FA64(arg0, arg1, &D_80400008[temp_v1], D_800E4350[temp_v1], D_800E44D0[temp_v1], D_800E4650[temp_v1]);
        // FAKE
        arg0 = arg0 + D_800E4350[temp_v1] + (0, 1);
    }
}

void func_8007FB80(s32, s32, s8*);

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
