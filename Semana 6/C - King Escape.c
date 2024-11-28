#include <stdio.h>

int main(){

    int n, ax, ay, bx, by, cx, cy;

    scanf("%d", &n);
    scanf("%d %d", &ax, &ay);
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &cx, &cy);

    if(((bx < ax)&&(cx < ax)) || ((bx > ax)&&(cx > ax))){
        if(((by < ay)&&(cy < ay)) || ((by > ay)&&(cy > ay))){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    else{
        printf("NO\n");
    }

    return 0;
}