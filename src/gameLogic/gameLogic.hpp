#ifndef gameLogic_hpp
#define gameLogic_hpp

#include <stdio.h>
#include <queue>
#include <map>

std::pair<int, int> getDirection(std::pair<int, int> x1, std::pair<int, int> x2);

class SnakeGame
{
public:
	SnakeGame();
	~SnakeGame();
    
	std::pair<int, int> getTail();
	std::pair<int, int> randomLoc();
	void updateDirection(std::pair<int, int> newDirection);
	void updateSnake();
    
	void setBoardSize(int size);
    
private:
    
	std::queue<std::pair<int, int>> snake;
	int snakeLength = 4;
	int boardSize = 30; // square board
	std::pair<int, int> head, tail, direction;
	std::map<int, std::pair<int, int>> directions;
};

#endif /* gameLogic_hpp */
