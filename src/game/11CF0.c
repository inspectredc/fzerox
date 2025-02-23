#include "global.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "segment_symbols.h"

unk_800E33E0 D_800E33E0[200];
s32 D_800E3A20;
Object gObjects[32];
unk_800E3F28 D_800E3F28[16];
unk_800E4068 D_800E4068[16];

void func_80077CF0(s32 segAddr, size_t size, u8* startAddr) {
    osInvalDCache(startAddr, size);
    Dma_LoadAssets(SEGMENT_ROM_START(segment_2B9EA0) + SEGMENT_OFFSET(segAddr), startAddr, size);
}

void func_80077D44(void) {
    D_800E3A20 = 0;
}

extern u8* D_800E33C0;

u8* func_80077D50(unk_80077D50* arg0, s32 arg1) {
    bool var_a0;
    bool var_s7;
    s32 var_s0;
    s32 alignedWidth;
    s32 var_s2;
    size_t textureSize;
    u8* sp44;
    u8* var_s4;
    u8* header;
    unk_800E33E0* var_s8 = D_800E33E0;

    sp44 = D_800E33C0;
    var_s7 = false;

    while (arg0->unk_04 != 0) {
        var_a0 = false;
        if (arg1 == 0) {
            for (var_s0 = 0; var_s0 < D_800E3A20; var_s0++) {
                // FAKE
                if (D_800E33E0[var_s0].unk_00 == (0, arg0->unk_04)) {
                    var_a0 = true;
                    break;
                }
            }
        }
        if (!var_a0) {
            switch (arg0->unk_00) {
                case 4:
                case 5:
                    if (arg0->width % 16) {
                        alignedWidth = ((arg0->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = arg0->width;
                    }
                    textureSize = arg0->height * alignedWidth;
                    var_s4 = func_800768F4(0, textureSize);
                    func_80077CF0(arg0->unk_04, textureSize, var_s4);
                    break;
                case 20:
                case 21:

                    if (arg0->width % 16) {
                        alignedWidth = ((arg0->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = arg0->width;
                    }
                    textureSize = arg0->height * alignedWidth;
                    if (arg0->compressedSize != 0) {
                        var_s2 = ALIGN_2(arg0->compressedSize) + 2;
                    } else {
                        var_s2 = 0x400;
                    }
                    var_s4 = func_800768F4(0, textureSize);
                    header = func_800768F4(1, var_s2);
                    osInvalDCache(header, var_s2);
                    func_80077CF0(arg0->unk_04, var_s2, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s4);
                    } else {
                        bzero(var_s4, (arg0->height * alignedWidth) / 2);
                    }
                    break;
                case 17:
                case 18:
                    if (arg0->compressedSize != 0) {
                        var_s0 = ALIGN_2(arg0->compressedSize) + 2;
                    } else {
                        var_s0 = 0x400;
                    }

                    var_s4 = func_800768F4(0, arg0->height * arg0->width * 2);
                    header = func_800768F4(1, var_s0);
                    osInvalDCache(header, var_s0);
                    func_80077CF0(arg0->unk_04, var_s0, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s4);
                    } else {
                        bzero(var_s4, arg0->height * arg0->width * 2);
                    }
                    break;
                default:
                    var_s0 = arg0->height * arg0->width * 2;
                    var_s4 = func_800768F4(0, var_s0);
                    func_80077CF0(arg0->unk_04, var_s0, var_s4);
                    break;
            }
            if (!var_s7) {
                sp44 = var_s4;
                var_s7 = true;
            }
            var_s8[D_800E3A20].unk_00 = arg0->unk_04;
            var_s8[D_800E3A20].unk_04 = (s32) var_s4;
            D_800E3A20++;
        }

        arg0++;
    }

    return sp44;
}

void* func_80078104(void* arg0, s32 textureSize, s32 arg2, s32 arg3, bool arg4) {
    s32 var_a3;
    bool var_t0;
    u8* var_s0;
    u8* var_a2;
    s32 sp24;
    unk_800E33E0* var_v1 = D_800E33E0;

    var_t0 = false;
    if ((arg2 == 0) && !arg4) {
        for (var_a3 = 0; var_a3 < D_800E3A20; var_a3++) {
            if (D_800E33E0[var_a3].unk_00 == arg0) {
                var_t0 = true;
                break;
            }
        }
    }
    if (!var_t0 || arg4) {
        if (arg3 == 0) {
            if (!arg4) {
                var_s0 = func_800768F4(0, textureSize);
            } else {
                var_s0 = func_800768F4(1, textureSize);
            }
            func_80077CF0(arg0, textureSize, var_s0);
        } else {
            var_s0 = func_800768F4(1, 8);
            func_80077CF0(arg0, 8, var_s0);
            var_a3 = func_800AA6BC(var_s0);

            if (!arg4) {
                var_s0 = func_800768F4(0, var_a3);
                var_a2 = func_800768F4(1, textureSize);
            } else {
                if (var_a3 % 16) {
                    var_a3 = ((var_a3 / 16) * 16) + 16;
                }
                if (textureSize % 16) {
                    textureSize = ((textureSize / 16) * 16) + 16;
                }

                sp24 = textureSize + var_a3;
                var_s0 = func_800768F4(1, sp24);
                osInvalDCache(var_s0, sp24);
                var_a2 = var_s0 + var_a3;
            }

            osInvalDCache(var_a2, textureSize);
            func_80077CF0(arg0, textureSize, var_a2);
            if (*(s32*) var_a2 == (s32) 'MIO0') {
                mio0Decode(var_a2, var_s0);
            } else {
                bzero(var_s0, var_a3);
            }
        }
        if (!arg4) {
            var_v1[D_800E3A20].unk_00 = arg0;
            var_v1[D_800E3A20].unk_04 = var_s0;
            D_800E3A20++;
        }
    } else {
        // FAKE
        return (var_v1 + var_a3)->unk_04;
    }
    return var_s0;
}

TexturePtr func_800783AC(void* arg0) {
    s32 i;

    for (i = 0; i < D_800E3A20; i++) {
        if (arg0 == D_800E33E0[i].unk_00) {
            return D_800E33E0[i].unk_04;
        }
    }
    return NULL;
}

Gfx* func_800783F4(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture) {

    switch (arg1->unk_00) {
        case 3:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 0, 0,
                                 0);
        case 5:
        case 21:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 1, 0,
                                 0);
        case 2:
        case 18:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 0, 0);
        case 1:
        default:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                                 0, 0);
    }
}

Gfx* func_8007857C(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture) {

    switch (arg1->unk_00) {
        case 3:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 0, 0,
                                 0);
        case 5:
        case 21:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 1, 0,
                                 0);
        case 2:
        case 18:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1,
                                 0, 0);
        case 1:
        default:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0,
                                 0, 0);
    }
}

Gfx* func_8007870C(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, s32 arg5, s32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 0, 0,
                                 0);
        case 5:
        case 21:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 1, 0,
                                 0);
        case 2:
        case 18:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 arg5, arg6);
        case 1:
        default:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                                 arg5, arg6);
    }
}

Gfx* func_800788A4(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 5:
        case 21:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 2:
        case 18:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 0, 0);
        case 1:
        default:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 0, 0, 0);
    }
}

Gfx* func_80078A4C(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 5:
        case 21:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 2:
        case 18:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 0, 0);
        case 1:
        default:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 0, 0, 1);
    }
}

Gfx* func_80078BF8(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8007B14C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 5:
        case 21:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 2:
        case 18:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 1, 1, 0);
        case 1:
        default:
            return func_8007CDB0(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 1, 0, 0);
    }
}

// BAD RETURN
Gfx* func_80078DB4(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, u32 arg5, s32 arg6, s32 arg7,
                   f32 arg8, f32 arg9) {
    switch (arg5) {
        case 0:
            return func_800783F4(gfx, arg1, left, top, texture);
        case 1:
            return func_8007857C(gfx, arg1, left, top, texture);
        case 2:
            return func_8007870C(gfx, arg1, left, top, texture, arg6, arg7);
        case 3:
            return func_800788A4(gfx, arg1, left, top, texture, arg8, arg9);
        case 5:
            return func_80078A4C(gfx, arg1, left, top, texture, arg8, arg9);
        case 4:
            return func_80078BF8(gfx, arg1, left, top, texture, arg8, arg9);
    }
}

Gfx* func_80078EA0(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, u32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8) {
    TexturePtr texture;

    while (arg1->unk_04 != 0) {
        // FAKE
        if (gfx) {}

        texture = func_800783AC(arg1->unk_04);
        if (texture != NULL) {
            gfx = func_80078DB4(gfx, arg1, left, top, texture, arg4, arg5, arg6, arg7, arg8);
        }
        arg1++;
    }
    return gfx;
}

Gfx* func_80078F80(Gfx* gfx, unk_800E3F28* arg1, s32 left, s32 top, u32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8) {
    TexturePtr texture;
    unk_80077D50* var_s0;
    s32 var;

    var_s0 = arg1->unk_00[arg1->unk_04].unk_00;

    while (var_s0->unk_04 != 0) {
        var = arg1->unk_0A;
        switch (var) {
            case 0:
                texture = arg1->unk_0C;
                break;
            default:
                texture = arg1->unk_10;
                break;
        }

        if (texture != NULL) {
            gfx = func_80078DB4(gfx, var_s0, left, top, texture, arg4, arg5, arg6, arg7, arg8);
        }

        var_s0++;
    }
    return gfx;
}

void func_80079080(void) {
    s32 i;

    D_800E4068[0].unk_00 = NULL;

    for (i = 1; i < 17; i++) {}
}

void func_800790A4(unk_80077D50* arg0, TexturePtr arg1) {
    unk_800E4068* var_v0;

    var_v0 = D_800E4068;
    while (var_v0->unk_00 != NULL) {
        var_v0++;
    }
    var_v0->unk_00 = arg0;
    var_v0->unk_04 = arg1;
}

void func_800790D4(void) {
    s32 var_v1;
    u8* header;
    size_t size;
    unk_80077D50* temp_s1;
    unk_800E4068* var_s3;

    var_s3 = D_800E4068;

    while (true) {
        temp_s1 = var_s3->unk_00;
        if (temp_s1 != NULL) {
            switch (temp_s1->unk_00) {
                case 4:
                case 5:
                    if (temp_s1->width % 16) {
                        var_v1 = ((temp_s1->width + 16) / 16) * 16;
                    } else {
                        var_v1 = temp_s1->width;
                    }
                    func_80077CF0(temp_s1->unk_04, temp_s1->height * var_v1, var_s3->unk_04);
                    break;
                case 17:
                case 18:
                    if (temp_s1->compressedSize != 0) {
                        size = ALIGN_2(temp_s1->compressedSize) + 2;
                    } else {
                        size = 0x400;
                    }
                    header = func_800768F4(1, size);
                    osInvalDCache(header, size);
                    func_80077CF0(temp_s1->unk_04, size, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s3->unk_04);
                    } else {
                        bzero(var_s3->unk_04, temp_s1->height * temp_s1->width * 2);
                    }
                    break;
                default:
                    size = temp_s1->height * temp_s1->width;
                    func_80077CF0(temp_s1->unk_04, size * 2, var_s3->unk_04);
                    break;
            }
            var_s3->unk_00 = NULL;
            var_s3++;
        } else {
            break;
        }
    }
}

void func_800792A8(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800E3F28[i].unk_08 = 0;
    }
}

s32 func_800792D8(unk_800792D8* arg0) {
    s32 i = 0;
    u8* var_v0;

    while (D_800E3F28[i].unk_08 != 0) {
        if (++i >= 16) {
            return -1;
        }
    }

    D_800E3F28[i].unk_00 = arg0;
    D_800E3F28[i].unk_04 = -1;
    D_800E3F28[i].unk_06 = 0;
    D_800E3F28[i].unk_08 = -0x8000;

    if (arg0[0].unk_00 != NULL) {
        D_800E3F28[i].unk_0C = func_80077D50(arg0[0].unk_00, 1);
    }

    D_800E3F28[i].unk_10 =
        (arg0[1].unk_00 != NULL) ? func_80077D50(arg0[1].unk_00, 1) : func_80077D50(arg0[0].unk_00, 1);
    D_800E3F28[i].unk_0A = 0;
    return i;
}

void func_800793E8(s32 arg0, s32 arg1, unk_800792D8* arg2) {
    unk_800E3F28* sp1C;
    s32 temp_a3;

    D_800E3F28[arg0].unk_04 = arg1;
    D_800E3F28[arg0].unk_00 = arg2;
    // FAKE
    D_800E3F28[arg0].unk_06 = (arg2 + arg1)->unk_04;
    temp_a3 = arg2[D_800E3F28[arg0].unk_04].unk_00;

    if (D_800E3F28[arg0].unk_0A != 0) {
        func_800790A4(temp_a3, D_800E3F28[arg0].unk_0C);
        D_800E3F28[arg0].unk_0A = 0;
    } else {
        func_800790A4(temp_a3, D_800E3F28[arg0].unk_10);
        D_800E3F28[arg0].unk_0A = 1;
    }
}

void Object_ClearAll(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        gObjects[i].cmdId = OBJECT_FREE;
    }
}

void Object_Init(s32 cmdId, s32 left, s32 top, s8 priority) {
    s32 i = 0;
    Object* object = gObjects;

    while (true) {
        // clang-format off
        if (object->cmdId == OBJECT_FREE) { \
            object->cmdId = cmdId;          \
            object->state = 0;              \
            object->state2 = 0;             \
            object->left = left;            \
            object->top = top;              \
            object->priority = priority;    \
            object->shouldDraw = true;      \
            object->counter = 0;            \
            object->counter2 = 0;           \
            break;
        }
        // clang-format on
        if (++i > ARRAY_COUNT(gObjects)) {
            return;
        }
        object++;
    }

    switch (cmdId) {
        case OBJECT_TITLE_BACKGROUND:
            Title_BackgroundInit(object);
            break;
        case OBJECT_14:
            func_i4_8011B0C8();
            break;
        case OBJECT_TITLE_LOGO:
            Title_LogoInit(object);
            break;
        case OBJECT_16:
            func_i4_8011B134();
            break;
        case OBJECT_TITLE_PUSH_START:
            Title_StartInit(object);
            break;
        case OBJECT_18:
            func_i4_8011B1E4();
            break;
        case OBJECT_TITLE_COPYRIGHT:
            Title_CopyrightInit();
            break;
        case OBJECT_TITLE_DISK_DRIVE:
            Title_DiskDriveInit(object);
            break;
        case OBJECT_MACHINE_SELECT_HEADER:
            MachineSelect_HeaderInit();
            break;
        case OBJECT_32:
            func_i4_80116E8C(object);
            break;
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
            MachineSettings_PortraitInit(object);
            break;
        case OBJECT_MACHINE_SELECT_PORTRAIT_0:
        case OBJECT_MACHINE_SELECT_PORTRAIT_1:
        case OBJECT_MACHINE_SELECT_PORTRAIT_2:
        case OBJECT_MACHINE_SELECT_PORTRAIT_3:
            MachineSelect_PortraitInit(object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
            MachineSelect_CursorNumInit(object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR:
            MachineSelect_CursorInit();
            break;
        case OBJECT_MACHINE_SELECT_CAR:
            MachineSelect_CarInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_CAR:
            MachineSettings_CarInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT:
            MachineSettings_EngineWeightInit();
            break;
        case OBJECT_MACHINE_SETTINGS_STATS:
            MachineSettings_StatsInit();
            break;
        case OBJECT_MACHINE_SETTINGS_NAME_CARD:
            MachineSettings_NameCardInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_SLIDER:
            MachineSettings_SliderInit();
            break;
        case OBJECT_MACHINE_SELECT_OK:
            MachineSelect_OkInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_OK:
            MachineSettings_OkInit(object);
            break;
        case OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS:
            MachineSelect_DifficultyCupsInit(object);
            break;
        case OBJECT_MACHINE_SELECT_STATS_0:
        case OBJECT_MACHINE_SELECT_STATS_1:
        case OBJECT_MACHINE_SELECT_STATS_2:
        case OBJECT_MACHINE_SELECT_STATS_3:
            MachineSelect_StatsInit();
            break;
        case OBJECT_MAIN_MENU_BACKGROUND:
            MainMenu_BackgroundInit(object);
            break;
        case OBJECT_MAIN_MENU_MODE_SIGN_0:
        case OBJECT_MAIN_MENU_MODE_SIGN_1:
        case OBJECT_MAIN_MENU_MODE_SIGN_2:
        case OBJECT_MAIN_MENU_MODE_SIGN_3:
        case OBJECT_MAIN_MENU_MODE_SIGN_4:
        case OBJECT_MAIN_MENU_MODE_SIGN_5:
        case OBJECT_MAIN_MENU_MODE_SIGN_6:
        case OBJECT_MAIN_MENU_MODE_SIGN_7:
            MainMenu_SignInit(object);
            break;
        case OBJECT_MAIN_MENU_HEADER:
            MainMenu_HeaderInit(object);
            break;
        case OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS:
            MainMenu_NumPlayersInit();
            break;
        case OBJECT_MAIN_MENU_SELECT_DIFFICULTY:
            MainMenu_DifficultyInit();
            break;
        case OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE:
            MainMenu_TimeAttackModeInit();
            break;
        case OBJECT_MAIN_MENU_OK:
            MainMenu_OkInit(object);
            break;
        case OBJECT_MAIN_MENU_UNLOCK_EVERYTHING:
            MainMenu_UnlockEverythingInit(object);
            break;
        case OBJECT_COURSE_SELECT_BACKGROUND:
            CourseSelect_BackgroundInit(object);
            break;
        case OBJECT_COURSE_SELECT_MODEL:
            CourseSelect_ModelInit();
            break;
        case OBJECT_COURSE_SELECT_CUP_0:
        case OBJECT_COURSE_SELECT_CUP_1:
        case OBJECT_COURSE_SELECT_CUP_2:
        case OBJECT_COURSE_SELECT_CUP_3:
        case OBJECT_COURSE_SELECT_CUP_4:
        case OBJECT_COURSE_SELECT_CUP_5:
            CourseSelect_CupInit(object);
            break;
        case OBJECT_COURSE_SELECT_HEADER:
            CourseSelect_HeaderInit(object);
            break;
        case OBJECT_COURSE_SELECT_OK:
            CourseSelect_OkInit(object);
            break;
        case OBJECT_COURSE_SELECT_ARROWS:
            CourseSelect_ArrowsInit(object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_MARKER:
            CourseSelect_GhostMarkerInit(object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_OPTION:
            CourseSelect_GhostOptionInit(object);
            break;
        default:
            break;
    }
}

Gfx* Object_Draw(Gfx* gfx, Object* object) {

    if (!object->shouldDraw) {
        return gfx;
    }

    switch (object->cmdId) {
        case OBJECT_FREE:
            break;
        case OBJECT_FRAMEBUFFER:
            gfx = func_8007AB88(gfx);
            gfx = func_8007AE70(gfx);
            gfx = func_8007ABA4(gfx);
            break;
        case OBJECT_TITLE_BACKGROUND:
            gfx = Title_BackgroundDraw(gfx, object);
            break;
        case OBJECT_14:
            gfx = func_i4_8011B3DC(gfx, object);
            break;
        case OBJECT_12:
            gfx = func_8007AF40(gfx, 118, 164, 203, 217, 255, 255, 255, 48);
            break;
        case OBJECT_13:
            gfx = func_8007AE8C(gfx, 12, 8, 307, 231, 0, 0, 0, 0);
            break;
        case OBJECT_TITLE_LOGO:
            gfx = Title_LogoDraw(gfx, object);
            break;
        case OBJECT_16:
            gfx = func_i4_8011B438(gfx, object);
            break;
        case OBJECT_TITLE_PUSH_START:
            gfx = Title_StartDraw(gfx, object);
            break;
        case OBJECT_18:
            gfx = func_i4_8011B668(gfx, object);
            break;
        case OBJECT_TITLE_COPYRIGHT:
            gfx = Title_CopyrightDraw(gfx, object);
            break;
        case OBJECT_TITLE_DISK_DRIVE:
            gfx = Title_DiskDriveDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_BACKGROUND:
            gfx = MachineSelect_BackgroundDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_BACKGROUND:
            gfx = func_8007AC48(gfx, 24, 24, 24);
            break;
        case OBJECT_MACHINE_SELECT_HEADER:
            gfx = MachineSelect_HeaderDraw(gfx, object);
            break;
        case OBJECT_32:
            gfx = func_i4_80117BE0(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
            gfx = MachineSettings_PortraitDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_PORTRAIT_0:
        case OBJECT_MACHINE_SELECT_PORTRAIT_1:
        case OBJECT_MACHINE_SELECT_PORTRAIT_2:
        case OBJECT_MACHINE_SELECT_PORTRAIT_3:
            gfx = MachineSelect_PortraitDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
            gfx = MachineSelect_CursorNumDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR:
            gfx = MachineSelect_CursorDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CAR:
            gfx = MachineSelect_CarDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_OK:
            gfx = MachineSelect_OkDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_STATS_0:
        case OBJECT_MACHINE_SELECT_STATS_1:
        case OBJECT_MACHINE_SELECT_STATS_2:
        case OBJECT_MACHINE_SELECT_STATS_3:
            gfx = MachineSelect_StatsDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_CAR:
            gfx = MachineSettings_CarDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_NAME:
            gfx = MachineSettings_NameDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT:
            gfx = MachineSettings_EngineWeightDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_STATS:
            gfx = MachineSettings_StatsDraw(gfx, object);
            break;
        case OBJECT_58:
            gfx = func_i4_801193B8(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_NAME_CARD:
            gfx = MachineSettings_NameCardDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_SLIDER:
            gfx = MachineSettings_SliderDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_SPLITSCREEN_BARS:
            gfx = MachineSettings_SplitscreenDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_OK:
            gfx = MachineSettings_OkDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS:
            gfx = MachineSelect_DifficultyCupsDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_NAME:
            gfx = MachineSelect_NameDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_BACKGROUND:
            gfx = MainMenu_BackgroundDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_MODE_SIGN_0:
        case OBJECT_MAIN_MENU_MODE_SIGN_1:
        case OBJECT_MAIN_MENU_MODE_SIGN_2:
        case OBJECT_MAIN_MENU_MODE_SIGN_3:
        case OBJECT_MAIN_MENU_MODE_SIGN_4:
        case OBJECT_MAIN_MENU_MODE_SIGN_5:
        case OBJECT_MAIN_MENU_MODE_SIGN_6:
        case OBJECT_MAIN_MENU_MODE_SIGN_7:
            gfx = MainMenu_SignDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_HEADER:
            gfx = MainMenu_HeaderDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS:
            gfx = MainMenu_NumPlayersDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_DIFFICULTY:
            gfx = MainMenu_DifficultyDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE:
            gfx = MainMenu_TimeAttackModeDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_OK:
            gfx = MainMenu_OkDraw(gfx, object);
            break;
        case OBJECT_100:
        case OBJECT_140:
            gfx = func_8007AC48(gfx, 0, 0, 0);
            break;
        case OBJECT_COURSE_SELECT_BACKGROUND:
            gfx = CourseSelect_BackgroundDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_MODEL:
            gfx = CourseSelect_ModelDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_CUP_0:
        case OBJECT_COURSE_SELECT_CUP_1:
        case OBJECT_COURSE_SELECT_CUP_2:
        case OBJECT_COURSE_SELECT_CUP_3:
        case OBJECT_COURSE_SELECT_CUP_4:
        case OBJECT_COURSE_SELECT_CUP_5:
            gfx = CourseSelect_CupDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_HEADER:
            gfx = CourseSelect_HeaderDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_OK:
            gfx = CourseSelect_OkDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_ARROWS:
            gfx = CourseSelect_ArrowsDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_NAME:
            gfx = CourseSelect_NameDraw(gfx);
            break;
        case OBJECT_COURSE_SELECT_GHOST_MARKER:
            gfx = CourseSelect_GhostMarkerDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_OPTION:
            gfx = CourseSelect_GhostOptionDraw(gfx, object);
            break;
    }
    return gfx;
}

Gfx* Object_UpdateAndDrawAll(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 32; i++) {
        switch (gObjects[i].cmdId) {
            case OBJECT_FREE:
                break;
            case OBJECT_TITLE_BACKGROUND:
                Title_BackgroundUpdate(&gObjects[i]);
                break;
            case OBJECT_TITLE_DISK_DRIVE:
                Title_DiskDriveUpdate(&gObjects[i]);
                break;
            case OBJECT_MAIN_MENU_OK:
                MainMenu_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_MAIN_MENU_UNLOCK_EVERYTHING:
                MainMenu_UnlockEverythingUpdate(&gObjects[i]);
                break;
            case OBJECT_32:
                D_800E3F28[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                func_i4_80119BB8(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
                D_800E3F28[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                MachineSettings_PortraitUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_PORTRAIT_0:
            case OBJECT_MACHINE_SELECT_PORTRAIT_1:
            case OBJECT_MACHINE_SELECT_PORTRAIT_2:
            case OBJECT_MACHINE_SELECT_PORTRAIT_3:
                D_800E3F28[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                MachineSelect_PortraitUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
                MachineSelect_CursorNumUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CURSOR:
                MachineSelect_CursorUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CAR:
                MachineSelect_CarUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_CAR:
                MachineSettings_CarUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_NAME_CARD:
                D_800E3F28[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                MachineSettings_NameCardUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_OK:
                MachineSelect_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_OK:
                MachineSettings_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_MODEL:
                CourseSelect_ModelUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_CUP_0:
            case OBJECT_COURSE_SELECT_CUP_1:
            case OBJECT_COURSE_SELECT_CUP_2:
            case OBJECT_COURSE_SELECT_CUP_3:
            case OBJECT_COURSE_SELECT_CUP_4:
            case OBJECT_COURSE_SELECT_CUP_5:
                CourseSelect_CupUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_OK:
                CourseSelect_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_ARROWS:
                CourseSelect_ArrowsUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_GHOST_MARKER:
                CourseSelect_GhostMarkerUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_GHOST_OPTION:
                CourseSelect_GhostOptionUpdate(&gObjects[i]);
                break;
        }
    }

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 32; i++) {
            if (j == gObjects[i].priority) {
                gfx = Object_Draw(gfx, &gObjects[i]);
            }
        }
    }

    return gfx;
}

Object* Object_Get(s32 cmdId) {
    Object* object;

    object = gObjects;

    while (true) {
        if (cmdId == object->cmdId) {
            break;
        }
        object++;
        //! @bug this allows for an iteration out of the bounds of the array
        if (object > &gObjects[ARRAY_COUNT(gObjects)]) {
            return NULL;
        }
    }
    return object;
}

extern s32 gGameMode;

void func_80079EC8(void) {
    func_80077D44();
    Object_ClearAll();
    func_800792A8();
    func_80079080();
    if (gGameMode != GAMEMODE_CREATE_MACHINE) {
        func_8007E2B4();
    }
}

void func_80079F1C(void) {
    Object_ClearAll();
    func_800792A8();
    func_80079080();
    func_8007E2B4();
}

void Object_LerpPosXToTarget(Object* object, s32 target, s32 stepScale) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        if (step > 0) {
            step /= stepScale;
            if (++step > 8) {
                step = 8;
            }
        } else {
            step /= stepScale;
            if (--step < -8) {
                step = -8;
            }
        }
    }
    OBJECT_LEFT(object) += step;
}

void Object_LerpPosYToTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 4;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) += step;
}

void Object_LerpToPos(Object* object, s32 xTarget, s32 yTarget) {
    Object_LerpPosXToTarget(object, xTarget, 4);
    Object_LerpPosYToTarget(object, yTarget);
}

void Object_LerpPosXToClampedTargetMaxStep(Object* object, s32 target, s32 maxStep) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (maxStep < ++step) {
                step = maxStep;
            }
            if (step < 8) {
                step = 8;
            }
            OBJECT_LEFT(object) += step;

            if (target < OBJECT_LEFT(object)) {
                OBJECT_LEFT(object) = target;
            }
        } else {
            step /= 4;
            if (--step < -maxStep) {
                step = -maxStep;
            }
            if (step > -8) {
                step = -8;
            }
            OBJECT_LEFT(object) += step;

            if (OBJECT_LEFT(object) < target) {
                OBJECT_LEFT(object) = target;
            }
        }
    }
}

void Object_LerpPosYToClampedTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 192) {
                step = 192;
            }
            if (step < 8) {
                step = 8;
            }
            OBJECT_TOP(object) += step;

            if (target < OBJECT_TOP(object)) {
                OBJECT_TOP(object) = target;
            }
        } else {
            step /= 4;
            if (--step < -192) {
                step = -192;
            }
            if (step >= -7) {
                step = -8;
            }
            OBJECT_TOP(object) += step;

            if (OBJECT_TOP(object) < target) {
                OBJECT_TOP(object) = target;
            }
        }
    }
}

// Duplicate function
void Object_LerpPosYToTarget2(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 4;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) += step;
}

void Object_LerpPosXToClampedTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        step = 200 / step;
        if (step > 0) {
            if (step > 24) {
                step = 24;
            }
            if (step < 16) {
                step = 16;
            }
            OBJECT_LEFT(object) += step;

            if (target < OBJECT_LEFT(object)) {
                OBJECT_LEFT(object) = target;
            }
        } else {
            if (step < -24) {
                step = -24;
            }
            if (step > -16) {
                step = -16;
            }
            OBJECT_LEFT(object) += step;

            if (OBJECT_LEFT(object) < target) {
                OBJECT_LEFT(object) = target;
            }
        }
    }
}

void Object_LerpAwayFromPosX(Object* object, s32 origin, s32 initialStep) {
    UNUSED s32 temp = OBJECT_LEFT(object);
    s32 step;

    step = origin - OBJECT_LEFT(object);
    if (origin == OBJECT_LEFT(object)) {
        OBJECT_LEFT(object) += initialStep;
        return;
    }
    if (step != 0) {
        if (step > 0) {
            step /= 8;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 8;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_LEFT(object) -= step;
}

void Object_LerpAwayFromPosY(Object* object, s32 origin, s32 initialStep) {
    UNUSED s32 temp = OBJECT_TOP(object);
    s32 step;

    step = origin - OBJECT_TOP(object);
    if (origin == OBJECT_TOP(object)) {
        OBJECT_TOP(object) += initialStep;
        return;
    }
    if (step != 0) {
        if (step > 0) {
            step /= 8;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 8;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) -= step;
}
