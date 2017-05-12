//
// Created by 박재영 on 2017. 5. 13..
//

#include <vector>
#include <string>
#include "BoardUtils.h"
#include <cstdlib>
#include <iostream>
#include "../../consts/GAME_BOARD.h"
#include "PrintUtils.h"


using namespace std;

vector<vector<int>> string2board(vector<string> boardString)
{
    int row = boardString.size();
    int col = boardString[0].length();

    vector<vector<int>> board(row, vector<int>(col, NONE_STONE));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ctoi(boardString[i].at(j));
        }
    }

    return board;
}

int ctoi(char c) {
    return c - '0';
}

char itoc(int i) {
    return i+'0';
}

std::vector<std::string> board2string(std::vector<std::vector<int>> &board)
{
    int row = board.size();
    int col = board[0].size();

    std::vector<std::string> boardString;
    for (int i = 0; i < row; i++)
    {
        std::string eachLine = "";
        for (int j = 0; j < col; j++)
        {
            eachLine += itoc(board[i][j]);
        }
        boardString.push_back(eachLine);
    }

    return boardString;
}