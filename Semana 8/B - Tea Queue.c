#include <stdio.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

typedef struct Fila{
    int size;
    Node* inicio;
    Node* fim;
} Fila;

Fila* criaFila();

int main(){

    fila = criaFila();

    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = 'A';
    fila -> inicio = temp;
    fila -> fim = temp;
    fila -> size = 1;

    for(int i = 1; i < 15; i++){
        Node* temp = (Node*)malloc(sizeof(Node));
        temp -> data = 'A' + i;
        fila -> fim = temp;
        fila -> size++;
    }


    return 0;
}

Fila* criaFila(){
    Fila* temp = (Fila*)malloc(sizeof(Fila));

    temp -> inicio = NULL;
    temp -> fim = NULL;
    temp -> size = 0;

    return temp;
}