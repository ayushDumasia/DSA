#include<stdio.h>

int binary_search(int a[],int size,int n){
    int l = 0 , r = size -1 ;

    while(l <= r){
    int mid = (l+r)/2;
        if(n == a[mid]){
            return mid;
        }
        else if(n < a[mid]){
            r =mid -1;
        }
        else{
            l = mid +1;
        }
    }
    return -1;
}

int main(){
int n;
int size = 10;
int a[10] = {0,1,2,3,7,23,29,68,69,70};   

printf("Enter n : ");
scanf("%d",&n);

int c = binary_search(a,size,n);


if (c != -1) {
        printf("Element %d found at index %d.\n", n, c);
    } 
    else {
        printf("Element %d not found in the array.\n", n);
    }

return 0;
}