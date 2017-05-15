//
// Created by 박재영 on 2017. 5. 15..
//

#include "GameEndTest.h"
#include "../Samples.h"
#include "../../ai/heuristic/RuleChk.h"
#include "LogUtils.h"
#include "../../consts/GAME_BOARD.h"

void isGameEndTest()
{
    int endFlag;
    vector<vector<int>> board;
    int stoneType = MY_STONE;

    board= getSample(6);
    endFlag = isGameEnd(board, stoneType);
    loginfo("main()", "isGamdEnd? ", endFlag, true);

    board= getSample(7);
    endFlag = isGameEnd(board, stoneType);
    loginfo("main()", "isGamdEnd? ", endFlag, true);
}