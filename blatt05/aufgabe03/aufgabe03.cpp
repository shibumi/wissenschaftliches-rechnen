//
// Created by chris on 5/19/19.
//

#include<iostream>

class A {
public:
    void foo() const { std::cout << "A::foo" << std::endl; }
};

class B : public A {
public:
    void foo() { std::cout << "B::foo" << std::endl; }
};

class C : public B { // Fixed Class C via setting B public
public:
    void bar() { foo(); }
};

void test(const A &a) { a.foo(); }

int main() {
    A a;
    B b;
    C c;
    a.foo();
    b.foo();
    test(b);
    c.bar();
    test(c);
    /* Output:
     * A::foo
     * B::foo
     * A::foo
     * B::foo
     * A::foo
     */
}