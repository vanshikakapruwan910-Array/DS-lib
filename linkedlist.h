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

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
 
    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
 
    void deleteAtBegin();
    void deleteAtEnd();
    void deleteAtPosition(int position);
 
    bool search(int data);
    int length();
    void display();

    void insertAfterK(int data, int k);
    void insertBeforeK(int data, int k);
    void deleteValueK(int k);
};
 
#endif
