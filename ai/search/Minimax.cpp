//
// Created by 박재영 on 2017. 5. 14..
//

#include "Minimax.h"
#include "../../test/utils/PrintUtils.h"
#include "../../test/utils/LogUtils.h"
#include "../../consts/SCORE.h"


Node* miniMaxWithAlphaBeta(Node* node, int depth,
                           double alpha, double beta, bool maximizingPlayer, int maximumDepth) {

    node->getEvaluation();

    double v = 0;
    Node* bestNode = node;
    if(node->getEvaluation() >= GAMEEND || node->getEvaluation() <= (-GAMEEND) || (!node->isExtended()) || depth == maximumDepth) {
//        loginfo("Minimax","miniMaxWithAlphaBeta","bestNode->getEvaluation()=",bestNode->getEvaluation());
        return bestNode;
    }

    if (maximizingPlayer) {
        v = -INF;
        list<Node*> children = node->getChildren();
        for (auto child : children) {
            double w = miniMaxWithAlphaBeta(child, depth + 1, alpha, beta, false, maximumDepth)->getEvaluation();


            if (v < w) {
                bestNode = child;
                v = w;
//                loginfo("Minimax","miniMaxWithAlphaBeta","updateBestNode=",depth);
                vector<vector<int>> board = bestNode->getBoard();
//                printBoard(board);
            }

            alpha = max(alpha, v);
            if(beta <= alpha) {
                break;
            }
        }

        return bestNode;
    } else {
        v = INF;
        list<Node*> children = node->getChildren();
        for (auto child : children) {
            double w = -(miniMaxWithAlphaBeta(child, depth + 1, alpha, beta, true, maximumDepth)->getEvaluation());
            if (v > w) {
                bestNode = child;
                v = w;
//                loginfo("GeneralMain","miniMaxWithAlphaBeta","updateBestNode=",depth);
                vector<vector<int>> board = bestNode->getBoard();
//                printBoard(board);
            }
            beta = -max(-beta, -v);
            if(beta <= alpha) {
                break;
            }
        }
        return bestNode;
    }
}