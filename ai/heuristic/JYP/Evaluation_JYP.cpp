//
// Created by 박재영 on 2017. 5. 13..
//

#include <iostream>
#include "Evaluation_JYP.h"
#include "../../../test/utils/PrintUtils.h"
#include "../../../test/utils/LOG_BY_EACHFUNCTION.h"
#include "../../../consts/GAME_BOARD.h"
#include "../../../test/utils/FunctionCostUtils.h"
#include "../../../consts/SCORE.h"
#include "EverySequence.h"
#include "CountMatches.h"
#include "../../../test/utils/LogUtils.h"

//double evaluation_jyp(std::vector<std::vector<int>> &board, int stoneType) {
//    functionCallStack(AI::HEURISTIC::EVALUATION_evaluation_key);
//    functionTic(AI::HEURISTIC::EVALUATION_evaluation_key);
//
//    double evaluation = 0;
//
//    if (board[0][0] == BLACK_STONE) {
//        evaluation = 90;
//    }
//
//    if (board[1][0] == BLACK_STONE) {
//        evaluation = 9;
//    }
//
//    if (board[0][1] == BLACK_STONE) {
//        evaluation = 900;
//    }
//
//
//    functionToc(AI::HEURISTIC::EVALUATION_evaluation_key);
//    return evaluation;
//}



double evaluation_jyp(vector<vector<int>> &board, int stoneType) {
    bool printFlag = false;
    loginfo("Evaluation_JYP","testScore",printFlag);
    functionCallStack(AI::HEURISTIC::EVALUATION_evaluation_key);
    functionTic(AI::HEURISTIC::EVALUATION_evaluation_key);

    loginfo("Evaluation_JYP","everySequence",printFlag);
    vector<string> seqs = wallToEnemy(everySequence(board));
    vector<string> enemySeqs =wallToEnemy(everyEnemySequence(board));

    double eval=0;
    eval += evalSumBySequences(seqs);
    eval -= evalSumBySequences(enemySeqs);
    loginfo("Evaluation_JYP","testScore","eval=",eval, printFlag);
    if(stoneType == NOT_MY_STONE) {
        eval = -eval;
    }

    functionToc(AI::HEURISTIC::EVALUATION_evaluation_key);
    return eval;
}

double evalSumBySequences(vector<string> boardString) {
    double eval = 0;

    vector<SequenceScorePair> sequence_score_pair = getSequence_Score_Pairs();
    for (int i = 0 ; i<boardString.size(); i++) {
        for (int j = 0; j < sequence_score_pair.size(); j++) {
            string scoredSeq = sequence_score_pair[j].getSequence();
            double seqScore = sequence_score_pair[j].getScore();
            int count = countMatches(boardString[i], scoredSeq);
            eval += seqScore*(double)count;
        }
    }
    return eval;
}

vector<string> wallToEnemy(vector<string> sequences) {
    vector<string> result(sequences.size());

    for (int i = 0; i < sequences.size(); i++) {
        string seq = sequences[i];
        replace(seq.begin(), seq.end(), WALL_STONE_CHAR, NOT_MY_STONE_CHAR);
        result[i] = seq;
    }

    return result;
}

vector<string> everyEnemySequence(vector<vector<int>> board) {
    return everySequence(inverseBoard(board));
}

vector<vector<int>> inverseBoard(vector<vector<int>> board) {
    vector<vector<int>> inverse = boardClone(board);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            inverse[i][j] = ENEMY_STONE_INCLUDE_NONE(board[i][j]);
        }
    }

    return inverse;
}