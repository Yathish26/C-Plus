#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

const int WIDTH = 20;
const int HEIGHT = 20;

struct Snake {
    int x, y;
    int length;
    int direction; // 0: up, 1: right, 2: down, 3: left
};

struct Food {
    int x, y;
};

#endif