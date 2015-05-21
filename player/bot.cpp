
/*
 * bot.cpp
 *
 *  Created on: 7.05.2015 г.
 *      Author: trifon
 */

#include "bot.h"

Bot::Bot(const char* _name, int _points, const char* _algo, double _threshold,
		int _difficulty)
	: Player(_name, _points), AI(_algo, _threshold),
	  difficulty(_difficulty) {
}

void Bot::print() const {
	Player::print();
	printNV();
}

void Bot::printNV() const {
	cout << " и е бот с ниво на трудност " << difficulty;
	cout << ", който се управлява от AI: ";
	AI::print();
}

void Bot::setDifficulty(int newDifficulty) {
	setThreshold(getThreshold() * newDifficulty / getDifficulty());
	difficulty = newDifficulty;
}
