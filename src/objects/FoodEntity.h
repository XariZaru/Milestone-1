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
	FoodEntity();
	virtual ~FoodEntity();

	std::pair<int, int> getPosition();

private:
	std::pair<int, int> location;

};

#endif /* FOODENTITY_H_ */