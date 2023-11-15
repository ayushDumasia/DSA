#include<stdio.h>
#define size 10
int count = 0 ;

void push1(int stack1[],int *ptr){
    int x;
    printf("Enter a Data : ");
    scanf("%d",&x);
    if(*ptr > size){
        printf("Stack OverFlow");
    }
    else{
        (*ptr)++;
        stack1[(*ptr)] = x;
    }
}

void enQueue(int stack1[], int *ptr){
    push1(stack1,ptr);
    count++;
}

void deQueue(int stack1,int *ptr1 , int *ptr2){
    if(*ptr1 == -1 && *ptr2 == -1 ){
        printf("Queue is Empty");
    }
    else{
        for(int i = 0 ; i < count ; i++){
            int a = pop1(),
            push2();
        }
    }
}









int main(){
int stack1[size],stack2[size],ptr1 = -1 , ptr2 = -1 ;
          
               
return 0;
}