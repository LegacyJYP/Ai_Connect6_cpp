//
// Created by 박재영 on 2017. 5. 14..
//

#include "NodeExtend.h"
#include "../../test/utils/LogUtils.h"
#include "../policy/NextStonePairs.h"
#include "../../test/utils/PrintUtils.h"


void NodeExtend(Node* node, int targetDepth) {
    if (!node->isExtended()) { // todo Extend More
        vector<vector<vector<int>>> nextStonePairs = nextStonePairsByPolicy(node->getBoard(), node->getStoneType());
//        loginfo("IterativeDeepening", "iterativeDeepeningSearch", "extend");
//        loginfo("IterativeDeepening", "iterativeDeepeningSearch", "stonePairList below");
//        printStonePairList(nextStonePairs);
        node->extend(nextStonePairs);

//        loginfo("IterativeDeepening", "iterativeDeepeningSearch", "added children below");
//        for (auto child : node->getChildren()) {
//            vector<vector<int>> diffBoard = child->getDiffBoard();
//            printBoard(diffBoard);
//        }
    }

    if (targetDepth > 1) {
        for (auto child : node->getChildren()) {
            NodeExtend(child, targetDepth - 1);
        }
    }
}