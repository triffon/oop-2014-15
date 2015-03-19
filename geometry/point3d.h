/*
 * point3d.h
 *
 *  Created on: 12.03.2015 г.
 *      Author: trifon
 */

#ifndef POINT3D_H_
#define POINT3D_H_

#include "point2d.h"

class Point3D {
	Point2D p;
	double z;

public:
	// конструктори
	Point3D();
	Point3D(Point2D, double);
	Point3D(double, double, double);

	// селектори
	double getX() const { return p.getX(); }
	double getY() const { return p.getY(); }
	double getZ() const { return z; }
	Point2D getP() const { return p; }
	void print() const;
	double vectorLength() const;
	double distance(Point3D) const;

	// мутатори
	void setX(double _x) { p.setX(_x); }
	void setY(double _y) { p.setY(_y); }
	void setZ(double _z) { z = _z; }
	void setP(Point2D _p) { p = _p; }
	void translate(Point3D);
	void reflect();
};



#endif /* POINT3D_H_ */
