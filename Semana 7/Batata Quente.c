#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[10];
    struct No* next;
    struct No* last;
}No;

typedef struct Lista{
    struct No* head;
    struct No* tail;
    int size;
}Lista;

No* novacrianca(char sample[10], Lista* list){
    No* temp = (No*)malloc(sizeof(No));

    strcpy(temp -> nome, sample);
    if(list -> head == NULL) list -> head = temp;
    if(list -> tail == NULL) list -> tail = temp;
    temp -> next = list -> head;
    temp -> last = list -> tail;

    temp -> last -> next = temp;
    list -> tail = temp;
    list -> head -> last = list -> tail;
    list -> size++;
    return temp;
}

void excluircrianca(int posicao, Lista* list){
    No* temp = list -> head;
    if(list -> size > 2){
        for(int i = 0; i < posicao; i++){
            temp = temp -> next;
        }
        printf("%s foi morto pela batata quente\n", temp -> nome);

        temp -> last -> next = temp -> next;
        temp -> next -> last = temp -> last;
        list -> size--;
    }
    /*else{
        if(posicao%2 == 0){
            list -> head -> next = list -> head;
            list -> head -> last = list -> head;
            list -> tail = list -> head;
        }
        else{
            list -> head = list -> tail;
            list -> head -> next = list -> head;
            list -> head -> last = list -> head;
            list -> tail = list -> head;
        }
    }*/
}

int main(){

    char sample[10];
    int posicao;
    Lista* roda = (Lista*)malloc(sizeof(Lista));
    roda -> size = 0;
    roda -> head = NULL;
    roda -> tail = NULL;

    while(1){
        scanf("%s", sample);
        if(sample[0] == '0') break;

        novacrianca(sample, roda);
    }

    while(roda -> size > 1){
        scanf("%d", &posicao);
        excluircrianca(posicao - 1, roda);
    }
    printf("%s ganhou!\n", roda -> head -> nome);

    return 0;
}