#include <iostream>
using namespace std;
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
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }

    void displayLL()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insertAtBeginLL(int data)
    {
        Node* n = new Node(data);
        n->next = head;
        head = n;
    }

    void insertAtEndLL(int data)
    {
        Node* n = new Node(data);
        if (head == NULL)
        {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }

    void insertBeforeKLL(int data, int k)
    {
        if (head == NULL)
        {
            cout << "Value not found.\n";
            return;
        }
        if (head->data == k)
        {
            insertAtBeginLL(data);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != k)
            temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "Value not found.\n";
            return;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void insertAfterKLL(int data, int k)
    {
        Node* temp = head;
        while (temp != NULL && temp->data != k)
            temp = temp->next;
        if (temp == NULL)
        {
            cout << "Value not found.\n";
            return;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void insertAtILL(int data, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position.\n";
            return;
        }
        if (pos == 0)
        {
            insertAtBeginLL(data);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
            temp = temp->next;
        if (temp == NULL)
        {
            cout << "Position out of range.\n";
            return;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteAtBeginLL()
    {
        if (head == NULL)
        {
            cout << "Empty linked list.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEndLL()
    {
        if (head == NULL)
        {
            cout << "Empty linked list.\n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtILL(int pos)
    {
        if (pos < 0 || head == NULL)
        {
            cout << "Invalid position or empty list.\n";
            return;
        }
        if (pos == 0)
        {
            deleteAtBeginLL();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Position out of range.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void deleteValueKLL(int k)
    {
        if (head == NULL)
        {
            cout << "Empty linked list.\n";
            return;
        }
        if (head->data == k)
        {
            deleteAtBeginLL();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != k)
            temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "Value not found.\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void searchLL(int data)
    {
        Node* temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Found at index " << i << ".\n";
                return;
            }
            temp = temp->next;
            i++;
        }
        cout << "Value not found.\n";
    }

    void lengthLL()
    {
        Node* temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "Length: " << count << "\n";
    }

    ~LinkedList()
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList a;
    int c, d, k;
    do
    {
        cout << "\n0. Display\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert before k\n"
             << "4. Insert after k\n"
             << "5. Insert at position i\n"
             << "6. Delete at beginning\n"
             << "7. Delete at end\n"
             << "8. Delete at position i\n"
             << "9. Delete node having value k\n"
             << "10. Search a value\n"
             << "11. Find length\n"
             << "-1. Exit\n"
             << "Enter choice: ";

        cin >> c;
        switch (c)
        {
            case 0:
                a.displayLL();
                break;

            case 1:
            case 2:
                cout << "Enter data: ";
                cin >> d;
                if (c == 1)
                    a.insertAtBeginLL(d);
                else
                    a.insertAtEndLL(d);
                break;

            case 3:
            case 4:
                cout << "Enter data and k: ";
                cin >> d >> k;
                if (c == 3)
                    a.insertBeforeKLL(d, k);
                else
                    a.insertAfterKLL(d, k);
                break;

            case 5:
                cout << "Enter data and position: ";
                cin >> d >> k;
                a.insertAtILL(d, k);
                break;

            case 6:
                a.deleteAtBeginLL();
                break;

            case 7:
                a.deleteAtEndLL();
                break;

            case 8:
                cout << "Enter position: ";
                cin >> k;
                a.deleteAtILL(k);
                break;

            case 9:
                cout << "Enter value: ";
                cin >> k;
                a.deleteValueKLL(k);
                break;

            case 10:
                cout << "Enter value to search: ";
                cin >> k;
                a.searchLL(k);
                break;

            case 11:
                a.lengthLL();
                break;

            case -1:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid input.\n";
        }
    } while (c != -1);
    return 0;
}
