#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <apstring.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

using namespace std;

class Stack {
    protected:
        float arr[20];
        int top;
    public:
        Stack();
        void push(float c);
        float pop();
        bool isEmpty();
        bool isFull();
        float getval();
};

#endif // STACK_H_INCLUDED

