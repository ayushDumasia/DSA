#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create(){
    int x;
    printf("Enter the value: ");
    scanf("%d", &x);

    node *new = (node *)malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    return new;
}

void insertInorder(node **head){
    node *temp = *head, *new = create() ,*prev= NULL;

    while((temp != NULL) && (new->data >= temp->data)){
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL){
        new->next = *head;
        *head = new;
    }
    else{
        prev->next = new;
        new->next = temp;
    }
}

void insertAtBeginning(node **head){
    node *new = create();

    new->next = *head;
    *head = new;
}

void insertAtEnd(node **head){
    node *temp,*new = create();
    if(head == NULL){
        *head = new;
    }
    else {
        temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}


void insertInPos(node **head){
    int pos, i = 1;
    printf("Enter a position to insert : ");
    scanf("%d",&pos);



    if(pos == 1){
        insertAtBeginning(&head);
    }
    else {
        node *new = create();
        node *temp = *head;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        new->next = temp->next;
        temp->next = new;
    }
}

void display(node **head){
    node *temp = *head;
    if(*head == NULL){
        printf("Linked List is Empty\n");
    }
    while(temp != NULL){
        printf("%d:%p-> ",temp->data , temp->next);
        temp = temp->next;
    }
    printf("NULL\n");

}
void deleteHead(node **head){
    if(*head == NULL){
        printf("Linked List is empty\n");
    }
    else {
        node *temp = *head;
        *head = (*head)->next;  
        free(temp);
    }
}

void deleteEnd(node **head){
    node *temp = *head;
    node *preNode = NULL;

    while(temp->next != NULL){
        preNode = temp;
        temp = temp->next;
    }

    if(temp == *head){
        *head = NULL;
        free(temp);
    }
    else{
        preNode->next = NULL;
        free(temp);
    }
}


void deleteAtPos(node **head){
    node *temp = *head;
    node *newnode;
    int pos, i = 1;
    printf("Enter a position to insert : ");
    scanf("%d",&pos);

    while(i < pos -1){
        temp = temp->next;
        i++;
    }

    newnode = temp->next;
    temp->next = newnode->next;

    free(newnode);
}

void findLength(node **head){
    node *temp = *head;
    int count = 0 ;
    
    while (temp != NULL){
        temp = temp->next;
        count++;
    }

    printf("Lenght : %d\n",count );
}

int main(){
    node *head = NULL;

    insertAtBeginning(&head);
    insertAtBeginning(&head);
    insertAtBeginning(&head);
    insertAtBeginning(&head);
    insertAtBeginning(&head);
    deleteHead(&head);
    deleteHead(&head);
    deleteHead(&head);
    deleteHead(&head);
    deleteHead(&head);
    deleteHead(&head);
    display(&head);


return 0;
}


