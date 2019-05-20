//
// Created by chris on 5/20/19.
//
#include <iostream>
#include <string>
#include <exception>

class my_exception: public std::exception {
public:

    // Our constructor with move statement, to move ownership of the string to my_exception
    explicit my_exception(std::string exception): exception(std::move(exception)){
    }

    // our watch function
    std::string watch(){
        return this->exception;
    }

private:
    // we use 'watch' for returning the string, therefore it can be private
    std::string exception;
};

//class Foo throws in the destructor
class Foo {
public:
    ~Foo() {
        throw my_exception("Foo exception");
    }
};


// class Bar throws in the constructor
class Bar {
public:
    Bar() {
        throw my_exception("Bar exception");
    }
};

int main()
try {
    Foo f;
    Bar b;
}
catch (const std::exception &e) {
    std::cout << "ERROR:" << e.what() << std::endl;
}
