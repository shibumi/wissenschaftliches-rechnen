//
// Created by chris on 5/1/19.
//

#ifndef WISSENSCHAFTLICHES_RECHNEN_LIST_H
#define WISSENSCHAFTLICHES_RECHNEN_LIST_H
#include "Node.h"

class List {
public:
    int m_length;
    Node *m_head;
    List (); // create an empty list
    ~List (); // clean up the list and all nodes
    Node *first() const; // return a pointer to the first entry
    Node *next(const Node *n) const; // return a pointer to the node after n
    void append (int i); // append a value to the end of the list
    void insert (Node *n, int i); // insert a value before n
    void erase (Node *n); // remove n from the list
};


#endif //WISSENSCHAFTLICHES_RECHNEN_LIST_H
