#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include "websocket.h"
#include "..\src\server\Server.h"

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
	for (int i = 0; i < clientIDs.size(); i++){
		if (clientIDs[i] != clientID)
			server.wsSend(clientIDs[i], os.str());
	}
	server.wsSend(clientID, "Welcome!");
}

/* called when a client disconnects */
void closeHandler(int clientID){
	ostringstream os;
	os << "Stranger " << clientID << " has leaved.";

	vector<int> clientIDs = server.getClientIDs();
	for (int i = 0; i < clientIDs.size(); i++){
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
		cout << "Player 1: " << player1name << endl;
	}
	found = message.find(".Player2");
	if (found != std::string::npos)
	{
		player2name = message.substr(0, found);
		cout << "Player 2: " << player2name << endl;
	}
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

	vector<int> clientIDs = server.getClientIDs();
	for (int i = 0; i < clientIDs.size(); i++){
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
		for (int i = 0; i < clientIDs.size(); i++)
			server.wsSend(clientIDs[i], os.str());

		next = time(NULL) + 10;
	}
}

int main(int argc, char *argv[]){
	int port;

	cout << "Please set server port: ";
	cin >> port;

	/* set event handler */
	server.setOpenHandler(openHandler);
	server.setCloseHandler(closeHandler);
	server.setMessageHandler(messageHandler);
	//server.setPeriodicHandler(periodicHandler);

	/* start the chatroom server, listen to ip '127.0.0.1' and port '8000' */
	server.startServer(port);

	Server* gameServer = Server::getInstance();
	

	return 1;
}
