//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_EVALUATION_H
#define AI_CONNECT6_EVALUATION_H

#include <vector>
#include <string>
#include "../../utils/BoardUtils.h"
using namespace std;
#endif //AI_CONNECT6_EVALUATION_H


double evaluation_jyp(vector<vector<int>> &board, int stoneType);
double evalSumBySequences(vector<string> seqsString);
vector<string> wallToEnemy(vector<string> sequences);
vector<string> everyEnemySequence(vector<vector<int>> board);
vector<vector<int>> inverseBoard(vector<vector<int>> board);