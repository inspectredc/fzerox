#include "global.h"
#include "ovl_i6.h"
#include "audio.h"
#include "tex_assets.h"
#include "assets/segment_17B1E0.h"

s8 D_i6_8011FAF0[30];
unk_801247C0* D_i6_8011FB10;
u8 D_i6_8011FB18[2][0x2580]; // Some kind of vtx buffer space?
void* D_i6_80124618;
s16 D_i6_80124620[176];
s32 gOptionsDataClearMenu;
s16 gOptionsDataAlreadyCleared;
s32 gOptionsSelectionState[7];
unk_800E51B8* D_i6_801247A4;
s16 D_i6_801247A8;
s16 D_i6_801247AA;
TexturePtr D_i6_801247AC;
s16 D_i6_801247B0;

s8 D_i6_8011DFA0 = 0;
UNUSED s32 D_i6_8011DFA4 = 64;
UNUSED s32 D_i6_8011DFA8 = 40;

s32 D_i6_8011DFAC = 60;
s32 D_i6_8011DFB0 = 30;
s32 D_i6_8011DFB4 = 50;

/*
    VEHICLE ARTWORK
 */

// BLUE FALCON
unk_80077D50 D_i6_8011DFB8[] = { { 18, D_F1C871C, 128, 85, 0x2289 }, { 0 } };

// WILD GOOSE
unk_80077D50 D_i6_8011DFD8[] = { { 18, D_F1CA9AC, 128, 94, 0x2905 }, { 0 } };

// FIRE STINGRAY
unk_80077D50 D_i6_8011DFF8[] = { { 18, D_F1CD2B8, 128, 113, 0x2DBA }, { 0 } };

// GOLDEN FOX
unk_80077D50 D_i6_8011E018[] = { { 18, D_F1D0078, 128, 91, 0x2A88 }, { 0 } };

// RED GAZELLE
unk_80077D50 D_i6_8011E038[] = { { 18, D_F1D2B04, 128, 94, 0x1DDB }, { 0 } };

// WHITE CAT
unk_80077D50 D_i6_8011E058[] = { { 18, D_F1D48E4, 128, 79, 0x24F5 }, { 0 } };

// IRON TIGER
unk_80077D50 D_i6_8011E078[] = { { 18, D_F1D6DE0, 128, 92, 0x2C79 }, { 0 } };

// DEEP CLAW
unk_80077D50 D_i6_8011E098[] = { { 18, D_F1D9A60, 128, 87, 0x2A05 }, { 0 } };

// CRAZY BEAR
unk_80077D50 D_i6_8011E0B8[] = { { 18, D_F1DC46C, 128, 96, 0x3077 }, { 0 } };

// GREAT STAR
unk_80077D50 D_i6_8011E0D8[] = { { 18, D_F1DF4E8, 128, 82, 0x272B }, { 0 } };

// BIG FANG
unk_80077D50 D_i6_8011E0F8[] = { { 18, D_F1E1C18, 128, 100, 0x2D0A }, { 0 } };

// MAD WOLF
unk_80077D50 D_i6_8011E118[] = { { 18, D_F1E4928, 128, 97, 0x3694 }, { 0 } };

// NIGHT THUNDER
unk_80077D50 D_i6_8011E138[] = { { 18, D_F1E7FC0, 128, 84, 0x2674 }, { 0 } };

// TWIN NORITTA
unk_80077D50 D_i6_8011E158[] = { { 18, D_F1EA638, 128, 93, 0x25D7 }, { 0 } };

// WONDER WASP
unk_80077D50 D_i6_8011E178[] = { { 18, D_F1ECC14, 128, 85, 0x21A2 }, { 0 } };

// QUEEN METEOR
unk_80077D50 D_i6_8011E198[] = { { 18, D_F1EEDBC, 128, 86, 0x226D }, { 0 } };

// BLOOD HAWK
unk_80077D50 D_i6_8011E1B8[] = { { 18, D_F1F1030, 128, 96, 0x2E39 }, { 0 } };

// ASTRO ROBIN
unk_80077D50 D_i6_8011E1D8[] = { { 18, D_F1F3E70, 128, 101, 0x309E }, { 0 } };

// DEATH ANCHOR
unk_80077D50 D_i6_8011E1F8[] = { { 18, D_F1F6F14, 128, 118, 0x2B7C }, { 0 } };

// WILD BOAR
unk_80077D50 D_i6_8011E218[] = { { 18, D_F1F9A94, 128, 98, 0x2EF3 }, { 0 } };

// KING METEOR
unk_80077D50 D_i6_8011E238[] = { { 18, D_F1FC98C, 128, 103, 0x2D69 }, { 0 } };

// SUPER PIRANHA
unk_80077D50 D_i6_8011E258[] = { { 18, D_F1FF6FC, 128, 94, 0x2E5F }, { 0 } };

// MIGHTY HURRICANE
unk_80077D50 D_i6_8011E278[] = { { 18, D_F202560, 128, 83, 0x2432 }, { 0 } };

// SPACE ANGLER
unk_80077D50 D_i6_8011E298[] = { { 18, D_F204998, 128, 92, 0x2CB2 }, { 0 } };

// MIGHTY TYPHOON
unk_80077D50 D_i6_8011E2B8[] = { { 18, D_F207650, 128, 82, 0x22C9 }, { 0 } };

// HYPER SPEEDER
unk_80077D50 D_i6_8011E2D8[] = { { 18, D_F209920, 128, 101, 0x2B2E }, { 0 } };

// GREEN PANTHER
unk_80077D50 D_i6_8011E2F8[] = { { 18, D_F20C454, 128, 88, 0x287D }, { 0 } };

// BLACK BULL
unk_80077D50 D_i6_8011E318[] = { { 18, D_F20ECD8, 128, 93, 0x2488 }, { 0 } };

// LITTLE WYVERN
unk_80077D50 D_i6_8011E338[] = { { 18, D_F211164, 128, 82, 0x22DA }, { 0 } };

// SONIC PHANTOM
unk_80077D50 D_i6_8011E358[] = { { 18, D_F213444, 128, 92, 0x276B }, { 0 } };

unk_800792D8 D_i6_8011E378[] = { { D_i6_8011DFB8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E388[] = { { D_i6_8011DFD8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E398[] = { { D_i6_8011DFF8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3A8[] = { { D_i6_8011E018, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3B8[] = { { D_i6_8011E038, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3C8[] = { { D_i6_8011E058, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3D8[] = { { D_i6_8011E078, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3E8[] = { { D_i6_8011E098, 60 }, { 0 } };

unk_800792D8 D_i6_8011E3F8[] = { { D_i6_8011E0B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E408[] = { { D_i6_8011E0D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E418[] = { { D_i6_8011E0F8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E428[] = { { D_i6_8011E118, 60 }, { 0 } };

unk_800792D8 D_i6_8011E438[] = { { D_i6_8011E138, 60 }, { 0 } };

unk_800792D8 D_i6_8011E448[] = { { D_i6_8011E158, 60 }, { 0 } };

unk_800792D8 D_i6_8011E458[] = { { D_i6_8011E178, 60 }, { 0 } };

unk_800792D8 D_i6_8011E468[] = { { D_i6_8011E198, 60 }, { 0 } };

unk_800792D8 D_i6_8011E478[] = { { D_i6_8011E1B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E488[] = { { D_i6_8011E1D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E498[] = { { D_i6_8011E1F8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4A8[] = { { D_i6_8011E218, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4B8[] = { { D_i6_8011E238, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4C8[] = { { D_i6_8011E258, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4D8[] = { { D_i6_8011E278, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4E8[] = { { D_i6_8011E298, 60 }, { 0 } };

unk_800792D8 D_i6_8011E4F8[] = { { D_i6_8011E2B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E508[] = { { D_i6_8011E2D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E518[] = { { D_i6_8011E2F8, 60 }, { 0 } };

unk_800792D8 D_i6_8011E528[] = { { D_i6_8011E318, 60 }, { 0 } };

unk_800792D8 D_i6_8011E538[] = { { D_i6_8011E338, 60 }, { 0 } };

unk_800792D8 D_i6_8011E548[] = { { D_i6_8011E358, 60 }, { 0 } };

unk_800792D8* D_i6_8011E558[] = {
    D_i6_8011E498, D_i6_8011E498, D_i6_8011E378, D_i6_8011E388, D_i6_8011E398, D_i6_8011E3A8, D_i6_8011E3B8,
    D_i6_8011E3C8, D_i6_8011E3D8, D_i6_8011E3E8, D_i6_8011E3F8, D_i6_8011E408, D_i6_8011E418, D_i6_8011E428,
    D_i6_8011E438, D_i6_8011E448, D_i6_8011E458, D_i6_8011E468, D_i6_8011E478, D_i6_8011E488, D_i6_8011E498,
    D_i6_8011E4A8, D_i6_8011E4B8, D_i6_8011E4C8, D_i6_8011E4D8, D_i6_8011E4E8, D_i6_8011E4F8, D_i6_8011E508,
    D_i6_8011E518, D_i6_8011E528, D_i6_8011E538, D_i6_8011E548,
};

/*
    CREDITS / ENDING IMAGES + CHARACTER PORTRAITS
 */

// ENDING SCREEN GIRL
unk_80077D50 D_i6_8011E5D8[] = { { 17, D_F1C417C, 80, 182, 0x25D1 }, { 0 } };

// 'SEE YOU AGAIN!!'
unk_80077D50 D_i6_8011E5F8[] = { { 17, D_F1C6754, 64, 64, 0x95A }, { 0 } };

// MR ZERO
unk_80077D50 D_i6_8011E618[] = { { 17, D_F1C70B4, 80, 72, 0x1662 }, { 0 } };

// COPYRIGHT LOGO (1998)
unk_80077D50 D_i6_8011E638[] = { { 17, D_F0336B8, 128, 14, 0x439 }, { 0 } };

// DR STEWART
unk_80077D50 D_i6_8011E658[] = { { 17, D_F033AB4, 180, 245, 0x4AF4 }, { 0 } };

// CAPTAIN FALCON
unk_80077D50 D_i6_8011E678[] = { { 17, D_F0385AC, 180, 245, 0x6604 }, { 0 } };

// JODY SUMMER
unk_80077D50 D_i6_8011E698[] = { { 17, D_F03EBB4, 180, 245, 0x5573 }, { 0 } };

// SAMURAI GOROH
unk_80077D50 D_i6_8011E6B8[] = { { 17, D_F04412C, 180, 245, 0x76B4 }, { 0 } };

// MIGHTY GAZELLE
unk_80077D50 D_i6_8011E6D8[] = { { 17, D_F04B7E4, 180, 245, 0x67F2 }, { 0 } };

// PICO
unk_80077D50 D_i6_8011E6F8[] = { { 17, D_F051FDC, 180, 245, 0x63BB }, { 0 } };

// BABA
unk_80077D50 D_i6_8011E718[] = { { 17, D_F05839C, 180, 245, 0x5EE9 }, { 0 } };

// MR EAD
unk_80077D50 D_i6_8011E738[] = { { 17, D_F05E28C, 180, 245, 0x7184 }, { 0 } };

// OCTOMAN
unk_80077D50 D_i6_8011E758[] = { { 17, D_F065414, 180, 245, 0x5666 }, { 0 } };

// THE SKULL
unk_80077D50 D_i6_8011E778[] = { { 17, D_F06AA80, 180, 245, 0x5A49 }, { 0 } };

// BEASTMAN
unk_80077D50 D_i6_8011E798[] = { { 17, D_F0704D0, 180, 245, 0x55C1 }, { 0 } };

// ANTONIO GUSTER
unk_80077D50 D_i6_8011E7B8[] = { { 17, D_F075A98, 180, 245, 0x594F }, { 0 } };

// DRAQ
unk_80077D50 D_i6_8011E7D8[] = { { 17, D_F07B3EC, 180, 245, 0x7A7A }, { 0 } };

// ROGER BUSTER
unk_80077D50 D_i6_8011E7F8[] = { { 17, D_F082E6C, 180, 245, 0x6444 }, { 0 } };

// SILVER NEEISEN
unk_80077D50 D_i6_8011E818[] = { { 17, D_F0892B4, 180, 245, 0x623A }, { 0 } };

// SUPER ARROW
unk_80077D50 D_i6_8011E838[] = { { 17, D_F08F4F4, 180, 245, 0x6F78 }, { 0 } };

// MRS ARROW
unk_80077D50 D_i6_8011E858[] = { { 17, D_F096470, 180, 245, 0x5C56 }, { 0 } };

// ZODA
unk_80077D50 D_i6_8011E878[] = { { 17, D_F09C0CC, 180, 245, 0x59E6 }, { 0 } };

// JOHN TANAKA
unk_80077D50 D_i6_8011E898[] = { { 17, D_F0A1AB8, 180, 245, 0x5B58 }, { 0 } };

// BIO REX
unk_80077D50 D_i6_8011E8B8[] = { { 17, D_F0A7614, 180, 245, 0x6B2D }, { 0 } };

// KATE ALEN
unk_80077D50 D_i6_8011E8D8[] = { { 17, D_F0AE148, 180, 245, 0x4E48 }, { 0 } };

// GOMAR & SHIOH
unk_80077D50 D_i6_8011E8F8[] = { { 17, D_F0B2F94, 180, 245, 0x6D92 }, { 0 } };

// MICHAEL CHAIN
unk_80077D50 D_i6_8011E918[] = { { 17, D_F0B9D2C, 180, 245, 0x5AB3 }, { 0 } };

// BILLY
unk_80077D50 D_i6_8011E938[] = { { 17, D_F0BF7E4, 180, 245, 0x5E3B }, { 0 } };

// DR CLASH
unk_80077D50 D_i6_8011E958[] = { { 17, D_F0C5624, 180, 245, 0x6EAC }, { 0 } };

// JACK LEVIN
unk_80077D50 D_i6_8011E978[] = { { 17, D_F0CC4D4, 180, 245, 0x4D32 }, { 0 } };

// BLOOD FALCON
unk_80077D50 D_i6_8011E998[] = { { 17, D_F0D120C, 180, 245, 0x603A }, { 0 } };

// LEON
unk_80077D50 D_i6_8011E9B8[] = { { 17, D_F0D724C, 180, 245, 0x60B6 }, { 0 } };

// JAMES MCCLOUD
unk_80077D50 D_i6_8011E9D8[] = { { 17, D_F0DD308, 180, 245, 0x5534 }, { 0 } };

// BLACK SHADOW
unk_80077D50 D_i6_8011E9F8[] = { { 17, D_F0E2840, 180, 245, 0x5DA7 }, { 0 } };

unk_800792D8 D_i6_8011EA18[] = { { D_i6_8011E658, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA28[] = { { D_i6_8011E678, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA38[] = { { D_i6_8011E698, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA48[] = { { D_i6_8011E6B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA58[] = { { D_i6_8011E6D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA68[] = { { D_i6_8011E6F8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA78[] = { { D_i6_8011E718, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA88[] = { { D_i6_8011E738, 60 }, { 0 } };

unk_800792D8 D_i6_8011EA98[] = { { D_i6_8011E758, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAA8[] = { { D_i6_8011E778, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAB8[] = { { D_i6_8011E798, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAC8[] = { { D_i6_8011E7B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAD8[] = { { D_i6_8011E7D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAE8[] = { { D_i6_8011E7F8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EAF8[] = { { D_i6_8011E818, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB08[] = { { D_i6_8011E838, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB18[] = { { D_i6_8011E858, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB28[] = { { D_i6_8011E878, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB38[] = { { D_i6_8011E898, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB48[] = { { D_i6_8011E8B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB58[] = { { D_i6_8011E8D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB68[] = { { D_i6_8011E8F8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB78[] = { { D_i6_8011E918, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB88[] = { { D_i6_8011E938, 60 }, { 0 } };

unk_800792D8 D_i6_8011EB98[] = { { D_i6_8011E958, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBA8[] = { { D_i6_8011E978, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBB8[] = { { D_i6_8011E998, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBC8[] = { { D_i6_8011E9B8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBD8[] = { { D_i6_8011E9D8, 60 }, { 0 } };

unk_800792D8 D_i6_8011EBE8[] = { { D_i6_8011E9F8, 60 }, { 0 } };

unk_800792D8* D_i6_8011EBF8[] = {
    D_i6_8011EA28, D_i6_8011EA68, D_i6_8011EA48, D_i6_8011EA18, D_i6_8011EA58, D_i6_8011EA38,
    D_i6_8011EA78, D_i6_8011EA98, D_i6_8011EB98, D_i6_8011EA88, D_i6_8011EB48, D_i6_8011EB88,
    D_i6_8011EAF8, D_i6_8011EB68, D_i6_8011EB38, D_i6_8011EB18, D_i6_8011EBB8, D_i6_8011EBA8,
    D_i6_8011EB28, D_i6_8011EB78, D_i6_8011EB08, D_i6_8011EB58, D_i6_8011EAE8, D_i6_8011EBC8,
    D_i6_8011EAD8, D_i6_8011EAB8, D_i6_8011EAC8, D_i6_8011EBE8, D_i6_8011EBD8, D_i6_8011EAA8,
};

const char* gCreditsAttributions[] = {
    "director",          "assistant director", "chief programmer",    "programmer",          "programmer",
    "programmer",        "dd programmer",      "dd programmer",       "sound composer",      "sound composer",
    "sound effects",     "chief designer",     "graphic designer",    "machine modeler",     "course design",
    "course design",     "course design",      "course design",       "sequence support",    "graphic support",
    "technical support", "technical support",  "progress management", "progress management", "special thanks to",
    "special thanks to", "special thanks to",  "special thanks to",   "special thanks to",   "executive producer",
    "producer",
};

const char* gCreditsNames[] = { "tadashi sugiyama", "yasuyuki oyagi",    "keizo ohta",       "tsutomu kaneshige",
                                "masahiro kawano",  "daisuke tsujimura", "hiroki sotoike",   "shiro mouri",
                                "taro bando",       "hajime wakai",      "taro bando",       "takaya imamura",
                                "katsuhiko kanno",  "tadashi sugiyama",  "tadashi sugiyama", "takaya imamura",
                                "yasuyuki oyagi",   "keizo ohta",        "hideki konno",     "masanao arimoto",
                                "hironobu kakui",   "shin hasegawa",     "kimiyoshi fukui",  "keizo kato",
                                "yasuhiro sakai",   "atsushi tejima",    "masanori sato",    "takayuki hashida",
                                "super mario club", "hiroshi yamauchi",  "shigeru miyamoto", "yoshitaka yasumoto",
                                "naruhisa kawano",  "sou kimura",        "kayomi mcdonald",  "jim wornell" };

const s16 D_i6_8011F4BC[] = { 50, 240, 280, -20, 280, 240, 50, -20 };

const s16 D_i6_8011F4CC[] = { 50, 100, 280, 180, 280, 100, 50, 180 };

const s16 D_i6_8011F4DC[] = { 150, 210, 50, 35, 50, 210, 150, 35 };

const s16 D_i6_8011F4EC[] = { 216, 0,   0, 248, 0, 0,   0, 0,   217, 0,   0,   249, 0, 0,   0,   0,   218, 0,
                              0,   250, 0, 251, 0, 0,   0, 0,   220, 0,   0,   252, 0, 253, 0,   0,   0,   0,
                              222, 0,   0, 254, 0, 255, 0, 262, 0,   256, 0,   257, 0, 261, 0,   263, 0,   264,
                              0,   265, 0, 258, 0, 0,   0, 0,   0,   0,   0,   0,   0, 0,   0,   0,   0,   0,
                              0,   0,   0, 0,   0, 0,   0, 0,   0,   0,   0,   0,   0, 0,   227, 0,   0,   259,
                              0,   0,   0, 0,   0, 0,   0, 0,   0,   0,   0,   0,   0, 0,   0,   0,   0,   0,
                              0,   0,   0, 0,   0, 0,   0, 0,   0,   0,   228, 0,   0, 260, -1,  0 };

UNUSED s32 D_i6_8011ED7C = 0; // UNUSED?

/*
    OPTIONS MENU
 */

// 'WITH', 'W/O'
OptionsTextureInfo gOptionsVsComSelection[] = {
    { D_F262FB4, 32, 16 },
    { D_F262ED0, 32, 16 },
};

// 'WITH', 'W/O'
OptionsTextureInfo gOptionsVsSlotSelection[] = {
    { D_F262FB4, 32, 16 },
    { D_F262ED0, 32, 16 },
};

// 'W/O', '+1', '+2'
OptionsTextureInfo gOptionsVsHandicapSelection[] = {
    { D_F262ED0, 32, 16 },
    { D_F263190, 32, 16 },
    { D_F263230, 32, 16 },
};

// 'Stereo', 'Mono'
OptionsTextureInfo gOptionsSoundModeSelection[] = {
    { D_F2632E8, 64, 16 },
    { D_F2634A4, 64, 16 },
};

// 'No', 'Yes'
OptionsTextureInfo gOptionsAllDataClearSelection[] = {
    { D_F2637DC, 32, 16 },
    { D_F2636F0, 32, 16 },
};

s32 gOptionsCurrentRow = 0;

OptionsInfo gOptionsInfo[] = {
    // 'VS COM (2P,3P)'
    { OPTIONS_VS_COM, OPTIONS_SHOWN, 2, 0, 0, gOptionsVsComSelection, { D_F261AD4, 128, 16 } },
    // 'VS Slot'
    { OPTIONS_VS_SLOT, OPTIONS_SHOWN, 2, 0, 0, gOptionsVsSlotSelection, { D_F262184, 96, 16 } },
    // 'VS Handicap'
    { OPTIONS_VS_HANDICAP, OPTIONS_SHOWN, 3, 0, 0, gOptionsVsHandicapSelection, { D_F261E80, 96, 16 } },
    // 'Sound Mode'
    { OPTIONS_SOUND_MODE, OPTIONS_SHOWN, 2, 0, 0, gOptionsSoundModeSelection, { D_F262398, 96, 16 } },
    // 'All data clear'
    { OPTIONS_DATA_CLEAR, OPTIONS_REQUIRE_SELECTING | OPTIONS_SHOWN, 0, 0, 0, NULL, { D_F262688, 96, 16 } },
    // 'Copying ghost'
    { OPTIONS_GHOST_COPY, OPTIONS_REQUIRE_SELECTING, 0, 0, 0, NULL, { D_F263DA8, 96, 16 } },
    // 'EXIT'
    { OPTIONS_EXIT, OPTIONS_REQUIRE_SELECTING | OPTIONS_SHOWN, 0, 0, 0, NULL, { D_F2630C8, 40, 16 } },
};

UNUSED char D_i6_8011EEBC[] = "Feel Mie";

extern unk_800E3A28 D_800E3A28[];
extern unk_800E3F28 D_800E3F28[];

void func_i6_80117EE0(unk_800E3A28* arg0) {

    arg0->unk_18 = func_800792D8(D_i6_8011E558[0]);

    arg0->unk_04 = 0;

    D_800E3F28[arg0->unk_18].unk_04 = -1;
}

void func_i6_80117F2C(unk_800E3A28* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_i6_8011FAF0); i++) {
        D_i6_8011FAF0[i] = 0;
    }
    arg0->unk_18 = func_800792D8(D_i6_8011E558[0]);

    D_800E3F28[arg0->unk_18].unk_04 = -1;
}

void func_i6_80117FA8(unk_800E3A28* arg0) {
    func_80077D50(D_i6_8011E5D8, 0);
    arg0->unk_1C = 0xB6;
}

void func_i6_80117FE0(void) {
    func_80077D50(D_i6_8011E5F8, 0);
}

void func_i6_80118008(unk_800E3A28* arg0) {
    func_80077D50(D_i6_8011E618, 0);
    arg0->unk_1C = 0x100;
    arg0->unk_18 = 0;
}

void func_i6_80118044(void) {
    func_80077D50(D_i6_8011E638, 0);
}

void func_i6_8011806C(unk_800E3A28* arg0) {

    arg0->unk_18 = func_800792D8(D_i6_8011EBF8[0]);

    D_800E3F28[arg0->unk_18].unk_04 = -1;
}

s16 func_i2_801061D4(s8*, s32);

Gfx* func_i6_801180B4(Gfx* gfx, unk_800E3A28* arg1, s32* arg2, s32 arg3) {
    s32 temp_v0;
    s32 i;
    s32 var_s2;
    s32 var_v0;
    s32 sp7C;
    s32 var_v1;
    s32 pad[4]; // possibly part of buffer
    s8 sp64[2];
    s8* name;

    name = gCreditsNames[arg1->unk_00 - 230];

    if (arg3 != 0) {
        i = func_i2_801062E4(name, 1, 0);
    } else {
        i = 0;
    }

    var_s2 = arg1->unk_0C - i;
    sp7C = arg1->unk_10;

    var_v0 = arg1->unk_1C / 5;
    if (var_v0 >= 23) {
        var_v0 = 23;
    }
    *arg2 = 0;

    for (i = 0; i < var_v0 + 1; i++) {

        sp64[0] = *name++;
        if (sp64[0] == 0) {
            break;
        }

        sp64[1] = 0;
        var_v1 = arg1->unk_1C - (i * 5);
        if (var_v1 >= 5) {
            var_v1 = 5;
        } else {
            *arg2 = 1;
        }
        if (var_v1 < 0) {
            break;
        }

        temp_v0 = 5 - var_v1;
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (var_v1 * 255) / 5);
        gfx = func_i2_80106450(gfx, (temp_v0 * 2) + var_s2, sp7C - SQ(temp_v0), sp64, 0, 1, 1);

        var_s2 += func_i2_801061D4(sp64, 1);
    }

    return gfx;
}

Gfx* func_i6_801182DC(Gfx* gfx, unk_800E3A28* arg1) {

    if (!D_i6_8011DFA0) {
        return gfx;
    }

    return func_80078F80(gfx, &D_800E3F28[arg1->unk_18], arg1->unk_0C, arg1->unk_10, 0, 0, 0, 1.0f, 1.0f);
}

#define UNK_RAND_MACRO(var, x, y) (((Math_Rand1() >> (var % 4)) % x) - y)

Gfx* func_i6_80118354(Gfx* gfx, unk_800E3A28* arg1) {
    s32 sp154;
    s32 row;
    s32 var_t5;
    f32 var_fv1;
    s32 sp144;
    unk_800E3F28* temp_s1;
    s32 height;
    s32 width;
    s32 var_a0;
    s32 pad;
    s32 additionalWidth;
    s32 additionalHeight;
    f32 var_ft4;
    TexturePtr texture;
    s32 var_s3;

    temp_s1 = &D_800E3F28[arg1->unk_18];

    sp144 = arg1->unk_0C;
    var_s3 = arg1->unk_10;

    if (arg1->unk_10 > 120) {
        var_s3 = arg1->unk_10 - temp_s1->unk_00->unk_00->height;
    }

    sp154 = arg1->unk_1C;
    if (sp154 > 64) {
        sp154 = 64;
    }

    width = temp_s1->unk_00->unk_00->width;
    height = temp_s1->unk_00->unk_00->height;

    switch (arg1->unk_08) {
        case 0:

            if (temp_s1->unk_0A == 0) {
                texture = temp_s1->unk_0C;
            } else {
                texture = temp_s1->unk_10;
            }

            gSPDisplayList(gfx++, D_3000088);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, (sp154 * 255) / 64);

            var_a0 = UNK_RAND_MACRO(row, 13, 6);
            sp144 += var_a0 * (64 - sp154) / 64;

            for (row = 0; row < height; row++) {
                var_a0 = UNK_RAND_MACRO(row, 15, 7);
                if ((var_a0 < 4) && (var_a0 > -4)) {
                    var_a0 = 0;
                } else {
                    if (var_a0 > 0) {
                        var_a0 -= (sp154 * 4) / 64;
                        var_a0 = var_a0 * var_a0;
                    } else {
                        var_a0 += (sp154 * 4) / 64;
                        var_a0 = -var_a0 * var_a0;
                    }
                    var_a0 = ((64 - sp154) * var_a0) / 64;
                }

                var_t5 = (UNK_RAND_MACRO(row, 7, 3) * (64 - sp154)) / 64;

                if (((row + var_t5) < 0) || ((row + var_t5) >= height)) {
                    var_t5 = 0;
                }

                gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, 1 /* unused by macro */, 0,
                                   (row + var_t5), width, (row + var_t5) + 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPScisTextureRectangle(gfx++, (sp144 + var_a0) << 2, (var_s3 + row) << 2,
                                        ((sp144 + var_a0) + width) << 2, (var_s3 + row + 1) << 2, 0, 0, 0, 1 << 10,
                                        1 << 10);
            }
            break;
        case 1:
            gfx = func_80078F80(gfx, temp_s1, arg1->unk_0C, var_s3, 0, 0, 0, 1.0f, 1.0f);
            break;
        case 2:
            if (sp154 < 5) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);

                var_fv1 = (64 - (sp154 * 2)) / 64.0f;
                additionalWidth = (width * (1.0f - var_fv1)) / 2;
                additionalHeight = (height * (1.0f - var_fv1)) / 2;

                gfx = func_80078F80(gfx, temp_s1, arg1->unk_0C + additionalWidth, var_s3 + additionalHeight, 4, 0, 0,
                                    var_fv1, var_fv1);
            } else {
                if (temp_s1->unk_0A == 0) {
                    texture = temp_s1->unk_0C;
                } else {
                    texture = temp_s1->unk_10;
                }
                gSPDisplayList(gfx++, D_3000088);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);

                var_fv1 = (64 - (sp154 * 2)) / 64.0f;
                var_ft4 = (84 - (sp154 * 6)) / 64.0f;

                if (var_fv1 < 0.0f) {
                    var_fv1 = 0;
                }
                if (var_ft4 < 0.0f) {
                    var_ft4 = 0;
                }

                if (var_fv1 != 0.0f) {
                    var_t5 = 1024.0f / var_fv1;
                } else {
                    var_t5 = 0;
                }

                additionalWidth = (width * (1.0f - var_fv1)) / 2;
                additionalHeight = (height * (1.0f - var_ft4)) / 2;

                for (row = 0; row < height; row++) {
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, ((64 - sp154) * 255) / 64);
                    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                    gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, 1 /* unused by macro */, 0,
                                       row, width, row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                       G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    gSPScisTextureRectangle(gfx++, (sp144 + additionalWidth) << 2,
                                            (s32) ((var_s3 + additionalHeight) + (row * var_ft4)) << 2,
                                            ((sp144 + additionalWidth) + width) << 2,
                                            (s32) (((var_s3 + additionalHeight) + (row * var_ft4)) + 1.0f) << 2, 0, 0,
                                            0, var_t5, 1 << 10);
                    gDPPipeSync(gfx++);
                    gfx = func_8007A440(gfx, (sp144 + additionalWidth), ((var_s3 + additionalHeight) + (row * var_ft4)),
                                        ((sp144 + additionalWidth) + (width * var_fv1)),
                                        ((var_s3 + additionalHeight) + (row * var_ft4)) + 1.0f, 0x80, 0x80, 0x80, 0x10);
                }
            }
            break;
    }

    return gfx;
}

Gfx* func_i6_80118ED4(Gfx* gfx, unk_800E3A28* arg1) {
    s32 row;
    s32 var_a0;
    s32 var_a1;
    s32 spB0;
    s32 var_s1;
    s32 alpha;
    s32 var_t5;
    TexturePtr texture;

    texture = func_800783AC(D_F1C417C);
    spB0 = arg1->unk_0C;
    var_s1 = arg1->unk_10;

    gSPDisplayList(gfx++, D_3000088);

    for (row = 0; row < 182; row++) {
        var_t5 = 0;

        switch (arg1->unk_04) {
            case 0:
                alpha = row - arg1->unk_1C;
                if (alpha < 0) {
                    alpha = -alpha;
                }

                if (alpha < 8) {
                    alpha = 255 - (alpha * 32);
                } else {
                    alpha = 0;
                }
                break;
            case 1:
                alpha = row - 0x17;
                if (alpha < 0) {
                    alpha = -alpha;
                }
                if (alpha < 8) {
                    alpha = 255 - (alpha * 32);
                } else {
                    alpha = 0;
                }
                break;
            case 2:
                var_a1 = row - 0x17;
                var_a0 = arg1->unk_1C - 0x17;
                if (var_a0 < 0) {
                    var_a0 = -var_a0;
                }
                if (var_a1 < 0) {
                    var_a1 = -var_a1;
                }
                alpha = (var_a0 - var_a1);
                if (var_a1 < var_a0) {
                    alpha = 255;
                } else if ((var_a1 - var_a0) < 8) {
                    alpha = (alpha * 32) + 255;
                } else {
                    alpha = 0;
                }
                break;
            case 3:
                alpha = 255;
                break;
            case 4:
                alpha = 255;
                if (arg1->unk_08 != 0) {
                    var_a0 = UNK_RAND_MACRO(row, 7, 3);
                    var_t5 = (s32) ((0x20 - arg1->unk_08) * var_a0) / 32;
                }
                break;
            default:
                alpha = 255;
                break;
        }

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 1 /* unused by macro */, 0, row, 80,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, (spB0 + var_t5) << 2, (var_s1 + row) << 2, (spB0 + var_t5 + 80) << 2,
                                (var_s1 + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gSPScisTextureRectangle(gfx++, ((240 - spB0) + var_t5) << 2, (var_s1 + row) << 2, ((320 - spB0) + var_t5) << 2,
                                (var_s1 + row + 1) << 2, 0, 0x9E0, 0, 0xFC00, 1 << 10);
    }

    arg1->unk_08 = 0;

    return gfx;
}

Gfx* func_i6_8011946C(Gfx* gfx, unk_800E3A28* arg1) {
    s32 row;
    s32 sp50;
    s32 alpha;
    s32 var_s2;
    s32 var_s5;
    TexturePtr texture;

    arg1->unk_1C++;
    texture = func_800783AC(D_F1C6754);
    sp50 = arg1->unk_0C;
    var_s5 = arg1->unk_10;

    gSPDisplayList(gfx++, D_3000088);

    if (arg1->unk_04 == 1) {
        gDPSetAlphaCompare(gfx++, G_AC_DITHER);
    }

    for (row = 0; row < 64; row++) {
        switch (arg1->unk_04) {
            case 0:
                var_s2 = UNK_RAND_MACRO(row, 11, 5);
                if (arg1->unk_1C < 64) {
                    var_s2 = (s32) ((64 - arg1->unk_1C) * var_s2) / 64;
                } else {
                    var_s2 = 0;
                }
                if (arg1->unk_1C < 6) {
                    alpha = arg1->unk_1C * 50;
                } else {
                    alpha = 255;
                }
                break;
            case 1:

                var_s2 = UNK_RAND_MACRO(row, 7, 3);
                ;
                if (arg1->unk_1C < 32) {
                    var_s2 = ((32 - arg1->unk_1C) * var_s2) / 32;
                    func_80079E88(0xC1)->unk_08 = arg1->unk_1C;
                } else {
                    var_s2 = 0;
                }
                if (arg1->unk_1C < 20) {
                    if (arg1->unk_1C < 10) {
                        alpha = 255 - (arg1->unk_1C * 10);
                    } else {
                        alpha = (arg1->unk_1C * 10) + 55;
                    }
                } else {
                    alpha = 255;
                }
                break;
            default:
                var_s2 = 0;
                alpha = 255;
                break;
        }

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 1 /* unused by macro */, 0, row, 64,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, (sp50 + var_s2) << 2, (var_s5 + row) << 2, (sp50 + var_s2 + 64) << 2,
                                (var_s5 + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    return gfx;
}

Gfx* func_i6_80119908(Gfx* gfx, unk_800E3A28* arg1);
#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i6/E2000/func_i6_80119908.s")

Gfx* func_i6_8011A248(Gfx* gfx, unk_800E3A28* arg1) {
    s32 var_s2;
    s32 temp_s7;
    s32 var_a2;
    s32 row;
    TexturePtr texture;

    arg1->unk_1C++;
    texture = func_800783AC(D_F0336B8);
    var_s2 = arg1->unk_10;
    temp_s7 = arg1->unk_0C;
    gSPDisplayList(gfx++, D_3000088);

    for (row = 0; row < 14; row++) {
        var_a2 = UNK_RAND_MACRO(row, 11, 5);
        if (arg1->unk_1C < 32) {
            var_a2 = ((32 - arg1->unk_1C) * var_a2) / 32;
        } else {
            var_a2 = 0;
        }
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 1 /* unused by macro */, 0, row, 128,
                           row + 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, (temp_s7 + var_a2) << 2, (var_s2 + row) << 2, (temp_s7 + var_a2 + 128) << 2,
                                (var_s2 + row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    return gfx;
}

Gfx* func_i6_8011A59C(Gfx* gfx, unk_800E3A28* arg1) {
    s32 pad[14];
    unk_800E3F28* sp34;
    s32 temp_v1;
    s32 var_a2;
    s32 temp;

    sp34 = &D_800E3F28[arg1->unk_18];
    temp_v1 = arg1->unk_1C;
    temp = D_i6_8011F4DC[(arg1->unk_20 % 4) * 2];

    if (temp < 100) {
        var_a2 = 320 - (temp_v1 / 1.2);
    } else {
        var_a2 = (temp_v1 / 1.2) - 180;
    }

    if (arg1->unk_08 == 0) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - temp_v1);
        gfx = func_80078F80(gfx, sp34, var_a2, -5, 1, 0, 0, 1.0f, 1.0f);
    }
    return gfx;
}

Gfx* func_i6_8011A6CC(Gfx* gfx, unk_800E3A28* arg1) {
    s32 pad[3];
    s32 temp_v0;
    s8* temp_s2;

    temp_v0 = arg1->unk_00 - 198;
    temp_s2 = gCreditsAttributions[temp_v0];

    gDPSetPrimColor(gfx++, 0, 0, 24, 24, 24, 255);

    switch (temp_v0 % 4) {
        case 0:
        case 3:
            gfx = func_i2_80106450(gfx, arg1->unk_0C + 1, arg1->unk_10 + 1, temp_s2, 0, 6, 0);
            break;
        case 1:
        case 2:
            gfx = func_i2_80106450(gfx, (arg1->unk_0C - func_i2_801062E4(temp_s2, 6, 0)) + 1, arg1->unk_10 + 1, temp_s2,
                                   0, 6, 0);
            break;
    }

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    switch (temp_v0 % 4) {
        case 0:
        case 3:
            gfx = func_i2_80106450(gfx, arg1->unk_0C, arg1->unk_10, temp_s2, 0, 6, 0);
            break;
        case 1:
        case 2:
            gfx = func_i2_80106450(gfx, arg1->unk_0C - func_i2_801062E4(temp_s2, 6, 0), arg1->unk_10, temp_s2, 0, 6, 0);
            break;
    }

    return gfx;
}

Gfx* func_i6_8011A890(Gfx* gfx, unk_800E3A28* arg1) {
    s8* temp_a3;
    s32 index = arg1->unk_00 - 198;

    temp_a3 = gCreditsAttributions[index];

    gDPSetPrimColor(gfx++, 0, 0, 24, 24, 24, 255);
    gfx = func_i2_80106450(gfx, arg1->unk_0C + 1, arg1->unk_10 + 1, temp_a3, 0, 6, 0);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i2_80106450(gfx, arg1->unk_0C, arg1->unk_10, temp_a3, 0, 6, 0);

    return gfx;
}

Gfx* func_i6_8011A944(Gfx* gfx, unk_800E3A28* arg1) {
    s32 temp_v1;
    s32 pad[2];
    s32 sp60;
    s32 pad2[9];
    char* temp_a3;

    temp_v1 = arg1->unk_00 - 230;
    temp_a3 = gCreditsNames[temp_v1];

    switch (arg1->unk_04) {
        case 0:
            sp60 = 0;
            switch (temp_v1 % 4) {
                case 0:
                case 3:
                    gfx = func_i6_801180B4(gfx, arg1, &sp60, 0);
                    break;
                case 1:
                case 2:
                    gfx = func_i6_801180B4(gfx, arg1, &sp60, 1);
                    break;
            }
            if (sp60 == 0) {
                arg1->unk_04 = 1;
            }
            break;
        case 1:
        case 2:
            switch (temp_v1 % 4) {
                case 0:
                case 3:
                    gfx = func_i2_80106450(gfx, arg1->unk_0C, arg1->unk_10, temp_a3, 0, 1, 0);
                    break;
                case 1:
                case 2:
                    gfx = func_i2_80106450(gfx, arg1->unk_0C - func_i2_801062E4(temp_a3, 1, 0), arg1->unk_10, temp_a3,
                                           0, 1, 0);
                    break;
            }
            break;
    }
    return gfx;
}

Gfx* func_i6_8011AAC8(Gfx* gfx, unk_800E3A28* arg1) {
    s32 index = arg1->unk_00 - 0xE6;
    char* temp = gCreditsNames[index];

    return func_i2_80106450(gfx, arg1->unk_0C, arg1->unk_10, temp, 0, 1, 0);
}

extern u16 D_800E416C;

void func_i6_8011AB1C(unk_800E3A28* arg0) {
    s32 var_v1;
    unk_800E3F28* temp_v0;

    temp_v0 = &D_800E3F28[arg0->unk_18];
    var_v1 = 0;
    if (temp_v0->unk_04 == -1) {
        temp_v0->unk_04 = 0;
        arg0->unk_04 = 0;
        var_v1 = 1;
    }
    if (D_i6_8011DFA0) {
        if (D_800E416C & BTN_LEFT) {
            func_800BA8D8(30);
            if (arg0->unk_04 != 0) {
                arg0->unk_04--;
            } else {
                arg0->unk_04 = 29;
            }
            var_v1++;
        }

        if (D_800E416C & BTN_RIGHT) {
            func_800BA8D8(30);
            arg0->unk_04++;
            arg0->unk_04 = arg0->unk_04 % 30;
            var_v1++;
        }
    }
    if (var_v1 != 0) {
        func_800793E8(arg0->unk_18, 0, D_i6_8011E558[arg0->unk_04 + 2]);
    }
}

void func_i6_8011AC38(unk_800E3A28* arg0) {
    s32 pad;
    s32 var_a2;
    s32 var_v1;
    unk_800E3A28* temp_v0_2;

    var_a2 = 0;

    arg0->unk_0C = D_i6_8011F4DC[(arg0->unk_20 % 4) * 2 + 0];
    arg0->unk_10 = D_i6_8011F4DC[(arg0->unk_20 % 4) * 2 + 1];
    switch (arg0->unk_08) {
        case 0:
            if (++arg0->unk_1C >= 64) {
                arg0->unk_08 = 1;
            }
            break;
        case 1:
            arg0->unk_1C = 0;
            break;
        case 2:
            if (++arg0->unk_1C >= 64) {
                arg0->unk_08 = 3;
                arg0->unk_1C = 0;
                temp_v0_2 = func_80079E88(0xBE);
                var_a2 = 0;
                if (temp_v0_2 != NULL) {
                    temp_v0_2->unk_08 = 2;
                }
            }
            break;
        case 3:
            if (arg0->unk_1C != 0) {
                arg0->unk_08 = 0;
                arg0->unk_20++;
                var_v1 = 0;
                if ((arg0->unk_20 == 5) && (D_i6_8011FAF0[9] == 0)) {
                    var_a2 = 9;
                    D_i6_8011FAF0[9] = 1;
                    var_v1 = 1;
                }
                if (var_v1 == 0) {
                    while (true) {
                        var_a2 = Math_Rand1() % 30;
                        if (D_i6_8011FAF0[var_a2] == 0) {
                            D_i6_8011FAF0[var_a2] = 1;
                            goto label;
                        }
                        var_v1++;
                        if (var_v1 > 10) {
                            break;
                        }
                    }

                    for (var_v1 = 0; var_v1 < ARRAY_COUNT(D_i6_8011FAF0); var_v1++) {
                        var_a2 = var_v1;
                        if (D_i6_8011FAF0[var_v1] == 0) {
                            D_i6_8011FAF0[var_v1] = 1;
                            goto label;
                        }
                    }
                }
            label:
                arg0->unk_04 = var_a2;
                var_a2 = 1;
                temp_v0_2 = func_80079E88(0xC5);
                if ((temp_v0_2 != NULL) && (temp_v0_2->unk_08 == 3)) {
                    temp_v0_2->unk_1C = 1;
                }
            }
            break;
    }

    if (D_800E3F28[arg0->unk_18].unk_04 == -1) {
        D_800E3F28[arg0->unk_18].unk_04 = 0;
        arg0->unk_04 = Math_Rand1() % 30;
        D_i6_8011FAF0[arg0->unk_04] = 1;
        var_a2++;
    }
    if (var_a2 != 0) {
        func_800793E8(arg0->unk_18, 0, D_i6_8011E558[arg0->unk_04 + 2]);
    }
}

void func_i6_8011AEB4(unk_800E3A28* arg0) {
    s32 pad;
    s32 var_v1 = 0;

    switch (arg0->unk_08) {
        case 0:
            if (++arg0->unk_1C >= 255) {
                arg0->unk_1C = 0;
                arg0->unk_08 = 3;
            }
            break;
        case 3:
            if (arg0->unk_1C != 0) {
                arg0->unk_08 = 0;
                arg0->unk_20++;
                arg0->unk_04 = func_80079E88(0xC0)->unk_04;
                var_v1 = 1;
                arg0->unk_1C = 0;
            }
            break;
    }

    if (D_800E3F28[arg0->unk_18].unk_04 == -1) {
        D_800E3F28[arg0->unk_18].unk_04 = 0;
        arg0->unk_04 = func_80079E88(0xC0)->unk_04;
        var_v1++;
    }
    if (var_v1 != 0) {
        func_800793E8(arg0->unk_18, 0, D_i6_8011EBF8[arg0->unk_04]);
    }
}

bool func_i6_8011AFC8(unk_800E3A28* arg0, s32 arg1, s32 arg2) {

    arg0->unk_0C += arg1;
    if (arg1 < 0) {
        if (arg2 >= arg0->unk_0C) {
            return true;
        }
    } else {
        if (arg0->unk_0C >= arg2) {
            return true;
        }
    }
    return false;
}

bool func_i6_8011B010(unk_800E3A28* arg0, s32 arg1, s32 arg2) {

    arg0->unk_10 += arg1;
    if (arg1 < 0) {
        if (arg2 >= arg0->unk_10) {
            return true;
        }
    } else {
        if (arg0->unk_10 >= arg2) {
            return true;
        }
    }
    return false;
}

extern u32 gGameFrameCount;

bool func_i6_8011B058(unk_800E3A28* arg0, s32 arg1, s32 arg2, s32 arg3) {

    if (gGameFrameCount % arg3) {
        return false;
    }

    arg0->unk_10 += arg1;
    if (arg1 < 0) {
        if (arg2 >= arg0->unk_10) {
            return true;
        }
    } else {
        if (arg0->unk_10 >= arg2) {
            return true;
        }
    }
    return false;
}

void func_i6_8011BAC0(s32 arg0, s32 arg1, s32 arg2, s8 arg3);

void func_i6_8011B0CC(unk_800E3A28* arg0) {
    s32 temp_a0;
    s32 index;
    unk_800E3A28* temp_v0_4;

    arg0->unk_1C++;
    if (arg0->unk_04 < 18) {
        switch (arg0->unk_08) {
            case 0:
                switch (arg0->unk_1C) {
                    case 0x1:
                        func_i6_8011BAC0(arg0->unk_04 + 0xC6, D_i6_8011F4BC[(arg0->unk_04 % 4) * 2 + 0],
                                         D_i6_8011F4BC[(arg0->unk_04 % 4) * 2 + 1], 0xC);
                        temp_v0_4 = func_80079E88(0xC0);
                        if ((temp_v0_4 != NULL) && (temp_v0_4->unk_08 == 3)) {
                            temp_v0_4->unk_1C++;
                        }
                        break;
                    case 0x3C:
                        func_i6_8011BAC0(arg0->unk_04 + 0xE6, D_i6_8011F4CC[(arg0->unk_04 % 4) * 2 + 0],
                                         D_i6_8011F4CC[(arg0->unk_04 % 4) * 2 + 1], 0xA);
                        arg0->unk_08 = 1;
                        break;
                }
                break;
            case 1:
                arg0->unk_1C = 0;
                break;
            case 2:
                if (arg0->unk_1C >= 0x1F) {
                    arg0->unk_04++;
                    arg0->unk_08 = 0;
                    arg0->unk_1C = 0;
                }
                break;
        }
    } else {
        switch (arg0->unk_04) {
            case 18:
                if ((arg0->unk_1C % 15) == 0) {
                    index = arg0->unk_1C / 15;
                    temp_a0 = D_i6_8011F4EC[index - 1];
                    if (temp_a0 > 0) {
                        func_i6_8011BAC0(temp_a0, 0x32, 0xF0, 0xA);
                    } else if (temp_a0 < 0) {
                        arg0->unk_04++;
                    }
                }
                break;
            case 19:
                if (func_80079E88(0x104) == NULL) {
                    arg0->unk_04++;
                }
                break;
            case 20:
                func_i6_8011BAC0(0xC1, 0xC8, 0x1E, 8);
                arg0->unk_04++;
                break;
            case 21:
                arg0->unk_00 = 0;
                break;
            default:
                break;
        }
    }
}

void func_i6_8011B340(unk_800E3A28* arg0) {
    s32 pad[2];
    s32 temp_v0;
    s32 sp28;
    s32 var_a2;
    s32 var_a1;
    s8* sp1C;
    unk_800E3A28* temp_v0_3;

    temp_v0 = arg0->unk_00 - 198;
    sp1C = gCreditsAttributions[temp_v0];

    switch (temp_v0 % 4) {
        case 0:
        case 3:
            sp28 = -1;
            break;
        case 1:
        case 2:
            sp28 = 1;
            break;
    }

    if (temp_v0 % 2) {
        var_a2 = 150;
        var_a1 = 1;
    } else {
        var_a2 = 70;
        var_a1 = -1;
    }

    switch (arg0->unk_04) {
        case 0:
            if (func_i6_8011B010(arg0, var_a1, var_a2)) {
                arg0->unk_04 = 1;
                arg0->unk_1C = 0;
            }
            break;
        case 1:
            if (++arg0->unk_1C > 120) {
                arg0->unk_04 = 2;
                temp_v0_3 = func_80079E88(0xC0);
                if ((temp_v0_3 != NULL) && (temp_v0_3->unk_08 == 1)) {
                    temp_v0_3->unk_08 = 2;
                }
            }
            break;
        case 2:
            func_8007A334(arg0, D_i6_8011F4BC[(temp_v0 % 4) * 2], sp28);
            if (sp28 < 0) {
                if (arg0->unk_0C < -func_i2_801062E4(sp1C, 1, 0)) {
                    arg0->unk_00 = 0;
                }
            } else {
                if ((func_i2_801062E4(sp1C, 1, 0) + 0x140) < arg0->unk_0C) {
                    arg0->unk_00 = 0;
                }
            }
            break;
    }
}

void func_i6_8011B50C(unk_800E3A28* arg0) {
    if (func_i6_8011B058(arg0, -1, -0x14, 2)) {
        arg0->unk_00 = 0;
    }
}

void func_i6_8011B544(unk_800E3A28* arg0) {
    s32 temp_a1;
    s32 sp18;

    temp_a1 = arg0->unk_00 - 230;

    switch (temp_a1 % 4) {
        case 0:
        case 3:
            sp18 = 1;
            break;
        case 1:
        case 2:
            sp18 = -1;
            break;
    }

    switch (arg0->unk_04) {
        case 0:
            arg0->unk_1C++;
            break;
        case 1:
            if (func_80079E88(temp_a1 + 0xC6)->unk_04 >= 2) {
                arg0->unk_04 = 2;
            }
            break;
        case 2:
            func_8007A334(arg0, D_i6_8011F4CC[(temp_a1 % 4) * 2], sp18);
            if (sp18 > 0) {
                if (arg0->unk_0C > 320) {
                    arg0->unk_00 = 0;
                }
            } else {
                if (arg0->unk_0C < 0) {
                    arg0->unk_00 = 0;
                }
            }
            break;
    }
}

void func_i6_8011B668(unk_800E3A28* arg0) {
    if (func_i6_8011B058(arg0, -1, -0x14, 2)) {
        arg0->unk_00 = 0;
    }
}

void func_i6_8011B6A0(unk_800E3A28* arg0) {

    switch (arg0->unk_04) {
        case 0:
            if (--arg0->unk_1C < 0x18) {
                arg0->unk_04++;
                arg0->unk_1C = 0;
            }
            break;
        case 1:
            if (++arg0->unk_1C >= 0x3C) {
                arg0->unk_04++;
                arg0->unk_1C = 0x17;
            }
            break;
        case 2:
            arg0->unk_1C += arg0->unk_1C / 11;
            if (arg0->unk_1C >= 0xB6) {
                arg0->unk_04++;
                arg0->unk_1C = 0;
            }
            break;
        case 3:
            if (++arg0->unk_1C >= 0x12) {
                arg0->unk_04++;
                arg0->unk_1C = 0;
                func_i6_8011BAC0(0xC2, 0x80, 0x40, 8);
                func_800BA8D8(0x2B);
            }
            break;
        case 4:
            break;
    }
}

void func_i6_8011B7B0(unk_800E3A28* arg0) {

    switch (arg0->unk_04) {
        case 0:
            if (++arg0->unk_1C >= 0xAF) {
                arg0->unk_04++;
                arg0->unk_1C = 0;
                func_i6_8011BAC0(0xC4, 0x60, 0xCD, 8);
            }
            break;
        case 1:
            if (++arg0->unk_1C >= 0x64) {
                arg0->unk_04++;
                arg0->unk_1C = 0;
            }
            break;
        case 2:
            break;
    }
}

void func_i6_8011B860(unk_800E3A28* arg0) {

    switch (++arg0->unk_18) {
        case 30:
            if (arg0->unk_04 == 0) {
                arg0->unk_04 = 1;
            }
            break;
        case 60:
            if (arg0->unk_08 == 0) {
                arg0->unk_08 = 1;
            }
            break;
        case 370:
            func_i6_8011BAC0(0xBE, 0, 0, 0);
            func_i6_8011BAC0(0xC0, 0, 0, 4);
            func_i6_8011BAC0(0xC5, 0, 0, 8);
            arg0->unk_00 = 0;
            break;
        default:
            if (arg0->unk_18 > 300) {
                if (arg0->unk_08 == 2) {
                    arg0->unk_08 = 3;
                }
                if (arg0->unk_04 == 2) {
                    arg0->unk_04 = 3;
                }
            }
            break;
    }

    switch (arg0->unk_04) {
        case 0:
            arg0->unk_1C = 256;
            break;
        case 1:
            if (arg0->unk_1C > 0) {
                arg0->unk_1C -= 4;
            }
            if (arg0->unk_1C <= 0) {
                arg0->unk_1C = 0;
                arg0->unk_04 = 2;
            }
            break;
        case 3:
            if (arg0->unk_1C < 255) {
                arg0->unk_1C += 4;
            }
            if (arg0->unk_1C >= 255) {
                arg0->unk_1C = 255;
                arg0->unk_04 = 4;
            }
            break;
        case 4:
            arg0->unk_1C = 255;
            break;
        default:
            arg0->unk_1C = 0;
            break;
    }
    switch (arg0->unk_08) {
        case 0:
            arg0->unk_20 = 256;
            break;
        case 1:
            if (arg0->unk_20 > 0) {
                arg0->unk_20 -= 4;
            }
            if (arg0->unk_20 <= 0) {
                arg0->unk_20 = 0;
                arg0->unk_08 = 2;
            }
            break;
        case 3:
            if (arg0->unk_20 < 255) {
                arg0->unk_20 += 4;
            }
            if (arg0->unk_20 >= 256) {
                arg0->unk_20 = 255;
                arg0->unk_08 = 4;
            }
            break;
        case 4:
            arg0->unk_20 = 255;
            break;
        default:
            arg0->unk_20 = 0;
            break;
    }
}

void func_i6_8011BAB8(unk_800E3A28* arg0) {
}

void func_i6_8011BAC0(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 i = 0;
    unk_800E3A28* var_s0 = D_800E3A28;

    while (true) {
        if (var_s0->unk_00 == 0) {
            break;
        }

        if (++i > 32) {
            return;
        }
        var_s0++;
    }

    var_s0->unk_00 = arg0;
    var_s0->unk_04 = 0;
    var_s0->unk_08 = 0;
    var_s0->unk_0C = arg1;
    var_s0->unk_10 = arg2;
    var_s0->unk_14 = arg3;
    var_s0->unk_15 = 1;
    var_s0->unk_1C = 0;
    var_s0->unk_20 = 0;

    switch (arg0) {
        case 0x99:
            func_i6_80117EE0(var_s0);
            break;
        case 0xC0:
            func_i6_80117F2C(var_s0);
            break;
        case 0xC1:
            func_i6_80117FA8(var_s0);
            break;
        case 0xC2:
            func_i6_80117FE0();
            break;
        case 0xC3:
            func_i6_80118008(var_s0);
            break;
        case 0xC4:
            func_i6_80118044();
            break;
        case 0xC5:
            func_i6_8011806C(var_s0);
            break;
        case 0xBE:
        case 0xBF:
        default:
            break;
    }
}

Gfx* func_i6_8011BBE4(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j++) {

            if ((D_800E3A28[j].unk_14 != i) || (D_800E3A28[j].unk_15 == 0)) {
                continue;
            }

            switch (D_800E3A28[j].unk_00) {
                case 0:
                    break;
                case 0x5:
                    gfx = func_8007AB88(gfx);
                    gfx = func_8007AE70(gfx);
                    gfx = func_8007ABA4(gfx);
                    break;
                case 0x96:
                    gfx = func_8007AC48(gfx, 0, 0, 0);
                    break;
                case 0x99:
                    gfx = func_i6_801182DC(gfx, &D_800E3A28[j]);
                    break;
                case 0xBF:
                    gfx = func_8007AC48(gfx, 0, 0, 0);
                    break;
                case 0xC0:
                    gfx = func_i6_80118354(gfx, &D_800E3A28[j]);
                    break;
                case 0xC1:
                    gfx = func_i6_80118ED4(gfx, &D_800E3A28[j]);
                    break;
                case 0xC2:
                    gfx = func_i6_8011946C(gfx, &D_800E3A28[j]);
                    break;
                case 0xC3:
                    gfx = func_i6_80119908(gfx, &D_800E3A28[j]);
                    break;
                case 0xC4:
                    gfx = func_i6_8011A248(gfx, &D_800E3A28[j]);
                    break;
                case 0xC5:
                    gfx = func_i6_8011A59C(gfx, &D_800E3A28[j]);
                    break;
                case 0xC6:
                case 0xC7:
                case 0xC8:
                case 0xC9:
                case 0xCA:
                case 0xCB:
                case 0xCC:
                case 0xCD:
                case 0xCE:
                case 0xCF:
                case 0xD0:
                case 0xD1:
                case 0xD2:
                case 0xD3:
                case 0xD4:
                case 0xD5:
                case 0xD6:
                case 0xD7:
                    gfx = func_i6_8011A6CC(gfx, &D_800E3A28[j]);
                    break;
                case 0xD8:
                case 0xD9:
                case 0xDA:
                case 0xDB:
                case 0xDC:
                case 0xDD:
                case 0xDE:
                case 0xDF:
                case 0xE0:
                case 0xE1:
                case 0xE2:
                case 0xE3:
                case 0xE4:
                    gfx = func_i6_8011A890(gfx, &D_800E3A28[j]);
                    break;
                case 0xE6:
                case 0xE7:
                case 0xE8:
                case 0xE9:
                case 0xEA:
                case 0xEB:
                case 0xEC:
                case 0xED:
                case 0xEE:
                case 0xEF:
                case 0xF0:
                case 0xF1:
                case 0xF2:
                case 0xF3:
                case 0xF4:
                case 0xF5:
                case 0xF6:
                case 0xF7:
                    gfx = func_i6_8011A944(gfx, &D_800E3A28[j]);
                    break;
                case 0xF8:
                case 0xF9:
                case 0xFA:
                case 0xFB:
                case 0xFC:
                case 0xFD:
                case 0xFE:
                case 0xFF:
                case 0x100:
                case 0x101:
                case 0x102:
                case 0x103:
                case 0x104:
                case 0x105:
                case 0x106:
                case 0x107:
                case 0x108:
                case 0x109:
                    gfx = func_i6_8011AAC8(gfx, &D_800E3A28[j]);
                    break;
            }
        }
    }
    return gfx;
}

void func_i6_8011BE1C(void) {
    s32 i;

    for (i = 0; i < 32; i++) {

        switch (D_800E3A28[i].unk_00) {
            case 0:
                break;
            case 0x99:
                func_i6_8011AB1C(&D_800E3A28[i]);
                break;
            case 0xBE:
                func_i6_8011B0CC(&D_800E3A28[i]);
                break;
            case 0xC0:
                func_i6_8011AC38(&D_800E3A28[i]);
                break;
            case 0xC5:
                func_i6_8011AEB4(&D_800E3A28[i]);
                break;
            case 0xC6:
            case 0xC7:
            case 0xC8:
            case 0xC9:
            case 0xCA:
            case 0xCB:
            case 0xCC:
            case 0xCD:
            case 0xCE:
            case 0xCF:
            case 0xD0:
            case 0xD1:
            case 0xD2:
            case 0xD3:
            case 0xD4:
            case 0xD5:
            case 0xD6:
            case 0xD7:
                func_i6_8011B340(&D_800E3A28[i]);
                break;
            case 0xD8:
            case 0xD9:
            case 0xDA:
            case 0xDB:
            case 0xDC:
            case 0xDD:
            case 0xDE:
            case 0xDF:
            case 0xE0:
            case 0xE1:
            case 0xE2:
            case 0xE3:
            case 0xE4:
                func_i6_8011B50C(&D_800E3A28[i]);
                break;
            case 0xE6:
            case 0xE7:
            case 0xE8:
            case 0xE9:
            case 0xEA:
            case 0xEB:
            case 0xEC:
            case 0xED:
            case 0xEE:
            case 0xEF:
            case 0xF0:
            case 0xF1:
            case 0xF2:
            case 0xF3:
            case 0xF4:
            case 0xF5:
            case 0xF6:
            case 0xF7:
                func_i6_8011B544(&D_800E3A28[i]);
                break;
            case 0xF8:
            case 0xF9:
            case 0xFA:
            case 0xFB:
            case 0xFC:
            case 0xFD:
            case 0xFE:
            case 0xFF:
            case 0x100:
            case 0x101:
            case 0x102:
            case 0x103:
            case 0x104:
            case 0x105:
            case 0x106:
            case 0x107:
            case 0x108:
            case 0x109:
                func_i6_8011B668(&D_800E3A28[i]);
                break;
            case 0xC1:
                func_i6_8011B6A0(&D_800E3A28[i]);
                break;
            case 0xC2:
                func_i6_8011B7B0(&D_800E3A28[i]);
                break;
            case 0xC3:
                func_i6_8011B860(&D_800E3A28[i]);
                break;
            case 0xC4:
                func_i6_8011BAB8(&D_800E3A28[i]);
                break;
        }
    }
}

extern s16 D_800CCFE8;

void func_i6_8011BF50(void) {
    D_800CCFE8 = 3;
    func_800794B0(5, 0, 0, 1);
    func_i6_8011BAC0(0xBF, 0, 0, 1);
    func_i6_8011BAC0(0xC3, 0, 0, 8);
}

extern s32 D_800DCE44;
extern Controller D_800DD180;

s32 func_i6_8011BFB0(void) {

    func_8007DABC(&D_800DD180);
    if (D_800E416C & (BTN_A | BTN_START)) {
        D_i6_8011DFA0 ^= 1;
    }
    if ((D_800DCE44 != 0x800C) && (D_800E416C & BTN_B)) {
        return 0x8007;
    } else {
        return D_800DCE44;
    }
}

Gfx* func_i6_8011C01C(Gfx* gfx) {
    func_i6_8011BE1C();
    gfx = func_i6_8011BBE4(gfx);
    func_800790D4();
    return gfx;
}

extern s16 D_800CCFE8;
extern s8 D_800CD3C4;

void func_i6_8011C404(void);

void func_i6_8011C050(void) {
    s32 i;
    OptionsInfo* option;

    D_800CCFE8 = 3;
    func_800794B0(5, 0, 0, 1);
    func_80078104(D_F25F070, 0x40, 0, 0, false);
    func_80078104(D_F138AB8, 0x2000, 0, 1, false);
    func_80078104(D_F26176C, 0x900, 0, 1, false);
    func_80078104(D_F2629A8, 0x1000, 0, 1, false);
    func_80078104(D_F262ED0, 0x200, 0, 1, false);
    func_80078104(D_F262FB4, 0x200, 0, 1, false);
    func_80078104(D_F263190, 0x200, 0, 1, false);
    func_80078104(D_F263230, 0x200, 0, 1, false);
    func_80078104(D_F2632E8, 0x400, 0, 1, false);
    func_80078104(D_F2634A4, 0x400, 0, 1, false);
    func_80078104(D_F263648, 0x100, 0, 1, false);
    func_80078104(D_F26369C, 0x100, 0, 1, false);
    func_80078104(D_F2637DC, 0x200, 0, 1, false);
    func_80078104(D_F2636F0, 0x200, 0, 1, false);

    for (i = 0, option = gOptionsInfo; i < OPTIONS_MAX; i++, option++) {
        func_80078104(option->optionTextureInfo.textureOffset,
                      option->optionTextureInfo.width * option->optionTextureInfo.height, 0, 1, 0);
    }

    func_80078104(D_F000004, 0x23A00, 0, 1, 0);
    func_8007A828(func_800783AC(D_F000004), 0x23A00, 0xC3, 0x5F, 0x5F);

    if (D_800CD3C4 == 1) {
        D_i6_801247AC = func_80078104(D_F014A68, 0x25800, 0, 1, 0);
        func_8007A828(D_i6_801247AC, 0x25800, 0xC3, 0x5F, 0x5F);
    } else if (D_800CD3C4 == 2) {
        D_i6_801247AC = func_80078104(D_F026348, 0x25800, 0, 1, 0);
        func_8007A828(D_i6_801247AC, 0x25800, 0xC3, 0x5F, 0x5F);
    }
    if (D_800CD3C4 != 0) {
        D_i6_801247A8 = 1;
        // clang-format off
        for (i = 0; i < ARRAY_COUNT(D_i6_80124620); i++) { \
            D_i6_80124620[i] = 255;
        }
        // clang-format on
    } else {
        D_i6_801247A8 = 0;
    }
    gOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_CLOSED;
    gOptionsDataAlreadyCleared = false;
    D_i6_801247B0 = 0;
    gOptionsCurrentRow = 0;
    func_i6_8011C404();
    func_80080A40(&D_i6_801247A4);
    func_80080A48();
    D_i6_8011FB10 = &D_801247C0;
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i6/E2000/func_i6_8011C404.s")

bool func_i6_8011C788(void);
void func_i6_8011CBB4(void);
void func_i6_8011D394(void);
extern s16 D_800CD048;
extern s32 D_i2_80106DA4;

s32 func_i6_8011C6DC(void) {
    func_8007DABC(&D_800DD180);
    func_80080C0C();
    func_i6_8011D394();
    if (!gOptionsDataAlreadyCleared) {
        switch (gOptionsDataClearMenu) {
            case OPTIONS_DATA_CLEAR_MENU_CLOSED:
                if (D_i2_80106DA4 == 0 && func_i6_8011C788()) {
                    gOptionsDataAlreadyCleared = true;
                    D_800CD048 = 0xE;
                }
                break;
            case OPTIONS_DATA_CLEAR_MENU_OPEN:
                func_i6_8011CBB4();
                break;
        }
    }
    return 0x8014;
}

extern s16 D_800CE4D0;
extern s16 D_800CE4D4;
extern u16 D_800E416E;
extern s32 D_80106F40;
extern s16 D_80111840;
Gfx* func_i6_8011D168(Gfx*, s32, s32);

bool func_i6_8011C788(void) {
    s32 lastRow;
    s32 temp_t0;
    bool updateSettings;
    OptionsInfo* temp_a3_2;

    if (func_8008108C(D_i6_801247A4, 0)) {
        return false;
    }
    lastRow = gOptionsCurrentRow;
    if (D_800E416C & BTN_UP) {
        if (--gOptionsCurrentRow < OPTIONS_VS_COM) {
            gOptionsCurrentRow = OPTIONS_EXIT;
        }
        while (!(gOptionsInfo[gOptionsCurrentRow].flags & OPTIONS_SHOWN)) {
            if (--gOptionsCurrentRow < OPTIONS_VS_COM) {
                gOptionsCurrentRow = OPTIONS_EXIT;
            }
        }
    }
    if (D_800E416C & BTN_DOWN) {
        if (++gOptionsCurrentRow > OPTIONS_EXIT) {
            gOptionsCurrentRow = OPTIONS_VS_COM;
        }
        while (!(gOptionsInfo[gOptionsCurrentRow].flags & OPTIONS_SHOWN)) {
            if (++gOptionsCurrentRow > OPTIONS_EXIT) {
                gOptionsCurrentRow = OPTIONS_VS_COM;
            }
        }
    }
    if (lastRow != gOptionsCurrentRow) {
        func_800BA8D8(0x1E);
        return false;
    }
    temp_a3_2 = &gOptionsInfo[gOptionsCurrentRow];
    updateSettings = false;
    if (!(temp_a3_2->flags & OPTIONS_REQUIRE_SELECTING)) {
        temp_t0 = gOptionsSelectionState[gOptionsCurrentRow];
        if (D_800E416E & BTN_LEFT) {
            gOptionsSelectionState[gOptionsCurrentRow]--;
            if (gOptionsSelectionState[gOptionsCurrentRow] < 0) {
                gOptionsSelectionState[gOptionsCurrentRow] = temp_a3_2->totalSelectionStates - 1;
            }
        }
        if (D_800E416E & BTN_RIGHT) {
            gOptionsSelectionState[gOptionsCurrentRow]++;
            if (gOptionsSelectionState[gOptionsCurrentRow] > temp_a3_2->totalSelectionStates - 1) {
                gOptionsSelectionState[gOptionsCurrentRow] = 0;
            }
        }
        if (temp_t0 != gOptionsSelectionState[gOptionsCurrentRow]) {
            updateSettings = true;
            func_800BA8D8(0x21);
        }
    }
    if (D_800E416E & BTN_B) {
        func_800BA8D8(0x10);
        return true;
    }

    switch (temp_a3_2->row) {
        case OPTIONS_VS_COM:
            if (updateSettings) {
                if (gOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    D_800CE4D4 = 0;
                } else {
                    D_800CE4D4 = 1;
                }
            }
            break;
        case OPTIONS_VS_SLOT:
            if (updateSettings) {
                if (gOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    D_80106F40 = 0;
                } else {
                    D_80106F40 = 1;
                }
            }
            break;
        case OPTIONS_VS_HANDICAP:
            if (updateSettings) {
                if (gOptionsSelectionState[gOptionsCurrentRow] == 0) {
                    D_800CE4D0 = 0;
                } else if (gOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    D_800CE4D0 = 1;
                } else {
                    D_800CE4D0 = 2;
                }
            }
            break;
        case OPTIONS_SOUND_MODE:
            if (updateSettings) {
                if (gOptionsSelectionState[gOptionsCurrentRow] == 0) {
                    D_80111840 = 0;
                    func_800BA28C(SOUNDMODE_SURROUND); // Option says stereo, but sets surround anyway?
                } else {
                    D_80111840 = 1;
                    func_800BA28C(SOUNDMODE_MONO);
                }
            }
            break;
        case OPTIONS_DATA_CLEAR:
            if (D_800E416E & (BTN_A | BTN_START)) {
                D_i6_801247A4 =
                    func_80080AA8(0, 0x5A, 0x8C, 0x94, 0x50, GPACK_RGBA5551(255, 0, 0, 1), func_i6_8011D168);
                if (D_i6_801247A4 != NULL) {
                    gOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_OPEN;
                    gOptionsSelectionState[gOptionsCurrentRow] = 0;
                    func_800BA8D8(0x21);
                }
            }
            break;
        case OPTIONS_EXIT:
            if (D_800E416E & (BTN_A | BTN_START)) {
                func_800BA8D8(0x10);
                return true;
            }
            break;
        default:
            break;
    }

    if (updateSettings) {
        func_i2_80101414();
    }
    return false;
}

extern s32 D_800E5F00[];
extern s32 D_800E5F10[];

void func_i6_8011CBB4(void) {
    s32 lastSelectionState;
    s32 pad;
    s32 i;
    bool updateSettings;

    if (func_8008108C(D_i6_801247A4, 1) != 0) {
        lastSelectionState = gOptionsSelectionState[gOptionsCurrentRow];
        if (D_800E416E & BTN_LEFT) {
            if (--gOptionsSelectionState[gOptionsCurrentRow] < 0) {
                gOptionsSelectionState[gOptionsCurrentRow] = 1;
            }
        }
        if (D_800E416E & BTN_RIGHT) {
            if (++gOptionsSelectionState[gOptionsCurrentRow] > 1) {
                gOptionsSelectionState[gOptionsCurrentRow] = 0;
            }
        }
        if (lastSelectionState != gOptionsSelectionState[gOptionsCurrentRow]) {
            func_800BA8D8(0x1E);
        }
        updateSettings = false;
        if (D_800E416E & (BTN_A | BTN_START)) {
            updateSettings = true;
            if (gOptionsSelectionState[gOptionsCurrentRow] == 1) {
                func_i2_80101784(D_i6_8011FB10, 1);
                func_i6_8011C404();
                for (i = 0; i < 4; i++) {
                    D_800E5F00[i] = D_800E5F10[i] = 0;
                }
                func_8007E398();
                func_800BA8D8(5);
            } else {
                func_800BA8D8(0x10);
            }
        } else if (D_800E416E & BTN_B) {
            updateSettings = true;
            func_800BA8D8(0x10);
        }
        if (updateSettings) {
            gOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_CLOSED;
            func_80080BDC(D_i6_801247A4);
        }
    }
}

Gfx* func_i6_8011D8C8(Gfx*);

Gfx* Menu_OptionsDraw(Gfx* gfx) {
    s32 temp_s4;
    s32 var_s5;
    s32 i;
    s32 var_s7;
    OptionsInfo* option;
    OptionsTextureInfo* selectionStateTextureInfo;
    OptionsTextureInfo* optionTextureInfo;

    gfx = func_80079BC8(gfx);
    if (D_i6_801247A8 != 1) {
        gfx = func_8007B14C(gfx, func_800783AC(D_F000004), 8, 0, 0x130, 0xF0, 0, 2, 0, 0, 0, 0);
    }
    if (D_i6_801247A8 != 0) {
        gfx = func_i6_8011D8C8(gfx);
    }
    gfx = func_8007B14C(gfx, func_800783AC(D_F138AB8), 0x32, 4, 0x40, 0x40, 0, 2, 0, 0, 1, 0);
    gfx = func_8007B14C(gfx, func_800783AC(D_F138AB8), 0xCE, 4, 0x40, 0x40, 0, 2, 0, 0, 0, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_8007E410(gfx, func_800783AC(D_F26176C), func_800783AC(D_F25F070), 2, 1, 0x70, 0x16, 0x60, 0x18, 3);

    var_s5 = 60;

    if (D_i6_801247B0 != 0) {
        var_s7 = 0x17;
    } else {
        var_s7 = 0x1B;
    }

    for (i = 0, option = gOptionsInfo; i < 7; i++, option++) {
        if (!(option->flags & OPTIONS_SHOWN)) {
            continue;
        }

        gDPPipeSync(gfx++);
        if (gOptionsCurrentRow != i) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gfx = func_8007DB28(gfx, 0);
        }
        optionTextureInfo = &option->optionTextureInfo;
        gfx = func_8007E410(gfx, func_800783AC(optionTextureInfo->textureOffset), NULL, 2, 1, option->unk_0C + 0x1E,
                            var_s5, optionTextureInfo->width, optionTextureInfo->height, 0);

        if (!(option->flags & OPTIONS_REQUIRE_SELECTING)) {
            gfx = func_8007E410(gfx, func_800783AC(D_F263648), NULL, 2, 1, 0xBE, var_s5, 0x10, 0x10, 0);
            gfx = func_8007E410(gfx, func_800783AC(D_F26369C), NULL, 2, 1, 0x109, var_s5, 0x10, 0x10, 0);
            selectionStateTextureInfo = &option->selectionStateTextureInfo[gOptionsSelectionState[i]];
            temp_s4 = ((60 - selectionStateTextureInfo->width) / 2) + option->unk_10;
            gfx =
                func_8007E410(gfx, func_800783AC(selectionStateTextureInfo->textureOffset), NULL, 2, 1, temp_s4 + 0xD0,
                              var_s5, selectionStateTextureInfo->width, selectionStateTextureInfo->height, 0);
        }
        var_s5 += var_s7;
    }

    return func_80080E90(gfx);
}

Gfx* func_i6_8011D168(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 sp54;
    OptionsTextureInfo* dataClearTextureInfo;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    gfx = func_8007E410(gfx, func_800783AC(D_F2629A8), func_800783AC(D_F25F070), 2, 1, arg1 + 0xC, arg2 + 0xA, 0x80,
                        0x20, 3);

    gDPPipeSync(gfx++);
    gfx = func_8007DB28(gfx, 0);
    gfx = func_8007E410(gfx, func_800783AC(D_F263648), NULL, 2, 1, arg1 + 0x18, arg2 + 0x32, 0x10, 0x10, 0);
    gfx = func_8007E410(gfx, func_800783AC(D_F26369C), NULL, 2, 1, arg1 + 0x63, arg2 + 0x32, 0x10, 0x10, 0);
    dataClearTextureInfo = &gOptionsAllDataClearSelection[gOptionsSelectionState[gOptionsCurrentRow]];
    sp54 = (60 - dataClearTextureInfo->width) / 2;
    return func_8007E410(gfx, func_800783AC(dataClearTextureInfo->textureOffset), NULL, 2, 1, arg1 + sp54 + 0x2A,
                         arg2 + 0x32, dataClearTextureInfo->width, dataClearTextureInfo->height, 0);
}

#pragma GLOBAL_ASM("asm/us/rev0/nonmatchings/overlays/ovl_i6/E2000/func_i6_8011D394.s")

extern GfxPool D_1000000;
extern Mtx D_2000000[];
extern Gfx D_8014810[];

Gfx* func_i6_8011D8C8(Gfx* gfx) {
    s32 pad[27];
    s32 sp40;
    s32 lrt;
    s32 uls;
    s32 lrs;
    s32 ult;
    s32 var_s3;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t5;

    if ((D_i6_801247A8 == 1) || (D_i6_801247A8 == 2)) {
        gfx = func_8006A00C(gfx, 0);
        gSPDisplayList(gfx++, D_8014810);
        gDPSetTextureFilter(gfx++, G_TF_POINT);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_DECALRGB, G_CC_DECALRGB);
        gSPMatrix(gfx++, D_1000000.unk_2B248, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        for (sp40 = 0, var_s5 = 0x10, var_s4 = -1; var_s4 < SCREEN_HEIGHT - 1; var_s4 += 16, sp40 += 10, var_s5 += 16) {

            var_s3 = sp40 << 2;

            for (var_s2 = 32, var_t5 = -1; var_t5 < SCREEN_WIDTH - 1; var_t5 += 32, var_s3 += 4, var_s2 += 32) {
                uls = MAX(var_t5, 0);
                lrs = MIN(var_s2, SCREEN_WIDTH - 1);
                ult = MAX(var_s4, 0);
                lrt = MIN(var_s5, SCREEN_HEIGHT - 1);

                gSPVertex(gfx++, (u8*) D_i6_80124618 + (var_s3 << 4), 4, 0);
                gDPPipeSync(gfx++);
                gDPLoadTextureTile(gfx++, D_i6_801247AC, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                   SCREEN_HEIGHT /* unused by macro */, uls, ult, lrs, lrt, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);
                gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
            }
        }
    }
    return gfx;
}
