/*
 * EntityAdministrator.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef ENTITYADMINISTRATOR_H_
#define ENTITYADMINISTRATOR_H_

#include <vector>
#include "..\objects\GameEntity.h"

class EntityAdministrator {
public:
	EntityAdministrator();

	const std::vector<GameEntity*> getEntities();
	const std::vector<GameEntity*> getPlayers();
	GameEntity* getFood();

	bool addEntity(GameEntity& entity) {
		entities.push_back(&entity);
		return true;
	}

	void removeEntity(std::string& name);

	GameEntity* getEntity(std::string& name);

private:
	std::vector<GameEntity*> entities;
};


#endif /* ENTITYADMINISTRATOR_H_ */
