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

    class Row {
    public:
        Row(T* data): data(data){}
        bool operator==(const Row& rhs) const {
            return data == rhs.data;
        }

        bool operator!=(const Row& rhs) const {
            return data != rhs.data;
        }
        T* begin() {
            return ColIterator(data, sizeof(T));
        }
        T* end() {
            return ColIterator(data, sizeof(T));
        }
    private:
        T* data;
    };

    class RowIterator {
    public:
        RowIterator(T* data, size_t size): data(data), size(size){}
        Row operator*() {
            return Row(data);
        }
        const Row operator*() const {
            return Row(data);
        }
        void operator++() {
            data += size;
        }
        bool operator==(const RowIterator& rhs) const {
            return data == rhs.data;
        }

        bool operator!=(const RowIterator& rhs) const {
            return data != rhs.data;
        }

        int row() const {
            // row() is not specified in the task
            // so I will just skip this here and return 0
            // I have no idea what is meant with row() .. the row index?
            return 0;
        };
    private:
        T* data;
        size_t size;
    };

    class ColIterator {
    public:
        ColIterator(T* data, size_t size): data(data), size(size){}
        T& operator*() {
            return *data;
        }
        const T& operator*() const {
            return *data;
        }
        void operator++() {
            data += size;
        }
        bool operator==(const RowIterator& rhs) const {
            return data == rhs.data;
        }

        bool operator!=(const RowIterator& rhs) const {
            return data != rhs.data;
        }

        unsigned int col() const {
            // no idea what is meant with col().. the col index?
            // it's not specified in the task
            return 0;
        }
    private:
        T* data;
        size_t size;
    };

    // Set number of matrix rows and columns and initialize its elements with value
    void resize(size_t numRows, size_t numCols, const T &value = T());

    // Access matrix element at position (i,j)
    T &operator()(size_t i, size_t j);

    T operator()(size_t i, size_t j) const;

    // Output matrix content
    void print() const;

    // Returns number of matrix rows
    size_t rows() const {
        return numRows_;
    }

    // Returns number of matrix columns
    size_t cols() const {
        return numCols_;
    }

    RowIterator begin() {
        return RowIterator(&a_[0], cols());
    }

    RowIterator end() {
        return RowIterator(&a_[rows() * cols()] , cols());
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

