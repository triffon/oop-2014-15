/*
 * rational.cpp
 *
 *  Created on: 5.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "rational.h"

// char endl = '5';

void read() {
	int n;
	cout << "Please enter a number: ";
	cin >> n;
	cout << "Thank you!" << std::endl;
}

int Rational::gcd(int x, int y) {
	if (x <= 0 || y <= 0) {
		cout << "gcd: Грешни данни!\n";
		return 1;
	}
	while (x != y)
		if (x > y)
			x -= y;
		else
			y -= x;

	return x; // == y
}


// конструктор с параметри
Rational::Rational(int n, int d)
	: numer(n), denom(d) {
	if (denom == 0) {
		cout << "Опит за подаване на знаменател 0!" << std::endl;
		denom = 1;
	}
	if (numer != 0) {
		int g = gcd(numer, denom);
		numer /= g;
		denom /= g;
	}
	else
		denom = 1;
}

// функция за извеждане
void Rational::print() const {
	cout << getNumerator() << '/' << getDenominator();
}

// мутатор (функция за промяна) чрез въвеждане
void Rational::read() {
	// 3/4
	cin >> numer;
	cin.ignore();
	cin >> denom;
}

// селектор за конвертиране към double
double Rational::toDouble() const {
	return (double)getNumerator() / getDenominator();
}

Rational add(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator()
			        + p.getDenominator() * q.getNumerator(),
					p.getDenominator() * q.getDenominator());
}

Rational subtract(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator()
			        - p.getDenominator() * q.getNumerator(),
					p.getDenominator() * q.getDenominator());
}

Rational multiply(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getNumerator(),
					p.getDenominator() * q.getDenominator());
}

Rational divide(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator(),
					p.getDenominator() * q.getNumerator());
}


Rational::Rational(Rational const& r) :
		numer(r.numer), denom(r.denom) {
	cout << "Внимание: копираме ";
	r.print();
	cout << "!\n";
}


