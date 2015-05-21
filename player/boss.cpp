/*
 * boss.cpp
 *
 *  Created on: 21.05.2015 г.
 *      Author: trifon
 */

#include "boss.h"

Boss::Boss(const char* _name,
		int _pts, int _lvl, const char* _algo,
		double _threshold, int _difficulty,
		int _damage) :
		Hero(0, 0, _lvl),
		Bot(0, 0, _algo, _threshold, _difficulty),
		Player(_name, _pts),
		damage(_damage) {
}

void Boss::print() const {
	Player::print();
	printNV();
}

void Boss::printNV() const {
	Hero::printNV();
	Bot::printNV();
	cout << " Този boss взема " << damage <<
			" точки при успешна атака.";
}
