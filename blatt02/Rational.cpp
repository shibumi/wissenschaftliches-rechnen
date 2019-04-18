//
// Created by chris on 4/17/19.
//

#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() : rational1{1,1} {
}

Rational::Rational(int number) : rational1{number} {

}

Rational::Rational(int x, int y) : rational1{x,y} {
}

int Rational::numerator() {
    return Rational::rational1.numerator;
}

int Rational::denominator() {
    return Rational::rational1.denominator;
}

void Rational::print() {
    cout << Rational::rational1.numerator << "/" << Rational::rational1.denominator << endl;
}

int Rational::gcd(int numerator, int denominator) {
    if (denominator != 0) return gcd(denominator, numerator%denominator);
    else return numerator;
}


int main() {
    Rational rat = Rational();
    rat.print();
}