#include <iostream>
#include "linkedlist.h"
#include <cmath>
#include <stdlib.h>

using namespace std;

//Constructor
linkedlist::linkedlist(){
    top = -1;
    head = NULL;
}

//Push
void linkedlist::push(float c){
    if (isFull()){
        cout << "Stack is full." << endl;
        return;
    }
    Node *newnode = new Node;
    newnode->value = c;
    newnode->next = head;
    head = newnode;
    top++;
}

//Pop
float linkedlist::pop(){
    if (isEmpty()){
        cout << "Stack is empty." << endl;
        return 0;
    }
    Node *temp = head;
    head = head->next;
    top--;
    float c = temp->value;
    return c;
}

//Check if list is empty
bool linkedlist::isEmpty(){
    if (top < 0){
        return true;
    }
    return false;
}

//Check if list is full
bool linkedlist::isFull(){
    if (top == 19){
        return true;
    }
    return false;
}

float linkedlist::getval(){
    return head->value;
}
