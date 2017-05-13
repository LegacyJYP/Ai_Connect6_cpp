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


using namespace std;


int main() {
    extern map<string,FunctionInfo> functionInfoMap;

//    initCostMaps();
//    functionInfoMap.find("1")->second.addTotalTime(1.5);
//    functionInfoMap.find("1")->second.increaseCall();
//    cout << functionInfoMap.find("1")->second << endl;


    tic();
    for (int i = 0; i < 1000; ++i) {


//    tic(1);

        vector<vector<int>> board = getSample(1);
//        printBoard(board);

        double eval = evaluation(board, BLACK_STONE);

//        cout << eval;

//    printToc(1);
    }

//    printToc();
    printSummary();

    return 0;
}