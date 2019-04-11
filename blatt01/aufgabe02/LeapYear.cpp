//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi:
// Matrikelnummer: 493981
//

#include "LeapYear.h"
#include <map>
#include <iostream>

using namespace std;

// This method checks for leap years
bool LeapYear::checkForLeapYear(unsigned int year) {
    if (year % 100 != 0 && year % 4 == 0) return true;
    else if (year % 400 == 0) return true;
    else return false;
}

// This method is testing our method with provided leap years
// You can execute it with leapyear.test()
void LeapYear::test() {
    map<unsigned int, bool> testYears = {{1896, true}, {1916, true}, {2000, true},
                                         {2012, true}, {1881, false}, {1900, false},
                                         {2003, false}, {2013, false}};
    bool solution;
    for(auto const& x: testYears){
        solution = LeapYear::checkForLeapYear(x.first);
        if (solution != x.second){
            cout << "Failed test: " << x.first << " = " << solution << endl;
            cout << "Expected results: " << x.second << endl;
        }
        else {
            cout << "Passed test: " << x.first << " = " << solution << endl;
        }
    }
}


int main() {
    LeapYear leapyear = LeapYear();
    // uncomment the following line for testing all provided years
    //leapyear.test();
    unsigned int year;
    cout << "Please enter an unsigned integer as year: ";
    cin >> year;
    // Here we use the failbit of cin. If cin get's non integer input
    // We will run into this if.
    if(!cin) {
        cout << "You didn't provide an unsigned integer";
        exit(EXIT_FAILURE);
    }
    // Check for the actual leap year
    if (leapyear.checkForLeapYear(year)) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }
}