//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//

#include "NumMatrixClass.h"
#include <iostream>
#include <cstdlib>

int main() {
    // Define a matrix A
    NumMatrixClass<double> A(4, 4);
    std::cout << "A : " << std::endl;
    A.print();

    // Define a square tridiagonal matrix A
    for (size_t i = 0; i < A.rows(); ++i)
        A(i, i) = 2.0;
    for (size_t i = 0; i < A.rows() - 1; ++i)
        A(i + 1, i) = A(i, i + 1) = -1.0;

    // Define a matrix C of same content as A
    NumMatrixClass<double> C(A);
    std::cout << "C : " << std::endl;
    C.print();

    //A = 2 * C;
    std::cout << "A = 2 * C" << std::endl;
    A.print();

    A = C * 2.;
    std::cout << "A = C * 2." << std::endl;
    A.print();

    A = C + A;
    std::cout << "A = C + A" << std::endl;
    A.print();

    // Resize A
    A.resize(5, 5);
    for (size_t i = 0; i < A.rows(); ++i)
        A(i, i) = 2.0;
    for (size_t i = 0; i < A.rows() - 1; ++i)
        A(i + 1, i) = A(i, i + 1) = -1.0;

    // Print A
    std::cout << "A :" << std::endl;
    A.print();

    // Exception tests
    try {
        NumMatrixClass<int> D(4,4);
        std::cout <<  D(-1,0);
    } catch (const IllegalRowIndex &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        NumMatrixClass<int> E(5,5);
        std::cout << E(4,-1);
    } catch (const IllegalColumnIndex &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        NumMatrixClass<int> D(4,4);
        NumMatrixClass<int> E(5,5);
        NumMatrixClass<int> F = D + E;
    } catch (const DimensionMismatch &e) {
        std::cout << e.what() << std::endl;
    }


}
