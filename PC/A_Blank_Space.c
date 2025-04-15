#include <stdio.h>

int main(){

    int t, n;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        int array[n];

        for(int j = 0; j < n; j++){
            scanf("%d", &array[j]);
        }
        int maxcont = 0, cont = 0;
        for(int j = 0; j < n; j++){
            if(array[j] == 0) {
                cont++;
                if(cont > maxcont) maxcont = cont;
            }
            else {
                cont = 0;
            }
        }
        printf("%d\n", maxcont);
    }


    return 0;
}