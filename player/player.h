/*
 * player.h
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#ifndef PLAYER_H_
#define PLAYER_H_

int const MAX = 51;

class Player {
	char name[MAX];
	int points;
public:

	// конструктор
	Player(char const* = "", int = 0);

	// селектори
	char const* getName() const { return name; }
	int getPoints() const { return points; }
	void print() const;

	// мутатори
	void setName(char const*);
	void setPoints(int p) { points = p; }

};



#endif /* PLAYER_H_ */
