//
// Created by chris on 4/17/19.
//

#include "Rational.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Rational::Rational() : m_rational{1, 1} {
}

Rational::Rational(int number) : m_rational{number, 1} {
}

// Custom Constructor for two arguments.
// We make sure to avoid division by zero.
Rational::Rational(int x, int y) : m_rational{x, y} {
    if (m_rational.denominator == 0) {
        cout << "Error: 0 as denominator is not allowed!" << endl;
        exit(EXIT_FAILURE);
    }
}

// getter method for numerator.
// We don't really use this, because I prefer asking for the constant value of the members as guardian for the functions
const int Rational::numerator() {
    return m_rational.numerator;
}

// getter method for denominator.
// We don't really use this, because I prefer asking for the constant value of the members as guardian for the functions
const int Rational::denominator() {
    return m_rational.denominator;
}

// Pretty print method for Rational Class.
// This will print the shortened form as well.
const void Rational::print() {
    int divisor = gcd(m_rational.numerator, m_rational.denominator);
    cout << m_rational.numerator << "/" << Rational::m_rational.denominator;
    cout << " = " << m_rational.numerator / divisor << "/" << m_rational.denominator / divisor << endl;
}

// Greatest Common Divisor method with recursion.
int Rational::gcd(int numerator, int denominator) {
    if (denominator != 0) return gcd(denominator, numerator % denominator);
    else return numerator;
}

bool Rational::operator==(const Rational y) {
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

bool Rational::operator!=(Rational y) {
    if (*this == y) return false;
    else return true;
}

bool Rational::operator<(const Rational y) {
    if (m_rational.denominator * y.m_rational.numerator > 0) {
        return (m_rational.numerator * y.m_rational.denominator < y.m_rational.numerator * m_rational.denominator);
    } else return (m_rational.numerator * y.m_rational.denominator > y.m_rational.numerator * m_rational.denominator);
}

bool Rational::operator>(const Rational y) {
    if (m_rational.denominator * y.m_rational.numerator > 0) {
        return (m_rational.numerator * y.m_rational.denominator > y.m_rational.numerator * m_rational.denominator);
    } else return (m_rational.numerator * y.m_rational.denominator < y.m_rational.numerator * m_rational.denominator);
}

bool Rational::operator<=(const Rational y) {
    if (*this == y) return true;
    return *this < y;
}

bool Rational::operator>=(const Rational y) {
    if (*this == y) return true;
    return *this > y;
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

// testRational method for testing tasks 6, 7 and 8
void testRational() {
    // tests for task 6
    cout << "starting tests.. printing numbers" << endl;
    cout << "---------------------------------" << endl;
    Rational f1 = Rational(-3, 12);
    cout << "f1: ";
    f1.print();
    Rational f2 = Rational(4, 3);
    cout << "f2: ";
    f2.print();
    Rational f3 = Rational(13, 12);
    cout << "f3: ";
    f3.print();
    Rational f4 = Rational(-1, 3);
    cout << "f4: ";
    f4.print();
    Rational f5 = Rational(16, 3);
    cout << "f5: ";
    f5.print();
    Rational f6 = Rational(19, 3);
    cout << "f6: ";
    f6.print();
    Rational f7 = Rational(-3, 1);
    cout << "f7: ";
    f7.print();
    Rational f8 = Rational(-3, 2);
    cout << "f8: ";
    f8.print();
    Rational f9 = Rational(-3, 16);
    cout << "f9: ";
    f9.print();
    Rational four = Rational(4);
    Rational five = Rational(5);
    Rational six = Rational(6);
    Rational twelve = Rational(12);
    Rational result = f1 + f2;
    if (result == f3) cout << "test passed: f3 = f1 + f2" << endl;
    else cout << "test failed: f3 = f1 + f2" << endl;
    result = f1 * f2;
    if (result == f4) cout << "test passed: f3 = f1 * f2" << endl;
    else cout << "test failed: f3 = f1 * f2" << endl;
    result = four + f2;
    if (result == f5) cout << "test passed: f3 = 4 + f2" << endl;
    else cout << "test failed: f3 = 4 + f2" << endl;
    result = f2 + five;
    if (result == f6) cout << "test passed: f3 = f2 + 5" << endl;
    else cout << "test failed: f3 = f2 + 5" << endl;
    result = twelve * f1;
    if (result == f7) cout << "test passed: f3 = 12 * f1" << endl;
    else cout << "test failed: f3 = 12 * f1" << endl;
    result = f1 * six;
    if (result == f8) cout << "test passed: f3 = f1 * 6" << endl;
    else cout << "test failed: f3 = f1 * 6" << endl;
    result = f1 / f2;
    if (result == f9) cout << "test passed: f3 = f1 / f2" << endl;
    else cout << "test failed: f3 = f1 / f2" << endl;
    // tests for task 7
    cout << endl;
    cout << "starting tests.. printing numbers" << endl;
    cout << "---------------------------------" << endl;
    Rational f10 = Rational(3, 12);
    cout << "f10: ";
    f10.print();
    Rational f11 = Rational(1, 4);
    cout << "f11: ";
    f11.print();
    if (f10 == f11) cout << "test passed: f10 == f11" << endl;
    else cout << "test failed: f10 == f11" << endl;
    if (f10 >= f11) cout << "test passed: f10 <= f11" << endl;
    else cout << "test failed: f10 >= f11" << endl;
    if (f10 <= f11) cout << "test passed: f10 <= f11" << endl;
    else cout << "test failed: f10 <=f11" << endl;
    if (!(f10 > f11)) cout << "test passed: NOT f10 > f11" << endl;
    else cout << "test failed: NOT f10 > f11" << endl;
    if (!(f10 < f11)) cout << "test passed: NOT f10 < f11" << endl;
    else cout << "test failed: NOT f10 < f11" << endl;
    // tests for toDouble()
    cout << endl;
    cout << "starting tests.. printing numbers" << endl;
    cout << "---------------------------------" << endl;
    Rational f12 = Rational(1, 8);
    cout << "f12: ";
    f10.print();
    if (f12.toDouble() == 0.125) cout << "test passed: f12 to Double is " << f12.toDouble() << endl;
    else cout << "test failed: f12 to Double is not " << 0.125 << " we got: " << f12.toDouble() << endl;
}

// Double convert method
double Rational::toDouble() {
    return double(m_rational.numerator) / double(m_rational.denominator);
}


int main() {
    testRational();

}