#include <stdio.h>

int main(){

    int n, d, m, maneiras = 0;

    scanf("%d", &n);
    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    scanf("%d %d", &d, &m);

    for(int i = 0; i < (n-m+1); i++){
        int cont = 0, soma = 0;
        for(int j = i; cont < m; j++, cont++){
            soma += vetor[j];
        }
        if(soma == d) maneiras++;
    }

    printf("%d\n", maneiras);

    return 0;
}