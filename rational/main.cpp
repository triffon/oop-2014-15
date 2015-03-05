/*
 * main.cpp
 *
 *  Created on: 5.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x, int y) {
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
		if (d == 0) {
			cout << "Опит за подаване на знаменател 0!" << endl;
			denom = 1;
		} else
			denom = d;
		if (numer != 0) {
			int g = gcd(numer, denom);
			numer /= g;
			denom /= g;
		}
		else
			denom = 1;
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

	// селектор за конвертиране към double
	double toDouble() {
		return (double)getNumerator() / getDenominator();
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

int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}

Rational sum(int x, int n) {
	Rational result;
	for(int i = 0; i <= n; i++) {
		Rational term(pow(x, i), fact(i));
		result = add(result, term);
	}
	return result;
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
	sum(1, 5).print();cout << endl;
	cout << sum(1, 5).toDouble() << endl;
	Rational s(1E9, 2E9);
	multiply(s, s).print();cout << endl;
	Rational t(0, 1000);
	t.print();cout << endl;
	return 0;
}
