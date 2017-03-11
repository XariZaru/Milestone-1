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
#include <queue>

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
	void addCommand(GameEntity::Command* command) {
		commands.push(command);
	}

	boolean isPaused() {
		return paused;
	}

private:
	~Server();
	static Server* instance;
	EntityAdministrator* admin;
	boolean paused = true;
	std::priority_queue<GameEntity::Command, std::vector<GameEntity::Command*>, GameEntity::CommandComparator> commands;
};


#endif /* SERVER_H_ */
