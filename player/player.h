/*
 * player.h
 *
 *  Created on: 26.03.2015 г.
 *      Author: trifon
 */

#ifndef PLAYER_H_
#define PLAYER_H_


#include <iostream>
using namespace std;
const size_t MAX = 1501;

#include "printable.h"

class Player : virtual public Printable {
	char* name;
	int points;
public:

	// конструктор
	Player(char const* = "<анонимен>", int = 0);
	Player(Player const&);

	// селектори
	char const* getName() const { return name; }
	int getPoints() const { return points; }
	virtual void print() const;

	// мутатори
	void setName(char const*);
	void setPoints(int p) { points = p; }
	Player& operator=(Player const&);

	// деструктори
	virtual ~Player();

	friend ostream& operator<<(ostream&, Player const&);
	friend istream& operator>>(istream&, Player&);

	void prettyPrint() const;

};



#endif /* PLAYER_H_ */
