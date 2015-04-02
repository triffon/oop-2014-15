/*
 * player.h
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#ifndef PLAYER_H_
#define PLAYER_H_

const size_t MAX = 1501;

class Player {
	char* name;
	int points;
public:

	// конструктор
	Player(char const* = "", int = 0);
	Player(Player const&);

	// селектори
	char const* getName() const { return name; }
	int getPoints() const { return points; }
	void print() const;

	// мутатори
	void setName(char const*);
	void setPoints(int p) { points = p; }

	// деструктори
	~Player();

};



#endif /* PLAYER_H_ */
