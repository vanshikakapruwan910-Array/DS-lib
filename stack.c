#include<stdio.h>
#define max 10
int push(int[],int);
int pop(int[],int);
void peek(int[],int);
void display(int[],int);

int operateStack(){
    int s[max],top = -1,ch;
    do{
        printf("----------Enter a choice----------\n ~~~~~1.Push~~~~~\n~~~~~2.Pop~~~~~\n~~~~~3.Peek~~~~~\n~~~~~4.Display~~~~~\n");
        scanf("%d", &ch);
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
        }
    }while(ch<=4);
}

int push(int s[],int top)
{
    int x;
    if(top== max-1)
    {
        printf("----------Stack is overflow----------\n");
    }
    else{
        printf("~~~~~~Enter the value~~~~~~\n");
        scanf("%d", &x);
        top++;
        s[top] = x;
    }
     return top;
}

int pop(int s[], int top)
{
    if(top == -1)
    {
        printf("----------Stack is underflow----------\n");
        return top;
    }
    else{
        printf("The poppped element is%d\n", s[top]);
        top--;
    }
      return top;
}


void peek(int s[],int top)
{
    if(top == -1)
    {
        printf("----------Stack is underflow----------\n");
    }   
    else{
        printf("~~~~~The top element of the stack is~~~~~~%d\n", s[top]);
       
    }
     return;
}


void display(int s[],int top)
{
    int i;
    if(top == -1)
    {
        printf("----------Stack is underflow----------\n");
    }  
    else{
        printf("~~~~~~~~~Elements in the stack~~~~~~~~\n");
        for(i = top;i>=0;i--)
        {
            printf("%d",s[top]);
        }
        printf("\n");
    }    
    return;
}
