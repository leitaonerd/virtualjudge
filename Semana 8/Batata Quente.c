#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char nome[12];
    struct Node* next;
} Node;

typedef struct Fila{
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

Fila* Queue(){
    Fila* temp = (Fila*)malloc(sizeof(Fila*));

    temp -> inicio = NULL;
    temp -> fim = NULL;
    temp -> tamanho = 0;

    return temp;
}

int main(){

    int ncriancas;

    Fila* fila = Queue();

    printf("Quantas criancas vao participar da brincadeira?: ");
    scanf("%d", &ncriancas);
    for(int i = 0; i < ncriancas; i++){
        Node* node = (Node*)malloc(sizeof(Node));
        scanf("%s", node -> nome);
        node -> next = NULL;

        if(fila -> tamanho == 0){
            fila -> inicio = node;
            fila -> fim = node;
        }
        else{
            fila -> fim -> next = node;
            fila -> fim = node;
        }
        fila -> tamanho++;
    }    

    printf("Digite %d numeros, um para cada crianca a ser eliminada: ");
    for(int i = 0; i < ncriancas - 1; i++){
        int iteracoes;
        scanf("%d", &iteracoes); 
        for(int j = 0; j < iteracoes; j++){
            fila -> fim -> next = fila -> inicio;
            fila -> inicio =  fila -> inicio -> next;
        }
        fila -> inicio = fila -> inicio -> next;
    }
    printf("O vencedor foi %s!\n", fila -> inicio -> nome);

    return 0;
}