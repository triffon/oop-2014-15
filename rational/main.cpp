/*
 * main.cpp
 *
 *  Created on: 5.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

// физическо представяне
struct Rational {
	int numer, denom;

	// конструктор по подразбиране
	Rational() {
		numer = 0;
		denom = 1;
	}

	// конструктор с параметри
	Rational(int n, int d) {
		numer = n;
		denom = d;
	}

	// селектор за числител
	int getNumerator() {
		return numer;
	}

	// селектор за знаменател
	int getDenominator() {
		return denom;
	}

	// функция за извеждане
	void print() {
		cout << getNumerator() << '/' << getDenominator();
	}

	// мутатор (функция за промяна) чрез въвеждане
	void read() {
		// 3/4
		cin >> numer;
		cin.ignore();
		cin >> denom;
	}
};

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

int main() {
	// Rational r = Rational();
	Rational r = Rational(3, 4);
	// Rational r = { 3, 4 };
	r.print();
	cout << endl;
	Rational q;
	q.read();
	q.print();
	cout << endl;
	Rational p = add(r, q);
	r.print();cout << " + ";q.print();cout << " = ";
	p.print();cout << endl;
	multiply(r, q).print();cout << endl;
	divide(r, q).print();cout << endl;
	return 0;
}
