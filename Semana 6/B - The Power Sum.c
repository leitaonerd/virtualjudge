#include <stdio.h>
#include <math.h>

int acharcombinacao(int it, int x, int n, int* vetor);

int main(){

    int x, n, maneiras = 0, ant = 0, potencias[32];
    scanf("%d", &x);
    scanf("%d", &n);

    for(int i = 1; ant < x; i++){
        potencias[i] = pow(i, n);
        ant = potencias[i];
    }

    maneiras = acharcombinacao(1, x, n, potencias);
    printf("%d\n", maneiras);

    return 0;
}

int acharcombinacao(int it, int x, int n, int* vetor){
    if(x == 0) return 1;
    if(x < 0) return 0;

    int soma = 0;
    for(int i = it; vetor[i] <= x; i++){
        soma += acharcombinacao(i + 1, x - vetor[i], n, vetor);
    }
    return soma;
}
