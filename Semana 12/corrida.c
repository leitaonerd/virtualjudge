#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(){

    int ncorredores, menordif = 9999999;

    printf("Digite o numero de corredores: ");
    scanf("%d", &ncorredores);
    
    int array[ncorredores];
    for(int i = 0; i < ncorredores; i++){
        printf("Digite a habilidade do corredor %d:", i+1);
        scanf("%d", &array[i]);
    }

    qsort(array, ncorredores, sizeof(int), compare);
    
    for(int i = 0; i < ncorredores-1; i++){
        if(array[i+1] - array[i] < menordif) menordif = array[i+1] - array[i];
    }

    printf("A menor diferenca de habilidade eh %d\n", menordif);

    return 0;
}