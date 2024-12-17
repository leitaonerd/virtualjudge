#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int chegada;
    int saida;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* topo;
    int tamanho;
} Stack;

int main(){
    int t, n, k, c, s, check;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        check = 0;
        Stack* pilha = (Stack*)malloc(sizeof(Stack));
        pilha -> topo = NULL;
        pilha -> tamanho = 0;

        scanf("%d %d", &n, &k);
        for(int j = 0; j < n; j++){
            scanf("%d %d", &c, &s);

            while(pilha -> topo != NULL && pilha -> topo -> saida <= c){
                pilha -> topo = pilha -> topo -> next;
                pilha -> tamanho--;
            } 
            if(pilha -> topo != NULL && s > pilha -> topo -> saida) check = 1;

            Node* temp = (Node*)malloc(sizeof(Node));
            temp -> chegada = c;
            temp -> saida = s;
            temp -> next = pilha -> topo;

            pilha -> topo = temp;
            pilha -> tamanho++;
            if(pilha -> tamanho > k) check = 1;
        }

        check? printf("Nao\n") : printf("Sim\n");
    }

    return 0;
}