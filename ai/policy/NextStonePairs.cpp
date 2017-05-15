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

    list<vector<int>> effectiveList = effectiveRange(board); // 왜 중복이 많이 뜨지? -> 해결
    loginfo("NextStonePairs","nextStonePairsByPolicy", "effectiveList=below", false);
//    printStonePointList(effectiveList);
    loginfo("NextStonePairs","nextStonePairsByPolicy", "effectiveList visualBoard", false);
    vector<vector<int>> visualBoard;
//    visualBoard = putStonePointsForVisualize(board, effectiveList, stoneType);
//    printBoard(visualBoard);

    vector<vector<int>> filteredStoneList = filterByHeuristic(board, effectiveList, stoneType);
    loginfo("NextStonePairs","nextStonePairsByPolicy", "filteredStoneList=below", false);
//    printStonePointList(filteredStoneList);
    loginfo("NextStonePairs","nextStonePairsByPolicy", "filteredStoneList visualBoard", false);
//    visualBoard = putStonePointsForVisualize(board, filteredStoneList, stoneType);
//    printBoard(visualBoard);

    vector<vector<vector<int>>> filteredStonePairs = stonePoints2stonePairs(filteredStoneList);

    loginfo("NextStonePairs","filteredStonePairs","filteredStonePairs.size()=",filteredStonePairs.size());
//    for (auto stonePair: filteredStonePairs) {
//        loginfo("NextStonePairs","nextStonePairsByPolicy","policy result");
//        loginfo("NextStonePairs", "stonepairSize", stonePair.size());
//        vector<vector<int>> sboard = putStonePointsForVisualize(board, stonePair, stoneType);
//        printBoard(sboard);
//    }


    return filteredStonePairs;
}