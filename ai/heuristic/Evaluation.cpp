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
//    functionCallStack(AI::HEURISTIC::EVALUATION_evaluation);
//    cout << "evaluation_count=" << evaluation_count << '\n';
    functionCallStack(AI::HEURISTIC::EVALUATION_evaluation_key);
    functionTic(AI::HEURISTIC::EVALUATION_evaluation_key);
//    log("evaluation ", AI::HEURISTIC::EVALUATION_evaluation_key);

    double evaluation = 0;

    if (board[0][0] == BLACK_STONE) {
        evaluation = 1;
    }

    if (stoneType == BLACK_STONE)
    {
        functionToc(AI::HEURISTIC::EVALUATION_evaluation_key);
        return evaluation;
    }
    else
    {
        functionToc(AI::HEURISTIC::EVALUATION_evaluation_key);
        return -evaluation;
    }
}