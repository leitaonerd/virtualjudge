#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int vetor[n+1];
    for(int i = 1; i < n+1; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 1; i < n+1; i++){
        if(i == vetor[vetor[vetor[i]]]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}