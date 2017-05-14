//
// Created by 박재영 on 2017. 5. 13..
//

#include <vector>
#include <string>
#include "BoardUtils.h"
#include <cstdlib>
#include <iostream>
#include "../../consts/GAME_BOARD.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/LogUtils.h"


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


vector<vector<int>> boardCloneZeros(vector<vector<int>> board)
{
    int row = board.size();
    int col = board[0].size();

    vector<vector<int>> effectiveBoard(row, vector<int>(col, NONE_STONE));
//
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            board[i][j] = ctoi(boardString[i].at(j));
//        }
//    }

    return effectiveBoard;
}

vector<vector<int>> boardClone(vector<vector<int>> board) {
    int row = board.size();
    int col = board[0].size();

    vector<vector<int>> cloneBoard(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cloneBoard[i][j] = board[i][j];
        }
    }

    return cloneBoard;
}

vector<double> vectorClone(vector<double> origin) {
    int len = origin.size();
    vector<double> clone(len);

    for (int i = 0; i < len; i++) {
        clone[i] = origin[i];
    }

    return clone;
}

vector<vector<int>> arr2vec(int board[BOARD_ARRAY_SIZE][BOARD_ARRAY_SIZE]) {
    int row = BOARD_ARRAY_SIZE;
    int col = BOARD_ARRAY_SIZE;

    vector<vector<int>> vecBoard(row, vector<int>(col));

    for(int i = 0; i< row;i++) {
        for(int j = 0; j< col;j++){
            vecBoard[i][j] = board[i][j];
        }
    }

    return vecBoard;
}

void fillBoardAroundPoint(vector<vector<int>>& board, int x, int y) {
    int row = board.size();
    int col = board[0].size();

    int minX = std::max(x - (EFFECTIVE_RANGE-1), 0);
    int maxX = std::min(x + (EFFECTIVE_RANGE-1), row - 1);
    int minY = std::max(y - (EFFECTIVE_RANGE-1),0);
    int maxY = std::min(y + (EFFECTIVE_RANGE-1), col - 1);

//    loginfo("BoardUtils/fillBoardArroundPoint");
    //        log.info("BoardUtils/fillBoardAroundPoint: before");
    //        printBoard(board);
    //        log.info("BoardUtils/fillBoardAroundPoint: x,y=[{}],[{}]",x,y);
    for (int i = minX;i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            //                log.info("BoardUtils/fillBoardAroundPoint: i,j=[{}],[{}]",i,j);
            board[i][j] = EFFECTIVE_POSITION;
        }
    }

    //        log.info("BoardUtils/fillBoardAroundPoint: after");
    //        printBoard(board);
}

std::vector<std::vector<int>> putStonePoint(std::vector<std::vector<int>> &board, std::vector<int> &stonePoint, int stoneType)
{
    std::vector<std::vector<int>> result = boardClone(board);

    result[stonePoint[X]][stonePoint[Y]] = stoneType;

    return result;
}

// 2stones
std::vector<std::vector<int>> putStonePoints(std::vector<std::vector<int>> &board, std::vector<std::vector<int>> &stonePoints, int stoneType)
{
    std::vector<std::vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType;
    }

    return result;
}


// more than 2 stones
std::vector<std::vector<int>> putStonePoints(std::vector<std::vector<int>> &board, std::list<std::vector<int>> &stonePoints, int stoneType)
{
    std::vector<std::vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType;
    }

    return result;
}

std::vector<std::vector<int>> putStonePointsForVisualize(std::vector<std::vector<int>> &board, std::vector<std::vector<int>> &stonePoints, int stoneType)
{
    std::vector<std::vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType+2;
    }

    return result;
}