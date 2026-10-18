#include <iostream>
#include <cstdlib>
#include "ll.h"
#include "stack.h"
#include "q1.h"
#include"array.hpp"
using namespace std;

int main(){
    int c;
    do{
        cout<<"============MENU==========="<<endl;
        cout << "~~~~PRESS~~~~\n----1.To Operate on ARRAY----\n----2.To Operate on LINKED LIST----\n----3.To Operate on STACK\n----4. To Operate on QUEUE----\n5. EXIT----" endl;
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
