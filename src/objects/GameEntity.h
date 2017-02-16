/*
 * GameEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

class GameEntity {
public:

	enum EntityType {PLAYER, FOOD, GENERAL};

	GameEntity();
	virtual ~GameEntity();

	virtual EntityType getType();

private:
	EntityType type;
};

#endif /* GAMEENTITY_H_ */
