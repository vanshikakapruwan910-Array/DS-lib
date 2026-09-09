#include <iostream>
#include <cstdlib.h>
#include "array.hpp"
#include "ll.hpp"
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
    int c;
    do{
        cout << "Enter 1 to operate on array, 2 to operate on linked list, 3 to operate on stack, 4 to operate on queue, and 0 to exit." endl;
        cin >> c;
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
                cout << "Invalid Input" endl;
        }
    }while(c!=0);
    cout << "-----EXIT-----";
}