#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "ovl_i4.h"
#include "assets/segment_2B9EA0.h"

s32 D_i4_8011D790;
s32 D_i4_8011D794;

static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = {
    { 17, aTitleBackgroundMainTex, TEX_WIDTH(aTitleBackgroundMainTex), TEX_HEIGHT(aTitleBackgroundMainTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundMainTex) },
    { 0 }
};
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = {
    { 17, aTitleBackgroundComicTex, TEX_WIDTH(aTitleBackgroundComicTex), TEX_HEIGHT(aTitleBackgroundComicTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundComicTex) },
    { 0 }
};
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = {
    { 17, aTitleBackgroundFalconTex, TEX_WIDTH(aTitleBackgroundFalconTex), TEX_HEIGHT(aTitleBackgroundFalconTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundFalconTex) },
    { 0 }
};

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

unk_80077D50 sTitleLogoCompTexInfo[] = { { 18, aTitleLogoTex, TEX_WIDTH(aTitleLogoTex), TEX_HEIGHT(aTitleLogoTex),
                                           TEX_COMPRESSED_SIZE(aTitleLogoTex) },
                                         { 0 } };
unk_80077D50 sTitlePushStartCompTexInfo[] = { { 18, aTitlePushStartTex, TEX_WIDTH(aTitlePushStartTex),
                                                TEX_HEIGHT(aTitlePushStartTex),
                                                TEX_COMPRESSED_SIZE(aTitlePushStartTex) },
                                              { 0 } };
unk_80077D50 sTitleNoControllerCompTexInfo[] = { { 20, aTitleNoControllerTex, TEX_WIDTH(aTitleNoControllerTex),
                                                   TEX_HEIGHT(aTitleNoControllerTex),
                                                   TEX_COMPRESSED_SIZE(aTitleNoControllerTex) },
                                                 { 0 } };
unk_80077D50 sTitleExpansionPakWarningCompTexInfo[] = {
    { 20, aTitleExpansionPakWarningTex, TEX_WIDTH(aTitleExpansionPakWarningTex),
      TEX_HEIGHT(aTitleExpansionPakWarningTex), TEX_COMPRESSED_SIZE(aTitleExpansionPakWarningTex) },
    { 0 }
};
unk_80077D50 sTitleDiskWarningCompTexInfo[] = { { 20, aTitleDiskWarningTex, TEX_WIDTH(aTitleDiskWarningTex),
                                                  TEX_HEIGHT(aTitleDiskWarningTex),
                                                  TEX_COMPRESSED_SIZE(aTitleDiskWarningTex) },
                                                { 0 } };

unk_80077D50* sTitleWarningCompTexInfos[] = {
    sTitleNoControllerCompTexInfo,
    sTitleExpansionPakWarningCompTexInfo,
    sTitleDiskWarningCompTexInfo,
};

unk_80077D50 sCopyrightCompTexInfo[] = { { 17, aCopyrightTex, TEX_WIDTH(aCopyrightTex), TEX_HEIGHT(aCopyrightTex),
                                           TEX_COMPRESSED_SIZE(aCopyrightTex) },
                                         { 0 } };

UNUSED s32 D_i4_8011D628[] = { 85, 21, 120, 150 };

s32 D_i4_8011D638 = 0;

extern s32 gLeoDDConnected;
extern s16 D_800CCFE8;
extern s32 gCourseIndex;
extern s32 gGameMode;
extern Controller gSharedController;
extern u16 gInputButtonPressed;
extern u32 gGameFrameCount;

void func_i4_8011A860(u16* arg0) {
}

void func_i4_8011A868(u16* texture) {
    s32 column;
    s32 pixel;
    s32 pixelIndex;
    s32 nextPixelIndex;

    column = (Math_Rand1() >> 3) % 304;
    pixelIndex = (((Math_Rand1() >> 4) % 240) * 304) + column;
    nextPixelIndex = (pixelIndex + 1) % (304 * 240);

    pixel = texture[pixelIndex];
    texture[pixelIndex] = texture[nextPixelIndex];
    texture[nextPixelIndex] = pixel;

    column = (Math_Rand1() >> 5) % 304;
    pixelIndex = (((Math_Rand1() >> 6) % 240) * 304) + column;
    nextPixelIndex = (pixelIndex + 304) % (304 * 240);

    pixel = texture[pixelIndex];
    texture[pixelIndex] = texture[nextPixelIndex];
    texture[nextPixelIndex] = pixel;
}

void func_i4_8011A98C(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 pad2;
    u16* srcPixel;

    column = (Math_Rand1() >> 4) % 304;
    pixelIndex = (((Math_Rand1() >> 5) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 6) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    if (texture[pixelIndex] < *srcPixel) {
        texture[pixelIndex] = *srcPixel;
    }
}

void func_i4_8011AAD8(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 fakeVar;
    u16* srcPixel;

    column = (Math_Rand1() >> 5) % 304;
    pixelIndex = (((Math_Rand1() >> 6) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 7) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    // FAKE
    fakeVar = texture[pixelIndex];

    if (*srcPixel - texture[pixelIndex] < 0) {
        texture[pixelIndex] = *srcPixel;
    }
}

void func_i4_8011AC24(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 pad2;
    u16* srcPixel;

    column = (Math_Rand1() >> 6) % 304;
    pixelIndex = (((Math_Rand1() >> 7) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 8) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    texture[pixelIndex] = *srcPixel;
}

void Title_Init(void) {
    D_800CCFE8 = 3;
    D_i4_8011D638 = 1;
    gCourseIndex = 0;
    D_i4_8011D790 = 0;
    D_i4_8011D794 = 0;
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_TITLE_BACKGROUND, 0, 0, 8);
    Object_Init(OBJECT_TITLE_LOGO, 0, 0, 10);
    Object_Init(OBJECT_TITLE_PUSH_START, 0, 0, 12);
    Object_Init(OBJECT_TITLE_COPYRIGHT, 94, 200, 12);
    if (gLeoDDConnected) {
        Object_Init(OBJECT_TITLE_DISK_DRIVE, 0, 0, 12);
    }
}

extern s32 gControllersConnected;
extern s16 D_800CD044;

s32 Title_Update(void) {

    if (gControllersConnected == 0) {
        return gGameMode;
    }
    Controller_SetGlobalInputs(&gSharedController);
    Math_Rand1();
    if (gLeoDDConnected && (OBJECT_COUNTER(Object_Get(OBJECT_TITLE_DISK_DRIVE)) != 0) &&
        (OBJECT_STATE(Object_Get(OBJECT_TITLE_DISK_DRIVE)) == 0)) {
        return gGameMode;
    }
    if (D_i4_8011D794 != 0) {
        return gGameMode;
    }

    if (D_i4_8011D790 < 0) {
        return gGameMode;
    }

    D_i4_8011D790++;
    if (D_i4_8011D790 < 0x50) {
        return gGameMode;
    }

    if ((D_800CD044 == 0) && (gInputButtonPressed & (BTN_A | BTN_START))) {
        func_800BA8D8(0x3E);
        func_8007E0CC();
        D_i4_8011D790 = -1;
        if (gLeoDDConnected && (OBJECT_STATE(Object_Get(OBJECT_TITLE_DISK_DRIVE)) == 1)) {
            func_800BB370();
        }
        return GAMEMODE_FLX_MAIN_MENU;
    } else {
        return GAMEMODE_FLX_TITLE;
    }
}

Gfx* Title_Draw(Gfx* gfx) {

    gfx = Object_UpdateAndDrawAll(gfx);

    if (D_i4_8011D794 != 0) {
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    }

    return gfx;
}

extern s8 D_800CD3C4;

void Title_BackgroundInit(Object* backgroundObj) {
    OBJECT_STATE(backgroundObj) = D_800CD3C4;
    func_80077D50(sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)], 0);
    if (OBJECT_STATE(backgroundObj) == 0) {
        OBJECT_LEFT(backgroundObj) = 8;
    }
}

void func_i4_8011B0C8(void) {
}

void Title_LogoInit(Object* logoObj) {
    OBJECT_STATE(logoObj) = D_800CD3C4;
    OBJECT_LEFT(logoObj) = 0x55;

    switch (OBJECT_STATE(logoObj)) {
        case 0:
        case 2:
            OBJECT_TOP(logoObj) = 0x15;
            break;
        case 1:
            OBJECT_TOP(logoObj) = 0x30;
            break;
    }

    func_80077D50(sTitleLogoCompTexInfo, 0);
}

void func_i4_8011B134(void) {
}

void Title_StartInit(Object* startObj) {

    OBJECT_STATE(startObj) = D_800CD3C4;
    func_80077D50(sTitleNoControllerCompTexInfo, 0);
    if (gControllersConnected != 0) {
        func_80077D50(sTitlePushStartCompTexInfo, 0);
        OBJECT_LEFT(startObj) = 120;
        switch (OBJECT_STATE(startObj)) {
            case 0:
                OBJECT_TOP(startObj) = 150;
                return;
            case 1:
            case 2:
                OBJECT_TOP(startObj) = 171;
                break;
        }
    }
}

void func_i4_8011B1E4(void) {
}

void Title_CopyrightInit(void) {
    func_80077D50(sCopyrightCompTexInfo, 0);
}

extern s32 gRamDDCompatible;

void Title_DiskDriveInit(Object* diskDriveObj) {
    s32 var_v0;

    OBJECT_LEFT(diskDriveObj) = 80;

    switch (D_800CD3C4) {
        case 0:
        case 2:
            OBJECT_TOP(diskDriveObj) = 100;
            break;
        case 1:
            OBJECT_TOP(diskDriveObj) = 120;
            break;
    }

    if (!gRamDDCompatible) {
        var_v0 = 1;
    } else {
        var_v0 = 2;
    }

    func_80077D50(sTitleWarningCompTexInfos[var_v0], 0);
    if (gRamDDCompatible && (func_800758F8() != 1)) {
        OBJECT_COUNTER(diskDriveObj)++;
        D_i4_8011D794 = 1;
        func_800BB334();
    }
}

void (*sTitleBackgroundEffectFuncs[])(u16*) = {
    func_i4_8011A860, func_i4_8011A860, func_i4_8011A868, func_i4_8011A98C, func_i4_8011AAD8, func_i4_8011AC24,
};

void Title_BackgroundUpdate(Object* backgroundObj) {
    void (*backgroundEffect)(u16*);
    s32 i;
    u16* backgroundTexture;

    if (D_i4_8011D638 == 0) {
        OBJECT_STATE(backgroundObj)++;
        if (OBJECT_STATE(backgroundObj) > 5) {
            OBJECT_STATE(backgroundObj) = 1;
        }
        backgroundEffect = sTitleBackgroundEffectFuncs[OBJECT_STATE(backgroundObj)];
    } else {
        backgroundEffect = sTitleBackgroundEffectFuncs[D_i4_8011D638];
    }

    backgroundTexture = func_800783AC(aTitleBackgroundMainTex);

    for (i = 1999; i > 0; i--) {
        backgroundEffect(backgroundTexture);
    }
}

Gfx* Title_BackgroundDraw(Gfx* gfx, Object* backgroundObj) {
    return func_80078EA0(gfx, sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)], OBJECT_LEFT(backgroundObj),
                         OBJECT_TOP(backgroundObj), 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B3DC(Gfx* gfx, Object* arg1) {
    return gfx;
}

Gfx* Title_LogoDraw(Gfx* gfx, Object* logoObj) {
    return func_80078EA0(gfx, sTitleLogoCompTexInfo, OBJECT_LEFT(logoObj), OBJECT_TOP(logoObj), 0, 0, 0, 1.0f, 1.0f);
}

Gfx* func_i4_8011B438(Gfx* gfx, Object* arg1) {
    return gfx;
}

Gfx* Title_StartDraw(Gfx* gfx, Object* startObj) {
    s32 var_v1;

    if (gControllersConnected != 0) {
        if ((D_i4_8011D790 < 95) && (D_i4_8011D790 >= 0)) {
            return gfx;
        }
        gfx = func_8007DB28(gfx, 0);
        gfx = func_80078EA0(gfx, sTitlePushStartCompTexInfo, OBJECT_LEFT(startObj), OBJECT_TOP(startObj), 1, 0, 0, 1.0f,
                            1.0f);
    } else {
        OBJECT_LEFT(startObj) = 80;

        switch (OBJECT_STATE(startObj)) {
            case 0:
            case 2:
                OBJECT_TOP(startObj) = 150;
                break;
            case 1:
                OBJECT_TOP(startObj) = 162;
                break;
        }

        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            var_v1 = 90 - var_v1;
        } else {
            var_v1 = 30 - var_v1;
        }

        gfx = func_8007A440(gfx, OBJECT_LEFT(startObj), OBJECT_TOP(startObj), OBJECT_LEFT(startObj) + 160,
                            OBJECT_TOP(startObj) + 32, (s32) (var_v1 * 40) / 60, 0, 0, 0xF0);
        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, ((40 - var_v1) * 255) / 40, 0, 0, 255);
        }

        gfx = func_80078EA0(gfx, sTitleNoControllerCompTexInfo, OBJECT_LEFT(startObj), OBJECT_TOP(startObj), 0, 0, 0,
                            1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i4_8011B668(Gfx* gfx, Object* arg1) {
    return gfx;
}

Gfx* Title_CopyrightDraw(Gfx* gfx, Object* copyrightObj) {
    return func_80078EA0(gfx, sCopyrightCompTexInfo, OBJECT_LEFT(copyrightObj), OBJECT_TOP(copyrightObj), 0, 0, 0, 1.0f,
                         1.0f);
}

Gfx* Title_DiskDriveDraw(Gfx* gfx, Object* diskDriveObj) {
    s32 var_t0;
    s32 var_v1;

    var_t0 = 0;
    if (!gRamDDCompatible) {
        var_t0 = 1;
    } else if (OBJECT_STATE(diskDriveObj) != 0) {
        var_t0 = 2;
    }

    if (var_t0 != 0) {
        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            var_v1 = 90 - var_v1;
        } else {
            var_v1 = 30 - var_v1;
        }

        gfx = func_8007A440(gfx, OBJECT_LEFT(diskDriveObj), OBJECT_TOP(diskDriveObj), OBJECT_LEFT(diskDriveObj) + 160,
                            OBJECT_TOP(diskDriveObj) + 32, (s32) (var_v1 * 40) / 60, 0, 0, 0xF0);
        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, ((40 - var_v1) * 255) / 40, 0, 0, 255);
        }
        gfx = func_80078EA0(gfx, sTitleWarningCompTexInfos[var_t0], OBJECT_LEFT(diskDriveObj), OBJECT_TOP(diskDriveObj),
                            0, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

extern s8 D_800CD010;

void Title_DiskDriveUpdate(Object* diskDriveObj) {

    if (gRamDDCompatible && (D_i4_8011D790 != -1) && (D_800CD010 == 0)) {
        if (func_800758F8() == 1) {
            if (OBJECT_COUNTER(diskDriveObj) != 0) {
                func_800BB370();
                func_800BAFA4(0xD);
            }
            OBJECT_COUNTER(diskDriveObj) = 0;
            OBJECT_STATE(diskDriveObj) = 0;
            D_i4_8011D794 = 0;
            return;
        }

        if (OBJECT_COUNTER(diskDriveObj) < 30) {
            OBJECT_COUNTER(diskDriveObj)++;
        }
        switch (OBJECT_COUNTER(diskDriveObj)) {
            case 1:
                func_800BB334();
                break;
            case 30:
                if (func_800761D4() == 2) {
                    func_8007F9E0();
                    func_8007515C();
                } else {
                    OBJECT_STATE(diskDriveObj) = 1;
                    D_i4_8011D794 = 0;
                }
                break;
        }
    }
}
