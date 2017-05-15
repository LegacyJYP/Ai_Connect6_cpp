//
// Created by 박재영 on 2017. 5. 15..
//

#include "RuleChk.h"
#include "../../consts/GAME_BOARD.h"


int isGameEnd(vector<vector<int>> board, int stoneType) {
    for(int i=0; i<NUM_DIRECTIONS; i++) {
        int dir[2] = {DIRECTION[i][X],
                      DIRECTION[i][Y]};

        int cnt = 0;
        int highest = 0;

//        for (int j<) {
//
//        }
    }




    return NONE_STONE;

    return MY_STONE;

    return NOT_MY_STONE;
}