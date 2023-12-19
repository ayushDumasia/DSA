#include<stdio.h>
#include<time.h>
#define size 5

void push(int st[], int *top){
    int x;

    if(*top >= size - 1){
        printf("ERROR: Stack overflow.\n");
        return ;
    }
    else{
    printf("Enter the value: ");
    scanf("%d", &x);
        (*top)++;
        st[*top] = x;
    }
}

void pop(int st[], int *top){
    if(*top < 0){
        printf("ERROR: Stack Underflow.\n");

    }
    else{
        (*top)--;
    }
}

void peep(int st[], int *top){
    printf("%d", st[*top]);
}

void change(int st[], int *top){ 

    int temp[100], changeIdx, i=0, val;

    label:
    printf("Enter the index at which you want to change the value: ");
    scanf("%d", &changeIdx);
    if(changeIdx > *top){
        printf("ERROR: Index out of bound.\n\n");
        goto label;
    }
    printf("Enter the new value: ");
    scanf("%d", &val);

    while(*top > changeIdx){
        temp[i++] = st[(*top)--];
    }
    st[changeIdx] = val;
    while(i > 0){
        st[++(*top)] = temp[--i];
    }
}

void display(int st[], int *top){
    for(int i = *top; i >= 0; i--){
        printf("%d\n", st[i]);
    }
}

void main(){
    int st[size], top = -1;

    printf("\n---------------Push---------------\n");
    push(st, &top);
    push(st, &top);
    push(st, &top);
    push(st, &top);
    push(st, &top);
    printf("-------------Display--------------\n");
    display(st, &top);
    printf("---------------Pop----------------\n");
    pop(st, &top);
    display(st, &top);
    printf("---------------Peep---------------\n");
    peep(st, &top);
    printf("\n--------------Change--------------\n");
    change(st, &top);
    printf("\nYour final stack is: \n");
    display(st, &top);
}