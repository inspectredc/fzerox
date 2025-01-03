#include "global.h"
#include "PR/leo.h"

bool D_800CD510 = false;
s32 gSkyboxType;
s32 gBackgroundFloorType;
RaceStats gCupRaceStats[1][6];

void func_8007F4E0(s32 arg0, s32 arg1) {
    D_800CD510 = true;
    gBackgroundFloorType = arg0;
    gSkyboxType = arg1;
}

s8 D_800E42C8[4];
s16 D_800E42CC;

void func_8007F500(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E42C8[i] = 0;
    }

    D_800E42CC = 0;
}

extern OSMesgQueue D_800DCAE0;

void func_8007F520(void) {
    u8 i;
    OSMesg temp_v0;
    OSMesg msg;

    for (i = 0; i < 30; i++) {
    start:
        do {
            osRecvMesg(&D_800DCAE0, &msg, OS_MESG_BLOCK);
        } while (msg != (OSMesg) 0x1A);

        LeoResetClear();
        temp_v0 = func_80075534();
        if (temp_v0 != (OSMesg) 0x2B) {
            return;
        }
    }

    func_800751C0();
    func_8007FCB8();
    func_8007FC68(temp_v0);
    func_800751C0();
    while (true) {}
}

void func_80076310(void);
void func_8007F520(void);
void func_800762B0(LEODiskID);

OSMesgQueue D_800E42D0;
OSMesg D_800E42E8[16];

extern s32 D_i1_80428610;
extern LEODiskID D_i1_80428618;
extern LEODiskID leoBootID;

void func_8007F5EC(void) {

    func_80076310();
    osCreateMesgQueue(&D_800E42D0, D_800E42E8, ARRAY_COUNT(D_800E42E8));
    func_i1_80404AEC("01", "EFZE");
    if (func_i1_80403F4C(0x101, D_800E42E8, ARRAY_COUNT(D_800E42E8)) < 0) {
        switch (D_i1_80428610) {
            case 0x29:
                return;
            case 0x2A:
            case 0xF9:
            default:
                goto label;
                break;
        }
    }

label:
    if (D_i1_80428610 == 0xF9) {
        func_8007F520();
    }
    func_i1_8040428C();
    func_800762B0(D_i1_80428618);
    leoBootID = D_i1_80428618;

    switch (func_i1_804046F0()) {
        case 1:
            break;
        case 0:
            if (func_i1_804043B8(1) < 0) {}
            break;
        case -1:
            switch (D_i1_80428610) {
                case 42:
                    break;
                case 23:
                    func_i1_804043B8(1);
                    break;
            }
            break;
    }
    func_i1_804067BC(0, 0);
}
