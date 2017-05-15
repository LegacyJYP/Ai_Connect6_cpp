//
// Created by 박재영 on 2017. 5. 14..
//

#include "Evaluation.h"
#include "onefile/Evaluation_ONEFILE.h"
#include "../../consts/GAME_BOARD.h"
#include "../../consts/SCORE.h"
#include "RuleChk.h"


double evaluation(std::vector<std::vector<int>> &board, int stoneType) {
    int winner = isGameEnd(board, NOT_MY_STONE);
    if(winner == MY_STONE) {
        return GAMEEND;
    } else if (winner == NOT_MY_STONE) {
        return -GAMEEND;
    }

    return evaluation_onefile(board, stoneType);
}