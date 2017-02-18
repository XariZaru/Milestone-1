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
	virtual EntityType  getType() = 0;
	virtual std::string getName();
	virtual std::pair<int, int> getPosition();
	virtual void setPosition(std::pair<int, int>& new_position) ;
	virtual void changeX(int x_change);
	virtual void changeY(int y_change);
	virtual int  getId();
	virtual void update();
	virtual void respawn();

private:
	std::string name;

protected:
	std::pair<int, int> position;
};

#endif /* GAMEENTITY_H_ */
