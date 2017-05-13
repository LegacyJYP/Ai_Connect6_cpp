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


static map<int, double> ELAPSED_TIME_INFUNC;
static map<int, int>    CALL_COUNT_INFUNC;



map<string, FunctionInfo> functionInfoMap;



void initCostMaps() {
    FunctionInfo functionInfo = FunctionInfo();
    functionInfo.addTotalTime(10);
//    cout << functionInfo << endl;
    functionInfoMap.insert(pair<string, FunctionInfo>("1", functionInfo));

    ELAPSED_TIME_INFUNC.insert(
            pair<int,double>(
                    AI::HEURISTIC::EVALUATION_evaluation_key, 0
            )
    );

    CALL_COUNT_INFUNC.insert(
            pair<int,int>(
                    AI::HEURISTIC::EVALUATION_evaluation_key, 0
            )
    );
}

void functionCallStack(int functionKey) {
    if(ELAPSED_TIME_INFUNC.size() == 0) {
        log("functionCallStack initCostMaps");
        initCostMaps();
    }
    CALL_COUNT_INFUNC.find(functionKey)->second++;
//    cout << CALL_COUNT_INFUNC.find(functionKey)->second;
//    nln();
}

void functionTic(int functionKey) {
    tic(functionKey);
}

void functionToc(int functionKey) {
    ELAPSED_TIME_INFUNC.find(functionKey)->second += toc(functionKey);
//    cout << "functionToc "<< toc(functionKey) << '\n';
    ELAPSED_TIME_INFUNC.find(functionKey)->second += toc(functionKey);
}

void printSummary() {
    int key = AI::HEURISTIC::EVALUATION_evaluation_key;
    cout << "ELAPSED_TIME "<< ELAPSED_TIME_INFUNC.find(AI::HEURISTIC::EVALUATION_evaluation_key)->second << '\n';
    cout << "CALL_COUNT "<< CALL_COUNT_INFUNC.find(AI::HEURISTIC::EVALUATION_evaluation_key)->second << '\n';
}


void FunctionInfo::increaseCall() {
    call++;
}

void FunctionInfo::addTotalTime(double duration) {
    totalTime += duration;
}

ostream& operator<<(ostream& os, const FunctionInfo& fi)
{
    os << "콜횟수 : " << fi.call << endl;
    os << "소요시간 : " << fi.totalTime;
    return os;
}