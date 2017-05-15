//
// Created by 박재영 on 2017. 5. 14..
//

#include "Evaluation.h"
#include "onefile/Evaluation_ONEFILE.h"
#include "../../consts/GAME_BOARD.h"
#include "../../consts/SCORE.h"
#include "RuleChk.h"
#include "../../test/utils/LogUtils.h"


double evaluation(std::vector<std::vector<int>> &board, int stoneType) {
    bool printFlag = true;
    int winner = isGameEnd(board, NOT_MY_STONE);
    double eval;

    // wincheck
    if(winner == MY_STONE) {
        eval = GAMEEND;
        loginfo("Evaluation","evaluation","eval=",eval,printFlag);
    } else if (winner == NOT_MY_STONE) {
        eval = -GAMEEND;
        loginfo("Evaluation","evaluation","eval=",eval,printFlag);
    } else {
        eval = evaluation_onefile(board, stoneType);
    }


    return eval;
}