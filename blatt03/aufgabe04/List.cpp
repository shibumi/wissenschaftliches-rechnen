//
// Created by chris on 5/1/19.
//

#include "List.h"

// Initializes list with a length of 0 and a nullptr as head
List::List() {
    this->m_length = 0;
    this->m_head = nullptr;
}

// Initializes a list via another list and copies the values over to the new list
// This constructor implements a copy-by-value.
List::List(const List &list) {
    // make sure to initialize the new list, otherwise we will get valgrind warnings "UninitCondition"
    this->m_head = nullptr;
    this->m_length = 0;
    for (Node *current = list.first(); current != nullptr; current = list.next(current)) {
        append(current->m_value);
    }
}

// This implements our own assignment operator for copy-by-value
List &List::operator=(const List &list) {
    // make sure to initialize the new list, otherwise we will get valgrind warnings "UninitCondition"
    this->m_head = nullptr;
    this->m_length = 0;
    for (Node *current = list.first(); current != nullptr; current = list.next(current)) {
        append(current->m_value);
    }
}

// This is our custom destructor. It will destroy all our nodes, set the length to 0 and the head to a nullptr
List::~List() {
    Node *n = first();
    Node *new_node = nullptr;
    while (n != nullptr) {
        new_node = next(n);
        delete n;
        n = new_node;
    }
    this->m_length = 0;
    this->m_head = nullptr;
}

// This function will find the maximum in our list. If the list is empty we return a nullptr
const Node *List::findMax() const {
    if (this->m_head == nullptr) return nullptr;
    Node *node = this->m_head;
    for (Node *current = first(); current != nullptr; current = next(current)) {
        if (node->m_value < current->m_value) node = current;
    }
    return node;
}

// This function will find the minimum in our list. If the list is empty we return a nullptr
const Node *List::findMin() const {
    if (this->m_head == nullptr) return nullptr;
    Node *node = this->m_head;
    for (Node *current = first(); current != nullptr; current = next(current)) {
        if (node->m_value > current->m_value) node = current;
    }
    return node;
}

// This is a helper function for finding the first node that matches an integer value.
// This function is a little extra and not demanded on the homework sheet.
Node *List::findNode(int i) const {
    for (Node *current = first(); current != nullptr; current = next(current)) {
        if (current->m_value == i) return current;
    }
    // If we have no matched Node, return nullptr
    return nullptr;
}

// This function will append a node to the list
void List::append(int i) {
    Node *node = new Node(i);
    if (this->m_head == nullptr) {
        this->m_head = node;
    } else {
        for (Node *current = first(); current != nullptr; current = next(current)) {
            if (current->getNext() == nullptr) {
                current->setNext(node);
                break;
            }
        }
    }
    this->m_length++;
}

// This function will give us the first element of our list, also called the 'head'.
Node *List::first() const {
    return this->m_head;
}

// This function will give us the next node of the given node.
Node *List::next(const Node *n) const {
    return n->getNext();
}

// This function will insert a node before the given node
void List::insert(Node *n, int i) {
    Node *node = new Node(i);
    if (n == first()) {
        this->m_head = node;
        node->setNext(n);
    } else {
        for (Node *current = first(); current != nullptr; current = next(current)) {
            if (current->getNext() == n) {
                node->setNext(current->getNext());
                current->setNext(node);
                break;
            }
        }
    }
    this->m_length++;
}

// This function will erase a node from the list
void List::erase(Node *n) {
    if (this->m_head == n) {
        this->m_head = n->getNext();
        delete n;
    } else {
        for (Node *current = first(); current != nullptr; current = next(current)) {
            if (current->getNext() == n) {
                current->setNext(current->getNext()->getNext());
                delete n;
            }
        }
    }
    this->m_length--;
}