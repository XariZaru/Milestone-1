#pragma once

#include <iostream>
#include "..\objects\GameEntity.h"

class PacketEvent {
public:

	PacketEvent(int clientID, std::string information, GameEntity* p);

	std::string getInfo() {
		return info;
	}

	int getClientID() {
		return id;
	}

	GameEntity* getPlayer() {
		return player;
	}

private:
	std::string info;
	GameEntity* player;
	int id;
};