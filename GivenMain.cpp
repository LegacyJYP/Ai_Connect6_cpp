////
//// Created by 박재영 on 2017. 5. 14..
////
//
//#include <stdio.h>
//#include <time.h>
//#include <cstdlib>
//#include "Connect6Algo.h"
////char info[] = { "TeamName:ª˘«√ƒ⁄µÂ[C],Department:AI∫Œº≠[C]" };
//
//
//#include "consts/GAME_BOARD.h"
//#include "ai/search/IterativeDeepening.h"
//#include "ai/utils/BoardUtils.h"
//#include "test/utils/TimeUtils.h"
//#include "test/utils/LogUtils.h"
//#include "test/utils/PrintUtils.h"
//
//
//void myturn(int cnt) {
//    tic();
//    int x[2], y[2];
//
//
//    extern int board[][];
//    vector<vector<int>> copyBoard = arr2vec(board);
//    loginfo("GivenMain","copyBoard=");
//    printBoard(copyBoard);
//    iterativeDeepeningSearch(copyBoard, stoneType, cnt, x,y);
//
//    loginfo("GivenMain","extend","*x=",*x);
////    loginfo("GivenMain","extend","x[1]=",x[1]);
//    loginfo("GivenMain","extend","*y=",*y);
////    loginfo("GivenMain","extend","y[1]=",y[1]);
////    domymove(x,y,cnt);
//
//    printToc();
//    // ¿Ã ∫Œ∫–ø°º≠ æÀ∞Ì∏Æ¡Ú «¡∑Œ±◊∑•(AI)¿ª ¿€º∫«œΩ Ω√ø¿. ±‚∫ª ¡¶∞¯µ» ƒ⁄µÂ∏¶ ºˆ¡§ ∂«¥¬ ªË¡¶«œ∞Ì ∫ª¿Œ¿Ã ƒ⁄µÂ∏¶ ªÁøÎ«œΩ√∏È µÀ¥œ¥Ÿ.
//    // «ˆ¿Á Sample code¿« AI¥¬ Random¿∏∑Œ µπ¿ª ≥ı¥¬ Algorithm¿Ã ¿€º∫µ«æÓ ¿÷Ω¿¥œ¥Ÿ.
//
//    srand((unsigned)time(NULL));
//
//    for (int i = 0; i < cnt; i++) {
//        do {
//            x[i] = rand() % width;
//            y[i] = rand() % height;
//            if (terminateAI) return;
//        } while (!isFree(x[i], y[i]));
//
//        if (x[1] == x[0] && y[1] == y[0]) i--;
//    }
//
//    // ¿Ã ∫Œ∫–ø°º≠ ¿⁄Ω≈¿Ã ≥ı¿ª µπ¿ª √‚∑¬«œΩ Ω√ø¿.
//    // « ºˆ «‘ºˆ : domymove(xπËø≠,yπËø≠,πËø≠≈©±‚)
//    // ø©±‚º≠ πËø≠≈©±‚(cnt)¥¬ myturn()¿« ∆ƒ∂ÛπÃ≈Õ cnt∏¶ ±◊¥Î∑Œ ≥÷æÓæﬂ«’¥œ¥Ÿ.
//
//    domymove(x, y, cnt);
//}