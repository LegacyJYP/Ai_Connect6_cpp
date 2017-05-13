//
// Created by 박재영 on 2017. 5. 13..
//


#include <iostream>
#include <list>
#include "PrintUtils.h"
#include "BoardUtils.h"
#include "LogUtils.h"
#include "../../consts/GAME_BOARD.h"


void printBoard(vector<vector<int>> &board) {
    loginfo("printBoard");
    vector<string> boardString = board2string(board);

    printStringList(boardString);
}

void printStringList(vector<string> &boardString)
{
    for (int i = 0; i < boardString.size(); i++)
    {
        loginfo("PrintUtils/printBoard: ", boardString[i]);
    }
}

void printStonePairList(list<vector<vector<int>>> &stonePairsList) {
        list<vector<vector<int>>>::iterator i;
        for (i = stonePairsList.begin(); i != stonePairsList.end(); i++) {
            printStonePair(*i);
        }

}

void printStonePair(vector<vector<int>> &stonePairs) {
    for (int i = 0; i < stonePairs.size(); i++)
    {
        printStonePoint(stonePairs[i]);
    }
}

void printStonePoint(vector<int> &stonePoint)
{
    loginfo("printStonePoint", stonePoint[X], stonePoint[Y]);
}

void printStonePointList(list<vector<int>> printStonePointList) {
//    loginfo("printStonePointList");
    list<vector<int>>::iterator i;
    for (i = printStonePointList.begin(); i != printStonePointList.end(); i++) {
        printStonePoint(*i);
    }
}