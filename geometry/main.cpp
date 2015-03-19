/*
 * main.cpp
 *
 *  Created on: 19.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "point3d.h"

int main() {
	Point3D a(1,2,3);
	Point3D c(1,3,3);
	Point3D b(4,6,15);
	cout << a.distance(c) << endl;
	cout << a.distance(b) << endl;
	return 0;
}


