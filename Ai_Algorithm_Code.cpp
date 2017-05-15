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
//const int stoneType = MY_STONE;
//
//void myturn(int cnt) {
//    int x[2], y[2];
//
//    if(terminateAI) {
//        return;
//    }
//
//    vector<vector<int>> copyBoard(BOARD_SIZE,vector<int>(BOARD_SIZE));
//
//    for(int i = 0; i<BOARD_SIZE; i++) {
//        for(int j=0; j<BOARD_SIZE;j++) {
//            copyBoard[i][j] = showBoard(i,j);
//        }
//    }
//
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