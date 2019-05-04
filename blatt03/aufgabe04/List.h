//
// Created by chris on 5/1/19.
//

#ifndef WISSENSCHAFTLICHES_RECHNEN_LIST_H
#define WISSENSCHAFTLICHES_RECHNEN_LIST_H

#include "Node.h"

class List {
public:
    int m_length; // the length of the list, not really used here
    Node *m_head; // the head of our list, very much used :)
    List(); // create an empty list
    List(const List &list); // copy-by-value constructor
    List &operator=(const List &list); // our assignment operator for assigning a list via copy-by-value
    ~List(); // clean up the list and all nodes
    const Node *findMin() const; // our function for finding a minimum
    const Node *findMax() const; // our function for finding a maximum
    Node *first() const; // return a pointer to the first entry
    Node *next(const Node *n) const; // return a pointer to the node after n
    Node *findNode(int i) const; // our own findNode function to make it easier to test erase and insert functions
    void append(int i); // append a value to the end of the list
    void insert(Node *n, int i); // insert a value before n
    void erase(Node *n); // remove n from the list
};


#endif //WISSENSCHAFTLICHES_RECHNEN_LIST_H
