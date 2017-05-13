//
// Created by 박재영 on 2017. 5. 12..
//

#include <iostream>
#include <list>
#include <vector>

#include "Samples.h"
#include "../ai/utils/BoardUtils.h"
#include "utils/PrintUtils.h"

using namespace std;

static bool VAR_INIT_SAMPLE = false;
static vector<vector<string>> VAR_SAMPLES(0, vector<string>(19, ""));

vector<vector<int>> getSample(int idx)
{
//    cout << "getSample idx=" << idx << "\n";

    if (!VAR_INIT_SAMPLE)
    {
//        cout << "getSample " << "!VAR_INIT_SAMPLE" << "\n";
        initSamples();
        VAR_INIT_SAMPLE = true;
    }
    vector<vector<int>> board = string2board(VAR_SAMPLES[idx]);
    return board;
}

void initSamples() {
    cout << "initSamples\n";
    // 0
    VAR_SAMPLES.push_back({
                                  "0000000000000000000",
                                  "1111111111111111111",
                                  "0000000000000000000",
                                  "0000000000001000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",

                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000"
                          });

    // 1
    VAR_SAMPLES.push_back({
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0010000000000000000",
                                  "0000000000001000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0001000000000000000",
                                  "0000000000000000000",

                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000",
                                  "0000000000000000000"
                          });

}