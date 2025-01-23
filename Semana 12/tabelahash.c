#include <stdio.h>

typedef struct node{
    int dado;
    struct node* next;
} node;

typedef struct lista{
    int tamanho;
    node* head;
    node* tail;
} lista;

typedef struct hashtable{
    int qtd, tablesize;
    lista** array;
} hashtable;

node* newNode(){
    node* temp = (node*)malloc(sizeof(node));
    if(!temp) return NULL;

    temp -> next = NULL;
    return temp;
}

lista* newLista(){
    lista* temp = (lista*)malloc(sizeof(lista));
    if(!temp) return NULL;
    
    temp -> tamanho = 0;
    temp -> head = NULL;
    temp -> tail = NULL;

    return temp;
}

hashtable* newHashtable(int tablesize){
    hashtable* temp = (hashtable*)malloc(sizeof(hashtable));
    if(!temp) return NULL;

    temp -> tablesize = tablesize;
    temp -> array = (lista**)malloc(sizeof(lista*) * tablesize);
    if(!temp -> array){
        free(temp);
        return NULL;
    }

    for(int i = 0; i < tablesize; i++){
        temp -> array[i] = newLista();
        if(!temp -> array[i]){
            for(int j = 0; j < i; j++){
                free(temp -> array[j]);
            }
            free(temp -> array);
            free(temp);
            return NULL;
        }
    }

    return temp;
}

int geraHash(int key, int tablesize){
    return key%tablesize;
}

void addHashtable(int a, int tablesize){
    node* temp = newNode();
    temp -> dado = a;

    int hash = geraHash(a, tablesize);

}

int main(){





    return 0;
}

