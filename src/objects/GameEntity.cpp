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
