/*
* FoodEntity.h
*
*  Created on: Feb 16, 2017
*      Author: Wesley
*/

#ifndef FOODENTITY_H_
#define FOODENTITY_H_

#include "GameEntity.h"

#include <map>

class FoodEntity : public GameEntity {

public:
	FoodEntity();
	virtual ~FoodEntity();

	EntityType getType() {
		return EntityType::FOOD;
	}

	std::string getName();

	std::pair<int, int> getPosition();
	std::pair<int, int> respawn();

private:
	std::pair<int, int> location;

};

#endif /* FOODENTITY_H_ */