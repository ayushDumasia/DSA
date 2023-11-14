#include <stdio.h>

int linear_search(int a[], int n)
{
    // int i = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == n)
        {
            printf("%d", i);
            return 1;
        }
    }
    printf("NOT FOUND");
    return 0;

    // if (i == n)
    // {
    //printf("NOT FOUND");
    // }
}     

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    printf("Enter n : ");
    scanf("%d", &n);

    linear_search(a, n);

    return 0;
}