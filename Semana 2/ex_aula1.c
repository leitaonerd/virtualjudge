#include <stdio.h>
#include <string.h>

char converteChar(char a);

int main(){

    char string[999];

    scanf("%[^\n]", string);
    getchar();

    for(int i = 0; i < strlen(string); i++){
        string[i] = converteChar(string[i]);
    }

    printf("%s\n", string);

    return 0;
}

char converteChar(char a){
    if(a >= 'a' && a <= 'z'){
        return a-32;
    }
    if(a >= 'A' && a <= 'Z'){
        return a+32;
    }
}
