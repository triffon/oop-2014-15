/*
 * main.cpp
 *
 *  Created on: 5.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;
#include "rational.h"

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
