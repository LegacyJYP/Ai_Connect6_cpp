//
// Created by 박재영 on 2017. 5. 14..
//

#include "NodeExtend.h"
#include "../../test/utils/LogUtils.h"
#include "../policy/NextStonePairs.h"
#include "../../test/utils/PrintUtils.h"
#include "../../consts/SCORE.h"
#include "../../consts/GAME_BOARD.h"


void NodeExtend(Node* node, int targetDepth) {
    bool printFlag = false;

    if (!node->isExtended()) { // todo Extend More
        if(node->getEvaluation() > GAMEEND/2) {
            // nope
            loginfo("NodeExtend","vector<vector<vector<int>>>","eval > GAMEEND/2 -> size=0으로 확장", printFlag);
            node->extend(vector<vector<vector<int>>>(0));
            return;
        }

        vector<vector<vector<int>>> nextStonePairs = nextStonePairsByPolicy(node->getBoard(), ENEMY_STONE(node->getStoneType()));
        loginfo("NodeExtend", "NodeExtend", "extend",printFlag);
        loginfo("NodeExtend", "NodeExtend", "stonePairList below",printFlag);
        printStonePairList(nextStonePairs, printFlag);
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