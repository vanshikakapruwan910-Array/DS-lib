#include <iostream>
#include <cstdlib>
<<<<<<< HEAD
#include "array.hpp"
#include"linkedlist.h"
#include "ll.hpp"
=======
#include "ll.h"
>>>>>>> 29d38a0d585a17784f47325cf6f3c88d0ec0a22d
#include "stack.h"
#include "q1.h"
#include"array.hpp"
using namespace std;

int main(){
    int c;
    do{
<<<<<<< HEAD
        cout << "Enter 1 to operate on array, 2 to operate on linked list, 3 to operate on stack, 4 to operate on queue, and 0 to exit." endl;
=======
        cout<<"============MENU==========="<<endl;
        cout << "~~~~PRESS~~~~\n----1.To Operate on ARRAY----\n----2.To Operate on LINKED LIST----\n----3.To Operate on STACK\n----4. To Operate on QUEUE----\n5. EXIT----" endl;
>>>>>>> 29d38a0d585a17784f47325cf6f3c88d0ec0a22d
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
            case 5:
                break;
            default:
                cout << "Invalid Input" endl;
        }
    }while(c!=0);
    cout << "-----EXIT-----";
}
<<<<<<< HEAD
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
=======
>>>>>>> 29d38a0d585a17784f47325cf6f3c88d0ec0a22d
