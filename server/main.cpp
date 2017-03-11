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

/* called when a client connects */
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

/* called when a client disconnects */
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

/* called when a client sends a message to the server */
void messageHandler(int clientID, string message){
	cout << "Message received: " << message << endl;
	ostringstream os;
	os << "Stranger " << clientID << " says: " << message;

	/*
	std::uniform_int_distribution<int> delay(0, 1000);
	cout << "Time: " << time(0) << endl;
	this_thread::sleep_for(chrono::milliseconds(delay(randomGenerator)));
	cout << "Time: " << time(0) << endl;
	*/

	// If message contains a player keyword, sets the name of player to inputted name
	std::size_t found = message.find(".Player1");
	if(found != std::string::npos){
		player1name = message.substr(0, found);
		Server::getInstance()->getAdministrator()->addPlayer(player1name, clientID);
		cout << "Player " << (Server::getInstance()->getAdministrator()->getPlayers().size()) << ": " << player1name << endl;
		Server::getInstance()->printState();
		Server::getInstance()->unpause();
	} 

	// If the message contains a key keyword, move in specific direction
	found = message.find(".KEY");
	if (found != std::string::npos) {
		std::string command = message.substr(0, found);
		PlayerEntity* player = Server::getInstance()->getAdministrator()->getPlayer(clientID);
		if (player == nullptr)
			return;
		SYSTEMTIME st, delay;
		GetSystemTime(&st);
		long time_start = st.wMilliseconds;
		bool paused = Server::getInstance()->isPaused();
		unsigned long long millis = std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1);
		std::cout << millis << std::endl;
		if (!paused) {
			SYSTEMTIME time;
			GetSystemTime(&time);
			std::uniform_int_distribution<int> delay(0, 2);
			GameEntity::Command* command_event = new GameEntity::Command();
			command_event->command = command;
			command_event->initial = time.wSecond;
			command_event->delay = delay(randomGenerator);

			if (player->getCommand())
				player->addCommand(command_event);
			else
				player->setCommand(command_event);
		} else if (command == "p") {
			if (Server::getInstance()->isPaused())
				Server::getInstance()->unpause();
			else
				Server::getInstance()->pause();
		}
		GetSystemTime(&st);
		long time_elapsed = st.wMilliseconds - time_start;
		ostringstream oss;
		oss << "ACK " << time_elapsed;
		server.wsSend(clientID, oss.str());
	}

	// If the message contains a timestamp keyword, returns timestamp after latency
	found = message.find(".TIMESTAMP");
	if (found != std::string::npos) {

	};

	/*
	// Update scores
	found = message.find(".P1Score");
	if (found != std::string::npos)
	{
		player1score = stoi(message.substr(0, found));
		cout << player1name << ": " << player1score << endl;
	}
	found = message.find(".P2Score");
	if (found != std::string::npos)
	{
		player2score = stoi(message.substr(0, found));
		cout << player2name << ": " << player2score << endl;
	}
	*/

	vector<int> clientIDs = server.getClientIDs();
	for (unsigned int i = 0; i < clientIDs.size(); i++){
		if (clientIDs[i] != clientID)
			server.wsSend(clientIDs[i], os.str());
	}

}

/* called once per select() loop */
void periodicHandler(){
	static time_t next = time(NULL) + 10;
	time_t current = time(NULL);
	if (current >= next){
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
	//gameServer->run();
	gameServer->printState();
	gameServer->addPacketListener(&server);
	// Need to put game loop somewhere here afterwards
	cout << "Please set server port: ";
	cin >> port;

	/* set event handler */
	server.setOpenHandler(openHandler);
	server.setCloseHandler(closeHandler);
	server.setMessageHandler(messageHandler);
	//server.setPeriodicHandler(periodicHandler);

	/* run the chatroom server, listen to ip '127.0.0.1' and port '8000' */
	server.startServer(port);

	return 1;
}
