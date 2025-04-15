#include <stdio.h>

void printh(){
    printf("##");
}
void printp(){
    printf("..");
}

int main(){

    int t, n;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d", &n);

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if((j+k)%2 == 0){
                    printh();
                }
                else printp();
            }
            printf("\n");
            for(int k = 0; k < n; k++){
                if((j+k)%2 == 0){
                    printh();
                }
                else printp();
            }
            printf("\n");
        }
    }


    return 0;
}