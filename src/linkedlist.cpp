#include <iostream>
#include "linkedlist.h"
using namespace std;

Node::Node(int value)
{
    data = value;
    next = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtBegin(int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int data)
{
    Node* newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void LinkedList::insertAtPosition(int data, int position)
{
    if (position < 1)
    {
        cout << "Invalid position\n";
        return;
    }
    if (position == 1)
    {
        insertAtBegin(data);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;
    if (temp == nullptr)
    {
        cout << "Invalid position\n";
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::insertAfterK(int data, int k)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != k)
        temp = temp->next;
    if (temp == nullptr)
    {
        cout << "Value not found\n";
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::insertBeforeK(int data, int k)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->data == k)
    {
        insertAtBegin(data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != k)
        temp = temp->next;

    if (temp->next == nullptr)
    {
        cout << "Value not found\n";
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteAtBegin()
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteAtEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::deleteAtPosition(int position)
{
    if (position < 1 || head == nullptr)
    {
        cout << "Invalid position or empty list\n";
        return;
    }
    if (position == 1)
    {
        deleteAtBegin();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Invalid position\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void LinkedList::deleteValueK(int k)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    if (head->data == k)
    {
        deleteAtBegin();
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != k)
        temp = temp->next;

    if (temp->next == nullptr)
    {
        cout << "Value not found\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

bool LinkedList::search(int data)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return true;

        temp = temp->next;
    }
    return false;
}

int LinkedList::length()
{
    int count = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void LinkedList::display()
{
    Node* temp = head;
    if (temp == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
void operateLinkedList()
{
    LinkedList list;
    int ch, data, position, k;
    do
    {
        cout << "\n~~~~ LINKED LIST MENU ~~~~\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After Value\n";
        cout << "5. Insert Before Value\n";
        cout << "6. Delete at Beginning\n";
        cout << "7. Delete at End\n";
        cout << "8. Delete at Position\n";
        cout << "9. Delete a Value\n";
        cout << "10. Search a Value\n";
        cout << "11. Find Length\n";
        cout << "12. Display List\n";
        cout << "13. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtBegin(data);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;

            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(data, position);
                break;

            case 4:
                cout << "Enter value after which to insert: ";
                cin >> k;
                cout << "Enter new data: ";
                cin >> data;
                list.insertAfterK(data, k);
                break;

            case 5:
                cout << "Enter value before which to insert: ";
                cin >> k;
                cout << "Enter new data: ";
                cin >> data;
                list.insertBeforeK(data, k);
                break;

            case 6:
                list.deleteAtBegin();
                break;

            case 7:
                list.deleteAtEnd();
                break;

            case 8:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;

            case 9:
                cout << "Enter value to delete: ";
                cin >> k;
                list.deleteValueK(k);
                break;

            case 10:
                cout << "Enter value to search: ";
                cin >> data;

                if (list.search(data))
                    cout << "Value found\n";
                else
                    cout << "Value not found\n";
                break;

            case 11:
                cout << "Length of list: "
                     << list.length() << endl;
                break;

            case 12:
                list.display();
                break;

            case 13:
                cout << "Exiting Linked List Menu\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (ch != 13);
}
