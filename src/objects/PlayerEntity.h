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
	PlayerEntity(std::string name, int clientID);
	PlayerEntity(std::string name, std::pair<int, int> position, int clientID);
	virtual ~PlayerEntity();
	virtual int getId();
	virtual void update();
	EntityType getType() {
		return EntityType::PLAYER;
	}

	std::string getName();

	int size();

	void grow();

private:
	int length, id, dx = 10, dy = 0;
	std::pair<int, int> head, tail, direction;
	std::map<int, std::pair<int, int>> directions;
	std::string name;
};

#endif /* PLAYERENTITY_H_ */
