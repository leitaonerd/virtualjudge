#include <stdio.h>

int main(){

    int t, n;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int pares = 0, impares = 0, total = 0;
        scanf("%d", &n);
        int array[n];

        for(int j = 0; j < n; j++){
            scanf("%d", &array[j]);
            array[j]%2 == 0 ? pares++ : impares++;
            total += array[j];
        }

        if(impares%2 != 0 || impares+pares < 2) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}