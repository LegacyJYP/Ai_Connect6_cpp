//
// Created by 박재영 on 2017. 5. 14..
//

#ifndef AI_CONNECT6_EVALUATION_H
#define AI_CONNECT6_EVALUATION_H

#endif //AI_CONNECT6_EVALUATION_H


#include <vector>

using namespace std;

namespace ONEFILE {
    double window(int stoneType, vector<vector<int>> board);

    double evaluation_onefile(vector<vector<int>> board, int comp);
}