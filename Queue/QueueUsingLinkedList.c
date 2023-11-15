#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

node *create(){
    int x;
    printf("Enter a data : ");
    scanf("%d",&x);

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
}

void enQueue(node **top){
    node *newNode = create();
    node *temp = *top;

    if(*top == NULL){
        *top = newNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



void display(node **top){
    if(*top == NULL){
        printf("Stack is Empty\n");
    }
    else{
        node *temp = *top;
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

void deQueue(node **top){
    if(*top == NULL){
        printf("Stack is Empty\n");
    }
    else{
        node *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

void peep(node **top){
    printf("%d",(*top)->data);
}

int main(){
node *top = NULL;

enQueue(&top);
enQueue(&top);
enQueue(&top);
enQueue(&top);
enQueue(&top);
deQueue(&top);
peep(&top);
display(&top);


return 0;
}