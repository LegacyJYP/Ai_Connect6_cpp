//
// Created by 박재영 on 2017. 5. 13..
//

#include "BoardUtils.h"
#include <cstdlib>
#include <iostream>
#include "../../consts/GAME_BOARD.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/LogUtils.h"


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

vector<string> board2string(vector<vector<int>> &board)
{
    int row = board.size();
    int col = board[0].size();

    vector<string> boardString;
    for (int i = 0; i < row; i++)
    {
        string eachLine = "";
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
    int row = BOARD_SIZE;
    int col = BOARD_SIZE;

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

vector<vector<int>> putStonePoint(vector<vector<int>> &board, vector<int> &stonePoint, int stoneType)
{
    vector<vector<int>> result = boardClone(board);

    result[stonePoint[X]][stonePoint[Y]] = stoneType;

    return result;
}

// 2stones
vector<vector<int>> putStonePoints(vector<vector<int>> &board, vector<vector<int>> &stonePoints, int stoneType)
{
    vector<vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType;
    }

    return result;
}


// more than 2 stones
vector<vector<int>> putStonePoints(vector<vector<int>> &board, std::list<vector<int>> &stonePoints, int stoneType)
{
    vector<vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType;
    }

    return result;
}

vector<vector<int>> putStonePointsForVisualize(vector<vector<int>> &board, vector<vector<int>> &stonePoints, int stoneType)
{
    vector<vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType+4;
    }

    return result;
}

vector<vector<int>> putStonePointsForVisualize(vector<vector<int>> &board, list<vector<int>> &stonePoints, int stoneType) {
    vector<vector<int>> result = boardClone(board);

    for (auto stonePoint : stonePoints)
    {
        result[stonePoint[X]][stonePoint[Y]] = stoneType+4;
    }

    return result;
}

vector<vector<int>> putStonePointsForVisualize(vector<vector<int>> &board, vector<vector<vector<int>>> &stonePointList, int stoneType)
{
    vector<vector<int>> result = boardClone(board);

    for (auto stonePoints : stonePointList)
    {
        result = putStonePointsForVisualize(result, stonePoints, stoneType);
    }

    return result;
}

vector<string> everySequence(vector<vector<int>> board) {
    bool printFlag = true;

    vector<vector<string>> str3dArr(4);

    str3dArr[0] = garo(board);
    str3dArr[1] = sero(board);
    str3dArr[2] = leftdowncross(board);
    str3dArr[3] = rightdowncross(board);

    vector<string> strArr(
                    str3dArr[0].size() +
                    str3dArr[1].size() +
                    str3dArr[2].size() +
                    str3dArr[3].size()
    );

    int accumulatedIdx = 0;
    for(int i=0; i< str3dArr.size(); i++) {
        for(int j=0; j< str3dArr[i].size(); j++) {
            strArr[accumulatedIdx] = str3dArr[i][j];
            accumulatedIdx++;
        }
    }

    return strArr;
}

vector<string> garo(vector<vector<int>> board) {
    return toStringArr(board);
}

vector<string> sero(vector<vector<int>> board) {
    vector<vector<int>> transState = transpose(board);

    return toStringArr(transState);
}

vector<vector<int>> transpose(vector<vector<int>> ori) {
    vector<vector<int>> dup = boardClone(ori);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            dup[j][i] = ori[i][j];
        }
    }

    return dup;
}

vector<string> toStringArr(vector<vector<int>> board) {
    vector<string> strArr(BOARD_SIZE);

    for(int i=0; i< BOARD_SIZE; i++) {
        string str = "";
        str += (WALL_STONE_CHAR);
        for(int j=0; j< BOARD_SIZE; j++) {
            str = str + itoc(board[i][j]);
        }
        str = str + WALL_STONE_CHAR;
        // System.out.println(str.toString());
        strArr[i] = str;
    }
    return strArr;
}

vector<string> leftdowncross(vector<vector<int>> board) {
    vector<string> strArr(BOARD_SIZE*2-1);
    string str;

    for (int i = 0; i < BOARD_SIZE; i++) {
        str = WALL_STONE_CHAR;
        for (int j = i; j >= 0; j--) {
            str = str + itoc(board[i-j][j]);
        }
        str = str + WALL_STONE_CHAR;
//            System.out.println(str);
        strArr[i]=str;
    }

    for (int j = 1; j < BOARD_SIZE; j++) {
        str = WALL_STONE_CHAR;
        for (int i = 0; (j+i) < BOARD_SIZE; i++) {
            str = str + itoc(board[j+i][BOARD_SIZE-i-1]);
        }
        str = str + WALL_STONE_CHAR;
//            System.out.println(str);
        strArr[BOARD_SIZE+j-1] = str;
    }

    return strArr;
}

vector<string> rightdowncross(vector<vector<int>> board) {
    vector<string> strArr(BOARD_SIZE*2-1);
    string str;

    for (int i = 0; i < BOARD_SIZE; i++) {
        str = WALL_STONE_CHAR;

        for (int j = 0; (i+j) < BOARD_SIZE; j++) {
            str = str + itoc(board[i+j][j]);
        }
        str = str+WALL_STONE_CHAR;
        strArr[i] = str;
    }

    for (int j = 1; j < BOARD_SIZE; j++) {
        str = WALL_STONE_CHAR;
        for (int i = 0; (i+j) < BOARD_SIZE; i++) {
            str = str + itoc(board[i][i+j]);
        }
        str = str+WALL_STONE_CHAR;

        strArr[BOARD_SIZE+j-1] = (str);
    }

    return strArr;
}