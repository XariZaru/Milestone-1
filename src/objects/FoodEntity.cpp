/*
* FoodEntity.cpp
*
*  Created on: Feb 16, 2017
*      Author: Wesley
*/

#include "FoodEntity.h"
#include <iostream>
#include <cstdlib>

std::pair<int, int> location;

FoodEntity::FoodEntity() {
	location = std::make_pair(rand() % 400, rand() % 400);
};

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
std::pair<int, int> FoodEntity::respawn()
{

	return location = std::make_pair(rand() % 40, rand() % 400);
}
;

std::pair<int, int> getPosition() {
	return location;
};