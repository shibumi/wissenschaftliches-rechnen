//
// Created by chris on 7/1/19.
//

#include "Vectornorm.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <numeric>

template<typename T>
double hilbertNorm(std::vector<T> v) {
    double result = 0;
    result = std::inner_product(v.begin(), v.end(), v.begin(), 0);
    return std::sqrt(result);
}

template<typename T>
double sumNorm(std::vector<T> v) {
    for(auto& element: v){
        element = abs(element);
    }
    return std::accumulate(v.begin(), v.end(), 0);
}

template<typename T>
T maxNorm(std::vector<T> v) {
    std::vector<T> w;
    w = v;
    for(auto& element: w){
        element = abs(element);
    }
    auto result = std::max_element(w.begin(), w.end());
    return v[std::distance(v.begin(), result)];
}


int main() {
    std::vector<int> v {1,2,3};
    std::cout << hilbertNorm(v) << std::endl;
    std::cout << sumNorm(v) << std::endl;
    std::cout << maxNorm(v) << std::endl;
}