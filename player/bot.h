/*
 * bot.h
 *
 *  Created on: 7.05.2015 г.
 *      Author: trifon
 */

#ifndef BOT_H_
#define BOT_H_

#include "player.h"
#include "ai.h"

class Bot : public Player, public AI {
private:
	int difficulty;
public:
	// конструктор
	Bot(char const* _name, int _points,
			char const* _algo, double _threshold,
			int _difficulty);

	// селектори
	int getDifficulty() const { return difficulty; }
	void print() const;

	// мутатори
	void setDifficulty(int newifficulty);
};




#endif /* BOT_H_ */
