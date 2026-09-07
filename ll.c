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

void insertAfterK(struct Node** head, int data, int k){
    struct Node* new=makeNode(data);
    if (*head==NULL){
        *head=new;
        return;
    }
    struct Node* temp=*head;
    while(temp != NULL && temp->data != k)
        temp=temp->next;

    if(temp==NULL){
        free(new);
        return;
    }
    new->next=temp->next;
    temp->next=new;
}

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

void deleteValueK(struct Node** head, int k){
    if(*head==NULL){
        printf("Empty linked list.\n");
        return;
    }
    struct Node* temp=*head;
    if(temp->data==k){
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp->next!=NULL && temp->next->data!=k){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Value not found.\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void searchLL(struct Node* head, int data){
    struct Node* temp=head;
    int i=0,f=0;
    while(temp!=NULL){
        if(temp->data){
            printf("Found at index %d.\n",i);
            f=1;
        }
        temp=temp->next;
        i++;
    }
    if(!f)
        printf("Given value not found in linked list.\n");
    
}

void lengthLL(struct Node* head){
    struct Node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    printf("Length of linked list: %d\n",c);
}

int operateLL(){
    int c,d,k;
    struct Node *a=NULL;
    do{
        printf("Enter: 0 to display LL\n1 to insert at begin\n2 to insert at end\n3 to insert before k\n4 to inser after k\n5 to insert at i\n6 to delete at begin\n7 to delete at end\n8 to delete at i\n9 to delete node having value k\n10 to search the linked list for a value\n11 to find the length of the linked list\n-1 to exit.\n");
        scanf("%d",&c);
        switch(c){
            case 0:
                displayLL(a);
                break;
            case 1:
                printf("Enter data to insert.\n");
                scanf("%d",&d);
                insertAtBegin(&a,d);
                printf("Element inserted.\n");
                break;
            case 2:
                printf("Enter data to insert.\n");
                scanf("%d",&d);
                insertAtEnd(&a,d);
                printf("Element inserted.\n");
                break;
            case 3:
                printf("Enter data to insert and k.\n");
                scanf("%d %d",&d,&k);
                insertBeforeK(&a,d,k);
                printf("Element inserted.\n");
                break;
            case 4:
                printf("Enter data to insert and k.\n");
                scanf("%d %d",&d,&k);
                insertAfterK(&a,d,k);
                printf("Element inserted.\n");
                break;
            case 5:
                printf("Enter data to insert and i.\n");
                scanf("%d %d",&d,&k);
                insertAtI(&a,d,k);
                printf("Element inserted.\n");
                break;
            case 6:
                deleteAtBegin(&a);
                printf("Element deleted.\n");
                break;
            case 7:
                deleteAtEnd(&a);
                printf("Element deleted.\n");
                break;
            case 8:
                printf("Enter i.");
                scanf("%d",&k);
                deleteAtI(&a,k);
                printf("Element deleted.\n");
                break;
            case 9:
                printf("Enter k.\n");
                scanf("%d",&k);
                deleteValueK(&a,k);
                printf("Element deleted.\n");
                break;
            case 10:
                printf("Enter value to find.\n");
                scanf("%d",&k);
                searchLL(a,k);
                break;
            case 11:
                lengthLL(a);
                break;
            default:
                printf("Invalid Input\n");
        }
    }while(c!=-1);
    return 0;
}