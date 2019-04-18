//
// Created by chris on 4/17/19.
//

#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() : m_rational{1,1} {
}

Rational::Rational(int number) : m_rational{number,1} {

}

Rational::Rational(int x, int y) : m_rational{x,y} {
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
    if (denominator != 0) return gcd(denominator, numerator%denominator);
    else return numerator;
}

bool Rational::operator==(const Rational y) {
    return m_rational.numerator == y.m_rational.denominator && m_rational.denominator == y.m_rational.denominator;
}

void Rational::operator+=(const Rational y) {
    m_rational.numerator = (m_rational.numerator * y.m_rational.denominator) + (y.m_rational.numerator * m_rational.denominator);
    m_rational.denominator *= y.m_rational.denominator;
}

void Rational::operator*=(const Rational y) {
    m_rational.numerator *= y.m_rational.numerator;
    m_rational.denominator *= y.m_rational.denominator;
}

void Rational::operator-=(const Rational y) {
    m_rational.numerator = (m_rational.numerator * y.m_rational.denominator) - (y.m_rational.numerator * m_rational.denominator);
    m_rational.denominator *= y.m_rational.denominator;
}

void Rational::operator/=(const Rational y) {
    m_rational.numerator *= y.m_rational.denominator;
    m_rational.denominator *= y.m_rational.numerator;
}




int main() {
    Rational rat = Rational(6,7);
    rat.print();
    Rational rat2 = Rational(3,4);
    rat2.print();
    rat /= rat2;
    rat.print();
}