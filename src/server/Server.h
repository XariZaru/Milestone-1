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
#include "..\listeners\PacketListener.h"
#include <set>
#include <queue>
#include <iterator>

class Server {
public:
	Server();
	static Server* getInstance();

	EntityAdministrator* getAdministrator();

	void printState();
	void addPacketListener(PacketListener* listener) {
		packetListeners.insert(listener);
		updatePacketListeners(1, "this stuff works");
	}

	void updatePacketListeners(int clientID, std::string info) {
		PacketEvent event(clientID, info, admin->getPlayer(clientID));
		for (PacketListener* listener : packetListeners)
			listener->update(&event);
	}

	void addCommand(GameEntity::Command* command) {
		std::cout << "Adding command " << command->command << " with " << command->initial << std::endl;
		commands.push(command);

		if (commands.size() >= 2) {
			std::cout << "Command 1 " << commands.top()->command << "  " << commands.top()->initial << std::endl;
			commands.pop();
			std::cout << "Command 2 " << commands.top()->command << "  " << commands.top()->initial << std::endl;
			commands.pop();
			std::cout << "Size is " << commands.size() << std::endl;
		}
	}

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
	std::set<PacketListener*> packetListeners;
	std::priority_queue<GameEntity::Command*, std::vector<GameEntity::Command*>, GameEntity::CommandComparator> commands;
};


#endif /* SERVER_H_ */
