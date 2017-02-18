#include "GameEntity.h"

GameEntity::EntityType GameEntity::getType()
{
	std::cout << "Using non-overrided" << std::endl;
	return EntityType::GENERAL;
}

std::string GameEntity::getName()
{
	std::cout << "Using non-overrided name" << std::endl;
	return "";
}

std::pair<int, int> GameEntity::getPosition() {
	return position;
}

void GameEntity::setPosition(std::pair<int, int>& new_position)
{
	position = new_position;
}

void GameEntity::changeX(int x_change)
{
	position.first += x_change;
}

void GameEntity::changeY(int y_change)
{
	position.second += y_change;
}

int GameEntity::getId()
{
	return 999;
}

void GameEntity::update()
{
}
