#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return(*(int *)a - *(int *)b);
}

int main(){

    int n;
    scanf("%d", &n);
    int array[n], array2[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), compare);
    int ptrstr = 0, ptrend = n-1;
    for(int i = 0; i < n && ptrstr <= ptrend; i++){
        if(i%2 == 0){
            printf("%d ", array[ptrstr]);
            ptrstr++;
        }
        else{
            printf("%d ", array[ptrend]);
            ptrend--;
        }
    }
    printf("\n");

    return 0;
}