//
// Created by 박재영 on 2017. 5. 14..
//

#include "MinimaxTest.h"
#include "../ai/search/domain/Node.h"
#include "../ai/search/Minimax.h"
#include "../consts/SCORE.h"
#include "utils/LogUtils.h"


// Test 완료
void minimaxTest() {
// sample ggenerate
    Node root = Node(1, true);
    Node a(100);root.addChild(&a);
    Node b(200);root.addChild(&b);
    Node c(300);root.addChild(&c);

    Node aa(10);a.addChild(&aa);
    Node ab(20);a.addChild(&ab);

    Node ba(30);b.addChild(&ba);
    Node bb(40);b.addChild(&bb);

    Node ca(50);c.addChild(&ca);
    Node cb(60);c.addChild(&cb);

    Node aaa(4);aa.addChild(&aaa);
    Node aab(6);aa.addChild(&aab);
    Node aba(7);ab.addChild(&aba);
    Node abb(9);ab.addChild(&abb);

    Node baa(1);ba.addChild(&baa);
    Node bab(2);ba.addChild(&bab);
    Node bba(0);bb.addChild(&bba);
    Node bbb(1);bb.addChild(&bbb);

    Node caa(8);ca.addChild(&caa);
    Node cab(1);ca.addChild(&cab);
    Node cba(9);cb.addChild(&cba);
    Node cbb(2);cb.addChild(&cbb);


    Node *rootPtr = &root;
    int targetDepth = 3;


    Node *bestNode = miniMaxWithAlphaBeta(rootPtr, 0,
                                          -INF, INF, true,
                                          targetDepth);

    loginfo("MinimaxTest","minimaxTest","bestNode->getEvaluation()=",bestNode->getEvaluation());
}