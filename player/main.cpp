/*
 * main.cpp
 *
 *  Created on: 2.04.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "player.h"
#include "hero.h"
#include "superhero.h"

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

void testHero() {
	Hero gandalf("Гандалф Сивия", 45, 15);
	Player catniss("Катнис Евърдийн", 20);
	gandalf.print();cout << endl;
	catniss.print();cout << endl;
	Hero unknown;
	unknown.print();cout << endl;
	cout << gandalf.getName() << endl;
	cout << catniss.getName() << endl;
	// !!! cout << gandalf.points;
	Player gandalf2 = gandalf;
	gandalf2.setName("Гандалф Белия");
	gandalf2.print();cout << endl;
	Hero catniss2 = (Hero const&)catniss;
	catniss2.print();cout << endl;
	Hero& everdeen = (Hero&)catniss;
	everdeen.setLevel(2);
	everdeen.print();cout << endl;
	Hero gandalf3; gandalf3 = gandalf;
	gandalf3.print();cout << endl;
}

void battle(Hero& hero1, Hero& hero2, int prize) {
	cout << "Битка между:" << endl;
	hero1.print();cout << endl;
	cout << " и " << endl;
	hero2.print();cout << endl;
	if (hero1.getLevel() > hero2.getLevel()) {
		cout << "Печели " << hero1.getName() << endl;
		hero1.setPoints(hero1.getPoints() + prize);
	} else
	if (hero2.getLevel() > hero1.getLevel()) {
		cout << "Печели " << hero2.getName() << endl;
		hero2.setPoints(hero2.getPoints() + prize);
	} else {
		cout << "Няма победител!" << endl;
	}
}

void testSuperHero() {
	SuperHero superman("Супермен", 100, 13, "летене", 8);
	// superman.print();cout << endl;
	Hero gandalf("Гандалф Сивия", 45, 15);
	battle(superman, gandalf, 5);
	superman.startUsingSP();
	cout << "Ново ниво: " << superman.getLevel() << endl;
	battle(superman, gandalf, 5);

}

int main() {
	// testCopy();
	// testInputOutput();
	// testHero();
	testSuperHero();
	return 0;
}
