#include<stdio.h>


int merge(int a[],int arr1[],int arr2[],int size,int mid){
    int i = 0 , j = 0 , k = 0;
    int n = mid , m = size - mid;


    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            a[k++] = arr1[i++];
        }
        else{
            a[k++] = arr2[j++];
        }
    }
}



int merge_sort(int a[],int size){
    int mid = size/2;
    int arr1[mid] ;
    int arr2[size - mid] ;

    if(size <= 1){
        return;
    }

    for(int i = 0 ; i < mid ; i++){
        arr1[i] = a[i];
    }
    for(int i = 0 ; i < size - mid; i++){
        arr2[i] = a[i+mid];
    }

    merge_sort(arr1,mid);
    merge_sort(arr2,size-mid);
    merge(a,arr1,arr2,size,mid);

}




int main(){
int size = 8;
int a[] = {90,10,20,56,70,44,33,58};

merge_sort(a,size);

for(int i=0; i<size; i++){
    printf("%d\n",a[i]);
}

return 0;
}