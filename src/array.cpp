#include<iostream>
#include"array.hpp"

using namespace std;

void display(int arr[],int *n)
{
    int i;
    cout<<"Array: ";
    for(i=0;i< *n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}

void update(int arr[], int *n)
{
    int pos,x;
    cout<<"Enter position to update: ";
    cin>>pos;
    if(pos < 1 || pos > *n)
    {
        cout<<"Invalid position\n";
        return;
    }
    cout<<"enter new element: ";
    cin>>x;
    arr[pos-1]= x;
}

void search(int arr[],int *n)
{
    int x,i,found=0;
    cout<<"Enter element to search: ";
    cin>>x;

    for(i=0;i< *n;i++)
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

void reversearray(int arr[], int *n)
{
    int i,temp;
    cout<<"Reversed array : ";
    for(i=0;i< *n/2;i++)
    {
        temp = arr[i];
        arr[i] = arr[*n-i-1];
        arr[*n-i-1] = temp;
    }
    cout<<"Array reversed"<<endl;
    display(arr,n);

}

void sort(int arr[], int *n)
{
    int i,j ,temp,ch;
    cout<<"1.Ascending Order: ";
    cout<<"2.Descending Order: ";

    cout<<"\nEnter your choice:";
    cin>>ch;
    if(ch == 1)
    {
        for(i=0;i<(*n);i++)
        {
            if(ch==1 && arr[i]>arr[i+1])
            {
                temp = arr[i];
                arr[i] =  arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    else
    {
        for(i=0;i< *n;i++)
        {
            if(ch==2 && arr[i]<arr[i+1])
            {
                temp = arr[i];
                arr[i] =  arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    cout<<"Sorted array: ";
    display(arr,n);
}




void DELETE_AT_Begin(int arr[], int *n)
{
    if (*n <= 0)
    {
        cout << "Array is empty";
        return;
    }

    for (int i = 0; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;

    cout << "Element deleted from beginning";
}

void DELETE_AT_End(int arr[], int *n)
{
    if (*n <= 0)
    {
        cout << "Array is empty";
        return;
    }

    (*n)--;

    cout << "Element deleted from end";
}

void DELETE_AT_ith_position(int arr[], int *n)
{
    int pos;
    if ((*n) <= 0)
    {
        cout << "Array is empty";
        return;
    }
    cout << "Enter position: ";
    cin >> pos;
    if (pos < 1 || pos > (*n))
    {
        cout << "Invalid position"<<endl;
        return;
    }
    for (int i = pos - 1; i < (*n) - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    cout << "Element deleted from position " << pos;
}

void DELETE_Before_element(int arr[], int *n)
{
    int e, pos = -1;
    if ((*n) <= 0)
    {
        cout << "Array is empty.";
        return;
    }
    cout << "Enter element to delete: ";
    cin >> e;
    for (int i = 0; i < (*n); i++)
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
    for (int i = pos - 1; i < (*n)- 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    cout << "Element before " << e << " deleted";
}


void DELETE_After_element(int arr[], int *n)
{
    int e, pos = -1;
    if ((*n) <= 0)
    {
        cout << "Array is empty";
        return;
    }
    cout << "Enter element to delete: ";
    cin >> e;
    for (int i = 0; i < (*n); i++)
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
    if (pos == (*n)- 1)
    {
        cout << "No element exists after " << e;
        return;
    }
    for (int i = pos + 1; i < (*n)- 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    cout << "Element after " << e << " deleted";
}


int INSERT_AT_Begin(int arr[], int *n)
{
    int x, i;
    cout<<"Enter element: ";
    cin>>x;
    for(i = (*n); i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = x;

    (*n)++;

    return *n;
}


int INSERT_AT_End(int arr[], int *n)
{
    int x;

    cout<<"Enter element: ";
    cin>>x;

    arr[*n] = x;

    (*n)++;

    return *n;
}

void INSERT_AT_Ith_position(int arr[],int *n)
{
    int i,pos,ind,x;
    cout<<"Enter elements: ";
    for(i=0;i< *n;i++)
    {
        scanf("%d", &arr[i]);
    }
    cout<<"Enter the index you want to add element in: ";
    cin>>ind;
    cout<<"Enter value to insert: ";
    cin>>x;
    if(ind<0||ind> *n)
    {
        cout<<"Invalid position.";
        return;
    }
    for(i= *n;i>ind;i--)
    {
        arr[i]= arr[i-1];
    }
    arr[ind]= x;
    (*n)++;
    cout<<"Final array after insertion: ";
    for(i=0;i< *n;i++)
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


void displayeven(int arr[], int *n)
{
    int i;
    cout<<"Even elements: ";
    for(i=0;i< (*n);i++)
    {
        if(arr[i]%2==0)
        {
            cin>>arr[i];
        }
    }
}


void displayodd(int arr[], int *n)
{
    int i;
    cout<<"Odd elements: ";
    for(i=0;i< *n;i++)
    {
        if(arr[i]%2!=0)
        {
            cout<<arr[i];
        }
    }
}

void countevenodd(int arr[], int *n)
{
    int i , even=0,odd=0;
    for(i=0;i< *n;i++)
    {
        if(arr[i]%2==0)
            even++;
        else
            odd++;
    }
    cout<<"Number of even elements:"<<even;
    cout<<"Number of odd elements:"<<odd;
}
