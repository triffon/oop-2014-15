/*
 * main.cpp
 *
 *  Created on: 19.03.2015 г.
 *      Author: trifon
 */

#include <iostream>
using namespace std;
#include "point3d.h"

template <typename T>
void myswap(T& x, T& y) {
	T tmp = x; x = y; y = tmp;
}

template <typename T>
void reverse(T* a, int n) {
	for(int i = 0; i < n/2; i++)
		myswap(a[i], a[n - i - 1]);
}

template <typename T>
void readArray(T* a, int n, char const* name = "a") {
	for(int i = 0; i < n; i++) {
		cout << name << "[" << i << "] = ";
		cin >> a[i];
	}
}

void myswap(int& a, int& b) {
	cerr << "Извикваме специалната функция!" << endl;
	a += b;
	b = a - b;
	a = a - b;
}

void testPoints() {
	Point3D a(1,2,3);
	Point3D c(1,3,3);
	Point3D b(4,6,15);
	cout << a.distance(c) << endl;
	cout << a.distance(b) << endl;
}

void testTemplates() {
	int i1 = 5, i2 = 3;
	myswap<int>(i1, i2);
	double d1 = 1.2, d2 = 2.3;
	myswap(d1, d2);
	Point3D p1(1,2,3), p2(2, 3, 4);
	// !!! myswap<Point2D>(p1, p2);
	myswap(p1, p2);

	int a[50];
	char b[20] = { 0 };
	readArray(a, 3);
	readArray(b, 4, "b");
	Point3D p[10];
	readArray(p, 3, "p");
	p[0].print();
	p[1].print();
	p[2].print();
}

int main() {
	// testPoints();
	testTemplates();
	return 0;
}


