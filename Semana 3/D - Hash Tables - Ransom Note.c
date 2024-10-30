#include <stdio.h>
#include <string.h>

int main(){

    int m, n;

    scanf("%d %d", &m, &n);
    char magazine[m][7], note[n][7];
    int hashmap[m];
    memset(hashmap, 0, sizeof(hashmap));
    
    for(int i = 0; i < m; i++){
        scanf("%s", magazine[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%s", note[i]);

        int achou = 0;
        for(int j = 0; j < m; j++){
            if(strcmp(note[i], magazine[j]) == 0){
                if(hashmap[j] == 0){
                    achou = 1;
                    hashmap[j]++;
                }
            }
            if(achou == 1){
                break;
            }
        }
        if(achou == 0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");

    return 0;
}