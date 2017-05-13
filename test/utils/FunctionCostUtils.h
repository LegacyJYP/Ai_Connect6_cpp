//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_FUNCTIONCOSTUTILS_H
#define AI_CONNECT6_FUNCTIONCOSTUTILS_H

#endif //AI_CONNECT6_FUNCTIONCOSTUTILS_H

#include <iostream>

using namespace std;


class FunctionInfo {
private:
    int call;
    double totalTime;
    bool print;
public:
    void increaseCall();
    void addTotalTime(double duration);
    bool isPrint();
    FunctionInfo setPrint(bool);
    FunctionInfo() : call(0), totalTime(0), print(true) {};
    friend ostream& operator<<(ostream& os, const FunctionInfo& dt);
};


void initCostMaps();
void functionCallStack(string functionKey);
void functionTic(string functionKey);
void functionToc(string functionKey);
void printSummary();