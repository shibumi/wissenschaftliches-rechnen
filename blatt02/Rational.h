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
    const int numerator();
    const int denominator();
    const void print();
    int gcd(int numerator, int denominator);
    void operator+=(Rational y);
    void operator*=(Rational y);
    void operator-=(Rational y);
    void operator/=(Rational y);
    bool operator==(Rational y);
    bool operator!=(Rational y);
    bool operator<(Rational y);
    bool operator>(Rational y);
    bool operator<=(Rational y);
    bool operator>=(Rational y);
    double toDouble();
private:
    struct rational {
        int numerator;
        int denominator;
    } m_rational;
};

#endif //BLATT01_RATIONAL_H
