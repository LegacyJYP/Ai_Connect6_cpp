//
// Created by 박재영 on 2017. 5. 15..
//

#ifndef AI_CONNECT6_EVERYSEQUENCE_H
#define AI_CONNECT6_EVERYSEQUENCE_H

#include <vector>
#include <string>

using namespace std;

class SequenceScorePair {
private:
    string sequence;
    double score;
public:
    SequenceScorePair(string sequence, double score) : sequence(sequence), score(score) {};
    SequenceScorePair() {};

    string getSequence();
    double getScore();
};

vector<SequenceScorePair> getSequence_Score_Pairs();
void init();

#endif //AI_CONNECT6_EVERYSEQUENCE_H
