#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int value) : data(value), prevptr(nullptr), nextptr(nullptr) {}
    int data;
    Node* prevptr;
    Node* nextptr;
};

#endif // NODE_H
