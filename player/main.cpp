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
	cout << p;
}

void testSelectorLeak() {
	Player* p3 = new Player("Кетнис Евърдийн", 30);
	cout << *p3;
	char const* n = p3->getName();
	cout << n << endl;
	delete p3;
	// !!! cout << n << endl;
}

void testCopy() {
	Player p1("Гандалф Сивия", 45);
	Player p2; // = p1;
	p2 = p1;
	p1 = p1;
//  p2.setName("Гандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф БелияГандалф Белия");
	p2.setName("Гандалф Белия");
	p2.setPoints(50);
	cout << p1 << p2;
	anonymousPrint(p1);
	cout << p1 << p2;
}

void testInputOutput() {
	Player p1("Гандалф Сивия", 45);
	cout << p1;
	Player p2;
	cout << p2;
	cin >> p2;
	cout << p2;
}

int main() {
	testCopy();
	// testInputOutput();
	return 0;
}
