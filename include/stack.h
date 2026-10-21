#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
class Stack
{
    private:
     int s[100];
     int top;

    public:
     Stack();

     bool isFull();
     bool isEmpty();
     int getTop();
     int size();
     
     void push(int );
     int pop();
     int peek();
     void display();
     void clear();
};
void operateStack();

#endif
