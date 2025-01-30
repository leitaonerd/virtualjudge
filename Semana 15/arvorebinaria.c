#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
    struct Arvore* direita;
    struct Arvore* esquerda;
    int dado;
} Arvore;

typedef struct Raiz{
    struct Arvore* inicio;
} Raiz;

Arvore* criaArvore(int x){
    Arvore* temp = (Arvore*)malloc(sizeof(Arvore));

    temp -> direita = NULL;
    temp -> esquerda = NULL;
    temp -> dado = x;

    return temp;
}



int main(){

    int n;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        Arvore* last = criaArvore(a);

    }


}