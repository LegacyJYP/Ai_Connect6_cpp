//
// Created by 박재영 on 2017. 5. 13..
//

#include "VectorUtils.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/LogUtils.h"


vector<vector<int>> list2vec(list<vector<int>> origin)
{
    int len = origin.size();
    vector<vector<int>> dest(len);


    int idx=0;
    for (list<vector<int>>::iterator i = origin.begin(); i != origin.end(); i++, idx++) {
        dest[idx] = (*i);
//        loginfo("VectorUtils","list2vec");
//        printStonePoint(dest[idx]);
    }



    return dest;
}
