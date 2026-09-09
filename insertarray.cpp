#include<iostream>
#include"array.h"

using namespace std;

int INSERT_AT_Begin(int arr[], int n)
{
    int x, i;

    cout<<"Enter element: ";
    cin>>x;

    for(i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = x;

    n++;

    return n;
}
int INSERT_AT_End(int arr[], int n)
{
    int x;

    cout<<"Enter element: ";
    cin>>x;

    arr[n] = x;

    n++;

    return n;
}

void INSERT_AT_Ith_position(int arr[],int n)
{
    int i,pos,ind,x;
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    cout<<"Enter the index you want to add element in: ";
    cin>>ind;
    cout<<"Enter value to insert: ";
    cin>>x;
    if(ind<0||ind>n)
    {
        cout<<"Invalid position.";
        return;
    }
    for(i=n;i>ind;i--)
    {
        arr[i]= arr[i-1];
    }
    arr[ind]= x;
    n++;
    cout<<"Final array after insertion: ";
    for(i=0;i<n;i++)
    {
        printf("%d", arr[i]);
    }
}


void INSERT_Before_element(int arr[],int *n)
{
    int e,x,pos= -1,i;
    cout<<"Enter the element before which we need to insert:";
    cin>>e;
    cout<<"Enter value to insert.";
    cin>>x;
    for(i=0;i<*n;i++)
    {
        if(arr[i]==e)
        {
            pos = i;
            break;
        }
    }
    if(pos== -1)
    {
        cout<<"Element"<<e<<"not found";
        return;
    }
    for(int i = *n; i > pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos] = x;
    (*n)++;
    cout<<"Inserted "<<x<<"before"<<e;
}


void INSERT_After_element(int arr[], int *n)
{
    int e, x, pos = -1;
    cout<<"Enter element after which to insert: ";
    cin>>e;
    cout<<"Enter value to insert: ";
    cin>>x;

    for(int i = 0; i < *n; i++) {
        if(arr[i] == e) {
            pos = i;
            break;
        }
    }

    if(pos == -1) {
        cout<<"Element"<<e<<"not found!";
        return;
    }

    // shift from pos+1
    for(int i = *n; i > pos+1; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos+1] = x;
    (*n)++;
    cout<<"Inserted"<<x<<"after"<<e;
}