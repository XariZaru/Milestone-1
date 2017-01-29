/*
 * Server.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "Server.h"

Server* Server::instance;

Server::Server() {
	// TODO Auto-generated constructor stub

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

Server* Server::getInstance() {
	if (!Server::instance)
		Server::instance = new Server();
	return Server::instance;
}
