//
// Created by 박재영 on 2017. 5. 15..
//

#include "EverySequence.h"
#include "../../../consts/SCORE.h"


vector<SequenceScorePair> SEQUENCE_SCORE_PAIRS;

vector<SequenceScorePair> getSequence_Score_Pairs() {
    if(SEQUENCE_SCORE_PAIRS.size() == 0) {
        init();
    }
    return SEQUENCE_SCORE_PAIRS;
}

void init() {
    SEQUENCE_SCORE_PAIRS.resize(4);
    SEQUENCE_SCORE_PAIRS[0] = SequenceScorePair("01111110", GAMEEND);
    SEQUENCE_SCORE_PAIRS[1] = SequenceScorePair("21111112", GAMEEND);
    SEQUENCE_SCORE_PAIRS[2] = SequenceScorePair("21111110", GAMEEND);
    SEQUENCE_SCORE_PAIRS[3] = SequenceScorePair("01111112", GAMEEND);
}

string SequenceScorePair::getSequence() {
    return this->sequence;
};
double SequenceScorePair::getScore() {
    return this->score;
};