#include<iostream>
#include "q1.h"
using namespace std;

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
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[front];
}

int Queue::getRear()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[rear];
}

void Queue::enqueue(int data)
{
    if(isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    rear = (rear + 1) % _size;
    arr[rear] = data;
    count++;
}

void Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    front = (front + 1) % _size;
    count--;
    if(count == 0)
    {
        front = 0;
        rear = -1;
    }
}

void Queue::enqueueFront(int data)
{
    if(isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    if(isEmpty())
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
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    rear = (rear + _size - 1) % _size;
    count--;
    if(count == 0)
    {
        front = 0;
        rear = -1;
    }
}

void Queue::sort(bool asc)
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    int *temp = new int[count];
    int i = front;
    for(int j = 0; j < count; j++)
    {
        temp[j] = arr[i];
        i = (i + 1) % _size;
    }
    for(int a = 1; a < count; a++)
    {
        int key = temp[a];
        int b = a - 1;
        while(b >= 0 &&
             (asc ? temp[b] > key : temp[b] < key))
        {
            temp[b + 1] = temp[b];
            b--;
        }
        temp[b + 1] = key;
    }
    
    for(int j = 0; j < count; j++)
    {
        arr[j] = temp[j];
    }

    front = 0;
    rear = count - 1;
    delete[] temp;
}

void Queue::display()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front;
    cout << "Queue elements: ";
    for(int j = 0; j < count; j++)
    {
        cout << arr[i] << " ";
        i = (i + 1) % _size;
    }
    cout << endl;
}

void operateQueue()
{
    Queue q(5);
    int ch, data;
    do
    {
        cout << "\n~~~~~~ QUEUE MENU ~~~~~~" << endl;
        cout << "1. ENQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. GET FRONT" << endl;
        cout << "4. GET REAR" << endl;
        cout << "5. SORT ASCENDING" << endl;
        cout << "6. SORT DESCENDING" << endl;
        cout << "7. DISPLAY" << endl;
        cout << "8. CHECK EMPTY" << endl;
        cout << "9. CHECK FULL" << endl;
        cout << "10. ENQUEUE FRONT" << endl;
        cout << "11. DEQUEUE REAR" << endl;
        cout << "12. EXIT" << endl;
        
        cout << "Enter your choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "Enter element: ";
                cin >> data;
                q.enqueue(data);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                if(!q.isEmpty())
                    cout << "Front element: "
                         << q.getFront() << endl;
                else
                    cout << "Queue is empty" << endl;
                break;

            case 4:
                if(!q.isEmpty())
                    cout << "Rear element: "
                         << q.getRear() << endl;
                else
                    cout << "Queue is empty" << endl;
                break;

            case 5:
                q.sort(true);
                q.display();
                break;

            case 6:
                q.sort(false);
                q.display();
                break;

            case 7:
                q.display();
                break;

            case 8:
                if(q.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;

            case 9:
                if(q.isFull())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue is not full" << endl;
                break;

            case 10:
                cout << "Enter element: ";
                cin >> data;
                q.enqueueFront(data);
                break;

            case 11:
                q.dequeueRear();
                break;

            case 12:
                cout << "Exiting Queue Menu" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while(ch != 12);
}
