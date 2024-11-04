#include <stdio.h>

int main(){

    int n, k, cont = 0;

    scanf("%d %d", &n, &k);
    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if((vetor[i]+vetor[j])%k == 0) cont++;
        }
    }

    printf("%d\n", cont);

    return 0;
}