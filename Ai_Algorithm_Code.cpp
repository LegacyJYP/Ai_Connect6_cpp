//////
////// Created by 박재영 on 2017. 5. 14..
//////
//
//#include <stdio.h>
//#include <time.h>
//#include <cstdlib>
//#include "Connect6Algo.h"
//char info[] = { "TeamName:aaa,Department:aaa]" };
//
//
//#include "consts/GAME_BOARD.h"
//#include "ai/search/IterativeDeepening.h"
//#include "ai/utils/BoardUtils.h"
//#include "test/utils/TimeUtils.h"
//#include "test/utils/LogUtils.h"
//#include "test/utils/PrintUtils.h"
//
//int stoneType = BLACK_STONE;
//
//void myturn(int cnt) {
//    tic();
//    int x[2], y[2];
//
//
//    extern int board[BOARD_ARRAY_SIZE][BOARD_ARRAY_SIZE];
//    vector<vector<int>> copyBoard = arr2vec(board);
//    loginfo("GivenMain","copyBoard=");
//    printBoard(copyBoard);
//    iterativeDeepeningSearch(copyBoard, stoneType, cnt, x,y);
//
//    for (int i = 0; i < cnt; i++) {
//        loginfo("myturn", "result", "*x=", *(x + i));
//        loginfo("myturn", "result", "*y=", *(y + i));
//    }
//
//    domymove(x, y, cnt);
//}