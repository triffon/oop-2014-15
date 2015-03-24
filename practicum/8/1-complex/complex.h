class ComplexNumber
{
    double re;
    double im;

public:
    ComplexNumber();
    ComplexNumber(double, double);
    
    double getRe() const;
    double getIm() const;

    void print() const;

    double abs() const;
    ComplexNumber conjugate() const;

    void setRe(double);
    void setIm(double);

    void add(const ComplexNumber&);
    void subtract(const ComplexNumber&);
    void multiply(const ComplexNumber&);
    void divide(const ComplexNumber&);
};

ComplexNumber sum(ComplexNumber, const ComplexNumber&);
ComplexNumber difference(ComplexNumber, const ComplexNumber&);
ComplexNumber product(ComplexNumber, const ComplexNumber&);
ComplexNumber quotient(ComplexNumber, const ComplexNumber&);

