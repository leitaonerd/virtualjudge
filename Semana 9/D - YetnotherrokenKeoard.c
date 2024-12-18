#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* topo;
    int tamanho;
} Stack;

Stack* createStack(){
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp -> topo = NULL;
    temp -> tamanho = 0;
    return temp;
}

void pushStack(Stack* pilha, char a){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = a;
    temp -> next = pilha -> topo;
    pilha -> topo = temp;
    pilha -> tamanho++;
}

int verification(Stack* temp, char a, char b){
    if(temp -> topo == NULL) return -1;
    if(temp -> topo -> next == NULL) return -1;
    if(temp->topo->next->data >= a && temp->topo->next->data <= b) return -1;
    return 0;
}

int main(){
    int t;
    char string[10000];
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%s", string);
        int len = strlen(string);

        Stack* pilha = createStack();
        for(int j = 0; j < len; j++){
            if(string[j] != 'b' && string[j] != 'B') pushStack(pilha, string[j]);
            else if(string[j] == 'b'){
                Stack* temp = pilha;
                while(verification(temp, 'a', 'z') == 0){
                    temp -> topo = temp -> topo -> next;
                }
                temp->topo->next = temp->topo->next->next;
            }
            else if(string[j] == 'B'){
                Stack* temp = pilha;
                while(verification(temp, 'A', 'Z') == 0){
                    temp -> topo = temp -> topo -> next;
                }
                temp->topo->next = temp->topo->next->next;
            }
        }

        while(pilha->topo != NULL){
            printf("%c", pilha->topo->data);
            pilha->topo = pilha->topo->next;
        }
    }
    return 0;
}