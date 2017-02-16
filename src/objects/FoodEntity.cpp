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
};

std::pair<int, int> getPosition() {
	return location;
};