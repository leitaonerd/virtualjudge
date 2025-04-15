#include <stdio.h>

int main(){

    int t, n, m, x, y, somax, somay, initx, inity;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &m);
        somax = 0;
        somay = 0;
        initx = 0;
        inity = 0;

        scanf("%d %d", &initx, &inity);
        somax += initx;
        somay += inity;

        for(int j = 1; j < n; j++){
            scanf("%d %d", &x, &y);
            somax += x;
            somay += y;
            
        }
        printf("%d\n", 2*(somax + m - initx) + 2*(somay + m - inity));
    }

    return 0;
}