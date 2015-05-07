/*
 * hero.cpp
 *
 *  Created on: 30.04.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "hero.h"

Hero::Hero(const char* _name, int _points, int _level) :
		Player(_name, _points), level(_level) {
}

void Hero::print() const {
	Player::print();
	cout << " и е герой от " << getLevel() << " ниво";
}

/*
Hero::Hero(Hero const& h) :
		Player(h),
		level(h.level) {

}
*/

/*
Hero& Hero::operator=(Hero const& h) {
	if (this != &h) {
		Player::operator=(h);
		//(Player&)*this = h;
		level = h.level;
	}
	return *this;
}
*/