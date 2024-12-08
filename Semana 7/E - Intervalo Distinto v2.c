#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head = 0, atualcont = 0, maxcont = 0, hashmap[100000] = {0};
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < n; i++){
        hashmap[array[i]]++;

        while(hashmap[array[i]] > 1){
            hashmap[array[head]]--;
            head++;
        }

        atualcont = i - head + 1;
        if(atualcont > maxcont){
            maxcont = atualcont;
        }
    }

    printf("%d\n", maxcont);

    return 0;
}
