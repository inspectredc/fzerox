#include "global.h"
#include "leo/leo_internal.h"

OSIoMesg D_xk1_8003A470;
s32 D_xk1_8003A488;
UNUSED s32 D_xk1_8003A48C;
s32 D_xk1_8003A490;
s32 D_xk1_8003A494;
s32* D_xk1_8003A498[31];
s32* D_xk1_8003A518[12];
s32* D_xk1_8003A548;
u16* D_xk1_8003A54C;

u8 D_80030060[9] = { 0 };
u8 D_8003006C[9] = { 0 };

UNUSED s32 D_80030078 = 0;
UNUSED s32 D_8003007C = 0;

s32 D_xk1_80030080 = 0;
s32 D_xk1_80030084 = 0;

s32 func_xk1_80025C20(s8* arg0) {
    s32 var_v1;

    var_v1 = 0;
    while (true) {

        if (*arg0 == 0) {
            break;
        }

        if (*arg0 == 0xA) {
            arg0++;
        } else {
            arg0 += 2;
            var_v1++;
        }
    }
    return var_v1;
}

extern u8* D_xk1_800331F0[];
extern u8* D_xk1_8003339C[];

s32 func_xk1_80025C58(void) {
    s32 var_s1;
    s32 i;

    var_s1 = 0;
    for (i = 0; i < 31; i++) {
        var_s1 += func_xk1_80025C20(D_xk1_800331F0[i]);
    }
    for (i = 0; i < 12; i++) {
        var_s1 += func_xk1_80025C20(D_xk1_8003339C[i]);
    }

    return var_s1;
}

s32 func_xk1_80025CD8(u16 arg0) {
    s32 i;

    for (i = 0; i < D_xk1_8003A494; i++) {
        if (arg0 == D_xk1_8003A54C[i]) {
            return 0;
        }
    }
    return 1;
}

void func_xk1_80025D2C(char* arg0) {
    u16 temp_s1;

    while (true) {
        if (arg0[0] == '\0') {
            break;
        }

        if (arg0[0] == 0xA) {
            arg0++;
        } else {
            temp_s1 = (arg0[0] << 8) + arg0[1];
            if (func_xk1_80025CD8(temp_s1) != 0) {
                D_xk1_8003A54C[D_xk1_8003A494] = temp_s1;
                D_xk1_8003A494++;
            }
            arg0 += 2;
        }
    }
}

s32 func_xk1_80025DE4(void) {
    s32 i;

    D_xk1_80030084 = 0;
    for (i = 0; i < D_xk1_80030080; i++) {}
    D_xk1_8003A494 = 0;

    for (i = 0; i < 31; i++) {
        func_xk1_80025D2C(D_xk1_800331F0[i]);
    }

    for (i = 0; i < 12; i++) {
        func_xk1_80025D2C(D_xk1_8003339C[i]);
    }

    return D_xk1_8003A494;
}

s32 func_xk1_80025E8C(u16 arg0) {
    s32 i;

    for (i = 0; i < D_xk1_8003A494; i++) {
        if (arg0 == D_xk1_8003A54C[i]) {
            break;
        }
    }
    return i;
}

void func_xk1_80025ED4(char* arg0) {
    u16 temp_s1;

    while (true) {
        if (arg0[0] == '\0') {
            break;
        }

        if (arg0[0] == 0xA) {
            arg0++;
        } else {
            temp_s1 = (arg0[0] << 8) + arg0[1];
            D_xk1_8003A548[D_xk1_80030080] = (func_xk1_80025E8C(temp_s1) << 7) + D_xk1_8003A488 + 0xE00;
            D_xk1_80030080++;
            arg0 += 2;
        }
    }
}

void func_xk1_80025F98(void) {
    s32 i;

    D_xk1_80030080 = func_xk1_80025C58();
    D_xk1_8003A54C = Arena_Allocate(ALLOC_FRONT, D_xk1_80030080 * sizeof(u16));
    D_xk1_8003A548 = Arena_Allocate(ALLOC_FRONT, D_xk1_80030080 * sizeof(s32));
    D_xk1_8003A494 = func_xk1_80025DE4();
    D_xk1_8003A488 = Arena_Allocate(ALLOC_FRONT, (D_xk1_8003A494 << 7) + 0xE00);
    D_xk1_8003A490 += 0xE00;
    func_xk1_800267C4(D_xk1_8003A54C);
    D_xk1_80030080 = 0;

    for (i = 0; i < 31; i++) {
        D_xk1_8003A498[i] = &D_xk1_8003A548[D_xk1_80030080];
        func_xk1_80025ED4(D_xk1_800331F0[i]);
    }

    for (i = 0; i < 12; i++) {
        D_xk1_8003A518[i] = &D_xk1_8003A548[D_xk1_80030080];
        func_xk1_80025ED4(D_xk1_8003339C[i]);
    };
}

void func_xk1_800260E4(void) {
    D_xk1_8003A490 = 0;
}

extern OSMesgQueue gDmaMesgQueue;
extern OSPiHandle* gDriveRomHandle;

Gfx* func_xk1_800260F0(Gfx* gfx, s32 arg1, s32 arg2, s32 code) {
    s32 fontAddr = LeoGetKAdr(code) + DDROM_FONT_START;

    // TODO: move to appropriate place
    PRINTF("KANJI NUM COUNT START\n");
    PRINTF("KANJI NUM IS %d\n");
    PRINTF("FONT NUM IS %d\n");
    PRINTF("\nDMA OK\n");
    PRINTF("KANJI READY OK %d\n");
    PRINTF("*");

    D_xk1_8003A470.hdr.pri = 0;
    D_xk1_8003A470.hdr.retQueue = &gDmaMesgQueue;
    D_xk1_8003A470.dramAddr = D_xk1_8003A488 + D_xk1_8003A490;
    D_xk1_8003A470.devAddr = fontAddr;
    D_xk1_8003A470.size = 0x80;
    gDriveRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    func_80768B88(gDriveRomHandle, &D_xk1_8003A470, OS_READ);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);

    gDPLoadTextureBlock_4b(gfx++, D_xk1_8003A488 + D_xk1_8003A490, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 16) << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    D_xk1_8003A490 += 0x80;
    return gfx;
}

extern volatile u8 D_80794E14;

Gfx* func_xk1_800262F4(Gfx* gfx, s32 arg1, s32 arg2, u8* arg3) {
    u8* var_s0;
    u8* var_s1;
    s32 i;

    if (D_80794E14) {
        return gfx;
    }

    i = 0;
    var_s0 = arg3;
    while (var_s0[i] != '\0') {
        gfx = func_xk1_800260F0(gfx, arg1, arg2, (var_s0[i] << 8) + var_s0[i + 1]);
        i += 2;
        arg1 += 16;
    }

    return gfx;
}

Gfx* func_xk1_800263B0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {

    gDPLoadTextureBlock_4b(gfx++, arg3, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 16) << 2, (arg2 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_xk1_800264C0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    s32* var_s1;
    s8* var_s0;
    Gfx* tempGfx;

    var_s1 = D_xk1_8003A498[arg3];
    var_s0 = D_xk1_800331F0[arg3];

    while (*var_s0 != 0) {
        if (*var_s0 == 0xA) {
            break;
        }

        tempGfx = func_xk1_800263B0(gfx, arg1, arg2, *var_s1++);
        arg1 += 16;
        gfx = tempGfx;
        var_s0 += 2;
    }
    return gfx;
}

Gfx* func_xk1_8002656C(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Gfx* tempGfx;
    s32* var_s1;
    s8* var_s0;
    s32 i;

    var_s1 = D_xk1_8003A498[arg3];
    var_s0 = D_xk1_800331F0[arg3];

    for (i = 0; i < arg4; i++) {
        while (*var_s0 != 0) {
            if (*var_s0 == 0xA) {
                var_s0 += 1;
                break;
            }
            var_s1++;
            var_s0 += 2;
        }
    }

    while (*var_s0 != 0) {
        if (*var_s0 == 0xA) {
            break;
        }

        tempGfx = func_xk1_800263B0(gfx, arg1, arg2, *var_s1++);

        arg1 += 16;
        gfx = tempGfx;
        var_s0 += 2;
    }
    return gfx;
}

Gfx* func_xk1_80026670(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    Gfx* tempGfx;
    s32* var_s1;
    s8* var_s0;

    var_s1 = D_xk1_8003A518[arg3];
    var_s0 = D_xk1_8003339C[arg3];

    while (*var_s0 != 0) {
        if (*var_s0 == 0xA) {
            break;
        }

        tempGfx = func_xk1_800263B0(gfx, arg1, arg2, *var_s1++);
        arg1 += 16;
        gfx = tempGfx;
        var_s0 += 2;
    }
    return gfx;
}

void func_xk1_8002671C(s32 code) {
    s32 fontAddr = LeoGetKAdr(code) + DDROM_FONT_START;

    D_xk1_8003A470.hdr.pri = 0;
    D_xk1_8003A470.hdr.retQueue = &gDmaMesgQueue;
    D_xk1_8003A470.dramAddr = D_xk1_8003A488 + D_xk1_8003A490;
    D_xk1_8003A470.devAddr = fontAddr;
    D_xk1_8003A470.size = 0x80;
    gDriveRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    func_80768B88(gDriveRomHandle, &D_xk1_8003A470, OS_READ);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    D_xk1_8003A490 += 0x80;
}

void func_xk1_800267C4(u16* arg0) {
    s32 i;

    for (i = 0; i < D_xk1_8003A494; i++) {
        func_xk1_8002671C(arg0[i]);
    }
}
