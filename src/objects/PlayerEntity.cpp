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
		snake.push_front(piece);
	}
}

PlayerEntity::PlayerEntity(std::string str, std::pair<int, int> pos, int clientID) : id(clientID), length(5), name(str), snake(std::deque<SnakePiece>()) {
	setPosition(pos);
	for (int x = 5; x >= 0; x--) {
		SnakePiece piece;
		piece.x = position.first - x;
		piece.y = position.second;
		snake.push_front(piece);
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
	changeX(dx);
	changeY(dy);

	for (SnakePiece& piece : snake) {
		piece.x += dx;
		piece.y += dy;
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
		snake.push_front(piece);
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
	length++;
	SnakePiece piece;
	piece.x = snake.at(0).x - dx;
	piece.y = snake.at(0).y - dy;
	snake.push_front(piece);
	score++;
}
