#include<iostream>
#include"array.h"

using namespace std;

void displayeven(int arr[], int n)
{
    int i;
    cout<<"Even elements: ";
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            cin>>arr[i];
        }
    }
}

void displayodd(int arr[], int n)
{
    int i;
    cout<<"Odd elements: ";
    for(i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            cout<<arr[i];
        }
    }
}

void countevenodd(int arr[], int n)
{
    int i , even=0,odd=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            even++;
        else
            odd++;
    }
    cout<<"Number of even elements:"<<even;
    cout<<"Number of odd elements:"<<odd;
}
