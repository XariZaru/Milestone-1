/*
 * Server.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "..\entity\EntityAdministrator.h"
#include "..\network\PacketHandler.h"

class Server {
public:
	Server();
	virtual ~Server();
	static Server* getInstance();

	EntityAdministrator* getAdministrator();
	PacketHandler* getPacketHandler();

private:
	static Server* instance;
	EntityAdministrator* admin;
	PacketHandler* packet_handler;
};


#endif /* SERVER_H_ */
