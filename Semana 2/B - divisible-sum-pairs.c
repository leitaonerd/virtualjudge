#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){

    int n, k, cont = 0;

    scanf("%d %d", &n, &k);
    int vetor[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    qsort(vetor, n, sizeof(int), compare);

    for(int i = 0, j = n; i <= n/2; i = i){
        if((vetor[i] + vetor[j])%k == 0){
            cont++;
            i++;
            j = n;
        }
        else if(j != i+1) j--;
        else i++;
    }

    printf("%d\n", cont);

    return 0;
}