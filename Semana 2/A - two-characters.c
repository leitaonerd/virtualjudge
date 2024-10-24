#include <stdio.h>

int main(){

    int n, achou, cont = 0, maxcont = 0;
    scanf("%d", &n);
    getchar();

    char vetor[n], ant;
    scanf("%s", vetor);

    for(int i = 0; i < n-1; i++){
        int j = i+1;
        while(vetor[j] == vetor[i]){
            j++;
        }

        ant = vetor[j];
        cont = 2;
        achou = 0;

        for(int k = j+1; k < n; k++){
            if(achou == 0){
                while(vetor[k] != vetor[i]) k++;
                achou = 1;
                cont++;
            }
            if(achou == 1){
                while(vetor[k] != ant) k++;
                achou = 0;
                cont++;
            }
        }
        if(cont > maxcont) maxcont = cont;
    }
    printf("%d\n", maxcont);

    return 0;
}