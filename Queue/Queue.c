#include<stdio.h>
#define size 10

int enQueue(int a[],int *head,int *tail){
    int x;
    if(*tail > size){
        printf("Queue Overflow");
    }
    else if(*head == -1 & *tail == -1 ){
        *head = *tail = 0;
        printf("Enter a value : ");
        scanf("%d",&x);
        a[*tail] = x;
    }
    else{
        (*tail)++;
        printf("Enter a value : ");
        scanf("%d",&x);

        a[*tail] = x;
    }
}

int deQueue(int a[],int *head,int *tail){
    if(*head == -1){
        printf("Underflow");
        return -1;
    }
    int removed = a[*head];
    if(*head == *tail){
        *head = *tail = -1;
    }
    else{
        (*head)++;
    }
    return removed;
}

int peep(int a[],int *head){
    if(*head == -1){
        printf("Queue is  empty");
    }
    else{
        printf(" %d ",a[*head]);
    }
}


int display(int a[],int *head,int *tail){
    int i = *head;
    if(*head == -1 && *tail == -1){
        printf("Queue is  empty\n");   
    }
    for(int i = *head ; i < *tail + 1 ; i++){
        printf(" %d ",a[i]);
    }
}




int main(){
int a[size],*head = -1,*tail = -1;


enQueue(a,&head,&tail);
enQueue(a,&head,&tail);
enQueue(a,&head,&tail);
enQueue(a,&head,&tail); 
enQueue(a,&head,&tail);

     
printf("Queue is : ");
display(a,&head,&tail);
printf("\n");

//delete elements in queue
deQueue(a,&head,&tail);
deQueue(a,&head,&tail);
enQueue(a,&head,&tail);

printf("Queue after delete 2 elements : ");
display(a,&head,&tail);

//using peep function
printf("\n");
printf("Peep Element  : ");
peep(a,&head);

return 0;
}