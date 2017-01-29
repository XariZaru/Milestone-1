/*
 * PlayerEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef PLAYERENTITY_H_
#define PLAYERENTITY_H_

#include "GameEntity.h"

class PlayerEntity: public GameEntity {
public:
	PlayerEntity();
	virtual ~PlayerEntity();

	int size();

	void grow(int amt);

private:
	int length;
};

#endif /* PLAYERENTITY_H_ */
