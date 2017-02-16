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

	std::vector<GameEntity> getEntities();

	bool addEntity(GameEntity& entity) {
		entities.push_back(entity);
		return true;
	}

private:
	std::vector<GameEntity> entities;
};


#endif /* ENTITYADMINISTRATOR_H_ */
