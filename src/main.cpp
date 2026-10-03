#include <iostream>
<<<<<<< HEAD
#include <cstdlib.h>
#include "array.hpp"
#include "ll.hpp"
=======
#include <cstdlib>
#include "ll.h"
>>>>>>> 79fb0ffdbdcd68cdf4ae3343780de77a1024780e
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
    int c;
    do{
<<<<<<< HEAD
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
=======
        cout<<"~~~~Enter~~~~"<<endl;
        cout<<"-----1. To operate ARRAY-----"<<endl<<"-----2. To operate on LINKED LIST-----"<<endl<< "-----3. To operate on STACK-----"<< "-----4. To operate on QUEUE-----"<<"-----5. To EXIT-----"<<endl;
        cin>>c;
        switch(c){

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
    cout<<"-----EXIT-----"<<endl;
}
>>>>>>> 79fb0ffdbdcd68cdf4ae3343780de77a1024780e
