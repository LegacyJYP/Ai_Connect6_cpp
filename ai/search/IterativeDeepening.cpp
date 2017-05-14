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


void iterativeDeepeningSearch(vector<vector<int>> board, int stoneType) {
    printBoard(board);
    int targetDepth = ITERATIVE_DEEPENING_SEARCH::INITIAL_DEPTH;
    Node* rootPtr = getOrCreateRoot(board, stoneType);

    while(true) {
        loginfo("IterativeDeepening","iterativeDeepeningSearch","depth=",targetDepth);

        NodeExtend(rootPtr, targetDepth);

        Node* bestNode = miniMaxWithAlphaBeta(rootPtr, 0,
                                              -INF, INF, true,
                                              targetDepth);

        vector<vector<int>> bestBoard = bestNode->getDiffBoard();
        loginfo("IterativeDeepening","bestBoard below");
        printBoard(bestBoard);
        targetDepth++;
        if(targetDepth > ITERATIVE_DEEPENING_SEARCH::MAXIMUM_DEPTH) {
            break;
        }
    }
}