//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//
#ifndef BLATT02_EXCEPTIONS_CPP
#define BLATT02_EXCEPTIONS_CPP

#include <exception>
#include <string>

class IllegalRowIndex : public std::exception {
private:
    std::string m_msg;
public:
    explicit IllegalRowIndex(const size_t numRows) : m_msg(
            std::string("Illegal row index: valid range is 0 to ") + std::to_string(numRows - 1)) {}

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
};

class IllegalColumnIndex : public std::exception {
private:
    std::string m_msg;
public:
    explicit IllegalColumnIndex(const size_t numCols) : m_msg(
            std::string("Illegal column index: valid range is 0 to ") + std::to_string(numCols - 1)) {}

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
};

class DimensionMismatch : public std::exception {
private:
    std::string m_msg;
public:
    DimensionMismatch(const size_t numRows, const size_t numCols, const size_t xNumRows, const size_t xNumCols) : m_msg(
            std::string("Dimension mismatch: ") + std::to_string(numRows) + " x " + std::to_string(numCols) + " with " +
            std::to_string(xNumRows) + " x " + std::to_string(xNumCols)) {}

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
};

#endif //BLATT02_EXCEPTIONS_CPP