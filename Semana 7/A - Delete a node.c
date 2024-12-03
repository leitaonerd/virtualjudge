#include <stdio.h>
#include <stdlib.h>
struct Elemento {
    int dados;
    struct Elemento* prox_elemento;
};


struct Elemento* novo_elemento(int dados){
    struct Elemento* temp = (struct Elemento*)malloc(sizeof(struct Elemento)); // malloc retorna um ponteiro para o espaco de memoria reservado que precisa ser castado pro tipo desejado

    temp -> dados = dados;
    temp -> prox_elemento = NULL;

    return temp;
}

int main(){

    int n, dado, retirado;
    struct Elemento* inicial = NULL;
    struct Elemento* atual = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &dado);
        struct Elemento* temporario = novo_elemento(dado);

        if(inicial == NULL) inicial = temporario;
        else atual -> prox_elemento = temporario;

        atual = temporario;
    }
    scanf("%d", &retirado);
    
    
    if(retirado == 1){
        struct Elemento* temporario = inicial;
        inicial = inicial -> prox_elemento;
        free(temporario);
    } 
    else{
        struct Elemento* posicao = inicial;
        for(int i = 1; i < retirado - 1 && posicao != NULL; i++){
            posicao = posicao -> prox_elemento;
        }
        if(posicao != NULL && posicao->prox_elemento != NULL){
            struct Elemento* temporario = posicao -> prox_elemento;
            posicao -> prox_elemento = temporario -> prox_elemento;
            free(temporario);
        }
    }
    

    struct Elemento* posicao = inicial;
    while(posicao != NULL){
        printf("%d ", posicao -> dados);
        posicao = posicao -> prox_elemento;
    }
    printf("\n");

    return 0;
}