//
// Created by chris on 9/14/19.
//

#include <cmath>
#include "ComplexNumber.h"

double ComplexNumber::getReal() {
    return this->real;
}

double ComplexNumber::getImaginary() {
    return this->imaginary;
}

std::pair<double, double> ComplexNumber::getComplexNumber() {
    return std::make_pair(this->real, this->imaginary);
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber &rhs) {
    this->real = this->real + rhs.real;
    this->imaginary = this->imaginary + rhs.imaginary;
    return *this;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &rhs) const {
    return ComplexNumber(*this) += rhs;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber &rhs) {
    this->real = this->real - rhs.real;
    this->imaginary = this->imaginary - rhs.imaginary;
    return *this;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &rhs) const {
    return ComplexNumber(*this) -= rhs;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber &rhs) {
    ComplexNumber temp = ComplexNumber(*this);
    double divisor = pow(rhs.real, 2) + pow(rhs.imaginary, 2);
    this->real = temp.real * rhs.real + temp.imaginary * rhs.imaginary;
    this->imaginary = temp.imaginary * rhs.real - temp.real * rhs.imaginary;
    this->imaginary /= divisor;
    this->real /= divisor;
    return *this;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &rhs) const {
    return ComplexNumber(*this) /= rhs;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber &rhs) {
    ComplexNumber temp = ComplexNumber(*this);
    this->real = temp.real * rhs.real;
    this->imaginary = temp.real * rhs.imaginary + temp.imaginary * rhs.real;
    this->real -= temp.imaginary * rhs.imaginary;
    return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs) const {
    return ComplexNumber(*this) *= rhs;
}

int main() {
    ComplexNumber a = ComplexNumber(1,2);
    ComplexNumber b = ComplexNumber(2, 1);
    ComplexNumber c = a + b;
    a += b;
    ComplexNumber d = a * b;
    a *= b;
    ComplexNumber e = a - b;
    a -= b;
    ComplexNumber f = a / b;
    a /= b;

}