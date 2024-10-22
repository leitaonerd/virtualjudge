#include <stdio.h>
#include <stdlib.h>

int main(){

    int q, x, y, z, dist;

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d %d %d", &x, &y, &z);

        dist = abs(z-x) - abs(y-z);
        if(dist < 0) printf("Cat A\n");
        else if (dist > 0) printf("Cat B\n");
        else printf("Mouse C\n");
    }
    
    return 0;
}