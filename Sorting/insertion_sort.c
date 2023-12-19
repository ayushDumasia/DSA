#include<stdio.h>

int swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}

int insertion(int a[]){

    for(int i = 0 ; i < 10-1 ; i++){
        if(a[i] > a[i+1]){
            swap(a[i], a[i+1]);
        }
        for(int j = i ; j > 0 ; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }
}

int main(){
int a[5] = {34,8,10,90,100};

insertion(a);

for(int i=0; i<10; i++){
    printf("%d\n",a[i]);
}

return 0;
}