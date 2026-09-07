#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h>  
#include"queue.h"
struct queue
{
    int *arr,front,rear;
    size_t _size;
};

struct queue *newqueue(size_t _size)
{
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue)); 
    if(temp==NULL)
    return NULL;
    temp->arr=(int *)malloc(sizeof(int)*_size);   
    if(temp->arr== NULL)
    {
        free (temp);
        return NULL;
    }
    temp->_size=_size;  
    temp->front=temp->rear=-1;   
    return temp;
}

int isfull(struct queue *q)
{
    return (q->rear+1) % q->_size==q->front;     
}

int isempty(struct queue *q)
{
    return (q->rear==-1);
}

int front(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue underflow\n");
        return INT_MIN;
    }
    printf("%d\n",q->arr[q->front]);
    return q->arr[q->front];
}

void enque(struct queue *q,int data)
{
    if(isfull(q))
    {
        printf("queue overflow\n");
        return ;
    }
    else if(isempty(q))
    {
        q->front=q->rear=0;
        q->arr[q->rear]=data;
        return ;
    }
    else
    {
        q->rear=(q->rear+1) % q->_size;
        q->arr[q->rear]=data;
        return;
    }
}

void deque(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue underflow");
        return;
    }
    else
    {
        if(q->rear==q->front)
        {
            q->front=q->rear=-1;
            return ;
        }
        q->front=(q->front+1) % q->_size;
    }
}

void print(struct queue *q)
{
    if(isempty(q))
    {
        return ;
    }
    int i;
    for(i=q->front; i!=q->rear ;i=(i+1)%q-> _size)
    {
        printf("%d->",q->arr[i]);
    }
    printf("%d\n",q->arr[i]);
    printf("\n");
}
int operateQueue()
{
    struct queue *q=newqueue(5);
    int ch,data;
    while(1)
    {
        printf("\n-------QUEUE MENU DRIVEN-------\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.front\n");
        printf("4.print queue\n");
        printf("5.exit\n");
        printf("enter your choice: \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter data");
            scanf("%d",&data);
            enque(q,data);
            break;

            case 2:
            deque(q);
            break;

            case 3:
            front(q);
            break;

            case 4:
            print(q);
            break;

            case 5:
            free(q->arr);
            free(q);
            printf("program ended\n");
            return 0;

            default:
            printf("invalid choice");
        }
    }
}
int main()
{
    return operateQueue();
}
