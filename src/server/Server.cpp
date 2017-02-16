/*
 * Server.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "Server.h"
#include "..\objects\PlayerEntity.h"
#include "..\objects\FoodEntity.h"

Server* Server::instance;

Server::Server() {
	admin = new EntityAdministrator();

	// Delete after. Test cases
	admin->addEntity(PlayerEntity());
	admin->addEntity(GameEntity());

	PlayerEntity player = PlayerEntity();
	std::cout << "Player's type is " << player.getType() << std::endl;

	FoodEntity food = FoodEntity();
	std::cout << "Food's type is " << food.getType() << std::endl;

	for (GameEntity entity : admin->getEntities())
		std::cout << entity.getType() << std::endl;
}

Server::~Server() {
	delete admin;
	delete Server::instance;
}

Server* Server::getInstance() {
	if (!Server::instance)
		Server::instance = new Server();
	return Server::instance;
}

EntityAdministrator* Server::getAdministrator() {
	return admin;
}

void Server::printState()
{
	std::cout << "Server ready." << std::endl;
}
