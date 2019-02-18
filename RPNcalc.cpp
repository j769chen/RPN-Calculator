#include <iostream>
#include "RPNcalc.h"
#include <cmath>
#include <math.h>
#define PI 3.14159265

//Operations
void RPNcalc::operate(char c){
    float a = 0;

    switch(c) {
        case '+': if (top > 0){
                    push(pop() + pop());
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case '-': if (top > 0){
                    a = pop();
                    push(pop() - a);
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case 'x': if (top > 0) {
                  push(pop() * pop());
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case '/': if (top > 0) {
                    a = pop();
                    if (a != 0){
                        push(pop() / a);
                    }
                    else {
                        cout << "CANNOT DIVIDE BY ZERO." << endl;
                    }
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case '^': if (top > 0){
                    a = pop();
                    push(pow(pop(), a));
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case '1': if (!isEmpty()){
                    push(1/pop());
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case '2': if (!isEmpty()){
                    push(sqrt(pop()));
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case 's': if (!isEmpty()){
                    push(sinf(pop()));
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case 'c': if (!isEmpty()){
                    push(cosf(pop()));
                  }
                  else {
                    cout << "Insufficient data." << endl;
                  }
        break;

        case 't': if (!isEmpty()){
                    push(tanf(pop()));
                  }
                  else {
                    cout << "Insufficient data." <<endl;
                  }
        break;

        case 'p': push(PI);
        break;

        case 'l': if (!isEmpty()){
                    a = pop();
                    if (a > 0){
                        push(log10(a));
                    }
                    else {
                        cout << "Cannot take log of negative number or zero!" << endl;
                    }
                  }
                  else{
                    cout << "Insufficient data." << endl;
                  }
        break;

        default: cout << "Insufficient data." << endl;
        break;
    }
}

//Clear linked list
void RPNcalc::clearcalc(){
    while(head){
        pop();
    }
}
