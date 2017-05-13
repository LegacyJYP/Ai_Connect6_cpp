#include <iostream>
#include <vector>
#include <map>
#include "test/Samples.h"
#include "test/utils/PrintUtils.h"
#include "ai/heuristic/Evaluation.h"
#include "consts/GAME_BOARD.h"
#include "test/utils/TimeUtils.h"
#include "test/utils/LOG_BY_EACHFUNCTION.h"
#include "test/utils/FunctionCostUtils.h"
#include "test/utils/LogUtils.h"


using namespace std;

void testCountAndElapsedTime();

int main() {
    extern map<string,FunctionInfo> functionInfoMap;

    vector<vector<int>> board = getSample(1);
    printBoard(board);

    double eval = evaluation(board, BLACK_STONE);
    loginfo("main","eval=",eval);

//    tic(); // Total time;

    testCountAndElapsedTime();

//    printToc(); // Total time;

    printSummary();

    return 0;
}

void testCountAndElapsedTime() {
    for (int i = 0; i < 10; ++i) {
        vector<vector<int>> board = getSample(1);
        printBoard(board);

        double eval = evaluation(board, BLACK_STONE);
    }
}