#include "global.h"
#include ASSET_HEADER_EK(overlays/expansion_kit/dd_fault.h)

u16 D_xk1_8003BBA0;
u16 D_xk1_8003BBA8[4];
s32* D_8003BBB0;

u16 D_xk1_80033500 = 180;

void func_xk1_8002E9D0(s32 arg0) {
    D_xk1_80033500 = 180 / arg0;
}

Gfx* func_xk1_8002EA10(Gfx* gfx, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5) {

    gfx = ExpansionKit_DrawRectangleBorder(gfx, arg1 - 2, arg2 - 2, arg3 + 1, arg4 + 1, arg5, 2, 2);

    gSPDisplayList(gfx++, D_xk1_800335F0);
    gDPFillRectangle(gfx++, arg1, arg2, arg3, arg4);
    gSPDisplayList(gfx++, D_xk1_80033630);
    return gfx;
}

extern volatile unk_807C6EA8 D_807C6EA8;

Gfx* func_xk1_8002EAF0(Gfx* gfx, u16 arg1, u8 arg2, u16 arg3) {

    D_xk1_8003BBA0 = (SCREEN_WIDTH - arg1) >> 1;

    if (D_807C6EA8.unk_04 != 0) {
        switch (arg2) {
            case 1:
                D_xk1_8003BBA8[0] = 110;
                break;
            case 2:
                D_xk1_8003BBA8[0] = 107;
                D_xk1_8003BBA8[1] = 127;
                break;
            case 3:
                D_xk1_8003BBA8[0] = 104;
                D_xk1_8003BBA8[1] = 124;
                D_xk1_8003BBA8[2] = 144;
                break;
            case 4:
                D_xk1_8003BBA8[0] = 101;
                D_xk1_8003BBA8[1] = 121;
                D_xk1_8003BBA8[2] = 141;
                D_xk1_8003BBA8[3] = 161;
                break;
        }
    } else {
        switch (arg2) {
            case 1:
                D_xk1_8003BBA8[0] = 110;
                break;
            case 2:
                D_xk1_8003BBA8[0] = 100;
                D_xk1_8003BBA8[1] = 120;
                break;
            case 3:
                D_xk1_8003BBA8[0] = 90;
                D_xk1_8003BBA8[1] = 110;
                D_xk1_8003BBA8[2] = 130;
                break;
            case 4:
                D_xk1_8003BBA8[0] = 80;
                D_xk1_8003BBA8[1] = 100;
                D_xk1_8003BBA8[2] = 120;
                D_xk1_8003BBA8[3] = 140;
                break;
        }
    }
    gfx = func_xk1_8002EA10(gfx, D_xk1_8003BBA0 - 6, D_xk1_8003BBA8[0] - 3, D_xk1_8003BBA0 + arg1 + 6,
                            D_xk1_8003BBA8[arg2 - 1] + 19, arg3);

    return gfx;
}

Gfx* func_xk1_8002ECE8(Gfx* gfx, u16 arg1, u16 arg2, s32 arg3, u16 arg4) {
    u16 sp28 = (0x140 - arg2) >> 1;

    gfx = func_xk1_8002EA10(gfx, sp28, arg1, (sp28 + arg2), arg1 + 16, arg4);
    gfx = func_xk1_800262F4(gfx, sp28, arg1, arg3);
    return gfx;
}

u16 D_xk1_80033504 = 0;
u16 D_xk1_80033508 = 0;

extern u8* D_xk3_801372B8[];
extern u8* sLeoErrorMessages[];
extern volatile u8 D_80794E1C;
extern volatile u8 D_80794E24;
extern OSMesgQueue D_807C6E90;
extern u8* D_xk1_800337D0[];

Gfx* func_xk1_8002ED64(Gfx* gfx) {
    static u16 D_xk1_8003350C = 0;
    static u8 D_xk1_80033510 = 0;
    char sp34[4];

    switch (D_807C6EA8.unk_10) {
        case 2:
        case 3:
        case 4:
            osSendMesg(&D_807C6E90, NULL, OS_MESG_BLOCK);
            break;
        default:
            break;
    }

    if (D_807C6EA8.unk_08 == 6) {
        D_xk1_8003350C++;
        if ((D_xk1_80033510 == 1) && (D_xk1_8003350C >= (D_xk1_80033500 / 6))) {
            D_xk1_8003350C = 0;
            D_xk1_80033510 = 0;
            D_807C6EA8.unk_08 = 0;
        }
    } else if (D_xk1_80033508 == 6) {
        if (D_807C6EA8.unk_08 == 2) {
            D_xk1_8003350C = 0;
            D_xk1_80033510 = 0;
        } else if (D_xk1_8003350C < (D_xk1_80033500 / 6)) {
            D_xk1_80033510 = 1;
            D_807C6EA8.unk_08 = 6;
        } else {
            D_xk1_8003350C = 0;
            D_xk1_80033510 = 0;
        }
    }
    D_xk1_80033508 = D_807C6EA8.unk_08;
    switch (D_807C6EA8.unk_08) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 25:
        case 26:
            if ((D_807C6EA8.unk_04 != 0) || (D_807C6EA8.unk_0C != 0)) {
                D_807C6EA8.unk_08 = 10;
            }
            break;
    }
    if (D_807C6EA8.unk_04 != 0) {
        sprintf(sp34, "%02d", D_807C6EA8.unk_14);
        gfx = func_xk1_8002EA10(gfx, 102, 67, func_xk1_8002FB30(sp34) + 200, 89, GPACK_RGBA5551(255, 0, 0, 1));
        LeoFault_DrawErrorMessage(&gfx, 108, 70, sLeoErrorMessages[10]);
        LeoFault_DrawErrorMessageNumber(&gfx, 194, 70, sp34);
    }
    switch (D_807C6EA8.unk_08) {
        case 0:
            break;
        case 1:
            gfx = func_xk1_8002EAF0(gfx, 216, 1, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], sLeoErrorMessages[11]);
            break;
        case 2:
            gfx = func_xk1_8002EAF0(gfx, 240, 4, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], sLeoErrorMessages[12]);
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[1], sLeoErrorMessages[13]);
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[2], sLeoErrorMessages[14]);
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[3], sLeoErrorMessages[15]);
            break;
        case 3:
            gfx = func_xk1_8002EAF0(gfx, 272, 3, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], sLeoErrorMessages[18]);
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[1], sLeoErrorMessages[19]);
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[2], sLeoErrorMessages[20]);
            break;
        case 4:
            gfx = func_xk1_8002EAF0(gfx, 248, 1, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], sLeoErrorMessages[21]);
            break;
        case 6:
            gfx = func_xk1_8002EAF0(gfx, 104, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[0]);
            break;
        case 5:
            gfx = func_xk1_8002EAF0(gfx, 104, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[1]);
            break;
        case 7:
            gfx = func_xk1_8002EAF0(gfx, 104, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[9]);
            break;
        case 8:
            gfx = func_xk1_8002EAF0(gfx, 136, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[10]);
            break;
        case 9:
            gfx = func_xk1_8002EAF0(gfx, 216, 1, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[2]);
            break;
        case 11:
            gfx = func_xk1_8002EAF0(gfx, 136, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[3]);
            break;
        case 12:
            gfx = func_xk1_8002EAF0(gfx, 168, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[4]);
            break;
        case 13:
            if (D_80794E24 != 0) {
                D_xk1_80033504 = 0;
                D_80794E24 = 0;
            }
            if (D_xk1_80033504 < D_xk1_80033500) {
                if (((D_xk1_80033500 / 4) < D_xk1_80033504) &&
                    ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) ||
                     (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B))) {
                    D_807C6EA8.unk_08 = 0;
                } else {
                    gfx = func_xk1_8002EAF0(gfx, 168, 1, GPACK_RGBA5551(130, 130, 255, 1));
                    LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[5]);
                    D_xk1_80033504++;
                    break;
                }
            } else {
                D_807C6EA8.unk_08 = 0;
            }
            break;
        case 14:
            gfx = func_xk1_8002EAF0(gfx, 200, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[6]);
            break;
        case 15:
            gfx = func_xk1_8002EAF0(gfx, 216, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[7]);
            break;
        case 16:
        case 27:
            if (D_80794E1C != 0) {
                D_xk1_80033504 = 0;
                D_80794E1C = 0;
            }

            if (D_xk1_80033504 < D_xk1_80033500) {
                if (((D_xk1_80033500 / 4) < D_xk1_80033504) &&
                    ((gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) ||
                     (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B))) {
                    D_807C6EA8.unk_08 = 0;
                } else {
                    switch (D_807C6EA8.unk_08) {
                        case 16:
                            gfx = func_xk1_8002EAF0(gfx, 216, 1, GPACK_RGBA5551(255, 0, 0, 1));
                            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[8]);
                            break;
                        case 27:
                            gfx = func_xk1_8002EAF0(gfx, 184, 1, GPACK_RGBA5551(130, 130, 255, 1));
                            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[13]);
                            break;
                    }
                    D_xk1_80033504++;
                }
            } else {
                D_807C6EA8.unk_08 = 0;
            }
            break;
        case 17:
            gfx = func_xk1_8002ECE8(gfx, 54, 192, D_xk3_801372B8[0], GPACK_RGBA5551(130, 130, 255, 1));
            break;
        case 18:
            gfx = func_xk1_8002ECE8(gfx, 54, 256, D_xk3_801372B8[2], GPACK_RGBA5551(130, 130, 255, 1));
            func_xk1_8002D340(&gfx);
            break;
        case 19:
            gfx = func_xk1_8002EA10(gfx, 40, 40, 280, 72, GPACK_RGBA5551(255, 0, 0, 1));
            gfx = func_xk1_800262F4(gfx, 40, 40, D_xk3_801372B8[3]);
            gfx = func_xk1_800262F4(gfx, 40, 56, D_xk3_801372B8[4]);
            break;
        case 20:
            gfx = func_xk1_8002ECE8(gfx, 54, 272, D_xk3_801372B8[5], GPACK_RGBA5551(130, 130, 255, 1));
            func_xk1_8002D340(&gfx);
            break;
        case 21:
            gfx = func_xk1_8002EA10(gfx, 48, 40, 272, 72, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, 48, 40, sLeoErrorMessages[25]);
            LeoFault_DrawErrorMessage(&gfx, 48, 56, sLeoErrorMessages[26]);
            break;
        case 22:
            gfx = func_xk1_8002ECE8(gfx, 54, 112, D_xk3_801372B8[6], GPACK_RGBA5551(255, 0, 0, 1));
            break;
        case 23:
            gfx = func_xk1_8002ECE8(gfx, 54, 128, D_xk3_801372B8[7], GPACK_RGBA5551(255, 0, 0, 1));
            break;
        case 24:
            gfx = func_xk1_8002ECE8(gfx, 54, 272, D_xk3_801372B8[9], GPACK_RGBA5551(130, 130, 255, 1));
            break;
        case 25:
            gfx = func_xk1_8002EAF0(gfx, 136, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[11]);
            break;
        case 26:
            gfx = func_xk1_8002EAF0(gfx, 184, 1, GPACK_RGBA5551(130, 130, 255, 1));
            LeoFault_DrawErrorMessage(&gfx, D_xk1_8003BBA0, D_xk1_8003BBA8[0], D_xk1_800337D0[12]);
            break;
    }

    switch (D_807C6EA8.unk_0C) {
        case 1:
            gfx = func_xk1_8002EA10(gfx, 38, 187, 282, 209, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, 44, 190, sLeoErrorMessages[16]);
            break;
        case 2:
            gfx = func_xk1_8002EA10(gfx, 38, 187, 282, 209, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, 44, 190, sLeoErrorMessages[24]);
            break;
        case 3:
            gfx = func_xk1_8002EA10(gfx, 50, 167, 270, 209, GPACK_RGBA5551(255, 0, 0, 1));
            LeoFault_DrawErrorMessage(&gfx, 56, 170, sLeoErrorMessages[17]);
            LeoFault_DrawErrorMessage(&gfx, 56, 190, sLeoErrorMessages[23]);
            break;
    }
    return gfx;
}

Gfx* func_xk1_8002F9DC(Gfx* gfx) {
    if (D_807C6EA8.unk_0C == 4) {
        gfx = func_xk1_8002EA10(gfx, 62, 187, 258, 209, GPACK_RGBA5551(130, 130, 255, 1));
        LeoFault_DrawErrorMessage(&gfx, 68, 190, sLeoErrorMessages[34]);
    }
    return gfx;
}

extern u8* gExpansionKitFontPtr;
extern u8 D_xk1_80033808[];

void func_xk1_8002FA50(void) {
    u16 i;

    gExpansionKitFontPtr = Arena_Allocate(ALLOC_FRONT, 20 * 0x80);
    D_8003BBB0 = Arena_Allocate(ALLOC_FRONT, 20 * sizeof(s32));

    for (i = 0; i < 20; i++) {
        D_8003BBB0[i] = (D_xk1_80033808[i * 2] << 8) + D_xk1_80033808[i * 2 + 1];
        LeoFault_CopyFontToRam(D_8003BBB0[i], gExpansionKitFontPtr + i * 0x80);
    };
}
