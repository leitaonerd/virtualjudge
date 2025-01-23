#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int main(){

    int t, n, k, cat, saved;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &k);
        int mice[k], count = 0;
        saved = 0;
        cat = 0;
        for(int j = 0; j < k; j++){
            scanf("%d", &mice[j]);
        }
        
        qsort(mice, k, sizeof(int), compare);
        
        int last = k - 1;
        while(cat < mice[last] && cat < n){
            while(count < k && (mice[count] == n || mice[count] == -1)){
                count++;
            }
            mice[count]++; 
            if(mice[count] == n) saved++;
            cat++;
            if(cat == mice[last]){
                mice[last] = -1;
                last--;
            } 
        }
        printf("%d\n", saved);
    }

    return 0;
}