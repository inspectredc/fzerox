#include "global.h"

// Please select a file
// Load file?
// Do you want to save?
// Do you want to delete the file?
// You cannot save because a file with the same name already exists
// You cannot change the name because a file with the same name already exists
// You can't save any more files. Please delete any unnecessary files
// There is an error and you cannot save
// The file is write protected
// The course is not available
// The file is corrupted
// The starting point has been changed
// If you copy to another disk******
// Please swap the discs
// OK
// Please select the files you want to copy
// Please enter a new file name
// This location cannot be changed by the system
// You want to clear the course data, are you sure?
// The dots are too close together to place
// The dash mark will be removed instead
// You can return to the previous state with the button
// You can access the help section using the icon in the bottom right corner
// You want to cancel your entry, are you sure?
// First, set the points and create the course
// Press the A button to set a point. To change the section you are setting, move the cursor to the desired section and
// press the Z trigger Select points with the Z trigger. You can select multiple points by holding down the Z trigger
// and drawing a circle around them Press the A button to change the road type. To change the section of road you want
// to modify, move the cursor to the section you want to modify and press the Z trigger Press the A button to set the
// mechanism. To change the setting range, move the cursor to the desired range and press the Z trigger The course is
// too long, so it cannot be moved You want to completely re-initialize the disk, are you sure?

// clang-format off
char* gCourseEditMessageStrs[] = {
    "ファイルを選んで下さい",
    "をロードしますか？",
    "にセーブしますか？",
    "を消しますか？",
    "同じ名前のファイルがあるので、\nセーブできません",
    "同じ名前のファイルがあるので、\n変更できません",
    "これ以上セーブできません\nいらないファイルを消して下さい",
    "エラーがあるのでセーブできません",
    "プロテクトがかかっています",
    "コースができていません",
    "ファイルが壊れています",
    "スタート地点を変更しました",
    "別のディスクにコピーする場合は",
    "ディスクを入れ替えて下さい",
    "ＯＫ",
    "コピーするファイルを選んで下さい",
    "新しいファイル名を入力して下さい",
    "この場所はシステム上変更できません",
    "コースデータをクリアします\nよろしいですか？",
    "点の間隔が狭くて置けません",
    "ダッシュマークが代りになくなります",
    "ボタンでひとつ前の状態に戻れます",
    "右下の　アイコンで\nヘルプを表\\示できます",
    "エントリーを解除します\nよろしいですか？",
    "最初はポイントをセットして，\nコースを作成して下さい",
    "Ａボタンでポイントをセットします\nセットする区間を変更する時は\nセットする区間にカーソ\\ルを合わせて\nＺトリガーです",
    "Ｚトリガーでポイントを選択します\nＺトリガーを押しながら複数の\nポイントを囲むと，複数のポイントを\n選択できます",
    "Ａボタンで道路のタイプを変えます\nタイプを変える区間を変更する時は\n変更したい区間にカーソ\\ルを合わせて\nＺトリガーです",
    "Ａボタンでしかけをセットします\nセットする区間を変更する時は\nセットする区間にカーソ\\ルを合わせて\nＺトリガーです",
    "コースが長すぎるので移動できません",
    "ディスクを完全に初期化します\nよろしいですか？",
};

// The placement of the points is unreasonable
// The course is too long
// The placement of the parts is incorrect
// The roads overlap
// It's too narrow to place the joint parts
// No more can be placed here
// The points on the curve are too close together
// There are too many dirt sections
// The course is too low
// The course extends out of bounds
// Display processing has reached its limit
// The course is too short

char* gCourseRestrictionMessageStrs[] = {
    "点の配置に無理があります",
    "コースが長すぎます",
    "パーツの配置がおかしいです",
    "道が重なっています",
    "ジョイントパーツを置くには狭いです",
    "これ以上おけません",
    "カーブにおける点の間隔が狭いです",
    "ダート等の置きすぎです",
    "コースが低すぎます",
    "コースがはみだしています",
    "表\\示処理が限界です",
    "コースが短かすぎます",
};
// clang-format on
