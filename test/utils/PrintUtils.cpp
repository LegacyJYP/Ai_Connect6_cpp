//
// Created by 박재영 on 2017. 5. 13..
//

#include <vector>
#include <iostream>
#include "PrintUtils.h"
#include "BoardUtils.h"
#include "LogUtils.h"

using namespace std;

void printBoard(std::vector<std::vector<int>> &board) {
//    log("printBoard");
    std::vector <std::string> boardString = board2string(board);

    printStringList(boardString);
}

void printStringList(std::vector<std::string> &boardString)
{
    for (int i = 0; i < boardString.size(); i++)
    {
//        log("PrintUtils/printBoard: ", boardString[i]);
    }
}