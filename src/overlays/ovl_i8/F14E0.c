#include "global.h"
#include "fzx_racer.h"
#include "tex_assets.h"

typedef struct unk_80144F74 {
    void* unk_00;
    s16 width;
    s16 height;
} unk_80144F74; // size = 0x8

typedef struct unk_80144F44 {
    s32 unk_00;
    unk_80144F74 unk_04;
} unk_80144F44; // size = 0xC

typedef struct unk_80144FE0 {
    Mtx unk_00;
    Vtx unk_40[4];
} unk_80144FE0; // size = 0x80

s32 D_80144FB0;
s32 D_i8_80144FB4;
s16 D_i8_80144FB8[4];
unk_800E51B8* D_i8_80144FC0;
unk_800E51B8* D_i8_80144FC4;
s16 D_i8_80144FC8;
s16 D_i8_80144FCA;
s16 D_i8_80144FCC;
s16 D_i8_80144FCE;
s16 D_i8_80144FD0;
s16 D_i8_80144FD2;
s16 D_i8_80144FD4;
s16 D_i8_80144FD6;
unk_80144FE0* D_i8_80144FD8;
unk_80144FE0 D_i8_80144FE0[2];

s32 D_i8_80144F40 = 0;

unk_80144F44 D_i8_80144F44[] = {
    { 3, { D_F25F69C, 64, 16 } }, // CHANGE COURSE
    { 2, { D_F25F334, 24, 16 } }, // QUIT
    { 0, { D_F260460, 64, 16 } }, // CLEAR RECORD
    { 1, { D_F260A98, 64, 16 } }, // CLEAR GHOST
};

unk_80144F74 D_i8_80144F74[] = {
    { D_F26064C, 96, 32 }, // ERASE COURSE DATA? (1)
    { D_F260C64, 96, 32 }, // ERASE COURSE DATA? (2)
};

unk_80144F74 D_i8_80144F84[] = {
    { D_F2637DC, 32, 16 }, // NO
    { D_F2636F0, 32, 16 }, // YES
};

extern s16 D_800CCFE8;
extern s8 D_800DCE5C;
extern s32 D_i2_80106F10;
extern unk_8010B7B0 D_8010B7B0;
extern s32 gDifficulty;

void func_i8_80143A78(void);

void func_i8_801439D0(void) {
    D_800CCFE8 = D_i2_80106F10 = 3;
    D_800DCE5C = 0;
    gDifficulty = MASTER;
    gRacers[0].character = CAPTAIN_FALCON;
    func_800A4EAC();
    func_i3_80116C4C();
    func_8008C7C8();
    func_80085610();
    func_8007F4E0(D_8010B7B0.unk_000[2], D_8010B7B0.unk_000[3]);
    func_i3_801365E0();
    func_8006D448();
    func_8006E478();
    func_8006EC7C();
    func_80071260(0);
    func_i8_80143A78();
}

bool func_i8_80143D30(s32);
bool func_i8_80143D84(s32);

extern s8 D_800CD3C0;
extern s8 D_800CD3C8;
extern s32 D_800F8514;

void func_i8_80143A78(void) {
    s32 i;
    unk_80144F44* var_s0;

    D_i8_80144F40 = D_800F8514;
    if ((D_800CD3C0 == 0) && (D_800CD3C8 == 0)) {
        D_i8_80144FB4 = 0x12;
    } else {
        D_i8_80144FB4 = 0x18;
    }

    for (i = 0; i < 4; i++, var_s0++) {
        switch (D_i8_80144F44[i].unk_00) {
            case 0:
                if (func_i8_80143D30(D_i8_80144F40)) {
                    D_i8_80144FB8[i] = 0;
                } else {
                    D_i8_80144FB8[i] = 1;
                }
                break;
            case 1:
                if (func_i8_80143D84(D_i8_80144F40)) {
                    D_i8_80144FB8[i] = 1;
                    D_i8_80144FD0 = 1;
                    D_i8_80144FD2 = D_i8_80144FD4 = 255;
                } else {
                    D_i8_80144FB8[i] = 0;
                    D_i8_80144FD0 = 0;
                }
                break;
            case 3:
                D_i8_80144FCA = i;
                D_i8_80144FB8[i] = 1;
                break;
            default:
                D_i8_80144FB8[i] = 1;
                break;
        }
    }
    D_80144FB0 = 0;
    D_i8_80144FD6 = 0;
    func_80078104(D_F25F070, 0x40, 0, 0, false);

    var_s0 = D_i8_80144F44;
    for (i = 0; i < 4; i++, var_s0++) {
        func_80078104(var_s0->unk_04.unk_00, var_s0->unk_04.width * var_s0->unk_04.height, 0, 1, false);
    }
    func_80078104(D_F26064C, 0xC00, 0, 1, false);
    func_80078104(D_F260C64, 0xC00, 0, 1, false);
    func_80078104(D_F263648, 0x100, 0, 1, false);
    func_80078104(D_F26369C, 0x100, 0, 1, false);
    func_80078104(D_F2637DC, 0x200, 0, 1, false);
    func_80078104(D_F2636F0, 0x200, 0, 1, false);
    func_80078104(D_F13A9E0, 0x100, 0, 0, false);
    func_i3_80139D20();
    func_80080A40(&D_i8_80144FC0);
    func_80080A40(&D_i8_80144FC4);
    func_80080A48();
}

bool func_i8_80143D30(s32 arg0) {
    s32 i;
    bool ret = true;

    for (i = 0; i < 5; i++) {
        if (D_802A6B40[arg0].unk_20[i] != MAX_TIMER) {
            ret = false;
            break;
        }
    }

    return ret;
}

bool func_i8_80143D84(s32 arg0) {
    s32 pad;
    bool ret = false;
    s32 pad2[2];
    unk_80141C88 sp18;

    func_i2_801014D4(&sp18);

    if (sp18.unk_04 == D_802A6B40[arg0].unk_00) {
        ret = true;
    }
    return ret;
}

s32 func_i8_80143F94(void);
s32 func_i8_80144144(void);
void func_i8_801443D0(void);
void func_i8_801447C0(void);

extern s16 D_800CD048;
extern s32 D_800CD3BC;
extern s32 D_800DCCFC;
extern Controller D_800DD180;

s32 func_i8_80143DDC(void) {
    s32 temp_v0;
    s32 var_v1;
    s32 sp1C;

    func_8007DABC(&D_800DD180);
    D_i8_80144FD8 = &D_i8_80144FE0[D_800DCCFC];
    func_800952F4();
    func_8008675C();
    func_i3_80136A6C();
    func_800A5028();
    func_80074844();
    if (D_i8_80144FD0 != 0) {
        func_i8_801447C0();
    }
    func_i3_8013A004();
    func_80080C0C();
    var_v1 = 6;
    sp1C = 0;
    if (D_i8_80144FD6 == 0) {
        switch (D_80144FB0) {
            case 0:
                temp_v0 = func_i8_80143F94();
                var_v1 = 6;
                if (temp_v0 == 1) {
                    sp1C = 1;
                } else if (temp_v0 == 2) {
                    var_v1 = 0x8013;
                }
                if (temp_v0 != 0) {
                    D_i8_80144FD6 = 1;
                }
                break;
            case 1:
                temp_v0 = func_i8_80144144();
                var_v1 = 6;
                if (temp_v0 == 1) {
                    var_v1 = 0x8013;
                } else if (temp_v0 == 2) {
                    var_v1 = 0x8007;
                }
                if (temp_v0 != 0) {
                    D_i8_80144FD6 = 1;
                }
                break;
            case 2:
                func_i8_801443D0();
                var_v1 = 6;
                break;
        }
    }
    if (sp1C != 0) {
        D_800CD3BC = D_800F8514;
        D_800CD048 = 8;
    } else if ((var_v1 == 6) && (D_i8_80144FD6 == 0) && (gRacers[0].unk_04 & 0x80000)) {
        D_800CD048 = 1;
    }
    return var_v1;
}

Gfx* func_i8_80144B34(Gfx*, s32, s32);
Gfx* func_i8_80144CDC(Gfx*, s32, s32);

extern s32 D_i2_80106DA4;
extern u16 D_800E416C;
extern u16 D_800E416E;

s32 func_i8_80143F94(void) {
    s32 sp2C;
    s32 sp28;

    if (D_i2_80106DA4 != 0) {
        return 0;
    }
    if (func_8008108C(D_i8_80144FC0, 0) != 0) {
        return 0;
    }
    func_i3_8013BF18(1);

    sp28 = D_800F8514;
    if (D_800E416C & BTN_RIGHT) {
        D_800F8514++;
        if (D_800F8514 >= D_i8_80144FB4) {
            D_800F8514 = 0;
        }
        func_i2_800FCD38(9, 0);
    } else if (D_800E416C & BTN_LEFT) {
        D_800F8514--;
        if (D_800F8514 < 0) {
            D_800F8514 = D_i8_80144FB4 - 1;
        }
        func_i2_800FCD38(9, 1);
    }

    if (sp28 != D_800F8514) {
        sp2C = 1;
        func_800BA8D8(0x1E);
    } else {
        sp2C = 0;
    }
    if (sp2C == 0) {
        if (D_800E416E & (BTN_A | BTN_START)) {
            D_i8_80144FC0 = func_80080AA8(0, 108, 50, 104, 100, GPACK_RGBA5551(0, 255, 0, 1), func_i8_80144B34);
            if (D_i8_80144FC0 != NULL) {
                D_80144FB0 = 1;
                D_i8_80144FC8 = 0;
                func_800BA8D8(0x21);
                func_i3_8013BF18(0);
            }
        } else if (D_800E416E & BTN_B) {
            sp2C = 2;
            func_800BA8D8(0x10);
        }
    }
    return sp2C;
}

s32 func_i8_80144144(void) {
    s32 var_v0;
    s32 var_t0;
    s32 sp2C;
    s32 sp28;

    if (func_8008108C(D_i8_80144FC0, 1) == 0) {
        return 0;
    }
    sp2C = 0;
    sp28 = D_i8_80144FC8;
    // clang-format off
    if (D_800E416C & BTN_UP) {
        if (--D_i8_80144FC8 < 0) { D_i8_80144FC8 = 3; }

        while (D_i8_80144FB8[D_i8_80144FC8] == 0) {
            if (--D_i8_80144FC8 < 0) { D_i8_80144FC8 = 3; }
        }
    } else if (D_800E416C & BTN_DOWN) {
        if (++D_i8_80144FC8 > 3) { D_i8_80144FC8 = 0; }

        while (D_i8_80144FB8[D_i8_80144FC8] == 0) {
            if (++D_i8_80144FC8 > 3) { D_i8_80144FC8 = 0; }
        }
    }
    // clang-format on
    if (sp28 != D_i8_80144FC8) {
        func_800BA8D8(0x1E);
    }
    if (D_800E416E & (BTN_A | BTN_START)) {
        var_t0 = 0;

        switch (D_i8_80144F44[D_i8_80144FC8].unk_00) {
            case 3:
                var_t0 = 1;
                sp2C = 1;
                break;
            case 2:
                var_t0 = 1;
                sp2C = 2;
                break;
            case 0:
            case 1:
                if (D_i8_80144F44[D_i8_80144FC8].unk_00 == 0) {
                    D_i8_80144FCE = 0;
                    var_v0 = 120;
                } else {
                    D_i8_80144FCE = 1;
                    var_v0 = 142;
                }

                D_i8_80144FC4 = func_80080AA8(1, 120, var_v0, 148, 80, GPACK_RGBA5551(255, 0, 0, 1), func_i8_80144CDC);

                var_t0 = 0;
                if (D_i8_80144FC4 != NULL) {
                    D_i8_80144FCC = 0;
                    var_t0 = 1;
                    D_80144FB0 = 2;
                }
                break;
        }

        if (var_t0 != 0) {
            func_800BA8D8(0x21);
        }
    } else if (D_800E416E & BTN_B) {
        D_80144FB0 = 0;
        func_80080BDC(D_i8_80144FC0);
        func_800BA8D8(0x10);
    }
    return sp2C;
}

void func_i8_801443D0(void) {
    s32 sp1C;
    s32 sp18;

    if (func_8008108C(D_i8_80144FC4, 1) != 0) {
        sp1C = D_i8_80144FCC;
        if (D_800E416C & BTN_LEFT) {
            if (--D_i8_80144FCC < 0) {
                D_i8_80144FCC = 1;
            }
        } else if (D_800E416C & BTN_RIGHT) {
            if (++D_i8_80144FCC > 1) {
                D_i8_80144FCC = 0;
            }
        }
        if (sp1C != D_i8_80144FCC) {
            func_800BA8D8(0x1E);
        }
        sp18 = 0;
        if (D_800E416E & (BTN_A | BTN_START)) {
            sp18 = 1;
            if (D_i8_80144FCC == 0) {
                func_800BA8D8(0x10);
            } else {
                if (D_i8_80144FCE == 0) {
                    func_i2_801017B8(D_800F8514);
                } else if (D_i8_80144FCE == 1) {
                    func_i2_801018A8(D_800F8514);
                    D_i8_80144FD0 = 2;
                }
                D_i8_80144FB8[D_i8_80144FC8] = 0;
                D_i8_80144FC8 = D_i8_80144FCA;
                func_800BA8D8(5);
            }
        } else if (D_800E416E & BTN_B) {
            sp18 = 1;
            func_800BA8D8(0x10);
        }
        if (sp18 != 0) {
            D_80144FB0 = 1;
            func_80080BDC(D_i8_80144FC4);
        }
    }
}

extern FrameBuffer* D_800DCCD0[];
extern s32 D_800DCD04;
extern Vtx* D_800E5ECC;
extern Vtx* D_800E5ED0;
extern Vtx* D_800F8520;
extern GfxPool* D_800DCCF0;

extern Gfx D_303A810[];

Gfx* func_i8_801449B8(Gfx*);

Gfx* func_i8_80144568(Gfx* gfx) {

    if (D_i2_80106F10 != 0) {
        D_i2_80106F10--;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPPipelineMode(gfx++, G_PM_NPRIMITIVE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    gSPDisplayList(gfx++, D_303A810);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(D_800DCCD0[D_800DCD04]));

    D_800F8520 = D_800DCCF0->unk_10008;
    D_800E5ECC = D_800DCCF0->unk_21B48;
    D_800E5ED0 = &D_800DCCF0->unk_21B48[0x7FF];
    gfx = func_i3_801381DC(gfx, 0, 0);
    gfx = func_800A9938(gfx, 0);
    gfx = func_8006DAAC(gfx, 0);
    gfx = func_i3_8013A360(gfx, D_i8_80144F40);
    if (D_i8_80144FD0 != 0) {
        gfx = func_i8_801449B8(gfx);
    }
    return func_80080E90(gfx);
}

void func_i8_801447C0(void) {
    Vtx* vtx;
    u16 temp;

    switch (D_i8_80144FD0) {
        case 1:
            break;
        case 2:
            if (D_i8_80144FD4 > 0) {
                D_i8_80144FD4 -= 10;
                if (D_i8_80144FD4 < 0) {
                    D_i8_80144FD4 = 0;
                }
            }
            if (D_i8_80144FD4 == 0) {
                D_i8_80144FD2 -= 10;
                if (D_i8_80144FD2 < 0) {
                    D_i8_80144FD2 = 0;
                }
            }
            if ((D_i8_80144FD4 == 0) && (D_i8_80144FD2 == 0)) {
                D_i8_80144FD0 = 0;
                return;
            }
            break;
    }

    func_8006D2E0(&D_i8_80144FD8->unk_00, NULL, 1.0f, 0.0f, 319.0f, 239.0f, 0.0f, -100.0f, 100.0f);

    vtx = D_i8_80144FD8->unk_40;
    // FAKE
    temp = -0x10;

    // clang-format off
    vtx->v.ob[0] = 236;           \
    vtx->v.ob[1] = 60;            \
    vtx->v.ob[2] = 0;             \
    vtx->v.flag = 0;              \
    vtx->v.tc[0] = temp;          \
    vtx->v.tc[1] = temp;          \
    vtx->v.cn[0] = 255;           \
    vtx->v.cn[1] = 255;           \
    vtx->v.cn[2] = 255;           \
    vtx->v.cn[3] = D_i8_80144FD2;
    vtx++;
    
    vtx->v.ob[0] = 267;           \
    vtx->v.ob[1] = 60;            \
    vtx->v.ob[2] = 0;             \
    vtx->v.flag = 0;              \
    vtx->v.tc[0] = 0x400;         \
    vtx->v.tc[1] = 0;             \
    vtx->v.cn[0] = 255;           \
    vtx->v.cn[1] = 255;           \
    vtx->v.cn[2] = 255;           \
    vtx->v.cn[3] = D_i8_80144FD2;
    vtx++;
    
    vtx->v.ob[0] = 236;           \
    vtx->v.ob[1] = 75;            \
    vtx->v.ob[2] = 0;             \
    vtx->v.flag = 0;              \
    vtx->v.tc[0] = 0;             \
    vtx->v.tc[1] = 0x200;         \
    vtx->v.cn[0] = 255;           \
    vtx->v.cn[1] = 255;           \
    vtx->v.cn[2] = 255;           \
    vtx->v.cn[3] = D_i8_80144FD4;
    vtx++;
    
    vtx->v.ob[0] = 267;           \
    vtx->v.ob[1] = 75;            \
    vtx->v.ob[2] = 0;             \
    vtx->v.flag = 0;              \
    vtx->v.tc[0] = 0x400;         \
    vtx->v.tc[1] = 0x200;         \
    vtx->v.cn[0] = 255;           \
    vtx->v.cn[1] = 255;           \
    vtx->v.cn[2] = 255;           \
    vtx->v.cn[3] = D_i8_80144FD4;
    vtx++;
    // clang-format on
}

extern Mtx D_2000000[];
extern Gfx D_8014810[];

Gfx* func_i8_801449B8(Gfx* gfx) {

    gfx = func_8006A00C(gfx, 0);
    gSPDisplayList(gfx++, D_8014810);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    gSPMatrix(gfx++, &D_i8_80144FD8->unk_00, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gfx++, D_i8_80144FD8->unk_40, 4, 0);

    gDPLoadTextureBlock_4b(gfx++, func_800783AC(D_F13A9E0), G_IM_FMT_I, 32, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);

    return gfx;
}

extern Gfx D_8014940[];

Gfx* func_i8_80144B34(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 temp_s4;
    s32 i;
    unk_80144F74* temp_s1;
    TexturePtr var_s2;
    unk_80144F44* var_s5;

    gSPDisplayList(gfx++, D_8014940);

    var_s5 = D_i8_80144F44;
    for (i = 0; i < 4; i++, var_s5++) {
        temp_s1 = &var_s5->unk_04;
        gDPPipeSync(gfx++);

        if (i != D_i8_80144FC8) {
            if (D_i8_80144FB8[i] != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8007DB28(gfx, 0);
        }

        if (i == 0) {
            var_s2 = func_800783AC(D_F25F070);
        } else {
            var_s2 = NULL;
        }

        temp_s4 = ((0x68 - temp_s1->width) / 2) - 0x14;
        gfx = func_8007E410(gfx, func_800783AC(temp_s1->unk_00), var_s2, G_IM_FMT_CI, 1, arg1 + temp_s4 + 20,
                            arg2 + 10 + i * 20, temp_s1->width, temp_s1->height, 3);
    }

    return gfx;
}

Gfx* func_i8_80144CDC(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_80144F74* temp_s0;
    s32 sp58;
    s32 pad;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    temp_s0 = &D_i8_80144F74[D_i8_80144FCE];
    sp58 = (0x7C - temp_s0->width) / 2;

    gfx = func_8007E410(gfx, func_800783AC(temp_s0->unk_00), func_800783AC(D_F25F070), G_IM_FMT_CI, 1, arg1 + sp58 + 12,
                        arg2 + 10, temp_s0->width, temp_s0->height, 3);

    gDPPipeSync(gfx++);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_8007E410(gfx, func_800783AC(D_F263648), NULL, G_IM_FMT_CI, 1, arg1 + 24, arg2 + 50, 16, 16, 0);
    gfx = func_8007E410(gfx, func_800783AC(D_F26369C), NULL, G_IM_FMT_CI, 1, arg1 + 99, arg2 + 50, 16, 16, 0);

    temp_s0 = &D_i8_80144F84[D_i8_80144FCC];
    sp58 = (0x3B - temp_s0->width) / 2;
    return func_8007E410(gfx, func_800783AC(temp_s0->unk_00), NULL, G_IM_FMT_CI, 1, arg1 + sp58 + 42, arg2 + 50,
                         temp_s0->width, temp_s0->height, 0);
}
