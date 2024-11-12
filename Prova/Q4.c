#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int n;
    float xc, yc, xr, yr;

    scanf("%d %f %f %f %f", &n, &xc, &yc, &xr, &yr);

    for(int i = 0; i < n; i++){
        float a, b;
        scanf("%f %f", &a, &b);

        float distc = sqrt(abs(a-xc)*abs(a-xc) + abs(b-yc)*abs(b-yc));
        float distr = sqrt(abs(a-xr)*abs(a-xr) + abs(b-yr)*abs(b-yr));

        if(2*distc < distr){
            printf("O coelho pode escapar pelo buraco (%.3f,%.3f).\n", a, b);
            return 0;
        } 
    }

    printf("O coelho nao pode escapar.\n");


    return 0;
}