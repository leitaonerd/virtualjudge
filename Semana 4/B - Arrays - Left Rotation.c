#include <stdio.h>

int main(){

    int n, d;

    scanf("%d %d", &n, &d);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    for(int i = d; i < n; i++){
        printf("%d ", array[i]);
    }
    for(int i = 0; i < d; i++){
        printf("%d ", array[i]);
    }

    return 0;
}