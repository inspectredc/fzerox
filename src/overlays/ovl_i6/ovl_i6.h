#ifndef OVL_I6_H
#define OVL_I6_H

#include "unk_structs.h"
#include "other_types.h"

typedef struct unk_8011DC40 {
    f32 unk_00;
    f32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
} unk_8011DC40; // UNUSED?

typedef struct unk_8011EDDC_unk_14 {
    void* textureOffset;
    s16 width;
    s16 height;
} unk_8011EDDC_unk_14;

typedef struct unk_8011EDDC {
    s32 unk_00;
    u16 unk_04;
    // s16 unk_06;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    unk_8011EDDC_unk_14* unk_14; // points to pair
    unk_8011EDDC_unk_14 unk_18;
} unk_8011EDDC;

extern u8 D_F129C54[];
extern u8 D_F12ABB0[];
extern u8 D_F12BC00[];
extern u8 D_F12CB9C[];
extern u8 D_F12DB18[];
extern u8 D_F12E9A0[];
extern u8 D_F12F934[];
extern u8 D_F130950[];

extern u8 D_F000004[];
extern u8 D_F014A68[];
extern u8 D_F026348[];

extern u8 D_F134760[];
extern u8 D_F131968[];
extern u8 D_F134D64[];
extern u8 D_F134EAC[];
extern u8 D_F134FFC[];
extern u8 D_F13514C[];
extern u8 D_F13437C[];
extern u8 D_F1344C8[];
extern u8 D_F134610[];
extern u8 D_F1352A0[];
extern u8 D_F135458[];

extern u8 D_F139710[];

extern u8 D_F1C871C[];
extern u8 D_F1CA9AC[];
extern u8 D_F1CD2B8[];
extern u8 D_F1D0078[];
extern u8 D_F1D2B04[];
extern u8 D_F1D48E4[];
extern u8 D_F1D6DE0[];
extern u8 D_F1D9A60[];
extern u8 D_F1DC46C[];
extern u8 D_F1DF4E8[];
extern u8 D_F1E1C18[];
extern u8 D_F1E4928[];
extern u8 D_F1E7FC0[];
extern u8 D_F1EA638[];
extern u8 D_F1ECC14[];
extern u8 D_F1EEDBC[];
extern u8 D_F1F1030[];
extern u8 D_F1F3E70[];
extern u8 D_F1F6F14[];
extern u8 D_F1F9A94[];
extern u8 D_F1FC98C[];
extern u8 D_F1FF6FC[];
extern u8 D_F202560[];
extern u8 D_F204998[];
extern u8 D_F207650[];
extern u8 D_F209920[];
extern u8 D_F20C454[];
extern u8 D_F20ECD8[];
extern u8 D_F211164[];
extern u8 D_F213444[];

extern u8 D_F1C417C[];
extern u8 D_F1C6754[];
extern u8 D_F1C70B4[];
extern u8 D_F0336B8[];
extern u8 D_F033AB4[];
extern u8 D_F0385AC[];
extern u8 D_F03EBB4[];
extern u8 D_F04412C[];
extern u8 D_F04B7E4[];
extern u8 D_F051FDC[];
extern u8 D_F05839C[];
extern u8 D_F05E28C[];
extern u8 D_F065414[];
extern u8 D_F06AA80[];
extern u8 D_F0704D0[];
extern u8 D_F075A98[];
extern u8 D_F07B3EC[];
extern u8 D_F082E6C[];
extern u8 D_F0892B4[];
extern u8 D_F08F4F4[];
extern u8 D_F096470[];
extern u8 D_F09C0CC[];
extern u8 D_F0A1AB8[];
extern u8 D_F0A7614[];
extern u8 D_F0AE148[];
extern u8 D_F0B2F94[];
extern u8 D_F0B9D2C[];
extern u8 D_F0BF7E4[];

extern u8 D_F0C5624[];
extern u8 D_F0CC4D4[];
extern u8 D_F0D120C[];
extern u8 D_F0D724C[];
extern u8 D_F0DD308[];
extern u8 D_F0E2840[];

extern u8 D_F262FB4[];
extern u8 D_F262ED0[];
extern u8 D_F263190[];
extern u8 D_F263230[];
extern u8 D_F2632E8[];
extern u8 D_F2634A4[];
extern u8 D_F2637DC[];
extern u8 D_F2636F0[];

extern u8 D_F261AD4[];
extern u8 D_F262184[];
extern u8 D_F261E80[];
extern u8 D_F262398[];
extern u8 D_F262688[];
extern u8 D_F263DA8[];
extern u8 D_F2630C8[];

#endif // OVL_I6_H
