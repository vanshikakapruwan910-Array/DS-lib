#ifndef ARRAY_HPP
#define ARRAY_HPP
#define MAX 100

int INSERT_AT_Begin(int arr[],int *n);
int INSERT_AT_End(int arr[],int *n);
void INSERT_AT_Ith_position(int arr[],int *n);
void INSERT_Before_element(int arr[],int *n);
void INSERT_After_element(int arr[],int *n);


void DELETE_AT_Begin(int arr[],int *n);
void DELETE_AT_End(int arr[],int *n);
void DELETE_AT_ith_position(int arr[],int *n);
void DELETE_Before_element(int arr[],int *n);
void DELETE_After_element(int arr[],int *n);


void display(int arr[],int *n);
void update(int arr[],int *n);
void search(int arr[],int *n);
void reversearray(int arr[],int *n);
void sort(int arr[],int *n);

void displayeven(int arr[],int *n);
void displayodd(int arr[],int *n);
void countevenodd(int arr[],int *n);


int INSERT_AT_Begin2D(int arr[MAX][MAX], int r, int c);
int INSERT_AT_End2D(int arr[MAX][MAX], int r, int c);

void INSERT_AT_Ith_position2D(int arr[MAX][MAX], int r, int c);
void INSERT_Before_element2D(int arr[MAX][MAX], int r, int c);
void INSERT_After_element2D(int arr[MAX][MAX] ,int r, int c);

void DELETE_AT_Begin2D(int arr[MAX][MAX], int r, int c);
void DELETE_AT_End2D(int arr[MAX][MAX], int r, int c);
void DELETE_AT_ith_position2D(int arr[MAX][MAX], int r, int c);
void DELETE_Before_element2D(int arr[MAX][MAX], int r, int c);
void DELETE_After_element2D(int arr[MAX][MAX], int r, int c);

void display2D(int arr[MAX][MAX], int r, int c);
void update2D(int arr[MAX][MAX], int r, int c);
void search2D(int arr[MAX][MAX], int r, int c);
void reversearray2D(int arr[MAX][MAX], int r, int c);
void sort2D(int arr[MAX][MAX], int r, int c);

void displayeven2D(int arr[MAX][MAX], int r, int c);
void displayodd2D(int arr[MAX][MAX], int r, int c);
void countevenodd2D(int arr[MAX][MAX], int r, int c);

#endif
