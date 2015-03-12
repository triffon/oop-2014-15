/*
 * point2d.h
 *
 *  Created on: 12.03.2015 г.
 *      Author: trifon
 */

#ifndef POINT2D_H_
#define POINT2D_H_

class Point2D {
	double x, y;

public:

	// конструктори
	Point2D() { x = y = 0; }
	Point2D(double, double);

	// селектори
	double getX() const { return x; }
	double getY() const { return y; }
	void print() const;
	double vectorLength() const;
	double distance(Point2D) const;
	// a.distance(b);
	// distance(a, b); - ако е външна функция

	// мутатори
	void setX(double _x) { x = _x; }
	void setY(double _y) { y = _y; }
	void translate(Point2D);
	// a.translate(b);
	// премести точката a с вектор, който е
	// определен от точката b
	void reflect();
};



#endif /* POINT2D_H_ */
