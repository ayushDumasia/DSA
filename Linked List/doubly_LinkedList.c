#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *pre;
}node;

node *create(){
    node *newNode = (node *)malloc(sizeof(node));
    int x;
    printf("Enter a Data : ");
    scanf("%d",&x);

    newNode->data = x;
    newNode->next = NULL;
    newNode->pre = NULL;
}

void insertAtBeginning(node **head){
    node *newNode = create();

    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        (*head)->pre = newNode;
        *head = newNode;
    }
}

void display(node **head){
    node *temp = *head;
    if(*head == NULL){
        printf("Linked List is Empty");
    }
    else{
        while(temp != NULL){
            printf("<-%d->",temp->data);
            temp = temp->next;
        }
    }
}

void insertAtEnd(node **head){
    node *newNode = create();
    node *temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->pre = temp;
}

void insertAtpos(node **head){
    int pos, i = 1;
    node *temp = *head;
    printf("Enter a Position , You want to insert a Value : ");
    scanf("%d",&pos);
    node *newNode = create();

    if(*head == NULL){
        insertAtBeginning(&head);
    }
    else{
        while(i < pos - 1){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->pre = temp;
        temp->next->pre = newNode;
        temp->next = newNode;
    }
}

void deleteHead(node **head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    else{
        *head = (*head)->next; 
        (*head)->pre = NULL;
    }
}

void deleteAtEnd(node **head){
    node *temp = *head;
    node *preNode = NULL;
    while(temp->next != NULL){
        preNode = temp;
        temp = temp->next;
    }
    preNode->next = NULL;
    free(temp);
}

void deleteAtPos(node **head){
    int pos, i = 1;
    node *temp = *head;
    node *preNode = NULL;
    printf("Enter a Position , You want to delete  : ");
    scanf("%d",&pos);

    while(i < pos && temp != NULL){
        preNode = temp;
        temp = temp->next;
        i++;
    }

    preNode->next = temp->next;
    temp->next->pre = preNode;

}


int main(){

node *head = NULL;
          
insertAtBeginning(&head);
// insertAtBeginning(&head);
// insertAtBeginning(&head);
// insertAtBeginning(&head);
// insertAtBeginning(&head);
insertAtEnd(&head);
insertAtEnd(&head);
insertAtEnd(&head);
insertAtEnd(&head);
insertAtEnd(&head);
// deleteHead(&head);
// deleteAtEnd(&head);
deleteAtPos(&head);
// insertAtpos(&head);
display(&head);
               
return 0;
}