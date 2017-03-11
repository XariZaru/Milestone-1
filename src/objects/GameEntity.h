/*
 * GameEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef GAMEENTITY_H_
#define GAMEENTITY_H_

#include <iostream>
#include <deque>
#include <Windows.h>

class GameEntity {
public:

	struct Command {
		std::string command;
		unsigned int initial = 0;
		unsigned int delay = 0;
	};

	struct CommandComparator {
		bool operator() (Command* c1, Command* c2) {
			return c1->initial > c2->initial;
		}
	};

	enum EntityType {PLAYER, FOOD, GENERAL};
	enum CommandType {LEFT, RIGHT, UP, DOWN};
	virtual EntityType  getType() = 0;
	virtual std::string getName();
	virtual std::pair<int, int> getPosition();
	virtual void setPosition(std::pair<int, int>& new_position) ;
	virtual void changeX(int x_change);
	virtual void changeY(int y_change);
	virtual int  getId();
	virtual void update();
	virtual void respawn();

	void addCommand(Command* command) {
		command_queue.push_back(command);
	}

	std::deque<Command*>& getCommands() {
		return command_queue;
	}

private:
	std::string name;

protected:
	std::pair<int, int> position;
	std::deque<Command*> command_queue;
};

#endif /* GAMEENTITY_H_ */
