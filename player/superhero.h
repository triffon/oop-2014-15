/*
 * superhero.h
 *
 *  Created on: 7.05.2015 г.
 *      Author: trifon
 */

#ifndef SUPERHERO_H_
#define SUPERHERO_H_

#include "hero.h"

class SuperHero : public Hero {
private:
	char* superPower;
	bool usingSP;
	int levelIncrease;

	// мутатор за лично ползване
	void setSuperPower(char const* _sp);

public:

	// конструктор по подразбиране
	// конструктори с параметри
	SuperHero(char const* _name = "<?>",
			  int _pts = 0, int _level = 1,
			  char const* _sp = "<тайна>",
			  int _linc = 1);

	SuperHero(SuperHero const&);
	SuperHero& operator=(SuperHero const&);
	~SuperHero();

	// селектори
	char const* getSuperPower() const { return superPower; }

	bool isUsingSP() const { return usingSP; }

	int getLevelIncrease() const { return levelIncrease; }

	void print() const;

	int getLevel() const;

	// мутатори
	void startUsingSP() { usingSP = true; }

	void stopUsingSP() { usingSP = false; }

	void setLevelIncrease(int _linc) { levelIncrease = _linc; }
};



#endif /* SUPERHERO_H_ */
