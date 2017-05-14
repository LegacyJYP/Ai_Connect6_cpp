//
// Created by 박재영 on 2017. 5. 14..
//

#include "Evaluation_ONEFILE.h"
#include "../../../consts/GAME_BOARD.h"


double window(int stoneType, vector<vector<int>> board) {
    int n = BOARD_SIZE;
    int temp = 0, score = 0, counter;

    char otherPlayer;
    if (stoneType == BLACK_STONE)
        otherPlayer = WHITE_STONE;
    if (stoneType == WHITE_STONE)
        otherPlayer = BLACK_STONE;

    int extraPoints = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == stoneType) {
//starting 6 back, checking each series of 6 vertically
                for (int t = -5; t <= 0; t++) {
                    extraPoints = 0;
                    counter = 0;
                    for (int a = 0; a < 6 && i + t + 5 < n && i + t >= 0; a++) {
//extra points are awarded for consecutive tiles
                        if (board[i + t + a][j] == NONE_STONE) {
                            extraPoints = 0;
                        }
                        if (board[i + t + a][j] == stoneType) {
                            temp += (10 + extraPoints);
                            extraPoints = (extraPoints + 1) * 2;
                            counter++;
                        }
                        if (board[i + t + a][j] == otherPlayer) {
                            temp = 0;
                            break;
                        }
                    }
                    if (counter == 6) {
                        temp *= 81;
                    }
                    if (counter == 5) {
                        temp *= 9;
                    }
                    if (counter == 4) {
                        temp *= 3;
                    }
                    score += temp;
                    temp = 0;
                }

//starting 6 back, checking each series of 6 horizontally
                for (int t = -5; t <= 0; t++) {
                    extraPoints = 0;
                    counter = 0;
                    for (int a = 0; a < 6 && j + 5 + t < n && j + t >= 0; a++) {
                        if (board[i][j + t + a] == NONE_STONE) {
                            extraPoints = 0;
                        }
                        if (board[i][j + t + a] == stoneType) {
                            temp += (10 + extraPoints);
                            extraPoints = (extraPoints + 1) * 2;
                            counter++;
                        }
                        if (board[i][j + t + a] == otherPlayer) {
                            temp = 0;
                            break;
                        }
                    }
                    if (counter == 6) {
                        temp *= 81;
                    }
                    if (counter == 5) {
                        temp *= 9;
                    }
                    if (counter == 4) {
                        temp *= 3;
                    }
                    score += temp;
                    temp = 0;
                }


//starting 6 back, checking each series of 6 diagonally downward
                for (int t = -5; t <= 0; t++) {
                    extraPoints = 0;
                    counter = 0;
                    for (int a = 0; a < 6 && j + 5 + t < n && i + 5 + t < n && i + t >= 0 && j + t >= 0; a++) {
                        if (board[i + t + a][j + t + a] == NONE_STONE) {
                            extraPoints = 0;
                        }
                        if (board[i + t + a][j + t + a] == stoneType) {
                            temp += (10 + extraPoints);
                            extraPoints = (extraPoints + 1) * 2;
                            counter++;
                        }
                        if (board[i + t + a][j + t + a] == otherPlayer) {
                            temp = 0;
                            break;
                        }
                    }
                    if (counter == 6) {
                        temp *= 81;
                    }
                    if (counter == 5) {
                        temp *= 9;
                    }
                    if (counter == 4) {
                        temp *= 3;
                    }
                    score += temp;
                    temp = 0;
                }


//starting 6 back, checking each series of 6 diagonally upward
                for (int t = -5; t <= 0; t++) {
                    extraPoints = 0;
                    counter = 0;
                    for (int a = 0; a < 6 && j + 5 + t < n && i - t < n && j + t >= 0 && i - 5 - t >= 0; a++) {
                        if (board[i - t - a][j + t + a] == NONE_STONE) {
                            extraPoints = 0;
                        }
                        if (board[i - t - a][j + t + a] == stoneType) {
                            temp += (10 + extraPoints);
                            extraPoints = (extraPoints + 1) * 2;
                            counter++;
                        }
                        if (board[i - t - a][j + t + a] == otherPlayer) {
                            temp = 0;
                            break;
                        }
                    }
                    if (counter == 6) {
                        temp *= 81;
                    }
                    if (counter == 5) {
                        temp *= 9;
                    }
                    if (counter == 4) {
                        temp *= 3;
                    }
                    score += temp;
                    temp = 0;
                }
            }
        }
    }
    return score;
}

//function to evaluate the score of the board for both stoneTypes, then find the difference

double evaluation_onefile(vector<vector<int>> board, int comp) {
    int human;
    if (comp == BLACK_STONE)
        human = WHITE_STONE;
    if (comp == WHITE_STONE)
        human = BLACK_STONE;

    int scoreComp, score1, score2;
    int scoreHuman, score3, score4;
    int difference;
    //if (debug)
    //    printBoard();

    scoreComp = window(comp, board);
    scoreHuman = window(human, board);
    difference = scoreComp - scoreHuman;
    return difference;
}