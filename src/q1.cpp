#include<iostream>
using namespace std;
#include "q1.h"

Queue::Queue(size_t size)
{
    _size = size;
    arr = new int[_size];
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

bool Queue::isFull()
{
    return count == _size;
}

bool Queue::isEmpty()
{
    return count == 0;
}

int Queue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }

    return arr[front];
}

void Queue::enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full\n";
        return;
    }

    rear = (rear + 1) % _size;
    arr[rear] = data;
    count++;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }

    front = (front + 1) % _size;
    count--;
    if (count == 0)
    {
        front=0;
        rear=-1;
    }
}

void Queue::sort(bool asc)
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
 
    int *temp = new int[count];
 
    int i = front;
    for (int j = 0; j < count; j++)
    {
        temp[j] = arr[i];
        i = (i + 1) % _size;
    }
 
    for (int a = 1; a < count; a++)
    {
        int key = temp[a];
        int b = a - 1;
        while (b >= 0 && (asc ? temp[b] > key : temp[b] < key))
        {
            temp[b + 1] = temp[b];
            b--;
        }
        temp[b + 1] = key;
    }
 
    for (int j = 0; j < count; j++)
        arr[j] = temp[j];
 
    front = 0;
    rear = count - 1;
 
    delete[] temp;
}
 
int Queue::getRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
 
    return arr[rear];
}
 
void Queue::enqueueFront(int data)
{
    if (isFull())
    {
        cout << "Queue is full\n";
        return;
    }
 
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        front = (front + _size - 1) % _size;   
    }
 
    arr[front] = data;
    count++;
}
 
void Queue::dequeueRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
 
    rear = (rear + _size - 1) % _size;       
    count--;
    if (count == 0)
    {
        front = 0;
        rear = -1;
    }
}
 
void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }

    int i = front;
    cout<<"queue is :-"<<endl;
    for (int j = 0; j < count; j++)
    {
        cout <<  arr[i] << " ";
        i = (i + 1) % _size;
    }

    cout << endl;
}
