/*
 * player.cpp
 *
 *  Created on: 2.04.2015 г.
 *      Author: trifon
 */

#include <cstring>
#include <iostream>
using namespace std;

#include "player.h"

Player::Player(const char* _name, int _points)
	: points(_points) {
	setName(_name);
}

void Player::print() const {
	cout << "Играч " << getName() << " има ";
	cout << getPoints() << " точки" << endl;
}

void Player::setName(const char* _name) {
	strncpy(name, _name, MAX);
	name[MAX-1] = '\0';
}




