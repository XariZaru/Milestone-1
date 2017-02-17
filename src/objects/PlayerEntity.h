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
	PlayerEntity(std::string name);
	PlayerEntity(std::string name, std::pair<int, int> position);
	virtual ~PlayerEntity();
	EntityType getType() {
		return EntityType::PLAYER;
	}

	std::string getName();

	int size();

	void grow();

private:
	int length;
	std::pair<int, int> head, tail, direction;
	std::map<int, std::pair<int, int>> directions;
	std::string name;
};

#endif /* PLAYERENTITY_H_ */
