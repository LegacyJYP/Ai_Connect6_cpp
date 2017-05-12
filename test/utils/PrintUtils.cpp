//
// Created by 박재영 on 2017. 5. 13..
//

#include <vector>
#include <iostream>
#include "PrintUtils.h"
#include "BoardUtils.h"


void printBoard(std::vector<std::vector<int>> &board) {
    log("printBoard");
    std::vector <std::string> boardString = board2string(board);

    printStringList(boardString);
}

void printStringList(std::vector<std::string> &boardString)
{
    for (int i = 0; i < boardString.size(); i++)
    {
        log("PrintUtils/printBoard: ", boardString[i]);
    }
}

void log(string s) {
    cout << s << '\n';
}

void log(string s1, string s2) {
    cout << s1 << " " << s2 << '\n';
}