#include <stdio.h>
#include <string.h>
 
int main(){

    int a, b, equal = 0;

    scanf("%d %d", &a, &b);

    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    else if(a == b){
        equal = 1;
    }

    if(equal == 0) printf("%d\n%d\ndiferentes\n", a, b);
    else printf("%d\n%d\niguais\n", a, b);

    return 0;
}