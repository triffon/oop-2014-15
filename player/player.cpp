/*
 * player.cpp
 *
 *  Created on: 2.04.2015 г.
 *      Author: trifon
 */

#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

#include "player.h"

Player::Player(const char* _name, int _points)
	: name(NULL), points(_points) {
	setName(_name);
}

Player::Player(Player const& p)
	: name(NULL), points(p.points) {
	setName(p.name);
}

void Player::print() const {
	cout << "Играч " << getName() << " има ";
	cout << getPoints() << " точки" << endl;
}

void Player::setName(const char* _name) {
	size_t m = min(strlen(_name) + 1, MAX);
	delete[] name;
	name = new char[m];
	strncpy(name, _name, m);
	name[m - 1] = '\0';
}




