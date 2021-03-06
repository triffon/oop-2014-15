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
#include "rational_point.h"

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

void testRationals() {
	// Rational r = Rational();
	Rational r = Rational(3, 4);
	// Rational r = { 3, 4 };
	r.print();
	cout << endl;
	Rational q; // q.numer = 0; q.denom = 1;
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
// !!!	Rational x();
// !!!	x.print();
	t.print();cout << endl;
	Rational z(3, 0);
}

void testConstructors() {
	Rational r1;
//	Rational r2(3);
	Rational r2 = 3; // <-> Rational r2 = Rational(3);
	Rational r3(3,4);
	r1.print();cout << endl;
	r2.print();cout << endl;
	r3.print();cout << endl;
	Rational r4 = r3;
	r4.print();cout << endl;
	add(r3, r4).print();
	add(3, r3).print();
	add(5, 5).print();
}

void testRationalPoint() {
	RationalPoint p;
	RationalPoint q = p;
	p.print();cout << endl;
	q.print();cout << endl;
}

void testArrays() {
	Rational p(1,3), q(3, 5);
	Rational a[6] = { Rational(),
			Rational(5, 7),
			p, Rational(q), 1 };
	for(int i = 0; i < 6; i++) {
		a[i].print();
		cout << endl;
	}
	Rational* r = new Rational(7);
	Rational* b = new Rational[10];
	delete r;
	delete[] b;
}

double square(double x) {
	return x * x;
}

void testOperators() {
	Rational r(5, 2);
	cout << r;
	cout << square(r);
}

int main() {
	// testRationals();
	// testConstructors();
	// testRationalPoint();
	// testArrays();
	testOperators();
}
