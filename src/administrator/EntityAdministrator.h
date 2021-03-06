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
#include "..\objects\PlayerEntity.h"
#include "..\objects\FoodEntity.h"

class EntityAdministrator {

public:
	EntityAdministrator();

	const std::vector<GameEntity*> getEntities();
	const std::vector<PlayerEntity*> getPlayers();
	FoodEntity* getFood();

	bool addEntity(GameEntity& entity) 
	{
		entities.push_back(&entity);
		return true;
	}

	void removeEntity(std::string& name);
	void removeEntity(int id);
	void addPlayer(std::string& name, int clientID);

	GameEntity* getEntity(std::string& name);
	PlayerEntity* getPlayer(int clientID);

private:
	std::vector<GameEntity*> entities;
};


#endif /* ENTITYADMINISTRATOR_H_ */