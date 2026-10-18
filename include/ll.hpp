#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
public:
    LinkedList();

    struct Node* makeNode(int data);
    void displayLL(struct Node* head);
    void insertAtBeginLL(struct Node** head, int data);
    void insertAtEndLL(struct Node** head, int data);
    void insertBeforeKLL(struct Node** head, int data, int k);
    void insertAfterKLL(struct Node** head, int data, int k);
    void insertAtILL(struct Node** head, int data, int pos);
    void deleteAtBeginLL(struct Node** head);
    void deleteAtEndLL(struct Node** head);
    void deleteAtILL(struct Node** head, int pos);
    void deleteValueKLL(struct Node** head, int k);
    void searchLL(struct Node* head, int data);
    void lengthLL(struct Node* head);
    int operateLL();
};

#endif
