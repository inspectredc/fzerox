#include "global.h"
#include "fzx_game.h"
#include "segment_symbols.h"

unk_800E33E0 D_800E33E0[200];
s32 D_800E3A20;
unk_800E3A28 D_800E3A28[32];
unk_800E3F28 D_800E3F28[16];
unk_800E4068 D_800E4068[16];

void func_80077CF0(s32 segAddr, size_t size, u8* startAddr) {
    osInvalDCache(startAddr, size);
    func_800765CC(SEGMENT_ROM_START(segment_2B9EA0) + SEGMENT_OFFSET(segAddr), startAddr, size);
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
        return ((unk_800E33E0*) (var_v1 + var_a3))->unk_04;
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
    D_800E3F28[arg0].unk_06 = ((unk_800E33E0*) (arg2 + arg1))->unk_04;
    temp_a3 = arg2[D_800E3F28[arg0].unk_04].unk_00;

    if (D_800E3F28[arg0].unk_0A != 0) {
        func_800790A4(temp_a3, D_800E3F28[arg0].unk_0C);
        D_800E3F28[arg0].unk_0A = 0;
    } else {
        func_800790A4(temp_a3, D_800E3F28[arg0].unk_10);
        D_800E3F28[arg0].unk_0A = 1;
    }
}

void func_80079480(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        D_800E3A28[i].unk_00 = 0;
    }
}

void func_800794B0(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 i = 0;
    unk_800E3A28* var_s0 = D_800E3A28;

    while (true) {
        // clang-format off
        if (var_s0->unk_00 == 0) {   \
            var_s0->unk_00 = arg0;   \
            var_s0->unk_04 = 0;      \
            var_s0->unk_08 = 0;      \
            var_s0->unk_0C = arg1;   \
            var_s0->unk_10 = arg2;   \
            var_s0->unk_14 = arg3;   \
            var_s0->unk_15 = 1;      \
            var_s0->unk_1C = 0;      \
            var_s0->unk_20 = 0;      \
            break;
        }
        // clang-format on
        if (++i > 0x20) {
            return;
        }
        var_s0++;
    }

    switch (arg0) {
        case 0xA:
            func_i4_8011B06C(var_s0);
            break;
        case 0xE:
            func_i4_8011B0C8();
            break;
        case 0xF:
            func_i4_8011B0D0(var_s0);
            break;
        case 0x10:
            func_i4_8011B134();
            break;
        case 0x11:
            func_i4_8011B13C(var_s0);
            break;
        case 0x12:
            func_i4_8011B1E4();
            break;
        case 0x13:
            func_i4_8011B1EC();
            break;
        case 0x14:
            func_i4_8011B214(var_s0);
            break;
        case 0x1F:
            func_i4_80116E64();
            break;
        case 0x20:
            func_i4_80116E8C(var_s0);
            break;
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            func_i4_80116F48(var_s0);
            break;
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            func_i4_80117008(var_s0);
            break;
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            func_i4_80117038(var_s0);
            break;
        case 0x2C:
            func_i4_8011706C();
            break;
        case 0x2D:
            func_i4_80117094(var_s0);
            break;
        case 0x35:
            func_i4_80117400(var_s0);
            break;
        case 0x33:
            func_i4_8011764C();
            break;
        case 0x34:
            func_i4_801176BC();
            break;
        case 0x36:
            func_i4_8011770C(var_s0);
            break;
        case 0x37:
            func_i4_8011774C();
            break;
        case 0x2E:
            func_i4_80117854(var_s0);
            break;
        case 0x39:
            func_i4_8011788C(var_s0);
            break;
        case 0x2F:
            func_i4_80117774(var_s0);
            break;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
            func_i4_80117808();
            break;
        case 0x50:
            func_i6_801167EC(var_s0);
            break;
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
            func_i6_80116894(var_s0);
            break;
        case 0x59:
            func_i6_801168EC(var_s0);
            break;
        case 0x5A:
            func_i6_80116934();
            break;
        case 0x5C:
            func_i6_80116990();
            break;
        case 0x5F:
            func_i6_801169EC();
            break;
        case 0x5D:
            func_i6_80116A48(var_s0);
            break;
        case 0x5E:
            func_i6_80116A80(var_s0);
            break;
        case 0x78:
            func_i5_80117684(var_s0);
            break;
        case 0x79:
            func_i5_80117758();
            break;
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
            func_i5_801177EC(var_s0);
            break;
        case 0x83:
            func_i5_801178D8(var_s0);
            break;
        case 0x80:
            func_i5_80117934(var_s0);
            break;
        case 0x81:
            func_i5_8011796C(var_s0);
            break;
        case 0x84:
            func_i5_801179A8(var_s0);
            break;
        case 0x85:
            func_i5_80117A2C(var_s0);
            break;
        default:
            break;
    }
}

Gfx* func_800797CC(Gfx* gfx, unk_800E3A28* arg1) {

    if (arg1->unk_15 == 0) {
        return gfx;
    }

    switch (arg1->unk_00) {
        case 0:
            break;
        case 0x5:
            gfx = func_8007ABA4(func_8007AE70(func_8007AB88(gfx)));
            break;
        case 0xA:
            gfx = func_i4_8011B380(gfx, arg1);
            break;
        case 0xE:
            gfx = func_i4_8011B3DC(gfx, arg1);
            break;
        case 0xC:
            gfx = func_8007AF40(gfx, 118, 164, 203, 217, 255, 255, 255, 48);
            break;
        case 0xD:
            gfx = func_8007AE8C(gfx, 12, 8, 307, 231, 0, 0, 0, 0);
            break;
        case 0xF:
            gfx = func_i4_8011B3E8(gfx, arg1);
            break;
        case 0x10:
            gfx = func_i4_8011B438(gfx, arg1);
            break;
        case 0x11:
            gfx = func_i4_8011B444(gfx, arg1);
            break;
        case 0x12:
            gfx = func_i4_8011B668(gfx, arg1);
            break;
        case 0x13:
            gfx = func_i4_8011B674(gfx, arg1);
            break;
        case 0x14:
            gfx = func_i4_8011B6C4(gfx, arg1);
            break;
        case 0x1E:
            gfx = func_i4_801178C4(gfx);
            break;
        case 0x3B:
            gfx = func_8007AC48(gfx, 0x18, 0x18, 0x18);
            break;
        case 0x1F:
            gfx = func_i4_80117B74(gfx, arg1);
            break;
        case 0x20:
            gfx = func_i4_80117BE0(gfx, arg1);
            break;
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
            gfx = func_i4_80117D10(gfx, arg1);
            break;
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
            gfx = func_i4_801180EC(gfx, arg1);
            break;
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
            gfx = func_i4_801181C0(gfx, arg1);
            break;
        case 0x2C:
            gfx = func_i4_8011821C(gfx, arg1);
            break;
        case 0x2D:
            gfx = func_i4_80118414(gfx, arg1);
            break;
        case 0x2E:
            gfx = func_i4_80118734(gfx, arg1);
            break;
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
            gfx = func_i4_80117E98(gfx, arg1);
            break;
        case 0x35:
            gfx = func_i4_80118918(gfx, arg1);
            break;
        case 0x32:
            gfx = func_i4_801187C0(gfx);
            break;
        case 0x33:
            gfx = func_i4_80118EC8(gfx, arg1);
            break;
        case 0x34:
            gfx = func_i4_80119170(gfx, arg1);
            break;
        case 0x3A:
            gfx = func_i4_801193B8(gfx, arg1);
            break;
        case 0x36:
            gfx = func_i4_801194F8(gfx, arg1);
            break;
        case 0x37:
            gfx = func_i4_80119574(gfx, arg1);
            break;
        case 0x38:
            gfx = func_i4_801197A0(gfx);
            break;
        case 0x39:
            gfx = func_i4_80119B50(gfx, arg1);
            break;
        case 0x2F:
            gfx = func_i4_80119834(gfx, arg1);
            break;
        case 0x30:
            gfx = func_i4_80119A64(gfx, arg1);
            break;
        case 0x50:
            gfx = func_i6_80116C78(gfx, arg1);
            break;
        case 0x51:
        case 0x52:
        case 0x53:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
            gfx = func_i6_80116AA8(gfx, arg1);
            break;
        case 0x59:
            gfx = func_i6_80117400(gfx, arg1);
            break;
        case 0x5A:
            gfx = func_i6_801174DC(gfx, arg1);
            break;
        case 0x5C:
            gfx = func_i6_80117760(gfx, arg1);
            break;
        case 0x5F:
            gfx = func_i6_80117A18(gfx, arg1);
            break;
        case 0x5D:
            gfx = func_i6_80117C50(gfx, arg1);
            break;
        case 0x64:
        case 0x8C:
            gfx = func_8007AC48(gfx, 0, 0, 0);
            break;
        case 0x78:
            gfx = func_i5_80117A98(gfx, arg1);
            break;
        case 0x79:
            gfx = func_i5_80117BE0(gfx, arg1);
            break;
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x7E:
        case 0x7F:
            gfx = func_i5_80117C48(gfx, arg1);
            break;
        case 0x83:
            gfx = func_i5_80117FB4(gfx, arg1);
            break;
        case 0x80:
            gfx = func_i5_80118100(gfx, arg1);
            break;
        case 0x81:
            gfx = func_i5_80118168(gfx, arg1);
            break;
        case 0x82:
            gfx = func_i5_801182DC(gfx);
            break;
        case 0x84:
            gfx = func_i5_80118674(gfx, arg1);
            break;
        case 0x85:
            gfx = func_i5_80118790(gfx, arg1);
            break;
    }
    return gfx;
}

Gfx* func_80079BC8(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 32; i++) {
        switch (D_800E3A28[i].unk_00) {
            case 0:
                break;
            case 0xA:
                func_i4_8011B2E0(&D_800E3A28[i]);
                break;
            case 0x14:
                func_i4_8011B874(&D_800E3A28[i]);
                break;
            case 0x5D:
                func_i6_80117D3C(&D_800E3A28[i]);
                break;
            case 0x5E:
                func_i6_80117DE0(&D_800E3A28[i]);
                break;
            case 0x20:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_80119BB8(&D_800E3A28[i]);
                break;
            case 0x3C:
            case 0x3D:
            case 0x3E:
            case 0x3F:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_80119BC0(&D_800E3A28[i]);
                break;
            case 0x21:
            case 0x22:
            case 0x23:
            case 0x24:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_80119C80(&D_800E3A28[i]);
                break;
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
                func_i4_80119D0C(&D_800E3A28[i]);
                break;
            case 0x2C:
                func_i4_80119D84(&D_800E3A28[i]);
                break;
            case 0x2D:
                func_i4_80119D8C(&D_800E3A28[i]);
                break;
            case 0x35:
                func_i4_8011A08C(&D_800E3A28[i]);
                break;
            case 0x36:
                D_800E3F28[D_800E3A28[i].unk_18].unk_04 = 0;
                func_i4_8011A73C(&D_800E3A28[i]);
                break;
            case 0x2E:
                func_i4_8011A6A0(&D_800E3A28[i]);
                break;
            case 0x39:
                func_i4_8011A6EC(&D_800E3A28[i]);
                break;
            case 0x79:
                func_i5_80118928(&D_800E3A28[i]);
                break;
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
                func_i5_801189C4(&D_800E3A28[i]);
                break;
            case 0x80:
                func_i5_80118D44(&D_800E3A28[i]);
                break;
            case 0x81:
                func_i5_80118D94(&D_800E3A28[i]);
                break;
            case 0x84:
                func_i5_80118F24(&D_800E3A28[i]);
                break;
            case 0x85:
                func_i5_80118F84(&D_800E3A28[i]);
                break;
        }
    }

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 32; i++) {
            if (j == D_800E3A28[i].unk_14) {
                gfx = func_800797CC(gfx, &D_800E3A28[i]);
            }
        }
    }

    return gfx;
}

unk_800E3A28* func_80079E88(s32 arg0) {
    unk_800E3A28* var_v1;

    var_v1 = D_800E3A28;

    while (true) {
        if (arg0 == var_v1->unk_00) {
            break;
        }
        var_v1++;
        if ((u32) D_800E3F28 < (u32) var_v1) {
            return NULL;
        }
    }
    return var_v1;
}

extern s32 gGameMode;

void func_80079EC8(void) {
    func_80077D44();
    func_80079480();
    func_800792A8();
    func_80079080();
    if (gGameMode != GAMEMODE_10) {
        func_8007E2B4();
    }
}

void func_80079F1C(void) {
    func_80079480();
    func_800792A8();
    func_80079080();
    func_8007E2B4();
}

void func_80079F54(unk_800E3A28* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_0C;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= arg2;
            if (++var_v0 > 8) {
                var_v0 = 8;
            }
        } else {
            var_v0 /= arg2;
            if (--var_v0 < -8) {
                var_v0 = -8;
            }
        }
    }
    arg0->unk_0C += var_v0;
}

void func_80079FFC(unk_800E3A28* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_10;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (++var_v0 > 16) {
                var_v0 = 16;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -16) {
                var_v0 = -16;
            }
        }
    }
    arg0->unk_10 += var_v0;
}

void func_8007A06C(unk_800E3A28* arg0, s32 arg1, s32 arg2) {
    func_80079F54(arg0, arg1, 4);
    func_80079FFC(arg0, arg2);
}

void func_8007A0A0(unk_800E3A28* arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_0C;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (arg2 < ++var_v0) {
                var_v0 = arg2;
            }
            if (var_v0 < 8) {
                var_v0 = 8;
            }
            arg0->unk_0C += var_v0;

            if (arg1 < arg0->unk_0C) {
                arg0->unk_0C = arg1;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -arg2) {
                var_v0 = -arg2;
            }
            if (var_v0 > -8) {
                var_v0 = -8;
            }
            arg0->unk_0C += var_v0;

            if (arg0->unk_0C < arg1) {
                arg0->unk_0C = arg1;
            }
        }
    }
}

void func_8007A154(unk_800E3A28* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_10;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (++var_v0 > 0xC0) {
                var_v0 = 0xC0;
            }
            if (var_v0 < 8) {
                var_v0 = 8;
            }
            arg0->unk_10 += var_v0;

            if (arg1 < arg0->unk_10) {
                arg0->unk_10 = arg1;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -0xC0) {
                var_v0 = -0xC0;
            }
            if (var_v0 >= -7) {
                var_v0 = -8;
            }
            arg0->unk_10 += var_v0;

            if (arg0->unk_10 < arg1) {
                arg0->unk_10 = arg1;
            }
        }
    }
}

void func_8007A208(unk_800E3A28* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_10;
    if (var_v0 != 0) {
        if (var_v0 > 0) {
            var_v0 /= 4;
            if (++var_v0 > 16) {
                var_v0 = 16;
            }
        } else {
            var_v0 /= 4;
            if (--var_v0 < -16) {
                var_v0 = -16;
            }
        }
    }
    arg0->unk_10 += var_v0;
}

void func_8007A278(unk_800E3A28* arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg1 - arg0->unk_0C;
    if (var_v0 != 0) {
        var_v0 = 200 / var_v0;
        if (var_v0 > 0) {
            if (var_v0 > 24) {
                var_v0 = 24;
            }
            if (var_v0 < 16) {
                var_v0 = 16;
            }
            arg0->unk_0C += var_v0;

            if (arg1 < arg0->unk_0C) {
                arg0->unk_0C = arg1;
            }
        } else {
            if (var_v0 < -24) {
                var_v0 = -24;
            }
            if (var_v0 > -16) {
                var_v0 = -16;
            }
            arg0->unk_0C += var_v0;

            if (arg0->unk_0C < arg1) {
                arg0->unk_0C = arg1;
            }
        }
    }
}

void func_8007A334(unk_800E3A28* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 temp = arg0->unk_0C;
    s32 var_v1;

    var_v1 = arg1 - arg0->unk_0C;
    if (arg1 == arg0->unk_0C) {
        arg0->unk_0C += arg2;
        return;
    }
    if (var_v1 != 0) {
        if (var_v1 > 0) {
            var_v1 /= 8;
            if (++var_v1 > 16) {
                var_v1 = 16;
            }
        } else {
            var_v1 /= 8;
            if (--var_v1 < -16) {
                var_v1 = -16;
            }
        }
    }
    arg0->unk_0C -= var_v1;
}

void func_8007A3B8(unk_800E3A28* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 temp = arg0->unk_10;
    s32 var_v1;

    var_v1 = arg1 - arg0->unk_10;
    if (arg1 == arg0->unk_10) {
        arg0->unk_10 += arg2;
        return;
    }
    if (var_v1 != 0) {
        if (var_v1 > 0) {
            var_v1 /= 8;
            if (++var_v1 > 16) {
                var_v1 = 16;
            }
        } else {
            var_v1 /= 8;
            if (--var_v1 < -16) {
                var_v1 = -16;
            }
        }
    }
    arg0->unk_10 -= var_v1;
}
