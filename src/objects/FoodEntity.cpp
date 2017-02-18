/*
* FoodEntity.cpp
*
*  Created on: Feb 16, 2017
*      Author: Wesley
*/

#include "FoodEntity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::pair<int, int> location;

FoodEntity::FoodEntity() {
	srand(time(NULL));
	location = std::make_pair(rand() % 50, rand() % 50);
	std::cout << "Creating food entity with " << location.first << " " << location.second << std::endl;
}

FoodEntity::~FoodEntity() {
	// DECONSTRUCTOR
}
std::string FoodEntity::getName()
{
	return "Food";
}
std::pair<int, int> FoodEntity::getPosition()
{
	return location;
}
void FoodEntity::respawn() {
	srand(time(NULL));
	location = std::make_pair(rand() % 50, rand() % 50);
}

std::pair<int, int> getPosition() {
	return location;
}