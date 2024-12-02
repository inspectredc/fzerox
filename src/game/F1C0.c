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
        case LEO_ERROR_GOOD:
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            return true;
        case LEO_ERROR_QUEUE_FULL:
            return func_800752EC();
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            return false;
        case LEO_ERROR_COMMAND_TERMINATED:
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
    osRecvMesg(&D_800E3308, &D_800E3324, OS_MESG_BLOCK);

    switch ((s32) D_800E3324) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = 1;
            return D_800E3324;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_800752EC()) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_800751C0();
            func_8007FCF4();
            func_800751C0();
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
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
    osRecvMesg(&D_800E3308, &D_800E3324, OS_MESG_BLOCK);

    switch ((s32) D_800E3324) {
        case LEO_ERROR_GOOD:
            D_800CD2D0 = 1;
            return D_800E3324;
        case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
            return (OSMesg) LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (func_800752EC()) {}
            break;

        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_800751C0();
            func_8007FCF4();
            func_800751C0();
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
    }

    return D_800E3324;
}

s32 func_80075690(LEODiskID arg0) {
    s32 i;
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
    char company[] = { '0', '1' };

    if (arg0.company[0] != company[0]) {
        return 1;
    }
    if (arg0.company[1] != company[1]) {
        return 1;
    }

    for (i = 0; i < ARRAY_COUNT(arg0.gameName); i++) {
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
        case LEO_ERROR_GOOD:
            if (D_800CD2D0 == 0) {
                if (func_800753EC() == 0) {
                    return 0;
                }
                return 1;
            }
            return 0;
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            if (func_800753EC() == 0) {
                func_80075228();
                return 0;
            }
            break;
        case LEO_ERROR_BUSY:
            return 2;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
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
        case LEO_ERROR_BUSY:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            func_800751C0();
            func_8007FCB8();
            func_8007FC68(D_800E3324);
            func_800751C0();
            while (true) {}
        case LEO_ERROR_GOOD:
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            if (D_800E32E0 & 1) {
                return 1;
            } else {
                return 0;
            }
    }
}

bool func_800759AC(LEOCmd* cmdBlock, s32 direction, u32 LBA, void* vAddr, u32 nLBAs, OSMesgQueue* arg5) {
    OSMesg msg;

    while (func_80075738(D_800CD2B0) != 2) {

        func_800751C0();
        func_8007FE48();
        func_800751C0();

        while (func_800752EC()) {}
        while (func_80075800()) {}
    }
    LeoReadWrite(cmdBlock, direction, LBA, vAddr, nLBAs, &D_800E3308);
    osRecvMesg(&D_800E3308, &D_800E3324, OS_MESG_BLOCK);

    msg = D_800E3324;

    if (msg == NULL) {
        osSendMesg(arg5, msg, OS_MESG_NOBLOCK);
    }

    switch ((s32) D_800E3324) {
        case LEO_ERROR_GOOD:
            return false;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            func_800751C0();
            func_8007FE98();
            func_800751C0();

            while (func_80075800()) {}
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:

            while (func_80075800()) {}
            func_80075228();
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_800751C0();
            func_8007FD58();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_80075800()) {}
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_800752EC()) {}
            while (func_80075800()) {}

            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_QUEUE_FULL:
            return func_800759AC(cmdBlock, direction, LBA, vAddr, nLBAs, arg5);
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
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
        case LEO_ERROR_GOOD:
            return 0;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            func_800751C0();
            func_8007FE98();
            func_800751C0();

            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:

            while (func_80075800()) {}
            func_80075228();
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_800751C0();
            func_8007FD58();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_800751C0();
            func_8007FDD0();
            func_8007FC68(D_800E3324);
            func_800751C0();

            while (func_800752EC()) {}
            while (func_80075800()) {}
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_QUEUE_FULL:
            return func_80075D10(cmdBlock, direction, LBA, vaddr, nLBAs, arg5);
        case LEO_ERROR_UNRECOVERED_READ_ERROR:
            if (direction == OS_READ) {
                break;
            }
        /* fallthrough */
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
    D_800E3324 = LeoCACreateLeoManager(0x95, 0x96, D_800E3330, ARRAY_COUNT(D_800E3330));

    if ((s32) D_800E3324 == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE) {
        return -1;
    }
    return 0;
}

void func_800763A8(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        do {
            osRecvMesg(&D_800DCAE0, &D_800E3328, OS_MESG_BLOCK);
        } while (D_800E3328 != (OSMesg) 0x1A);

        LeoResetClear();
        D_800E3324 = func_80075534();

        if ((s32) D_800E3324 != LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED) {
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
