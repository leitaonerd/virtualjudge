#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* trocaLista(struct ListNode* head) {
    int array[10000], i = 0;
    struct ListNode* starthead = (struct ListNode*)malloc(sizeof(struct ListNode));
    starthead = head;

    while(head != NULL){
        array[i] = head -> val;
        i++;
    }

    int max = i;
    i = 0;

    while(i < max){
        int temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
        i+=2;
    }
    
    while(i <= max){
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp -> val = array[i];
        
    }
    
}

int main(){

    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        
    }




}