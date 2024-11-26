#include <stdio.h>

int achar(int a, int b);

int vetor[1000] = {0}, cont = 0;

int main(){

    int a, b, achou;

    scanf("%d %d", &a, &b);
    achou = achar(a, b);

    if(achou == -1) printf("NO\n");
    else{
        printf("YES\n%d\n%d ", cont+1, a);
        for(int i = cont-1; i >= 0; i--){
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }

    return 0;
}

int achar(int a, int b){
    if(b == a) return 0;
    if(b < a) return -1; 

    if(b%2 == 0){
        vetor[cont] = b;
        cont++;
        return(achar(a,b/2));
    }
    else{
        vetor[cont] = b;
        cont++;
        return(achar(a,(b-1)/10));
    }
}