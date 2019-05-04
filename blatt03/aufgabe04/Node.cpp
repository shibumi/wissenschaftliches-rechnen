//
// Created by chris on 5/1/19.
//

#include "Node.h"

// We initialize our Node via Member list initialization
Node::Node(int value) : m_value(value), m_next(nullptr){
}

// For setting the next Node we just set m_next
void Node::setNext(Node *next) {
    this->m_next = next;
}

// For getting the next node we just return m_next
Node* Node::getNext() const {
    return m_next;
}
