#include <stdio.h>
#include "Fila.h"

Fila* Queue(){
    Fila* temp = (Fila*)malloc(sizeof(Fila*));

    temp -> inicio = NULL;
    temp -> fim = NULL;
    temp -> tamanho = 0;

    return temp;
}

void enqueue(Fila* fila, int item){
    Node* temp = (Node*)malloc(sizeof(Node));

    temp -> data = item;
    temp -> next = NULL;

    if(fila -> tamanho == 0){
        fila -> inicio = temp;
        fila -> fim = temp;
    }
    else{
        fila -> fim -> next = temp;
        fila -> fim = temp;
    }
    fila -> tamanho++;
    return
}

int isEmpty(Fila* fila){
    if(Fila -> tamanho == 0) return 1;
    return 0;
}

int dequeue(Fila* fila){
    if(isEmpty(fila) == 1) return -1;
    
    int temp;

    temp = fila -> inicio -> data;
    fila -> inicio = fila -> inicio -> next;
    return temp;
}

int front(Fila* fila){
    return Fila -> inicio -> valor;
}

int size(Fila* fila){
    return Fila -> tamanho;
}



