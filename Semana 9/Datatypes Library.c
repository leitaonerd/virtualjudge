#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    int data;
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

Node* createNode(int data);
void removeNode(Node* node);

Queue* createQueue();
void enqueue(Queue* queue, int data);
void dequeue(Queue* queue);
int front(Queue* queue);
void emptyQ(Queue* queue);

Stack* createStack();
void push(Stack* stack, int data);
void pop(Stack* stack);
int top(Stack* stack);
void emptyS(Stack* stack);


int main(void){
    
    return 0;
}


// Nodes
Node* createNode(int data){
    Node* newNode = NULL;
    newNode = malloc(sizeof(Node));
    if(!newNode){
        printf("Error allocating memory to new node\n");
        return NULL;
    }

    newNode->next = NULL;
    newNode->data = data; 

    return newNode;
}


void removeNode(Node* node){
    if(!node) return;
    free(node);
}


// Queues
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


void enqueue(Queue* queue, int data){
    Node* newNode = createNode(data);
    if(!queue || !newNode) return;

    if(!queue->tamanho) queue->head = newNode;
    else queue->tail->next = newNode;

    queue->tail = newNode;
    queue->tamanho++;

    return;
}


void dequeue(Queue* queue){
    if(!queue || !queue->tamanho) return;

    Node* tmp = queue->head;
    queue->head = queue->head->next;
    free(tmp);
    queue->tamanho--;

    return;
}


int front(Queue* queue){
    if(!queue || !queue->tamanho) return -1;

    return queue->head->data;
}


void emptyQ(Queue* queue){
    if(!queue || !queue->tamanho) return;

    while(queue->head){
        Node* tmp = queue->head;
        queue->head = tmp->next;
        free(tmp);
    }

    queue->tamanho = 0;

    return;
}


// Stacks
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


void push(Stack* stack, int data){
    Node* newNode = createNode(data);
    if(!stack || !newNode) return;

    newNode->next = stack->head;
    stack->head = newNode;
    stack->tamanho++;

    return;
}


void pop(Stack* stack){
    if(!stack || !stack->tamanho) return;

    Node* tmp = stack->head;
    stack->head = tmp->next;
    free(tmp);
    stack->tamanho--;

    return;    
}


int top(Stack* stack){
    if(!stack || !stack->tamanho) return -1;
    return stack->head->data;
}


void emptyS(Stack* stack){
    if(!stack || !stack->tamanho) return;

    while(stack->head){
        Node* tmp = stack->head;
        stack->head = tmp->next;
        free(tmp);
    }

    stack->tamanho = 0;

    return;
}