#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front, rear;
    size_t _size;
    int count;

public:
    Queue(size_t size);
    ~Queue();

    bool isFull();
    bool isEmpty();

    int getFront();
    int getRear();

    void enqueue(int data);
    void dequeue();

    void sort(bool asc); 
    void enqueueFront(int data);        
    void dequeueRear();                 
    void display();
};
void operateQueue();

#endif
