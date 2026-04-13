#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

class Queue
{
public:
    Node* front;
    Node* end;

    bool isEmpty()
    {
        if(front == nullptr && end == nullptr)
            return 1;
        else
            return 0;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if(!isEmpty())
        {
            front = newNode;
            end = newNode;
        }
        else
        {
            end->nextptr = newNode;
            newNode->prevptr = end;
            end = newNode;
        }

    }

    int dequeue()
    {
        if(isEmpty())
            throw std::runtime_error("Queue is empty!");
        else
        {
            int value = front->data;
            Node* tempptr = front;
            front = front->nextptr;

            if(front != nullptr)
            {
                front->prevptr = nullptr;
            }
            else
            {
                end = nullptr;
            }
            delete tempptr;
            return value;
        }
    }

    void clear()
    {
        Node* tempptr = front;
        while(tempptr != nullptr)
        {
            Node* next = tempptr->nextptr;
            delete tempptr;
            tempptr = next;
        }
        front = end = nullptr;
    }

    Node* findMin()
    {
        if(isEmpty()) return nullptr;
        Node* current = front;
        Node* minNode = front;
        while (current != nullptr)
        {
            if (current->data < minNode->data)
                minNode = current;
            current = current->nextptr;
        }
        return minNode;
    }

    Node* findMax()
    {
        if(isEmpty()) return nullptr;
        Node* current = front;
        Node* maxNode = front;
        while (current != nullptr)
        {
            if (current->data > maxNode->data)
                maxNode = current;
            current = current->nextptr;
        }
        return maxNode;
    }

    void insertBetween(Queue& otherQueue, Node* from, Node* to)
    {
       if (!from || !to || otherQueue.isEmpty()) return;

        Node* current = from->nextptr;
        while (current != to && current != nullptr) {
            Node* toDelete = current;
            current = current->nextptr;
            delete toDelete;
        }

        from->nextptr = otherQueue.front;
        otherQueue.front->prevptr = from;

        to->prevptr = otherQueue.end;
        otherQueue.end->next = to;
    }
    Queue() : front(nullptr), end(nullptr) {}
};

#endif // QUEUE_H
