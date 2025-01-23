#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){

    int n;
    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), compare);
    int pstr = 0, pend = n-1;

    for(int i = 0; i < n; i++){
        printf("%d ", array[pstr]);
        pstr++;
        i++;
        
        if(i < n){
            printf("%d ", array[pend]);
            pend--;
        }
    }

    return 0;
}