
#include <iostream>
#include "array.hpp"
using namespace std;

Array2D::Array2D()
{
    r = 0;
    c = 0;
}

void Array2D::initialize2D(const int values[][3], int rows, int cols)
{
    if (rows < 0 || rows > MAX || cols < 1 || cols > 3)
    {
        cout << "Invalid 2D array dimensions.\n";
        return;
    }

    r = rows;
    c = cols;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = values[i][j];
}

void Array2D::display2D() const
{
    if (r == 0 || c == 0)
    {
        cout << "2D array is empty.\n";
        return;
    }

    cout << "2D Array:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void Array2D::update2D()
{
    int row, col, value;

    cout << "Enter row index (0 to " << r - 1 << "): ";
    cin >> row;
    cout << "Enter column index (0 to " << c - 1 << "): ";
    cin >> col;

    if (row < 0 || row >= r || col < 0 || col >= c)
    {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter new value: ";
    cin >> value;
    arr[row][col] = value;
}

void Array2D::search2D() const
{
    int value;
    cout << "Enter element to search: ";
    cin >> value;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (arr[i][j] == value)
            {
                cout << "Found at row " << i
                     << ", column " << j << ".\n";
                return;
            }

    cout << "Element not found.\n";
}

void Array2D::reversearray2D()
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

    cout << "2D array elements reversed.\n";
}

void Array2D::sort2D()
{
    int total = r * c;

    for (int i = 0; i < total - 1; i++)
        for (int j = 0; j < total - 1 - i; j++)
        {
            int r1 = j / c, c1 = j % c;
            int r2 = (j + 1) / c, c2 = (j + 1) % c;

            if (arr[r1][c1] > arr[r2][c2])
            {
                int temp = arr[r1][c1];
                arr[r1][c1] = arr[r2][c2];
                arr[r2][c2] = temp;
            }
        }

    cout << "2D array sorted in row-major order.\n";
}

void Array2D::insertRowAtBegin()
{
    if (r >= MAX || c == 0)
    {
        cout << "Cannot insert row.\n";
        return;
    }

    for (int i = r; i > 0; i--)
        for (int j = 0; j < c; j++)
            arr[i][j] = arr[i - 1][j];

    cout << "Enter " << c << " values for the new row: ";
    for (int j = 0; j < c; j++)
        cin >> arr[0][j];

    r++;
}

void Array2D::insertRowAtEnd()
{
    if (r >= MAX || c == 0)
    {
        cout << "Cannot insert row.\n";
        return;
    }

    cout << "Enter " << c << " values for the new row: ";
    for (int j = 0; j < c; j++)
        cin >> arr[r][j];

    r++;
}

void Array2D::deleteRowAtBegin()
{
    if (r == 0)
    {
        cout << "2D array is empty.\n";
        return;
    }

    for (int i = 0; i < r - 1; i++)
        for (int j = 0; j < c; j++)
            arr[i][j] = arr[i + 1][j];

    r--;
}

void Array2D::deleteRowAtEnd()
{
    if (r == 0)
    {
        cout << "2D array is empty.\n";
        return;
    }

    r--;
}

void Array2D::displayeven2D() const
{
    cout << "Even elements: ";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (arr[i][j] % 2 == 0)
                cout << arr[i][j] << " ";
    cout << endl;
}

void Array2D::displayodd2D() const
{
    cout << "Odd elements: ";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (arr[i][j] % 2 != 0)
                cout << arr[i][j] << " ";
    cout << endl;
}

void Array2D::countevenodd2D() const
{
    int even = 0, odd = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] % 2 == 0)
                even++;
            else
                odd++;
        }

    cout << "Even count: " << even << endl;
    cout << "Odd count: " << odd << endl;
}

void Array2D::operate2DArray()
{
    int choice;

    do
    {
        cout << "\n--- 2D ARRAY MENU ---\n";
        cout << "1. Display\n";
        cout << "2. Update element\n";
        cout << "3. Search element\n";
        cout << "4. Reverse elements\n";
        cout << "5. Sort elements\n";
        cout << "6. Insert row at beginning\n";
        cout << "7. Insert row at end\n";
        cout << "8. Delete row at beginning\n";
        cout << "9. Delete row at end\n";
        cout << "10. Display even elements\n";
        cout << "11. Display odd elements\n";
        cout << "12. Count even and odd\n";
        cout << "0. Back to main menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: display2D(); break;
            case 2: update2D(); display2D(); break;
            case 3: search2D(); break;
            case 4: reversearray2D(); display2D(); break;
            case 5: sort2D(); display2D(); break;
            case 6: insertRowAtBegin(); display2D(); break;
            case 7: insertRowAtEnd(); display2D(); break;
            case 8: deleteRowAtBegin(); display2D(); break;
            case 9: deleteRowAtEnd(); display2D(); break;
            case 10: displayeven2D(); break;
            case 11: displayodd2D(); break;
            case 12: countevenodd2D(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
