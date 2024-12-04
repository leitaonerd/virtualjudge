#include <stdio.h>
#include <stdlib.h>

//adicionar hashmap JUNTO da linked list
struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

int main(){

    int n, a, cont, maxcont = 0;
    struct Node* head = NULL;
    struct Node* curr = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        struct Node* temp = newNode(a);

        if(head == NULL) head = temp;
        else curr -> next = temp;

        curr = temp;
    }




    return 0;
}