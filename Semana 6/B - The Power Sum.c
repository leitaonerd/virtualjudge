#include <stdio.h>
#include <math.h>

int fatorar(int a, int b, int* vetor);

int main(){

    int x, n, fatoracao1[32] = {0}, fatoracao2[32] = {0}, res1 = 1, res2 = 1;
    scanf("%d", &x);
    scanf("%d", n);

    fatorar(x, 2, fatoracao1);
    fatorar(x-1, 2, fatoracao2);

    for(int i = 1; i < 32; i++){
        if(fatoracao1[i] % n != 0){
            res1 = 0;
            break;
        }
    }
    for(int i = 1; i < 32; i++){
        if(fatoracao2[i] % n != 0){
            res2 = 0;
            break;
        }
    }
    printf("%d\n", res1 + res2);

    return 0;
}

int fatorar(int a, int b, int* vetor){
    if(b > a) return 0;
    if(a%b == 0){
        vetor[b]++;
        return (fatorar(a/b, b, vetor));
    }
    else{
        return (fatorar(a, b+1, vetor));
    }
}