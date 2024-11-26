#include <stdio.h>
#include <string.h>

int main(){

    long long int k, soma = 0, temp;
    char n[1000000];

    scanf("%s %lld", n, &k);
    for(int i = 0; i < strlen(n); i++){
        soma += n[i] - '0';
    }
    soma = soma * k;

    while(soma > 9){
        temp = soma;
        soma = 0;
        while(temp > 0){
            soma += temp%10;
            temp = temp/10;
        }
    }
    
    printf("%lld\n", soma);   

    return 0;
}