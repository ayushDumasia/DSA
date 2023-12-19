#include<stdio.h>
void sort(int a[],int n ){
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-1-i ; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;;
            }
        }
    }
    

}
int main(){
    int n;
    printf("Enter  n : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0 ;i < n;++i){
        printf("Enter a number -%d : ",i+1);
        scanf("%d",&a[i]);
    }

    sort(a,n);
    
    for(int i = 0 ; i < n ; i++){
        printf("%d \n",a[i]);
    }
    return 0;
}