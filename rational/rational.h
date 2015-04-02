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

	// конструктор по подразбиране
	// и конструктор с 1 параметър
	// и конструктор с 2 параметъра;
	Rational(int = 0, int = 1);

	// конструктор за копиране
	Rational(Rational const&);

	// селектори
	int getNumerator() const { return numer; }
	int getDenominator() const { return denom; }
	void print() const;
	double toDouble() const;

	// мутатори
	void read();

	// безсмислен деструктор
	~Rational();
};

Rational add(Rational, Rational);
Rational subtract(Rational, Rational);
Rational multiply(Rational, Rational);
Rational divide(Rational, Rational);

#endif /* RATIONAL_H_ */
