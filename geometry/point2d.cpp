/*
 * point2d.cpp
 *
 *  Created on: 12.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "point2d.h"

Point2D::Point2D(double _x, double _y) {
	x = _x;
	y = _y;
}

void Point2D::print() const {
	cout << '(' << x << ", " << y << endl;
}

double Point2D::vectorLength() const {
	return sqrt(x*x + y*y);
}

double Point2D::distance(Point2D p) const {
	/*
	return sqrt((x-p.x)*(x-p.x) +
				(y-p.y)*(y-p.y));
	*/
	/*
	return sqrt((getX()-p.getX())*(getX()-p.getX()) +
				(getY()-p.getY())*(getY()-p.getY()));
	*/
	Point2D v = *this;
	v.reflect();
	p.translate(v);
	return p.vectorLength();
}

void Point2D::translate(Point2D p) {
	/*
	x += p.x;
	y += p.y;
	*/
	setX(getX() + p.getX());
	setY(getY() + p.getY());
}

void Point2D::reflect() {
	/*
	x = -x;
	y = -y;
	*/
	setX(-getX());
	setY(-getY());
}


