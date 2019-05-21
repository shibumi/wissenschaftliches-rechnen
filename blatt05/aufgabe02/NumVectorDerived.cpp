//
// Created by chris on 5/18/19.
//

#include <vector>
#include <iostream>
#include <cmath>

class NumVector: private std::vector<double> {
public:
    // We use size_type instead of int here, because it's platform independent
    explicit NumVector(size_type size) : vector(size) {}

    double norm() const {
        // make sure result is empty
        double result = 0;
        for(const double &value: *this){
            result += value*value;
        }
        return sqrt(result);
    }

    // We need both. A const operator and a non-const operator.
    const double &operator[](size_type index) const {
        // at() is more cost intensive as `return operator[](index)` but with at() we get proper bound-checks
        // and exceptions in bad situations :)
        return at(index);
    }
    double &operator[](size_type index) {
        return at(index);
    }
};

