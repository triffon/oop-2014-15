/*
 * rational.h
 *
 *  Created on: 5.03.2015 г.
 *      Author: trifon
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational {
private:
	int numer, denom;
	int gcd(int, int);

public:
	// конструктори
	Rational();
	Rational(int, int);

	// селектори
	int getNumerator() const;
	int getDenominator() const;
	void print() const;
	double toDouble() const;

	// мутатори
	void read();
};

Rational add(Rational, Rational);
Rational subtract(Rational, Rational);
Rational multiply(Rational, Rational);
Rational divide(Rational, Rational);

#endif /* RATIONAL_H_ */
