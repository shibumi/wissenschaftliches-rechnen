#include <iomanip>
#include <iostream>
#include <vector>

/**
 * Matrix Class representing matrices of double values
 */

class MatrixClass {
public:

    // Set number of matrix rows and columns and initialize its elements with value
    void resize(size_t numRows, size_t numCols, const double &value = double());

    // Access matrix element at position (i,j)
    double &operator()(size_t i, size_t j);

    double operator()(size_t i, size_t j) const;

    // Arithmetic functions 
    MatrixClass &operator*=(double x);

    MatrixClass &operator+=(const MatrixClass &b);

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

    MatrixClass &operator=(const MatrixClass &b) {
        a_.release();
        a_ = std::unique_ptr<double[]>(new double[b.size_]);
        for (size_t i = 0; i < size_; ++i)
            a_[i] = b.a_[i];
        numRows_ = b.numRows_;
        numCols_ = b.numCols_;
        size_ = b.size_;
        return *this;
    }


    // Constructors
    MatrixClass(size_t numRows, size_t numCols, const double &value = double()) :
            numRows_(numRows), numCols_(numCols) {
        if ((numRows_ + numCols_ > 0) && (numRows_ * numCols_ == 0)) {
            numRows_ = 0;
            numCols_ = 0;
        }
        a_ = std::unique_ptr<double[]>(new double[numRows_ * numCols_]);
        for (size_t j = 0; j < size_; ++j)
            a_[j] = value;
    }

    MatrixClass(size_t numElem) : MatrixClass(numElem, numElem) {}

    MatrixClass() = default;

    MatrixClass(const MatrixClass &b) {
        a_ = std::unique_ptr<double[]>(new double[b.size_]);
        for (size_t i = 0; i < size_; ++i)
            a_[i] = b.a_[i];
        numRows_ = b.numRows_;
        numCols_ = b.numCols_;
        size_ = b.size_;
    }

private:
    // matrix elements
    std::unique_ptr<double[]> a_;
    // number of rows
    size_t numRows_ = 0;
    // number of columns
    size_t numCols_ = 0;
    size_t size_ = 0;
};

// More arithmetic functions
MatrixClass operator*(const MatrixClass &a, double x);

MatrixClass operator*(double x, const MatrixClass &a);

MatrixClass operator+(const MatrixClass &a, const MatrixClass &b);
