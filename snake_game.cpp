#include <iostream>
#include <cstdlib>
#include <ctime>
#include "snake_game.h"
#include <conio.h>

using namespace std;

// Function to draw the game board
void drawBoard(Snake snake, Food food) {
    system("cls"); // Clear the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == snake.y && j == snake.x) {
                cout << 'S'; // Snake head
            } else if (i == food.y && j == food.x) {
                cout << 'F'; // Food
            } else {
                cout << '.'; // Empty space
            }
        }
        cout << endl;
    }
}

// Function to update snake position
void updateSnake(Snake &snake) {
    switch (snake.direction) {
        case 0: snake.y--; break; // Move up
        case 1: snake.x++; break; // Move right
        case 2: snake.y++; break; // Move down
        case 3: snake.x--; break; // Move left
    }
}

// Function to check collisions
bool checkCollision(Snake snake) {
    if (snake.x < 0 || snake.x >= WIDTH || snake.y < 0 || snake.y >= HEIGHT) {
        return true; // Wall collision
    }
    // Check self-collision (simplified for this example)
    if (snake.length > 1 && snake.x == snake.x - 1 && snake.y == snake.y - 1) {
        return true;
    }
    return false;
}

int main() {
    srand(time(0)); // Initialize random seed

    Snake snake = {WIDTH / 2, HEIGHT / 2, 1, 1}; // Initialize snake
    Food food = {rand() % WIDTH, rand() % HEIGHT}; // Initialize food

    while (true) {
        drawBoard(snake, food);
        char input;
        cin >> input;

        switch (input) {
            case 'w': snake.direction = 0; break; // Move up
            case 'd': snake.direction = 1; break; // Move right
            case 's': snake.direction = 2; break; // Move down
            case 'a': snake.direction = 3; break; // Move left
        }

        updateSnake(snake);

        if (checkCollision(snake)) {
            cout << "Game Over!" << endl;
            break;
        }

        if (snake.x == food.x && snake.y == food.y) {
            snake.length++;
            food.x = rand() % WIDTH;
            food.y = rand() % HEIGHT;
        }
    }

    return 0;
}