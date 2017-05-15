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
#include "../../Connect6Algo.h"
#include <time.h>


void iterativeDeepeningSearch(vector<vector<int>> board, int stoneType, int cnt, int x[], int y[]) {
    bool printFlag = false;

    loginfo("",printFlag);
    loginfo("IterativeDeepening","iterativeDeepeningSearch","cnt=",cnt,printFlag);
    loginfo("IterativeDeepening","iterativeDeepeningSearch","input board below",printFlag);
    printBoard(board,printFlag);

    if(cnt == 1) {
        srand((unsigned)time(NULL));

        for (int i = 0; i < cnt; i++) {
            while(true) {
                x[i] = rand() % (BOARD_SIZE-RANDOM_CENTER);
                x[i] += RANDOM_CENTER/2;
                y[i] = rand() % (BOARD_SIZE-RANDOM_CENTER);
                y[i] += RANDOM_CENTER/2;

                if(board[x[i]][y[i]] == NONE_STONE ) {
                    break;
                }
            }

            if (x[1] == x[0] && y[1] == y[0]) i--;
        }
        return;
    }

    int targetDepth = ITERATIVE_DEEPENING_SEARCH::INITIAL_DEPTH;
    Node* rootPtr = getOrCreateRoot(board, stoneType);

    while(true) {
        loginfo("IterativeDeepening","iterativeDeepeningSearch","depth=",targetDepth,printFlag);

        NodeExtend(rootPtr, targetDepth);

        Node* bestNode = miniMaxWithAlphaBeta(rootPtr, 0,
                                              -INF, INF, true,
                                              targetDepth);

        vector<vector<int>> stonePair = bestNode->getStones();
        x[0] = stonePair[0][X];y[0] = stonePair[0][Y];
        x[1] = stonePair[1][X];y[1] = stonePair[1][Y];

        vector<vector<int>> bestBoard = bestNode->getDiffBoard();
        vector<vector<int>> stones = bestNode->getStones();
        loginfo("IterativeDeepening","bestBoard stones", printFlag);
        printStonePair(stones,printFlag);
        loginfo("IterativeDeepening","bestBoard below", printFlag);
        printBoard(bestBoard,printFlag);
        targetDepth++;
        if(targetDepth > ITERATIVE_DEEPENING_SEARCH::MAXIMUM_DEPTH) {
            break;
        }
    }
}