//
// Created by chris on 4/17/19.
//

#ifndef BLATT01_RATIONAL_H
#define BLATT01_RATIONAL_H


class Rational {
public:
    Rational(int numerator, int denominator);
    explicit Rational(int number);
    Rational();
    int numerator();
    int denominator();
    void print();
    int gcd(int numerator, int denominator);
private:
    struct rational {
        int numerator;
        int denominator;
    } rational1;
};


#endif //BLATT01_RATIONAL_H
