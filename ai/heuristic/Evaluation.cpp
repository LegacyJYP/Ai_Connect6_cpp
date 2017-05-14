//
// Created by 박재영 on 2017. 5. 14..
//

#include "Evaluation.h"
#include "onefile/Evaluation_ONEFILE.h"


double evaluation(std::vector<std::vector<int>> &board, int stoneType) {
    return evaluation_onefile(board, stoneType);
}