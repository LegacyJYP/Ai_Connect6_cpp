#include <iostream>
#include <vector>
#include "test/Samples.h"
#include "test/utils/PrintUtils.h"


using namespace std;

int main() {
    vector<vector<int>> board = getSample(1);
    printBoard(board);

    return 0;
}