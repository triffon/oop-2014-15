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
	// cout << "Копираме Player!" << endl;
	setName(p.name);
}

void Player::print() const {
	cout << *this;
}

void Player::setName(const char* _name) {
	size_t m = min(strlen(_name) + 1, MAX);
	delete[] name;
	name = new char[m];
	strncpy(name, _name, m);
	name[m - 1] = '\0';
}

Player::~Player() {
	delete[] name;
}

ostream& operator<<(ostream& os, Player const& p) {
	return os << "Играч " << p.name << " има "
			   << p.points << " точки";
}

istream& operator>>(istream& is, Player& p) {
	// !!!! return is.getline(p.name, MAX) >> p.points;
	char buffer[MAX];
	is.getline(buffer, MAX);
	p.setName(buffer);
	return is >> p.points;
}

Player& Player::operator=(Player const& p) {
	if (&p != this) {
		setName(p.getName());
		setPoints(p.getPoints());
	}
	return *this;
}

void Player::prettyPrint() const {
	cout << "===========[ Информация за играча ]===========\n";
	print();
	cout << "\n==============================================\n";
}
