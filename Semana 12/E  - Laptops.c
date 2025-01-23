#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    const int (*x)[2] = a;
    const int (*y)[2] = b;
    return (*x)[0] - (*y)[0];
}

int main(){

    int n, atual;

    scanf("%d", &n);
    int vetor[n][2];

    for(int i = 0; i < n; i++){
        scanf("%d %d", &vetor[i][0], &vetor[i][1]);
    }

    qsort(vetor, n, sizeof(vetor[0]), compare);

    atual = vetor[0][1];
    for(int i = 1; i < n; i++){
        if(vetor[i][1] < atual){
            printf("Happy Alex\n");
            return 0;
        }
        atual = vetor[i][1];
    }
    printf("Poor Alex\n");

    return 0;
}