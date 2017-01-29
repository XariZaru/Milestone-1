/*
 * PlayerEntity.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "PlayerEntity.h"
#include <iostream>

int length;

PlayerEntity::PlayerEntity() : direction(std::pair<int, int> {0, 1}), head(std::pair<int, int> {5, 5}) {
	length = 0;
}

PlayerEntity::~PlayerEntity() {
	// TODO Auto-generated destructor stub
}

int PlayerEntity::size() {
	return length;
}

void PlayerEntity::grow() {
	head.first += direction.first; head.second += direction.second;
	length++;
}
