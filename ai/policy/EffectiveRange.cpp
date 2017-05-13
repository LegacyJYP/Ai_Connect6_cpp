//
// Created by 박재영 on 2017. 5. 13..
//


#include "EffectiveRange.h"
#include "../../test/utils/BoardUtils.h"
#include "../../consts/GAME_BOARD.h"


list<vector<int>> effectiveRange(vector<vector<int>> &board) {
    // todo  board를 포인터로준다면 더짧아지나?(왜냐면 인스턴스보다 포인터가 작으니까)
    // -> 느려지는게맞음

    vector<vector<int>> effectiveBoard = boardCloneZeros(board);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == BLACK_STONE || board[i][j] == WHITE_STONE) {
                fillBoardAroundPoint(effectiveBoard, i,j);
            }
        }
    }

    list<vector<int>> effectiveList;
//
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == NONE_STONE && effectiveBoard[i][j] != EFFECTIVE_POSITION) {
                effectiveList.push_back({i,j});
            }
        }
    }

    return effectiveList;
}