#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int t;
    char string[1000000];
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%s", string);
        int len = strlen(string);

        for(int j = 0; j < len; j++){
            if(string[j] == 'B'){
                string[j] = 1;

                int k = j, achou = 0;
                while(k >= 0 && achou == 0){
                    if(string[k] >= 'A' && string[k] <= 'Z'){
                        achou = 1;
                        string[k] = 1;
                        break;
                    }
                    k--;
                } 
            }
            else if(string[j] == 'b'){
                string[j] = 1;

                int k = j, achou = 0;
                while(k >= 0 && achou == 0){
                    if(string[k] >= 'a' && string[k] <= 'z'){
                        achou = 1;
                        string[k] = 1;
                        break;
                    }
                    k--;
                } 
            }
        }

        for(int j = 0; j < len; j++){
            if(string[j] != 1) printf("%c", string[j]);
        }
        printf("\n");
    }
    return 0;
}