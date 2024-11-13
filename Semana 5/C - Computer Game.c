#include <stdio.h>

int main(){

    int t, n;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        char l1[n+1], l2[n+2];

        scanf("%s", l1);
        scanf("%s", l2);

        int achou = 0;
        for(int j = 1; j < n; j++){
            if(l1[j] == '1' && l2[j] == '1'){
                printf("NO\n");
                achou = 1;
                break;
            }
        }
        if(achou == 0) printf("YES\n");
    }

    return 0;
}