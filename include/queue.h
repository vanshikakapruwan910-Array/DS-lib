#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <climits>
#include <cstddef>
using namespace std;
class Queue
{
    int *arr;
    int front, rear;
    size_t _size;
public:
    Queue(size_t s);
    bool isfull();
    bool isempty();
    int getfront();
    void enqueue(int data);
    void dequeue();
    void sortqueue();
    void print();
};
int operateQueue();
#endif

