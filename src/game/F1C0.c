#include "global.h"
#include "PR/leo.h"

LEOStatus D_800E32E0;
LEOCmd D_800E32E8;
OSMesgQueue D_800E3308;
OSMesg D_800E3320;
OSMesg D_800E3324;
OSMesg D_800E3328;
static u8 D_800E332C[4];
OSMesg D_800E3330[16];

extern bool D_800DCCCC;
extern OSMesgQueue D_800DCAE0;

LEODiskID D_800CD2B0 = { 0 };
s32 D_800CD2D0 = 0;
OSThread* D_800CD2D4 = NULL;

s32 func_800BBD00(void);
void func_800BBD60(s32);

void func_800751C0(void) {
    s32 sp1C = func_800BBD00();

    func_800BBD60(1);
    osWritebackDCacheAll();
    func_800BBD60(sp1C);
}

void func_800751FC(char* arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800E332C[i] = *arg0++;
    }
}

void func_80075228(void) {
}

void func_80075230(OSThread* arg0) {
    D_800CD2D4 = arg0;
}

bool func_8007523C(LEODiskID arg0, LEODiskID arg1) {
    s32 i;
    s32* var_v0 = (s32*) &arg0;
    s32* var_v1 = (s32*) &arg1;

    for (i = 0; i < 8; i++, var_v0++, var_v1++) {
        if (*var_v0 != *var_v1) {
            return true;
        }
    }

    return false;
}

void func_8007FCB8(void);

bool func_800752EC(void) {

    LeoSpdlMotor(&D_800E32E8, LEO_MOTOR_BRAKE, &D_800E3308);
    osRecvMesg(&D_800E3308, &D_800E3324, OS_MESG_BLOCK);
    switch ((s32) D_800E3324) {
        case 0:
        case 2:
            return true;
        case 35:
            return func_800752EC();
        case 42:
        case 47:
            return false;
        case 34:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
    }
}

OSMesg func_800753EC(void) {

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &D_800E3308);
    osRecvMesg(&D_800E3308, &D_800E3324, 1);

    switch ((s32) D_800E3324) {
        case 0:
            D_800CD2D0 = 1;
            return D_800E3324;
        case 42:
            break;
        case 2:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_800752EC()) {}
            break;
        case 49:
            func_800751C0();
            func_8007FCF4();
            func_800751C0();
            break;
        case 34:
        case 35:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
    }

    return D_800E3324;
}

OSMesg func_80075534(void) {

    LeoReadDiskID(&D_800E32E8, &D_800CD2B0, &D_800E3308);
    osRecvMesg(&D_800E3308, &D_800E3324, 1);

    switch ((s32) D_800E3324) {
        case 0:
            D_800CD2D0 = 1;
            return D_800E3324;
        case 0x2B:
            return (OSMesg) 0x2B;
        case 2:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (func_800752EC()) {}
            break;

        case 0x31:
            func_800751C0();
            func_8007FCF4();
            func_800751C0();
            break;
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
        case 0x2A:
            break;
    }

    return D_800E3324;
}

s32 func_80075690(LEODiskID arg0) {
    u32 i;
    char company[] = { '0', '1' };

    if (arg0.company[0] != company[0]) {
        return 1;
    }
    if (arg0.company[1] != company[1]) {
        return 1;
    }

    if (arg0.gameName[0] < D_800E332C[0]) {
        return 1;
    }

    for (i = 1; i < ARRAY_COUNT(arg0.gameName); i++) {
        if (D_800E332C[i] != arg0.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 func_80075738(LEODiskID arg0) {
    s32 i;
    char company[2] = { '0', '1' };

    if (arg0.company[0] != company[0]) {
        return 1;
    }
    if (arg0.company[1] != company[1]) {
        return 1;
    }

    for (i = 0; i < 4; i++) {
        if (D_800E332C[i] != arg0.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

void func_80075228(void);

s32 func_80075800(void) {

    D_800E3324 = LeoTestUnitReady(&D_800E32E0);

    switch ((s32) D_800E3324) {
        case 0:
            if (D_800CD2D0 == 0) {
                if (func_800753EC() == 0) {
                    return 0;
                }
                return 1;
            }
            return 0;
        case 47:
            if (func_800753EC() == 0) {
                func_80075228();
                return 0;
            }
            break;
        case 8:
            return 2;
        case 42:
            return 1;
        case 34:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
    }
    return 1;
}

s32 func_800758F8(void) {

    D_800E3324 = LeoTestUnitReady(&D_800E32E0);

    switch ((s32) D_800E3324) {
        case 8:
            return 1;
        case 34:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
        case 0:
        case 42:
        case 47:
            if (D_800E32E0 & 1) {
                return 1;
            } else {
                return 0;
            }
    }
}

bool func_800759AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, OSMesgQueue* arg5) {
    OSMesg msg;

    while (func_80075738(D_800CD2B0) != 2) {

        func_800751C0();
        func_8007FE48();
        func_800751C0();

        while (func_800752EC()) {}
        while (func_80075800()) {}
    }
    LeoReadWrite(arg0, arg1, arg2, arg3, arg4, &D_800E3308);
    osRecvMesg(&D_800E3308, &D_800E3324, 1);

    msg = D_800E3324;

    if (msg == NULL) {
        osSendMesg(arg5, msg, 0);
    }

    switch ((s32) D_800E3324) {
        case 0:
            return 0;
        case 42:
            func_800751C0();
            func_8007FE98();
            func_800751C0();

            while (func_80075800()) {}
            return func_800759AC(arg0, arg1, arg2, arg3, arg4, arg5);
        case 47:

            while (func_80075800()) {}
            func_80075228();
            return func_800759AC(arg0, arg1, arg2, arg3, arg4, arg5);
        case 49:
            func_800751C0();
            func_8007FD58();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_80075800()) {}
            return func_800759AC(arg0, arg1, arg2, arg3, arg4, arg5);
        case 2:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_800752EC()) {}
            while (func_80075800()) {}

            return func_800759AC(arg0, arg1, arg2, arg3, arg4, arg5);
        case 35:
            return func_800759AC(arg0, arg1, arg2, arg3, arg4, arg5);
        case 23:
            if (arg1 == 0) {
                break;
            }
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 43:
        case 44:
        case 45:
        case 46:
        case 48:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
    }

    return false;
}

bool func_80075D10(LEOCmd* cmdBlock, s32 direction, s32 LBA, void* vaddr, u32 nLBAs, OSMesgQueue* arg5) {
    OSMesg msg;

    while (func_8007523C(D_800CD2B0, leoBootID)) {

        func_800751C0();
        func_8007FED4();
        func_800751C0();

        while (func_800752EC()) {}
        while (func_80075800()) {}
    }
    LeoReadWrite(cmdBlock, direction, LBA, vaddr, nLBAs, &D_800E3308);
    osRecvMesg(&D_800E3308, &D_800E3324, OS_MESG_BLOCK);

    msg = D_800E3324;

    if (msg == NULL) {
        osSendMesg(arg5, msg, OS_MESG_NOBLOCK);
    }

    switch ((s32) D_800E3324) {
        case 0:
            return 0;
        case 42:
            func_800751C0();
            func_8007FE98();
            func_800751C0();

            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case 47:

            while (func_80075800()) {}
            func_80075228();
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case 49:
            func_800751C0();
            func_8007FD58();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case 2:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_800752EC()) {}
            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case 35:
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case 23:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 43:
        case 44:
        case 45:
        case 46:
        case 48:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
    }

    return false;
}

s32 func_800760F8(void) {
    static s32 D_800E3370;

    if (!D_800DCCCC) {
        return 0;
    }
    D_800E3370 = func_80075800();

    while (D_800E3370 == 2) {
        D_800E3370 = func_80075800();
    }
    if (D_800E3370 == 0) {
        if (func_80075738(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

s32 func_800761D4(void) {
    static s32 D_800E3374;

    if (!D_800DCCCC) {
        return 0;
    }
    D_800E3374 = func_80075800();

    while (D_800E3374 == 2) {
        D_800E3374 = func_80075800();
    }
    if (D_800E3374 == 0) {
        if (func_80075690(D_800CD2B0) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

void func_800762B0(LEODiskID arg0) {
    D_800CD2B0 = arg0;
}

void func_80076310(void) {
    osCreateMesgQueue(&D_800E3308, &D_800E3320, 1);
}

s32 func_80076340(void) {

    osCreateMesgQueue(&D_800E3308, &D_800E3320, 1);
    D_800E3324 = LeoCACreateLeoManager(0x95, 0x96, D_800E3330, 0x10);

    if ((s32) D_800E3324 == 0x29) {
        return -1;
    }
    return 0;
}

void func_800763A8(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        do {
            osRecvMesg(&D_800DCAE0, &D_800E3328, 1);
        } while (D_800E3328 != (OSMesg) 0x1A);

        LeoResetClear();
        D_800E3324 = func_80075534();

        if ((s32) D_800E3324 != 0x2B) {
            return;
        }
    }
    func_800751C0();
    func_8007FCB8();
    func_8007FC68(D_800E3324);
    func_800751C0();
    while (true) {}
}

void func_8007647C(void) {
}
