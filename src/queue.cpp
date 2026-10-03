#include <iostream>
#include <climits>
using namespace std;

struct queue
{
    int *arr;
    int front, rear;
    size_t _size;
};

queue* newqueue(size_t _size)
{
    queue *temp = new queue;

    if (temp == nullptr)
        return nullptr;

    temp->arr = new int[_size];

    temp->_size = _size;
    temp->front = temp->rear = -1;

    return temp;
}

int isfull(queue *q)
{
    return (q->rear + 1) % q->_size == q->front;
}

int isempty(queue *q)
{
    return (q->rear == -1);
}

int front(queue *q)
{
    if (isempty(q))
    {
        cout << "Queue underflow\n";
        return INT_MIN;
    }

    cout << q->arr[q->front] << endl;
    return q->arr[q->front];
}

void enque(queue *q, int data)
{
    if (isfull(q))
    {
        cout << "Queue overflow\n";
        return;
    }

    if (isempty(q))
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = data;
        return;
    }

    q->rear = (q->rear + 1) % q->_size;
    q->arr[q->rear] = data;
}

void deque(queue *q)
{
    if (isempty(q))
    {
        cout << "Queue underflow\n";
        return;
    }

    if (q->rear == q->front)
    {
        q->front = q->rear = -1;
        return;
    }

    q->front = (q->front + 1) % q->_size;
}

void print(queue *q)
{
    if (isempty(q))
    {
        cout << "Queue is empty\n";
        return;
    }

    int i;

    for (i = q->front; i != q->rear; i = (i + 1) % q->_size)
    {
        cout << q->arr[i] << "->";
    }

    cout << q->arr[i] << endl;
}

int operateQueue()
{
    queue *q = newqueue(5);

    if (q == nullptr)
    {
        cout << "Memory allocation failed\n";
        return 1;
    }

    int ch, data;

    while (true)
    {
        cout << "\n------- QUEUE MENU DRIVEN -------\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Print Queue\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                enque(q, data);
                break;

            case 2:
                deque(q);
                break;

            case 3:
                front(q);
                break;

            case 4:
                print(q);
                break;

            case 5:
                delete[] q->arr;
                delete q;

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
