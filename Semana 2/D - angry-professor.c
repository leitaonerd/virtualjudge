#include <stdio.h>

int main(){

    int t, n, k;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &k);
        int a, emtempo = 0, atrasados = 0;

        for(int j = 0; j < n; j++){
            scanf("%d", &a);
            (a>0) ? atrasados++ : emtempo++;
        }

        (emtempo>=k) ? printf("NO\n") : printf("YES\n");
    }

    return 0;
}