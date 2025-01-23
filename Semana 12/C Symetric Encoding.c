#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int t, n;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        char string[n], aux[n];
        int hashmap[26] = {0};
        scanf("%s", string);

        for(int j = 0; j < n; j++){
            hashmap[string[j] - 'a']++;
        }
        int idx = 0;
        for(int j = 0; j < 26; j++){
            if(hashmap[j] != 0){
                aux[idx] = 'a' + j;
                idx++;
            }
        }
        aux[idx] = '\0';

        for(int j = 0; j < n; j++){
            char temp = string[j];
            idx = 0;
            while(temp != aux[idx]) idx++;
            string[j] = aux[strlen(aux) - 1 - idx];
        }
        string[n] = '\0';
        printf("%s\n", string);
    }

    return 0;
}