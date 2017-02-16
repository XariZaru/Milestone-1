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

	std::pair<int, int> position();
	std::pair<int, int> respawn();

private:
	std::pair<int, int> x_loc, y_loc;

};

#endif /* FOODENTITY_H_ */