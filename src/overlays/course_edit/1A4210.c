#include "global.h"
#include "leo/mfs.h"
#include "fzx_course.h"
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

UNUSED s32 D_xk2_80104EF0 = 0;
UNUSED s32 D_xk2_80104EF4 = 0;
UNUSED s32 D_xk2_80104EF8 = -1;
UNUSED s32 D_xk2_80104EFC = 60;
UNUSED s32 D_xk2_80104F00 = 0;
s32 D_xk2_80104F04 = 0;

UNUSED s32 D_xk2_80104F08[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

u8 D_xk2_80104F28[] = {
    0x97, 0xDB, 0xC3, 0xB8, 0xC4, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104F30[] = {
    0xA6, 0xB6, 0xB9, 0xC0, 0xB2, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104F38[] = {
    0xCC, 0xA7, 0xB2, 0xD9, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104F40[] = {
    0xA6,
    0x00,
    0x00,
    0x00,
};

u8 D_xk2_80104F44[] = {
    0xBE, 0xDD, 0xC0, 0xB8, 0xBC, 0xC3, 0xB8, 0x8B, 0xBB, 0xB2, 0x00, 0x00,
};

u8 D_xk2_80104F50[] = {
    0x81, 0xBD, 0x8E, 0xC6, 0xB6, 0xB6, 0xAF, 0xC3, 0xB2, 0xD9, 0x00, 0x00,
};

u8 D_xk2_80104F5C[] = {
    0xA6, 0xBE, 0xDD, 0xC0, 0xB8, 0xBD, 0xD9, 0xC4, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104F68[] = {
    0xA6, 0xB6, 0xB2, 0x87, 0xAE, 0x8E, 0xB7, 0xCF, 0xBD, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104F74[] = {
    0x02, 0xBB, 0xB8, 0xBE, 0xB2, 0xBC, 0xC0, 0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xA6, 0x20, 0x01, 0xC3,
    0xBD, 0xC4, 0x02, 0xBF, 0xB3, 0xBA, 0xB3, 0x8E, 0xB7, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104F94[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xA6, 0x20, 0x01, 0xD7, 0xB2, 0xDD, 0x02,
    0x8E, 0x20, 0xCB, 0xAE, 0xB3, 0x87, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80104FAC[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xC9, 0xB5, 0xB7, 0x90, 0xBC, 0xAE, 0xA6, 0xBE,
    0xB2, 0x84, 0xDD, 0xBC, 0xC3, 0x20, 0xC1, 0xAE, 0xB8, 0xBE, 0xDD, 0xA6, 0xC2, 0xB8,
    0xD8, 0xD4, 0xBD, 0xB8, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80104FD4[] = {
    0x01, 0x93, 0xB0, 0xBD, 0x02, 0xC4, 0xC5, 0xD9, 0x01, 0xBA, 0xB0, 0xBD,
    0x02, 0xA6, 0x20, 0x02, 0xC2, 0xB8, 0xD8, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80104FEC[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xC9, 0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20,
    0x02, 0xB2, 0x8F, 0xB3, 0xC5, 0x8F, 0xBB, 0xBE, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105008[] = {
    0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC9, 0x01, 0xC0, 0xB2, 0x97, 0x02, 0xC5, 0x8F, 0x02,
    0xA6, 0x20, 0x02, 0xCD, 0xDD, 0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105024[] = {
    0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC6, 0x02, 0xB5, 0xB9, 0xD9, 0x01, 0xBC, 0xB6, 0xB9, 0x20, 0x02, 0xCF, 0xC0,
    0xCA, 0x01, 0x91, 0xD9, 0x02, 0xC5, 0x8F, 0x02, 0xA6, 0x20, 0x02, 0xB2, 0xDA, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80105048[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x01, 0xBC, 0xB0, 0xDD, 0x02, 0xC4, 0x02,
    0xBF, 0xD7, 0xA6, 0x20, 0x02, 0xCD, 0xDD, 0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_80105064[] = {
    0x01, 0x42, 0x47, 0x4D, 0x02, 0xA6, 0x20, 0x02, 0xCD, 0xDD,
    0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105078[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20,
    0x01, 0xBE, 0xAF, 0xC4, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105090[] = {
    0x01, 0xBD, 0xC0, 0xB0, 0xC4, 0x02, 0xC9, 0x20, 0x02, 0x90, 0xBC, 0xAE, 0x02, 0xA6,
    0x20, 0x02, 0xB2, 0x8F, 0xB3, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_801050AC[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0x89, 0xDD, 0xC0, 0xB2, 0x02, 0xA6, 0x20, 0x02, 0xC1, 0xAD, 0xB3,
    0xBC, 0xDD, 0x02, 0xC6, 0x02, 0xB2, 0x8F, 0xB3, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_801050CC[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xC9, 0x20, 0x02, 0xBC, 0xDD, 0xBA, 0xB3, 0xCE, 0xB3,
    0xBA, 0xB3, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_801050E8[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0x89, 0xDD, 0xC0, 0xB2, 0x02,
    0xA6, 0x20, 0x02, 0xB9, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_801050FC[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xCD, 0xB2, 0xBA,
    0xB3, 0x02, 0xB2, 0x8F, 0xB3, 0x02, 0xBB, 0xBE, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_80105114[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xC9, 0x20, 0x02, 0xC0, 0xB6, 0xBB,
    0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_8010512C[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xC1, 0xAD, 0xB3, 0xBC, 0xDD, 0x02, 0xC6,
    0x20, 0x02, 0xD0, 0xC1, 0xCA, 0x90, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_8010514C[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xC1, 0xAD, 0xB3, 0xBC, 0xDD,
    0x02, 0xC6, 0x20, 0x02, 0xD0, 0xC1, 0x02, 0xC9, 0x20, 0x02, 0xB6, 0xC0, 0xD1, 0xB7,
    0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105174[] = {
    0x02, 0xD0, 0xC1, 0xCA, 0x90, 0x02, 0xC9, 0x20, 0x02, 0xC1, 0xAD, 0xB3, 0xBC, 0xDD,
    0x02, 0xC3, 0xDD, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80105190[] = {
    0x02, 0xBE, 0xDD, 0xC0, 0xB8, 0xBC, 0xC0, 0x01, 0x99, 0xB2, 0xDD, 0xC4,
    0x02, 0xA6, 0x20, 0x02, 0xB9, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_801051A8[] = {
    0x02, 0xBE, 0xDD, 0xC0, 0xB8, 0xBC, 0xC0, 0x02, 0xCC, 0xB8, 0xBD, 0xB3, 0x02, 0xC9,
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xCF, 0xAF, 0xBD, 0x83, 0x02,
    0xC6, 0x02, 0xC5, 0xD7, 0x93, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_801051D0[] = {
    0x01, 0x81, 0xB0, 0x8F, 0xDA, 0xB0, 0xD9, 0x02, 0xC9, 0x02, 0xB1, 0xD9, 0x20, 0x02, 0xCC, 0xC2,
    0xB3, 0x02, 0xC9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_801051F0[] = {
    0x02, 0xC0, 0xB6, 0xB2, 0x01, 0x81, 0xB0, 0x8F, 0xDA, 0xB0, 0xD9, 0x02, 0x81, 0x01, 0xBE, 0xAF,
    0xC4, 0x02, 0xBB, 0xDA, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80105210[] = {
    0x01, 0x81, 0xB0, 0x8F, 0xDA, 0xB0, 0xD9, 0x02, 0x81, 0x02, 0xC5, 0xB2, 0x20, 0x02, 0xB7, 0xB9,
    0xDD, 0x02, 0xC5, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105230[] = {
    0x01, 0xC4, 0xDD, 0xC8, 0xD9, 0x02, 0xC2, 0xB7, 0x02, 0xC9,
    0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_80105244[] = {
    0x01, 0x95, 0xB2, 0x97, 0x02, 0x87, 0xAE, 0xB3, 0x02, 0xC9, 0x20, 0x02, 0xC5, 0xB6,
    0xA6, 0xCA, 0xBC, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_80105260[] = {
    0x01, 0xCA, 0xB0, 0xCC, 0x01, 0x95, 0xB2, 0x97, 0x02, 0x87, 0xAE, 0xB3, 0x02, 0xC9, 0x20, 0x02,
    0xC5, 0xB6, 0xA6, 0xCA, 0xBC, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_80105280[] = {
    0x01, 0x95, 0xB2, 0x97, 0x02, 0x87, 0xAE, 0xB3, 0x02, 0xC9, 0x20, 0x02, 0xBF, 0xC4,
    0xA6, 0xCA, 0xBC, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_8010529C[] = {
    0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC4, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC9, 0x02, 0xB1, 0xB2, 0x8B, 0x02,
    0xC6, 0x20, 0x02, 0xB8, 0xB3, 0xB6, 0xDD, 0x02, 0xA6, 0x20, 0x02, 0xC2, 0xB8, 0xD8, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_801052C0[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0x8F, 0xB3, 0xBC, 0xC9, 0x02, 0xB1, 0xB2, 0x8B, 0x02, 0xC6,
    0x20, 0x01, 0xD9, 0xB0, 0x97, 0x02, 0xA6, 0x20, 0x02, 0xC2, 0xB8, 0xD8, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_801052E0[] = {
    0x01, 0xB4, 0xC8, 0xD9, 0x82, 0xB0, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB2, 0xCC, 0xB8,
    0xBB, 0xBE, 0xD9, 0x01, 0xB4, 0xD8, 0xB1, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_801052FC[] = {
    0x02, 0xB2, 0xC1, 0x87, 0xC3, 0xB7, 0xC6, 0x20, 0x02, 0xB6, 0xBF, 0xB8, 0x8E, 0xB7,
    0xD9, 0x01, 0x97, 0xDA, 0xB0, 0xC4, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105318[] = {
    0x02, 0x84, 0xDD, 0xBF, 0xB8, 0xBD, 0xD9, 0x01, 0xB4, 0xD8, 0xB1, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_80105328[] = {
    0x02, 0xBD, 0x93, 0xD8, 0x02, 0xD4, 0xBD, 0xB2, 0x01, 0xB4,
    0xD8, 0xB1, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_8010533C[] = {
    0x02, 0xCC, 0xD1, 0xC4, 0x20, 0x01, 0x87, 0xAC, 0xDD, 0x97, 0x02, 0xBD,
    0xD9, 0x01, 0x97, 0xDA, 0xB0, 0xC4, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80105354[] = {
    0x02, 0xCC, 0xD1, 0xC4, 0x20, 0x02, 0xC4, 0x90, 0xBB, 0xDA, 0xC3, 0x01, 0x8B, 0xD2, 0xB0, 0x87,
    0x02, 0xD3, 0x20, 0x02, 0xB3, 0xB9, 0xD9, 0x01, 0xDC, 0xC5, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80105374[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x20, 0x01, 0x84,
    0xB0, 0xC4, 0x02, 0xD9, 0xB2, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_80105388[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x20, 0x01, 0x91, 0xD9, 0x20,
    0x02, 0xB2, 0xDC, 0xC5, 0x8F, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_801053A0[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x20, 0x02, 0xB6,
    0xDD, 0x90, 0xDD, 0x02, 0xD9, 0xB2, 0x8E, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_801053B4[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6,
    0x20, 0x02, 0xD6, 0xD0, 0x8B, 0xBC, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_801053C8[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6,
    0x20, 0x02, 0xB6, 0xB7, 0xBA, 0xD0, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_801053DC[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xC9, 0x20, 0x02, 0xC5, 0xCF,
    0xB4, 0x02, 0xA6, 0x20, 0x02, 0xCD, 0xDD, 0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00,
};

u8 D_xk2_801053F8[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6,
    0x20, 0x02, 0xB9, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_8010540C[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6, 0x20, 0x02, 0xCE, 0xB6,
    0xCD, 0x20, 0x01, 0xBA, 0x96, 0xB0, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

u8 D_xk2_80105428[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6, 0x20, 0x01, 0xB4, 0x8E, 0xA8, 0xAF, 0xC4, 0xB6,
    0xAF, 0x97, 0x02, 0xC6, 0x20, 0x01, 0xB4, 0xDD, 0xC4, 0xD8, 0xB0, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

u8 D_xk2_8010544C[] = {
    0x01, 0xB4, 0xDD, 0xC4, 0xD8, 0xB0, 0x02, 0xBC, 0xC3, 0xB2, 0xD9, 0x01, 0xBA, 0xB0, 0xBD, 0x02,
    0xA6, 0x20, 0x02, 0xB6, 0xB2, 0x87, 0xAE, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

u8 D_xk2_8010546C[] = {
    0x01, 0xB4, 0xDD, 0xC4, 0xD8, 0xB0, 0x02, 0xBC, 0xC3, 0xB2, 0xD9, 0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xA6, 0x20,
    0x02, 0xBD, 0x93, 0xC3, 0x02, 0xB6, 0xB2, 0x87, 0xAE, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

extern GfxPool* gGfxPool;
extern unk_807B3C20 D_802CB6D0;
extern unk_800D6CA0 D_800D6CA0;
extern Vtx* gCourseVtxPtr;

s32 func_xk2_800F2750(void) {
    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gCourseInfos->courseSegments = D_802CB6D0.unk_0000;
    gCourseInfos->segmentCount = D_802CB6D0.controlPointCount;
    if (D_800D6CA0.unk_20 == -1) {
        Course_SegmentContinuousFlagInit(gCourseInfos);
        Course_SegmentFormsInit(gCourseInfos);
        return func_800A1954(gCourseInfos);
    }
    return 0;
}

extern s32 D_xk2_80104364;
extern s32 D_xk2_80104368;
extern s32 D_xk2_80104378;
extern s32 D_xk1_80032C20;
extern s32 gSegmentChunkCount;
extern u8 D_xk2_80104CA0[];

void func_xk2_800F27DC(CourseInfo* courseInfo) {
    s32 i;
    s32 temp_v0;
    s32 pad;
    s32 sp18;

    D_xk2_80104364 = 0;
    D_xk2_80104368 = 0;
    gCourseCtx.courseData.flag = 0;
    sp18 = 0;
    if (D_802CB6D0.controlPointCount < 4) {
        D_xk1_80032C20 = 0;
        D_800D6CA0.unk_08 = 0x10;
        D_xk2_80104378 = 9;
        return;
    }

    i = 0;

    while (true) {
        if (D_xk2_80104CA0[i] != 0) {
            D_xk1_80032C20 = 0;
            D_800D6CA0.unk_08 = 0x10;
            D_xk2_80104378 = 7;
            break;
        }
        i++;
        if (i == 12) {
            D_xk2_80104CA0[7] = 0;
            if ((func_i2_800B39B4(courseInfo) != -1) || (func_i2_800BE8BC(courseInfo) != -1)) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                break;
            }
            func_800A4D0C(2);
            temp_v0 = func_800A1954(courseInfo);
            if (temp_v0 != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                if (temp_v0 & 0x10000) {
                    D_xk2_80104CA0[3] = 1;
                    D_xk2_80104364 = 1;
                    D_800D6CA0.unk_1C = func_xk2_800E9134(temp_v0 & 0xFFFF);
                }
                if (gSegmentChunkCount >= 0x2FF) {
                    D_xk2_80104CA0[0xA] = 1;
                    D_xk2_80104368 = 1;
                }
                func_800A4D0C(0);
                sp18 = 1;
            }
            Course_EffectsViewInteractDataInit(false);
            if (D_xk2_80104CA0[7] != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                sp18 = 1;
                func_800A4D0C(0);
            }
            func_800A4D0C(1);
            temp_v0 = func_800A1954(courseInfo);
            if (temp_v0 != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                sp18 = 1;
                if (temp_v0 & 0x10000) {
                    D_xk2_80104CA0[3] = 1;
                    D_xk2_80104364 = 1;
                    D_800D6CA0.unk_1C = func_xk2_800E9134(temp_v0 & 0xFFFF);
                }
                if (gSegmentChunkCount >= 0x2FF) {
                    D_xk2_80104CA0[0xA] = 1;
                    D_xk2_80104368 = 1;
                }
                func_800A4D0C(0);
            }
            Course_EffectsViewInteractDataInit(false);
            if (D_xk2_80104CA0[7] != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                sp18 = 1;
                func_800A4D0C(0);
            }
            func_800A4D0C(0);
            if (sp18 == 0) {
                gCourseCtx.courseData.flag = 1;
            }
            break;
        }
    }
}

s32 func_xk2_800F2AC0(s8* arg0) {
    s32 var_v1;

    var_v1 = 0;
    do {
        if ((*arg0 == 0xA) || (*arg0 == 0)) {
            var_v1++;
        }
    } while (!*arg0++ == 0);
    return var_v1;
}

s32 func_xk2_800F2AF4(s8* arg0) {
    s32 var_v0;
    s32 var_v1;

    var_v1 = 0;
    var_v0 = 0;

    while (true) {
        if ((*arg0 != 0xA) && (*arg0 != 0)) {
            arg0++;
            var_v0++;
            continue;
        }

        if (var_v1 < var_v0) {
            var_v1 = var_v0;
        }
        if (*arg0 == 0) {
            break;
        }
        arg0++;
        var_v0 = 0;
    }
    return var_v1;
}

extern Gfx D_3000510[];
extern Gfx D_3000540[];
extern Gfx D_8014940[];
extern u8* D_xk1_800331F0[];
extern s32 gCourseEditCursorYPos;

void func_xk2_800F2B48(Gfx** gfxP) {
    Gfx* gfx;
    s32 width;
    s32 i;
    s32 temp_v1;
    s32 top = 200;
    s32 pad;

    gfx = *gfxP;
    D_xk2_80104F04 = 0;
    for (i = 0; i < 12; i++) {
        if (D_xk2_80104CA0[i] != 0) {
            D_xk2_80104F04 = 1;
        }
    }

    if ((D_xk2_80104F04 != 0) && (func_xk2_800EF780() != 0) && (gCourseEditCursorYPos < 200)) {
        width = mfsStrLen(D_xk1_800331F0[21]) * 8;
        width += 16;
        temp_v1 = (s32) (SCREEN_WIDTH - width) / 2;

        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        // FAKE
        gSPTextureRectangle(pad = gfx++, (temp_v1 - 2) << 2, (top - 2) << 2, (temp_v1 + width + 2) << 2,
                            (top + 16 + 2) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gSPTextureRectangle(gfx++, (temp_v1 - 1) << 2, (top - 1) << 2, (temp_v1 + width + 1) << 2, (top + 16 + 1) << 2,
                            0, 0, 0, 1 << 10, 1 << 10);
        gSPDisplayList(gfx++, D_3000540);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = func_xk1_800264C0(gfx, temp_v1 + 16, top, 0x15);

        gSPDisplayList(gfx++, D_8014940);

        // B Button
        gDPLoadTextureBlock(gfx++, aExpansionKitABButtonTex + 16 * 16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, temp_v1 << 2, top << 2, (temp_v1 + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        *gfxP = gfx;
    }
}

extern s32 D_xk1_80032AD0;
extern s32 D_80119880;

void func_xk2_800F2E4C(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 temp;
    s32 top;
    s32 width;
    s32 height;

    if ((D_800D6CA0.unk_08 != 3) || (D_80119880 != 4)) {
        return;
    }

    gfx = *gfxP;
    left = 24;
    top = 96;
    width = 128;
    height = 40;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, (top + height + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (top - 1) << 2, (left + width + 1) << 2, (top + height + 1) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gfx++, G_TF_POINT);

    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F28);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 40, top, D_xk2_80104F30);
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left + 80, top, D_xk2_80104F38);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 112, top, D_xk2_80104F40);
    top += 8;
    D_xk1_80032AD0 = 1;

    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F44);
    top += 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F28);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 40, top, D_xk2_80104F50);
    top += 8;
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F38);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 32, top, D_xk2_80104F5C);
    top += 8;
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F28);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 40, top, D_xk2_80104F68);
    *gfxP = gfx;
}

extern s32 D_xk2_80119918;

void func_xk2_800F3164(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 left;
    s32 top;
    s32 width;

    if (D_xk2_80119918 == 0) {
        return;
    }
    gfx = *gfxP;
    left = 48;
    top = 20;
    width = 224;

    gSPDisplayList(gfx++, D_8014940);

    for (i = 0; i < 32; i++) {
        gDPLoadTextureBlock(gfx++, aExpansionKitPauseInstructionsTex + i * width, G_IM_FMT_RGBA, G_IM_SIZ_16b, 224, 1,
                            0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        top++;
    }

    *gfxP = gfx;
}

s32 func_xk2_800F3320(s8* arg0) {
    s32 var_v1;
    s32 temp;

    var_v1 = 0;

    while (true) {
        // FAKE
        temp = *arg0;
        switch (*arg0) {
            case 0:
                goto exit;
            case 1:
            case 2:
                break;
            default:
                var_v1++;
                break;
        }
        arg0++;
    }

exit:
    return var_v1;
}

void func_xk2_800F335C(Gfx** gfxP, s32 top, s8* arg2) {
    s32 left;
    s32 width;
    s32 height;
    s32 temp_v0;
    Gfx* gfx;

    gfx = *gfxP;
    temp_v0 = func_xk2_800F3320(arg2);
    width = temp_v0 * 8;
    left = (((0x22 - temp_v0) / 2) * 8) + 0x18;
    height = 8;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, (top + height + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (top - 1) << 2, (left + width + 1) << 2, (top + height + 1) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_xk1_8002924C(gfx, left, top, arg2);
    *gfxP = gfx;
}

extern s32 D_8076C96C;
extern s32 gCourseEditHighlightedIconIndex;

void func_xk2_800F3548(Gfx** gfxP) {
    s32 top = 194;
    Gfx* gfx;

    if (D_8076C96C == 0) {
        return;
    }
    gfx = *gfxP;
    switch (gCourseEditHighlightedIconIndex) {
        case 0:
            func_xk2_800F335C(&gfx, top, D_xk2_80104F74);
            break;
        case 1:
            func_xk2_800F335C(&gfx, top, D_xk2_80104F94);
            break;
        case 2:
            func_xk2_800F335C(&gfx, top, D_xk2_80104FAC);
            break;
        case 3:
            break;
    }
    *gfxP = gfx;
}

extern MenuWidget gCourseEditWidget;
extern MenuWidget gCourseEditEntryWidget;
extern MenuWidget gCourseEditFileWidget;
extern MenuWidget gCreateWidget;
extern MenuWidget gPointWidget;
extern MenuWidget gMoveWidget;
extern MenuWidget gDesignStyleWidget;
extern MenuWidget gPartsStyleWidget;

void func_xk2_800F3600(Gfx** gfxP) {
    s32 pad;
    Gfx* gfx;
    MenuWidget* sp2C;

    if ((D_8076C96C == 0) || (D_800D6CA0.unk_08 != 1)) {
        return;
    }
    sp2C = func_xk1_80026914(&gCourseEditWidget);

    gfx = *gfxP;
    if (sp2C == &gCreateWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_80104FD4);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[25], 25);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_80104FEC);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[26], 26);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105008);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[27], 27);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105024);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[28], 28);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105048);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105064);
                break;
        }
    }
    if (sp2C == &gPointWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105078);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105090);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050AC);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050CC);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050E8);
                break;
        }
    }
    if (sp2C == &gMoveWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050FC);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105114);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010512C);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010514C);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105174);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105190);
                break;
            case 6:
                func_xk2_800F335C(&gfx, 24, D_xk2_801051A8);
                break;
        }
    }
    if (sp2C == &gCourseEditFileWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053B4);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053C8);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053DC);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053F8);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010540C);
                break;
        }
    }
    if (sp2C == &gCourseEditEntryWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105428);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010544C);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010546C);
                break;
        }
    }
    if (sp2C == &gDesignStyleWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801051D0);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_801051F0);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105210);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105230);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105244);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105260);
                break;
            case 6:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105280);
                break;
            case 7:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010529C);
                break;
            case 8:
                func_xk2_800F335C(&gfx, 24, D_xk2_801052C0);
                break;
        }
    }
    if (sp2C == &gPartsStyleWidget) {
        switch (sp2C->highlightedIndex) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801052E0);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_801052FC);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105318);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105328);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010533C);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105354);
                break;
            case 6:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105374);
                break;
            case 7:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105388);
                break;
            case 8:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053A0);
                break;
        }
    }
    *gfxP = gfx;
}

extern u16* gCourseEditIconTextures[];
extern s32 D_8076C95C;
extern s32 D_8076C960;

void func_xk2_800F3D10(void) {

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        D_8076C96C = 1;
        gCourseEditIconTextures[3] = aCourseEditGoldQuestionIconTex;
        D_8076C95C = 0;
        D_8076C960 = 0;
        D_800D6CA0.unk_08 = 0;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        D_8076C95C = 0;
        D_800D6CA0.unk_08 = 0;
        func_xk2_800EE664(0x16);
    }
}

extern s32 D_8076C958;

void func_xk2_800F3DAC(Gfx** gfxP) {
    s32 left;
    s32 top;
    s32 width;
    s32 height;
    s32 temp_v1;
    Gfx* gfx;

    gfx = *gfxP;
    if (D_8076C958 == 0) {
        return;
    }
    D_8076C958--;
    if (D_8076C958 == 0) {
        return;
    }

    left = 128;
    top = 88;
    width = 16;
    height = 16;

    func_xk2_800F2AC0(D_xk1_800331F0[22]);
    temp_v1 = (((0x22 - func_xk2_800F2AF4(D_xk1_800331F0[22])) / 2) * 8) + 0x18;
    func_xk2_800EECD4(&gfx, temp_v1, 0x58, D_xk1_800331F0[22], 22);

    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, aCourseEditQuestionIconTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gDPPipeSync(gfx++);

    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 255);

    gDPLoadTextureBlock(gfx++, aCourseEditMouseClickTex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_xk2_800E92E4(&gfx, 0x120, 0xCC);
    *gfxP = gfx;
}
