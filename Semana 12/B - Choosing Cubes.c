#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int main(){

    int t, n, f, k, fav;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &n, &f, &k);
        
        int array[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &array[j]);
        }

        int flagno = 0, flagmaybe = 0, flagyes = 0, flagelim = 0;
        fav = array[f-1];

        qsort(array, n, sizeof(int), compare);

        for(int j = 0; j < k; j++){
            if(array[j] == fav){
                flagelim = 1;
                break;
            }
        }
        for(int j = k; j < n; j++){
            if(array[j] == fav){
                if(flagelim == 1){
                    flagmaybe = 1;
                    break;
                }
                else{
                    flagno = 1;
                    break;
                }
            }
        }

        if(flagelim == 1 && flagmaybe == 0 && flagno == 0) printf("YES\n");
        else if(flagmaybe == 1) printf("MAYBE\n");
        else if(flagno == 1) printf("NO\n");
    }

    return 0;
}