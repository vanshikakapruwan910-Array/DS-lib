#include"array.hpp"
#include <iostream>
using namespace std;

#define MAX 100

class Array2D
{
public:

    // Insert at beginning
    int INSERT_AT_Begin2D(int arr[MAX][MAX], int &r, int c)
    {
        if (r >= MAX || c <= 0 || c > MAX)
            return r;

        cout << "Enter new row elements: ";
        for (int j = 0; j < c; j++)
            cin >> arr[r][j];

        for (int i = r; i > 0; i--)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i - 1][j];

        // The new row must be entered after shifting.
        cout << "Enter new row elements again: ";
        for (int j = 0; j < c; j++)
            cin >> arr[0][j];

        r++;
        return r;
    }

    // Insert at end
    int INSERT_AT_End2D(int arr[MAX][MAX], int &r, int c)
    {
        if (r >= MAX || c <= 0 || c > MAX)
            return r;

        cout << "Enter new row elements: ";
        for (int j = 0; j < c; j++)
            cin >> arr[r][j];

        r++;
        return r;
    }

    // Insert at ith position
    void INSERT_AT_Ith_position2D(
        int arr[MAX][MAX], int &r, int c)
    {
        int pos;

        if (r >= MAX)
        {
            cout << "Array is full.\n";
            return;
        }

        cout << "Enter position: ";
        cin >> pos;

        if (pos < 1 || pos > r + 1)
        {
            cout << "Invalid position.\n";
            return;
        }

        for (int i = r; i >= pos; i--)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i - 1][j];

        cout << "Enter new row elements: ";
        for (int j = 0; j < c; j++)
            cin >> arr[pos - 1][j];

        r++;
    }

    // Insert before element
    void INSERT_Before_element2D(
        int arr[MAX][MAX], int &r, int c)
    {
        int key, pos = -1;

        if (r >= MAX)
        {
            cout << "Array is full.\n";
            return;
        }

        cout << "Enter element: ";
        cin >> key;

        for (int i = 0; i < r && pos == -1; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] == key)
                {
                    pos = i;
                    break;
                }

        if (pos == -1)
        {
            cout << "Element not found.\n";
            return;
        }

        for (int i = r; i > pos; i--)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i - 1][j];

        cout << "Enter new row elements: ";
        for (int j = 0; j < c; j++)
            cin >> arr[pos][j];

        r++;
    }

    // Insert after element
    void INSERT_After_element2D(
        int arr[MAX][MAX], int &r, int c)
    {
        int key, pos = -1;

        if (r >= MAX)
        {
            cout << "Array is full.\n";
            return;
        }

        cout << "Enter element: ";
        cin >> key;

        for (int i = 0; i < r && pos == -1; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] == key)
                {
                    pos = i;
                    break;
                }

        if (pos == -1)
        {
            cout << "Element not found.\n";
            return;
        }

        pos++;

        for (int i = r; i > pos; i--)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i - 1][j];

        cout << "Enter new row elements: ";
        for (int j = 0; j < c; j++)
            cin >> arr[pos][j];

        r++;
    }

    // Delete at beginning
    void DELETE_AT_Begin2D(
        int arr[MAX][MAX], int &r, int c)
    {
        if (r == 0)
        {
            cout << "Array is empty.\n";
            return;
        }

        for (int i = 0; i < r - 1; i++)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i + 1][j];

        r--;
    }

    // Delete at end
    void DELETE_AT_End2D(
        int arr[MAX][MAX], int &r, int c)
    {
        if (r > 0)
            r--;
        else
            cout << "Array is empty.\n";
    }

    // Delete at ith position
    void DELETE_AT_ith_position2D(
        int arr[MAX][MAX], int &r, int c)
    {
        int pos;

        cout << "Enter position: ";
        cin >> pos;

        if (pos < 1 || pos > r)
        {
            cout << "Invalid position.\n";
            return;
        }

        for (int i = pos - 1; i < r - 1; i++)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i + 1][j];

        r--;
    }

    // Delete before element
    void DELETE_Before_element2D(
        int arr[MAX][MAX], int &r, int c)
    {
        int key, pos = -1;

        cout << "Enter element: ";
        cin >> key;

        for (int i = 0; i < r && pos == -1; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] == key)
                {
                    pos = i;
                    break;
                }

        if (pos <= 0)
        {
            cout << "Element not found or no previous row.\n";
            return;
        }

        for (int i = pos - 1; i < r - 1; i++)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i + 1][j];

        r--;
    }

    // Delete after element
    void DELETE_After_element2D(
        int arr[MAX][MAX], int &r, int c)
    {
        int key, pos = -1;

        cout << "Enter element: ";
        cin >> key;

        for (int i = 0; i < r && pos == -1; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] == key)
                {
                    pos = i;
                    break;
                }

        if (pos == -1 || pos == r - 1)
        {
            cout << "Element not found or no next row.\n";
            return;
        }

        for (int i = pos + 1; i < r - 1; i++)
            for (int j = 0; j < c; j++)
                arr[i][j] = arr[i + 1][j];

        r--;
    }

    // Display
    void display2D(int arr[MAX][MAX], int r, int c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << arr[i][j] << " ";

            cout << "\n";
        }
    }

    // Update
    void update2D(int arr[MAX][MAX], int r, int c)
    {
        int row, col, value;

        cout << "Enter row and column: ";
        cin >> row >> col;

        if (row < 1 || row > r || col < 1 || col > c)
        {
            cout << "Invalid position.\n";
            return;
        }

        cout << "Enter new value: ";
        cin >> value;

        arr[row - 1][col - 1] = value;
    }

    // Search
    void search2D(int arr[MAX][MAX], int r, int c)
    {
        int key, found = 0;

        cout << "Enter element: ";
        cin >> key;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] == key)
                {
                    cout << "Found at row " << i + 1
                         << ", column " << j + 1 << "\n";
                    found = 1;
                }

        if (!found)
            cout << "Element not found.\n";
    }

    // Reverse all elements
    void reversearray2D(int arr[MAX][MAX], int r, int c)
    {
        int total = r * c;

        for (int i = 0; i < total / 2; i++)
        {
            int r1 = i / c, c1 = i % c;
            int r2 = (total - 1 - i) / c;
            int c2 = (total - 1 - i) % c;

            int temp = arr[r1][c1];
            arr[r1][c1] = arr[r2][c2];
            arr[r2][c2] = temp;
        }
    }

    // Sort
    void sort2D(int arr[MAX][MAX], int r, int c)
    {
        int total = r * c;

        for (int i = 0; i < total - 1; i++)
            for (int j = 0; j < total - i - 1; j++)
            {
                int r1 = j / c, c1 = j % c;
                int r2 = (j + 1) / c;
                int c2 = (j + 1) % c;

                if (arr[r1][c1] > arr[r2][c2])
                {
                    int temp = arr[r1][c1];
                    arr[r1][c1] = arr[r2][c2];
                    arr[r2][c2] = temp;
                }
            }
    }

    // Display even elements
    void displayeven2D(int arr[MAX][MAX], int r, int c)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] % 2 == 0)
                    cout << arr[i][j] << " ";

        cout << "\n";
    }

    // Display odd elements
    void displayodd2D(int arr[MAX][MAX], int r, int c)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] % 2 != 0)
                    cout << arr[i][j] << " ";

        cout << "\n";
    }

    // Count even and odd elements
    void countevenodd2D(
        int arr[MAX][MAX], int r, int c)
    {
        int even = 0, odd = 0;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (arr[i][j] % 2 == 0)
                    even++;
                else
                    odd++;

        cout << "Even elements: " << even << "\n";
        cout << "Odd elements: " << odd << "\n";
    }
};
