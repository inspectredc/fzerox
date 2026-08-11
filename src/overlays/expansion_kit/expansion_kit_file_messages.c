#include "global.h"

#include ASSET_SOURCE_EK(overlays/expansion_kit/dd_fault/dd_fault.c)

// Saving...
// Loading...
// Cannot execute while accessing file
// The name is being changed
// Deleting file
// The file does not exist
// Applying write protection
// Write protection is being removed
// The file is write protected
// Copying...
// Registration currently in progress
// Cleared file
// Saving options
// No entries found

char* gFileMessageStrs[] = {
    "セーブ中です。",
    "ロード中です。",
    "アクセス中は実行できません。",
    "名前を変更中です。",
    "ファイルを削除中です。",
    "ファイルがありません。",
    "プロテクトをかけています。",
    "プロテクトを解除しています。",
    "プロテクトがかかっています。",
    "コピー中です。",
    "エントリー中です。",
    "クリアしています。",
    "オプションセーブ中です。",
    "エントリーがありません。",
};

// (Characters as they appear above)
char gFileMessageChars[] = "ロド実行名変更ファイル削除テけ解ピオショ";
