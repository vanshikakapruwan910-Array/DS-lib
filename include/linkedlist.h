#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node
{
public:
    int data;
    Node* next;

    Node(int value);
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void insertAfterK(int data, int k);
    void insertBeforeK(int data, int k);

    void deleteAtBegin();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void deleteValueK(int k);

    bool search(int data);
    int length();
    void display();
};
void operateLinkedList();
#endif
