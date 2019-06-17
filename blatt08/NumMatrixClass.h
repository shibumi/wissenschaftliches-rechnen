//
// Created by chris on 6/17/19.
//

#ifndef BLATT02_NUMMATRIXCLASS_H
#define BLATT02_NUMMATRIXCLASS_H

#include "MatrixClass.h"

template <typename T, typename U = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class NumMatrixClass: public MatrixClass<T> {
    using MatrixClass<T>::MatrixClass;
public:
    // Arithmetic functions
    NumMatrixClass<T> &operator*=(T x);
    NumMatrixClass<T> &operator+=(const NumMatrixClass<T> &x);
};

// More arithmetic functions
template <typename T, typename U>
NumMatrixClass<T> operator*(const NumMatrixClass<T> &a, T x);

template <typename T, typename U>
NumMatrixClass<T> operator*(T x, const NumMatrixClass<T> &a);

template <typename T, typename U>
NumMatrixClass<T> operator+(const NumMatrixClass<T> &a, const NumMatrixClass<T> &b);

// Arithmetic functions
// Multiplication by value x
template <typename T, typename U>
NumMatrixClass<T> &NumMatrixClass<T, U>::operator*=(T x) {
    for (size_t i = 0; i < MatrixClass<T>::numRows_ * MatrixClass<T>::numCols_; ++i)
        MatrixClass<T>::a_[i] *= x;

    return *this;
}

// Addition
template <typename T, typename U>
NumMatrixClass<T> &NumMatrixClass<T, U>::operator+=(const NumMatrixClass<T> &x) {
    if ((x.numRows_ != MatrixClass<T>::numRows_) || (x.numCols_ != MatrixClass<T>::numCols_)) throw DimensionMismatch(MatrixClass<T>::numRows_, MatrixClass<T>::numCols_, x.numRows_, x.numCols_);
    for (size_t i = 0; i < MatrixClass<T>::numRows_ * MatrixClass<T>::numCols_; ++i)
        MatrixClass<T>::a_[i] += x.a_[i];
    return *this;
}


// More arithmetic functions
template <typename T>
NumMatrixClass<T> operator*(const NumMatrixClass<T> &a, T x) {
    NumMatrixClass<T> temp(a);
    temp *= x;
    return temp;
}

template <typename T>
NumMatrixClass<T> operator*(T x, const NumMatrixClass<T> &a) {
    NumMatrixClass<T> temp(a);
    temp *= x;
    return temp;
}

// Concatenate
template <typename T>
NumMatrixClass<T> operator+(const NumMatrixClass<T> &a, const NumMatrixClass<T> &b) {
    NumMatrixClass<T> temp(a);
    temp += b;
    return temp;
}

#endif //BLATT02_NUMMATRIXCLASS_H
