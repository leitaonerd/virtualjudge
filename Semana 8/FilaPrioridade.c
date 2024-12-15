#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nome[12];    
    int idade;
    struct Node* next;
} Node;

typedef struct Fila{
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

Fila* criaFila();
void printFila(Fila* fila);

int main(){

    int idade = 1;
    char nome[12];

    Fila* fila = criaFila();
    Fila* fila60 = criaFila();
    Fila* fila80 = criaFila();

    while(1){
        printf("Ola! Qual seu nome? ");
        scanf("%s", nome);
        printf("Quantos anos voce tem? ");
        scanf("%d", &idade);
        if(idade < 0) break;
    
        Node* temp = (Node*)malloc(sizeof(Node));
        strcpy(temp -> nome, nome);
        temp -> idade = idade;

        if(idade >= 80){
            if(fila80 -> tamanho == 0){
                fila80 -> inicio = temp;
                fila80 -> fim = temp;
            } 
            fila80 -> fim -> next = temp;
            fila80 -> fim = temp;
            fila80 -> tamanho++;
        } 
        else if(idade >= 60){
            if(fila60 -> tamanho == 0){
                fila60 -> inicio = temp;
                fila60 -> fim = temp;
            } 
            fila60 -> fim -> next = temp;
            fila60 -> fim = temp;
            fila60 -> tamanho++;
        } 
        else{
            if(fila -> tamanho == 0){
                fila -> inicio = temp;
                fila -> fim = temp;
            } 
            fila -> fim -> next = temp;
            fila -> fim = temp;
            fila -> tamanho++; 
        }
        
    }

    printf("Esta e a fila: ");
    printFila(fila80);
    printFila(fila60);
    printFila(fila);

    return 0;
}

Fila* criaFila(){
    Fila* temp = (Fila*)malloc(sizeof(Fila));

    temp -> inicio = NULL;
    temp -> fim = NULL;
    temp -> tamanho = 0;

    return temp;
}

void printFila(Fila* fila){
    for(int i = 0; i < fila -> tamanho; i++){
        printf("%s\n", fila -> inicio -> nome);
        fila -> inicio = fila -> inicio -> next;
    }
}
