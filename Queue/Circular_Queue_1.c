#include<stdio.h>
// #define size 5

int head = -1 , tail = -1;
int size = 5;


int enQueue(int queue[]){
    int x;
    if(head == -1 && tail == -1){//for first element
        head = tail = 0;
        printf("Enter x : ");
        scanf("%d",&x);
        queue[tail] = x;
    }
    else if(((tail+1) %size) == head){//for last element
        printf("Queue is full\n");
        return -1;
    }
    else{
        tail = (tail +1)%size;
        printf("Enter x : ");
        scanf("%d",&x);
        queue[tail] = x;
    }
    return tail;
}

int deQueue(int queue[]){
    if(head == -1 && tail == -1){
        printf("Queue is Empty\n");
    }
    else if(head == tail){
        head = tail = -1;
    }
    else{
        printf("POP UP ELEMENT : %d\n",queue[head]);
        head = head + 1 % size; 
    }
}


int display(int queue[]){
    int i = head;
    if(head == -1 && tail == -1){
        printf("Queue is full\n");
    }
    else {
        while(i != tail){
            printf(" %d ",queue[i]);
            i = i +1 % size;
        }
        printf(" %d ",queue[i]);
    }
}

int peep(int queue[]){
    if(head == -1 && tail == -1){
        printf("Queue is full\n");
    }
    else{
        printf("\nPEEP ELEMENT IS : %d\n",queue[head]);
    }
}

int main(){
int queue[size];

enQueue(queue);
enQueue(queue);
enQueue(queue);
enQueue(queue);
enQueue(queue);
enQueue(queue);//here Queue is already full

deQueue(queue);
deQueue(queue);

display(queue);

peep(queue);




return 0;
}