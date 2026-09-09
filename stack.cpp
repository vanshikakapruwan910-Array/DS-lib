#include<iostream>
using namespace std;
#define max 10
int push(int[],int);
int pop(int[],int);
void peek(int[],int);
void display(int[],int);

int operateStack(){
    int s[max],top = -1,ch;
    do{
        cout<<"----------Enter a choice----------"<<endl;
        cout<<"~~~~~1.Push~~~~~"<<"~~~~~2.Pop~~~~~"<<"~~~~~3.Peek~~~~~"<<"~~~~~4.Display~~~~~"<<"~~~~~5.Exit~~~~~"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            top = push(s,top);
            break;
            case 2:
            top = pop(s,top);
            break;
            case 3:
            peek(s,top);
            break;
            case 4:
            display(s,top);
            break; 
            case 5:
            exit(0);
            default:
            printf("Invalid Input~~~~~TRY AGAIN!!!!!");
        }
    }while(ch<=5);
}

int push(int s[],int top)
{
    int x;
    if(top== max-1)
    {
        cout<<"----------Stack is overflow----------"<<endl;
    }
    else{
        cout<<"~~~~~~Enter the value~~~~~~"<<endl;
        cin>>x;
        top++;
        s[top] = x;
    }
     return top;
}

int pop(int s[], int top)
{
    if(top == -1)
    {
        cout<<"----------Stack is underflow----------";
        return top;
    }
    else{
        cout<<"The poppped element is: "<< s[top];
        top--;
    }
      return top;
}


void peek(int s[],int top)
{
    if(top == -1)
    {
        cout<<"----------Stack is underflow----------";
    }   
    else{
        cout<<"~~~~~The top element of the stack is~~~~~~"<< s[top];
       
    }
     return;
}


void display(int s[],int top)
{
    int i;
    if(top == -1)
    {
        cout<<"----------Stack is underflow----------"<<endl;
    }  
    else{
        cout<<"~~~~~~~~~Elements in the stack~~~~~~~~"<<endl;
        for(i = top;i>=0;i--)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }    
    return;
}
