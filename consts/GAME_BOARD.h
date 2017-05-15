//
// Created by 박재영 on 2017. 5. 13..
//

#ifndef AI_CONNECT6_GAME_BOARD_H
#define AI_CONNECT6_GAME_BOARD_H

const int NONE_STONE = 0;


const int BLACK_STONE = 1;
const char BLACK_STONE_CHAR = '1';
const int MY_STONE = BLACK_STONE;
const char MY_STONE_CHAR = BLACK_STONE_CHAR;
const int WHITE_STONE = 2;
const char WHITE_STONE_CHAR = '2';
const int NOT_MY_STONE = WHITE_STONE;
const char NOT_MY_STONE_CHAR = WHITE_STONE_CHAR;

const int WALL_STONE = 3;
const char WALL_STONE_CHAR = '3';

#define ENEMY_STONE(x) (x==BLACK_STONE) ? WHITE_STONE : BLACK_STONE
#define ENEMY_STONE_INCLUDE_NONE(x) (x==NONE_STONE ) ? 0 : (x==BLACK_STONE) ? WHITE_STONE : BLACK_STONE
const int BOARD_SIZE = 19;
#ifndef BOARD_ARRAY_SIZE
#define BOARD_ARRAY_SIZE 20
#endif

// fillBoardAroundPoint
const int EFFECTIVE_RANGE = 4;

const int EFFECTIVE_POSITION = 1;
const int NOT_AVAILABLE_POSITION = 0;
const int X = 0;
const int Y = 1;
const int NUM_DIRECTIONS = 4;
const int DIRECTION[4][2] =
        {
                {1, 1},
                {1, -1},
                {1, 0},
                {0, 1}
        };

const int MY_STONE_LIST = 0;
const int NOT_MY_STONE_LIST = 1;

const int RANDOM_CENTER = 10;
#endif //AI_CONNECT6_GAME_BOARD_H

