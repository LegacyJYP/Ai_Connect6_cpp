//
// Created by 박재영 on 2017. 5. 15..
//

#include "RuleChk.h"
#include "../../consts/GAME_BOARD.h"
#include "JYP/Evaluation_JYP.h"
#include "../../consts/SCORE.h"


int isGameEnd(vector<vector<int>> board, int stoneType) {
    double eval = evaluation_jyp(board, stoneType);
    if(eval > GAMEEND/2) {
        return MY_STONE;
    } else if(eval < -GAMEEND/2) {
        return NOT_MY_STONE;
    }

    return NONE_STONE;
}