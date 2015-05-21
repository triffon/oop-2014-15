/*
 * boss.h
 *
 *  Created on: 21.05.2015 г.
 *      Author: trifon
 */

#ifndef BOSS_H_
#define BOSS_H_

#include "hero.h"
#include "bot.h"

class Boss : public Hero, public Bot {
private:
	int damage;

public:
	Boss(char const* _name = "<анонимен бос>",
		 int _pts = 0,
		 int _lvl = 10,
		 char const* _algo = "<случаен>",
		 double _threshold = 1,
		 int _difficulty = 1,
		 int _damage = 5);

	void print() const;
	void printNV() const;

	int getDamage() const { return damage; }
	void setDamage(int _damage) { damage = _damage; }
};



#endif /* BOSS_H_ */
