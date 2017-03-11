#pragma once

#include <iostream>

class PacketEvent {
public:

	PacketEvent(int clientID, std::string information);
	std::string getInfo() {
		return info;
	}

	int getClientID() {
		return id;
	}
private:
	std::string info;
	int id;
};