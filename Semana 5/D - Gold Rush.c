#include <stdio.h>

int pile(int a, int b);

int main(){

    int t, n, m, res;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &m);

        if(n < m){
            printf("NO\n");
            goto END;
        } 
        if(n == m){
            printf("YES\n");
            goto END;
        }

        res = pile(n, m);
        if(res == 1) printf("YES\n");
        else printf("NO\n");
        END: continue;
    }

    return 0;
}

int pile(int a, int b){
    if(a == 0) return 0;
    if(a%3 != 0) return 0;
    if(a/3 == b || (a/3)*2 == b){
        return 1;
    }
    return (pile(a/3, b) || pile((a/3)*2, b));
}