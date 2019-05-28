//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//

#ifndef BLATT02_NEWTON_H
#define BLATT02_NEWTON_H

#include "Interpolation.h"

class Newton : public Interpolation {
private:
    std::vector<std::pair<double, double>> m_coordinates;
    std::vector<double> m_coefficients;
    std::function<double(double)> m_func;
    auto &make_func();
public:
    Newton(std::vector<std::pair<double,double>>);
    std::vector<double> getCoefficients() override;
    std::function<double(double)> &getFunc() override;
    double evaluate(double x) override;
};


#endif //BLATT02_NEWTON_H
