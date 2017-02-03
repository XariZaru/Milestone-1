/*
 * PlayerEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef PLAYERENTITY_H_
#define PLAYERENTITY_H_

#include "GameEntity.h"

#include <map>

class PlayerEntity: public GameEntity {
public:
	PlayerEntity();
	virtual ~PlayerEntity();

	int size();

	void grow();

private:
	int length;
	std::pair<int, int> head, tail, direction;
	std::map<int, std::pair<int, int>> directions;
};

#endif /* PLAYERENTITY_H_ */
