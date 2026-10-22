#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#define QUEUE_SIZE 5
using namespace std;
class Queue
{
private:
    int *arr;
    int front, rear;
    size_t _size;
    int count;

public:
    Queue();
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
