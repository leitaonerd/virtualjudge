#include <stdio.h>

int main(){

    int t, n;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        int arr[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }

        int point = n/2;

        while(point > 0 && point < n-1){
            int somaesq = 0, somadir = 0;
            for(int k = 0; k < point; k++){
                somaesq += arr[k];
            }
            for(int k = point+1; k < n; k++){
                somadir += arr[k];
            }

            if(somadir > somaesq) point++;
            else if(somadir < somaesq) point--;
            else{
                printf("YES\n");
                break;
            }
        }
        if(point > 0 && point < n) continue;
        else printf("NO\n");
    }

    return 0;
}