//
// Created by 박재영 on 2017. 5. 14..
//

#include "IterativeDeepening.h"

#include "../../test/Samples.h"
#include "../../consts/CONFIG.h"
#include "domain/Node.h"
#include "../../consts/GAME_BOARD.h"
#include "../policy/NextStonePairs.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/LogUtils.h"
#include "Minimax.h"
#include "../../consts/SCORE.h"
#include "NodeExtend.h"


void iterativeDeepeningSearch(vector<vector<int>> board, int stoneType, int cnt, int x[], int y[]) {
    printBoard(board);

    if(cnt == 1) {
        *x = { 5 };
        *y = { 5 };
        return;
    }

    int targetDepth = ITERATIVE_DEEPENING_SEARCH::INITIAL_DEPTH;
    Node* rootPtr = getOrCreateRoot(board, stoneType);

    while(true) {
        loginfo("IterativeDeepening","iterativeDeepeningSearch","depth=",targetDepth);

        NodeExtend(rootPtr, targetDepth);

        Node* bestNode = miniMaxWithAlphaBeta(rootPtr, 0,
                                              -INF, INF, true,
                                              targetDepth);

        vector<vector<int>> stonePair = bestNode->getStones();
//        x[0] = 7;
//        x[1] = 9;
//        y[0] = 1;
//        y[1] = 3;
        x[0] = stonePair[0][X];
        x[1] = stonePair[1][X];
        y[0] = stonePair[0][Y];
        y[1] = stonePair[1][Y];

        vector<vector<int>> bestBoard = bestNode->getDiffBoard();
        loginfo("IterativeDeepening","bestBoard below");
        printBoard(bestBoard);
        targetDepth++;
        if(targetDepth > ITERATIVE_DEEPENING_SEARCH::MAXIMUM_DEPTH) {
            break;
        }
    }
}