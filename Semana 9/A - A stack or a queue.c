#include <stdio.h>

int main(){

    int t, n, checkqueue, checkstack;
    
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        int array1[n], array2[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &array1[j]);
        }
        for(int j = 0; j < n; j++){
            scanf("%d", &array2[j]);
        }

        checkqueue = 0;
        for(int j = 0; j < n; j++){
            if(array1[j] != array2[j]){
                checkqueue = 1;
                break;
            }
        }
        checkstack = 0;
        for(int j = 0, k = n-1; j < n && k >= 0; j++, k--){
            if(array1[j] != array2[k]){
                checkstack = 1;
                break;
            }
        }

        if(checkqueue == 1 && checkstack == 1) printf("neither\n");
        else if(checkqueue == 0 && checkstack == 0) printf("both\n");
        else if(checkqueue == 0 && checkstack == 1) printf("queue\n");
        else if(checkqueue == 1 && checkstack == 0) printf("stack\n");
    }


    return 0;
}