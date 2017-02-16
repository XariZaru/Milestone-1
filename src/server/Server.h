/*
 * Server.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "..\entity\EntityAdministrator.h"
#include <iostream>

class Server {
public:
	Server();
	static Server* getInstance();

	EntityAdministrator* getAdministrator();

	void printState();

private:
	~Server();
	static Server* instance;
	EntityAdministrator* admin;
};


#endif /* SERVER_H_ */
