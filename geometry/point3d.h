/*
 * point3d.h
 *
 *  Created on: 12.03.2015 г.
 *      Author: trifon
 */

#ifndef POINT3D_H_
#define POINT3D_H_

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

	// мутатори
};



#endif /* POINT3D_H_ */
