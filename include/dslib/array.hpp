
#ifndef ARRAY_HPP
#define ARRAY_HPP

#define MAX 100

class Array
{
private:
    int arr[MAX];
    int n;

public:
    Array();

    void initialize(const int values[], int size);
    void display() const;
    void update();
    void search() const;
    void reversearray();
    void sort();

    void INSERT_AT_Begin();
    void INSERT_AT_End();
    void DELETE_AT_Begin();
    void DELETE_AT_End();

    void displayeven() const;
    void displayodd() const;
    void countevenodd() const;

    int getElement(int index) const;
    int size() const;

    void operateArray();
};

class Array2D
{
private:
    int arr[MAX][MAX];
    int r, c;

public:
    Array2D();

    void initialize2D(const int values[][3], int rows, int cols);
    void display2D() const;
    void update2D();
    void search2D() const;
    void reversearray2D();
    void sort2D();

    void insertRowAtBegin();
    void insertRowAtEnd();
    void deleteRowAtBegin();
    void deleteRowAtEnd();

    void displayeven2D() const;
    void displayodd2D() const;
    void countevenodd2D() const;

    void operate2DArray();
};

#endif
