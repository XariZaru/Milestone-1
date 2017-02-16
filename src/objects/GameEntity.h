/*
 * GameEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

enum EntityType {player, food};

class GameEntity {
public:
	GameEntity();
	virtual ~GameEntity();

	EntityType getType() {
		return type;
	}

	void setType(EntityType type) {
		GameEntity::type = type;
	}

private:
	EntityType type;
};

#endif /* GAMEENTITY_H_ */
