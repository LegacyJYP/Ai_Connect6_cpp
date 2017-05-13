//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_LOG_BY_FILE_H
#define AI_CONNECT6_LOG_BY_FILE_H

#endif //AI_CONNECT6_LOG_BY_FILE_H


namespace AI { // package
    namespace HEURISTIC { // package
        const bool EVALUATION_evaluation_printFlag = true;
        const string EVALUATION_evaluation_key = "EVALUATION/evaluation";
        const string base = "FILENAME/methodname";

//        const bool EVALUATION_evaluation_printFlag = true;
//        const string EVALUATION_evaluation_key = "EVALUATION/evaluation";
//
//        const bool EVALUATION_evaluation_printFlag = true;
//        const string EVALUATION_evaluation_key = "EVALUATION/evaluation";
//
//        const bool EVALUATION_evaluation_printFlag = true;
//        const string EVALUATION_evaluation_key = "EVALUATION/evaluation";
    }
}
namespace TEST {
    namespace UTILS {
        const bool BOARDUTILS_string2board_printFlag = true;
        const string BOARDUTILS_string2board_key = "BOARDUTILS/string2board";
        const string base = "FILENAME/methodname";
    }
}

void functionCallStack(int functionName);
void printSummary();