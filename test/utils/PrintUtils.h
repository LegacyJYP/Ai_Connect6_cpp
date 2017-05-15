//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_PRINTUTILS_H
#define AI_CONNECT6_PRINTUTILS_H

#endif //AI_CONNECT6_PRINTUTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

void printBoard(vector<vector<int>> &board);
void printBoard(vector<vector<int>> &board, bool printFlag);
void printStringList(vector<string> &boardString);
void printStonePairList(list<vector<vector<int>>> &stonePairsList);
void printStonePairList(list<vector<vector<int>>> &stonePairsList, bool printFlag);
void printStonePairList(vector<vector<vector<int>>> &stonePairsList);
void printStonePairList(vector<vector<vector<int>>> &stonePairsList, bool printFlag);
void printStonePair(vector<vector<int>> &stonePairs);
void printStonePair(vector<vector<int>> &stonePairs, bool printFlag);
void printStonePoint(vector<int> &stonePoint);
void printStonePointList(list<vector<int>> effectiveList);
void printStonePointList(vector<vector<int>> printStonePointList);
