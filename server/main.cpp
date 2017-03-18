#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "websocket.h"
#include "..\src\server\Server.h"
#include <Windows.h>
#include <thread>
#include <chrono>
#include <ctime>
#include <random>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

webSocket server;

int player1score = 0;
int player2score = 0;
string player1name = "";
string player2name = "";

// Sets random seed
mt19937 randomGenerator(time(0));

// Calls this function when a client connects
void openHandler(int clientID){
	ostringstream os;
	os << "Stranger " << clientID << " has joined.";

	vector<int> clientIDs = server.getClientIDs();
	for (unsigned int i = 0; i < clientIDs.size(); i++){
		if (clientIDs[i] != clientID)
			server.wsSend(clientIDs[i], os.str());
	}
	server.wsSend(clientID, "Welcome!");
}

// Calls this function when a client disconnects
void closeHandler(int clientID){
	ostringstream os;
	os << "Stranger " << clientID << " has left.";
	std::cout << "A player has disconnected" << std::endl;
	Server::getInstance()->getAdministrator()->removeEntity(clientID);
	Server::getInstance()->printState();

	vector<int> clientIDs = server.getClientIDs();
	for (unsigned int i = 0; i < clientIDs.size(); i++){
		if (clientIDs[i] != clientID)
			server.wsSend(clientIDs[i], os.str());
	}
}

// Calls this function when client sends a message to the server
void messageHandler(int clientID, string message){
	cout << "Message received: " << message << endl;
	ostringstream os;
	os << "Stranger " << clientID << " says: " << message;

	// If message contains ".PLAYER1" keyword, sets the name of player to inputted name
	std::size_t found = message.find(".Player1");

	if (found != std::string::npos) {
		player1name = message.substr(0, found);
		Server::getInstance()->getAdministrator()->addPlayer(player1name, clientID);
		cout << "Player " << (Server::getInstance()->getAdministrator()->getPlayers().size()) << ": " << player1name << endl;
		Server::getInstance()->printState();
		Server::getInstance()->unpause();
	} 

	// If the message contains the ".KEY" keyword, moves in specific direction
	found = message.find(".KEY");
	if (found != std::string::npos) {
		std::string packet = message.substr(0, found);
		int space = message.find(" ");
		std::string command = packet.substr(0, space);
		long long time_stamp = std::atoll(packet.substr(space + 1, packet.length()).c_str());

		PlayerEntity* player = Server::getInstance()->getAdministrator()->getPlayer(clientID);

		if (player == nullptr)
			return;

		SYSTEMTIME st;
		GetSystemTime(&st);
		long time_start = st.wMilliseconds;
		bool paused = Server::getInstance()->isPaused();

		// Creates a command event that stores the necessary timestamps
		// such as time after artificial delay and time when processed
		if (!paused) {
			SYSTEMTIME time;
			GetSystemTime(&time);
			std::uniform_int_distribution<int> delay(100, 200);
			GameEntity::Command* command_event = new GameEntity::Command();
			command_event->command = command;
			command_event->initial = time_stamp;
			command_event->delay = delay(randomGenerator);
			command_event->player = Server::getInstance()->getAdministrator()->getPlayer(clientID);
			command_event->to_arrive = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1) + command_event->delay;

			Server::getInstance()->addCommand(command_event);
			
		} 

		else if (command == "p") {
			if (Server::getInstance()->isPaused())
				Server::getInstance()->unpause();
			else
				Server::getInstance()->pause();
		}

		// Sends an acknowledgement back to the 
		GetSystemTime(&st);
		long time_elapsed = st.wMilliseconds - time_start;
		ostringstream oss;
		oss << "ACK " << time_elapsed;
		server.wsSend(clientID, oss.str());
	}

	vector<int> clientIDs = server.getClientIDs();

	for (unsigned int i = 0; i < clientIDs.size(); i++) {
		if (clientIDs[i] != clientID)
			server.wsSend(clientIDs[i], os.str());
	}
}

// Calls this function once per select() loop
void periodicHandler(){
	static time_t next = time(NULL) + 10;
	time_t current = time(NULL);

	if (current >= next) {
		ostringstream os;
		string timestring = ctime(&current);
		timestring = timestring.substr(0, timestring.size() - 1);
		os << timestring;
		

		vector<int> clientIDs = server.getClientIDs();
		for (unsigned int i = 0; i < clientIDs.size(); i++)
			server.wsSend(clientIDs[i], os.str());

		next = time(NULL) + 10;
	}
}

int main(int argc, char *argv[]){
	int port;
	Server* gameServer = Server::getInstance();
	gameServer->printState();
	gameServer->addPacketListener(&server);
	cout << "Please set server port: ";
	cin >> port;

	// Sets event handler
	server.setOpenHandler(openHandler);
	server.setCloseHandler(closeHandler);
	server.setMessageHandler(messageHandler);

	// Runs the server
	server.startServer(port);

	return 1;
}
