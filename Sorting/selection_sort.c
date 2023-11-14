
#include<stdio.h>

int selection_sort(int a[]){
    for(int i  =0 ; i < 9 ; i++){
        int min = i ;
        for(int j = i+1 ; j < 10 ; j++){
            if(a[min] > a[j]){
                min = j ;
            }
        }
        if(min != i ){
            int temp  =a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

// int selection_sort(int a[]){
//     for(int i = 0 ; i < 9 ; i++){
//         int min = a[i];
//         for(int j = i +1 ; j < 10 ; j++){
//             if(a[min] > a[j]){
//                 min = j;
//             }
//         }
//         if(min != i){
//             int temp  =a[i];
//             a[i] = a[min];
//             a[min] = temp;
//         }
//     }
// }


int main(){
int a[10];

for(int i=0; i<10; i++){
    scanf("%d",&a[i]);
}
          
selection_sort(a);
printf("======");
for(int i=0; i<10; i++){
    printf("%d\n",a[i]);
}
               
return 0;
}