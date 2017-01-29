/*
 * Server.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef SERVER_H_
#define SERVER_H_

class Server {
public:
	Server();
	virtual ~Server();
	static Server* getInstance();

private:
	static Server* instance;
};


#endif /* SERVER_H_ */
