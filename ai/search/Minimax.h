//
// Created by 박재영 on 2017. 5. 14..
//

#ifndef AI_CONNECT6_GENERALMAIN_H
#define AI_CONNECT6_GENERALMAIN_H

#endif //AI_CONNECT6_GENERALMAIN_H

#include <vector>
#include "domain/Node.h"


using namespace std;

Node* miniMaxWithAlphaBeta(Node* node, int depth,
                          double alpha, double beta, bool maximizingPlayer, int maximumDepth);