#include<stdio.h>

void createHashtable(int arr[] , int size , int hashtable[] , int *hk){
    int  i , m = 10;

    for(i = 0 ; i < size ; i++){
        *hk = ((2 * arr[i]) + 3) % m;
        if(hashtable[*hk] == 0){
            hashtable[*hk] = arr[i];
        }
        else{
            while(hashtable[*hk] != 0){
                *hk = (++(*hk)) % m;
            }
            hashtable[*hk] = arr[i];
        }
    }
}

int main(){
    int arr[] = {3,2,9,6,11,13,7,12};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int hashtable[10] = {0} , i = 0 , hk;

    createHashtable(arr,size,hashtable,&hk);

    for(i = 0 ; i < 10 ; i++){
        printf("%d\n", hashtable[i]);
    }

return 0;
}