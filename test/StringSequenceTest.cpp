//
// Created by 박재영 on 2017. 5. 15..
//

#include "StringSequenceTest.h"
#include "../ai/utils/BoardUtils.h"
#include "Samples.h"
#include "utils/PrintUtils.h"
#include "../ai/heuristic/JYP/Evaluation_JYP.h"
#include "utils/LogUtils.h"

#include <vector>

using namespace std;

void testStringSeq() {
    vector<vector<int>> board = getSample(6);
    vector<string> boardString;
//    boardString = sero(board);
//    boardString = garo(board);
//    boardString = rightdowncross(board);
//    boardString = leftdowncross(board);
    boardString = everySequence(board);
    printStringList(boardString);
}

void testScore() {
    vector<vector<int>> board = getSample(7);
    double eval = evaluation_jyp(board, MY_STONE);
    
//    loginfo("StringSequenceTest","testScore","eval=",eval);
}