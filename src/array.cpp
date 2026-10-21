
#include <iostream>
#include "array.hpp"
using namespace std;

Array::Array()
{
    n = 0;
}

void Array::initialize(const int values[], int size)
{
    if (size < 0 || size > MAX)
    {
        cout << "Invalid array size.\n";
        return;
    }

    n = size;
    for (int i = 0; i < n; i++)
        arr[i] = values[i];
}

void Array::display() const
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Array::update()
{
    int index, value;

    cout << "Enter index to update (0 to " << n - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= n)
    {
        cout << "Invalid index.\n";
        return;
    }

    cout << "Enter new value: ";
    cin >> value;
    arr[index] = value;
}

void Array::search() const
{
    int value;
    cout << "Enter element to search: ";
    cin >> value;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            cout << "Element found at index " << i << ".\n";
            return;
        }
    }

    cout << "Element not found.\n";
}

void Array::reversearray()
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout << "Array reversed.\n";
}

void Array::sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Array sorted in ascending order.\n";
}

void Array::INSERT_AT_Begin()
{
    if (n >= MAX)
    {
        cout << "Array is full.\n";
        return;
    }

    int value;
    cout << "Enter value: ";
    cin >> value;

    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = value;
    n++;
}

void Array::INSERT_AT_End()
{
    if (n >= MAX)
    {
        cout << "Array is full.\n";
        return;
    }

    cout << "Enter value: ";
    cin >> arr[n];
    n++;
}

void Array::DELETE_AT_Begin()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

void Array::DELETE_AT_End()
{
    if (n == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    n--;
}

void Array::displayeven() const
{
    cout << "Even elements: ";
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";
    cout << endl;
}

void Array::displayodd() const
{
    cout << "Odd elements: ";
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 != 0)
            cout << arr[i] << " ";
    cout << endl;
}

void Array::countevenodd() const
{
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << "Even count: " << even << endl;
    cout << "Odd count: " << odd << endl;
}

int Array::getElement(int index) const
{
    if (index < 0 || index >= n)
        return 0;

    return arr[index];
}

int Array::size() const
{
    return n;
}

void Array::operateArray()
{
    int choice;

    do
    {
        cout << "\n--- 1D ARRAY MENU ---\n";
        cout << "1. Display\n";
        cout << "2. Update\n";
        cout << "3. Search\n";
        cout << "4. Reverse\n";
        cout << "5. Sort\n";
        cout << "6. Insert at beginning\n";
        cout << "7. Insert at end\n";
        cout << "8. Delete from beginning\n";
        cout << "9. Delete from end\n";
        cout << "10. Display even elements\n";
        cout << "11. Display odd elements\n";
        cout << "12. Count even and odd\n";
        cout << "0. Back to main menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: display(); break;
            case 2: update(); break;
            case 3: search(); break;
            case 4: reversearray(); display(); break;
            case 5: sort(); display(); break;
            case 6: INSERT_AT_Begin(); display(); break;
            case 7: INSERT_AT_End(); display(); break;
            case 8: DELETE_AT_Begin(); display(); break;
            case 9: DELETE_AT_End(); display(); break;
            case 10: displayeven(); break;
            case 11: displayodd(); break;
            case 12: countevenodd(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
