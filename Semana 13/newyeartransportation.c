#include <stdio.h>

int main(){

    int n, t, soma = 1;
    scanf("%d %d", &n, &t);
    int vetor[n+1];

    for(int i = 1; i <= n; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 1; i <= n; i++){
        if(i == t){
            printf("YES\n");
            return 0;
        }
        i += vetor[i] - 1;
    }
    printf("NO\n");

    return 0;
}