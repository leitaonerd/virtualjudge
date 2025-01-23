#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* last;
} Node;

typedef struct LinkedList{
    int size;
    Node* start;
    Node* end;
} LinkedList;

Node* createNode(int dados){
    Node* tempnode = (Node*)malloc(sizeof(Node));
    tempnode -> data = dados;
    tempnode -> next = NULL;
    tempnode -> last = NULL;

    return tempnode;
}

LinkedList* createList(){
    LinkedList* templist = (LinkedList*)malloc(sizeof(LinkedList));
    Node* tempnode = createNode(0);

    tempnode -> next = tempnode;
    tempnode -> last = tempnode;
    
    templist -> start = tempnode;
    templist -> end = tempnode;
    templist -> size = 1;

    return templist;
}