#include "gameLogic.hpp"
#include <iostream>
#include <random>

std::pair<int, int> getDirection(std::pair<int, int> x1, std::pair<int, int> x2)
{
    return std::pair<int, int> {x2.first - x1.first, x2.second - x1.second};
}

SnakeGame::SnakeGame() : head(randomLoc()), direction(std::pair<int, int> {0, 1})
{
    if (head.second + snakeLength >= boardSize)
        head.second -= snakeLength;
    tail.first = head.first; tail.second = head.second + snakeLength;
}

std::pair<int, int> SnakeGame::getTail()
{
    return snake.back();
}

// Do we need to do this handling here or is that client side? Wesley seems to have their locations spawned in already
std::pair<int, int> SnakeGame::randomLoc()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, boardSize-1);
    return std::pair<int, int>{ dist(rng), dist(rng) };
}
    
void SnakeGame::setBoardSize(int size)
{
    boardSize = size;
}

// Maybe we should define an actual Snake class where we can edit its properties there
/*
void SnakeGame::elongate()
{
    head.first += direction.first; head.second += direction.second;
    length++;
}
*/

// Updates direction based on user input.
void SnakeGame::updateDirection(std::pair<int, int> newDirection)
{
    direction = newDirection;
}

// Updates the head and tail of the snake accordingly.
// Removes the locations of turns for the snake when the tail
// is at the first element of the snake turn location queue.
void SnakeGame::updateSnake()
{
    std::pair<int, int> tailDirection, firstTurn = snake.front();
    head.first += direction.first; head.second += direction.second;
    direction = getDirection(head, firstTurn);
    tail.first += tailDirection.first; tail.second += tailDirection.second;
    if (tail == firstTurn)
        snake.pop();
}


