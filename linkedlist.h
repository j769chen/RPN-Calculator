#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>

using namespace std;

class linkedlist {
    protected:
        struct Node {
            float value;
            Node *next;
        };
        int top;
        Node *head;
    public:
        linkedlist();
        void push(float c);
        float pop();
        bool isEmpty();
        bool isFull();
        float getval();
};

#endif // LINKEDLIST_H_INCLUDED
