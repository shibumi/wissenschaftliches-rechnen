#include "matrix_double.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

// Set number of matrix rows and columns and 
// initialize matrix elements with a given T value
template<typename T>
void MatrixClass<T>::resize(size_t numRows, size_t numCols, const T &value) {
    if ((numRows_ + numCols_ > 0) && (numRows_ * numCols_ == 0)) {
        numRows_ = 0;
        numCols_ = 0;
    }
    a_.release();
    a_ = std::unique_ptr<T[]>(new T[numRows_ * numCols_]);
    for (size_t i = 0; i < size_; ++i)
        a_[i] = value;
    numRows_ = numRows;
    numCols_ = numCols;
}

// Access matrix element at position (i,j)
template<typename T>
T &MatrixClass<T>::operator()(size_t i, size_t j) {
    if ((i < 0) || (i >= numRows_)) {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is (0:" << numRows_ - 1 << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if ((j < 0) || (j >= numCols_)) {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is (0:" << numCols_ - 1 << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return a_[i * numCols_ + j];
}

// Access matrix element at position (i,j)
template<typename T>
T MatrixClass<T>::operator()(size_t i, size_t j) const {
    if ((i < 0) || (i >= numRows_)) {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is (0:" << numRows_ - 1 << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if ((j < 0) || (j >= numCols_)) {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is (0:" << numCols_ - 1 << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return a_[i * numCols_ + j];
}

// Output matrix content
template<typename T>
void MatrixClass<T>::print() const {
    std::cout << "(" << numRows_ << "x";
    std::cout << numCols_ << ") matrix:" << std::endl;
    for (size_t i = 0; i < numRows_; ++i) {
        std::cout << std::setprecision(3);
        for (size_t j = 0; j < numCols_; ++j)
            std::cout << std::setw(5) << a_[i * numCols_ + j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Arithmetic functions 

// Multiplication by value x
template<typename T>
MatrixClass<T> &MatrixClass<T>::operator*=(T x) {
    for (size_t i = 0; i < size_; ++i)
        a_[i] *= x;

    return *this;
}

// Addition
template<typename T>
MatrixClass<T> &MatrixClass<T>::operator+=(const MatrixClass<T> &x) {
    if ((x.numRows_ != numRows_) || (x.numCols_ != numCols_)) {
        std::cerr << "Dimensions of matrix a (" << numRows_
                  << "x" << numCols_ << ") and matrix x ("
                  << numRows_ << "x" << numCols_ << ") do not match!";
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size_; ++i)
        a_[i] += x.a_[i];
    return *this;
}


// More arithmetic functions
template<typename T>
MatrixClass<T> operator*(const MatrixClass<T> &a, T x) {
    MatrixClass<T> temp(a);
    temp *= x;
    return temp;
}

template<typename T>
MatrixClass<T> operator*(T x, const MatrixClass<T> &a) {
    MatrixClass<T> temp(a);
    temp *= x;
    return temp;
}

// Concatenate
template<typename T>
MatrixClass<T> operator+(const MatrixClass<T> &a, const MatrixClass<T> &b) {
    MatrixClass<T> temp(a);
    temp += b;
    return temp;
}
