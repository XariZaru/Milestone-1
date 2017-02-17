/*
 * EntityAdministrator.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "EntityAdministrator.h"
#include <iostream>

std::vector<GameEntity> entities;

EntityAdministrator::EntityAdministrator() {
	entities = std::vector<GameEntity*>();
}


std::vector<GameEntity*> EntityAdministrator::getEntities()
{
	return entities;
}

void EntityAdministrator::removeEntity(std::string & name)
{
	for (std::vector<GameEntity*>::iterator it = entities.begin(); it != entities.end(); it++)
		if ((*it)->getName() == name) {
			int index = it - entities.begin();
			GameEntity* entity = *it;
			entities.erase(entities.begin() + index);
			delete entity;
			break;
		}
}

GameEntity * EntityAdministrator::getEntity(std::string & name)
{
	for (GameEntity* entity : entities)
		if (entity->getName() == name)
			return entity;
	return nullptr;
}
