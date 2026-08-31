#include "global.h"
#include "leo/mfs.h"
#include "fzx_course.h"
#include "fzx_expansion_kit.h"
#include ASSET_HEADER(setup_gfx.h)
#include ASSET_HEADER(course_track_gfx.h)
#include ASSET_HEADER_EK(expansion_kit_textures.h)
#include ASSET_HEADER_EK(course_edit_textures.h)

UNUSED s32 D_xk2_80104EF0 = 0;
UNUSED s32 D_xk2_80104EF4 = 0;
UNUSED s32 D_xk2_80104EF8 = -1;
UNUSED s32 D_xk2_80104EFC = 60;
UNUSED s32 D_xk2_80104F00 = 0;
s32 D_xk2_80104F04 = 0;

UNUSED s32 D_xk2_80104F08[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

// プロテクト
u8 D_xk2_80104F28[] = {
    0x97, 0xDB, 0xC3, 0xB8, 0xC4, 0x00, 0x00, 0x00,
};

// をかけたい
u8 D_xk2_80104F30[] = {
    0xA6, 0xB6, 0xB9, 0xC0, 0xB2, 0x00, 0x00, 0x00,
};

// ファイル
u8 D_xk2_80104F38[] = {
    0xCC, 0xA7, 0xB2, 0xD9, 0x00, 0x00, 0x00, 0x00,
};

// を
u8 D_xk2_80104F40[] = {
    0xA6,
    0x00,
    0x00,
    0x00,
};

// せんたくしてください
u8 D_xk2_80104F44[] = {
    0xBE, 0xDD, 0xC0, 0xB8, 0xBC, 0xC3, 0xB8, 0x8B, 0xBB, 0xB2, 0x00, 0x00,
};

// がすでにかかっている
u8 D_xk2_80104F50[] = {
    0x81, 0xBD, 0x8E, 0xC6, 0xB6, 0xB6, 0xAF, 0xC3, 0xB2, 0xD9, 0x00, 0x00,
};

// をせんたくすると
u8 D_xk2_80104F5C[] = {
    0xA6, 0xBE, 0xDD, 0xC0, 0xB8, 0xBD, 0xD9, 0xC4, 0x00, 0x00, 0x00, 0x00,
};

// をかいじょできます
u8 D_xk2_80104F68[] = {
    0xA6, 0xB6, 0xB2, 0x87, 0xAE, 0x8E, 0xB7, 0xCF, 0xBD, 0x00, 0x00, 0x00,
};

// さくせいしたコースを  テストそうこうできます。
u8 sTestDriveTooltipEncStr[] = {
    0x02, 0xBB, 0xB8, 0xBE, 0xB2, 0xBC, 0xC0, 0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xA6, 0x20, 0x01, 0xC3,
    0xBD, 0xC4, 0x02, 0xBF, 0xB3, 0xBA, 0xB3, 0x8E, 0xB7, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// コースを  ラインで ひょうじします。
u8 sLineDisplayTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xA6, 0x20, 0x01, 0xD7, 0xB2, 0xDD, 0x02,
    0x8E, 0x20, 0xCB, 0xAE, 0xB3, 0x87, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

// ポイントのおきばしょをせいげんして ちょくせんをつくりやすくします。
u8 sAlignPointsTooltipEncStr[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xC9, 0xB5, 0xB7, 0x90, 0xBC, 0xAE, 0xA6, 0xBE,
    0xB2, 0x84, 0xDD, 0xBC, 0xC3, 0x20, 0xC1, 0xAE, 0xB8, 0xBE, 0xDD, 0xA6, 0xC2, 0xB8,
    0xD8, 0xD4, 0xBD, 0xB8, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// ベースとなるコースを  つくります。
u8 sCreateCourseTooltipEncStr[] = {
    0x01, 0x93, 0xB0, 0xBD, 0x02, 0xC4, 0xC5, 0xD9, 0x01, 0xBA, 0xB0, 0xBD,
    0x02, 0xA6, 0x20, 0x02, 0xC2, 0xB8, 0xD8, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

// コースのポイントを  いどうなどさせます。
u8 sCreatePointTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xC9, 0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20,
    0x02, 0xB2, 0x8F, 0xB3, 0xC5, 0x8F, 0xBB, 0xBE, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// どうろのタイプなどを  へんこうします。
u8 sCreateDesignTooltipEncStr[] = {
    0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC9, 0x01, 0xC0, 0xB2, 0x97, 0x02, 0xC5, 0x8F, 0x02,
    0xA6, 0x20, 0x02, 0xCD, 0xDD, 0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// どうろにおけるシカケ  またはビルなどを  いれます。
u8 D_xk2_80105024[] = {
    0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC6, 0x02, 0xB5, 0xB9, 0xD9, 0x01, 0xBC, 0xB6, 0xB9, 0x20, 0x02, 0xCF, 0xC0,
    0xCA, 0x01, 0x91, 0xD9, 0x02, 0xC5, 0x8F, 0x02, 0xA6, 0x20, 0x02, 0xB2, 0xDA, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

// はいけいのシーンとそらを  へんこうします。
u8 sCreateBackgroundTooltipEncStr[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x01, 0xBC, 0xB0, 0xDD, 0x02, 0xC4, 0x02,
    0xBF, 0xD7, 0xA6, 0x20, 0x02, 0xCD, 0xDD, 0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00,
};

// BGMを  へんこうします。
u8 sCreateBGMTooltipEncStr[] = {
    0x01, 0x42, 0x47, 0x4D, 0x02, 0xA6, 0x20, 0x02, 0xCD, 0xDD,
    0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// コースポイントを  セットします。
u8 sPointSetTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20,
    0x01, 0xBE, 0xAF, 0xC4, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// スタートの  ばしょを  いどうします。
u8 sPointStartTooltipEncStr[] = {
    0x01, 0xBD, 0xC0, 0xB0, 0xC4, 0x02, 0xC9, 0x20, 0x02, 0x90, 0xBC, 0xAE, 0x02, 0xA6,
    0x20, 0x02, 0xB2, 0x8F, 0xB3, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// コースせんたいを  ちゅうしんにいどうします。
u8 sPointCenteringTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0x89, 0xDD, 0xC0, 0xB2, 0x02, 0xA6, 0x20, 0x02, 0xC1, 0xAD, 0xB3,
    0xBC, 0xDD, 0x02, 0xC6, 0x02, 0xB2, 0x8F, 0xB3, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// コースの  しんこうほうこうを  かえます。
u8 sPointReverseTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xC9, 0x20, 0x02, 0xBC, 0xDD, 0xBA, 0xB3, 0xCE, 0xB3,
    0xBA, 0xB3, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// コースせんたいを  けします。
u8 sPointClearAllTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0x02, 0x89, 0xDD, 0xC0, 0xB2, 0x02,
    0xA6, 0x20, 0x02, 0xB9, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

// ポイントを  へいこういどうさせます。
u8 sMoveXZTooltipEncStr[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xCD, 0xB2, 0xBA,
    0xB3, 0x02, 0xB2, 0x8F, 0xB3, 0x02, 0xBB, 0xBE, 0xCF, 0xBD, 0xA1, 0x00,
};

// ポイントの  たかさを  かえます。
u8 sMoveYTooltipEncStr[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xC9, 0x20, 0x02, 0xC0, 0xB6, 0xBB,
    0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// ポイントを  ちゅうしんに  みちはばを  かえます。
u8 sMoveWidthTooltipEncStr[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xC1, 0xAD, 0xB3, 0xBC, 0xDD, 0x02, 0xC6,
    0x20, 0x02, 0xD0, 0xC1, 0xCA, 0x90, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00,
};

// ポイントを  ちゅうしんに  みちの  かたむきを  かえます。
u8 sMoveBankTooltipEncStr[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xC1, 0xAD, 0xB3, 0xBC, 0xDD,
    0x02, 0xC6, 0x20, 0x02, 0xD0, 0xC1, 0x02, 0xC9, 0x20, 0x02, 0xB6, 0xC0, 0xD1, 0xB7,
    0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// みちはばの  ちゅうしんてんを  かえます。
u8 sMoveCenterTooltipEncStr[] = {
    0x02, 0xD0, 0xC1, 0xCA, 0x90, 0x02, 0xC9, 0x20, 0x02, 0xC1, 0xAD, 0xB3, 0xBC, 0xDD,
    0x02, 0xC3, 0xDD, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB4, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

// せんたくしたポイントを  けします。
u8 sMoveClearTooltipEncStr[] = {
    0x02, 0xBE, 0xDD, 0xC0, 0xB8, 0xBC, 0xC0, 0x01, 0x99, 0xB2, 0xDD, 0xC4,
    0x02, 0xA6, 0x20, 0x02, 0xB9, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// せんたくしたふくすうのポイントを  まっすぐにならべます。
u8 sMoveStraightTooltipEncStr[] = {
    0x02, 0xBE, 0xDD, 0xC0, 0xB8, 0xBC, 0xC0, 0x02, 0xCC, 0xB8, 0xBD, 0xB3, 0x02, 0xC9,
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0xA6, 0x20, 0x02, 0xCF, 0xAF, 0xBD, 0x83, 0x02,
    0xC6, 0x02, 0xC5, 0xD7, 0x93, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// ガードレールのある  ふつうの  どうろです。
u8 sTrackDesignRoadTooltipEncStr[] = {
    0x01, 0x81, 0xB0, 0x8F, 0xDA, 0xB0, 0xD9, 0x02, 0xC9, 0x02, 0xB1, 0xD9, 0x20, 0x02, 0xCC, 0xC2,
    0xB3, 0x02, 0xC9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// たかいガードレールがセットされる  どうろです。
u8 sTrackDesignHRoadTooltipEncStr[] = {
    0x02, 0xC0, 0xB6, 0xB2, 0x01, 0x81, 0xB0, 0x8F, 0xDA, 0xB0, 0xD9, 0x02, 0x81, 0x01, 0xBE, 0xAF,
    0xC4, 0x02, 0xBB, 0xDA, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

// ガードレールがない  きけんな  どうろです。
u8 sTrackDesignTRoadTooltipEncStr[] = {
    0x01, 0x81, 0xB0, 0x8F, 0xDA, 0xB0, 0xD9, 0x02, 0x81, 0x02, 0xC5, 0xB2, 0x20, 0x02, 0xB7, 0xB9,
    0xDD, 0x02, 0xC5, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// トンネルつきの  どうろです。
u8 sTrackDesignTunnelTooltipEncStr[] = {
    0x01, 0xC4, 0xDD, 0xC8, 0xD9, 0x02, 0xC2, 0xB7, 0x02, 0xC9,
    0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

// パイプじょうの  なかをはしる  どうろです。
u8 sTrackDesignPipeTooltipEncStr[] = {
    0x01, 0x95, 0xB2, 0x97, 0x02, 0x87, 0xAE, 0xB3, 0x02, 0xC9, 0x20, 0x02, 0xC5, 0xB6,
    0xA6, 0xCA, 0xBC, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

// ハーフパイプじょうの  なかをはしる  どうろです。
u8 sTrackDesignHalfPipeTooltipEncStr[] = {
    0x01, 0xCA, 0xB0, 0xCC, 0x01, 0x95, 0xB2, 0x97, 0x02, 0x87, 0xAE, 0xB3, 0x02, 0xC9, 0x20, 0x02,
    0xC5, 0xB6, 0xA6, 0xCA, 0xBC, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

// パイプじょうの  そとをはしる  どうろです。
u8 sTrackDesignCylinderTooltipEncStr[] = {
    0x01, 0x95, 0xB2, 0x97, 0x02, 0x87, 0xAE, 0xB3, 0x02, 0xC9, 0x20, 0x02, 0xBF, 0xC4,
    0xA6, 0xCA, 0xBC, 0xD9, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

// どうろと  どうろのあいだに  くうかんを  つくります。
u8 sTrackDesignSpaceTooltipEncStr[] = {
    0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC4, 0x20, 0x02, 0x8F, 0xB3, 0xDB, 0x02, 0xC9, 0x02, 0xB1, 0xB2, 0x8B, 0x02,
    0xC6, 0x20, 0x02, 0xB8, 0xB3, 0xB6, 0xDD, 0x02, 0xA6, 0x20, 0x02, 0xC2, 0xB8, 0xD8, 0xCF, 0xBD, 0xA1, 0x00,
};

// ポイントどうしのあいだに  ループを  つくります。
u8 sTrackDesignLoopTooltipEncStr[] = {
    0x01, 0x99, 0xB2, 0xDD, 0xC4, 0x02, 0x8F, 0xB3, 0xBC, 0xC9, 0x02, 0xB1, 0xB2, 0x8B, 0x02, 0xC6,
    0x20, 0x01, 0xD9, 0xB0, 0x97, 0x02, 0xA6, 0x20, 0x02, 0xC2, 0xB8, 0xD8, 0xCF, 0xBD, 0xA1, 0x00,
};

// エネルギーを  かいふくさせるエリアです。
u8 sTrackPartPitTooltipEncStr[] = {
    0x01, 0xB4, 0xC8, 0xD9, 0x82, 0xB0, 0x02, 0xA6, 0x20, 0x02, 0xB6, 0xB2, 0xCC, 0xB8,
    0xBB, 0xBE, 0xD9, 0x01, 0xB4, 0xD8, 0xB1, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// いちじてきに  かそくできるプレートです。
u8 sTrackPartDashTooltipEncStr[] = {
    0x02, 0xB2, 0xC1, 0x87, 0xC3, 0xB7, 0xC6, 0x20, 0x02, 0xB6, 0xBF, 0xB8, 0x8E, 0xB7,
    0xD9, 0x01, 0x97, 0xDA, 0xB0, 0xC4, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// げんそくするエリアです。
u8 sTrackPartDirtTooltipEncStr[] = {
    0x02, 0x84, 0xDD, 0xBF, 0xB8, 0xBD, 0xD9, 0x01, 0xB4, 0xD8, 0xB1, 0x02, 0x8E, 0xBD, 0xA1, 0x00,
};

// すべりやすいエリアです。
u8 sTrackPartIceTooltipEncStr[] = {
    0x02, 0xBD, 0x93, 0xD8, 0x02, 0xD4, 0xBD, 0xB2, 0x01, 0xB4,
    0xD8, 0xB1, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// ふむと  ジャンプするプレートです。
u8 sTrackPartJumpTooltipEncStr[] = {
    0x02, 0xCC, 0xD1, 0xC4, 0x20, 0x01, 0x87, 0xAC, 0xDD, 0x97, 0x02, 0xBD,
    0xD9, 0x01, 0x97, 0xDA, 0xB0, 0xC4, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

// ふむと  とばされてダメージも  うけるワナです。
u8 sTrackPartTrapTooltipEncStr[] = {
    0x02, 0xCC, 0xD1, 0xC4, 0x20, 0x02, 0xC4, 0x90, 0xBB, 0xDA, 0xC3, 0x01, 0x8B, 0xD2, 0xB0, 0x87,
    0x02, 0xD3, 0x20, 0x02, 0xB3, 0xB9, 0xD9, 0x01, 0xDC, 0xC5, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

// はいけいの  ゲートるいです。
u8 sTrackPartGateTooltipEncStr[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x20, 0x01, 0x84,
    0xB0, 0xC4, 0x02, 0xD9, 0xB2, 0x8E, 0xBD, 0xA1, 0x00, 0x00,
};

// はいけいの  ビル  いわなどです。
u8 sTrackPartBuildingTooltipEncStr[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x20, 0x01, 0x91, 0xD9, 0x20,
    0x02, 0xB2, 0xDC, 0xC5, 0x8F, 0x02, 0x8E, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// はいけいの  かんばんるいです。
u8 sTrackPartSignTooltipEncStr[] = {
    0x02, 0xCA, 0xB2, 0xB9, 0xB2, 0x02, 0xC9, 0x20, 0x02, 0xB6,
    0xDD, 0x90, 0xDD, 0x02, 0xD9, 0xB2, 0x8E, 0xBD, 0xA1, 0x00,
};

// コースファイルを  よみだします。
u8 sFileLoadTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6,
    0x20, 0x02, 0xD6, 0xD0, 0x8B, 0xBC, 0xCF, 0xBD, 0xA1, 0x00,
};

// コースファイルを  かきこみます。
u8 sFileSaveTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6,
    0x20, 0x02, 0xB6, 0xB7, 0xBA, 0xD0, 0xCF, 0xBD, 0xA1, 0x00,
};

// コースファイルの  なまえを  へんこうします。
u8 sFileRenameTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xC9, 0x20, 0x02, 0xC5, 0xCF,
    0xB4, 0x02, 0xA6, 0x20, 0x02, 0xCD, 0xDD, 0xBA, 0xB3, 0xBC, 0xCF, 0xBD, 0xA1, 0x00,
};

// コースファイルを  けします。
u8 sFileEraseTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6,
    0x20, 0x02, 0xB9, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// コースファイルを  ほかへ  コピーします。
u8 sFileCopyTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6, 0x20, 0x02, 0xCE, 0xB6,
    0xCD, 0x20, 0x01, 0xBA, 0x96, 0xB0, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00,
};

// コースファイルを  エディットカップに  エントリーします。
u8 sEntryRegisterTooltipEncStr[] = {
    0x01, 0xBA, 0xB0, 0xBD, 0xCC, 0xA7, 0xB2, 0xD9, 0x02, 0xA6, 0x20, 0x01, 0xB4, 0x8E, 0xA8, 0xAF, 0xC4, 0xB6,
    0xAF, 0x97, 0x02, 0xC6, 0x20, 0x01, 0xB4, 0xDD, 0xC4, 0xD8, 0xB0, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00,
};

// エントリーしているコースを  かいじょします。
u8 sEntryDeregisterTooltipEncStr[] = {
    0x01, 0xB4, 0xDD, 0xC4, 0xD8, 0xB0, 0x02, 0xBC, 0xC3, 0xB2, 0xD9, 0x01, 0xBA, 0xB0, 0xBD, 0x02,
    0xA6, 0x20, 0x02, 0xB6, 0xB2, 0x87, 0xAE, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

// エントリーしているコースを  すべてかいじょします。
u8 sEntryDeregisterAllTooltipEncStr[] = {
    0x01, 0xB4, 0xDD, 0xC4, 0xD8, 0xB0, 0x02, 0xBC, 0xC3, 0xB2, 0xD9, 0x01, 0xBA, 0xB0, 0xBD, 0x02, 0xA6, 0x20,
    0x02, 0xBD, 0x93, 0xC3, 0x02, 0xB6, 0xB2, 0x87, 0xAE, 0x02, 0xBC, 0xCF, 0xBD, 0xA1, 0x00, 0x00, 0x00, 0x00,
};

extern GfxPool* gGfxPool;
extern unk_807B3C20 D_802CB6D0;
extern unk_800D6CA0 D_800D6CA0;
extern Vtx* gCourseVtxPtr;

s32 func_xk2_800F2750(void) {
    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gCourseInfos->courseSegments = D_802CB6D0.segments;
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
extern s32 gExpansionKitYesNoOptionIndex;
extern s32 gSegmentChunkCount;
extern u8 D_xk2_80104CA0[12];

void func_xk2_800F27DC(CourseInfo* courseInfo) {
    s32 i;
    s32 temp_v0;
    s32 pad;
    bool sp18;

    D_xk2_80104364 = 0;
    D_xk2_80104368 = 0;
    COURSE_CONTEXT()->courseData.flag = 0;
    sp18 = false;
    if (D_802CB6D0.controlPointCount < 4) {
        gExpansionKitYesNoOptionIndex = 0;
        D_800D6CA0.state = 0x10;
        D_xk2_80104378 = 9;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(D_xk2_80104CA0); i++) {
        if (D_xk2_80104CA0[i] != 0) {
            gExpansionKitYesNoOptionIndex = 0;
            D_800D6CA0.state = 0x10;
            D_xk2_80104378 = 7;
            return;
        }
    }
    D_xk2_80104CA0[7] = 0;
    if ((func_i2_800B39B4(courseInfo) != -1) || (func_i2_800BE8BC(courseInfo) != -1)) {
        gExpansionKitYesNoOptionIndex = 0;
        D_800D6CA0.state = 0x10;
        D_xk2_80104378 = 7;
        return;
    }
    func_800A4D0C(2);
    temp_v0 = func_800A1954(courseInfo);
    if (temp_v0 != 0) {
        gExpansionKitYesNoOptionIndex = 0;
        D_800D6CA0.state = 0x10;
        D_xk2_80104378 = 7;
        if (temp_v0 & 0x10000) {
            D_xk2_80104CA0[3] = 1;
            D_xk2_80104364 = 1;
            D_800D6CA0.unk_1C = func_xk2_800E9134(temp_v0 & 0xFFFF);
        }
        if (gSegmentChunkCount >= 0x2FF) {
            D_xk2_80104CA0[10] = 1;
            D_xk2_80104368 = 1;
        }
        func_800A4D0C(0);
        sp18 = true;
    }
    Course_EffectsViewInteractDataInit(false);
    if (D_xk2_80104CA0[7] != 0) {
        gExpansionKitYesNoOptionIndex = 0;
        D_800D6CA0.state = 0x10;
        D_xk2_80104378 = 7;
        sp18 = true;
        func_800A4D0C(0);
    }
    func_800A4D0C(1);
    temp_v0 = func_800A1954(courseInfo);
    if (temp_v0 != 0) {
        gExpansionKitYesNoOptionIndex = 0;
        D_800D6CA0.state = 0x10;
        D_xk2_80104378 = 7;
        sp18 = true;
        if (temp_v0 & 0x10000) {
            D_xk2_80104CA0[3] = 1;
            D_xk2_80104364 = 1;
            D_800D6CA0.unk_1C = func_xk2_800E9134(temp_v0 & 0xFFFF);
        }
        if (gSegmentChunkCount >= 0x2FF) {
            D_xk2_80104CA0[10] = 1;
            D_xk2_80104368 = 1;
        }
        func_800A4D0C(0);
    }
    Course_EffectsViewInteractDataInit(false);
    if (D_xk2_80104CA0[7] != 0) {
        gExpansionKitYesNoOptionIndex = 0;
        D_800D6CA0.state = 0x10;
        D_xk2_80104378 = 7;
        sp18 = true;
        func_800A4D0C(0);
    }
    func_800A4D0C(0);
    if (!sp18) {
        COURSE_CONTEXT()->courseData.flag = 1;
    }
}

s32 func_xk2_800F2AC0(s8* str) {
    s32 numLines;

    numLines = 0;
    do {
        if ((*str == '\n') || (*str == '\0')) {
            numLines++;
        }
    } while (!*str++ == 0);
    return numLines;
}

s32 func_xk2_800F2AF4(s8* str) {
    s32 lineLength;
    s32 maxLineLength;

    maxLineLength = 0;
    lineLength = 0;

    while (true) {
        if ((*str != '\n') && (*str != '\0')) {
            str++;
            lineLength++;
            continue;
        }

        if (maxLineLength < lineLength) {
            maxLineLength = lineLength;
        }
        if (*str == '\0') {
            break;
        }
        str++;
        lineLength = 0;
    }
    return maxLineLength;
}

extern char* gCourseEditMessageStrs[];
extern s32 gCourseEditCursorYPos;

void CourseEdit_DrawPressBToReturnToPreviousState(Gfx** gfxP) {
    Gfx* gfx;
    s32 width;
    s32 i;
    s32 left;
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
        width = mfsStrLen(gCourseEditMessageStrs[21]) * 8 + 16;
        left = (s32) (SCREEN_WIDTH - width) / 2;

        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        // FAKE
        gSPTextureRectangle(pad = gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, (top + 16 + 2) << 2,
                            0, 0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gSPTextureRectangle(gfx++, (left - 1) << 2, (top - 1) << 2, (left + width + 1) << 2, (top + 16 + 1) << 2, 0, 0,
                            0, 1 << 10, 1 << 10);
        gSPDisplayList(gfx++, D_3000540);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = func_xk1_800264C0(gfx, left + 16, top, 21);

        gSPDisplayList(gfx++, D_8014940);

        // B Button
        gDPLoadTextureBlock(gfx++, aExpansionKitABButtonTex + 16 * 16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        *gfxP = gfx;
    }
}

extern s32 gExpansionKitEncStrEncType;
extern s32 D_80119880;

void func_xk2_800F2E4C(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 temp;
    s32 top;
    s32 width;
    s32 height;

    if ((D_800D6CA0.state != 3) || (D_80119880 != 4)) {
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

    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, left, top, D_xk2_80104F28);
    gExpansionKitEncStrEncType = 1;
    gfx = ExpansionKit_DrawEncStr(gfx, left + 40, top, D_xk2_80104F30);
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, left + 80, top, D_xk2_80104F38);
    gExpansionKitEncStrEncType = 1;
    gfx = ExpansionKit_DrawEncStr(gfx, left + 112, top, D_xk2_80104F40);
    top += 8;
    gExpansionKitEncStrEncType = 1;

    gfx = ExpansionKit_DrawEncStr(gfx, left, top, D_xk2_80104F44);
    top += 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, left, top, D_xk2_80104F28);
    gExpansionKitEncStrEncType = 1;
    gfx = ExpansionKit_DrawEncStr(gfx, left + 40, top, D_xk2_80104F50);
    top += 8;
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, left, top, D_xk2_80104F38);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gExpansionKitEncStrEncType = 1;
    gfx = ExpansionKit_DrawEncStr(gfx, left + 32, top, D_xk2_80104F5C);
    top += 8;
    gExpansionKitEncStrEncType = 0;
    gfx = ExpansionKit_DrawEncStr(gfx, left, top, D_xk2_80104F28);
    gExpansionKitEncStrEncType = 1;
    gfx = ExpansionKit_DrawEncStr(gfx, left + 40, top, D_xk2_80104F68);
    *gfxP = gfx;
}

extern s32 gCourseEditCameraOnlyMode;

void CourseEdit_DrawCameraOnlyInstructions(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 left;
    s32 top;
    s32 width;

    if (!gCourseEditCameraOnlyMode) {
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

s32 CourseEdit_GetEncStrLength(s8* str) {
    s32 length;

    length = 0;

    while (true) {
        if (*str == '\0') {
            break;
        }
        switch (*str) {
            case 1:
            case 2:
                break;
            default:
                length++;
                break;
        }
        str++;
    }

    return length;
}

void CourseEdit_DrawTooltip(Gfx** gfxP, s32 top, s8* str) {
    s32 left;
    s32 width;
    s32 height;
    s32 length;
    Gfx* gfx;

    gfx = *gfxP;
    length = CourseEdit_GetEncStrLength(str);
    width = length * 8;
    left = (((34 - length) / 2) * 8) + 24;
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

    gfx = ExpansionKit_DrawEncStr(gfx, left, top, str);
    *gfxP = gfx;
}

extern s32 gCourseEditToolTipEnabled;
extern s32 gCourseEditHighlightedIconIndex;

void CourseEdit_DrawIconTooltip(Gfx** gfxP) {
    s32 top = 194;
    Gfx* gfx;

    if (!gCourseEditToolTipEnabled) {
        return;
    }
    gfx = *gfxP;
    switch (gCourseEditHighlightedIconIndex) {
        case COURSE_EDIT_ICON_TEST_DRIVE:
            CourseEdit_DrawTooltip(&gfx, top, sTestDriveTooltipEncStr);
            break;
        case COURSE_EDIT_ICON_LINE_DISPLAY:
            CourseEdit_DrawTooltip(&gfx, top, sLineDisplayTooltipEncStr);
            break;
        case COURSE_EDIT_ICON_ALIGN_POINTS:
            CourseEdit_DrawTooltip(&gfx, top, sAlignPointsTooltipEncStr);
            break;
        case COURSE_EDIT_ICON_TOOLTIPS:
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
    MenuWidget* widget;

    if (!gCourseEditToolTipEnabled || (D_800D6CA0.state != 1)) {
        return;
    }
    widget = func_xk1_80026914(&gCourseEditWidget);

    gfx = *gfxP;
    if (widget == &gCreateWidget) {
        switch (widget->highlightedIndex) {
            case CREATE_OPTION_COURSE:
                CourseEdit_DrawTooltip(&gfx, 24, sCreateCourseTooltipEncStr);
                func_xk2_800EECD4(&gfx, 0, 156, gCourseEditMessageStrs[25], 25);
                break;
            case CREATE_OPTION_POINT:
                CourseEdit_DrawTooltip(&gfx, 24, sCreatePointTooltipEncStr);
                func_xk2_800EECD4(&gfx, 0, 156, gCourseEditMessageStrs[26], 26);
                break;
            case CREATE_OPTION_DESIGN:
                CourseEdit_DrawTooltip(&gfx, 24, sCreateDesignTooltipEncStr);
                func_xk2_800EECD4(&gfx, 0, 156, gCourseEditMessageStrs[27], 27);
                break;
            case CREATE_OPTION_PARTS:
                CourseEdit_DrawTooltip(&gfx, 24, D_xk2_80105024);
                func_xk2_800EECD4(&gfx, 0, 156, gCourseEditMessageStrs[28], 28);
                break;
            case CREATE_OPTION_BACKGROUND:
                CourseEdit_DrawTooltip(&gfx, 24, sCreateBackgroundTooltipEncStr);
                break;
            case CREATE_OPTION_BGM:
                CourseEdit_DrawTooltip(&gfx, 24, sCreateBGMTooltipEncStr);
                break;
        }
    }
    if (widget == &gPointWidget) {
        switch (widget->highlightedIndex) {
            case POINT_OPTION_SET:
                CourseEdit_DrawTooltip(&gfx, 24, sPointSetTooltipEncStr);
                break;
            case POINT_OPTION_START:
                CourseEdit_DrawTooltip(&gfx, 24, sPointStartTooltipEncStr);
                break;
            case POINT_OPTION_CENTERING:
                CourseEdit_DrawTooltip(&gfx, 24, sPointCenteringTooltipEncStr);
                break;
            case POINT_OPTION_REVERSE:
                CourseEdit_DrawTooltip(&gfx, 24, sPointReverseTooltipEncStr);
                break;
            case POINT_OPTION_CLEAR_ALL:
                CourseEdit_DrawTooltip(&gfx, 24, sPointClearAllTooltipEncStr);
                break;
        }
    }
    if (widget == &gMoveWidget) {
        switch (widget->highlightedIndex) {
            case MOVE_OPTION_MOVE_XZ:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveXZTooltipEncStr);
                break;
            case MOVE_OPTION_MOVE_Y:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveYTooltipEncStr);
                break;
            case MOVE_OPTION_WIDTH:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveWidthTooltipEncStr);
                break;
            case MOVE_OPTION_BANK:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveBankTooltipEncStr);
                break;
            case MOVE_OPTION_CENTER:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveCenterTooltipEncStr);
                break;
            case MOVE_OPTION_CLEAR:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveClearTooltipEncStr);
                break;
            case MOVE_OPTION_STRAIGHT:
                CourseEdit_DrawTooltip(&gfx, 24, sMoveStraightTooltipEncStr);
                break;
        }
    }
    if (widget == &gCourseEditFileWidget) {
        switch (widget->highlightedIndex) {
            case FILE_OPTION_LOAD:
                CourseEdit_DrawTooltip(&gfx, 24, sFileLoadTooltipEncStr);
                break;
            case FILE_OPTION_SAVE:
                CourseEdit_DrawTooltip(&gfx, 24, sFileSaveTooltipEncStr);
                break;
            case FILE_OPTION_RENAME:
                CourseEdit_DrawTooltip(&gfx, 24, sFileRenameTooltipEncStr);
                break;
            case FILE_OPTION_ERASE:
                CourseEdit_DrawTooltip(&gfx, 24, sFileEraseTooltipEncStr);
                break;
            case FILE_OPTION_COPY:
                CourseEdit_DrawTooltip(&gfx, 24, sFileCopyTooltipEncStr);
                break;
        }
    }
    if (widget == &gCourseEditEntryWidget) {
        switch (widget->highlightedIndex) {
            case ENTRY_OPTION_REGISTER:
                CourseEdit_DrawTooltip(&gfx, 24, sEntryRegisterTooltipEncStr);
                break;
            case ENTRY_OPTION_DEREGISTER:
                CourseEdit_DrawTooltip(&gfx, 24, sEntryDeregisterTooltipEncStr);
                break;
            case ENTRY_OPTION_DEREGISTER_ALL:
                CourseEdit_DrawTooltip(&gfx, 24, sEntryDeregisterAllTooltipEncStr);
                break;
        }
    }
    if (widget == &gDesignStyleWidget) {
        switch (widget->highlightedIndex) {
            case TRACK_DESIGN_STYLE_ROAD:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignRoadTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_H_ROAD:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignHRoadTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_T_ROAD:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignTRoadTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_TUNNEL:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignTunnelTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_PIPE:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignPipeTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_HALF_PIPE:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignHalfPipeTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_CYLINDER:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignCylinderTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_SPACE:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignSpaceTooltipEncStr);
                break;
            case TRACK_DESIGN_STYLE_LOOP:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackDesignLoopTooltipEncStr);
                break;
        }
    }
    if (widget == &gPartsStyleWidget) {
        switch (widget->highlightedIndex) {
            case TRACK_PART_STYLE_PIT:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartPitTooltipEncStr);
                break;
            case TRACK_PART_STYLE_DASH:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartDashTooltipEncStr);
                break;
            case TRACK_PART_STYLE_DIRT:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartDirtTooltipEncStr);
                break;
            case TRACK_PART_STYLE_SLIP:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartIceTooltipEncStr);
                break;
            case TRACK_PART_STYLE_JUMP:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartJumpTooltipEncStr);
                break;
            case TRACK_PART_STYLE_TRAP:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartTrapTooltipEncStr);
                break;
            case TRACK_PART_STYLE_GATE:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartGateTooltipEncStr);
                break;
            case TRACK_PART_STYLE_BUILDING:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartBuildingTooltipEncStr);
                break;
            case TRACK_PART_STYLE_SIGN:
                CourseEdit_DrawTooltip(&gfx, 24, sTrackPartSignTooltipEncStr);
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
        gCourseEditToolTipEnabled = 1;
        gCourseEditIconTextures[3] = aCourseEditGoldQuestionIconTex;
        D_8076C95C = 0;
        D_8076C960 = 0;
        D_800D6CA0.state = 0;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        D_8076C95C = 0;
        D_800D6CA0.state = 0;
        func_xk2_800EE664(0x16);
    }
}

extern s32 D_8076C958;

void CourseEdit_DrawTooltipIntroHelper(Gfx** gfxP) {
    s32 left;
    s32 top;
    s32 width;
    s32 height;
    s32 strLeft;
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

    func_xk2_800F2AC0(gCourseEditMessageStrs[22]);
    strLeft = (((34 - func_xk2_800F2AF4(gCourseEditMessageStrs[22])) / 2) * 8) + 24;
    func_xk2_800EECD4(&gfx, strLeft, top, gCourseEditMessageStrs[22], 22);

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

    CourseEdit_DrawMouseClick(&gfx, 288, 204);
    *gfxP = gfx;
}
