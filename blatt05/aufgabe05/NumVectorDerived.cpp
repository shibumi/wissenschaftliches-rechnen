//
// Created by chris on 5/18/19.
//

#include <vector>
#include <iostream>
#include <cmath>
#include <exception>

class NumVector: private std::vector<double> {
class OutOfBound: public std::exception {
    // We use the newer noexcept specifier here. throw() shouldn't be used anymore... C++11 Standard
    const char *what() const noexcept override {
        return "NumVector is out-of-bound!";
    }
};
class NotSameSize: public std::exception {
    // We use the newer noexcept specifier here. throw() shouldn't be used anymore... C++11 Standard
    const char *what() const noexcept override {
        return "Vectors don't have the same size!";
    }
};
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
        // Well we don't really need this exception, because we use at() here..
        // but just imagine we would use `return operator[](index);`
        // Then this next line would totally make sense...
        if (index < 0 || index > size()) throw OutOfBound();
        // at() is more cost intensive as `return operator[](index)` but with at() we get proper bound-checks
        // and exceptions in bad situations :)
        return at(index);
    }
    double &operator[](size_type index) {
        // Well we don't really need this exception, because we use at() here..
        // but just imagine we would use `return operator[](index);`
        // Then this next line would totally make sense...
        if (index < 0 || index > size()) throw OutOfBound();
        return at(index);
    }

    double operator*(const NumVector& rhs) {
        // We throw our custom exception when both are not equal sized
        if (size() != rhs.size()) throw NotSameSize();
        double result = 0;
        for(size_type i = 0; i < size(); i++){
            result += at(i) * rhs.at(i);
        }
        return result;
    }

};

int main() {
    // first we test if our operator* works
    NumVector v(3);
    v[0]=1; v[1]=3, v[2]=4;
    NumVector w(3);
    w[0]=1; w[1]=3, w[2]=4;
    std::cout<< v * w << std::endl; // this should return 26
    // Next we test for our new OutOfBound exception
    try {
        v[42] = 23;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Next we test for unequal scalar product
    try {
        NumVector x(4);
        std::cout<< x * w << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

