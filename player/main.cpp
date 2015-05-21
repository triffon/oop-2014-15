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
#include "bot.h"
#include "boss.h"

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
//	p1 = p1;
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
	/* !!!
	Hero catniss2 = (Hero const&)catniss;
	catniss2.print();cout << endl;
	Hero& everdeen = (Hero&)catniss;
	everdeen.setLevel(2);
	everdeen.print();cout << endl;
	!!! */
	Hero gandalf3; gandalf3 = gandalf;
	gandalf3.print();cout << endl;
}

Player* determineWinner(Hero& hero1, Hero& hero2) {
	if (hero1.getLevel() > hero2.getLevel())
		return &hero1;
	else
	if (hero2.getLevel() > hero1.getLevel())
		return &hero2;
	else
		return NULL;
}

void battle(Hero& hero1, Hero& hero2, int prize) {
	cout << "Битка между:" << endl;
	hero1.prettyPrint();cout << endl;
	cout << " и " << endl;
	hero2.prettyPrint();cout << endl;
	Player* winner = determineWinner(hero1, hero2);
	if (winner != NULL) {
		cout << "Печели " << winner->getName() << endl;
		winner->setPoints(winner->getPoints() + prize);
	} else
		cout << "Няма победител!" << endl;
}

void testSuperHero() {
	SuperHero superman("Супермен", 100, 13, "летене", 8);
	// superman.print();cout << "\n-----------\n";
	Player* p = &superman;
	// p->Player::print();cout << endl;
	p->print(); cout << endl;
	Hero gandalf("Гандалф Сивия", 45, 15);
	battle(superman, gandalf, 5);
	superman.startUsingSP();
	cout << "Ново ниво: " << superman.getLevel() << endl;
	battle(gandalf, superman, 5);
}

void testBot() {
	Bot b("Deep Thought", 100, "minimax", 0.15, 3);
	b.print();cout << endl;
	b.setDifficulty(5);
	b.print();cout << endl;
}

void testBoss() {
	Boss b("Саурон", 200, 50, "тъмни сили", 5.8, 10, 100);
	b.print();cout << endl;
	cout << "Име: " << b.getName() << endl;

	Hero gandalf("Гандалф Сивия", 45, 15);
	gandalf.print();cout << endl;

	Bot dt("Deep Thought", 100, "minimax", 0.15, 3);
	dt.print();cout << endl;
}

int main() {
	// testCopy();
	// testInputOutput();
	// testHero();
	testSuperHero();
	// testBot();
	// testBoss();
	return 0;
}
