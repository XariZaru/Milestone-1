/*
 * GameEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

#include <iostream>

class GameEntity {
public:

	enum EntityType {PLAYER, FOOD, GENERAL};
	virtual EntityType  getType();
	virtual std::string getName();

private:
	std::string name;
};

#endif /* GAMEENTITY_H_ */
