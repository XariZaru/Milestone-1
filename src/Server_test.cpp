//============================================================================
// Name        : Milestone.cpp
// Author      : Jon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Server.h"
#include <assert.h>

Server* server;

int main() {
	server = Server::getInstance();
	assert(server != NULL);
	return 0;
}

