#include<stdio.h>

int towerOfHanoi(int n , int source , int aux ,int dest){
    if(n==1){
        printf("Move disk 1 from %c to %c",source,dest);
        return;
    }

    towerOfHanoi(n-1,source,dest,aux);
    printf("\nMove disk %d from %c to %c\n",n,source,dest);
    towerOfHanoi(n-1,aux,source,dest);
}



int main(){
int n;

printf("Enter a n : ");
scanf("%d",&n);

towerOfHanoi(n,'A','B','C');


return 0;
}