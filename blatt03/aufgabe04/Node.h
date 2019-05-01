//
// Created by chris on 5/1/19.
//

#ifndef WISSENSCHAFTLICHES_RECHNEN_NODE_H
#define WISSENSCHAFTLICHES_RECHNEN_NODE_H


class Node {
    friend class List;
public:
    explicit Node(int value);
    void setNext(Node *next);
    Node *getNext() const;
    int m_value;
private:
    Node *m_next;
};


#endif //WISSENSCHAFTLICHES_RECHNEN_NODE_H
