#include <stdio.h>

int main(){

    int a, on = 1;
    while(on == 1){
        scanf("%d", &a);
        if(a == 0) return 0;

        printf("%d\n", a/2);
    }
    return 0;
}