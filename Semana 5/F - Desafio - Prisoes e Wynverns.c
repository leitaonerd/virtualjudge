#include <stdio.h>

#define MOD 1000000007;

int main(){

    int n;
    scanf("%d", &n);

    int dano[n];
    dano[0] = 1;
    
    for(int i = 1; i <= n; i++){
        dano[i] = 0;
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0) dano[i] = (dano[i] + dano[i-j]) % MOD;
        }
        printf("%d\n", dano[i]);
    }

    printf("%d\n", dano[n]);

    return 0;
}