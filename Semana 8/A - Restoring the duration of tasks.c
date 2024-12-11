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

    int t, n;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        Fila* fila = criaFila();
        Node* elemento1 = (Node*)malloc(sizeof(Node));

        //primeiro elemento da fila
        scanf("%d", &elemento1 -> given);
        fila -> inicio = elemento1;
        fila -> fim = elemento1;

        //resto dos elementos da fila
        for(int j = 0; j < n-1; j++){
            Node* elemento = (Node*)malloc(sizeof(Node));
            scanf("%d", &elemento -> given);

            fila -> fim -> next = elemento;
            fila -> fim = fila -> fim -> next;
        }
        
        //guardar a completion em cada elemento da fila
        for(int j = 0; j < n; j++){
            scanf("%d", &fila -> inicio -> completion);
            fila -> inicio = fila -> inicio -> next;
        }
        fila -> inicio = elemento1;

        while(fila -> fim -> next != NULL){
            if(fila -> inicio -> next -> given < fila -> inicio -> completion){
                printf("%d", fila -> inicio -> completion - fila -> inicio -> given);
                fila -> inicio = fila -> inicio -> next;
            }
            else if(fila -> inicio)
        }



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