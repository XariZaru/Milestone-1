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
		piece.head.dx = dx;
		piece.tail.dx = dx;
		snake.push_front(piece);
	}
}

PlayerEntity::PlayerEntity(std::string str, std::pair<int, int> pos, int clientID) : id(clientID), length(5), name(str), snake(std::deque<SnakePiece>()) {
	setPosition(pos);
	for (int x = 5; x >= 0; x--) {
		SnakePiece piece;
		piece.x = position.first - x;
		piece.y = position.second;
		piece.head.dx = dx;
		piece.tail.dx = dx;
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

	for (int x = 0; x < snake.size(); x++) {
		SnakePiece& piece = snake.at(x);
		piece.x += piece.head.dx;
		piece.y += piece.head.dy;
		if (x != 0) {
			SnakePiece& prev_piece = snake.at(x - 1);
			prev_piece.tail.dx = prev_piece.head.dx;
			prev_piece.tail.dy = prev_piece.head.dy;
			piece.head.dx = prev_piece.tail.dx;
			piece.head.dy = prev_piece.tail.dy;
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
		piece.head.dx = 1;
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
		snake.at(0).head.dx = pdx;
		snake.at(0).head.dy = 0;
	}
}

void PlayerEntity::setDy(int pdy)
{
	if (dy == 0) {
		dy = pdy;
		dx = 0;
		snake.at(0).head.dy = pdy;
		snake.at(0).head.dx = 0;
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
	piece.head.dx = snake.at(0).tail.dx;
	piece.head.dy = snake.at(0).tail.dy;
	snake.push_front(piece);
	score++;
}
