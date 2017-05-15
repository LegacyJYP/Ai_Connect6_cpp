//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_BOARDUTILS_H
#define AI_CONNECT6_BOARDUTILS_H

#include <list>
#include "../../consts/GAME_BOARD.h"
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> board2string(vector<vector<int>> &board);
vector<vector<int>> string2board(vector<string> boardString);
int ctoi(char c);
char itoc(int i);
vector<double> vectorClone(vector<double> origin);
vector<vector<int>> boardCloneZeros(vector<vector<int>> board);
vector<vector<int>> boardClone(vector<vector<int>> board);
void fillBoardAroundPoint(vector<vector<int>>& board, int x, int y);
vector<vector<int>> arr2vec(int[BOARD_ARRAY_SIZE][BOARD_ARRAY_SIZE]);

vector<vector<int>> putStonePoint(vector<vector<int>> &board, vector<int> &stonePoint, int stoneType);

vector<vector<int>> putStonePoints(vector<vector<int>> &board, vector<vector<int>> &stonePoints, int stoneType);
vector<vector<int>> putStonePoints(vector<vector<int>> &board, std::list<vector<int>> &stonePoints, int stoneType);
vector<vector<int>> putStonePointsForVisualize(vector<vector<int>> &board, vector<vector<int>> &stonePoints, int stoneType);
vector<vector<int>> putStonePointsForVisualize(vector<vector<int>> &board, list<vector<int>> &stonePoints, int stoneType);
vector<vector<int>> putStonePointsForVisualize(vector<vector<int>> &board, vector<vector<vector<int>>> &stonePoints, int stoneType);

vector<string> garo(vector<vector<int>> board);
vector<string> sero(vector<vector<int>> board);
vector<vector<int>> transpose(vector<vector<int>> ori);
vector<string> toStringArr(vector<vector<int>> board);
vector<string> leftdowncross(vector<vector<int>> board);
vector<string> rightdowncross(vector<vector<int>> board);
vector<string> everySequence(vector<vector<int>> board);
#endif //AI_CONNECT6_BOARDUTILS_H
