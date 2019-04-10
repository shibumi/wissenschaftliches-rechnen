//
// Created by chris on 4/10/19.
//

#include "Faculty.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Faculty::Faculty() {
    // Using a constructor to retrieve the number for the faculty calculation
    cout << "For Faculty please enter a number greater than 0: ";
    cin >> number;
    if (number <= 0) {
        cout << "The input is either smaller than 1 or not a number." << endl;
        cout << "Make sure to give us a number greater than 0." << endl;
        exit(EXIT_FAILURE);
    }
}

unsigned int Faculty::calculate() {
    // if !1 we return 1
    if (number == 1) return 1;

    // We are solving the faculty problem iterative.
    // I am pretty sure there is a recursive way as well,
    // but using a recursive solution can get in trouble due to the stack size.
    unsigned int sum = 1;
    for (; number >= 1; number--) {
        sum = number * sum;
    }
    return sum;
}



int main() {
    // Creating faculty object for retrieving the number for faculty calculation
    Faculty fac = Faculty();
    // Start actual faculty calculation
    cout << "The solution is: " << fac.calculate() << endl;
}