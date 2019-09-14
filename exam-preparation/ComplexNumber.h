//
// Created by chris on 9/14/19.
//

#ifndef BLATT02_COMPLEXNUMBER_H
#define BLATT02_COMPLEXNUMBER_H


#include <utility>

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber() : real(0.0), imaginary(0.0) {};
    ComplexNumber(double x, double y) : real(x), imaginary(y) {};
    ComplexNumber operator+(const ComplexNumber &rhs) const;
    ComplexNumber operator-(const ComplexNumber &rhs) const;
    ComplexNumber operator*(const ComplexNumber &rhs) const;
    ComplexNumber operator/(const ComplexNumber &rhs) const;
    ComplexNumber& operator+=(const ComplexNumber& rhs);
    ComplexNumber& operator-=(const ComplexNumber& rhs);
    ComplexNumber& operator*=(const ComplexNumber& rhs);
    ComplexNumber& operator/=(const ComplexNumber& rhs);
    double getReal();
    double getImaginary();
    std::pair<double, double> getComplexNumber();
};


#endif //BLATT02_COMPLEXNUMBER_H
