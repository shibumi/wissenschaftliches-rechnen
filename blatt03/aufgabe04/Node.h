//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi:
// Matrikelnummer: 493981
//

#ifndef WISSENSCHAFTLICHES_RECHNEN_NODE_H
#define WISSENSCHAFTLICHES_RECHNEN_NODE_H


class Node {
    friend class List; // I doubt that we really need this in our implementation
public:
    explicit Node(int value); // We set this explicit, because we demand an integer as parameter
    void setNext(Node *next); // this sets the next node
    Node *getNext() const; // this returns the next node
    int m_value; // this holds the value of a node
private:
    Node *m_next; // this holds the next node
};


#endif //WISSENSCHAFTLICHES_RECHNEN_NODE_H
