//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//

#ifndef BLATT02_INTERPOLATION_H
#define BLATT02_INTERPOLATION_H

#include <functional>
#include <vector>

class Interpolation {
public:
    virtual std::vector<double> getCoefficients() = 0;
    virtual std::function<double(double)> &getFunc() = 0;
    virtual double evaluate(double x) = 0;
};

#endif //BLATT02_INTERPOLATION_H
