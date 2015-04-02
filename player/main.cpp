/*
 * main.cpp
 *
 *  Created on: 2.04.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "player.h"

void anonymousPrint(Player p) {
	p.setName("Анонимен");
	p.print();
}

int main() {
	Player p1("Гандалф Сивия", 45);
	Player p2 = p1;
//  p2.setName("Гандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф Белия");
	p2.setName("Гандалф Белия");
	p2.setPoints(50);
	p1.print();
	p2.print();
	anonymousPrint(p1);
	return 0;
}
