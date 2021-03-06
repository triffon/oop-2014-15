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
						  Player(_name, _pts),
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
	cout << *this;
}

void SuperHero::setSuperPower(const char* _sp) {
	// TODO: да се сложи ограничение на дължината на superPower
	superPower = new char[strlen(_sp) + 1];
	strcpy(superPower, _sp);
}

int SuperHero::getLevel() const {
	if (usingSP) {
		// !!! return ((Hero*)this)->getLevel() + levelIncrease;
		return Hero::getLevel() + levelIncrease;
	}
	// !!! return ((Hero*)this)->getLevel();
	return Hero::getLevel();
}

ostream& operator<<(ostream& os, SuperHero const& sh) {
	return os
	   << ", но може да стане супергерой със суперсила " << sh.superPower
	   << ", която дава увеличение на нивото " << sh.levelIncrease;
}
