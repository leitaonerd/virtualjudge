#include <stdio.h>

int main(){

    int t, n, k;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &k);
        int a, ontime = 0, late = 0;

        for(int j = 0; j < n; j++){
            scanf("%d", &a);
            (a>0) ? late++ : ontime++;
        }

        (ontime>=k) ? printf("NO\n") : printf("YES\n");
    }

    return 0;
}