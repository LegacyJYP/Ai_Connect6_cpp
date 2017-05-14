//
// Created by 박재영 on 2017. 5. 13..
//

#include <map>
#include "FunctionCostUtils.h"
#include "LOG_BY_EACHFUNCTION.h"
#include "PrintUtils.h"
#include <iostream>
#include "LogUtils.h"
#include "TimeUtils.h"
#include "../Samples.h"


map<string, FunctionInfo> functionInfoMap;

void FunctionInfo::increaseCall() {
    call++;
}

void FunctionInfo::addTotalTime(double duration) {
    totalTime += duration;
}

bool FunctionInfo::isPrint() {
    return print;
}

FunctionInfo FunctionInfo::setPrint(bool boolean) {
    print = boolean;
    return *this;
}

ostream& operator<<(ostream& os, const FunctionInfo& fi)
{
    os << "콜횟수 : " << fi.call << endl;
    os << "소요시간 : " << fi.totalTime;
    return os;
}

// ----------------------------------------------------------

void initCostMaps() {
    functionInfoMap.insert(pair<string, FunctionInfo>(
            AI::HEURISTIC::EVALUATION_evaluation_key,
            FunctionInfo().setPrint(
                    AI::HEURISTIC::EVALUATION_evaluation_printFlag
            )
    ));

    functionInfoMap.insert(pair<string, FunctionInfo>(
            AI::HEURISTIC::EVALUATION_evaluation_key,
            FunctionInfo().setPrint(
                    AI::HEURISTIC::EVALUATION_evaluation_printFlag
            )
    ));
}

void functionCallStack(string functionKey) {
    if(functionInfoMap.size() == 0) {
        loginfo("functionCallStack initCostMaps");
        initCostMaps();
    }
    functionInfoMap.find(functionKey)->second.increaseCall();
}

void functionTic(string functionKey) {
    tic(functionKey);
}

void functionToc(string functionKey) {
    functionInfoMap.find(functionKey)->second.addTotalTime(toc(functionKey));
//    loginfo("functionToc ", toc(functionKey));
}

void printSummary() {
    map<string, FunctionInfo>::iterator i;
    for (i = functionInfoMap.begin(); i != functionInfoMap.end(); i++) {
        if (i->second.isPrint()) {
//            cout << "함수이름 : " << i->first << endl;
//            cout << i->second << endl;
        }
    }
}