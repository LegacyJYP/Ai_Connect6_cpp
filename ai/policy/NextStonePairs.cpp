//
// Created by 박재영 on 2017. 5. 13..
//

#include "NextStonePairs.h"
#include "EffectiveRange.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/BoardUtils.h"


list<vector<vector<int>>> nextStonePairsByPolicy(vector<vector<int>> board, int stoneType) {

    list<vector<vector<int>>> nextStonePairs;

    list<vector<int>> effectiveList = effectiveRange(board);
    printStonePointList(effectiveList);
//    putStonePoints()

    return nextStonePairs;
}