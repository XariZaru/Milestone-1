/*
 * Server.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "..\administrator\EntityAdministrator.h"
#include <iostream>
#include <windows.h>

class Server {
public:
	Server();
	static Server* getInstance();

	EntityAdministrator* getAdministrator();

	void printState();
	void run();
	void restart();
	void pause();
	void unpause();
	boolean isPaused() {
		return paused;
	}

private:
	~Server();
	static Server* instance;
	EntityAdministrator* admin;
	boolean paused = true;
};


#endif /* SERVER_H_ */
