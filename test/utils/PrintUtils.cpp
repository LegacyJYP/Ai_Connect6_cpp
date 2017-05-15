//
// Created by 박재영 on 2017. 5. 13..
//


#include <iostream>
#include <list>
#include "PrintUtils.h"
#include "../../ai/utils/BoardUtils.h"
#include "LogUtils.h"
#include "../../consts/GAME_BOARD.h"


void printBoard(vector<vector<int>> &board) {
        loginfo("printBoard");
        vector<string> boardString = board2string(board);

        printStringList(boardString);
}

void printBoard(vector<vector<int>> &board, bool printFlag) {
    if(printFlag) {
        loginfo("printBoard");
        vector<string> boardString = board2string(board);

        printStringList(boardString);
    }
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
void printStonePairList(list<vector<vector<int>>> &stonePairsList, bool printFlag) {

}

void printStonePairList(vector<vector<vector<int>>> &stonePairs) {
    vector<vector<vector<int>>>::iterator i;
    for (i = stonePairs.begin(); i != stonePairs.end(); i++) {
        printStonePair(*i);
    }
}

void printStonePairList(vector<vector<vector<int>>> &stonePairsList, bool printFlag) {

}

void printStonePair(vector<vector<int>> &stonePairs) {
    for (int i = 0; i < stonePairs.size(); i++)
    {
        printStonePoint(stonePairs[i]);
    }
}

void printStonePair(vector<vector<int>> &stonePairs, bool printFlag) {
    if(printFlag) {
        for (int i = 0; i < stonePairs.size(); i++) {
            printStonePoint(stonePairs[i]);
        }
    }
}

void printStonePoint(vector<int> &stonePoint)
{
    loginfo("PrintUtils","printStonePoint");
    loginfo("printStonePoint", stonePoint[X], stonePoint[Y]);
}

void printStonePointList(list<vector<int>> printStonePointList) {
//    loginfo("printStonePointList");
    for (list<vector<int>>::iterator i = printStonePointList.begin(); i != printStonePointList.end(); i++) {
        printStonePoint(*i);
    }
}

void printStonePointList(vector<vector<int>> printStonePointList) {
    loginfo("PrintUtils","printStonePointList","printStonePointList.size()=",printStonePointList.size());
    for (vector<vector<int>>::iterator i = printStonePointList.begin(); i != printStonePointList.end(); i++) {
        printStonePoint(*i);
    }
}

// void printBoardAfterPutStonePointList(board, list, stoneType);
//    vector<vector<int>> afterBoard = putStonePoints(board,effectiveList, stoneType);
//    printBoard(afterBoard);