#include <stdio.h>

int buscamoedas(int x, int sub, int* vetor, int it);

int main(){

    int n, x, min, sub, it;
    scanf("%d %d", &n, &x);
    int moedas[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &moedas[i]);
    }

    min = -1;
    for(int i = 1; i <= n; i++){
        int tentativa = buscamoedas(x, sub, moedas, it);
        if(tentativa != 0 && tentativa < min) min = tentativa;
    }
    
    printf("%d\n", min);

    return 0;
}

int buscamoedas(int x, int sub, int* vetor, int it){
    if(x == 0) return 1;
    if(x < 0){
        return 0;
        it = 0;
    }

    it++;
    for(int i = 0; sub < x; i++){
        sub += buscamoedas(x - vetor[i], sub, vetor, it);
    }
    
    return it;
}