#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList{
    int size;
    Node* start;
} LinkedList;

Node* createNode(int dados){
    Node* tempnode = (Node*)malloc(sizeof(Node));
    tempnode -> data = dados;
    tempnode -> next = NULL;

    return tempnode;
}

LinkedList* createList(){
    LinkedList* templist = (LinkedList*)malloc(sizeof(LinkedList));
    Node* tempnode = createNode(0);
    templist -> start = tempnode;
    templist -> size = 1;

    return templist;
}


int main{

    int op = 0, element;
    LinkedList lista = createList();

    printf("Ola, qual operacao deseja realizar?\n\n");
    printf("1 - Adicionar elemento no inicio da lista\n");
    printf("2 - Adicionar elemento no fim da lista\n");
    printf("3 - Adicionar elemento numa posicao especifica\n");
    printf("4 - Excluir elemento\n");
    printf("5 - Imprimir a lista\n");
    printf("6 - encerrar\n");

    scanf("%d", &op);
    if(op == 1){
        scanf("%d", &element);

        Node* temp = createNode(element);
        temp -> next = lista -> start;
        lista -> start = temp;
        lista -> size++;    
    }
    if(op == 2){
        scanf("%d", &element);

        LinkedList listatemp = lista;
        while(listatemp -> next != NULL){
            listatemp = listatemp -> next;
        }
        
        Node* nodetemp = createNode(element);
        listatemp -> next = nodetemp;
        lista -> size++;
    }
    if(op == 3){
        scanf("%d", &element);
        int posicao, point = 1;
        scanf("%d", &posicao);

        LinkedList listatemp = lista;
        while(point < posicao){
            listatemp = listatemp -> next;
            point++;
        }

        Node* nodetemp = createNode(element);
        nodetemp -> next = listatemp -> next;
        listatemp -> next = nodetemp;
    }
    if(op == 4){
        int posicao, point = 1;
        scanf("%d", &posicao);

        LinkedList listatemp = lista;
        while(point < posicao - 1){
            listatemp = listatemp -> next;
            point++;
        }
        Node* nodetemp = createNode(element);
        nodetemp = listatemp -> next;
        free(listatemp->next);
        listatemp -> next = nodetemp -> next;
        free(nodetemp);
    }
    if(op == 5){
        LinkedList listatemp = lista;
        while(listatemp != NULL){
            printf("%d ", listatemp -> data);
        }
        printf("\n")
    }

    if(op == 6) return 0;
}