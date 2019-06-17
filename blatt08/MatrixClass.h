//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//

#include <iomanip>
#include <iostream>
#include <vector>
#include "exceptions.cpp"

/**
 * Matrix Class representing matrices of T values
 */

template<typename T>
class MatrixClass {
public:

    // Set number of matrix rows and columns and initialize its elements with value
    void resize(size_t numRows, size_t numCols, const T &value = T());

    // Access matrix element at position (i,j)
    T &operator()(size_t i, size_t j);

    T operator()(size_t i, size_t j) const;

    // Output matrix content
    void print() const;

    // Returns number of matrix raws
    size_t rows() const {
        return numRows_;
    }

    // Returns number of matrix columns
    size_t cols() const {
        return numCols_;
    }

    MatrixClass<T> &operator=(const MatrixClass<T> &b) {
        a_.release();
        numRows_ = b.numRows_;
        numCols_ = b.numCols_;
        a_ = std::unique_ptr<T[]>(new T[numRows_ * numCols_]);
        for (size_t i = 0; i < numRows_ * numCols_; ++i)
            a_[i] = b.a_[i];
        return *this;
    }


    // Constructors
    MatrixClass(size_t numRows, size_t numCols, const T &value = T()) :
            numRows_(numRows), numCols_(numCols) {
        if ((numRows_ + numCols_ > 0) && (numRows_ * numCols_ == 0)) {
            numRows_ = 0;
            numCols_ = 0;
        }
        a_ = std::unique_ptr<T[]>(new T[numRows_ * numCols_]);
        for (size_t j = 0; j < numRows_ * numCols_; ++j)
            a_[j] = value;
    }

    explicit MatrixClass(size_t numElem) : MatrixClass(numElem, numElem) {}

    MatrixClass() = default;

    MatrixClass(const MatrixClass<T> &b) {
        numRows_ = b.numRows_;
        numCols_ = b.numCols_;
        a_ = std::unique_ptr<T[]>(new T[numRows_ * numCols_]);
        for (size_t i = 0; i < numRows_ * numCols_; ++i)
            a_[i] = b.a_[i];
    }

protected:
    // matrix elements
    std::unique_ptr<T[]> a_;
    // number of rows
    size_t numRows_ = 0;
    // number of columns
    size_t numCols_ = 0;
};

// Set number of matrix rows and columns and
// initialize matrix elements with a given T value
template<typename T>
void MatrixClass<T>::resize(size_t numRows, size_t numCols, const T &value) {
    if ((numRows + numCols > 0) && (numRows * numCols == 0)) {
        numRows = 0;
        numCols = 0;
    }
    a_.release();
    numRows_ = numRows;
    numCols_ = numCols;
    a_ = std::unique_ptr<T[]>(new T[numRows_ * numCols_]);
    for (size_t i = 0; i < numRows_ * numCols_; ++i)
        a_[i] = value;
}

// Access matrix element at position (i,j)
template<typename T>
T &MatrixClass<T>::operator()(size_t i, size_t j) {
    if ((i < 0) || (i >= numRows_)) throw IllegalRowIndex(numRows_);
    if ((j < 0) || (j >= numCols_)) throw IllegalColumnIndex(numCols_);
    return a_[i * numCols_ + j];
}

// Access matrix element at position (i,j)
template<typename T>
T MatrixClass<T>::operator()(size_t i, size_t j) const {
    if ((i < 0) || (i >= numRows_)) throw IllegalRowIndex(numRows_);
    if ((j < 0) || (j >= numCols_)) throw IllegalColumnIndex(numCols_);
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

