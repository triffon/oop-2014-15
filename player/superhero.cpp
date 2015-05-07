/*
 * superhero.cpp
 *
 *  Created on: 7.05.2015 г.
 *      Author: trifon
 */

#include <cstring>
#include "superhero.h"

SuperHero::SuperHero(const char* _name, int _pts, int _level,
					 const char* _sp, int _linc)
						: Hero(_name, _pts, _level),
						  levelIncrease(_linc),
						  usingSP(false) {
	setSuperPower(_sp);
}

SuperHero::SuperHero(const SuperHero& sh)
		: Hero(sh), levelIncrease(sh.levelIncrease),
		  usingSP(sh.usingSP) {
	setSuperPower(sh.superPower);
}

SuperHero& SuperHero::operator=(const SuperHero& sh) {
	if (this != &sh) {
		levelIncrease = sh.levelIncrease;
		usingSP = sh.usingSP;
		delete[] superPower;
		setSuperPower(sh.superPower);
	}
	return *this;
}

SuperHero::~SuperHero() {
	delete[] superPower;
}

void SuperHero::print() const {
	Hero::print();
	cout << ", но може да стане супергерой със суперсила " << superPower;
	cout << ", която дава увеличение на нивото " << levelIncrease;
}

void SuperHero::setSuperPower(const char* _sp) {
	// TODO: да се сложи ограничение на дължината на superPower
	superPower = new char[strlen(_sp) + 1];
	strcpy(superPower, _sp);
}

int SuperHero::getLevel() const {
	if (usingSP) {
		return Hero::getLevel() + levelIncrease;
	}
	return Hero::getLevel();
}
