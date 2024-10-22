#include <stdio.h>

int main(){

    int a, b, d, m, n, s, t, apple = 0, orange = 0;

    scanf("%d %d", &s, &t);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++){
        scanf("%d", &d);
        if(d >= (s-a) && d <= (t-a)) apple++;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &d);
        if(d <= (t-b) && d >= (s-b)) orange++;
    }

    printf("%d\n%d\n", apple, orange);

    return 0;
}