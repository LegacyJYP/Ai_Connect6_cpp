//
// Created by 박재영 on 2017. 5. 15..
//

#ifndef AI_CONNECT6_NODELISTMAP_H
#define AI_CONNECT6_NODELISTMAP_H

#include <map>
#include "Node.h"

#endif //AI_CONNECT6_NODELISTMAP_H
using namespace std;


Node* addNode(Node* mother, vector<vector<int>> stonePair, int stoneType, int nTurns);
Node* addNode(vector<vector<int>> board, int stoneType,int nTurns);
void removeNodes(int nTurns);