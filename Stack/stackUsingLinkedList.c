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

void push(node **top){
    node *newNode = create();

    newNode->next = *top;
    *top = newNode;
}

void pop(node **top){
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
    printf("Peep Element : %d\n",(*top)->data);
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


int main(){
node *top = NULL;

push(&top);
push(&top);
push(&top);
push(&top);
push(&top);
// pop(&top);
// pop(&top);
pop(&top);
pop(&top);
pop(&top);
peep(&top);
display(&top);
               
return 0;
}