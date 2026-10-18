#include<iostream>
#include "stack.h"
using namespace std;
Stack::Stack()
{
    top = -1;
}

bool Stack::isFull()
{
    return top ==99;
}

bool Stack::isEmpty()
{
    return top == -1;
}

int Stack::getTop()
{
    if(isEmpty())
    {
        cout<<"stack is empty"<<endl;
        return top +1;
    }
    return s[top];
}

void Stack::push()
{
    int x;
    if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    cout<<"Enter a element:";
    cin>>x;
    s[++top] = x;
    cout<<"Pushed element: "<< x <<endl;
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    int x= s[top--];
    cout<<"Popped element: "<< x <<endl;
    return x;
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    cout<<"Top element: "<<s[top]<<endl;
    return s[top];
}

void Stack::display()
{
    if(isEmpty())
    {
    cout<<"Stack is empty"<<endl;
    }
    cout<<"Elements present in stack";
    for(int i = top;i>=0;i--)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

int Stack::size()
{
    return top+1;
}

void Stack::clear()
{
    top = -1;
    cout<<"stack is cleared successfully"<<endl;
}

void operatestack()
{
    Stack st;
    int ch;
    do
    {
      cout<<"~~~~~~STACK MENU~~~~~~~~"<<endl;
      cout<<"----1. PUSH----\n----2. POP----\n----3. PEEK----\n----4. DISPLAY----\n----5. CHECK EMPTY----\n"<<endl;
      cout<<"----6.CHECK FULL----\n----7.GET TOP ELEMENT----\n----8.SIZE----\n----9.CLEAR STACK----\n----10.EXIT----"<<endl;
      cout<<"Enter your choice"<<endl;
      cin>>ch;
      switch(ch)
      {
        case 1:
         st.push();
         break;
        case 2:
         st.pop();
         break;
        case 3:
         st.peek();
         break;
        case 4:
         st.display();
         break;
        case 5:
          if(st.isEmpty())
            cout<<"Stack is empty"<<endl;
          else 
            cout<<"Stack is not empty"<<endl;
           break;
        case 7:
           if(!st.isEmpty())
              cout<<"Top Element: "<<st.getTop()<<endl;
           else 
              cout<<"Stack is empty"<<endl;
           break;
        case 8:
           cout<<"Number of elements";
           cout<<st.size()<<endl;
           break;
        case 9:
           st.clear();
           break;      
        case 10:
         cout<<"~~~~~Exiting menu~~~~~"<<endl;
         break;
        default:
         cout<<"Invalid choice";
      }

    } while (ch!=10);
}
