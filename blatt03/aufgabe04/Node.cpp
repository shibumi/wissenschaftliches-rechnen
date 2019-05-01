//
// Created by chris on 5/1/19.
//

#include "Node.h"

Node::Node(int value) : m_value(value), m_next(nullptr){
}

void Node::setNext(Node *next) {
    this->m_next = next;
}

Node* Node::getNext() const {
    return m_next;
}
