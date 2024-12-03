#include <stdio.h>
#include <string.h>

int main(){

    int t, n, hashmap[26], baloes;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        char string[n+1];
        memset(hashmap, 0, sizeof(hashmap));
        baloes = 0;

        scanf("%s", string);
        for(int j = 0; j < n; j++){
            hashmap[string[j] - 'A']++;
            if(hashmap[string[j] - 'A'] == 1) baloes += 2;
            else if(hashmap[string[j] - 'A'] > 1) baloes++;
        }
        printf("%d\n", baloes);
    }

    return 0;
}