#include "stack.h"
#include <iostream>
#include <cmath>


using namespace std;

//Stack constructor
Stack::Stack(){
    top = -1;

    for(int i = 0; i < 20; i++){
        arr[i] = 0;
    }
}

//Check if stack is empty
bool Stack::isEmpty(){
    if (top < 0){
        return true;
    }
    return false;
}

//Check if stack is full
bool Stack::isFull(){
    if (top == 19){
        return true;
    }
    return false;
}

//Push
void Stack::push(float c){
   if (isFull()){
        cout << "Stack is full." << endl;
        return;
   }
   top++;
   arr[top] = c;
   return;
}

//Pop
float Stack::pop(){
    if (isEmpty()){
        cout << "Stack is empty." << endl;
        return 0;
    }
    float data = arr[top];
    top--;
    return data;
}

//Return top value
float Stack::getval(){
    return arr[top];
}
