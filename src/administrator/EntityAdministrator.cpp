/*
 * EntityAdministrator.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "EntityAdministrator.h"
#include <iostream>

std::vector<GameEntity> entities;

EntityAdministrator::EntityAdministrator() : entities(std::vector<GameEntity>()) {
}

void EntityAdministrator::hello()
{
}

std::vector<GameEntity> EntityAdministrator::getEntities()
{
	return entities;
}
