/*
 * point3d.cpp
 *
 *  Created on: 19.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;

#include "point3d.h"

Point3D::Point3D() {
	setX(0);
	setY(0);
	setZ(0);
}

Point3D::Point3D(Point2D _p, double _z) {
	p = _p;
	z = _z;
}

Point3D::Point3D(double _x, double _y, double _z) {
/*
	p.setX(_x);
	p.setY(_y);
	z = _z;
*/
	setX(_x);
	setY(_y);
	setZ(_z);
}

void Point3D::print() const {
	cout << '(' << getX() << ',';
	cout << getY() << ',';
	cout << getZ() << ')';
	/*
	 * cout << '[';
	 * p.print();
	 * cout << ',' << getZ() << ']';
	 */
}

double Point3D::vectorLength() const {
	/*
	return sqrt(p.vectorLength()*p.vectorLength() +
				getZ() * getZ());
	*/
	return Point2D(getP().vectorLength(), getZ()).
			vectorLength();
}

double Point3D::distance(Point3D p3D) const {
	Point3D v = *this;
	v.reflect();
	p3D.translate(v);
	return p3D.vectorLength();
}

void Point3D::translate(Point3D p3D) {
	/*
	setX(getX() + p3D.getX());
	setY(getY() + p3D.getY());
	*/
	// setP(getP().translate(p3D.getP()));
	p.translate(p3D.getP());
	setZ(getZ() + p3D.getZ());
}

void Point3D::reflect() {
	/*
	setX(-getX());
	setY(-getY());
	*/
	//setP(getP().reflect());
	p.reflect();
	setZ(-getZ());
}


