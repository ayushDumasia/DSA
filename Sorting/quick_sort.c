#include<stdio.h>


int swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int pivotPos(int a[],int pivot,int size){
    int count = 0;
    for(int i = 0 ; i < size; i++){
        if(pivot > a[i]){
            count++;
        }
    }
    swap(&a[0],&a[count]);
}

void quickSort(int a[],int size){
    int pivot =a[0];
    pivotPos(a,pivot,size);
    int left = 0  ,right = size - 1;

    if(left > right){
        return ;
    }
    while(left < right){
        if(a[left] < pivot){
            left++;
        }
        else if(a[right] > pivot){
            right--;
        }
        else{
            swap(&a[left],&a[right]);
            left++;
            right--;

        }   
    }
    quickSort(a,left);
    quickSort(a + left +1 , size - left -1 );
}




int main(){
int a[10] = {9,56,21,48,75,32,54,02,900,58},pivot;
int n = sizeof(a) / sizeof(a[0]);

// for(int i=0; i<10; i++){
//     scanf("%d",&a[i]);
// }

quickSort(a,n);

printf("======");
for(int i=0; i<n; i++){
    printf("%d\n",a[i]);
}
          
               
return 0;
}