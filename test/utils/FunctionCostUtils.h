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
public:
    void increaseCall();
    void addTotalTime(double duration);
    FunctionInfo() : call(0), totalTime(0) {};
    friend ostream& operator<<(ostream& os, const FunctionInfo& dt);
};

void initCostMaps();
void functionCallStack(int functionName);
void functionTic(int functionKey);
void functionToc(int functionKey);