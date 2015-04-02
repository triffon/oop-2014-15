/*
 * rational_point.h
 *
 *  Created on: 2.04.2015 г.
 *      Author: trifon
 */

#ifndef RATIONAL_POINT_H_
#define RATIONAL_POINT_H_

#include "rational.h"

class RationalPoint {
	Rational x, y;
public:
	RationalPoint() : y(2), x(1) {
		// x = 1; // <-> x = Rational(1);
		// y = 1; // <-> y = Rational(1);
	}
	RationalPoint(RationalPoint const& p)
		: x(p.x), y(p.y) {
		// късно!
		// x = p.x;
		// y = p.y;
	}
	void print() const {
		cout << '(';
		x.print();
		cout << ',';
		y.print();
		cout << ')';
	}
};



#endif /* RATIONAL_POINT_H_ */
