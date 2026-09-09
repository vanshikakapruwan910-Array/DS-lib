#include <iostream>
#include <cstdlib>
#include "ll.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
    int c;
    do{
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
