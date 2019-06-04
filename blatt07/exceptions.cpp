//
// Created by chris on 6/4/19.
//

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
    DimensionMismatch(const size_t numRows, const size_t numCols) : m_msg(
            std::string("Dimension mismatch: ") + std::to_string(numRows) + " x " + std::to_string(numCols)) {}

    const char *what() const noexcept override {
        return m_msg.c_str();
    }
};
