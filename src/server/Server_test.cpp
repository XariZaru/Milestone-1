//============================================================================
// Name        : Milestone.cpp
// Author      : Jon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Server.h"
#include <assert.h>

Server* server;

int main() {
	server = Server::getInstance();

	// Server creation
	assert(server != NULL);
	assert(server->getAdministrator() != NULL);
	assert(server->getPacketHandler() != NULL);
	std::cout << "Hi" << std::endl;
	return 0;
}

