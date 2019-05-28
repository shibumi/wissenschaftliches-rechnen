//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//

#include "Newton.h"

std::vector<double> Newton::getCoefficients() {
    return m_coefficients;
}

std::function<double(double)>& Newton::getFunc() {
    return m_func;
}

auto& Newton::make_func() {
    auto f = new std::function<double(double)>([coefficients = m_coefficients](double x){
        for(auto &coefficient: coefficients){

        }
    })
}

Newton::Newton(std::vector<std::pair<double, double>> coordinates) : m_coordinates(std::move(coordinates)){
    for(auto &value: m_coordinates){
        if(value.second == m_coordinates.front().second) {
            // y0 = a0 in our newton interpolation
            m_coefficients.push_back(value.second);
        }

    }
}