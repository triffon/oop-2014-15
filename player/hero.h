/*
 * hero.h
 *
 *  Created on: 30.04.2015 г.
 *      Author: trifon
 */

#ifndef HERO_H_
#define HERO_H_

#include "player.h"

class Hero : public Player {
	int level;
public:
	// конструктор
	Hero(char const* = "<анонимен>", int = 0, int = 1);
	//Hero(Hero const&);

	//Hero& operator=(Hero const&);
	// селектори
	int getLevel() const { return level; }
	void print() const;

	// мутатори
	void setLevel(int _level) { level = _level; }
};



#endif /* HERO_H_ */
