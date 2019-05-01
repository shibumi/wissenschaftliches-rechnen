//
// Created by chris on 5/1/19.
//
#include <iostream>
#include "List.h"
#include "Node.h"


using namespace std;

int main () {
    List list;
    list.append(2);
    list.append(3);
    list.insert(list.first(), 1);
    for (Node *n = list.first(); n != 0; n = list.next(n))
        std::cout << n->m_value << std::endl;
    return 0;
}