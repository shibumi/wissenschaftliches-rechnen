//
// Created by chris on 4/17/19.
//

#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() : m_rational{1, 1} {
}

Rational::Rational(int number) : m_rational{number, 1} {

}

Rational::Rational(int x, int y) : m_rational{x, y} {
}

const int Rational::numerator() {
    return m_rational.numerator;
}

const int Rational::denominator() {
    return m_rational.denominator;
}

const void Rational::print() {
    int divisor = gcd(m_rational.numerator, m_rational.denominator);
    cout << m_rational.numerator << "/" << Rational::m_rational.denominator;
    cout << " = " << m_rational.numerator / divisor << "/" << m_rational.denominator / divisor << endl;
}

int Rational::gcd(int numerator, int denominator) {
    if (denominator != 0) return gcd(denominator, numerator % denominator);
    else return numerator;
}

bool Rational::operator==(const Rational y) {
    //TODO respect cases like 1/1 == 5/5
    int y_divisor = gcd(y.m_rational.numerator, y.m_rational.denominator);
    int divisor = gcd(m_rational.numerator, m_rational.denominator);
    return m_rational.numerator / divisor == y.m_rational.numerator / y_divisor &&
           m_rational.denominator / divisor == y.m_rational.denominator / y_divisor;
}

void Rational::operator+=(const Rational y) {
    m_rational.numerator =
            (m_rational.numerator * y.m_rational.denominator) + (y.m_rational.numerator * m_rational.denominator);
    m_rational.denominator *= y.m_rational.denominator;
}

void Rational::operator*=(const Rational y) {
    m_rational.numerator *= y.m_rational.numerator;
    m_rational.denominator *= y.m_rational.denominator;
}

void Rational::operator-=(const Rational y) {
    m_rational.numerator =
            (m_rational.numerator * y.m_rational.denominator) - (y.m_rational.numerator * m_rational.denominator);
    m_rational.denominator *= y.m_rational.denominator;
}

void Rational::operator/=(const Rational y) {
    m_rational.numerator *= y.m_rational.denominator;
    m_rational.denominator *= y.m_rational.numerator;
}

Rational operator+(const Rational x, const Rational y) {
    Rational tmp = Rational(x);
    tmp += y;
    return tmp;
}

Rational operator-(const Rational x, const Rational y) {
    Rational tmp = Rational(x);
    tmp -= y;
    return tmp;
}

Rational operator*(const Rational x, const Rational y) {
    Rational tmp = Rational(x);
    tmp *= y;
    return tmp;
}

Rational operator/(const Rational x, const Rational y) {
    Rational tmp = Rational(x);
    tmp /= y;
    return tmp;
}

void testRational() {
    Rational f1 = Rational(-3, 12);
    Rational f2 = Rational(4, 3);
    Rational f3 = Rational(13, 12);
    Rational f4 = Rational(-1, 3);
    Rational f5 = Rational(16, 3);
    Rational f6 = Rational(19, 3);
    Rational f7 = Rational(-3, 1);
    Rational f8 = Rational(-3, 2);
    Rational f9 = Rational(-3, 16);
    if (f3 == (f1 + f2)) cout << "test passed: f3 = f1 + f2" << endl;
    else cout << "test failed: f3 = f1 + f2" << endl;
    if (f3 == f1 * f2) cout << "test passed: f3 = f1 * f2" << endl;
    else cout << "test failed: f3 = f1 * f2" << endl;

}


int main() {
    testRational();
}