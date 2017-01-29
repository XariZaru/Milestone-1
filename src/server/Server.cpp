/*
 * Server.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "Server.h"

Server* Server::instance;
EntityAdministrator* admin;
PacketHandler* packet_handler;

Server::Server() {
	admin = new EntityAdministrator();
	packet_handler = new PacketHandler();
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

Server* Server::getInstance() {
	if (!Server::instance)
		Server::instance = new Server();
	return Server::instance;
}

EntityAdministrator* Server::getAdministrator() {
	return admin;
}

PacketHandler* Server::getPacketHandler() {
	return packet_handler;
}
