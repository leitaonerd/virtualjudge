#include <stdio.h>

typedef struct Node{
    int given;
    int completion;
    struct Node* next;
} Node;

typedef struct Fila{
    int size;
    Node* inicio;
    Node* fim;
} Fila;

Fila* criaFila();

int main(){

    return 0;
}

Fila* criaFila(){
    Fila* temp = (Fila*)malloc(sizeof(Fila));

    temp -> inicio = NULL;
    temp -> fim = NULL;
    temp -> size = 0;

    return temp;
}