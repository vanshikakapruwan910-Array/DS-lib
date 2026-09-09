#include<iostream>
#include"array.h"

using namespace std;

void display(int arr[],int n)
{
    int i;
    cout<<"Array: ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    cout<<"\n";
}

void update(int arr[], int n)
{
    int pos,x;
    cout<<"Enter position to update: ";
    cin>>pos;
    if(pos < 1 || pos > n)
    {
        cout<<"Invalid position\n";
        return;
    }
    cout<<"enter new element: ";
    cin>>x;
    arr[pos-1]=x;
}

void search(int arr[],int n)
{
    int x,i,found=0;
    cout<<"enter element to search: ";
    cin>>x;

    for(i=0;i<n;i++)
    {
        if(arr[i] == x)
        {
            cout<<"Element found at the position \n"<<i+1;
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        cout<<"Element not found\n";
    }
}

void reversearray(int arr[], int n)
{
    int i,temp;
    cout<<"Reversed array : ";
    for(i=0;i<n/2;i++)
    {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

void sort(int arr[], int n)
{
    int i,j ,temp,ch;
    cout<<"1.Ascending Order: ";
    cout<<"2.Descending Order: ";

    cout<<"\nEnter your choice:";
    cin>>ch;
    for(i=0;i<n;i++)
    {
        if(ch==1 && arr[i]>arr[i+1])
        {
            temp = arr[i];
            arr[i] =  arr[i+1];
            arr[i+1] = temp;
        }
    }
    for(i=0;i<n;i++)
    {
        if(ch==2 && arr[i]<arr[i+1])
        {
            temp = arr[i];
            arr[i] =  arr[i+1];
            arr[i+1] = temp;
        }
    }
    cout<<"Sorted array: ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}




