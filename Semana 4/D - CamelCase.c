#include <stdio.h>
#include <string.h>

int main(){

    char string[100001];
    int count = 0;

    scanf("%s", string);
    for(int i = 0; i < strlen(string); i++){
        if(string[i] >= 'A' && string[i] <= 'Z') count++;
    }
    
    if(strlen(string) > 0) count++;
    printf("%d\n", count);

    return 0;
}