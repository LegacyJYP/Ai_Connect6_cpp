//
// Created by 박재영 on 2017. 5. 13..
//

#include "Sort.h"
#include "../utils/BoardUtils.h"
#include "../../test/utils/LogUtils.h"
#include "../../consts/SCORE.h"


vector<int> sortAndReturnIdx(vector<double> evalList) {
    vector<double> cloneList = vectorClone(evalList);

    int len = evalList.size();
    vector<int> sortedIdx(len);

    for (int i = 0; i < len; i++) {

        double maximum = -INF;
        int maximum_idx = i;
        for (int j = 0; j < len; j++) {
            double temp = cloneList[j];
            if (temp > maximum) {
                // sort할때 idx를 출력하는 방식은 순서를 변경하면안됨. 이미 사용한놈만 -INF로 바꾸기.
                maximum = temp;
                maximum_idx = j;
//                loginfo("Sort","sortAndReturnIdx","temp=",temp);
//                loginfo("Sort","sortAndReturnIdx","maximum_idx=",maximum_idx);
            }
        }
//        loginfo("Sort","sortAndReturnIdx","maximum_idx=",maximum_idx);
        sortedIdx[i]= maximum_idx;

        cloneList[maximum_idx] = -INF;
    }

    return sortedIdx;
}