#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dado;
    struct Node* next;
} Node;

typedef struct Grafo{
    int n_arestas;
    int n_vertices;
    Node** array;
} Grafo;

Node* criaNode(){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(!temp) return NULL;

    temp -> next = NULL;
    temp -> dado = 0;
    return temp;
}

void appendNode(Node* vertice, int relacionado){
    Node* novo = criaNode();
    novo -> dado = relacionado;
    
    if(vertice -> next == NULL) vertice -> next = novo;
    else{
        novo -> next = vertice -> next;
        vertice -> next = novo;
    }
}

Grafo* criaGrafo(int tamanho){
    Grafo* temp = (Grafo*)malloc(sizeof(Grafo));
    if(!temp) return NULL;

    temp -> n_vertices = tamanho;
    temp -> n_arestas = 0;

    temp -> array = (Node**)malloc(sizeof(Node*) * tamanho);
    if(!temp -> array) return NULL;

    for(int i = 0; i < tamanho; i++){
        temp->array[i] = criaNode();
    }

    return temp;
}

void printGrafo(Grafo* grafo){
    printf("%d vertices e %d arestas\n", grafo -> n_vertices, grafo -> n_arestas);
    for(int i = 0; i < grafo -> n_vertices; i++){
        Node* index = grafo -> array[i];
        printf("Node [%d]: ", index -> dado);
        index = index -> next;
        while(index != NULL){
            printf("%d ", index -> dado);
            index = index -> next;
        }
        printf("\n");
    }
}

void freeGrafo(Grafo* grafo){
    Node* next = NULL;
    Node* base = NULL;

    for(int i = 0; i < grafo -> n_vertices; i++){
        base = grafo -> array[i];
        while(base != NULL){
            next = base -> next;
            free(base);
            base = next;
        }
    }
    printf("Grafo apagado\n");
}

int main(){

    int tamanho, relaciona;
    printf("Insira numero de vertices do grafo: ");
    scanf("%d", &tamanho);

    Grafo* grafo = criaGrafo(tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("Insira o valor do vertice: ");
        scanf("%d", grafo -> array[i] -> dado);
        printf("Com quantos vertices ele se relaciona?: ");
        scanf("%d", &relaciona);
        for(int j = 0; j < relaciona; j++){
            int relacionado;
            printf("Insira o vertice relacionado: ");
            scanf("%d", &relacionado);
            appendNode(grafo -> array[i], relacionado);
            grafo -> n_arestas++;
        }
    }
    printGrafo(grafo);

    freeGrafo(grafo);

    return 0;
}