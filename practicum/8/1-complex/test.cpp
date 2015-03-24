#include <iostream>

#include "complex.h"

using namespace std;

void input(ComplexNumber& c)
{
    int re, im;
    cout << "-- Input of a complex number --" << endl;
    cout << "Enter real part: " << endl;
    cin >> re;
    cout << "Enter imaginary part: " << endl;
    cin >> im;

    c.setRe(re);
    c.setIm(im);

    cout << "You enter the complex number with:" << endl;
    cout << "    real part: " << c.getRe() << endl;
    cout << "    imaginary part: " << c.getIm() << endl;
}

int main()
{
    ComplexNumber c;

    cout << "This is the default complex number: ";
    c.print();
    cout << endl;

    cout << "This is an example complex number: ";
    ComplexNumber(1, 2).print();
    cout << endl;

    input(c);

    cout << "Absolute value: " << c.abs() << endl;
    cout << "Conjugate number: ";
    c.conjugate().print();
    cout << endl;

    ComplexNumber c1;
    input(c1);

    cout << "Sum of the two complex numbers: ";
    sum(c, c1).print();
    cout << endl;

    cout << "Difference of the two complex numbers: ";
    difference(c, c1).print();
    cout << endl;

    cout << "Product of the two complex numbers: ";
    product(c, c1).print();
    cout << endl;

    cout << "Quotient of the two complex numbers: ";
    quotient(c, c1).print();
    cout << endl;

    return 0;
}

