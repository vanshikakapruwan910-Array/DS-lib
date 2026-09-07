#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "ll.h"
#include "stack.h"
#include "queue.h"

int main(){
    int c;
    do{
        printf("Enter 1 to operate on array, 2 to operate on linked list, 3 to operate on stack, 4 to operate on queue, and 0 to exit.\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                operateArray();
                break;
            case 2:
                operateLL();
                break;
            case 3:
                operateStack();
                break;
            case 4:
                operateQueue();
                break;
            default:
                printf("Invalid Input\n");
        }
    }while(c!=0);
    printf("-----EXIT-----");
}