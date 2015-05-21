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
		Hero(_algo, 10, _lvl),
		Bot(_name, _pts, _algo, _threshold, _difficulty),
		damage(_damage) {
}

void Boss::print() const {
	Hero::print();
	Bot::print();
	cout << " Този boss взема " << damage <<
			" точки при успешна атака.";
}
