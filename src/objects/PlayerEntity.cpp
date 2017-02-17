/*
 * PlayerEntity.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "PlayerEntity.h"
#include <iostream>

int length;
std::string name;

PlayerEntity::PlayerEntity(std::string str) : direction(std::pair<int, int> {0, 1}), head(std::pair<int, int> {5, 5}), length(5), name(str) {
}

PlayerEntity::PlayerEntity(std::string str, std::pair<int, int> pos) : direction(std::pair<int, int> {0, 1}), head(std::pair<int, int> {5, 5}), length(5), name(str), position(pos) {
}

PlayerEntity::~PlayerEntity() {
	// TODO Auto-generated destructor stub
}

std::string PlayerEntity::getName()
{
	return name;
}

int PlayerEntity::size() {
	return length;
}

void PlayerEntity::grow() {
	head.first += direction.first; head.second += direction.second;
	length++;
}
