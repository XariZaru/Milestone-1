#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "websocket.h"
#include "..\src\server\Server.h"
#include <Windows.h>

using namespace std;

webSocket server;

int player1score = 0;
int player2score = 0;
string player1name = "";
string player2name = "";

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
//	cout << message << endl;
	ostringstream os;
	os << "Stranger " << clientID << " says: " << message;

	// Set player names
	std::size_t found = message.find(".Player1");
	if(found != std::string::npos){
		player1name = message.substr(0, found);
		Server::getInstance()->getAdministrator()->addPlayer(player1name, clientID);
		cout << "Player " << (Server::getInstance()->getAdministrator()->getPlayers().size()) << ": " << player1name << endl;
		Server::getInstance()->printState();
	} 

	found = message.find(".KEY");
	if (found != std::string::npos) {
		std::string command = message.substr(0, found);
		PlayerEntity* player = Server::getInstance()->getAdministrator()->getPlayer(clientID);
		if (player == nullptr)
			return;
		if (command == "left")
			player->setDx(-1);
		else if (command == "right")
			player->setDx(1);
		else if (command == "up")
			player->setDy(-1);
		else if (command == "down")
			player->setDy(1);
	}

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
