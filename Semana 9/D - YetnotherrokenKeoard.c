#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node* next;
    struct Node* last;
} Node;

typedef struct List{
    Node* start;
    Node* end;
    int tamanho;
} List;

List* createList(){
    List* temp = (List*)malloc(sizeof(List));
    temp->start = NULL;
    temp->end = NULL;
    temp->tamanho = 0;
    return temp;
}

void addList(List* lista, char a){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = a;
    temp->next = NULL;

    if(lista->tamanho == 0){
        temp->last = NULL;
        lista->start = temp;
    } 
    else{
        temp->last = lista->end;
        lista->end->next = temp;
    }
    lista->end = temp;
    lista->tamanho++;
}

int main(){
    int t;
    char string[1000000];
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%s", string);
        int len = strlen(string);

        List* lista = createList();

        for(int j = 0; j < len; j++)
            if(string[j] != 'b' && string[j] != 'B') addList(lista, string[j]);
            else if(string[j] == 'b'){
                Node* temp = lista->end;
                while(temp != NULL){
                    if(temp->data >= 'a' && temp->data <= 'z'){
                        if(temp->last != NULL) temp->last->next = temp->next;
                        else lista->start = temp->next;

                        if(temp->next != NULL) temp->next->last = temp->last;
                        else lista->end = temp->last;

                        lista->tamanho--;
                        break;
                    }
                    temp = temp->last;
                }
            } 
            else if(string[j] == 'B'){
                Node* temp = lista->end;
                while(temp != NULL){
                    if(temp->data >= 'A' && temp->data <= 'Z'){
                        if(temp->last != NULL) temp->last->next = temp->next;
                        else lista->start = temp->next;

                        if(temp->next != NULL) temp->next->last = temp->last;
                        else lista->end = temp->last;

                        lista->tamanho--;
                        break;
                    }
                    temp = temp->last;
                }
            }

        int k = 0;
        while(lista->start != NULL){
            string[k] = lista->start->data;
            lista->start = lista->start->next;
            k++;
        }
        string[k] = '\0';
        printf("%s\n", string);
    }

    return 0;
}
