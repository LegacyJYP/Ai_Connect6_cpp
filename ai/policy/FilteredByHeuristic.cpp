//
// Created by 박재영 on 2017. 5. 13..
//

#include "FilteredByHeuristic.h"
#include "../utils/BoardUtils.h"
#include "../../test/utils/LogUtils.h"
#include "../../test/utils/PrintUtils.h"
#include "Sort.h"
#include "../utils/VectorUtils.h"
#include "../../consts/GAME_BOARD.h"
#include "../heuristic/Evaluation.h"
#include <algorithm>

vector<vector<int>> filterByHeuristic(vector<vector<int>> board, list<vector<int>> effectiveList, int stoneType) {
    vector<double> evalList;

    for (auto stonePoint : effectiveList) {

        vector<vector<int>> afterBoard = putStonePoint(board,stonePoint,stoneType);

        double eval = evaluation(afterBoard, stoneType);
        evalList.push_back(eval); // todo 메모리 leak 확인

        bool printFlag = false;
        loginfo("",printFlag );
        loginfo("FilteredByHeuristic","filterByHeuristic","eval=",eval,printFlag );
//        printStonePoint(stonePoint);
        loginfo("FilteredByHeuristic","filterByHeuristic","eval=",eval,printFlag );
        loginfo("FilteredByHeuristic","afterBoard","putStone",printFlag );
//        printBoard(afterBoard);
        loginfo("",printFlag );
    }

    vector<int> sortedIdx = sortAndReturnIdx(evalList); // todo 상위 구하고 정렬 멈추기

    int numIdx = sortedIdx.size();
    int filteredNum = min((int)(numIdx * FILTERED_BY_HEURISTIC::THRESHOLD_PERSENTAGE),
                          FILTERED_BY_HEURISTIC::THRESHOLD_NUMBER);
//    loginfo("FilteredByHeuristic","sortAndReturnIdx ","filteredNum=",filteredNum);

    vector<vector<int>> filteredList = vector<vector<int>>(filteredNum);

//    loginfo("FilteredByHeuristic","sortAndReturnIdx","list2vec before");
//    printStonePointList(effectiveList);
    vector<vector<int>> effectiveListVec = list2vec(effectiveList); // list2vec 이놈이문제였음 복사재대로 안함 -> 해결
//    loginfo("FilteredByHeuristic","sortAndReturnIdx","list2vec after");
//    printStonePointList(effectiveListVec);
    for(int i=0; i<filteredNum; i++) { // 한번도 안돌음 -> 해결
//        loginfo("FilteredByHeuristic","filterByHeuristic","before filteredList = effectiveList[sortedidx]");
//        loginfo("FilteredByHeuristic","filterByHeuristic","i=",i);
//        loginfo("FilteredByHeuristic","filterByHeuristic","sortedIdx[i]=",sortedIdx[i]);
//        loginfo("FilteredByHeuristic","filterByHeuristic","effectiveListVec.at(sortedIdx[X])=",effectiveListVec.at(sortedIdx[i])[X]);
//        loginfo("FilteredByHeuristic","filterByHeuristic","effectiveListVec.at(sortedIdx[Y])=",effectiveListVec.at(sortedIdx[i])[Y]);
        filteredList[i] = effectiveListVec.at(sortedIdx[i]);
//        loginfo("FilteredByHeuristic","filterByHeuristic","after filteredList = effectiveList[sortedidx]");
//        loginfo("FilteredByHeuristic","filterByHeuristic","filteredList[i][X]",filteredList[i][X]);
//        loginfo("FilteredByHeuristic","filterByHeuristic","filteredList[i][Y]",filteredList[i][Y]);
    }

//    printStonePointList(filteredList);

    return filteredList;
}