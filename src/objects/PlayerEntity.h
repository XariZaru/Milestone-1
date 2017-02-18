/*
 * PlayerEntity.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#ifndef PLAYERENTITY_H_
#define PLAYERENTITY_H_

#include "GameEntity.h"

#include <deque>
#include <map>

class PlayerEntity: public GameEntity {
public:

	struct Direction {
		int dx = 0, dy = 0;
	};

	struct SnakePiece {
		int x;
		int y;
		Direction head;
		Direction tail;

	};

	PlayerEntity(std::string name, int clientID);
	PlayerEntity(std::string name, std::pair<int, int> position, int clientID);
	virtual ~PlayerEntity();
	virtual int getId();
	virtual void update();
	virtual void respawn();
	void setDx(int dx);
	void setDy(int dy);
	void setScore(int value) {
		score = value;
	}
	int getScore() {
		return score;
	}

	std::deque<SnakePiece> getPieces();

	EntityType getType() {
		return EntityType::PLAYER;
	}

	std::string getName();

	int size();

	void grow();

private:
	int length, id, dx = 1, dy = 0;
	int score = 0;
	std::deque<SnakePiece> snake;
	std::string name;
};

#endif /* PLAYERENTITY_H_ */
