//
// Created by 박재영 on 2017. 5. 13..
//

#include "NextStonePairs.h"
#include "EffectiveRange.h"
#include "../../test/utils/PrintUtils.h"
#include "../utils/BoardUtils.h"
#include "FilteredByHeuristic.h"
#include "../utils/StoneUtils.h"
#include "../../test/utils/LogUtils.h"


vector<vector<vector<int>>> nextStonePairsByPolicy(vector<vector<int>> board, int stoneType) {

    vector<vector<vector<int>>> nextStonePairs;

    list<vector<int>> effectiveList = effectiveRange(board); // 왜 중복이 많이 뜨지? -> 해결
//    printStonePointList(effectiveList);

    vector<vector<int>> filteredStoneList = filterByHeuristic(board, effectiveList, stoneType);
    loginfo("NextStonePairs","nextStonePairsByPolicy", "filteredStoneList : below");
    printStonePointList(filteredStoneList);
    vector<vector<vector<int>>> filteredStonePairs = stonePoints2stonePairs(filteredStoneList);
//    printStonePairList(filteredStonePairs);


    return nextStonePairs;
}