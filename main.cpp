#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "test/Samples.h"
#include "test/utils/PrintUtils.h"
#include "consts/GAME_BOARD.h"
#include "test/utils/TimeUtils.h"
#include "test/utils/LOG_BY_EACHFUNCTION.h"
#include "test/utils/FunctionCostUtils.h"
#include "test/utils/LogUtils.h"
#include "ai/policy/EffectiveRange.h"
#include "ai/policy/NextStonePairs.h"
#include "ai/search/domain/Node.h"
#include "consts/CONFIG.h"
#include "ai/search/Minimax.h"
#include "ai/search/IterativeDeepening.h"
#include "test/MinimaxTest.h"
#include "ai/heuristic/Evaluation.h"

using namespace std;

void testCountAndElapsedTime();

int main() {
    vector<vector<int>> board = getSample(2);
    int stoneType = BLACK_STONE;

    iterativeDeepeningSearch(board, stoneType);

//
//    double eval = evaluation(board, BLACK_STONE);
//    printBoard(board);
//    loginfo("main","main","eval=",eval); // eval 단독테스트
//
//
//    printBoard(board);
//     //--------------------------------------------------------------------------------------
//
//
//    int stoneType = BLACK_STONE;
//    vector<vector<vector<int>>> nextStonePairs = nextStonePairsByPolicy(board, stoneType);
////    printStonePairList(nextStonePairs);
//
//    // --------------------------------------------------------------------------------------
//
//    Node root = Node(board, stoneType, ROOT_DEPTH);
//    root.extend(nextStonePairs);
//
//
//    // -----------------------------------------
//
////    double eval = evaluation(board, BLACK_STONE);
////    loginfo("main","eval=",eval);
//
//    tic(); // Total time;
//
////    testCountAndElapsedTime();
//
//    printToc(); // Total time;
//
//    printSummary();

    return 0;
}

void testCountAndElapsedTime() {
    for (int i = 0; i < 900000; ++i) {
        vector<vector<int>> board = getSample(1);
//        printBoard(board);

        double eval = evaluation(board, BLACK_STONE);
    }
}