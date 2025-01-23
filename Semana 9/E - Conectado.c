#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char cor[31];
    struct Node* next;
}Node;

typedef struct Queue{
    int tamanho;
    Node* head;
    Node* tail;
}Queue;

typedef struct Stack{
    int tamanho;
    Node* head;
}Stack;

Queue* createQueue(){
    Queue* newQueue = NULL;
    newQueue = malloc(sizeof(Queue));
    if(!newQueue){
        printf("Error allocating memory to new queue\n");
        return NULL;
    }

    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->tamanho = 0;

    return newQueue;
}

Node* createNode(char cor[31]){
    Node* newNode = NULL;
    newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Error allocating memory to new node\n");
        return NULL;
    }

    newNode->next = NULL;
    strcpy(newNode->cor, cor);

    return newNode;
}

Stack* createStack(){
    Stack* newStack = NULL;
    newStack = malloc(sizeof(Stack));
    if(!newStack){
        printf("Error allocating memory to new stack\n");
        return NULL;
    }

    newStack->tamanho = 0;
    newStack->head = NULL;

    return newStack;
}

int main(){
    int n, seq = 0;
    char sequencia[100000], cortemp[31], reservado[31];

    Stack* stackentrada = createStack();
    Stack* stacksaida = createStack();
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", cortemp);
        Node* temp = createNode(cortemp);
        
        if(stackentrada -> tamanho == 0){
            stackentrada -> head = temp;
            stackentrada -> tamanho++;
        }
        else{
            temp -> next = stackentrada -> head;
            stackentrada -> head = temp;
            stackentrada -> tamanho++;
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%s", cortemp);
        Node* temp = createNode(cortemp);

        if(stacksaida -> tamanho == 0){
            stacksaida -> head = temp;
            stacksaida -> tamanho++;
        }
        else{
            temp -> next = stacksaida -> head;
            stacksaida -> head = temp;
            stacksaida -> tamanho++;
        }
    }
    while(stackentrada->head != NULL){
        if(strcmp(stackentrada->head->cor, stacksaida->head->cor) == 0){
            sequencia[seq] = 'M';
            seq++;

            stackentrada -> head = stackentrada -> head -> next;
            stacksaida -> head = stacksaida -> head -> next;
        }
        else{
            if(strlen(reservado) > 0){
                if(strcmp(reservado, stacksaida->head->cor) == 0){
                    sequencia[seq] = 'R';
                    seq++;

                    reservado[0] = '\0';
                    stacksaida -> head = stacksaida -> head -> next;
                }
                else{
                    printf("Defeito de fabrica!\n");
                    return 0;
                }
            }
            else{
                strcpy(reservado, stackentrada->head->cor);
                stackentrada -> head = stackentrada -> head -> next;
                sequencia[seq] = 'G';
                seq++;
            }
            
        }
    }
    if(reservado[0] != '\0'){
        if(strcmp(reservado, stacksaida->head->cor) == 0){
            sequencia[seq] = 'R';
            stacksaida -> head = stacksaida -> head -> next;
        } 
        else{
            printf("Defeito de fabrica!\n");
            return 0;
        }
    }
    if(stacksaida -> head != NULL){
        printf("Defeito de fabrica!\n");
        return 0;
    }

    printf("%s\n", sequencia);
    return 0;
}