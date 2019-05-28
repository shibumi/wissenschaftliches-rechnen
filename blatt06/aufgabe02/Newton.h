//
// Created by chris on 5/28/19.
//

#ifndef BLATT02_NEWTON_H
#define BLATT02_NEWTON_H

#include "Interpolation.h"

class Newton : public Interpolation {
private:
    std::vector<double> m_coefficients;
    std::function<double(double)> m_func;
    auto &make_func();
public:
    Newton(std::vector<std::pair<double,double>>);
    std::vector<double> getCoefficients();
    std::function<double(double)> &getFunc();
    double evaluate(double x);
};


#endif //BLATT02_NEWTON_H
