#ifndef FILA_H
#define FILA_H

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Fila{
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;

Fila* Queue();

void enqueue(Fila* fila, int item);

int dequeue(Fila* fila); 

int front(Fila* fila);

int isEmpty(Fila* fila);

int size(Fila* fila);

#endif