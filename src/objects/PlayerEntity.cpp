/*
 * PlayerEntity.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jon
 */

#include "PlayerEntity.h"
#include <iostream>

int length;
std::string name;

PlayerEntity::PlayerEntity(std::string str, int clientID) : id(clientID), length(5), name(str), snake(std::deque<SnakePiece>()) {
	for (int x = 5; x >= 0; x--) {
		SnakePiece piece;
		piece.x = position.first - x;
		piece.y = position.second;
		snake.push_back(piece);
	}
}

PlayerEntity::PlayerEntity(std::string str, std::pair<int, int> pos, int clientID) : id(clientID), length(5), name(str), snake(std::deque<SnakePiece>()) {
	setPosition(pos);
	for (int x = 5; x >= 0; x--) {
		SnakePiece piece;
		piece.x = position.first - x;
		piece.y = position.second;
		snake.push_back(piece);
	}
}

PlayerEntity::~PlayerEntity() {
	// TODO Auto-generated destructor stub
}

int PlayerEntity::getId()
{
	return id;
}

void PlayerEntity::update()
{
	// Check queue and if delay has passed then execute dx or dy changes
	SYSTEMTIME elapsed;
	GetSystemTime(&elapsed);

	/*
	if (!current_command || elapsed.wSecond - current_command->initial >= current_command->delay)
	{

		if (current_command)
		{
			std::string command = current_command->command;

			if (command == "left") {
				setDx(-1);
			}
			else if (command == "right") {
				setDx(1);
			}
			else if (command == "up") {
				setDy(-1);
			}
			else if (command == "down") {
				setDy(1);
			}
			long time_elapsed = elapsed.wMilliseconds - current_command->initial;
			std::ostringstream oss;
			oss << "ACK " << time_elapsed;
			delete current_command;
			current_command = nullptr;
		} else if (command_queue.size() > 0) {
			current_command = command_queue.at(0);
			command_queue.pop_front();
		}
	}
	*/

	changeX(dx);
	changeY(dy);

	for (int x = 0; x < snake.size(); x++) {
		SnakePiece& piece = snake.at(x);
		piece.previous_coordinate = std::make_pair(piece.x, piece.y);
		if (x != 0) { // Not first piece
			piece.x = snake.at(x - 1).previous_coordinate.first;
			piece.y = snake.at(x - 1).previous_coordinate.second;
		}
		else { // First piece
			piece.x = position.first;
			piece.y = position.second;
		}
	}
}

void PlayerEntity::respawn()
{
	dx = 1;
	dy = 0;
	snake = std::deque<SnakePiece>();
	for (int x = 5; x >= 0; x--) {
		SnakePiece piece;
		piece.x = position.first - x;
		piece.y = position.second;
		snake.push_back(piece);
	}
	score = 0;
}

void PlayerEntity::setDx(int pdx)
{
	// Want to change right but going left
	if (dx == 0) {
		dx = pdx;
		dy = 0;
	}
}

void PlayerEntity::setDy(int pdy)
{
	if (dy == 0) {
		dy = pdy;
		dx = 0;
	}
}

std::deque<PlayerEntity::SnakePiece> PlayerEntity::getPieces()
{
	return snake;
}

std::string PlayerEntity::getName()
{
	return name;
}

int PlayerEntity::size() {
	return length;
}

void PlayerEntity::grow() {
	SnakePiece piece;
	piece.x = snake.at(snake.size() - 1).x - dx;
	piece.y = snake.at(snake.size() - 1).y - dy;
	snake.push_back(piece);
	score++;
}
