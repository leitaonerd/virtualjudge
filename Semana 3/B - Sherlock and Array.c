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

        int point = n/2, somaesq = 0, somadir = 0, prt = 0;

        while(point > 0 && point < n-1){
            somaesq = 0, somadir = 0;
            for(int k = 0; k < point; k++){
                somaesq += arr[k];
            }
            for(int k = point+1; k < n; k++){
                somadir += arr[k];
            }

            if(somadir > somaesq) point += (point/2 + 1);
            else if(somadir < somaesq) point -= (point/2 + 1);
            else{
                printf("YES\n");
                prt = 1;
                break;
            }
        }
        if((somadir == 0 || somaesq == 0) && prt == 0){
            printf("YES\n");
            continue;
        } 
        if(point > 0 && point < n-1) continue;
        else printf("NO\n");
    }

    return 0;
}