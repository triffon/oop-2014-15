/*
 * point3d.h
 *
 *  Created on: 12.03.2015 г.
 *      Author: trifon
 */

#ifndef POINT3D_H_
#define POINT3D_H_

#include <iostream>
using namespace std;
#include "point2d.cpp"

class Point3D {
	typedef Point2D<double> Point2DD;
	Point2DD p;
	double z;

public:
	// конструктори
	Point3D();
	Point3D(Point2DD, double);
	Point3D(double, double, double);

	// селектори
	double getX() const { return p.getX(); }
	double getY() const { return p.getY(); }
	double getZ() const { return z; }
	Point2DD getP() const { return p; }
	void print() const;
	double vectorLength() const;
	double distance(Point3D) const;

	// мутатори
	void setX(double _x) { p.setX(_x); }
	void setY(double _y) { p.setY(_y); }
	void setZ(double _z) { z = _z; }
	void setP(Point2DD _p) { p = _p; }
	void translate(Point3D);
	void reflect();

	friend istream& operator>>(istream&, Point3D&);
};



#endif /* POINT3D_H_ */
