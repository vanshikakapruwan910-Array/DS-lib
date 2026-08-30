#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* makeNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    return new;
}

void displayLL(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insertAtBegin(struct Node** head, int data){
    struct Node* new=makeNode(data);
    new->next=*head;
    *head=new;
}

void insertAtEnd(struct Node** head, int data){
    struct Node* new=makeNode(data);
    if (*head==NULL){
        *head=new;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}

void insertBeforeK(struct Node** head, int data, int k){
    struct Node* new=makeNode(data);
    if (*head==NULL){
        *head=new;
        return;
    }
    if((*head)->data==k){
        new->next=*head;
        *head=new;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL && temp->next->data!=k){
        temp=temp->next;
    }
    if(temp->next==NULL){
        free(new);
        return;
    }
    new->next=temp->next;
    temp->next=new;
}

/*void insertAfterK(struct Node** head, int data, int k){
    struct Node* new=makeNode(data);
    if (*head==NULL){
        *head=new;
        return;
    }
    if((*head)->data==k){
        new->next=*head;
        *head=new;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL && temp->next->data != k){
        temp=temp->next;
    }
    if(temp->next==NULL){
        free(new);
        return;
    }
    new->next=temp->next;
    temp->next=new;
}*/

void insertAtI(struct Node** head, int data, int pos){
    struct Node* new=makeNode(data);
    if (pos==0){
        insertAtBegin(head,data);
        return;
    }
    struct Node* temp=*head;
    for(int i=0;temp!=NULL && i<pos-1;i++){
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("pos out of range\n");
        free(new);
        return;
    }
    new->next = temp->next;
    temp->next = new;
}

void deleteAtBegin(struct Node** head){
    if(*head==NULL){
        printf("Empty linked list.\n");
        return;
    }
    struct Node* temp=*head;
    *head=temp->next;
    free(temp);
}

void deleteAtEnd(struct Node** head){
    if (*head==NULL){
        printf("Empty linked list.\n");
        return;
    }
    struct Node* temp = *head;
    if(temp->next==NULL){
        free(temp);
        *head=NULL;
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleteAtI(struct Node** head, int pos){
    if(*head==NULL){
        printf("Empty linked list.\n");
        return;
    }
    struct Node* temp=*head;
    if(pos==0){
        deleteAtBegin(head);
        return;
    }
    for(int i=0;temp!=NULL && i<pos-1;i++){
        temp = temp->next;
    }
    if(temp==NULL||temp->next==NULL){
        printf("Position is out of range.\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main(){
    int c,d,k;
    struct Node *a=NULL;
    do{
        printf("Enter 0 to display LL, 1 to insert at begin, 2 to insert at end, 3 to insert before k, 4 to inser after k, 5 to insert at i, 6 to delete at begin, 7 to delete at end, 8 to delete at i, -1 to exit.");
        scanf("%d",&c);
        switch(c){
            case 0:
                displayLL(a);
                break;
            case 1:
                printf("Enter data to insert.");
                scanf("%d",&d);
                insertAtBegin(&a,d);
                break;
            case 2:
                printf("Enter data to insert.");
                scanf("%d",&d);
                insertAtEnd(&a,d);
                break;
            case 3:
                printf("Enter data to insert and k.");
                scanf("%d %d",&d,&k);
                insertBeforeK(&a,d,k);
                break;
            case 4:
                /*printf("Enter data to insert and k.");
                scanf("%d %d",&d,&k);
                insertAfterK(&a,d,k);
                break;*/
            case 5:
                printf("Enter data to insert and i.");
                scanf("%d %d",&d,&k);
                insertAtI(&a,d,k);
                break;
            case 6:
                deleteAtBegin(&a);
                printf("Element deleted.");
                break;
            case 7:
                deleteAtEnd(&a);
                printf("Element deleted.");
                break;
            case 8:
                printf("Enter i.");
                scanf("%d",&k);
                deleteAtI(&a,k);
                break;
            default:
                printf("Invalid Input");
        }
    }while(c!=-1);
}