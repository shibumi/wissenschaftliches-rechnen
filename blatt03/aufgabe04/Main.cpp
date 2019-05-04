//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//
#include <iostream>
#include "List.h"
#include "Node.h"


using namespace std;

// This is the test function for our findMin() and findMax() functions.
// It will create a list and test this list on various cases:
// 1. empty list
// 2. list with just one element
// 3. modify list and mix it up and insert some random numbers
void testListMinMax() {
    // test empty list
    List testList;
    if (testList.findMin() != nullptr) cout << "ERROR: findMin() on empty List should return nullptr" << endl;
    else cout << "PASSED: findMin() test on empty List" << endl;
    if (testList.findMax() != nullptr) cout << "ERROR: findMax() on empty List should return nullptr" << endl;
    else cout << "PASSED: findMax() test on empty List" << endl;
    // test list with just one element
    testList.append(-5);
    Node const *minResult = testList.findMin();
    Node const *maxResult = testList.findMax();
    if (minResult->m_value != -5)
        cout << "ERROR: findMin() should return -5 for List with element -5; got " << minResult->m_value << endl;
    else cout << "PASSED: findMin() test on List with one element" << endl;
    if (maxResult->m_value != -5)
        cout << "ERROR: findMax() should return -5 for List with element -5; got " << maxResult->m_value << endl;
    else cout << "PASSED: findMax() test on List with one element" << endl;
    // test random list with positive and negative numbers
    testList.append(5);
    testList.append(9000);
    testList.append(0);
    // play around with the list to mix it up a bit
    testList.insert(testList.findNode(0), 23);
    testList.insert(testList.findNode(0), -301);
    testList.erase(testList.findNode(0));
    testList.append(-300);
    // erase minCache to check if cache updating works
    testList.erase(testList.findNode(-301));
    minResult = testList.findMin();
    maxResult = testList.findMax();
    if (minResult->m_value != -300)
        cout << "ERROR: findMin() should return -300 for List with min element -300; got " << minResult->m_value
             << endl;
    else cout << "PASSED: findMin() test on List with random values" << endl;
    if (maxResult->m_value != 9000)
        cout << "ERROR: findMin() should return 9000 for List with max element 9000; got " << maxResult->m_value
             << endl;
    else cout << "PASSED: findMax() test on List with random values" << endl;
    testList.insert(nullptr, 0); // this should add a node with the value 0 at the end of the list...
    testList.erase(nullptr); // this should do nothing, but let's see if we run into an error here...

}


// Our main method and entry point
// All code is tested via valgrind on memory leaks, double frees and uninitialized conditions. :-)
int main() {
    testListMinMax();
    List list;
    list.append(2);
    list.append(3);
    list.insert(list.first(), 1);
    for (Node *n = list.first(); n != nullptr; n = list.next(n))
        std::cout << n->m_value << std::endl;
    List list2 = list;
    for (Node *n = list2.first(); n != nullptr; n = list2.next(n))
        std::cout << n->m_value << std::endl;
    return 0;
}