#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, head, atualcont = 0, maxcont = 0, hashmap[100000] = {0};

    scanf("%d", &n);
    int array[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    head = 0;
    for(int i = 0; i < n; i++){
        if(hashmap[array[i]] == 0){
            hashmap[array[i]]++;
            atualcont++;
        }
        else{
            int j = head;
            while(array[j] != array[i]){
                j++;
            }
            head = j++;

            if(atualcont > maxcont) maxcont = atualcont;
            memset(hashmap, 0, 100000* sizeof(int));
            atualcont = 0;
            i = head;
        }
    }

    if(atualcont > maxcont) maxcont = atualcont;

    printf("%d\n", maxcont);

    return 0;
}