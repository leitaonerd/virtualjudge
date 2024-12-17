#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Pilha{
    Node* topo;
    int tamanho;
} Pilha;