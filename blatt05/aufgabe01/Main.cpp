//
// Created by chris on 5/18/19.
//

#include "Empty.cpp"
#include <iostream>
#include <limits>

using namespace std;

struct Composite {
    Empty a;
    int b;
};

struct CompositeChar {
    Empty a;
    char b;
};

struct CompositeLongLong {
    Empty a;
    long long b;
};


int main() {
    Empty empty = Empty();
    EmptyDerived emptyDerived = EmptyDerived();
    NonEmpty nonEmpty = NonEmpty();
    cout << "Size of Empty Object: " << sizeof(empty) << endl;
    cout << "Size of EmptyDerived Object: " << sizeof(emptyDerived) << endl;
    cout << "Size of NonEmpty Object: " << sizeof(nonEmpty) << endl;
    Composite composite = {
            empty,
            23, // byte size 4 on Linux 64 Bit system
    };
    cout << "Size of composite: " << sizeof(composite) << endl;
    CompositeChar compositeChar = {
            empty,
            'z', // byte size 1
    };
    cout << "Size of compositeChar: " << sizeof(compositeChar) << endl;
    CompositeLongLong compositeLongLong = {
            empty,
            numeric_limits<long long>::max(), // Byte size of 8
    };
    cout << "Size of compositeLongLong: " << sizeof(compositeLongLong) << endl;
}