#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Pilha{
    int tamanho;
    Node* topo;
} Pilha;

int main(){

    int n, a, soma = 0;
    scanf("%d", &n);

    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha -> tamanho = 0;
    pilha -> topo = NULL;

    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a != 0){
            Node* temp = (Node*)malloc(sizeof(Node));

            temp -> data = a;
            temp -> next = pilha -> topo;

            pilha -> topo = temp;
            pilha -> tamanho++;    
        }
        else{
            pilha -> topo = pilha -> topo -> next;
            pilha -> tamanho --;
        }
    }

    while(pilha -> topo != NULL){
        soma += pilha -> topo -> data;
        pilha -> topo = pilha -> topo -> next;
    }

    printf("%d\n", soma);
}