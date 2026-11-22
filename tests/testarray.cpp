#include <iostream>
#include "array.hpp"
using namespace std;

int main()
{
    Array2D a;

    int values[3][3] = {
        {10, 5, 30},
        {20, 15, 40},
        {8, 25, 12}
    };

    cout << "\nTEST 1: INITIALIZATION\n";
    a.initialize2D(values, 3, 3);
    a.display2D();

    cout << "\nTEST 2: UPDATE\n";
    a.update2D();

    cout << "\nTEST 3: SEARCH\n";
    a.search2D();

    cout << "\nTEST 4: INSERT ROW AT BEGINNING\n";
    a.insertRowAtBegin();
    a.display2D();

    cout << "\nTEST 5: INSERT ROW AT END\n";
    a.insertRowAtEnd();
    a.display2D();

    cout << "\nTEST 6: DELETE ROW AT BEGINNING\n";
    a.deleteRowAtBegin();
    a.display2D();

    cout << "\nTEST 7: DELETE ROW AT END\n";
    a.deleteRowAtEnd();
    a.display2D();

    cout << "\nTEST 8: REVERSE ARRAY\n";
    a.reversearray2D();
    a.display2D();

    cout << "\nTEST 9: SORT ARRAY\n";
    a.sort2D();
    a.display2D();

    cout << "\nTEST 10: DISPLAY EVEN ELEMENTS\n";
    a.displayeven2D();

    cout << "\nTEST 11: DISPLAY ODD ELEMENTS\n";
    a.displayodd2D();

    cout << "\nTEST 12: COUNT EVEN AND ODD\n";
    a.countevenodd2D();

    return 0;
}