//
// Created by 박재영 on 2017. 5. 15..
//

#include <iostream>

#include "CountMatches.h"
#include "../../../test/utils/LogUtils.h"


int countMatches(string string1, string string2) {
    bool printFlag = false;

    int i=0;
    int count = 0;
    while(true){
        size_t contain = string1.find(string2,i);
        if (contain == string::npos) {
            break;
        }
        count++;
        i = contain + 1;
    }

    loginfo("CountMatches","countMatches","string1=",string1,printFlag);
    loginfo("CountMatches","countMatches","string2=",string2,printFlag);
    loginfo("CountMatches","countMatches","countMatches=",count,printFlag);
    return count;
}