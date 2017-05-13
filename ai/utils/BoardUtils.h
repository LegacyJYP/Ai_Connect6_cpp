//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_BOARDUTILS_H
#define AI_CONNECT6_BOARDUTILS_H

#endif //AI_CONNECT6_BOARDUTILS_H

#include <list>

using namespace std;


std::vector<std::string> board2string(std::vector<std::vector<int>> &board);
vector<vector<int>> string2board(vector<string> boardString);
int ctoi(char c);
char itoc(int i);
vector<double> vectorClone(vector<double> origin);
vector<vector<int>> boardCloneZeros(vector<vector<int>> board);
void fillBoardAroundPoint(vector<vector<int>>& board, int x, int y);

std::vector<std::vector<int>> putStonePoint(std::vector<std::vector<int>> &board, std::vector<int> &stonePoint, int stoneType);
std::vector<std::vector<int>> putStonePoints(std::vector<std::vector<int>> &board, std::vector<std::vector<int>> &stonePoints, int stoneType);
std::vector<std::vector<int>> putStonePoints(std::vector<std::vector<int>> &board, std::list<std::vector<int>> &stonePoints, int stoneType);
std::vector<std::vector<int>> putStonePointsForVisualize(std::vector<std::vector<int>> &board, std::vector<std::vector<int>> &stonePoints, int stoneType);
