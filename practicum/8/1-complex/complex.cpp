#include <cmath>
#include <iostream>

#include "complex.h"

ComplexNumber::ComplexNumber(): re(0), im(0) {}
ComplexNumber::ComplexNumber(double _re, double _im):
        re(_re), im(_im) {}

double ComplexNumber::getRe() const
{
    return re;
}

double ComplexNumber::getIm() const
{
    return im;
}

void ComplexNumber::print() const
{
    std::cout << '(' << re << ", " << im << ')';
}

double ComplexNumber::abs() const
{
    return sqrt(re * re + im * im);
}

ComplexNumber ComplexNumber::conjugate() const
{
    return ComplexNumber(re, -im);
}

void ComplexNumber::setRe(double _re)
{
    re = _re;
}

void ComplexNumber::setIm(double _im)
{
    im = _im;
}

void ComplexNumber::add(const ComplexNumber& other)
{
    re += other.re;
    im += other.im;
}

void ComplexNumber::subtract(const ComplexNumber& other)
{
    re -= other.re;
    im -= other.im;
}

void ComplexNumber::multiply(const ComplexNumber& other)
{
    re = re * other.re - im * other.im;
    im = im * other.re + re * other.im;
}

void ComplexNumber::divide(const ComplexNumber& other)
{
    double other_abs = other.abs();

    re = (re * other.re + im * other.im) / other_abs;
    im = (im * other.re - re * other.im) / other_abs;
}

ComplexNumber sum(ComplexNumber c1, const ComplexNumber& c2)
{
    c1.add(c2);
    return c1;
}

ComplexNumber difference(ComplexNumber c1, const ComplexNumber& c2)
{
    c1.subtract(c2);
    return c1;
}

ComplexNumber product(ComplexNumber c1, const ComplexNumber& c2)
{
    c1.multiply(c2);
    return c1;
}

ComplexNumber quotient(ComplexNumber c1, const ComplexNumber& c2)
{
    c1.divide(c2);
    return c1;
}

