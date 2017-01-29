/*
 * PlayerEntity.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "PlayerEntity.h"

int length;

PlayerEntity::PlayerEntity() {
	length = 0;
}

PlayerEntity::~PlayerEntity() {
	// TODO Auto-generated destructor stub
}

int PlayerEntity::size() {
	return length;
}

void PlayerEntity::grow(int amt) {
	length += amt;
}
