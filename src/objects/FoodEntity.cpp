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
	location = std::make_pair(rand() % 300, rand() % 300);
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
	return std::pair<int, int>();
}
std::pair<int, int> FoodEntity::respawn()
{

	return std::make_pair(rand() % 300, rand() % 300);
}
;

std::pair<int, int> getPosition() {
	return location;
};