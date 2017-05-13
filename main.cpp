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
    loginfo("eval=",eval);
//    initCostMaps();
//    functionInfoMap.find("1")->second.addTotalTime(1.5);
//    functionInfoMap.find("1")->second.increaseCall();
//    cout << functionInfoMap.find("1")->second << endl;


//    tic(); // Total time;


//    printToc(); // Total time;
    testCountAndElapsedTime();
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