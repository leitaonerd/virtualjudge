#include <stdio.h>

int main(){

    int t, n;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        int given[n], completed[n];

        for(int j = 0; j < n; j++){
            scanf("%d", &given[j]);
        } 
        for(int j = 0; j < n; j++){
            scanf("%d", &completed[j]);
        } 

        printf("%d ", completed[0] - given[0]);
        for(int j = 1; j < n; j++){
            if(given[j] > completed[j-1]) printf("%d ", (completed[j] - given[j]));
            else printf("%d ", (completed[j] - completed[j-1]));
        }
    }

    return 0;
}