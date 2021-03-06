//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_CONFIG_H
#define AI_CONNECT6_CONFIG_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

namespace FILTERED_BY_HEURISTIC {
    const double THRESHOLD_PERSENTAGE = 1;
    const int PAIR_THRESHOLD_NUMBER = 10;
    const int THRESHOLD_NUMBER = 200;
}

const int ROOT_DEPTH = 0;

namespace ITERATIVE_DEEPENING_SEARCH {
    const int INITIAL_DEPTH = 1;
    const int MAXIMUM_DEPTH = 1;
}

const bool LOG_ON_FILE = false;
const string LOG_FILENAME = "C:/jyp/output.log";
//const string LOG_FILENAME = "output.txt";
const bool LOG_ON_CONSOLE = true;


#endif //AI_CONNECT6_CONFIG_H