#include <stdio.h>

int main(){

    int n, achou, cont = 0, maxcont = 0;
    scanf("%d\n", &n);

    char vetor[n], ant;
    scanf("%s", vetor);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            while(vetor[j] == vetor[i]){
                j++;
            }

            ant = vetor[j];
            cont = 2;
            achou = 0;

            for(int k = j+1; k < n; k++){
                if(achou == 0){
                    while(vetor[k] != vetor[i] && vetor[k] != ant) k++;
                    if(vetor[k] == ant){
                        cont++;
                        goto END;
                    }
                    achou = 1;
                    cont++;
                }
                if(achou == 1){
                    while(vetor[k] != ant && vetor[k] != vetor[j]) k++;
                    if(vetor[k] == vetor[j]){
                        cont++;
                        goto END;
                    }
                    achou = 0;
                    cont++;
                }
            }
            END: if(cont > maxcont) maxcont = cont;
        }
            
    }
    printf("%d\n", maxcont);

    return 0;
}