#include <iostream>
#include "array.h"
using namespace std;

void DELETE_AT_Begin(int arr[], int n)
{
    if (n <= 0)
    {
        cout << "Array is empty";
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    cout << "Element deleted from beginning";
}

void DELETE_AT_End(int arr[], int n)
{
    if (n <= 0)
    {
        cout << "Array is empty";
        return;
    }

    n--;

    cout << "Element deleted from end";
}

void DELETE_AT_ith_position(int arr[], int n)
{
    int pos;
    if (n <= 0)
    {
        cout << "Array is empty";
        return;
    }
    cout << "Enter position: ";
    cin >> pos;
    if (pos < 1 || pos > n)
    {
        cout << "Invalid position";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "Element deleted from position " << pos;
}

void DELETE_Before_element(int arr[], int n)
{
    int e, pos = -1;
    if (n <= 0)
    {
        cout << "Array is empty.";
        return;
    }
    cout << "Enter element: ";
    cin >> e;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == e)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Element " << e << " not found";
        return;
    }
    if (pos == 0)
    {
        cout << "No element exists before " << e;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "Element before " << e << " deleted";
}

void DELETE_After_element(int arr[], int n)
{
    int e, pos = -1;
    if (n <= 0)
    {
        cout << "Array is empty";
        return;
    }
    cout << "Enter element: ";
    cin >> e;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == e)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "Element " << e << " not found";
        return;
    }
    if (pos == n - 1)
    {
        cout << "No element exists after " << e;
        return;
    }
    for (int i = pos + 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "Element after " << e << " deleted";
}