//
// Created by 박재영 on 2017. 5. 13..
//

#include "StoneUtils.h"
#include "../../test/utils/LogUtils.h"
#include "../../consts/GAME_BOARD.h"

vector<vector<vector<int>>> stonePoints2stonePairs(vector<vector<int>> stonePoints)
{
    int len = stonePoints.size();
    int numStonePairs = len*(len-1)/2;
//    loginfo("StoneUtils","stonePoints2stonePairs","numStonePairs=",numStonePairs);
    vector<vector<vector<int>>> stonePairs(numStonePairs);

    int idx = 0;
    for (int i = 0; i < len- 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            vector<int> firstStone = stonePoints[i];
            vector<int> secondStone = stonePoints[j];
//            loginfo("StoneUtils","stonePoints2stonePairs","firstStone[X]=",firstStone[X]);
//            loginfo("StoneUtils","stonePoints2stonePairs","firstStone[Y]=",firstStone[Y]);
//            loginfo("StoneUtils","stonePoints2stonePairs","secondStone[X]=",secondStone[X]);
//            loginfo("StoneUtils","stonePoints2stonePairs","secondStone[Y]=",secondStone[Y]);
//            loginfo("StoneUtils","stonePoints2stonePairs","idx=",idx);
            stonePairs[idx] = (vector<vector<int>>{firstStone, secondStone});
            idx++;
        }
    }

    return stonePairs;
}