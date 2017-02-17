/*
* FoodEntity.cpp
*
*  Created on: Feb 16, 2017
*      Author: Wesley
*/

#include "FoodEntity.h"
#include <iostream>

std::pair<int, int> location;

FoodEntity::FoodEntity() {
	location = std::make_pair(0, 0);
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
;

std::pair<int, int> getPosition() {
	return location;
};