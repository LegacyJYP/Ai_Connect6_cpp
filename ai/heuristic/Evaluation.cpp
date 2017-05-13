//
// Created by 박재영 on 2017. 5. 13..
//

#include <iostream>
#include "Evaluation.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/LOG_BY_EACHFUNCTION.h"
#include "../../consts/GAME_BOARD.h"
#include "../../test/utils/FunctionCostUtils.h"


double evaluation(std::vector<std::vector<int>> &board, int stoneType) {
    functionCallStack(AI::HEURISTIC::EVALUATION_evaluation_key);
    functionTic(AI::HEURISTIC::EVALUATION_evaluation_key);

    double evaluation = 0;

    if (board[0][0] == BLACK_STONE) {
        evaluation = 90;
    }

    if (board[1][0] == BLACK_STONE) {
        evaluation = 9;
    }

    if (board[0][1] == BLACK_STONE) {
        evaluation = 900;
    }

    if (stoneType == WHITE_STONE)
    {
        return -evaluation;
    }

    functionToc(AI::HEURISTIC::EVALUATION_evaluation_key);
    return evaluation;
}