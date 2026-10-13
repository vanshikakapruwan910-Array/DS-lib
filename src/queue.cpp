#include <iostream>
#include <climits>
using namespace std;

class Queue
{
    int *arr;
    int front, rear;
    size_t _size;

public:
    Queue(size_t s)
    {
        _size = s;
        arr = new int[_size];
        front = rear = -1;
    }

    bool isfull()
    {
        return (rear + 1) % _size == front;
    }

    bool isempty()
    {
        return rear == -1;
    }

    int getfront()
    {
        if (isempty())
        {
            cout << "Queue underflow\n";
            return INT_MIN;
        }

        return arr[front];
    }

    void enqueue(int data)
    {
        if (isfull())
        {
            cout << "Queue overflow\n";
            return;
        }
        if (isempty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % _size;
        }
        arr[rear] = data;
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "Queue underflow\n";
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % _size;
        }
    }

    void sortqueue()
    {
        if (isempty())
        {
            cout << "Queue is empty\n";
            return;
        }
        int n = (rear - front + _size) % _size + 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                int pos1 = (front + j) % _size;
                int pos2 = (front + j + 1) % _size;
                if (arr[pos1] > arr[pos2])
                {
                    int temp = arr[pos1];
                    arr[pos1] = arr[pos2];
                    arr[pos2] = temp;
                }
            }
        }
        cout << "Queue sorted successfully\n";
    }

    void print()
    {
        if (isempty())
        {
            cout << "Queue is empty\n";
            return;
        }
        int i;
        for (i = front; i != rear; i = (i + 1) % _size)
        {
            cout << arr[i] << "->";
        }
        cout << arr[i] << endl;
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int operateQueue()
{
    Queue q(5);
    int ch, data;
    while (true)
    {
        cout << "\n------- CIRCULAR QUEUE MENU -------\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Sort queue\n";
        cout << "5. Print Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                q.enqueue(data);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                if (!q.isempty())
                    cout << "Front element: " << q.getfront() << endl;
                else
                    cout << "Queue underflow\n";
                break;

            case 4:
                q.sortqueue();
                break;

            case 5:
                q.print();
                break;

            case 6:
                cout << "Program ended\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
int main()
{
    return operateQueue();
}
