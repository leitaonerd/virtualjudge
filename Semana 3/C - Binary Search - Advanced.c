#include <stdio.h>

int main(){

    int n, key, lbound = 0, ubound = 0, freq = 0;

    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    scanf("%d", &key);
    int point = n/2;

    int loopcont = 0;
    while((array[point] != key - 1) && loopcont < 2000){
        if(array[point] > key-1) point -= (point/2 + 1);
        else if(array[point] < key-1) point += (point/2+1);
        loopcont++;
    }
    if(loopcont == 2000){
        printf("-1 -1 0\n");
        return 0;
    }

    while(array[point] != key){
        point++;
    }
    lbound = point;
    while(array[point] != key+1){
        point++;
        freq++;
    }
    ubound = point-1;

    printf("%d %d %d\n", lbound, ubound, freq);

    return 0;
}