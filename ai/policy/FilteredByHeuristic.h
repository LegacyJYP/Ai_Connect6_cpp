//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_FILTEREDBYHEURISTIC_H
#define AI_CONNECT6_FILTEREDBYHEURISTIC_H

#endif //AI_CONNECT6_FILTEREDBYHEURISTIC_H

#include <vector>
#include <list>
#include "../../consts/CONFIG.h"

using namespace std;
vector<vector<vector<int>>> filterPairByHeuristic(vector<vector<int>> board, vector<vector<vector<int>>> effectivePair, int stoneType);
vector<vector<int>> filterByHeuristic(vector<vector<int>> board, list<vector<int>> effectiveList, int stoneType);